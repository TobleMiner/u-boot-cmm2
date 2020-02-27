// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2019 NXP
 */

#include <linux/kernel.h>
#include <asm/arch/ddr.h>

struct dram_cfg_param ddr_ddrc_cfg[] = {
	/** Initialize DDRC registers **/
	{ 0x3d400304, 0x1 },
	{ 0x3d400030, 0x1 },
	{ 0x3d400000, 0xa3080020 },
	{ 0x3d400020, 0x1323 },
	{ 0x3d400024, 0x1e84800 },
	{ 0x3d400064, 0x7a0118 },
	{ 0x3d4000d0, 0xc00307a3 },
	{ 0x3d4000d4, 0xc50000 },
	{ 0x3d4000dc, 0xf4003f },
	{ 0x3d4000e0, 0x330000 },
	{ 0x3d4000e8, 0x460048 },
	{ 0x3d4000ec, 0x150048 },
	{ 0x3d400100, 0x2028222a },
	{ 0x3d400104, 0x807bf },
	{ 0x3d40010c, 0xe0e000 },
	{ 0x3d400110, 0x12040a12 },
	{ 0x3d400114, 0x2050f0f },
	{ 0x3d400118, 0x1010009 },
	{ 0x3d40011c, 0x501 },
	{ 0x3d400130, 0x20800 },
	{ 0x3d400134, 0xe100002 },
	{ 0x3d400138, 0x120 },
	{ 0x3d400144, 0xc80064 },
	{ 0x3d400180, 0x3e8001e },
	{ 0x3d400184, 0x3207a12 },
	{ 0x3d400188, 0x0 },
	{ 0x3d400190, 0x49f820e },
	{ 0x3d400194, 0x80303 },
	{ 0x3d4001b4, 0x1f0e },
	{ 0x3d4001a0, 0xe0400018 },
	{ 0x3d4001a4, 0xdf00e4 },
	{ 0x3d4001a8, 0x80000000 },
	{ 0x3d4001b0, 0x11 },
	{ 0x3d4001c0, 0x1 },
	{ 0x3d4001c4, 0x1 },
	{ 0x3d4000f4, 0xc99 },
	{ 0x3d400108, 0x9121c1c },
	{ 0x3d400200, 0x16 },
	{ 0x3d40020c, 0x0 },
	{ 0x3d400210, 0x1f1f },
	{ 0x3d400204, 0x80808 },
	{ 0x3d400214, 0x7070707 },
	{ 0x3d400218, 0x68070707 },
	{ 0x3d40021c, 0xf08 },
	{ 0x3d400250, 0x00001705 },
	{ 0x3d400254, 0x2c },
	{ 0x3d40025c, 0x4000030 },
	{ 0x3d400264, 0x900093e7 },
	{ 0x3d40026c, 0x2005574 },
	{ 0x3d400400, 0x111 },
       { 0x3d400404, 0x72ff },
	{ 0x3d400408, 0x72ff },
	{ 0x3d400494, 0x2100e07 },
	{ 0x3d400498, 0x620096 },
	{ 0x3d40049c, 0x1100e07 },
	{ 0x3d4004a0, 0xc8012c },
	{ 0x3d402020, 0x21 },
	{ 0x3d402024, 0x7d00 },
	{ 0x3d402050, 0x20d040 },
	{ 0x3d402064, 0xc001c },
	{ 0x3d4020dc, 0x840000 },
	{ 0x3d4020e0, 0x310000 },
	{ 0x3d4020e8, 0x66004d },
	{ 0x3d4020ec, 0x16004d },
	{ 0x3d402100, 0xa040305 },
	{ 0x3d402104, 0x30407 },
	{ 0x3d402108, 0x203060b },
	{ 0x3d40210c, 0x505000 },
	{ 0x3d402110, 0x2040202 },
	{ 0x3d402114, 0x2030202 },
	{ 0x3d402118, 0x1010004 },
	{ 0x3d40211c, 0x301 },
	{ 0x3d402130, 0x20300 },
	{ 0x3d402134, 0xa100002 },
	{ 0x3d402138, 0x1d },
	{ 0x3d402144, 0x14000a },
	{ 0x3d402180, 0x640004 },
	{ 0x3d402190, 0x3818200 },
	{ 0x3d402194, 0x80303 },
	{ 0x3d4021b4, 0x100 },
	{ 0x3d4020f4, 0xc99 },
	{ 0x3d403020, 0x21 },
	{ 0x3d403024, 0x30d400 },
	{ 0x3d403050, 0x20d040 },
	{ 0x3d403064, 0x30007 },
	{ 0x3d4030dc, 0x840000 },
	{ 0x3d4030e0, 0x310000 },
	{ 0x3d4030e8, 0x66004d },
	{ 0x3d4030ec, 0x16004d },
	{ 0x3d403100, 0xa010102 },
	{ 0x3d403104, 0x30404 },
	{ 0x3d403108, 0x203060b },
	{ 0x3d40310c, 0x505000 },
	{ 0x3d403110, 0x2040202 },
	{ 0x3d403114, 0x2030202 },
	{ 0x3d403118, 0x1010004 },
	{ 0x3d40311c, 0x301 },
	{ 0x3d403130, 0x20300 },
	{ 0x3d403134, 0xa100002 },
	{ 0x3d403138, 0x8 },
	{ 0x3d403144, 0x50003 },
	{ 0x3d403180, 0x190004 },
	{ 0x3d403190, 0x3818200 },
	{ 0x3d403194, 0x80303 },
	{ 0x3d4031b4, 0x100 },
	{ 0x3d400028, 0x0 },
};

