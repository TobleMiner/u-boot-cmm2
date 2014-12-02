/*
 * arch/arm/include/asm/arch-rmobile/r8a7793.h
 *
 * Copyright (C) 2014 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: GPL-2.0
 */

#ifndef __ASM_ARCH_R8A7793_H
#define __ASM_ARCH_R8A7793_H

#include "rcar-base.h"

/*
 * R8A7793 I/O Addresses
 */

/* SH-I2C */
#define CONFIG_SYS_I2C_SH_BASE2	0xE60B0000

#define DBSC3_1_QOS_R0_BASE	0xE67A1000
#define DBSC3_1_QOS_R1_BASE	0xE67A1100
#define DBSC3_1_QOS_R2_BASE	0xE67A1200
#define DBSC3_1_QOS_R3_BASE	0xE67A1300
#define DBSC3_1_QOS_R4_BASE	0xE67A1400
#define DBSC3_1_QOS_R5_BASE	0xE67A1500
#define DBSC3_1_QOS_R6_BASE	0xE67A1600
#define DBSC3_1_QOS_R7_BASE	0xE67A1700
#define DBSC3_1_QOS_R8_BASE	0xE67A1800
#define DBSC3_1_QOS_R9_BASE	0xE67A1900
#define DBSC3_1_QOS_R10_BASE	0xE67A1A00
#define DBSC3_1_QOS_R11_BASE	0xE67A1B00
#define DBSC3_1_QOS_R12_BASE	0xE67A1C00
#define DBSC3_1_QOS_R13_BASE	0xE67A1D00
#define DBSC3_1_QOS_R14_BASE	0xE67A1E00
#define DBSC3_1_QOS_R15_BASE	0xE67A1F00
#define DBSC3_1_QOS_W0_BASE	0xE67A2000
#define DBSC3_1_QOS_W1_BASE	0xE67A2100
#define DBSC3_1_QOS_W2_BASE	0xE67A2200
#define DBSC3_1_QOS_W3_BASE	0xE67A2300
#define DBSC3_1_QOS_W4_BASE	0xE67A2400
#define DBSC3_1_QOS_W5_BASE	0xE67A2500
#define DBSC3_1_QOS_W6_BASE	0xE67A2600
#define DBSC3_1_QOS_W7_BASE	0xE67A2700
#define DBSC3_1_QOS_W8_BASE	0xE67A2800
#define DBSC3_1_QOS_W9_BASE	0xE67A2900
#define DBSC3_1_QOS_W10_BASE	0xE67A2A00
#define DBSC3_1_QOS_W11_BASE	0xE67A2B00
#define DBSC3_1_QOS_W12_BASE	0xE67A2C00
#define DBSC3_1_QOS_W13_BASE	0xE67A2D00
#define DBSC3_1_QOS_W14_BASE	0xE67A2E00
#define DBSC3_1_QOS_W15_BASE	0xE67A2F00

#define DBSC3_1_DBADJ2		0xE67A00C8

/*
 * R8A7793 I/O Product Information
 */

/* Module stop control/status register bits */
#define MSTP0_BITS	0x00640801
#define MSTP1_BITS	0x9B6C9B5A
#define MSTP2_BITS	0x100D21FC
#define MSTP3_BITS	0xF08CD810
#define MSTP4_BITS	0x800001C4
#define MSTP5_BITS	0x44C00046
#define MSTP7_BITS	0x05BFE618
#define MSTP8_BITS	0x40C0FE85
#define MSTP9_BITS	0xFF979FFF
#define MSTP10_BITS	0xFFFEFFE0
#define MSTP11_BITS	0x000001C0

#define R8A7793_CUT_ES2X	2
#define IS_R8A7793_ES2() \
	(rmobile_get_cpu_rev_integer() == R8A7793_CUT_ES2X)

#endif /* __ASM_ARCH_R8A7793_H */
