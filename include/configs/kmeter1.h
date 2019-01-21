/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2012
 * Holger Brunck, Keymile GmbH Hannover, <holger.brunck@keymile.com>
 * Christian Herzig, Keymile AG Switzerland, <christian.herzig@keymile.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* KMBEC FPGA (PRIO) */
#define CONFIG_SYS_KMBEC_FPGA_BASE	0xE8000000
#define CONFIG_SYS_KMBEC_FPGA_SIZE	64

#define CONFIG_HOSTNAME		"kmeter1"
#define CONFIG_KM_BOARD_NAME   "kmeter1"
#define CONFIG_KM_DEF_NETDEV	"netdev=eth2\0"

/*
 * High Level Configuration Options
 */
#define CONFIG_QE			/* Has QE */

/* include common defines/options for all Keymile boards */
#include "km/keymile-common.h"
#include "km/km-powerpc.h"

/*
 * DDR Setup
 */
#define CONFIG_SYS_SDRAM_BASE		0x00000000 /* DDR is system memory */
#define CONFIG_SYS_SDRAM_BASE2	(CONFIG_SYS_SDRAM_BASE + 0x10000000) /* +256M */

#define CONFIG_SYS_DDR_SDRAM_BASE	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_DDR_SDRAM_CLK_CNTL	(DDR_SDRAM_CLK_CNTL_SS_EN | \
					DDR_SDRAM_CLK_CNTL_CLK_ADJUST_05)

#define CFG_83XX_DDR_USES_CS0

/*
 * Manually set up DDR parameters
 */
#define CONFIG_DDR_II
#define CONFIG_SYS_DDR_SIZE		2048 /* MB */

/*
 * The reserved memory
 */
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_TEXT_BASE /* start of monitor */
#define CONFIG_SYS_FLASH_BASE		0xF0000000

#if (CONFIG_SYS_MONITOR_BASE < CONFIG_SYS_FLASH_BASE)
#define CONFIG_SYS_RAMBOOT
#endif

/* Reserve 768 kB for Mon */
#define CONFIG_SYS_MONITOR_LEN		(768 * 1024)

/*
 * Initial RAM Base Address Setup
 */
#define CONFIG_SYS_INIT_RAM_LOCK
#define CONFIG_SYS_INIT_RAM_ADDR	0xE6000000 /* Initial RAM address */
#define CONFIG_SYS_INIT_RAM_SIZE	0x1000 /* End of used area in RAM */
#define CONFIG_SYS_GBL_DATA_OFFSET	(CONFIG_SYS_INIT_RAM_SIZE - \
						GENERATED_GBL_DATA_SIZE)

/*
 * Init Local Bus Memory Controller:
 *
 * Bank Bus     Machine PortSz  Size  Device
 * ---- ---     ------- ------  -----  ------
 *  0   Local   GPCM    16 bit  256MB FLASH
 *  1   Local   GPCM     8 bit  128MB GPIO/PIGGY
 *
 */
/*
 * FLASH on the Local Bus
 */
#define CONFIG_SYS_FLASH_SIZE		256 /* max FLASH size is 256M */


#define CONFIG_SYS_MAX_FLASH_BANKS	1   /* max num of flash banks	*/
#define CONFIG_SYS_MAX_FLASH_SECT	512 /* max num of sects on one chip */
#define CONFIG_SYS_FLASH_BANKS_LIST { CONFIG_SYS_FLASH_BASE }

/*
 * PRIO1/PIGGY on the local bus CS1
 */


/*
 * Serial Port
 */
#define CONFIG_CONS_INDEX	1
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	1
#define CONFIG_SYS_NS16550_CLK		get_bus_freq(0)

#define CONFIG_SYS_NS16550_COM1	(CONFIG_SYS_IMMR+0x4500)
#define CONFIG_SYS_NS16550_COM2	(CONFIG_SYS_IMMR+0x4600)

/*
 * QE UEC ethernet configuration
 */
#define CONFIG_UEC_ETH
#define CONFIG_ETHPRIME		"UEC0"

