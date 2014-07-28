#ifndef __ASM_R8A7794_H__
#define __ASM_R8A7794_H__

/* Pin Function Controller:
 * GPIO_FN_xx - GPIO used to select pin function
 * GPIO_GP_x_x - GPIO mapped to real I/O pin on CPU
 */
enum {
	GPIO_GP_0_0, GPIO_GP_0_1, GPIO_GP_0_2, GPIO_GP_0_3,
	GPIO_GP_0_4, GPIO_GP_0_5, GPIO_GP_0_6, GPIO_GP_0_7,
	GPIO_GP_0_8, GPIO_GP_0_9, GPIO_GP_0_10, GPIO_GP_0_11,
	GPIO_GP_0_12, GPIO_GP_0_13, GPIO_GP_0_14, GPIO_GP_0_15,
	GPIO_GP_0_16, GPIO_GP_0_17, GPIO_GP_0_18, GPIO_GP_0_19,
	GPIO_GP_0_20, GPIO_GP_0_21, GPIO_GP_0_22, GPIO_GP_0_23,
	GPIO_GP_0_24, GPIO_GP_0_25, GPIO_GP_0_26, GPIO_GP_0_27,
	GPIO_GP_0_28, GPIO_GP_0_29, GPIO_GP_0_30, GPIO_GP_0_31,

	GPIO_GP_1_0, GPIO_GP_1_1, GPIO_GP_1_2, GPIO_GP_1_3,
	GPIO_GP_1_4, GPIO_GP_1_5, GPIO_GP_1_6, GPIO_GP_1_7,
	GPIO_GP_1_8, GPIO_GP_1_9, GPIO_GP_1_10, GPIO_GP_1_11,
	GPIO_GP_1_12, GPIO_GP_1_13, GPIO_GP_1_14, GPIO_GP_1_15,
	GPIO_GP_1_16, GPIO_GP_1_17, GPIO_GP_1_18, GPIO_GP_1_19,
	GPIO_GP_1_20, GPIO_GP_1_21, GPIO_GP_1_22, GPIO_GP_1_23,
	GPIO_GP_1_24, GPIO_GP_1_25,

	GPIO_GP_2_0, GPIO_GP_2_1, GPIO_GP_2_2, GPIO_GP_2_3,
	GPIO_GP_2_4, GPIO_GP_2_5, GPIO_GP_2_6, GPIO_GP_2_7,
	GPIO_GP_2_8, GPIO_GP_2_9, GPIO_GP_2_10, GPIO_GP_2_11,
	GPIO_GP_2_12, GPIO_GP_2_13, GPIO_GP_2_14, GPIO_GP_2_15,
	GPIO_GP_2_16, GPIO_GP_2_17, GPIO_GP_2_18, GPIO_GP_2_19,
	GPIO_GP_2_20, GPIO_GP_2_21, GPIO_GP_2_22, GPIO_GP_2_23,
	GPIO_GP_2_24, GPIO_GP_2_25, GPIO_GP_2_26, GPIO_GP_2_27,
	GPIO_GP_2_28, GPIO_GP_2_29, GPIO_GP_2_30, GPIO_GP_2_31,

	GPIO_GP_3_0, GPIO_GP_3_1, GPIO_GP_3_2, GPIO_GP_3_3,
	GPIO_GP_3_4, GPIO_GP_3_5, GPIO_GP_3_6, GPIO_GP_3_7,
	GPIO_GP_3_8, GPIO_GP_3_9, GPIO_GP_3_10, GPIO_GP_3_11,
	GPIO_GP_3_12, GPIO_GP_3_13, GPIO_GP_3_14, GPIO_GP_3_15,
	GPIO_GP_3_16, GPIO_GP_3_17, GPIO_GP_3_18, GPIO_GP_3_19,
	GPIO_GP_3_20, GPIO_GP_3_21, GPIO_GP_3_22, GPIO_GP_3_23,
	GPIO_GP_3_24, GPIO_GP_3_25, GPIO_GP_3_26, GPIO_GP_3_27,
	GPIO_GP_3_28, GPIO_GP_3_29, GPIO_GP_3_30, GPIO_GP_3_31,

