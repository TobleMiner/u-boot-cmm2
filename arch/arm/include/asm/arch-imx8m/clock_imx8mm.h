/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2018-2019 NXP
 *
 * Peng Fan <peng.fan@nxp.com>
 */

#ifndef _ASM_ARCH_IMX8MM_CLOCK_H
#define _ASM_ARCH_IMX8MM_CLOCK_H

#define PLL_1443X_RATE(_rate, _m, _p, _s, _k)			\
	{							\
		.rate	=	(_rate),			\
		.mdiv	=	(_m),				\
		.pdiv	=	(_p),				\
		.sdiv	=	(_s),				\
		.kdiv	=	(_k),				\
	}

#define LOCK_STATUS	BIT(31)
#define LOCK_SEL_MASK	BIT(29)
#define CLKE_MASK	BIT(11)
#define RST_MASK	BIT(9)
#define BYPASS_MASK	BIT(4)
#define	MDIV_SHIFT	12
#define	MDIV_MASK	GENMASK(21, 12)
#define PDIV_SHIFT	4
#define PDIV_MASK	GENMASK(9, 4)
#define SDIV_SHIFT	0
#define SDIV_MASK	GENMASK(2, 0)
#define KDIV_SHIFT	0
#define KDIV_MASK	GENMASK(15, 0)

struct imx_int_pll_rate_table {
	u32 rate;
	int mdiv;
	int pdiv;
	int sdiv;
	int kdiv;
};

enum pll_clocks {
	ANATOP_ARM_PLL,
	ANATOP_VPU_PLL,
	ANATOP_GPU_PLL,
	ANATOP_SYSTEM_PLL1,
	ANATOP_SYSTEM_PLL2,
	ANATOP_SYSTEM_PLL3,
	ANATOP_AUDIO_PLL1,
	ANATOP_AUDIO_PLL2,
	ANATOP_VIDEO_PLL,
	ANATOP_DRAM_PLL,
};