#define CONFIG_UEC_ETH1		/* GETH1 */
#define UEC_VERBOSE_DEBUG	1

#ifdef CONFIG_UEC_ETH1
#define CONFIG_SYS_UEC1_UCC_NUM	3	/* UCC4 */
#define CONFIG_SYS_UEC1_RX_CLK		QE_CLK_NONE /* not used in RMII Mode */
#define CONFIG_SYS_UEC1_TX_CLK		QE_CLK17
#define CONFIG_SYS_UEC1_ETH_TYPE	FAST_ETH
#define CONFIG_SYS_UEC1_PHY_ADDR	0
#define CONFIG_SYS_UEC1_INTERFACE_TYPE	PHY_INTERFACE_MODE_RMII
#define CONFIG_SYS_UEC1_INTERFACE_SPEED	100
#endif

/*
 * Environment
 */

#ifndef CONFIG_SYS_RAMBOOT
#ifndef CONFIG_ENV_ADDR
#define CONFIG_ENV_ADDR		(CONFIG_SYS_MONITOR_BASE + \
					CONFIG_SYS_MONITOR_LEN)
#endif
#define CONFIG_ENV_SECT_SIZE	0x20000 /* 128K(one sector) for env */
#ifndef CONFIG_ENV_OFFSET
#define CONFIG_ENV_OFFSET	(CONFIG_SYS_MONITOR_LEN)
#endif

/* Address and size of Redundant Environment Sector	*/
#define CONFIG_ENV_OFFSET_REDUND	(CONFIG_ENV_OFFSET + \
						CONFIG_ENV_SECT_SIZE)
#define CONFIG_ENV_SIZE_REDUND	(CONFIG_ENV_SIZE)

#else /* CFG_SYS_RAMBOOT */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_MONITOR_BASE - 0x1000)
#define CONFIG_ENV_SIZE		0x2000
#endif /* CFG_SYS_RAMBOOT */

/* I2C */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_NUM_I2C_BUSES	4
#define CONFIG_SYS_I2C_MAX_HOPS		1
#define CONFIG_SYS_I2C_FSL
#define CONFIG_SYS_FSL_I2C_SPEED	200000
#define CONFIG_SYS_FSL_I2C_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C_OFFSET	0x3000
#define CONFIG_SYS_I2C_OFFSET		0x3000
#define CONFIG_SYS_FSL_I2C2_SPEED	200000
#define CONFIG_SYS_FSL_I2C2_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C2_OFFSET	0x3100
#define CONFIG_SYS_I2C_BUSES	{{0, {I2C_NULL_HOP} }, \
		{0, {{I2C_MUX_PCA9547, 0x70, 2} } }, \
		{0, {{I2C_MUX_PCA9547, 0x70, 1} } }, \
		{1, {I2C_NULL_HOP} } }

#define CONFIG_KM_IVM_BUS		2	/* I2C2 (Mux-Port 1)*/

#if defined(CONFIG_CMD_NAND)
#define CONFIG_NAND_KMETER1
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		CONFIG_SYS_KMBEC_FPGA_BASE
#endif

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 8 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ		(8 << 20)

/*
 * Internal Definitions
 */
#define BOOTFLASH_START	0xF0000000

#define CONFIG_KM_CONSOLE_TTY	"ttyS0"

/*
 * Environment Configuration
 */
#define CONFIG_ENV_OVERWRITE
#ifndef CONFIG_KM_DEF_ENV		/* if not set by keymile-common.h */
#define CONFIG_KM_DEF_ENV "km-common=empty\0"
#endif

#ifndef CONFIG_KM_DEF_ARCH
#define CONFIG_KM_DEF_ARCH	"arch=ppc_82xx\0"
#endif

#define CONFIG_EXTRA_ENV_SETTINGS \
	CONFIG_KM_DEF_ENV						\
	CONFIG_KM_DEF_ARCH						\
	"newenv="							\
		"prot off "__stringify(CONFIG_ENV_ADDR)" +0x40000 && "	\
		"era "__stringify(CONFIG_ENV_ADDR)" +0x40000\0"		\
	"unlock=yes\0"							\
	""

