/*
 * m5301x.h -- Definitions for Freescale Coldfire 5301x
 *
 * Copyright (C) 2004-2008 Freescale Semiconductor, Inc.
 * TsiChung Liew (Tsi-Chung.Liew@freescale.com)
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef m5301x_h
#define m5301x_h

/* *** System Control Module (SCM) *** */
#define SCM_MPR_MPROT0(x)		(((x) & 0x0F) << 28)
#define SCM_MPR_MPROT1(x)		(((x) & 0x0F) << 24)
#define SCM_MPR_MPROT2(x)		(((x) & 0x0F) << 20)
#define SCM_MPR_MPROT4(x)		(((x) & 0x0F) << 12)
#define SCM_MPR_MPROT5(x)		(((x) & 0x0F) << 8)
#define SCM_MPR_MPROT6(x)		(((x) & 0x0F) << 4)
#define MPROT_MTR			4
#define MPROT_MTW			2
#define MPROT_MPL			1

#define SCM_PACRA_PACR0(x)		(((x) & 0x0F) << 28)
#define SCM_PACRA_PACR1(x)		(((x) & 0x0F) << 24)
#define SCM_PACRA_PACR2(x)		(((x) & 0x0F) << 20)
#define SCM_PACRA_PACR5(x)		(((x) & 0x0F) << 8)

#define SCM_PACRB_PACR12(x)		(((x) & 0x0F) << 12)
#define SCM_PACRB_PACR13(x)		(((x) & 0x0F) << 8)

#define SCM_PACRC_PACR16(x)		(((x) & 0x0F) << 28)
#define SCM_PACRC_PACR17(x)		(((x) & 0x0F) << 24)
#define SCM_PACRC_PACR18(x)		(((x) & 0x0F) << 20)
#define SCM_PACRC_PACR19(x)		(((x) & 0x0F) << 16)
#define SCM_PACRC_PACR21(x)		(((x) & 0x0F) << 8)
#define SCM_PACRC_PACR22(x)		(((x) & 0x0F) << 4)
#define SCM_PACRC_PACR23(x)		((x) & 0x0F)

#define SCM_PACRD_PACR24(x)		(((x) & 0x0F) << 28)
#define SCM_PACRD_PACR25(x)		(((x) & 0x0F) << 24)
#define SCM_PACRD_PACR26(x)		(((x) & 0x0F) << 20)
#define SCM_PACRD_PACR28(x)		(((x) & 0x0F) << 12)
#define SCM_PACRD_PACR29(x)		(((x) & 0x0F) << 8)
#define SCM_PACRD_PACR30(x)		(((x) & 0x0F) << 4)
#define SCM_PACRD_PACR31(x)		((x) & 0x0F)

#define SCM_PACRE_PACR32(x)		(((x) & 0x0F) << 28)
#define SCM_PACRE_PACR33(x)		(((x) & 0x0F) << 24)
#define SCM_PACRE_PACR34(x)		(((x) & 0x0F) << 20)
#define SCM_PACRE_PACR35(x)		(((x) & 0x0F) << 16)
#define SCM_PACRE_PACR36(x)		(((x) & 0x0F) << 12)
#define SCM_PACRE_PACR37(x)		(((x) & 0x0F) << 8)
#define SCM_PACRE_PACR39(x)		((x) & 0x0F)

#define SCM_PACRF_PACR40(x)		(((x) & 0x0F) << 28)
#define SCM_PACRF_PACR41(x)		(((x) & 0x0F) << 24)
#define SCM_PACRF_PACR42(x)		(((x) & 0x0F) << 20)
#define SCM_PACRF_PACR43(x)		(((x) & 0x0F) << 16)
#define SCM_PACRF_PACR44(x)		(((x) & 0x0F) << 12)
#define SCM_PACRF_PACR45(x)		(((x) & 0x0F) << 8)
#define SCM_PACRF_PACR46(x)		(((x) & 0x0F) << 4)
#define SCM_PACRF_PACR47(x)		((x) & 0x0F)

#define SCM_PACRG_PACR48(x)		(((x) & 0x0F) << 28)
#define SCM_PACRG_PACR49(x)		(((x) & 0x0F) << 24)
#define SCM_PACRG_PACR50(x)		(((x) & 0x0F) << 20)
#define SCM_PACRG_PACR51(x)		(((x) & 0x0F) << 16)

#define PACR_SP	4
#define PACR_WP	2
#define PACR_TP	1