#ifdef CONFIG_IMX8MN
enum clk_root_index {
	ARM_A53_CLK_ROOT		= 0,
	ARM_M7_CLK_ROOT			= 1,
	GPU_CORE_CLK_ROOT		= 3,
	GPU_SHADER_CLK_ROOT		= 4,
	MAIN_AXI_CLK_ROOT		= 16,
	ENET_AXI_CLK_ROOT		= 17,
	NAND_USDHC_BUS_CLK_ROOT		= 18,
	DISPLAY_AXI_CLK_ROOT		= 20,
	DISPLAY_APB_CLK_ROOT		= 21,
	USB_BUS_CLK_ROOT		= 23,
	GPU_AXI_CLK_ROOT		= 24,
	GPU_AHB_CLK_ROOT		= 25,
	NOC_CLK_ROOT			= 26,
	AHB_CLK_ROOT			= 32,
	IPG_CLK_ROOT			= 33,
	AUDIO_AHB_CLK_ROOT		= 34,
	DRAM_SEL_CFG			= 48,
	CORE_SEL_CFG			= 49,
	DRAM_ALT_CLK_ROOT		= 64,
	DRAM_APB_CLK_ROOT		= 65,
	DISPLAY_PIXEL_CLK_ROOT		= 74,
	SAI2_CLK_ROOT			= 76,
	SAI3_CLK_ROOT			= 77,
	SAI5_CLK_ROOT			= 79,
	SAI6_CLK_ROOT			= 80,
	SPDIF1_CLK_ROOT			= 81,
	ENET_REF_CLK_ROOT		= 83,
	ENET_TIMER_CLK_ROOT		= 84,
	ENET_PHY_REF_CLK_ROOT		= 85,
	NAND_CLK_ROOT			= 86,
	QSPI_CLK_ROOT			= 87,
	USDHC1_CLK_ROOT			= 88,
	USDHC2_CLK_ROOT			= 89,
	I2C1_CLK_ROOT			= 90,
	I2C2_CLK_ROOT			= 91,
	I2C3_CLK_ROOT			= 92,
	I2C4_CLK_ROOT			= 93,
	UART1_CLK_ROOT			= 94,
	UART2_CLK_ROOT			= 95,
	UART3_CLK_ROOT			= 96,
	UART4_CLK_ROOT			= 97,
	USB_CORE_REF_CLK_ROOT		= 98,
	USB_PHY_REF_CLK_ROOT		= 99,
	GIC_CLK_ROOT			= 100,
	ECSPI1_CLK_ROOT			= 101,
	ECSPI2_CLK_ROOT			= 102,
	PWM1_CLK_ROOT			= 103,
	PWM2_CLK_ROOT			= 104,
	PWM3_CLK_ROOT			= 105,
	PWM4_CLK_ROOT			= 106,
	GPT1_CLK_ROOT			= 107,
	GPT2_CLK_ROOT			= 108,
	GPT3_CLK_ROOT			= 109,
	GPT4_CLK_ROOT			= 110,
	GPT5_CLK_ROOT			= 111,
	GPT6_CLK_ROOT			= 112,
	TRACE_CLK_ROOT			= 113,
	WDOG_CLK_ROOT			= 114,
	WRCLK_CLK_ROOT			= 115,
	IPP_DO_CLKO1			= 116,
	IPP_DO_CLKO2			= 117,
	MIPI_DSI_CORE_CLK_ROOT		= 118,
	DISPLAY_DSI_PHY_REF_CLK_ROOT	= 119,
	MIPI_DSI_DBI_CLK_ROOT		= 120,
	USDHC3_CLK_ROOT			= 121,
	DISPLAY_CAMERA_PIXEL_CLK_ROOT	= 122,
	MIPI_CSI1_PHY_REF_CLK_ROOT	= 123,
	MIPI_CSI2_PHY_REF_CLK_ROOT	= 126,
	MIPI_CSI2_ESC_CLK_ROOT		= 127,
	ECSPI3_CLK_ROOT			= 131,
	PDM_CLK_ROOT			= 132,
	SAI7_CLK_ROOT			= 134,
	CLK_ROOT_MAX,
};
#else
enum clk_root_index {
	ARM_A53_CLK_ROOT		= 0,
	ARM_M4_CLK_ROOT			= 1,
	VPU_A53_CLK_ROOT		= 2,
	GPU3D_CLK_ROOT			= 3,
	GPU2D_CLK_ROOT			= 4,
	MAIN_AXI_CLK_ROOT		= 16,
	ENET_AXI_CLK_ROOT		= 17,
	NAND_USDHC_BUS_CLK_ROOT		= 18,
	VPU_BUS_CLK_ROOT		= 19,
	DISPLAY_AXI_CLK_ROOT		= 20,
	DISPLAY_APB_CLK_ROOT		= 21,
	DISPLAY_RTRM_CLK_ROOT		= 22,
	USB_BUS_CLK_ROOT		= 23,
	GPU_AXI_CLK_ROOT		= 24,
	GPU_AHB_CLK_ROOT		= 25,
	NOC_CLK_ROOT			= 26,
	NOC_APB_CLK_ROOT		= 27,
	AHB_CLK_ROOT			= 32,
	IPG_CLK_ROOT			= 33,
	AUDIO_AHB_CLK_ROOT		= 34,
	MIPI_DSI_ESC_RX_CLK_ROOT	= 36,
	DRAM_SEL_CFG			= 48,
	CORE_SEL_CFG			= 49,
	DRAM_ALT_CLK_ROOT		= 64,
	DRAM_APB_CLK_ROOT		= 65,
	VPU_G1_CLK_ROOT			= 66,
	VPU_G2_CLK_ROOT			= 67,
	DISPLAY_DTRC_CLK_ROOT		= 68,
	DISPLAY_DC8000_CLK_ROOT		= 69,
	PCIE_CTRL_CLK_ROOT		= 70,
	PCIE_PHY_CLK_ROOT		= 71,
	PCIE_AUX_CLK_ROOT		= 72,
	DC_PIXEL_CLK_ROOT		= 73,
	LCDIF_PIXEL_CLK_ROOT		= 74,
	SAI1_CLK_ROOT			= 75,
	SAI2_CLK_ROOT			= 76,
	SAI3_CLK_ROOT			= 77,
	SAI4_CLK_ROOT			= 78,
	SAI5_CLK_ROOT			= 79,
	SAI6_CLK_ROOT			= 80,
	SPDIF1_CLK_ROOT			= 81,
	SPDIF2_CLK_ROOT			= 82,
	ENET_REF_CLK_ROOT		= 83,
	ENET_TIMER_CLK_ROOT		= 84,
	ENET_PHY_REF_CLK_ROOT		= 85,
	NAND_CLK_ROOT			= 86,
	QSPI_CLK_ROOT			= 87,
	USDHC1_CLK_ROOT			= 88,
	USDHC2_CLK_ROOT			= 89,
	I2C1_CLK_ROOT			= 90,
	I2C2_CLK_ROOT			= 91,
	I2C3_CLK_ROOT			= 92,
	I2C4_CLK_ROOT			= 93,
	UART1_CLK_ROOT			= 94,
	UART2_CLK_ROOT			= 95,
	UART3_CLK_ROOT			= 96,
	UART4_CLK_ROOT			= 97,
	USB_CORE_REF_CLK_ROOT		= 98,
	USB_PHY_REF_CLK_ROOT		= 99,
	GIC_CLK_ROOT			= 100,
	ECSPI1_CLK_ROOT			= 101,
	ECSPI2_CLK_ROOT			= 102,
	PWM1_CLK_ROOT			= 103,
	PWM2_CLK_ROOT			= 104,
	PWM3_CLK_ROOT			= 105,
	PWM4_CLK_ROOT			= 106,
	GPT1_CLK_ROOT			= 107,
	GPT2_CLK_ROOT			= 108,
	GPT3_CLK_ROOT			= 109,
	GPT4_CLK_ROOT			= 110,
	GPT5_CLK_ROOT			= 111,
	GPT6_CLK_ROOT			= 112,
	TRACE_CLK_ROOT			= 113,
	WDOG_CLK_ROOT			= 114,
	WRCLK_CLK_ROOT			= 115,
	IPP_DO_CLKO1			= 116,
	IPP_DO_CLKO2			= 117,
	MIPI_DSI_CORE_CLK_ROOT		= 118,
	MIPI_DSI_PHY_REF_CLK_ROOT	= 119,
	MIPI_DSI_DBI_CLK_ROOT		= 120,
	USDHC3_CLK_ROOT			= 121,
	MIPI_CSI1_CORE_CLK_ROOT		= 122,
	MIPI_CSI1_PHY_REF_CLK_ROOT	= 123,
	MIPI_CSI1_ESC_CLK_ROOT		= 124,
	MIPI_CSI2_CORE_CLK_ROOT		= 125,
	MIPI_CSI2_PHY_REF_CLK_ROOT	= 126,
	MIPI_CSI2_ESC_CLK_ROOT		= 127,
	PCIE2_CTRL_CLK_ROOT		= 128,
	PCIE2_PHY_CLK_ROOT		= 129,
	PCIE2_AUX_CLK_ROOT		= 130,
	ECSPI3_CLK_ROOT			= 131,
	PDM_CLK_ROOT			= 132,
	VPU_H1_CLK_ROOT			= 133,
	CLK_ROOT_MAX,
};
#endif

