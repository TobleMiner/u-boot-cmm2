/*
 * Copyright 2006,2009 Freescale Semiconductor, Inc.
 *
 * 2012, Heiko Schocher, DENX Software Engineering, hs@denx.de.
 * Changes for multibus/multiadapter I2C support.
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#include <common.h>
#include <command.h>
#include <i2c.h>		/* Functional interface */
#include <asm/io.h>
#include <asm/fsl_i2c.h>	/* HW definitions */

/* The maximum number of microseconds we will wait until another master has
 * released the bus.  If not defined in the board header file, then use a
 * generic value.
 */
#ifndef CONFIG_I2C_MBB_TIMEOUT
#define CONFIG_I2C_MBB_TIMEOUT	100000
#endif

/* The maximum number of microseconds we will wait for a read or write
 * operation to complete.  If not defined in the board header file, then use a
 * generic value.
 */
#ifndef CONFIG_I2C_TIMEOUT
#define CONFIG_I2C_TIMEOUT	100000
#endif

#define I2C_READ_BIT  1
#define I2C_WRITE_BIT 0

DECLARE_GLOBAL_DATA_PTR;

static const struct fsl_i2c_base *i2c_base[4] = {
	(struct fsl_i2c_base *)(CONFIG_SYS_IMMR + CONFIG_SYS_FSL_I2C_OFFSET),
#ifdef CONFIG_SYS_FSL_I2C2_OFFSET
	(struct fsl_i2c_base *)(CONFIG_SYS_IMMR + CONFIG_SYS_FSL_I2C2_OFFSET),
#endif
#ifdef CONFIG_SYS_FSL_I2C3_OFFSET
	(struct fsl_i2c_base *)(CONFIG_SYS_IMMR + CONFIG_SYS_FSL_I2C3_OFFSET),
#endif
#ifdef CONFIG_SYS_FSL_I2C4_OFFSET
	(struct fsl_i2c_base *)(CONFIG_SYS_IMMR + CONFIG_SYS_FSL_I2C4_OFFSET)
#endif
};

/* I2C speed map for a DFSR value of 1 */

/*
 * Map I2C frequency dividers to FDR and DFSR values
 *
 * This structure is used to define the elements of a table that maps I2C
 * frequency divider (I2C clock rate divided by I2C bus speed) to a value to be
 * programmed into the Frequency Divider Ratio (FDR) and Digital Filter
 * Sampling Rate (DFSR) registers.
 *
 * The actual table should be defined in the board file, and it must be called
 * fsl_i2c_speed_map[].
 *
 * The last entry of the table must have a value of {-1, X}, where X is same
 * FDR/DFSR values as the second-to-last entry.  This guarantees that any
 * search through the array will always find a match.
 *
 * The values of the divider must be in increasing numerical order, i.e.
 * fsl_i2c_speed_map[x+1].divider > fsl_i2c_speed_map[x].divider.
 *
 * For this table, the values are based on a value of 1 for the DFSR
 * register.  See the application note AN2919 "Determining the I2C Frequency
 * Divider Ratio for SCL"
 *
 * ColdFire I2C frequency dividers for FDR values are different from
 * PowerPC. The protocol to use the I2C module is still the same.
 * A different table is defined and are based on MCF5xxx user manual.
 *
 */
static const struct {
	unsigned short divider;
	u8 fdr;
} fsl_i2c_speed_map[] = {
#ifdef __M68K__
	{20, 32}, {22, 33}, {24, 34}, {26, 35},
	{28, 0}, {28, 36}, {30, 1}, {32, 37},
	{34, 2}, {36, 38}, {40, 3}, {40, 39},
	{44, 4}, {48, 5}, {48, 40}, {56, 6},
	{56, 41}, {64, 42}, {68, 7}, {72, 43},
	{80, 8}, {80, 44}, {88, 9}, {96, 41},
	{104, 10}, {112, 42}, {128, 11}, {128, 43},
	{144, 12}, {160, 13}, {160, 48}, {192, 14},
	{192, 49}, {224, 50}, {240, 15}, {256, 51},
	{288, 16}, {320, 17}, {320, 52}, {384, 18},
	{384, 53}, {448, 54}, {480, 19}, {512, 55},
	{576, 20}, {640, 21}, {640, 56}, {768, 22},
	{768, 57}, {960, 23}, {896, 58}, {1024, 59},
	{1152, 24}, {1280, 25}, {1280, 60}, {1536, 26},
	{1536, 61}, {1792, 62}, {1920, 27}, {2048, 63},
	{2304, 28}, {2560, 29}, {3072, 30}, {3840, 31},
	{-1, 31}
#endif
};

