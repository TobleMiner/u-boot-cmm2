/*
 * Copyright (C) 2016 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _ASM_ARCH_PCC_H
#define _ASM_ARCH_PCC_H

#include <common.h>
#include <asm/arch/scg.h>

/* PCC2 */

enum pcc2_entry {
	/* On-Platform (32 entries) */
	RSVD0_PCC2_SLOT			= 0,
	RSVD1_PCC2_SLOT			= 1,
	CA7_GIC_PCC2_SLOT		= 2,
	RSVD3_PCC2_SLOT			= 3,
	RSVD4_PCC2_SLOT			= 4,
	RSVD5_PCC2_SLOT			= 5,
	RSVD6_PCC2_SLOT			= 6,
	RSVD7_PCC2_SLOT			= 7,
	DMA1_PCC2_SLOT			= 8,
	RSVD9_PCC2_SLOT			= 9,
	RSVD10_PCC2_SLOT		= 10,
	RSVD11_PCC2_SLOT		= 11,
	RSVD12_PCC2_SLOT		= 12,
	RSVD13_PCC2_SLOT		= 13,
	RSVD14_PCC2_SLOT		= 14,
	RGPIO1_PCC2_SLOT		= 15,
	FLEXBUS0_PCC2_SLOT		= 16,
	RSVD17_PCC2_SLOT		= 17,
	RSVD18_PCC2_SLOT		= 18,
	RSVD19_PCC2_SLOT		= 19,
	RSVD20_PCC2_SLOT		= 20,
	RSVD21_PCC2_SLOT		= 21,
	RSVD22_PCC2_SLOT		= 22,
	RSVD23_PCC2_SLOT		= 23,
	RSVD24_PCC2_SLOT		= 24,
	RSVD25_PCC2_SLOT		= 25,
	RSVD26_PCC2_SLOT		= 26,
	SEMA42_1_PCC2_SLOT		= 27,
	RSVD28_PCC2_SLOT		= 28,
	RSVD29_PCC2_SLOT		= 29,
	RSVD30_PCC2_SLOT		= 30,
	RSVD31_PCC2_SLOT		= 31,

