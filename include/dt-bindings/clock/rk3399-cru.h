/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2016 Rockchip Electronics Co. Ltd.
 */

#ifndef _DT_BINDINGS_CLK_ROCKCHIP_RK3399_H
#define _DT_BINDINGS_CLK_ROCKCHIP_RK3399_H

/* core clocks */
#define PLL_APLLL			1
#define PLL_APLLB			2
#define PLL_DPLL			3
#define PLL_CPLL			4
#define PLL_GPLL			5
#define PLL_NPLL			6
#define PLL_VPLL			7
#define ARMCLKL				8
#define ARMCLKB				9

/* sclk gates (special clocks) */
#define SCLK_I2C1			65
#define SCLK_I2C2			66
#define SCLK_I2C3			67
#define SCLK_I2C5			68
#define SCLK_I2C6			69
#define SCLK_I2C7			70
#define SCLK_SPI0			71
#define SCLK_SPI1			72
#define SCLK_SPI2			73
#define SCLK_SPI4			74
#define SCLK_SPI5			75
#define SCLK_SDMMC			76
#define SCLK_SDIO			77
#define SCLK_EMMC			78
#define SCLK_TSADC			79
#define SCLK_SARADC			80
#define SCLK_UART0			81
#define SCLK_UART1			82
#define SCLK_UART2			83
#define SCLK_UART3			84
#define SCLK_SPDIF_8CH			85
#define SCLK_I2S0_8CH			86
#define SCLK_I2S1_8CH			87
#define SCLK_I2S2_8CH			88
#define SCLK_I2S_8CH_OUT		89
#define SCLK_TIMER00			90
#define SCLK_TIMER01			91
#define SCLK_TIMER02			92
#define SCLK_TIMER03			93
#define SCLK_TIMER04			94
#define SCLK_TIMER05			95
#define SCLK_TIMER06			96
#define SCLK_TIMER07			97
#define SCLK_TIMER08			98
#define SCLK_TIMER09			99
#define SCLK_TIMER10			100
#define SCLK_TIMER11			101
#define SCLK_MACREF			102
#define SCLK_MAC_RX			103
#define SCLK_MAC_TX			104
#define SCLK_MAC			105
#define SCLK_MACREF_OUT			106
#define SCLK_VOP0_PWM			107
#define SCLK_VOP1_PWM			108
#define SCLK_RGA_CORE			109
#define SCLK_ISP0			110
#define SCLK_ISP1			111
#define SCLK_HDMI_CEC			112
#define SCLK_HDMI_SFR			113
#define SCLK_DP_CORE			114
#define SCLK_PVTM_CORE_L		115
#define SCLK_PVTM_CORE_B		116
#define SCLK_PVTM_GPU			117
#define SCLK_PVTM_DDR			118
#define SCLK_MIPIDPHY_REF		119
#define SCLK_MIPIDPHY_CFG		120
#define SCLK_HSICPHY			121
#define SCLK_USBPHY480M			122
#define SCLK_USB2PHY0_REF		123
#define SCLK_USB2PHY1_REF		124
#define SCLK_UPHY0_TCPDPHY_REF		125
#define SCLK_UPHY0_TCPDCORE		126
#define SCLK_UPHY1_TCPDPHY_REF		127
#define SCLK_UPHY1_TCPDCORE		128
#define SCLK_USB3OTG0_REF		129
#define SCLK_USB3OTG1_REF		130
#define SCLK_USB3OTG0_SUSPEND		131
#define SCLK_USB3OTG1_SUSPEND		132
#define SCLK_CRYPTO0			133
#define SCLK_CRYPTO1			134
#define SCLK_CCI_TRACE			135
#define SCLK_CS				136
#define SCLK_CIF_OUT			137
#define SCLK_PCIEPHY_REF		138
#define SCLK_PCIE_CORE			139
#define SCLK_M0_PERILP			140
#define SCLK_M0_PERILP_DEC		141
#define SCLK_CM0S			142
#define SCLK_DBG_NOC			143
#define SCLK_DBG_PD_CORE_B		144
#define SCLK_DBG_PD_CORE_L		145
#define SCLK_DFIMON0_TIMER		146
#define SCLK_DFIMON1_TIMER		147
#define SCLK_INTMEM0			148
#define SCLK_INTMEM1			149
#define SCLK_INTMEM2			150
#define SCLK_INTMEM3			151
#define SCLK_INTMEM4			152
#define SCLK_INTMEM5			153
#define SCLK_SDMMC_DRV			154
#define SCLK_SDMMC_SAMPLE		155
#define SCLK_SDIO_DRV			156
#define SCLK_SDIO_SAMPLE		157
#define SCLK_VDU_CORE			158
#define SCLK_VDU_CA			159
#define SCLK_PCIE_PM			160
#define SCLK_SPDIF_REC_DPTX		161
#define SCLK_DPHY_PLL			162
#define SCLK_DPHY_TX0_CFG		163
#define SCLK_DPHY_TX1RX1_CFG		164
#define SCLK_DPHY_RX0_CFG		165
#define SCLK_RMII_SRC			166
#define SCLK_PCIEPHY_REF100M		167
#define SCLK_USBPHY0_480M_SRC		168
#define SCLK_USBPHY1_480M_SRC		169
#define SCLK_DDRCLK			170
#define SCLK_TESTOUT2			171