/* PHY Initialize Configuration */
struct dram_cfg_param ddr_ddrphy_cfg[] = {
	{ 0x100a0, 0x0 },
	{ 0x100a1, 0x1 },
	{ 0x100a2, 0x2 },
	{ 0x100a3, 0x3 },
	{ 0x100a4, 0x4 },
	{ 0x100a5, 0x5 },
	{ 0x100a6, 0x6 },
	{ 0x100a7, 0x7 },
	{ 0x110a0, 0x0 },
	{ 0x110a1, 0x1 },
	{ 0x110a2, 0x3 },
	{ 0x110a3, 0x4 },
	{ 0x110a4, 0x5 },
	{ 0x110a5, 0x2 },
	{ 0x110a6, 0x7 },
	{ 0x110a7, 0x6 },
	{ 0x120a0, 0x0 },
	{ 0x120a1, 0x1 },
	{ 0x120a2, 0x3 },
	{ 0x120a3, 0x2 },
	{ 0x120a4, 0x5 },
	{ 0x120a5, 0x4 },
	{ 0x120a6, 0x7 },
	{ 0x120a7, 0x6 },
	{ 0x130a0, 0x0 },
	{ 0x130a1, 0x1 },
	{ 0x130a2, 0x2 },
	{ 0x130a3, 0x3 },
	{ 0x130a4, 0x4 },
	{ 0x130a5, 0x5 },
	{ 0x130a6, 0x6 },
	{ 0x130a7, 0x7 },
	{ 0x1005f, 0x1ff },
	{ 0x1015f, 0x1ff },
	{ 0x1105f, 0x1ff },
	{ 0x1115f, 0x1ff },
	{ 0x1205f, 0x1ff },
	{ 0x1215f, 0x1ff },
	{ 0x1305f, 0x1ff },
	{ 0x1315f, 0x1ff },
	{ 0x11005f, 0x1ff },
	{ 0x11015f, 0x1ff },
	{ 0x11105f, 0x1ff },
	{ 0x11115f, 0x1ff },
	{ 0x11205f, 0x1ff },
	{ 0x11215f, 0x1ff },
	{ 0x11305f, 0x1ff },
	{ 0x11315f, 0x1ff },
	{ 0x21005f, 0x1ff },
	{ 0x21015f, 0x1ff },
	{ 0x21105f, 0x1ff },
	{ 0x21115f, 0x1ff },
	{ 0x21205f, 0x1ff },
	{ 0x21215f, 0x1ff },
	{ 0x21305f, 0x1ff },
	{ 0x21315f, 0x1ff },
	{ 0x55, 0x1ff },
	{ 0x1055, 0x1ff },
	{ 0x2055, 0x1ff },
	{ 0x3055, 0x1ff },
	{ 0x4055, 0x1ff },
	{ 0x5055, 0x1ff },
	{ 0x6055, 0x1ff },
	{ 0x7055, 0x1ff },
	{ 0x8055, 0x1ff },
	{ 0x9055, 0x1ff },
	{ 0x200c5, 0x18 },
	{ 0x1200c5, 0x7 },
	{ 0x2200c5, 0x7 },
	{ 0x2002e, 0x2 },
	{ 0x12002e, 0x2 },
	{ 0x22002e, 0x2 },
	{ 0x90204, 0x0 },
	{ 0x190204, 0x0 },
	{ 0x290204, 0x0 },
	{ 0x20024, 0x1e3 },
	{ 0x2003a, 0x2 },
	{ 0x120024, 0x1e3 },
	{ 0x2003a, 0x2 },
	{ 0x220024, 0x1e3 },
	{ 0x2003a, 0x2 },
	{ 0x20056, 0x3 },
	{ 0x120056, 0x3 },
	{ 0x220056, 0x3 },
	{ 0x1004d, 0xe00 },
	{ 0x1014d, 0xe00 },
	{ 0x1104d, 0xe00 },
	{ 0x1114d, 0xe00 },
	{ 0x1204d, 0xe00 },
	{ 0x1214d, 0xe00 },
	{ 0x1304d, 0xe00 },
	{ 0x1314d, 0xe00 },
	{ 0x11004d, 0xe00 },
	{ 0x11014d, 0xe00 },
	{ 0x11104d, 0xe00 },
	{ 0x11114d, 0xe00 },
	{ 0x11204d, 0xe00 },
	{ 0x11214d, 0xe00 },
	{ 0x11304d, 0xe00 },
	{ 0x11314d, 0xe00 },
	{ 0x21004d, 0xe00 },
	{ 0x21014d, 0xe00 },
	{ 0x21104d, 0xe00 },
	{ 0x21114d, 0xe00 },
	{ 0x21204d, 0xe00 },
	{ 0x21214d, 0xe00 },
	{ 0x21304d, 0xe00 },
	{ 0x21314d, 0xe00 },
	{ 0x10049, 0xeba },
	{ 0x10149, 0xeba },
	{ 0x11049, 0xeba },
	{ 0x11149, 0xeba },
	{ 0x12049, 0xeba },
	{ 0x12149, 0xeba },
	{ 0x13049, 0xeba },
	{ 0x13149, 0xeba },
	{ 0x110049, 0xeba },
	{ 0x110149, 0xeba },
	{ 0x111049, 0xeba },
	{ 0x111149, 0xeba },
	{ 0x112049, 0xeba },
	{ 0x112149, 0xeba },
	{ 0x113049, 0xeba },
	{ 0x113149, 0xeba },
	{ 0x210049, 0xeba },
	{ 0x210149, 0xeba },
	{ 0x211049, 0xeba },
	{ 0x211149, 0xeba },
	{ 0x212049, 0xeba },
	{ 0x212149, 0xeba },
	{ 0x213049, 0xeba },
	{ 0x213149, 0xeba },
	{ 0x43, 0x63 },
	{ 0x1043, 0x63 },
	{ 0x2043, 0x63 },
	{ 0x3043, 0x63 },
	{ 0x4043, 0x63 },
	{ 0x5043, 0x63 },
	{ 0x6043, 0x63 },
	{ 0x7043, 0x63 },
	{ 0x8043, 0x63 },
	{ 0x9043, 0x63 },
	{ 0x20018, 0x3 },
	{ 0x20075, 0x4 },
	{ 0x20050, 0x0 },
	{ 0x20008, 0x3e8 },
	{ 0x120008, 0x64 },
	{ 0x220008, 0x19 },
	{ 0x20088, 0x9 },
	{ 0x200b2, 0x104 },
	{ 0x10043, 0x5a1 },
	{ 0x10143, 0x5a1 },
	{ 0x11043, 0x5a1 },
	{ 0x11143, 0x5a1 },
	{ 0x12043, 0x5a1 },
	{ 0x12143, 0x5a1 },
	{ 0x13043, 0x5a1 },
	{ 0x13143, 0x5a1 },
	{ 0x1200b2, 0x104 },
	{ 0x110043, 0x5a1 },
	{ 0x110143, 0x5a1 },
	{ 0x111043, 0x5a1 },
	{ 0x111143, 0x5a1 },
	{ 0x112043, 0x5a1 },
	{ 0x112143, 0x5a1 },
	{ 0x113043, 0x5a1 },
	{ 0x113143, 0x5a1 },
	{ 0x2200b2, 0x104 },
	{ 0x210043, 0x5a1 },
	{ 0x210143, 0x5a1 },
	{ 0x211043, 0x5a1 },
	{ 0x211143, 0x5a1 },
	{ 0x212043, 0x5a1 },
	{ 0x212143, 0x5a1 },
	{ 0x213043, 0x5a1 },
	{ 0x213143, 0x5a1 },
	{ 0x200fa, 0x1 },
	{ 0x1200fa, 0x1 },
	{ 0x2200fa, 0x1 },
	{ 0x20019, 0x1 },
	{ 0x120019, 0x1 },
	{ 0x220019, 0x1 },
	{ 0x200f0, 0x660 },
	{ 0x200f1, 0x0 },
	{ 0x200f2, 0x4444 },
	{ 0x200f3, 0x8888 },
	{ 0x200f4, 0x5665 },
	{ 0x200f5, 0x0 },
	{ 0x200f6, 0x0 },
	{ 0x200f7, 0xf000 },
	{ 0x20025, 0x0 },
	{ 0x2002d, 0x0 },
	{ 0x12002d, 0x0 },
	{ 0x22002d, 0x0 },
	{ 0x2007d, 0x212 },
	{ 0x12007d, 0x212 },
	{ 0x22007d, 0x212 },
	{ 0x2007c, 0x61 },
	{ 0x12007c, 0x61 },
	{ 0x22007c, 0x61 },
	{ 0x1004a, 0x500 },
	{ 0x1104a, 0x500 },
	{ 0x1204a, 0x500 },
	{ 0x1304a, 0x500 },
	{ 0x2002c, 0x0 },
};

