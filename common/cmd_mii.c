/*
 * (C) Copyright 2001
 * Gerald Van Baren, Custom IDEAS, vanbaren@cideas.com
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

/*
 * MII Utilities
 */

#include <common.h>
#include <command.h>

#if (CONFIG_COMMANDS & CFG_CMD_MII)
#include <miiphy.h>

#define	CONFIG_TERSE_MII	/* XXX necessary here because "miivals.h" is missing */

#ifdef CONFIG_TERSE_MII
/*
 * Display values from last command.
 */
uint last_op;
uint last_addr;
uint last_data;
uint last_reg;

/*
 * MII read/write
 *
 * Syntax:
 *  mii read {addr} {reg}
 *  mii write {addr} {reg} {data}
 */

int do_mii (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char		op;
	unsigned char	addr, reg;
	unsigned short	data;
	int		rcode = 0;

#if defined(CONFIG_8xx) || defined(CONFIG_MCF52x2)
	mii_init ();
#endif

	/*
	 * We use the last specified parameters, unless new ones are
	 * entered.
	 */
	op   = last_op;
	addr = last_addr;
	data = last_data;
	reg  = last_reg;

	if ((flag & CMD_FLAG_REPEAT) == 0) {
		op = argv[1][0];
		if (argc >= 3)
			addr = simple_strtoul (argv[2], NULL, 16);
		if (argc >= 4)
			reg  = simple_strtoul (argv[3], NULL, 16);
		if (argc >= 5)
			data = simple_strtoul (argv[4], NULL, 16);
	}

	/*
	 * check info/read/write.
	 */
	if (op == 'i') {
		unsigned char j, start, end;
		unsigned int oui;
		unsigned char model;
		unsigned char rev;

		/*
		 * Look for any and all PHYs.  Valid addresses are 0..31.
		 */
		if (argc >= 3) {
			start = addr; end = addr + 1;
		} else {
			start = 0; end = 32;
		}

		for (j = start; j < end; j++) {
			if (miiphy_info (j, &oui, &model, &rev) == 0) {
				printf ("PHY 0x%02X: "
					"OUI = 0x%04X, "
					"Model = 0x%02X, "
					"Rev = 0x%02X, "
					"%3dbaseT, %s\n",
					j, oui, model, rev,
					miiphy_speed (j),
					miiphy_duplex (j) == FULL ? "FDX" : "HDX");
			}
		}
	} else if (op == 'r') {
		if (miiphy_read (addr, reg, &data) != 0) {
			puts ("Error reading from the PHY\n");
			rcode = 1;
		}
		printf ("%04X\n", data & 0x0000FFFF);
	} else if (op == 'w') {
		if (miiphy_write (addr, reg, data) != 0) {
			puts ("Error writing to the PHY\n");
			rcode = 1;
		}
	} else {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/*
	 * Save the parameters for repeats.
	 */
	last_op = op;
	last_addr = addr;
	last_data = data;
	last_reg = reg;

	return rcode;
}

/***************************************************/

U_BOOT_CMD(
	mii,	5,	1,	do_mii,
	"mii     - MII utility commands\n",
	"info  <addr>              - display MII PHY info\n"
	"mii read  <addr> <reg>        - read  MII PHY <addr> register <reg>\n"
	"mii write <addr> <reg> <data> - write MII PHY <addr> register <reg>\n"
);

#else /* ! CONFIG_TERSE_MII ================================================= */

#include <miivals.h>

typedef struct _MII_reg_desc_t {
	ushort regno;
	char * name;
} MII_reg_desc_t;

MII_reg_desc_t reg_0_5_desc_tbl[] = {
	{ 0,   "PHY control register"                },
	{ 1,   "PHY status register"                 },
	{ 2,   "PHY ID 1 register"                   },
	{ 3,   "PHY ID 2 register"                   },
	{ 4,   "Autonegotiation advertisement register" },
	{ 5,   "Autonegotiation partner abilities register" },
};

typedef struct _MII_field_desc_t {
	ushort hi;
	ushort lo;
	ushort mask;
	char * name;
} MII_field_desc_t;

MII_field_desc_t reg_0_desc_tbl[] = {
	{ 15, 15, 0x01, "reset"                        },
	{ 14, 14, 0x01, "loopback"                     },
	{ 13,  6, 0x81, "speed selection"              }, /* special */
	{ 12, 12, 0x01, "A/N enable"                   },
	{ 11, 11, 0x01, "power-down"                   },
	{ 10, 10, 0x01, "isolate"                      },
	{  9,  9, 0x01, "restart A/N"                  },
	{  8,  8, 0x01, "duplex"                       }, /* special */
	{  7,  7, 0x01, "collision test enable"        },
	{  5,  0, 0x3f, "(reserved)"                   }
};

MII_field_desc_t reg_1_desc_tbl[] = {
	{ 15, 15, 0x01, "100BASE-T4 able"              },
	{ 14, 14, 0x01, "100BASE-X  full duplex able"  },
	{ 13, 13, 0x01, "100BASE-X  half duplex able"  },
	{ 12, 12, 0x01, "10 Mbps    full duplex able"  },
	{ 11, 11, 0x01, "10 Mbps    half duplex able"  },
	{ 10, 10, 0x01, "100BASE-T2 full duplex able"  },
	{  9,  9, 0x01, "100BASE-T2 half duplex able"  },
	{  8,  8, 0x01, "extended status"              },
	{  7,  7, 0x01, "(reserved)"                   },
	{  6,  6, 0x01, "MF preamble suppression"      },
	{  5,  5, 0x01, "A/N complete"                 },
	{  4,  4, 0x01, "remote fault"                 },
	{  3,  3, 0x01, "A/N able"                     },
	{  2,  2, 0x01, "link status"                  },
	{  1,  1, 0x01, "jabber detect"                },
	{  0,  0, 0x01, "extended capabilities"        },
};

MII_field_desc_t reg_2_desc_tbl[] = {
	{ 15,  0, 0xffff, "OUI portion"                },
};

MII_field_desc_t reg_3_desc_tbl[] = {
	{ 15, 10, 0x3f, "OUI portion"                },
	{  9,  4, 0x3f, "manufacturer part number"   },
	{  3,  0, 0x0f, "manufacturer rev. number"   },
};

MII_field_desc_t reg_4_desc_tbl[] = {
	{ 15, 15, 0x01, "next page able"               },
	{ 14, 14, 0x01, "reserved"                     },
	{ 13, 13, 0x01, "remote fault"                 },
	{ 12, 12, 0x01, "reserved"                     },
	{ 11, 11, 0x01, "asymmetric pause"             },
	{ 10, 10, 0x01, "pause enable"                 },
	{  9,  9, 0x01, "100BASE-T4 able"              },
	{  8,  8, 0x01, "100BASE-TX full duplex able"  },
	{  7,  7, 0x01, "100BASE-TX able"              },
	{  6,  6, 0x01, "10BASE-T   full duplex able"  },
	{  5,  5, 0x01, "10BASE-T   able"              },
	{  4,  0, 0x1f, "xxx to do"                    },
};

MII_field_desc_t reg_5_desc_tbl[] = {
	{ 15, 15, 0x01, "next page able"               },
	{ 14, 14, 0x01, "acknowledge"                  },
	{ 13, 13, 0x01, "remote fault"                 },
	{ 12, 12, 0x01, "(reserved)"                   },
	{ 11, 11, 0x01, "asymmetric pause able"        },
	{ 10, 10, 0x01, "pause able"                   },
	{  9,  9, 0x01, "100BASE-T4 able"              },
	{  8,  8, 0x01, "100BASE-X full duplex able"   },
	{  7,  7, 0x01, "100BASE-TX able"              },
	{  6,  6, 0x01, "10BASE-T full duplex able"    },
	{  5,  5, 0x01, "10BASE-T able"                },
	{  4,  0, 0x1f, "xxx to do"                    },
};

#define DESC0LEN (sizeof(reg_0_desc_tbl)/sizeof(reg_0_desc_tbl[0]))
#define DESC1LEN (sizeof(reg_1_desc_tbl)/sizeof(reg_1_desc_tbl[0]))
#define DESC2LEN (sizeof(reg_2_desc_tbl)/sizeof(reg_2_desc_tbl[0]))
#define DESC3LEN (sizeof(reg_3_desc_tbl)/sizeof(reg_3_desc_tbl[0]))
#define DESC4LEN (sizeof(reg_4_desc_tbl)/sizeof(reg_4_desc_tbl[0]))
#define DESC5LEN (sizeof(reg_5_desc_tbl)/sizeof(reg_5_desc_tbl[0]))

typedef struct _MII_field_desc_and_len_t {
	MII_field_desc_t * pdesc;
	ushort len;
} MII_field_desc_and_len_t;

MII_field_desc_and_len_t desc_and_len_tbl[] = {
	{ reg_0_desc_tbl, DESC0LEN },
	{ reg_1_desc_tbl, DESC1LEN },
	{ reg_2_desc_tbl, DESC2LEN },
	{ reg_3_desc_tbl, DESC3LEN },
	{ reg_4_desc_tbl, DESC4LEN },
	{ reg_5_desc_tbl, DESC5LEN },
};

static void dump_reg(
	ushort             regval,
	MII_reg_desc_t   * prd,
	MII_field_desc_and_len_t * pdl);

static int special_field(
	ushort regno,
	MII_field_desc_t * pdesc,
	ushort regval);

void MII_dump_0_to_5(
	ushort regvals[6],
	uchar reglo,
	uchar reghi)
{
	ulong i;

	for (i = 0; i < 6; i++) {
		if ((reglo <= i) && (i <= reghi))
			dump_reg(regvals[i], &reg_0_5_desc_tbl[i],
				&desc_and_len_tbl[i]);
	}
}

static void dump_reg(
	ushort             regval,
	MII_reg_desc_t   * prd,
	MII_field_desc_and_len_t * pdl)
{
	ulong i;
	ushort mask_in_place;
	MII_field_desc_t * pdesc;

	printf("%u.     (%04hx)                 -- %s --\n",
		prd->regno, regval, prd->name);

	for (i = 0; i < pdl->len; i++) {
		pdesc = &pdl->pdesc[i];

		mask_in_place = pdesc->mask << pdesc->lo;

		printf("  (%04hx:%04hx) %u.",
			mask_in_place,
			regval & mask_in_place,
			prd->regno);

		if (special_field(prd->regno, pdesc, regval)) {
		}
		else {
			if (pdesc->hi == pdesc->lo)
				printf("%2u   ", pdesc->lo);
			else
				printf("%2u-%2u", pdesc->hi, pdesc->lo);
			printf(" = %5u    %s",
				(regval & mask_in_place) >> pdesc->lo,
				pdesc->name);
		}
		printf("\n");

	}
	printf("\n");
}

/* Special fields:
** 0.6,13
** 0.8
** 2.15-0
** 3.15-0
** 4.4-0
** 5.4-0
*/

static int special_field(
	ushort regno,
	MII_field_desc_t * pdesc,
	ushort regval)
{
	if ((regno == 0) && (pdesc->lo == 6)) {
		ushort speed_bits = regval & MII_CTL_SPEED_MASK;
		printf("%2u,%2u =   b%u%u    speed selection = %s Mbps",
			6, 13,
			(regval >>  6) & 1,
			(regval >> 13) & 1,
			speed_bits == MII_CTL_SPEED_1000_MBPS ? "1000" :
			speed_bits == MII_CTL_SPEED_100_MBPS  ? "100" :
			speed_bits == MII_CTL_SPEED_10_MBPS   ? "10" :
			"???");
		return 1;
	}

	else if ((regno == 0) && (pdesc->lo == 8)) {
		printf("%2u    = %5u    duplex = %s",
			pdesc->lo,
			(regval >>  pdesc->lo) & 1,
			((regval >> pdesc->lo) & 1) ? "full" : "half");
		return 1;
	}

	else if ((regno == 4) && (pdesc->lo == 0)) {
		ushort sel_bits = (regval >> pdesc->lo) & pdesc->mask;
		printf("%2u-%2u = %5u    selector = %s",
			pdesc->hi, pdesc->lo, sel_bits,
			sel_bits == MII_AN_ADV_IEEE_802_3 ?
				"IEEE 802.3" :
			sel_bits == MII_AN_ADV_IEEE_802_9_ISLAN_16T ?
				"IEEE 802.9 ISLAN-16T" :
			"???");
		return 1;
	}

	else if ((regno == 5) && (pdesc->lo == 0)) {
		ushort sel_bits = (regval >> pdesc->lo) & pdesc->mask;
		printf("%2u-%2u =     %u    selector = %s",
			pdesc->hi, pdesc->lo, sel_bits,
			sel_bits == MII_AN_PARTNER_IEEE_802_3 ?
				"IEEE 802.3" :
			sel_bits == MII_AN_PARTNER_IEEE_802_9_ISLAN_16T ?
				"IEEE 802.9 ISLAN-16T" :
			"???");
		return 1;
	}

	return 0;
}

uint last_op;
uint last_data;
uint last_addr_lo;
uint last_addr_hi;
uint last_reg_lo;
uint last_reg_hi;

static void extract_range(
	char * input,
	unsigned char * plo,
	unsigned char * phi)
{
	char * end;
	*plo = simple_strtoul(input, &end, 16);
	if (*end == '-') {
		end++;
		*phi = simple_strtoul(end, NULL, 16);
	}
	else {
		*phi = *plo;
	}
}

/* ---------------------------------------------------------------- */
int do_mii (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	char		op;
	unsigned char	addrlo, addrhi, reglo, reghi;
	unsigned char	addr, reg;
	unsigned short	data;
	int		rcode = 0;

#ifdef CONFIG_8xx
	mii_init ();
#endif

	/*
	 * We use the last specified parameters, unless new ones are
	 * entered.
	 */
	op     = last_op;
	addrlo = last_addr_lo;
	addrhi = last_addr_hi;
	reglo  = last_reg_lo;
	reghi  = last_reg_hi;
	data   = last_data;

	if ((flag & CMD_FLAG_REPEAT) == 0) {
		op = argv[1][0];
		if (argc >= 3)
			extract_range(argv[2], &addrlo, &addrhi);
		if (argc >= 4)
			extract_range(argv[3], &reglo, &reghi);
		if (argc >= 5)
			data = simple_strtoul (argv[4], NULL, 16);
	}

	/*
	 * check info/read/write.
	 */
	if (op == 'i') {
		unsigned char j, start, end;
		unsigned int oui;
		unsigned char model;
		unsigned char rev;

		/*
		 * Look for any and all PHYs.  Valid addresses are 0..31.
		 */
		if (argc >= 3) {
			start = addr; end = addr + 1;
		} else {
			start = 0; end = 32;
		}

		for (j = start; j < end; j++) {
			if (miiphy_info (j, &oui, &model, &rev) == 0) {
				printf("PHY 0x%02X: "
					"OUI = 0x%04X, "
					"Model = 0x%02X, "
					"Rev = 0x%02X, "
					"%3dbaseT, %s\n",
					j, oui, model, rev,
					miiphy_speed (j),
					miiphy_duplex (j) == FULL ? "FDX" : "HDX");
			}
		}
	} else if (op == 'r') {
		for (addr = addrlo; addr <= addrhi; addr++) {
			for (reg = reglo; reg <= reghi; reg++) {
				data = 0xffff;
				if (miiphy_read (addr, reg, &data) != 0) {
					printf(
					"Error reading from the PHY addr=%02x reg=%02x\n",
						addr, reg);
					rcode = 1;
				}
				else {
					if ((addrlo != addrhi) || (reglo != reghi))
						printf("addr=%02x reg=%02x data=",
							(uint)addr, (uint)reg);
					printf("%04X\n", data & 0x0000FFFF);
				}
			}
			if ((addrlo != addrhi) && (reglo != reghi))
				printf("\n");
		}
	} else if (op == 'w') {
		for (addr = addrlo; addr <= addrhi; addr++) {
			for (reg = reglo; reg <= reghi; reg++) {
				if (miiphy_write (addr, reg, data) != 0) {
					printf("Error writing to the PHY addr=%02x reg=%02x\n",
						addr, reg);
					rcode = 1;
				}
			}
		}
	} else if (op == 'd') {
		ushort regs[6];
		int ok = 1;
		if ((reglo > 5) || (reghi > 5)) {
			printf(
				"The MII dump command only formats the "
				"standard MII registers, 0-5.\n");
			return 1;
		}
		for (addr = addrlo; addr <= addrhi; addr++) {
			for (reg = 0; reg < 6; reg++) {
				if (miiphy_read(addr, reg, &regs[reg]) != 0) {
					ok = 0;
					printf(
					"Error reading from the PHY addr=%02x reg=%02x\n",
						addr, reg);
					rcode = 1;
				}
			}
			if (ok)
				MII_dump_0_to_5(regs, reglo, reghi);
			printf("\n");
		}
	} else {
		printf("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/*
	 * Save the parameters for repeats.
	 */
	last_op      = op;
	last_addr_lo = addrlo;
	last_addr_hi = addrhi;
	last_reg_lo  = reglo;
	last_reg_hi  = reghi;
	last_data    = data;

	return rcode;
}

/***************************************************/

U_BOOT_CMD(
	mii,	5,	1,	do_mii,
	"mii     - MII utility commands\n",
	"info  <addr>                  - display MII PHY info\n"
	"mii read  <addr> <reg>        - read  MII PHY <addr> register <reg>\n"
	"mii write <addr> <reg> <data> - write MII PHY <addr> register <reg>\n"
	"mii dump  <addr> <reg>        - pretty-print <addr> <reg> (0-5 only)\n"
	"Addr and/or reg may be ranges, e.g. 2-7.\n"
);

#endif /* CONFIG_TERSE_MII */

#endif /* CFG_CMD_MII */
