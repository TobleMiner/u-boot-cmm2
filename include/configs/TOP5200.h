/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * modified for TOP5200 by Reinhard Meyer, www.emk-elektronik.de
 * TOP5200 differences from IceCube:
 * 1 FLASH Bank for one Chip only, up to 64 MB in 16 MB Banks
 *   bank switch controlled by TIMER_6(LSB) and TIMER_7(MSB) Pins
 * 1 SDRAM/DDRAM Bank up to 256 MB
 * local VPD I2C Bus is software driven and uses
 *   GPIO_WKUP_6 for SDA, GPIO_WKUP_7 for SCL
 * FLASH is located at 0x80000000
 * Internal regs are at 0xfff00000
 * Reset jumps to 0x00000100
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

#define CONFIG_MPC5XXX		1	/* This is an MPC5xxx CPU */
#define CONFIG_MPC5200		1	/* More exactly a MPC5200 */
#define CONFIG_TOP5200		1	/* ... on TOP5200 board - we need this for FEC.C */

#define CFG_MPC5XXX_CLKIN	33333333 /* ... running at 33MHz */

#define BOOTFLAG_COLD		0x01	/* Normal Power-On: Boot from FLASH  */
#define BOOTFLAG_WARM		0x02	/* Software reboot	     */

#define CFG_CACHELINE_SIZE	32	/* For MPC5xxx CPUs */
#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#  define CFG_CACHELINE_SHIFT	5	/* log base 2 of the above value */
#endif

/*
 * Serial console configuration
 */
#define CONFIG_PSC_CONSOLE	1	/* console is on PSC1 */
#define CONFIG_BAUDRATE		9600	/* ... at 9600 bps */
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, 230400 }


#ifdef CONFIG_EVAL5200		/* PCI is supported with Evaluation board only */
/*
 * PCI Mapping:
 * 0x40000000 - 0x4fffffff - PCI Memory
 * 0x50000000 - 0x50ffffff - PCI IO Space
 */
#  define CONFIG_PCI		1
#  define CONFIG_PCI_PNP		1
#  define CONFIG_PCI_SCAN_SHOW	1

#  define CONFIG_PCI_MEM_BUS	0x40000000
#  define CONFIG_PCI_MEM_PHYS	CONFIG_PCI_MEM_BUS
#  define CONFIG_PCI_MEM_SIZE	0x10000000

#  define CONFIG_PCI_IO_BUS	0x50000000
#  define CONFIG_PCI_IO_PHYS	CONFIG_PCI_IO_BUS
#  define CONFIG_PCI_IO_SIZE	0x01000000

#  define ADD_PCI_CMD 		CFG_CMD_PCI

#else	/* no Evaluation board */

#  define ADD_PCI_CMD		0  /* no CFG_CMD_PCI */

#endif

/*
 * Supported commands
 */
#define CONFIG_COMMANDS		(CONFIG_CMD_DFL | ADD_PCI_CMD | \
				 CFG_CMD_I2C | CFG_CMD_EEPROM)

/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h>

/*
 * Autobooting
 */
#define CONFIG_BOOTDELAY	5	/* autoboot after 5 seconds */
#define CONFIG_BOOTCOMMAND	"bootm 100000"	/* autoboot command */
#define CONFIG_BOOTARGS		"root=/dev/ram rw"

/*
 * IPB Bus clocking configuration.
 */
#undef CFG_IPBSPEED_133   		/* define for 133MHz speed */

/*
 * I2C configuration
 */
/*
 * EEPROM configuration
 */
#define CFG_EEPROM_PAGE_WRITE_BITS	3
#define CFG_EEPROM_PAGE_WRITE_DELAY_MS	70

#define CFG_I2C_EEPROM_ADDR_LEN 2
#define CFG_EEPROM_SIZE 0x2000

#define CONFIG_ENV_OVERWRITE
#define CONFIG_MISC_INIT_R