/* ddr phy trained csr */
struct dram_cfg_param ddr_ddrphy_trained_csr[] = {
	{ 0x200b2, 0x0 },
	{ 0x1200b2, 0x0 },
	{ 0x2200b2, 0x0 },
	{ 0x200cb, 0x0 },
	{ 0x10043, 0x0 },
	{ 0x110043, 0x0 },
	{ 0x210043, 0x0 },
	{ 0x10143, 0x0 },
	{ 0x110143, 0x0 },
	{ 0x210143, 0x0 },
	{ 0x11043, 0x0 },
	{ 0x111043, 0x0 },
	{ 0x211043, 0x0 },
	{ 0x11143, 0x0 },
	{ 0x111143, 0x0 },
	{ 0x211143, 0x0 },
	{ 0x12043, 0x0 },
	{ 0x112043, 0x0 },
	{ 0x212043, 0x0 },
	{ 0x12143, 0x0 },
	{ 0x112143, 0x0 },
	{ 0x212143, 0x0 },
	{ 0x13043, 0x0 },
	{ 0x113043, 0x0 },
	{ 0x213043, 0x0 },
	{ 0x13143, 0x0 },
	{ 0x113143, 0x0 },
	{ 0x213143, 0x0 },
	{ 0x80, 0x0 },
	{ 0x100080, 0x0 },
	{ 0x200080, 0x0 },
	{ 0x1080, 0x0 },
	{ 0x101080, 0x0 },
	{ 0x201080, 0x0 },
	{ 0x2080, 0x0 },
	{ 0x102080, 0x0 },
	{ 0x202080, 0x0 },
	{ 0x3080, 0x0 },
	{ 0x103080, 0x0 },
	{ 0x203080, 0x0 },
	{ 0x4080, 0x0 },
	{ 0x104080, 0x0 },
	{ 0x204080, 0x0 },
	{ 0x5080, 0x0 },
	{ 0x105080, 0x0 },
	{ 0x205080, 0x0 },
	{ 0x6080, 0x0 },
	{ 0x106080, 0x0 },
	{ 0x206080, 0x0 },
	{ 0x7080, 0x0 },
	{ 0x107080, 0x0 },
	{ 0x207080, 0x0 },
	{ 0x8080, 0x0 },
	{ 0x108080, 0x0 },
	{ 0x208080, 0x0 },
	{ 0x9080, 0x0 },
	{ 0x109080, 0x0 },
	{ 0x209080, 0x0 },
	{ 0x10080, 0x0 },
	{ 0x110080, 0x0 },
	{ 0x210080, 0x0 },
	{ 0x10180, 0x0 },
	{ 0x110180, 0x0 },
	{ 0x210180, 0x0 },
	{ 0x11080, 0x0 },
	{ 0x111080, 0x0 },
	{ 0x211080, 0x0 },
	{ 0x11180, 0x0 },
	{ 0x111180, 0x0 },
	{ 0x211180, 0x0 },
	{ 0x12080, 0x0 },
	{ 0x112080, 0x0 },
	{ 0x212080, 0x0 },
	{ 0x12180, 0x0 },
	{ 0x112180, 0x0 },
	{ 0x212180, 0x0 },
	{ 0x13080, 0x0 },
	{ 0x113080, 0x0 },
	{ 0x213080, 0x0 },
	{ 0x13180, 0x0 },
	{ 0x113180, 0x0 },
	{ 0x213180, 0x0 },
	{ 0x10081, 0x0 },
	{ 0x110081, 0x0 },
	{ 0x210081, 0x0 },
	{ 0x10181, 0x0 },
	{ 0x110181, 0x0 },
	{ 0x210181, 0x0 },
	{ 0x11081, 0x0 },
	{ 0x111081, 0x0 },
	{ 0x211081, 0x0 },
	{ 0x11181, 0x0 },
	{ 0x111181, 0x0 },
	{ 0x211181, 0x0 },
	{ 0x12081, 0x0 },
	{ 0x112081, 0x0 },
	{ 0x212081, 0x0 },
	{ 0x12181, 0x0 },
	{ 0x112181, 0x0 },
	{ 0x212181, 0x0 },
	{ 0x13081, 0x0 },
	{ 0x113081, 0x0 },
	{ 0x213081, 0x0 },
	{ 0x13181, 0x0 },
	{ 0x113181, 0x0 },
	{ 0x213181, 0x0 },
	{ 0x100d0, 0x0 },
	{ 0x1100d0, 0x0 },
	{ 0x2100d0, 0x0 },
	{ 0x101d0, 0x0 },
	{ 0x1101d0, 0x0 },
	{ 0x2101d0, 0x0 },
	{ 0x110d0, 0x0 },
	{ 0x1110d0, 0x0 },
	{ 0x2110d0, 0x0 },
	{ 0x111d0, 0x0 },
	{ 0x1111d0, 0x0 },
	{ 0x2111d0, 0x0 },
	{ 0x120d0, 0x0 },
	{ 0x1120d0, 0x0 },
	{ 0x2120d0, 0x0 },
	{ 0x121d0, 0x0 },
	{ 0x1121d0, 0x0 },
	{ 0x2121d0, 0x0 },
	{ 0x130d0, 0x0 },
	{ 0x1130d0, 0x0 },
	{ 0x2130d0, 0x0 },
	{ 0x131d0, 0x0 },
	{ 0x1131d0, 0x0 },
	{ 0x2131d0, 0x0 },
	{ 0x100d1, 0x0 },
	{ 0x1100d1, 0x0 },
	{ 0x2100d1, 0x0 },
	{ 0x101d1, 0x0 },
	{ 0x1101d1, 0x0 },
	{ 0x2101d1, 0x0 },
	{ 0x110d1, 0x0 },
	{ 0x1110d1, 0x0 },
	{ 0x2110d1, 0x0 },
	{ 0x111d1, 0x0 },
	{ 0x1111d1, 0x0 },
	{ 0x2111d1, 0x0 },
	{ 0x120d1, 0x0 },
	{ 0x1120d1, 0x0 },
	{ 0x2120d1, 0x0 },
	{ 0x121d1, 0x0 },
	{ 0x1121d1, 0x0 },
	{ 0x2121d1, 0x0 },
	{ 0x130d1, 0x0 },
	{ 0x1130d1, 0x0 },
	{ 0x2130d1, 0x0 },
	{ 0x131d1, 0x0 },
	{ 0x1131d1, 0x0 },
	{ 0x2131d1, 0x0 },
	{ 0x10068, 0x0 },
	{ 0x10168, 0x0 },
	{ 0x10268, 0x0 },
	{ 0x10368, 0x0 },
	{ 0x10468, 0x0 },
	{ 0x10568, 0x0 },
	{ 0x10668, 0x0 },
	{ 0x10768, 0x0 },
	{ 0x10868, 0x0 },
	{ 0x11068, 0x0 },
	{ 0x11168, 0x0 },
	{ 0x11268, 0x0 },
	{ 0x11368, 0x0 },
	{ 0x11468, 0x0 },
	{ 0x11568, 0x0 },
	{ 0x11668, 0x0 },
	{ 0x11768, 0x0 },
	{ 0x11868, 0x0 },
	{ 0x12068, 0x0 },
	{ 0x12168, 0x0 },
	{ 0x12268, 0x0 },
	{ 0x12368, 0x0 },
	{ 0x12468, 0x0 },
	{ 0x12568, 0x0 },
	{ 0x12668, 0x0 },
	{ 0x12768, 0x0 },
	{ 0x12868, 0x0 },
	{ 0x13068, 0x0 },
	{ 0x13168, 0x0 },
	{ 0x13268, 0x0 },
	{ 0x13368, 0x0 },
	{ 0x13468, 0x0 },
	{ 0x13568, 0x0 },
	{ 0x13668, 0x0 },
	{ 0x13768, 0x0 },
	{ 0x13868, 0x0 },
	{ 0x10069, 0x0 },
	{ 0x10169, 0x0 },
	{ 0x10269, 0x0 },
	{ 0x10369, 0x0 },
	{ 0x10469, 0x0 },
	{ 0x10569, 0x0 },
	{ 0x10669, 0x0 },
	{ 0x10769, 0x0 },
	{ 0x10869, 0x0 },
	{ 0x11069, 0x0 },
	{ 0x11169, 0x0 },
	{ 0x11269, 0x0 },
	{ 0x11369, 0x0 },
	{ 0x11469, 0x0 },
	{ 0x11569, 0x0 },
	{ 0x11669, 0x0 },
	{ 0x11769, 0x0 },
	{ 0x11869, 0x0 },
	{ 0x12069, 0x0 },
	{ 0x12169, 0x0 },
	{ 0x12269, 0x0 },
	{ 0x12369, 0x0 },
	{ 0x12469, 0x0 },
	{ 0x12569, 0x0 },
	{ 0x12669, 0x0 },
	{ 0x12769, 0x0 },
	{ 0x12869, 0x0 },
	{ 0x13069, 0x0 },
	{ 0x13169, 0x0 },
	{ 0x13269, 0x0 },
	{ 0x13369, 0x0 },
	{ 0x13469, 0x0 },
	{ 0x13569, 0x0 },
	{ 0x13669, 0x0 },
	{ 0x13769, 0x0 },
	{ 0x13869, 0x0 },
	{ 0x1008c, 0x0 },
	{ 0x11008c, 0x0 },
	{ 0x21008c, 0x0 },
	{ 0x1018c, 0x0 },
	{ 0x11018c, 0x0 },
	{ 0x21018c, 0x0 },
	{ 0x1108c, 0x0 },
	{ 0x11108c, 0x0 },
	{ 0x21108c, 0x0 },
	{ 0x1118c, 0x0 },
	{ 0x11118c, 0x0 },
	{ 0x21118c, 0x0 },
	{ 0x1208c, 0x0 },
	{ 0x11208c, 0x0 },
	{ 0x21208c, 0x0 },
	{ 0x1218c, 0x0 },
	{ 0x11218c, 0x0 },
	{ 0x21218c, 0x0 },
	{ 0x1308c, 0x0 },
	{ 0x11308c, 0x0 },
	{ 0x21308c, 0x0 },
	{ 0x1318c, 0x0 },
	{ 0x11318c, 0x0 },
	{ 0x21318c, 0x0 },
	{ 0x1008d, 0x0 },
	{ 0x11008d, 0x0 },
	{ 0x21008d, 0x0 },
	{ 0x1018d, 0x0 },
	{ 0x11018d, 0x0 },
	{ 0x21018d, 0x0 },
	{ 0x1108d, 0x0 },
	{ 0x11108d, 0x0 },
	{ 0x21108d, 0x0 },
	{ 0x1118d, 0x0 },
	{ 0x11118d, 0x0 },
	{ 0x21118d, 0x0 },
	{ 0x1208d, 0x0 },
	{ 0x11208d, 0x0 },
	{ 0x21208d, 0x0 },
	{ 0x1218d, 0x0 },
	{ 0x11218d, 0x0 },
	{ 0x21218d, 0x0 },
	{ 0x1308d, 0x0 },
	{ 0x11308d, 0x0 },
	{ 0x21308d, 0x0 },
	{ 0x1318d, 0x0 },
	{ 0x11318d, 0x0 },
	{ 0x21318d, 0x0 },
	{ 0x100c0, 0x0 },
	{ 0x1100c0, 0x0 },
	{ 0x2100c0, 0x0 },
	{ 0x101c0, 0x0 },
	{ 0x1101c0, 0x0 },
	{ 0x2101c0, 0x0 },
	{ 0x102c0, 0x0 },
	{ 0x1102c0, 0x0 },
	{ 0x2102c0, 0x0 },
	{ 0x103c0, 0x0 },
	{ 0x1103c0, 0x0 },
	{ 0x2103c0, 0x0 },
	{ 0x104c0, 0x0 },
	{ 0x1104c0, 0x0 },
	{ 0x2104c0, 0x0 },
	{ 0x105c0, 0x0 },
	{ 0x1105c0, 0x0 },
	{ 0x2105c0, 0x0 },
	{ 0x106c0, 0x0 },
	{ 0x1106c0, 0x0 },
	{ 0x2106c0, 0x0 },
	{ 0x107c0, 0x0 },
	{ 0x1107c0, 0x0 },
	{ 0x2107c0, 0x0 },
	{ 0x108c0, 0x0 },
	{ 0x1108c0, 0x0 },
	{ 0x2108c0, 0x0 },
	{ 0x110c0, 0x0 },
	{ 0x1110c0, 0x0 },
	{ 0x2110c0, 0x0 },
	{ 0x111c0, 0x0 },
	{ 0x1111c0, 0x0 },
	{ 0x2111c0, 0x0 },
	{ 0x112c0, 0x0 },
	{ 0x1112c0, 0x0 },
	{ 0x2112c0, 0x0 },
	{ 0x113c0, 0x0 },
	{ 0x1113c0, 0x0 },
	{ 0x2113c0, 0x0 },
	{ 0x114c0, 0x0 },
	{ 0x1114c0, 0x0 },
	{ 0x2114c0, 0x0 },
	{ 0x115c0, 0x0 },
	{ 0x1115c0, 0x0 },
	{ 0x2115c0, 0x0 },
	{ 0x116c0, 0x0 },
	{ 0x1116c0, 0x0 },
	{ 0x2116c0, 0x0 },
	{ 0x117c0, 0x0 },
	{ 0x1117c0, 0x0 },
	{ 0x2117c0, 0x0 },
	{ 0x118c0, 0x0 },
	{ 0x1118c0, 0x0 },
	{ 0x2118c0, 0x0 },
	{ 0x120c0, 0x0 },
	{ 0x1120c0, 0x0 },
	{ 0x2120c0, 0x0 },
	{ 0x121c0, 0x0 },
	{ 0x1121c0, 0x0 },
	{ 0x2121c0, 0x0 },
	{ 0x122c0, 0x0 },
	{ 0x1122c0, 0x0 },
	{ 0x2122c0, 0x0 },
	{ 0x123c0, 0x0 },
	{ 0x1123c0, 0x0 },
	{ 0x2123c0, 0x0 },
	{ 0x124c0, 0x0 },
	{ 0x1124c0, 0x0 },
	{ 0x2124c0, 0x0 },
	{ 0x125c0, 0x0 },
	{ 0x1125c0, 0x0 },
	{ 0x2125c0, 0x0 },
	{ 0x126c0, 0x0 },
	{ 0x1126c0, 0x0 },
	{ 0x2126c0, 0x0 },
	{ 0x127c0, 0x0 },
	{ 0x1127c0, 0x0 },
	{ 0x2127c0, 0x0 },
	{ 0x128c0, 0x0 },
	{ 0x1128c0, 0x0 },
	{ 0x2128c0, 0x0 },
	{ 0x130c0, 0x0 },
	{ 0x1130c0, 0x0 },
	{ 0x2130c0, 0x0 },
	{ 0x131c0, 0x0 },
	{ 0x1131c0, 0x0 },
	{ 0x2131c0, 0x0 },
	{ 0x132c0, 0x0 },
	{ 0x1132c0, 0x0 },
	{ 0x2132c0, 0x0 },
	{ 0x133c0, 0x0 },
	{ 0x1133c0, 0x0 },
	{ 0x2133c0, 0x0 },
	{ 0x134c0, 0x0 },
	{ 0x1134c0, 0x0 },
	{ 0x2134c0, 0x0 },
	{ 0x135c0, 0x0 },
	{ 0x1135c0, 0x0 },
	{ 0x2135c0, 0x0 },
	{ 0x136c0, 0x0 },
	{ 0x1136c0, 0x0 },
	{ 0x2136c0, 0x0 },
	{ 0x137c0, 0x0 },
	{ 0x1137c0, 0x0 },
	{ 0x2137c0, 0x0 },
	{ 0x138c0, 0x0 },
	{ 0x1138c0, 0x0 },
	{ 0x2138c0, 0x0 },
	{ 0x100c1, 0x0 },
	{ 0x1100c1, 0x0 },
	{ 0x2100c1, 0x0 },
	{ 0x101c1, 0x0 },
	{ 0x1101c1, 0x0 },
	{ 0x2101c1, 0x0 },
	{ 0x102c1, 0x0 },
	{ 0x1102c1, 0x0 },
	{ 0x2102c1, 0x0 },
	{ 0x103c1, 0x0 },
	{ 0x1103c1, 0x0 },
	{ 0x2103c1, 0x0 },
	{ 0x104c1, 0x0 },
	{ 0x1104c1, 0x0 },
	{ 0x2104c1, 0x0 },
	{ 0x105c1, 0x0 },
	{ 0x1105c1, 0x0 },
	{ 0x2105c1, 0x0 },
	{ 0x106c1, 0x0 },
	{ 0x1106c1, 0x0 },
	{ 0x2106c1, 0x0 },
	{ 0x107c1, 0x0 },
	{ 0x1107c1, 0x0 },
	{ 0x2107c1, 0x0 },
	{ 0x108c1, 0x0 },
	{ 0x1108c1, 0x0 },
	{ 0x2108c1, 0x0 },
	{ 0x110c1, 0x0 },
	{ 0x1110c1, 0x0 },
	{ 0x2110c1, 0x0 },
	{ 0x111c1, 0x0 },
	{ 0x1111c1, 0x0 },
	{ 0x2111c1, 0x0 },
	{ 0x112c1, 0x0 },
	{ 0x1112c1, 0x0 },
	{ 0x2112c1, 0x0 },
	{ 0x113c1, 0x0 },
	{ 0x1113c1, 0x0 },
	{ 0x2113c1, 0x0 },
	{ 0x114c1, 0x0 },
	{ 0x1114c1, 0x0 },
	{ 0x2114c1, 0x0 },
	{ 0x115c1, 0x0 },
	{ 0x1115c1, 0x0 },
	{ 0x2115c1, 0x0 },
	{ 0x116c1, 0x0 },
	{ 0x1116c1, 0x0 },
	{ 0x2116c1, 0x0 },
	{ 0x117c1, 0x0 },
	{ 0x1117c1, 0x0 },
	{ 0x2117c1, 0x0 },
	{ 0x118c1, 0x0 },
	{ 0x1118c1, 0x0 },
	{ 0x2118c1, 0x0 },
	{ 0x120c1, 0x0 },
	{ 0x1120c1, 0x0 },
	{ 0x2120c1, 0x0 },
	{ 0x121c1, 0x0 },
	{ 0x1121c1, 0x0 },
	{ 0x2121c1, 0x0 },
	{ 0x122c1, 0x0 },
	{ 0x1122c1, 0x0 },
	{ 0x2122c1, 0x0 },
	{ 0x123c1, 0x0 },
	{ 0x1123c1, 0x0 },
	{ 0x2123c1, 0x0 },
	{ 0x124c1, 0x0 },
	{ 0x1124c1, 0x0 },
	{ 0x2124c1, 0x0 },
	{ 0x125c1, 0x0 },
	{ 0x1125c1, 0x0 },
	{ 0x2125c1, 0x0 },
	{ 0x126c1, 0x0 },
	{ 0x1126c1, 0x0 },
	{ 0x2126c1, 0x0 },
	{ 0x127c1, 0x0 },
	{ 0x1127c1, 0x0 },
	{ 0x2127c1, 0x0 },
	{ 0x128c1, 0x0 },
	{ 0x1128c1, 0x0 },
	{ 0x2128c1, 0x0 },
	{ 0x130c1, 0x0 },
	{ 0x1130c1, 0x0 },
	{ 0x2130c1, 0x0 },
	{ 0x131c1, 0x0 },
	{ 0x1131c1, 0x0 },
	{ 0x2131c1, 0x0 },
	{ 0x132c1, 0x0 },
	{ 0x1132c1, 0x0 },
	{ 0x2132c1, 0x0 },
	{ 0x133c1, 0x0 },
	{ 0x1133c1, 0x0 },
	{ 0x2133c1, 0x0 },
	{ 0x134c1, 0x0 },
	{ 0x1134c1, 0x0 },
	{ 0x2134c1, 0x0 },
	{ 0x135c1, 0x0 },
	{ 0x1135c1, 0x0 },
	{ 0x2135c1, 0x0 },
	{ 0x136c1, 0x0 },
	{ 0x1136c1, 0x0 },
	{ 0x2136c1, 0x0 },
	{ 0x137c1, 0x0 },
	{ 0x1137c1, 0x0 },
	{ 0x2137c1, 0x0 },
	{ 0x138c1, 0x0 },
	{ 0x1138c1, 0x0 },
	{ 0x2138c1, 0x0 },
	{ 0x10020, 0x0 },
	{ 0x110020, 0x0 },
	{ 0x210020, 0x0 },
	{ 0x11020, 0x0 },
	{ 0x111020, 0x0 },
	{ 0x211020, 0x0 },
	{ 0x12020, 0x0 },
	{ 0x112020, 0x0 },
	{ 0x212020, 0x0 },
	{ 0x13020, 0x0 },
	{ 0x113020, 0x0 },
	{ 0x213020, 0x0 },
	{ 0x20072, 0x0 },
	{ 0x20073, 0x0 },
	{ 0x20074, 0x0 },
	{ 0x100aa, 0x0 },
	{ 0x110aa, 0x0 },
	{ 0x120aa, 0x0 },
	{ 0x130aa, 0x0 },
	{ 0x20010, 0x0 },
	{ 0x120010, 0x0 },
	{ 0x220010, 0x0 },
	{ 0x20011, 0x0 },
	{ 0x120011, 0x0 },
	{ 0x220011, 0x0 },
	{ 0x100ae, 0x0 },
	{ 0x1100ae, 0x0 },
	{ 0x2100ae, 0x0 },
	{ 0x100af, 0x0 },
	{ 0x1100af, 0x0 },
	{ 0x2100af, 0x0 },
	{ 0x110ae, 0x0 },
	{ 0x1110ae, 0x0 },
	{ 0x2110ae, 0x0 },
	{ 0x110af, 0x0 },
	{ 0x1110af, 0x0 },
	{ 0x2110af, 0x0 },
	{ 0x120ae, 0x0 },
	{ 0x1120ae, 0x0 },
	{ 0x2120ae, 0x0 },
	{ 0x120af, 0x0 },
	{ 0x1120af, 0x0 },
	{ 0x2120af, 0x0 },
	{ 0x130ae, 0x0 },
	{ 0x1130ae, 0x0 },
	{ 0x2130ae, 0x0 },
	{ 0x130af, 0x0 },
	{ 0x1130af, 0x0 },
	{ 0x2130af, 0x0 },
	{ 0x20020, 0x0 },
	{ 0x120020, 0x0 },
	{ 0x220020, 0x0 },
	{ 0x100a0, 0x0 },
	{ 0x100a1, 0x0 },
	{ 0x100a2, 0x0 },
	{ 0x100a3, 0x0 },
	{ 0x100a4, 0x0 },
	{ 0x100a5, 0x0 },
	{ 0x100a6, 0x0 },
	{ 0x100a7, 0x0 },
	{ 0x110a0, 0x0 },
	{ 0x110a1, 0x0 },
	{ 0x110a2, 0x0 },
	{ 0x110a3, 0x0 },
	{ 0x110a4, 0x0 },
	{ 0x110a5, 0x0 },
	{ 0x110a6, 0x0 },
	{ 0x110a7, 0x0 },
	{ 0x120a0, 0x0 },
	{ 0x120a1, 0x0 },
	{ 0x120a2, 0x0 },
	{ 0x120a3, 0x0 },
	{ 0x120a4, 0x0 },
	{ 0x120a5, 0x0 },
	{ 0x120a6, 0x0 },
	{ 0x120a7, 0x0 },
	{ 0x130a0, 0x0 },
	{ 0x130a1, 0x0 },
	{ 0x130a2, 0x0 },
	{ 0x130a3, 0x0 },
	{ 0x130a4, 0x0 },
	{ 0x130a5, 0x0 },
	{ 0x130a6, 0x0 },
	{ 0x130a7, 0x0 },
	{ 0x2007c, 0x0 },
	{ 0x12007c, 0x0 },
	{ 0x22007c, 0x0 },
	{ 0x2007d, 0x0 },
	{ 0x12007d, 0x0 },
	{ 0x22007d, 0x0 },
	{ 0x400fd, 0x0 },
	{ 0x400c0, 0x0 },
	{ 0x90201, 0x0 },
	{ 0x190201, 0x0 },
	{ 0x290201, 0x0 },
	{ 0x90202, 0x0 },
	{ 0x190202, 0x0 },
	{ 0x290202, 0x0 },
	{ 0x90203, 0x0 },
	{ 0x190203, 0x0 },
	{ 0x290203, 0x0 },
	{ 0x90204, 0x0 },
	{ 0x190204, 0x0 },
	{ 0x290204, 0x0 },
	{ 0x90205, 0x0 },
	{ 0x190205, 0x0 },
	{ 0x290205, 0x0 },
	{ 0x90206, 0x0 },
	{ 0x190206, 0x0 },
	{ 0x290206, 0x0 },
	{ 0x90207, 0x0 },
	{ 0x190207, 0x0 },
	{ 0x290207, 0x0 },
	{ 0x90208, 0x0 },
	{ 0x190208, 0x0 },
	{ 0x290208, 0x0 },
	{ 0x10062, 0x0 },
	{ 0x10162, 0x0 },
	{ 0x10262, 0x0 },
	{ 0x10362, 0x0 },
	{ 0x10462, 0x0 },
	{ 0x10562, 0x0 },
	{ 0x10662, 0x0 },
	{ 0x10762, 0x0 },
	{ 0x10862, 0x0 },
	{ 0x11062, 0x0 },
	{ 0x11162, 0x0 },
	{ 0x11262, 0x0 },
	{ 0x11362, 0x0 },
	{ 0x11462, 0x0 },
	{ 0x11562, 0x0 },
	{ 0x11662, 0x0 },
	{ 0x11762, 0x0 },
	{ 0x11862, 0x0 },
	{ 0x12062, 0x0 },
	{ 0x12162, 0x0 },
	{ 0x12262, 0x0 },
	{ 0x12362, 0x0 },
	{ 0x12462, 0x0 },
	{ 0x12562, 0x0 },
	{ 0x12662, 0x0 },
	{ 0x12762, 0x0 },
	{ 0x12862, 0x0 },
	{ 0x13062, 0x0 },
	{ 0x13162, 0x0 },
	{ 0x13262, 0x0 },
	{ 0x13362, 0x0 },
	{ 0x13462, 0x0 },
	{ 0x13562, 0x0 },
	{ 0x13662, 0x0 },
	{ 0x13762, 0x0 },
	{ 0x13862, 0x0 },
	{ 0x20077, 0x0 },
	{ 0x10001, 0x0 },
	{ 0x11001, 0x0 },
	{ 0x12001, 0x0 },
	{ 0x13001, 0x0 },
	{ 0x10040, 0x0 },
	{ 0x10140, 0x0 },
	{ 0x10240, 0x0 },
	{ 0x10340, 0x0 },
	{ 0x10440, 0x0 },
	{ 0x10540, 0x0 },
	{ 0x10640, 0x0 },
	{ 0x10740, 0x0 },
	{ 0x10840, 0x0 },
	{ 0x10030, 0x0 },
	{ 0x10130, 0x0 },
	{ 0x10230, 0x0 },
	{ 0x10330, 0x0 },
	{ 0x10430, 0x0 },
	{ 0x10530, 0x0 },
	{ 0x10630, 0x0 },
	{ 0x10730, 0x0 },
	{ 0x10830, 0x0 },
	{ 0x11040, 0x0 },
	{ 0x11140, 0x0 },
	{ 0x11240, 0x0 },
	{ 0x11340, 0x0 },
	{ 0x11440, 0x0 },
	{ 0x11540, 0x0 },
	{ 0x11640, 0x0 },
	{ 0x11740, 0x0 },
	{ 0x11840, 0x0 },
	{ 0x11030, 0x0 },
	{ 0x11130, 0x0 },
	{ 0x11230, 0x0 },
	{ 0x11330, 0x0 },
	{ 0x11430, 0x0 },
	{ 0x11530, 0x0 },
	{ 0x11630, 0x0 },
	{ 0x11730, 0x0 },
	{ 0x11830, 0x0 },
	{ 0x12040, 0x0 },
	{ 0x12140, 0x0 },
	{ 0x12240, 0x0 },
	{ 0x12340, 0x0 },
	{ 0x12440, 0x0 },
	{ 0x12540, 0x0 },
	{ 0x12640, 0x0 },
	{ 0x12740, 0x0 },
	{ 0x12840, 0x0 },
	{ 0x12030, 0x0 },
	{ 0x12130, 0x0 },
	{ 0x12230, 0x0 },
	{ 0x12330, 0x0 },
	{ 0x12430, 0x0 },
	{ 0x12530, 0x0 },
	{ 0x12630, 0x0 },
	{ 0x12730, 0x0 },
	{ 0x12830, 0x0 },
	{ 0x13040, 0x0 },
	{ 0x13140, 0x0 },
	{ 0x13240, 0x0 },
	{ 0x13340, 0x0 },
	{ 0x13440, 0x0 },
	{ 0x13540, 0x0 },
	{ 0x13640, 0x0 },
	{ 0x13740, 0x0 },
	{ 0x13840, 0x0 },
	{ 0x13030, 0x0 },
	{ 0x13130, 0x0 },
	{ 0x13230, 0x0 },
	{ 0x13330, 0x0 },
	{ 0x13430, 0x0 },
	{ 0x13530, 0x0 },
	{ 0x13630, 0x0 },
	{ 0x13730, 0x0 },
	{ 0x13830, 0x0 },
};