#define DCLK_VOP0			180
#define DCLK_VOP1			181
#define DCLK_VOP0_DIV			182
#define DCLK_VOP1_DIV			183
#define DCLK_M0_PERILP			184

#define FCLK_CM0S			190

/* aclk gates */
#define ACLK_PERIHP			192
#define ACLK_PERIHP_NOC			193
#define ACLK_PERILP0			194
#define ACLK_PERILP0_NOC		195
#define ACLK_PERF_PCIE			196
#define ACLK_PCIE			197
#define ACLK_INTMEM			198
#define ACLK_TZMA			199
#define ACLK_DCF			200
#define ACLK_CCI			201
#define ACLK_CCI_NOC0			202
#define ACLK_CCI_NOC1			203
#define ACLK_CCI_GRF			204
#define ACLK_CENTER			205
#define ACLK_CENTER_MAIN_NOC		206
#define ACLK_CENTER_PERI_NOC		207
#define ACLK_GPU			208
#define ACLK_PERF_GPU			209
#define ACLK_GPU_GRF			210
#define ACLK_DMAC0_PERILP		211
#define ACLK_DMAC1_PERILP		212
#define ACLK_GMAC			213
#define ACLK_GMAC_NOC			214
#define ACLK_PERF_GMAC			215
#define ACLK_VOP0_NOC			216
#define ACLK_VOP0			217
#define ACLK_VOP1_NOC			218
#define ACLK_VOP1			219
#define ACLK_RGA			220
#define ACLK_RGA_NOC			221
#define ACLK_HDCP			222
#define ACLK_HDCP_NOC			223
#define ACLK_HDCP22			224
#define ACLK_IEP			225
#define ACLK_IEP_NOC			226
#define ACLK_VIO			227
#define ACLK_VIO_NOC			228
#define ACLK_ISP0			229
#define ACLK_ISP1			230
#define ACLK_ISP0_NOC			231
#define ACLK_ISP1_NOC			232
#define ACLK_ISP0_WRAPPER		233
#define ACLK_ISP1_WRAPPER		234
#define ACLK_VCODEC			235
#define ACLK_VCODEC_NOC			236
#define ACLK_VDU			237
#define ACLK_VDU_NOC			238
#define ACLK_PERI			239
#define ACLK_EMMC			240
#define ACLK_EMMC_CORE			241
#define ACLK_EMMC_NOC			242
#define ACLK_EMMC_GRF			243
#define ACLK_USB3			244
#define ACLK_USB3_NOC			245
#define ACLK_USB3OTG0			246
#define ACLK_USB3OTG1			247
#define ACLK_USB3_RKSOC_AXI_PERF	248
#define ACLK_USB3_GRF			249
#define ACLK_GIC			250
#define ACLK_GIC_NOC			251
#define ACLK_GIC_ADB400_CORE_L_2_GIC	252
#define ACLK_GIC_ADB400_CORE_B_2_GIC	253
#define ACLK_GIC_ADB400_GIC_2_CORE_L	254
#define ACLK_GIC_ADB400_GIC_2_CORE_B	255
#define ACLK_CORE_ADB400_CORE_L_2_CCI500 256
#define ACLK_CORE_ADB400_CORE_B_2_CCI500 257
#define ACLK_ADB400M_PD_CORE_L		258
#define ACLK_ADB400M_PD_CORE_B		259
#define ACLK_PERF_CORE_L		260
#define ACLK_PERF_CORE_B		261
#define ACLK_GIC_PRE			262
#define ACLK_VOP0_PRE			263
#define ACLK_VOP1_PRE			264

