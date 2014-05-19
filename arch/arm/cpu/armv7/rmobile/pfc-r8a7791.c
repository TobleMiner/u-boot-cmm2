/*
 * arch/arm/cpu/armv7/rmobile/pfc-r8a7791.c
 *
 * Copyright (C) 2013 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: GPL-2.0
 */

#include <common.h>
#include <sh_pfc.h>
#include <asm/gpio.h>
#include "pfc-r8a7790.h"

enum {
	PINMUX_RESERVED = 0,

	PINMUX_DATA_BEGIN,
	GP_ALL(DATA),
	PINMUX_DATA_END,

	PINMUX_INPUT_BEGIN,
	GP_ALL(IN),
	PINMUX_INPUT_END,

	PINMUX_OUTPUT_BEGIN,
	GP_ALL(OUT),
	PINMUX_OUTPUT_END,

	PINMUX_FUNCTION_BEGIN,
	GP_ALL(FN),

	/* GPSR0 */
	FN_IP0_0, FN_IP0_1, FN_IP0_2, FN_IP0_3, FN_IP0_4, FN_IP0_5,
	FN_IP0_6, FN_IP0_7, FN_IP0_8, FN_IP0_9, FN_IP0_10, FN_IP0_11,
	FN_IP0_12, FN_IP0_13, FN_IP0_14, FN_IP0_15, FN_IP0_18_16, FN_IP0_20_19,
	FN_IP0_22_21, FN_IP0_24_23, FN_IP0_26_25, FN_IP0_28_27, FN_IP0_30_29,
	FN_IP1_1_0, FN_IP1_3_2, FN_IP1_5_4, FN_IP1_7_6, FN_IP1_10_8,
	FN_IP1_13_11, FN_IP1_16_14, FN_IP1_19_17, FN_IP1_22_20,

	/* GPSR1 */
	FN_IP1_25_23, FN_IP1_28_26, FN_IP1_31_29, FN_IP2_2_0, FN_IP2_4_3,
	FN_IP2_6_5, FN_IP2_9_7, FN_IP2_12_10, FN_IP2_15_13, FN_IP2_18_16,
	FN_IP2_20_19, FN_IP2_22_21, FN_EX_CS0_N, FN_IP2_24_23, FN_IP2_26_25,
	FN_IP2_29_27, FN_IP3_2_0, FN_IP3_5_3, FN_IP3_8_6, FN_RD_N,
	FN_IP3_11_9, FN_IP3_13_12, FN_IP3_15_14 , FN_IP3_17_16 , FN_IP3_19_18,
	FN_IP3_21_20,

	/* GPSR2 */
	FN_IP3_27_25, FN_IP3_30_28, FN_IP4_1_0, FN_IP4_4_2, FN_IP4_7_5,
	FN_IP4_9_8, FN_IP4_12_10, FN_IP4_15_13, FN_IP4_18_16, FN_IP4_19,
	FN_IP4_20, FN_IP4_21, FN_IP4_23_22, FN_IP4_25_24, FN_IP4_27_26,
	FN_IP4_30_28, FN_IP5_2_0, FN_IP5_5_3, FN_IP5_8_6, FN_IP5_11_9,
	FN_IP5_14_12, FN_IP5_16_15, FN_IP5_19_17, FN_IP5_21_20, FN_IP5_23_22,
	FN_IP5_25_24, FN_IP5_28_26, FN_IP5_31_29, FN_AUDIO_CLKA, FN_IP6_2_0,
	FN_IP6_5_3, FN_IP6_7_6,

	/* GPSR3 */
	FN_IP7_5_3, FN_IP7_8_6, FN_IP7_10_9, FN_IP7_12_11, FN_IP7_14_13,
	FN_IP7_16_15, FN_IP7_18_17, FN_IP7_20_19, FN_IP7_23_21, FN_IP7_26_24,
	FN_IP7_29_27, FN_IP8_2_0, FN_IP8_5_3, FN_IP8_8_6, FN_IP8_11_9,
	FN_IP8_14_12, FN_IP8_17_15, FN_IP8_20_18, FN_IP8_23_21, FN_IP8_25_24,
	FN_IP8_27_26, FN_IP8_30_28, FN_IP9_2_0, FN_IP9_5_3, FN_IP9_6, FN_IP9_7,
	FN_IP9_10_8, FN_IP9_11, FN_IP9_12, FN_IP9_15_13, FN_IP9_16,
	FN_IP9_18_17,

	/* GPSR4 */
	FN_VI0_CLK, FN_IP9_20_19, FN_IP9_22_21, FN_IP9_24_23, FN_IP9_26_25,
	FN_VI0_DATA0_VI0_B0, FN_VI0_DATA0_VI0_B1, FN_VI0_DATA0_VI0_B2,
	FN_IP9_28_27, FN_VI0_DATA0_VI0_B4, FN_VI0_DATA0_VI0_B5,
	FN_VI0_DATA0_VI0_B6, FN_VI0_DATA0_VI0_B7, FN_IP9_31_29, FN_IP10_2_0,
	FN_IP10_5_3, FN_IP10_8_6, FN_IP10_11_9, FN_IP10_14_12, FN_IP10_16_15,
	FN_IP10_18_17, FN_IP10_21_19, FN_IP10_24_22, FN_IP10_26_25,
	FN_IP10_28_27, FN_IP10_31_29, FN_IP11_2_0, FN_IP11_5_3, FN_IP11_8_6,
	FN_IP15_1_0, FN_IP15_3_2, FN_IP15_5_4,

	/* GPSR5 */
	FN_IP11_11_9, FN_IP11_14_12, FN_IP11_16_15, FN_IP11_18_17, FN_IP11_19,
	FN_IP11_20, FN_IP11_21, FN_IP11_22, FN_IP11_23, FN_IP11_24,
	FN_IP11_25, FN_IP11_26, FN_IP11_27, FN_IP11_29_28, FN_IP11_31_30,
	FN_IP12_1_0, FN_IP12_3_2, FN_IP12_6_4, FN_IP12_9_7, FN_IP12_12_10,
	FN_IP12_15_13, FN_IP12_17_16, FN_IP12_19_18, FN_IP12_21_20,
	FN_IP12_23_22, FN_IP12_26_24, FN_IP12_29_27, FN_IP13_2_0, FN_IP13_4_3,
	FN_IP13_6_5, FN_IP13_9_7, FN_IP3_24_22,

	/* GPSR6 */
	FN_IP13_10, FN_IP13_11, FN_IP13_12, FN_IP13_13, FN_IP13_14,
	FN_IP13_15, FN_IP13_18_16, FN_IP13_21_19, FN_IP13_22, FN_IP13_24_23,
	FN_IP13_25, FN_IP13_26, FN_IP13_27, FN_IP13_30_28, FN_IP14_1_0,
	FN_IP14_2, FN_IP14_3, FN_IP14_4, FN_IP14_5, FN_IP14_6, FN_IP14_7,
	FN_IP14_10_8, FN_IP14_13_11, FN_IP14_16_14, FN_IP14_19_17,
	FN_IP14_22_20, FN_IP14_25_23, FN_IP14_28_26, FN_IP14_31_29,

	/* GPSR7 */
	FN_IP15_17_15, FN_IP15_20_18, FN_IP15_23_21, FN_IP15_26_24,
	FN_IP15_29_27, FN_IP16_2_0, FN_IP16_5_3, FN_IP16_7_6, FN_IP16_9_8,
	FN_IP16_11_10, FN_IP6_9_8, FN_IP6_11_10, FN_IP6_13_12, FN_IP6_15_14,
	FN_IP6_18_16, FN_IP6_20_19, FN_IP6_23_21, FN_IP6_26_24, FN_IP6_29_27,
	FN_IP7_2_0, FN_IP15_8_6, FN_IP15_11_9, FN_IP15_14_12,
	FN_USB0_PWEN, FN_USB0_OVC, FN_USB1_PWEN,

	/* IPSR0 -  IPSR10 */

	/* IPSR11 */
	FN_VI0_R5, FN_VI2_DATA6, FN_GLO_SDATA_B, FN_RX0_C, FN_SDA1_D,
	FN_VI0_R6, FN_VI2_DATA7, FN_GLO_SS_B, FN_TX1_C, FN_SCL4_B,
	FN_VI0_R7, FN_GLO_RFON_B, FN_RX1_C, FN_CAN0_RX_E,
	FN_SDA4_B, FN_HRX1_D, FN_SCIFB0_RXD_D,
	FN_VI1_HSYNC_N, FN_AVB_RXD0, FN_TS_SDATA0_B, FN_TX4_B, FN_SCIFA4_TXD_B,
	FN_VI1_VSYNC_N, FN_AVB_RXD1, FN_TS_SCK0_B, FN_RX4_B, FN_SCIFA4_RXD_B,
	FN_VI1_CLKENB, FN_AVB_RXD2, FN_TS_SDEN0_B,
	FN_VI1_FIELD, FN_AVB_RXD3, FN_TS_SPSYNC0_B,
	FN_VI1_CLK, FN_AVB_RXD4, FN_VI1_DATA0, FN_AVB_RXD5,
	FN_VI1_DATA1, FN_AVB_RXD6, FN_VI1_DATA2, FN_AVB_RXD7,
	FN_VI1_DATA3, FN_AVB_RX_ER, FN_VI1_DATA4, FN_AVB_MDIO,
	FN_VI1_DATA5, FN_AVB_RX_DV, FN_VI1_DATA6, FN_AVB_MAGIC,
	FN_VI1_DATA7, FN_AVB_MDC,
	FN_ETH_MDIO, FN_AVB_RX_CLK, FN_SCL2_C,
	FN_ETH_CRS_DV, FN_AVB_LINK, FN_SDA2_C,