	/* Off-Platform (96 entries) */
	RSVD32_PCC2_SLOT		= 32,
	DMA1_CH_MUX0_PCC2_SLOT		= 33,
	MU_B_PCC2_SLOT			= 34,
	SNVS_PCC2_SLOT			= 35,
	CAAM_PCC2_SLOT			= 36,
	LPTPM4_PCC2_SLOT		= 37,
	LPTPM5_PCC2_SLOT		= 38,
	LPIT1_PCC2_SLOT			= 39,
	RSVD40_PCC2_SLOT		= 40,
	LPSPI2_PCC2_SLOT		= 41,
	LPSPI3_PCC2_SLOT		= 42,
	LPI2C4_PCC2_SLOT		= 43,
	LPI2C5_PCC2_SLOT		= 44,
	LPUART4_PCC2_SLOT		= 45,
	LPUART5_PCC2_SLOT		= 46,
	RSVD47_PCC2_SLOT		= 47,
	RSVD48_PCC2_SLOT		= 48,
	FLEXIO1_PCC2_SLOT		= 49,
	RSVD50_PCC2_SLOT		= 50,
	USBOTG0_PCC2_SLOT		= 51,
	USBOTG1_PCC2_SLOT		= 52,
	USBPHY_PCC2_SLOT		= 53,
	USB_PL301_PCC2_SLOT		= 54,
	USDHC0_PCC2_SLOT		= 55,
	USDHC1_PCC2_SLOT		= 56,
	RSVD57_PCC2_SLOT		= 57,
	TRGMUX1_PCC2_SLOT		= 58,
	RSVD59_PCC2_SLOT		= 59,
	RSVD60_PCC2_SLOT		= 60,
	WDG1_PCC2_SLOT			= 61,
	SCG1_PCC2_SLOT			= 62,
	PCC2_PCC2_SLOT			= 63,
	PMC1_PCC2_SLOT			= 64,
	SMC1_PCC2_SLOT			= 65,
	RCM1_PCC2_SLOT			= 66,
	WDG2_PCC2_SLOT			= 67,
	RSVD68_PCC2_SLOT		= 68,
	TEST_SPACE1_PCC2_SLOT		= 69,
	TEST_SPACE2_PCC2_SLOT		= 70,
	TEST_SPACE3_PCC2_SLOT		= 71,
	RSVD72_PCC2_SLOT		= 72,
	RSVD73_PCC2_SLOT		= 73,
	RSVD74_PCC2_SLOT		= 74,
	RSVD75_PCC2_SLOT		= 75,
	RSVD76_PCC2_SLOT		= 76,
	RSVD77_PCC2_SLOT		= 77,
	RSVD78_PCC2_SLOT		= 78,
	RSVD79_PCC2_SLOT		= 79,
	RSVD80_PCC2_SLOT		= 80,
	RSVD81_PCC2_SLOT		= 81,
	RSVD82_PCC2_SLOT		= 82,
	RSVD83_PCC2_SLOT		= 83,
	RSVD84_PCC2_SLOT		= 84,
	RSVD85_PCC2_SLOT		= 85,
	RSVD86_PCC2_SLOT		= 86,
	RSVD87_PCC2_SLOT		= 87,
	RSVD88_PCC2_SLOT		= 88,
	RSVD89_PCC2_SLOT		= 89,
	RSVD90_PCC2_SLOT		= 90,
	RSVD91_PCC2_SLOT		= 91,
	RSVD92_PCC2_SLOT		= 92,
	RSVD93_PCC2_SLOT		= 93,
	RSVD94_PCC2_SLOT		= 94,
	RSVD95_PCC2_SLOT		= 95,
	RSVD96_PCC2_SLOT		= 96,
	RSVD97_PCC2_SLOT		= 97,
	RSVD98_PCC2_SLOT		= 98,
	RSVD99_PCC2_SLOT		= 99,
	RSVD100_PCC2_SLOT		= 100,
	RSVD101_PCC2_SLOT		= 101,
	RSVD102_PCC2_SLOT		= 102,
	RSVD103_PCC2_SLOT		= 103,
	RSVD104_PCC2_SLOT		= 104,
	RSVD105_PCC2_SLOT		= 105,
	RSVD106_PCC2_SLOT		= 106,
	RSVD107_PCC2_SLOT		= 107,
	RSVD108_PCC2_SLOT		= 108,
	RSVD109_PCC2_SLOT		= 109,
	RSVD110_PCC2_SLOT		= 110,
	RSVD111_PCC2_SLOT		= 111,
	RSVD112_PCC2_SLOT		= 112,
	RSVD113_PCC2_SLOT		= 113,
	RSVD114_PCC2_SLOT		= 114,
	RSVD115_PCC2_SLOT		= 115,
	RSVD116_PCC2_SLOT		= 116,
	RSVD117_PCC2_SLOT		= 117,
	RSVD118_PCC2_SLOT		= 118,
	RSVD119_PCC2_SLOT		= 119,
	RSVD120_PCC2_SLOT		= 120,
	RSVD121_PCC2_SLOT		= 121,
	RSVD122_PCC2_SLOT		= 122,
	RSVD123_PCC2_SLOT		= 123,
	RSVD124_PCC2_SLOT		= 124,
	RSVD125_PCC2_SLOT		= 125,
	RSVD126_PCC2_SLOT		= 126,
	RSVD127_PCC2_SLOT		= 127,
};

enum pcc3_entry {
	/* On-Platform (32 entries) */
	RSVD0_PCC3_SLOT			= 0,
	RSVD1_PCC3_SLOT			= 1,
	RSVD2_PCC3_SLOT			= 2,
	RSVD3_PCC3_SLOT			= 3,
	RSVD4_PCC3_SLOT			= 4,
	RSVD5_PCC3_SLOT			= 5,
	RSVD6_PCC3_SLOT			= 6,
	RSVD7_PCC3_SLOT			= 7,
	RSVD8_PCC3_SLOT			= 8,
	RSVD9_PCC3_SLOT			= 9,
	RSVD10_PCC3_SLOT		= 10,
	RSVD11_PCC3_SLOT		= 11,
	RSVD12_PCC3_SLOT		= 12,
	RSVD13_PCC3_SLOT		= 13,
	RSVD14_PCC3_SLOT		= 14,
	RSVD15_PCC3_SLOT		= 15,
	ROMCP1_PCC3_SLOT		= 16,
	RSVD17_PCC3_SLOT		= 17,
	RSVD18_PCC3_SLOT		= 18,
	RSVD19_PCC3_SLOT		= 19,
	RSVD20_PCC3_SLOT		= 20,
	RSVD21_PCC3_SLOT		= 21,
	RSVD22_PCC3_SLOT		= 22,
	RSVD23_PCC3_SLOT		= 23,
	RSVD24_PCC3_SLOT		= 24,
	RSVD25_PCC3_SLOT		= 25,
	RSVD26_PCC3_SLOT		= 26,
	RSVD27_PCC3_SLOT		= 27,
	RSVD28_PCC3_SLOT		= 28,
	RSVD29_PCC3_SLOT		= 29,
	RSVD30_PCC3_SLOT		= 30,
	RSVD31_PCC3_SLOT		= 31,

