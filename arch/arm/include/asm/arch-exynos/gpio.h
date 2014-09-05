/*
 * (C) Copyright 2010 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ASM_ARCH_GPIO_H
#define __ASM_ARCH_GPIO_H

#ifndef __ASSEMBLY__
struct s5p_gpio_bank {
	unsigned int	con;
	unsigned int	dat;
	unsigned int	pull;
	unsigned int	drv;
	unsigned int	pdn_con;
	unsigned int	pdn_pull;
	unsigned char	res1[8];
};

/* GPIO pins per bank  */
#define GPIO_PER_BANK 8

/* A list of valid GPIO numbers for the asm-generic/gpio.h interface */
enum exynos4_gpio_pin {
	/* GPIO_PART1_STARTS */
	EXYNOS4_GPIO_A00,		/* 0 */
	EXYNOS4_GPIO_A01,
	EXYNOS4_GPIO_A02,
	EXYNOS4_GPIO_A03,
	EXYNOS4_GPIO_A04,
	EXYNOS4_GPIO_A05,
	EXYNOS4_GPIO_A06,
	EXYNOS4_GPIO_A07,
	EXYNOS4_GPIO_A10,		/* 8 */
	EXYNOS4_GPIO_A11,
	EXYNOS4_GPIO_A12,
	EXYNOS4_GPIO_A13,
	EXYNOS4_GPIO_A14,
	EXYNOS4_GPIO_A15,
	EXYNOS4_GPIO_A16,
	EXYNOS4_GPIO_A17,
	EXYNOS4_GPIO_B0,		/* 16 0x10 */
	EXYNOS4_GPIO_B1,
	EXYNOS4_GPIO_B2,
	EXYNOS4_GPIO_B3,
	EXYNOS4_GPIO_B4,
	EXYNOS4_GPIO_B5,
	EXYNOS4_GPIO_B6,
	EXYNOS4_GPIO_B7,
	EXYNOS4_GPIO_C00,		/* 24 0x18 */
	EXYNOS4_GPIO_C01,
	EXYNOS4_GPIO_C02,
	EXYNOS4_GPIO_C03,
	EXYNOS4_GPIO_C04,
	EXYNOS4_GPIO_C05,
	EXYNOS4_GPIO_C06,
	EXYNOS4_GPIO_C07,
	EXYNOS4_GPIO_C10,		/* 32 0x20*/
	EXYNOS4_GPIO_C11,
	EXYNOS4_GPIO_C12,
	EXYNOS4_GPIO_C13,
	EXYNOS4_GPIO_C14,
	EXYNOS4_GPIO_C15,
	EXYNOS4_GPIO_C16,
	EXYNOS4_GPIO_C17,
	EXYNOS4_GPIO_D00,		/* 40 0x28 */
	EXYNOS4_GPIO_D01,
	EXYNOS4_GPIO_D02,
	EXYNOS4_GPIO_D03,
	EXYNOS4_GPIO_D04,
	EXYNOS4_GPIO_D05,
	EXYNOS4_GPIO_D06,
	EXYNOS4_GPIO_D07,
	EXYNOS4_GPIO_D10,		/* 48 0x30 */
	EXYNOS4_GPIO_D11,
	EXYNOS4_GPIO_D12,
	EXYNOS4_GPIO_D13,
	EXYNOS4_GPIO_D14,
	EXYNOS4_GPIO_D15,
	EXYNOS4_GPIO_D16,
	EXYNOS4_GPIO_D17,
	EXYNOS4_GPIO_E00,		/* 56 0x38 */
	EXYNOS4_GPIO_E01,
	EXYNOS4_GPIO_E02,
	EXYNOS4_GPIO_E03,
	EXYNOS4_GPIO_E04,
	EXYNOS4_GPIO_E05,
	EXYNOS4_GPIO_E06,
	EXYNOS4_GPIO_E07,
	EXYNOS4_GPIO_E10,		/* 64 0x40 */
	EXYNOS4_GPIO_E11,
	EXYNOS4_GPIO_E12,
	EXYNOS4_GPIO_E13,
	EXYNOS4_GPIO_E14,
	EXYNOS4_GPIO_E15,
	EXYNOS4_GPIO_E16,
	EXYNOS4_GPIO_E17,
	EXYNOS4_GPIO_E20,		/* 72 0x48 */
	EXYNOS4_GPIO_E21,
	EXYNOS4_GPIO_E22,
	EXYNOS4_GPIO_E23,
	EXYNOS4_GPIO_E24,
	EXYNOS4_GPIO_E25,
	EXYNOS4_GPIO_E26,
	EXYNOS4_GPIO_E27,
	EXYNOS4_GPIO_E30,		/* 80 0x50 */
	EXYNOS4_GPIO_E31,
	EXYNOS4_GPIO_E32,
	EXYNOS4_GPIO_E33,
	EXYNOS4_GPIO_E34,
	EXYNOS4_GPIO_E35,
	EXYNOS4_GPIO_E36,
	EXYNOS4_GPIO_E37,
	EXYNOS4_GPIO_E40,		/* 88 0x58 */
	EXYNOS4_GPIO_E41,
	EXYNOS4_GPIO_E42,
	EXYNOS4_GPIO_E43,
	EXYNOS4_GPIO_E44,
	EXYNOS4_GPIO_E45,
	EXYNOS4_GPIO_E46,
	EXYNOS4_GPIO_E47,
	EXYNOS4_GPIO_F00,		/* 96 0x60 */
	EXYNOS4_GPIO_F01,
	EXYNOS4_GPIO_F02,
	EXYNOS4_GPIO_F03,
	EXYNOS4_GPIO_F04,
	EXYNOS4_GPIO_F05,
	EXYNOS4_GPIO_F06,
	EXYNOS4_GPIO_F07,
	EXYNOS4_GPIO_F10,		/* 104 0x68 */
	EXYNOS4_GPIO_F11,
	EXYNOS4_GPIO_F12,
	EXYNOS4_GPIO_F13,
	EXYNOS4_GPIO_F14,
	EXYNOS4_GPIO_F15,
	EXYNOS4_GPIO_F16,
	EXYNOS4_GPIO_F17,
	EXYNOS4_GPIO_F20,		/* 112 0x70 */
	EXYNOS4_GPIO_F21,
	EXYNOS4_GPIO_F22,
	EXYNOS4_GPIO_F23,
	EXYNOS4_GPIO_F24,
	EXYNOS4_GPIO_F25,
	EXYNOS4_GPIO_F26,
	EXYNOS4_GPIO_F27,
	EXYNOS4_GPIO_F30,		/* 120 0x78 */
	EXYNOS4_GPIO_F31,
	EXYNOS4_GPIO_F32,
	EXYNOS4_GPIO_F33,
	EXYNOS4_GPIO_F34,
	EXYNOS4_GPIO_F35,
	EXYNOS4_GPIO_F36,
	EXYNOS4_GPIO_F37,