	/* IPSR12 */
	FN_ETH_RX_ER, FN_AVB_CRS, FN_SCL3, FN_SCL7,
	FN_ETH_RXD0, FN_AVB_PHY_INT, FN_SDA3, FN_SDA7,
	FN_ETH_RXD1, FN_AVB_GTXREFCLK, FN_CAN0_TX_C,
	FN_SCL2_D, FN_MSIOF1_RXD_E,
	FN_ETH_LINK, FN_AVB_TXD0, FN_CAN0_RX_C, FN_SDA2_D, FN_MSIOF1_SCK_E,
	FN_ETH_REFCLK, FN_AVB_TXD1, FN_SCIFA3_RXD_B,
	FN_CAN1_RX_C, FN_MSIOF1_SYNC_E,
	FN_ETH_TXD1, FN_AVB_TXD2, FN_SCIFA3_TXD_B,
	FN_CAN1_TX_C, FN_MSIOF1_TXD_E,
	FN_ETH_TX_EN, FN_AVB_TXD3, FN_TCLK1_B, FN_CAN_CLK_B,
	FN_ETH_MAGIC, FN_AVB_TXD4, FN_IETX_C,
	FN_ETH_TXD0, FN_AVB_TXD5, FN_IECLK_C,
	FN_ETH_MDC, FN_AVB_TXD6, FN_IERX_C,
	FN_STP_IVCXO27_0, FN_AVB_TXD7, FN_SCIFB2_TXD_D,
	FN_ADIDATA_B, FN_MSIOF0_SYNC_C,
	FN_STP_ISCLK_0, FN_AVB_TX_EN, FN_SCIFB2_RXD_D,
	FN_ADICS_SAMP_B, FN_MSIOF0_SCK_C,

	/* IPSR13 */
	/* MOD_SEL */
	FN_SEL_SCIF1_0, FN_SEL_SCIF1_1, FN_SEL_SCIF1_2, FN_SEL_SCIF1_3,
	FN_SEL_SCIFB_0, FN_SEL_SCIFB_1, FN_SEL_SCIFB_2, FN_SEL_SCIFB_3,
	FN_SEL_SCIFB2_0, FN_SEL_SCIFB2_1, FN_SEL_SCIFB2_2, FN_SEL_SCIFB2_3,
	FN_SEL_SCIFB1_0, FN_SEL_SCIFB1_1, FN_SEL_SCIFB1_2, FN_SEL_SCIFB1_3,
	FN_SEL_SCIFA1_0, FN_SEL_SCIFA1_1, FN_SEL_SCIFA1_2,
	FN_SEL_SSI9_0, FN_SEL_SSI9_1,
	FN_SEL_SCFA_0, FN_SEL_SCFA_1,
	FN_SEL_QSP_0, FN_SEL_QSP_1,
	FN_SEL_SSI7_0, FN_SEL_SSI7_1,
	FN_SEL_HSCIF1_0, FN_SEL_HSCIF1_1, FN_SEL_HSCIF1_2, FN_SEL_HSCIF1_3,
	FN_SEL_HSCIF1_4,
	FN_SEL_VI1_0, FN_SEL_VI1_1, FN_SEL_VI1_2,
	FN_SEL_TMU1_0, FN_SEL_TMU1_1,
	FN_SEL_LBS_0, FN_SEL_LBS_1, FN_SEL_LBS_2, FN_SEL_LBS_3,
	FN_SEL_TSIF0_0, FN_SEL_TSIF0_1, FN_SEL_TSIF0_2, FN_SEL_TSIF0_3,
	FN_SEL_SOF0_0, FN_SEL_SOF0_1, FN_SEL_SOF0_2,

	/* MOD_SEL2 */
	FN_SEL_SCIF0_0, FN_SEL_SCIF0_1, FN_SEL_SCIF0_2, FN_SEL_SCIF0_3,
	FN_SEL_SCIF0_4,
	FN_SEL_SCIF_0, FN_SEL_SCIF_1,
	FN_SEL_CAN0_0, FN_SEL_CAN0_1, FN_SEL_CAN0_2, FN_SEL_CAN0_3,
	FN_SEL_CAN0_4, FN_SEL_CAN0_5,
	FN_SEL_CAN1_0, FN_SEL_CAN1_1, FN_SEL_CAN1_2, FN_SEL_CAN1_3,
	FN_SEL_SCIFA2_0, FN_SEL_SCIFA2_1,
	FN_SEL_SCIF4_0, FN_SEL_SCIF4_1, FN_SEL_SCIF4_2,
	FN_SEL_ADG_0, FN_SEL_ADG_1,
	FN_SEL_FM_0, FN_SEL_FM_1, FN_SEL_FM_2, FN_SEL_FM_3, FN_SEL_FM_4,
	FN_SEL_SCIFA5_0, FN_SEL_SCIFA5_1, FN_SEL_SCIFA5_2,
	FN_SEL_GPS_0, FN_SEL_GPS_1, FN_SEL_GPS_2, FN_SEL_GPS_3,
	FN_SEL_SCIFA4_0, FN_SEL_SCIFA4_1, FN_SEL_SCIFA4_2,
	FN_SEL_SCIFA3_0, FN_SEL_SCIFA3_1, FN_SEL_SCIFA3_2,
	FN_SEL_SIM_0, FN_SEL_SIM_1,
	FN_SEL_SSI8_0, FN_SEL_SSI8_1,

	/* MOD_SEL3 */
	FN_SEL_HSCIF2_0, FN_SEL_HSCIF2_1, FN_SEL_HSCIF2_2, FN_SEL_HSCIF2_3,
	FN_SEL_CANCLK_0, FN_SEL_CANCLK_1, FN_SEL_CANCLK_2, FN_SEL_CANCLK_3,
	FN_SEL_IIC8_0, FN_SEL_IIC8_1, FN_SEL_IIC8_2,
	FN_SEL_IIC7_0, FN_SEL_IIC7_1, FN_SEL_IIC7_2,
	FN_SEL_IIC4_0, FN_SEL_IIC4_1, FN_SEL_IIC4_2,
	FN_SEL_IIC3_0, FN_SEL_IIC3_1, FN_SEL_IIC3_2, FN_SEL_IIC3_3,
	FN_SEL_SCIF3_0, FN_SEL_SCIF3_1, FN_SEL_SCIF3_2, FN_SEL_SCIF3_3,
	FN_SEL_IEB_0, FN_SEL_IEB_1, FN_SEL_IEB_2,
	FN_SEL_MMC_0, FN_SEL_MMC_1,
	FN_SEL_SCIF5_0, FN_SEL_SCIF5_1,
	FN_SEL_IIC2_0, FN_SEL_IIC2_1, FN_SEL_IIC2_2, FN_SEL_IIC2_3,
	FN_SEL_IIC1_0, FN_SEL_IIC1_1, FN_SEL_IIC1_2, FN_SEL_IIC1_3,
	FN_SEL_IIC1_4,
	FN_SEL_IIC0_0, FN_SEL_IIC0_1, FN_SEL_IIC0_2,

	/* MOD_SEL4 */
	FN_SEL_SOF1_0, FN_SEL_SOF1_1, FN_SEL_SOF1_2, FN_SEL_SOF1_3,
	FN_SEL_SOF1_4,
	FN_SEL_HSCIF0_0, FN_SEL_HSCIF0_1, FN_SEL_HSCIF0_2,
	FN_SEL_DIS_0, FN_SEL_DIS_1, FN_SEL_DIS_2,
	FN_SEL_RAD_0, FN_SEL_RAD_1,
	FN_SEL_RCN_0, FN_SEL_RCN_1,
	FN_SEL_RSP_0, FN_SEL_RSP_1,
	FN_SEL_SCIF2_0, FN_SEL_SCIF2_1, FN_SEL_SCIF2_2, FN_SEL_SCIF2_3,
	FN_SEL_SCIF2_4,
	FN_SEL_SOF2_0, FN_SEL_SOF2_1, FN_SEL_SOF2_2, FN_SEL_SOF2_3,
	FN_SEL_SOF2_4,
	FN_SEL_SSI1_0, FN_SEL_SSI1_1,
	FN_SEL_SSI0_0, FN_SEL_SSI0_1,
	FN_SEL_SSP_0, FN_SEL_SSP_1, FN_SEL_SSP_2,
	PINMUX_FUNCTION_END,

	PINMUX_MARK_BEGIN,

	EX_CS0_N_MARK, RD_N_MARK,

	AUDIO_CLKA_MARK,

	VI0_CLK_MARK, VI0_DATA0_VI0_B0_MARK, VI0_DATA0_VI0_B1_MARK,
	VI0_DATA0_VI0_B2_MARK, VI0_DATA0_VI0_B4_MARK, VI0_DATA0_VI0_B5_MARK,
	VI0_DATA0_VI0_B6_MARK, VI0_DATA0_VI0_B7_MARK,

	USB0_PWEN_MARK, USB0_OVC_MARK, USB1_PWEN_MARK,