#define SCM_CWCR_RO			(0x8000)
#define SCM_CWCR_CWR_WH			(0x0100)
#define SCM_CWCR_CWE			(0x0080)
#define SCM_CWCR_CWRI_WINDOW		(0x0060)
#define SCM_CWCR_CWRI_RESET		(0x0040)
#define SCM_CWCR_CWRI_INT_RESET		(0x0020)
#define SCM_CWCR_CWRI_INT		(0x0000)
#define SCM_CWCR_CWT(x)			(((x) & 0x001F))

#define SCM_ISR_CFEI			(0x02)
#define SCM_ISR_CWIC			(0x01)

#define BCR_GBR				(0x00000200)
#define BCR_GBW				(0x00000100)
#define BCR_S7				(0x00000080)
#define BCR_S6				(0x00000040)
#define BCR_S4				(0x00000010)
#define BCR_S1				(0x00000002)

#define SCM_CFIER_ECFEI			(0x01)

#define SCM_CFLOC_LOC			(0x80)

#define SCM_CFATR_WRITE			(0x80)
#define SCM_CFATR_SZ32			(0x20)
#define SCM_CFATR_SZ16			(0x10)
#define SCM_CFATR_SZ08			(0x00)
#define SCM_CFATR_CACHE			(0x08)
#define SCM_CFATR_MODE			(0x02)
#define SCM_CFATR_TYPE			(0x01)

/* *** Interrupt Controller (INTC) *** */
#define INT0_LO_RSVD0			(0)
#define INT0_LO_EPORT1			(1)
#define INT0_LO_EPORT2			(2)
#define INT0_LO_EPORT3			(3)
#define INT0_LO_EPORT4			(4)
#define INT0_LO_EPORT5			(5)
#define INT0_LO_EPORT6			(6)
#define INT0_LO_EPORT7			(7)
#define INT0_LO_EDMA_00			(8)
#define INT0_LO_EDMA_01			(9)
#define INT0_LO_EDMA_02			(10)
#define INT0_LO_EDMA_03			(11)
#define INT0_LO_EDMA_04			(12)
#define INT0_LO_EDMA_05			(13)
#define INT0_LO_EDMA_06			(14)
#define INT0_LO_EDMA_07			(15)
#define INT0_LO_EDMA_08			(16)
#define INT0_LO_EDMA_09			(17)
#define INT0_LO_EDMA_10			(18)
#define INT0_LO_EDMA_11			(19)
#define INT0_LO_EDMA_12			(20)
#define INT0_LO_EDMA_13			(21)
#define INT0_LO_EDMA_14			(22)
#define INT0_LO_EDMA_15			(23)
#define INT0_LO_EDMA_ERR		(24)
#define INT0_LO_SCM_CWIC		(25)
#define INT0_LO_UART0			(26)
#define INT0_LO_UART1			(27)
#define INT0_LO_UART2			(28)
#define INT0_LO_RSVD1			(29)
#define INT0_LO_I2C			(30)
#define INT0_LO_DSPI			(31)
#define INT0_HI_DTMR0			(32)
#define INT0_HI_DTMR1			(33)
#define INT0_HI_DTMR2			(34)
#define INT0_HI_DTMR3			(35)
#define INT0_HI_FEC0_TXF		(36)
#define INT0_HI_FEC0_TXB		(37)
#define INT0_HI_FEC0_UN			(38)
#define INT0_HI_FEC0_RL			(39)
#define INT0_HI_FEC0_RXF		(40)
#define INT0_HI_FEC0_RXB		(41)
#define INT0_HI_FEC0_MII		(42)
#define INT0_HI_FEC0_LC			(43)
#define INT0_HI_FEC0_HBERR		(44)
#define INT0_HI_FEC0_GRA		(45)
#define INT0_HI_FEC0_EBERR		(46)
#define INT0_HI_FEC0_BABT		(47)
#define INT0_HI_FEC0_BABR		(48)
#define INT0_HI_FEC1_TXF		(49)
#define INT0_HI_FEC1_TXB		(50)
#define INT0_HI_FEC1_UN			(51)
#define INT0_HI_FEC1_RL			(52)
#define INT0_HI_FEC1_RXF		(53)
#define INT0_HI_FEC1_RXB		(54)
#define INT0_HI_FEC1_MII		(55)
#define INT0_HI_FEC1_LC			(56)
#define INT0_HI_FEC1_HBERR		(57)
#define INT0_HI_FEC1_GRA		(58)
#define INT0_HI_FEC1_EBERR		(59)
#define INT0_HI_FEC1_BABT		(60)
#define INT0_HI_FEC1_BABR		(61)
#define INT0_HI_SCM_CFEI		(62)

