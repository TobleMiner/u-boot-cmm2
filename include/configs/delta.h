/*
 * Configuation settings for the Delta board.
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

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_CPU_MONAHANS	1	/* Intel Monahan CPU    */
#define CONFIG_DELTA		1	/* Delta board       */

/* #define CONFIG_LCD		1 */
#ifdef CONFIG_LCD
#define CONFIG_SHARP_LM8V31
#endif
/* #define CONFIG_MMC		1 */
#define BOARD_LATE_INIT		1

#undef CONFIG_SKIP_RELOCATE_UBOOT
#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */

/*
 * Size of malloc() pool
 */
#define CFG_MALLOC_LEN	    (CFG_ENV_SIZE + 256*1024)
#define CFG_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */

#undef TURN_ON_ETHERNET
#ifdef TURN_ON_ETHERNET
# define CONFIG_DRIVER_SMC91111 1
# define CONFIG_SMC91111_BASE   0x14000300
# define CONFIG_SMC91111_EXT_PHY
# define CONFIG_SMC_USE_32_BIT
# undef CONFIG_SMC_USE_IOFUNCS          /* just for use with the kernel */
#endif

/*
 * select serial console configuration
 */
#define CONFIG_FFUART	       1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/* #define CONFIG_COMMANDS       (CONFIG_CMD_DFL | CFG_CMD_MMC | CFG_CMD_FAT) */
#ifdef TURN_ON_ETHERNET
# define CONFIG_COMMANDS        (CONFIG_CMD_DFL | CFG_CMD_PING)
#else
# define CONFIG_COMMANDS	((CONFIG_CMD_DFL | CFG_CMD_NAND) \
				& ~(CFG_CMD_NET | CFG_CMD_FLASH | \
				    CFG_CMD_ENV | CFG_CMD_IMLS))
#endif


/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h>

#define CONFIG_BOOTDELAY	-1
#define CONFIG_ETHADDR		08:00:3e:26:0a:5b
#define CONFIG_NETMASK		255.255.0.0
#define CONFIG_IPADDR		192.168.0.21
#define CONFIG_SERVERIP		192.168.0.250
#define CONFIG_BOOTCOMMAND	"bootm 80000"
#define CONFIG_BOOTARGS		"root=/dev/mtdblock2 rootfstype=cramfs console=ttyS0,115200"
#define CONFIG_CMDLINE_TAG
#define CONFIG_TIMESTAMP

#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	230400		/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	2		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define CFG_HUSH_PARSER		1
#define CFG_PROMPT_HUSH_PS2	"> "

#define CFG_LONGHELP				/* undef to save memory		*/
#ifdef CFG_HUSH_PARSER
#define CFG_PROMPT		"$ "		/* Monitor Command Prompt */
#else
#define CFG_PROMPT		"=> "		/* Monitor Command Prompt */
#endif
#define CFG_CBSIZE		256		/* Console I/O Buffer Size	*/
#define CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */
#define CFG_MAXARGS		16		/* max number of command args	*/
#define CFG_BARGSIZE		CFG_CBSIZE	/* Boot Argument Buffer Size	*/
#define CFG_DEVICE_NULLDEV	1

#define CFG_MEMTEST_START	0xa0400000	/* memtest works on	*/
#define CFG_MEMTEST_END		0xa0800000	/* 4 ... 8 MB in DRAM	*/

#undef	CFG_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define CFG_LOAD_ADDR	(CFG_DRAM_BASE + 0x8000) /* default load address */

#define CFG_HZ			3686400		/* incrementer freq: 3.6864 MHz */
#define CFG_CPUSPEED		0x161		/* set core clock to 400/200/100 MHz */

						/* valid baudrates */
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/* #define CFG_MMC_BASE		0xF0000000 */

/*
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	4	   /* we have 2 banks of DRAM */
#define PHYS_SDRAM_1		0xa0000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x1000000  /* 64 MB */
#define PHYS_SDRAM_2		0xa1000000 /* SDRAM Bank #2 */
#define PHYS_SDRAM_2_SIZE	0x1000000  /* 64 MB */
#define PHYS_SDRAM_3		0xa2000000 /* SDRAM Bank #3 */
#define PHYS_SDRAM_3_SIZE	0x1000000  /* 64 MB */
#define PHYS_SDRAM_4		0xa3000000 /* SDRAM Bank #4 */
#define PHYS_SDRAM_4_SIZE	0x1000000  /* 64 MB */

#define CFG_DRAM_BASE		0xa0000000 /* at CS0 */
#define CFG_DRAM_SIZE		0x04000000 /* 64 MB Ram */

#undef CFG_SKIP_DRAM_SCRUB

/*
 * NAND Flash
 */
/* Use the new NAND code. (BOARDLIBS = drivers/nand/libnand.a required) */
#define CONFIG_NEW_NAND_CODE
#define CFG_NAND0_BASE		0x0 /* 0x43100040 */ /* 0x10000000 */
#undef CFG_NAND1_BASE