enum clk_root_src {
	OSC_24M_CLK,
	ARM_PLL_CLK,
	DRAM_PLL1_CLK,
	VIDEO_PLL2_CLK,
	VPU_PLL_CLK,
	GPU_PLL_CLK,
	SYSTEM_PLL1_800M_CLK,
	SYSTEM_PLL1_400M_CLK,
	SYSTEM_PLL1_266M_CLK,
	SYSTEM_PLL1_200M_CLK,
	SYSTEM_PLL1_160M_CLK,
	SYSTEM_PLL1_133M_CLK,
	SYSTEM_PLL1_100M_CLK,
	SYSTEM_PLL1_80M_CLK,
	SYSTEM_PLL1_40M_CLK,
	SYSTEM_PLL2_1000M_CLK,
	SYSTEM_PLL2_500M_CLK,
	SYSTEM_PLL2_333M_CLK,
	SYSTEM_PLL2_250M_CLK,
	SYSTEM_PLL2_200M_CLK,
	SYSTEM_PLL2_166M_CLK,
	SYSTEM_PLL2_125M_CLK,
	SYSTEM_PLL2_100M_CLK,
	SYSTEM_PLL2_50M_CLK,
	SYSTEM_PLL3_CLK,
	AUDIO_PLL1_CLK,
	AUDIO_PLL2_CLK,
	VIDEO_PLL_CLK,
	OSC_32K_CLK,
	EXT_CLK_1,
	EXT_CLK_2,
	EXT_CLK_3,
	EXT_CLK_4,
	OSC_HDMI_CLK
};

