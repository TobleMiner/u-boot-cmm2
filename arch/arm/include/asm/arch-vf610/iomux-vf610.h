/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2013-2014 Freescale Semiconductor, Inc.
 */

#ifndef __IOMUX_VF610_H__
#define __IOMUX_VF610_H__

#include <asm/mach-imx/iomux-v3.h>

/* Pad control groupings */
#define VF610_UART_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_DSE_25ohm | \
				PAD_CTL_OBE_IBE_ENABLE)
#define VF610_SDHC_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_DSE_20ohm | \
				PAD_CTL_OBE_IBE_ENABLE)
#define VF610_ENET_PAD_CTRL	(PAD_CTL_PUS_47K_UP | PAD_CTL_DSE_50ohm | \
				PAD_CTL_OBE_IBE_ENABLE)
#define VF610_DDR_PAD_CTRL	PAD_CTL_DSE_25ohm
#define VF610_DDR_PAD_CTRL_1	(PAD_CTL_DSE_25ohm | \
				PAD_CTL_INPUT_DIFFERENTIAL)
#define VF610_I2C_PAD_CTRL	(PAD_CTL_PUS_47K_UP | PAD_CTL_DSE_50ohm | \
				PAD_CTL_SPEED_HIGH | PAD_CTL_ODE | \
				PAD_CTL_OBE_IBE_ENABLE)
#define VF610_NFC_IO_PAD_CTRL	(PAD_CTL_SPEED_MED | PAD_CTL_SRE | \
				PAD_CTL_DSE_50ohm | PAD_CTL_PUS_47K_UP | \
				PAD_CTL_OBE_IBE_ENABLE)
#define VF610_NFC_CN_PAD_CTRL	(PAD_CTL_SPEED_MED | PAD_CTL_SRE | \
				PAD_CTL_DSE_25ohm | PAD_CTL_OBE_ENABLE)
#define VF610_NFC_RB_PAD_CTRL	(PAD_CTL_SPEED_MED | PAD_CTL_SRE | \
				PAD_CTL_PUS_22K_UP | PAD_CTL_IBE_ENABLE)

#define VF610_QSPI_PAD_CTRL	(PAD_CTL_SPEED_HIGH | PAD_CTL_DSE_150ohm | \
				PAD_CTL_PUS_22K_UP | PAD_CTL_OBE_IBE_ENABLE)

#define VF610_GPIO_PAD_CTRL	(PAD_CTL_SPEED_MED | PAD_CTL_DSE_50ohm | \
				PAD_CTL_IBE_ENABLE)

#define VF610_DSPI_PAD_CTRL	(PAD_CTL_OBE_ENABLE | PAD_CTL_DSE_20ohm | \
				PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_HIGH)
#define VF610_DSPI_SIN_PAD_CTRL	(PAD_CTL_IBE_ENABLE | PAD_CTL_DSE_20ohm | \
				PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_HIGH)
#define VF610_DCU_PAD_CTRL     (PAD_CTL_SPEED_MED | PAD_CTL_SRE | \
				PAD_CTL_DSE_37ohm | PAD_CTL_OBE_ENABLE)