/* P0 message block paremeter for training firmware */
struct dram_cfg_param ddr_fsp0_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54003, 0xfa0 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x14 },
	{ 0x54008, 0x131f },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x5400f, 0x100 },
	{ 0x54012, 0x310 },
	{ 0x54019, 0x3ff4 },
	{ 0x5401a, 0x33 },
	{ 0x5401b, 0x4866 },
	{ 0x5401c, 0x4800 },
	{ 0x5401e, 0x16 },
	{ 0x5401f, 0x3ff4 },
	{ 0x54020, 0x33 },
	{ 0x54021, 0x4866 },
	{ 0x54022, 0x4800 },
	{ 0x54024, 0x16 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x3 },
	{ 0x54032, 0xf400 },
	{ 0x54033, 0x333f },
	{ 0x54034, 0x6600 },
	{ 0x54035, 0x48 },
	{ 0x54036, 0x48 },
	{ 0x54037, 0x1600 },
	{ 0x54038, 0xf400 },
	{ 0x54039, 0x333f },
	{ 0x5403a, 0x6600 },
	{ 0x5403b, 0x48 },
	{ 0x5403c, 0x48 },
	{ 0x5403d, 0x1600 },
	{ 0xd0000, 0x1 },
};

/* P1 message block paremeter for training firmware */
struct dram_cfg_param ddr_fsp1_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54002, 0x101 },
	{ 0x54003, 0x190 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x14 },
	{ 0x54008, 0x121f },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x5400f, 0x100 },
	{ 0x54012, 0x310 },
	{ 0x54019, 0x84 },
	{ 0x5401a, 0x33 },
	{ 0x5401b, 0x4846 },
	{ 0x5401c, 0x4800 },
	{ 0x5401e, 0x15 },
	{ 0x5401f, 0x84 },
	{ 0x54020, 0x33 },
	{ 0x54021, 0x4846 },
	{ 0x54022, 0x4800 },
	{ 0x54024, 0x15 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x3 },
	{ 0x54032, 0x8400 },
	{ 0x54033, 0x3300 },
	{ 0x54034, 0x4600 },
	{ 0x54035, 0x48 },
	{ 0x54036, 0x48 },
	{ 0x54037, 0x1500 },
	{ 0x54038, 0x8400 },
	{ 0x54039, 0x3300 },
	{ 0x5403a, 0x4600 },
	{ 0x5403b, 0x48 },
	{ 0x5403c, 0x48 },
	{ 0x5403d, 0x1500 },
	{ 0xd0000, 0x1 },
};

