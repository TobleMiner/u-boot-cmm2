/*
 * (C) Copyright 2009
 * Marvell Semiconductor <www.marvell.com>
 * Written-by: Prafulla Wadaskar <prafulla@marvell.com>
 *
 * Header file for the Marvell's Feroceon CPU core.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _MVEBU_SOC_H
#define _MVEBU_SOC_H

#define SOC_MV78460_ID		0x7846
#define SOC_88F6810_ID		0x6810
#define SOC_88F6820_ID		0x6820
#define SOC_88F6828_ID		0x6828

/* A38x revisions */
#define MV_88F68XX_Z1_ID	0x0
#define MV_88F68XX_A0_ID	0x4

/* TCLK Core Clock definition */
#ifndef CONFIG_SYS_TCLK
#define CONFIG_SYS_TCLK		250000000	/* 250MHz */
#endif

/* Armada XP PLL frequency (used for NAND clock generation) */
#define CONFIG_SYS_MVEBU_PLL_CLOCK	2000000000

/* SOC specific definations */
#define INTREG_BASE		0xd0000000
#define INTREG_BASE_ADDR_REG	(INTREG_BASE + 0x20080)
#if defined(CONFIG_SPL_BUILD)
/*
 * On A38x switching the regs base address without running from
 * SDRAM doesn't seem to work. So let the SPL still use the
 * default base address and switch to the new address in the
 * main u-boot later.
 */
#define SOC_REGS_PHY_BASE	0xd0000000
#else
#define SOC_REGS_PHY_BASE	0xf1000000
#endif
#define MVEBU_REGISTER(x)	(SOC_REGS_PHY_BASE + x)

#define MVEBU_SDRAM_SCRATCH	(MVEBU_REGISTER(0x01504))
#define MVEBU_L2_CACHE_BASE	(MVEBU_REGISTER(0x08000))
#define CONFIG_SYS_PL310_BASE	MVEBU_L2_CACHE_BASE
#define MVEBU_TWSI_BASE		(MVEBU_REGISTER(0x11000))
#define MVEBU_MPP_BASE		(MVEBU_REGISTER(0x18000))
#define MVEBU_GPIO0_BASE	(MVEBU_REGISTER(0x18100))
#define MVEBU_GPIO1_BASE	(MVEBU_REGISTER(0x18140))
#define MVEBU_GPIO2_BASE	(MVEBU_REGISTER(0x18180))
#define MVEBU_SYSTEM_REG_BASE	(MVEBU_REGISTER(0x18200))
#define MVEBU_CLOCK_BASE	(MVEBU_REGISTER(0x18700))
#define MVEBU_CPU_WIN_BASE	(MVEBU_REGISTER(0x20000))
#define MVEBU_SDRAM_BASE	(MVEBU_REGISTER(0x20180))
#define MVEBU_TIMER_BASE	(MVEBU_REGISTER(0x20300))
#define MVEBU_REG_PCIE_BASE	(MVEBU_REGISTER(0x40000))
#define MVEBU_AXP_USB_BASE      (MVEBU_REGISTER(0x50000))
#define MVEBU_USB20_BASE	(MVEBU_REGISTER(0x58000))
#define MVEBU_AXP_SATA_BASE	(MVEBU_REGISTER(0xa0000))
#define MVEBU_SATA0_BASE	(MVEBU_REGISTER(0xa8000))
#define MVEBU_NAND_BASE		(MVEBU_REGISTER(0xd0000))
#define MVEBU_SDIO_BASE		(MVEBU_REGISTER(0xd8000))

#define SOC_COHERENCY_FABRIC_CTRL_REG	(MVEBU_REGISTER(0x20200))
#define MBUS_ERR_PROP_EN	(1 << 8)

#define MBUS_BRIDGE_WIN_CTRL_REG (MVEBU_REGISTER(0x20250))
#define MBUS_BRIDGE_WIN_BASE_REG (MVEBU_REGISTER(0x20254))

#define MVEBU_SOC_DEV_MUX_REG	(MVEBU_SYSTEM_REG_BASE + 0x08)
#define NAND_EN			BIT(0)
#define NAND_ARBITER_EN		BIT(27)

#define ARMADA_XP_PUP_ENABLE	(MVEBU_SYSTEM_REG_BASE + 0x44c)
#define GE0_PUP_EN		BIT(0)
#define GE1_PUP_EN		BIT(1)
#define LCD_PUP_EN		BIT(2)
#define NAND_PUP_EN		BIT(4)
#define SPI_PUP_EN		BIT(5)

#define MVEBU_CORE_DIV_CLK_CTRL(i)	(MVEBU_CLOCK_BASE + ((i) * 0x8))
#define NAND_ECC_DIVCKL_RATIO_OFFS	8
#define NAND_ECC_DIVCKL_RATIO_MASK	(0x3F << NAND_ECC_DIVCKL_RATIO_OFFS)

#define SDRAM_MAX_CS		4
#define SDRAM_ADDR_MASK		0xFF000000

/* MVEBU CPU memory windows */
#define MVCPU_WIN_CTRL_DATA	CPU_WIN_CTRL_DATA
#define MVCPU_WIN_ENABLE	CPU_WIN_ENABLE
#define MVCPU_WIN_DISABLE	CPU_WIN_DISABLE

#endif /* _MVEBU_SOC_H */