#define CFG_NAND_BASE_LIST	{ CFG_NAND0_BASE }
#define CFG_MAX_NAND_DEVICE	1	/* Max number of NAND devices */
#define SECTORSIZE 		512
#define NAND_DELAY_US		25	/* mk@tbd: could be 0, I guess */

/* nand timeout values */	
#define CFG_NAND_PROG_ERASE_TO	3000
#define CFG_NAND_OTHER_TO	100
#define CFG_NAND_SENDCMD_RETRY	3
#undef NAND_ALLOW_ERASE_ALL	/* Allow erasing bad blocks - don't use */

/* NAND Timing Parameters (in ns) */
#define NAND_TIMING_tCH 	10
#define NAND_TIMING_tCS 	0
#define NAND_TIMING_tWH		20
#define NAND_TIMING_tWP 	40

#define NAND_TIMING_tRH 	20
#define NAND_TIMING_tRP 	40

#define NAND_TIMING_tR  	11123
/* #define NAND_TIMING_tWHR	110 */
#define NAND_TIMING_tWHR	100
#define NAND_TIMING_tAR		10

/* NAND debugging */
#define CFG_DFC_DEBUG1 /* usefull */
#undef CFG_DFC_DEBUG2  /* noisy */
#undef CFG_DFC_DEBUG3  /* extremly noisy  */

#define CONFIG_MTD_DEBUG
#define CONFIG_MTD_DEBUG_VERBOSE 1

#define ADDR_COLUMN 1
#define ADDR_PAGE 2
#define ADDR_COLUMN_PAGE 3

#define NAND_ChipID_UNKNOWN	0x00
#define NAND_MAX_FLOORS 1
#define NAND_MAX_CHIPS 1

#define CFG_NO_FLASH	1
#ifndef CGF_NO_FLASH
/* these are required by the environment code */
#define PHYS_FLASH_1            CFG_NAND0_BASE /* Flash Bank #1 */
#define PHYS_FLASH_SIZE         0x04000000 /* 64 MB */
#define PHYS_FLASH_BANK_SIZE    0x04000000 /* 64 MB Banks */
#define PHYS_FLASH_SECT_SIZE    (SECTORSIZE*1024) /*  KB sectors (x2) */
#endif

/*
 * GPIO settings
 */
#define CFG_GPSR0_VAL		0x00008000
#define CFG_GPSR1_VAL		0x00FC0382
#define CFG_GPSR2_VAL		0x0001FFFF
#define CFG_GPCR0_VAL		0x00000000
#define CFG_GPCR1_VAL		0x00000000
#define CFG_GPCR2_VAL		0x00000000
#define CFG_GPDR0_VAL		0x0060A800
#define CFG_GPDR1_VAL		0x00FF0382
#define CFG_GPDR2_VAL		0x0001C000
#define CFG_GAFR0_L_VAL		0x98400000
#define CFG_GAFR0_U_VAL		0x00002950
#define CFG_GAFR1_L_VAL		0x000A9558
#define CFG_GAFR1_U_VAL		0x0005AAAA
#define CFG_GAFR2_L_VAL		0xA0000000
#define CFG_GAFR2_U_VAL		0x00000002

#define CFG_PSSR_VAL		0x20

/*
 * Memory settings
 */
#define CFG_MSC0_VAL		0x23F223F2
#define CFG_MSC1_VAL		0x3FF1A441
#define CFG_MSC2_VAL		0x7FF97FF1
#define CFG_MDCNFG_VAL		0x00001AC9
#define CFG_MDREFR_VAL		0x00018018
#define CFG_MDMRS_VAL		0x00000000

/*
 * PCMCIA and CF Interfaces
 */
#define CFG_MECR_VAL		0x00000000
#define CFG_MCMEM0_VAL		0x00010504
#define CFG_MCMEM1_VAL		0x00010504
#define CFG_MCATT0_VAL		0x00010504
#define CFG_MCATT1_VAL		0x00010504
#define CFG_MCIO0_VAL		0x00004715
#define CFG_MCIO1_VAL		0x00004715

#define _LED			0x08000010
#define LED_BLANK		0x08000040

/*
 * FLASH and environment organization
 */
#ifndef CFG_NO_FLASH
#define CFG_MAX_FLASH_BANKS	2	/* max number of memory banks		*/
#define CFG_MAX_FLASH_SECT	128  /* max number of sectors on one chip    */

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(25*CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(25*CFG_HZ) /* Timeout for Flash Write */


/* NOTE: many default partitioning schemes assume the kernel starts at the
 * second sector, not an environment.  You have been warned!
 */
#define	CFG_MONITOR_LEN		PHYS_FLASH_SECT_SIZE
#endif /* #ifndef CFG_NO_FLASH */

#define CFG_ENV_IS_NOWHERE
/* #define CFG_ENV_IS_IN_NAND      1 */
#define CFG_ENV_OFFSET		0x40000
#define CFG_ENV_SIZE		0x4000

#endif	/* __CONFIG_H */