/* P2 message block paremeter for training firmware */
struct dram_cfg_param ddr_fsp2_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54002, 0x102 },
	{ 0x54003, 0x64 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x14 },
	{ 0x54008, 0x121f },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x5400f, 0x100 },
	{ 0x54012, 0x310 },
	{ 0x54019, 0x84 },
	{ 0x5401a, 0x33 },
	{ 0x5401b, 0x4846 },
	{ 0x5401c, 0x4800 },
	{ 0x5401e, 0x15 },
	{ 0x5401f, 0x84 },
	{ 0x54020, 0x33 },
	{ 0x54021, 0x4846 },
	{ 0x54022, 0x4800 },
	{ 0x54024, 0x15 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x3 },
	{ 0x54032, 0x8400 },
	{ 0x54033, 0x3300 },
	{ 0x54034, 0x4600 },
	{ 0x54035, 0x48 },
	{ 0x54036, 0x48 },
	{ 0x54037, 0x1500 },
	{ 0x54038, 0x8400 },
	{ 0x54039, 0x3300 },
	{ 0x5403a, 0x4600 },
	{ 0x5403b, 0x48 },
	{ 0x5403c, 0x48 },
	{ 0x5403d, 0x1500 },
	{ 0xd0000, 0x1 },
};

/* P0 2D message block paremeter for training firmware */
struct dram_cfg_param ddr_fsp0_2d_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54003, 0xfa0 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x14 },
	{ 0x54008, 0x61 },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x5400d, 0x100 },
	{ 0x5400f, 0x100 },
	{ 0x54010, 0x1f7f },
	{ 0x54012, 0x310 },
	{ 0x54019, 0x3ff4 },
	{ 0x5401a, 0x33 },
	{ 0x5401b, 0x4866 },
	{ 0x5401c, 0x4800 },
	{ 0x5401e, 0x16 },
	{ 0x5401f, 0x3ff4 },
	{ 0x54020, 0x33 },
	{ 0x54021, 0x4866 },
	{ 0x54022, 0x4800 },
	{ 0x54024, 0x16 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x3 },
	{ 0x54032, 0xf400 },
	{ 0x54033, 0x333f },
	{ 0x54034, 0x6600 },
	{ 0x54035, 0x48 },
	{ 0x54036, 0x48 },
	{ 0x54037, 0x1600 },
	{ 0x54038, 0xf400 },
	{ 0x54039, 0x333f },
	{ 0x5403a, 0x6600 },
	{ 0x5403b, 0x48 },
	{ 0x5403c, 0x48 },
	{ 0x5403d, 0x1600 },
	{ 0xd0000, 0x1 },
};

