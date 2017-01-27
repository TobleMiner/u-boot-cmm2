/*
 * Copyright (C) 2012-2015 Panasonic Corporation
 * Copyright (C) 2015-2017 Socionext Inc.
 *   Author: Masahiro Yamada <yamada.masahiro@socionext.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <fdtdec.h>
#include <linux/errno.h>
#include <linux/sizes.h>

#include "init.h"
#include "sg-regs.h"
#include "soc-info.h"

DECLARE_GLOBAL_DATA_PTR;

struct uniphier_memif_data {
	unsigned int soc_id;
	unsigned long sparse_ch1_base;
	int have_ch2;
};

static const struct uniphier_memif_data uniphier_memif_data[] = {
	{
		.soc_id = UNIPHIER_SLD3_ID,
		.sparse_ch1_base = 0xc0000000,
		/*
		 * In fact, SLD3 has DRAM ch2, but the memory regions for ch1
		 * and ch2 overlap, and host cannot get access to them at the
		 * same time.  Hide the ch2 from U-Boot.
		 */
	},
	{
		.soc_id = UNIPHIER_LD4_ID,
		.sparse_ch1_base = 0xc0000000,
	},
	{
		.soc_id = UNIPHIER_PRO4_ID,
		.sparse_ch1_base = 0xa0000000,
	},
	{
		.soc_id = UNIPHIER_SLD8_ID,
		.sparse_ch1_base = 0xc0000000,
	},
	{
		.soc_id = UNIPHIER_PRO5_ID,
		.sparse_ch1_base = 0xc0000000,
	},
	{
		.soc_id = UNIPHIER_PXS2_ID,
		.sparse_ch1_base = 0xc0000000,
		.have_ch2 = 1,
	},
	{
		.soc_id = UNIPHIER_LD6B_ID,
		.sparse_ch1_base = 0xc0000000,
		.have_ch2 = 1,
	},
	{
		.soc_id = UNIPHIER_LD11_ID,
		.sparse_ch1_base = 0xc0000000,
	},
	{
		.soc_id = UNIPHIER_LD20_ID,
		.sparse_ch1_base = 0xc0000000,
		.have_ch2 = 1,
	},
	{
		.soc_id = UNIPHIER_PXS3_ID,
		.sparse_ch1_base = 0xc0000000,
		.have_ch2 = 1,
	},
};
UNIPHIER_DEFINE_SOCDATA_FUNC(uniphier_get_memif_data, uniphier_memif_data)