	/* GPIO_PART2_STARTS */
	EXYNOS4_GPIO_MAX_PORT_PART_1,	/* 128 0x80 */
	EXYNOS4_GPIO_J00 = EXYNOS4_GPIO_MAX_PORT_PART_1,
	EXYNOS4_GPIO_J01,
	EXYNOS4_GPIO_J02,
	EXYNOS4_GPIO_J03,
	EXYNOS4_GPIO_J04,
	EXYNOS4_GPIO_J05,
	EXYNOS4_GPIO_J06,
	EXYNOS4_GPIO_J07,
	EXYNOS4_GPIO_J10,		/* 136 0x88 */
	EXYNOS4_GPIO_J11,
	EXYNOS4_GPIO_J12,
	EXYNOS4_GPIO_J13,
	EXYNOS4_GPIO_J14,
	EXYNOS4_GPIO_J15,
	EXYNOS4_GPIO_J16,
	EXYNOS4_GPIO_J17,
	EXYNOS4_GPIO_K00,		/* 144 0x90 */
	EXYNOS4_GPIO_K01,
	EXYNOS4_GPIO_K02,
	EXYNOS4_GPIO_K03,
	EXYNOS4_GPIO_K04,
	EXYNOS4_GPIO_K05,
	EXYNOS4_GPIO_K06,
	EXYNOS4_GPIO_K07,
	EXYNOS4_GPIO_K10,		/* 152 0x98 */
	EXYNOS4_GPIO_K11,
	EXYNOS4_GPIO_K12,
	EXYNOS4_GPIO_K13,
	EXYNOS4_GPIO_K14,
	EXYNOS4_GPIO_K15,
	EXYNOS4_GPIO_K16,
	EXYNOS4_GPIO_K17,
	EXYNOS4_GPIO_K20,		/* 160 0xA0 */
	EXYNOS4_GPIO_K21,
	EXYNOS4_GPIO_K22,
	EXYNOS4_GPIO_K23,
	EXYNOS4_GPIO_K24,
	EXYNOS4_GPIO_K25,
	EXYNOS4_GPIO_K26,
	EXYNOS4_GPIO_K27,
	EXYNOS4_GPIO_K30,		/* 168 0xA8 */
	EXYNOS4_GPIO_K31,
	EXYNOS4_GPIO_K32,
	EXYNOS4_GPIO_K33,
	EXYNOS4_GPIO_K34,
	EXYNOS4_GPIO_K35,
	EXYNOS4_GPIO_K36,
	EXYNOS4_GPIO_K37,
	EXYNOS4_GPIO_L00,		/* 176 0xB0 */
	EXYNOS4_GPIO_L01,
	EXYNOS4_GPIO_L02,
	EXYNOS4_GPIO_L03,
	EXYNOS4_GPIO_L04,
	EXYNOS4_GPIO_L05,
	EXYNOS4_GPIO_L06,
	EXYNOS4_GPIO_L07,
	EXYNOS4_GPIO_L10,		/* 184 0xB8 */
	EXYNOS4_GPIO_L11,
	EXYNOS4_GPIO_L12,
	EXYNOS4_GPIO_L13,
	EXYNOS4_GPIO_L14,
	EXYNOS4_GPIO_L15,
	EXYNOS4_GPIO_L16,
	EXYNOS4_GPIO_L17,
	EXYNOS4_GPIO_L20,		/* 192 0xC0 */
	EXYNOS4_GPIO_L21,
	EXYNOS4_GPIO_L22,
	EXYNOS4_GPIO_L23,
	EXYNOS4_GPIO_L24,
	EXYNOS4_GPIO_L25,
	EXYNOS4_GPIO_L26,
	EXYNOS4_GPIO_L27,
	EXYNOS4_GPIO_Y00,		/* 200 0xC8 */
	EXYNOS4_GPIO_Y01,
	EXYNOS4_GPIO_Y02,
	EXYNOS4_GPIO_Y03,
	EXYNOS4_GPIO_Y04,
	EXYNOS4_GPIO_Y05,
	EXYNOS4_GPIO_Y06,
	EXYNOS4_GPIO_Y07,
	EXYNOS4_GPIO_Y10,		/* 208 0xD0 */
	EXYNOS4_GPIO_Y11,
	EXYNOS4_GPIO_Y12,
	EXYNOS4_GPIO_Y13,
	EXYNOS4_GPIO_Y14,
	EXYNOS4_GPIO_Y15,
	EXYNOS4_GPIO_Y16,
	EXYNOS4_GPIO_Y17,
	EXYNOS4_GPIO_Y20,		/* 216 0xD8 */
	EXYNOS4_GPIO_Y21,
	EXYNOS4_GPIO_Y22,
	EXYNOS4_GPIO_Y23,
	EXYNOS4_GPIO_Y24,
	EXYNOS4_GPIO_Y25,
	EXYNOS4_GPIO_Y26,
	EXYNOS4_GPIO_Y27,
	EXYNOS4_GPIO_Y30,		/* 224 0xE0 */
	EXYNOS4_GPIO_Y31,
	EXYNOS4_GPIO_Y32,
	EXYNOS4_GPIO_Y33,
	EXYNOS4_GPIO_Y34,
	EXYNOS4_GPIO_Y35,
	EXYNOS4_GPIO_Y36,
	EXYNOS4_GPIO_Y37,
	EXYNOS4_GPIO_Y40,		/* 232 0xE8 */
	EXYNOS4_GPIO_Y41,
	EXYNOS4_GPIO_Y42,
	EXYNOS4_GPIO_Y43,
	EXYNOS4_GPIO_Y44,
	EXYNOS4_GPIO_Y45,
	EXYNOS4_GPIO_Y46,
	EXYNOS4_GPIO_Y47,
	EXYNOS4_GPIO_Y50,		/* 240 0xF0 */
	EXYNOS4_GPIO_Y51,
	EXYNOS4_GPIO_Y52,
	EXYNOS4_GPIO_Y53,
	EXYNOS4_GPIO_Y54,
	EXYNOS4_GPIO_Y55,
	EXYNOS4_GPIO_Y56,
	EXYNOS4_GPIO_Y57,
	EXYNOS4_GPIO_Y60,		/* 248 0xF8 */
	EXYNOS4_GPIO_Y61,
	EXYNOS4_GPIO_Y62,
	EXYNOS4_GPIO_Y63,
	EXYNOS4_GPIO_Y64,
	EXYNOS4_GPIO_Y65,
	EXYNOS4_GPIO_Y66,
	EXYNOS4_GPIO_Y67,
	EXYNOS4_GPIO_X00 = 896,		/* 896 0x380 */
	EXYNOS4_GPIO_X01,
	EXYNOS4_GPIO_X02,
	EXYNOS4_GPIO_X03,
	EXYNOS4_GPIO_X04,
	EXYNOS4_GPIO_X05,
	EXYNOS4_GPIO_X06,
	EXYNOS4_GPIO_X07,
	EXYNOS4_GPIO_X10,		/* 904 0x388 */
	EXYNOS4_GPIO_X11,
	EXYNOS4_GPIO_X12,
	EXYNOS4_GPIO_X13,
	EXYNOS4_GPIO_X14,
	EXYNOS4_GPIO_X15,
	EXYNOS4_GPIO_X16,
	EXYNOS4_GPIO_X17,
	EXYNOS4_GPIO_X20,		/* 912 0x390 */
	EXYNOS4_GPIO_X21,
	EXYNOS4_GPIO_X22,
	EXYNOS4_GPIO_X23,
	EXYNOS4_GPIO_X24,
	EXYNOS4_GPIO_X25,
	EXYNOS4_GPIO_X26,
	EXYNOS4_GPIO_X27,
	EXYNOS4_GPIO_X30,		/* 920 0x398 */
	EXYNOS4_GPIO_X31,
	EXYNOS4_GPIO_X32,
	EXYNOS4_GPIO_X33,
	EXYNOS4_GPIO_X34,
	EXYNOS4_GPIO_X35,
	EXYNOS4_GPIO_X36,
	EXYNOS4_GPIO_X37,

	/* GPIO_PART3_STARTS */
	EXYNOS4_GPIO_MAX_PORT_PART_2,	/* 928 0x3A0 */
	EXYNOS4_GPIO_Z0 = EXYNOS4_GPIO_MAX_PORT_PART_2,
	EXYNOS4_GPIO_Z1,
	EXYNOS4_GPIO_Z2,
	EXYNOS4_GPIO_Z3,
	EXYNOS4_GPIO_Z4,
	EXYNOS4_GPIO_Z5,
	EXYNOS4_GPIO_Z6,
	EXYNOS4_GPIO_Z7,

	EXYNOS4_GPIO_MAX_PORT
};

enum exynos4X12_gpio_pin {
	/* GPIO_PART1_STARTS */
	EXYNOS4X12_GPIO_A00,		/* 0 */
	EXYNOS4X12_GPIO_A01,
	EXYNOS4X12_GPIO_A02,
	EXYNOS4X12_GPIO_A03,
	EXYNOS4X12_GPIO_A04,
	EXYNOS4X12_GPIO_A05,
	EXYNOS4X12_GPIO_A06,
	EXYNOS4X12_GPIO_A07,
	EXYNOS4X12_GPIO_A10,		/* 8 */
	EXYNOS4X12_GPIO_A11,
	EXYNOS4X12_GPIO_A12,
	EXYNOS4X12_GPIO_A13,
	EXYNOS4X12_GPIO_A14,
	EXYNOS4X12_GPIO_A15,
	EXYNOS4X12_GPIO_A16,
	EXYNOS4X12_GPIO_A17,
	EXYNOS4X12_GPIO_B0,		/* 16 0x10 */
	EXYNOS4X12_GPIO_B1,
	EXYNOS4X12_GPIO_B2,
	EXYNOS4X12_GPIO_B3,
	EXYNOS4X12_GPIO_B4,
	EXYNOS4X12_GPIO_B5,
	EXYNOS4X12_GPIO_B6,
	EXYNOS4X12_GPIO_B7,
	EXYNOS4X12_GPIO_C00,		/* 24 0x18 */
	EXYNOS4X12_GPIO_C01,
	EXYNOS4X12_GPIO_C02,
	EXYNOS4X12_GPIO_C03,
	EXYNOS4X12_GPIO_C04,
	EXYNOS4X12_GPIO_C05,
	EXYNOS4X12_GPIO_C06,
	EXYNOS4X12_GPIO_C07,
	EXYNOS4X12_GPIO_C10,		/* 32 0x20 */
	EXYNOS4X12_GPIO_C11,
	EXYNOS4X12_GPIO_C12,
	EXYNOS4X12_GPIO_C13,
	EXYNOS4X12_GPIO_C14,
	EXYNOS4X12_GPIO_C15,
	EXYNOS4X12_GPIO_C16,
	EXYNOS4X12_GPIO_C17,
	EXYNOS4X12_GPIO_D00,		/* 40 0x28 */
	EXYNOS4X12_GPIO_D01,
	EXYNOS4X12_GPIO_D02,
	EXYNOS4X12_GPIO_D03,
	EXYNOS4X12_GPIO_D04,
	EXYNOS4X12_GPIO_D05,
	EXYNOS4X12_GPIO_D06,
	EXYNOS4X12_GPIO_D07,
	EXYNOS4X12_GPIO_D10,		/* 48 0x30 */
	EXYNOS4X12_GPIO_D11,
	EXYNOS4X12_GPIO_D12,
	EXYNOS4X12_GPIO_D13,
	EXYNOS4X12_GPIO_D14,
	EXYNOS4X12_GPIO_D15,
	EXYNOS4X12_GPIO_D16,
	EXYNOS4X12_GPIO_D17,
	EXYNOS4X12_GPIO_F00 = 96,	/* 96 0x60 */
	EXYNOS4X12_GPIO_F01,
	EXYNOS4X12_GPIO_F02,
	EXYNOS4X12_GPIO_F03,
	EXYNOS4X12_GPIO_F04,
	EXYNOS4X12_GPIO_F05,
	EXYNOS4X12_GPIO_F06,
	EXYNOS4X12_GPIO_F07,
	EXYNOS4X12_GPIO_F10,		/* 104 0x68 */
	EXYNOS4X12_GPIO_F11,
	EXYNOS4X12_GPIO_F12,
	EXYNOS4X12_GPIO_F13,
	EXYNOS4X12_GPIO_F14,
	EXYNOS4X12_GPIO_F15,
	EXYNOS4X12_GPIO_F16,
	EXYNOS4X12_GPIO_F17,
	EXYNOS4X12_GPIO_F20,		/* 112 0x70 */
	EXYNOS4X12_GPIO_F21,
	EXYNOS4X12_GPIO_F22,
	EXYNOS4X12_GPIO_F23,
	EXYNOS4X12_GPIO_F24,
	EXYNOS4X12_GPIO_F25,
	EXYNOS4X12_GPIO_F26,
	EXYNOS4X12_GPIO_F27,
	EXYNOS4X12_GPIO_F30,		/* 120 0x78 */
	EXYNOS4X12_GPIO_F31,
	EXYNOS4X12_GPIO_F32,
	EXYNOS4X12_GPIO_F33,
	EXYNOS4X12_GPIO_F34,
	EXYNOS4X12_GPIO_F35,
	EXYNOS4X12_GPIO_F36,
	EXYNOS4X12_GPIO_F37,
	EXYNOS4X12_GPIO_J00 = 144,	/* 144 0x90 */
	EXYNOS4X12_GPIO_J01,
	EXYNOS4X12_GPIO_J02,
	EXYNOS4X12_GPIO_J03,
	EXYNOS4X12_GPIO_J04,
	EXYNOS4X12_GPIO_J05,
	EXYNOS4X12_GPIO_J06,
	EXYNOS4X12_GPIO_J07,
	EXYNOS4X12_GPIO_J10,		/* 152 0x98 */
	EXYNOS4X12_GPIO_J11,
	EXYNOS4X12_GPIO_J12,
	EXYNOS4X12_GPIO_J13,
	EXYNOS4X12_GPIO_J14,
	EXYNOS4X12_GPIO_J15,
	EXYNOS4X12_GPIO_J16,
	EXYNOS4X12_GPIO_J17,

