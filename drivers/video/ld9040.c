/*
 * ld9040 AMOLED LCD panel driver.
 *
 * Copyright (C) 2012 Samsung Electronics
 * Donghwa Lee <dh09.lee@samsung.com>
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

#include <common.h>
#include <spi.h>

static const unsigned char SEQ_SWRESET[] = {
	0x01,
};

static const unsigned char SEQ_USER_SETTING[] = {
	0xF0, 0x5A, 0x5A
};

static const unsigned char SEQ_ELVSS_ON[] = {
	0xB1, 0x0D, 0x00, 0x16,
};

static const unsigned char SEQ_TEMP_SWIRE[] = {
	0xB2, 0x06, 0x06, 0x06, 0x06,
};

static const unsigned char SEQ_GTCON[] = {
	0xF7, 0x09, 0x00, 0x00,
};

static const unsigned char SEQ_PANEL_CONDITION[] = {
	0xF8, 0x05, 0x65, 0x96, 0x71, 0x7D, 0x19, 0x3B,
	0x0D, 0x19, 0x7E, 0x0D, 0xE2, 0x00, 0x00, 0x7E,
	0x7D, 0x07, 0x07, 0x20, 0x20, 0x20, 0x02, 0x02,
};

static const unsigned char SEQ_GAMMA_SET1[] = {
	0xF9, 0x00, 0xA7, 0xB4, 0xAE, 0xBF, 0x00, 0x91,
	0x00, 0xB2, 0xB4, 0xAA, 0xBB, 0x00, 0xAC, 0x00,
	0xB3, 0xB1, 0xAA, 0xBC, 0x00, 0xB3,
};

static const unsigned char SEQ_GAMMA_CTRL[] = {
	0xFB, 0x02, 0x5A,
};

static const unsigned char SEQ_APON[] = {
	0xF3, 0x00, 0x00, 0x00, 0x0A, 0x02,
};

static const unsigned char SEQ_DISPCTL[] = {
	0xF2, 0x02, 0x08, 0x08, 0x10, 0x10,
};

static const unsigned char SEQ_MANPWR[] = {
	0xB0, 0x04,
};

static const unsigned char SEQ_PWR_CTRL[] = {
	0xF4, 0x0A, 0x87, 0x25, 0x6A, 0x44, 0x02, 0x88,
};

static const unsigned char SEQ_SLPOUT[] = {
	0x11,
};

static const unsigned char SEQ_SLPIN[] = {
	0x10,
};

static const unsigned char SEQ_DISPON[] = {
	0x29,
};

static const unsigned char SEQ_DISPOFF[] = {
	0x28,
};

static void ld9040_spi_write(const unsigned char *wbuf, unsigned int size_cmd)
{
	int i = 0;

	/*
	 * Data are transmitted in 9-bit words:
	 * the first bit is command/parameter, the other are the value.
	 * The value's LSB is shifted to MSB position, to be sent as 9th bit
	 */

	unsigned int data_out = 0, data_in = 0;
	for (i = 0; i < size_cmd; i++) {
		data_out = wbuf[i] >> 1;
		if (i != 0)
			data_out += 0x0080;
		if (wbuf[i] & 0x01)
			data_out += 0x8000;
		spi_xfer(NULL, 9, &data_out, &data_in, SPI_XFER_BEGIN);
	}
}

void ld9040_cfg_ldo(void)
{
	udelay(10);

	ld9040_spi_write(SEQ_USER_SETTING,
					ARRAY_SIZE(SEQ_USER_SETTING));
	ld9040_spi_write(SEQ_PANEL_CONDITION,
					ARRAY_SIZE(SEQ_PANEL_CONDITION));
	ld9040_spi_write(SEQ_DISPCTL, ARRAY_SIZE(SEQ_DISPCTL));
	ld9040_spi_write(SEQ_MANPWR, ARRAY_SIZE(SEQ_MANPWR));
	ld9040_spi_write(SEQ_PWR_CTRL, ARRAY_SIZE(SEQ_PWR_CTRL));
	ld9040_spi_write(SEQ_ELVSS_ON, ARRAY_SIZE(SEQ_ELVSS_ON));
	ld9040_spi_write(SEQ_GTCON, ARRAY_SIZE(SEQ_GTCON));
	ld9040_spi_write(SEQ_GAMMA_SET1, ARRAY_SIZE(SEQ_GAMMA_SET1));
	ld9040_spi_write(SEQ_GAMMA_CTRL, ARRAY_SIZE(SEQ_GAMMA_CTRL));
	ld9040_spi_write(SEQ_SLPOUT, ARRAY_SIZE(SEQ_SLPOUT));

	udelay(120);
}

void ld9040_enable_ldo(unsigned int onoff)
{
	if (onoff)
		ld9040_spi_write(SEQ_DISPON, ARRAY_SIZE(SEQ_DISPON));
	else
		ld9040_spi_write(SEQ_DISPOFF, ARRAY_SIZE(SEQ_DISPOFF));
}