/**
 * Set the I2C bus speed for a given I2C device
 *
 * @param base: the I2C device registers
 * @i2c_clk: I2C bus clock frequency
 * @speed: the desired speed of the bus
 *
 * The I2C device must be stopped before calling this function.
 *
 * The return value is the actual bus speed that is set.
 */
static unsigned int set_i2c_bus_speed(const struct fsl_i2c_base *base,
	unsigned int i2c_clk, unsigned int speed)
{
	unsigned short divider = min(i2c_clk / speed, (unsigned int)USHRT_MAX);

	/*
	 * We want to choose an FDR/DFSR that generates an I2C bus speed that
	 * is equal to or lower than the requested speed.  That means that we
	 * want the first divider that is equal to or greater than the
	 * calculated divider.
	 */
#ifdef __PPC__
	u8 dfsr, fdr = 0x31; /* Default if no FDR found */
	/* a, b and dfsr matches identifiers A,B and C respectively in AN2919 */
	unsigned short a, b, ga, gb;
	unsigned long c_div, est_div;

#ifdef CONFIG_FSL_I2C_CUSTOM_DFSR
	dfsr = CONFIG_FSL_I2C_CUSTOM_DFSR;
#else
	/* Condition 1: dfsr <= 50/T */
	dfsr = (5 * (i2c_clk / 1000)) / 100000;
#endif
#ifdef CONFIG_FSL_I2C_CUSTOM_FDR
	fdr = CONFIG_FSL_I2C_CUSTOM_FDR;
	speed = i2c_clk / divider; /* Fake something */
#else
	debug("Requested speed:%d, i2c_clk:%d\n", speed, i2c_clk);
	if (!dfsr)
		dfsr = 1;

	est_div = ~0;
	for (ga = 0x4, a = 10; a <= 30; ga++, a += 2) {
		for (gb = 0; gb < 8; gb++) {
			b = 16 << gb;
			c_div = b * (a + ((3*dfsr)/b)*2);
			if ((c_div > divider) && (c_div < est_div)) {
				unsigned short bin_gb, bin_ga;

				est_div = c_div;
				bin_gb = gb << 2;
				bin_ga = (ga & 0x3) | ((ga & 0x4) << 3);
				fdr = bin_gb | bin_ga;
				speed = i2c_clk / est_div;
				debug("FDR:0x%.2x, div:%ld, ga:0x%x, gb:0x%x, "
				      "a:%d, b:%d, speed:%d\n",
				      fdr, est_div, ga, gb, a, b, speed);
				/* Condition 2 not accounted for */
				debug("Tr <= %d ns\n",
				      (b - 3 * dfsr) * 1000000 /
				      (i2c_clk / 1000));
			}
		}
		if (a == 20)
			a += 2;
		if (a == 24)
			a += 4;
	}
	debug("divider:%d, est_div:%ld, DFSR:%d\n", divider, est_div, dfsr);
	debug("FDR:0x%.2x, speed:%d\n", fdr, speed);
#endif
	writeb(dfsr, &base->dfsrr);	/* set default filter */
	writeb(fdr, &base->fdr);	/* set bus speed */
#else
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(fsl_i2c_speed_map); i++)
		if (fsl_i2c_speed_map[i].divider >= divider) {
			u8 fdr;

			fdr = fsl_i2c_speed_map[i].fdr;
			speed = i2c_clk / fsl_i2c_speed_map[i].divider;
			writeb(fdr, &base->fdr);	/* set bus speed */

			break;
		}
