/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Altera SoCFPGA IOCSR configuration
 */

#ifndef __SOCFPGA_IOCSR_CONFIG_H__
#define __SOCFPGA_IOCSR_CONFIG_H__

#define CONFIG_HPS_IOCSR_SCANCHAIN0_LENGTH	1337
#define CONFIG_HPS_IOCSR_SCANCHAIN1_LENGTH	1719
#define CONFIG_HPS_IOCSR_SCANCHAIN2_LENGTH	1528
#define CONFIG_HPS_IOCSR_SCANCHAIN3_LENGTH	16766

const unsigned long iocsr_scan_chain0_table[] = {
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00008000,
	0x00060180,
	0x18060000,
	0x18000060,
	0x00018060,
	0x06018060,
	0x00004000,
	0x0C0300C0,
	0x0C030000,
	0x00000030,
	0x00000000,
	0x00000000,
	0x00002000,
	0x00000000,
	0x00000000,
	0x06000000,
	0x00006018,
	0x01806018,
	0x00001000,
	0x0000C030,
	0x04000000,
	0x03000000,
	0x0000300C,
	0x00000000,
	0x00000800,
	0x00006018,
	0x01806000,
	0x01800000,
	0x00000006,
	0x00001806,
	0x00000400,
	0x0000300C,
	0x00C03000,
	0x00C00000,
	0x00000003,
	0x00000C03,
	0x00000200,
};

const unsigned long iocsr_scan_chain1_table[] = {
	0x00100000,
	0x300C0000,
	0x300000C0,
	0x000000C0,
	0x000300C0,
	0x00008000,
	0x00060180,
	0x18060000,
	0x18000000,
	0x00000060,
	0x00018060,
	0x00004000,
	0x000300C0,
	0x10000000,
	0x0C000000,
	0x00000030,
	0x0000C030,
	0x00002000,
	0x06018060,
	0x06018000,
	0x01FE0000,
	0xF8000000,
	0x00000007,
	0x00001000,
	0x0000C030,
	0x0300C000,
	0x03000000,
	0x0000300C,
	0x0000300C,
	0x00000800,
	0x00006018,
	0x01806000,
	0x01800000,
	0x00000006,
	0x00002000,
	0x00000400,
	0x0000300C,
	0x01000000,
	0x00000000,
	0x00000004,
	0x00000C03,
	0x00000200,
	0x00001806,
	0x00800000,
	0x00000000,
	0x00000002,
	0x00000800,
	0x00000100,
	0x00001000,
	0x00400000,
	0xC0300000,
	0x00000000,
	0x00000400,
	0x00000080,
};

const unsigned long iocsr_scan_chain2_table[] = {
	0x00100000,
	0x40000000,
	0x00000000,
	0x00000100,
	0x00040000,
	0x00008000,
	0x18060180,
	0x20000000,
	0x00000000,
	0x00000080,
	0x00020000,
	0x00004000,
	0x00040000,
	0x10000000,
	0x00000000,
	0x00000000,
	0x00010000,
	0x00002000,
	0x10038060,
	0x00000000,
	0x00000000,
	0x00000020,
	0x01806018,
	0x00001000,
	0x00010000,
	0x04000000,
	0x03000000,
	0x0000801C,
	0x00004000,
	0x00000800,
	0x01806018,
	0x02000000,
	0x00000000,
	0x00000008,
	0x00002000,
	0x00000400,
	0x00C0300C,
	0x00C03000,
	0x00C00003,
	0x00000C03,
	0x00300C03,
	0x00000200,
	0x00601806,
	0x80601800,
	0x80600001,
	0x80000601,
	0x00180601,
	0x00000100,
};

