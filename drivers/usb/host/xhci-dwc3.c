/*
 * Copyright 2015 Freescale Semiconductor, Inc.
 *
 * DWC3 controller driver
 *
 * Author: Ramneek Mehresh<ramneek.mehresh@freescale.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <generic-phy.h>
#include <usb.h>

#include "xhci.h"
#include <asm/io.h>
#include <linux/usb/dwc3.h>
#include <linux/usb/otg.h>

DECLARE_GLOBAL_DATA_PTR;

struct xhci_dwc3_platdata {
	struct phy *usb_phys;
	int num_phys;
};

void dwc3_set_mode(struct dwc3 *dwc3_reg, u32 mode)
{
	clrsetbits_le32(&dwc3_reg->g_ctl,
			DWC3_GCTL_PRTCAPDIR(DWC3_GCTL_PRTCAP_OTG),
			DWC3_GCTL_PRTCAPDIR(mode));
}

static void dwc3_phy_reset(struct dwc3 *dwc3_reg)
{
	/* Assert USB3 PHY reset */
	setbits_le32(&dwc3_reg->g_usb3pipectl[0], DWC3_GUSB3PIPECTL_PHYSOFTRST);

	/* Assert USB2 PHY reset */
	setbits_le32(&dwc3_reg->g_usb2phycfg, DWC3_GUSB2PHYCFG_PHYSOFTRST);

	mdelay(100);

	/* Clear USB3 PHY reset */
	clrbits_le32(&dwc3_reg->g_usb3pipectl[0], DWC3_GUSB3PIPECTL_PHYSOFTRST);

	/* Clear USB2 PHY reset */
	clrbits_le32(&dwc3_reg->g_usb2phycfg, DWC3_GUSB2PHYCFG_PHYSOFTRST);
}

void dwc3_core_soft_reset(struct dwc3 *dwc3_reg)
{
	/* Before Resetting PHY, put Core in Reset */
	setbits_le32(&dwc3_reg->g_ctl, DWC3_GCTL_CORESOFTRESET);

	/* reset USB3 phy - if required */
	dwc3_phy_reset(dwc3_reg);

	mdelay(100);

	/* After PHYs are stable we can take Core out of reset state */
	clrbits_le32(&dwc3_reg->g_ctl, DWC3_GCTL_CORESOFTRESET);
}

int dwc3_core_init(struct dwc3 *dwc3_reg)
{
	u32 reg;
	u32 revision;
	unsigned int dwc3_hwparams1;

	revision = readl(&dwc3_reg->g_snpsid);
	/* This should read as U3 followed by revision number */
	if ((revision & DWC3_GSNPSID_MASK) != 0x55330000) {
		puts("this is not a DesignWare USB3 DRD Core\n");
		return -1;
	}

	dwc3_core_soft_reset(dwc3_reg);

	dwc3_hwparams1 = readl(&dwc3_reg->g_hwparams1);

	reg = readl(&dwc3_reg->g_ctl);
	reg &= ~DWC3_GCTL_SCALEDOWN_MASK;
	reg &= ~DWC3_GCTL_DISSCRAMBLE;
	switch (DWC3_GHWPARAMS1_EN_PWROPT(dwc3_hwparams1)) {
	case DWC3_GHWPARAMS1_EN_PWROPT_CLK:
		reg &= ~DWC3_GCTL_DSBLCLKGTNG;
		break;
	default:
		debug("No power optimization available\n");
	}

	/*
	 * WORKAROUND: DWC3 revisions <1.90a have a bug
	 * where the device can fail to connect at SuperSpeed
	 * and falls back to high-speed mode which causes
	 * the device to enter a Connect/Disconnect loop
	 */
	if ((revision & DWC3_REVISION_MASK) < 0x190a)
		reg |= DWC3_GCTL_U2RSTECN;

	writel(reg, &dwc3_reg->g_ctl);

	return 0;
}

void dwc3_set_fladj(struct dwc3 *dwc3_reg, u32 val)
{
	setbits_le32(&dwc3_reg->g_fladj, GFLADJ_30MHZ_REG_SEL |
			GFLADJ_30MHZ(val));
}