enum {
	VF610_PAD_PTA6__RMII0_CLKIN		= IOMUX_PAD(0x0000, 0x0000, 2, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTA6__RMII0_CLKOUT		= IOMUX_PAD(0x0000, 0x0000, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTA7__GPIO_134		= IOMUX_PAD(0x0218, 0x0218, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTA17__GPIO_7			= IOMUX_PAD(0x001c, 0x001c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTA20__GPIO_10		= IOMUX_PAD(0x0028, 0x0028, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTA21__GPIO_11		= IOMUX_PAD(0x002c, 0x002c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTA30__GPIO_20		= IOMUX_PAD(0x0050, 0x0050, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTA31__GPIO_21		= IOMUX_PAD(0x0054, 0x0054, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB0__GPIO_22			= IOMUX_PAD(0x0058, 0x0058, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB1__GPIO_23			= IOMUX_PAD(0x005C, 0x005C, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB4__UART1_TX		= IOMUX_PAD(0x0068, 0x0068, 2, 0x0380, 0, VF610_UART_PAD_CTRL),
	VF610_PAD_PTB5__UART1_RX		= IOMUX_PAD(0x006c, 0x006c, 2, 0x037c, 0, VF610_UART_PAD_CTRL),
	VF610_PAD_PTB6__GPIO_28			= IOMUX_PAD(0x0070, 0x0070, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB7__GPIO_29			= IOMUX_PAD(0x0074, 0x0074, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB8__GPIO_30			= IOMUX_PAD(0x0078, 0x0078, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB9__GPIO_31			= IOMUX_PAD(0x007C, 0x007C, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB10__UART0_TX		= IOMUX_PAD(0x0080, 0x0080, 1, __NA_, 0, VF610_UART_PAD_CTRL),
	VF610_PAD_PTB11__UART0_RX		= IOMUX_PAD(0x0084, 0x0084, 1, __NA_, 0, VF610_UART_PAD_CTRL),
	VF610_PAD_PTB12__GPIO_34		= IOMUX_PAD(0x0088, 0x0088, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB13__GPIO_35		= IOMUX_PAD(0x008c, 0x008c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB16__GPIO_38		= IOMUX_PAD(0x0098, 0x0098, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB17__GPIO_39		= IOMUX_PAD(0x009c, 0x009c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB18__GPIO_40		= IOMUX_PAD(0x00a0, 0x00a0, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB21__GPIO_43		= IOMUX_PAD(0x00ac, 0x00ac, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB22__GPIO_44		= IOMUX_PAD(0x00b0, 0x00b0, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB23__GPIO_93		= IOMUX_PAD(0x0174, 0x0174, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB26__GPIO_96		= IOMUX_PAD(0x0180, 0x0180, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTB28__GPIO_98		= IOMUX_PAD(0x0188, 0x0188, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC1__GPIO_46			= IOMUX_PAD(0x00b8, 0x00b8, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC1__RMII0_MDIO		= IOMUX_PAD(0x00b8, 0x00b8, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC0__GPIO_45			= IOMUX_PAD(0x00b4, 0x00b4, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC0__RMII0_MDC		= IOMUX_PAD(0x00b4, 0x00b4, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC2__RMII0_CRS_DV		= IOMUX_PAD(0x00bc, 0x00bc, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC2__GPIO_47			= IOMUX_PAD(0x00bc, 0x00bc, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC3__RMII0_RD1		= IOMUX_PAD(0x00c0, 0x00c0, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC3__GPIO_48			= IOMUX_PAD(0x00c0, 0x00c0, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC4__RMII0_RD0		= IOMUX_PAD(0x00c4, 0x00c4, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC4__GPIO_49			= IOMUX_PAD(0x00c4, 0x00c4, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC5__RMII0_RXER		= IOMUX_PAD(0x00c8, 0x00c8, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC5__GPIO_50			= IOMUX_PAD(0x00c8, 0x00c8, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC6__RMII0_TD1		= IOMUX_PAD(0x00cc, 0x00cc, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC6__GPIO_51			= IOMUX_PAD(0x00cc, 0x00cc, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC7__RMII0_TD0		= IOMUX_PAD(0x00D0, 0x00D0, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC7__GPIO_52			= IOMUX_PAD(0x00D0, 0x00D0, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC8__RMII0_TXEN		= IOMUX_PAD(0x00D4, 0x00D4, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC8__GPIO_53			= IOMUX_PAD(0x00D4, 0x00D4, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC10__RMII1_MDIO		= IOMUX_PAD(0x00dc, 0x00dc, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC9__RMII1_MDC		= IOMUX_PAD(0x00d8, 0x00d8, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC11__RMII1_CRS_DV		= IOMUX_PAD(0x00e0, 0x00e0, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC12__RMII1_RD1		= IOMUX_PAD(0x00e4, 0x00e4, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC13__RMII1_RD0		= IOMUX_PAD(0x00e8, 0x00e8, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC14__RMII1_RXER		= IOMUX_PAD(0x00ec, 0x00ec, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC15__RMII1_TD1		= IOMUX_PAD(0x00f0, 0x00f0, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC16__RMII1_TD0		= IOMUX_PAD(0x00f4, 0x00f4, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTC17__RMII1_TXEN		= IOMUX_PAD(0x00f8, 0x00f8, 1, __NA_, 0, VF610_ENET_PAD_CTRL),
	VF610_PAD_PTD5__DSPI1_CS0		= IOMUX_PAD(0x0150, 0x0150, 3, 0x300, 1, VF610_DSPI_PAD_CTRL),
	VF610_PAD_PTD6__DSPI1_SIN		= IOMUX_PAD(0x0154, 0x0154, 3, 0x2fc, 1, VF610_DSPI_SIN_PAD_CTRL),
	VF610_PAD_PTD7__DSPI1_SOUT		= IOMUX_PAD(0x0158, 0x0158, 3, __NA_, 0, VF610_DSPI_PAD_CTRL),
	VF610_PAD_PTD8__DSPI1_SCK		= IOMUX_PAD(0x015c, 0x015c, 3, 0x2f8, 1, VF610_DSPI_PAD_CTRL),
	VF610_PAD_PTC29__GPIO_102		= IOMUX_PAD(0x0198, 0x0198, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTC30__GPIO_103		= IOMUX_PAD(0x019c, 0x019c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTA24__ESDHC1_CLK		= IOMUX_PAD(0x0038, 0x0038, 5, __NA_, 0, VF610_SDHC_PAD_CTRL),
	VF610_PAD_PTA25__ESDHC1_CMD		= IOMUX_PAD(0x003c, 0x003c, 5, __NA_, 0, VF610_SDHC_PAD_CTRL),
	VF610_PAD_PTA26__ESDHC1_DAT0		= IOMUX_PAD(0x0040, 0x0040, 5, __NA_, 0, VF610_SDHC_PAD_CTRL),
	VF610_PAD_PTA27__ESDHC1_DAT1		= IOMUX_PAD(0x0044, 0x0044, 5, __NA_, 0, VF610_SDHC_PAD_CTRL),
	VF610_PAD_PTA28__ESDHC1_DAT2		= IOMUX_PAD(0x0048, 0x0048, 5, __NA_, 0, VF610_SDHC_PAD_CTRL),
	VF610_PAD_PTA29__ESDHC1_DAT3		= IOMUX_PAD(0x004c, 0x004c, 5, __NA_, 0, VF610_SDHC_PAD_CTRL),
	VF610_PAD_PTB14__I2C0_SCL		= IOMUX_PAD(0x0090, 0x0090, 2, 0x033c, 1, VF610_I2C_PAD_CTRL),
	VF610_PAD_PTB15__I2C0_SDA		= IOMUX_PAD(0x0094, 0x0094, 2, 0x0340, 1, VF610_I2C_PAD_CTRL),
	VF610_PAD_PTA22__I2C2_SCL		= IOMUX_PAD(0x0030, 0x0030, 6, 0x034c, 0, VF610_I2C_PAD_CTRL),
	VF610_PAD_PTA23__I2C2_SDA		= IOMUX_PAD(0x0034, 0x0034, 6, 0x0350, 0, VF610_I2C_PAD_CTRL),
	VF610_PAD_PTD31__NF_IO15		= IOMUX_PAD(0x00fc, 0x00fc, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD31__GPIO_63		= IOMUX_PAD(0x00fc, 0x00fc, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD30__NF_IO14		= IOMUX_PAD(0x0100, 0x0100, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD30__GPIO_64		= IOMUX_PAD(0x0100, 0x0100, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD29__NF_IO13		= IOMUX_PAD(0x0104, 0x0104, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD29__GPIO_65		= IOMUX_PAD(0x0104, 0x0104, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD28__NF_IO12		= IOMUX_PAD(0x0108, 0x0108, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD28__GPIO_66		= IOMUX_PAD(0x0108, 0x0108, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD27__NF_IO11		= IOMUX_PAD(0x010c, 0x010c, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD27__GPIO_67		= IOMUX_PAD(0x010c, 0x010c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD26__NF_IO10		= IOMUX_PAD(0x0110, 0x0110, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD26__GPIO_68		= IOMUX_PAD(0x0110, 0x0110, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD25__NF_IO9			= IOMUX_PAD(0x0114, 0x0114, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD25__GPIO_69		= IOMUX_PAD(0x0114, 0x0114, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD24__NF_IO8			= IOMUX_PAD(0x0118, 0x0118, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD24__GPIO_70		= IOMUX_PAD(0x0118, 0x0118, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD23__NF_IO7			= IOMUX_PAD(0x011c, 0x011c, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD0__QSPI0_A_QSCK		= IOMUX_PAD(0x013c, 0x013c, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD0__UART2_TX		= IOMUX_PAD(0x013c, 0x013c, 2, 0x38c, 2, VF610_UART_PAD_CTRL),
	VF610_PAD_PTD1__QSPI0_A_CS0		= IOMUX_PAD(0x0140, 0x0140, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD1__UART2_RX		= IOMUX_PAD(0x0140, 0x0140, 2, 0x388, 2, VF610_UART_PAD_CTRL),
	VF610_PAD_PTD2__QSPI0_A_DATA3		= IOMUX_PAD(0x0144, 0x0144, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD2__GPIO_81			= IOMUX_PAD(0x0144, 0x0144, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD3__QSPI0_A_DATA2		= IOMUX_PAD(0x0148, 0x0148, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD3__GPIO_82			= IOMUX_PAD(0x0148, 0x0148, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD4__GPIO_83			= IOMUX_PAD(0x014C, 0x014C, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD4__QSPI0_A_DATA1		= IOMUX_PAD(0x014c, 0x014c, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD5__QSPI0_A_DATA0		= IOMUX_PAD(0x0150, 0x0150, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD7__QSPI0_B_QSCK		= IOMUX_PAD(0x0158, 0x0158, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD8__QSPI0_B_CS0		= IOMUX_PAD(0x015c, 0x015c, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD9__QSPI0_B_DATA3		= IOMUX_PAD(0x0160, 0x0160, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD9__GPIO_88			= IOMUX_PAD(0x0160, 0x0160, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD10__QSPI0_B_DATA2		= IOMUX_PAD(0x0164, 0x0164, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD10__GPIO_89		= IOMUX_PAD(0x0164, 0x0164, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD11__QSPI0_B_DATA1		= IOMUX_PAD(0x0168, 0x0168, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD11__GPIO_90		= IOMUX_PAD(0x0168, 0x0168, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD12__QSPI0_B_DATA0		= IOMUX_PAD(0x016c, 0x016c, 1, __NA_, 0, VF610_QSPI_PAD_CTRL),
	VF610_PAD_PTD12__GPIO_91		= IOMUX_PAD(0x016c, 0x016c, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD13__GPIO_92		= IOMUX_PAD(0x0170, 0x0170, 0, __NA_, 0, VF610_GPIO_PAD_CTRL),
	VF610_PAD_PTD22__NF_IO6			= IOMUX_PAD(0x0120, 0x0120, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD21__NF_IO5			= IOMUX_PAD(0x0124, 0x0124, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD20__NF_IO4			= IOMUX_PAD(0x0128, 0x0128, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD19__NF_IO3			= IOMUX_PAD(0x012c, 0x012c, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD18__NF_IO2			= IOMUX_PAD(0x0130, 0x0130, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD17__NF_IO1			= IOMUX_PAD(0x0134, 0x0134, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTD16__NF_IO0			= IOMUX_PAD(0x0138, 0x0138, 2, __NA_, 0, VF610_NFC_IO_PAD_CTRL),
	VF610_PAD_PTB24__NF_WE_B		= IOMUX_PAD(0x0178, 0x0178, 5, __NA_, 0, VF610_NFC_CN_PAD_CTRL),
	VF610_PAD_PTB25__NF_CE0_B		= IOMUX_PAD(0x017c, 0x017c, 5, __NA_, 0, VF610_NFC_CN_PAD_CTRL),

	VF610_PAD_PTB27__NF_RE_B 		= IOMUX_PAD(0x0184, 0x0184, 6, __NA_, 0, VF610_NFC_CN_PAD_CTRL),

	VF610_PAD_PTC26__NF_RB_B 		= IOMUX_PAD(0x018C, 0x018C, 5, __NA_, 0, VF610_NFC_RB_PAD_CTRL),

	VF610_PAD_PTC27__NF_ALE  		= IOMUX_PAD(0x0190, 0x0190, 6, __NA_, 0, VF610_NFC_CN_PAD_CTRL),

	VF610_PAD_PTC28__NF_CLE  		= IOMUX_PAD(0x0194, 0x0194, 6, __NA_, 0, VF610_NFC_CN_PAD_CTRL),

	VF610_PAD_PTE0__DCU0_HSYNC		= IOMUX_PAD(0x01a4, 0x01a4, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE1__DCU0_VSYNC		= IOMUX_PAD(0x01a8, 0x01a8, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE2__DCU0_PCLK		= IOMUX_PAD(0x01ac, 0x01ac, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE4__DCU0_DE			= IOMUX_PAD(0x01b4, 0x01b4, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE5__DCU0_R0			= IOMUX_PAD(0x01b8, 0x01b8, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE6__DCU0_R1			= IOMUX_PAD(0x01bc, 0x01bc, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE7__DCU0_R2			= IOMUX_PAD(0x01c0, 0x01c0, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE8__DCU0_R3			= IOMUX_PAD(0x01c4, 0x01c4, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE9__DCU0_R4			= IOMUX_PAD(0x01c8, 0x01c8, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE10__DCU0_R5		= IOMUX_PAD(0x01cc, 0x01cc, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE11__DCU0_R6		= IOMUX_PAD(0x01d0, 0x01d0, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE12__DCU0_R7		= IOMUX_PAD(0x01d4, 0x01d4, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE13__DCU0_G0		= IOMUX_PAD(0x01d8, 0x01d8, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE14__DCU0_G1		= IOMUX_PAD(0x01dc, 0x01dc, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE15__DCU0_G2		= IOMUX_PAD(0x01e0, 0x01e0, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE16__DCU0_G3		= IOMUX_PAD(0x01e4, 0x01e4, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE17__DCU0_G4		= IOMUX_PAD(0x01e8, 0x01e8, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE18__DCU0_G5		= IOMUX_PAD(0x01ec, 0x01ec, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE19__DCU0_G6		= IOMUX_PAD(0x01f0, 0x01f0, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE20__DCU0_G7		= IOMUX_PAD(0x01f4, 0x01f4, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE21__DCU0_B0		= IOMUX_PAD(0x01f8, 0x01f8, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE22__DCU0_B1		= IOMUX_PAD(0x01fc, 0x01fc, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE23__DCU0_B2		= IOMUX_PAD(0x0200, 0x0200, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE24__DCU0_B3		= IOMUX_PAD(0x0204, 0x0204, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE25__DCU0_B4		= IOMUX_PAD(0x0208, 0x0208, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE26__DCU0_B5		= IOMUX_PAD(0x020c, 0x020c, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE27__DCU0_B6		= IOMUX_PAD(0x0210, 0x0210, 1, __NA_, 0, VF610_DCU_PAD_CTRL),
	VF610_PAD_PTE28__DCU0_B7		= IOMUX_PAD(0x0214, 0x0214, 1, __NA_, 0, VF610_DCU_PAD_CTRL),

	VF610_PAD_DDR_RESETB			= IOMUX_PAD(0x021c, 0x021c, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A15__DDR_A_15		= IOMUX_PAD(0x0220, 0x0220, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A14__DDR_A_14		= IOMUX_PAD(0x0224, 0x0224, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A13__DDR_A_13		= IOMUX_PAD(0x0228, 0x0228, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A12__DDR_A_12		= IOMUX_PAD(0x022c, 0x022c, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A11__DDR_A_11		= IOMUX_PAD(0x0230, 0x0230, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A10__DDR_A_10		= IOMUX_PAD(0x0234, 0x0234, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A9__DDR_A_9		= IOMUX_PAD(0x0238, 0x0238, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A8__DDR_A_8		= IOMUX_PAD(0x023c, 0x023c, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A7__DDR_A_7		= IOMUX_PAD(0x0240, 0x0240, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A6__DDR_A_6		= IOMUX_PAD(0x0244, 0x0244, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A5__DDR_A_5		= IOMUX_PAD(0x0248, 0x0248, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A4__DDR_A_4		= IOMUX_PAD(0x024c, 0x024c, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A3__DDR_A_3		= IOMUX_PAD(0x0250, 0x0250, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A2__DDR_A_2		= IOMUX_PAD(0x0254, 0x0254, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A1__DDR_A_1		= IOMUX_PAD(0x0258, 0x0258, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_A0__DDR_A_0		= IOMUX_PAD(0x025c, 0x025c, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_BA2__DDR_BA_2		= IOMUX_PAD(0x0260, 0x0260, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_BA1__DDR_BA_1		= IOMUX_PAD(0x0264, 0x0264, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_BA0__DDR_BA_0		= IOMUX_PAD(0x0268, 0x0268, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_CAS__DDR_CAS_B		= IOMUX_PAD(0x026c, 0x026c, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_CKE__DDR_CKE_0		= IOMUX_PAD(0x0270, 0x0270, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_CLK__DDR_CLK_0		= IOMUX_PAD(0x0274, 0x0274, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_CS__DDR_CS_B_0		= IOMUX_PAD(0x0278, 0x0278, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_D15__DDR_D_15		= IOMUX_PAD(0x027c, 0x027c, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D14__DDR_D_14		= IOMUX_PAD(0x0280, 0x0280, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D13__DDR_D_13		= IOMUX_PAD(0x0284, 0x0284, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D12__DDR_D_12		= IOMUX_PAD(0x0288, 0x0288, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D11__DDR_D_11		= IOMUX_PAD(0x028c, 0x028c, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D10__DDR_D_10		= IOMUX_PAD(0x0290, 0x0290, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D9__DDR_D_9		= IOMUX_PAD(0x0294, 0x0294, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D8__DDR_D_8		= IOMUX_PAD(0x0298, 0x0298, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D7__DDR_D_7		= IOMUX_PAD(0x029c, 0x029c, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D6__DDR_D_6		= IOMUX_PAD(0x02a0, 0x02a0, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D5__DDR_D_5		= IOMUX_PAD(0x02a4, 0x02a4, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D4__DDR_D_4		= IOMUX_PAD(0x02a8, 0x02a8, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D3__DDR_D_3		= IOMUX_PAD(0x02ac, 0x02ac, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D2__DDR_D_2		= IOMUX_PAD(0x02b0, 0x02b0, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D1__DDR_D_1		= IOMUX_PAD(0x02b4, 0x02b4, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_D0__DDR_D_0		= IOMUX_PAD(0x02b8, 0x02b8, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_DQM1__DDR_DQM_1		= IOMUX_PAD(0x02bc, 0x02bc, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_DQM0__DDR_DQM_0		= IOMUX_PAD(0x02c0, 0x02c0, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_DQS1__DDR_DQS_1		= IOMUX_PAD(0x02c4, 0x02c4, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_DQS0__DDR_DQS_0		= IOMUX_PAD(0x02c8, 0x02c8, 0, __NA_, 0, VF610_DDR_PAD_CTRL_1),
	VF610_PAD_DDR_RAS__DDR_RAS_B		= IOMUX_PAD(0x02cc, 0x02cc, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_WE__DDR_WE_B		= IOMUX_PAD(0x02d0, 0x02d0, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_ODT1__DDR_ODT_0		= IOMUX_PAD(0x02d4, 0x02d4, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_ODT0__DDR_ODT_1		= IOMUX_PAD(0x02d8, 0x02d8, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_DDRBYTE1__DDR_DDRBYTE1	= IOMUX_PAD(0x02dc, 0x02dc, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
	VF610_PAD_DDR_DDRBYTE2__DDR_DDRBYTE2	= IOMUX_PAD(0x02e0, 0x02e0, 0, __NA_, 0, VF610_DDR_PAD_CTRL),
};

#endif	/* __IOMUX_VF610_H__ */
