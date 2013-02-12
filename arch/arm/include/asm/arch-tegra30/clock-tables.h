/*
 * Copyright (c) 2010-2012, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Tegra30 clock PLL tables */

#ifndef _TEGRA30_CLOCK_TABLES_H_
#define _TEGRA30_CLOCK_TABLES_H_

/* The PLLs supported by the hardware */
enum clock_id {
	CLOCK_ID_FIRST,
	CLOCK_ID_CGENERAL = CLOCK_ID_FIRST,
	CLOCK_ID_MEMORY,
	CLOCK_ID_PERIPH,
	CLOCK_ID_AUDIO,
	CLOCK_ID_USB,
	CLOCK_ID_DISPLAY,

	/* now the simple ones */
	CLOCK_ID_FIRST_SIMPLE,
	CLOCK_ID_XCPU = CLOCK_ID_FIRST_SIMPLE,
	CLOCK_ID_EPCI,
	CLOCK_ID_SFROM32KHZ,

	/* These are the base clocks (inputs to the Tegra SOC) */
	CLOCK_ID_32KHZ,
	CLOCK_ID_OSC,

	CLOCK_ID_COUNT,	/* number of PLLs */
	CLOCK_ID_DISPLAY2,	/* Tegra3, placeholder */
	CLOCK_ID_NONE = -1,
};

/* The clocks supported by the hardware */
enum periph_id {
	PERIPH_ID_FIRST,

	/* Low word: 31:0 */
	PERIPH_ID_CPU = PERIPH_ID_FIRST,
	PERIPH_ID_COP,
	PERIPH_ID_TRIGSYS,
	PERIPH_ID_RESERVED3,
	PERIPH_ID_RESERVED4,
	PERIPH_ID_TMR,
	PERIPH_ID_UART1,
	PERIPH_ID_UART2,

	/* 8 */
	PERIPH_ID_GPIO,
	PERIPH_ID_SDMMC2,
	PERIPH_ID_SPDIF,
	PERIPH_ID_I2S1,
	PERIPH_ID_I2C1,
	PERIPH_ID_NDFLASH,
	PERIPH_ID_SDMMC1,
	PERIPH_ID_SDMMC4,

	/* 16 */
	PERIPH_ID_RESERVED16,
	PERIPH_ID_PWM,
	PERIPH_ID_I2S2,
	PERIPH_ID_EPP,
	PERIPH_ID_VI,
	PERIPH_ID_2D,
	PERIPH_ID_USBD,
	PERIPH_ID_ISP,

	/* 24 */
	PERIPH_ID_3D,
	PERIPH_ID_RESERVED24,
	PERIPH_ID_DISP2,
	PERIPH_ID_DISP1,
	PERIPH_ID_HOST1X,
	PERIPH_ID_VCP,
	PERIPH_ID_I2S0,
	PERIPH_ID_CACHE2,

	/* Middle word: 63:32 */
	PERIPH_ID_MEM,
	PERIPH_ID_AHBDMA,
	PERIPH_ID_APBDMA,
	PERIPH_ID_RESERVED35,
	PERIPH_ID_KBC,
	PERIPH_ID_STAT_MON,
	PERIPH_ID_PMC,
	PERIPH_ID_FUSE,

	/* 40 */
	PERIPH_ID_KFUSE,
	PERIPH_ID_SBC1,
	PERIPH_ID_SNOR,
	PERIPH_ID_RESERVED43,
	PERIPH_ID_SBC2,
	PERIPH_ID_RESERVED45,
	PERIPH_ID_SBC3,
	PERIPH_ID_DVC_I2C,

	/* 48 */
	PERIPH_ID_DSI,
	PERIPH_ID_TVO,
	PERIPH_ID_MIPI,
	PERIPH_ID_HDMI,
	PERIPH_ID_CSI,
	PERIPH_ID_TVDAC,
	PERIPH_ID_I2C2,
	PERIPH_ID_UART3,

	/* 56 */
	PERIPH_ID_RESERVED56,
	PERIPH_ID_EMC,
	PERIPH_ID_USB2,
	PERIPH_ID_USB3,
	PERIPH_ID_MPE,
	PERIPH_ID_VDE,
	PERIPH_ID_BSEA,
	PERIPH_ID_BSEV,

	/* Upper word 95:64 */
	PERIPH_ID_SPEEDO,
	PERIPH_ID_UART4,
	PERIPH_ID_UART5,
	PERIPH_ID_I2C3,
	PERIPH_ID_SBC4,
	PERIPH_ID_SDMMC3,
	PERIPH_ID_PCIE,
	PERIPH_ID_OWR,

