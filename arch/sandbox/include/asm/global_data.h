/*
 * Copyright (c) 2011 The Chromium OS Authors.
 *
 * (C) Copyright 2002-2010
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef	__ASM_GBL_DATA_H
#define __ASM_GBL_DATA_H

/* Architecture-specific global data */
struct arch_global_data {
	u8		*ram_buf;	/* emulated RAM buffer */
};

#include <asm-generic/global_data.h>

#define DECLARE_GLOBAL_DATA_PTR     extern gd_t *gd

#endif /* __ASM_GBL_DATA_H */