	/* GPIO_PART2_STARTS */
	EXYNOS4X12_GPIO_MAX_PORT_PART_1,/* 160 0xA0 */
	EXYNOS4X12_GPIO_K00 = 176,	/* 176 0xB0 */
	EXYNOS4X12_GPIO_K01,
	EXYNOS4X12_GPIO_K02,
	EXYNOS4X12_GPIO_K03,
	EXYNOS4X12_GPIO_K04,
	EXYNOS4X12_GPIO_K05,
	EXYNOS4X12_GPIO_K06,
	EXYNOS4X12_GPIO_K07,
	EXYNOS4X12_GPIO_K10,		/* 184 0xB8 */
	EXYNOS4X12_GPIO_K11,
	EXYNOS4X12_GPIO_K12,
	EXYNOS4X12_GPIO_K13,
	EXYNOS4X12_GPIO_K14,
	EXYNOS4X12_GPIO_K15,
	EXYNOS4X12_GPIO_K16,
	EXYNOS4X12_GPIO_K17,
	EXYNOS4X12_GPIO_K20,		/* 192 0xC0 */
	EXYNOS4X12_GPIO_K21,
	EXYNOS4X12_GPIO_K22,
	EXYNOS4X12_GPIO_K23,
	EXYNOS4X12_GPIO_K24,
	EXYNOS4X12_GPIO_K25,
	EXYNOS4X12_GPIO_K26,
	EXYNOS4X12_GPIO_K27,
	EXYNOS4X12_GPIO_K30,		/* 200 0xC8 */
	EXYNOS4X12_GPIO_K31,
	EXYNOS4X12_GPIO_K32,
	EXYNOS4X12_GPIO_K33,
	EXYNOS4X12_GPIO_K34,
	EXYNOS4X12_GPIO_K35,
	EXYNOS4X12_GPIO_K36,
	EXYNOS4X12_GPIO_K37,
	EXYNOS4X12_GPIO_L00,		/* 208 0xD0 */
	EXYNOS4X12_GPIO_L01,
	EXYNOS4X12_GPIO_L02,
	EXYNOS4X12_GPIO_L03,
	EXYNOS4X12_GPIO_L04,
	EXYNOS4X12_GPIO_L05,
	EXYNOS4X12_GPIO_L06,
	EXYNOS4X12_GPIO_L07,
	EXYNOS4X12_GPIO_L10,		/* 216 0xD8 */
	EXYNOS4X12_GPIO_L11,
	EXYNOS4X12_GPIO_L12,
	EXYNOS4X12_GPIO_L13,
	EXYNOS4X12_GPIO_L14,
	EXYNOS4X12_GPIO_L15,
	EXYNOS4X12_GPIO_L16,
	EXYNOS4X12_GPIO_L17,
	EXYNOS4X12_GPIO_L20,		/* 224 0xE0 */
	EXYNOS4X12_GPIO_L21,
	EXYNOS4X12_GPIO_L22,
	EXYNOS4X12_GPIO_L23,
	EXYNOS4X12_GPIO_L24,
	EXYNOS4X12_GPIO_L25,
	EXYNOS4X12_GPIO_L26,
	EXYNOS4X12_GPIO_L27,
	EXYNOS4X12_GPIO_Y00,		/* 232 0xE8 */
	EXYNOS4X12_GPIO_Y01,
	EXYNOS4X12_GPIO_Y02,
	EXYNOS4X12_GPIO_Y03,
	EXYNOS4X12_GPIO_Y04,
	EXYNOS4X12_GPIO_Y05,
	EXYNOS4X12_GPIO_Y06,
	EXYNOS4X12_GPIO_Y07,
	EXYNOS4X12_GPIO_Y10,		/* 240 0xF0 */
	EXYNOS4X12_GPIO_Y11,
	EXYNOS4X12_GPIO_Y12,
	EXYNOS4X12_GPIO_Y13,
	EXYNOS4X12_GPIO_Y14,
	EXYNOS4X12_GPIO_Y15,
	EXYNOS4X12_GPIO_Y16,
	EXYNOS4X12_GPIO_Y17,
	EXYNOS4X12_GPIO_Y20,		/* 248 0xF8 */
	EXYNOS4X12_GPIO_Y21,
	EXYNOS4X12_GPIO_Y22,
	EXYNOS4X12_GPIO_Y23,
	EXYNOS4X12_GPIO_Y24,
	EXYNOS4X12_GPIO_Y25,
	EXYNOS4X12_GPIO_Y26,
	EXYNOS4X12_GPIO_Y27,
	EXYNOS4X12_GPIO_Y30,		/* 256 0x100 */
	EXYNOS4X12_GPIO_Y31,
	EXYNOS4X12_GPIO_Y32,
	EXYNOS4X12_GPIO_Y33,
	EXYNOS4X12_GPIO_Y34,
	EXYNOS4X12_GPIO_Y35,
	EXYNOS4X12_GPIO_Y36,
	EXYNOS4X12_GPIO_Y37,
	EXYNOS4X12_GPIO_Y40,		/* 264 0x108 */
	EXYNOS4X12_GPIO_Y41,
	EXYNOS4X12_GPIO_Y42,
	EXYNOS4X12_GPIO_Y43,
	EXYNOS4X12_GPIO_Y44,
	EXYNOS4X12_GPIO_Y45,
	EXYNOS4X12_GPIO_Y46,
	EXYNOS4X12_GPIO_Y47,
	EXYNOS4X12_GPIO_Y50,		/* 272 0x110 */
	EXYNOS4X12_GPIO_Y51,
	EXYNOS4X12_GPIO_Y52,
	EXYNOS4X12_GPIO_Y53,
	EXYNOS4X12_GPIO_Y54,
	EXYNOS4X12_GPIO_Y55,
	EXYNOS4X12_GPIO_Y56,
	EXYNOS4X12_GPIO_Y57,
	EXYNOS4X12_GPIO_Y60,		/* 280 0x118 */
	EXYNOS4X12_GPIO_Y61,
	EXYNOS4X12_GPIO_Y62,
	EXYNOS4X12_GPIO_Y63,
	EXYNOS4X12_GPIO_Y64,
	EXYNOS4X12_GPIO_Y65,
	EXYNOS4X12_GPIO_Y66,
	EXYNOS4X12_GPIO_Y67,
	EXYNOS4X12_GPIO_M00 = 312,	/* 312 0xF0 */
	EXYNOS4X12_GPIO_M01,
	EXYNOS4X12_GPIO_M02,
	EXYNOS4X12_GPIO_M03,
	EXYNOS4X12_GPIO_M04,
	EXYNOS4X12_GPIO_M05,
	EXYNOS4X12_GPIO_M06,
	EXYNOS4X12_GPIO_M07,
	EXYNOS4X12_GPIO_M10,		/* 320 0xF8 */
	EXYNOS4X12_GPIO_M11,
	EXYNOS4X12_GPIO_M12,
	EXYNOS4X12_GPIO_M13,
	EXYNOS4X12_GPIO_M14,
	EXYNOS4X12_GPIO_M15,
	EXYNOS4X12_GPIO_M16,
	EXYNOS4X12_GPIO_M17,
	EXYNOS4X12_GPIO_M20,		/* 328 0x100 */
	EXYNOS4X12_GPIO_M21,
	EXYNOS4X12_GPIO_M22,
	EXYNOS4X12_GPIO_M23,
	EXYNOS4X12_GPIO_M24,
	EXYNOS4X12_GPIO_M25,
	EXYNOS4X12_GPIO_M26,
	EXYNOS4X12_GPIO_M27,
	EXYNOS4X12_GPIO_M30,		/* 336 0x108 */
	EXYNOS4X12_GPIO_M31,
	EXYNOS4X12_GPIO_M32,
	EXYNOS4X12_GPIO_M33,
	EXYNOS4X12_GPIO_M34,
	EXYNOS4X12_GPIO_M35,
	EXYNOS4X12_GPIO_M36,
	EXYNOS4X12_GPIO_M37,
	EXYNOS4X12_GPIO_M40,		/* 344 0x110 */
	EXYNOS4X12_GPIO_M41,
	EXYNOS4X12_GPIO_M42,
	EXYNOS4X12_GPIO_M43,
	EXYNOS4X12_GPIO_M44,
	EXYNOS4X12_GPIO_M45,
	EXYNOS4X12_GPIO_M46,
	EXYNOS4X12_GPIO_M47,
	EXYNOS4X12_GPIO_X00 = 928,	/* 928 0x3A0 */
	EXYNOS4X12_GPIO_X01,
	EXYNOS4X12_GPIO_X02,
	EXYNOS4X12_GPIO_X03,
	EXYNOS4X12_GPIO_X04,
	EXYNOS4X12_GPIO_X05,
	EXYNOS4X12_GPIO_X06,
	EXYNOS4X12_GPIO_X07,
	EXYNOS4X12_GPIO_X10,		/* 936 0x3A8 */
	EXYNOS4X12_GPIO_X11,
	EXYNOS4X12_GPIO_X12,
	EXYNOS4X12_GPIO_X13,
	EXYNOS4X12_GPIO_X14,
	EXYNOS4X12_GPIO_X15,
	EXYNOS4X12_GPIO_X16,
	EXYNOS4X12_GPIO_X17,
	EXYNOS4X12_GPIO_X20,		/* 944 0x3B0 */
	EXYNOS4X12_GPIO_X21,
	EXYNOS4X12_GPIO_X22,
	EXYNOS4X12_GPIO_X23,
	EXYNOS4X12_GPIO_X24,
	EXYNOS4X12_GPIO_X25,
	EXYNOS4X12_GPIO_X26,
	EXYNOS4X12_GPIO_X27,
	EXYNOS4X12_GPIO_X30,		/* 952 0x3B8 */
	EXYNOS4X12_GPIO_X31,
	EXYNOS4X12_GPIO_X32,
	EXYNOS4X12_GPIO_X33,
	EXYNOS4X12_GPIO_X34,
	EXYNOS4X12_GPIO_X35,
	EXYNOS4X12_GPIO_X36,
	EXYNOS4X12_GPIO_X37,

