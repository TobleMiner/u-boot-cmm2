// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2018 MediaTek Inc.
 * Author: Ryder Lee <ryder.lee@mediatek.com>
 */

#include <clk.h>
#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <linux/iopoll.h>

#include <dt-bindings/power/mt7629-power.h>

#define SPM_EN			(0xb16 << 16 | 0x1)
#define SPM_ETHSYS_PWR_CON	0x2e0
#define SPM_HIF0_PWR_CON	0x2e4
#define SPM_HIF1_PWR_CON	0x2e8
#define SPM_PWR_STATUS		0x60c
#define SPM_PWR_STATUS_2ND	0x610

#define PWR_RST_B_BIT		BIT(0)
#define PWR_ISO_BIT		BIT(1)
#define PWR_ON_BIT		BIT(2)
#define PWR_ON_2ND_BIT		BIT(3)
#define PWR_CLK_DIS_BIT		BIT(4)

#define PWR_STATUS_ETHSYS	BIT(24)
#define PWR_STATUS_HIF0		BIT(25)
#define PWR_STATUS_HIF1		BIT(26)

/* Infrasys configuration */
#define INFRA_TOPDCM_CTRL	0x10
#define INFRA_TOPAXI_PROT_EN	0x220
#define INFRA_TOPAXI_PROT_STA1	0x228

#define DCM_TOP_EN		BIT(0)

enum scp_domain_type {
	SCPSYS_MT7629,
};

struct scp_domain;

struct scp_domain_data {
	struct scp_domain *scpd;
	u32 sta_mask;
	int ctl_offs;
	u32 sram_pdn_bits;
	u32 sram_pdn_ack_bits;
	u32 bus_prot_mask;
};

struct scp_domain {
	void __iomem *base;
	void __iomem *infracfg;
	enum scp_domain_type type;
	struct scp_domain_data *data;
};

static struct scp_domain_data scp_domain_mt7629[] = {
	[MT7629_POWER_DOMAIN_ETHSYS] = {
		.sta_mask = PWR_STATUS_ETHSYS,
		.ctl_offs = SPM_ETHSYS_PWR_CON,
		.sram_pdn_bits = GENMASK(11, 8),
		.sram_pdn_ack_bits = GENMASK(15, 12),
		.bus_prot_mask = (BIT(3) | BIT(17)),
	},
	[MT7629_POWER_DOMAIN_HIF0] = {
		.sta_mask = PWR_STATUS_HIF0,
		.ctl_offs = SPM_HIF0_PWR_CON,
		.sram_pdn_bits = GENMASK(11, 8),
		.sram_pdn_ack_bits = GENMASK(15, 12),
		.bus_prot_mask = GENMASK(25, 24),
	},
	[MT7629_POWER_DOMAIN_HIF1] = {
		.sta_mask = PWR_STATUS_HIF1,
		.ctl_offs = SPM_HIF1_PWR_CON,
		.sram_pdn_bits = GENMASK(11, 8),
		.sram_pdn_ack_bits = GENMASK(15, 12),
		.bus_prot_mask = GENMASK(28, 26),
	},
};

/**
 * This function enables the bus protection bits for disabled power
 * domains so that the system does not hang when some unit accesses the
 * bus while in power down.
 */
static int mtk_infracfg_set_bus_protection(void __iomem *infracfg,
					   u32 mask)
{
	u32 val;

	clrsetbits_le32(infracfg + INFRA_TOPAXI_PROT_EN, mask, mask);

	return readl_poll_timeout(infracfg + INFRA_TOPAXI_PROT_STA1, val,
				  (val & mask) == mask, 100);
}

static int mtk_infracfg_clear_bus_protection(void __iomem *infracfg,
					     u32 mask)
{
	u32 val;

	clrbits_le32(infracfg + INFRA_TOPAXI_PROT_EN, mask);

	return readl_poll_timeout(infracfg + INFRA_TOPAXI_PROT_STA1, val,
				  !(val & mask), 100);
}

static int scpsys_domain_is_on(struct scp_domain_data *data)
{
	struct scp_domain *scpd = data->scpd;
	u32 sta = readl(scpd->base + SPM_PWR_STATUS) &
			data->sta_mask;
	u32 sta2 = readl(scpd->base + SPM_PWR_STATUS_2ND) &
			 data->sta_mask;

	/*
	 * A domain is on when both status bits are set. If only one is set
	 * return an error. This happens while powering up a domain
	 */
	if (sta && sta2)
		return true;
	if (!sta && !sta2)
		return false;

	return -EINVAL;
}