/* DRAM PHY init engine image */
struct dram_cfg_param ddr_phy_pie[] = {
	{ 0xd0000, 0x0 },
	{ 0x90000, 0x10 },
	{ 0x90001, 0x400 },
	{ 0x90002, 0x10e },
	{ 0x90003, 0x0 },
	{ 0x90004, 0x0 },
	{ 0x90005, 0x8 },
	{ 0x90029, 0xb },
	{ 0x9002a, 0x480 },
	{ 0x9002b, 0x109 },
	{ 0x9002c, 0x8 },
	{ 0x9002d, 0x448 },
	{ 0x9002e, 0x139 },
	{ 0x9002f, 0x8 },
	{ 0x90030, 0x478 },
	{ 0x90031, 0x109 },
	{ 0x90032, 0x0 },
	{ 0x90033, 0xe8 },
	{ 0x90034, 0x109 },
	{ 0x90035, 0x2 },
	{ 0x90036, 0x10 },
	{ 0x90037, 0x139 },
	{ 0x90038, 0xb },
	{ 0x90039, 0x7c0 },
	{ 0x9003a, 0x139 },
	{ 0x9003b, 0x44 },
	{ 0x9003c, 0x633 },
	{ 0x9003d, 0x159 },
	{ 0x9003e, 0x14f },
	{ 0x9003f, 0x630 },
	{ 0x90040, 0x159 },
	{ 0x90041, 0x47 },
	{ 0x90042, 0x633 },
	{ 0x90043, 0x149 },
	{ 0x90044, 0x4f },
	{ 0x90045, 0x633 },
	{ 0x90046, 0x179 },
	{ 0x90047, 0x8 },
	{ 0x90048, 0xe0 },
	{ 0x90049, 0x109 },
	{ 0x9004a, 0x0 },
	{ 0x9004b, 0x7c8 },
	{ 0x9004c, 0x109 },
	{ 0x9004d, 0x0 },
	{ 0x9004e, 0x1 },
	{ 0x9004f, 0x8 },
	{ 0x90050, 0x0 },
	{ 0x90051, 0x45a },
	{ 0x90052, 0x9 },
	{ 0x90053, 0x0 },
	{ 0x90054, 0x448 },
	{ 0x90055, 0x109 },
	{ 0x90056, 0x40 },
	{ 0x90057, 0x633 },
	{ 0x90058, 0x179 },
	{ 0x90059, 0x1 },
	{ 0x9005a, 0x618 },
	{ 0x9005b, 0x109 },
	{ 0x9005c, 0x40c0 },
	{ 0x9005d, 0x633 },
	{ 0x9005e, 0x149 },
	{ 0x9005f, 0x8 },
	{ 0x90060, 0x4 },
	{ 0x90061, 0x48 },
	{ 0x90062, 0x4040 },
	{ 0x90063, 0x633 },
	{ 0x90064, 0x149 },
	{ 0x90065, 0x0 },
	{ 0x90066, 0x4 },
	{ 0x90067, 0x48 },
	{ 0x90068, 0x40 },
	{ 0x90069, 0x633 },
	{ 0x9006a, 0x149 },
	{ 0x9006b, 0x10 },
	{ 0x9006c, 0x4 },
	{ 0x9006d, 0x18 },
	{ 0x9006e, 0x0 },
	{ 0x9006f, 0x4 },
	{ 0x90070, 0x78 },
	{ 0x90071, 0x549 },
	{ 0x90072, 0x633 },
	{ 0x90073, 0x159 },
	{ 0x90074, 0xd49 },
	{ 0x90075, 0x633 },
	{ 0x90076, 0x159 },
	{ 0x90077, 0x94a },
	{ 0x90078, 0x633 },
	{ 0x90079, 0x159 },
	{ 0x9007a, 0x441 },
	{ 0x9007b, 0x633 },
	{ 0x9007c, 0x149 },
	{ 0x9007d, 0x42 },
	{ 0x9007e, 0x633 },
	{ 0x9007f, 0x149 },
	{ 0x90080, 0x1 },
	{ 0x90081, 0x633 },
	{ 0x90082, 0x149 },
	{ 0x90083, 0x0 },
	{ 0x90084, 0xe0 },
	{ 0x90085, 0x109 },
	{ 0x90086, 0xa },
	{ 0x90087, 0x10 },
	{ 0x90088, 0x109 },
	{ 0x90089, 0x9 },
	{ 0x9008a, 0x3c0 },
	{ 0x9008b, 0x149 },
	{ 0x9008c, 0x9 },
	{ 0x9008d, 0x3c0 },
	{ 0x9008e, 0x159 },
	{ 0x9008f, 0x18 },
	{ 0x90090, 0x10 },
	{ 0x90091, 0x109 },
	{ 0x90092, 0x0 },
	{ 0x90093, 0x3c0 },
	{ 0x90094, 0x109 },
	{ 0x90095, 0x18 },
	{ 0x90096, 0x4 },
	{ 0x90097, 0x48 },
	{ 0x90098, 0x18 },
	{ 0x90099, 0x4 },
	{ 0x9009a, 0x58 },
	{ 0x9009b, 0xb },
	{ 0x9009c, 0x10 },
	{ 0x9009d, 0x109 },
	{ 0x9009e, 0x1 },
	{ 0x9009f, 0x10 },
	{ 0x900a0, 0x109 },
	{ 0x900a1, 0x5 },
	{ 0x900a2, 0x7c0 },
	{ 0x900a3, 0x109 },
	{ 0x40000, 0x811 },
	{ 0x40020, 0x880 },
	{ 0x40040, 0x0 },
	{ 0x40060, 0x0 },
	{ 0x40001, 0x4008 },
	{ 0x40021, 0x83 },
	{ 0x40041, 0x4f },
	{ 0x40061, 0x0 },
	{ 0x40002, 0x4040 },
	{ 0x40022, 0x83 },
	{ 0x40042, 0x51 },
	{ 0x40062, 0x0 },
	{ 0x40003, 0x811 },
	{ 0x40023, 0x880 },
	{ 0x40043, 0x0 },
	{ 0x40063, 0x0 },
	{ 0x40004, 0x720 },
	{ 0x40024, 0xf },
	{ 0x40044, 0x1740 },
	{ 0x40064, 0x0 },
	{ 0x40005, 0x16 },
	{ 0x40025, 0x83 },
	{ 0x40045, 0x4b },
	{ 0x40065, 0x0 },
	{ 0x40006, 0x716 },
	{ 0x40026, 0xf },
	{ 0x40046, 0x2001 },
	{ 0x40066, 0x0 },
	{ 0x40007, 0x716 },
	{ 0x40027, 0xf },
	{ 0x40047, 0x2800 },
	{ 0x40067, 0x0 },
	{ 0x40008, 0x716 },
	{ 0x40028, 0xf },
	{ 0x40048, 0xf00 },
	{ 0x40068, 0x0 },
	{ 0x40009, 0x720 },
	{ 0x40029, 0xf },
	{ 0x40049, 0x1400 },
	{ 0x40069, 0x0 },
	{ 0x4000a, 0xe08 },
	{ 0x4002a, 0xc15 },
	{ 0x4004a, 0x0 },
	{ 0x4006a, 0x0 },
	{ 0x4000b, 0x625 },
	{ 0x4002b, 0x15 },
	{ 0x4004b, 0x0 },
	{ 0x4006b, 0x0 },
	{ 0x4000c, 0x4028 },
	{ 0x4002c, 0x80 },
	{ 0x4004c, 0x0 },
	{ 0x4006c, 0x0 },
	{ 0x4000d, 0xe08 },
	{ 0x4002d, 0xc1a },
	{ 0x4004d, 0x0 },
	{ 0x4006d, 0x0 },
	{ 0x4000e, 0x625 },
	{ 0x4002e, 0x1a },
	{ 0x4004e, 0x0 },
	{ 0x4006e, 0x0 },
	{ 0x4000f, 0x4040 },
	{ 0x4002f, 0x80 },
	{ 0x4004f, 0x0 },
	{ 0x4006f, 0x0 },
	{ 0x40010, 0x2604 },
	{ 0x40030, 0x15 },
	{ 0x40050, 0x0 },
	{ 0x40070, 0x0 },
	{ 0x40011, 0x708 },
	{ 0x40031, 0x5 },
	{ 0x40051, 0x0 },
	{ 0x40071, 0x2002 },
	{ 0x40012, 0x8 },
	{ 0x40032, 0x80 },
	{ 0x40052, 0x0 },
	{ 0x40072, 0x0 },
	{ 0x40013, 0x2604 },
	{ 0x40033, 0x1a },
	{ 0x40053, 0x0 },
	{ 0x40073, 0x0 },
	{ 0x40014, 0x708 },
	{ 0x40034, 0xa },
	{ 0x40054, 0x0 },
	{ 0x40074, 0x2002 },
	{ 0x40015, 0x4040 },
	{ 0x40035, 0x80 },
	{ 0x40055, 0x0 },
	{ 0x40075, 0x0 },
	{ 0x40016, 0x60a },
	{ 0x40036, 0x15 },
	{ 0x40056, 0x1200 },
	{ 0x40076, 0x0 },
	{ 0x40017, 0x61a },
	{ 0x40037, 0x15 },
	{ 0x40057, 0x1300 },
	{ 0x40077, 0x0 },
	{ 0x40018, 0x60a },
	{ 0x40038, 0x1a },
	{ 0x40058, 0x1200 },
	{ 0x40078, 0x0 },
	{ 0x40019, 0x642 },
	{ 0x40039, 0x1a },
	{ 0x40059, 0x1300 },
	{ 0x40079, 0x0 },
	{ 0x4001a, 0x4808 },
	{ 0x4003a, 0x880 },
	{ 0x4005a, 0x0 },
	{ 0x4007a, 0x0 },
	{ 0x900a4, 0x0 },
	{ 0x900a5, 0x790 },
	{ 0x900a6, 0x11a },
	{ 0x900a7, 0x8 },
	{ 0x900a8, 0x7aa },
	{ 0x900a9, 0x2a },
	{ 0x900aa, 0x10 },
	{ 0x900ab, 0x7b2 },
	{ 0x900ac, 0x2a },
	{ 0x900ad, 0x0 },
	{ 0x900ae, 0x7c8 },
	{ 0x900af, 0x109 },
	{ 0x900b0, 0x10 },
	{ 0x900b1, 0x10 },
	{ 0x900b2, 0x109 },
	{ 0x900b3, 0x10 },
	{ 0x900b4, 0x2a8 },
	{ 0x900b5, 0x129 },
	{ 0x900b6, 0x8 },
	{ 0x900b7, 0x370 },
	{ 0x900b8, 0x129 },
	{ 0x900b9, 0xa },
	{ 0x900ba, 0x3c8 },
	{ 0x900bb, 0x1a9 },
	{ 0x900bc, 0xc },
	{ 0x900bd, 0x408 },
	{ 0x900be, 0x199 },
	{ 0x900bf, 0x14 },
	{ 0x900c0, 0x790 },
	{ 0x900c1, 0x11a },
	{ 0x900c2, 0x8 },
	{ 0x900c3, 0x4 },
	{ 0x900c4, 0x18 },
	{ 0x900c5, 0xe },
	{ 0x900c6, 0x408 },
	{ 0x900c7, 0x199 },
	{ 0x900c8, 0x8 },
	{ 0x900c9, 0x8568 },
	{ 0x900ca, 0x108 },
	{ 0x900cb, 0x18 },
	{ 0x900cc, 0x790 },
	{ 0x900cd, 0x16a },
	{ 0x900ce, 0x8 },
	{ 0x900cf, 0x1d8 },
	{ 0x900d0, 0x169 },
	{ 0x900d1, 0x10 },
	{ 0x900d2, 0x8558 },
	{ 0x900d3, 0x168 },
	{ 0x900d4, 0x70 },
	{ 0x900d5, 0x788 },
	{ 0x900d6, 0x16a },
	{ 0x900d7, 0x1ff8 },
	{ 0x900d8, 0x85a8 },
	{ 0x900d9, 0x1e8 },
	{ 0x900da, 0x50 },
	{ 0x900db, 0x798 },
	{ 0x900dc, 0x16a },
	{ 0x900dd, 0x60 },
	{ 0x900de, 0x7a0 },
	{ 0x900df, 0x16a },
	{ 0x900e0, 0x8 },
	{ 0x900e1, 0x8310 },
	{ 0x900e2, 0x168 },
	{ 0x900e3, 0x8 },
	{ 0x900e4, 0xa310 },
	{ 0x900e5, 0x168 },
	{ 0x900e6, 0xa },
	{ 0x900e7, 0x408 },
	{ 0x900e8, 0x169 },
	{ 0x900e9, 0x6e },
	{ 0x900ea, 0x0 },
	{ 0x900eb, 0x68 },
	{ 0x900ec, 0x0 },
	{ 0x900ed, 0x408 },
	{ 0x900ee, 0x169 },
	{ 0x900ef, 0x0 },
	{ 0x900f0, 0x8310 },
	{ 0x900f1, 0x168 },
	{ 0x900f2, 0x0 },
	{ 0x900f3, 0xa310 },
	{ 0x900f4, 0x168 },
	{ 0x900f5, 0x1ff8 },
	{ 0x900f6, 0x85a8 },
	{ 0x900f7, 0x1e8 },
	{ 0x900f8, 0x68 },
	{ 0x900f9, 0x798 },
	{ 0x900fa, 0x16a },
	{ 0x900fb, 0x78 },
	{ 0x900fc, 0x7a0 },
	{ 0x900fd, 0x16a },
	{ 0x900fe, 0x68 },
	{ 0x900ff, 0x790 },
	{ 0x90100, 0x16a },
	{ 0x90101, 0x8 },
	{ 0x90102, 0x8b10 },
	{ 0x90103, 0x168 },
	{ 0x90104, 0x8 },
	{ 0x90105, 0xab10 },
	{ 0x90106, 0x168 },
	{ 0x90107, 0xa },
	{ 0x90108, 0x408 },
	{ 0x90109, 0x169 },
	{ 0x9010a, 0x58 },
	{ 0x9010b, 0x0 },
	{ 0x9010c, 0x68 },
	{ 0x9010d, 0x0 },
	{ 0x9010e, 0x408 },
	{ 0x9010f, 0x169 },
	{ 0x90110, 0x0 },
	{ 0x90111, 0x8b10 },
	{ 0x90112, 0x168 },
	{ 0x90113, 0x1 },
	{ 0x90114, 0xab10 },
	{ 0x90115, 0x168 },
	{ 0x90116, 0x0 },
	{ 0x90117, 0x1d8 },
	{ 0x90118, 0x169 },
	{ 0x90119, 0x80 },
	{ 0x9011a, 0x790 },
	{ 0x9011b, 0x16a },
	{ 0x9011c, 0x18 },
	{ 0x9011d, 0x7aa },
	{ 0x9011e, 0x6a },
	{ 0x9011f, 0xa },
	{ 0x90120, 0x0 },
	{ 0x90121, 0x1e9 },
	{ 0x90122, 0x8 },
	{ 0x90123, 0x8080 },
	{ 0x90124, 0x108 },
	{ 0x90125, 0xf },
	{ 0x90126, 0x408 },
	{ 0x90127, 0x169 },
	{ 0x90128, 0xc },
	{ 0x90129, 0x0 },
	{ 0x9012a, 0x68 },
	{ 0x9012b, 0x9 },
	{ 0x9012c, 0x0 },
	{ 0x9012d, 0x1a9 },
	{ 0x9012e, 0x0 },
	{ 0x9012f, 0x408 },
	{ 0x90130, 0x169 },
	{ 0x90131, 0x0 },
	{ 0x90132, 0x8080 },
	{ 0x90133, 0x108 },
	{ 0x90134, 0x8 },
	{ 0x90135, 0x7aa },
	{ 0x90136, 0x6a },
	{ 0x90137, 0x0 },
	{ 0x90138, 0x8568 },
	{ 0x90139, 0x108 },
	{ 0x9013a, 0xb7 },
	{ 0x9013b, 0x790 },
	{ 0x9013c, 0x16a },
	{ 0x9013d, 0x1f },
	{ 0x9013e, 0x0 },
	{ 0x9013f, 0x68 },
	{ 0x90140, 0x8 },
	{ 0x90141, 0x8558 },
	{ 0x90142, 0x168 },
	{ 0x90143, 0xf },
	{ 0x90144, 0x408 },
	{ 0x90145, 0x169 },
	{ 0x90146, 0xd },
	{ 0x90147, 0x0 },
	{ 0x90148, 0x68 },
	{ 0x90149, 0x0 },
	{ 0x9014a, 0x408 },
	{ 0x9014b, 0x169 },
	{ 0x9014c, 0x0 },
	{ 0x9014d, 0x8558 },
	{ 0x9014e, 0x168 },
	{ 0x9014f, 0x8 },
	{ 0x90150, 0x3c8 },
	{ 0x90151, 0x1a9 },
	{ 0x90152, 0x3 },
	{ 0x90153, 0x370 },
	{ 0x90154, 0x129 },
	{ 0x90155, 0x20 },
	{ 0x90156, 0x2aa },
	{ 0x90157, 0x9 },
	{ 0x90158, 0x0 },
	{ 0x90159, 0x400 },
	{ 0x9015a, 0x10e },
	{ 0x9015b, 0x8 },
	{ 0x9015c, 0xe8 },
	{ 0x9015d, 0x109 },
	{ 0x9015e, 0x0 },
	{ 0x9015f, 0x8140 },
	{ 0x90160, 0x10c },
	{ 0x90161, 0x10 },
	{ 0x90162, 0x8138 },
	{ 0x90163, 0x10c },
	{ 0x90164, 0x8 },
	{ 0x90165, 0x7c8 },
	{ 0x90166, 0x101 },
	{ 0x90167, 0x8 },
	{ 0x90168, 0x448 },
	{ 0x90169, 0x109 },
	{ 0x9016a, 0xf },
	{ 0x9016b, 0x7c0 },
	{ 0x9016c, 0x109 },
	{ 0x9016d, 0x0 },
	{ 0x9016e, 0xe8 },
	{ 0x9016f, 0x109 },
	{ 0x90170, 0x47 },
	{ 0x90171, 0x630 },
	{ 0x90172, 0x109 },
	{ 0x90173, 0x8 },
	{ 0x90174, 0x618 },
	{ 0x90175, 0x109 },
	{ 0x90176, 0x8 },
	{ 0x90177, 0xe0 },
	{ 0x90178, 0x109 },
	{ 0x90179, 0x0 },
	{ 0x9017a, 0x7c8 },
	{ 0x9017b, 0x109 },
	{ 0x9017c, 0x8 },
	{ 0x9017d, 0x8140 },
	{ 0x9017e, 0x10c },
	{ 0x9017f, 0x0 },
	{ 0x90180, 0x478 },
	{ 0x90181, 0x109 },
	{ 0x90182, 0x0 },
	{ 0x90183, 0x1 },
	{ 0x90184, 0x8 },
	{ 0x90185, 0x8 },
	{ 0x90186, 0x4 },
	{ 0x90187, 0x8 },
	{ 0x90188, 0x8 },
	{ 0x90189, 0x7c8 },
	{ 0x9018a, 0x101 },
	{ 0x90006, 0x0 },
	{ 0x90007, 0x0 },
	{ 0x90008, 0x8 },
	{ 0x90009, 0x0 },
	{ 0x9000a, 0x0 },
	{ 0x9000b, 0x0 },
	{ 0xd00e7, 0x400 },
	{ 0x90017, 0x0 },
	{ 0x9001f, 0x29 },
	{ 0x90026, 0x6a },
	{ 0x400d0, 0x0 },
	{ 0x400d1, 0x101 },
	{ 0x400d2, 0x105 },
	{ 0x400d3, 0x107 },
	{ 0x400d4, 0x10f },
	{ 0x400d5, 0x202 },
	{ 0x400d6, 0x20a },
	{ 0x400d7, 0x20b },
	{ 0x2003a, 0x2 },
	{ 0x2000b, 0x7d },
	{ 0x2000c, 0xfa },
	{ 0x2000d, 0x9c4 },
	{ 0x2000e, 0x2c },
	{ 0x12000b, 0xc },
	{ 0x12000c, 0x19 },
	{ 0x12000d, 0xfa },
	{ 0x12000e, 0x10 },
	{ 0x22000b, 0x3 },
	{ 0x22000c, 0x6 },
	{ 0x22000d, 0x3e },
	{ 0x22000e, 0x10 },
	{ 0x9000c, 0x0 },
	{ 0x9000d, 0x173 },
	{ 0x9000e, 0x60 },
	{ 0x9000f, 0x6110 },
	{ 0x90010, 0x2152 },
	{ 0x90011, 0xdfbd },
	{ 0x90012, 0x2060 },
	{ 0x90013, 0x6152 },
	{ 0x20010, 0x5a },
	{ 0x20011, 0x3 },
	{ 0x40080, 0xe0 },
	{ 0x40081, 0x12 },
	{ 0x40082, 0xe0 },
	{ 0x40083, 0x12 },
	{ 0x40084, 0xe0 },
	{ 0x40085, 0x12 },
	{ 0x140080, 0xe0 },
	{ 0x140081, 0x12 },
	{ 0x140082, 0xe0 },
	{ 0x140083, 0x12 },
	{ 0x140084, 0xe0 },
	{ 0x140085, 0x12 },
	{ 0x240080, 0xe0 },
	{ 0x240081, 0x12 },
	{ 0x240082, 0xe0 },
	{ 0x240083, 0x12 },
	{ 0x240084, 0xe0 },
	{ 0x240085, 0x12 },
	{ 0x400fd, 0xf },
	{ 0x10011, 0x1 },
	{ 0x10012, 0x1 },
	{ 0x10013, 0x180 },
	{ 0x10018, 0x1 },
	{ 0x10002, 0x6209 },
	{ 0x100b2, 0x1 },
	{ 0x101b4, 0x1 },
	{ 0x102b4, 0x1 },
	{ 0x103b4, 0x1 },
	{ 0x104b4, 0x1 },
	{ 0x105b4, 0x1 },
	{ 0x106b4, 0x1 },
	{ 0x107b4, 0x1 },
	{ 0x108b4, 0x1 },
	{ 0x11011, 0x1 },
	{ 0x11012, 0x1 },
	{ 0x11013, 0x180 },
	{ 0x11018, 0x1 },
	{ 0x11002, 0x6209 },
	{ 0x110b2, 0x1 },
	{ 0x111b4, 0x1 },
	{ 0x112b4, 0x1 },
	{ 0x113b4, 0x1 },
	{ 0x114b4, 0x1 },
	{ 0x115b4, 0x1 },
	{ 0x116b4, 0x1 },
	{ 0x117b4, 0x1 },
	{ 0x118b4, 0x1 },
	{ 0x12011, 0x1 },
	{ 0x12012, 0x1 },
	{ 0x12013, 0x180 },
	{ 0x12018, 0x1 },
	{ 0x12002, 0x6209 },
	{ 0x120b2, 0x1 },
	{ 0x121b4, 0x1 },
	{ 0x122b4, 0x1 },
	{ 0x123b4, 0x1 },
	{ 0x124b4, 0x1 },
	{ 0x125b4, 0x1 },
	{ 0x126b4, 0x1 },
	{ 0x127b4, 0x1 },
	{ 0x128b4, 0x1 },
	{ 0x13011, 0x1 },
	{ 0x13012, 0x1 },
	{ 0x13013, 0x180 },
	{ 0x13018, 0x1 },
	{ 0x13002, 0x6209 },
	{ 0x130b2, 0x1 },
	{ 0x131b4, 0x1 },
	{ 0x132b4, 0x1 },
	{ 0x133b4, 0x1 },
	{ 0x134b4, 0x1 },
	{ 0x135b4, 0x1 },
	{ 0x136b4, 0x1 },
	{ 0x137b4, 0x1 },
	{ 0x138b4, 0x1 },
	{ 0x20089, 0x1 },
	{ 0x20088, 0x19 },
	{ 0xc0080, 0x2 },
	{ 0xd0000, 0x1 }
};