	/* GPIO_PART3_STARTS */
	EXYNOS4X12_GPIO_MAX_PORT_PART_2,/* 960 0x3C0 */
	EXYNOS4X12_GPIO_Z0 = EXYNOS4X12_GPIO_MAX_PORT_PART_2,
	EXYNOS4X12_GPIO_Z1,
	EXYNOS4X12_GPIO_Z2,
	EXYNOS4X12_GPIO_Z3,
	EXYNOS4X12_GPIO_Z4,
	EXYNOS4X12_GPIO_Z5,
	EXYNOS4X12_GPIO_Z6,
	EXYNOS4X12_GPIO_Z7,

	/* GPIO_PART4_STARTS */
	EXYNOS4X12_GPIO_MAX_PORT_PART_3,/* 968 0x3C8 */
	EXYNOS4X12_GPIO_V00 = EXYNOS4X12_GPIO_MAX_PORT_PART_3,
	EXYNOS4X12_GPIO_V01,
	EXYNOS4X12_GPIO_V02,
	EXYNOS4X12_GPIO_V03,
	EXYNOS4X12_GPIO_V04,
	EXYNOS4X12_GPIO_V05,
	EXYNOS4X12_GPIO_V06,
	EXYNOS4X12_GPIO_V07,
	EXYNOS4X12_GPIO_V10,		/* 976 0x3D0 */
	EXYNOS4X12_GPIO_V11,
	EXYNOS4X12_GPIO_V12,
	EXYNOS4X12_GPIO_V13,
	EXYNOS4X12_GPIO_V14,
	EXYNOS4X12_GPIO_V15,
	EXYNOS4X12_GPIO_V16,
	EXYNOS4X12_GPIO_V17,
	EXYNOS4X12_GPIO_V20 = 992,	/* 992 0x3E0 */
	EXYNOS4X12_GPIO_V21,
	EXYNOS4X12_GPIO_V22,
	EXYNOS4X12_GPIO_V23,
	EXYNOS4X12_GPIO_V24,
	EXYNOS4X12_GPIO_V25,
	EXYNOS4X12_GPIO_V26,
	EXYNOS4X12_GPIO_V27,
	EXYNOS4X12_GPIO_V30 = 1000,	/* 1000 0x3E8 */
	EXYNOS4X12_GPIO_V31,
	EXYNOS4X12_GPIO_V32,
	EXYNOS4X12_GPIO_V33,
	EXYNOS4X12_GPIO_V34,
	EXYNOS4X12_GPIO_V35,
	EXYNOS4X12_GPIO_V36,
	EXYNOS4X12_GPIO_V37,
	EXYNOS4X12_GPIO_V40 = 1016,	/* 1016 0x3F8 */
	EXYNOS4X12_GPIO_V41,
	EXYNOS4X12_GPIO_V42,
	EXYNOS4X12_GPIO_V43,
	EXYNOS4X12_GPIO_V44,
	EXYNOS4X12_GPIO_V45,
	EXYNOS4X12_GPIO_V46,
	EXYNOS4X12_GPIO_V47,

	EXYNOS4X12_GPIO_MAX_PORT
};

enum exynos5_gpio_pin {
	/* GPIO_PART1_STARTS */
	EXYNOS5_GPIO_A00,		/* 0 */
	EXYNOS5_GPIO_A01,
	EXYNOS5_GPIO_A02,
	EXYNOS5_GPIO_A03,
	EXYNOS5_GPIO_A04,
	EXYNOS5_GPIO_A05,
	EXYNOS5_GPIO_A06,
	EXYNOS5_GPIO_A07,
	EXYNOS5_GPIO_A10,		/* 8 */
	EXYNOS5_GPIO_A11,
	EXYNOS5_GPIO_A12,
	EXYNOS5_GPIO_A13,
	EXYNOS5_GPIO_A14,
	EXYNOS5_GPIO_A15,
	EXYNOS5_GPIO_A16,
	EXYNOS5_GPIO_A17,
	EXYNOS5_GPIO_A20,		/* 16 0x10 */
	EXYNOS5_GPIO_A21,
	EXYNOS5_GPIO_A22,
	EXYNOS5_GPIO_A23,
	EXYNOS5_GPIO_A24,
	EXYNOS5_GPIO_A25,
	EXYNOS5_GPIO_A26,
	EXYNOS5_GPIO_A27,
	EXYNOS5_GPIO_B00,		/* 24 0x18 */
	EXYNOS5_GPIO_B01,
	EXYNOS5_GPIO_B02,
	EXYNOS5_GPIO_B03,
	EXYNOS5_GPIO_B04,
	EXYNOS5_GPIO_B05,
	EXYNOS5_GPIO_B06,
	EXYNOS5_GPIO_B07,
	EXYNOS5_GPIO_B10,		/* 32 0x20 */
	EXYNOS5_GPIO_B11,
	EXYNOS5_GPIO_B12,
	EXYNOS5_GPIO_B13,
	EXYNOS5_GPIO_B14,
	EXYNOS5_GPIO_B15,
	EXYNOS5_GPIO_B16,
	EXYNOS5_GPIO_B17,
	EXYNOS5_GPIO_B20,		/* 40 0x28 */
	EXYNOS5_GPIO_B21,
	EXYNOS5_GPIO_B22,
	EXYNOS5_GPIO_B23,
	EXYNOS5_GPIO_B24,
	EXYNOS5_GPIO_B25,
	EXYNOS5_GPIO_B26,
	EXYNOS5_GPIO_B27,
	EXYNOS5_GPIO_B30,		/* 48 0x39 */
	EXYNOS5_GPIO_B31,
	EXYNOS5_GPIO_B32,
	EXYNOS5_GPIO_B33,
	EXYNOS5_GPIO_B34,
	EXYNOS5_GPIO_B35,
	EXYNOS5_GPIO_B36,
	EXYNOS5_GPIO_B37,
	EXYNOS5_GPIO_C00,		/* 56 0x38 */
	EXYNOS5_GPIO_C01,
	EXYNOS5_GPIO_C02,
	EXYNOS5_GPIO_C03,
	EXYNOS5_GPIO_C04,
	EXYNOS5_GPIO_C05,
	EXYNOS5_GPIO_C06,
	EXYNOS5_GPIO_C07,
	EXYNOS5_GPIO_C10,		/* 64 0x40 */
	EXYNOS5_GPIO_C11,
	EXYNOS5_GPIO_C12,
	EXYNOS5_GPIO_C13,
	EXYNOS5_GPIO_C14,
	EXYNOS5_GPIO_C15,
	EXYNOS5_GPIO_C16,
	EXYNOS5_GPIO_C17,
	EXYNOS5_GPIO_C20,		/* 72 0x48 */
	EXYNOS5_GPIO_C21,
	EXYNOS5_GPIO_C22,
	EXYNOS5_GPIO_C23,
	EXYNOS5_GPIO_C24,
	EXYNOS5_GPIO_C25,
	EXYNOS5_GPIO_C26,
	EXYNOS5_GPIO_C27,
	EXYNOS5_GPIO_C30,		/* 80 0x50 */
	EXYNOS5_GPIO_C31,
	EXYNOS5_GPIO_C32,
	EXYNOS5_GPIO_C33,
	EXYNOS5_GPIO_C34,
	EXYNOS5_GPIO_C35,
	EXYNOS5_GPIO_C36,
	EXYNOS5_GPIO_C37,
	EXYNOS5_GPIO_D00,		/* 88 0x58 */
	EXYNOS5_GPIO_D01,
	EXYNOS5_GPIO_D02,
	EXYNOS5_GPIO_D03,
	EXYNOS5_GPIO_D04,
	EXYNOS5_GPIO_D05,
	EXYNOS5_GPIO_D06,
	EXYNOS5_GPIO_D07,
	EXYNOS5_GPIO_D10,		/* 96 0x60 */
	EXYNOS5_GPIO_D11,
	EXYNOS5_GPIO_D12,
	EXYNOS5_GPIO_D13,
	EXYNOS5_GPIO_D14,
	EXYNOS5_GPIO_D15,
	EXYNOS5_GPIO_D16,
	EXYNOS5_GPIO_D17,
	EXYNOS5_GPIO_Y00,		/* 104 0x68 */
	EXYNOS5_GPIO_Y01,
	EXYNOS5_GPIO_Y02,
	EXYNOS5_GPIO_Y03,
	EXYNOS5_GPIO_Y04,
	EXYNOS5_GPIO_Y05,
	EXYNOS5_GPIO_Y06,
	EXYNOS5_GPIO_Y07,
	EXYNOS5_GPIO_Y10,		/* 112 0x70 */
	EXYNOS5_GPIO_Y11,
	EXYNOS5_GPIO_Y12,
	EXYNOS5_GPIO_Y13,
	EXYNOS5_GPIO_Y14,
	EXYNOS5_GPIO_Y15,
	EXYNOS5_GPIO_Y16,
	EXYNOS5_GPIO_Y17,
	EXYNOS5_GPIO_Y20,		/* 120 0x78 */
	EXYNOS5_GPIO_Y21,
	EXYNOS5_GPIO_Y22,
	EXYNOS5_GPIO_Y23,
	EXYNOS5_GPIO_Y24,
	EXYNOS5_GPIO_Y25,
	EXYNOS5_GPIO_Y26,
	EXYNOS5_GPIO_Y27,
	EXYNOS5_GPIO_Y30,		/* 128 0x80 */
	EXYNOS5_GPIO_Y31,
	EXYNOS5_GPIO_Y32,
	EXYNOS5_GPIO_Y33,
	EXYNOS5_GPIO_Y34,
	EXYNOS5_GPIO_Y35,
	EXYNOS5_GPIO_Y36,
	EXYNOS5_GPIO_Y37,
	EXYNOS5_GPIO_Y40,		/* 136 0x88 */
	EXYNOS5_GPIO_Y41,
	EXYNOS5_GPIO_Y42,
	EXYNOS5_GPIO_Y43,
	EXYNOS5_GPIO_Y44,
	EXYNOS5_GPIO_Y45,
	EXYNOS5_GPIO_Y46,
	EXYNOS5_GPIO_Y47,
	EXYNOS5_GPIO_Y50,		/* 144 0x90 */
	EXYNOS5_GPIO_Y51,
	EXYNOS5_GPIO_Y52,
	EXYNOS5_GPIO_Y53,
	EXYNOS5_GPIO_Y54,
	EXYNOS5_GPIO_Y55,
	EXYNOS5_GPIO_Y56,
	EXYNOS5_GPIO_Y57,
	EXYNOS5_GPIO_Y60,		/* 152 0x98 */
	EXYNOS5_GPIO_Y61,
	EXYNOS5_GPIO_Y62,
	EXYNOS5_GPIO_Y63,
	EXYNOS5_GPIO_Y64,
	EXYNOS5_GPIO_Y65,
	EXYNOS5_GPIO_Y66,
	EXYNOS5_GPIO_Y67,