enum clk_ccgr_index {
	CCGR_DVFS = 0,
	CCGR_ANAMIX = 1,
	CCGR_CPU = 2,
	CCGR_CSU = 3,
	CCGR_DEBUG = 4,
	CCGR_DDR1 = 5,
	CCGR_ECSPI1 = 7,
	CCGR_ECSPI2 = 8,
	CCGR_ECSPI3 = 9,
	CCGR_ENET1 = 10,
	CCGR_GPIO1 = 11,
	CCGR_GPIO2 = 12,
	CCGR_GPIO3 = 13,
	CCGR_GPIO4 = 14,
	CCGR_GPIO5 = 15,
	CCGR_GPT1 = 16,
	CCGR_GPT2 = 17,
	CCGR_GPT3 = 18,
	CCGR_GPT4 = 19,
	CCGR_GPT5 = 20,
	CCGR_GPT6 = 21,
	CCGR_HS = 22,
	CCGR_I2C1 = 23,
	CCGR_I2C2 = 24,
	CCGR_I2C3 = 25,
	CCGR_I2C4 = 26,
	CCGR_IOMUX = 27,
	CCGR_IOMUX1 = 28,
	CCGR_IOMUX2 = 29,
	CCGR_IOMUX3 = 30,
	CCGR_IOMUX4 = 31,
	CCGR_SNVSMIX_IPG_CLK = 32,
	CCGR_MU = 33,
	CCGR_OCOTP = 34,
	CCGR_OCRAM = 35,
	CCGR_OCRAM_S = 36,
	CCGR_PCIE = 37,
	CCGR_PERFMON1 = 38,
	CCGR_PERFMON2 = 39,
	CCGR_PWM1 = 40,
	CCGR_PWM2 = 41,
	CCGR_PWM3 = 42,
	CCGR_PWM4 = 43,
	CCGR_QOS = 44,
	CCGR_QOS_DISPMIX = 45,
	CCGR_QOS_ETHENET = 46,
	CCGR_QSPI = 47,
	CCGR_RAWNAND = 48,
	CCGR_RDC = 49,
	CCGR_ROM = 50,
	CCGR_SAI1 = 51,
	CCGR_SAI2 = 52,
	CCGR_SAI3 = 53,
	CCGR_SAI4 = 54,
	CCGR_SAI5 = 55,
	CCGR_SAI6 = 56,
	CCGR_SCTR = 57,
	CCGR_SDMA1 = 58,
	CCGR_SDMA2 = 59,
	CCGR_SEC_DEBUG = 60,
	CCGR_SEMA1 = 61,
	CCGR_SEMA2 = 62,
	CCGR_SIM_DISPLAY = 63,
	CCGR_SIM_ENET = 64,
	CCGR_SIM_M = 65,
	CCGR_SIM_MAIN = 66,
	CCGR_SIM_S = 67,
	CCGR_SIM_WAKEUP = 68,
	CCGR_SIM_HSIO = 69,
	CCGR_SIM_VPU = 70,
	CCGR_SNVS = 71,
	CCGR_TRACE = 72,
	CCGR_UART1 = 73,
	CCGR_UART2 = 74,
	CCGR_UART3 = 75,
	CCGR_UART4 = 76,
	CCGR_USB_MSCALE_PL301 = 77,
	CCGR_GPU3D = 79,
	CCGR_USDHC1 = 81,
	CCGR_USDHC2 = 82,
	CCGR_WDOG1 = 83,
	CCGR_WDOG2 = 84,
	CCGR_WDOG3 = 85,
	CCGR_VPUG1 = 86,
	CCGR_GPU_BUS = 87,
	CCGR_VPUH1 = 89,
	CCGR_VPUG2 = 90,
	CCGR_PDM = 91,
	CCGR_GIC = 92,
	CCGR_DISPMIX = 93,
	CCGR_USDHC3 = 94,
	CCGR_SDMA3 = 95,
	CCGR_XTAL = 96,
	CCGR_PLL = 97,
	CCGR_TEMP_SENSOR = 98,
	CCGR_VPUMIX_BUS = 99,
	CCGR_GPU2D = 102,
	CCGR_MAX
};