	GPIO_GP_4_0, GPIO_GP_4_1, GPIO_GP_4_2, GPIO_GP_4_3,
	GPIO_GP_4_4, GPIO_GP_4_5, GPIO_GP_4_6, GPIO_GP_4_7,
	GPIO_GP_4_8, GPIO_GP_4_9, GPIO_GP_4_10, GPIO_GP_4_11,
	GPIO_GP_4_12, GPIO_GP_4_13, GPIO_GP_4_14, GPIO_GP_4_15,
	GPIO_GP_4_16, GPIO_GP_4_17, GPIO_GP_4_18, GPIO_GP_4_19,
	GPIO_GP_4_20, GPIO_GP_4_21, GPIO_GP_4_22, GPIO_GP_4_23,
	GPIO_GP_4_24, GPIO_GP_4_25, GPIO_GP_4_26, GPIO_GP_4_27,
	GPIO_GP_4_28, GPIO_GP_4_29, GPIO_GP_4_30, GPIO_GP_4_31,

	GPIO_GP_5_0, GPIO_GP_5_1, GPIO_GP_5_2, GPIO_GP_5_3,
	GPIO_GP_5_4, GPIO_GP_5_5, GPIO_GP_5_6, GPIO_GP_5_7,
	GPIO_GP_5_8, GPIO_GP_5_9, GPIO_GP_5_10, GPIO_GP_5_11,
	GPIO_GP_5_12, GPIO_GP_5_13, GPIO_GP_5_14, GPIO_GP_5_15,
	GPIO_GP_5_16, GPIO_GP_5_17, GPIO_GP_5_18, GPIO_GP_5_19,
	GPIO_GP_5_20, GPIO_GP_5_21, GPIO_GP_5_22, GPIO_GP_5_23,
	GPIO_GP_5_24, GPIO_GP_5_25, GPIO_GP_5_26, GPIO_GP_5_27,

	GPIO_GP_6_0, GPIO_GP_6_1, GPIO_GP_6_2, GPIO_GP_6_3,
	GPIO_GP_6_4, GPIO_GP_6_5, GPIO_GP_6_6, GPIO_GP_6_7,
	GPIO_GP_6_8, GPIO_GP_6_9, GPIO_GP_6_10, GPIO_GP_6_11,
	GPIO_GP_6_12, GPIO_GP_6_13, GPIO_GP_6_14, GPIO_GP_6_15,
	GPIO_GP_6_16, GPIO_GP_6_17, GPIO_GP_6_18, GPIO_GP_6_19,
	GPIO_GP_6_20, GPIO_GP_6_21, GPIO_GP_6_22, GPIO_GP_6_23,
	GPIO_GP_6_24, GPIO_GP_6_25,

	GPIO_FN_A2, GPIO_FN_WE0_N, GPIO_FN_WE1_N, GPIO_FN_DACK0,
	GPIO_FN_USB0_PWEN, GPIO_FN_USB0_OVC, GPIO_FN_USB1_PWEN,
	GPIO_FN_USB1_OVC, GPIO_FN_SD0_CLK, GPIO_FN_SD0_CMD,
	GPIO_FN_SD0_DATA0, GPIO_FN_SD0_DATA1, GPIO_FN_SD0_DATA2,
	GPIO_FN_SD0_DATA3, GPIO_FN_SD0_CD, GPIO_FN_SD0_WP,
	GPIO_FN_SD1_CLK, GPIO_FN_SD1_CMD, GPIO_FN_SD1_DATA0,
	GPIO_FN_SD1_DATA1, GPIO_FN_SD1_DATA2, GPIO_FN_SD1_DATA3,

	/*
	 * From IPSR0 to IPSR5 have been removed because they does not use.
	 */