	/* IPSR0  IPSR10 */
	/* IPSR11 */
	VI0_R5_MARK, VI2_DATA6_MARK, GLO_SDATA_B_MARK, RX0_C_MARK, SDA1_D_MARK,
	VI0_R6_MARK, VI2_DATA7_MARK, GLO_SS_B_MARK, TX1_C_MARK, SCL4_B_MARK,
	VI0_R7_MARK, GLO_RFON_B_MARK, RX1_C_MARK, CAN0_RX_E_MARK,
	SDA4_B_MARK, _MARK, HRX1_D_MARK, SCIFB0_RXD_D_MARK,
	VI1_HSYNC_N_MARK, AVB_RXD0_MARK, TS_SDATA0_B_MARK,
	TX4_B_MARK, SCIFA4_TXD_B_MARK,
	VI1_VSYNC_N_MARK, AVB_RXD1_MARK, TS_SCK0_B_MARK,
	RX4_B_MARK, SCIFA4_RXD_B_MARK,
	VI1_CLKENB_MARK, AVB_RXD2_MARK, TS_SDEN0_B_MARK,
	VI1_FIELD_MARK, AVB_RXD3_MARK, TS_SPSYNC0_B_MARK,
	VI1_CLK_MARK, AVB_RXD4_MARK, VI1_DATA0_MARK, AVB_RXD5_MARK,
	VI1_DATA1_MARK, AVB_RXD6_MARK, VI1_DATA2_MARK, AVB_RXD7_MARK,
	VI1_DATA3_MARK, AVB_RX_ER_MARK, VI1_DATA4_MARK, AVB_MDIO_MARK,
	VI1_DATA5_MARK, AVB_RX_DV_MARK, VI1_DATA6_MARK, AVB_MAGIC_MARK,
	VI1_DATA7_MARK, AVB_MDC_MARK,
	ETH_MDIO_MARK, AVB_RX_CLK_MARK, SCL2_C_MARK,
	ETH_CRS_DV_MARK, AVB_LINK_MARK, SDA2_C_MARK,

	/* IPSR12 */
	ETH_RX_ER_MARK, AVB_CRS_MARK, SCL3_MARK, SCL7_MARK,
	ETH_RXD0_MARK, AVB_PHY_INT_MARK, SDA3_MARK, SDA7_MARK,
	ETH_RXD1_MARK, AVB_GTXREFCLK_MARK, CAN0_TX_C_MARK,
	SCL2_D_MARK, MSIOF1_RXD_E_MARK,
	ETH_LINK_MARK, AVB_TXD0_MARK, CAN0_RX_C_MARK,
	SDA2_D_MARK, MSIOF1_SCK_E_MARK,
	ETH_REFCLK_MARK, AVB_TXD1_MARK, SCIFA3_RXD_B_MARK,
	CAN1_RX_C_MARK, MSIOF1_SYNC_E_MARK,
	ETH_TXD1_MARK, AVB_TXD2_MARK, SCIFA3_TXD_B_MARK,
	CAN1_TX_C_MARK, MSIOF1_TXD_E_MARK,
	ETH_TX_EN_MARK, AVB_TXD3_MARK, TCLK1_B_MARK, CAN_CLK_B_MARK,
	ETH_MAGIC_MARK, AVB_TXD4_MARK, IETX_C_MARK,
	ETH_TXD0_MARK, AVB_TXD5_MARK, IECLK_C_MARK,
	ETH_MDC_MARK, AVB_TXD6_MARK, IERX_C_MARK,
	STP_IVCXO27_0_MARK, AVB_TXD7_MARK, SCIFB2_TXD_D_MARK,
	ADIDATA_B_MARK, MSIOF0_SYNC_C_MARK,
	STP_ISCLK_0_MARK, AVB_TX_EN_MARK, SCIFB2_RXD_D_MARK,
	ADICS_SAMP_B_MARK, MSIOF0_SCK_C_MARK,

	/* IPSR13 */
	PINMUX_MARK_END,
};

static pinmux_enum_t pinmux_data[] = {
	PINMUX_DATA_GP_ALL(), /* PINMUX_DATA(GP_M_N_DATA, GP_M_N_FN...), */

	/* OTHER IPSR0  - IPSR10 */
	/* IPSR11 */
	PINMUX_IPSR_DATA(IP11_2_0, VI0_R5),
	PINMUX_IPSR_DATA(IP11_2_0, VI2_DATA6),
	PINMUX_IPSR_MODSEL_DATA(IP11_2_0, GLO_SDATA_B, SEL_GPS_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_2_0, RX0_C, SEL_SCIF0_2),
	PINMUX_IPSR_MODSEL_DATA(IP11_2_0, SDA1_D, SEL_IIC1_3),
	PINMUX_IPSR_DATA(IP11_5_3, VI0_R6),
	PINMUX_IPSR_DATA(IP11_5_3, VI2_DATA7),
	PINMUX_IPSR_MODSEL_DATA(IP11_5_3, GLO_SS_B, SEL_GPS_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_5_3, TX1_C, SEL_SCIF1_2),
	PINMUX_IPSR_MODSEL_DATA(IP11_5_3, SCL4_B, SEL_IIC4_1),
	PINMUX_IPSR_DATA(IP11_8_6, VI0_R7),
	PINMUX_IPSR_MODSEL_DATA(IP11_8_6, GLO_RFON_B, SEL_GPS_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_8_6, RX1_C, SEL_SCIF1_2),
	PINMUX_IPSR_MODSEL_DATA(IP11_8_6, CAN0_RX_E, SEL_CAN0_4),
	PINMUX_IPSR_MODSEL_DATA(IP11_8_6, SDA4_B, SEL_IIC4_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_8_6, HRX1_D, SEL_HSCIF1_3),
	PINMUX_IPSR_MODSEL_DATA(IP11_8_6, SCIFB0_RXD_D, SEL_SCIFB_3),
	PINMUX_IPSR_MODSEL_DATA(IP11_11_9, VI1_HSYNC_N, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_11_9, AVB_RXD0),
	PINMUX_IPSR_MODSEL_DATA(IP11_11_9, TS_SDATA0_B, SEL_TSIF0_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_11_9, TX4_B, SEL_SCIF4_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_11_9, SCIFA4_TXD_B, SEL_SCIFA4_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_14_12, VI1_VSYNC_N, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_14_12, AVB_RXD1),
	PINMUX_IPSR_MODSEL_DATA(IP11_14_12, TS_SCK0_B, SEL_TSIF0_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_14_12, RX4_B, SEL_SCIF4_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_14_12, SCIFA4_RXD_B, SEL_SCIFA4_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_16_15, VI1_CLKENB, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_16_15, AVB_RXD2),
	PINMUX_IPSR_MODSEL_DATA(IP11_16_15, TS_SDEN0_B, SEL_TSIF0_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_18_17, VI1_FIELD, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_18_17, AVB_RXD3),
	PINMUX_IPSR_MODSEL_DATA(IP11_18_17, TS_SPSYNC0_B, SEL_TSIF0_1),
	PINMUX_IPSR_MODSEL_DATA(IP11_19, VI1_CLK, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_19, AVB_RXD4),
	PINMUX_IPSR_MODSEL_DATA(IP11_20, VI1_DATA0, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_20, AVB_RXD5),
	PINMUX_IPSR_MODSEL_DATA(IP11_21, VI1_DATA1, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_21, AVB_RXD6),
	PINMUX_IPSR_MODSEL_DATA(IP11_22, VI1_DATA2, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_22, AVB_RXD7),
	PINMUX_IPSR_MODSEL_DATA(IP11_23, VI1_DATA3, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_23, AVB_RX_ER),
	PINMUX_IPSR_MODSEL_DATA(IP11_24, VI1_DATA4, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_24, AVB_MDIO),
	PINMUX_IPSR_MODSEL_DATA(IP11_25, VI1_DATA5, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_25, AVB_RX_DV),
	PINMUX_IPSR_MODSEL_DATA(IP11_26, VI1_DATA6, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_26, AVB_MAGIC),
	PINMUX_IPSR_MODSEL_DATA(IP11_27, VI1_DATA7, SEL_VI1_0),
	PINMUX_IPSR_DATA(IP11_27, AVB_MDC),
	PINMUX_IPSR_DATA(IP11_29_28, ETH_MDIO),
	PINMUX_IPSR_DATA(IP11_29_28, AVB_RX_CLK),
	PINMUX_IPSR_MODSEL_DATA(IP11_29_28, SCL2_C, SEL_IIC2_2),
	PINMUX_IPSR_DATA(IP11_31_30, ETH_CRS_DV),
	PINMUX_IPSR_DATA(IP11_31_30, AVB_LINK),
	PINMUX_IPSR_MODSEL_DATA(IP11_31_30, SDA2_C, SEL_IIC2_2),

	/* IPSR12 */
	PINMUX_IPSR_DATA(IP12_1_0, ETH_RX_ER),
	PINMUX_IPSR_DATA(IP12_1_0, AVB_CRS),
	PINMUX_IPSR_MODSEL_DATA(IP12_1_0, SCL3, SEL_IIC3_0),
	PINMUX_IPSR_MODSEL_DATA(IP12_1_0, SCL7, SEL_IIC7_0),
	PINMUX_IPSR_DATA(IP12_3_2, ETH_RXD0),
	PINMUX_IPSR_DATA(IP12_3_2, AVB_PHY_INT),
	PINMUX_IPSR_MODSEL_DATA(IP12_3_2, SDA3, SEL_IIC3_0),
	PINMUX_IPSR_MODSEL_DATA(IP12_3_2, SDA7, SEL_IIC7_0),
	PINMUX_IPSR_DATA(IP12_6_4, ETH_RXD1),
	PINMUX_IPSR_DATA(IP12_6_4, AVB_GTXREFCLK),
	PINMUX_IPSR_MODSEL_DATA(IP12_6_4, CAN0_TX_C, SEL_CAN0_2),
	PINMUX_IPSR_MODSEL_DATA(IP12_6_4, SCL2_D, SEL_IIC2_3),
	PINMUX_IPSR_MODSEL_DATA(IP12_6_4, MSIOF1_RXD_E, SEL_SOF1_4),
	PINMUX_IPSR_DATA(IP12_9_7, ETH_LINK),
	PINMUX_IPSR_DATA(IP12_9_7, AVB_TXD0),
	PINMUX_IPSR_MODSEL_DATA(IP12_9_7, CAN0_RX_C, SEL_CAN0_2),
	PINMUX_IPSR_MODSEL_DATA(IP12_9_7, SDA2_D, SEL_IIC2_3),
	PINMUX_IPSR_MODSEL_DATA(IP12_9_7, MSIOF1_SCK_E, SEL_SOF1_4),
	PINMUX_IPSR_DATA(IP12_12_10, ETH_REFCLK),
	PINMUX_IPSR_DATA(IP12_12_10, AVB_TXD1),
	PINMUX_IPSR_MODSEL_DATA(IP12_12_10, SCIFA3_RXD_B, SEL_SCIFA3_1),
	PINMUX_IPSR_MODSEL_DATA(IP12_12_10, CAN1_RX_C, SEL_CAN1_2),
	PINMUX_IPSR_MODSEL_DATA(IP12_12_10, MSIOF1_SYNC_E, SEL_SOF1_4),
	PINMUX_IPSR_DATA(IP12_15_13, ETH_TXD1),
	PINMUX_IPSR_DATA(IP12_15_13, AVB_TXD2),
	PINMUX_IPSR_MODSEL_DATA(IP12_15_13, SCIFA3_TXD_B, SEL_SCIFA3_1),
	PINMUX_IPSR_MODSEL_DATA(IP12_15_13, CAN1_TX_C, SEL_CAN1_2),
	PINMUX_IPSR_MODSEL_DATA(IP12_15_13, MSIOF1_TXD_E, SEL_SOF1_4),
	PINMUX_IPSR_DATA(IP12_17_16, ETH_TX_EN),
	PINMUX_IPSR_DATA(IP12_17_16, AVB_TXD3),
	PINMUX_IPSR_MODSEL_DATA(IP12_17_16, TCLK1_B, SEL_TMU1_0),
	PINMUX_IPSR_MODSEL_DATA(IP12_17_16, CAN_CLK_B, SEL_CANCLK_1),
	PINMUX_IPSR_DATA(IP12_19_18, ETH_MAGIC),
	PINMUX_IPSR_DATA(IP12_19_18, AVB_TXD4),
	PINMUX_IPSR_MODSEL_DATA(IP12_19_18, IETX_C, SEL_IEB_2),
	PINMUX_IPSR_DATA(IP12_21_20, ETH_TXD0),
	PINMUX_IPSR_DATA(IP12_21_20, AVB_TXD5),
	PINMUX_IPSR_MODSEL_DATA(IP12_21_20, IECLK_C, SEL_IEB_2),
	PINMUX_IPSR_DATA(IP12_23_22, ETH_MDC),
	PINMUX_IPSR_DATA(IP12_23_22, AVB_TXD6),
	PINMUX_IPSR_MODSEL_DATA(IP12_23_22, IERX_C, SEL_IEB_2),
	PINMUX_IPSR_MODSEL_DATA(IP12_26_24, STP_IVCXO27_0, SEL_SSP_0),
	PINMUX_IPSR_DATA(IP12_26_24, AVB_TXD7),
	PINMUX_IPSR_MODSEL_DATA(IP12_26_24, SCIFB2_TXD_D, SEL_SCIFB2_3),
	PINMUX_IPSR_MODSEL_DATA(IP12_26_24, ADIDATA_B, SEL_RAD_1),
	PINMUX_IPSR_MODSEL_DATA(IP12_26_24, MSIOF0_SYNC_C, SEL_SOF0_2),
	PINMUX_IPSR_MODSEL_DATA(IP12_29_27, STP_ISCLK_0, SEL_SSP_0),
	PINMUX_IPSR_DATA(IP12_29_27, AVB_TX_EN),
	PINMUX_IPSR_MODSEL_DATA(IP12_29_27, SCIFB2_RXD_D, SEL_SCIFB2_3),
	PINMUX_IPSR_MODSEL_DATA(IP12_29_27, ADICS_SAMP_B, SEL_RAD_1),
	PINMUX_IPSR_MODSEL_DATA(IP12_29_27, MSIOF0_SCK_C, SEL_SOF0_2),

	/* IPSR13 - IPSR16 */
};