enum clk_src_index {
	CLK_SRC_CKIL_SYNC_REQ = 0,
	CLK_SRC_ARM_PLL_EN = 1,
	CLK_SRC_GPU_PLL_EN = 2,
	CLK_SRC_VPU_PLL_EN = 3,
	CLK_SRC_DRAM_PLL_EN = 4,
	CLK_SRC_SYSTEM_PLL1_EN = 5,
	CLK_SRC_SYSTEM_PLL2_EN = 6,
	CLK_SRC_SYSTEM_PLL3_EN = 7,
	CLK_SRC_AUDIO_PLL1_EN = 8,
	CLK_SRC_AUDIO_PLL2_EN = 9,
	CLK_SRC_VIDEO_PLL1_EN = 10,
	CLK_SRC_RESERVED = 11,
	CLK_SRC_ARM_PLL = 12,
	CLK_SRC_GPU_PLL = 13,
	CLK_SRC_VPU_PLL = 14,
	CLK_SRC_DRAM_PLL = 15,
	CLK_SRC_SYSTEM_PLL1_800M = 16,
	CLK_SRC_SYSTEM_PLL1_400M = 17,
	CLK_SRC_SYSTEM_PLL1_266M = 18,
	CLK_SRC_SYSTEM_PLL1_200M = 19,
	CLK_SRC_SYSTEM_PLL1_160M = 20,
	CLK_SRC_SYSTEM_PLL1_133M = 21,
	CLK_SRC_SYSTEM_PLL1_100M = 22,
	CLK_SRC_SYSTEM_PLL1_80M = 23,
	CLK_SRC_SYSTEM_PLL1_40M = 24,
	CLK_SRC_SYSTEM_PLL2_1000M = 25,
	CLK_SRC_SYSTEM_PLL2_500M = 26,
	CLK_SRC_SYSTEM_PLL2_333M = 27,
	CLK_SRC_SYSTEM_PLL2_250M = 28,
	CLK_SRC_SYSTEM_PLL2_200M = 29,
	CLK_SRC_SYSTEM_PLL2_166M = 30,
	CLK_SRC_SYSTEM_PLL2_125M = 31,
	CLK_SRC_SYSTEM_PLL2_100M = 32,
	CLK_SRC_SYSTEM_PLL2_50M = 33,
	CLK_SRC_SYSTEM_PLL3 = 34,
	CLK_SRC_AUDIO_PLL1 = 35,
	CLK_SRC_AUDIO_PLL2 = 36,
	CLK_SRC_VIDEO_PLL1 = 37,
};

