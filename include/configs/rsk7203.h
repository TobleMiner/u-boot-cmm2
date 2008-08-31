/*
 * Configuation settings for the Renesas Technology RSK 7203
 *
 * Copyright (C) 2008 Nobuhiro Iwamatsu
 * Copyright (C) 2008 Renesas Solutions Corp.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __RSK7203_H
#define __RSK7203_H

#undef DEBUG
#define CONFIG_SH		1
#define CONFIG_SH2		1
#define CONFIG_SH2A		1
#define CONFIG_CPU_SH7203	1
#define CONFIG_RSK7203	1

#define CONFIG_CMD_FLASH
#define CONFIG_CMD_NET
#define CONFIG_CMD_NFS
#define CONFIG_CMD_PING
#define CONFIG_CMD_ENV
#define CONFIG_CMD_SDRAM
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_CACHE

#define CONFIG_BAUDRATE		115200
#define CONFIG_BOOTARGS		"console=ttySC0,115200"
#define CONFIG_LOADADDR		0x0C100000 /* RSK7203_SDRAM_BASE + 1MB */

#define CONFIG_VERSION_VARIABLE
#undef	CONFIG_SHOW_BOOT_PROGRESS

/* MEMORY */
#define RSK7203_SDRAM_BASE	0x0C000000
#define RSK7203_FLASH_BASE_1	0x20000000	/* Non cache */
#define RSK7203_FLASH_BANK_SIZE	(4 * 1024 * 1024)

#define CFG_LONGHELP		/* undef to save memory	*/
#define CFG_PROMPT	"=> "	/* Monitor Command Prompt */
#define CFG_CBSIZE	256	/* Buffer size for input from the Console */
#define CFG_PBSIZE	256	/* Buffer size for Console output */
#define CFG_MAXARGS	16	/* max args accepted for monitor commands */
/* Buffer size for Boot Arguments passed to kernel */
#define CFG_BARGSIZE	512
/* List of legal baudrate settings for this board */
#define CFG_BAUDRATE_TABLE	{ 115200 }

/* SCIF */
#define CFG_SCIF_CONSOLE	1
#define CONFIG_CONS_SCIF0	1

#define CFG_MEMTEST_START	RSK7203_SDRAM_BASE
#define CFG_MEMTEST_END		(CFG_MEMTEST_START + (3 * 1024 * 1024))

#define CFG_SDRAM_BASE		RSK7203_SDRAM_BASE
#define CFG_SDRAM_SIZE		(32 * 1024 * 1024)

#define CFG_LOAD_ADDR		(CFG_SDRAM_BASE + 1024 * 1024)
#define CFG_MONITOR_BASE	RSK7203_FLASH_BASE_1
#define CFG_MONITOR_LEN		(128 * 1024)
#define CFG_MALLOC_LEN		(256 * 1024)
#define CFG_GBL_DATA_SIZE	256
#define CFG_BOOTMAPSZ		(8 * 1024 * 1024)

/* FLASH */
#define CFG_FLASH_CFI
#define CFG_FLASH_CFI_WIDTH FLASH_CFI_16BIT
#define CFG_FLASH_CFI_DRIVER
#undef	CFG_FLASH_QUIET_TEST
#define CFG_FLASH_EMPTY_INFO	/* print 'E' for empty sector on flinfo */
#define CFG_FLASH_BASE		RSK7203_FLASH_BASE_1
#define CFG_FLASH_BANKS_LIST	{ CFG_FLASH_BASE }
#define CFG_MAX_FLASH_SECT	64
#define CFG_MAX_FLASH_BANKS	1

#define CFG_ENV_IS_IN_FLASH
#define CFG_ENV_SECT_SIZE	(64 * 1024)
#define CFG_ENV_SIZE		CFG_ENV_SECT_SIZE
#define CFG_ENV_ADDR		(CFG_MONITOR_BASE + CFG_MONITOR_LEN)
#define CFG_FLASH_ERASE_TOUT	12000
#define CFG_FLASH_WRITE_TOUT	500

/* Board Clock */
#define CONFIG_SYS_CLK_FREQ	33333333
#define CMT_CLK_DIVIDER	32	/* 8 (default), 32, 128 or 512 */
#define CFG_HZ			(CONFIG_SYS_CLK_FREQ / CMT_CLK_DIVIDER)

#endif	/* __RSK7203_H */