static struct pinmux_gpio pinmux_gpios[] = {
	PINMUX_GPIO_GP_ALL(),

	/* OTHER, IPSR0 - IPSR10 */
	/* IPSR11 */
	GPIO_FN(VI0_R5), GPIO_FN(VI2_DATA6), GPIO_FN(GLO_SDATA_B),
	GPIO_FN(RX0_C), GPIO_FN(SDA1_D),
	GPIO_FN(VI0_R6), GPIO_FN(VI2_DATA7),
	GPIO_FN(GLO_SS_B), GPIO_FN(TX1_C), GPIO_FN(SCL4_B),
	GPIO_FN(VI0_R7), GPIO_FN(GLO_RFON_B),
	GPIO_FN(RX1_C), GPIO_FN(CAN0_RX_E),
	GPIO_FN(SDA4_B), GPIO_FN(HRX1_D), GPIO_FN(SCIFB0_RXD_D),
	GPIO_FN(VI1_HSYNC_N), GPIO_FN(AVB_RXD0), GPIO_FN(TS_SDATA0_B),
	GPIO_FN(TX4_B), GPIO_FN(SCIFA4_TXD_B),
	GPIO_FN(VI1_VSYNC_N), GPIO_FN(AVB_RXD1), GPIO_FN(TS_SCK0_B),
	GPIO_FN(RX4_B), GPIO_FN(SCIFA4_RXD_B),
	GPIO_FN(VI1_CLKENB), GPIO_FN(AVB_RXD2), GPIO_FN(TS_SDEN0_B),
	GPIO_FN(VI1_FIELD), GPIO_FN(AVB_RXD3), GPIO_FN(TS_SPSYNC0_B),
	GPIO_FN(VI1_CLK), GPIO_FN(AVB_RXD4),
	GPIO_FN(VI1_DATA0), GPIO_FN(AVB_RXD5),
	GPIO_FN(VI1_DATA1), GPIO_FN(AVB_RXD6),
	GPIO_FN(VI1_DATA2), GPIO_FN(AVB_RXD7),
	GPIO_FN(VI1_DATA3), GPIO_FN(AVB_RX_ER),
	GPIO_FN(VI1_DATA4), GPIO_FN(AVB_MDIO),
	GPIO_FN(VI1_DATA5), GPIO_FN(AVB_RX_DV),
	GPIO_FN(VI1_DATA6), GPIO_FN(AVB_MAGIC),
	GPIO_FN(VI1_DATA7), GPIO_FN(AVB_MDC),
	GPIO_FN(ETH_MDIO), GPIO_FN(AVB_RX_CLK), GPIO_FN(SCL2_C),
	GPIO_FN(ETH_CRS_DV), GPIO_FN(AVB_LINK), GPIO_FN(SDA2_C),

	/* IPSR12 */
	GPIO_FN(ETH_RX_ER), GPIO_FN(AVB_CRS), GPIO_FN(SCL3), GPIO_FN(SCL7),
	GPIO_FN(ETH_RXD0), GPIO_FN(AVB_PHY_INT), GPIO_FN(SDA3), GPIO_FN(SDA7),
	GPIO_FN(ETH_RXD1), GPIO_FN(AVB_GTXREFCLK), GPIO_FN(CAN0_TX_C),
	GPIO_FN(SCL2_D), GPIO_FN(MSIOF1_RXD_E),
	GPIO_FN(ETH_LINK), GPIO_FN(AVB_TXD0), GPIO_FN(CAN0_RX_C),
	GPIO_FN(SDA2_D), GPIO_FN(MSIOF1_SCK_E),
	GPIO_FN(ETH_REFCLK), GPIO_FN(AVB_TXD1), GPIO_FN(SCIFA3_RXD_B),
	GPIO_FN(CAN1_RX_C), GPIO_FN(MSIOF1_SYNC_E),
	GPIO_FN(ETH_TXD1), GPIO_FN(AVB_TXD2), GPIO_FN(SCIFA3_TXD_B),
	GPIO_FN(CAN1_TX_C), GPIO_FN(MSIOF1_TXD_E),
	GPIO_FN(ETH_TX_EN), GPIO_FN(AVB_TXD3),
	GPIO_FN(TCLK1_B), GPIO_FN(CAN_CLK_B),
	GPIO_FN(ETH_MAGIC), GPIO_FN(AVB_TXD4), GPIO_FN(IETX_C),
	GPIO_FN(ETH_TXD0), GPIO_FN(AVB_TXD5), GPIO_FN(IECLK_C),
	GPIO_FN(ETH_MDC), GPIO_FN(AVB_TXD6), GPIO_FN(IERX_C),
	GPIO_FN(STP_IVCXO27_0), GPIO_FN(AVB_TXD7), GPIO_FN(SCIFB2_TXD_D),
	GPIO_FN(ADIDATA_B), GPIO_FN(MSIOF0_SYNC_C),
	GPIO_FN(STP_ISCLK_0), GPIO_FN(AVB_TX_EN), GPIO_FN(SCIFB2_RXD_D),
	GPIO_FN(ADICS_SAMP_B), GPIO_FN(MSIOF0_SCK_C),

