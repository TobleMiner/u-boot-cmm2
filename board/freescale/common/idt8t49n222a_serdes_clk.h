/*
 * Copyright 2013 Freescale Semiconductor, Inc.
 * Author: Shaveta Leekha <shaveta@freescale.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __IDT8T49N222A_SERDES_CLK_H_
#define __IDT8T49N222A_SERDES_CLK_H_	1

#include <common.h>
#include <i2c.h>
#include "qixis.h"
#include "../b4860qds/b4860qds_qixis.h"
#include <errno.h>

#define NUM_IDT_REGS		23
#define NUM_IDT_REGS_FEEDBACK	12
#define NUM_IDT_REGS_156_25	11

/* CLK */
enum serdes_refclk {
	SERDES_REFCLK_100,	/* refclk 100Mhz */
	SERDES_REFCLK_122_88,	/* refclk 122.88Mhz */
	SERDES_REFCLK_125,	/* refclk 125Mhz */
	SERDES_REFCLK_156_25,	/* refclk 156.25Mhz */
	SERDES_REFCLK_NONE = -1,
};

/* configuration values for IDT registers for Output Refclks:
 * Refclk1 = 122.88MHz Refclk2 = 122.88MHz
 */
static const u8 idt_conf_122_88[23][2] = { {0x00, 0x3C}, {0x01, 0x00},
		{0x02, 0x9F}, {0x03, 0x00}, {0x04, 0x0B}, {0x05, 0x00},
		{0x06, 0x00}, {0x07, 0x00}, {0x08, 0x7D}, {0x09, 0x00},
		{0x0A, 0x08}, {0x0B, 0x00}, {0x0C, 0xDC}, {0x0D, 0x00},
		{0x0E, 0x00}, {0x0F, 0x00}, {0x10, 0x12}, {0x11, 0x12},
		{0x12, 0xB9}, {0x13, 0xBC}, {0x14, 0x40}, {0x15, 0x08},
		{0x16, 0xA0} };


/* configuration values for IDT registers for Output Refclks:
 * Refclk1 not equal to 122.88MHz Refclk2 not equal to 122.88MHz
 */
static const u8 idt_conf_not_122_88[23][2] = { {0x00, 0x00}, {0x01, 0x00},
		{0x02, 0x00}, {0x03, 0x00}, {0x04, 0x0A}, {0x05, 0x00},
		{0x06, 0x00}, {0x07, 0x00}, {0x08, 0x7D}, {0x09, 0x00},
		{0x0A, 0x08}, {0x0B, 0x00}, {0x0C, 0xDC}, {0x0D, 0x00},
		{0x0E, 0x00}, {0x0F, 0x00}, {0x10, 0x14}, {0x11, 0x14},
		{0x12, 0x35}, {0x13, 0xBC}, {0x14, 0x40}, {0x15, 0x08},
		{0x16, 0xA0} };

/* Reconfiguration values for some of IDT registers for
 * Output Refclks:
 * Refclk1 = 122.88MHz Refclk2 = 122.88MHz
 * and with feedback as 1
 */
static const u8 idt_conf_122_88_feedback[12][2] = { {0x00, 0x50}, {0x02, 0xD7},
		{0x04, 0x89}, {0x06, 0xC3}, {0x08, 0xC0}, {0x0A, 0x07},
		{0x0C, 0x80}, {0x10, 0x10}, {0x11, 0x10}, {0x12, 0x1B},
		{0x14, 0x00}, {0x15, 0xE8} };

/* configuration values for IDT registers for Output Refclks:
 * Refclk1 : 156.25MHz Refclk2 : 156.25MHz
 */
static const u8 idt_conf_156_25[11][2] = { {0x04, 0x19}, {0x06, 0x03},
		{0x08, 0xC0}, {0x0A, 0x07}, {0x0C, 0xA1}, {0x0E, 0x20},
		{0x10, 0x10}, {0x11, 0x10}, {0x12, 0xB5}, {0x13, 0x3C},
		{0x15, 0xE8} };

/* configuration values for IDT registers for Output Refclks:
 * Refclk1 : 100MHz Refclk2 : 156.25MHz
 */
static const u8 idt_conf_100_156_25[11][2] = { {0x04, 0x19}, {0x06, 0x03},
		{0x08, 0xC0}, {0x0A, 0x07}, {0x0C, 0xA1}, {0x0E, 0x20},
		{0x10, 0x19}, {0x11, 0x10}, {0x12, 0xB5}, {0x13, 0x3C},
		{0x15, 0xE8} };

/* configuration values for IDT registers for Output Refclks:
 * Refclk1 : 125MHz Refclk2 : 156.25MHz
 */
static const u8 idt_conf_125_156_25[11][2] = { {0x04, 0x19}, {0x06, 0x03},
		{0x08, 0xC0}, {0x0A, 0x07}, {0x0C, 0xA1}, {0x0E, 0x20},
		{0x10, 0x14}, {0x11, 0x10}, {0x12, 0xB5}, {0x13, 0x3C},
		{0x15, 0xE8} };

/* configuration values for IDT registers for Output Refclks:
 * Refclk1 : 156.25MHz Refclk2 : 100MHz
 */
static const u8 idt_conf_156_25_100[11][2] = { {0x04, 0x19}, {0x06, 0x03},
		{0x08, 0xC0}, {0x0A, 0x07}, {0x0C, 0xA1}, {0x0E, 0x20},
		{0x10, 0x10}, {0x11, 0x19}, {0x12, 0xB5}, {0x13, 0x3C},
		{0x15, 0xE8} };

/* configuration values for IDT registers for Output Refclks:
 * Refclk1 : 156.25MHz Refclk2 : 125MHz
 */
static const u8 idt_conf_156_25_125[11][2] = { {0x04, 0x19}, {0x06, 0x03},
		{0x08, 0xC0}, {0x0A, 0x07}, {0x0C, 0xA1}, {0x0E, 0x20},
		{0x10, 0x10}, {0x11, 0x14}, {0x12, 0xB5}, {0x13, 0x3C},
		{0x15, 0xE8} };

int set_serdes_refclk(u8 idt_addr, u8 serdes_num,
			enum serdes_refclk refclk1,
			enum serdes_refclk refclk2, u8 feedback);

#endif	/*__IDT8T49N222A_SERDES_CLK_H_ */