/* pclk gates */
#define PCLK_PERIHP			320
#define PCLK_PERIHP_NOC			321
#define PCLK_PERILP0			322
#define PCLK_PERILP1			323
#define PCLK_PERILP1_NOC		324
#define PCLK_PERILP_SGRF		325
#define PCLK_PERIHP_GRF			326
#define PCLK_PCIE			327
#define PCLK_SGRF			328
#define PCLK_INTR_ARB			329
#define PCLK_CENTER_MAIN_NOC		330
#define PCLK_CIC			331
#define PCLK_COREDBG_B			332
#define PCLK_COREDBG_L			333
#define PCLK_DBG_CXCS_PD_CORE_B		334
#define PCLK_DCF			335
#define PCLK_GPIO2			336
#define PCLK_GPIO3			337
#define PCLK_GPIO4			338
#define PCLK_GRF			339
#define PCLK_HSICPHY			340
#define PCLK_I2C1			341
#define PCLK_I2C2			342
#define PCLK_I2C3			343
#define PCLK_I2C5			344
#define PCLK_I2C6			345
#define PCLK_I2C7			346
#define PCLK_SPI0			347
#define PCLK_SPI1			348
#define PCLK_SPI2			349
#define PCLK_SPI4			350
#define PCLK_SPI5			351
#define PCLK_UART0			352
#define PCLK_UART1			353
#define PCLK_UART2			354
#define PCLK_UART3			355
#define PCLK_TSADC			356
#define PCLK_SARADC			357
#define PCLK_GMAC			358
#define PCLK_GMAC_NOC			359
#define PCLK_TIMER0			360
#define PCLK_TIMER1			361
#define PCLK_EDP			362
#define PCLK_EDP_NOC			363
#define PCLK_EDP_CTRL			364
#define PCLK_VIO			365
#define PCLK_VIO_NOC			366
#define PCLK_VIO_GRF			367
#define PCLK_MIPI_DSI0			368
#define PCLK_MIPI_DSI1			369
#define PCLK_HDCP			370
#define PCLK_HDCP_NOC			371
#define PCLK_HDMI_CTRL			372
#define PCLK_DP_CTRL			373
#define PCLK_HDCP22			374
#define PCLK_GASKET			375
#define PCLK_DDR			376
#define PCLK_DDR_MON			377
#define PCLK_DDR_SGRF			378
#define PCLK_ISP1_WRAPPER		379
#define PCLK_WDT			380
#define PCLK_EFUSE1024NS		381
#define PCLK_EFUSE1024S			382
#define PCLK_PMU_INTR_ARB		383
#define PCLK_MAILBOX0			384
#define PCLK_USBPHY_MUX_G		385
#define PCLK_UPHY0_TCPHY_G		386
#define PCLK_UPHY0_TCPD_G		387
#define PCLK_UPHY1_TCPHY_G		388
#define PCLK_UPHY1_TCPD_G		389
#define PCLK_ALIVE			390

/* hclk gates */
#define HCLK_PERIHP			448
#define HCLK_PERILP0			449
#define HCLK_PERILP1			450
#define HCLK_PERILP0_NOC		451
#define HCLK_PERILP1_NOC		452
#define HCLK_M0_PERILP			453
#define HCLK_M0_PERILP_NOC		454
#define HCLK_AHB1TOM			455
#define HCLK_HOST0			456
#define HCLK_HOST0_ARB			457
#define HCLK_HOST1			458
#define HCLK_HOST1_ARB			459
#define HCLK_HSIC			460
#define HCLK_SD				461
#define HCLK_SDMMC			462
#define HCLK_SDMMC_NOC			463
#define HCLK_M_CRYPTO0			464
#define HCLK_M_CRYPTO1			465
#define HCLK_S_CRYPTO0			466
#define HCLK_S_CRYPTO1			467
#define HCLK_I2S0_8CH			468
#define HCLK_I2S1_8CH			469
#define HCLK_I2S2_8CH			470
#define HCLK_SPDIF			471
#define HCLK_VOP0_NOC			472
#define HCLK_VOP0			473
#define HCLK_VOP1_NOC			474
#define HCLK_VOP1			475
#define HCLK_ROM			476
#define HCLK_IEP			477
#define HCLK_IEP_NOC			478
#define HCLK_ISP0			479
#define HCLK_ISP1			480
#define HCLK_ISP0_NOC			481
#define HCLK_ISP1_NOC			482
#define HCLK_ISP0_WRAPPER		483
#define HCLK_ISP1_WRAPPER		484
#define HCLK_RGA			485
#define HCLK_RGA_NOC			486
#define HCLK_HDCP			487
#define HCLK_HDCP_NOC			488
#define HCLK_HDCP22			489
#define HCLK_VCODEC			490
#define HCLK_VCODEC_NOC			491
#define HCLK_VDU			492
#define HCLK_VDU_NOC			493
#define HCLK_SDIO			494
#define HCLK_SDIO_NOC			495
#define HCLK_SDIOAUDIO_NOC		496

