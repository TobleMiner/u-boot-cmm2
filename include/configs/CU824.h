/*
 * (C) Copyright 2001-2005
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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
 *
 * Configuration settings for the CU824 board.
 *
 */

/* ------------------------------------------------------------------------- */

/*
 * board/config.h - configuration options, board specific
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */

#define CONFIG_MPC824X		1
#define CONFIG_MPC8240		1
#define CONFIG_CU824		1

#define	CONFIG_SYS_TEXT_BASE	0xFFF00000

#define CONFIG_CONS_INDEX	1
#define CONFIG_BAUDRATE		9600
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define CONFIG_PREBOOT	"echo;echo Type \\\"run flash_nfs\\\" to mount root filesystem over NFS;echo"

#define CONFIG_BOOTCOMMAND	"bootm FE020000"	/* autoboot command	*/
#define CONFIG_BOOTDELAY	5

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_BOOTFILESIZE


#define	CONFIG_TIMESTAMP		/* Print image info with timestamp */


/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_BEDBUG
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PCI
#define CONFIG_CMD_NFS
#define CONFIG_CMD_SNTP


/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP			/* undef to save memory		*/
#define CONFIG_SYS_PROMPT	"=> "		/* Monitor Command Prompt	*/
#define CONFIG_SYS_CBSIZE	256		/* Console I/O Buffer Size	*/

#if 1
#define	CONFIG_SYS_HUSH_PARSER		1	/* use "hush" command parser	*/
#endif
#ifdef	CONFIG_SYS_HUSH_PARSER
#define	CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

/* Print Buffer Size
 */
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)

#define	CONFIG_SYS_MAXARGS	16		/* max number of command args	*/
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size	*/
#define CONFIG_SYS_LOAD_ADDR	0x00100000	/* Default load address		*/

/*-----------------------------------------------------------------------
 * Start addresses for the final memory configuration
 * (Set up by the startup code)
 * Please note that CONFIG_SYS_SDRAM_BASE _must_ start at 0
 */
#define CONFIG_SYS_SDRAM_BASE	    0x00000000
#define CONFIG_SYS_FLASH_BASE	    0xFF000000

#define CONFIG_SYS_RESET_ADDRESS   0xFFF00100

#define CONFIG_SYS_EUMB_ADDR	    0xFCE00000

#define CONFIG_SYS_MONITOR_BASE    CONFIG_SYS_TEXT_BASE

#define CONFIG_SYS_MONITOR_LEN	    (256 << 10) /* Reserve 256 kB for Monitor	*/
#define CONFIG_SYS_MALLOC_LEN	    (128 << 10) /* Reserve 128 kB for malloc()	*/

#define CONFIG_SYS_MEMTEST_START   0x00004000	/* memtest works on		*/
#define CONFIG_SYS_MEMTEST_END	    0x02000000	/* 0 ... 32 MB in DRAM		*/

	/* Maximum amount of RAM.
	 */
#define CONFIG_SYS_MAX_RAM_SIZE    0x10000000


#if CONFIG_SYS_MONITOR_BASE >= CONFIG_SYS_FLASH_BASE
#undef CONFIG_SYS_RAMBOOT
#else
#define CONFIG_SYS_RAMBOOT
#endif


/*-----------------------------------------------------------------------
 * Definitions for initial stack pointer and data area
 */

	/* Size in bytes reserved for initial data
	 */
#define CONFIG_SYS_GBL_DATA_SIZE    128

#define CONFIG_SYS_INIT_RAM_ADDR     0x40000000
#define CONFIG_SYS_INIT_RAM_SIZE      0x1000
#define CONFIG_SYS_GBL_DATA_OFFSET  (CONFIG_SYS_INIT_RAM_SIZE - CONFIG_SYS_GBL_DATA_SIZE)

/*
 * NS16550 Configuration
 */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL

#define CONFIG_SYS_NS16550_REG_SIZE	4

#define CONFIG_SYS_NS16550_CLK		(14745600 / 2)

#define CONFIG_SYS_NS16550_COM1	0xFE800080
#define CONFIG_SYS_NS16550_COM2	0xFE8000C0