/* 0 - 24 reserved */
#define INT1_LO_EPORT1_FLAG0		(25)
#define INT1_LO_EPORT1_FLAG1		(26)
#define INT1_LO_EPORT1_FLAG2		(27)
#define INT1_LO_EPORT1_FLAG3		(28)
#define INT1_LO_EPORT1_FLAG4		(29)
#define INT1_LO_EPORT1_FLAG5		(30)
#define INT1_LO_EPORT1_FLAG6		(31)
#define INT1_LO_EPORT1_FLAG7		(32)
#define INT1_HI_DSPI_EOQF		(33)
#define INT1_HI_DSPI_TFFF		(34)
#define INT1_HI_DSPI_TCF		(35)
#define INT1_HI_DSPI_TFUF		(36)
#define INT1_HI_DSPI_RFDF		(37)
#define INT1_HI_DSPI_RFOF		(38)
#define INT1_HI_DSPI_RFOF_TFUF		(39)
#define INT1_HI_RNG_EI			(40)
#define INT1_HI_PLL_LOCF		(41)
#define INT1_HI_PLL_LOLF		(42)
#define INT1_HI_PIT0			(43)
#define INT1_HI_PIT1			(44)
#define INT1_HI_PIT2			(45)
#define INT1_HI_PIT3			(46)
#define INT1_HI_USBOTG_STS		(47)
#define INT1_HI_USBHOST_STS		(48)
#define INT1_HI_SSI			(49)
/* 50 - 51 reserved */
#define INT1_HI_RTC			(52)
#define INT1_HI_CCM_USBSTAT		(53)
#define INT1_HI_CODEC_OR		(54)
#define INT1_HI_CODEC_RF_TE		(55)
#define INT1_HI_CODEC_ROE		(56)
#define INT1_HI_CODEC_TUE		(57)
/* 58 reserved */
#define INT1_HI_SIM1_DATA		(59)
#define INT1_HI_SIM1_GENERAL		(60)
/* 61 - 62 reserved */
#define INT1_HI_SDHC			(63)

/* *** Reset Controller Module (RCM) *** */
#define RCM_RCR_SOFTRST			(0x80)
#define RCM_RCR_FRCRSTOUT		(0x40)

#define RCM_RSR_SOFT			(0x20)
#define RCM_RSR_LOC			(0x10)
#define RCM_RSR_POR			(0x08)
#define RCM_RSR_EXT			(0x04)
#define RCM_RSR_WDR_CORE		(0x02)
#define RCM_RSR_LOL			(0x01)

/* *** Chip Configuration Module (CCM) *** */
#define CCM_CCR_CSC			(0x0020)
#define CCM_CCR_BOOTPS			(0x0010)
#define CCM_CCR_LOAD			(0x0008)
#define CCM_CCR_OSC_MODE		(0x0004)
#define CCM_CCR_SDR_MODE		(0x0002)
#define CCM_CCR_RESERVED		(0x0001)

#define CCM_RCON_SDR_32BIT_UNIFIED	(0x0012)
#define CCM_RCON_DDR_8BIT_SPLIT		(0x0010)
#define CCM_RCON_SDR_16BIT_UNIFIED	(0x0002)
#define CCM_RCON_DDR_16BIT_SPLIT	(0x0000)

#define CCM_CIR_PIN(x)			(((x) & 0x03FF) << 6)
#define CCM_CIR_PRN(x)			((x) & 0x003F)

#define CCM_MISCCR_FECM			(0x8000)
#define CCM_MISCCR_CDCSRC		(0x4000)
#define CCM_MISCCR_PLL_LOCK		(0x2000)
#define CCM_MISCCR_LIMP			(0x1000)
#define CCM_MISCCR_BME			(0x8000)
#define CCM_MISCCR_BMT_MASK		(0xF8FF)
#define CCM_MISCCR_BMT(x)		(((x) & 0x0007) << 8)
#define CCM_MISCCR_BMT_512		(0x0700)
#define CCM_MISCCR_BMT_1024		(0x0600)
#define CCM_MISCCR_BMT_2048		(0x0500)
#define CCM_MISCCR_BMT_4096		(0x0400)
#define CCM_MISCCR_BMT_8192		(0x0300)
#define CCM_MISCCR_BMT_16384		(0x0200)
#define CCM_MISCCR_BMT_32768		(0x0100)
#define CCM_MISCCR_BMT_65536		(0x0000)
#define CCM_MISCCR_TIM_DMA		(0x0020)
#define CCM_MISCCR_SSI_SRC		(0x0010)
#define CCM_MISCCR_USBH_OC		(0x0008)
#define CCM_MISCCR_USBO_OC		(0x0004)
#define CCM_MISCCR_USB_PUE		(0x0002)
#define CCM_MISCCR_USB_SRC		(0x0001)