	/* GPIO_PART2_STARTS */
	EXYNOS5_GPIO_MAX_PORT_PART_1,	/* 160 0xa0 */
	EXYNOS5_GPIO_C40 = EXYNOS5_GPIO_MAX_PORT_PART_1,
	EXYNOS5_GPIO_C41,
	EXYNOS5_GPIO_C42,
	EXYNOS5_GPIO_C43,
	EXYNOS5_GPIO_C44,
	EXYNOS5_GPIO_C45,
	EXYNOS5_GPIO_C46,
	EXYNOS5_GPIO_C47,

	/* GPIO_PART3_STARTS */
	EXYNOS5_GPIO_MAX_PORT_PART_2,	/* 168 0xa8 */
	EXYNOS5_GPIO_X00 = EXYNOS5_GPIO_MAX_PORT_PART_2,
	EXYNOS5_GPIO_X01,
	EXYNOS5_GPIO_X02,
	EXYNOS5_GPIO_X03,
	EXYNOS5_GPIO_X04,
	EXYNOS5_GPIO_X05,
	EXYNOS5_GPIO_X06,
	EXYNOS5_GPIO_X07,
	EXYNOS5_GPIO_X10,		/* 176 0xb0 */
	EXYNOS5_GPIO_X11,
	EXYNOS5_GPIO_X12,
	EXYNOS5_GPIO_X13,
	EXYNOS5_GPIO_X14,
	EXYNOS5_GPIO_X15,
	EXYNOS5_GPIO_X16,
	EXYNOS5_GPIO_X17,
	EXYNOS5_GPIO_X20,		/* 184 0xb8 */
	EXYNOS5_GPIO_X21,
	EXYNOS5_GPIO_X22,
	EXYNOS5_GPIO_X23,
	EXYNOS5_GPIO_X24,
	EXYNOS5_GPIO_X25,
	EXYNOS5_GPIO_X26,
	EXYNOS5_GPIO_X27,
	EXYNOS5_GPIO_X30,		/* 192 0xc0 */
	EXYNOS5_GPIO_X31,
	EXYNOS5_GPIO_X32,
	EXYNOS5_GPIO_X33,
	EXYNOS5_GPIO_X34,
	EXYNOS5_GPIO_X35,
	EXYNOS5_GPIO_X36,
	EXYNOS5_GPIO_X37,

	/* GPIO_PART4_STARTS */
	EXYNOS5_GPIO_MAX_PORT_PART_3,	/* 200 0xc8 */
	EXYNOS5_GPIO_E00 = EXYNOS5_GPIO_MAX_PORT_PART_3,
	EXYNOS5_GPIO_E01,
	EXYNOS5_GPIO_E02,
	EXYNOS5_GPIO_E03,
	EXYNOS5_GPIO_E04,
	EXYNOS5_GPIO_E05,
	EXYNOS5_GPIO_E06,
	EXYNOS5_GPIO_E07,
	EXYNOS5_GPIO_E10,		/* 208 0xd0 */
	EXYNOS5_GPIO_E11,
	EXYNOS5_GPIO_E12,
	EXYNOS5_GPIO_E13,
	EXYNOS5_GPIO_E14,
	EXYNOS5_GPIO_E15,
	EXYNOS5_GPIO_E16,
	EXYNOS5_GPIO_E17,
	EXYNOS5_GPIO_F00,		/* 216 0xd8 */
	EXYNOS5_GPIO_F01,
	EXYNOS5_GPIO_F02,
	EXYNOS5_GPIO_F03,
	EXYNOS5_GPIO_F04,
	EXYNOS5_GPIO_F05,
	EXYNOS5_GPIO_F06,
	EXYNOS5_GPIO_F07,
	EXYNOS5_GPIO_F10,		/* 224 0xe0 */
	EXYNOS5_GPIO_F11,
	EXYNOS5_GPIO_F12,
	EXYNOS5_GPIO_F13,
	EXYNOS5_GPIO_F14,
	EXYNOS5_GPIO_F15,
	EXYNOS5_GPIO_F16,
	EXYNOS5_GPIO_F17,
	EXYNOS5_GPIO_G00,		/* 232 0xe8 */
	EXYNOS5_GPIO_G01,
	EXYNOS5_GPIO_G02,
	EXYNOS5_GPIO_G03,
	EXYNOS5_GPIO_G04,
	EXYNOS5_GPIO_G05,
	EXYNOS5_GPIO_G06,
	EXYNOS5_GPIO_G07,
	EXYNOS5_GPIO_G10,		/* 240 0xf0 */
	EXYNOS5_GPIO_G11,
	EXYNOS5_GPIO_G12,
	EXYNOS5_GPIO_G13,
	EXYNOS5_GPIO_G14,
	EXYNOS5_GPIO_G15,
	EXYNOS5_GPIO_G16,
	EXYNOS5_GPIO_G17,
	EXYNOS5_GPIO_G20,		/* 248 0xf8 */
	EXYNOS5_GPIO_G21,
	EXYNOS5_GPIO_G22,
	EXYNOS5_GPIO_G23,
	EXYNOS5_GPIO_G24,
	EXYNOS5_GPIO_G25,
	EXYNOS5_GPIO_G26,
	EXYNOS5_GPIO_G27,
	EXYNOS5_GPIO_H00,		/* 256 0x100 */
	EXYNOS5_GPIO_H01,
	EXYNOS5_GPIO_H02,
	EXYNOS5_GPIO_H03,
	EXYNOS5_GPIO_H04,
	EXYNOS5_GPIO_H05,
	EXYNOS5_GPIO_H06,
	EXYNOS5_GPIO_H07,
	EXYNOS5_GPIO_H10,		/* 264 0x108 */
	EXYNOS5_GPIO_H11,
	EXYNOS5_GPIO_H12,
	EXYNOS5_GPIO_H13,
	EXYNOS5_GPIO_H14,
	EXYNOS5_GPIO_H15,
	EXYNOS5_GPIO_H16,
	EXYNOS5_GPIO_H17,

	/* GPIO_PART4_STARTS */
	EXYNOS5_GPIO_MAX_PORT_PART_4,	/* 272 0x110 */
	EXYNOS5_GPIO_V00 = EXYNOS5_GPIO_MAX_PORT_PART_4,
	EXYNOS5_GPIO_V01,
	EXYNOS5_GPIO_V02,
	EXYNOS5_GPIO_V03,
	EXYNOS5_GPIO_V04,
	EXYNOS5_GPIO_V05,
	EXYNOS5_GPIO_V06,
	EXYNOS5_GPIO_V07,
	EXYNOS5_GPIO_V10,		/* 280 0x118 */
	EXYNOS5_GPIO_V11,
	EXYNOS5_GPIO_V12,
	EXYNOS5_GPIO_V13,
	EXYNOS5_GPIO_V14,
	EXYNOS5_GPIO_V15,
	EXYNOS5_GPIO_V16,
	EXYNOS5_GPIO_V17,

	/* GPIO_PART5_STARTS */
	EXYNOS5_GPIO_MAX_PORT_PART_5,	/* 288 0x120 */
	EXYNOS5_GPIO_V20 = EXYNOS5_GPIO_MAX_PORT_PART_5,
	EXYNOS5_GPIO_V21,
	EXYNOS5_GPIO_V22,
	EXYNOS5_GPIO_V23,
	EXYNOS5_GPIO_V24,
	EXYNOS5_GPIO_V25,
	EXYNOS5_GPIO_V26,
	EXYNOS5_GPIO_V27,
	EXYNOS5_GPIO_V30,		/* 296 0x128 */
	EXYNOS5_GPIO_V31,
	EXYNOS5_GPIO_V32,
	EXYNOS5_GPIO_V33,
	EXYNOS5_GPIO_V34,
	EXYNOS5_GPIO_V35,
	EXYNOS5_GPIO_V36,
	EXYNOS5_GPIO_V37,

	/* GPIO_PART6_STARTS */
	EXYNOS5_GPIO_MAX_PORT_PART_6,	/* 304 0x130 */
	EXYNOS5_GPIO_V40 = EXYNOS5_GPIO_MAX_PORT_PART_6,
	EXYNOS5_GPIO_V41,
	EXYNOS5_GPIO_V42,
	EXYNOS5_GPIO_V43,
	EXYNOS5_GPIO_V44,
	EXYNOS5_GPIO_V45,
	EXYNOS5_GPIO_V46,
	EXYNOS5_GPIO_V47,