struct dram_fsp_msg ddr_dram_fsp_msg[] = {
	{
		/* P0 4000mts 1D */
		.drate = 4000,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp0_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp0_cfg),
	},
	{
		/* P1 400mts 1D */
		.drate = 400,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp1_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp1_cfg),
	},
	{
		/* P2 100mts 1D */
		.drate = 100,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp2_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp2_cfg),
	},
	{
		/* P0 4000mts 2D */
		.drate = 4000,
		.fw_type = FW_2D_IMAGE,
		.fsp_cfg = ddr_fsp0_2d_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp0_2d_cfg),
	},
};

/* ddr timing config params */
struct dram_timing_info dram_timing = {
	.ddrc_cfg = ddr_ddrc_cfg,
	.ddrc_cfg_num = ARRAY_SIZE(ddr_ddrc_cfg),
	.ddrphy_cfg = ddr_ddrphy_cfg,
	.ddrphy_cfg_num = ARRAY_SIZE(ddr_ddrphy_cfg),
	.fsp_msg = ddr_dram_fsp_msg,
	.fsp_msg_num = ARRAY_SIZE(ddr_dram_fsp_msg),
	.ddrphy_trained_csr = ddr_ddrphy_trained_csr,
	.ddrphy_trained_csr_num = ARRAY_SIZE(ddr_ddrphy_trained_csr),
	.ddrphy_pie = ddr_phy_pie,
	.ddrphy_pie_num = ARRAY_SIZE(ddr_phy_pie),
	.fsp_table = { 4000, 400, 100, },
};