#undef	CONFIG_HARD_I2C			/* I2C with hardware support */
#define	CONFIG_SOFT_I2C		1

#if defined (CONFIG_SOFT_I2C)
#  define SDA0			0x40
#  define SCL0			0x80
#  define GPIOE0		*((volatile uchar*)(CFG_MBAR+0x0c00))
#  define DDR0			*((volatile uchar*)(CFG_MBAR+0x0c08))
#  define DVO0			*((volatile uchar*)(CFG_MBAR+0x0c0c))
#  define DVI0			*((volatile uchar*)(CFG_MBAR+0x0c20))
#  define ODE0			*((volatile uchar*)(CFG_MBAR+0x0c04))
#  define I2C_INIT		{GPIOE0|=(SDA0|SCL0);ODE0|=(SDA0|SCL0);DVO0|=(SDA0|SCL0);DDR0|=(SDA0|SCL0);}
#  define I2C_READ		((DVI0&SDA0)?1:0)
#  define I2C_SDA(x)	{if(x)DVO0|=SDA0;else DVO0&=~SDA0;}
#  define I2C_SCL(x)	{if(x)DVO0|=SCL0;else DVO0&=~SCL0;}
#  define I2C_DELAY		{udelay(5);}
#  define I2C_ACTIVE	{DDR0|=SDA0;}
#  define I2C_TRISTATE	{DDR0&=~SDA0;}
#  define CFG_I2C_SPEED		100000
#  define CFG_I2C_SLAVE		0x7F
#endif

#if defined (CONFIG_HARD_I2C)
#  define CFG_I2C_MODULE	2		/* Select I2C module #1 or #2 */
#  define CFG_I2C_SPEED		100000	/* 100 kHz */
#  define CFG_I2C_SLAVE		0x7F
#endif

/*
 * Flash configuration, expect one 16 Megabyte Bank at most
 */
#define CFG_FLASH_BASE		0xff000000
#define CFG_FLASH_SIZE		0x01000000
#define CFG_MAX_FLASH_BANKS	1	/* max num of memory banks      */
#define CFG_ENV_ADDR		(CFG_FLASH_BASE + 0)

#define CFG_MAX_FLASH_SECT	256	/* max num of sects on one chip */

#define CFG_FLASH_ERASE_TOUT	240000	/* Flash Erase Timeout (in ms)  */
#define CFG_FLASH_WRITE_TOUT	500	/* Flash Write Timeout (in ms)  */

#undef CONFIG_FLASH_16BIT	/* Flash is 8-bit */

/*
 * DRAM configuration - will be read from VPD later... TODO!
 */
#if 0
/* 2x MT48LC16M16A2 - 7.0 ns SDRAMS = 64 MegaBytes Total */
#define	CFG_DRAM_DDR		0
#define CFG_DRAM_EMODE		0
#define CFG_DRAM_MODE		0x008D
#define CFG_DRAM_CONTROL	0x514F0000
#define CFG_DRAM_CONFIG1	0xC2233A00
#define CFG_DRAM_CONFIG2	0x88B70004
#define	CFG_DRAM_TAP_DEL	0x08
#define CFG_DRAM_RAM_SIZE	0x19
#endif
#if 1
/* 2x MT48LC16M16A2 - 7.5 ns SDRAMS = 64 MegaBytes Total */
#define	CFG_DRAM_DDR		0
#define CFG_DRAM_EMODE		0
#define CFG_DRAM_MODE		0x00CD
#define CFG_DRAM_CONTROL	0x514F0000
#define CFG_DRAM_CONFIG1	0xD2333A00
#define CFG_DRAM_CONFIG2	0x8AD70004
#define	CFG_DRAM_TAP_DEL	0x08
#define CFG_DRAM_RAM_SIZE	0x19
#endif

/*
 * Environment settings
 */
