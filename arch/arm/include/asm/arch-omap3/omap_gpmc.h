/*
 * (C) Copyright 2004-2008 Texas Instruments, <www.ti.com>
 * Rohit Choraria <rohitkc@ti.com>
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
#ifndef __ASM_ARCH_OMAP_GPMC_H
#define __ASM_ARCH_OMAP_GPMC_H

/* GPMC CS configuration for an SMSC LAN9221 ethernet controller */
#define NET_LAN9221_GPMC_CONFIG1    0x00001000
#define NET_LAN9221_GPMC_CONFIG2    0x00060700
#define NET_LAN9221_GPMC_CONFIG3    0x00020201
#define NET_LAN9221_GPMC_CONFIG4    0x06000700
#define NET_LAN9221_GPMC_CONFIG5    0x0006090A
#define NET_LAN9221_GPMC_CONFIG6    0x87030000
#define NET_LAN9221_GPMC_CONFIG7    0x00000f6c

#endif /* __ASM_ARCH_OMAP_GPMC_H */
