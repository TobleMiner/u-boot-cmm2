/*
 * ET1011C PHY driver
 *
 * Derived from Linux kernel driver by Chaithrika U S
 * Copyright (C) 2013, Texas Instruments, Incorporated - http://www.ti.com/
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
 */
#include <config.h>
#include <phy.h>

#define ET1011C_CONFIG_REG		(0x16)
#define ET1011C_TX_FIFO_MASK		(0x3 << 12)
#define ET1011C_TX_FIFO_DEPTH_8		(0x0 << 12)
#define ET1011C_TX_FIFO_DEPTH_16	(0x1 << 12)
#define ET1011C_INTERFACE_MASK		(0x7 << 0)
#define ET1011C_GMII_INTERFACE		(0x2 << 0)
#define ET1011C_SYS_CLK_EN		(0x1 << 4)
#define ET1011C_TX_CLK_EN		(0x1 << 5)

#define ET1011C_STATUS_REG		(0x1A)
#define ET1011C_DUPLEX_STATUS		(0x1 << 7)
#define ET1011C_SPEED_MASK		(0x3 << 8)
#define ET1011C_SPEED_1000		(0x2 << 8)
#define ET1011C_SPEED_100		(0x1 << 8)
#define ET1011C_SPEED_10		(0x0 << 8)

static int et1011c_config(struct phy_device *phydev)
{
	int ctl = 0;
	ctl = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMCR);
	if (ctl < 0)
		return ctl;
	ctl &= ~(BMCR_FULLDPLX | BMCR_SPEED100 | BMCR_SPEED1000 |
		 BMCR_ANENABLE);
	/* First clear the PHY */
	phy_write(phydev, MDIO_DEVAD_NONE, MII_BMCR, ctl | BMCR_RESET);

	return genphy_config_aneg(phydev);
}

static int et1011c_parse_status(struct phy_device *phydev)
{
	int mii_reg;
	int speed;

	mii_reg = phy_read(phydev, MDIO_DEVAD_NONE, ET1011C_STATUS_REG);

	if (mii_reg & ET1011C_DUPLEX_STATUS)
		phydev->duplex = DUPLEX_FULL;
	else
		phydev->duplex = DUPLEX_HALF;

	speed = mii_reg & ET1011C_SPEED_MASK;
	switch (speed) {
	case ET1011C_SPEED_1000:
		phydev->speed = SPEED_1000;
		mii_reg = phy_read(phydev, MDIO_DEVAD_NONE, ET1011C_CONFIG_REG);
		mii_reg &= ~ET1011C_TX_FIFO_MASK;
		phy_write(phydev, MDIO_DEVAD_NONE, ET1011C_CONFIG_REG,
			  mii_reg |
			  ET1011C_GMII_INTERFACE |
			  ET1011C_SYS_CLK_EN |
#ifdef CONFIG_PHY_ET1011C_TX_CLK_FIX
			  ET1011C_TX_CLK_EN |
#endif
			  ET1011C_TX_FIFO_DEPTH_16);
		break;
	case ET1011C_SPEED_100:
		phydev->speed = SPEED_100;
		break;
	case ET1011C_SPEED_10:
		phydev->speed = SPEED_10;
		break;
	}

	return 0;
}

static int et1011c_startup(struct phy_device *phydev)
{
	genphy_update_link(phydev);
	et1011c_parse_status(phydev);
	return 0;
}

static struct phy_driver et1011c_driver = {
	.name		= "ET1011C",
	.uid		= 0x0282f014,
	.mask		= 0xfffffff0,
	.features	= PHY_GBIT_FEATURES,
	.config		= &et1011c_config,
	.startup	= &et1011c_startup,
};

int phy_et1011c_init(void)
{
	phy_register(&et1011c_driver);

	return 0;
}
