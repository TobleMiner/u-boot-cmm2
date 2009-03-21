/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian.pop@leadtechdesign.com>
 * Lead Tech Design <www.leadtechdesign.com>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_pmc.h>
#include <asm/arch/gpio.h>
#include <asm/arch/io.h>

void at91_spi0_hw_init(unsigned long cs_mask)
{
	at91_set_A_periph(AT91_PIN_PA25, 0);	/* SPI0_MISO */
	at91_set_A_periph(AT91_PIN_PA26, 0);	/* SPI0_MOSI */
	at91_set_A_periph(AT91_PIN_PA27, 0);	/* SPI0_SPCK */

	/* Enable clock */
	at91_sys_write(AT91_PMC_PCER, 1 << AT91SAM9RL_ID_SPI);

	if (cs_mask & (1 << 0)) {
		at91_set_gpio_output(AT91_PIN_PA28, 1);
	}
	if (cs_mask & (1 << 1)) {
		at91_set_gpio_output(AT91_PIN_PB7, 1);
	}
	if (cs_mask & (1 << 2)) {
		at91_set_gpio_output(AT91_PIN_PD8, 1);
	}
	if (cs_mask & (1 << 3)) {
		at91_set_gpio_output(AT91_PIN_PD9, 1);
	}
}