#ifdef CONFIG_DM_USB
static int xhci_dwc3_setup_phy(struct udevice *dev)
{
	struct xhci_dwc3_platdata *plat = dev_get_platdata(dev);
	int i, ret, count;

	/* Return if no phy declared */
	if (!dev_read_prop(dev, "phys", NULL))
		return 0;

	count = dev_count_phandle_with_args(dev, "phys", "#phy-cells");
	if (count <= 0)
		return count;

	plat->usb_phys = devm_kcalloc(dev, count, sizeof(struct phy),
				      GFP_KERNEL);
	if (!plat->usb_phys)
		return -ENOMEM;

	for (i = 0; i < count; i++) {
		ret = generic_phy_get_by_index(dev, i, &plat->usb_phys[i]);
		if (ret && ret != -ENOENT) {
			pr_err("Failed to get USB PHY%d for %s\n",
			       i, dev->name);
			return ret;
		}

		++plat->num_phys;
	}

	for (i = 0; i < plat->num_phys; i++) {
		ret = generic_phy_init(&plat->usb_phys[i]);
		if (ret) {
			pr_err("Can't init USB PHY%d for %s\n",
			       i, dev->name);
			goto phys_init_err;
		}
	}

	for (i = 0; i < plat->num_phys; i++) {
		ret = generic_phy_power_on(&plat->usb_phys[i]);
		if (ret) {
			pr_err("Can't power USB PHY%d for %s\n",
			       i, dev->name);
			goto phys_poweron_err;
		}
	}

	return 0;

phys_poweron_err:
	for (; i >= 0; i--)
		generic_phy_power_off(&plat->usb_phys[i]);

	for (i = 0; i < plat->num_phys; i++)
		generic_phy_exit(&plat->usb_phys[i]);

	return ret;

phys_init_err:
	for (; i >= 0; i--)
		generic_phy_exit(&plat->usb_phys[i]);

	return ret;
}

static int xhci_dwc3_shutdown_phy(struct udevice *dev)
{
	struct xhci_dwc3_platdata *plat = dev_get_platdata(dev);
	int i, ret;

	for (i = 0; i < plat->num_phys; i++) {
		if (!generic_phy_valid(&plat->usb_phys[i]))
			continue;

		ret = generic_phy_power_off(&plat->usb_phys[i]);
		ret |= generic_phy_exit(&plat->usb_phys[i]);
		if (ret) {
			pr_err("Can't shutdown USB PHY%d for %s\n",
			       i, dev->name);
		}
	}

	return 0;
}

static int xhci_dwc3_probe(struct udevice *dev)
{
	struct xhci_hcor *hcor;
	struct xhci_hccr *hccr;
	struct dwc3 *dwc3_reg;
	enum usb_dr_mode dr_mode;
	int ret;

	hccr = (struct xhci_hccr *)((uintptr_t)dev_read_addr(dev));
	hcor = (struct xhci_hcor *)((uintptr_t)hccr +
			HC_LENGTH(xhci_readl(&(hccr)->cr_capbase)));

	ret = xhci_dwc3_setup_phy(dev);
	if (ret)
		return ret;

	dwc3_reg = (struct dwc3 *)((char *)(hccr) + DWC3_REG_OFFSET);

	dwc3_core_init(dwc3_reg);

	dr_mode = usb_get_dr_mode(dev_of_offset(dev));
	if (dr_mode == USB_DR_MODE_UNKNOWN)
		/* by default set dual role mode to HOST */
		dr_mode = USB_DR_MODE_HOST;

	dwc3_set_mode(dwc3_reg, dr_mode);

	return xhci_register(dev, hccr, hcor);
}

static int xhci_dwc3_remove(struct udevice *dev)
{
	xhci_dwc3_shutdown_phy(dev);

	return xhci_deregister(dev);
}

static const struct udevice_id xhci_dwc3_ids[] = {
	{ .compatible = "snps,dwc3" },
	{ }
};

U_BOOT_DRIVER(xhci_dwc3) = {
	.name = "xhci-dwc3",
	.id = UCLASS_USB,
	.of_match = xhci_dwc3_ids,
	.probe = xhci_dwc3_probe,
	.remove = xhci_dwc3_remove,
	.ops = &xhci_usb_ops,
	.priv_auto_alloc_size = sizeof(struct xhci_ctrl),
	.platdata_auto_alloc_size = sizeof(struct xhci_dwc3_platdata),
	.flags = DM_FLAG_ALLOC_PRIV_DMA,
};
#endif