	/* IPSR13 - IPSR16 */
};

static struct pinmux_cfg_reg pinmux_config_regs[] = {
	{ PINMUX_CFG_REG("GPSR0", 0xE6060004, 32, 1) {
		GP_0_31_FN, FN_IP1_22_20,
		GP_0_30_FN, FN_IP1_19_17,
		GP_0_29_FN, FN_IP1_16_14,
		GP_0_28_FN, FN_IP1_13_11,
		GP_0_27_FN, FN_IP1_10_8,
		GP_0_26_FN, FN_IP1_7_6,
		GP_0_25_FN, FN_IP1_5_4,
		GP_0_24_FN, FN_IP1_3_2,
		GP_0_23_FN, FN_IP1_1_0,
		GP_0_22_FN, FN_IP0_30_29,
		GP_0_21_FN, FN_IP0_28_27,
		GP_0_20_FN, FN_IP0_26_25,
		GP_0_19_FN, FN_IP0_24_23,
		GP_0_18_FN, FN_IP0_22_21,
		GP_0_17_FN, FN_IP0_20_19,
		GP_0_16_FN, FN_IP0_18_16,
		GP_0_15_FN, FN_IP0_15,
		GP_0_14_FN, FN_IP0_14,
		GP_0_13_FN, FN_IP0_13,
		GP_0_12_FN, FN_IP0_12,
		GP_0_11_FN, FN_IP0_11,
		GP_0_10_FN, FN_IP0_10,
		GP_0_9_FN, FN_IP0_9,
		GP_0_8_FN, FN_IP0_8,
		GP_0_7_FN, FN_IP0_7,
		GP_0_6_FN, FN_IP0_6,
		GP_0_5_FN, FN_IP0_5,
		GP_0_4_FN, FN_IP0_4,
		GP_0_3_FN, FN_IP0_3,
		GP_0_2_FN, FN_IP0_2,
		GP_0_1_FN, FN_IP0_1,
		GP_0_0_FN, FN_IP0_0, }
	},
	{ PINMUX_CFG_REG("GPSR1", 0xE6060008, 32, 1) {
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		GP_1_25_FN, FN_IP3_21_20,
		GP_1_24_FN, FN_IP3_19_18,
		GP_1_23_FN, FN_IP3_17_16,
		GP_1_22_FN, FN_IP3_15_14,
		GP_1_21_FN, FN_IP3_13_12,
		GP_1_20_FN, FN_IP3_11_9,
		GP_1_19_FN, FN_RD_N,
		GP_1_18_FN, FN_IP3_8_6,
		GP_1_17_FN, FN_IP3_5_3,
		GP_1_16_FN, FN_IP3_2_0,
		GP_1_15_FN, FN_IP2_29_27,
		GP_1_14_FN, FN_IP2_26_25,
		GP_1_13_FN, FN_IP2_24_23,
		GP_1_12_FN, FN_EX_CS0_N,
		GP_1_11_FN, FN_IP2_22_21,
		GP_1_10_FN, FN_IP2_20_19,
		GP_1_9_FN, FN_IP2_18_16,
		GP_1_8_FN, FN_IP2_15_13,
		GP_1_7_FN, FN_IP2_12_10,
		GP_1_6_FN, FN_IP2_9_7,
		GP_1_5_FN, FN_IP2_6_5,
		GP_1_4_FN, FN_IP2_4_3,
		GP_1_3_FN, FN_IP2_2_0,
		GP_1_2_FN, FN_IP1_31_29,
		GP_1_1_FN, FN_IP1_28_26,
		GP_1_0_FN, FN_IP1_25_23, }
	},
	{ PINMUX_CFG_REG("GPSR2", 0xE606000C, 32, 1) {
		GP_2_31_FN, FN_IP6_7_6,
		GP_2_30_FN, FN_IP6_5_3,
		GP_2_29_FN, FN_IP6_2_0,
		GP_2_28_FN, FN_AUDIO_CLKA,
		GP_2_27_FN, FN_IP5_31_29,
		GP_2_26_FN, FN_IP5_28_26,
		GP_2_25_FN, FN_IP5_25_24,
		GP_2_24_FN, FN_IP5_23_22,
		GP_2_23_FN, FN_IP5_21_20,
		GP_2_22_FN, FN_IP5_19_17,
		GP_2_21_FN, FN_IP5_16_15,
		GP_2_20_FN, FN_IP5_14_12,
		GP_2_19_FN, FN_IP5_11_9,
		GP_2_18_FN, FN_IP5_8_6,
		GP_2_17_FN, FN_IP5_5_3,
		GP_2_16_FN, FN_IP5_2_0,
		GP_2_15_FN, FN_IP4_30_28,
		GP_2_14_FN, FN_IP4_27_26,
		GP_2_13_FN, FN_IP4_25_24,
		GP_2_12_FN, FN_IP4_23_22,
		GP_2_11_FN, FN_IP4_21,
		GP_2_10_FN, FN_IP4_20,
		GP_2_9_FN, FN_IP4_19,
		GP_2_8_FN, FN_IP4_18_16,
		GP_2_7_FN, FN_IP4_15_13,
		GP_2_6_FN, FN_IP4_12_10,
		GP_2_5_FN, FN_IP4_9_8,
		GP_2_4_FN, FN_IP4_7_5,
		GP_2_3_FN, FN_IP4_4_2,
		GP_2_2_FN, FN_IP4_1_0,
		GP_2_1_FN, FN_IP3_30_28,
		GP_2_0_FN, FN_IP3_27_25 }
	},
	{ PINMUX_CFG_REG("GPSR3", 0xE6060010, 32, 1) {
		GP_3_31_FN, FN_IP9_18_17,
		GP_3_30_FN, FN_IP9_16,
		GP_3_29_FN, FN_IP9_15_13,
		GP_3_28_FN, FN_IP9_12,
		GP_3_27_FN, FN_IP9_11,
		GP_3_26_FN, FN_IP9_10_8,
		GP_3_25_FN, FN_IP9_7,
		GP_3_24_FN, FN_IP9_6,
		GP_3_23_FN, FN_IP9_5_3,
		GP_3_22_FN, FN_IP9_2_0,
		GP_3_21_FN, FN_IP8_30_28,
		GP_3_20_FN, FN_IP8_27_26,
		GP_3_19_FN, FN_IP8_25_24,
		GP_3_18_FN, FN_IP8_23_21,
		GP_3_17_FN, FN_IP8_20_18,
		GP_3_16_FN, FN_IP8_17_15,
		GP_3_15_FN, FN_IP8_14_12,
		GP_3_14_FN, FN_IP8_11_9,
		GP_3_13_FN, FN_IP8_8_6,
		GP_3_12_FN, FN_IP8_5_3,
		GP_3_11_FN, FN_IP8_2_0,
		GP_3_10_FN, FN_IP7_29_27,
		GP_3_9_FN, FN_IP7_26_24,
		GP_3_8_FN, FN_IP7_23_21,
		GP_3_7_FN, FN_IP7_20_19,
		GP_3_6_FN, FN_IP7_18_17,
		GP_3_5_FN, FN_IP7_16_15,
		GP_3_4_FN, FN_IP7_14_13,
		GP_3_3_FN, FN_IP7_12_11,
		GP_3_2_FN, FN_IP7_10_9,
		GP_3_1_FN, FN_IP7_8_6,
		GP_3_0_FN, FN_IP7_5_3 }
	},
	{ PINMUX_CFG_REG("GPSR4", 0xE6060014, 32, 1) {
		GP_4_31_FN, FN_IP15_5_4,
		GP_4_30_FN, FN_IP15_3_2,
		GP_4_29_FN, FN_IP15_1_0,
		GP_4_28_FN, FN_IP11_8_6,
		GP_4_27_FN, FN_IP11_5_3,
		GP_4_26_FN, FN_IP11_2_0,
		GP_4_25_FN, FN_IP10_31_29,
		GP_4_24_FN, FN_IP10_28_27,
		GP_4_23_FN, FN_IP10_26_25,
		GP_4_22_FN, FN_IP10_24_22,
		GP_4_21_FN, FN_IP10_21_19,
		GP_4_20_FN, FN_IP10_18_17,
		GP_4_19_FN, FN_IP10_16_15,
		GP_4_18_FN, FN_IP10_14_12,
		GP_4_17_FN, FN_IP10_11_9,
		GP_4_16_FN, FN_IP10_8_6,
		GP_4_15_FN, FN_IP10_5_3,
		GP_4_14_FN, FN_IP10_2_0,
		GP_4_13_FN, FN_IP9_31_29,
		GP_4_12_FN, FN_VI0_DATA0_VI0_B7,
		GP_4_11_FN, FN_VI0_DATA0_VI0_B6,
		GP_4_10_FN, FN_VI0_DATA0_VI0_B5,
		GP_4_9_FN, FN_VI0_DATA0_VI0_B4,
		GP_4_8_FN, FN_IP9_28_27,
		GP_4_7_FN, FN_VI0_DATA0_VI0_B2,
		GP_4_6_FN, FN_VI0_DATA0_VI0_B1,
		GP_4_5_FN, FN_VI0_DATA0_VI0_B0,
		GP_4_4_FN, FN_IP9_26_25,
		GP_4_3_FN, FN_IP9_24_23,
		GP_4_2_FN, FN_IP9_22_21,
		GP_4_1_FN, FN_IP9_20_19,
		GP_4_0_FN, FN_VI0_CLK }
	},
	{ PINMUX_CFG_REG("GPSR5", 0xE6060018, 32, 1) {
		GP_5_31_FN, FN_IP3_24_22,
		GP_5_30_FN, FN_IP13_9_7,
		GP_5_29_FN, FN_IP13_6_5,
		GP_5_28_FN, FN_IP13_4_3,
		GP_5_27_FN, FN_IP13_2_0,
		GP_5_26_FN, FN_IP12_29_27,
		GP_5_25_FN, FN_IP12_26_24,
		GP_5_24_FN, FN_IP12_23_22,
		GP_5_23_FN, FN_IP12_21_20,
		GP_5_22_FN, FN_IP12_19_18,
		GP_5_21_FN, FN_IP12_17_16,
		GP_5_20_FN, FN_IP12_15_13,
		GP_5_19_FN, FN_IP12_12_10,
		GP_5_18_FN, FN_IP12_9_7,
		GP_5_17_FN, FN_IP12_6_4,
		GP_5_16_FN, FN_IP12_3_2,
		GP_5_15_FN, FN_IP12_1_0,
		GP_5_14_FN, FN_IP11_31_30,
		GP_5_13_FN, FN_IP11_29_28,
		GP_5_12_FN, FN_IP11_27,
		GP_5_11_FN, FN_IP11_26,
		GP_5_10_FN, FN_IP11_25,
		GP_5_9_FN, FN_IP11_24,
		GP_5_8_FN, FN_IP11_23,
		GP_5_7_FN, FN_IP11_22,
		GP_5_6_FN, FN_IP11_21,
		GP_5_5_FN, FN_IP11_20,
		GP_5_4_FN, FN_IP11_19,
		GP_5_3_FN, FN_IP11_18_17,
		GP_5_2_FN, FN_IP11_16_15,
		GP_5_1_FN, FN_IP11_14_12,
		GP_5_0_FN, FN_IP11_11_9 }
	},
	{ PINMUX_CFG_REG("GPSR6", 0xE606001C, 32, 1) {
		0, 0,
		0, 0,
		GP_6_29_FN, FN_IP14_31_29,
		GP_6_28_FN, FN_IP14_28_26,
		GP_6_27_FN, FN_IP14_25_23,
		GP_6_26_FN, FN_IP14_22_20,
		GP_6_25_FN, FN_IP14_19_17,
		GP_6_24_FN, FN_IP14_16_14,
		GP_6_23_FN, FN_IP14_13_11,
		GP_6_22_FN, FN_IP14_10_8,
		GP_6_21_FN, FN_IP14_7,
		GP_6_20_FN, FN_IP14_6,
		GP_6_19_FN, FN_IP14_5,
		GP_6_18_FN, FN_IP14_4,
		GP_6_17_FN, FN_IP14_3,
		GP_6_16_FN, FN_IP14_2,
		GP_6_15_FN, FN_IP14_1_0,
		GP_6_14_FN, FN_IP13_30_28,
		GP_6_13_FN, FN_IP13_27,
		GP_6_12_FN, FN_IP13_26,
		GP_6_11_FN, FN_IP13_25,
		GP_6_10_FN, FN_IP13_24_23,
		GP_6_9_FN, FN_IP13_22,
		0, 0,
		GP_6_7_FN, FN_IP13_21_19,
		GP_6_6_FN, FN_IP13_18_16,
		GP_6_5_FN, FN_IP13_15,
		GP_6_4_FN, FN_IP13_14,
		GP_6_3_FN, FN_IP13_13,
		GP_6_2_FN, FN_IP13_12,
		GP_6_1_FN, FN_IP13_11,
		GP_6_0_FN, FN_IP13_10 }
	},
	{ PINMUX_CFG_REG("GPSR7", 0xE6060074, 32, 1) {
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		GP_7_25_FN, FN_USB1_PWEN,
		GP_7_24_FN, FN_USB0_OVC,
		GP_7_23_FN, FN_USB0_PWEN,
		GP_7_22_FN, FN_IP15_14_12,
		GP_7_21_FN, FN_IP15_11_9,
		GP_7_20_FN, FN_IP15_8_6,
		GP_7_19_FN, FN_IP7_2_0,
		GP_7_18_FN, FN_IP6_29_27,
		GP_7_17_FN, FN_IP6_26_24,
		GP_7_16_FN, FN_IP6_23_21,
		GP_7_15_FN, FN_IP6_20_19,
		GP_7_14_FN, FN_IP6_18_16,
		GP_7_13_FN, FN_IP6_15_14,
		GP_7_12_FN, FN_IP6_13_12,
		GP_7_11_FN, FN_IP6_11_10,
		GP_7_10_FN, FN_IP6_9_8,
		GP_7_9_FN, FN_IP16_11_10,
		GP_7_8_FN, FN_IP16_9_8,
		GP_7_7_FN, FN_IP16_7_6,
		GP_7_6_FN, FN_IP16_5_3,
		GP_7_5_FN, FN_IP16_2_0,
		GP_7_4_FN, FN_IP15_29_27,
		GP_7_3_FN, FN_IP15_26_24,
		GP_7_2_FN, FN_IP15_23_21,
		GP_7_1_FN, FN_IP15_20_18,
		GP_7_0_FN, FN_IP15_17_15 }
	},
	/* IPSR0 - IPSR10 */
	{ PINMUX_CFG_REG_VAR("IPSR11", 0xE606004C, 32,
			     2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
			     3, 3, 3, 3, 3) {
		/* IP11_31_30 [2] */
		FN_ETH_CRS_DV, FN_AVB_LINK, FN_SDA2_C, 0,
		/* IP11_29_28 [2] */
		FN_ETH_MDIO, FN_AVB_RX_CLK, FN_SCL2_C, 0,
		/* IP11_27 [1] */
		FN_VI1_DATA7, FN_AVB_MDC,
		/* IP11_26 [1] */
		FN_VI1_DATA6, FN_AVB_MAGIC,
		/* IP11_25 [1] */
		FN_VI1_DATA5, FN_AVB_RX_DV,
		/* IP11_24 [1] */
		FN_VI1_DATA4, FN_AVB_MDIO,
		/* IP11_23 [1] */
		FN_VI1_DATA3, FN_AVB_RX_ER,
		/* IP11_22 [1] */
		FN_VI1_DATA2, FN_AVB_RXD7,
		/* IP11_21 [1] */
		FN_VI1_DATA1, FN_AVB_RXD6,
		/* IP11_20 [1] */
		FN_VI1_DATA0, FN_AVB_RXD5,
		/* IP11_19 [1] */
		FN_VI1_CLK, FN_AVB_RXD4,
		/* IP11_18_17 [2] */
		FN_VI1_FIELD, FN_AVB_RXD3, FN_TS_SPSYNC0_B, 0,
		/* IP11_16_15 [2] */
		FN_VI1_CLKENB, FN_AVB_RXD2, FN_TS_SDEN0_B, 0,
		/* IP11_14_12 [3] */
		FN_VI1_VSYNC_N, FN_AVB_RXD1, FN_TS_SCK0_B,
		FN_RX4_B, FN_SCIFA4_RXD_B,
		0, 0, 0,
		/* IP11_11_9 [3] */
		FN_VI1_HSYNC_N, FN_AVB_RXD0, FN_TS_SDATA0_B,
		FN_TX4_B, FN_SCIFA4_TXD_B,
		0, 0, 0,
		/* IP11_8_6 [3] */
		FN_VI0_R7, FN_GLO_RFON_B, FN_RX1_C, FN_CAN0_RX_E,
		FN_SDA4_B, FN_HRX1_D, FN_SCIFB0_RXD_D, 0,
		/* IP11_5_3 [3] */
		FN_VI0_R6, FN_VI2_DATA7, FN_GLO_SS_B, FN_TX1_C, FN_SCL4_B,
		0, 0, 0,
		/* IP11_2_0 [3] */
		FN_VI0_R5, FN_VI2_DATA6, FN_GLO_SDATA_B, FN_RX0_C, FN_SDA1_D,
		0, 0, 0, }
	},
	{ PINMUX_CFG_REG_VAR("IPSR12", 0xE6060050, 32,
			     2, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2) {
		/* IP12_31_30 [2] */
		0, 0, 0, 0,
		/* IP12_29_27 [3] */
		FN_STP_ISCLK_0, FN_AVB_TX_EN, FN_SCIFB2_RXD_D,
		FN_ADICS_SAMP_B, FN_MSIOF0_SCK_C,
		0, 0, 0,
		/* IP12_26_24 [3] */
		FN_STP_IVCXO27_0, FN_AVB_TXD7, FN_SCIFB2_TXD_D,
		FN_ADIDATA_B, FN_MSIOF0_SYNC_C,
		0, 0, 0,
		/* IP12_23_22 [2] */
		FN_ETH_MDC, FN_AVB_TXD6, FN_IERX_C, 0,
		/* IP12_21_20 [2] */
		FN_ETH_TXD0, FN_AVB_TXD5, FN_IECLK_C, 0,
		/* IP12_19_18 [2] */
		FN_ETH_MAGIC, FN_AVB_TXD4, FN_IETX_C, 0,
		/* IP12_17_16 [2] */
		FN_ETH_TX_EN, FN_AVB_TXD3, FN_TCLK1_B, FN_CAN_CLK_B,
		/* IP12_15_13 [3] */
		FN_ETH_TXD1, FN_AVB_TXD2, FN_SCIFA3_TXD_B,
		FN_CAN1_TX_C, FN_MSIOF1_TXD_E,
		0, 0, 0,
		/* IP12_12_10 [3] */
		FN_ETH_REFCLK, FN_AVB_TXD1, FN_SCIFA3_RXD_B,
		FN_CAN1_RX_C, FN_MSIOF1_SYNC_E,
		0, 0, 0,
		/* IP12_9_7 [3] */
		FN_ETH_LINK, FN_AVB_TXD0, FN_CAN0_RX_C,
		FN_SDA2_D, FN_MSIOF1_SCK_E,
		0, 0, 0,
		/* IP12_6_4 [3] */
		FN_ETH_RXD1, FN_AVB_GTXREFCLK, FN_CAN0_TX_C,
		FN_SCL2_D, FN_MSIOF1_RXD_E,
		0, 0, 0,
		/* IP12_3_2 [2] */
		FN_ETH_RXD0, FN_AVB_PHY_INT, FN_SDA3, FN_SDA7,
		/* IP12_1_0 [2] */
		FN_ETH_RX_ER, FN_AVB_CRS, FN_SCL3, FN_SCL7, }
	},