#define CCM_CDR_LPDIV(x)		(((x) & 0x0F) << 8)
#define CCM_CDR_SSIDIV(x)		((x) & 0xFF)

#define CCM_UOCSR_DPPD			(0x2000)
#define CCM_UOCSR_DMPD			(0x1000)
#define CCM_UOCSR_DRV_VBUS		(0x0800)
#define CCM_UOCSR_CRG_VBUS		(0x0400)
#define CCM_UOCSR_DCR_VBUS		(0x0200)
#define CCM_UOCSR_DPPU			(0x0100)
#define CCM_UOCSR_AVLD			(0x0080)
#define CCM_UOCSR_BVLD			(0x0040)
#define CCM_UOCSR_VVLD			(0x0020)
#define CCM_UOCSR_SEND			(0x0010)
#define CCM_UOCSR_PWRFLT		(0x0008)
#define CCM_UOCSR_WKUP			(0x0004)
#define CCM_UOCSR_UOMIE			(0x0002)
#define CCM_UOCSR_XPDE			(0x0001)

#define CCM_UHCSR_PORTIND(x)		(((x) & 0x0003) << 14)
#define CCM_UHCSR_DRV_VBUS		(0x0010)
#define CCM_UHCSR_PWRFLT		(0x0008)
#define CCM_UHCSR_WKUP			(0x0004)
#define CCM_UHCSR_UHMIE			(0x0002)
#define CCM_UHCSR_XPDE			(0x0001)

#define CCM_CODCR_BGREN			(0x8000)
#define CCM_CODCR_REGEN			(0x0080)

#define CCM_MISC2_IGNLL			(0x0008)
#define CCM_MISC2_DPS			(0x0001)

/* *** General Purpose I/O (GPIO) *** */
#define GPIO_PDR_FBCTL			((x) & 0x0F)
#define GPIO_PDR_BE			((x) & 0x0F)
#define GPIO_PDR_CS32			(((x) & 0x03) << 4)
#define GPIO_PDR_CS10			(((x) & 0x03) << 4)
#define GPIO_PDR_DSPI			((x) & 0x7F)
#define GPIO_PDR_FEC0			((x) & 0x7F)
#define GPIO_PDR_FECI2C			((x) & 0x3F)
#define GPIO_PDR_SIMP1			((x) & 0x1F)
#define GPIO_PDR_SIMP0			((x) & 0x1F)
#define GPIO_PDR_TIMER			((x) & 0x0F)
#define GPIO_PDR_UART			((x) & 0x3F)
#define GPIO_PDR_DEBUG			(0x01)
#define GPIO_PDR_SDHC			((x) & 0x3F)
#define GPIO_PDR_SSI			((x) & 0x1F)

#define GPIO_PAR_FBCTL_OE		(0x80)
#define GPIO_PAR_FBCTL_TA		(0x40)
#define GPIO_PAR_FBCTL_RWB		(0x20)
#define GPIO_PAR_FBCTL_TS		(0x18)

#define GPIO_PAR_BE3			(0x40)
#define GPIO_PAR_BE2			(0x10)
#define GPIO_PAR_BE1			(0x04)
#define GPIO_PAR_BE0			(0x01)

#define GPIO_PAR_CS5			(0x40)
#define GPIO_PAR_CS4			(0x10)
#define GPIO_PAR_CS1_MASK		(0xF3)
#define GPIO_PAR_CS1_CS1		(0x0C)
#define GPIO_PAR_CS1_SDCS1		(0x08)
#define GPIO_PAR_CS0_MASK		(0xFC)
#define GPIO_PAR_CS0_CS0		(0x03)
#define GPIO_PAR_CS0_CS4		(0x02)

#define GPIO_PAR_DSPIH_SIN_MASK		(0x3F)
#define GPIO_PAR_DSPIH_SIN		(0xC0)
#define GPIO_PAR_DSPIH_SIN_U2RXD	(0x80)
#define GPIO_PAR_DSPIH_SOUT_MASK	(0xCF)
#define GPIO_PAR_DSPIH_SOUT		(0x30)
#define GPIO_PAR_DSPIH_SOUT_U2TXD	(0x20)
#define GPIO_PAR_DSPIH_SCK_MASK		(0xF3)
#define GPIO_PAR_DSPIH_SCK		(0x0C)
#define GPIO_PAR_DSPIH_SCK_U2CTS	(0x08)
#define GPIO_PAR_DSPIH_PCS0_MASK	(0xFC)
#define GPIO_PAR_DSPIH_PCS0		(0x03)
#define GPIO_PAR_DSPIH_PCS0_U2RTS	(0x02)

