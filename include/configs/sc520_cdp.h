/*
 * (C) Copyright 2002
 * Daniel Engstr�m, Omicron Ceti AB, daniel@omicron.se.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * board/config.h - configuration options, board specific
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */

#define CONFIG_X86		1	/* This is a X86 CPU		*/

#define CFG_SDRAM_PRECHARGE_DELAY 6     /* 6T */	
#define CFG_SDRAM_REFRESH_RATE    78    /* 7.8uS (choices are 7.8, 15.6, 31.2 or 62.5uS) */
#define CFG_SDRAM_RAS_CAS_DELAY   3     /* 3T */

/* define at most one of these */
#undef CFG_SDRAM_CAS_LATENCY_2T
#define CFG_SDRAM_CAS_LATENCY_3T

#define CFG_SC520_HIGH_SPEED    0       /* 100 or 133MHz */
#define CFG_RESET_GENERIC       1       /* use tripple-fault to reset cpu */
#undef  CFG_RESET_SC520                 /* use SC520 MMCR's to reset cpu */
#undef  CFG_TIMER_SC520                 /* use SC520 swtimers */
#define CFG_TIMER_GENERIC       1       /* use the i8254 PIT timers */
#undef  CFG_TIMER_TSC                   /* use the Pentium TSC timers */
#define  CFG_USE_SIO_UART       0       /* prefer the uarts on the SIO to those
					 * in the SC520 on the CDP */

#define CFG_STACK_SIZE          0x8000  /* Size of bootloader stack */

#define CONFIG_SHOW_BOOT_PROGRESS 1
#define CONFIG_LAST_STAGE_INIT    1

/*
 * Size of malloc() pool
 */
#define CONFIG_MALLOC_SIZE	(CFG_ENV_SIZE + 128*1024)


/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CFG_ENV_IS_NOWHERE 1
#undef CFG_ENV_IS_IN_FLASH 
#undef CFG_ENV_IS_IN_NVRAM 
#undef CFG_ENV_IS_INEEPROM

#define CONFIG_BAUDRATE		9600

#define CONFIG_COMMANDS         (CONFIG_CMD_DFL | CFG_CMD_PCI | CFG_CMD_JFFS2 | CFG_CMD_IDE | CFG_CMD_NET)

/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h>

#define CONFIG_BOOTDELAY	15
#define CONFIG_BOOTARGS    	"root=/dev/mtdblock0 console=ttyS0,9600"
/* #define CONFIG_BOOTCOMMAND	"bootm 38000000" */

#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200		/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	2		/* which serial port to use */
#endif

#define CFG_JFFS2_FIRST_BANK    0           /* use for JFFS2 */
#define CFG_JFFS2_NUM_BANKS     1           /*  */

/*
 * Miscellaneous configurable options
 */
#define	CFG_LONGHELP				/* undef to save memory		*/
#define	CFG_PROMPT		"boot > "	/* Monitor Command Prompt	*/
#define	CFG_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */
#define	CFG_MAXARGS		16		/* max number of command args	*/
#define CFG_BARGSIZE		CFG_CBSIZE	/* Boot Argument Buffer Size	*/

#define CFG_MEMTEST_START	0x00100000	/* memtest works on	*/
#define CFG_MEMTEST_END		0x01000000	/* 1 ... 16 MB in DRAM	*/

#undef  CFG_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define	CFG_LOAD_ADDR		0x38000000	/* default load address	*/

#define	CFG_HZ			1024		/* incrementer freq: 1kHz */

						/* valid baudrates */
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }


/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	4	   /* we have 4 banks of DRAM */


#define PHYS_FLASH_1		0x38000000 /* Flash Bank #1 */
#define PHYS_FLASH_SIZE		0x00800000 /* 8 MB */

#define CFG_FLASH_BASE		PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks		*/
#define CFG_MAX_FLASH_SECT	64	/* max number of sectors on one chip	*/

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(2*CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(2*CFG_HZ) /* Timeout for Flash Write */

#define	CFG_ENV_IS_IN_FLASH	1
#define CFG_ENV_ADDR		(PHYS_FLASH_1 + 0x7a0000)	/* Addr of Environment Sector	*/
#define CFG_ENV_SIZE		0x4000	/* Total Size of Environment Sector	*/


/*-----------------------------------------------------------------------
 * Device drivers
 */
#define CONFIG_NET_MULTI        /* Multi ethernet cards support */
#define CONFIG_PCNET
#define CONFIG_PCNET_79C973
#define CONFIG_PCNET_79C975
#define PCNET_HAS_PROM         1
/************************************************************
 * IDE/ATA stuff
 ************************************************************/
#define CFG_IDE_MAXBUS		2   /* max. 2 IDE busses	*/
#define CFG_IDE_MAXDEVICE	(CFG_IDE_MAXBUS*2) /* max. 2 drives per IDE bus */

#define CFG_ATA_IDE0_OFFSET	0x01F0	/* ide0 offste */
#define CFG_ATA_IDE1_OFFSET	0x0170	/* ide1 offset */
#define CFG_ATA_DATA_OFFSET	0	/* data reg offset	*/
#define CFG_ATA_REG_OFFSET	0	/* reg offset */
#define CFG_ATA_ALT_OFFSET	0x200	/* alternate register offset */

#undef	CONFIG_IDE_8xx_DIRECT		/* no pcmcia interface required */
#undef	CONFIG_IDE_LED			/* no led for ide supported	*/
#undef  CONFIG_IDE_RESET		/* reset for ide unsupported...	*/
#undef  CONFIG_IDE_RESET_ROUTINE	/* no special reset function */

/************************************************************
 * ATAPI support (experimental)
 ************************************************************/
#define CONFIG_ATAPI			/* enable ATAPI Support */

/************************************************************
 * DISK Partition support
 ************************************************************/
#define CONFIG_DOS_PARTITION
#define CONFIG_MAC_PARTITION
#define CONFIG_ISO_PARTITION /* Experimental */

/************************************************************
 * Keyboard support
 ************************************************************/
#define CONFIG_ISA_KEYBOARD

#if 0
/************************************************************
 * Video support
 ************************************************************/
#define CONFIG_VIDEO			/*To enable video controller support */
#define CONFIG_VIDEO_CT69000
#define CONFIG_CFB_CONSOLE
#define CONFIG_VIDEO_LOGO
#define CONFIG_CONSOLE_EXTRA_INFO
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_VIDEO_SW_CURSOR
#define CONFIG_VIDEO_ONBOARD		/* Video controller is on-board */
#endif

/************************************************************
 * RTC
 ***********************************************************/
#define CONFIG_RTC_MC146818
#undef CONFIG_WATCHDOG			/* watchdog disabled		*/

/*
 * PCI stuff
 */
#define CONFIG_PCI                                /* include pci support */
#define CONFIG_PCI_PNP                            /* pci plug-and-play */
#define CONFIG_PCI_SCAN_SHOW

#endif	/* __CONFIG_H */
