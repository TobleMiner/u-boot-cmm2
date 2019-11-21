/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuation settings for the sh7753evb board
 *
 * Copyright (C) 2012 Renesas Solutions Corp.
 */

#ifndef __SH7753EVB_H
#define __SH7753EVB_H

#define CONFIG_CPU_SH7753	1

#define CONFIG_DISPLAY_BOARDINFO

/* MEMORY */
#define SH7753EVB_SDRAM_BASE		(0x40000000)
#define SH7753EVB_SDRAM_SIZE		(512 * 1024 * 1024)

#define CONFIG_SYS_PBSIZE		256
#define CONFIG_SYS_BAUDRATE_TABLE	{ 115200 }

/* SCIF */
#define CONFIG_CONS_SCIF2	1

#define CONFIG_SYS_MEMTEST_START	(SH7753EVB_SDRAM_BASE)
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + \
					 480 * 1024 * 1024)
#undef	CONFIG_SYS_MEMTEST_SCRATCH
#undef	CONFIG_SYS_LOADS_BAUD_CHANGE

#define CONFIG_SYS_SDRAM_BASE		(SH7753EVB_SDRAM_BASE)
#define CONFIG_SYS_SDRAM_SIZE		(SH7753EVB_SDRAM_SIZE)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + \
					 128 * 1024 * 1024)

#define CONFIG_SYS_MONITOR_BASE		0x00000000
#define CONFIG_SYS_MONITOR_LEN		(512 * 1024)
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)
#define CONFIG_SYS_BOOTMAPSZ		(8 * 1024 * 1024)

/* Ether */
#define CONFIG_SH_ETHER_USE_PORT	0
#define CONFIG_SH_ETHER_PHY_ADDR	18
#define CONFIG_SH_ETHER_CACHE_WRITEBACK	1
#define CONFIG_SH_ETHER_USE_GETHER	1
#define CONFIG_BITBANGMII
#define CONFIG_BITBANGMII_MULTI
#define CONFIG_SH_ETHER_PHY_MODE PHY_INTERFACE_MODE_RGMII
#define CONFIG_PHY_VITESSE

#define SH7753EVB_ETHERNET_MAC_BASE_SPI	0x00090000
#define SH7753EVB_SPI_SECTOR_SIZE	(64 * 1024)
#define SH7753EVB_ETHERNET_MAC_BASE	SH7753EVB_ETHERNET_MAC_BASE_SPI
#define SH7753EVB_ETHERNET_MAC_SIZE	17
#define SH7753EVB_ETHERNET_NUM_CH	2

/* SPI */
#define CONFIG_SH_SPI_BASE		0xfe002000

/* MMCIF */
#define CONFIG_SH_MMCIF_ADDR		0xffcb0000
#define CONFIG_SH_MMCIF_CLK		48000000

/* ENV setting */
#define CONFIG_ENV_OVERWRITE	1
#define CONFIG_EXTRA_ENV_SETTINGS				\
		"netboot=bootp; bootm\0"

/* Board Clock */
#define CONFIG_SYS_CLK_FREQ	48000000
#define CONFIG_SH_SCIF_CLK_FREQ CONFIG_SYS_CLK_FREQ
#endif	/* __SH7753EVB_H */