	/* IPSR13 - IPSR16 */

	{ PINMUX_CFG_REG_VAR("MOD_SEL", 0xE6060090, 32,
			     1, 2, 2, 2, 3, 2, 1, 1, 1, 1,
			     3, 2, 2, 2, 1, 2, 2, 2) {
		/* RESEVED [1] */
		0, 0,
		/* SEL_SCIF1 [2] */
		FN_SEL_SCIF1_0, FN_SEL_SCIF1_1, FN_SEL_SCIF1_2, FN_SEL_SCIF1_3,
		/* SEL_SCIFB [2] */
		FN_SEL_SCIFB_0, FN_SEL_SCIFB_1, FN_SEL_SCIFB_2, FN_SEL_SCIFB_3,
		/* SEL_SCIFB2 [2] */
		FN_SEL_SCIFB2_0, FN_SEL_SCIFB2_1,
		FN_SEL_SCIFB2_2, FN_SEL_SCIFB2_3,
		/* SEL_SCIFB1 [3] */
		FN_SEL_SCIFB1_0, FN_SEL_SCIFB1_1,
		FN_SEL_SCIFB1_2, FN_SEL_SCIFB1_3,
		0, 0, 0, 0,
		/* SEL_SCIFA1 [2] */
		FN_SEL_SCIFA1_0, FN_SEL_SCIFA1_1, FN_SEL_SCIFA1_2, 0,
		/* SEL_SSI9 [1] */
		FN_SEL_SSI9_0, FN_SEL_SSI9_1,
		/* SEL_SCFA [1] */
		FN_SEL_SCFA_0, FN_SEL_SCFA_1,
		/* SEL_QSP [1] */
		FN_SEL_QSP_0, FN_SEL_QSP_1,
		/* SEL_SSI7 [1] */
		FN_SEL_SSI7_0, FN_SEL_SSI7_1,
		/* SEL_HSCIF1 [3] */
		FN_SEL_HSCIF1_0, FN_SEL_HSCIF1_1, FN_SEL_HSCIF1_2,
		FN_SEL_HSCIF1_3, FN_SEL_HSCIF1_4,
		0, 0, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* SEL_VI1 [2] */
		FN_SEL_VI1_0, FN_SEL_VI1_1, FN_SEL_VI1_2, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* SEL_TMU [1] */
		FN_SEL_TMU1_0, FN_SEL_TMU1_1,
		/* SEL_LBS [2] */
		FN_SEL_LBS_0, FN_SEL_LBS_1, FN_SEL_LBS_2, FN_SEL_LBS_3,
		/* SEL_TSIF0 [2] */
		FN_SEL_TSIF0_0, FN_SEL_TSIF0_1, FN_SEL_TSIF0_2, FN_SEL_TSIF0_3,
		/* SEL_SOF0 [2] */
		FN_SEL_SOF0_0, FN_SEL_SOF0_1, FN_SEL_SOF0_2, 0, }
	},
	{ PINMUX_CFG_REG_VAR("MOD_SEL2", 0xE6060094, 32,
			     3, 1, 1, 3, 2, 1, 1, 2, 2,
			     1, 3, 2, 1, 2, 2, 2, 1, 1, 1) {
		/* SEL_SCIF0 [3] */
		FN_SEL_SCIF0_0, FN_SEL_SCIF0_1, FN_SEL_SCIF0_2,
		FN_SEL_SCIF0_3, FN_SEL_SCIF0_4,
		0, 0, 0,
		/* RESEVED [1] */
		0, 0,
		/* SEL_SCIF [1] */
		FN_SEL_SCIF_0, FN_SEL_SCIF_1,
		/* SEL_CAN0 [3] */
		FN_SEL_CAN0_0, FN_SEL_CAN0_1, FN_SEL_CAN0_2, FN_SEL_CAN0_3,
		FN_SEL_CAN0_4, FN_SEL_CAN0_5,
		0, 0,
		/* SEL_CAN1 [2] */
		FN_SEL_CAN1_0, FN_SEL_CAN1_1, FN_SEL_CAN1_2, FN_SEL_CAN1_3,
		/* RESEVED [1] */
		0, 0,
		/* SEL_SCIFA2 [1] */
		FN_SEL_SCIFA2_0, FN_SEL_SCIFA2_1,
		/* SEL_SCIF4 [2] */
		FN_SEL_SCIF4_0, FN_SEL_SCIF4_1, FN_SEL_SCIF4_2, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* SEL_ADG [1] */
		FN_SEL_ADG_0, FN_SEL_ADG_1,
		/* SEL_FM [3] */
		FN_SEL_FM_0, FN_SEL_FM_1, FN_SEL_FM_2,
		FN_SEL_FM_3, FN_SEL_FM_4,
		0, 0, 0,
		/* SEL_SCIFA5 [2] */
		FN_SEL_SCIFA5_0, FN_SEL_SCIFA5_1, FN_SEL_SCIFA5_2, 0,
		/* RESEVED [1] */
		0, 0,
		/* SEL_GPS [2] */
		FN_SEL_GPS_0, FN_SEL_GPS_1, FN_SEL_GPS_2, FN_SEL_GPS_3,
		/* SEL_SCIFA4 [2] */
		FN_SEL_SCIFA4_0, FN_SEL_SCIFA4_1, FN_SEL_SCIFA4_2, 0,
		/* SEL_SCIFA3 [2] */
		FN_SEL_SCIFA3_0, FN_SEL_SCIFA3_1, FN_SEL_SCIFA3_2, 0,
		/* SEL_SIM [1] */
		FN_SEL_SIM_0, FN_SEL_SIM_1,
		/* RESEVED [1] */
		0, 0,
		/* SEL_SSI8 [1] */
		FN_SEL_SSI8_0, FN_SEL_SSI8_1, }
	},
	{ PINMUX_CFG_REG_VAR("MOD_SEL3", 0xE6060098, 32,
			     2, 2, 2, 2, 2, 2, 2, 2,
			     1, 1, 2, 2, 3, 2, 2, 2, 1) {
		/* SEL_HSCIF2 [2] */
		FN_SEL_HSCIF2_0, FN_SEL_HSCIF2_1,
		FN_SEL_HSCIF2_2, FN_SEL_HSCIF2_3,
		/* SEL_CANCLK [2] */
		FN_SEL_CANCLK_0, FN_SEL_CANCLK_1,
		FN_SEL_CANCLK_2, FN_SEL_CANCLK_3,
		/* SEL_IIC8 [2] */
		FN_SEL_IIC8_0, FN_SEL_IIC8_1, FN_SEL_IIC8_2, 0,
		/* SEL_IIC7 [2] */
		FN_SEL_IIC7_0, FN_SEL_IIC7_1, FN_SEL_IIC7_2, 0,
		/* SEL_IIC4 [2] */
		FN_SEL_IIC4_0, FN_SEL_IIC4_1, FN_SEL_IIC4_2, 0,
		/* SEL_IIC3 [2] */
		FN_SEL_IIC3_0, FN_SEL_IIC3_1, FN_SEL_IIC3_2, FN_SEL_IIC3_3,
		/* SEL_SCIF3 [2] */
		FN_SEL_SCIF3_0, FN_SEL_SCIF3_1, FN_SEL_SCIF3_2, FN_SEL_SCIF3_3,
		/* SEL_IEB [2] */
		FN_SEL_IEB_0, FN_SEL_IEB_1, FN_SEL_IEB_2, 0,
		/* SEL_MMC [1] */
		FN_SEL_MMC_0, FN_SEL_MMC_1,
		/* SEL_SCIF5 [1] */
		FN_SEL_SCIF5_0, FN_SEL_SCIF5_1,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* SEL_IIC2 [2] */
		FN_SEL_IIC2_0, FN_SEL_IIC2_1, FN_SEL_IIC2_2, FN_SEL_IIC2_3,
		/* SEL_IIC1 [3] */
		FN_SEL_IIC1_0, FN_SEL_IIC1_1, FN_SEL_IIC1_2, FN_SEL_IIC1_3,
		FN_SEL_IIC1_4,
		0, 0, 0,
		/* SEL_IIC0 [2] */
		FN_SEL_IIC0_0, FN_SEL_IIC0_1, FN_SEL_IIC0_2, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* RESEVED [1] */
		0, 0, }
	},
	{ PINMUX_CFG_REG_VAR("MOD_SEL4", 0xE606009C, 32,
			     3, 2, 2, 1, 1, 1, 1, 3, 2,
			     2, 3, 1, 1, 1, 2, 2, 2, 2) {
		/* SEL_SOF1 [3] */
		FN_SEL_SOF1_0, FN_SEL_SOF1_1, FN_SEL_SOF1_2, FN_SEL_SOF1_3,
		FN_SEL_SOF1_4,
		0, 0, 0,
		/* SEL_HSCIF0 [2] */
		FN_SEL_HSCIF0_0, FN_SEL_HSCIF0_1, FN_SEL_HSCIF0_2, 0,
		/* SEL_DIS [2] */
		FN_SEL_DIS_0, FN_SEL_DIS_1, FN_SEL_DIS_2, 0,
		/* RESEVED [1] */
		0, 0,
		/* SEL_RAD [1] */
		FN_SEL_RAD_0, FN_SEL_RAD_1,
		/* SEL_RCN [1] */
		FN_SEL_RCN_0, FN_SEL_RCN_1,
		/* SEL_RSP [1] */
		FN_SEL_RSP_0, FN_SEL_RSP_1,
		/* SEL_SCIF2 [3] */
		FN_SEL_SCIF2_0, FN_SEL_SCIF2_1, FN_SEL_SCIF2_2,
		FN_SEL_SCIF2_3, FN_SEL_SCIF2_4,
		0, 0, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* SEL_SOF2 [3] */
		FN_SEL_SOF2_0, FN_SEL_SOF2_1, FN_SEL_SOF2_2,
		FN_SEL_SOF2_3, FN_SEL_SOF2_4,
		0, 0, 0,
		/* RESEVED [1] */
		0, 0,
		/* SEL_SSI1 [1] */
		FN_SEL_SSI1_0, FN_SEL_SSI1_1,
		/* SEL_SSI0 [1] */
		FN_SEL_SSI0_0, FN_SEL_SSI0_1,
		/* SEL_SSP [2] */
		FN_SEL_SSP_0, FN_SEL_SSP_1, FN_SEL_SSP_2, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* RESEVED [2] */
		0, 0, 0, 0,
		/* RESEVED [2] */
		0, 0, 0, 0, }
	},
	{ PINMUX_CFG_REG("INOUTSEL0", 0xE6050004, 32, 1) { GP_INOUTSEL(0) } },
	{ PINMUX_CFG_REG("INOUTSEL1", 0xE6051004, 32, 1) {
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		GP_1_25_IN, GP_1_25_OUT,
		GP_1_24_IN, GP_1_24_OUT,
		GP_1_23_IN, GP_1_23_OUT,
		GP_1_22_IN, GP_1_22_OUT,
		GP_1_21_IN, GP_1_21_OUT,
		GP_1_20_IN, GP_1_20_OUT,
		GP_1_19_IN, GP_1_19_OUT,
		GP_1_18_IN, GP_1_18_OUT,
		GP_1_17_IN, GP_1_17_OUT,
		GP_1_16_IN, GP_1_16_OUT,
		GP_1_15_IN, GP_1_15_OUT,
		GP_1_14_IN, GP_1_14_OUT,
		GP_1_13_IN, GP_1_13_OUT,
		GP_1_12_IN, GP_1_12_OUT,
		GP_1_11_IN, GP_1_11_OUT,
		GP_1_10_IN, GP_1_10_OUT,
		GP_1_9_IN, GP_1_9_OUT,
		GP_1_8_IN, GP_1_8_OUT,
		GP_1_7_IN, GP_1_7_OUT,
		GP_1_6_IN, GP_1_6_OUT,
		GP_1_5_IN, GP_1_5_OUT,
		GP_1_4_IN, GP_1_4_OUT,
		GP_1_3_IN, GP_1_3_OUT,
		GP_1_2_IN, GP_1_2_OUT,
		GP_1_1_IN, GP_1_1_OUT,
		GP_1_0_IN, GP_1_0_OUT, }
	},
	{ PINMUX_CFG_REG("INOUTSEL2", 0xE6052004, 32, 1) { GP_INOUTSEL(2) } },
	{ PINMUX_CFG_REG("INOUTSEL3", 0xE6053004, 32, 1) { GP_INOUTSEL(3) } },
	{ PINMUX_CFG_REG("INOUTSEL4", 0xE6054004, 32, 1) { GP_INOUTSEL(4) } },
	{ PINMUX_CFG_REG("INOUTSEL5", 0xE6055004, 32, 1) { GP_INOUTSEL(5) } },
	{ PINMUX_CFG_REG("INOUTSEL6", 0xE6055404, 32, 1) { GP_INOUTSEL(6) } },
	{ PINMUX_CFG_REG("INOUTSEL7", 0xE6055804, 32, 1) {
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		GP_7_25_IN, GP_7_25_OUT,
		GP_7_24_IN, GP_7_24_OUT,
		GP_7_23_IN, GP_7_23_OUT,
		GP_7_22_IN, GP_7_22_OUT,
		GP_7_21_IN, GP_7_21_OUT,
		GP_7_20_IN, GP_7_20_OUT,
		GP_7_19_IN, GP_7_19_OUT,
		GP_7_18_IN, GP_7_18_OUT,
		GP_7_17_IN, GP_7_17_OUT,
		GP_7_16_IN, GP_7_16_OUT,
		GP_7_15_IN, GP_7_15_OUT,
		GP_7_14_IN, GP_7_14_OUT,
		GP_7_13_IN, GP_7_13_OUT,
		GP_7_12_IN, GP_7_12_OUT,
		GP_7_11_IN, GP_7_11_OUT,
		GP_7_10_IN, GP_7_10_OUT,
		GP_7_9_IN, GP_7_9_OUT,
		GP_7_8_IN, GP_7_8_OUT,
		GP_7_7_IN, GP_7_7_OUT,
		GP_7_6_IN, GP_7_6_OUT,
		GP_7_5_IN, GP_7_5_OUT,
		GP_7_4_IN, GP_7_4_OUT,
		GP_7_3_IN, GP_7_3_OUT,
		GP_7_2_IN, GP_7_2_OUT,
		GP_7_1_IN, GP_7_1_OUT,
		GP_7_0_IN, GP_7_0_OUT, }
	},
	{ },
};