#define CLK_NR_CLKS			(HCLK_SDIOAUDIO_NOC + 1)

/* pmu-clocks indices */

#define PLL_PPLL			1

#define SCLK_32K_SUSPEND_PMU		2
#define SCLK_SPI3_PMU			3
#define SCLK_TIMER12_PMU		4
#define SCLK_TIMER13_PMU		5
#define SCLK_UART4_PMU			6
#define SCLK_PVTM_PMU			7
#define SCLK_WIFI_PMU			8
#define SCLK_I2C0_PMU			9
#define SCLK_I2C4_PMU			10
#define SCLK_I2C8_PMU			11

#define PCLK_SRC_PMU			19
#define PCLK_PMU			20
#define PCLK_PMUGRF_PMU			21
#define PCLK_INTMEM1_PMU		22
#define PCLK_GPIO0_PMU			23
#define PCLK_GPIO1_PMU			24
#define PCLK_SGRF_PMU			25
#define PCLK_NOC_PMU			26
#define PCLK_I2C0_PMU			27
#define PCLK_I2C4_PMU			28
#define PCLK_I2C8_PMU			29
#define PCLK_RKPWM_PMU			30
#define PCLK_SPI3_PMU			31
#define PCLK_TIMER_PMU			32
#define PCLK_MAILBOX_PMU		33
#define PCLK_UART4_PMU			34
#define PCLK_WDT_M0_PMU			35

#define FCLK_CM0S_SRC_PMU		44
#define FCLK_CM0S_PMU			45
#define SCLK_CM0S_PMU			46
#define HCLK_CM0S_PMU			47
#define DCLK_CM0S_PMU			48
#define PCLK_INTR_ARB_PMU		49
#define HCLK_NOC_PMU			50

#define CLKPMU_NR_CLKS			(HCLK_NOC_PMU + 1)

/* soft-reset indices */

/* cru_softrst_con0 */
#define SRST_CORE_L0			0
#define SRST_CORE_B0			1
#define SRST_CORE_PO_L0			2
#define SRST_CORE_PO_B0			3
#define SRST_L2_L			4
#define SRST_L2_B			5
#define SRST_ADB_L			6
#define SRST_ADB_B			7
#define SRST_A_CCI			8
#define SRST_A_CCIM0_NOC		9
#define SRST_A_CCIM1_NOC		10
#define SRST_DBG_NOC			11

/* cru_softrst_con1 */
#define SRST_CORE_L0_T			16
#define SRST_CORE_L1			17
#define SRST_CORE_L2			18
#define SRST_CORE_L3			19
#define SRST_CORE_PO_L0_T		20
#define SRST_CORE_PO_L1			21
#define SRST_CORE_PO_L2			22
#define SRST_CORE_PO_L3			23
#define SRST_A_ADB400_GIC2COREL		24
#define SRST_A_ADB400_COREL2GIC		25
#define SRST_P_DBG_L			26
#define SRST_L2_L_T			28
#define SRST_ADB_L_T			29
#define SRST_A_RKPERF_L			30
#define SRST_PVTM_CORE_L		31

/* cru_softrst_con2 */
#define SRST_CORE_B0_T			32
#define SRST_CORE_B1			33
#define SRST_CORE_PO_B0_T		36
#define SRST_CORE_PO_B1			37
#define SRST_A_ADB400_GIC2COREB		40
#define SRST_A_ADB400_COREB2GIC		41
#define SRST_P_DBG_B			42
#define SRST_L2_B_T			43
#define SRST_ADB_B_T			45
#define SRST_A_RKPERF_B			46
#define SRST_PVTM_CORE_B		47