	/* Off-Platform (96 entries) */
	RSVD32_PCC3_SLOT		= 32,
	LPTPM6_PCC3_SLOT		= 33,
	LPTPM7_PCC3_SLOT		= 34,
	RSVD35_PCC3_SLOT		= 35,
	LPI2C6_PCC3_SLOT		= 36,
	LPI2C7_PCC3_SLOT		= 37,
	LPUART6_PCC3_SLOT		= 38,
	LPUART7_PCC3_SLOT		= 39,
	VIU0_PCC3_SLOT			= 40,
	DSI0_PCC3_SLOT			= 41,
	LCDIF0_PCC3_SLOT		= 42,
	MMDC0_PCC3_SLOT			= 43,
	IOMUXC1_PCC3_SLOT		= 44,
	IOMUXC_DDR_PCC3_SLOT		= 45,
	PORTC_PCC3_SLOT			= 46,
	PORTD_PCC3_SLOT			= 47,
	PORTE_PCC3_SLOT			= 48,
	PORTF_PCC3_SLOT			= 49,
	RSVD50_PCC3_SLOT		= 50,
	PCC3_PCC3_SLOT			= 51,
	RSVD52_PCC3_SLOT		= 52,
	WKPU_PCC3_SLOT			= 53,
	RSVD54_PCC3_SLOT		= 54,
	RSVD55_PCC3_SLOT		= 55,
	RSVD56_PCC3_SLOT		= 56,
	RSVD57_PCC3_SLOT		= 57,
	RSVD58_PCC3_SLOT		= 58,
	RSVD59_PCC3_SLOT		= 59,
	RSVD60_PCC3_SLOT		= 60,
	RSVD61_PCC3_SLOT		= 61,
	RSVD62_PCC3_SLOT		= 62,
	RSVD63_PCC3_SLOT		= 63,
	RSVD64_PCC3_SLOT		= 64,
	RSVD65_PCC3_SLOT		= 65,
	RSVD66_PCC3_SLOT		= 66,
	RSVD67_PCC3_SLOT		= 67,
	RSVD68_PCC3_SLOT		= 68,
	RSVD69_PCC3_SLOT		= 69,
	RSVD70_PCC3_SLOT		= 70,
	RSVD71_PCC3_SLOT		= 71,
	RSVD72_PCC3_SLOT		= 72,
	RSVD73_PCC3_SLOT		= 73,
	RSVD74_PCC3_SLOT		= 74,
	RSVD75_PCC3_SLOT		= 75,
	RSVD76_PCC3_SLOT		= 76,
	RSVD77_PCC3_SLOT		= 77,
	RSVD78_PCC3_SLOT		= 78,
	RSVD79_PCC3_SLOT		= 79,
	RSVD80_PCC3_SLOT		= 80,
	GPU3D_PCC3_SLOT			= 81,
	GPU2D_PCC3_SLOT			= 82,
	RSVD83_PCC3_SLOT		= 83,
	RSVD84_PCC3_SLOT		= 84,
	RSVD85_PCC3_SLOT		= 85,
	RSVD86_PCC3_SLOT		= 86,
	RSVD87_PCC3_SLOT		= 87,
	RSVD88_PCC3_SLOT		= 88,
	RSVD89_PCC3_SLOT		= 89,
	RSVD90_PCC3_SLOT		= 90,
	RSVD91_PCC3_SLOT		= 91,
	RSVD92_PCC3_SLOT		= 92,
	RSVD93_PCC3_SLOT		= 93,
	RSVD94_PCC3_SLOT		= 94,
	RSVD95_PCC3_SLOT		= 95,
	RSVD96_PCC3_SLOT		= 96,
	RSVD97_PCC3_SLOT		= 97,
	RSVD98_PCC3_SLOT		= 98,
	RSVD99_PCC3_SLOT		= 99,
	RSVD100_PCC3_SLOT		= 100,
	RSVD101_PCC3_SLOT		= 101,
	RSVD102_PCC3_SLOT		= 102,
	RSVD103_PCC3_SLOT		= 103,
	RSVD104_PCC3_SLOT		= 104,
	RSVD105_PCC3_SLOT		= 105,
	RSVD106_PCC3_SLOT		= 106,
	RSVD107_PCC3_SLOT		= 107,
	RSVD108_PCC3_SLOT		= 108,
	RSVD109_PCC3_SLOT		= 109,
	RSVD110_PCC3_SLOT		= 110,
	RSVD111_PCC3_SLOT		= 111,
	RSVD112_PCC3_SLOT		= 112,
	RSVD113_PCC3_SLOT		= 113,
	RSVD114_PCC3_SLOT		= 114,
	RSVD115_PCC3_SLOT		= 115,
	RSVD116_PCC3_SLOT		= 116,
	RSVD117_PCC3_SLOT		= 117,
	RSVD118_PCC3_SLOT		= 118,
	RSVD119_PCC3_SLOT		= 119,
	RSVD120_PCC3_SLOT		= 120,
	RSVD121_PCC3_SLOT		= 121,
	RSVD122_PCC3_SLOT		= 122,
	RSVD123_PCC3_SLOT		= 123,
	RSVD124_PCC3_SLOT		= 124,
	RSVD125_PCC3_SLOT		= 125,
	RSVD126_PCC3_SLOT		= 126,
	RSVD127_PCC3_SLOT		= 127,
};