	/* IPSR6 */
	GPIO_FN_DU0_EXVSYNC_DU0_VSYNC, GPIO_FN_QSTB_QHE, GPIO_FN_CC50_STATE28,
	GPIO_FN_DU0_EXODDF_DU0_ODDF_DISP_CDE, GPIO_FN_QCPV_QDE,
	GPIO_FN_CC50_STATE29, GPIO_FN_DU0_DISP, GPIO_FN_QPOLA,
	GPIO_FN_CC50_STATE30, GPIO_FN_DU0_CDE, GPIO_FN_QPOLB,
	GPIO_FN_CC50_STATE31, GPIO_FN_VI0_CLK, GPIO_FN_AVB_RX_CLK,
	GPIO_FN_VI0_DATA0_VI0_B0, GPIO_FN_AVB_RX_DV, GPIO_FN_VI0_DATA1_VI0_B1,
	GPIO_FN_AVB_RXD0, GPIO_FN_VI0_DATA2_VI0_B2, GPIO_FN_AVB_RXD1,
	GPIO_FN_VI0_DATA3_VI0_B3, GPIO_FN_AVB_RXD2, GPIO_FN_VI0_DATA4_VI0_B4,
	GPIO_FN_AVB_RXD3, GPIO_FN_VI0_DATA5_VI0_B5, GPIO_FN_AVB_RXD4,
	GPIO_FN_VI0_DATA6_VI0_B6, GPIO_FN_AVB_RXD5, GPIO_FN_VI0_DATA7_VI0_B7,
	GPIO_FN_AVB_RXD6, GPIO_FN_VI0_CLKENB, GPIO_FN_I2C3_SCL,
	GPIO_FN_SCIFA5_RXD_C, GPIO_FN_IETX_C, GPIO_FN_AVB_RXD7,
	GPIO_FN_VI0_FIELD, GPIO_FN_I2C3_SDA, GPIO_FN_SCIFA5_TXD_C,
	GPIO_FN_IECLK_C, GPIO_FN_AVB_RX_ER, GPIO_FN_VI0_HSYNC_N,
	GPIO_FN_SCIF0_RXD_B, GPIO_FN_I2C0_SCL_C, GPIO_FN_IERX_C,
	GPIO_FN_AVB_COL, GPIO_FN_VI0_VSYNC_N, GPIO_FN_SCIF0_TXD_B,
	GPIO_FN_I2C0_SDA_C, GPIO_FN_AUDIO_CLKOUT_B, GPIO_FN_AVB_TX_EN,
	GPIO_FN_ETH_MDIO, GPIO_FN_VI0_G0, GPIO_FN_MSIOF2_RXD_B,
	GPIO_FN_IIC0_SCL_D, GPIO_FN_AVB_TX_CLK, GPIO_FN_ADIDATA, GPIO_FN_AD_DI,

