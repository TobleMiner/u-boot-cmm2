/*
 * Based on arch/arm/include/asm/arch-armada100/mfp.h
 * (C) Copyright 2011
 * Marvell Semiconductor <www.marvell.com>
 * Written-by: Lei Wen <leiwen@marvell.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __PANTHEON_MFP_H
#define __PANTHEON_MFP_H

/*
 * Frequently used MFP Configuration macros for all PANTHEON family of SoCs
 *
 * offset, pull,pF, drv,dF, edge,eF ,afn,aF
 */
/* UART2 */
#define MFP47_UART2_RXD		(MFP_REG(0x198) | MFP_AF6 | MFP_DRIVE_MEDIUM)
#define MFP48_UART2_TXD		(MFP_REG(0x19c) | MFP_AF6 | MFP_DRIVE_MEDIUM)
#define MFP53_CI2C_SCL		(MFP_REG(0x1b0) | MFP_AF2 | MFP_DRIVE_MEDIUM)
#define MFP54_CI2C_SDA		(MFP_REG(0x1b4) | MFP_AF2 | MFP_DRIVE_MEDIUM)

/* More macros can be defined here... */
#define MFP_MMC1_DAT7		(MFP_REG(0x84) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MFP_MMC1_DAT6		(MFP_REG(0x88) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MFP_MMC1_DAT5		(MFP_REG(0x8c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MFP_MMC1_DAT4		(MFP_REG(0x90) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MFP_MMC1_DAT3		(MFP_REG(0x94) | MFP_AF0 | MFP_DRIVE_FAST)
#define MFP_MMC1_DAT2		(MFP_REG(0x98) | MFP_AF0 | MFP_DRIVE_FAST)
#define MFP_MMC1_DAT1		(MFP_REG(0x9c) | MFP_AF0 | MFP_DRIVE_FAST)
#define MFP_MMC1_DAT0		(MFP_REG(0xa0) | MFP_AF0 | MFP_DRIVE_FAST)
#define MFP_MMC1_CMD		(MFP_REG(0xa4) | MFP_AF0 | MFP_DRIVE_FAST)
#define MFP_MMC1_CLK		(MFP_REG(0xa8) | MFP_AF0 | MFP_DRIVE_FAST)
#define MFP_MMC1_CD		(MFP_REG(0xac) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MFP_MMC1_WP		(MFP_REG(0xb0) | MFP_AF0 | MFP_DRIVE_MEDIUM)

#define MFP_PIN_MAX	117
#endif