static int scpsys_power_on(struct power_domain *power_domain)
{
	struct scp_domain *scpd = dev_get_priv(power_domain->dev);
	struct scp_domain_data *data = &scpd->data[power_domain->id];
	void __iomem *ctl_addr = scpd->base + data->ctl_offs;
	u32 pdn_ack = data->sram_pdn_ack_bits;
	u32 val;
	int ret, tmp;

	writel(SPM_EN, scpd->base);

	val = readl(ctl_addr);
	val |= PWR_ON_BIT;
	writel(val, ctl_addr);

	val |= PWR_ON_2ND_BIT;
	writel(val, ctl_addr);

	ret = readx_poll_timeout(scpsys_domain_is_on, data, tmp, tmp > 0,
				 100);
	if (ret < 0)
		return ret;

	val &= ~PWR_CLK_DIS_BIT;
	writel(val, ctl_addr);

	val &= ~PWR_ISO_BIT;
	writel(val, ctl_addr);

	val |= PWR_RST_B_BIT;
	writel(val, ctl_addr);

	val &= ~data->sram_pdn_bits;
	writel(val, ctl_addr);

	ret = readl_poll_timeout(ctl_addr, tmp, !(tmp & pdn_ack), 100);
	if (ret < 0)
		return ret;

	if (data->bus_prot_mask) {
		ret = mtk_infracfg_clear_bus_protection(scpd->infracfg,
							data->bus_prot_mask);
		if (ret)
			return ret;
	}

	return 0;
}

static int scpsys_power_off(struct power_domain *power_domain)
{
	struct scp_domain *scpd = dev_get_priv(power_domain->dev);
	struct scp_domain_data *data = &scpd->data[power_domain->id];
	void __iomem *ctl_addr = scpd->base + data->ctl_offs;
	u32 pdn_ack = data->sram_pdn_ack_bits;
	u32 val;
	int ret, tmp;

	if (data->bus_prot_mask) {
		ret = mtk_infracfg_set_bus_protection(scpd->infracfg,
						      data->bus_prot_mask);
		if (ret)
			return ret;
	}

	val = readl(ctl_addr);
	val |= data->sram_pdn_bits;
	writel(val, ctl_addr);

	ret = readl_poll_timeout(ctl_addr, tmp, (tmp & pdn_ack) == pdn_ack,
				 100);
	if (ret < 0)
		return ret;

	val |= PWR_ISO_BIT;
	writel(val, ctl_addr);

	val &= ~PWR_RST_B_BIT;
	writel(val, ctl_addr);

	val |= PWR_CLK_DIS_BIT;
	writel(val, ctl_addr);

	val &= ~PWR_ON_BIT;
	writel(val, ctl_addr);

	val &= ~PWR_ON_2ND_BIT;
	writel(val, ctl_addr);

	ret = readx_poll_timeout(scpsys_domain_is_on, data, tmp, !tmp, 100);
	if (ret < 0)
		return ret;

	return 0;
}

static int scpsys_power_request(struct power_domain *power_domain)
{
	struct scp_domain *scpd = dev_get_priv(power_domain->dev);
	struct scp_domain_data *data;

	data = &scpd->data[power_domain->id];
	data->scpd = scpd;

	return 0;
}

static int scpsys_power_free(struct power_domain *power_domain)
{
	return 0;
}

static int mtk_power_domain_hook(struct udevice *dev)
{
	struct scp_domain *scpd = dev_get_priv(dev);

	scpd->type = (enum scp_domain_type)dev_get_driver_data(dev);

	switch (scpd->type) {
	case SCPSYS_MT7629:
		scpd->data = scp_domain_mt7629;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static int mtk_power_domain_probe(struct udevice *dev)
{
	struct ofnode_phandle_args args;
	struct scp_domain *scpd = dev_get_priv(dev);
	struct regmap *regmap;
	struct clk_bulk bulk;
	int err;

	scpd->base = dev_read_addr_ptr(dev);
	if (!scpd->base)
		return -ENOENT;

	err = mtk_power_domain_hook(dev);
	if (err)
		return err;

	/* get corresponding syscon phandle */
	err = dev_read_phandle_with_args(dev, "infracfg", NULL, 0, 0, &args);
	if (err)
		return err;

	regmap = syscon_node_to_regmap(args.node);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	scpd->infracfg = regmap_get_range(regmap, 0);
	if (!scpd->infracfg)
		return -ENOENT;

	/* enable Infra DCM */
	setbits_le32(scpd->infracfg + INFRA_TOPDCM_CTRL, DCM_TOP_EN);

	err = clk_get_bulk(dev, &bulk);
	if (err)
		return err;

	return clk_enable_bulk(&bulk);
}

static const struct udevice_id mtk_power_domain_ids[] = {
	{
		.compatible = "mediatek,mt7629-scpsys",
		.data = SCPSYS_MT7629,
	},
	{ /* sentinel */ }
};

struct power_domain_ops mtk_power_domain_ops = {
	.free = scpsys_power_free,
	.off = scpsys_power_off,
	.on = scpsys_power_on,
	.request = scpsys_power_request,
};

U_BOOT_DRIVER(mtk_power_domain) = {
	.name = "mtk_power_domain",
	.id = UCLASS_POWER_DOMAIN,
	.ops = &mtk_power_domain_ops,
	.probe = mtk_power_domain_probe,
	.of_match = mtk_power_domain_ids,
	.priv_auto_alloc_size = sizeof(struct scp_domain),
};