#endif
	return speed;
}

static unsigned int get_i2c_clock(int bus)
{
	if (bus)
		return gd->arch.i2c2_clk;	/* I2C2 clock */
	else
		return gd->arch.i2c1_clk;	/* I2C1 clock */
}

static int fsl_i2c_fixup(const struct fsl_i2c_base *base)
{
	const unsigned long long timeout = usec2ticks(CONFIG_I2C_MBB_TIMEOUT);
	unsigned long long timeval = 0;
	int ret = -1;
	unsigned int flags = 0;

#ifdef CONFIG_SYS_FSL_ERRATUM_I2C_A004447
	unsigned int svr = get_svr();
	if ((SVR_SOC_VER(svr) == SVR_8548 && IS_SVR_REV(svr, 3, 1)) ||
	    (SVR_REV(svr) <= CONFIG_SYS_FSL_A004447_SVR_REV))
		flags = I2C_CR_BIT6;
#endif

	writeb(I2C_CR_MEN | I2C_CR_MSTA, &base->cr);

	timeval = get_ticks();
	while (!(readb(&base->sr) & I2C_SR_MBB)) {
		if ((get_ticks() - timeval) > timeout)
			goto err;
	}

	if (readb(&base->sr) & I2C_SR_MAL) {
		/* SDA is stuck low */
		writeb(0, &base->cr);
		udelay(100);
		writeb(I2C_CR_MSTA | flags, &base->cr);
		writeb(I2C_CR_MEN | I2C_CR_MSTA | flags, &base->cr);
	}

	readb(&base->dr);

	timeval = get_ticks();
	while (!(readb(&base->sr) & I2C_SR_MIF)) {
		if ((get_ticks() - timeval) > timeout)
			goto err;
	}
	ret = 0;

err:
	writeb(I2C_CR_MEN | flags, &base->cr);
	writeb(0, &base->sr);
	udelay(100);

	return ret;
}

static void fsl_i2c_init(struct i2c_adapter *adap, int speed, int slaveadd)
{
	const struct fsl_i2c_base *base;
	const unsigned long long timeout = usec2ticks(CONFIG_I2C_MBB_TIMEOUT);
	unsigned long long timeval;

#ifdef CONFIG_SYS_I2C_INIT_BOARD
	/* Call board specific i2c bus reset routine before accessing the
	 * environment, which might be in a chip on that bus. For details
	 * about this problem see doc/I2C_Edge_Conditions.
	*/
	i2c_init_board();
#endif
	base = (struct fsl_i2c_base *)i2c_base[adap->hwadapnr];

	writeb(0, &base->cr);		/* stop I2C controller */
	udelay(5);			/* let it shutdown in peace */
	set_i2c_bus_speed(base, get_i2c_clock(adap->hwadapnr), speed);
	writeb(slaveadd << 1, &base->adr);/* write slave address */
	writeb(0x0, &base->sr);		/* clear status register */
	writeb(I2C_CR_MEN, &base->cr);	/* start I2C controller */

	timeval = get_ticks();
	while (readb(&base->sr) & I2C_SR_MBB) {
		if ((get_ticks() - timeval) < timeout)
			continue;

		if (fsl_i2c_fixup(base))
			debug("i2c_init: BUS#%d failed to init\n",
			      adap->hwadapnr);

		break;
	}

#ifdef CONFIG_SYS_I2C_BOARD_LATE_INIT
	/* Call board specific i2c bus reset routine AFTER the bus has been
	 * initialized. Use either this callpoint or i2c_init_board;
	 * which is called before i2c_init operations.
	 * For details about this problem see doc/I2C_Edge_Conditions.
	*/
	i2c_board_late_init();
#endif
}

static int
i2c_wait4bus(struct i2c_adapter *adap)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];
	unsigned long long timeval = get_ticks();
	const unsigned long long timeout = usec2ticks(CONFIG_I2C_MBB_TIMEOUT);

	while (readb(&base->sr) & I2C_SR_MBB) {
		if ((get_ticks() - timeval) > timeout)
			return -1;
	}

	return 0;
}