	/* 72 */
	PERIPH_ID_AFI,
	PERIPH_ID_CORESIGHT,
	PERIPH_ID_PCIEXCLK,
	PERIPH_ID_AVPUCQ,
	PERIPH_ID_RESERVED76,
	PERIPH_ID_RESERVED77,
	PERIPH_ID_RESERVED78,
	PERIPH_ID_DTV,

	/* 80 */
	PERIPH_ID_NANDSPEED,
	PERIPH_ID_I2CSLOW,
	PERIPH_ID_DSIB,
	PERIPH_ID_RESERVED83,
	PERIPH_ID_IRAMA,
	PERIPH_ID_IRAMB,
	PERIPH_ID_IRAMC,
	PERIPH_ID_IRAMD,

	/* 88 */
	PERIPH_ID_CRAM2,
	PERIPH_ID_RESERVED89,
	PERIPH_ID_MDOUBLER,
	PERIPH_ID_RESERVED91,
	PERIPH_ID_SUSOUT,
	PERIPH_ID_RESERVED93,
	PERIPH_ID_RESERVED94,
	PERIPH_ID_RESERVED95,

	PERIPH_ID_VW_FIRST,
	/* V word: 31:0 */
	PERIPH_ID_CPUG = PERIPH_ID_VW_FIRST,
	PERIPH_ID_CPULP,
	PERIPH_ID_3D2,
	PERIPH_ID_MSELECT,
	PERIPH_ID_TSENSOR,
	PERIPH_ID_I2S3,
	PERIPH_ID_I2S4,
	PERIPH_ID_I2C4,

	/* 08 */
	PERIPH_ID_SBC5,
	PERIPH_ID_SBC6,
	PERIPH_ID_AUDIO,
	PERIPH_ID_APBIF,
	PERIPH_ID_DAM0,
	PERIPH_ID_DAM1,
	PERIPH_ID_DAM2,
	PERIPH_ID_HDA2CODEC2X,

	/* 16 */
	PERIPH_ID_ATOMICS,
	PERIPH_ID_EX_RESERVED17,
	PERIPH_ID_EX_RESERVED18,
	PERIPH_ID_EX_RESERVED19,
	PERIPH_ID_EX_RESERVED20,
	PERIPH_ID_EX_RESERVED21,
	PERIPH_ID_EX_RESERVED22,
	PERIPH_ID_ACTMON,

	/* 24 */
	PERIPH_ID_EX_RESERVED24,
	PERIPH_ID_EX_RESERVED25,
	PERIPH_ID_EX_RESERVED26,
	PERIPH_ID_EX_RESERVED27,
	PERIPH_ID_SATA,
	PERIPH_ID_HDA,
	PERIPH_ID_EX_RESERVED30,
	PERIPH_ID_EX_RESERVED31,

	/* W word: 31:0 */
	PERIPH_ID_HDA2HDMICODEC,
	PERIPH_ID_SATACOLD,
	PERIPH_ID_RESERVED0_PCIERX0,
	PERIPH_ID_RESERVED1_PCIERX1,
	PERIPH_ID_RESERVED2_PCIERX2,
	PERIPH_ID_RESERVED3_PCIERX3,
	PERIPH_ID_RESERVED4_PCIERX4,
	PERIPH_ID_RESERVED5_PCIERX5,

	/* 40 */
	PERIPH_ID_CEC,
	PERIPH_ID_RESERVED6_PCIE2,
	PERIPH_ID_RESERVED7_EMC,
	PERIPH_ID_RESERVED8_HDMI,
	PERIPH_ID_RESERVED9_SATA,
	PERIPH_ID_RESERVED10_MIPI,
	PERIPH_ID_EX_RESERVED46,
	PERIPH_ID_EX_RESERVED47,

	PERIPH_ID_COUNT,
	PERIPH_ID_NONE = -1,
};

enum pll_out_id {
	PLL_OUT1,
	PLL_OUT2,
	PLL_OUT3,
	PLL_OUT4
};

/*
 * Clock peripheral IDs which sadly don't match up with PERIPH_ID. we want
 * callers to use the PERIPH_ID for all access to peripheral clocks to avoid
 * confusion bewteen PERIPH_ID_... and PERIPHC_...
 *
 * We don't call this CLOCK_PERIPH_ID or PERIPH_CLOCK_ID as it would just be
 * confusing.
 */