/*
 * Low Level Configuration Settings
 * (address mappings, register initial values, etc.)
 * You should know what you are doing if you make changes here.
 * For the detail description refer to the MPC8240 user's manual.
 */

#define CONFIG_SYS_CLK_FREQ  33000000
#define CONFIG_SYS_HZ		     1000

	/* Bit-field values for MCCR1.
	 */
#define CONFIG_SYS_ROMNAL	    0
#define CONFIG_SYS_ROMFAL	    7

	/* Bit-field values for MCCR2.
	 */
#define CONFIG_SYS_REFINT	    430	    /* Refresh interval			*/

	/* Burst To Precharge. Bits of this value go to MCCR3 and MCCR4.
	 */
#define CONFIG_SYS_BSTOPRE	    192

	/* Bit-field values for MCCR3.
	 */
#define CONFIG_SYS_REFREC	    2	    /* Refresh to activate interval	*/
#define CONFIG_SYS_RDLAT	    3	    /* Data latancy from read command	*/

	/* Bit-field values for MCCR4.
	 */
#define CONFIG_SYS_PRETOACT	    2	    /* Precharge to activate interval	*/
#define CONFIG_SYS_ACTTOPRE	    5	    /* Activate to Precharge interval	*/
#define CONFIG_SYS_SDMODE_CAS_LAT  2	    /* SDMODE CAS latancy		*/
#define CONFIG_SYS_SDMODE_WRAP	    0	    /* SDMODE wrap type			*/
#define CONFIG_SYS_SDMODE_BURSTLEN 2	    /* SDMODE Burst length		*/
#define CONFIG_SYS_ACTORW	    2
#define CONFIG_SYS_REGISTERD_TYPE_BUFFER 1

/* Memory bank settings.
 * Only bits 20-29 are actually used from these vales to set the
 * start/end addresses. The upper two bits will always be 0, and the lower
 * 20 bits will be 0x00000 for a start address, or 0xfffff for an end
 * address. Refer to the MPC8240 book.
 */

#define CONFIG_SYS_BANK0_START	    0x00000000
#define CONFIG_SYS_BANK0_END	    (CONFIG_SYS_MAX_RAM_SIZE - 1)
#define CONFIG_SYS_BANK0_ENABLE    1
#define CONFIG_SYS_BANK1_START	    0x3ff00000
#define CONFIG_SYS_BANK1_END	    0x3fffffff
#define CONFIG_SYS_BANK1_ENABLE    0
#define CONFIG_SYS_BANK2_START	    0x3ff00000
#define CONFIG_SYS_BANK2_END	    0x3fffffff
#define CONFIG_SYS_BANK2_ENABLE    0
#define CONFIG_SYS_BANK3_START	    0x3ff00000
#define CONFIG_SYS_BANK3_END	    0x3fffffff
#define CONFIG_SYS_BANK3_ENABLE    0
#define CONFIG_SYS_BANK4_START	    0x3ff00000
#define CONFIG_SYS_BANK4_END	    0x3fffffff
#define CONFIG_SYS_BANK4_ENABLE    0
#define CONFIG_SYS_BANK5_START	    0x3ff00000
#define CONFIG_SYS_BANK5_END	    0x3fffffff
#define CONFIG_SYS_BANK5_ENABLE    0
#define CONFIG_SYS_BANK6_START	    0x3ff00000
#define CONFIG_SYS_BANK6_END	    0x3fffffff
#define CONFIG_SYS_BANK6_ENABLE    0
#define CONFIG_SYS_BANK7_START	    0x3ff00000
#define CONFIG_SYS_BANK7_END	    0x3fffffff
#define CONFIG_SYS_BANK7_ENABLE    0

#define CONFIG_SYS_ODCR	    0xff

#define CONFIG_SYS_IBAT0L  (CONFIG_SYS_SDRAM_BASE | BATL_PP_10 | BATL_MEMCOHERENCE)
#define CONFIG_SYS_IBAT0U  (CONFIG_SYS_SDRAM_BASE | BATU_BL_256M | BATU_VS | BATU_VP)

