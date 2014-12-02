/*
 * arch/arm/include/asm/arch-rmobile/r8a7794.h
 *
 * Copyright (C) 2014 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: GPL-2.0
*/

#ifndef __ASM_ARCH_R8A7794_H
#define __ASM_ARCH_R8A7794_H

#include "rcar-base.h"

/* SH-I2C */
#define CONFIG_SYS_I2C_SH_BASE2	0xE60B0000

/* Module stop control/status register bits */
#define MSTP0_BITS	0x00440801
#define MSTP1_BITS	0x936899DA
#define MSTP2_BITS	0x100D21FC
#define MSTP3_BITS	0xE084D810
#define MSTP4_BITS	0x800001C4
#define MSTP5_BITS	0x40C00044
#define MSTP7_BITS	0x013FE618
#define MSTP8_BITS	0x40803C05
#define MSTP9_BITS	0xFB879FEE
#define MSTP10_BITS	0xFFFEFFE0
#define MSTP11_BITS	0x000001C0

#endif /* __ASM_ARCH_R8A7794_H */
