/*
 * Altera SoCFPGA IOCSR configuration
 *
 * SPDX-License-Identifier:	BSD-3-Clause
 */

#ifndef __SOCFPGA_IOCSR_CONFIG_H__
#define __SOCFPGA_IOCSR_CONFIG_H__

#define CONFIG_HPS_IOCSR_SCANCHAIN0_LENGTH	764
#define CONFIG_HPS_IOCSR_SCANCHAIN1_LENGTH	1719
#define CONFIG_HPS_IOCSR_SCANCHAIN2_LENGTH	955
#define CONFIG_HPS_IOCSR_SCANCHAIN3_LENGTH	16766

const unsigned long iocsr_scan_chain0_table[] = {
	0x00000000,
	0x00000000,
	0x0FF00000,
	0xC0000000,
	0x0000003F,
	0x00008000,
	0x00020080,
	0x18060000,
	0x08000000,
	0x00018020,
	0x00000000,
	0x00004000,
	0x00010040,
	0x04010000,
	0x04000000,
	0x00000010,
	0x00004010,
	0x00002000,
	0x00020000,
	0x02008000,
	0x02000000,
	0x00000008,
	0x00002008,
	0x00001000,
};

const unsigned long iocsr_scan_chain1_table[] = {
	0x00100000,
	0x10040000,
	0x100000C0,
	0x00000040,
	0x00010040,
	0x00008000,
	0x00060180,
	0x20000000,
	0x00000000,
	0x00000080,
	0x00020000,
	0x00004000,
	0x00010040,
	0x10000000,
	0x04000000,
	0x00000010,
	0x00004010,
	0x00002000,
	0x00020000,
	0x06018000,
	0x01FE0000,
	0xF8000000,
	0x00000007,
	0x00001000,
	0x00010000,
	0x04000000,
	0x00000000,
	0x00000010,
	0x00004000,
	0x00000800,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000008,
	0x00002000,
	0x00000400,
	0x00000000,
	0x00401000,
	0x00000003,
	0x00000000,
	0x00000000,
	0x00000200,
	0x00600802,
	0x00000000,
	0x80200000,
	0x80000600,
	0x00000200,
	0x00000100,
	0x00300401,
	0xC0100400,
	0x40100000,
	0x40000300,
	0x000C0100,
	0x00000080,
};

const unsigned long iocsr_scan_chain2_table[] = {
	0x300C0300,
	0x00000000,
	0x0FF00000,
	0x00000000,
	0x0C0300C0,
	0x00008000,
	0x00080000,
	0x18060000,
	0x18000000,
	0x00018060,
	0x00020000,
	0x00004000,
	0x200300C0,
	0x10000000,
	0x00000000,
	0x00000040,
	0x00010000,
	0x00002000,
	0x10018060,
	0x06018000,
	0x06000000,
	0x00010018,
	0x00006018,
	0x00001000,
	0x00010000,
	0x00000000,
	0x03000000,
	0x0000800C,
	0x00C01004,
	0x00000800,
};