#define CONFIG_SYS_IBAT1L  (CONFIG_SYS_INIT_RAM_ADDR | BATL_PP_10 | BATL_MEMCOHERENCE)
#define CONFIG_SYS_IBAT1U  (CONFIG_SYS_INIT_RAM_ADDR | BATU_BL_128K | BATU_VS | BATU_VP)

#define CONFIG_SYS_IBAT2L  (0x80000000 | BATL_PP_10 | BATL_CACHEINHIBIT)
#define CONFIG_SYS_IBAT2U  (0x80000000 | BATU_BL_256M | BATU_VS | BATU_VP)

#define CONFIG_SYS_IBAT3L  (0xFC000000 | BATL_PP_10 | BATL_CACHEINHIBIT)
#define CONFIG_SYS_IBAT3U  (0xFC000000 | BATU_BL_64M | BATU_VS | BATU_VP)

#define CONFIG_SYS_DBAT0L  CONFIG_SYS_IBAT0L
#define CONFIG_SYS_DBAT0U  CONFIG_SYS_IBAT0U
#define CONFIG_SYS_DBAT1L  CONFIG_SYS_IBAT1L
#define CONFIG_SYS_DBAT1U  CONFIG_SYS_IBAT1U
#define CONFIG_SYS_DBAT2L  CONFIG_SYS_IBAT2L
#define CONFIG_SYS_DBAT2U  CONFIG_SYS_IBAT2U
#define CONFIG_SYS_DBAT3L  CONFIG_SYS_IBAT3L
#define CONFIG_SYS_DBAT3U  CONFIG_SYS_IBAT3U

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 8 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ	    (8 << 20)	/* Initial Memory map for Linux */

/*-----------------------------------------------------------------------
 * FLASH organization
 */
#define CONFIG_SYS_MAX_FLASH_BANKS	2	/* Max number of flash banks		*/
#define CONFIG_SYS_MAX_FLASH_SECT	39	/* Max number of sectors in one bank	*/

#define CONFIG_SYS_FLASH_ERASE_TOUT	120000	/* Timeout for Flash Erase (in ms)	*/
#define CONFIG_SYS_FLASH_WRITE_TOUT	500	/* Timeout for Flash Write (in ms)	*/

	/* Warining: environment is not EMBEDDED in the U-Boot code.
	 * It's stored in flash separately.
	 */
#define CONFIG_ENV_IS_IN_FLASH	    1
#if 0
#define CONFIG_ENV_ADDR		0xFF008000
#define CONFIG_ENV_SIZE		0x8000	/* Size of the Environment Sector	*/
#else
#define CONFIG_ENV_ADDR		0xFFFC0000
#define CONFIG_ENV_SIZE		0x4000	/* Size of the Environment		*/
#define CONFIG_ENV_OFFSET		0	/* starting right at the beginning	*/
#define CONFIG_ENV_SECT_SIZE	0x40000 /* Size of the Environment Sector	*/
#endif

/*-----------------------------------------------------------------------
 * Cache Configuration
 */
#define CONFIG_SYS_CACHELINE_SIZE	32
#if defined(CONFIG_CMD_KGDB)
#  define CONFIG_SYS_CACHELINE_SHIFT	5	/* log base 2 of the above value	*/
#endif

/*-----------------------------------------------------------------------
 * PCI stuff
 *-----------------------------------------------------------------------
 */
#define CONFIG_PCI			/* include pci support			*/
#undef CONFIG_PCI_PNP

#define CONFIG_NET_MULTI		/* Multi ethernet cards support		*/

#define CONFIG_TULIP
#define CONFIG_TULIP_USE_IO

#define CONFIG_SYS_ETH_DEV_FN	     0x7800
#define CONFIG_SYS_ETH_IOBASE	     0x00104000

#define CONFIG_EEPRO100
#define CONFIG_SYS_RX_ETH_BUFFER	8               /* use 8 rx buffer on eepro100  */
#define PCI_ENET0_IOADDR	0x00104000
#define PCI_ENET0_MEMADDR	0x80000000
#endif	/* __CONFIG_H */