const unsigned long iocsr_scan_chain3_table[] = {
	0x2C820D80,
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
	0x00000050,
	0x24590000,
	0x00001000,
	0xA0000034,
	0x0D000001,
	0x906808A2,
	0xA2834024,
	0x05141A00,
	0x808A20D0,
	0x34024906,
	0x01A00A28,
	0xA20D0000,
	0x24906808,
	0x00A28340,
	0xD000001A,
	0x06808A20,
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
	0x00000050,
	0x24590000,
	0x00001000,
	0xA0000034,
	0x0D000001,
	0x906808A2,
	0xA2834024,
	0x05141A00,
	0x808A20D0,
	0x34024906,
	0x01A00040,
	0xA20D0002,
	0x24906808,
	0x00A28340,
	0xD005141A,
	0x06808A20,
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
	0x01C3A810,
	0xAA0D4000,
	0x01C3A808,
	0xAA0D4000,
	0x01C3A810,
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
	0x00E1D404,
	0x00000000,
	0xC880090C,
	0x00003001,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA04,
	0x2A835000,
	0x0070EA02,
	0x2A835000,
	0x0070EA04,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00002000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC055F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0xBA28A3D8,
	0xF511451E,
	0x0341D348,
	0x821A0000,
	0x0000D000,
	0x04510680,
	0xD859647A,
	0x1EBA28A3,
	0x48F51145,
	0x000341D3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875011,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x00003FC2,
	0x00820000,
	0xAA0D4000,
	0x01C3A810,
	0xAA0D4000,
	0x01C3A808,
	0xAA0D4000,
	0x01C3A810,
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
	0x00E1D404,
	0x00000000,
	0x0000090C,
	0x00000010,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA04,
	0x2A835000,
	0x0070EA02,
	0x2A835000,
	0x0070EA04,
	0x00015000,
	0x0000F200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00600391,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC055F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0xBA28A3D8,
	0xF511451E,
	0x8341D348,
	0x821A0124,
	0x0000D000,
	0x00000680,
	0xD859647A,
	0x1EBA28A3,
	0x48F51145,
	0x000341D3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875011,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0xAA0D4000,
	0x01C3A810,
	0xAA0D4000,
	0x01C3A808,
	0xAA0D4000,
	0x01C3A810,
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
	0x00E1D404,
	0x00000000,
	0xC880090C,
	0x00003001,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA04,
	0x2A835000,
	0x0070EA02,
	0x2A835000,
	0x0070EA04,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00002000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC055F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0xBA28A3D8,
	0xF511451E,
	0x0341D348,
	0x821A0000,
	0x0000D000,
	0x00000680,
	0xD859647A,
	0x1EBA28A3,
	0x48F51145,
	0x000341D3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875011,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0xAA0D4000,
	0x01C3A810,
	0xAA0D4000,
	0x01C3A808,
	0xAA0D4000,
	0x01C3A810,
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
	0x00E1D404,
	0x00000000,
	0x0000090C,
	0x00000010,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA04,
	0x2A835000,
	0x0070EA02,
	0x2A835000,
	0x0070EA04,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00400000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC055F80,
	0xFFFFFFFF,
	0x14F1690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0xBA28A3D8,
	0xF511451E,
	0x0341D348,
	0x821A0000,
	0x0000D000,
	0x00000680,
	0xD859647A,
	0x1EBA28A3,
	0x48F51145,
	0x000341D3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875011,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0x00481800,
	0x001A1A1A,
	0x085506A0,
	0x0000E1D4,
	0x045506A0,
	0x0000E1D4,
	0x085506A0,
	0x8000E1D4,
	0x00000200,
	0x00000004,
	0x04000000,
	0x00000009,
	0x00002410,
	0x00000040,
	0x41000000,
	0x00002082,
	0x00000350,
	0x000000DA,
	0x00000100,
	0x40000002,
	0x00000100,
	0x00000002,
	0x022A8350,
	0x000070EA,
	0x86000000,
	0x08000004,
	0x00000000,
	0x00482000,
	0x21800000,
	0x00101061,
	0x021541A8,
	0x00003875,
	0x011541A8,
	0x00003875,
	0x021541A8,
	0x20003875,
	0x00000080,
	0x00000001,
	0x41000000,
	0x00000002,
	0x00FF0904,
	0x00000000,
	0x90400000,
	0x00000820,
	0xC0000001,
	0xFFD602AF,
	0x86FFFFFF,
	0x0A0A78B4,
	0x000D020A,
	0x00006800,
	0x028A4320,
	0xEC2CB23D,
	0x8F5D1451,
	0xA47A88A2,
	0x0001A0E9,
	0x00410D00,
	0x40000068,
	0x3D000003,
	0x51EC2CB2,
	0xA28F5D14,
	0xE9A47A88,
	0x000001A0,
	0x00000401,
	0x00000008,
	0x00000401,
	0x00000008,
	0x00000540,
	0x000003A8,
	0x08AA0D40,
	0x8001C3A8,
	0x0000007F,
	0x00000000,
	0x00004060,
	0xE1208000,
	0x0000001F,
	0x00004100,
};


#endif /* __SOCFPGA_IOCSR_CONFIG_H__ */
