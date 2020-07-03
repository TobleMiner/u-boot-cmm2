/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2012 Atmel Corporation
 * Copyright (C) 2019 Stefan Roese <sr@denx.de>
 *
 * Configuation settings for the GARDENA smart Gateway (AT91SAM9G25)
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#ifndef __ASSEMBLY__
#include <linux/bitops.h>
#endif

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_SLOW_CLOCK	32768
#define CONFIG_SYS_AT91_MAIN_CLOCK	12000000	/* 12 MHz crystal */

#ifndef CONFIG_SPL_BUILD
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif
#define CONFIG_SKIP_LOWLEVEL_INIT_ONLY

/* general purpose I/O */
#define CONFIG_ATMEL_LEGACY		/* required until (g)pio is fixed */

/* SDRAM */
#define CONFIG_SYS_SDRAM_BASE		0x20000000
#define CONFIG_SYS_SDRAM_SIZE		0x08000000	/* 128 megs */

#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_SDRAM_BASE + 16 * 1024 - GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_MALLOC_LEN		(16 * 1024 * 1024)

/* NAND flash */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x40000000
#define CONFIG_SYS_NAND_DBW_8		1
/* our ALE is AD21 */
#define CONFIG_SYS_NAND_MASK_ALE	BIT(21)
/* our CLE is AD22 */
#define CONFIG_SYS_NAND_MASK_CLE	BIT(22)
#define CONFIG_SYS_NAND_ENABLE_PIN	AT91_PIN_PD4
#define CONFIG_SYS_NAND_READY_PIN	AT91_PIN_PD5

#define CONFIG_SYS_LOAD_ADDR		0x22000000	/* load address */

/* SPL */
#define CONFIG_SPL_MAX_SIZE		0x7000
#define CONFIG_SPL_STACK		0x308000

#define CONFIG_SPL_BSS_START_ADDR	0x20000000
#define CONFIG_SPL_BSS_MAX_SIZE		0x80000
#define CONFIG_SYS_SPL_MALLOC_START	0x20080000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x80000

#define CONFIG_SYS_MONITOR_LEN		(512 << 10)

#define CONFIG_SYS_MASTER_CLOCK		132096000
#define CONFIG_SYS_AT91_PLLA		0x20c73f03
#define CONFIG_SYS_MCKR			0x1301
#define CONFIG_SYS_MCKR_CSS		0x1302

#define CONFIG_SPL_NAND_RAW_ONLY
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x40000
#define CONFIG_SYS_NAND_U_BOOT_SIZE	0xa0000
#define	CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_NAND_U_BOOT_DST	CONFIG_SYS_TEXT_BASE

#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_PAGE_SIZE	0x800
#define CONFIG_SYS_NAND_PAGE_COUNT	64
#define CONFIG_SYS_NAND_OOBSIZE		64
#define CONFIG_SYS_NAND_BLOCK_SIZE	0x20000
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	0x0

#define CONFIG_SPL_PAD_TO		CONFIG_SYS_NAND_U_BOOT_OFFS
#define CONFIG_SYS_SPL_LEN		CONFIG_SPL_PAD_TO

#endif