/* cru_softrst_con3 */
#define SRST_A_CCI_T			50
#define SRST_A_CCIM0_NOC_T		51
#define SRST_A_CCIM1_NOC_T		52
#define SRST_A_ADB400M_PD_CORE_B_T	53
#define SRST_A_ADB400M_PD_CORE_L_T	54
#define SRST_DBG_NOC_T			55
#define SRST_DBG_CXCS			56
#define SRST_CCI_TRACE			57
#define SRST_P_CCI_GRF			58

/* cru_softrst_con4 */
#define SRST_A_CENTER_MAIN_NOC		64
#define SRST_A_CENTER_PERI_NOC		65
#define SRST_P_CENTER_MAIN		66
#define SRST_P_DDRMON			67
#define SRST_P_CIC			68
#define SRST_P_CENTER_SGRF		69
#define SRST_DDR0_MSCH			70
#define SRST_DDRCFG0_MSCH		71
#define SRST_DDR0			72
#define SRST_DDRPHY0			73
#define SRST_DDR1_MSCH			74
#define SRST_DDRCFG1_MSCH		75
#define SRST_DDR1			76
#define SRST_DDRPHY1			77
#define SRST_DDR_CIC			78
#define SRST_PVTM_DDR			79

/* cru_softrst_con5 */
#define SRST_A_VCODEC_NOC		80
#define SRST_A_VCODEC			81
#define SRST_H_VCODEC_NOC		82
#define SRST_H_VCODEC			83
#define SRST_A_VDU_NOC			88
#define SRST_A_VDU			89
#define SRST_H_VDU_NOC			90
#define SRST_H_VDU			91
#define SRST_VDU_CORE			92
#define SRST_VDU_CA			93

/* cru_softrst_con6 */
#define SRST_A_IEP_NOC			96
#define SRST_A_VOP_IEP			97
#define SRST_A_IEP			98
#define SRST_H_IEP_NOC			99
#define SRST_H_IEP			100
#define SRST_A_RGA_NOC			102
#define SRST_A_RGA			103
#define SRST_H_RGA_NOC			104
#define SRST_H_RGA			105
#define SRST_RGA_CORE			106
#define SRST_EMMC_NOC			108
#define SRST_EMMC			109
#define SRST_EMMC_GRF			110

/* cru_softrst_con7 */
#define SRST_A_PERIHP_NOC		112
#define SRST_P_PERIHP_GRF		113
#define SRST_H_PERIHP_NOC		114
#define SRST_USBHOST0			115
#define SRST_HOSTC0_AUX			116
#define SRST_HOST0_ARB			117
#define SRST_USBHOST1			118
#define SRST_HOSTC1_AUX			119
#define SRST_HOST1_ARB			120
#define SRST_SDIO0			121
#define SRST_SDMMC			122
#define SRST_HSIC			123
#define SRST_HSIC_AUX			124
#define SRST_AHB1TOM			125
#define SRST_P_PERIHP_NOC		126
#define SRST_HSICPHY			127

/* cru_softrst_con8 */
#define SRST_A_PCIE			128
#define SRST_P_PCIE			129
#define SRST_PCIE_CORE			130
#define SRST_PCIE_MGMT			131
#define SRST_PCIE_MGMT_STICKY		132
#define SRST_PCIE_PIPE			133
#define SRST_PCIE_PM			134
#define SRST_PCIEPHY			135
#define SRST_A_GMAC_NOC			136
#define SRST_A_GMAC			137
#define SRST_P_GMAC_NOC			138
#define SRST_P_GMAC_GRF			140
#define SRST_HSICPHY_POR		142
#define SRST_HSICPHY_UTMI		143

/* cru_softrst_con9 */
#define SRST_USB2PHY0_POR		144
#define SRST_USB2PHY0_UTMI_PORT0	145
#define SRST_USB2PHY0_UTMI_PORT1	146
#define SRST_USB2PHY0_EHCIPHY		147
#define SRST_UPHY0_PIPE_L00		148
#define SRST_UPHY0			149
#define SRST_UPHY0_TCPDPWRUP		150
#define SRST_USB2PHY1_POR		152
#define SRST_USB2PHY1_UTMI_PORT0	153
#define SRST_USB2PHY1_UTMI_PORT1	154
#define SRST_USB2PHY1_EHCIPHY		155
#define SRST_UPHY1_PIPE_L00		156
#define SRST_UPHY1			157
#define SRST_UPHY1_TCPDPWRUP		158