	/* IPSR7 */
	GPIO_FN_ETH_CRS_DV, GPIO_FN_VI0_G1, GPIO_FN_MSIOF2_TXD_B,
	GPIO_FN_IIC0_SDA_D, GPIO_FN_AVB_TXD0, GPIO_FN_ADICS_SAMP, GPIO_FN_AD_DO,
	GPIO_FN_ETH_RX_ER, GPIO_FN_VI0_G2, GPIO_FN_MSIOF2_SCK_B,
	GPIO_FN_CAN0_RX_B, GPIO_FN_AVB_TXD1, GPIO_FN_ADICLK, GPIO_FN_AD_CLK,
	GPIO_FN_ETH_RXD0, GPIO_FN_VI0_G3, GPIO_FN_MSIOF2_SYNC_B,
	GPIO_FN_CAN0_TX_B, GPIO_FN_AVB_TXD2, GPIO_FN_ADICHS0, GPIO_FN_AD_NCS_N,
	GPIO_FN_ETH_RXD1, GPIO_FN_VI0_G4, GPIO_FN_MSIOF2_SS1_B,
	GPIO_FN_SCIF4_RXD_D, GPIO_FN_AVB_TXD3, GPIO_FN_ADICHS1,
	GPIO_FN_ETH_LINK, GPIO_FN_VI0_G5, GPIO_FN_MSIOF2_SS2_B,
	GPIO_FN_SCIF4_TXD_D, GPIO_FN_AVB_TXD4, GPIO_FN_ADICHS2,
	GPIO_FN_ETH_REFCLK, GPIO_FN_VI0_G6, GPIO_FN_SCIF2_SCK_C,
	GPIO_FN_AVB_TXD5, GPIO_FN_SSI_SCK5_B, GPIO_FN_ETH_TXD1, GPIO_FN_VI0_G7,
	GPIO_FN_SCIF2_RXD_C, GPIO_FN_IIC1_SCL_D, GPIO_FN_AVB_TXD6,
	GPIO_FN_SSI_WS5_B, GPIO_FN_ETH_TX_EN, GPIO_FN_VI0_R0,
	GPIO_FN_SCIF2_TXD_C, GPIO_FN_IIC1_SDA_D, GPIO_FN_AVB_TXD7,
	GPIO_FN_SSI_SDATA5_B, GPIO_FN_ETH_MAGIC, GPIO_FN_VI0_R1,
	GPIO_FN_SCIF3_SCK_B, GPIO_FN_AVB_TX_ER, GPIO_FN_SSI_SCK6_B,
	GPIO_FN_ETH_TXD0, GPIO_FN_VI0_R2, GPIO_FN_SCIF3_RXD_B,
	GPIO_FN_I2C4_SCL_E, GPIO_FN_AVB_GTX_CLK, GPIO_FN_SSI_WS6_B,
	GPIO_FN_DREQ0_N, GPIO_FN_SCIFB1_RXD,

	/* IPSR8 */
	GPIO_FN_ETH_MDC, GPIO_FN_VI0_R3, GPIO_FN_SCIF3_TXD_B,
	GPIO_FN_I2C4_SDA_E, GPIO_FN_AVB_MDC, GPIO_FN_SSI_SDATA6_B,
	GPIO_FN_HSCIF0_HRX, GPIO_FN_VI0_R4, GPIO_FN_I2C1_SCL_C,
	GPIO_FN_AUDIO_CLKA_B, GPIO_FN_AVB_MDIO, GPIO_FN_SSI_SCK78_B,
	GPIO_FN_HSCIF0_HTX, GPIO_FN_VI0_R5, GPIO_FN_I2C1_SDA_C,
	GPIO_FN_AUDIO_CLKB_B, GPIO_FN_AVB_LINK, GPIO_FN_SSI_WS78_B,
	GPIO_FN_HSCIF0_HCTS_N, GPIO_FN_VI0_R6, GPIO_FN_SCIF0_RXD_D,
	GPIO_FN_I2C0_SCL_E, GPIO_FN_AVB_MAGIC, GPIO_FN_SSI_SDATA7_B,
	GPIO_FN_HSCIF0_HRTS_N, GPIO_FN_VI0_R7, GPIO_FN_SCIF0_TXD_D,
	GPIO_FN_I2C0_SDA_E, GPIO_FN_AVB_PHY_INT, GPIO_FN_SSI_SDATA8_B,
	GPIO_FN_HSCIF0_HSCK, GPIO_FN_SCIF_CLK_B, GPIO_FN_AVB_CRS,
	GPIO_FN_AUDIO_CLKC_B, GPIO_FN_I2C0_SCL, GPIO_FN_SCIF0_RXD_C,
	GPIO_FN_PWM5, GPIO_FN_TCLK1_B, GPIO_FN_AVB_GTXREFCLK, GPIO_FN_CAN1_RX_D,
	GPIO_FN_TPUTO0_B, GPIO_FN_I2C0_SDA, GPIO_FN_SCIF0_TXD_C, GPIO_FN_TPUTO0,
	GPIO_FN_CAN_CLK, GPIO_FN_DVC_MUTE, GPIO_FN_CAN1_TX_D, GPIO_FN_I2C1_SCL,
	GPIO_FN_SCIF4_RXD, GPIO_FN_PWM5_B, GPIO_FN_DU1_DR0, GPIO_FN_RIF1_SYNC_B,
	GPIO_FN_TS_SDATA_D, GPIO_FN_TPUTO1_B, GPIO_FN_I2C1_SDA,
	GPIO_FN_SCIF4_TXD, GPIO_FN_IRQ5, GPIO_FN_DU1_DR1, GPIO_FN_RIF1_CLK_B,
	GPIO_FN_TS_SCK_D, GPIO_FN_BPFCLK_C, GPIO_FN_MSIOF0_RXD,
	GPIO_FN_SCIF5_RXD, GPIO_FN_I2C2_SCL_C, GPIO_FN_DU1_DR2,
	GPIO_FN_RIF1_D0_B, GPIO_FN_TS_SDEN_D, GPIO_FN_FMCLK_C, GPIO_FN_RDS_CLK,

