/*
 * (C) Copyright 2013 Keymile AG
 * Valentin Longchamp <valentin.longchamp@keymile.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>

#include "../common/common.h"
#include "kmp204x.h"

/* QRIO GPIO register offsets */
#define DIRECT_OFF		0x18
#define GPRT_OFF		0x1c

int qrio_get_gpio(u8 port_off, u8 gpio_nr)
{
	u32 gprt;

	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	gprt = in_be32(qrio_base + port_off + GPRT_OFF);

	return (gprt >> gpio_nr) & 1U;
}

void qrio_set_gpio(u8 port_off, u8 gpio_nr, bool value)
{
	u32 gprt, mask;

	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	mask = 1U << gpio_nr;

	gprt = in_be32(qrio_base + port_off + GPRT_OFF);
	if (value)
		gprt |= mask;
	else
		gprt &= ~mask;

	out_be32(qrio_base + port_off + GPRT_OFF, gprt);
}

void qrio_gpio_direction_output(u8 port_off, u8 gpio_nr, bool value)
{
	u32 direct, mask;

	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	mask = 1U << gpio_nr;

	direct = in_be32(qrio_base + port_off + DIRECT_OFF);
	direct |= mask;
	out_be32(qrio_base + port_off + DIRECT_OFF, direct);

	qrio_set_gpio(port_off, gpio_nr, value);
}

void qrio_gpio_direction_input(u8 port_off, u8 gpio_nr)
{
	u32 direct, mask;

	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	mask = 1U << gpio_nr;

	direct = in_be32(qrio_base + port_off + DIRECT_OFF);
	direct &= ~mask;
	out_be32(qrio_base + port_off + DIRECT_OFF, direct);
}

void qrio_set_opendrain_gpio(u8 port_off, u8 gpio_nr, u8 val)
{
	u32 direct, mask;

	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	mask = 1U << gpio_nr;

	direct = in_be32(qrio_base + port_off + DIRECT_OFF);
	if (val == 0)
		/* set to output -> GPIO drives low */
		direct |= mask;
	else
		/* set to input -> GPIO floating */
		direct &= ~mask;

	out_be32(qrio_base + port_off + DIRECT_OFF, direct);
}

#define WDMASK_OFF	0x16

static void qrio_wdmask(u8 bit, bool wden)
{
	u16 wdmask;
	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	wdmask = in_be16(qrio_base + WDMASK_OFF);

	if (wden)
		wdmask |= (1 << bit);
	else
		wdmask &= ~(1 << bit);

	out_be16(qrio_base + WDMASK_OFF, wdmask);
}

#define PRST_OFF	0x1a

void qrio_prst(u8 bit, bool en, bool wden)
{
	u16 prst;
	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	qrio_wdmask(bit, wden);

	prst = in_be16(qrio_base + PRST_OFF);

	if (en)
		prst &= ~(1 << bit);
	else
		prst |= (1 << bit);

	out_be16(qrio_base + PRST_OFF, prst);
}

#define PRSTCFG_OFF	0x1c

void qrio_prstcfg(u8 bit, u8 mode)
{
	u32 prstcfg;
	u8 i;
	void __iomem *qrio_base = (void *)CONFIG_SYS_QRIO_BASE;

	prstcfg = in_be32(qrio_base + PRSTCFG_OFF);

	for (i = 0; i < 2; i++) {
		if (mode & (1<<i))
			set_bit(2*bit+i, &prstcfg);
		else
			clear_bit(2*bit+i, &prstcfg);
	}

	out_be32(qrio_base + PRSTCFG_OFF, prstcfg);
}