static int uniphier_memconf_decode(struct uniphier_dram_ch *dram_ch)
{
	const struct uniphier_memif_data *data;
	unsigned long size;
	u32 val;

	data = uniphier_get_memif_data();
	if (!data) {
		pr_err("unsupported SoC\n");
		return -EINVAL;
	}

	val = readl(SG_MEMCONF);

	/* set up ch0 */
	dram_ch[0].base = CONFIG_SYS_SDRAM_BASE;

	switch (val & SG_MEMCONF_CH0_SZ_MASK) {
	case SG_MEMCONF_CH0_SZ_64M:
		size = SZ_64M;
		break;
	case SG_MEMCONF_CH0_SZ_128M:
		size = SZ_128M;
		break;
	case SG_MEMCONF_CH0_SZ_256M:
		size = SZ_256M;
		break;
	case SG_MEMCONF_CH0_SZ_512M:
		size = SZ_512M;
		break;
	case SG_MEMCONF_CH0_SZ_1G:
		size = SZ_1G;
		break;
	default:
		pr_err("error: invald value is set to MEMCONF ch0 size\n");
		return -EINVAL;
	}

	if ((val & SG_MEMCONF_CH0_NUM_MASK) == SG_MEMCONF_CH0_NUM_2)
		size *= 2;

	dram_ch[0].size = size;

	/* set up ch1 */
	dram_ch[1].base = dram_ch[0].base + size;

	if (val & SG_MEMCONF_SPARSEMEM) {
		if (dram_ch[1].base > data->sparse_ch1_base) {
			pr_warn("Sparse mem is enabled, but ch0 and ch1 overlap\n");
			pr_warn("Only ch0 is available\n");
			dram_ch[1].base = 0;
			return 0;
		}

		dram_ch[1].base = data->sparse_ch1_base;
	}

	switch (val & SG_MEMCONF_CH1_SZ_MASK) {
	case SG_MEMCONF_CH1_SZ_64M:
		size = SZ_64M;
		break;
	case SG_MEMCONF_CH1_SZ_128M:
		size = SZ_128M;
		break;
	case SG_MEMCONF_CH1_SZ_256M:
		size = SZ_256M;
		break;
	case SG_MEMCONF_CH1_SZ_512M:
		size = SZ_512M;
		break;
	case SG_MEMCONF_CH1_SZ_1G:
		size = SZ_1G;
		break;
	default:
		pr_err("error: invald value is set to MEMCONF ch1 size\n");
		return -EINVAL;
	}

	if ((val & SG_MEMCONF_CH1_NUM_MASK) == SG_MEMCONF_CH1_NUM_2)
		size *= 2;

	dram_ch[1].size = size;

	if (!data->have_ch2)
		return 0;

	/* set up ch2 */
	dram_ch[2].base = dram_ch[1].base + size;

	switch (val & SG_MEMCONF_CH2_SZ_MASK) {
	case SG_MEMCONF_CH2_SZ_64M:
		size = SZ_64M;
		break;
	case SG_MEMCONF_CH2_SZ_128M:
		size = SZ_128M;
		break;
	case SG_MEMCONF_CH2_SZ_256M:
		size = SZ_256M;
		break;
	case SG_MEMCONF_CH2_SZ_512M:
		size = SZ_512M;
		break;
	case SG_MEMCONF_CH2_SZ_1G:
		size = SZ_1G;
		break;
	default:
		pr_err("error: invald value is set to MEMCONF ch2 size\n");
		return -EINVAL;
	}

	if ((val & SG_MEMCONF_CH2_NUM_MASK) == SG_MEMCONF_CH2_NUM_2)
		size *= 2;

	dram_ch[2].size = size;

	return 0;
}

int dram_init(void)
{
	struct uniphier_dram_ch dram_ch[UNIPHIER_MAX_NR_DRAM_CH] = {};
	int ret, i;

	gd->ram_size = 0;

	ret = uniphier_memconf_decode(dram_ch);
	if (ret)
		return ret;

	for (i = 0; i < ARRAY_SIZE(dram_ch); i++) {

		if (!dram_ch[i].size)
			break;

		/*
		 * U-Boot relocates itself to the tail of the memory region,
		 * but it does not expect sparse memory.  We use the first
		 * contiguous chunk here.
		 */
		if (i > 0 &&
		    dram_ch[i - 1].base + dram_ch[i - 1].size < dram_ch[i].base)
			break;

		gd->ram_size += dram_ch[i].size;
	}

	return 0;
}

void dram_init_banksize(void)
{
	struct uniphier_dram_ch dram_ch[UNIPHIER_MAX_NR_DRAM_CH] = {};
	int i;

	uniphier_memconf_decode(dram_ch);

	for (i = 0; i < ARRAY_SIZE(dram_ch); i++) {
		if (i >= ARRAY_SIZE(gd->bd->bi_dram))
			break;

		gd->bd->bi_dram[i].start = dram_ch[i].base;
		gd->bd->bi_dram[i].size = dram_ch[i].size;
	}
}

#ifdef CONFIG_OF_BOARD_SETUP
/*
 * The DRAM PHY requires 64 byte scratch area in each DRAM channel
 * for its dynamic PHY training feature.
 */
int ft_board_setup(void *fdt, bd_t *bd)
{
	const struct uniphier_board_data *param;
	unsigned long rsv_addr;
	const unsigned long rsv_size = 64;
	int ch, ret;

	if (uniphier_get_soc_id() != UNIPHIER_LD20_ID)
		return 0;

	param = uniphier_get_board_param();
	if (!param) {
		printf("failed to get board parameter\n");
		return -ENODEV;
	}

	for (ch = 0; ch < param->dram_nr_ch; ch++) {
		rsv_addr = param->dram_ch[ch].base + param->dram_ch[ch].size;
		rsv_addr -= rsv_size;

		ret = fdt_add_mem_rsv(fdt, rsv_addr, rsv_size);
		if (ret)
			return -ENOSPC;

		printf("   Reserved memory region for DRAM PHY training: addr=%lx size=%lx\n",
		       rsv_addr, rsv_size);
	}

	return 0;
}
#endif