enum periphc_internal_id {
	/* 0x00 */
	PERIPHC_I2S1,
	PERIPHC_I2S2,
	PERIPHC_SPDIF_OUT,
	PERIPHC_SPDIF_IN,
	PERIPHC_PWM,
	PERIPHC_05h,
	PERIPHC_SBC2,
	PERIPHC_SBC3,

	/* 0x08 */
	PERIPHC_08h,
	PERIPHC_I2C1,
	PERIPHC_DVC_I2C,
	PERIPHC_0bh,
	PERIPHC_0ch,
	PERIPHC_SBC1,
	PERIPHC_DISP1,
	PERIPHC_DISP2,

	/* 0x10 */
	PERIPHC_CVE,
	PERIPHC_11h,
	PERIPHC_VI,
	PERIPHC_13h,
	PERIPHC_SDMMC1,
	PERIPHC_SDMMC2,
	PERIPHC_G3D,
	PERIPHC_G2D,

	/* 0x18 */
	PERIPHC_NDFLASH,
	PERIPHC_SDMMC4,
	PERIPHC_VFIR,
	PERIPHC_EPP,
	PERIPHC_MPE,
	PERIPHC_MIPI,
	PERIPHC_UART1,
	PERIPHC_UART2,

	/* 0x20 */
	PERIPHC_HOST1X,
	PERIPHC_21h,
	PERIPHC_TVO,
	PERIPHC_HDMI,
	PERIPHC_24h,
	PERIPHC_TVDAC,
	PERIPHC_I2C2,
	PERIPHC_EMC,

	/* 0x28 */
	PERIPHC_UART3,
	PERIPHC_29h,
	PERIPHC_VI_SENSOR,
	PERIPHC_2bh,
	PERIPHC_2ch,
	PERIPHC_SBC4,
	PERIPHC_I2C3,
	PERIPHC_SDMMC3,

	/* 0x30 */
	PERIPHC_UART4,
	PERIPHC_UART5,
	PERIPHC_VDE,
	PERIPHC_OWR,
	PERIPHC_NOR,
	PERIPHC_CSITE,
	PERIPHC_I2S0,
	PERIPHC_37h,

	PERIPHC_VW_FIRST,
	/* 0x38 */
	PERIPHC_G3D2 = PERIPHC_VW_FIRST,
	PERIPHC_MSELECT,
	PERIPHC_TSENSOR,
	PERIPHC_I2S3,
	PERIPHC_I2S4,
	PERIPHC_I2C4,
	PERIPHC_SBC5,
	PERIPHC_SBC6,

	/* 0x40 */
	PERIPHC_AUDIO,
	PERIPHC_41h,
	PERIPHC_DAM0,
	PERIPHC_DAM1,
	PERIPHC_DAM2,
	PERIPHC_HDA2CODEC2X,
	PERIPHC_ACTMON,
	PERIPHC_EXTPERIPH1,

	/* 0x48 */
	PERIPHC_EXTPERIPH2,
	PERIPHC_EXTPERIPH3,
	PERIPHC_NANDSPEED,
	PERIPHC_I2CSLOW,
	PERIPHC_SYS,
	PERIPHC_SPEEDO,
	PERIPHC_4eh,
	PERIPHC_4fh,

	/* 0x50 */
	PERIPHC_50h,
	PERIPHC_51h,
	PERIPHC_52h,
	PERIPHC_53h,
	PERIPHC_SATAOOB,
	PERIPHC_SATA,
	PERIPHC_HDA,

	PERIPHC_COUNT,

	PERIPHC_NONE = -1,
};

/* Converts a clock number to a clock register: 0=L, 1=H, 2=U, 0=V, 1=W */
#define PERIPH_REG(id) \
	(id < PERIPH_ID_VW_FIRST) ? \
		((id) >> 5) : ((id - PERIPH_ID_VW_FIRST) >> 5)

/* Mask value for a clock (within PERIPH_REG(id)) */
#define PERIPH_MASK(id) (1 << ((id) & 0x1f))

/* return 1 if a PLL ID is in range */
#define clock_id_is_pll(id) ((id) >= CLOCK_ID_FIRST && (id) < CLOCK_ID_COUNT)

/* return 1 if a peripheral ID is in range */
#define clock_periph_id_isvalid(id) ((id) >= PERIPH_ID_FIRST && \
		(id) < PERIPH_ID_COUNT)

#endif	/* _TEGRA30_CLOCK_TABLES_H_ */
