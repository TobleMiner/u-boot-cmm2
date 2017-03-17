/*
 * (C) Copyright 2017 Heiko Stuebner <heiko@sntech.de>
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef _ASM_ARCH_BOOTROM_H
#define _ASM_ARCH_BOOTROM_H

/*
 * Saved Stack pointer address.
 * Access might be needed in some special cases.
 */
extern u32 SAVE_SP_ADDR;

/*
 * Hand control back to the bootrom to load another
 * boot stage.
 */
extern void back_to_bootrom(void);

#endif