static __inline__ int
i2c_wait(struct i2c_adapter *adap, int write)
{
	u32 csr;
	unsigned long long timeval = get_ticks();
	const unsigned long long timeout = usec2ticks(CONFIG_I2C_TIMEOUT);
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];

	do {
		csr = readb(&base->sr);
		if (!(csr & I2C_SR_MIF))
			continue;
		/* Read again to allow register to stabilise */
		csr = readb(&base->sr);

		writeb(0x0, &base->sr);

		if (csr & I2C_SR_MAL) {
			debug("i2c_wait: MAL\n");
			return -1;
		}

		if (!(csr & I2C_SR_MCF))	{
			debug("i2c_wait: unfinished\n");
			return -1;
		}

		if (write == I2C_WRITE_BIT && (csr & I2C_SR_RXAK)) {
			debug("i2c_wait: No RXACK\n");
			return -1;
		}

		return 0;
	} while ((get_ticks() - timeval) < timeout);

	debug("i2c_wait: timed out\n");
	return -1;
}

static __inline__ int
i2c_write_addr(struct i2c_adapter *adap, u8 dev, u8 dir, int rsta)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];

	writeb(I2C_CR_MEN | I2C_CR_MSTA | I2C_CR_MTX
	       | (rsta ? I2C_CR_RSTA : 0),
	       &base->cr);

	writeb((dev << 1) | dir, &base->dr);

	if (i2c_wait(adap, I2C_WRITE_BIT) < 0)
		return 0;

	return 1;
}

static __inline__ int
__i2c_write(struct i2c_adapter *adap, u8 *data, int length)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];
	int i;

	for (i = 0; i < length; i++) {
		writeb(data[i], &base->dr);

		if (i2c_wait(adap, I2C_WRITE_BIT) < 0)
			break;
	}

	return i;
}

static __inline__ int
__i2c_read(struct i2c_adapter *adap, u8 *data, int length)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];
	int i;

	writeb(I2C_CR_MEN | I2C_CR_MSTA | ((length == 1) ? I2C_CR_TXAK : 0),
	       &base->cr);

	/* dummy read */
	readb(&base->dr);

	for (i = 0; i < length; i++) {
		if (i2c_wait(adap, I2C_READ_BIT) < 0)
			break;

		/* Generate ack on last next to last byte */
		if (i == length - 2)
			writeb(I2C_CR_MEN | I2C_CR_MSTA | I2C_CR_TXAK,
			       &base->cr);

		/* Do not generate stop on last byte */
		if (i == length - 1)
			writeb(I2C_CR_MEN | I2C_CR_MSTA | I2C_CR_MTX,
			       &base->cr);

		data[i] = readb(&base->dr);
	}

	return i;
}

static int
fsl_i2c_read(struct i2c_adapter *adap, u8 chip_addr, uint offset, int olen,
	     u8 *data, int dlen)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];
	int ret = -1; /* signal error */
	u8 *o = (u8 *)&offset;

	if (i2c_wait4bus(adap) < 0)
		return -1;

	/* Some drivers use offset lengths in excess of 4 bytes. These drivers
	 * adhere to the following convention:
	 * - the offset length is passed as negative (that is, the absolute
	 *   value of olen is the actual offset length)
	 * - the offset itself is passed in data, which is overwritten by the
	 *   subsequent read operation
	 */
	if (olen < 0) {
		if (i2c_write_addr(adap, chip_addr, I2C_WRITE_BIT, 0) != 0)
			ret = __i2c_write(adap, data, -olen);

		if (ret != -olen)
			return -1;

		if (dlen && i2c_write_addr(adap, chip_addr,
					   I2C_READ_BIT, 1) != 0)
			ret = __i2c_read(adap, data, dlen);
	} else {
		if ((!dlen || olen > 0) &&
		    i2c_write_addr(adap, chip_addr, I2C_WRITE_BIT, 0) != 0  &&
		    __i2c_write(adap, &o[4 - olen], olen) == olen)
			ret = 0; /* No error so far */

		if (dlen && i2c_write_addr(adap, chip_addr, I2C_READ_BIT,
					   olen ? 1 : 0) != 0)
			ret = __i2c_read(adap, data, dlen);
	}

	writeb(I2C_CR_MEN, &base->cr);

	if (i2c_wait4bus(adap)) /* Wait until STOP */
		debug("i2c_read: wait4bus timed out\n");

	if (ret == dlen)
		return 0;

	return -1;
}

