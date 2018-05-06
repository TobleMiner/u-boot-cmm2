/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2016 Grinn
 */

#ifndef __ARCH_ARM_MX6UL_LITESOM_H__
#define __ARCH_ARM_MX6UL_LITESOM_H__

int litesom_mmc_init(bd_t *bis);

#ifdef CONFIG_SPL_BUILD
void litesom_init_f(void);
#endif

#endif