#define CFG_ENV_IS_IN_EEPROM	1	/* turn on EEPROM env feature */
#define CFG_ENV_OFFSET		0x1000
#define CFG_ENV_SIZE		0x0700
#define CFG_I2C_EEPROM_ADDR 0x57

/*
 * VPD settings
 */
#define CFG_FACT_OFFSET		0x1800
#define CFG_FACT_SIZE		0x0800
#define CFG_I2C_FACT_ADDR	0x57

/*
 * Memory map
 *
 * Warning!!! with the current BestComm Task, MBAR MUST BE set to 0xf0000000
 */
#define CFG_MBAR			0xf0000000	/* DO NOT CHANGE this */
#define CFG_SDRAM_BASE		0x00000000
#define CFG_DEFAULT_MBAR	0x80000000

/* Use SRAM until RAM will be available */
#define CFG_INIT_RAM_ADDR	MPC5XXX_SRAM
#define CFG_INIT_RAM_END	MPC5XXX_SRAM_SIZE	/* End of used area in DPRAM */


#define CFG_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */
#define CFG_GBL_DATA_OFFSET	(CFG_INIT_RAM_END - CFG_GBL_DATA_SIZE)
#define CFG_INIT_SP_OFFSET	CFG_GBL_DATA_OFFSET

#define CFG_MONITOR_BASE    TEXT_BASE
#if (CFG_MONITOR_BASE < CFG_FLASH_BASE)
#   define CFG_RAMBOOT		1
#endif

#define CFG_MONITOR_LEN		(256 << 10)	/* Reserve 256 kB for Monitor	*/
#define CFG_MALLOC_LEN		(128 << 10)	/* Reserve 128 kB for malloc()	*/
#define CFG_BOOTMAPSZ		(8 << 20)	/* Initial Memory map for Linux */

/*
 * Ethernet configuration
 */
#define CONFIG_MPC5XXX_FEC	1
#define CONFIG_FEC_10MBIT	1		/* Workaround for FEC 100Mbit problem */
#define	CONFIG_PHY_ADDR		0x1f
#define	CONFIG_PHY_TYPE		0x79c874
/*
 * GPIO configuration:
 * PSC1,2,3 predefined as UART
 * PCI disabled
 * Ethernet 100 with MD
 */
#define CFG_GPS_PORT_CONFIG	0x00058444

/*
 * Miscellaneous configurable options
 */
#define CFG_LONGHELP			/* undef to save memory	    */
#define CFG_PROMPT		"=> "	/* Monitor Command Prompt   */
#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#  define CFG_CBSIZE		1024	/* Console I/O Buffer Size  */
#else
#  define CFG_CBSIZE		256	/* Console I/O Buffer Size  */
#endif
#define CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16)	/* Print Buffer Size */
#define CFG_MAXARGS		16		/* max number of command args	*/
#define CFG_BARGSIZE		CFG_CBSIZE	/* Boot Argument Buffer Size	*/

#define CFG_MEMTEST_START	0x00100000	/* memtest works on */
#define CFG_MEMTEST_END		0x01f00000	/* 1 ... 31 MB in DRAM	*/

#define CFG_LOAD_ADDR		0x100000	/* default load address */

#define CFG_HZ			1000	/* decrementer freq: 1 ms ticks */

/*
 * Various low-level settings
 */
#define CFG_HID0_INIT		HID0_ICE | HID0_ICFI
#define CFG_HID0_FINAL		HID0_ICE

#define CFG_BOOTCS_START	CFG_FLASH_BASE
#define CFG_BOOTCS_SIZE		CFG_FLASH_SIZE
#define CFG_BOOTCS_CFG		0x00047801
#define CFG_CS0_START		CFG_FLASH_BASE
#define CFG_CS0_SIZE		CFG_FLASH_SIZE

#define CFG_CS_BURST		0x00000000
#define CFG_CS_DEADCYCLE	0x33333333

#define CFG_RESET_ADDRESS	0x7f000000

#endif /* __CONFIG_H */
