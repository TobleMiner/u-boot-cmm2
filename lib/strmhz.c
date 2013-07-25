/*
 * (C) Copyright 2002-2006
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>

char *strmhz (char *buf, unsigned long hz)
{
	long l, n;
	long m;

	n = DIV_ROUND(hz, 1000) / 1000L;
	l = sprintf (buf, "%ld", n);

	hz -= n * 1000000L;
	m = DIV_ROUND(hz, 1000L);
	if (m != 0)
		sprintf (buf + l, ".%03ld", m);
	return (buf);
}