static int
fsl_i2c_write(struct i2c_adapter *adap, u8 chip_addr, uint offset, int olen,
	      u8 *data, int dlen)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];
	int ret = -1; /* signal error */
	u8 *o = (u8 *)&offset;

	if (i2c_wait4bus(adap) < 0)
		return -1;

	if (i2c_write_addr(adap, chip_addr, I2C_WRITE_BIT, 0) != 0 &&
	    __i2c_write(adap, &o[4 - olen], olen) == olen) {
		ret = __i2c_write(adap, data, dlen);
	}

	writeb(I2C_CR_MEN, &base->cr);
	if (i2c_wait4bus(adap)) /* Wait until STOP */
		debug("i2c_write: wait4bus timed out\n");

	if (ret == dlen)
		return 0;

	return -1;
}

static int
fsl_i2c_probe_chip(struct i2c_adapter *adap, uchar chip)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];
	/* For unknow reason the controller will ACK when
	 * probing for a slave with the same address, so skip
	 * it.
	 */
	if (chip == (readb(&base->adr) >> 1))
		return -1;

	return fsl_i2c_read(adap, chip, 0, 0, NULL, 0);
}

static unsigned int fsl_i2c_set_bus_speed(struct i2c_adapter *adap,
			unsigned int speed)
{
	struct fsl_i2c_base *base =
		(struct fsl_i2c_base *)i2c_base[adap->hwadapnr];

	writeb(0, &base->cr);		/* stop controller */
	set_i2c_bus_speed(base, get_i2c_clock(adap->hwadapnr), speed);
	writeb(I2C_CR_MEN, &base->cr);	/* start controller */

	return 0;
}

/*
 * Register fsl i2c adapters
 */
U_BOOT_I2C_ADAP_COMPLETE(fsl_0, fsl_i2c_init, fsl_i2c_probe_chip, fsl_i2c_read,
			 fsl_i2c_write, fsl_i2c_set_bus_speed,
			 CONFIG_SYS_FSL_I2C_SPEED, CONFIG_SYS_FSL_I2C_SLAVE,
			 0)
#ifdef CONFIG_SYS_FSL_I2C2_OFFSET
U_BOOT_I2C_ADAP_COMPLETE(fsl_1, fsl_i2c_init, fsl_i2c_probe_chip, fsl_i2c_read,
			 fsl_i2c_write, fsl_i2c_set_bus_speed,
			 CONFIG_SYS_FSL_I2C2_SPEED, CONFIG_SYS_FSL_I2C2_SLAVE,
			 1)
#endif
#ifdef CONFIG_SYS_FSL_I2C3_OFFSET
U_BOOT_I2C_ADAP_COMPLETE(fsl_2, fsl_i2c_init, fsl_i2c_probe_chip, fsl_i2c_read,
			 fsl_i2c_write, fsl_i2c_set_bus_speed,
			 CONFIG_SYS_FSL_I2C3_SPEED, CONFIG_SYS_FSL_I2C3_SLAVE,
			 2)
#endif
#ifdef CONFIG_SYS_FSL_I2C4_OFFSET
U_BOOT_I2C_ADAP_COMPLETE(fsl_3, fsl_i2c_init, fsl_i2c_probe_chip, fsl_i2c_read,
			 fsl_i2c_write, fsl_i2c_set_bus_speed,
			 CONFIG_SYS_FSL_I2C4_SPEED, CONFIG_SYS_FSL_I2C4_SLAVE,
			 3)
#endif