#define GPIO_PAR_DSPIL_PCS1_MASK	(0x3F)
#define GPIO_PAR_DSPIL_PCS1		(0xC0)
#define GPIO_PAR_DSPIL_PCS2_MASK	(0xCF)
#define GPIO_PAR_DSPIL_PCS2		(0x30)
#define GPIO_PAR_DSPIL_PCS2_USBH_OC	(0x20)
#define GPIO_PAR_DSPIL_PCS3_MASK	(0xF3)
#define GPIO_PAR_DSPIL_PCS3		(0x0C)
#define GPIO_PAR_DSPIL_PCS3_USBH_EN	(0x08)

#define GPIO_PAR_FEC1_7W_FEC		(0x40)
#define GPIO_PAR_FEC1_RMII_FEC		(0x10)
#define GPIO_PAR_FEC0_7W_FEC		(0x04)
#define GPIO_PAR_FEC0_RMII_FEC		(0x01)

/* GPIO_PAR_FECI2C */
#define GPIO_PAR_FECI2C_RMII0_MASK	(0x3F)
#define GPIO_PAR_FECI2C_MDC0		(0x80)
#define GPIO_PAR_FECI2C_MDIO0		(0x40)
#define GPIO_PAR_FECI2C_RMII1_MASK	(0xCF)
#define GPIO_PAR_FECI2C_MDC1		(0x20)
#define GPIO_PAR_FECI2C_MDIO1		(0x10)
#define GPIO_PAR_FECI2C_SDA_MASK	(0xF3)
#define GPIO_PAR_FECI2C_SDA(x)		(((x) & 0x03) << 2)
#define GPIO_PAR_FECI2C_SDA_SDA		(0x0C)
#define GPIO_PAR_FECI2C_SDA_U2TXD	(0x08)
#define GPIO_PAR_FECI2C_SDA_MDIO1	(0x04)
#define GPIO_PAR_FECI2C_SCL_MASK	(0xFC)
#define GPIO_PAR_FECI2C_SCL(x)		((x) & 0x03)
#define GPIO_PAR_FECI2C_SCL_SCL		(0x03)
#define GPIO_PAR_FECI2C_SCL_U2RXD	(0x02)
#define GPIO_PAR_FECI2C_SCL_MDC1	(0x01)

#define GPIO_PAR_IRQ0H_IRQ07_MASK	(0x3F)
#define GPIO_PAR_IRQ0H_IRQ06_MASK	(0xCF)
#define GPIO_PAR_IRQ0H_IRQ06_USBCLKIN	(0x10)
#define GPIO_PAR_IRQ0H_IRQ04_MASK	(0xFC)
#define GPIO_PAR_IRQ0H_IRQ04_DREQ0	(0x02)

#define GPIO_PAR_IRQ0L_IRQ01_MASK	(0xF3)
#define GPIO_PAR_IRQ0L_IRQ01_DREQ1	(0x08)

#define GPIO_PAR_IRQ1H_IRQ17_DDATA3	(0x40)
#define GPIO_PAR_IRQ1H_IRQ16_DDATA2	(0x10)
#define GPIO_PAR_IRQ1H_IRQ15_DDATA1	(0x04)
#define GPIO_PAR_IRQ1H_IRQ14_DDATA0	(0x01)

#define GPIO_PAR_IRQ1L_IRQ13_PST3	(0x40)
#define GPIO_PAR_IRQ1L_IRQ12_PST2	(0x10)
#define GPIO_PAR_IRQ1L_IRQ11_PST1	(0x04)
#define GPIO_PAR_IRQ1L_IRQ10_PST0	(0x01)

