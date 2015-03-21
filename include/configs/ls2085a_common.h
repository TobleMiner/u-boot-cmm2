/*
 * Copyright (C) 2014 Freescale Semiconductor
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LS2_COMMON_H
#define __LS2_COMMON_H

#define CONFIG_SYS_GENERIC_BOARD

#define CONFIG_REMAKE_ELF
#define CONFIG_FSL_LSCH3
#define CONFIG_LS2085A
#define CONFIG_GICV3
#define CONFIG_FSL_TZPC_BP147

/* Errata fixes */
#define CONFIG_ARM_ERRATA_828024
#define CONFIG_ARM_ERRATA_826974

/* We need architecture specific misc initializations */
#define CONFIG_ARCH_MISC_INIT

/* Link Definitions */
#define CONFIG_SYS_TEXT_BASE		0x30100000

#ifdef CONFIG_EMU
#define CONFIG_SYS_NO_FLASH
#endif

#define CONFIG_SUPPORT_RAW_INITRD

#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_BOARD_EARLY_INIT_F	1

/* Flat Device Tree Definitions */
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP

/* new uImage format support */
#define CONFIG_FIT
#define CONFIG_FIT_VERBOSE	/* enable fit_format_{error,warning}() */

#define CONFIG_FSL_DDR_INTERACTIVE	/* Interactive debugging */
#ifndef CONFIG_SYS_FSL_DDR4
#define CONFIG_SYS_FSL_DDR3		/* Use DDR3 memory */
#define CONFIG_SYS_DDR_RAW_TIMING
#endif

#define CONFIG_SYS_FSL_DDR_INTLV_256B	/* force 256 byte interleaving */

#define CONFIG_SYS_DDR_SDRAM_BASE	0x80000000UL
#define CONFIG_SYS_FSL_DDR_SDRAM_BASE_PHY	0
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_DDR_SDRAM_BASE
#define CONFIG_SYS_DDR_BLOCK2_BASE	0x8080000000ULL
#define CONFIG_SYS_FSL_DDR_MAIN_NUM_CTRLS	2

/*
 * SMP Definitinos
 */
#define CPU_RELEASE_ADDR		secondary_boot_func

#define CONFIG_SYS_FSL_OTHER_DDR_NUM_CTRLS
#define CONFIG_SYS_DP_DDR_BASE		0x6000000000ULL
/*
 * DDR controller use 0 as the base address for binding.
 * It is mapped to CONFIG_SYS_DP_DDR_BASE for core to access.
 */
#define CONFIG_SYS_DP_DDR_BASE_PHY	0
#define CONFIG_DP_DDR_CTRL		2
#define CONFIG_DP_DDR_NUM_CTRLS		1

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY		12000000	/* 12MHz */

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 2048 * 1024)

/* I2C */
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C3		/* enable I2C bus 3 */
#define CONFIG_SYS_I2C_MXC_I2C4		/* enable I2C bus 4 */

/* Serial Port */
#define CONFIG_CONS_INDEX       2
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE     1
#define CONFIG_SYS_NS16550_CLK          (get_bus_freq(0)/2)

#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/* IFC */
#define CONFIG_FSL_IFC

/*
 * During booting, CS0 needs to be at the region of 0x30000000, i.e. the IFC
 * address 0. But this region is limited to 256MB. To accommodate bigger NOR
 * flash and other devices, we will map CS0 to 0x580000000 after relocation.
 * CONFIG_SYS_FLASH_BASE has the final address (core view)
 * CONFIG_SYS_FLASH_BASE_PHYS has the final address (IFC view)
 * CONFIG_SYS_FLASH_BASE_PHYS_EARLY has the temporary IFC address
 * CONFIG_SYS_TEXT_BASE is linked to 0x30000000 for booting
 */
#define CONFIG_SYS_FLASH_BASE			0x580000000ULL
#define CONFIG_SYS_FLASH_BASE_PHYS		0x80000000
#define CONFIG_SYS_FLASH_BASE_PHYS_EARLY	0x00000000

#ifndef CONFIG_SYS_NO_FLASH
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#define CONFIG_SYS_FLASH_QUIET_TEST
#endif

#define CONFIG_SYS_NAND_BASE		0x520000000
#define CONFIG_SYS_NAND_BASE_PHYS	0x20000000

/* Debug Server firmware */
#define CONFIG_SYS_DEBUG_SERVER_DRAM_BLOCK_MIN_SIZE	(512UL * 1024 * 1024)
/* 2 sec timeout */
#define CONFIG_SYS_DEBUG_SERVER_TIMEOUT			(2 * 1000 * 1000)

