/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2019 NVIDIA Corporation. All rights reserved.
 */

#ifndef _TEGRA_CBOOT_H_
#define _TEGRA_CBOOT_H_

#ifdef CONFIG_ARM64
extern unsigned long cboot_boot_x0;

void cboot_save_boot_params(unsigned long x0, unsigned long x1,
			    unsigned long x2, unsigned long x3);
int cboot_dram_init(void);
int cboot_dram_init_banksize(void);
ulong cboot_get_usable_ram_top(ulong total_size);
#else
static inline void cboot_save_boot_params(unsigned long x0, unsigned long x1,
					  unsigned long x2, unsigned long x3)
{
}

static inline int cboot_dram_init(void)
{
	return -ENOSYS;
}

static inline int cboot_dram_init_banksize(void)
{
	return -ENOSYS;
}

static inline ulong cboot_get_usable_ram_top(ulong total_size)
{
	return 0;
}
#endif

#endif
