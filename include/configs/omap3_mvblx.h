/*
 * MATRIX VISION GmbH mvBlueLYNX-X
 *
 * Derived from omap3_beagle.h:
 * (C) Copyright 2006-2008
 * Texas Instruments.
 * Richard Woodruff <r-woodruff2@ti.com>
 * Syed Mohammed Khasim <x0khasim@ti.com>
 *
 * Configuration settings for the TI OMAP3530 Beagle board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 */
#define CONFIG_OMAP		1	/* in a TI OMAP core */
#define CONFIG_MVBLX		1	/* working with mvBlueLYNX-X */
#define CONFIG_MACH_TYPE	MACH_TYPE_MVBLX
#define CONFIG_OMAP_GPIO
#define CONFIG_OMAP_COMMON
/* Common ARM Erratas */
#define CONFIG_ARM_ERRATA_454179
#define CONFIG_ARM_ERRATA_430973
#define CONFIG_ARM_ERRATA_621766

#define CONFIG_SDRC	/* The chip has SDRC controller */

#include <asm/arch/cpu.h>		/* get chip and board defs */
#include <asm/arch/omap.h>

/*
 * Display CPU and Board information
 */
#define CONFIG_DISPLAY_CPUINFO		1
#define CONFIG_DISPLAY_BOARDINFO	1

/* Clock Defines */
#define V_OSCK			26000000	/* Clock output from T2 */
#define V_SCLK			(V_OSCK >> 1)

#define CONFIG_MISC_INIT_R

#define CONFIG_OF_LIBFDT		1

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_INITRD_TAG		1
#define CONFIG_REVISION_TAG		1
#define CONFIG_SERIAL_TAG		1

/*
 * Size of malloc() pool
 */
#define CONFIG_ENV_SIZE			(2 << 10)	/* 2 KiB */
						/* Sector */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (128 << 10))

/*
 * Hardware drivers
 */

/*
 * NS16550 Configuration
 */
#define V_NS16550_CLK			48000000	/* 48MHz (APLL96/2) */

#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		V_NS16550_CLK

/*
 * select serial console configuration
 */
#define CONFIG_CONS_INDEX		1
#define CONFIG_SYS_NS16550_COM1		OMAP34XX_UART1
#define CONFIG_SERIAL1			1	/* UART1 */

#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{4800, 9600, 19200, 38400, 57600,\
					115200}
#define CONFIG_GENERIC_MMC		1
#define CONFIG_MMC			1
#define CONFIG_OMAP_HSMMC		1
#define CONFIG_DOS_PARTITION		1

/* silent console by default */
#define CONFIG_SYS_DEVICE_NULLDEV	1
#define CONFIG_SILENT_CONSOLE		1

/* USB */
#define CONFIG_USB_MUSB_UDC			1
#define CONFIG_USB_OMAP3		1
#define CONFIG_TWL4030_USB		1

/* USB device configuration */
#define CONFIG_USB_DEVICE		1
#define CONFIG_USB_TTY			1
#define CONFIG_SYS_CONSOLE_IS_IN_ENV	1
#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE 1
#define CONFIG_SYS_CONSOLE_ENV_OVERWRITE 1
#define CONFIG_USBD_VENDORID			0x164c
#define CONFIG_USBD_PRODUCTID_GSERIAL	0x0201
#define CONFIG_USBD_PRODUCTID_CDCACM	0x0201
#define CONFIG_USBD_MANUFACTURER		"MATRIX VISION GmbH"
#define CONFIG_USBD_PRODUCT_NAME		"mvBlueLYNX-X"

/* no FLASH available */
#define CONFIG_SYS_NO_FLASH

/* commands to include */
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_EXT2		/* EXT2 Support			*/
#define CONFIG_CMD_FAT		/* FAT support			*/
#define CONFIG_CMD_I2C		/* I2C serial bus support	*/
#define CONFIG_CMD_MMC		/* MMC support			*/
#define CONFIG_CMD_EEPROM
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PING
#define CONFIG_CMD_FPGA_LOADMK

#define CONFIG_SYS_I2C
#define CONFIG_SYS_OMAP24_I2C_SPEED	100000
#define CONFIG_SYS_OMAP24_I2C_SLAVE	1
#define CONFIG_SYS_I2C_OMAP34XX

/*
 * TWL4030
 */
#define CONFIG_TWL4030_POWER		1

/* Environment information */
#undef CONFIG_ENV_OVERWRITE	/* disallow overwriting serial# and ethaddr */
#define CONFIG_BOOTDELAY		0
#define CONFIG_ZERO_BOOTDELAY_CHECK

