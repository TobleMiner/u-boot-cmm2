/*
 * Copyright (C) 2015 Masahiro Yamada <yamada.masahiro@socionext.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <libfdt.h>
#include <linux/kernel.h>

#include "init.h"

DECLARE_GLOBAL_DATA_PTR;

#if defined(CONFIG_ARCH_UNIPHIER_PH1_SLD3)
static const struct uniphier_board_data ph1_sld3_data = {
	.dram_freq = 1600,
	.dram_nr_ch = 3,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x20000000,
		.width = 32,
	},
	.dram_ch[1] = {
		.base = 0xc0000000,
		.size = 0x20000000,
		.width = 16,
	},
	.dram_ch[2] = {
		.base = 0xc0000000,
		.size = 0x10000000,
		.width = 16,
	},
};
#endif

#if defined(CONFIG_ARCH_UNIPHIER_PH1_LD4)
static const struct uniphier_board_data ph1_ld4_data = {
	.dram_freq = 1600,
	.dram_nr_ch = 2,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x10000000,
		.width = 16,
	},
	.dram_ch[1] = {
		.base = 0x90000000,
		.size = 0x10000000,
		.width = 16,
	},
};
#endif

#if defined(CONFIG_ARCH_UNIPHIER_PH1_PRO4)
/* 1GB RAM board */
static const struct uniphier_board_data ph1_pro4_data = {
	.dram_freq = 1600,
	.dram_nr_ch = 2,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x20000000,
		.width = 32,
	},
	.dram_ch[1] = {
		.base = 0xa0000000,
		.size = 0x20000000,
		.width = 32,
	},
};

/* 2GB RAM board */
static const struct uniphier_board_data ph1_pro4_2g_data = {
	.dram_freq = 1600,
	.dram_nr_ch = 2,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x40000000,
		.width = 32,
	},
	.dram_ch[1] = {
		.base = 0xc0000000,
		.size = 0x40000000,
		.width = 32,
	},
};
#endif

#if defined(CONFIG_ARCH_UNIPHIER_PH1_SLD8)
static const struct uniphier_board_data ph1_sld8_data = {
	.dram_freq = 1333,
	.dram_nr_ch = 2,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x10000000,
		.width = 16,
	},
	.dram_ch[1] = {
		.base = 0x90000000,
		.size = 0x10000000,
		.width = 16,
	},
};
#endif

#if defined(CONFIG_ARCH_UNIPHIER_PH1_PRO5)
static const struct uniphier_board_data ph1_pro5_data = {
	.dram_freq = 1866,
	.dram_nr_ch = 2,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x20000000,
		.width = 32,
	},
	.dram_ch[1] = {
		.base = 0xa0000000,
		.size = 0x20000000,
		.width = 32,
	},
};
#endif

#if defined(CONFIG_ARCH_UNIPHIER_PROXSTREAM2)
static const struct uniphier_board_data proxstream2_data = {
	.dram_freq = 2133,
	.dram_nr_ch = 3,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x40000000,
		.width = 32,
	},
	.dram_ch[1] = {
		.base = 0xc0000000,
		.size = 0x20000000,
		.width = 32,
	},
	.dram_ch[2] = {
		.base = 0xe0000000,
		.size = 0x20000000,
		.width = 16,
	},
};
#endif

#if defined(CONFIG_ARCH_UNIPHIER_PH1_LD6B)
static const struct uniphier_board_data ph1_ld6b_data = {
	.dram_freq = 1866,
	.dram_nr_ch = 3,
	.dram_ch[0] = {
		.base = 0x80000000,
		.size = 0x40000000,
		.width = 32,
	},
	.dram_ch[1] = {
		.base = 0xc0000000,
		.size = 0x20000000,
		.width = 32,
	},
	.dram_ch[2] = {
		.base = 0xe0000000,
		.size = 0x20000000,
		.width = 16,
	},
};
#endif

struct uniphier_board_id {
	const char *compatible;
	const struct uniphier_board_data *param;
};

static const struct uniphier_board_id uniphier_boards[] = {
#if defined(CONFIG_ARCH_UNIPHIER_PH1_SLD3)
	{ "socionext,ph1-sld3", &ph1_sld3_data, },
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PH1_LD4)
	{ "socionext,ph1-ld4", &ph1_ld4_data, },
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PH1_PRO4)
	{ "socionext,ph1-pro4-ace", &ph1_pro4_2g_data, },
	{ "socionext,ph1-pro4-sanji", &ph1_pro4_2g_data, },
	{ "socionext,ph1-pro4", &ph1_pro4_data, },
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PH1_SLD8)
	{ "socionext,ph1-sld8", &ph1_sld8_data, },
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PH1_PRO5)
	{ "socionext,ph1-pro5", &ph1_pro5_data, },
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PROXSTREAM2)
	{ "socionext,proxstream2", &proxstream2_data, },
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PH1_LD6B)
	{ "socionext,ph1-ld6b", &ph1_ld6b_data, },
#endif
};

const struct uniphier_board_data *uniphier_get_board_param(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(uniphier_boards); i++) {
		if (!fdt_node_check_compatible(gd->fdt_blob, 0,
					       uniphier_boards[i].compatible))
			return uniphier_boards[i].param;
	}

	return NULL;
}