/* cru_softrst_con10 */
#define SRST_A_PERILP0_NOC		160
#define SRST_A_DCF			161
#define SRST_GIC500			162
#define SRST_DMAC0_PERILP0		163
#define SRST_DMAC1_PERILP0		164
#define SRST_TZMA			165
#define SRST_INTMEM			166
#define SRST_ADB400_MST0		167
#define SRST_ADB400_MST1		168
#define SRST_ADB400_SLV0		169
#define SRST_ADB400_SLV1		170
#define SRST_H_PERILP0			171
#define SRST_H_PERILP0_NOC		172
#define SRST_ROM			173
#define SRST_CRYPTO_S			174
#define SRST_CRYPTO_M			175

/* cru_softrst_con11 */
#define SRST_P_DCF			176
#define SRST_CM0S_NOC			177
#define SRST_CM0S			178
#define SRST_CM0S_DBG			179
#define SRST_CM0S_PO			180
#define SRST_CRYPTO			181
#define SRST_P_PERILP1_SGRF		182
#define SRST_P_PERILP1_GRF		183
#define SRST_CRYPTO1_S			184
#define SRST_CRYPTO1_M			185
#define SRST_CRYPTO1			186
#define SRST_GIC_NOC			188
#define SRST_SD_NOC			189
#define SRST_SDIOAUDIO_BRG		190

/* cru_softrst_con12 */
#define SRST_H_PERILP1			192
#define SRST_H_PERILP1_NOC		193
#define SRST_H_I2S0_8CH			194
#define SRST_H_I2S1_8CH			195
#define SRST_H_I2S2_8CH			196
#define SRST_H_SPDIF_8CH		197
#define SRST_P_PERILP1_NOC		198
#define SRST_P_EFUSE_1024		199
#define SRST_P_EFUSE_1024S		200
#define SRST_P_I2C0			201
#define SRST_P_I2C1			202
#define SRST_P_I2C2			203
#define SRST_P_I2C3			204
#define SRST_P_I2C4			205
#define SRST_P_I2C5			206
#define SRST_P_MAILBOX0			207

/* cru_softrst_con13 */
#define SRST_P_UART0			208
#define SRST_P_UART1			209
#define SRST_P_UART2			210
#define SRST_P_UART3			211
#define SRST_P_SARADC			212
#define SRST_P_TSADC			213
#define SRST_P_SPI0			214
#define SRST_P_SPI1			215
#define SRST_P_SPI2			216
#define SRST_P_SPI4			217
#define SRST_P_SPI5			218
#define SRST_SPI0			219
#define SRST_SPI1			220
#define SRST_SPI2			221
#define SRST_SPI4			222
#define SRST_SPI5			223

/* cru_softrst_con14 */
#define SRST_I2S0_8CH			224
#define SRST_I2S1_8CH			225
#define SRST_I2S2_8CH			226
#define SRST_SPDIF_8CH			227
#define SRST_UART0			228
#define SRST_UART1			229
#define SRST_UART2			230
#define SRST_UART3			231
#define SRST_TSADC			232
#define SRST_I2C0			233
#define SRST_I2C1			234
#define SRST_I2C2			235
#define SRST_I2C3			236
#define SRST_I2C4			237
#define SRST_I2C5			238
#define SRST_SDIOAUDIO_NOC		239

/* cru_softrst_con15 */
#define SRST_A_VIO_NOC			240
#define SRST_A_HDCP_NOC			241
#define SRST_A_HDCP			242
#define SRST_H_HDCP_NOC			243
#define SRST_H_HDCP			244
#define SRST_P_HDCP_NOC			245
#define SRST_P_HDCP			246
#define SRST_P_HDMI_CTRL		247
#define SRST_P_DP_CTRL			248
#define SRST_S_DP_CTRL			249
#define SRST_C_DP_CTRL			250
#define SRST_P_MIPI_DSI0		251
#define SRST_P_MIPI_DSI1		252
#define SRST_DP_CORE			253
#define SRST_DP_I2S			254