#define GPIO_PAR_SIMP1H_DATA1_MASK	(0x3F)
#define GPIO_PAR_SIMP1H_DATA1_SIMDATA1	(0xC0)
#define GPIO_PAR_SIMP1H_DATA1_SSITXD	(0x80)
#define GPIO_PAR_SIMP1H_DATA1_U1TXD	(0x40)
#define GPIO_PAR_SIMP1H_VEN1_MASK	(0xCF)
#define GPIO_PAR_SIMP1H_VEN1_SIMVEN1	(0x30)
#define GPIO_PAR_SIMP1H_VEN1_SSIRXD	(0x20)
#define GPIO_PAR_SIMP1H_VEN1_U1RXD	(0x10)
#define GPIO_PAR_SIMP1H_RST1_MASK	(0xF3)
#define GPIO_PAR_SIMP1H_RST1_SIMRST1	(0x0C)
#define GPIO_PAR_SIMP1H_RST1_SSIFS	(0x08)
#define GPIO_PAR_SIMP1H_RST1_U1RTS	(0x04)
#define GPIO_PAR_SIMP1H_PD1_MASK	(0xFC)
#define GPIO_PAR_SIMP1H_PD1_SIMPD1	(0x03)
#define GPIO_PAR_SIMP1H_PD1_SSIBCLK	(0x02)
#define GPIO_PAR_SIMP1H_PD1_U1CTS	(0x01)

#define GPIO_PAR_SIMP1L_CLK_MASK	(0x3F)
#define GPIO_PAR_SIMP1L_CLK_CLK1	(0xC0)
#define GPIO_PAR_SIMP1L_CLK_SSIMCLK	(0x80)

#define GPIO_PAR_SIMP0_DATA0		(0x10)
#define GPIO_PAR_SIMP0_VEN0		(0x08)
#define GPIO_PAR_SIMP0_RST0		(0x04)
#define GPIO_PAR_SIMP0_PD0		(0x02)
#define GPIO_PAR_SIMP0_CLK0		(0x01)

#define GPIO_PAR_TIN3(x)		(((x) & 0x03) << 6)
#define GPIO_PAR_TIN2(x)		(((x) & 0x03) << 4)
#define GPIO_PAR_TIN1(x)		(((x) & 0x03) << 2)
#define GPIO_PAR_TIN0(x)		((x) & 0x03)
#define GPIO_PAR_TIN3_MASK		(0x3F)
#define GPIO_PAR_TIN3_TIN3		(0xC0)
#define GPIO_PAR_TIN3_TOUT3		(0x80)
#define GPIO_PAR_TIN3_IRQ03		(0x40)
#define GPIO_PAR_TIN2_MASK		(0xCF)
#define GPIO_PAR_TIN2_TIN2		(0x30)
#define GPIO_PAR_TIN2_TOUT2		(0x20)
#define GPIO_PAR_TIN2_IRQ02		(0x10)
#define GPIO_PAR_TIN1_MASK		(0xF3)
#define GPIO_PAR_TIN1_TIN1		(0x0C)
#define GPIO_PAR_TIN1_TOUT1		(0x08)
#define GPIO_PAR_TIN1_DACK1		(0x04)
#define GPIO_PAR_TIN0_MASK		(0xFC)
#define GPIO_PAR_TIN0_TIN0		(0x03)
#define GPIO_PAR_TIN0_TOUT0		(0x02)
#define GPIO_PAR_TIN0_CODEC_ALTCLK	(0x01)

#define GPIO_PAR_UART_U2TXD		(0x80)
#define GPIO_PAR_UART_U2RXD		(0x40)
#define GPIO_PAR_UART_U0TXD		(0x20)
#define GPIO_PAR_UART_U0RXD		(0x10)
#define GPIO_PAR_UART_RTS0(x)		(((x) & 0x03) << 2)
#define GPIO_PAR_UART_CTS0(x)		((x) & 0x03)
#define GPIO_PAR_UART_RTS0_MASK		(0xF3)
#define GPIO_PAR_UART_RTS0_U0RTS	(0x0C)
#define GPIO_PAR_UART_RTS0_USBO_VBOC	(0x08)
#define GPIO_PAR_UART_CTS0_MASK		(0xFC)
#define GPIO_PAR_UART_CTS0_U0CTS	(0x03)
#define GPIO_PAR_UART_CTS0_USB0_VBEN	(0x02)
#define GPIO_PAR_UART_CTS0_USB_PULLUP	(0x01)

#define GPIO_PAR_DEBUG_ALLPST		(0x80)

#define GPIO_PAR_SDHC_DATA3		(0x20)
#define GPIO_PAR_SDHC_DATA2		(0x10)
#define GPIO_PAR_SDHC_DATA1		(0x08)
#define GPIO_PAR_SDHC_DATA0		(0x04)
#define GPIO_PAR_SDHC_CMD		(0x02)
#define GPIO_PAR_SDHC_CLK		(0x01)