/* PCC registers */
#define PCC_PR_OFFSET	31
#define PCC_PR_MASK		(0x1 << PCC_PR_OFFSET)
#define PCC_CGC_OFFSET	30
#define PCC_CGC_MASK	(0x1 << PCC_CGC_OFFSET)
#define PCC_INUSE_OFFSET	29
#define PCC_INUSE_MASK		(0x1 << PCC_INUSE_OFFSET)
#define PCC_PCS_OFFSET	24
#define PCC_PCS_MASK	(0x7 << PCC_PCS_OFFSET)
#define PCC_FRAC_OFFSET	4
#define PCC_FRAC_MASK	(0x1 << PCC_FRAC_OFFSET)
#define PCC_PCD_OFFSET	0
#define PCC_PCD_MASK	(0xf << PCC_PCD_OFFSET)


enum pcc_clksrc_type {
	CLKSRC_PER_PLAT = 0,
	CLKSRC_PER_BUS = 1,
	CLKSRC_NO_PCS = 2,
};

enum pcc_div_type {
	PCC_HAS_DIV,
	PCC_NO_DIV,
};

/* All peripheral clocks on A7 PCCs */
enum pcc_clk {
	/*PCC2 clocks*/
	PER_CLK_DMA1 = 0,
	PER_CLK_RGPIO2P1,
	PER_CLK_FLEXBUS,
	PER_CLK_SEMA42_1,
	PER_CLK_DMA_MUX1,
	PER_CLK_SNVS,
	PER_CLK_CAAM,
	PER_CLK_LPTPM4,
	PER_CLK_LPTPM5,
	PER_CLK_LPIT1,
	PER_CLK_LPSPI2,
	PER_CLK_LPSPI3,
	PER_CLK_LPI2C4,
	PER_CLK_LPI2C5,
	PER_CLK_LPUART4,
	PER_CLK_LPUART5,
	PER_CLK_FLEXIO1,
	PER_CLK_USB0,
	PER_CLK_USB1,
	PER_CLK_USB_PHY,
	PER_CLK_USB_PL301,
	PER_CLK_USDHC0,
	PER_CLK_USDHC1,
	PER_CLK_WDG1,
	PER_CLK_WDG2,

	/*PCC3 clocks*/
	PER_CLK_LPTPM6,
	PER_CLK_LPTPM7,
	PER_CLK_LPI2C6,
	PER_CLK_LPI2C7,
	PER_CLK_LPUART6,
	PER_CLK_LPUART7,
	PER_CLK_VIU,
	PER_CLK_DSI,
	PER_CLK_LCDIF,
	PER_CLK_MMDC,
	PER_CLK_PCTLC,
	PER_CLK_PCTLD,
	PER_CLK_PCTLE,
	PER_CLK_PCTLF,
	PER_CLK_GPU3D,
	PER_CLK_GPU2D,
};


/* This structure keeps info for each pcc slot */
struct pcc_entry {
	u32 pcc_base;
	u32 pcc_slot;
	enum pcc_clksrc_type clksrc;
	enum pcc_div_type div;
};

int pcc_clock_enable(enum pcc_clk clk, bool enable);
int pcc_clock_sel(enum pcc_clk clk, enum scg_clk src);
int pcc_clock_div_config(enum pcc_clk clk, bool frac, u8 div);
bool pcc_clock_is_enable(enum pcc_clk clk);
int pcc_clock_get_clksrc(enum pcc_clk clk, enum scg_clk *src);
u32 pcc_clock_get_rate(enum pcc_clk clk);
#endif