const unsigned long iocsr_scan_chain3_table[] = {
	0x0C420D80,
	0x082000FF,
	0x0A804001,
	0x07900000,
	0x08020000,
	0x00100000,
	0x0A800000,
	0x07900000,
	0x08020000,
	0x00100000,
	0xC8800000,
	0x00003001,
	0x00C00722,
	0x00000000,
	0x00000021,
	0x82000004,
	0x05400000,
	0x03C80000,
	0x04010000,
	0x00080000,
	0x05400000,
	0x03C80000,
	0x05400000,
	0x03C80000,
	0xE4400000,
	0x00001800,
	0x00600391,
	0x800E4400,
	0x00000001,
	0x40000002,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x72200000,
	0x80000C00,
	0x003001C8,
	0xC0072200,
	0x1C880000,
	0x20000300,
	0x00040000,
	0x50670000,
	0x00000010,
	0x24590000,
	0x00001000,
	0xA0000034,
	0x0D000001,
	0xC0680618,
	0x45034071,
	0x0A281A01,
	0x806180D0,
	0x34071C06,
	0x01A034D0,
	0x180D0000,
	0x71C06806,
	0x01450340,
	0xD000001A,
	0x0680E380,
	0x10040000,
	0x00200000,
	0x10040000,
	0x00200000,
	0x15000000,
	0x0F200000,
	0x15000000,
	0x0F200000,
	0x01FE0000,
	0x00000000,
	0x01800E44,
	0x00391000,
	0x007F8006,
	0x00000000,
	0x0A800001,
	0x07900000,
	0x0A800000,
	0x07900000,
	0x0A800000,
	0x07900000,
	0x08020000,
	0x00100000,
	0xC8800000,
	0x00003001,
	0x00C00722,
	0x00000FF0,
	0x72200000,
	0x80000C00,
	0x05400000,
	0x02480000,
	0x04000000,
	0x00080000,
	0x05400000,
	0x03C80000,
	0x05400000,
	0x03C80000,
	0x6A1C0000,
	0x00001800,
	0x00600391,
	0x800E4400,
	0x1A870001,
	0x40000600,
	0x02A00040,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x72200000,
	0x80000C00,
	0x003001C8,
	0xC0072200,
	0x1C880000,
	0x20000300,
	0x00040000,
	0x50670000,
	0x00000010,
	0x24590000,
	0x00001000,
	0xA0000034,
	0x0D000001,
	0xC0680618,
	0x45034071,
	0x0A281A01,
	0x806180D0,
	0x34071C06,
	0x01A00040,
	0x180D0002,
	0x71C06806,
	0x01450340,
	0xD00A281A,
	0x06806180,
	0x10040000,
	0x00200000,
	0x10040000,
	0x00200000,
	0x15000000,
	0x0F200000,
	0x15000000,
	0x0F200000,
	0x01FE0000,
	0x00000000,
	0x01800E44,
	0x00391000,
	0x007F8006,
	0x00000000,
	0x99300001,
	0x34343400,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x01000000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x0002A000,
	0x0001E400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0xC880090C,
	0x00003001,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00002000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x0C864000,
	0x79E47A03,
	0xCAAAA3DD,
	0xF6D5551E,
	0x0352D348,
	0x821A0000,
	0x0000D000,
	0x030C0680,
	0xD559647A,
	0x1ECAAAA3,
	0xC8F6D965,
	0x00034AB2,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x00003FC2,
	0x00820000,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x00008000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x00020080,
	0x00000400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0x0000090C,
	0x00000010,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00015000,
	0x0000F200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00600391,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x0C864000,
	0x79E47A03,
	0x8B2CA3DD,
	0xF6D9651E,
	0x034AB2C8,
	0x821A0041,
	0x0000D000,
	0x00000680,
	0xD559647A,
	0x1E8B2CA3,
	0xC8F6D965,
	0x00034AB2,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x00008000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x0002A000,
	0x0001E400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0xC880090C,
	0x00003001,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00002000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0x8AAAA3D5,
	0xF6D9651E,
	0x034AB2C8,
	0x821A0000,
	0x0000D000,
	0x00000680,
	0xD559647A,
	0x1E8B2CA3,
	0xC8F6D965,
	0x00034AB2,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x00008000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x00020080,
	0x00000400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0x0000090C,
	0x00000010,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00400000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F1690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0x8B2CA3D5,
	0xF6D9651E,
	0x0352D348,
	0x821A0000,
	0x0000D000,
	0x00000680,
	0xD559647A,
	0x1E8B2CA3,
	0x48F6D965,
	0x000352D3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0x00489800,
	0x801A1A1A,
	0x00000200,
	0x80000004,
	0x00000200,
	0x80000004,
	0x00000200,
	0x80000004,
	0x00000200,
	0x00000004,
	0x00040000,
	0x10000000,
	0x00000000,
	0x00000040,
	0x00010000,
	0x40002000,
	0x00000100,
	0x40000002,
	0x00000100,
	0x40000002,
	0x00000100,
	0x40000002,
	0x00000100,
	0x00000002,
	0x00020000,
	0x08000000,
	0x00000000,
	0x00000020,
	0x00008000,
	0x20001000,
	0x00000080,
	0x20000001,
	0x00000080,
	0x20000001,
	0x00000080,
	0x20000001,
	0x00000080,
	0x00000001,
	0x00010000,
	0x04000000,
	0x00FF0000,
	0x00000000,
	0x00004000,
	0x00000800,
	0xC0000001,
	0x00041419,
	0x40000000,
	0x04000816,
	0x000D0000,
	0x00006800,
	0x00000340,
	0xD000001A,
	0x06800000,
	0x00340000,
	0x0001A000,
	0x00000D00,
	0x40000068,
	0x1A000003,
	0x00D00000,
	0x00068000,
	0x00003400,
	0x000001A0,
	0x00000401,
	0x00000008,
	0x00000401,
	0x00000008,
	0x00000401,
	0x00000008,
	0x00000401,
	0x80000008,
	0x0000007F,
	0x20000000,
	0x00000000,
	0xE0000080,
	0x0000001F,
	0x00004000,
};


#endif /* __SOCFPGA_IOCSR_CONFIG_H__ */
