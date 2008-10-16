/*
 * (C) Copyright 2008
 *  Ricado Ribalda-Universidad Autonoma de Madrid-ricardo.ribalda@uam.es
 *  This work has been supported by: QTechnology  http://qtec.com/
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __CONFIG_GEN_H
#define __CONFIG_GEN_H
/*
#define DEBUG
#define ET_DEBUG
*/
 /*CPU*/
#define CONFIG_XILINX_440	1
#define CONFIG_440		1
#define CONFIG_4xx		1

/*Mem Map*/
#define CONFIG_SYS_SDRAM_BASE		0x0
#define CONFIG_SYS_MONITOR_BASE	TEXT_BASE
#define CONFIG_SYS_MONITOR_LEN		(192 * 1024)
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 128 * 1024)

/*Uart*/
#define CONFIG_XILINX_UARTLITE
#define CONFIG_BAUDRATE		XPAR_UARTLITE_0_BAUDRATE
#define CONFIG_SYS_BAUDRATE_TABLE	{ XPAR_UARTLITE_0_BAUDRATE }
#define CONFIG_SERIAL_BASE	XPAR_UARTLITE_0_BASEADDR

/*Cmd*/
#include <config_cmd_default.h>
#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_DIAG
#define CONFIG_CMD_ELF
#define CONFIG_CMD_IRQ
#define CONFIG_CMD_REGINFO
#define CONFIG_CMD_JFFS2
#define CONFIG_JFFS2_CMDLINE
#undef CONFIG_CMD_SPI
#undef CONFIG_CMD_I2C
#undef CONFIG_CMD_DTT
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_PING
#undef CONFIG_CMD_DHCP
#undef CONFIG_CMD_EEPROM
#undef CONFIG_CMD_IMLS

/*Misc*/
#define CONFIG_BOOTDELAY	5	/* autoboot after 5 seconds     */
#define CONFIG_SYS_LONGHELP			/* undef to save memory         */
#if defined(CONFIG_CMD_KGDB)
#define CONFIG_SYS_CBSIZE		1024	/* Console I/O Buffer Size      */
#else
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size      */
#endif
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command args   */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size */
#define CONFIG_SYS_MEMTEST_START	0x00400000	/* memtest works on           */
#define CONFIG_SYS_MEMTEST_END		0x00C00000	/* 4 ... 12 MB in DRAM        */
#define CONFIG_SYS_LOAD_ADDR		0x00400000	/* default load address       */
#define CONFIG_SYS_EXTBDINFO		1	/* Extended board_into (bd_t) */
#define CONFIG_SYS_HZ			1000	/* decrementer freq: 1 ms ticks */
#define CONFIG_CMDLINE_EDITING		/* add command line history     */
#define CONFIG_AUTO_COMPLETE		/* add autocompletion support   */
#define CONFIG_LOOPW			/* enable loopw command         */
#define CONFIG_MX_CYCLIC		/* enable mdc/mwc commands      */
#define CONFIG_ZERO_BOOTDELAY_CHECK	/* check for keypress on bootdelay==0 */
#define CONFIG_VERSION_VARIABLE		/* include version env variable */
#define CONFIG_SYS_CONSOLE_INFO_QUIET		/* don't print console @ startup */
#define CONFIG_SYS_HUSH_PARSER			/* Use the HUSH parser          */
#define	CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_LOADS_ECHO		/* echo on for serial download  */
#define CONFIG_SYS_LOADS_BAUD_CHANGE		/* allow baudrate change        */
#define CONFIG_SYS_BOOTMAPSZ		(8 << 20)/* Initial Memory map for Linux */

/*Stack*/
#define CONFIG_SYS_INIT_RAM_ADDR	0x800000	/* Initial RAM address    */
#define CONFIG_SYS_INIT_RAM_END	0x2000		/* End of used area in RAM  */
#define CONFIG_SYS_GBL_DATA_SIZE	128		/* num bytes initial data   */
#define CONFIG_SYS_GBL_DATA_OFFSET	(CONFIG_SYS_INIT_RAM_END - CONFIG_SYS_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_OFFSET	CONFIG_SYS_GBL_DATA_OFFSET
/*Speed*/
#define CONFIG_SYS_CLK_FREQ	XPAR_CORE_CLOCK_FREQ_HZ

/*Flash*/
#define	CONFIG_SYS_FLASH_BASE		XPAR_FLASH_MEM0_BASEADDR
#define	CONFIG_SYS_FLASH_CFI		1
#define	CONFIG_FLASH_CFI_DRIVER	1
#define	CONFIG_SYS_FLASH_EMPTY_INFO	1
#define	CONFIG_SYS_MAX_FLASH_BANKS	1
#define	CONFIG_SYS_FLASH_PROTECTION

#endif						/* __CONFIG_H */