/* MC firmware */
#define CONFIG_FSL_MC_ENET
#define CONFIG_SYS_LS_MC_DRAM_BLOCK_MIN_SIZE	(512UL * 1024 * 1024)
/* TODO Actual DPL max length needs to be confirmed with the MC FW team */
#define CONFIG_SYS_LS_MC_DPL_MAX_LENGTH		(256 * 1024)
#define CONFIG_SYS_LS_MC_DRAM_DPL_OFFSET	0xe00000

/* Carve out a DDR region which will not be used by u-boot/Linux */
#if defined(CONFIG_FSL_MC_ENET) || defined(CONFIG_FSL_DEBUG_SERVER)
#define CONFIG_SYS_MEM_TOP_HIDE		get_dram_size_to_hide()
#endif

/* PCIe */
#define CONFIG_PCIE1		/* PCIE controler 1 */
#define CONFIG_PCIE2		/* PCIE controler 2 */
#define CONFIG_PCIE3		/* PCIE controler 3 */
#define CONFIG_PCIE4		/* PCIE controler 4 */
#define FSL_PCIE_COMPAT "fsl,20851a-pcie"

#define CONFIG_SYS_PCI_64BIT

#define CONFIG_SYS_PCIE_CFG0_PHYS_OFF	0x00000000
#define CONFIG_SYS_PCIE_CFG0_SIZE	0x00001000	/* 4k */
#define CONFIG_SYS_PCIE_CFG1_PHYS_OFF	0x00001000
#define CONFIG_SYS_PCIE_CFG1_SIZE	0x00001000	/* 4k */

#define CONFIG_SYS_PCIE_IO_BUS		0x00000000
#define CONFIG_SYS_PCIE_IO_PHYS_OFF	0x00010000
#define CONFIG_SYS_PCIE_IO_SIZE		0x00010000	/* 64k */

#define CONFIG_SYS_PCIE_MEM_BUS		0x40000000
#define CONFIG_SYS_PCIE_MEM_PHYS_OFF	0x40000000
#define CONFIG_SYS_PCIE_MEM_SIZE	0x40000000	/* 1G */

/* Command line configuration */
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_BDI
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_ENV
#define CONFIG_CMD_FLASH
#define CONFIG_CMD_IMI
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_RUN
#define CONFIG_CMD_BOOTD
#define CONFIG_CMD_ECHO
#define CONFIG_CMD_SOURCE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION

/* Miscellaneous configurable options */
#define CONFIG_SYS_LOAD_ADDR	(CONFIG_SYS_DDR_SDRAM_BASE + 0x10000000)
#define CONFIG_ARCH_EARLY_INIT_R

/* Physical Memory Map */
/* fixme: these need to be checked against the board */
#define CONFIG_CHIP_SELECTS_PER_CTRL	4

#define CONFIG_NR_DRAM_BANKS		3

#define CONFIG_HWCONFIG
#define HWCONFIG_BUFFER_SIZE		128

#define CONFIG_DISPLAY_CPUINFO

/* Initial environment variables */
#define CONFIG_EXTRA_ENV_SETTINGS		\
	"hwconfig=fsl_ddr:bank_intlv=auto\0"	\
	"loadaddr=0x80100000\0"			\
	"kernel_addr=0x100000\0"		\
	"ramdisk_addr=0x800000\0"		\
	"ramdisk_size=0x2000000\0"		\
	"fdt_high=0xa0000000\0"			\
	"initrd_high=0xffffffffffffffff\0"	\
	"kernel_start=0x581200000\0"		\
	"kernel_load=0xa0000000\0"		\
	"kernel_size=0x1000000\0"		\
	"console=ttyAMA0,38400n8\0"

#define CONFIG_BOOTARGS		"console=ttyS1,115200 root=/dev/ram0 " \
				"earlycon=uart8250,mmio,0x21c0600,115200 " \
				"default_hugepagesz=2m hugepagesz=2m " \
				"hugepages=16"
#define CONFIG_BOOTCOMMAND		"cp.b $kernel_start $kernel_load "     \
					"$kernel_size && bootm $kernel_load"
#define CONFIG_BOOTDELAY		1

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		512	/* Console I/O Buffer Size */
#define CONFIG_SYS_PROMPT		"=> "
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE /* Boot args buffer */
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING		1
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_MAXARGS		64	/* max command args */

#ifndef __ASSEMBLY__
unsigned long get_dram_size_to_hide(void);
#endif

#define CONFIG_PANIC_HANG	/* do not reset board on panic */

#endif /* __LS2_COMMON_H */
