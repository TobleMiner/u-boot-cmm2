// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) Xilinx, Inc.
 */

#include <asm/arch/ps7_init_gpl.h>

unsigned long ps7_pll_init_data_3_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: PLL SLCR REGISTERS */
	/* .. .. START: ARM PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000110[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000110[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x177 */
	/* .. .. ==> 0XF8000110[21:12] = 0x00000177U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00177000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000110, 0x003FFFF0U, 0x001772C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x1a */
	/* .. .. .. ==> 0XF8000100[18:12] = 0x0000001AU */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x0001A000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x0007F000U, 0x0001A000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000100[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000100[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000100[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. ARM_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000001U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000100[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. .. SRCSEL = 0x0 */
	/* .. .. .. ==> 0XF8000120[5:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. .. DIVISOR = 0x2 */
	/* .. .. .. ==> 0XF8000120[13:8] = 0x00000002U */
	/* .. .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000200U */
	/* .. .. .. CPU_6OR4XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[24:24] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x01000000U    VAL : 0x01000000U */
	/* .. .. .. CPU_3OR2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[25:25] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x02000000U    VAL : 0x02000000U */
	/* .. .. .. CPU_2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[26:26] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x04000000U    VAL : 0x04000000U */
	/* .. .. .. CPU_1XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[27:27] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x08000000U    VAL : 0x08000000U */
	/* .. .. .. CPU_PERI_CLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[28:28] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000120, 0x1F003F30U, 0x1F000200U),
	/* .. .. FINISH: ARM PLL INIT */
	/* .. .. START: DDR PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000114[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000114[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x1db */
	/* .. .. ==> 0XF8000114[21:12] = 0x000001DBU */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x001DB000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000114, 0x003FFFF0U, 0x001DB2C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x15 */
	/* .. .. .. ==> 0XF8000104[18:12] = 0x00000015U */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x00015000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x0007F000U, 0x00015000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000104[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000104[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000104[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. DDR_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[1:1] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000002U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000104[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. .. DDR_3XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000124[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. DDR_2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000124[1:1] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. .. DDR_3XCLK_DIVISOR = 0x2 */
	/* .. .. .. ==> 0XF8000124[25:20] = 0x00000002U */
	/* .. .. ..     ==> MASK : 0x03F00000U    VAL : 0x00200000U */
	/* .. .. .. DDR_2XCLK_DIVISOR = 0x3 */
	/* .. .. .. ==> 0XF8000124[31:26] = 0x00000003U */
	/* .. .. ..     ==> MASK : 0xFC000000U    VAL : 0x0C000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000124, 0xFFF00003U, 0x0C200003U),
	/* .. .. FINISH: DDR PLL INIT */
	/* .. .. START: IO PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000118[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000118[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x1f4 */
	/* .. .. ==> 0XF8000118[21:12] = 0x000001F4U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x001F4000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000118, 0x003FFFF0U, 0x001F42C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x14 */
	/* .. .. .. ==> 0XF8000108[18:12] = 0x00000014U */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x00014000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x0007F000U, 0x00014000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000108[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000108[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000108[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. IO_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[2:2] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000004U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000108[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. FINISH: IO PLL INIT */
	/* .. FINISH: PLL SLCR REGISTERS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_clock_init_data_3_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: CLOCK CONTROL SLCR REGISTERS */
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000128[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. DIVISOR0 = 0x34 */
	/* .. ==> 0XF8000128[13:8] = 0x00000034U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00003400U */
	/* .. DIVISOR1 = 0x2 */
	/* .. ==> 0XF8000128[25:20] = 0x00000002U */
	/* ..     ==> MASK : 0x03F00000U    VAL : 0x00200000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000128, 0x03F03F01U, 0x00203401U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000138[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000138[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000138, 0x00000011U, 0x00000001U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000140[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000140[6:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x8 */
	/* .. ==> 0XF8000140[13:8] = 0x00000008U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000800U */
	/* .. DIVISOR1 = 0x1 */
	/* .. ==> 0XF8000140[25:20] = 0x00000001U */
	/* ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000140, 0x03F03F71U, 0x00100801U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF800014C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF800014C[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x5 */
	/* .. ==> 0XF800014C[13:8] = 0x00000005U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. */
	EMIT_MASKWRITE(0XF800014C, 0x00003F31U, 0x00000501U),
	/* .. CLKACT0 = 0x1 */
	/* .. ==> 0XF8000150[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. CLKACT1 = 0x0 */
	/* .. ==> 0XF8000150[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000150[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x14 */
	/* .. ==> 0XF8000150[13:8] = 0x00000014U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00001400U */
	/* .. */
	EMIT_MASKWRITE(0XF8000150, 0x00003F33U, 0x00001401U),
	/* .. CLKACT0 = 0x0 */
	/* .. ==> 0XF8000154[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. CLKACT1 = 0x1 */
	/* .. ==> 0XF8000154[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000154[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0xa */
	/* .. ==> 0XF8000154[13:8] = 0x0000000AU */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000A00U */
	/* .. */
	EMIT_MASKWRITE(0XF8000154, 0x00003F33U, 0x00000A02U),
	/* .. .. START: TRACE CLOCK */
	/* .. .. FINISH: TRACE CLOCK */
	/* .. .. CLKACT = 0x1 */
	/* .. .. ==> 0XF8000168[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000168[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR = 0x5 */
	/* .. .. ==> 0XF8000168[13:8] = 0x00000005U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000168, 0x00003F31U, 0x00000501U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000170[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0xa */
	/* .. .. ==> 0XF8000170[13:8] = 0x0000000AU */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000A00U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000170[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000170, 0x03F03F30U, 0x00100A00U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000180[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x7 */
	/* .. .. ==> 0XF8000180[13:8] = 0x00000007U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000700U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000180[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000180, 0x03F03F30U, 0x00100700U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000190[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x5 */
	/* .. .. ==> 0XF8000190[13:8] = 0x00000005U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000190[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000190, 0x03F03F30U, 0x00100500U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF80001A0[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x14 */
	/* .. .. ==> 0XF80001A0[13:8] = 0x00000014U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00001400U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF80001A0[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80001A0, 0x03F03F30U, 0x00101400U),
	/* .. .. CLK_621_TRUE = 0x1 */
	/* .. .. ==> 0XF80001C4[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80001C4, 0x00000001U, 0x00000001U),
	/* .. .. DMA_CPU_2XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. USB0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[2:2] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. .. USB1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[3:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. .. GEM0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[6:6] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000040U */
	/* .. .. GEM1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. SDI0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[10:10] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000400U */
	/* .. .. SDI1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. SPI0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. SPI1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. CAN0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. CAN1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. I2C0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[18:18] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00040000U */
	/* .. .. I2C1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. UART0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. UART1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[21:21] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00200000U */
	/* .. .. GPIO_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[22:22] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00400000U */
	/* .. .. LQSPI_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[23:23] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00800000U */
	/* .. .. SMC_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[24:24] = 0x00000001U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x01000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800012C, 0x01FFCCCDU, 0x01EC044DU),
	/* .. FINISH: CLOCK CONTROL SLCR REGISTERS */
	/* .. START: THIS SHOULD BE BLANK */
	/* .. FINISH: THIS SHOULD BE BLANK */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_ddr_init_data_3_0[] = {
	/* START: top */
	/* .. START: DDR INITIALIZATION */
	/* .. .. START: LOCK DDR */
	/* .. .. reg_ddrc_soft_rstb = 0 */
	/* .. .. ==> 0XF8006000[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_powerdown_en = 0x0 */
	/* .. .. ==> 0XF8006000[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_data_bus_width = 0x0 */
	/* .. .. ==> 0XF8006000[3:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000CU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_burst8_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[6:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rdwr_idle_gap = 0x1 */
	/* .. .. ==> 0XF8006000[13:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003F80U    VAL : 0x00000080U */
	/* .. .. reg_ddrc_dis_rd_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_act_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_auto_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000080U),
	/* .. .. FINISH: LOCK DDR */
	/* .. .. reg_ddrc_t_rfc_nom_x32 = 0x7f */
	/* .. .. ==> 0XF8006004[11:0] = 0x0000007FU */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x0000007FU */
	/* .. .. reserved_reg_ddrc_active_ranks = 0x1 */
	/* .. .. ==> 0XF8006004[13:12] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003000U    VAL : 0x00001000U */
	/* .. .. reg_ddrc_addrmap_cs_bit0 = 0x0 */
	/* .. .. ==> 0XF8006004[18:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0007C000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006004, 0x0007FFFFU, 0x0000107FU),
	/* .. .. reg_ddrc_hpr_min_non_critical_x32 = 0xf */
	/* .. .. ==> 0XF8006008[10:0] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x0000000FU */
	/* .. .. reg_ddrc_hpr_max_starve_x32 = 0xf */
	/* .. .. ==> 0XF8006008[21:11] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x003FF800U    VAL : 0x00007800U */
	/* .. .. reg_ddrc_hpr_xact_run_length = 0xf */
	/* .. .. ==> 0XF8006008[25:22] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x03C00000U    VAL : 0x03C00000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006008, 0x03FFFFFFU, 0x03C0780FU),
	/* .. .. reg_ddrc_lpr_min_non_critical_x32 = 0x1 */
	/* .. .. ==> 0XF800600C[10:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_lpr_max_starve_x32 = 0x2 */
	/* .. .. ==> 0XF800600C[21:11] = 0x00000002U */
	/* .. ..     ==> MASK : 0x003FF800U    VAL : 0x00001000U */
	/* .. .. reg_ddrc_lpr_xact_run_length = 0x8 */
	/* .. .. ==> 0XF800600C[25:22] = 0x00000008U */
	/* .. ..     ==> MASK : 0x03C00000U    VAL : 0x02000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800600C, 0x03FFFFFFU, 0x02001001U),
	/* .. .. reg_ddrc_w_min_non_critical_x32 = 0x1 */
	/* .. .. ==> 0XF8006010[10:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_w_xact_run_length = 0x8 */
	/* .. .. ==> 0XF8006010[14:11] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00007800U    VAL : 0x00004000U */
	/* .. .. reg_ddrc_w_max_starve_x32 = 0x2 */
	/* .. .. ==> 0XF8006010[25:15] = 0x00000002U */
	/* .. ..     ==> MASK : 0x03FF8000U    VAL : 0x00010000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006010, 0x03FFFFFFU, 0x00014001U),
	/* .. .. reg_ddrc_t_rc = 0x1a */
	/* .. .. ==> 0XF8006014[5:0] = 0x0000001AU */
	/* .. ..     ==> MASK : 0x0000003FU    VAL : 0x0000001AU */
	/* .. .. reg_ddrc_t_rfc_min = 0x54 */
	/* .. .. ==> 0XF8006014[13:6] = 0x00000054U */
	/* .. ..     ==> MASK : 0x00003FC0U    VAL : 0x00001500U */
	/* .. .. reg_ddrc_post_selfref_gap_x32 = 0x10 */
	/* .. .. ==> 0XF8006014[20:14] = 0x00000010U */
	/* .. ..     ==> MASK : 0x001FC000U    VAL : 0x00040000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006014, 0x001FFFFFU, 0x0004151AU),
	/* .. .. reg_ddrc_wr2pre = 0x12 */
	/* .. .. ==> 0XF8006018[4:0] = 0x00000012U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000012U */
	/* .. .. reg_ddrc_powerdown_to_x32 = 0x6 */
	/* .. .. ==> 0XF8006018[9:5] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x000000C0U */
	/* .. .. reg_ddrc_t_faw = 0x15 */
	/* .. .. ==> 0XF8006018[15:10] = 0x00000015U */
	/* .. ..     ==> MASK : 0x0000FC00U    VAL : 0x00005400U */
	/* .. .. reg_ddrc_t_ras_max = 0x23 */
	/* .. .. ==> 0XF8006018[21:16] = 0x00000023U */
	/* .. ..     ==> MASK : 0x003F0000U    VAL : 0x00230000U */
	/* .. .. reg_ddrc_t_ras_min = 0x13 */
	/* .. .. ==> 0XF8006018[26:22] = 0x00000013U */
	/* .. ..     ==> MASK : 0x07C00000U    VAL : 0x04C00000U */
	/* .. .. reg_ddrc_t_cke = 0x4 */
	/* .. .. ==> 0XF8006018[31:28] = 0x00000004U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006018, 0xF7FFFFFFU, 0x44E354D2U),
	/* .. .. reg_ddrc_write_latency = 0x5 */
	/* .. .. ==> 0XF800601C[4:0] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000005U */
	/* .. .. reg_ddrc_rd2wr = 0x7 */
	/* .. .. ==> 0XF800601C[9:5] = 0x00000007U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x000000E0U */
	/* .. .. reg_ddrc_wr2rd = 0xe */
	/* .. .. ==> 0XF800601C[14:10] = 0x0000000EU */
	/* .. ..     ==> MASK : 0x00007C00U    VAL : 0x00003800U */
	/* .. .. reg_ddrc_t_xp = 0x4 */
	/* .. .. ==> 0XF800601C[19:15] = 0x00000004U */
	/* .. ..     ==> MASK : 0x000F8000U    VAL : 0x00020000U */
	/* .. .. reg_ddrc_pad_pd = 0x0 */
	/* .. .. ==> 0XF800601C[22:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00700000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rd2pre = 0x4 */
	/* .. .. ==> 0XF800601C[27:23] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0F800000U    VAL : 0x02000000U */
	/* .. .. reg_ddrc_t_rcd = 0x7 */
	/* .. .. ==> 0XF800601C[31:28] = 0x00000007U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x70000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800601C, 0xFFFFFFFFU, 0x720238E5U),
	/* .. .. reg_ddrc_t_ccd = 0x4 */
	/* .. .. ==> 0XF8006020[4:2] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0000001CU    VAL : 0x00000010U */
	/* .. .. reg_ddrc_t_rrd = 0x6 */
	/* .. .. ==> 0XF8006020[7:5] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000000E0U    VAL : 0x000000C0U */
	/* .. .. reg_ddrc_refresh_margin = 0x2 */
	/* .. .. ==> 0XF8006020[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_t_rp = 0x7 */
	/* .. .. ==> 0XF8006020[15:12] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00007000U */
	/* .. .. reg_ddrc_refresh_to_x32 = 0x8 */
	/* .. .. ==> 0XF8006020[20:16] = 0x00000008U */
	/* .. ..     ==> MASK : 0x001F0000U    VAL : 0x00080000U */
	/* .. .. reg_ddrc_mobile = 0x0 */
	/* .. .. ==> 0XF8006020[22:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_en_dfi_dram_clk_disable = 0x0 */
	/* .. .. ==> 0XF8006020[23:23] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_read_latency = 0x7 */
	/* .. .. ==> 0XF8006020[28:24] = 0x00000007U */
	/* .. ..     ==> MASK : 0x1F000000U    VAL : 0x07000000U */
	/* .. .. reg_phy_mode_ddr1_ddr2 = 0x1 */
	/* .. .. ==> 0XF8006020[29:29] = 0x00000001U */
	/* .. ..     ==> MASK : 0x20000000U    VAL : 0x20000000U */
	/* .. .. reg_ddrc_dis_pad_pd = 0x0 */
	/* .. .. ==> 0XF8006020[30:30] = 0x00000000U */
	/* .. ..     ==> MASK : 0x40000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006020, 0x7FDFFFFCU, 0x270872D0U),
	/* .. .. reg_ddrc_en_2t_timing_mode = 0x0 */
	/* .. .. ==> 0XF8006024[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_prefer_write = 0x0 */
	/* .. .. ==> 0XF8006024[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_wr = 0x0 */
	/* .. .. ==> 0XF8006024[6:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_addr = 0x0 */
	/* .. .. ==> 0XF8006024[8:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000180U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_data = 0x0 */
	/* .. .. ==> 0XF8006024[24:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01FFFE00U    VAL : 0x00000000U */
	/* .. .. ddrc_reg_mr_wr_busy = 0x0 */
	/* .. .. ==> 0XF8006024[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_type = 0x0 */
	/* .. .. ==> 0XF8006024[26:26] = 0x00000000U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_rdata_valid = 0x0 */
	/* .. .. ==> 0XF8006024[27:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006024, 0x0FFFFFC3U, 0x00000000U),
	/* .. .. reg_ddrc_final_wait_x32 = 0x7 */
	/* .. .. ==> 0XF8006028[6:0] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000007FU    VAL : 0x00000007U */
	/* .. .. reg_ddrc_pre_ocd_x32 = 0x0 */
	/* .. .. ==> 0XF8006028[10:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000780U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_t_mrd = 0x4 */
	/* .. .. ==> 0XF8006028[13:11] = 0x00000004U */
	/* .. ..     ==> MASK : 0x00003800U    VAL : 0x00002000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006028, 0x00003FFFU, 0x00002007U),
	/* .. .. reg_ddrc_emr2 = 0x8 */
	/* .. .. ==> 0XF800602C[15:0] = 0x00000008U */
	/* .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000008U */
	/* .. .. reg_ddrc_emr3 = 0x0 */
	/* .. .. ==> 0XF800602C[31:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFF0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800602C, 0xFFFFFFFFU, 0x00000008U),
	/* .. .. reg_ddrc_mr = 0x930 */
	/* .. .. ==> 0XF8006030[15:0] = 0x00000930U */
	/* .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000930U */
	/* .. .. reg_ddrc_emr = 0x4 */
	/* .. .. ==> 0XF8006030[31:16] = 0x00000004U */
	/* .. ..     ==> MASK : 0xFFFF0000U    VAL : 0x00040000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006030, 0xFFFFFFFFU, 0x00040930U),
	/* .. .. reg_ddrc_burst_rdwr = 0x4 */
	/* .. .. ==> 0XF8006034[3:0] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000004U */
	/* .. .. reg_ddrc_pre_cke_x1024 = 0x167 */
	/* .. .. ==> 0XF8006034[13:4] = 0x00000167U */
	/* .. ..     ==> MASK : 0x00003FF0U    VAL : 0x00001670U */
	/* .. .. reg_ddrc_post_cke_x1024 = 0x1 */
	/* .. .. ==> 0XF8006034[25:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03FF0000U    VAL : 0x00010000U */
	/* .. .. reg_ddrc_burstchop = 0x0 */
	/* .. .. ==> 0XF8006034[28:28] = 0x00000000U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006034, 0x13FF3FFFU, 0x00011674U),
	/* .. .. reg_ddrc_force_low_pri_n = 0x0 */
	/* .. .. ==> 0XF8006038[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_dq = 0x0 */
	/* .. .. ==> 0XF8006038[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006038, 0x00000003U, 0x00000000U),
	/* .. .. reg_ddrc_addrmap_bank_b0 = 0x7 */
	/* .. .. ==> 0XF800603C[3:0] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000007U */
	/* .. .. reg_ddrc_addrmap_bank_b1 = 0x7 */
	/* .. .. ==> 0XF800603C[7:4] = 0x00000007U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000070U */
	/* .. .. reg_ddrc_addrmap_bank_b2 = 0x7 */
	/* .. .. ==> 0XF800603C[11:8] = 0x00000007U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000700U */
	/* .. .. reg_ddrc_addrmap_col_b5 = 0x0 */
	/* .. .. ==> 0XF800603C[15:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b6 = 0x0 */
	/* .. .. ==> 0XF800603C[19:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800603C, 0x000FFFFFU, 0x00000777U),
	/* .. .. reg_ddrc_addrmap_col_b2 = 0x0 */
	/* .. .. ==> 0XF8006040[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b3 = 0x0 */
	/* .. .. ==> 0XF8006040[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b4 = 0x0 */
	/* .. .. ==> 0XF8006040[11:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b7 = 0x0 */
	/* .. .. ==> 0XF8006040[15:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b8 = 0x0 */
	/* .. .. ==> 0XF8006040[19:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b9 = 0xf */
	/* .. .. ==> 0XF8006040[23:20] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00F00000U    VAL : 0x00F00000U */
	/* .. .. reg_ddrc_addrmap_col_b10 = 0xf */
	/* .. .. ==> 0XF8006040[27:24] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x0F000000U */
	/* .. .. reg_ddrc_addrmap_col_b11 = 0xf */
	/* .. .. ==> 0XF8006040[31:28] = 0x0000000FU */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0xF0000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006040, 0xFFFFFFFFU, 0xFFF00000U),
	/* .. .. reg_ddrc_addrmap_row_b0 = 0x6 */
	/* .. .. ==> 0XF8006044[3:0] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000006U */
	/* .. .. reg_ddrc_addrmap_row_b1 = 0x6 */
	/* .. .. ==> 0XF8006044[7:4] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000060U */
	/* .. .. reg_ddrc_addrmap_row_b2_11 = 0x6 */
	/* .. .. ==> 0XF8006044[11:8] = 0x00000006U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000600U */
	/* .. .. reg_ddrc_addrmap_row_b12 = 0x6 */
	/* .. .. ==> 0XF8006044[15:12] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00006000U */
	/* .. .. reg_ddrc_addrmap_row_b13 = 0x6 */
	/* .. .. ==> 0XF8006044[19:16] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00060000U */
	/* .. .. reg_ddrc_addrmap_row_b14 = 0xf */
	/* .. .. ==> 0XF8006044[23:20] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00F00000U    VAL : 0x00F00000U */
	/* .. .. reg_ddrc_addrmap_row_b15 = 0xf */
	/* .. .. ==> 0XF8006044[27:24] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x0F000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006044, 0x0FFFFFFFU, 0x0FF66666U),
	/* .. .. reg_phy_rd_local_odt = 0x0 */
	/* .. .. ==> 0XF8006048[13:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00003000U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_local_odt = 0x3 */
	/* .. .. ==> 0XF8006048[15:14] = 0x00000003U */
	/* .. ..     ==> MASK : 0x0000C000U    VAL : 0x0000C000U */
	/* .. .. reg_phy_idle_local_odt = 0x3 */
	/* .. .. ==> 0XF8006048[17:16] = 0x00000003U */
	/* .. ..     ==> MASK : 0x00030000U    VAL : 0x00030000U */
	/* .. .. reserved_reg_ddrc_rank0_wr_odt = 0x1 */
	/* .. .. ==> 0XF8006048[5:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000038U    VAL : 0x00000008U */
	/* .. .. reserved_reg_ddrc_rank0_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[2:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006048, 0x0003F03FU, 0x0003C008U),
	/* .. .. reg_phy_rd_cmd_to_data = 0x0 */
	/* .. .. ==> 0XF8006050[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_cmd_to_data = 0x0 */
	/* .. .. ==> 0XF8006050[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_phy_rdc_we_to_re_delay = 0x8 */
	/* .. .. ==> 0XF8006050[11:8] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000800U */
	/* .. .. reg_phy_rdc_fifo_rst_disable = 0x0 */
	/* .. .. ==> 0XF8006050[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_phy_use_fixed_re = 0x1 */
	/* .. .. ==> 0XF8006050[16:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00010000U */
	/* .. .. reg_phy_rdc_fifo_rst_err_cnt_clr = 0x0 */
	/* .. .. ==> 0XF8006050[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dis_phy_ctrl_rstn = 0x0 */
	/* .. .. ==> 0XF8006050[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_phy_clk_stall_level = 0x0 */
	/* .. .. ==> 0XF8006050[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_num_of_dq0 = 0x7 */
	/* .. .. ==> 0XF8006050[27:24] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x07000000U */
	/* .. .. reg_phy_wrlvl_num_of_dq0 = 0x7 */
	/* .. .. ==> 0XF8006050[31:28] = 0x00000007U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x70000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006050, 0xFF0F8FFFU, 0x77010800U),
	/* .. .. reg_ddrc_dis_dll_calib = 0x0 */
	/* .. .. ==> 0XF8006058[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006058, 0x00010000U, 0x00000000U),
	/* .. .. reg_ddrc_rd_odt_delay = 0x3 */
	/* .. .. ==> 0XF800605C[3:0] = 0x00000003U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000003U */
	/* .. .. reg_ddrc_wr_odt_delay = 0x0 */
	/* .. .. ==> 0XF800605C[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rd_odt_hold = 0x0 */
	/* .. .. ==> 0XF800605C[11:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_wr_odt_hold = 0x5 */
	/* .. .. ==> 0XF800605C[15:12] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00005000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800605C, 0x0000FFFFU, 0x00005003U),
	/* .. .. reg_ddrc_pageclose = 0x0 */
	/* .. .. ==> 0XF8006060[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_lpr_num_entries = 0x1f */
	/* .. .. ==> 0XF8006060[6:1] = 0x0000001FU */
	/* .. ..     ==> MASK : 0x0000007EU    VAL : 0x0000003EU */
	/* .. .. reg_ddrc_auto_pre_en = 0x0 */
	/* .. .. ==> 0XF8006060[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_refresh_update_level = 0x0 */
	/* .. .. ==> 0XF8006060[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_wc = 0x0 */
	/* .. .. ==> 0XF8006060[9:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_collision_page_opt = 0x0 */
	/* .. .. ==> 0XF8006060[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_selfref_en = 0x0 */
	/* .. .. ==> 0XF8006060[12:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006060, 0x000017FFU, 0x0000003EU),
	/* .. .. reg_ddrc_go2critical_hysteresis = 0x0 */
	/* .. .. ==> 0XF8006064[12:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001FE0U    VAL : 0x00000000U */
	/* .. .. reg_arb_go2critical_en = 0x1 */
	/* .. .. ==> 0XF8006064[17:17] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00020000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006064, 0x00021FE0U, 0x00020000U),
	/* .. .. reg_ddrc_wrlvl_ww = 0x41 */
	/* .. .. ==> 0XF8006068[7:0] = 0x00000041U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000041U */
	/* .. .. reg_ddrc_rdlvl_rr = 0x41 */
	/* .. .. ==> 0XF8006068[15:8] = 0x00000041U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00004100U */
	/* .. .. reg_ddrc_dfi_t_wlmrd = 0x28 */
	/* .. .. ==> 0XF8006068[25:16] = 0x00000028U */
	/* .. ..     ==> MASK : 0x03FF0000U    VAL : 0x00280000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006068, 0x03FFFFFFU, 0x00284141U),
	/* .. .. dfi_t_ctrlupd_interval_min_x1024 = 0x10 */
	/* .. .. ==> 0XF800606C[7:0] = 0x00000010U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000010U */
	/* .. .. dfi_t_ctrlupd_interval_max_x1024 = 0x16 */
	/* .. .. ==> 0XF800606C[15:8] = 0x00000016U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00001600U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800606C, 0x0000FFFFU, 0x00001610U),
	/* .. .. reg_ddrc_dfi_t_ctrl_delay = 0x1 */
	/* .. .. ==> 0XF8006078[3:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_dfi_t_dram_clk_disable = 0x1 */
	/* .. .. ==> 0XF8006078[7:4] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000010U */
	/* .. .. reg_ddrc_dfi_t_dram_clk_enable = 0x1 */
	/* .. .. ==> 0XF8006078[11:8] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000100U */
	/* .. .. reg_ddrc_t_cksre = 0x6 */
	/* .. .. ==> 0XF8006078[15:12] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00006000U */
	/* .. .. reg_ddrc_t_cksrx = 0x6 */
	/* .. .. ==> 0XF8006078[19:16] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00060000U */
	/* .. .. reg_ddrc_t_ckesr = 0x4 */
	/* .. .. ==> 0XF8006078[25:20] = 0x00000004U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00400000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006078, 0x03FFFFFFU, 0x00466111U),
	/* .. .. reg_ddrc_t_ckpde = 0x2 */
	/* .. .. ==> 0XF800607C[3:0] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000002U */
	/* .. .. reg_ddrc_t_ckpdx = 0x2 */
	/* .. .. ==> 0XF800607C[7:4] = 0x00000002U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000020U */
	/* .. .. reg_ddrc_t_ckdpde = 0x2 */
	/* .. .. ==> 0XF800607C[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_t_ckdpdx = 0x2 */
	/* .. .. ==> 0XF800607C[15:12] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00002000U */
	/* .. .. reg_ddrc_t_ckcsx = 0x3 */
	/* .. .. ==> 0XF800607C[19:16] = 0x00000003U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00030000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800607C, 0x000FFFFFU, 0x00032222U),
	/* .. .. reg_ddrc_dis_auto_zq = 0x0 */
	/* .. .. ==> 0XF80060A4[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_ddr3 = 0x1 */
	/* .. .. ==> 0XF80060A4[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. reg_ddrc_t_mod = 0x200 */
	/* .. .. ==> 0XF80060A4[11:2] = 0x00000200U */
	/* .. ..     ==> MASK : 0x00000FFCU    VAL : 0x00000800U */
	/* .. .. reg_ddrc_t_zq_long_nop = 0x200 */
	/* .. .. ==> 0XF80060A4[21:12] = 0x00000200U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00200000U */
	/* .. .. reg_ddrc_t_zq_short_nop = 0x40 */
	/* .. .. ==> 0XF80060A4[31:22] = 0x00000040U */
	/* .. ..     ==> MASK : 0xFFC00000U    VAL : 0x10000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A4, 0xFFFFFFFFU, 0x10200802U),
	/* .. .. t_zq_short_interval_x1024 = 0xc845 */
	/* .. .. ==> 0XF80060A8[19:0] = 0x0000C845U */
	/* .. ..     ==> MASK : 0x000FFFFFU    VAL : 0x0000C845U */
	/* .. .. dram_rstn_x1024 = 0x67 */
	/* .. .. ==> 0XF80060A8[27:20] = 0x00000067U */
	/* .. ..     ==> MASK : 0x0FF00000U    VAL : 0x06700000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A8, 0x0FFFFFFFU, 0x0670C845U),
	/* .. .. deeppowerdown_en = 0x0 */
	/* .. .. ==> 0XF80060AC[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. deeppowerdown_to_x1024 = 0xff */
	/* .. .. ==> 0XF80060AC[8:1] = 0x000000FFU */
	/* .. ..     ==> MASK : 0x000001FEU    VAL : 0x000001FEU */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060AC, 0x000001FFU, 0x000001FEU),
	/* .. .. dfi_wrlvl_max_x1024 = 0xfff */
	/* .. .. ==> 0XF80060B0[11:0] = 0x00000FFFU */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x00000FFFU */
	/* .. .. dfi_rdlvl_max_x1024 = 0xfff */
	/* .. .. ==> 0XF80060B0[23:12] = 0x00000FFFU */
	/* .. ..     ==> MASK : 0x00FFF000U    VAL : 0x00FFF000U */
	/* .. .. ddrc_reg_twrlvl_max_error = 0x0 */
	/* .. .. ==> 0XF80060B0[24:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. .. ddrc_reg_trdlvl_max_error = 0x0 */
	/* .. .. ==> 0XF80060B0[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dfi_wr_level_en = 0x1 */
	/* .. .. ==> 0XF80060B0[26:26] = 0x00000001U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x04000000U */
	/* .. .. reg_ddrc_dfi_rd_dqs_gate_level = 0x1 */
	/* .. .. ==> 0XF80060B0[27:27] = 0x00000001U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x08000000U */
	/* .. .. reg_ddrc_dfi_rd_data_eye_train = 0x1 */
	/* .. .. ==> 0XF80060B0[28:28] = 0x00000001U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B0, 0x1FFFFFFFU, 0x1CFFFFFFU),
	/* .. .. reg_ddrc_skip_ocd = 0x1 */
	/* .. .. ==> 0XF80060B4[9:9] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000200U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B4, 0x00000200U, 0x00000200U),
	/* .. .. reg_ddrc_dfi_t_rddata_en = 0x6 */
	/* .. .. ==> 0XF80060B8[4:0] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000006U */
	/* .. .. reg_ddrc_dfi_t_ctrlup_min = 0x3 */
	/* .. .. ==> 0XF80060B8[14:5] = 0x00000003U */
	/* .. ..     ==> MASK : 0x00007FE0U    VAL : 0x00000060U */
	/* .. .. reg_ddrc_dfi_t_ctrlup_max = 0x40 */
	/* .. .. ==> 0XF80060B8[24:15] = 0x00000040U */
	/* .. ..     ==> MASK : 0x01FF8000U    VAL : 0x00200000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B8, 0x01FFFFFFU, 0x00200066U),
	/* .. .. START: RESET ECC ERROR */
	/* .. .. Clear_Uncorrectable_DRAM_ECC_error = 1 */
	/* .. .. ==> 0XF80060C4[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. Clear_Correctable_DRAM_ECC_error = 1 */
	/* .. .. ==> 0XF80060C4[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000003U),
	/* .. .. FINISH: RESET ECC ERROR */
	/* .. .. Clear_Uncorrectable_DRAM_ECC_error = 0x0 */
	/* .. .. ==> 0XF80060C4[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. Clear_Correctable_DRAM_ECC_error = 0x0 */
	/* .. .. ==> 0XF80060C4[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000000U),
	/* .. .. CORR_ECC_LOG_VALID = 0x0 */
	/* .. .. ==> 0XF80060C8[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. ECC_CORRECTED_BIT_NUM = 0x0 */
	/* .. .. ==> 0XF80060C8[7:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000FEU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C8, 0x000000FFU, 0x00000000U),
	/* .. .. UNCORR_ECC_LOG_VALID = 0x0 */
	/* .. .. ==> 0XF80060DC[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060DC, 0x00000001U, 0x00000000U),
	/* .. .. STAT_NUM_CORR_ERR = 0x0 */
	/* .. .. ==> 0XF80060F0[15:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00000000U */
	/* .. .. STAT_NUM_UNCORR_ERR = 0x0 */
	/* .. .. ==> 0XF80060F0[7:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060F0, 0x0000FFFFU, 0x00000000U),
	/* .. .. reg_ddrc_ecc_mode = 0x0 */
	/* .. .. ==> 0XF80060F4[2:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_scrub = 0x1 */
	/* .. .. ==> 0XF80060F4[3:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060F4, 0x0000000FU, 0x00000008U),
	/* .. .. reg_phy_dif_on = 0x0 */
	/* .. .. ==> 0XF8006114[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_phy_dif_off = 0x0 */
	/* .. .. ==> 0XF8006114[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006114, 0x000000FFU, 0x00000000U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006118[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006118[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006118[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006118[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006118, 0x7FFFFFCFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF800611C[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF800611C[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF800611C[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF800611C[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800611C, 0x7FFFFFCFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006120[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006120[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006120[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006120[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006120, 0x7FFFFFCFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006124[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006124[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006124[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006124[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006124, 0x7FFFFFCFU, 0x40000001U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF800612C[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8f */
	/* .. .. ==> 0XF800612C[19:10] = 0x0000008FU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00023C00U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800612C, 0x000FFFFFU, 0x00023C00U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006130[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8a */
	/* .. .. ==> 0XF8006130[19:10] = 0x0000008AU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00022800U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006130, 0x000FFFFFU, 0x00022800U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006134[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8b */
	/* .. .. ==> 0XF8006134[19:10] = 0x0000008BU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00022C00U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006134, 0x000FFFFFU, 0x00022C00U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006138[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x92 */
	/* .. .. ==> 0XF8006138[19:10] = 0x00000092U */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00024800U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006138, 0x000FFFFFU, 0x00024800U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006140[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006140[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006140[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006140, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006144[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006144[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006144[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006144, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006148[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006148[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006148[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006148, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF800614C[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF800614C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF800614C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800614C, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x77 */
	/* .. .. ==> 0XF8006154[9:0] = 0x00000077U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000077U */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006154[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006154[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006154, 0x000FFFFFU, 0x00000077U),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x7c */
	/* .. .. ==> 0XF8006158[9:0] = 0x0000007CU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x0000007CU */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006158[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006158[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006158, 0x000FFFFFU, 0x0000007CU),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x7c */
	/* .. .. ==> 0XF800615C[9:0] = 0x0000007CU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x0000007CU */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF800615C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF800615C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800615C, 0x000FFFFFU, 0x0000007CU),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x75 */
	/* .. .. ==> 0XF8006160[9:0] = 0x00000075U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000075U */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006160[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006160[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006160, 0x000FFFFFU, 0x00000075U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe4 */
	/* .. .. ==> 0XF8006168[10:0] = 0x000000E4U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E4U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006168[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006168[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006168, 0x001FFFFFU, 0x000000E4U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xdf */
	/* .. .. ==> 0XF800616C[10:0] = 0x000000DFU */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000DFU */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF800616C[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF800616C[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800616C, 0x001FFFFFU, 0x000000DFU),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe0 */
	/* .. .. ==> 0XF8006170[10:0] = 0x000000E0U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E0U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006170[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006170[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006170, 0x001FFFFFU, 0x000000E0U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe7 */
	/* .. .. ==> 0XF8006174[10:0] = 0x000000E7U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E7U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006174[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006174[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006174, 0x001FFFFFU, 0x000000E7U),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xb7 */
	/* .. .. ==> 0XF800617C[9:0] = 0x000000B7U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000B7U */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF800617C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF800617C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800617C, 0x000FFFFFU, 0x000000B7U),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xbc */
	/* .. .. ==> 0XF8006180[9:0] = 0x000000BCU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000BCU */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006180[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006180[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006180, 0x000FFFFFU, 0x000000BCU),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xbc */
	/* .. .. ==> 0XF8006184[9:0] = 0x000000BCU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000BCU */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006184[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006184[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006184, 0x000FFFFFU, 0x000000BCU),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xb5 */
	/* .. .. ==> 0XF8006188[9:0] = 0x000000B5U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000B5U */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006188[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006188[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006188, 0x000FFFFFU, 0x000000B5U),
	/* .. .. reg_phy_bl2 = 0x0 */
	/* .. .. ==> 0XF8006190[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_at_spd_atpg = 0x0 */
	/* .. .. ==> 0XF8006190[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_enable = 0x0 */
	/* .. .. ==> 0XF8006190[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_force_err = 0x0 */
	/* .. .. ==> 0XF8006190[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_mode = 0x0 */
	/* .. .. ==> 0XF8006190[6:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. .. reg_phy_invert_clkout = 0x1 */
	/* .. .. ==> 0XF8006190[7:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. .. reg_phy_sel_logic = 0x0 */
	/* .. .. ==> 0XF8006190[9:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_ratio = 0x100 */
	/* .. .. ==> 0XF8006190[19:10] = 0x00000100U */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00040000U */
	/* .. .. reg_phy_ctrl_slave_force = 0x0 */
	/* .. .. ==> 0XF8006190[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006190[27:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0FE00000U    VAL : 0x00000000U */
	/* .. .. reg_phy_lpddr = 0x0 */
	/* .. .. ==> 0XF8006190[29:29] = 0x00000000U */
	/* .. ..     ==> MASK : 0x20000000U    VAL : 0x00000000U */
	/* .. .. reg_phy_cmd_latency = 0x0 */
	/* .. .. ==> 0XF8006190[30:30] = 0x00000000U */
	/* .. ..     ==> MASK : 0x40000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006190, 0x6FFFFEFEU, 0x00040080U),
	/* .. .. reg_phy_wr_rl_delay = 0x2 */
	/* .. .. ==> 0XF8006194[4:0] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000002U */
	/* .. .. reg_phy_rd_rl_delay = 0x4 */
	/* .. .. ==> 0XF8006194[9:5] = 0x00000004U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x00000080U */
	/* .. .. reg_phy_dll_lock_diff = 0xf */
	/* .. .. ==> 0XF8006194[13:10] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00003C00U    VAL : 0x00003C00U */
	/* .. .. reg_phy_use_wr_level = 0x1 */
	/* .. .. ==> 0XF8006194[14:14] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00004000U */
	/* .. .. reg_phy_use_rd_dqs_gate_level = 0x1 */
	/* .. .. ==> 0XF8006194[15:15] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00008000U */
	/* .. .. reg_phy_use_rd_data_eye_level = 0x1 */
	/* .. .. ==> 0XF8006194[16:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00010000U */
	/* .. .. reg_phy_dis_calib_rst = 0x0 */
	/* .. .. ==> 0XF8006194[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006194[19:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000C0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006194, 0x000FFFFFU, 0x0001FC82U),
	/* .. .. reg_arb_page_addr_mask = 0x0 */
	/* .. .. ==> 0XF8006204[31:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFFFFFFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006204, 0xFFFFFFFFU, 0x00000000U),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006208[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006208, 0x000703FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF800620C[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800620C, 0x000703FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006210[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006210, 0x000703FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006214[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006214, 0x000703FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006218[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006218, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF800621C[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800621C, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006220[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006220, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006224[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006224, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_ddrc_lpddr2 = 0x0 */
	/* .. .. ==> 0XF80062A8[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_derate_enable = 0x0 */
	/* .. .. ==> 0XF80062A8[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr4_margin = 0x0 */
	/* .. .. ==> 0XF80062A8[11:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000FF0U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062A8, 0x00000FF5U, 0x00000000U),
	/* .. .. reg_ddrc_mr4_read_interval = 0x0 */
	/* .. .. ==> 0XF80062AC[31:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFFFFFFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062AC, 0xFFFFFFFFU, 0x00000000U),
	/* .. .. reg_ddrc_min_stable_clock_x1 = 0x5 */
	/* .. .. ==> 0XF80062B0[3:0] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000005U */
	/* .. .. reg_ddrc_idle_after_reset_x32 = 0x12 */
	/* .. .. ==> 0XF80062B0[11:4] = 0x00000012U */
	/* .. ..     ==> MASK : 0x00000FF0U    VAL : 0x00000120U */
	/* .. .. reg_ddrc_t_mrw = 0x5 */
	/* .. .. ==> 0XF80062B0[21:12] = 0x00000005U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00005000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062B0, 0x003FFFFFU, 0x00005125U),
	/* .. .. reg_ddrc_max_auto_init_x1024 = 0xa6 */
	/* .. .. ==> 0XF80062B4[7:0] = 0x000000A6U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x000000A6U */
	/* .. .. reg_ddrc_dev_zqinit_x32 = 0x12 */
	/* .. .. ==> 0XF80062B4[17:8] = 0x00000012U */
	/* .. ..     ==> MASK : 0x0003FF00U    VAL : 0x00001200U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062B4, 0x0003FFFFU, 0x000012A6U),
	/* .. .. START: POLL ON DCI STATUS */
	/* .. .. DONE = 1 */
	/* .. .. ==> 0XF8000B74[13:13] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. .. */
	EMIT_MASKPOLL(0XF8000B74, 0x00002000U),
	/* .. .. FINISH: POLL ON DCI STATUS */
	/* .. .. START: UNLOCK DDR */
	/* .. .. reg_ddrc_soft_rstb = 0x1 */
	/* .. .. ==> 0XF8006000[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_ddrc_powerdown_en = 0x0 */
	/* .. .. ==> 0XF8006000[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_data_bus_width = 0x0 */
	/* .. .. ==> 0XF8006000[3:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000CU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_burst8_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[6:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rdwr_idle_gap = 1 */
	/* .. .. ==> 0XF8006000[13:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003F80U    VAL : 0x00000080U */
	/* .. .. reg_ddrc_dis_rd_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_act_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_auto_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000081U),
	/* .. .. FINISH: UNLOCK DDR */
	/* .. .. START: CHECK DDR STATUS */
	/* .. .. ddrc_reg_operating_mode = 1 */
	/* .. .. ==> 0XF8006054[2:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKPOLL(0XF8006054, 0x00000007U),
	/* .. .. FINISH: CHECK DDR STATUS */
	/* .. FINISH: DDR INITIALIZATION */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_mio_init_data_3_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: OCM REMAPPING */
	/* .. VREF_EN = 0x1 */
	/* .. ==> 0XF8000B00[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. VREF_SEL = 0x0 */
	/* .. ==> 0XF8000B00[6:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B00, 0x00000071U, 0x00000001U),
	/* .. FINISH: OCM REMAPPING */
	/* .. START: DDRIOB SETTINGS */
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B40[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B40[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B40[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B40[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCI_TYPE = 0x0 */
	/* .. ==> 0XF8000B40[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B40[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B40[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B40[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B40[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B40, 0x00000FFFU, 0x00000600U),
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B44[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B44[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B44[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B44[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCI_TYPE = 0x0 */
	/* .. ==> 0XF8000B44[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B44[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B44[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B44[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B44[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B44, 0x00000FFFU, 0x00000600U),
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B48[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x1 */
	/* .. ==> 0XF8000B48[2:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000002U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B48[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B48[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCI_TYPE = 0x3 */
	/* .. ==> 0XF8000B48[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B48[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B48[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B48[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B48[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B48, 0x00000FFFU, 0x00000672U),
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B4C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x1 */
	/* .. ==> 0XF8000B4C[2:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000002U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B4C[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B4C[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCI_TYPE = 0x3 */
	/* .. ==> 0XF8000B4C[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B4C[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B4C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B4C[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B4C[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B4C, 0x00000FFFU, 0x00000672U),
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B50[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x2 */
	/* .. ==> 0XF8000B50[2:1] = 0x00000002U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000004U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B50[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B50[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCI_TYPE = 0x3 */
	/* .. ==> 0XF8000B50[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B50[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B50[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B50[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B50[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B50, 0x00000FFFU, 0x00000674U),
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B54[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x2 */
	/* .. ==> 0XF8000B54[2:1] = 0x00000002U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000004U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B54[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B54[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCI_TYPE = 0x3 */
	/* .. ==> 0XF8000B54[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B54[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B54[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B54[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B54[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B54, 0x00000FFFU, 0x00000674U),
	/* .. reserved_INP_POWER = 0x0 */
	/* .. ==> 0XF8000B58[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B58[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE_B = 0x0 */
	/* .. ==> 0XF8000B58[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B58[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCI_TYPE = 0x0 */
	/* .. ==> 0XF8000B58[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B58[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B58[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B58[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B58[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B58, 0x00000FFFU, 0x00000600U),
	/* .. reserved_DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B5C[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. reserved_DRIVE_N = 0xc */
	/* .. ==> 0XF8000B5C[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. reserved_SLEW_P = 0x3 */
	/* .. ==> 0XF8000B5C[18:14] = 0x00000003U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x0000C000U */
	/* .. reserved_SLEW_N = 0x3 */
	/* .. ==> 0XF8000B5C[23:19] = 0x00000003U */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00180000U */
	/* .. reserved_GTL = 0x0 */
	/* .. ==> 0XF8000B5C[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. reserved_RTERM = 0x0 */
	/* .. ==> 0XF8000B5C[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B5C, 0xFFFFFFFFU, 0x0018C61CU),
	/* .. reserved_DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B60[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. reserved_DRIVE_N = 0xc */
	/* .. ==> 0XF8000B60[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. reserved_SLEW_P = 0x6 */
	/* .. ==> 0XF8000B60[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. reserved_SLEW_N = 0x1f */
	/* .. ==> 0XF8000B60[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. reserved_GTL = 0x0 */
	/* .. ==> 0XF8000B60[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. reserved_RTERM = 0x0 */
	/* .. ==> 0XF8000B60[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B60, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. reserved_DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B64[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. reserved_DRIVE_N = 0xc */
	/* .. ==> 0XF8000B64[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. reserved_SLEW_P = 0x6 */
	/* .. ==> 0XF8000B64[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. reserved_SLEW_N = 0x1f */
	/* .. ==> 0XF8000B64[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. reserved_GTL = 0x0 */
	/* .. ==> 0XF8000B64[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. reserved_RTERM = 0x0 */
	/* .. ==> 0XF8000B64[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B64, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. reserved_DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B68[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. reserved_DRIVE_N = 0xc */
	/* .. ==> 0XF8000B68[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. reserved_SLEW_P = 0x6 */
	/* .. ==> 0XF8000B68[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. reserved_SLEW_N = 0x1f */
	/* .. ==> 0XF8000B68[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. reserved_GTL = 0x0 */
	/* .. ==> 0XF8000B68[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. reserved_RTERM = 0x0 */
	/* .. ==> 0XF8000B68[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B68, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. VREF_INT_EN = 0x0 */
	/* .. ==> 0XF8000B6C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. VREF_SEL = 0x0 */
	/* .. ==> 0XF8000B6C[4:1] = 0x00000000U */
	/* ..     ==> MASK : 0x0000001EU    VAL : 0x00000000U */
	/* .. VREF_EXT_EN = 0x3 */
	/* .. ==> 0XF8000B6C[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. reserved_VREF_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[8:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000180U    VAL : 0x00000000U */
	/* .. REFIO_EN = 0x1 */
	/* .. ==> 0XF8000B6C[9:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000200U */
	/* .. reserved_REFIO_TEST = 0x0 */
	/* .. ==> 0XF8000B6C[11:10] = 0x00000000U */
	/* ..     ==> MASK : 0x00000C00U    VAL : 0x00000000U */
	/* .. reserved_REFIO_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. reserved_DRST_B_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. reserved_CKE_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[14:14] = 0x00000000U */
	/* ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B6C, 0x00007FFFU, 0x00000260U),
	/* .. .. START: ASSERT RESET */
	/* .. .. RESET = 1 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x00000001U, 0x00000001U),
	/* .. .. FINISH: ASSERT RESET */
	/* .. .. START: DEASSERT RESET */
	/* .. .. RESET = 0 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reserved_VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x00000021U, 0x00000020U),
	/* .. .. FINISH: DEASSERT RESET */
	/* .. .. RESET = 0x1 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. ENABLE = 0x1 */
	/* .. .. ==> 0XF8000B70[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. reserved_VRP_TRI = 0x0 */
	/* .. .. ==> 0XF8000B70[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reserved_VRN_TRI = 0x0 */
	/* .. .. ==> 0XF8000B70[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reserved_VRP_OUT = 0x0 */
	/* .. .. ==> 0XF8000B70[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reserved_VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. NREF_OPT1 = 0x0 */
	/* .. .. ==> 0XF8000B70[7:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000C0U    VAL : 0x00000000U */
	/* .. .. NREF_OPT2 = 0x0 */
	/* .. .. ==> 0XF8000B70[10:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000700U    VAL : 0x00000000U */
	/* .. .. NREF_OPT4 = 0x1 */
	/* .. .. ==> 0XF8000B70[13:11] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003800U    VAL : 0x00000800U */
	/* .. .. PREF_OPT1 = 0x0 */
	/* .. .. ==> 0XF8000B70[15:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000C000U    VAL : 0x00000000U */
	/* .. .. PREF_OPT2 = 0x0 */
	/* .. .. ==> 0XF8000B70[19:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000E0000U    VAL : 0x00000000U */
	/* .. .. UPDATE_CONTROL = 0x0 */
	/* .. .. ==> 0XF8000B70[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. reserved_INIT_COMPLETE = 0x0 */
	/* .. .. ==> 0XF8000B70[21:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. .. reserved_TST_CLK = 0x0 */
	/* .. .. ==> 0XF8000B70[22:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. .. reserved_TST_HLN = 0x0 */
	/* .. .. ==> 0XF8000B70[23:23] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. .. reserved_TST_HLP = 0x0 */
	/* .. .. ==> 0XF8000B70[24:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. .. reserved_TST_RST = 0x0 */
	/* .. .. ==> 0XF8000B70[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reserved_INT_DCI_EN = 0x0 */
	/* .. .. ==> 0XF8000B70[26:26] = 0x00000000U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x07FEFFFFU, 0x00000823U),
	/* .. FINISH: DDRIOB SETTINGS */
	/* .. START: MIO PROGRAMMING */
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000700[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000700[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000700[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000700[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000700[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000700[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000700[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000700[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000700[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000700, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000704[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000704[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000704[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000704[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000704[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000704[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000704[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000704[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000704[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000704, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000708[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000708[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000708[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000708[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000708[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000708[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000708[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000708[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000708[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000708, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800070C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800070C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800070C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800070C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800070C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800070C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800070C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800070C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800070C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800070C, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000710[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000710[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000710[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000710[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000710[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000710[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000710[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000710[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000710[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000710, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000714[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000714[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000714[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000714[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000714[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000714[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000714[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000714[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000714[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000714, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000718[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000718[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000718[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000718[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000718[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000718[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000718[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000718[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000718[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000718, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800071C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800071C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800071C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800071C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800071C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800071C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800071C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800071C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800071C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800071C, 0x00003FFFU, 0x00000600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000720[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000720[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000720[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000720[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000720[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000720[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000720[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000720[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000720[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000720, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000724[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000724[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000724[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000724[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000724[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000724[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000724[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000724[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000724[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000724, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000728[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000728[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000728[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000728[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000728[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000728[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000728[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000728[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000728[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000728, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800072C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800072C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800072C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800072C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800072C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800072C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800072C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF800072C[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800072C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800072C, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000730[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000730[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000730[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000730[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000730[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000730[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000730[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000730[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000730[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000730, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000734[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000734[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000734[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000734[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000734[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000734[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000734[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000734[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000734[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000734, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000738[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000738[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000738[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000738[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000738[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000738[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000738[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000738[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000738[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000738, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800073C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800073C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800073C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800073C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800073C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800073C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800073C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF800073C[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800073C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800073C, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000740[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000740[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000740[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000740[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000740[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000740[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000740[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000740[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000740[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000740, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000744[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000744[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000744[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000744[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000744[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000744[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000744[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000744[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000744[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000744, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000748[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000748[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000748[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000748[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000748[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000748[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000748[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000748[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000748[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000748, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800074C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800074C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800074C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800074C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800074C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800074C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800074C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800074C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF800074C[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF800074C, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000750[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000750[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000750[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000750[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000750[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000750[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000750[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000750[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000750[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000750, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000754[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000754[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000754[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000754[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000754[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000754[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000754[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000754[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000754[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000754, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000758[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000758[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000758[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000758[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000758[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000758[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000758[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000758[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000758[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000758, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800075C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800075C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800075C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800075C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800075C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800075C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800075C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800075C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800075C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800075C, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000760[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000760[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000760[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000760[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000760[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000760[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000760[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000760[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000760[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000760, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000764[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000764[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000764[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000764[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000764[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000764[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000764[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000764[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000764[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000764, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000768[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000768[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000768[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000768[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000768[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000768[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000768[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000768[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000768[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000768, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800076C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800076C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800076C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800076C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800076C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800076C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800076C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800076C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800076C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800076C, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000770[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000770[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000770[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000770[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000770[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000770[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000770[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000770[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000770[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000770, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000774[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000774[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000774[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000774[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000774[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000774[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000774[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000774[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000774[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000774, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000778[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000778[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000778[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000778[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000778[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000778[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000778[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000778[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000778[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000778, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800077C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800077C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800077C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800077C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800077C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800077C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800077C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800077C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800077C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800077C, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000780[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000780[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000780[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000780[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000780[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000780[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000780[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000780[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000780[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000780, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000784[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000784[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000784[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000784[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000784[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000784[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000784[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000784[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000784[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000784, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000788[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000788[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000788[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000788[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000788[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000788[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000788[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000788[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000788[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000788, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800078C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800078C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800078C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800078C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800078C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800078C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800078C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800078C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800078C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800078C, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000790[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000790[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000790[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000790[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000790[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000790[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000790[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000790[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000790[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000790, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000794[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000794[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000794[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000794[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000794[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000794[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000794[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000794[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000794[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000794, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000798[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000798[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000798[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000798[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000798[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000798[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000798[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000798[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000798[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000798, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800079C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800079C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800079C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800079C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800079C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800079C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800079C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800079C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800079C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800079C, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A0[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A0, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A4[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A4, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A8[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A8[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A8[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A8, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007AC[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007AC[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007AC[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007AC[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007AC[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007AC[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007AC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007AC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007AC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007AC, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007B0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007B0[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007B0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B0, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007B4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007B4[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007B4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B4, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007B8[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007B8[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF80007B8[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B8, 0x00003FFFU, 0x00001200U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF80007BC[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007BC[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007BC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007BC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007BC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007BC, 0x00003F01U, 0x00000201U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007C0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 7 */
	/* .. ==> 0XF80007C0[7:5] = 0x00000007U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x000000E0U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C0[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C0, 0x00003FFFU, 0x000002E0U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF80007C4[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 7 */
	/* .. ==> 0XF80007C4[7:5] = 0x00000007U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x000000E0U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C4[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C4, 0x00003FFFU, 0x000002E1U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007C8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007C8[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C8[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C8[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C8, 0x00003FFFU, 0x00000200U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007CC[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007CC[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007CC[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007CC[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007CC[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007CC[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007CC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007CC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007CC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007CC, 0x00003FFFU, 0x00000200U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007D0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007D0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007D0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007D0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007D0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007D0[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007D0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007D0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007D0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007D0, 0x00003FFFU, 0x00000280U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007D4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007D4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007D4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007D4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007D4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007D4[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007D4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007D4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007D4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007D4, 0x00003FFFU, 0x00000280U),
	/* .. SDIO0_WP_SEL = 55 */
	/* .. ==> 0XF8000830[5:0] = 0x00000037U */
	/* ..     ==> MASK : 0x0000003FU    VAL : 0x00000037U */
	/* .. SDIO0_CD_SEL = 47 */
	/* .. ==> 0XF8000830[21:16] = 0x0000002FU */
	/* ..     ==> MASK : 0x003F0000U    VAL : 0x002F0000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000830, 0x003F003FU, 0x002F0037U),
	/* .. FINISH: MIO PROGRAMMING */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_peripherals_init_data_3_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: DDR TERM/IBUF_DISABLE_MODE SETTINGS */
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B48[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B48[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B48, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B4C[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B4C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B4C, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B50[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B50[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B50, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B54[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B54[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B54, 0x00000180U, 0x00000180U),
	/* .. FINISH: DDR TERM/IBUF_DISABLE_MODE SETTINGS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* .. START: SRAM/NOR SET OPMODE */
	/* .. FINISH: SRAM/NOR SET OPMODE */
	/* .. START: QSPI REGISTERS */
	/* .. Holdb_dr = 1 */
	/* .. ==> 0XE000D000[19:19] = 0x00000001U */
	/* ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. */
	EMIT_MASKWRITE(0XE000D000, 0x00080000U, 0x00080000U),
	/* .. FINISH: QSPI REGISTERS */
	/* .. START: PL POWER ON RESET REGISTERS */
	/* .. PCFG_POR_CNT_4K = 0 */
	/* .. ==> 0XF8007000[29:29] = 0x00000000U */
	/* ..     ==> MASK : 0x20000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8007000, 0x20000000U, 0x00000000U),
	/* .. FINISH: PL POWER ON RESET REGISTERS */
	/* .. START: SMC TIMING CALCULATION REGISTER UPDATE */
	/* .. .. START: NAND SET CYCLE */
	/* .. .. FINISH: NAND SET CYCLE */
	/* .. .. START: OPMODE */
	/* .. .. FINISH: OPMODE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: SRAM/NOR CS0 SET CYCLE */
	/* .. .. FINISH: SRAM/NOR CS0 SET CYCLE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: NOR CS0 BASE ADDRESS */
	/* .. .. FINISH: NOR CS0 BASE ADDRESS */
	/* .. .. START: SRAM/NOR CS1 SET CYCLE */
	/* .. .. FINISH: SRAM/NOR CS1 SET CYCLE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: NOR CS1 BASE ADDRESS */
	/* .. .. FINISH: NOR CS1 BASE ADDRESS */
	/* .. .. START: USB RESET */
	/* .. .. .. START: USB0 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. DIRECTION_1 = 0x4000 */
	/* .. .. .. .. ==> 0XE000A244[21:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x003FFFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A244, 0x003FFFFFU, 0x00004000U),
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x4000 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. OP_ENABLE_1 = 0x4000 */
	/* .. .. .. .. ==> 0XE000A248[21:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x003FFFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A248, 0x003FFFFFU, 0x00004000U),
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x0 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00000000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF0000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x4000 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: USB0 RESET */
	/* .. .. .. START: USB1 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: USB1 RESET */
	/* .. .. FINISH: USB RESET */
	/* .. .. START: ENET RESET */
	/* .. .. .. START: ENET0 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: ENET0 RESET */
	/* .. .. .. START: ENET1 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: ENET1 RESET */
	/* .. .. FINISH: ENET RESET */
	/* .. .. START: I2C RESET */
	/* .. .. .. START: I2C0 RESET */
	/* .. .. .. .. START: DIR MODE GPIO BANK0 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK0 */
	/* .. .. .. .. START: DIR MODE GPIO BANK1 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: I2C0 RESET */
	/* .. .. .. START: I2C1 RESET */
	/* .. .. .. .. START: DIR MODE GPIO BANK0 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK0 */
	/* .. .. .. .. START: DIR MODE GPIO BANK1 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: I2C1 RESET */
	/* .. .. FINISH: I2C RESET */
	/* .. .. START: NOR CHIP SELECT */
	/* .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. FINISH: NOR CHIP SELECT */
	/* .. FINISH: SMC TIMING CALCULATION REGISTER UPDATE */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_post_config_3_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: ENABLING LEVEL SHIFTER */
	/* .. USER_LVL_INP_EN_0 = 1 */
	/* .. ==> 0XF8000900[3:3] = 0x00000001U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. USER_LVL_OUT_EN_0 = 1 */
	/* .. ==> 0XF8000900[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. USER_LVL_INP_EN_1 = 1 */
	/* .. ==> 0XF8000900[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. USER_LVL_OUT_EN_1 = 1 */
	/* .. ==> 0XF8000900[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. */
	EMIT_MASKWRITE(0XF8000900, 0x0000000FU, 0x0000000FU),
	/* .. FINISH: ENABLING LEVEL SHIFTER */
	/* .. START: FPGA RESETS TO 0 */
	/* .. reserved_3 = 0 */
	/* .. ==> 0XF8000240[31:25] = 0x00000000U */
	/* ..     ==> MASK : 0xFE000000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_ACP_RST = 0 */
	/* .. ==> 0XF8000240[24:24] = 0x00000000U */
	/* ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_AXDS3_RST = 0 */
	/* .. ==> 0XF8000240[23:23] = 0x00000000U */
	/* ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_AXDS2_RST = 0 */
	/* .. ==> 0XF8000240[22:22] = 0x00000000U */
	/* ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_AXDS1_RST = 0 */
	/* .. ==> 0XF8000240[21:21] = 0x00000000U */
	/* ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_AXDS0_RST = 0 */
	/* .. ==> 0XF8000240[20:20] = 0x00000000U */
	/* ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. reserved_2 = 0 */
	/* .. ==> 0XF8000240[19:18] = 0x00000000U */
	/* ..     ==> MASK : 0x000C0000U    VAL : 0x00000000U */
	/* .. reserved_FSSW1_FPGA_RST = 0 */
	/* .. ==> 0XF8000240[17:17] = 0x00000000U */
	/* ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. reserved_FSSW0_FPGA_RST = 0 */
	/* .. ==> 0XF8000240[16:16] = 0x00000000U */
	/* ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. reserved_1 = 0 */
	/* .. ==> 0XF8000240[15:14] = 0x00000000U */
	/* ..     ==> MASK : 0x0000C000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_FMSW1_RST = 0 */
	/* .. ==> 0XF8000240[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_FMSW0_RST = 0 */
	/* .. ==> 0XF8000240[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. reserved_FPGA_DMA3_RST = 0 */
	/* .. ==> 0XF8000240[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. reserved_FPGA_DMA2_RST = 0 */
	/* .. ==> 0XF8000240[10:10] = 0x00000000U */
	/* ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. reserved_FPGA_DMA1_RST = 0 */
	/* .. ==> 0XF8000240[9:9] = 0x00000000U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. reserved_FPGA_DMA0_RST = 0 */
	/* .. ==> 0XF8000240[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. reserved = 0 */
	/* .. ==> 0XF8000240[7:4] = 0x00000000U */
	/* ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. FPGA3_OUT_RST = 0 */
	/* .. ==> 0XF8000240[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. FPGA2_OUT_RST = 0 */
	/* .. ==> 0XF8000240[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. FPGA1_OUT_RST = 0 */
	/* .. ==> 0XF8000240[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. FPGA0_OUT_RST = 0 */
	/* .. ==> 0XF8000240[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000240, 0xFFFFFFFFU, 0x00000000U),
	/* .. FINISH: FPGA RESETS TO 0 */
	/* .. START: AFI REGISTERS */
	/* .. .. START: AFI0 REGISTERS */
	/* .. .. FINISH: AFI0 REGISTERS */
	/* .. .. START: AFI1 REGISTERS */
	/* .. .. FINISH: AFI1 REGISTERS */
	/* .. .. START: AFI2 REGISTERS */
	/* .. .. FINISH: AFI2 REGISTERS */
	/* .. .. START: AFI3 REGISTERS */
	/* .. .. FINISH: AFI3 REGISTERS */
	/* .. .. START: AFI2 SECURE REGISTER */
	/* .. .. FINISH: AFI2 SECURE REGISTER */
	/* .. FINISH: AFI REGISTERS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};


unsigned long ps7_pll_init_data_2_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: PLL SLCR REGISTERS */
	/* .. .. START: ARM PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000110[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000110[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x177 */
	/* .. .. ==> 0XF8000110[21:12] = 0x00000177U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00177000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000110, 0x003FFFF0U, 0x001772C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x1a */
	/* .. .. .. ==> 0XF8000100[18:12] = 0x0000001AU */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x0001A000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x0007F000U, 0x0001A000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000100[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000100[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000100[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. ARM_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000001U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000100[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. .. SRCSEL = 0x0 */
	/* .. .. .. ==> 0XF8000120[5:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. .. DIVISOR = 0x2 */
	/* .. .. .. ==> 0XF8000120[13:8] = 0x00000002U */
	/* .. .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000200U */
	/* .. .. .. CPU_6OR4XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[24:24] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x01000000U    VAL : 0x01000000U */
	/* .. .. .. CPU_3OR2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[25:25] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x02000000U    VAL : 0x02000000U */
	/* .. .. .. CPU_2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[26:26] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x04000000U    VAL : 0x04000000U */
	/* .. .. .. CPU_1XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[27:27] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x08000000U    VAL : 0x08000000U */
	/* .. .. .. CPU_PERI_CLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[28:28] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000120, 0x1F003F30U, 0x1F000200U),
	/* .. .. FINISH: ARM PLL INIT */
	/* .. .. START: DDR PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000114[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000114[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x1db */
	/* .. .. ==> 0XF8000114[21:12] = 0x000001DBU */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x001DB000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000114, 0x003FFFF0U, 0x001DB2C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x15 */
	/* .. .. .. ==> 0XF8000104[18:12] = 0x00000015U */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x00015000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x0007F000U, 0x00015000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000104[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000104[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000104[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. DDR_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[1:1] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000002U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000104[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. .. DDR_3XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000124[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. DDR_2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000124[1:1] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. .. DDR_3XCLK_DIVISOR = 0x2 */
	/* .. .. .. ==> 0XF8000124[25:20] = 0x00000002U */
	/* .. .. ..     ==> MASK : 0x03F00000U    VAL : 0x00200000U */
	/* .. .. .. DDR_2XCLK_DIVISOR = 0x3 */
	/* .. .. .. ==> 0XF8000124[31:26] = 0x00000003U */
	/* .. .. ..     ==> MASK : 0xFC000000U    VAL : 0x0C000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000124, 0xFFF00003U, 0x0C200003U),
	/* .. .. FINISH: DDR PLL INIT */
	/* .. .. START: IO PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000118[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000118[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x1f4 */
	/* .. .. ==> 0XF8000118[21:12] = 0x000001F4U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x001F4000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000118, 0x003FFFF0U, 0x001F42C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x14 */
	/* .. .. .. ==> 0XF8000108[18:12] = 0x00000014U */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x00014000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x0007F000U, 0x00014000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000108[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000108[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000108[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. IO_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[2:2] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000004U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000108[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. FINISH: IO PLL INIT */
	/* .. FINISH: PLL SLCR REGISTERS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_clock_init_data_2_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: CLOCK CONTROL SLCR REGISTERS */
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000128[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. DIVISOR0 = 0x34 */
	/* .. ==> 0XF8000128[13:8] = 0x00000034U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00003400U */
	/* .. DIVISOR1 = 0x2 */
	/* .. ==> 0XF8000128[25:20] = 0x00000002U */
	/* ..     ==> MASK : 0x03F00000U    VAL : 0x00200000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000128, 0x03F03F01U, 0x00203401U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000138[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000138[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000138, 0x00000011U, 0x00000001U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000140[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000140[6:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x8 */
	/* .. ==> 0XF8000140[13:8] = 0x00000008U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000800U */
	/* .. DIVISOR1 = 0x1 */
	/* .. ==> 0XF8000140[25:20] = 0x00000001U */
	/* ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000140, 0x03F03F71U, 0x00100801U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF800014C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF800014C[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x5 */
	/* .. ==> 0XF800014C[13:8] = 0x00000005U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. */
	EMIT_MASKWRITE(0XF800014C, 0x00003F31U, 0x00000501U),
	/* .. CLKACT0 = 0x1 */
	/* .. ==> 0XF8000150[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. CLKACT1 = 0x0 */
	/* .. ==> 0XF8000150[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000150[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x14 */
	/* .. ==> 0XF8000150[13:8] = 0x00000014U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00001400U */
	/* .. */
	EMIT_MASKWRITE(0XF8000150, 0x00003F33U, 0x00001401U),
	/* .. CLKACT0 = 0x0 */
	/* .. ==> 0XF8000154[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. CLKACT1 = 0x1 */
	/* .. ==> 0XF8000154[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000154[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0xa */
	/* .. ==> 0XF8000154[13:8] = 0x0000000AU */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000A00U */
	/* .. */
	EMIT_MASKWRITE(0XF8000154, 0x00003F33U, 0x00000A02U),
	/* .. .. START: TRACE CLOCK */
	/* .. .. FINISH: TRACE CLOCK */
	/* .. .. CLKACT = 0x1 */
	/* .. .. ==> 0XF8000168[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000168[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR = 0x5 */
	/* .. .. ==> 0XF8000168[13:8] = 0x00000005U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000168, 0x00003F31U, 0x00000501U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000170[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0xa */
	/* .. .. ==> 0XF8000170[13:8] = 0x0000000AU */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000A00U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000170[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000170, 0x03F03F30U, 0x00100A00U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000180[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x7 */
	/* .. .. ==> 0XF8000180[13:8] = 0x00000007U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000700U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000180[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000180, 0x03F03F30U, 0x00100700U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000190[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x5 */
	/* .. .. ==> 0XF8000190[13:8] = 0x00000005U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000190[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000190, 0x03F03F30U, 0x00100500U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF80001A0[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x14 */
	/* .. .. ==> 0XF80001A0[13:8] = 0x00000014U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00001400U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF80001A0[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80001A0, 0x03F03F30U, 0x00101400U),
	/* .. .. CLK_621_TRUE = 0x1 */
	/* .. .. ==> 0XF80001C4[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80001C4, 0x00000001U, 0x00000001U),
	/* .. .. DMA_CPU_2XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. USB0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[2:2] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. .. USB1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[3:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. .. GEM0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[6:6] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000040U */
	/* .. .. GEM1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. SDI0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[10:10] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000400U */
	/* .. .. SDI1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. SPI0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. SPI1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. CAN0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. CAN1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. I2C0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[18:18] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00040000U */
	/* .. .. I2C1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. UART0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. UART1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[21:21] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00200000U */
	/* .. .. GPIO_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[22:22] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00400000U */
	/* .. .. LQSPI_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[23:23] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00800000U */
	/* .. .. SMC_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[24:24] = 0x00000001U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x01000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800012C, 0x01FFCCCDU, 0x01EC044DU),
	/* .. FINISH: CLOCK CONTROL SLCR REGISTERS */
	/* .. START: THIS SHOULD BE BLANK */
	/* .. FINISH: THIS SHOULD BE BLANK */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_ddr_init_data_2_0[] = {
	/* START: top */
	/* .. START: DDR INITIALIZATION */
	/* .. .. START: LOCK DDR */
	/* .. .. reg_ddrc_soft_rstb = 0 */
	/* .. .. ==> 0XF8006000[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_powerdown_en = 0x0 */
	/* .. .. ==> 0XF8006000[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_data_bus_width = 0x0 */
	/* .. .. ==> 0XF8006000[3:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000CU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_burst8_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[6:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rdwr_idle_gap = 0x1 */
	/* .. .. ==> 0XF8006000[13:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003F80U    VAL : 0x00000080U */
	/* .. .. reg_ddrc_dis_rd_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_act_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_auto_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000080U),
	/* .. .. FINISH: LOCK DDR */
	/* .. .. reg_ddrc_t_rfc_nom_x32 = 0x7f */
	/* .. .. ==> 0XF8006004[11:0] = 0x0000007FU */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x0000007FU */
	/* .. .. reg_ddrc_active_ranks = 0x1 */
	/* .. .. ==> 0XF8006004[13:12] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003000U    VAL : 0x00001000U */
	/* .. .. reg_ddrc_addrmap_cs_bit0 = 0x0 */
	/* .. .. ==> 0XF8006004[18:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0007C000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_wr_odt_block = 0x1 */
	/* .. .. ==> 0XF8006004[20:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00180000U    VAL : 0x00080000U */
	/* .. .. reg_ddrc_diff_rank_rd_2cycle_gap = 0x0 */
	/* .. .. ==> 0XF8006004[21:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_cs_bit1 = 0x0 */
	/* .. .. ==> 0XF8006004[26:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x07C00000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_open_bank = 0x0 */
	/* .. .. ==> 0XF8006004[27:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_4bank_ram = 0x0 */
	/* .. .. ==> 0XF8006004[28:28] = 0x00000000U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006004, 0x1FFFFFFFU, 0x0008107FU),
	/* .. .. reg_ddrc_hpr_min_non_critical_x32 = 0xf */
	/* .. .. ==> 0XF8006008[10:0] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x0000000FU */
	/* .. .. reg_ddrc_hpr_max_starve_x32 = 0xf */
	/* .. .. ==> 0XF8006008[21:11] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x003FF800U    VAL : 0x00007800U */
	/* .. .. reg_ddrc_hpr_xact_run_length = 0xf */
	/* .. .. ==> 0XF8006008[25:22] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x03C00000U    VAL : 0x03C00000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006008, 0x03FFFFFFU, 0x03C0780FU),
	/* .. .. reg_ddrc_lpr_min_non_critical_x32 = 0x1 */
	/* .. .. ==> 0XF800600C[10:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_lpr_max_starve_x32 = 0x2 */
	/* .. .. ==> 0XF800600C[21:11] = 0x00000002U */
	/* .. ..     ==> MASK : 0x003FF800U    VAL : 0x00001000U */
	/* .. .. reg_ddrc_lpr_xact_run_length = 0x8 */
	/* .. .. ==> 0XF800600C[25:22] = 0x00000008U */
	/* .. ..     ==> MASK : 0x03C00000U    VAL : 0x02000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800600C, 0x03FFFFFFU, 0x02001001U),
	/* .. .. reg_ddrc_w_min_non_critical_x32 = 0x1 */
	/* .. .. ==> 0XF8006010[10:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_w_xact_run_length = 0x8 */
	/* .. .. ==> 0XF8006010[14:11] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00007800U    VAL : 0x00004000U */
	/* .. .. reg_ddrc_w_max_starve_x32 = 0x2 */
	/* .. .. ==> 0XF8006010[25:15] = 0x00000002U */
	/* .. ..     ==> MASK : 0x03FF8000U    VAL : 0x00010000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006010, 0x03FFFFFFU, 0x00014001U),
	/* .. .. reg_ddrc_t_rc = 0x1a */
	/* .. .. ==> 0XF8006014[5:0] = 0x0000001AU */
	/* .. ..     ==> MASK : 0x0000003FU    VAL : 0x0000001AU */
	/* .. .. reg_ddrc_t_rfc_min = 0x54 */
	/* .. .. ==> 0XF8006014[13:6] = 0x00000054U */
	/* .. ..     ==> MASK : 0x00003FC0U    VAL : 0x00001500U */
	/* .. .. reg_ddrc_post_selfref_gap_x32 = 0x10 */
	/* .. .. ==> 0XF8006014[20:14] = 0x00000010U */
	/* .. ..     ==> MASK : 0x001FC000U    VAL : 0x00040000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006014, 0x001FFFFFU, 0x0004151AU),
	/* .. .. reg_ddrc_wr2pre = 0x12 */
	/* .. .. ==> 0XF8006018[4:0] = 0x00000012U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000012U */
	/* .. .. reg_ddrc_powerdown_to_x32 = 0x6 */
	/* .. .. ==> 0XF8006018[9:5] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x000000C0U */
	/* .. .. reg_ddrc_t_faw = 0x15 */
	/* .. .. ==> 0XF8006018[15:10] = 0x00000015U */
	/* .. ..     ==> MASK : 0x0000FC00U    VAL : 0x00005400U */
	/* .. .. reg_ddrc_t_ras_max = 0x23 */
	/* .. .. ==> 0XF8006018[21:16] = 0x00000023U */
	/* .. ..     ==> MASK : 0x003F0000U    VAL : 0x00230000U */
	/* .. .. reg_ddrc_t_ras_min = 0x13 */
	/* .. .. ==> 0XF8006018[26:22] = 0x00000013U */
	/* .. ..     ==> MASK : 0x07C00000U    VAL : 0x04C00000U */
	/* .. .. reg_ddrc_t_cke = 0x4 */
	/* .. .. ==> 0XF8006018[31:28] = 0x00000004U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006018, 0xF7FFFFFFU, 0x44E354D2U),
	/* .. .. reg_ddrc_write_latency = 0x5 */
	/* .. .. ==> 0XF800601C[4:0] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000005U */
	/* .. .. reg_ddrc_rd2wr = 0x7 */
	/* .. .. ==> 0XF800601C[9:5] = 0x00000007U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x000000E0U */
	/* .. .. reg_ddrc_wr2rd = 0xe */
	/* .. .. ==> 0XF800601C[14:10] = 0x0000000EU */
	/* .. ..     ==> MASK : 0x00007C00U    VAL : 0x00003800U */
	/* .. .. reg_ddrc_t_xp = 0x4 */
	/* .. .. ==> 0XF800601C[19:15] = 0x00000004U */
	/* .. ..     ==> MASK : 0x000F8000U    VAL : 0x00020000U */
	/* .. .. reg_ddrc_pad_pd = 0x0 */
	/* .. .. ==> 0XF800601C[22:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00700000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rd2pre = 0x4 */
	/* .. .. ==> 0XF800601C[27:23] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0F800000U    VAL : 0x02000000U */
	/* .. .. reg_ddrc_t_rcd = 0x7 */
	/* .. .. ==> 0XF800601C[31:28] = 0x00000007U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x70000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800601C, 0xFFFFFFFFU, 0x720238E5U),
	/* .. .. reg_ddrc_t_ccd = 0x4 */
	/* .. .. ==> 0XF8006020[4:2] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0000001CU    VAL : 0x00000010U */
	/* .. .. reg_ddrc_t_rrd = 0x6 */
	/* .. .. ==> 0XF8006020[7:5] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000000E0U    VAL : 0x000000C0U */
	/* .. .. reg_ddrc_refresh_margin = 0x2 */
	/* .. .. ==> 0XF8006020[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_t_rp = 0x7 */
	/* .. .. ==> 0XF8006020[15:12] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00007000U */
	/* .. .. reg_ddrc_refresh_to_x32 = 0x8 */
	/* .. .. ==> 0XF8006020[20:16] = 0x00000008U */
	/* .. ..     ==> MASK : 0x001F0000U    VAL : 0x00080000U */
	/* .. .. reg_ddrc_sdram = 0x1 */
	/* .. .. ==> 0XF8006020[21:21] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00200000U */
	/* .. .. reg_ddrc_mobile = 0x0 */
	/* .. .. ==> 0XF8006020[22:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_clock_stop_en = 0x0 */
	/* .. .. ==> 0XF8006020[23:23] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_read_latency = 0x7 */
	/* .. .. ==> 0XF8006020[28:24] = 0x00000007U */
	/* .. ..     ==> MASK : 0x1F000000U    VAL : 0x07000000U */
	/* .. .. reg_phy_mode_ddr1_ddr2 = 0x1 */
	/* .. .. ==> 0XF8006020[29:29] = 0x00000001U */
	/* .. ..     ==> MASK : 0x20000000U    VAL : 0x20000000U */
	/* .. .. reg_ddrc_dis_pad_pd = 0x0 */
	/* .. .. ==> 0XF8006020[30:30] = 0x00000000U */
	/* .. ..     ==> MASK : 0x40000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_loopback = 0x0 */
	/* .. .. ==> 0XF8006020[31:31] = 0x00000000U */
	/* .. ..     ==> MASK : 0x80000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006020, 0xFFFFFFFCU, 0x272872D0U),
	/* .. .. reg_ddrc_en_2t_timing_mode = 0x0 */
	/* .. .. ==> 0XF8006024[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_prefer_write = 0x0 */
	/* .. .. ==> 0XF8006024[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_max_rank_rd = 0xf */
	/* .. .. ==> 0XF8006024[5:2] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0000003CU    VAL : 0x0000003CU */
	/* .. .. reg_ddrc_mr_wr = 0x0 */
	/* .. .. ==> 0XF8006024[6:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_addr = 0x0 */
	/* .. .. ==> 0XF8006024[8:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000180U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_data = 0x0 */
	/* .. .. ==> 0XF8006024[24:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01FFFE00U    VAL : 0x00000000U */
	/* .. .. ddrc_reg_mr_wr_busy = 0x0 */
	/* .. .. ==> 0XF8006024[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_type = 0x0 */
	/* .. .. ==> 0XF8006024[26:26] = 0x00000000U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_rdata_valid = 0x0 */
	/* .. .. ==> 0XF8006024[27:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006024, 0x0FFFFFFFU, 0x0000003CU),
	/* .. .. reg_ddrc_final_wait_x32 = 0x7 */
	/* .. .. ==> 0XF8006028[6:0] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000007FU    VAL : 0x00000007U */
	/* .. .. reg_ddrc_pre_ocd_x32 = 0x0 */
	/* .. .. ==> 0XF8006028[10:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000780U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_t_mrd = 0x4 */
	/* .. .. ==> 0XF8006028[13:11] = 0x00000004U */
	/* .. ..     ==> MASK : 0x00003800U    VAL : 0x00002000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006028, 0x00003FFFU, 0x00002007U),
	/* .. .. reg_ddrc_emr2 = 0x8 */
	/* .. .. ==> 0XF800602C[15:0] = 0x00000008U */
	/* .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000008U */
	/* .. .. reg_ddrc_emr3 = 0x0 */
	/* .. .. ==> 0XF800602C[31:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFF0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800602C, 0xFFFFFFFFU, 0x00000008U),
	/* .. .. reg_ddrc_mr = 0x930 */
	/* .. .. ==> 0XF8006030[15:0] = 0x00000930U */
	/* .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000930U */
	/* .. .. reg_ddrc_emr = 0x4 */
	/* .. .. ==> 0XF8006030[31:16] = 0x00000004U */
	/* .. ..     ==> MASK : 0xFFFF0000U    VAL : 0x00040000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006030, 0xFFFFFFFFU, 0x00040930U),
	/* .. .. reg_ddrc_burst_rdwr = 0x4 */
	/* .. .. ==> 0XF8006034[3:0] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000004U */
	/* .. .. reg_ddrc_pre_cke_x1024 = 0x167 */
	/* .. .. ==> 0XF8006034[13:4] = 0x00000167U */
	/* .. ..     ==> MASK : 0x00003FF0U    VAL : 0x00001670U */
	/* .. .. reg_ddrc_post_cke_x1024 = 0x1 */
	/* .. .. ==> 0XF8006034[25:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03FF0000U    VAL : 0x00010000U */
	/* .. .. reg_ddrc_burstchop = 0x0 */
	/* .. .. ==> 0XF8006034[28:28] = 0x00000000U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006034, 0x13FF3FFFU, 0x00011674U),
	/* .. .. reg_ddrc_force_low_pri_n = 0x0 */
	/* .. .. ==> 0XF8006038[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_dq = 0x0 */
	/* .. .. ==> 0XF8006038[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_debug_mode = 0x0 */
	/* .. .. ==> 0XF8006038[6:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_level_start = 0x0 */
	/* .. .. ==> 0XF8006038[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_level_start = 0x0 */
	/* .. .. ==> 0XF8006038[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq0_wait_t = 0x0 */
	/* .. .. ==> 0XF8006038[12:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001E00U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006038, 0x00001FC3U, 0x00000000U),
	/* .. .. reg_ddrc_addrmap_bank_b0 = 0x7 */
	/* .. .. ==> 0XF800603C[3:0] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000007U */
	/* .. .. reg_ddrc_addrmap_bank_b1 = 0x7 */
	/* .. .. ==> 0XF800603C[7:4] = 0x00000007U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000070U */
	/* .. .. reg_ddrc_addrmap_bank_b2 = 0x7 */
	/* .. .. ==> 0XF800603C[11:8] = 0x00000007U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000700U */
	/* .. .. reg_ddrc_addrmap_col_b5 = 0x0 */
	/* .. .. ==> 0XF800603C[15:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b6 = 0x0 */
	/* .. .. ==> 0XF800603C[19:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800603C, 0x000FFFFFU, 0x00000777U),
	/* .. .. reg_ddrc_addrmap_col_b2 = 0x0 */
	/* .. .. ==> 0XF8006040[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b3 = 0x0 */
	/* .. .. ==> 0XF8006040[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b4 = 0x0 */
	/* .. .. ==> 0XF8006040[11:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b7 = 0x0 */
	/* .. .. ==> 0XF8006040[15:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b8 = 0x0 */
	/* .. .. ==> 0XF8006040[19:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b9 = 0xf */
	/* .. .. ==> 0XF8006040[23:20] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00F00000U    VAL : 0x00F00000U */
	/* .. .. reg_ddrc_addrmap_col_b10 = 0xf */
	/* .. .. ==> 0XF8006040[27:24] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x0F000000U */
	/* .. .. reg_ddrc_addrmap_col_b11 = 0xf */
	/* .. .. ==> 0XF8006040[31:28] = 0x0000000FU */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0xF0000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006040, 0xFFFFFFFFU, 0xFFF00000U),
	/* .. .. reg_ddrc_addrmap_row_b0 = 0x6 */
	/* .. .. ==> 0XF8006044[3:0] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000006U */
	/* .. .. reg_ddrc_addrmap_row_b1 = 0x6 */
	/* .. .. ==> 0XF8006044[7:4] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000060U */
	/* .. .. reg_ddrc_addrmap_row_b2_11 = 0x6 */
	/* .. .. ==> 0XF8006044[11:8] = 0x00000006U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000600U */
	/* .. .. reg_ddrc_addrmap_row_b12 = 0x6 */
	/* .. .. ==> 0XF8006044[15:12] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00006000U */
	/* .. .. reg_ddrc_addrmap_row_b13 = 0x6 */
	/* .. .. ==> 0XF8006044[19:16] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00060000U */
	/* .. .. reg_ddrc_addrmap_row_b14 = 0xf */
	/* .. .. ==> 0XF8006044[23:20] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00F00000U    VAL : 0x00F00000U */
	/* .. .. reg_ddrc_addrmap_row_b15 = 0xf */
	/* .. .. ==> 0XF8006044[27:24] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x0F000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006044, 0x0FFFFFFFU, 0x0FF66666U),
	/* .. .. reg_ddrc_rank0_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[2:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank0_wr_odt = 0x1 */
	/* .. .. ==> 0XF8006048[5:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000038U    VAL : 0x00000008U */
	/* .. .. reg_ddrc_rank1_rd_odt = 0x1 */
	/* .. .. ==> 0XF8006048[8:6] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000001C0U    VAL : 0x00000040U */
	/* .. .. reg_ddrc_rank1_wr_odt = 0x1 */
	/* .. .. ==> 0XF8006048[11:9] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. .. reg_phy_rd_local_odt = 0x0 */
	/* .. .. ==> 0XF8006048[13:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00003000U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_local_odt = 0x3 */
	/* .. .. ==> 0XF8006048[15:14] = 0x00000003U */
	/* .. ..     ==> MASK : 0x0000C000U    VAL : 0x0000C000U */
	/* .. .. reg_phy_idle_local_odt = 0x3 */
	/* .. .. ==> 0XF8006048[17:16] = 0x00000003U */
	/* .. ..     ==> MASK : 0x00030000U    VAL : 0x00030000U */
	/* .. .. reg_ddrc_rank2_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[20:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001C0000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank2_wr_odt = 0x0 */
	/* .. .. ==> 0XF8006048[23:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00E00000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank3_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[26:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank3_wr_odt = 0x0 */
	/* .. .. ==> 0XF8006048[29:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x38000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006048, 0x3FFFFFFFU, 0x0003C248U),
	/* .. .. reg_phy_rd_cmd_to_data = 0x0 */
	/* .. .. ==> 0XF8006050[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_cmd_to_data = 0x0 */
	/* .. .. ==> 0XF8006050[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_phy_rdc_we_to_re_delay = 0x8 */
	/* .. .. ==> 0XF8006050[11:8] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000800U */
	/* .. .. reg_phy_rdc_fifo_rst_disable = 0x0 */
	/* .. .. ==> 0XF8006050[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_phy_use_fixed_re = 0x1 */
	/* .. .. ==> 0XF8006050[16:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00010000U */
	/* .. .. reg_phy_rdc_fifo_rst_err_cnt_clr = 0x0 */
	/* .. .. ==> 0XF8006050[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dis_phy_ctrl_rstn = 0x0 */
	/* .. .. ==> 0XF8006050[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_phy_clk_stall_level = 0x0 */
	/* .. .. ==> 0XF8006050[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_num_of_dq0 = 0x7 */
	/* .. .. ==> 0XF8006050[27:24] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x07000000U */
	/* .. .. reg_phy_wrlvl_num_of_dq0 = 0x7 */
	/* .. .. ==> 0XF8006050[31:28] = 0x00000007U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x70000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006050, 0xFF0F8FFFU, 0x77010800U),
	/* .. .. reg_ddrc_dll_calib_to_min_x1024 = 0x1 */
	/* .. .. ==> 0XF8006058[7:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_dll_calib_to_max_x1024 = 0x1 */
	/* .. .. ==> 0XF8006058[15:8] = 0x00000001U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00000100U */
	/* .. .. reg_ddrc_dis_dll_calib = 0x0 */
	/* .. .. ==> 0XF8006058[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006058, 0x0001FFFFU, 0x00000101U),
	/* .. .. reg_ddrc_rd_odt_delay = 0x3 */
	/* .. .. ==> 0XF800605C[3:0] = 0x00000003U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000003U */
	/* .. .. reg_ddrc_wr_odt_delay = 0x0 */
	/* .. .. ==> 0XF800605C[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rd_odt_hold = 0x0 */
	/* .. .. ==> 0XF800605C[11:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_wr_odt_hold = 0x5 */
	/* .. .. ==> 0XF800605C[15:12] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00005000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800605C, 0x0000FFFFU, 0x00005003U),
	/* .. .. reg_ddrc_pageclose = 0x0 */
	/* .. .. ==> 0XF8006060[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_lpr_num_entries = 0x1f */
	/* .. .. ==> 0XF8006060[6:1] = 0x0000001FU */
	/* .. ..     ==> MASK : 0x0000007EU    VAL : 0x0000003EU */
	/* .. .. reg_ddrc_auto_pre_en = 0x0 */
	/* .. .. ==> 0XF8006060[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_refresh_update_level = 0x0 */
	/* .. .. ==> 0XF8006060[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_wc = 0x0 */
	/* .. .. ==> 0XF8006060[9:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_collision_page_opt = 0x0 */
	/* .. .. ==> 0XF8006060[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_selfref_en = 0x0 */
	/* .. .. ==> 0XF8006060[12:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006060, 0x000017FFU, 0x0000003EU),
	/* .. .. reg_ddrc_go2critical_hysteresis = 0x0 */
	/* .. .. ==> 0XF8006064[12:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001FE0U    VAL : 0x00000000U */
	/* .. .. reg_arb_go2critical_en = 0x1 */
	/* .. .. ==> 0XF8006064[17:17] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00020000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006064, 0x00021FE0U, 0x00020000U),
	/* .. .. reg_ddrc_wrlvl_ww = 0x41 */
	/* .. .. ==> 0XF8006068[7:0] = 0x00000041U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000041U */
	/* .. .. reg_ddrc_rdlvl_rr = 0x41 */
	/* .. .. ==> 0XF8006068[15:8] = 0x00000041U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00004100U */
	/* .. .. reg_ddrc_dfi_t_wlmrd = 0x28 */
	/* .. .. ==> 0XF8006068[25:16] = 0x00000028U */
	/* .. ..     ==> MASK : 0x03FF0000U    VAL : 0x00280000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006068, 0x03FFFFFFU, 0x00284141U),
	/* .. .. dfi_t_ctrlupd_interval_min_x1024 = 0x10 */
	/* .. .. ==> 0XF800606C[7:0] = 0x00000010U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000010U */
	/* .. .. dfi_t_ctrlupd_interval_max_x1024 = 0x16 */
	/* .. .. ==> 0XF800606C[15:8] = 0x00000016U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00001600U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800606C, 0x0000FFFFU, 0x00001610U),
	/* .. .. reg_ddrc_dfi_t_ctrl_delay = 0x1 */
	/* .. .. ==> 0XF8006078[3:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_dfi_t_dram_clk_disable = 0x1 */
	/* .. .. ==> 0XF8006078[7:4] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000010U */
	/* .. .. reg_ddrc_dfi_t_dram_clk_enable = 0x1 */
	/* .. .. ==> 0XF8006078[11:8] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000100U */
	/* .. .. reg_ddrc_t_cksre = 0x6 */
	/* .. .. ==> 0XF8006078[15:12] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00006000U */
	/* .. .. reg_ddrc_t_cksrx = 0x6 */
	/* .. .. ==> 0XF8006078[19:16] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00060000U */
	/* .. .. reg_ddrc_t_ckesr = 0x4 */
	/* .. .. ==> 0XF8006078[25:20] = 0x00000004U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00400000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006078, 0x03FFFFFFU, 0x00466111U),
	/* .. .. reg_ddrc_t_ckpde = 0x2 */
	/* .. .. ==> 0XF800607C[3:0] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000002U */
	/* .. .. reg_ddrc_t_ckpdx = 0x2 */
	/* .. .. ==> 0XF800607C[7:4] = 0x00000002U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000020U */
	/* .. .. reg_ddrc_t_ckdpde = 0x2 */
	/* .. .. ==> 0XF800607C[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_t_ckdpdx = 0x2 */
	/* .. .. ==> 0XF800607C[15:12] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00002000U */
	/* .. .. reg_ddrc_t_ckcsx = 0x3 */
	/* .. .. ==> 0XF800607C[19:16] = 0x00000003U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00030000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800607C, 0x000FFFFFU, 0x00032222U),
	/* .. .. refresh_timer0_start_value_x32 = 0x0 */
	/* .. .. ==> 0XF80060A0[11:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x00000000U */
	/* .. .. refresh_timer1_start_value_x32 = 0x8 */
	/* .. .. ==> 0XF80060A0[23:12] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00FFF000U    VAL : 0x00008000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A0, 0x00FFFFFFU, 0x00008000U),
	/* .. .. reg_ddrc_dis_auto_zq = 0x0 */
	/* .. .. ==> 0XF80060A4[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_ddr3 = 0x1 */
	/* .. .. ==> 0XF80060A4[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. reg_ddrc_t_mod = 0x200 */
	/* .. .. ==> 0XF80060A4[11:2] = 0x00000200U */
	/* .. ..     ==> MASK : 0x00000FFCU    VAL : 0x00000800U */
	/* .. .. reg_ddrc_t_zq_long_nop = 0x200 */
	/* .. .. ==> 0XF80060A4[21:12] = 0x00000200U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00200000U */
	/* .. .. reg_ddrc_t_zq_short_nop = 0x40 */
	/* .. .. ==> 0XF80060A4[31:22] = 0x00000040U */
	/* .. ..     ==> MASK : 0xFFC00000U    VAL : 0x10000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A4, 0xFFFFFFFFU, 0x10200802U),
	/* .. .. t_zq_short_interval_x1024 = 0xc845 */
	/* .. .. ==> 0XF80060A8[19:0] = 0x0000C845U */
	/* .. ..     ==> MASK : 0x000FFFFFU    VAL : 0x0000C845U */
	/* .. .. dram_rstn_x1024 = 0x67 */
	/* .. .. ==> 0XF80060A8[27:20] = 0x00000067U */
	/* .. ..     ==> MASK : 0x0FF00000U    VAL : 0x06700000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A8, 0x0FFFFFFFU, 0x0670C845U),
	/* .. .. deeppowerdown_en = 0x0 */
	/* .. .. ==> 0XF80060AC[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. deeppowerdown_to_x1024 = 0xff */
	/* .. .. ==> 0XF80060AC[8:1] = 0x000000FFU */
	/* .. ..     ==> MASK : 0x000001FEU    VAL : 0x000001FEU */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060AC, 0x000001FFU, 0x000001FEU),
	/* .. .. dfi_wrlvl_max_x1024 = 0xfff */
	/* .. .. ==> 0XF80060B0[11:0] = 0x00000FFFU */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x00000FFFU */
	/* .. .. dfi_rdlvl_max_x1024 = 0xfff */
	/* .. .. ==> 0XF80060B0[23:12] = 0x00000FFFU */
	/* .. ..     ==> MASK : 0x00FFF000U    VAL : 0x00FFF000U */
	/* .. .. ddrc_reg_twrlvl_max_error = 0x0 */
	/* .. .. ==> 0XF80060B0[24:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. .. ddrc_reg_trdlvl_max_error = 0x0 */
	/* .. .. ==> 0XF80060B0[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dfi_wr_level_en = 0x1 */
	/* .. .. ==> 0XF80060B0[26:26] = 0x00000001U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x04000000U */
	/* .. .. reg_ddrc_dfi_rd_dqs_gate_level = 0x1 */
	/* .. .. ==> 0XF80060B0[27:27] = 0x00000001U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x08000000U */
	/* .. .. reg_ddrc_dfi_rd_data_eye_train = 0x1 */
	/* .. .. ==> 0XF80060B0[28:28] = 0x00000001U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B0, 0x1FFFFFFFU, 0x1CFFFFFFU),
	/* .. .. reg_ddrc_2t_delay = 0x0 */
	/* .. .. ==> 0XF80060B4[8:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000001FFU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_skip_ocd = 0x1 */
	/* .. .. ==> 0XF80060B4[9:9] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_dis_pre_bypass = 0x0 */
	/* .. .. ==> 0XF80060B4[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B4, 0x000007FFU, 0x00000200U),
	/* .. .. reg_ddrc_dfi_t_rddata_en = 0x6 */
	/* .. .. ==> 0XF80060B8[4:0] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000006U */
	/* .. .. reg_ddrc_dfi_t_ctrlup_min = 0x3 */
	/* .. .. ==> 0XF80060B8[14:5] = 0x00000003U */
	/* .. ..     ==> MASK : 0x00007FE0U    VAL : 0x00000060U */
	/* .. .. reg_ddrc_dfi_t_ctrlup_max = 0x40 */
	/* .. .. ==> 0XF80060B8[24:15] = 0x00000040U */
	/* .. ..     ==> MASK : 0x01FF8000U    VAL : 0x00200000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B8, 0x01FFFFFFU, 0x00200066U),
	/* .. .. START: RESET ECC ERROR */
	/* .. .. Clear_Uncorrectable_DRAM_ECC_error = 1 */
	/* .. .. ==> 0XF80060C4[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. Clear_Correctable_DRAM_ECC_error = 1 */
	/* .. .. ==> 0XF80060C4[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000003U),
	/* .. .. FINISH: RESET ECC ERROR */
	/* .. .. Clear_Uncorrectable_DRAM_ECC_error = 0x0 */
	/* .. .. ==> 0XF80060C4[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. Clear_Correctable_DRAM_ECC_error = 0x0 */
	/* .. .. ==> 0XF80060C4[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000000U),
	/* .. .. CORR_ECC_LOG_VALID = 0x0 */
	/* .. .. ==> 0XF80060C8[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. ECC_CORRECTED_BIT_NUM = 0x0 */
	/* .. .. ==> 0XF80060C8[7:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000FEU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C8, 0x000000FFU, 0x00000000U),
	/* .. .. UNCORR_ECC_LOG_VALID = 0x0 */
	/* .. .. ==> 0XF80060DC[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060DC, 0x00000001U, 0x00000000U),
	/* .. .. STAT_NUM_CORR_ERR = 0x0 */
	/* .. .. ==> 0XF80060F0[15:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00000000U */
	/* .. .. STAT_NUM_UNCORR_ERR = 0x0 */
	/* .. .. ==> 0XF80060F0[7:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060F0, 0x0000FFFFU, 0x00000000U),
	/* .. .. reg_ddrc_ecc_mode = 0x0 */
	/* .. .. ==> 0XF80060F4[2:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_scrub = 0x1 */
	/* .. .. ==> 0XF80060F4[3:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060F4, 0x0000000FU, 0x00000008U),
	/* .. .. reg_phy_dif_on = 0x0 */
	/* .. .. ==> 0XF8006114[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_phy_dif_off = 0x0 */
	/* .. .. ==> 0XF8006114[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006114, 0x000000FFU, 0x00000000U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006118[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006118[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006118[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006118[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006118[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006118[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006118, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF800611C[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF800611C[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF800611C[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF800611C[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF800611C[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF800611C[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800611C, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006120[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006120[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006120[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006120[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006120[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006120[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006120[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006120[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006120[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006120[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006120[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006120[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006120, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006124[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006124[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006124[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006124[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006124[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006124[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006124, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF800612C[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8f */
	/* .. .. ==> 0XF800612C[19:10] = 0x0000008FU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00023C00U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800612C, 0x000FFFFFU, 0x00023C00U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006130[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8a */
	/* .. .. ==> 0XF8006130[19:10] = 0x0000008AU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00022800U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006130, 0x000FFFFFU, 0x00022800U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006134[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8b */
	/* .. .. ==> 0XF8006134[19:10] = 0x0000008BU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00022C00U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006134, 0x000FFFFFU, 0x00022C00U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006138[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x92 */
	/* .. .. ==> 0XF8006138[19:10] = 0x00000092U */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00024800U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006138, 0x000FFFFFU, 0x00024800U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006140[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006140[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006140[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006140, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006144[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006144[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006144[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006144, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006148[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006148[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006148[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006148, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF800614C[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF800614C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF800614C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800614C, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x77 */
	/* .. .. ==> 0XF8006154[9:0] = 0x00000077U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000077U */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006154[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006154[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006154, 0x000FFFFFU, 0x00000077U),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x7c */
	/* .. .. ==> 0XF8006158[9:0] = 0x0000007CU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x0000007CU */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006158[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006158[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006158, 0x000FFFFFU, 0x0000007CU),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x7c */
	/* .. .. ==> 0XF800615C[9:0] = 0x0000007CU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x0000007CU */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF800615C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF800615C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800615C, 0x000FFFFFU, 0x0000007CU),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x75 */
	/* .. .. ==> 0XF8006160[9:0] = 0x00000075U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000075U */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006160[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006160[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006160, 0x000FFFFFU, 0x00000075U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe4 */
	/* .. .. ==> 0XF8006168[10:0] = 0x000000E4U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E4U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006168[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006168[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006168, 0x001FFFFFU, 0x000000E4U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xdf */
	/* .. .. ==> 0XF800616C[10:0] = 0x000000DFU */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000DFU */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF800616C[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF800616C[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800616C, 0x001FFFFFU, 0x000000DFU),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe0 */
	/* .. .. ==> 0XF8006170[10:0] = 0x000000E0U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E0U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006170[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006170[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006170, 0x001FFFFFU, 0x000000E0U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe7 */
	/* .. .. ==> 0XF8006174[10:0] = 0x000000E7U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E7U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006174[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006174[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006174, 0x001FFFFFU, 0x000000E7U),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xb7 */
	/* .. .. ==> 0XF800617C[9:0] = 0x000000B7U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000B7U */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF800617C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF800617C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800617C, 0x000FFFFFU, 0x000000B7U),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xbc */
	/* .. .. ==> 0XF8006180[9:0] = 0x000000BCU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000BCU */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006180[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006180[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006180, 0x000FFFFFU, 0x000000BCU),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xbc */
	/* .. .. ==> 0XF8006184[9:0] = 0x000000BCU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000BCU */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006184[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006184[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006184, 0x000FFFFFU, 0x000000BCU),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xb5 */
	/* .. .. ==> 0XF8006188[9:0] = 0x000000B5U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000B5U */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006188[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006188[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006188, 0x000FFFFFU, 0x000000B5U),
	/* .. .. reg_phy_loopback = 0x0 */
	/* .. .. ==> 0XF8006190[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_phy_bl2 = 0x0 */
	/* .. .. ==> 0XF8006190[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_at_spd_atpg = 0x0 */
	/* .. .. ==> 0XF8006190[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_enable = 0x0 */
	/* .. .. ==> 0XF8006190[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_force_err = 0x0 */
	/* .. .. ==> 0XF8006190[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_mode = 0x0 */
	/* .. .. ==> 0XF8006190[6:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. .. reg_phy_invert_clkout = 0x1 */
	/* .. .. ==> 0XF8006190[7:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. .. reg_phy_all_dq_mpr_rd_resp = 0x0 */
	/* .. .. ==> 0XF8006190[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_phy_sel_logic = 0x0 */
	/* .. .. ==> 0XF8006190[9:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_ratio = 0x100 */
	/* .. .. ==> 0XF8006190[19:10] = 0x00000100U */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00040000U */
	/* .. .. reg_phy_ctrl_slave_force = 0x0 */
	/* .. .. ==> 0XF8006190[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006190[27:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0FE00000U    VAL : 0x00000000U */
	/* .. .. reg_phy_use_rank0_delays = 0x1 */
	/* .. .. ==> 0XF8006190[28:28] = 0x00000001U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. reg_phy_lpddr = 0x0 */
	/* .. .. ==> 0XF8006190[29:29] = 0x00000000U */
	/* .. ..     ==> MASK : 0x20000000U    VAL : 0x00000000U */
	/* .. .. reg_phy_cmd_latency = 0x0 */
	/* .. .. ==> 0XF8006190[30:30] = 0x00000000U */
	/* .. ..     ==> MASK : 0x40000000U    VAL : 0x00000000U */
	/* .. .. reg_phy_int_lpbk = 0x0 */
	/* .. .. ==> 0XF8006190[31:31] = 0x00000000U */
	/* .. ..     ==> MASK : 0x80000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006190, 0xFFFFFFFFU, 0x10040080U),
	/* .. .. reg_phy_wr_rl_delay = 0x2 */
	/* .. .. ==> 0XF8006194[4:0] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000002U */
	/* .. .. reg_phy_rd_rl_delay = 0x4 */
	/* .. .. ==> 0XF8006194[9:5] = 0x00000004U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x00000080U */
	/* .. .. reg_phy_dll_lock_diff = 0xf */
	/* .. .. ==> 0XF8006194[13:10] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00003C00U    VAL : 0x00003C00U */
	/* .. .. reg_phy_use_wr_level = 0x1 */
	/* .. .. ==> 0XF8006194[14:14] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00004000U */
	/* .. .. reg_phy_use_rd_dqs_gate_level = 0x1 */
	/* .. .. ==> 0XF8006194[15:15] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00008000U */
	/* .. .. reg_phy_use_rd_data_eye_level = 0x1 */
	/* .. .. ==> 0XF8006194[16:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00010000U */
	/* .. .. reg_phy_dis_calib_rst = 0x0 */
	/* .. .. ==> 0XF8006194[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006194[19:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000C0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006194, 0x000FFFFFU, 0x0001FC82U),
	/* .. .. reg_arb_page_addr_mask = 0x0 */
	/* .. .. ==> 0XF8006204[31:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFFFFFFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006204, 0xFFFFFFFFU, 0x00000000U),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006208[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF8006208[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006208, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF800620C[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF800620C[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800620C, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006210[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF8006210[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006210, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006214[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF8006214[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006214, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006218[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006218, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF800621C[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800621C, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006220[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006220, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006224[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006224, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_ddrc_lpddr2 = 0x0 */
	/* .. .. ==> 0XF80062A8[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_per_bank_refresh = 0x0 */
	/* .. .. ==> 0XF80062A8[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_derate_enable = 0x0 */
	/* .. .. ==> 0XF80062A8[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr4_margin = 0x0 */
	/* .. .. ==> 0XF80062A8[11:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000FF0U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062A8, 0x00000FF7U, 0x00000000U),
	/* .. .. reg_ddrc_mr4_read_interval = 0x0 */
	/* .. .. ==> 0XF80062AC[31:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFFFFFFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062AC, 0xFFFFFFFFU, 0x00000000U),
	/* .. .. reg_ddrc_min_stable_clock_x1 = 0x5 */
	/* .. .. ==> 0XF80062B0[3:0] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000005U */
	/* .. .. reg_ddrc_idle_after_reset_x32 = 0x12 */
	/* .. .. ==> 0XF80062B0[11:4] = 0x00000012U */
	/* .. ..     ==> MASK : 0x00000FF0U    VAL : 0x00000120U */
	/* .. .. reg_ddrc_t_mrw = 0x5 */
	/* .. .. ==> 0XF80062B0[21:12] = 0x00000005U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00005000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062B0, 0x003FFFFFU, 0x00005125U),
	/* .. .. reg_ddrc_max_auto_init_x1024 = 0xa6 */
	/* .. .. ==> 0XF80062B4[7:0] = 0x000000A6U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x000000A6U */
	/* .. .. reg_ddrc_dev_zqinit_x32 = 0x12 */
	/* .. .. ==> 0XF80062B4[17:8] = 0x00000012U */
	/* .. ..     ==> MASK : 0x0003FF00U    VAL : 0x00001200U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062B4, 0x0003FFFFU, 0x000012A6U),
	/* .. .. START: POLL ON DCI STATUS */
	/* .. .. DONE = 1 */
	/* .. .. ==> 0XF8000B74[13:13] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. .. */
	EMIT_MASKPOLL(0XF8000B74, 0x00002000U),
	/* .. .. FINISH: POLL ON DCI STATUS */
	/* .. .. START: UNLOCK DDR */
	/* .. .. reg_ddrc_soft_rstb = 0x1 */
	/* .. .. ==> 0XF8006000[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_ddrc_powerdown_en = 0x0 */
	/* .. .. ==> 0XF8006000[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_data_bus_width = 0x0 */
	/* .. .. ==> 0XF8006000[3:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000CU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_burst8_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[6:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rdwr_idle_gap = 1 */
	/* .. .. ==> 0XF8006000[13:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003F80U    VAL : 0x00000080U */
	/* .. .. reg_ddrc_dis_rd_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_act_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_auto_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000081U),
	/* .. .. FINISH: UNLOCK DDR */
	/* .. .. START: CHECK DDR STATUS */
	/* .. .. ddrc_reg_operating_mode = 1 */
	/* .. .. ==> 0XF8006054[2:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKPOLL(0XF8006054, 0x00000007U),
	/* .. .. FINISH: CHECK DDR STATUS */
	/* .. FINISH: DDR INITIALIZATION */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_mio_init_data_2_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: OCM REMAPPING */
	/* .. VREF_EN = 0x1 */
	/* .. ==> 0XF8000B00[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. VREF_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B00[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. CLK_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B00[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. SRSTN_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B00[9:9] = 0x00000000U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B00, 0x00000303U, 0x00000001U),
	/* .. FINISH: OCM REMAPPING */
	/* .. START: DDRIOB SETTINGS */
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B40[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B40[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B40[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B40[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCR_TYPE = 0x0 */
	/* .. ==> 0XF8000B40[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B40[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B40[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B40[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B40[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B40, 0x00000FFFU, 0x00000600U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B44[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B44[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B44[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B44[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCR_TYPE = 0x0 */
	/* .. ==> 0XF8000B44[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B44[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B44[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B44[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B44[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B44, 0x00000FFFU, 0x00000600U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B48[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x1 */
	/* .. ==> 0XF8000B48[2:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000002U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B48[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B48[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B48[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B48[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B48[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B48[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B48[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B48, 0x00000FFFU, 0x00000672U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B4C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x1 */
	/* .. ==> 0XF8000B4C[2:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000002U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B4C[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B4C[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B4C[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B4C[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B4C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B4C[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B4C[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B4C, 0x00000FFFU, 0x00000672U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B50[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x2 */
	/* .. ==> 0XF8000B50[2:1] = 0x00000002U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000004U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B50[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B50[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B50[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B50[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B50[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B50[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B50[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B50, 0x00000FFFU, 0x00000674U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B54[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x2 */
	/* .. ==> 0XF8000B54[2:1] = 0x00000002U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000004U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B54[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B54[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B54[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B54[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B54[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B54[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B54[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B54, 0x00000FFFU, 0x00000674U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B58[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B58[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B58[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B58[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCR_TYPE = 0x0 */
	/* .. ==> 0XF8000B58[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B58[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B58[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B58[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B58[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B58, 0x00000FFFU, 0x00000600U),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B5C[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B5C[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x3 */
	/* .. ==> 0XF8000B5C[18:14] = 0x00000003U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x0000C000U */
	/* .. SLEW_N = 0x3 */
	/* .. ==> 0XF8000B5C[23:19] = 0x00000003U */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00180000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B5C[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B5C[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B5C, 0xFFFFFFFFU, 0x0018C61CU),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B60[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B60[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x6 */
	/* .. ==> 0XF8000B60[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. SLEW_N = 0x1f */
	/* .. ==> 0XF8000B60[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B60[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B60[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B60, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B64[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B64[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x6 */
	/* .. ==> 0XF8000B64[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. SLEW_N = 0x1f */
	/* .. ==> 0XF8000B64[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B64[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B64[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B64, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B68[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B68[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x6 */
	/* .. ==> 0XF8000B68[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. SLEW_N = 0x1f */
	/* .. ==> 0XF8000B68[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B68[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B68[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B68, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. VREF_INT_EN = 0x0 */
	/* .. ==> 0XF8000B6C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. VREF_SEL = 0x0 */
	/* .. ==> 0XF8000B6C[4:1] = 0x00000000U */
	/* ..     ==> MASK : 0x0000001EU    VAL : 0x00000000U */
	/* .. VREF_EXT_EN = 0x3 */
	/* .. ==> 0XF8000B6C[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. VREF_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[8:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000180U    VAL : 0x00000000U */
	/* .. REFIO_EN = 0x1 */
	/* .. ==> 0XF8000B6C[9:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000200U */
	/* .. REFIO_TEST = 0x0 */
	/* .. ==> 0XF8000B6C[11:10] = 0x00000000U */
	/* ..     ==> MASK : 0x00000C00U    VAL : 0x00000000U */
	/* .. REFIO_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DRST_B_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. CKE_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[14:14] = 0x00000000U */
	/* ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B6C, 0x00007FFFU, 0x00000260U),
	/* .. .. START: ASSERT RESET */
	/* .. .. RESET = 1 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x00000021U, 0x00000021U),
	/* .. .. FINISH: ASSERT RESET */
	/* .. .. START: DEASSERT RESET */
	/* .. .. RESET = 0 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x00000021U, 0x00000020U),
	/* .. .. FINISH: DEASSERT RESET */
	/* .. .. RESET = 0x1 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. ENABLE = 0x1 */
	/* .. .. ==> 0XF8000B70[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. VRP_TRI = 0x0 */
	/* .. .. ==> 0XF8000B70[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. VRN_TRI = 0x0 */
	/* .. .. ==> 0XF8000B70[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. VRP_OUT = 0x0 */
	/* .. .. ==> 0XF8000B70[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. NREF_OPT1 = 0x0 */
	/* .. .. ==> 0XF8000B70[7:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000C0U    VAL : 0x00000000U */
	/* .. .. NREF_OPT2 = 0x0 */
	/* .. .. ==> 0XF8000B70[10:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000700U    VAL : 0x00000000U */
	/* .. .. NREF_OPT4 = 0x1 */
	/* .. .. ==> 0XF8000B70[13:11] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003800U    VAL : 0x00000800U */
	/* .. .. PREF_OPT1 = 0x0 */
	/* .. .. ==> 0XF8000B70[16:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0001C000U    VAL : 0x00000000U */
	/* .. .. PREF_OPT2 = 0x0 */
	/* .. .. ==> 0XF8000B70[19:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000E0000U    VAL : 0x00000000U */
	/* .. .. UPDATE_CONTROL = 0x0 */
	/* .. .. ==> 0XF8000B70[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. INIT_COMPLETE = 0x0 */
	/* .. .. ==> 0XF8000B70[21:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. .. TST_CLK = 0x0 */
	/* .. .. ==> 0XF8000B70[22:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. .. TST_HLN = 0x0 */
	/* .. .. ==> 0XF8000B70[23:23] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. .. TST_HLP = 0x0 */
	/* .. .. ==> 0XF8000B70[24:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. .. TST_RST = 0x0 */
	/* .. .. ==> 0XF8000B70[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. INT_DCI_EN = 0x0 */
	/* .. .. ==> 0XF8000B70[26:26] = 0x00000000U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x07FFFFFFU, 0x00000823U),
	/* .. FINISH: DDRIOB SETTINGS */
	/* .. START: MIO PROGRAMMING */
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000700[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000700[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000700[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000700[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000700[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000700[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000700[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000700[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000700[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000700, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000704[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000704[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000704[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000704[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000704[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000704[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000704[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000704[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000704[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000704, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000708[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000708[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000708[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000708[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000708[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000708[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000708[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000708[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000708[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000708, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800070C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800070C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800070C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800070C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800070C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800070C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800070C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800070C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800070C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800070C, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000710[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000710[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000710[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000710[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000710[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000710[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000710[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000710[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000710[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000710, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000714[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000714[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000714[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000714[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000714[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000714[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000714[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000714[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000714[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000714, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000718[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000718[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000718[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000718[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000718[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000718[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000718[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000718[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000718[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000718, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800071C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800071C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800071C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800071C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800071C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800071C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800071C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800071C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800071C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800071C, 0x00003FFFU, 0x00000600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000720[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000720[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000720[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000720[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000720[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000720[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000720[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000720[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000720[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000720, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000724[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000724[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000724[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000724[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000724[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000724[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000724[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000724[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000724[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000724, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000728[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000728[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000728[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000728[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000728[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000728[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000728[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000728[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000728[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000728, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800072C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800072C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800072C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800072C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800072C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800072C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800072C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF800072C[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800072C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800072C, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000730[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000730[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000730[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000730[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000730[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000730[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000730[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000730[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000730[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000730, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000734[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000734[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000734[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000734[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000734[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000734[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000734[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000734[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000734[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000734, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000738[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000738[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000738[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000738[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000738[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000738[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000738[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000738[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000738[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000738, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800073C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800073C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800073C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800073C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800073C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800073C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800073C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF800073C[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800073C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800073C, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000740[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000740[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000740[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000740[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000740[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000740[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000740[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000740[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000740[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000740, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000744[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000744[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000744[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000744[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000744[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000744[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000744[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000744[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000744[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000744, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000748[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000748[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000748[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000748[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000748[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000748[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000748[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000748[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000748[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000748, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800074C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800074C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800074C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800074C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800074C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800074C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800074C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800074C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF800074C[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF800074C, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000750[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000750[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000750[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000750[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000750[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000750[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000750[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000750[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000750[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000750, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000754[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000754[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000754[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000754[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000754[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000754[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000754[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000754[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000754[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000754, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000758[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000758[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000758[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000758[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000758[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000758[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000758[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000758[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000758[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000758, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800075C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800075C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800075C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800075C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800075C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800075C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800075C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800075C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800075C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800075C, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000760[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000760[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000760[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000760[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000760[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000760[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000760[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000760[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000760[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000760, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000764[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000764[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000764[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000764[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000764[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000764[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000764[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000764[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000764[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000764, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000768[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000768[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000768[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000768[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000768[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000768[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000768[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000768[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000768[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000768, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800076C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800076C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800076C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800076C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800076C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800076C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800076C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800076C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800076C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800076C, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000770[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000770[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000770[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000770[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000770[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000770[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000770[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000770[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000770[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000770, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000774[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000774[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000774[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000774[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000774[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000774[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000774[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000774[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000774[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000774, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000778[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000778[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000778[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000778[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000778[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000778[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000778[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000778[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000778[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000778, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800077C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800077C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800077C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800077C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800077C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800077C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800077C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800077C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800077C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800077C, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000780[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000780[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000780[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000780[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000780[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000780[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000780[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000780[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000780[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000780, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000784[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000784[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000784[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000784[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000784[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000784[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000784[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000784[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000784[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000784, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000788[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000788[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000788[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000788[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000788[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000788[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000788[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000788[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000788[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000788, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800078C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800078C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800078C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800078C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800078C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800078C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800078C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800078C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800078C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800078C, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000790[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000790[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000790[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000790[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000790[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000790[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000790[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000790[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000790[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000790, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000794[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000794[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000794[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000794[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000794[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000794[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000794[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000794[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000794[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000794, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000798[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000798[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000798[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000798[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000798[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000798[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000798[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000798[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000798[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000798, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800079C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800079C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800079C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800079C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800079C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800079C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800079C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800079C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800079C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800079C, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A0[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A0, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A4[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A4, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A8[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A8[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A8[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A8, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007AC[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007AC[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007AC[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007AC[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007AC[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007AC[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007AC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007AC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007AC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007AC, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007B0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007B0[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007B0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B0, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007B4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007B4[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007B4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B4, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007B8[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007B8[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF80007B8[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B8, 0x00003FFFU, 0x00001200U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF80007BC[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007BC[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007BC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007BC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007BC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007BC, 0x00003F01U, 0x00000201U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007C0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 7 */
	/* .. ==> 0XF80007C0[7:5] = 0x00000007U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x000000E0U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C0[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C0, 0x00003FFFU, 0x000002E0U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF80007C4[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 7 */
	/* .. ==> 0XF80007C4[7:5] = 0x00000007U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x000000E0U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C4[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C4, 0x00003FFFU, 0x000002E1U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007C8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007C8[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C8[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C8[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C8, 0x00003FFFU, 0x00000200U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007CC[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007CC[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007CC[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007CC[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007CC[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007CC[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007CC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007CC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007CC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007CC, 0x00003FFFU, 0x00000200U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007D0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007D0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007D0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007D0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007D0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007D0[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007D0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007D0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007D0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007D0, 0x00003FFFU, 0x00000280U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007D4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007D4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007D4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007D4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007D4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007D4[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007D4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007D4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007D4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007D4, 0x00003FFFU, 0x00000280U),
	/* .. SDIO0_WP_SEL = 55 */
	/* .. ==> 0XF8000830[5:0] = 0x00000037U */
	/* ..     ==> MASK : 0x0000003FU    VAL : 0x00000037U */
	/* .. SDIO0_CD_SEL = 47 */
	/* .. ==> 0XF8000830[21:16] = 0x0000002FU */
	/* ..     ==> MASK : 0x003F0000U    VAL : 0x002F0000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000830, 0x003F003FU, 0x002F0037U),
	/* .. FINISH: MIO PROGRAMMING */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_peripherals_init_data_2_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: DDR TERM/IBUF_DISABLE_MODE SETTINGS */
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B48[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B48[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B48, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B4C[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B4C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B4C, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B50[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B50[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B50, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B54[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B54[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B54, 0x00000180U, 0x00000180U),
	/* .. FINISH: DDR TERM/IBUF_DISABLE_MODE SETTINGS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* .. START: SRAM/NOR SET OPMODE */
	/* .. FINISH: SRAM/NOR SET OPMODE */
	/* .. START: QSPI REGISTERS */
	/* .. Holdb_dr = 1 */
	/* .. ==> 0XE000D000[19:19] = 0x00000001U */
	/* ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. */
	EMIT_MASKWRITE(0XE000D000, 0x00080000U, 0x00080000U),
	/* .. FINISH: QSPI REGISTERS */
	/* .. START: PL POWER ON RESET REGISTERS */
	/* .. PCFG_POR_CNT_4K = 0 */
	/* .. ==> 0XF8007000[29:29] = 0x00000000U */
	/* ..     ==> MASK : 0x20000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8007000, 0x20000000U, 0x00000000U),
	/* .. FINISH: PL POWER ON RESET REGISTERS */
	/* .. START: SMC TIMING CALCULATION REGISTER UPDATE */
	/* .. .. START: NAND SET CYCLE */
	/* .. .. FINISH: NAND SET CYCLE */
	/* .. .. START: OPMODE */
	/* .. .. FINISH: OPMODE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: SRAM/NOR CS0 SET CYCLE */
	/* .. .. FINISH: SRAM/NOR CS0 SET CYCLE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: NOR CS0 BASE ADDRESS */
	/* .. .. FINISH: NOR CS0 BASE ADDRESS */
	/* .. .. START: SRAM/NOR CS1 SET CYCLE */
	/* .. .. FINISH: SRAM/NOR CS1 SET CYCLE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: NOR CS1 BASE ADDRESS */
	/* .. .. FINISH: NOR CS1 BASE ADDRESS */
	/* .. .. START: USB RESET */
	/* .. .. .. START: USB0 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. DIRECTION_1 = 0x4000 */
	/* .. .. .. .. ==> 0XE000A244[21:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x003FFFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A244, 0x003FFFFFU, 0x00004000U),
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x4000 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. OP_ENABLE_1 = 0x4000 */
	/* .. .. .. .. ==> 0XE000A248[21:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x003FFFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A248, 0x003FFFFFU, 0x00004000U),
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x0 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00000000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF0000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x4000 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: USB0 RESET */
	/* .. .. .. START: USB1 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: USB1 RESET */
	/* .. .. FINISH: USB RESET */
	/* .. .. START: ENET RESET */
	/* .. .. .. START: ENET0 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: ENET0 RESET */
	/* .. .. .. START: ENET1 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: ENET1 RESET */
	/* .. .. FINISH: ENET RESET */
	/* .. .. START: I2C RESET */
	/* .. .. .. START: I2C0 RESET */
	/* .. .. .. .. START: DIR MODE GPIO BANK0 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK0 */
	/* .. .. .. .. START: DIR MODE GPIO BANK1 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: I2C0 RESET */
	/* .. .. .. START: I2C1 RESET */
	/* .. .. .. .. START: DIR MODE GPIO BANK0 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK0 */
	/* .. .. .. .. START: DIR MODE GPIO BANK1 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: I2C1 RESET */
	/* .. .. FINISH: I2C RESET */
	/* .. .. START: NOR CHIP SELECT */
	/* .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. FINISH: NOR CHIP SELECT */
	/* .. FINISH: SMC TIMING CALCULATION REGISTER UPDATE */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_post_config_2_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: ENABLING LEVEL SHIFTER */
	/* .. USER_INP_ICT_EN_0 = 3 */
	/* .. ==> 0XF8000900[1:0] = 0x00000003U */
	/* ..     ==> MASK : 0x00000003U    VAL : 0x00000003U */
	/* .. USER_INP_ICT_EN_1 = 3 */
	/* .. ==> 0XF8000900[3:2] = 0x00000003U */
	/* ..     ==> MASK : 0x0000000CU    VAL : 0x0000000CU */
	/* .. */
	EMIT_MASKWRITE(0XF8000900, 0x0000000FU, 0x0000000FU),
	/* .. FINISH: ENABLING LEVEL SHIFTER */
	/* .. START: FPGA RESETS TO 0 */
	/* .. reserved_3 = 0 */
	/* .. ==> 0XF8000240[31:25] = 0x00000000U */
	/* ..     ==> MASK : 0xFE000000U    VAL : 0x00000000U */
	/* .. FPGA_ACP_RST = 0 */
	/* .. ==> 0XF8000240[24:24] = 0x00000000U */
	/* ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS3_RST = 0 */
	/* .. ==> 0XF8000240[23:23] = 0x00000000U */
	/* ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS2_RST = 0 */
	/* .. ==> 0XF8000240[22:22] = 0x00000000U */
	/* ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS1_RST = 0 */
	/* .. ==> 0XF8000240[21:21] = 0x00000000U */
	/* ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS0_RST = 0 */
	/* .. ==> 0XF8000240[20:20] = 0x00000000U */
	/* ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. reserved_2 = 0 */
	/* .. ==> 0XF8000240[19:18] = 0x00000000U */
	/* ..     ==> MASK : 0x000C0000U    VAL : 0x00000000U */
	/* .. FSSW1_FPGA_RST = 0 */
	/* .. ==> 0XF8000240[17:17] = 0x00000000U */
	/* ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. FSSW0_FPGA_RST = 0 */
	/* .. ==> 0XF8000240[16:16] = 0x00000000U */
	/* ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. reserved_1 = 0 */
	/* .. ==> 0XF8000240[15:14] = 0x00000000U */
	/* ..     ==> MASK : 0x0000C000U    VAL : 0x00000000U */
	/* .. FPGA_FMSW1_RST = 0 */
	/* .. ==> 0XF8000240[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. FPGA_FMSW0_RST = 0 */
	/* .. ==> 0XF8000240[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. FPGA_DMA3_RST = 0 */
	/* .. ==> 0XF8000240[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. FPGA_DMA2_RST = 0 */
	/* .. ==> 0XF8000240[10:10] = 0x00000000U */
	/* ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. FPGA_DMA1_RST = 0 */
	/* .. ==> 0XF8000240[9:9] = 0x00000000U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. FPGA_DMA0_RST = 0 */
	/* .. ==> 0XF8000240[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. reserved = 0 */
	/* .. ==> 0XF8000240[7:4] = 0x00000000U */
	/* ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. FPGA3_OUT_RST = 0 */
	/* .. ==> 0XF8000240[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. FPGA2_OUT_RST = 0 */
	/* .. ==> 0XF8000240[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. FPGA1_OUT_RST = 0 */
	/* .. ==> 0XF8000240[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. FPGA0_OUT_RST = 0 */
	/* .. ==> 0XF8000240[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000240, 0xFFFFFFFFU, 0x00000000U),
	/* .. FINISH: FPGA RESETS TO 0 */
	/* .. START: AFI REGISTERS */
	/* .. .. START: AFI0 REGISTERS */
	/* .. .. FINISH: AFI0 REGISTERS */
	/* .. .. START: AFI1 REGISTERS */
	/* .. .. FINISH: AFI1 REGISTERS */
	/* .. .. START: AFI2 REGISTERS */
	/* .. .. FINISH: AFI2 REGISTERS */
	/* .. .. START: AFI3 REGISTERS */
	/* .. .. FINISH: AFI3 REGISTERS */
	/* .. FINISH: AFI REGISTERS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};


unsigned long ps7_pll_init_data_1_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: PLL SLCR REGISTERS */
	/* .. .. START: ARM PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000110[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000110[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x177 */
	/* .. .. ==> 0XF8000110[21:12] = 0x00000177U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00177000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000110, 0x003FFFF0U, 0x001772C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x1a */
	/* .. .. .. ==> 0XF8000100[18:12] = 0x0000001AU */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x0001A000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x0007F000U, 0x0001A000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000100[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000100[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000100[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. ARM_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000001U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000100[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. .. SRCSEL = 0x0 */
	/* .. .. .. ==> 0XF8000120[5:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. .. DIVISOR = 0x2 */
	/* .. .. .. ==> 0XF8000120[13:8] = 0x00000002U */
	/* .. .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000200U */
	/* .. .. .. CPU_6OR4XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[24:24] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x01000000U    VAL : 0x01000000U */
	/* .. .. .. CPU_3OR2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[25:25] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x02000000U    VAL : 0x02000000U */
	/* .. .. .. CPU_2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[26:26] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x04000000U    VAL : 0x04000000U */
	/* .. .. .. CPU_1XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[27:27] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x08000000U    VAL : 0x08000000U */
	/* .. .. .. CPU_PERI_CLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000120[28:28] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000120, 0x1F003F30U, 0x1F000200U),
	/* .. .. FINISH: ARM PLL INIT */
	/* .. .. START: DDR PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000114[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000114[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x1db */
	/* .. .. ==> 0XF8000114[21:12] = 0x000001DBU */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x001DB000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000114, 0x003FFFF0U, 0x001DB2C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x15 */
	/* .. .. .. ==> 0XF8000104[18:12] = 0x00000015U */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x00015000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x0007F000U, 0x00015000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000104[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000104[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000104[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. DDR_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[1:1] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000002U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000104[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. .. DDR_3XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000124[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. DDR_2XCLKACT = 0x1 */
	/* .. .. .. ==> 0XF8000124[1:1] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. .. DDR_3XCLK_DIVISOR = 0x2 */
	/* .. .. .. ==> 0XF8000124[25:20] = 0x00000002U */
	/* .. .. ..     ==> MASK : 0x03F00000U    VAL : 0x00200000U */
	/* .. .. .. DDR_2XCLK_DIVISOR = 0x3 */
	/* .. .. .. ==> 0XF8000124[31:26] = 0x00000003U */
	/* .. .. ..     ==> MASK : 0xFC000000U    VAL : 0x0C000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000124, 0xFFF00003U, 0x0C200003U),
	/* .. .. FINISH: DDR PLL INIT */
	/* .. .. START: IO PLL INIT */
	/* .. .. PLL_RES = 0xc */
	/* .. .. ==> 0XF8000118[7:4] = 0x0000000CU */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x000000C0U */
	/* .. .. PLL_CP = 0x2 */
	/* .. .. ==> 0XF8000118[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. LOCK_CNT = 0x1f4 */
	/* .. .. ==> 0XF8000118[21:12] = 0x000001F4U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x001F4000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000118, 0x003FFFF0U, 0x001F42C0U),
	/* .. .. .. START: UPDATE FB_DIV */
	/* .. .. .. PLL_FDIV = 0x14 */
	/* .. .. .. ==> 0XF8000108[18:12] = 0x00000014U */
	/* .. .. ..     ==> MASK : 0x0007F000U    VAL : 0x00014000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x0007F000U, 0x00014000U),
	/* .. .. .. FINISH: UPDATE FB_DIV */
	/* .. .. .. START: BY PASS PLL */
	/* .. .. .. PLL_BYPASS_FORCE = 1 */
	/* .. .. .. ==> 0XF8000108[4:4] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000010U),
	/* .. .. .. FINISH: BY PASS PLL */
	/* .. .. .. START: ASSERT RESET */
	/* .. .. .. PLL_RESET = 1 */
	/* .. .. .. ==> 0XF8000108[0:0] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000001U),
	/* .. .. .. FINISH: ASSERT RESET */
	/* .. .. .. START: DEASSERT RESET */
	/* .. .. .. PLL_RESET = 0 */
	/* .. .. .. ==> 0XF8000108[0:0] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000000U),
	/* .. .. .. FINISH: DEASSERT RESET */
	/* .. .. .. START: CHECK PLL STATUS */
	/* .. .. .. IO_PLL_LOCK = 1 */
	/* .. .. .. ==> 0XF800010C[2:2] = 0x00000001U */
	/* .. .. ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. .. .. */
	EMIT_MASKPOLL(0XF800010C, 0x00000004U),
	/* .. .. .. FINISH: CHECK PLL STATUS */
	/* .. .. .. START: REMOVE PLL BY PASS */
	/* .. .. .. PLL_BYPASS_FORCE = 0 */
	/* .. .. .. ==> 0XF8000108[4:4] = 0x00000000U */
	/* .. .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. .. */
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000000U),
	/* .. .. .. FINISH: REMOVE PLL BY PASS */
	/* .. .. FINISH: IO PLL INIT */
	/* .. FINISH: PLL SLCR REGISTERS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_clock_init_data_1_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: CLOCK CONTROL SLCR REGISTERS */
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000128[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. DIVISOR0 = 0x34 */
	/* .. ==> 0XF8000128[13:8] = 0x00000034U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00003400U */
	/* .. DIVISOR1 = 0x2 */
	/* .. ==> 0XF8000128[25:20] = 0x00000002U */
	/* ..     ==> MASK : 0x03F00000U    VAL : 0x00200000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000128, 0x03F03F01U, 0x00203401U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000138[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000138[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000138, 0x00000011U, 0x00000001U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF8000140[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000140[6:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x8 */
	/* .. ==> 0XF8000140[13:8] = 0x00000008U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000800U */
	/* .. DIVISOR1 = 0x1 */
	/* .. ==> 0XF8000140[25:20] = 0x00000001U */
	/* ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000140, 0x03F03F71U, 0x00100801U),
	/* .. CLKACT = 0x1 */
	/* .. ==> 0XF800014C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF800014C[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x5 */
	/* .. ==> 0XF800014C[13:8] = 0x00000005U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. */
	EMIT_MASKWRITE(0XF800014C, 0x00003F31U, 0x00000501U),
	/* .. CLKACT0 = 0x1 */
	/* .. ==> 0XF8000150[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. CLKACT1 = 0x0 */
	/* .. ==> 0XF8000150[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000150[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0x14 */
	/* .. ==> 0XF8000150[13:8] = 0x00000014U */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00001400U */
	/* .. */
	EMIT_MASKWRITE(0XF8000150, 0x00003F33U, 0x00001401U),
	/* .. CLKACT0 = 0x0 */
	/* .. ==> 0XF8000154[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. CLKACT1 = 0x1 */
	/* .. ==> 0XF8000154[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. SRCSEL = 0x0 */
	/* .. ==> 0XF8000154[5:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. DIVISOR = 0xa */
	/* .. ==> 0XF8000154[13:8] = 0x0000000AU */
	/* ..     ==> MASK : 0x00003F00U    VAL : 0x00000A00U */
	/* .. */
	EMIT_MASKWRITE(0XF8000154, 0x00003F33U, 0x00000A02U),
	/* .. .. START: TRACE CLOCK */
	/* .. .. FINISH: TRACE CLOCK */
	/* .. .. CLKACT = 0x1 */
	/* .. .. ==> 0XF8000168[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000168[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR = 0x5 */
	/* .. .. ==> 0XF8000168[13:8] = 0x00000005U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000168, 0x00003F31U, 0x00000501U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000170[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0xa */
	/* .. .. ==> 0XF8000170[13:8] = 0x0000000AU */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000A00U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000170[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000170, 0x03F03F30U, 0x00100A00U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000180[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x7 */
	/* .. .. ==> 0XF8000180[13:8] = 0x00000007U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000700U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000180[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000180, 0x03F03F30U, 0x00100700U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF8000190[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x5 */
	/* .. .. ==> 0XF8000190[13:8] = 0x00000005U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00000500U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF8000190[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000190, 0x03F03F30U, 0x00100500U),
	/* .. .. SRCSEL = 0x0 */
	/* .. .. ==> 0XF80001A0[5:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000030U    VAL : 0x00000000U */
	/* .. .. DIVISOR0 = 0x14 */
	/* .. .. ==> 0XF80001A0[13:8] = 0x00000014U */
	/* .. ..     ==> MASK : 0x00003F00U    VAL : 0x00001400U */
	/* .. .. DIVISOR1 = 0x1 */
	/* .. .. ==> 0XF80001A0[25:20] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03F00000U    VAL : 0x00100000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80001A0, 0x03F03F30U, 0x00101400U),
	/* .. .. CLK_621_TRUE = 0x1 */
	/* .. .. ==> 0XF80001C4[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80001C4, 0x00000001U, 0x00000001U),
	/* .. .. DMA_CPU_2XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. USB0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[2:2] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. .. USB1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[3:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. .. GEM0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[6:6] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000040U */
	/* .. .. GEM1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. SDI0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[10:10] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000400U */
	/* .. .. SDI1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. SPI0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. SPI1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. CAN0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. CAN1_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. I2C0_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[18:18] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00040000U */
	/* .. .. I2C1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. UART0_CPU_1XCLKACT = 0x0 */
	/* .. .. ==> 0XF800012C[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. UART1_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[21:21] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00200000U */
	/* .. .. GPIO_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[22:22] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00400000U */
	/* .. .. LQSPI_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[23:23] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00800000U */
	/* .. .. SMC_CPU_1XCLKACT = 0x1 */
	/* .. .. ==> 0XF800012C[24:24] = 0x00000001U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x01000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800012C, 0x01FFCCCDU, 0x01EC044DU),
	/* .. FINISH: CLOCK CONTROL SLCR REGISTERS */
	/* .. START: THIS SHOULD BE BLANK */
	/* .. FINISH: THIS SHOULD BE BLANK */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_ddr_init_data_1_0[] = {
	/* START: top */
	/* .. START: DDR INITIALIZATION */
	/* .. .. START: LOCK DDR */
	/* .. .. reg_ddrc_soft_rstb = 0 */
	/* .. .. ==> 0XF8006000[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_powerdown_en = 0x0 */
	/* .. .. ==> 0XF8006000[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_data_bus_width = 0x0 */
	/* .. .. ==> 0XF8006000[3:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000CU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_burst8_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[6:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rdwr_idle_gap = 0x1 */
	/* .. .. ==> 0XF8006000[13:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003F80U    VAL : 0x00000080U */
	/* .. .. reg_ddrc_dis_rd_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_act_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_auto_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000080U),
	/* .. .. FINISH: LOCK DDR */
	/* .. .. reg_ddrc_t_rfc_nom_x32 = 0x7f */
	/* .. .. ==> 0XF8006004[11:0] = 0x0000007FU */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x0000007FU */
	/* .. .. reg_ddrc_active_ranks = 0x1 */
	/* .. .. ==> 0XF8006004[13:12] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003000U    VAL : 0x00001000U */
	/* .. .. reg_ddrc_addrmap_cs_bit0 = 0x0 */
	/* .. .. ==> 0XF8006004[18:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0007C000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_wr_odt_block = 0x1 */
	/* .. .. ==> 0XF8006004[20:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00180000U    VAL : 0x00080000U */
	/* .. .. reg_ddrc_diff_rank_rd_2cycle_gap = 0x0 */
	/* .. .. ==> 0XF8006004[21:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_cs_bit1 = 0x0 */
	/* .. .. ==> 0XF8006004[26:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x07C00000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_open_bank = 0x0 */
	/* .. .. ==> 0XF8006004[27:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_4bank_ram = 0x0 */
	/* .. .. ==> 0XF8006004[28:28] = 0x00000000U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006004, 0x1FFFFFFFU, 0x0008107FU),
	/* .. .. reg_ddrc_hpr_min_non_critical_x32 = 0xf */
	/* .. .. ==> 0XF8006008[10:0] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x0000000FU */
	/* .. .. reg_ddrc_hpr_max_starve_x32 = 0xf */
	/* .. .. ==> 0XF8006008[21:11] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x003FF800U    VAL : 0x00007800U */
	/* .. .. reg_ddrc_hpr_xact_run_length = 0xf */
	/* .. .. ==> 0XF8006008[25:22] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x03C00000U    VAL : 0x03C00000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006008, 0x03FFFFFFU, 0x03C0780FU),
	/* .. .. reg_ddrc_lpr_min_non_critical_x32 = 0x1 */
	/* .. .. ==> 0XF800600C[10:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_lpr_max_starve_x32 = 0x2 */
	/* .. .. ==> 0XF800600C[21:11] = 0x00000002U */
	/* .. ..     ==> MASK : 0x003FF800U    VAL : 0x00001000U */
	/* .. .. reg_ddrc_lpr_xact_run_length = 0x8 */
	/* .. .. ==> 0XF800600C[25:22] = 0x00000008U */
	/* .. ..     ==> MASK : 0x03C00000U    VAL : 0x02000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800600C, 0x03FFFFFFU, 0x02001001U),
	/* .. .. reg_ddrc_w_min_non_critical_x32 = 0x1 */
	/* .. .. ==> 0XF8006010[10:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_w_xact_run_length = 0x8 */
	/* .. .. ==> 0XF8006010[14:11] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00007800U    VAL : 0x00004000U */
	/* .. .. reg_ddrc_w_max_starve_x32 = 0x2 */
	/* .. .. ==> 0XF8006010[25:15] = 0x00000002U */
	/* .. ..     ==> MASK : 0x03FF8000U    VAL : 0x00010000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006010, 0x03FFFFFFU, 0x00014001U),
	/* .. .. reg_ddrc_t_rc = 0x1a */
	/* .. .. ==> 0XF8006014[5:0] = 0x0000001AU */
	/* .. ..     ==> MASK : 0x0000003FU    VAL : 0x0000001AU */
	/* .. .. reg_ddrc_t_rfc_min = 0x54 */
	/* .. .. ==> 0XF8006014[13:6] = 0x00000054U */
	/* .. ..     ==> MASK : 0x00003FC0U    VAL : 0x00001500U */
	/* .. .. reg_ddrc_post_selfref_gap_x32 = 0x10 */
	/* .. .. ==> 0XF8006014[20:14] = 0x00000010U */
	/* .. ..     ==> MASK : 0x001FC000U    VAL : 0x00040000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006014, 0x001FFFFFU, 0x0004151AU),
	/* .. .. reg_ddrc_wr2pre = 0x12 */
	/* .. .. ==> 0XF8006018[4:0] = 0x00000012U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000012U */
	/* .. .. reg_ddrc_powerdown_to_x32 = 0x6 */
	/* .. .. ==> 0XF8006018[9:5] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x000000C0U */
	/* .. .. reg_ddrc_t_faw = 0x15 */
	/* .. .. ==> 0XF8006018[15:10] = 0x00000015U */
	/* .. ..     ==> MASK : 0x0000FC00U    VAL : 0x00005400U */
	/* .. .. reg_ddrc_t_ras_max = 0x23 */
	/* .. .. ==> 0XF8006018[21:16] = 0x00000023U */
	/* .. ..     ==> MASK : 0x003F0000U    VAL : 0x00230000U */
	/* .. .. reg_ddrc_t_ras_min = 0x13 */
	/* .. .. ==> 0XF8006018[26:22] = 0x00000013U */
	/* .. ..     ==> MASK : 0x07C00000U    VAL : 0x04C00000U */
	/* .. .. reg_ddrc_t_cke = 0x4 */
	/* .. .. ==> 0XF8006018[31:28] = 0x00000004U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006018, 0xF7FFFFFFU, 0x44E354D2U),
	/* .. .. reg_ddrc_write_latency = 0x5 */
	/* .. .. ==> 0XF800601C[4:0] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000005U */
	/* .. .. reg_ddrc_rd2wr = 0x7 */
	/* .. .. ==> 0XF800601C[9:5] = 0x00000007U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x000000E0U */
	/* .. .. reg_ddrc_wr2rd = 0xe */
	/* .. .. ==> 0XF800601C[14:10] = 0x0000000EU */
	/* .. ..     ==> MASK : 0x00007C00U    VAL : 0x00003800U */
	/* .. .. reg_ddrc_t_xp = 0x4 */
	/* .. .. ==> 0XF800601C[19:15] = 0x00000004U */
	/* .. ..     ==> MASK : 0x000F8000U    VAL : 0x00020000U */
	/* .. .. reg_ddrc_pad_pd = 0x0 */
	/* .. .. ==> 0XF800601C[22:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00700000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rd2pre = 0x4 */
	/* .. .. ==> 0XF800601C[27:23] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0F800000U    VAL : 0x02000000U */
	/* .. .. reg_ddrc_t_rcd = 0x7 */
	/* .. .. ==> 0XF800601C[31:28] = 0x00000007U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x70000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800601C, 0xFFFFFFFFU, 0x720238E5U),
	/* .. .. reg_ddrc_t_ccd = 0x4 */
	/* .. .. ==> 0XF8006020[4:2] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0000001CU    VAL : 0x00000010U */
	/* .. .. reg_ddrc_t_rrd = 0x6 */
	/* .. .. ==> 0XF8006020[7:5] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000000E0U    VAL : 0x000000C0U */
	/* .. .. reg_ddrc_refresh_margin = 0x2 */
	/* .. .. ==> 0XF8006020[11:8] = 0x00000002U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_t_rp = 0x7 */
	/* .. .. ==> 0XF8006020[15:12] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00007000U */
	/* .. .. reg_ddrc_refresh_to_x32 = 0x8 */
	/* .. .. ==> 0XF8006020[20:16] = 0x00000008U */
	/* .. ..     ==> MASK : 0x001F0000U    VAL : 0x00080000U */
	/* .. .. reg_ddrc_sdram = 0x1 */
	/* .. .. ==> 0XF8006020[21:21] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00200000U */
	/* .. .. reg_ddrc_mobile = 0x0 */
	/* .. .. ==> 0XF8006020[22:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_clock_stop_en = 0x0 */
	/* .. .. ==> 0XF8006020[23:23] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_read_latency = 0x7 */
	/* .. .. ==> 0XF8006020[28:24] = 0x00000007U */
	/* .. ..     ==> MASK : 0x1F000000U    VAL : 0x07000000U */
	/* .. .. reg_phy_mode_ddr1_ddr2 = 0x1 */
	/* .. .. ==> 0XF8006020[29:29] = 0x00000001U */
	/* .. ..     ==> MASK : 0x20000000U    VAL : 0x20000000U */
	/* .. .. reg_ddrc_dis_pad_pd = 0x0 */
	/* .. .. ==> 0XF8006020[30:30] = 0x00000000U */
	/* .. ..     ==> MASK : 0x40000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_loopback = 0x0 */
	/* .. .. ==> 0XF8006020[31:31] = 0x00000000U */
	/* .. ..     ==> MASK : 0x80000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006020, 0xFFFFFFFCU, 0x272872D0U),
	/* .. .. reg_ddrc_en_2t_timing_mode = 0x0 */
	/* .. .. ==> 0XF8006024[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_prefer_write = 0x0 */
	/* .. .. ==> 0XF8006024[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_max_rank_rd = 0xf */
	/* .. .. ==> 0XF8006024[5:2] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0000003CU    VAL : 0x0000003CU */
	/* .. .. reg_ddrc_mr_wr = 0x0 */
	/* .. .. ==> 0XF8006024[6:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_addr = 0x0 */
	/* .. .. ==> 0XF8006024[8:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000180U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_data = 0x0 */
	/* .. .. ==> 0XF8006024[24:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01FFFE00U    VAL : 0x00000000U */
	/* .. .. ddrc_reg_mr_wr_busy = 0x0 */
	/* .. .. ==> 0XF8006024[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_type = 0x0 */
	/* .. .. ==> 0XF8006024[26:26] = 0x00000000U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr_rdata_valid = 0x0 */
	/* .. .. ==> 0XF8006024[27:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006024, 0x0FFFFFFFU, 0x0000003CU),
	/* .. .. reg_ddrc_final_wait_x32 = 0x7 */
	/* .. .. ==> 0XF8006028[6:0] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000007FU    VAL : 0x00000007U */
	/* .. .. reg_ddrc_pre_ocd_x32 = 0x0 */
	/* .. .. ==> 0XF8006028[10:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000780U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_t_mrd = 0x4 */
	/* .. .. ==> 0XF8006028[13:11] = 0x00000004U */
	/* .. ..     ==> MASK : 0x00003800U    VAL : 0x00002000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006028, 0x00003FFFU, 0x00002007U),
	/* .. .. reg_ddrc_emr2 = 0x8 */
	/* .. .. ==> 0XF800602C[15:0] = 0x00000008U */
	/* .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000008U */
	/* .. .. reg_ddrc_emr3 = 0x0 */
	/* .. .. ==> 0XF800602C[31:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFF0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800602C, 0xFFFFFFFFU, 0x00000008U),
	/* .. .. reg_ddrc_mr = 0x930 */
	/* .. .. ==> 0XF8006030[15:0] = 0x00000930U */
	/* .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000930U */
	/* .. .. reg_ddrc_emr = 0x4 */
	/* .. .. ==> 0XF8006030[31:16] = 0x00000004U */
	/* .. ..     ==> MASK : 0xFFFF0000U    VAL : 0x00040000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006030, 0xFFFFFFFFU, 0x00040930U),
	/* .. .. reg_ddrc_burst_rdwr = 0x4 */
	/* .. .. ==> 0XF8006034[3:0] = 0x00000004U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000004U */
	/* .. .. reg_ddrc_pre_cke_x1024 = 0x167 */
	/* .. .. ==> 0XF8006034[13:4] = 0x00000167U */
	/* .. ..     ==> MASK : 0x00003FF0U    VAL : 0x00001670U */
	/* .. .. reg_ddrc_post_cke_x1024 = 0x1 */
	/* .. .. ==> 0XF8006034[25:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x03FF0000U    VAL : 0x00010000U */
	/* .. .. reg_ddrc_burstchop = 0x0 */
	/* .. .. ==> 0XF8006034[28:28] = 0x00000000U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006034, 0x13FF3FFFU, 0x00011674U),
	/* .. .. reg_ddrc_force_low_pri_n = 0x0 */
	/* .. .. ==> 0XF8006038[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_dq = 0x0 */
	/* .. .. ==> 0XF8006038[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_debug_mode = 0x0 */
	/* .. .. ==> 0XF8006038[6:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000040U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_level_start = 0x0 */
	/* .. .. ==> 0XF8006038[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_level_start = 0x0 */
	/* .. .. ==> 0XF8006038[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq0_wait_t = 0x0 */
	/* .. .. ==> 0XF8006038[12:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001E00U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006038, 0x00001FC3U, 0x00000000U),
	/* .. .. reg_ddrc_addrmap_bank_b0 = 0x7 */
	/* .. .. ==> 0XF800603C[3:0] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000007U */
	/* .. .. reg_ddrc_addrmap_bank_b1 = 0x7 */
	/* .. .. ==> 0XF800603C[7:4] = 0x00000007U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000070U */
	/* .. .. reg_ddrc_addrmap_bank_b2 = 0x7 */
	/* .. .. ==> 0XF800603C[11:8] = 0x00000007U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000700U */
	/* .. .. reg_ddrc_addrmap_col_b5 = 0x0 */
	/* .. .. ==> 0XF800603C[15:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b6 = 0x0 */
	/* .. .. ==> 0XF800603C[19:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800603C, 0x000FFFFFU, 0x00000777U),
	/* .. .. reg_ddrc_addrmap_col_b2 = 0x0 */
	/* .. .. ==> 0XF8006040[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b3 = 0x0 */
	/* .. .. ==> 0XF8006040[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b4 = 0x0 */
	/* .. .. ==> 0XF8006040[11:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b7 = 0x0 */
	/* .. .. ==> 0XF8006040[15:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b8 = 0x0 */
	/* .. .. ==> 0XF8006040[19:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_addrmap_col_b9 = 0xf */
	/* .. .. ==> 0XF8006040[23:20] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00F00000U    VAL : 0x00F00000U */
	/* .. .. reg_ddrc_addrmap_col_b10 = 0xf */
	/* .. .. ==> 0XF8006040[27:24] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x0F000000U */
	/* .. .. reg_ddrc_addrmap_col_b11 = 0xf */
	/* .. .. ==> 0XF8006040[31:28] = 0x0000000FU */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0xF0000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006040, 0xFFFFFFFFU, 0xFFF00000U),
	/* .. .. reg_ddrc_addrmap_row_b0 = 0x6 */
	/* .. .. ==> 0XF8006044[3:0] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000006U */
	/* .. .. reg_ddrc_addrmap_row_b1 = 0x6 */
	/* .. .. ==> 0XF8006044[7:4] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000060U */
	/* .. .. reg_ddrc_addrmap_row_b2_11 = 0x6 */
	/* .. .. ==> 0XF8006044[11:8] = 0x00000006U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000600U */
	/* .. .. reg_ddrc_addrmap_row_b12 = 0x6 */
	/* .. .. ==> 0XF8006044[15:12] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00006000U */
	/* .. .. reg_ddrc_addrmap_row_b13 = 0x6 */
	/* .. .. ==> 0XF8006044[19:16] = 0x00000006U */
	/* .. ..     ==> MASK : 0x000F0000U    VAL : 0x00060000U */
	/* .. .. reg_ddrc_addrmap_row_b14 = 0xf */
	/* .. .. ==> 0XF8006044[23:20] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00F00000U    VAL : 0x00F00000U */
	/* .. .. reg_ddrc_addrmap_row_b15 = 0xf */
	/* .. .. ==> 0XF8006044[27:24] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x0F000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006044, 0x0FFFFFFFU, 0x0FF66666U),
	/* .. .. reg_ddrc_rank0_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[2:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank0_wr_odt = 0x1 */
	/* .. .. ==> 0XF8006048[5:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000038U    VAL : 0x00000008U */
	/* .. .. reg_ddrc_rank1_rd_odt = 0x1 */
	/* .. .. ==> 0XF8006048[8:6] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000001C0U    VAL : 0x00000040U */
	/* .. .. reg_ddrc_rank1_wr_odt = 0x1 */
	/* .. .. ==> 0XF8006048[11:9] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. .. reg_phy_rd_local_odt = 0x0 */
	/* .. .. ==> 0XF8006048[13:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00003000U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_local_odt = 0x3 */
	/* .. .. ==> 0XF8006048[15:14] = 0x00000003U */
	/* .. ..     ==> MASK : 0x0000C000U    VAL : 0x0000C000U */
	/* .. .. reg_phy_idle_local_odt = 0x3 */
	/* .. .. ==> 0XF8006048[17:16] = 0x00000003U */
	/* .. ..     ==> MASK : 0x00030000U    VAL : 0x00030000U */
	/* .. .. reg_ddrc_rank2_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[20:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001C0000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank2_wr_odt = 0x0 */
	/* .. .. ==> 0XF8006048[23:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00E00000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank3_rd_odt = 0x0 */
	/* .. .. ==> 0XF8006048[26:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rank3_wr_odt = 0x0 */
	/* .. .. ==> 0XF8006048[29:27] = 0x00000000U */
	/* .. ..     ==> MASK : 0x38000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006048, 0x3FFFFFFFU, 0x0003C248U),
	/* .. .. reg_phy_rd_cmd_to_data = 0x0 */
	/* .. .. ==> 0XF8006050[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_cmd_to_data = 0x0 */
	/* .. .. ==> 0XF8006050[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_phy_rdc_we_to_re_delay = 0x8 */
	/* .. .. ==> 0XF8006050[11:8] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000800U */
	/* .. .. reg_phy_rdc_fifo_rst_disable = 0x0 */
	/* .. .. ==> 0XF8006050[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_phy_use_fixed_re = 0x1 */
	/* .. .. ==> 0XF8006050[16:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00010000U */
	/* .. .. reg_phy_rdc_fifo_rst_err_cnt_clr = 0x0 */
	/* .. .. ==> 0XF8006050[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dis_phy_ctrl_rstn = 0x0 */
	/* .. .. ==> 0XF8006050[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_phy_clk_stall_level = 0x0 */
	/* .. .. ==> 0XF8006050[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_num_of_dq0 = 0x7 */
	/* .. .. ==> 0XF8006050[27:24] = 0x00000007U */
	/* .. ..     ==> MASK : 0x0F000000U    VAL : 0x07000000U */
	/* .. .. reg_phy_wrlvl_num_of_dq0 = 0x7 */
	/* .. .. ==> 0XF8006050[31:28] = 0x00000007U */
	/* .. ..     ==> MASK : 0xF0000000U    VAL : 0x70000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006050, 0xFF0F8FFFU, 0x77010800U),
	/* .. .. reg_ddrc_dll_calib_to_min_x1024 = 0x1 */
	/* .. .. ==> 0XF8006058[7:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000001U */
	/* .. .. reg_ddrc_dll_calib_to_max_x1024 = 0x1 */
	/* .. .. ==> 0XF8006058[15:8] = 0x00000001U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00000100U */
	/* .. .. reg_ddrc_dis_dll_calib = 0x0 */
	/* .. .. ==> 0XF8006058[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006058, 0x0001FFFFU, 0x00000101U),
	/* .. .. reg_ddrc_rd_odt_delay = 0x3 */
	/* .. .. ==> 0XF800605C[3:0] = 0x00000003U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000003U */
	/* .. .. reg_ddrc_wr_odt_delay = 0x0 */
	/* .. .. ==> 0XF800605C[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rd_odt_hold = 0x0 */
	/* .. .. ==> 0XF800605C[11:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000F00U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_wr_odt_hold = 0x5 */
	/* .. .. ==> 0XF800605C[15:12] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000F000U    VAL : 0x00005000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800605C, 0x0000FFFFU, 0x00005003U),
	/* .. .. reg_ddrc_pageclose = 0x0 */
	/* .. .. ==> 0XF8006060[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_lpr_num_entries = 0x1f */
	/* .. .. ==> 0XF8006060[6:1] = 0x0000001FU */
	/* .. ..     ==> MASK : 0x0000007EU    VAL : 0x0000003EU */
	/* .. .. reg_ddrc_auto_pre_en = 0x0 */
	/* .. .. ==> 0XF8006060[7:7] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_refresh_update_level = 0x0 */
	/* .. .. ==> 0XF8006060[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_wc = 0x0 */
	/* .. .. ==> 0XF8006060[9:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_collision_page_opt = 0x0 */
	/* .. .. ==> 0XF8006060[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_selfref_en = 0x0 */
	/* .. .. ==> 0XF8006060[12:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006060, 0x000017FFU, 0x0000003EU),
	/* .. .. reg_ddrc_go2critical_hysteresis = 0x0 */
	/* .. .. ==> 0XF8006064[12:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00001FE0U    VAL : 0x00000000U */
	/* .. .. reg_arb_go2critical_en = 0x1 */
	/* .. .. ==> 0XF8006064[17:17] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00020000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006064, 0x00021FE0U, 0x00020000U),
	/* .. .. reg_ddrc_wrlvl_ww = 0x41 */
	/* .. .. ==> 0XF8006068[7:0] = 0x00000041U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000041U */
	/* .. .. reg_ddrc_rdlvl_rr = 0x41 */
	/* .. .. ==> 0XF8006068[15:8] = 0x00000041U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00004100U */
	/* .. .. reg_ddrc_dfi_t_wlmrd = 0x28 */
	/* .. .. ==> 0XF8006068[25:16] = 0x00000028U */
	/* .. ..     ==> MASK : 0x03FF0000U    VAL : 0x00280000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006068, 0x03FFFFFFU, 0x00284141U),
	/* .. .. dfi_t_ctrlupd_interval_min_x1024 = 0x10 */
	/* .. .. ==> 0XF800606C[7:0] = 0x00000010U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000010U */
	/* .. .. dfi_t_ctrlupd_interval_max_x1024 = 0x16 */
	/* .. .. ==> 0XF800606C[15:8] = 0x00000016U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00001600U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800606C, 0x0000FFFFU, 0x00001610U),
	/* .. .. refresh_timer0_start_value_x32 = 0x0 */
	/* .. .. ==> 0XF80060A0[11:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x00000000U */
	/* .. .. refresh_timer1_start_value_x32 = 0x8 */
	/* .. .. ==> 0XF80060A0[23:12] = 0x00000008U */
	/* .. ..     ==> MASK : 0x00FFF000U    VAL : 0x00008000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A0, 0x00FFFFFFU, 0x00008000U),
	/* .. .. reg_ddrc_dis_auto_zq = 0x0 */
	/* .. .. ==> 0XF80060A4[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_ddr3 = 0x1 */
	/* .. .. ==> 0XF80060A4[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. reg_ddrc_t_mod = 0x200 */
	/* .. .. ==> 0XF80060A4[11:2] = 0x00000200U */
	/* .. ..     ==> MASK : 0x00000FFCU    VAL : 0x00000800U */
	/* .. .. reg_ddrc_t_zq_long_nop = 0x200 */
	/* .. .. ==> 0XF80060A4[21:12] = 0x00000200U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00200000U */
	/* .. .. reg_ddrc_t_zq_short_nop = 0x40 */
	/* .. .. ==> 0XF80060A4[31:22] = 0x00000040U */
	/* .. ..     ==> MASK : 0xFFC00000U    VAL : 0x10000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A4, 0xFFFFFFFFU, 0x10200802U),
	/* .. .. t_zq_short_interval_x1024 = 0xc845 */
	/* .. .. ==> 0XF80060A8[19:0] = 0x0000C845U */
	/* .. ..     ==> MASK : 0x000FFFFFU    VAL : 0x0000C845U */
	/* .. .. dram_rstn_x1024 = 0x67 */
	/* .. .. ==> 0XF80060A8[27:20] = 0x00000067U */
	/* .. ..     ==> MASK : 0x0FF00000U    VAL : 0x06700000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060A8, 0x0FFFFFFFU, 0x0670C845U),
	/* .. .. deeppowerdown_en = 0x0 */
	/* .. .. ==> 0XF80060AC[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. deeppowerdown_to_x1024 = 0xff */
	/* .. .. ==> 0XF80060AC[8:1] = 0x000000FFU */
	/* .. ..     ==> MASK : 0x000001FEU    VAL : 0x000001FEU */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060AC, 0x000001FFU, 0x000001FEU),
	/* .. .. dfi_wrlvl_max_x1024 = 0xfff */
	/* .. .. ==> 0XF80060B0[11:0] = 0x00000FFFU */
	/* .. ..     ==> MASK : 0x00000FFFU    VAL : 0x00000FFFU */
	/* .. .. dfi_rdlvl_max_x1024 = 0xfff */
	/* .. .. ==> 0XF80060B0[23:12] = 0x00000FFFU */
	/* .. ..     ==> MASK : 0x00FFF000U    VAL : 0x00FFF000U */
	/* .. .. ddrc_reg_twrlvl_max_error = 0x0 */
	/* .. .. ==> 0XF80060B0[24:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. .. ddrc_reg_trdlvl_max_error = 0x0 */
	/* .. .. ==> 0XF80060B0[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dfi_wr_level_en = 0x1 */
	/* .. .. ==> 0XF80060B0[26:26] = 0x00000001U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x04000000U */
	/* .. .. reg_ddrc_dfi_rd_dqs_gate_level = 0x1 */
	/* .. .. ==> 0XF80060B0[27:27] = 0x00000001U */
	/* .. ..     ==> MASK : 0x08000000U    VAL : 0x08000000U */
	/* .. .. reg_ddrc_dfi_rd_data_eye_train = 0x1 */
	/* .. .. ==> 0XF80060B0[28:28] = 0x00000001U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B0, 0x1FFFFFFFU, 0x1CFFFFFFU),
	/* .. .. reg_ddrc_2t_delay = 0x0 */
	/* .. .. ==> 0XF80060B4[8:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000001FFU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_skip_ocd = 0x1 */
	/* .. .. ==> 0XF80060B4[9:9] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000200U */
	/* .. .. reg_ddrc_dis_pre_bypass = 0x0 */
	/* .. .. ==> 0XF80060B4[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B4, 0x000007FFU, 0x00000200U),
	/* .. .. reg_ddrc_dfi_t_rddata_en = 0x6 */
	/* .. .. ==> 0XF80060B8[4:0] = 0x00000006U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000006U */
	/* .. .. reg_ddrc_dfi_t_ctrlup_min = 0x3 */
	/* .. .. ==> 0XF80060B8[14:5] = 0x00000003U */
	/* .. ..     ==> MASK : 0x00007FE0U    VAL : 0x00000060U */
	/* .. .. reg_ddrc_dfi_t_ctrlup_max = 0x40 */
	/* .. .. ==> 0XF80060B8[24:15] = 0x00000040U */
	/* .. ..     ==> MASK : 0x01FF8000U    VAL : 0x00200000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060B8, 0x01FFFFFFU, 0x00200066U),
	/* .. .. START: RESET ECC ERROR */
	/* .. .. Clear_Uncorrectable_DRAM_ECC_error = 1 */
	/* .. .. ==> 0XF80060C4[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. Clear_Correctable_DRAM_ECC_error = 1 */
	/* .. .. ==> 0XF80060C4[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000003U),
	/* .. .. FINISH: RESET ECC ERROR */
	/* .. .. Clear_Uncorrectable_DRAM_ECC_error = 0x0 */
	/* .. .. ==> 0XF80060C4[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. Clear_Correctable_DRAM_ECC_error = 0x0 */
	/* .. .. ==> 0XF80060C4[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000000U),
	/* .. .. CORR_ECC_LOG_VALID = 0x0 */
	/* .. .. ==> 0XF80060C8[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. ECC_CORRECTED_BIT_NUM = 0x0 */
	/* .. .. ==> 0XF80060C8[7:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000FEU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060C8, 0x000000FFU, 0x00000000U),
	/* .. .. UNCORR_ECC_LOG_VALID = 0x0 */
	/* .. .. ==> 0XF80060DC[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060DC, 0x00000001U, 0x00000000U),
	/* .. .. STAT_NUM_CORR_ERR = 0x0 */
	/* .. .. ==> 0XF80060F0[15:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000FF00U    VAL : 0x00000000U */
	/* .. .. STAT_NUM_UNCORR_ERR = 0x0 */
	/* .. .. ==> 0XF80060F0[7:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060F0, 0x0000FFFFU, 0x00000000U),
	/* .. .. reg_ddrc_ecc_mode = 0x0 */
	/* .. .. ==> 0XF80060F4[2:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_scrub = 0x1 */
	/* .. .. ==> 0XF80060F4[3:3] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000008U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80060F4, 0x0000000FU, 0x00000008U),
	/* .. .. reg_phy_dif_on = 0x0 */
	/* .. .. ==> 0XF8006114[3:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000000U */
	/* .. .. reg_phy_dif_off = 0x0 */
	/* .. .. ==> 0XF8006114[7:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006114, 0x000000FFU, 0x00000000U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006118[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006118[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006118[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006118[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006118[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006118[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006118[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006118, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF800611C[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF800611C[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF800611C[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF800611C[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF800611C[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF800611C[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF800611C[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800611C, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006120[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006120[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006120[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006120[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006120[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006120[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006120[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006120, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_data_slice_in_use = 0x1 */
	/* .. .. ==> 0XF8006124[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_phy_rdlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_wrlvl_inc_mode = 0x0 */
	/* .. .. ==> 0XF8006124[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_tx = 0x0 */
	/* .. .. ==> 0XF8006124[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_board_lpbk_rx = 0x0 */
	/* .. .. ==> 0XF8006124[5:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_shift_dq = 0x0 */
	/* .. .. ==> 0XF8006124[14:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00007FC0U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_err_clr = 0x0 */
	/* .. .. ==> 0XF8006124[23:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00FF8000U    VAL : 0x00000000U */
	/* .. .. reg_phy_dq_offset = 0x40 */
	/* .. .. ==> 0XF8006124[30:24] = 0x00000040U */
	/* .. ..     ==> MASK : 0x7F000000U    VAL : 0x40000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006124, 0x7FFFFFFFU, 0x40000001U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF800612C[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8f */
	/* .. .. ==> 0XF800612C[19:10] = 0x0000008FU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00023C00U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800612C, 0x000FFFFFU, 0x00023C00U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006130[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8a */
	/* .. .. ==> 0XF8006130[19:10] = 0x0000008AU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00022800U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006130, 0x000FFFFFU, 0x00022800U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006134[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x8b */
	/* .. .. ==> 0XF8006134[19:10] = 0x0000008BU */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00022C00U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006134, 0x000FFFFFU, 0x00022C00U),
	/* .. .. reg_phy_wrlvl_init_ratio = 0x0 */
	/* .. .. ==> 0XF8006138[9:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000000U */
	/* .. .. reg_phy_gatelvl_init_ratio = 0x92 */
	/* .. .. ==> 0XF8006138[19:10] = 0x00000092U */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00024800U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006138, 0x000FFFFFU, 0x00024800U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006140[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006140[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006140[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006140, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006144[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006144[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006144[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006144, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF8006148[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006148[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006148[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006148, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_rd_dqs_slave_ratio = 0x35 */
	/* .. .. ==> 0XF800614C[9:0] = 0x00000035U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000035U */
	/* .. .. reg_phy_rd_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF800614C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_rd_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF800614C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800614C, 0x000FFFFFU, 0x00000035U),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x77 */
	/* .. .. ==> 0XF8006154[9:0] = 0x00000077U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000077U */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006154[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006154[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006154, 0x000FFFFFU, 0x00000077U),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x7c */
	/* .. .. ==> 0XF8006158[9:0] = 0x0000007CU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x0000007CU */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006158[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006158[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006158, 0x000FFFFFU, 0x0000007CU),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x7c */
	/* .. .. ==> 0XF800615C[9:0] = 0x0000007CU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x0000007CU */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF800615C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF800615C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800615C, 0x000FFFFFU, 0x0000007CU),
	/* .. .. reg_phy_wr_dqs_slave_ratio = 0x75 */
	/* .. .. ==> 0XF8006160[9:0] = 0x00000075U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x00000075U */
	/* .. .. reg_phy_wr_dqs_slave_force = 0x0 */
	/* .. .. ==> 0XF8006160[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_dqs_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006160[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006160, 0x000FFFFFU, 0x00000075U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe4 */
	/* .. .. ==> 0XF8006168[10:0] = 0x000000E4U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E4U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006168[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006168[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006168, 0x001FFFFFU, 0x000000E4U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xdf */
	/* .. .. ==> 0XF800616C[10:0] = 0x000000DFU */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000DFU */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF800616C[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF800616C[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800616C, 0x001FFFFFU, 0x000000DFU),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe0 */
	/* .. .. ==> 0XF8006170[10:0] = 0x000000E0U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E0U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006170[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006170[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006170, 0x001FFFFFU, 0x000000E0U),
	/* .. .. reg_phy_fifo_we_slave_ratio = 0xe7 */
	/* .. .. ==> 0XF8006174[10:0] = 0x000000E7U */
	/* .. ..     ==> MASK : 0x000007FFU    VAL : 0x000000E7U */
	/* .. .. reg_phy_fifo_we_in_force = 0x0 */
	/* .. .. ==> 0XF8006174[11:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. .. reg_phy_fifo_we_in_delay = 0x0 */
	/* .. .. ==> 0XF8006174[20:12] = 0x00000000U */
	/* .. ..     ==> MASK : 0x001FF000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006174, 0x001FFFFFU, 0x000000E7U),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xb7 */
	/* .. .. ==> 0XF800617C[9:0] = 0x000000B7U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000B7U */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF800617C[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF800617C[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800617C, 0x000FFFFFU, 0x000000B7U),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xbc */
	/* .. .. ==> 0XF8006180[9:0] = 0x000000BCU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000BCU */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006180[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006180[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006180, 0x000FFFFFU, 0x000000BCU),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xbc */
	/* .. .. ==> 0XF8006184[9:0] = 0x000000BCU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000BCU */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006184[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006184[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006184, 0x000FFFFFU, 0x000000BCU),
	/* .. .. reg_phy_wr_data_slave_ratio = 0xb5 */
	/* .. .. ==> 0XF8006188[9:0] = 0x000000B5U */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000000B5U */
	/* .. .. reg_phy_wr_data_slave_force = 0x0 */
	/* .. .. ==> 0XF8006188[10:10] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. .. reg_phy_wr_data_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006188[19:11] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000FF800U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006188, 0x000FFFFFU, 0x000000B5U),
	/* .. .. reg_phy_loopback = 0x0 */
	/* .. .. ==> 0XF8006190[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_phy_bl2 = 0x0 */
	/* .. .. ==> 0XF8006190[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_phy_at_spd_atpg = 0x0 */
	/* .. .. ==> 0XF8006190[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_enable = 0x0 */
	/* .. .. ==> 0XF8006190[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_force_err = 0x0 */
	/* .. .. ==> 0XF8006190[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. reg_phy_bist_mode = 0x0 */
	/* .. .. ==> 0XF8006190[6:5] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. .. reg_phy_invert_clkout = 0x1 */
	/* .. .. ==> 0XF8006190[7:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. .. reg_phy_all_dq_mpr_rd_resp = 0x0 */
	/* .. .. ==> 0XF8006190[8:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. .. reg_phy_sel_logic = 0x0 */
	/* .. .. ==> 0XF8006190[9:9] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_ratio = 0x100 */
	/* .. .. ==> 0XF8006190[19:10] = 0x00000100U */
	/* .. ..     ==> MASK : 0x000FFC00U    VAL : 0x00040000U */
	/* .. .. reg_phy_ctrl_slave_force = 0x0 */
	/* .. .. ==> 0XF8006190[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006190[27:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0FE00000U    VAL : 0x00000000U */
	/* .. .. reg_phy_use_rank0_delays = 0x1 */
	/* .. .. ==> 0XF8006190[28:28] = 0x00000001U */
	/* .. ..     ==> MASK : 0x10000000U    VAL : 0x10000000U */
	/* .. .. reg_phy_lpddr = 0x0 */
	/* .. .. ==> 0XF8006190[29:29] = 0x00000000U */
	/* .. ..     ==> MASK : 0x20000000U    VAL : 0x00000000U */
	/* .. .. reg_phy_cmd_latency = 0x0 */
	/* .. .. ==> 0XF8006190[30:30] = 0x00000000U */
	/* .. ..     ==> MASK : 0x40000000U    VAL : 0x00000000U */
	/* .. .. reg_phy_int_lpbk = 0x0 */
	/* .. .. ==> 0XF8006190[31:31] = 0x00000000U */
	/* .. ..     ==> MASK : 0x80000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006190, 0xFFFFFFFFU, 0x10040080U),
	/* .. .. reg_phy_wr_rl_delay = 0x2 */
	/* .. .. ==> 0XF8006194[4:0] = 0x00000002U */
	/* .. ..     ==> MASK : 0x0000001FU    VAL : 0x00000002U */
	/* .. .. reg_phy_rd_rl_delay = 0x4 */
	/* .. .. ==> 0XF8006194[9:5] = 0x00000004U */
	/* .. ..     ==> MASK : 0x000003E0U    VAL : 0x00000080U */
	/* .. .. reg_phy_dll_lock_diff = 0xf */
	/* .. .. ==> 0XF8006194[13:10] = 0x0000000FU */
	/* .. ..     ==> MASK : 0x00003C00U    VAL : 0x00003C00U */
	/* .. .. reg_phy_use_wr_level = 0x1 */
	/* .. .. ==> 0XF8006194[14:14] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00004000U */
	/* .. .. reg_phy_use_rd_dqs_gate_level = 0x1 */
	/* .. .. ==> 0XF8006194[15:15] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00008000U */
	/* .. .. reg_phy_use_rd_data_eye_level = 0x1 */
	/* .. .. ==> 0XF8006194[16:16] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00010000U */
	/* .. .. reg_phy_dis_calib_rst = 0x0 */
	/* .. .. ==> 0XF8006194[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_phy_ctrl_slave_delay = 0x0 */
	/* .. .. ==> 0XF8006194[19:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000C0000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006194, 0x000FFFFFU, 0x0001FC82U),
	/* .. .. reg_arb_page_addr_mask = 0x0 */
	/* .. .. ==> 0XF8006204[31:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFFFFFFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006204, 0xFFFFFFFFU, 0x00000000U),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006208[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006208[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF8006208[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006208, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF800620C[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF800620C[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF800620C[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800620C, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006210[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006210[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF8006210[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006210, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_wr_portn = 0x3ff */
	/* .. .. ==> 0XF8006214[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_wr_portn = 0x0 */
	/* .. .. ==> 0XF8006214[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_rmw_portn = 0x1 */
	/* .. .. ==> 0XF8006214[19:19] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006214, 0x000F03FFU, 0x000803FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006218[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006218[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006218, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF800621C[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF800621C[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF800621C, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006220[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006220[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006220, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_arb_pri_rd_portn = 0x3ff */
	/* .. .. ==> 0XF8006224[9:0] = 0x000003FFU */
	/* .. ..     ==> MASK : 0x000003FFU    VAL : 0x000003FFU */
	/* .. .. reg_arb_disable_aging_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. reg_arb_disable_urgent_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[17:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. .. reg_arb_dis_page_match_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[18:18] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00040000U    VAL : 0x00000000U */
	/* .. .. reg_arb_set_hpr_rd_portn = 0x0 */
	/* .. .. ==> 0XF8006224[19:19] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00080000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006224, 0x000F03FFU, 0x000003FFU),
	/* .. .. reg_ddrc_lpddr2 = 0x0 */
	/* .. .. ==> 0XF80062A8[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_per_bank_refresh = 0x0 */
	/* .. .. ==> 0XF80062A8[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_derate_enable = 0x0 */
	/* .. .. ==> 0XF80062A8[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_mr4_margin = 0x0 */
	/* .. .. ==> 0XF80062A8[11:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000FF0U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062A8, 0x00000FF7U, 0x00000000U),
	/* .. .. reg_ddrc_mr4_read_interval = 0x0 */
	/* .. .. ==> 0XF80062AC[31:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0xFFFFFFFFU    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062AC, 0xFFFFFFFFU, 0x00000000U),
	/* .. .. reg_ddrc_min_stable_clock_x1 = 0x5 */
	/* .. .. ==> 0XF80062B0[3:0] = 0x00000005U */
	/* .. ..     ==> MASK : 0x0000000FU    VAL : 0x00000005U */
	/* .. .. reg_ddrc_idle_after_reset_x32 = 0x12 */
	/* .. .. ==> 0XF80062B0[11:4] = 0x00000012U */
	/* .. ..     ==> MASK : 0x00000FF0U    VAL : 0x00000120U */
	/* .. .. reg_ddrc_t_mrw = 0x5 */
	/* .. .. ==> 0XF80062B0[21:12] = 0x00000005U */
	/* .. ..     ==> MASK : 0x003FF000U    VAL : 0x00005000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062B0, 0x003FFFFFU, 0x00005125U),
	/* .. .. reg_ddrc_max_auto_init_x1024 = 0xa6 */
	/* .. .. ==> 0XF80062B4[7:0] = 0x000000A6U */
	/* .. ..     ==> MASK : 0x000000FFU    VAL : 0x000000A6U */
	/* .. .. reg_ddrc_dev_zqinit_x32 = 0x12 */
	/* .. .. ==> 0XF80062B4[17:8] = 0x00000012U */
	/* .. ..     ==> MASK : 0x0003FF00U    VAL : 0x00001200U */
	/* .. .. */
	EMIT_MASKWRITE(0XF80062B4, 0x0003FFFFU, 0x000012A6U),
	/* .. .. START: POLL ON DCI STATUS */
	/* .. .. DONE = 1 */
	/* .. .. ==> 0XF8000B74[13:13] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. .. */
	EMIT_MASKPOLL(0XF8000B74, 0x00002000U),
	/* .. .. FINISH: POLL ON DCI STATUS */
	/* .. .. START: UNLOCK DDR */
	/* .. .. reg_ddrc_soft_rstb = 0x1 */
	/* .. .. ==> 0XF8006000[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. reg_ddrc_powerdown_en = 0x0 */
	/* .. .. ==> 0XF8006000[1:1] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_data_bus_width = 0x0 */
	/* .. .. ==> 0XF8006000[3:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0000000CU    VAL : 0x00000000U */
	/* .. .. reg_ddrc_burst8_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[6:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000070U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_rdwr_idle_gap = 1 */
	/* .. .. ==> 0XF8006000[13:7] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003F80U    VAL : 0x00000080U */
	/* .. .. reg_ddrc_dis_rd_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[14:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_act_bypass = 0x0 */
	/* .. .. ==> 0XF8006000[15:15] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00008000U    VAL : 0x00000000U */
	/* .. .. reg_ddrc_dis_auto_refresh = 0x0 */
	/* .. .. ==> 0XF8006000[16:16] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000081U),
	/* .. .. FINISH: UNLOCK DDR */
	/* .. .. START: CHECK DDR STATUS */
	/* .. .. ddrc_reg_operating_mode = 1 */
	/* .. .. ==> 0XF8006054[2:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000007U    VAL : 0x00000001U */
	/* .. .. */
	EMIT_MASKPOLL(0XF8006054, 0x00000007U),
	/* .. .. FINISH: CHECK DDR STATUS */
	/* .. FINISH: DDR INITIALIZATION */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_mio_init_data_1_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: OCM REMAPPING */
	/* .. VREF_EN = 0x1 */
	/* .. ==> 0XF8000B00[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. VREF_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B00[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. CLK_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B00[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. SRSTN_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B00[9:9] = 0x00000000U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B00, 0x00000303U, 0x00000001U),
	/* .. FINISH: OCM REMAPPING */
	/* .. START: DDRIOB SETTINGS */
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B40[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B40[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B40[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B40[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCR_TYPE = 0x0 */
	/* .. ==> 0XF8000B40[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B40[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B40[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B40[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B40[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B40, 0x00000FFFU, 0x00000600U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B44[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B44[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B44[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B44[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCR_TYPE = 0x0 */
	/* .. ==> 0XF8000B44[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B44[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B44[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B44[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B44[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B44, 0x00000FFFU, 0x00000600U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B48[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x1 */
	/* .. ==> 0XF8000B48[2:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000002U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B48[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B48[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B48[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B48[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B48[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B48[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B48[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B48, 0x00000FFFU, 0x00000672U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B4C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x1 */
	/* .. ==> 0XF8000B4C[2:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000002U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B4C[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B4C[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B4C[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B4C[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B4C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B4C[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B4C[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B4C, 0x00000FFFU, 0x00000672U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B50[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x2 */
	/* .. ==> 0XF8000B50[2:1] = 0x00000002U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000004U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B50[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B50[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B50[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B50[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B50[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B50[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B50[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B50, 0x00000FFFU, 0x00000674U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B54[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x2 */
	/* .. ==> 0XF8000B54[2:1] = 0x00000002U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000004U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B54[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x1 */
	/* .. ==> 0XF8000B54[4:4] = 0x00000001U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000010U */
	/* .. DCR_TYPE = 0x3 */
	/* .. ==> 0XF8000B54[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. IBUF_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B54[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0 */
	/* .. ==> 0XF8000B54[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B54[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B54[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B54, 0x00000FFFU, 0x00000674U),
	/* .. INP_POWER = 0x0 */
	/* .. ==> 0XF8000B58[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. INP_TYPE = 0x0 */
	/* .. ==> 0XF8000B58[2:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000006U    VAL : 0x00000000U */
	/* .. DCI_UPDATE = 0x0 */
	/* .. ==> 0XF8000B58[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. TERM_EN = 0x0 */
	/* .. ==> 0XF8000B58[4:4] = 0x00000000U */
	/* ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. DCR_TYPE = 0x0 */
	/* .. ==> 0XF8000B58[6:5] = 0x00000000U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000000U */
	/* .. IBUF_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B58[7:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000000U */
	/* .. TERM_DISABLE_MODE = 0x0 */
	/* .. ==> 0XF8000B58[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. OUTPUT_EN = 0x3 */
	/* .. ==> 0XF8000B58[10:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000600U    VAL : 0x00000600U */
	/* .. PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B58[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B58, 0x00000FFFU, 0x00000600U),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B5C[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B5C[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x3 */
	/* .. ==> 0XF8000B5C[18:14] = 0x00000003U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x0000C000U */
	/* .. SLEW_N = 0x3 */
	/* .. ==> 0XF8000B5C[23:19] = 0x00000003U */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00180000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B5C[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B5C[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B5C, 0xFFFFFFFFU, 0x0018C61CU),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B60[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B60[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x6 */
	/* .. ==> 0XF8000B60[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. SLEW_N = 0x1f */
	/* .. ==> 0XF8000B60[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B60[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B60[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B60, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B64[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B64[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x6 */
	/* .. ==> 0XF8000B64[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. SLEW_N = 0x1f */
	/* .. ==> 0XF8000B64[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B64[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B64[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B64, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. DRIVE_P = 0x1c */
	/* .. ==> 0XF8000B68[6:0] = 0x0000001CU */
	/* ..     ==> MASK : 0x0000007FU    VAL : 0x0000001CU */
	/* .. DRIVE_N = 0xc */
	/* .. ==> 0XF8000B68[13:7] = 0x0000000CU */
	/* ..     ==> MASK : 0x00003F80U    VAL : 0x00000600U */
	/* .. SLEW_P = 0x6 */
	/* .. ==> 0XF8000B68[18:14] = 0x00000006U */
	/* ..     ==> MASK : 0x0007C000U    VAL : 0x00018000U */
	/* .. SLEW_N = 0x1f */
	/* .. ==> 0XF8000B68[23:19] = 0x0000001FU */
	/* ..     ==> MASK : 0x00F80000U    VAL : 0x00F80000U */
	/* .. GTL = 0x0 */
	/* .. ==> 0XF8000B68[26:24] = 0x00000000U */
	/* ..     ==> MASK : 0x07000000U    VAL : 0x00000000U */
	/* .. RTERM = 0x0 */
	/* .. ==> 0XF8000B68[31:27] = 0x00000000U */
	/* ..     ==> MASK : 0xF8000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B68, 0xFFFFFFFFU, 0x00F9861CU),
	/* .. VREF_INT_EN = 0x0 */
	/* .. ==> 0XF8000B6C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. VREF_SEL = 0x0 */
	/* .. ==> 0XF8000B6C[4:1] = 0x00000000U */
	/* ..     ==> MASK : 0x0000001EU    VAL : 0x00000000U */
	/* .. VREF_EXT_EN = 0x3 */
	/* .. ==> 0XF8000B6C[6:5] = 0x00000003U */
	/* ..     ==> MASK : 0x00000060U    VAL : 0x00000060U */
	/* .. VREF_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[8:7] = 0x00000000U */
	/* ..     ==> MASK : 0x00000180U    VAL : 0x00000000U */
	/* .. REFIO_EN = 0x1 */
	/* .. ==> 0XF8000B6C[9:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000200U */
	/* .. REFIO_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DRST_B_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. CKE_PULLUP_EN = 0x0 */
	/* .. ==> 0XF8000B6C[14:14] = 0x00000000U */
	/* ..     ==> MASK : 0x00004000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B6C, 0x000073FFU, 0x00000260U),
	/* .. .. START: ASSERT RESET */
	/* .. .. RESET = 1 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x00000021U, 0x00000021U),
	/* .. .. FINISH: ASSERT RESET */
	/* .. .. START: DEASSERT RESET */
	/* .. .. RESET = 0 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. .. VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x00000021U, 0x00000020U),
	/* .. .. FINISH: DEASSERT RESET */
	/* .. .. RESET = 0x1 */
	/* .. .. ==> 0XF8000B70[0:0] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. .. ENABLE = 0x1 */
	/* .. .. ==> 0XF8000B70[1:1] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. .. VRP_TRI = 0x0 */
	/* .. .. ==> 0XF8000B70[2:2] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. .. VRN_TRI = 0x0 */
	/* .. .. ==> 0XF8000B70[3:3] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. .. VRP_OUT = 0x0 */
	/* .. .. ==> 0XF8000B70[4:4] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000010U    VAL : 0x00000000U */
	/* .. .. VRN_OUT = 0x1 */
	/* .. .. ==> 0XF8000B70[5:5] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00000020U    VAL : 0x00000020U */
	/* .. .. NREF_OPT1 = 0x0 */
	/* .. .. ==> 0XF8000B70[7:6] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000000C0U    VAL : 0x00000000U */
	/* .. .. NREF_OPT2 = 0x0 */
	/* .. .. ==> 0XF8000B70[10:8] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00000700U    VAL : 0x00000000U */
	/* .. .. NREF_OPT4 = 0x1 */
	/* .. .. ==> 0XF8000B70[13:11] = 0x00000001U */
	/* .. ..     ==> MASK : 0x00003800U    VAL : 0x00000800U */
	/* .. .. PREF_OPT1 = 0x0 */
	/* .. .. ==> 0XF8000B70[16:14] = 0x00000000U */
	/* .. ..     ==> MASK : 0x0001C000U    VAL : 0x00000000U */
	/* .. .. PREF_OPT2 = 0x0 */
	/* .. .. ==> 0XF8000B70[19:17] = 0x00000000U */
	/* .. ..     ==> MASK : 0x000E0000U    VAL : 0x00000000U */
	/* .. .. UPDATE_CONTROL = 0x0 */
	/* .. .. ==> 0XF8000B70[20:20] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. .. INIT_COMPLETE = 0x0 */
	/* .. .. ==> 0XF8000B70[21:21] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. .. TST_CLK = 0x0 */
	/* .. .. ==> 0XF8000B70[22:22] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. .. TST_HLN = 0x0 */
	/* .. .. ==> 0XF8000B70[23:23] = 0x00000000U */
	/* .. ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. .. TST_HLP = 0x0 */
	/* .. .. ==> 0XF8000B70[24:24] = 0x00000000U */
	/* .. ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. .. TST_RST = 0x0 */
	/* .. .. ==> 0XF8000B70[25:25] = 0x00000000U */
	/* .. ..     ==> MASK : 0x02000000U    VAL : 0x00000000U */
	/* .. .. INT_DCI_EN = 0x0 */
	/* .. .. ==> 0XF8000B70[26:26] = 0x00000000U */
	/* .. ..     ==> MASK : 0x04000000U    VAL : 0x00000000U */
	/* .. .. */
	EMIT_MASKWRITE(0XF8000B70, 0x07FFFFFFU, 0x00000823U),
	/* .. FINISH: DDRIOB SETTINGS */
	/* .. START: MIO PROGRAMMING */
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000700[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000700[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000700[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000700[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000700[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000700[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000700[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000700[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000700[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000700, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000704[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000704[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000704[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000704[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000704[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000704[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000704[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000704[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000704[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000704, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000708[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000708[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000708[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000708[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000708[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000708[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000708[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000708[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000708[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000708, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800070C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800070C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800070C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800070C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800070C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800070C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800070C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800070C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800070C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800070C, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000710[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000710[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000710[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000710[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000710[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000710[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000710[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000710[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000710[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000710, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000714[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000714[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000714[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000714[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000714[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000714[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000714[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000714[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000714[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000714, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000718[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000718[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000718[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000718[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000718[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000718[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000718[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000718[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000718[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000718, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800071C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800071C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800071C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800071C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800071C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800071C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800071C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800071C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800071C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800071C, 0x00003FFFU, 0x00000600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000720[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000720[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000720[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000720[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000720[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000720[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000720[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000720[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000720[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000720, 0x00003FFFU, 0x00000702U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000724[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000724[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000724[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000724[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000724[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000724[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000724[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000724[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000724[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000724, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000728[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000728[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000728[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000728[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000728[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000728[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000728[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000728[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000728[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000728, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800072C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800072C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800072C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800072C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800072C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800072C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800072C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF800072C[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800072C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800072C, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000730[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000730[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000730[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000730[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000730[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000730[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000730[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000730[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000730[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000730, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000734[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000734[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000734[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000734[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000734[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000734[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000734[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000734[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000734[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000734, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000738[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000738[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000738[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000738[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000738[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF8000738[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF8000738[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF8000738[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000738[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000738, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800073C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800073C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800073C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800073C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800073C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF800073C[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 3 */
	/* .. ==> 0XF800073C[11:9] = 0x00000003U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000600U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF800073C[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800073C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800073C, 0x00003FFFU, 0x00001600U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000740[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000740[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000740[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000740[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000740[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000740[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000740[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000740[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000740[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000740, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000744[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000744[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000744[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000744[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000744[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000744[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000744[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000744[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000744[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000744, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000748[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000748[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000748[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000748[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000748[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000748[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000748[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000748[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000748[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000748, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800074C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800074C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800074C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800074C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800074C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800074C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800074C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800074C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF800074C[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF800074C, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000750[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000750[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000750[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000750[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000750[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000750[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000750[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000750[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000750[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000750, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000754[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000754[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000754[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000754[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000754[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000754[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000754[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000754[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 1 */
	/* .. ==> 0XF8000754[13:13] = 0x00000001U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00002000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000754, 0x00003FFFU, 0x00002902U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000758[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000758[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000758[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000758[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000758[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000758[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000758[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000758[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000758[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000758, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800075C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800075C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800075C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800075C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800075C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800075C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800075C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800075C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800075C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800075C, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000760[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000760[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000760[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000760[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000760[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000760[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000760[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000760[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000760[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000760, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000764[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000764[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000764[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000764[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000764[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000764[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000764[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000764[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000764[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000764, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000768[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF8000768[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF8000768[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000768[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000768[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000768[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF8000768[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000768[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000768[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000768, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800076C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 1 */
	/* .. ==> 0XF800076C[1:1] = 0x00000001U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000002U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF800076C[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800076C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800076C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800076C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 4 */
	/* .. ==> 0XF800076C[11:9] = 0x00000004U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000800U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800076C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800076C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800076C, 0x00003FFFU, 0x00000903U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000770[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000770[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000770[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000770[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000770[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000770[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000770[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000770[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000770[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000770, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000774[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000774[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000774[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000774[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000774[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000774[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000774[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000774[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000774[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000774, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000778[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000778[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000778[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000778[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000778[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000778[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000778[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000778[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000778[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000778, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF800077C[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800077C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800077C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800077C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800077C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800077C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800077C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800077C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800077C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800077C, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000780[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000780[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000780[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000780[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000780[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000780[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000780[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000780[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000780[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000780, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000784[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000784[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000784[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000784[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000784[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000784[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000784[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000784[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000784[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000784, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000788[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000788[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000788[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000788[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000788[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000788[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000788[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000788[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000788[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000788, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800078C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800078C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800078C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800078C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800078C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800078C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800078C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800078C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800078C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800078C, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF8000790[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000790[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000790[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000790[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000790[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000790[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000790[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000790[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000790[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000790, 0x00003FFFU, 0x00000305U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000794[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000794[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000794[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000794[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000794[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000794[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000794[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000794[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000794[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000794, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF8000798[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF8000798[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF8000798[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF8000798[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF8000798[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF8000798[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF8000798[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF8000798[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF8000798[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000798, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF800079C[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF800079C[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 1 */
	/* .. ==> 0XF800079C[2:2] = 0x00000001U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000004U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF800079C[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF800079C[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 1 */
	/* .. ==> 0XF800079C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF800079C[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF800079C[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF800079C[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF800079C, 0x00003FFFU, 0x00000304U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A0[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A0, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A4[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A4, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007A8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007A8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007A8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007A8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007A8[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007A8[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007A8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007A8[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007A8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007A8, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007AC[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007AC[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007AC[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007AC[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007AC[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007AC[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007AC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007AC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007AC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007AC, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007B0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007B0[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007B0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B0, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007B4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 1 */
	/* .. ==> 0XF80007B4[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007B4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B4, 0x00003FFFU, 0x00000380U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007B8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007B8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007B8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007B8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007B8[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007B8[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007B8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 1 */
	/* .. ==> 0XF80007B8[12:12] = 0x00000001U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00001000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007B8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007B8, 0x00003FFFU, 0x00001200U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF80007BC[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007BC[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007BC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007BC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007BC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007BC, 0x00003F01U, 0x00000201U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007C0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 7 */
	/* .. ==> 0XF80007C0[7:5] = 0x00000007U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x000000E0U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C0[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C0, 0x00003FFFU, 0x000002E0U),
	/* .. TRI_ENABLE = 1 */
	/* .. ==> 0XF80007C4[0:0] = 0x00000001U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000001U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 7 */
	/* .. ==> 0XF80007C4[7:5] = 0x00000007U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x000000E0U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C4[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C4, 0x00003FFFU, 0x000002E1U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007C8[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007C8[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007C8[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007C8[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007C8[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007C8[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007C8[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007C8[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007C8[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007C8, 0x00003FFFU, 0x00000200U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007CC[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007CC[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007CC[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007CC[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 0 */
	/* .. ==> 0XF80007CC[7:5] = 0x00000000U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000000U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007CC[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007CC[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007CC[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007CC[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007CC, 0x00003FFFU, 0x00000200U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007D0[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007D0[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007D0[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007D0[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007D0[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007D0[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007D0[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007D0[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007D0[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007D0, 0x00003FFFU, 0x00000280U),
	/* .. TRI_ENABLE = 0 */
	/* .. ==> 0XF80007D4[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. L0_SEL = 0 */
	/* .. ==> 0XF80007D4[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. L1_SEL = 0 */
	/* .. ==> 0XF80007D4[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. L2_SEL = 0 */
	/* .. ==> 0XF80007D4[4:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000018U    VAL : 0x00000000U */
	/* .. L3_SEL = 4 */
	/* .. ==> 0XF80007D4[7:5] = 0x00000004U */
	/* ..     ==> MASK : 0x000000E0U    VAL : 0x00000080U */
	/* .. Speed = 0 */
	/* .. ==> 0XF80007D4[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. IO_Type = 1 */
	/* .. ==> 0XF80007D4[11:9] = 0x00000001U */
	/* ..     ==> MASK : 0x00000E00U    VAL : 0x00000200U */
	/* .. PULLUP = 0 */
	/* .. ==> 0XF80007D4[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. DisableRcvr = 0 */
	/* .. ==> 0XF80007D4[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF80007D4, 0x00003FFFU, 0x00000280U),
	/* .. SDIO0_WP_SEL = 55 */
	/* .. ==> 0XF8000830[5:0] = 0x00000037U */
	/* ..     ==> MASK : 0x0000003FU    VAL : 0x00000037U */
	/* .. SDIO0_CD_SEL = 47 */
	/* .. ==> 0XF8000830[21:16] = 0x0000002FU */
	/* ..     ==> MASK : 0x003F0000U    VAL : 0x002F0000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000830, 0x003F003FU, 0x002F0037U),
	/* .. FINISH: MIO PROGRAMMING */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_peripherals_init_data_1_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: DDR TERM/IBUF_DISABLE_MODE SETTINGS */
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B48[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B48[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B48, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B4C[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B4C[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B4C, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B50[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B50[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B50, 0x00000180U, 0x00000180U),
	/* .. IBUF_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B54[7:7] = 0x00000001U */
	/* ..     ==> MASK : 0x00000080U    VAL : 0x00000080U */
	/* .. TERM_DISABLE_MODE = 0x1 */
	/* .. ==> 0XF8000B54[8:8] = 0x00000001U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000100U */
	/* .. */
	EMIT_MASKWRITE(0XF8000B54, 0x00000180U, 0x00000180U),
	/* .. FINISH: DDR TERM/IBUF_DISABLE_MODE SETTINGS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* .. START: SRAM/NOR SET OPMODE */
	/* .. FINISH: SRAM/NOR SET OPMODE */
	/* .. START: QSPI REGISTERS */
	/* .. Holdb_dr = 1 */
	/* .. ==> 0XE000D000[19:19] = 0x00000001U */
	/* ..     ==> MASK : 0x00080000U    VAL : 0x00080000U */
	/* .. */
	EMIT_MASKWRITE(0XE000D000, 0x00080000U, 0x00080000U),
	/* .. FINISH: QSPI REGISTERS */
	/* .. START: PL POWER ON RESET REGISTERS */
	/* .. PCFG_POR_CNT_4K = 0 */
	/* .. ==> 0XF8007000[29:29] = 0x00000000U */
	/* ..     ==> MASK : 0x20000000U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8007000, 0x20000000U, 0x00000000U),
	/* .. FINISH: PL POWER ON RESET REGISTERS */
	/* .. START: SMC TIMING CALCULATION REGISTER UPDATE */
	/* .. .. START: NAND SET CYCLE */
	/* .. .. FINISH: NAND SET CYCLE */
	/* .. .. START: OPMODE */
	/* .. .. FINISH: OPMODE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: SRAM/NOR CS0 SET CYCLE */
	/* .. .. FINISH: SRAM/NOR CS0 SET CYCLE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: NOR CS0 BASE ADDRESS */
	/* .. .. FINISH: NOR CS0 BASE ADDRESS */
	/* .. .. START: SRAM/NOR CS1 SET CYCLE */
	/* .. .. FINISH: SRAM/NOR CS1 SET CYCLE */
	/* .. .. START: DIRECT COMMAND */
	/* .. .. FINISH: DIRECT COMMAND */
	/* .. .. START: NOR CS1 BASE ADDRESS */
	/* .. .. FINISH: NOR CS1 BASE ADDRESS */
	/* .. .. START: USB RESET */
	/* .. .. .. START: USB0 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. DIRECTION_1 = 0x4000 */
	/* .. .. .. .. ==> 0XE000A244[21:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x003FFFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A244, 0x003FFFFFU, 0x00004000U),
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x4000 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. OP_ENABLE_1 = 0x4000 */
	/* .. .. .. .. ==> 0XE000A248[21:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x003FFFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A248, 0x003FFFFFU, 0x00004000U),
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x0 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00000000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00000000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF0000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. MASK_1_LSW = 0xbfff */
	/* .. .. .. .. ==> 0XE000A008[31:16] = 0x0000BFFFU */
	/* .. .. .. ..     ==> MASK : 0xFFFF0000U    VAL : 0xBFFF0000U */
	/* .. .. .. .. DATA_1_LSW = 0x4000 */
	/* .. .. .. .. ==> 0XE000A008[15:0] = 0x00004000U */
	/* .. .. .. ..     ==> MASK : 0x0000FFFFU    VAL : 0x00004000U */
	/* .. .. .. .. */
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: USB0 RESET */
	/* .. .. .. START: USB1 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: USB1 RESET */
	/* .. .. FINISH: USB RESET */
	/* .. .. START: ENET RESET */
	/* .. .. .. START: ENET0 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: ENET0 RESET */
	/* .. .. .. START: ENET1 RESET */
	/* .. .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. .. START: DIR MODE BANK 1 */
	/* .. .. .. .. FINISH: DIR MODE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. .. .. START: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. FINISH: OUTPUT ENABLE BANK 1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: ENET1 RESET */
	/* .. .. FINISH: ENET RESET */
	/* .. .. START: I2C RESET */
	/* .. .. .. START: I2C0 RESET */
	/* .. .. .. .. START: DIR MODE GPIO BANK0 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK0 */
	/* .. .. .. .. START: DIR MODE GPIO BANK1 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: I2C0 RESET */
	/* .. .. .. START: I2C1 RESET */
	/* .. .. .. .. START: DIR MODE GPIO BANK0 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK0 */
	/* .. .. .. .. START: DIR MODE GPIO BANK1 */
	/* .. .. .. .. FINISH: DIR MODE GPIO BANK1 */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: OUTPUT ENABLE */
	/* .. .. .. .. FINISH: OUTPUT ENABLE */
	/* .. .. .. .. START: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW LOW BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW LOW BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW LOW BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW LOW BANK [53:48] */
	/* .. .. .. .. START: ADD 1 MS DELAY */
	/* .. .. .. .. */
	EMIT_MASKDELAY(0XF8F00200, 1),
	/* .. .. .. .. FINISH: ADD 1 MS DELAY */
	/* .. .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. .. START: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. FINISH: MASK_DATA_0_MSW HIGH BANK [31:16] */
	/* .. .. .. .. START: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. FINISH: MASK_DATA_1_LSW HIGH BANK [47:32] */
	/* .. .. .. .. START: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. .. FINISH: MASK_DATA_1_MSW HIGH BANK [53:48] */
	/* .. .. .. FINISH: I2C1 RESET */
	/* .. .. FINISH: I2C RESET */
	/* .. .. START: NOR CHIP SELECT */
	/* .. .. .. START: DIR MODE BANK 0 */
	/* .. .. .. FINISH: DIR MODE BANK 0 */
	/* .. .. .. START: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. FINISH: MASK_DATA_0_LSW HIGH BANK [15:0] */
	/* .. .. .. START: OUTPUT ENABLE BANK 0 */
	/* .. .. .. FINISH: OUTPUT ENABLE BANK 0 */
	/* .. .. FINISH: NOR CHIP SELECT */
	/* .. FINISH: SMC TIMING CALCULATION REGISTER UPDATE */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};

unsigned long ps7_post_config_1_0[] = {
	/* START: top */
	/* .. START: SLCR SETTINGS */
	/* .. UNLOCK_KEY = 0XDF0D */
	/* .. ==> 0XF8000008[15:0] = 0x0000DF0DU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000DF0DU */
	/* .. */
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	/* .. FINISH: SLCR SETTINGS */
	/* .. START: ENABLING LEVEL SHIFTER */
	/* .. USER_INP_ICT_EN_0 = 3 */
	/* .. ==> 0XF8000900[1:0] = 0x00000003U */
	/* ..     ==> MASK : 0x00000003U    VAL : 0x00000003U */
	/* .. USER_INP_ICT_EN_1 = 3 */
	/* .. ==> 0XF8000900[3:2] = 0x00000003U */
	/* ..     ==> MASK : 0x0000000CU    VAL : 0x0000000CU */
	/* .. */
	EMIT_MASKWRITE(0XF8000900, 0x0000000FU, 0x0000000FU),
	/* .. FINISH: ENABLING LEVEL SHIFTER */
	/* .. START: FPGA RESETS TO 0 */
	/* .. reserved_3 = 0 */
	/* .. ==> 0XF8000240[31:25] = 0x00000000U */
	/* ..     ==> MASK : 0xFE000000U    VAL : 0x00000000U */
	/* .. FPGA_ACP_RST = 0 */
	/* .. ==> 0XF8000240[24:24] = 0x00000000U */
	/* ..     ==> MASK : 0x01000000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS3_RST = 0 */
	/* .. ==> 0XF8000240[23:23] = 0x00000000U */
	/* ..     ==> MASK : 0x00800000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS2_RST = 0 */
	/* .. ==> 0XF8000240[22:22] = 0x00000000U */
	/* ..     ==> MASK : 0x00400000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS1_RST = 0 */
	/* .. ==> 0XF8000240[21:21] = 0x00000000U */
	/* ..     ==> MASK : 0x00200000U    VAL : 0x00000000U */
	/* .. FPGA_AXDS0_RST = 0 */
	/* .. ==> 0XF8000240[20:20] = 0x00000000U */
	/* ..     ==> MASK : 0x00100000U    VAL : 0x00000000U */
	/* .. reserved_2 = 0 */
	/* .. ==> 0XF8000240[19:18] = 0x00000000U */
	/* ..     ==> MASK : 0x000C0000U    VAL : 0x00000000U */
	/* .. FSSW1_FPGA_RST = 0 */
	/* .. ==> 0XF8000240[17:17] = 0x00000000U */
	/* ..     ==> MASK : 0x00020000U    VAL : 0x00000000U */
	/* .. FSSW0_FPGA_RST = 0 */
	/* .. ==> 0XF8000240[16:16] = 0x00000000U */
	/* ..     ==> MASK : 0x00010000U    VAL : 0x00000000U */
	/* .. reserved_1 = 0 */
	/* .. ==> 0XF8000240[15:14] = 0x00000000U */
	/* ..     ==> MASK : 0x0000C000U    VAL : 0x00000000U */
	/* .. FPGA_FMSW1_RST = 0 */
	/* .. ==> 0XF8000240[13:13] = 0x00000000U */
	/* ..     ==> MASK : 0x00002000U    VAL : 0x00000000U */
	/* .. FPGA_FMSW0_RST = 0 */
	/* .. ==> 0XF8000240[12:12] = 0x00000000U */
	/* ..     ==> MASK : 0x00001000U    VAL : 0x00000000U */
	/* .. FPGA_DMA3_RST = 0 */
	/* .. ==> 0XF8000240[11:11] = 0x00000000U */
	/* ..     ==> MASK : 0x00000800U    VAL : 0x00000000U */
	/* .. FPGA_DMA2_RST = 0 */
	/* .. ==> 0XF8000240[10:10] = 0x00000000U */
	/* ..     ==> MASK : 0x00000400U    VAL : 0x00000000U */
	/* .. FPGA_DMA1_RST = 0 */
	/* .. ==> 0XF8000240[9:9] = 0x00000000U */
	/* ..     ==> MASK : 0x00000200U    VAL : 0x00000000U */
	/* .. FPGA_DMA0_RST = 0 */
	/* .. ==> 0XF8000240[8:8] = 0x00000000U */
	/* ..     ==> MASK : 0x00000100U    VAL : 0x00000000U */
	/* .. reserved = 0 */
	/* .. ==> 0XF8000240[7:4] = 0x00000000U */
	/* ..     ==> MASK : 0x000000F0U    VAL : 0x00000000U */
	/* .. FPGA3_OUT_RST = 0 */
	/* .. ==> 0XF8000240[3:3] = 0x00000000U */
	/* ..     ==> MASK : 0x00000008U    VAL : 0x00000000U */
	/* .. FPGA2_OUT_RST = 0 */
	/* .. ==> 0XF8000240[2:2] = 0x00000000U */
	/* ..     ==> MASK : 0x00000004U    VAL : 0x00000000U */
	/* .. FPGA1_OUT_RST = 0 */
	/* .. ==> 0XF8000240[1:1] = 0x00000000U */
	/* ..     ==> MASK : 0x00000002U    VAL : 0x00000000U */
	/* .. FPGA0_OUT_RST = 0 */
	/* .. ==> 0XF8000240[0:0] = 0x00000000U */
	/* ..     ==> MASK : 0x00000001U    VAL : 0x00000000U */
	/* .. */
	EMIT_MASKWRITE(0XF8000240, 0xFFFFFFFFU, 0x00000000U),
	/* .. FINISH: FPGA RESETS TO 0 */
	/* .. START: AFI REGISTERS */
	/* .. .. START: AFI0 REGISTERS */
	/* .. .. FINISH: AFI0 REGISTERS */
	/* .. .. START: AFI1 REGISTERS */
	/* .. .. FINISH: AFI1 REGISTERS */
	/* .. .. START: AFI2 REGISTERS */
	/* .. .. FINISH: AFI2 REGISTERS */
	/* .. .. START: AFI3 REGISTERS */
	/* .. .. FINISH: AFI3 REGISTERS */
	/* .. FINISH: AFI REGISTERS */
	/* .. START: LOCK IT BACK */
	/* .. LOCK_KEY = 0X767B */
	/* .. ==> 0XF8000004[15:0] = 0x0000767BU */
	/* ..     ==> MASK : 0x0000FFFFU    VAL : 0x0000767BU */
	/* .. */
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	/* .. FINISH: LOCK IT BACK */
	/* FINISH: top */
	/* */
	EMIT_EXIT(),

	/* */
};


#include "xil_io.h"

unsigned long *ps7_mio_init_data = ps7_mio_init_data_3_0;
unsigned long *ps7_pll_init_data = ps7_pll_init_data_3_0;
unsigned long *ps7_clock_init_data = ps7_clock_init_data_3_0;
unsigned long *ps7_ddr_init_data = ps7_ddr_init_data_3_0;
unsigned long *ps7_peripherals_init_data = ps7_peripherals_init_data_3_0;

int ps7_post_config(void)
{
	/* Get the PS_VERSION on run time */
	unsigned long si_ver = ps7GetSiliconVersion();
	int ret = -1;
	if (si_ver == PCW_SILICON_VERSION_1) {
		ret = ps7_config(ps7_post_config_1_0);
		if (ret != PS7_INIT_SUCCESS)
			return ret;
	} else if (si_ver == PCW_SILICON_VERSION_2) {
		ret = ps7_config(ps7_post_config_2_0);
		if (ret != PS7_INIT_SUCCESS)
			return ret;
	} else {
		ret = ps7_config(ps7_post_config_3_0);
		if (ret != PS7_INIT_SUCCESS)
			return ret;
	}
	return PS7_INIT_SUCCESS;
}

int ps7_init(void)
{
	/* Get the PS_VERSION on run time */
	unsigned long si_ver = ps7GetSiliconVersion();
	int ret;
	/*int pcw_ver = 0; */

	if (si_ver == PCW_SILICON_VERSION_1) {
		ps7_mio_init_data = ps7_mio_init_data_1_0;
		ps7_pll_init_data = ps7_pll_init_data_1_0;
		ps7_clock_init_data = ps7_clock_init_data_1_0;
		ps7_ddr_init_data = ps7_ddr_init_data_1_0;
		ps7_peripherals_init_data = ps7_peripherals_init_data_1_0;
		/*pcw_ver = 1; */

	} else if (si_ver == PCW_SILICON_VERSION_2) {
		ps7_mio_init_data = ps7_mio_init_data_2_0;
		ps7_pll_init_data = ps7_pll_init_data_2_0;
		ps7_clock_init_data = ps7_clock_init_data_2_0;
		ps7_ddr_init_data = ps7_ddr_init_data_2_0;
		ps7_peripherals_init_data = ps7_peripherals_init_data_2_0;
		/*pcw_ver = 2; */

	} else {
		ps7_mio_init_data = ps7_mio_init_data_3_0;
		ps7_pll_init_data = ps7_pll_init_data_3_0;
		ps7_clock_init_data = ps7_clock_init_data_3_0;
		ps7_ddr_init_data = ps7_ddr_init_data_3_0;
		ps7_peripherals_init_data = ps7_peripherals_init_data_3_0;
		/*pcw_ver = 3; */
	}

	/* MIO init */
	ret = ps7_config(ps7_mio_init_data);
	if (ret != PS7_INIT_SUCCESS)
		return ret;

	/* PLL init */
	ret = ps7_config(ps7_pll_init_data);
	if (ret != PS7_INIT_SUCCESS)
		return ret;

	/* Clock init */
	ret = ps7_config(ps7_clock_init_data);
	if (ret != PS7_INIT_SUCCESS)
		return ret;

	/* DDR init */
	ret = ps7_config(ps7_ddr_init_data);
	if (ret != PS7_INIT_SUCCESS)
		return ret;

	/* Peripherals init */
	ret = ps7_config(ps7_peripherals_init_data);
	if (ret != PS7_INIT_SUCCESS)
		return ret;
	return PS7_INIT_SUCCESS;
}