#if defined(CONFIG_UEC_ETH)
#define CONFIG_HAS_ETH0
#endif

/*
 * System IO Setup
 */
#define CONFIG_SYS_SICRH		(SICRH_UC1EOBI | SICRH_UC2E1OBI)

/**
 * DDR RAM settings
 */
#define CONFIG_SYS_DDR_SDRAM_CFG (\
	SDRAM_CFG_SDRAM_TYPE_DDR2 | \
	SDRAM_CFG_SREN | \
	SDRAM_CFG_HSE)

#define CONFIG_SYS_DDR_SDRAM_CFG2	0x00401000

#define CONFIG_SYS_DDR_CS0_CONFIG	(CSCONFIG_EN | CSCONFIG_AP | \
					 CSCONFIG_ROW_BIT_13 | \
					 CSCONFIG_COL_BIT_10 | \
					 CSCONFIG_ODT_WR_ONLY_CURRENT)

#define CONFIG_SYS_DDR_CLK_CNTL (\
	DDR_SDRAM_CLK_CNTL_CLK_ADJUST_05)

#define CONFIG_SYS_DDR_INTERVAL (\
	(0x080 << SDRAM_INTERVAL_BSTOPRE_SHIFT) | \
	(0x203 << SDRAM_INTERVAL_REFINT_SHIFT))

#define CONFIG_SYS_DDR_CS0_BNDS			0x0000007f

#define CONFIG_SYS_DDRCDR (\
	DDRCDR_EN | \
	DDRCDR_Q_DRN)
#define CONFIG_SYS_DDR_MODE		0x47860452
#define CONFIG_SYS_DDR_MODE2		0x8080c000

#define CONFIG_SYS_DDR_TIMING_0 (\
	(2 << TIMING_CFG0_MRS_CYC_SHIFT) | \
	(8 << TIMING_CFG0_ODT_PD_EXIT_SHIFT) | \
	(6 << TIMING_CFG0_PRE_PD_EXIT_SHIFT) | \
	(2 << TIMING_CFG0_ACT_PD_EXIT_SHIFT) | \
	(0 << TIMING_CFG0_WWT_SHIFT) | \
	(0 << TIMING_CFG0_RRT_SHIFT) | \
	(0 << TIMING_CFG0_WRT_SHIFT) | \
	(0 << TIMING_CFG0_RWT_SHIFT))

#define CONFIG_SYS_DDR_TIMING_1	((TIMING_CFG1_CASLAT_50) | \
				 (2 << TIMING_CFG1_WRTORD_SHIFT) | \
				 (2 << TIMING_CFG1_ACTTOACT_SHIFT) | \
				 (3 << TIMING_CFG1_WRREC_SHIFT) | \
				 (7 << TIMING_CFG1_REFREC_SHIFT) | \
				 (3 << TIMING_CFG1_ACTTORW_SHIFT) | \
				 (8 << TIMING_CFG1_ACTTOPRE_SHIFT) | \
				 (3 << TIMING_CFG1_PRETOACT_SHIFT))

#define CONFIG_SYS_DDR_TIMING_2 (\
	(0xa << TIMING_CFG2_FOUR_ACT_SHIFT) | \
	(3 << TIMING_CFG2_CKE_PLS_SHIFT) | \
	(2 << TIMING_CFG2_WR_DATA_DELAY_SHIFT) | \
	(2 << TIMING_CFG2_RD_TO_PRE_SHIFT) | \
	(4 << TIMING_CFG2_WR_LAT_DELAY_SHIFT) | \
	(5 << TIMING_CFG2_CPO_SHIFT) | \
	(0 << TIMING_CFG2_ADD_LAT_SHIFT))

#define CONFIG_SYS_DDR_TIMING_3			0x00000000

/* EEprom support */
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		2

/*
 * PAXE on the local bus CS3
 */
#define CONFIG_SYS_PAXE_BASE		0xA0000000
#define CONFIG_SYS_PAXE_SIZE		256


#endif /* CONFIG */