#define CONFIG_EXTRA_ENV_SETTINGS \
	"silent=true\0" \
	"loadaddr=0x82000000\0" \
	"usbtty=cdc_acm\0" \
	"console=ttyO0,115200n8\0" \
	"mpurate=600\0" \
	"vram=12M\0" \
	"dvimode=1024x768-24@60\0" \
	"defaultdisplay=dvi\0" \
	"loadfpga=if ext2load mmc ${mmcdev}:2 ${loadaddr} "\
		"/lib/firmware/mvblx/${fpgafilename}; then " \
			"fpga load 0 ${loadaddr} ${filesize}; " \
		"fi;\0" \
	"mmcdev=0\0" \
	"mmcroot=/dev/mmcblk0p2 rw\0" \
	"mmcrootfstype=ext3 rootwait\0" \
	"mmcargs=setenv bootargs console=${console} " \
		"mpurate=${mpurate} " \
		"vram=${vram} " \
		"omapfb.mode=dvi:${dvimode} " \
		"omapfb.debug=y " \
		"omapdss.def_disp=${defaultdisplay} " \
		"root=${mmcroot} " \
		"rootfstype=${mmcrootfstype} " \
		"mvfw.fpgavers=${fpgavers} " \
		"${cmdline_suffix}\0" \
	"loadbootenv=fatload mmc ${mmcdev} ${loadaddr} uEnv.txt\0" \
	"importbootenv=echo Importing environment from mmc ...; " \
		"env import -t $loadaddr $filesize\0" \
	"loaduimage=fatload mmc ${mmcdev} ${loadaddr} uImage\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"bootm ${loadaddr}\0" \
	"mmcbootcmd= " \
		"echo Trying mmc${mmcdev}; " \
		"mmc dev ${mmcdev}; " \
		"if mmc rescan; then " \
			"setenv mmcroot /dev/mmcblk${mmcdev}p2 rw; " \
			"echo SD/MMC found on device ${mmcdev};" \
			"if run loadbootenv; then " \
			   "echo Loading boot environment from mmc${mmcdev}; " \
			   "run importbootenv; " \
			"fi;" \
			"run loadfpga; " \
			"if test -n $uenvcmd; then " \
				"echo Running uenvcmd ...;" \
				"run uenvcmd;" \
			"fi;" \
			"if run loaduimage; then " \
				"run mmcboot; " \
			"fi;" \
		"fi\0"

#define CONFIG_BOOTCOMMAND \
	"setenv mmcdev 1;" \
	"run mmcbootcmd || " \
	"setenv mmcdev 0;" \
	"run mmcbootcmd"


#define CONFIG_AUTO_COMPLETE		1
/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser */
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		(CONFIG_SYS_CBSIZE)

#define CONFIG_SYS_ALT_MEMTEST      1 /* alternative memtest with looping */
#define CONFIG_SYS_MEMTEST_START	(0x82000000)	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		(0x9dffffff)	/* end = 448 MB */
#define CONFIG_SYS_MEMTEST_SCRATCH	(0x81000000)    /* dummy address */

/* default load address */
#define CONFIG_SYS_LOAD_ADDR		(OMAP34XX_SDRC_CS0)

/*
 * OMAP3 has 12 GP timers, they can be driven by the system clock
 * (12/13/16.8/19.2/38.4MHz) or by 32KHz clock. We use 13MHz (V_SCLK).
 * This rate is divided by a local divisor.
 */
#define CONFIG_SYS_TIMERBASE		(OMAP34XX_GPT2)
#define CONFIG_SYS_PTV			2       /* Divisor: 2^(PTV+1) => 8 */

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_1		OMAP34XX_SDRC_CS0
#define PHYS_SDRAM_2		OMAP34XX_SDRC_CS1

#define CONFIG_ENV_IS_NOWHERE	1

/*----------------------------------------------------------------------------
 * Network Subsystem (SMSC9211 Ethernet from SMSC9118 family)
 *----------------------------------------------------------------------------
 */
#if defined(CONFIG_CMD_NET)
  #define CONFIG_SMC911X		1
  #define CONFIG_SMC911X_32_BIT
  #define CONFIG_SMC911X_BASE     0x2C000000
#endif /* (CONFIG_CMD_NET) */

#define CONFIG_FPGA_COUNT	1
#define CONFIG_FPGA
#define CONFIG_FPGA_ALTERA
#define CONFIG_FPGA_CYCLON2
#define CONFIG_SYS_FPGA_PROG_FEEDBACK
#define CONFIG_SYS_FPGA_DONT_USE_CONF_DONE

#define CONFIG_SYS_I2C_EEPROM_ADDR 0x50 /* 0xA0>>1 */
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN  1
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS 4  /* 2^4 = 16-byte pages */
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS 5
#define CONFIG_SYS_EEPROM_SIZE 256 /* Bytes */
#define CONFIG_ID_EEPROM
#define CONFIG_SYS_EEPROM_BUS_NUM	2

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_RAM_ADDR	0x4020f800
#define CONFIG_SYS_INIT_RAM_SIZE	0x800
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

#define CONFIG_OMAP3_SPI

#define CONFIG_SYS_CACHELINE_SIZE	64

#endif /* __CONFIG_H */