#define GPIO_PAR_SSIH_RXD(x)		(((x) & 0x03) << 6)
#define GPIO_PAR_SSIH_TXD(x)		(((x) & 0x03) << 4)
#define GPIO_PAR_SSIH_FS(x)		(((x) & 0x03) << 2)
#define GPIO_PAR_SSIH_MCLK(x)		((x) & 0x03)
#define GPIO_PAR_SSIH_RXD_MASK		(0x3F)
#define GPIO_PAR_SSIH_RXD_SSIRXD	(0xC0)
#define GPIO_PAR_SSIH_RXD_U1RXD		(0x40)
#define GPIO_PAR_SSIH_TXD_MASK		(0xCF)
#define GPIO_PAR_SSIH_TXD_SSIRXD	(0x30)
#define GPIO_PAR_SSIH_TXD_U1TXD		(0x10)
#define GPIO_PAR_SSIH_FS_MASK		(0xF3)
#define GPIO_PAR_SSIH_FS_SSIFS		(0x0C)
#define GPIO_PAR_SSIH_FS_U1RTS		(0x04)
#define GPIO_PAR_SSIH_MCLK_MASK		(0xFC)
#define GPIO_PAR_SSIH_MCLK_SSIMCLK	(0x03)
#define GPIO_PAR_SSIH_MCLK_SSICLKIN	(0x01)

#define GPIO_PAR_SSIL_MASK		(0x3F)
#define GPIO_PAR_SSIL_BCLK		(0xC0)
#define GPIO_PAR_SSIL_U1CTS		(0x40)

#define GPIO_MSCR_MSCR1(x)		(((x) & 0x07) << 5)
#define GPIO_MSCR_MSCR2(x)		(((x) & 0x07) << 5)
#define GPIO_MSCR_MSCR3(x)		(((x) & 0x07) << 5)
#define GPIO_MSCR_MSCR4(x)		(((x) & 0x07) << 5)
#define GPIO_MSCR_MSCRn_MASK		(0x1F)
#define GPIO_MSCR_MSCRn_SDR		(0xE0)
#define GPIO_MSCR_MSCRn_25VDDR		(0x60)
#define GPIO_MSCR_MSCRn_18VDDR_FULL	(0x20)
#define GPIO_MSCR_MSCRn_18VDDR_HALF	(0x00)

#define GPIO_MSCR_MSCR5(x)		(((x) & 0x07) << 2)
#define GPIO_MSCR_MSCR5_MASK		(0xE3)
#define GPIO_MSCR_MSCR5_SDR		(0x1C)
#define GPIO_MSCR_MSCR5_25VDDR		(0x0C)
#define GPIO_MSCR_MSCR5_18VDDR_FULL	(0x04)
#define GPIO_MSCR_MSCR5_18VDDR_HALF	(0x00)

#define GPIO_SRCR_DSPI_MASK		(0xFC)
#define GPIO_SRCR_DSPI(x)		((x) & 0x03)
#define GPIO_SRCR_I2C_MASK		(0xFC)
#define GPIO_SRCR_I2C(x)		((x) & 0x03)
#define GPIO_SRCR_IRQ_IRQ0_MASK		(0xF3)
#define GPIO_SRCR_IRQ_IRQ0(x)		(((x) & 0x03) << 2)
#define GPIO_SRCR_IRQ_IRQ1DBG_MASK	(0xFC)
#define GPIO_SRCR_IRQ_IRQ1DBG(x)	((x) & 0x03)
#define GPIO_SRCR_SIM_SIMP0_MASK	(0xF3)
#define GPIO_SRCR_SIM_SIMP0(x)		(((x) & 0x03) << 2)
#define GPIO_SRCR_SIM_SIMP1_MASK	(0xFC)
#define GPIO_SRCR_SIM_SIMP1(x)		((x) & 0x03)
#define GPIO_SRCR_TIMER_MASK		(0xFC)
#define GPIO_SRCR_TIMER(x)		((x) & 0x03)
#define GPIO_SRCR_UART2_MASK		(0xF3)
#define GPIO_SRCR_UART2(x)		(((x) & 0x03) << 2)
#define GPIO_SRCR_UART0_MASK		(0xFC)
#define GPIO_SRCR_UART0(x)		((x) & 0x03)
#define GPIO_SRCR_SDHC_MASK		(0xFC)
#define GPIO_SRCR_SDHC(x)		((x) & 0x03)
#define GPIO_SRCR_SSI_MASK		(0xFC)
#define GPIO_SRCR_SSI(x)		((x) & 0x03)

