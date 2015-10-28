/*
 * (C) Copyright 2012
 * Dirk Eibach,  Guntermann & Drunck GmbH, dirk.eibach@gdsys.cc
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/* Parade Technologies Inc. DP501 DisplayPort DVI/HDMI Transmitter */

#include <common.h>
#include <asm/io.h>
#include <errno.h>
#include <i2c.h>

static void dp501_setbits(u8 addr, u8 reg, u8 mask)
{
	u8 val;

	val = i2c_reg_read(addr, reg);
	setbits_8(&val, mask);
	i2c_reg_write(addr, reg, val);
}

static void dp501_clrbits(u8 addr, u8 reg, u8 mask)
{
	u8 val;

	val = i2c_reg_read(addr, reg);
	clrbits_8(&val, mask);
	i2c_reg_write(addr, reg, val);
}

static int dp501_detect_cable_adapter(u8 addr)
{
	u8 val = i2c_reg_read(addr, 0x00);

	return !(val & 0x04);
}

static void dp501_link_training(u8 addr)
{
	u8 val;

	val = i2c_reg_read(addr, 0x51);
	i2c_reg_write(addr, 0x5d, val); /* set link_bw */
	val = i2c_reg_read(addr, 0x52);
	i2c_reg_write(addr, 0x5e, val); /* set lane_cnt */
	val = i2c_reg_read(addr, 0x53);
	i2c_reg_write(addr, 0x5c, val); /* set downspread_ctl */

	i2c_reg_write(addr, 0x5f, 0x0d); /* start training */
}

void dp501_powerup(u8 addr)
{
	dp501_clrbits(addr, 0x0a, 0x30); /* power on encoder */
	dp501_setbits(addr, 0x0a, 0x0e); /* block HDCP and MCCS on I2C bride*/
	i2c_reg_write(addr, 0x27, 0x30); /* Hardware auto detect DVO timing */
	dp501_setbits(addr, 0x72, 0x80); /* DPCD read enable */
	dp501_setbits(addr, 0x30, 0x20); /* RS polynomial select */
	i2c_reg_write(addr, 0x71, 0x20); /* Enable Aux burst write */
	dp501_setbits(addr, 0x78, 0x30); /* Disable HPD2 IRQ */
	dp501_clrbits(addr, 0x2f, 0x40); /* Link FIFO reset selection */
	dp501_clrbits(addr, 0x60, 0x20); /* Enable scrambling */

#ifdef CONFIG_SYS_DP501_VCAPCTRL0
	i2c_reg_write(addr, 0x24, CONFIG_SYS_DP501_VCAPCTRL0);
#else
	i2c_reg_write(addr, 0x24, 0xc0); /* SDR mode 0, ext. H/VSYNC */
#endif

#ifdef CONFIG_SYS_DP501_DIFFERENTIAL
	i2c_reg_write(addr + 2, 0x24, 0x10); /* clock input differential */
	i2c_reg_write(addr + 2, 0x25, 0x04);
	i2c_reg_write(addr + 2, 0x26, 0x10);
#else
	i2c_reg_write(addr + 2, 0x24, 0x02); /* clock input single ended */
#endif

	i2c_reg_write(addr + 2, 0x1a, 0x04); /* SPDIF input method TTL */

	i2c_reg_write(addr + 2, 0x00, 0x18); /* driving strength */
	i2c_reg_write(addr + 2, 0x03, 0x06); /* driving strength */
	i2c_reg_write(addr, 0x2c, 0x00); /* configure N value */
	i2c_reg_write(addr, 0x2d, 0x00); /* configure N value */
	i2c_reg_write(addr, 0x2e, 0x0c); /* configure N value */
	i2c_reg_write(addr, 0x76, 0xff); /* clear all interrupt */
	dp501_setbits(addr, 0x78, 0x03); /* clear all interrupt */
	i2c_reg_write(addr, 0x75, 0xf8); /* aux channel reset */
	i2c_reg_write(addr, 0x75, 0x00); /* clear aux channel reset */
	i2c_reg_write(addr, 0x87, 0x70); /* set retry counter as 7 */

	if (dp501_detect_cable_adapter(addr)) {
		printf("DVI/HDMI cable adapter detected\n");
		i2c_reg_write(addr, 0x5e, 0x04); /* enable 4 channel */
		dp501_clrbits(addr, 0x00, 0x08); /* DVI/HDMI HDCP operation */
	} else {
		printf("no DVI/HDMI cable adapter detected\n");
		dp501_setbits(addr, 0x00, 0x08); /* for DP HDCP operation */

		dp501_link_training(addr);
	}
}

void dp501_powerdown(u8 addr)
{
	dp501_setbits(addr, 0x0a, 0x30); /* power down encoder, standby mode */
}