	/*
	 * From IPSR9 to IPSR10 have been removed because they does not use.
	 */

	/* IPSR11 */
	GPIO_FN_SSI_WS5, GPIO_FN_SCIFA3_RXD, GPIO_FN_I2C3_SCL_C,
	GPIO_FN_DU1_DOTCLKOUT0, GPIO_FN_CAN_DEBUGOUT11, GPIO_FN_SSI_SDATA5,
	GPIO_FN_SCIFA3_TXD, GPIO_FN_I2C3_SDA_C, GPIO_FN_DU1_DOTCLKOUT1,
	GPIO_FN_CAN_DEBUGOUT12, GPIO_FN_SSI_SCK6, GPIO_FN_SCIFA1_SCK_B,
	GPIO_FN_DU1_EXHSYNC_DU1_HSYNC, GPIO_FN_CAN_DEBUGOUT13, GPIO_FN_SSI_WS6,
	GPIO_FN_SCIFA1_RXD_B, GPIO_FN_I2C4_SCL_C, GPIO_FN_DU1_EXVSYNC_DU1_VSYNC,
	GPIO_FN_CAN_DEBUGOUT14, GPIO_FN_SSI_SDATA6, GPIO_FN_SCIFA1_TXD_B,
	GPIO_FN_I2C4_SDA_C, GPIO_FN_DU1_EXODDF_DU1_ODDF_DISP_CDE,
	GPIO_FN_CAN_DEBUGOUT15, GPIO_FN_SSI_SCK78, GPIO_FN_SCIFA2_SCK_B,
	GPIO_FN_IIC0_SDA_C, GPIO_FN_DU1_DISP, GPIO_FN_SSI_WS78,
	GPIO_FN_SCIFA2_RXD_B, GPIO_FN_IIC0_SCL_C, GPIO_FN_DU1_CDE,
	GPIO_FN_SSI_SDATA7, GPIO_FN_SCIFA2_TXD_B, GPIO_FN_IRQ8,
	GPIO_FN_AUDIO_CLKA_D, GPIO_FN_CAN_CLK_D, GPIO_FN_PCMOE_N,
	GPIO_FN_SSI_SCK0129, GPIO_FN_MSIOF1_RXD_B, GPIO_FN_SCIF5_RXD_D,
	GPIO_FN_ADIDATA_B, GPIO_FN_AD_DI_B, GPIO_FN_PCMWE_N, GPIO_FN_SSI_WS0129,
	GPIO_FN_MSIOF1_TXD_B, GPIO_FN_SCIF5_TXD_D, GPIO_FN_ADICS_SAMP_B,
	GPIO_FN_AD_DO_B, GPIO_FN_SSI_SDATA0, GPIO_FN_MSIOF1_SCK_B,
	GPIO_FN_PWM0_B, GPIO_FN_ADICLK_B, GPIO_FN_AD_CLK_B,

	/*
	 * From IPSR12 to IPSR13 have been removed because they does not use.
	 */
};

#endif /* __ASM_R8A7794_H__ */