	/* GPIO_PART7_STARTS */		/* 312 0x138 */
	EXYNOS5_GPIO_MAX_PORT_PART_7,
	EXYNOS5_GPIO_Z0 = EXYNOS5_GPIO_MAX_PORT_PART_7,
	EXYNOS5_GPIO_Z1,
	EXYNOS5_GPIO_Z2,
	EXYNOS5_GPIO_Z3,
	EXYNOS5_GPIO_Z4,
	EXYNOS5_GPIO_Z5,
	EXYNOS5_GPIO_Z6,
	EXYNOS5_GPIO_MAX_PORT
};

enum exynos5420_gpio_pin {
	/* GPIO_PART1_STARTS */
	EXYNOS5420_GPIO_A00,		/* 0 */
	EXYNOS5420_GPIO_A01,
	EXYNOS5420_GPIO_A02,
	EXYNOS5420_GPIO_A03,
	EXYNOS5420_GPIO_A04,
	EXYNOS5420_GPIO_A05,
	EXYNOS5420_GPIO_A06,
	EXYNOS5420_GPIO_A07,
	EXYNOS5420_GPIO_A10,		/* 8 */
	EXYNOS5420_GPIO_A11,
	EXYNOS5420_GPIO_A12,
	EXYNOS5420_GPIO_A13,
	EXYNOS5420_GPIO_A14,
	EXYNOS5420_GPIO_A15,
	EXYNOS5420_GPIO_A16,
	EXYNOS5420_GPIO_A17,
	EXYNOS5420_GPIO_A20,		/* 16 0x10 */
	EXYNOS5420_GPIO_A21,
	EXYNOS5420_GPIO_A22,
	EXYNOS5420_GPIO_A23,
	EXYNOS5420_GPIO_A24,
	EXYNOS5420_GPIO_A25,
	EXYNOS5420_GPIO_A26,
	EXYNOS5420_GPIO_A27,
	EXYNOS5420_GPIO_B00,		/* 24 0x18 */
	EXYNOS5420_GPIO_B01,
	EXYNOS5420_GPIO_B02,
	EXYNOS5420_GPIO_B03,
	EXYNOS5420_GPIO_B04,
	EXYNOS5420_GPIO_B05,
	EXYNOS5420_GPIO_B06,
	EXYNOS5420_GPIO_B07,
	EXYNOS5420_GPIO_B10,		/* 32 0x20 */
	EXYNOS5420_GPIO_B11,
	EXYNOS5420_GPIO_B12,
	EXYNOS5420_GPIO_B13,
	EXYNOS5420_GPIO_B14,
	EXYNOS5420_GPIO_B15,
	EXYNOS5420_GPIO_B16,
	EXYNOS5420_GPIO_B17,
	EXYNOS5420_GPIO_B20,		/* 40 0x28 */
	EXYNOS5420_GPIO_B21,
	EXYNOS5420_GPIO_B22,
	EXYNOS5420_GPIO_B23,
	EXYNOS5420_GPIO_B24,
	EXYNOS5420_GPIO_B25,
	EXYNOS5420_GPIO_B26,
	EXYNOS5420_GPIO_B27,
	EXYNOS5420_GPIO_B30,		/* 48 0x30 */
	EXYNOS5420_GPIO_B31,
	EXYNOS5420_GPIO_B32,
	EXYNOS5420_GPIO_B33,
	EXYNOS5420_GPIO_B34,
	EXYNOS5420_GPIO_B35,
	EXYNOS5420_GPIO_B36,
	EXYNOS5420_GPIO_B37,
	EXYNOS5420_GPIO_B40,		/* 56 0x38 */
	EXYNOS5420_GPIO_B41,
	EXYNOS5420_GPIO_B42,
	EXYNOS5420_GPIO_B43,
	EXYNOS5420_GPIO_B44,
	EXYNOS5420_GPIO_B45,
	EXYNOS5420_GPIO_B46,
	EXYNOS5420_GPIO_B47,
	EXYNOS5420_GPIO_H00,		/* 64 0x40 */
	EXYNOS5420_GPIO_H01,
	EXYNOS5420_GPIO_H02,
	EXYNOS5420_GPIO_H03,
	EXYNOS5420_GPIO_H04,
	EXYNOS5420_GPIO_H05,
	EXYNOS5420_GPIO_H06,
	EXYNOS5420_GPIO_H07,

	/* GPIO PART 2 STARTS*/
	EXYNOS5420_GPIO_MAX_PORT_PART_1,/* 72 0x48 */
	EXYNOS5420_GPIO_Y70 = EXYNOS5420_GPIO_MAX_PORT_PART_1,
	EXYNOS5420_GPIO_Y71,
	EXYNOS5420_GPIO_Y72,
	EXYNOS5420_GPIO_Y73,
	EXYNOS5420_GPIO_Y74,
	EXYNOS5420_GPIO_Y75,
	EXYNOS5420_GPIO_Y76,
	EXYNOS5420_GPIO_Y77,

	/* GPIO PART 3 STARTS*/
	EXYNOS5420_GPIO_MAX_PORT_PART_2,/* 80 0x50 */
	EXYNOS5420_GPIO_X00 = EXYNOS5420_GPIO_MAX_PORT_PART_2,
	EXYNOS5420_GPIO_X01,
	EXYNOS5420_GPIO_X02,
	EXYNOS5420_GPIO_X03,
	EXYNOS5420_GPIO_X04,
	EXYNOS5420_GPIO_X05,
	EXYNOS5420_GPIO_X06,
	EXYNOS5420_GPIO_X07,
	EXYNOS5420_GPIO_X10,		/* 88 0x58 */
	EXYNOS5420_GPIO_X11,
	EXYNOS5420_GPIO_X12,
	EXYNOS5420_GPIO_X13,
	EXYNOS5420_GPIO_X14,
	EXYNOS5420_GPIO_X15,
	EXYNOS5420_GPIO_X16,
	EXYNOS5420_GPIO_X17,
	EXYNOS5420_GPIO_X20,		/* 96 0x60 */
	EXYNOS5420_GPIO_X21,
	EXYNOS5420_GPIO_X22,
	EXYNOS5420_GPIO_X23,
	EXYNOS5420_GPIO_X24,
	EXYNOS5420_GPIO_X25,
	EXYNOS5420_GPIO_X26,
	EXYNOS5420_GPIO_X27,
	EXYNOS5420_GPIO_X30,		/* 104 0x68 */
	EXYNOS5420_GPIO_X31,
	EXYNOS5420_GPIO_X32,
	EXYNOS5420_GPIO_X33,
	EXYNOS5420_GPIO_X34,
	EXYNOS5420_GPIO_X35,
	EXYNOS5420_GPIO_X36,
	EXYNOS5420_GPIO_X37,

	/* GPIO PART 4 STARTS*/
	EXYNOS5420_GPIO_MAX_PORT_PART_3,/* 112 0x70 */
	EXYNOS5420_GPIO_C00 = EXYNOS5420_GPIO_MAX_PORT_PART_3,
	EXYNOS5420_GPIO_C01,
	EXYNOS5420_GPIO_C02,
	EXYNOS5420_GPIO_C03,
	EXYNOS5420_GPIO_C04,
	EXYNOS5420_GPIO_C05,
	EXYNOS5420_GPIO_C06,
	EXYNOS5420_GPIO_C07,
	EXYNOS5420_GPIO_C10,		/* 120 0x78 */
	EXYNOS5420_GPIO_C11,
	EXYNOS5420_GPIO_C12,
	EXYNOS5420_GPIO_C13,
	EXYNOS5420_GPIO_C14,
	EXYNOS5420_GPIO_C15,
	EXYNOS5420_GPIO_C16,
	EXYNOS5420_GPIO_C17,
	EXYNOS5420_GPIO_C20,		/* 128 0x80 */
	EXYNOS5420_GPIO_C21,
	EXYNOS5420_GPIO_C22,
	EXYNOS5420_GPIO_C23,
	EXYNOS5420_GPIO_C24,
	EXYNOS5420_GPIO_C25,
	EXYNOS5420_GPIO_C26,
	EXYNOS5420_GPIO_C27,
	EXYNOS5420_GPIO_C30,		/* 136 0x88 */
	EXYNOS5420_GPIO_C31,
	EXYNOS5420_GPIO_C32,
	EXYNOS5420_GPIO_C33,
	EXYNOS5420_GPIO_C34,
	EXYNOS5420_GPIO_C35,
	EXYNOS5420_GPIO_C36,
	EXYNOS5420_GPIO_C37,
	EXYNOS5420_GPIO_C40,		/* 144 0x90 */
	EXYNOS5420_GPIO_C41,
	EXYNOS5420_GPIO_C42,
	EXYNOS5420_GPIO_C43,
	EXYNOS5420_GPIO_C44,
	EXYNOS5420_GPIO_C45,
	EXYNOS5420_GPIO_C46,
	EXYNOS5420_GPIO_C47,
	EXYNOS5420_GPIO_D10,		/* 152 0x98 */
	EXYNOS5420_GPIO_D11,
	EXYNOS5420_GPIO_D12,
	EXYNOS5420_GPIO_D13,
	EXYNOS5420_GPIO_D14,
	EXYNOS5420_GPIO_D15,
	EXYNOS5420_GPIO_D16,
	EXYNOS5420_GPIO_D17,
	EXYNOS5420_GPIO_Y00,		/* 160 0xa0 */
	EXYNOS5420_GPIO_Y01,
	EXYNOS5420_GPIO_Y02,
	EXYNOS5420_GPIO_Y03,
	EXYNOS5420_GPIO_Y04,
	EXYNOS5420_GPIO_Y05,
	EXYNOS5420_GPIO_Y06,
	EXYNOS5420_GPIO_Y07,
	EXYNOS5420_GPIO_Y10,		/* 168 0xa8 */
	EXYNOS5420_GPIO_Y11,
	EXYNOS5420_GPIO_Y12,
	EXYNOS5420_GPIO_Y13,
	EXYNOS5420_GPIO_Y14,
	EXYNOS5420_GPIO_Y15,
	EXYNOS5420_GPIO_Y16,
	EXYNOS5420_GPIO_Y17,
	EXYNOS5420_GPIO_Y20,		/* 176 0xb0 */
	EXYNOS5420_GPIO_Y21,
	EXYNOS5420_GPIO_Y22,
	EXYNOS5420_GPIO_Y23,
	EXYNOS5420_GPIO_Y24,
	EXYNOS5420_GPIO_Y25,
	EXYNOS5420_GPIO_Y26,
	EXYNOS5420_GPIO_Y27,
	EXYNOS5420_GPIO_Y30,		/* 184 0xb8 */
	EXYNOS5420_GPIO_Y31,
	EXYNOS5420_GPIO_Y32,
	EXYNOS5420_GPIO_Y33,
	EXYNOS5420_GPIO_Y34,
	EXYNOS5420_GPIO_Y35,
	EXYNOS5420_GPIO_Y36,
	EXYNOS5420_GPIO_Y37,
	EXYNOS5420_GPIO_Y40,		/* 192 0xc0 */
	EXYNOS5420_GPIO_Y41,
	EXYNOS5420_GPIO_Y42,
	EXYNOS5420_GPIO_Y43,
	EXYNOS5420_GPIO_Y44,
	EXYNOS5420_GPIO_Y45,
	EXYNOS5420_GPIO_Y46,
	EXYNOS5420_GPIO_Y47,
	EXYNOS5420_GPIO_Y50,		/* 200 0xc8 */
	EXYNOS5420_GPIO_Y51,
	EXYNOS5420_GPIO_Y52,
	EXYNOS5420_GPIO_Y53,
	EXYNOS5420_GPIO_Y54,
	EXYNOS5420_GPIO_Y55,
	EXYNOS5420_GPIO_Y56,
	EXYNOS5420_GPIO_Y57,
	EXYNOS5420_GPIO_Y60,		/* 208 0xd0 */
	EXYNOS5420_GPIO_Y61,
	EXYNOS5420_GPIO_Y62,
	EXYNOS5420_GPIO_Y63,
	EXYNOS5420_GPIO_Y64,
	EXYNOS5420_GPIO_Y65,
	EXYNOS5420_GPIO_Y66,
	EXYNOS5420_GPIO_Y67,