static struct pinmux_data_reg pinmux_data_regs[] = {
	{ PINMUX_DATA_REG("INDT0", 0xE6050008, 32) { GP_INDT(0) } },
	{ PINMUX_DATA_REG("INDT1", 0xE6051008, 32) {
		0, 0, 0, 0,
		0, 0, GP_1_25_DATA, GP_1_24_DATA,
		GP_1_23_DATA, GP_1_22_DATA, GP_1_21_DATA, GP_1_20_DATA,
		GP_1_19_DATA, GP_1_18_DATA, GP_1_17_DATA, GP_1_16_DATA,
		GP_1_15_DATA, GP_1_14_DATA, GP_1_13_DATA, GP_1_12_DATA,
		GP_1_11_DATA, GP_1_10_DATA, GP_1_9_DATA, GP_1_8_DATA,
		GP_1_7_DATA, GP_1_6_DATA, GP_1_5_DATA, GP_1_4_DATA,
		GP_1_3_DATA, GP_1_2_DATA, GP_1_1_DATA, GP_1_0_DATA }
	},
	{ PINMUX_DATA_REG("INDT2", 0xE6052008, 32) { GP_INDT(2) } },
	{ PINMUX_DATA_REG("INDT3", 0xE6053008, 32) { GP_INDT(3) } },
	{ PINMUX_DATA_REG("INDT4", 0xE6054008, 32) { GP_INDT(4) } },
	{ PINMUX_DATA_REG("INDT5", 0xE6055008, 32) { GP_INDT(5) } },
	{ PINMUX_DATA_REG("INDT6", 0xE6055408, 32) { GP_INDT(6) } },
	{ PINMUX_DATA_REG("INDT7", 0xE6055808, 32) {
		0, 0, 0, 0,
		0, 0, GP_7_25_DATA, GP_7_24_DATA,
		GP_7_23_DATA, GP_7_22_DATA, GP_7_21_DATA, GP_7_20_DATA,
		GP_7_19_DATA, GP_7_18_DATA, GP_7_17_DATA, GP_7_16_DATA,
		GP_7_15_DATA, GP_7_14_DATA, GP_7_13_DATA, GP_7_12_DATA,
		GP_7_11_DATA, GP_7_10_DATA, GP_7_9_DATA, GP_7_8_DATA,
		GP_7_7_DATA, GP_7_6_DATA, GP_7_5_DATA, GP_7_4_DATA,
		GP_7_3_DATA, GP_7_2_DATA, GP_7_1_DATA, GP_7_0_DATA }
	},
	{ },
};

static struct pinmux_info r8a7791_pinmux_info = {
	.name = "r8a7791_pfc",

	.unlock_reg = 0xe6060000, /* PMMR */

	.reserved_id = PINMUX_RESERVED,
	.data = { PINMUX_DATA_BEGIN, PINMUX_DATA_END },
	.input = { PINMUX_INPUT_BEGIN, PINMUX_INPUT_END },
	.output = { PINMUX_OUTPUT_BEGIN, PINMUX_OUTPUT_END },
	.mark = { PINMUX_MARK_BEGIN, PINMUX_MARK_END },
	.function = { PINMUX_FUNCTION_BEGIN, PINMUX_FUNCTION_END },

	.first_gpio = GPIO_GP_0_0,
	.last_gpio = GPIO_FN_MSIOF0_SCK_C /* GPIO_FN_CAN1_RX_B */,

	.gpios = pinmux_gpios,
	.cfg_regs = pinmux_config_regs,
	.data_regs = pinmux_data_regs,

	.gpio_data = pinmux_data,
	.gpio_data_size = ARRAY_SIZE(pinmux_data),
};

void r8a7791_pinmux_init(void)
{
	register_pinmux(&r8a7791_pinmux_info);
}