#define INTPLL_LOCK_MASK			BIT(31)
#define INTPLL_LOCK_SEL_MASK			BIT(29)
#define INTPLL_EXT_BYPASS_MASK			BIT(28)
#define INTPLL_DIV20_CLKE_MASK			BIT(27)
#define INTPLL_DIV20_CLKE_OVERRIDE_MASK		BIT(26)
#define INTPLL_DIV10_CLKE_MASK			BIT(25)
#define INTPLL_DIV10_CLKE_OVERRIDE_MASK		BIT(24)
#define INTPLL_DIV8_CLKE_MASK			BIT(23)
#define INTPLL_DIV8_CLKE_OVERRIDE_MASK		BIT(22)
#define INTPLL_DIV6_CLKE_MASK			BIT(21)
#define INTPLL_DIV6_CLKE_OVERRIDE_MASK		BIT(20)
#define INTPLL_DIV5_CLKE_MASK			BIT(19)
#define INTPLL_DIV5_CLKE_OVERRIDE_MASK		BIT(18)
#define INTPLL_DIV4_CLKE_MASK			BIT(17)
#define INTPLL_DIV4_CLKE_OVERRIDE_MASK		BIT(16)
#define INTPLL_DIV3_CLKE_MASK			BIT(15)
#define INTPLL_DIV3_CLKE_OVERRIDE_MASK		BIT(14)
#define INTPLL_DIV2_CLKE_MASK			BIT(13)
#define INTPLL_DIV2_CLKE_OVERRIDE_MASK		BIT(12)
#define INTPLL_CLKE_MASK			BIT(11)
#define INTPLL_CLKE_OVERRIDE_MASK		BIT(10)
#define INTPLL_RST_MASK				BIT(9)
#define INTPLL_RST_OVERRIDE_MASK		BIT(8)
#define INTPLL_BYPASS_MASK			BIT(4)
#define INTPLL_PAD_CLK_SEL_MASK			GENMASK(3, 2)
#define INTPLL_REF_CLK_SEL_MASK			GENMASK(1, 0)

#define INTPLL_MAIN_DIV_MASK		GENMASK(21, 12)
#define INTPLL_MAIN_DIV_VAL(n)		((n << 12) & GENMASK(21, 12))
#define INTPLL_MAIN_DIV_SHIFT		12
#define INTPLL_PRE_DIV_MASK		GENMASK(9, 4)
#define INTPLL_PRE_DIV_VAL(n)		((n << 4) & GENMASK(9, 4))
#define INTPLL_PRE_DIV_SHIFT		4
#define INTPLL_POST_DIV_MASK		GENMASK(2, 0)
#define INTPLL_POST_DIV_VAL(n)		((n << 0) & GENMASK(2, 0))
#define INTPLL_POST_DIV_SHIFT		0

#define INTPLL_LOCK_CON_DLY_MASK	GENMASK(5, 4)
#define INTPLL_LOCK_CON_DLY_SHIFT	4
#define INTPLL_LOCK_CON_OUT_MASK	GENMASK(3, 2)
#define INTPLL_LOCK_CON_OUT_SHIFT	2
#define INTPLL_LOCK_CON_IN_MASK		GENMASK(1, 0)
#define INTPLL_LOCK_CON_IN_SHIFT	0

#define INTPLL_LRD_EN_MASK		BIT(21)
#define INTPLL_FOUT_MASK		BIT(20)
#define INTPLL_AFC_SEL_MASK		BIT(19)
#define INTPLL_PBIAS_CTRL_MASK		BIT(18)
#define INTPLL_PBIAS_CTRL_EN_MASK	BIT(17)
#define INTPLL_AFCINIT_SEL_MASK		BIT(16)
#define INTPLL_FSEL_MASK		BIT(14)
#define INTPLL_FEED_EN_MASK		BIT(13)
#define INTPLL_EXTAFC_MASK		GENMASK(7, 3)
#define INTPLL_AFC_EN_MASK		BIT(2)
#define INTPLL_ICP_MASK			GENMASK(1, 0)

#endif