	/* GPIO_PART5_STARTS */
	EXYNOS5420_GPIO_MAX_PORT_PART_4,/* 216 0xd8 */
	EXYNOS5420_GPIO_E00 = EXYNOS5420_GPIO_MAX_PORT_PART_4,
	EXYNOS5420_GPIO_E01,
	EXYNOS5420_GPIO_E02,
	EXYNOS5420_GPIO_E03,
	EXYNOS5420_GPIO_E04,
	EXYNOS5420_GPIO_E05,
	EXYNOS5420_GPIO_E06,
	EXYNOS5420_GPIO_E07,
	EXYNOS5420_GPIO_E10,		/* 224 0xe0 */
	EXYNOS5420_GPIO_E11,
	EXYNOS5420_GPIO_E12,
	EXYNOS5420_GPIO_E13,
	EXYNOS5420_GPIO_E14,
	EXYNOS5420_GPIO_E15,
	EXYNOS5420_GPIO_E16,
	EXYNOS5420_GPIO_E17,
	EXYNOS5420_GPIO_F00,		/* 232 0xe8 */
	EXYNOS5420_GPIO_F01,
	EXYNOS5420_GPIO_F02,
	EXYNOS5420_GPIO_F03,
	EXYNOS5420_GPIO_F04,
	EXYNOS5420_GPIO_F05,
	EXYNOS5420_GPIO_F06,
	EXYNOS5420_GPIO_F07,
	EXYNOS5420_GPIO_F10,		/* 240 0xf0 */
	EXYNOS5420_GPIO_F11,
	EXYNOS5420_GPIO_F12,
	EXYNOS5420_GPIO_F13,
	EXYNOS5420_GPIO_F14,
	EXYNOS5420_GPIO_F15,
	EXYNOS5420_GPIO_F16,
	EXYNOS5420_GPIO_F17,
	EXYNOS5420_GPIO_G00,		/* 248 0xf8 */
	EXYNOS5420_GPIO_G01,
	EXYNOS5420_GPIO_G02,
	EXYNOS5420_GPIO_G03,
	EXYNOS5420_GPIO_G04,
	EXYNOS5420_GPIO_G05,
	EXYNOS5420_GPIO_G06,
	EXYNOS5420_GPIO_G07,
	EXYNOS5420_GPIO_G10,		/* 256 0x100 */
	EXYNOS5420_GPIO_G11,
	EXYNOS5420_GPIO_G12,
	EXYNOS5420_GPIO_G13,
	EXYNOS5420_GPIO_G14,
	EXYNOS5420_GPIO_G15,
	EXYNOS5420_GPIO_G16,
	EXYNOS5420_GPIO_G17,
	EXYNOS5420_GPIO_G20,		/* 264 0x108 */
	EXYNOS5420_GPIO_G21,
	EXYNOS5420_GPIO_G22,
	EXYNOS5420_GPIO_G23,
	EXYNOS5420_GPIO_G24,
	EXYNOS5420_GPIO_G25,
	EXYNOS5420_GPIO_G26,
	EXYNOS5420_GPIO_G27,
	EXYNOS5420_GPIO_J40,		/* 272 0x110 */
	EXYNOS5420_GPIO_J41,
	EXYNOS5420_GPIO_J42,
	EXYNOS5420_GPIO_J43,
	EXYNOS5420_GPIO_J44,
	EXYNOS5420_GPIO_J45,
	EXYNOS5420_GPIO_J46,
	EXYNOS5420_GPIO_J47,

	/* GPIO_PART6_STARTS */
	EXYNOS5420_GPIO_MAX_PORT_PART_5,/* 280 0x118 */
	EXYNOS5420_GPIO_Z0 = EXYNOS5420_GPIO_MAX_PORT_PART_5,
	EXYNOS5420_GPIO_Z1,
	EXYNOS5420_GPIO_Z2,
	EXYNOS5420_GPIO_Z3,
	EXYNOS5420_GPIO_Z4,
	EXYNOS5420_GPIO_Z5,
	EXYNOS5420_GPIO_Z6,
	EXYNOS5420_GPIO_MAX_PORT
};

struct gpio_info {
	unsigned int reg_addr;	/* Address of register for this part */
	unsigned int max_gpio;	/* Maximum GPIO in this part */
};

#define EXYNOS4_GPIO_NUM_PARTS	3
static struct gpio_info exynos4_gpio_data[EXYNOS4_GPIO_NUM_PARTS] = {
	{ EXYNOS4_GPIO_PART1_BASE, EXYNOS4_GPIO_MAX_PORT_PART_1 },
	{ EXYNOS4_GPIO_PART2_BASE, EXYNOS4_GPIO_MAX_PORT_PART_2 },
	{ EXYNOS4_GPIO_PART3_BASE, EXYNOS4_GPIO_MAX_PORT },
};

#define EXYNOS4X12_GPIO_NUM_PARTS	4
static struct gpio_info exynos4x12_gpio_data[EXYNOS4X12_GPIO_NUM_PARTS] = {
	{ EXYNOS4X12_GPIO_PART1_BASE, EXYNOS4X12_GPIO_MAX_PORT_PART_1 },
	{ EXYNOS4X12_GPIO_PART2_BASE, EXYNOS4X12_GPIO_MAX_PORT_PART_2 },
	{ EXYNOS4X12_GPIO_PART3_BASE, EXYNOS4X12_GPIO_MAX_PORT_PART_3 },
	{ EXYNOS4X12_GPIO_PART4_BASE, EXYNOS4X12_GPIO_MAX_PORT },
};

#define EXYNOS5_GPIO_NUM_PARTS	8
static struct gpio_info exynos5_gpio_data[EXYNOS5_GPIO_NUM_PARTS] = {
	{ EXYNOS5_GPIO_PART1_BASE, EXYNOS5_GPIO_MAX_PORT_PART_1 },
	{ EXYNOS5_GPIO_PART2_BASE, EXYNOS5_GPIO_MAX_PORT_PART_2 },
	{ EXYNOS5_GPIO_PART3_BASE, EXYNOS5_GPIO_MAX_PORT_PART_3 },
	{ EXYNOS5_GPIO_PART4_BASE, EXYNOS5_GPIO_MAX_PORT_PART_4 },
	{ EXYNOS5_GPIO_PART5_BASE, EXYNOS5_GPIO_MAX_PORT_PART_5 },
	{ EXYNOS5_GPIO_PART6_BASE, EXYNOS5_GPIO_MAX_PORT_PART_6 },
	{ EXYNOS5_GPIO_PART7_BASE, EXYNOS5_GPIO_MAX_PORT_PART_7 },
	{ EXYNOS5_GPIO_PART8_BASE, EXYNOS5_GPIO_MAX_PORT },
};

#define EXYNOS5420_GPIO_NUM_PARTS	6
static struct gpio_info exynos5420_gpio_data[EXYNOS5420_GPIO_NUM_PARTS] = {
	{ EXYNOS5420_GPIO_PART1_BASE, EXYNOS5420_GPIO_MAX_PORT_PART_1 },
	{ EXYNOS5420_GPIO_PART2_BASE, EXYNOS5420_GPIO_MAX_PORT_PART_2 },
	{ EXYNOS5420_GPIO_PART3_BASE, EXYNOS5420_GPIO_MAX_PORT_PART_3 },
	{ EXYNOS5420_GPIO_PART4_BASE, EXYNOS5420_GPIO_MAX_PORT_PART_4 },
	{ EXYNOS5420_GPIO_PART5_BASE, EXYNOS5420_GPIO_MAX_PORT_PART_5 },
	{ EXYNOS5420_GPIO_PART6_BASE, EXYNOS5420_GPIO_MAX_PORT },
};

