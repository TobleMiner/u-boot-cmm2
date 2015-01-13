/*
 * Copyright (c) 2014 Google, Inc
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>

static int cur_busnum;

static int i2c_compat_get_device(uint chip_addr, int alen,
				 struct udevice **devp)
{
	struct dm_i2c_chip *chip;
	int ret;

	ret = i2c_get_chip_for_busnum(cur_busnum, chip_addr, devp);
	if (ret)
		return ret;
	chip = dev_get_parentdata(*devp);
	if (chip->offset_len != alen) {
		printf("Requested alen %d does not match chip offset_len %d\n",
		       alen, chip->offset_len);
		return -EADDRNOTAVAIL;
	}

	return 0;
}

int i2c_probe(uint8_t chip_addr)
{
	struct udevice *bus, *dev;
	int ret;

	ret = uclass_get_device_by_seq(UCLASS_I2C, cur_busnum, &bus);
	if (ret) {
		debug("Cannot find I2C bus %d: err=%d\n", cur_busnum, ret);
		return ret;
	}

	if (!bus)
		return -ENOENT;

	return dm_i2c_probe(bus, chip_addr, 0, &dev);
}

int i2c_read(uint8_t chip_addr, unsigned int addr, int alen, uint8_t *buffer,
	     int len)
{
	struct udevice *dev;
	int ret;

	ret = i2c_compat_get_device(chip_addr, alen, &dev);
	if (ret)
		return ret;

	return dm_i2c_read(dev, addr, buffer, len);
}

int i2c_write(uint8_t chip_addr, unsigned int addr, int alen, uint8_t *buffer,
	      int len)
{
	struct udevice *dev;
	int ret;

	ret = i2c_compat_get_device(chip_addr, alen, &dev);
	if (ret)
		return ret;

	return dm_i2c_write(dev, addr, buffer, len);
}

int i2c_get_bus_num_fdt(int node)
{
	struct udevice *bus;
	int ret;

	ret = uclass_get_device_by_of_offset(UCLASS_I2C, node, &bus);
	if (ret)
		return ret;

	return bus->seq;
}

unsigned int i2c_get_bus_num(void)
{
	return cur_busnum;
}

int i2c_set_bus_num(unsigned int bus)
{
	cur_busnum = bus;

	return 0;
}