#define SRCR_HIGHEST			(0x03)
#define SRCR_HIGH			(0x02)
#define SRCR_LOW			(0x01)
#define SRCR_LOWEST			(0x00)

#define GPIO_DSCR_FEC_RMIICLK_MASK	(0xCF)
#define GPIO_DSCR_FEC_RMIICLK(x)	(((x) & 0x03) << 4)
#define GPIO_DSCR_FEC_RMII0_MASK	(0xF3)
#define GPIO_DSCR_FEC_RMII0(x)		(((x) & 0x03) << 2)
#define GPIO_DSCR_FEC_RMII1_MASK	(0xFC)
#define GPIO_DSCR_FEC_RMII1(x)		((x) & 0x03)

#define DSCR_50PF			(0x03)
#define DSCR_30PF			(0x02)
#define DSCR_20PF			(0x01)
#define DSCR_10PF			(0x00)

#define GPIO_PCRH_DSPI_PCS0_PULLUP_EN	(0x80)
#define GPIO_PCRH_SIM_VEN1_PULLUP_EN	(0x40)
#define GPIO_PCRH_SIM_VEN1_PULLUP	(0x20)
#define GPIO_PCRH_SIM_DATA1_PULLUP_EN	(0x10)
#define GPIO_PCRH_SIM_DATA1_PULLUP	(0x08)
#define GPIO_PCRH_SSI_PULLUP_EN		(0x02)
#define GPIO_PCRH_SSI_PULLUP		(0x01)

#define GPIO_PCRL_SDHC_DATA3_PULLUP_EN	(0x80)
#define GPIO_PCRL_SDHC_DATA3_PULLUP	(0x40)
#define GPIO_PCRL_SDHC_DATA2_PULLUP_EN	(0x20)
#define GPIO_PCRL_SDHC_DATA1_PULLUP_EN	(0x10)
#define GPIO_PCRL_SDHC_DATA0_PULLUP_EN	(0x08)
#define GPIO_PCRL_SDHC_CMD_PULLUP_EN	(0x04)

/* *** Phase Locked Loop (PLL) *** */
#define PLL_PCR_LOC_IRQ			(0x00040000)
#define PLL_PCR_LOC_RE			(0x00020000)
#define PLL_PCR_LOC_EN			(0x00010000)
#define PLL_PCR_LOL_IRQ			(0x00004000)
#define PLL_PCR_LOL_RE			(0x00002000)
#define PLL_PCR_LOL_EN			(0x00001000)
#define PLL_PCR_REFDIV_MASK		(0xFFFFF8FF)
#define PLL_PCR_REFDIV(x)		(((x) & 0x07) << 8)
#define PLL_PCR_FBDIV_MASK		(0xFFFFFFC0)
#define PLL_PCR_FBDIV(x)		((x) & 0x3F)

#define PLL_PDR_OUTDIV4_MASK		(0x0FFF)
#define PLL_PDR_OUTDIV4(x)		(((x) & 0x0000000F) << 12)
#define PLL_PDR_OUTDIV3_MASK		(0xF0FF)
#define PLL_PDR_OUTDIV3(x)		(((x) & 0x0000000F) << 8)
#define PLL_PDR_OUTDIV2_MASK		(0xFF0F)
#define PLL_PDR_OUTDIV2(x)		(((x) & 0x0000000F) << 4)
#define PLL_PDR_OUTDIV1_MASK		(0xFFF0)
#define PLL_PDR_OUTDIV1(x)		((x) & 0x0000000F)
#define PLL_PDR_USB(x)			PLL_PDR_OUTDIV4(x)
#define PLL_PDR_SDRAM(x)		PLL_PDR_OUTDIV3(x)
#define PLL_PDR_FB(x)			PLL_PDR_OUTDIV2(x)
#define PLL_PDR_CPU(x)			PLL_PDR_OUTDIV1(x)

#define PLL_PSR_LOCF			(0x00000200)
#define PLL_PSR_LOC			(0x00000100)
#define PLL_PSR_LOLF			(0x00000040)
#define PLL_PSR_LOCKS			(0x00000020)
#define PLL_PSR_LOCK			(0x00000010)
#define PLL_PSR_MODE(x)			((x) & 0x07)

/* *** Real Time Clock *** */
#define RTC_OCEN_OSCBYP			(0x00000010)
#define RTC_OCEN_CLKEN			(0x00000008)

/* SDRAM */
#define SDRAMC_SDCR_CKE			(0x40000000)
#define SDRAMC_SDCR_REF			(0x10000000)

#endif				/* m5301x_h */