static inline struct gpio_info *get_gpio_data(void)
{
	if (cpu_is_exynos5()) {
		if (proid_is_exynos5420())
			return exynos5420_gpio_data;
		else
			return exynos5_gpio_data;
	} else if (cpu_is_exynos4()) {
		if (proid_is_exynos4412())
			return exynos4x12_gpio_data;
		else
			return exynos4_gpio_data;
	}

	return NULL;
}

static inline unsigned int get_bank_num(void)
{
	if (cpu_is_exynos5()) {
		if (proid_is_exynos5420())
			return EXYNOS5420_GPIO_NUM_PARTS;
		else
			return EXYNOS5_GPIO_NUM_PARTS;
	} else if (cpu_is_exynos4()) {
		if (proid_is_exynos4412())
			return EXYNOS4X12_GPIO_NUM_PARTS;
		else
			return EXYNOS4_GPIO_NUM_PARTS;
	}

	return 0;
}

/*
 * This structure helps mapping symbolic GPIO names into indices from
 * exynos5_gpio_pin/exynos5420_gpio_pin enums.
 *
 * By convention, symbolic GPIO name is defined as follows:
 *
 * g[p]<bank><set><bit>, where
 *   p is optional
 *   <bank> - a single character bank name, as defined by the SOC
 *   <set> - a single digit set number
 *   <bit> - bit number within the set (in 0..7 range).
 *
 * <set><bit> essentially form an octal number of the GPIO pin within the bank
 * space. On the 5420 architecture some banks' sets do not start not from zero
 * ('d' starts from 1 and 'j' starts from 4). To compensate for that and
 * maintain flat number space withoout holes, those banks use offsets to be
 * deducted from the pin number.
 */
struct gpio_name_num_table {
	char bank;		/* bank name symbol */
	unsigned int bank_size;		/* total number of pins in the bank */
	char bank_offset;	/* offset of the first bank's pin */
	unsigned int base;	/* index of the first bank's pin in the enum */
};

#define GPIO_ENTRY(name, base, top, offset) { name, top - base, offset, base }
static const struct gpio_name_num_table exynos4_gpio_table[] = {
	GPIO_ENTRY('a', EXYNOS4_GPIO_A00, EXYNOS4_GPIO_B0, 0),
	GPIO_ENTRY('b', EXYNOS4_GPIO_B0, EXYNOS4_GPIO_C00, 0),
	GPIO_ENTRY('c', EXYNOS4_GPIO_C00, EXYNOS4_GPIO_D00, 0),
	GPIO_ENTRY('d', EXYNOS4_GPIO_D00, EXYNOS4_GPIO_E00, 0),
	GPIO_ENTRY('e', EXYNOS4_GPIO_E00, EXYNOS4_GPIO_F00, 0),
	GPIO_ENTRY('f', EXYNOS4_GPIO_F00, EXYNOS4_GPIO_J00, 0),
	GPIO_ENTRY('j', EXYNOS4_GPIO_J00, EXYNOS4_GPIO_K00, 0),
	GPIO_ENTRY('k', EXYNOS4_GPIO_K00, EXYNOS4_GPIO_L00, 0),
	GPIO_ENTRY('l', EXYNOS4_GPIO_L00, EXYNOS4_GPIO_Y00, 0),
	GPIO_ENTRY('y', EXYNOS4_GPIO_Y00, EXYNOS4_GPIO_X00, 0),
	GPIO_ENTRY('x', EXYNOS4_GPIO_X00, EXYNOS4_GPIO_Z0, 0),
	GPIO_ENTRY('z', EXYNOS4_GPIO_Z0, EXYNOS4_GPIO_MAX_PORT, 0),
	{ 0 }
};

static const struct gpio_name_num_table exynos4x12_gpio_table[] = {
	GPIO_ENTRY('a', EXYNOS4X12_GPIO_A00, EXYNOS4X12_GPIO_B0, 0),
	GPIO_ENTRY('b', EXYNOS4X12_GPIO_B0, EXYNOS4X12_GPIO_C00, 0),
	GPIO_ENTRY('c', EXYNOS4X12_GPIO_C00, EXYNOS4X12_GPIO_D00, 0),
	GPIO_ENTRY('d', EXYNOS4X12_GPIO_D00, EXYNOS4X12_GPIO_F00, 0),
	GPIO_ENTRY('f', EXYNOS4X12_GPIO_F00, EXYNOS4X12_GPIO_J00, 0),
	GPIO_ENTRY('j', EXYNOS4X12_GPIO_J00, EXYNOS4X12_GPIO_K00, 0),
	GPIO_ENTRY('k', EXYNOS4X12_GPIO_K00, EXYNOS4X12_GPIO_L00, 0),
	GPIO_ENTRY('l', EXYNOS4X12_GPIO_L00, EXYNOS4X12_GPIO_Y00, 0),
	GPIO_ENTRY('y', EXYNOS4X12_GPIO_Y00, EXYNOS4X12_GPIO_M00, 0),
	GPIO_ENTRY('m', EXYNOS4X12_GPIO_M00, EXYNOS4X12_GPIO_X00, 0),
	GPIO_ENTRY('x', EXYNOS4X12_GPIO_X00, EXYNOS4X12_GPIO_Z0, 0),
	GPIO_ENTRY('z', EXYNOS4X12_GPIO_Z0, EXYNOS4X12_GPIO_V00, 0),
	GPIO_ENTRY('v', EXYNOS4X12_GPIO_V00, EXYNOS4X12_GPIO_MAX_PORT, 0),
	{ 0 }
};

static const struct gpio_name_num_table exynos5_gpio_table[] = {
	GPIO_ENTRY('a', EXYNOS5_GPIO_A00, EXYNOS5_GPIO_B00, 0),
	GPIO_ENTRY('b', EXYNOS5_GPIO_B00, EXYNOS5_GPIO_C00, 0),
	GPIO_ENTRY('c', EXYNOS5_GPIO_C00, EXYNOS5_GPIO_D00, 0),
	GPIO_ENTRY('d', EXYNOS5_GPIO_D00, EXYNOS5_GPIO_Y00, 0),
	GPIO_ENTRY('y', EXYNOS5_GPIO_Y00, EXYNOS5_GPIO_C40, 0),
	GPIO_ENTRY('x', EXYNOS5_GPIO_X00, EXYNOS5_GPIO_E00, 0),
	GPIO_ENTRY('e', EXYNOS5_GPIO_E00, EXYNOS5_GPIO_F00, 0),
	GPIO_ENTRY('f', EXYNOS5_GPIO_F00, EXYNOS5_GPIO_G00, 0),
	GPIO_ENTRY('g', EXYNOS5_GPIO_G00, EXYNOS5_GPIO_H00, 0),
	GPIO_ENTRY('h', EXYNOS5_GPIO_H00, EXYNOS5_GPIO_V00, 0),
	GPIO_ENTRY('v', EXYNOS5_GPIO_V00, EXYNOS5_GPIO_Z0, 0),
	GPIO_ENTRY('z', EXYNOS5_GPIO_Z0, EXYNOS5_GPIO_MAX_PORT, 0),
	{ 0 }
};

static const struct gpio_name_num_table exynos5420_gpio_table[] = {
	GPIO_ENTRY('a', EXYNOS5420_GPIO_A00, EXYNOS5420_GPIO_B00, 0),
	GPIO_ENTRY('b', EXYNOS5420_GPIO_B00, EXYNOS5420_GPIO_H00, 0),
	GPIO_ENTRY('h', EXYNOS5420_GPIO_H00, EXYNOS5420_GPIO_Y70, 0),
	GPIO_ENTRY('x', EXYNOS5420_GPIO_X00, EXYNOS5420_GPIO_C00, 0),
	GPIO_ENTRY('c', EXYNOS5420_GPIO_C00, EXYNOS5420_GPIO_D10, 0),
	GPIO_ENTRY('d', EXYNOS5420_GPIO_D10, EXYNOS5420_GPIO_Y00, 010),
	GPIO_ENTRY('y', EXYNOS5420_GPIO_Y00, EXYNOS5420_GPIO_E00, 0),
	GPIO_ENTRY('e', EXYNOS5420_GPIO_E00, EXYNOS5420_GPIO_F00, 0),
	GPIO_ENTRY('f', EXYNOS5420_GPIO_F00, EXYNOS5420_GPIO_G00, 0),
	GPIO_ENTRY('g', EXYNOS5420_GPIO_G00, EXYNOS5420_GPIO_J40, 0),
	GPIO_ENTRY('j', EXYNOS5420_GPIO_J40, EXYNOS5420_GPIO_Z0, 040),
	GPIO_ENTRY('z', EXYNOS5420_GPIO_Z0, EXYNOS5420_GPIO_MAX_PORT, 0),
	{ 0 }
};

void gpio_cfg_pin(int gpio, int cfg);
void gpio_set_pull(int gpio, int mode);
void gpio_set_drv(int gpio, int mode);
int gpio_direction_input(unsigned gpio);
int gpio_direction_output(unsigned gpio, int value);
int gpio_set_value(unsigned gpio, int value);
int gpio_get_value(unsigned gpio);
void gpio_set_rate(int gpio, int mode);
struct s5p_gpio_bank *s5p_gpio_get_bank(unsigned gpio);
int s5p_gpio_get_pin(unsigned gpio);
#endif

/* Pin configurations */
#define S5P_GPIO_INPUT	0x0
#define S5P_GPIO_OUTPUT	0x1
#define S5P_GPIO_IRQ	0xf
#define S5P_GPIO_FUNC(x)	(x)

/* Pull mode */
#define S5P_GPIO_PULL_NONE	0x0
#define S5P_GPIO_PULL_DOWN	0x1
#define S5P_GPIO_PULL_UP	0x3

/* Drive Strength level */
#define S5P_GPIO_DRV_1X	0x0
#define S5P_GPIO_DRV_3X	0x1
#define S5P_GPIO_DRV_2X	0x2
#define S5P_GPIO_DRV_4X	0x3
#define S5P_GPIO_DRV_FAST	0x0
#define S5P_GPIO_DRV_SLOW	0x1
#endif