/* cru_softrst_con16 */
#define SRST_GASKET			256
#define SRST_VIO_GRF			258
#define SRST_DPTX_SPDIF_REC		259
#define SRST_HDMI_CTRL			260
#define SRST_HDCP_CTRL			261
#define SRST_A_ISP0_NOC			262
#define SRST_A_ISP1_NOC			263
#define SRST_H_ISP0_NOC			266
#define SRST_H_ISP1_NOC			267
#define SRST_H_ISP0			268
#define SRST_H_ISP1			269
#define SRST_ISP0			270
#define SRST_ISP1			271

/* cru_softrst_con17 */
#define SRST_A_VOP0_NOC			272
#define SRST_A_VOP1_NOC			273
#define SRST_A_VOP0			274
#define SRST_A_VOP1			275
#define SRST_H_VOP0_NOC			276
#define SRST_H_VOP1_NOC			277
#define SRST_H_VOP0			278
#define SRST_H_VOP1			279
#define SRST_D_VOP0			280
#define SRST_D_VOP1			281
#define SRST_VOP0_PWM			282
#define SRST_VOP1_PWM			283
#define SRST_P_EDP_NOC			284
#define SRST_P_EDP_CTRL			285

/* cru_softrst_con18 */
#define SRST_A_GPU			288
#define SRST_A_GPU_NOC			289
#define SRST_A_GPU_GRF			290
#define SRST_PVTM_GPU			291
#define SRST_A_USB3_NOC			292
#define SRST_A_USB3_OTG0		293
#define SRST_A_USB3_OTG1		294
#define SRST_A_USB3_GRF			295
#define SRST_PMU			296

/* cru_softrst_con19 */
#define SRST_P_TIMER0_5			304
#define SRST_TIMER0			305
#define SRST_TIMER1			306
#define SRST_TIMER2			307
#define SRST_TIMER3			308
#define SRST_TIMER4			309
#define SRST_TIMER5			310
#define SRST_P_TIMER6_11		311
#define SRST_TIMER6			312
#define SRST_TIMER7			313
#define SRST_TIMER8			314
#define SRST_TIMER9			315
#define SRST_TIMER10			316
#define SRST_TIMER11			317
#define SRST_P_INTR_ARB_PMU		318
#define SRST_P_ALIVE_SGRF		319

/* cru_softrst_con20 */
#define SRST_P_GPIO2			320
#define SRST_P_GPIO3			321
#define SRST_P_GPIO4			322
#define SRST_P_GRF			323
#define SRST_P_ALIVE_NOC		324
#define SRST_P_WDT0			325
#define SRST_P_WDT1			326
#define SRST_P_INTR_ARB			327
#define SRST_P_UPHY0_DPTX		328
#define SRST_P_UPHY0_APB		330
#define SRST_P_UPHY0_TCPHY		332
#define SRST_P_UPHY1_TCPHY		333
#define SRST_P_UPHY0_TCPDCTRL		334
#define SRST_P_UPHY1_TCPDCTRL		335

/* pmu soft-reset indices */

/* pmu_cru_softrst_con0 */
#define SRST_P_NOC			0
#define SRST_P_INTMEM			1
#define SRST_H_CM0S			2
#define SRST_H_CM0S_NOC			3
#define SRST_DBG_CM0S			4
#define SRST_PO_CM0S			5
#define SRST_P_SPI3			6
#define SRST_SPI3			7
#define SRST_P_TIMER_0_1		8
#define SRST_P_TIMER_0			9
#define SRST_P_TIMER_1			10
#define SRST_P_UART4			11
#define SRST_UART4			12
#define SRST_P_WDT			13

/* pmu_cru_softrst_con1 */
#define SRST_P_I2C6			16
#define SRST_P_I2C7			17
#define SRST_P_I2C8			18
#define SRST_P_MAILBOX			19
#define SRST_P_RKPWM			20
#define SRST_P_PMUGRF			21
#define SRST_P_SGRF			22
#define SRST_P_GPIO0			23
#define SRST_P_GPIO1			24
#define SRST_P_CRU			25
#define SRST_P_INTR			26
#define SRST_PVTM			27
#define SRST_I2C6			28
#define SRST_I2C7			29
#define SRST_I2C8			30

#endif
