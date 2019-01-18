// SPDX-License-Identifier: GPL-2.0+
/*
 * (c) Copyright 2010-2014 Xilinx, Inc. All rights reserved.
 * (c) Copyright 2016 Topic Embedded Products.
 */

#include <asm/arch/ps7_init_gpl.h>

static unsigned long ps7_pll_init_data_3_0[] = {
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	EMIT_MASKWRITE(0XF8000110, 0x003FFFF0U, 0x000FA240U),
	EMIT_MASKWRITE(0XF8000100, 0x0007F000U, 0x00030000U),
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000010U),
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000001U),
	EMIT_MASKWRITE(0XF8000100, 0x00000001U, 0x00000000U),
	EMIT_MASKPOLL(0XF800010C, 0x00000001U),
	EMIT_MASKWRITE(0XF8000100, 0x00000010U, 0x00000000U),
	EMIT_MASKWRITE(0XF8000120, 0x1F003F30U, 0x1F000200U),
	EMIT_MASKWRITE(0XF8000114, 0x003FFFF0U, 0x0012C220U),
	EMIT_MASKWRITE(0XF8000104, 0x0007F000U, 0x00020000U),
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000010U),
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000001U),
	EMIT_MASKWRITE(0XF8000104, 0x00000001U, 0x00000000U),
	EMIT_MASKPOLL(0XF800010C, 0x00000002U),
	EMIT_MASKWRITE(0XF8000104, 0x00000010U, 0x00000000U),
	EMIT_MASKWRITE(0XF8000124, 0xFFF00003U, 0x0C200003U),
	EMIT_MASKWRITE(0XF8000118, 0x003FFFF0U, 0x00113220U),
	EMIT_MASKWRITE(0XF8000108, 0x0007F000U, 0x00024000U),
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000010U),
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000001U),
	EMIT_MASKWRITE(0XF8000108, 0x00000001U, 0x00000000U),
	EMIT_MASKPOLL(0XF800010C, 0x00000004U),
	EMIT_MASKWRITE(0XF8000108, 0x00000010U, 0x00000000U),
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	EMIT_EXIT(),
};

static unsigned long ps7_clock_init_data_3_0[] = {
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	EMIT_MASKWRITE(0XF8000128, 0x03F03F01U, 0x00302301U),
	EMIT_MASKWRITE(0XF8000138, 0x00000011U, 0x00000011U),
	EMIT_MASKWRITE(0XF800013C, 0x00000011U, 0x00000011U),
	EMIT_MASKWRITE(0XF8000140, 0x03F03F71U, 0x00100141U),
	EMIT_MASKWRITE(0XF8000144, 0x03F03F71U, 0x00100141U),
	EMIT_MASKWRITE(0XF8000148, 0x00003F31U, 0x00000C01U),
	EMIT_MASKWRITE(0XF800014C, 0x00003F31U, 0x00000601U),
	EMIT_MASKWRITE(0XF8000150, 0x00003F33U, 0x00001803U),
	EMIT_MASKWRITE(0XF8000154, 0x00003F33U, 0x00000C03U),
	EMIT_MASKWRITE(0XF8000158, 0x00003F33U, 0x00000601U),
	EMIT_MASKWRITE(0XF8000168, 0x00003F31U, 0x00000601U),
	EMIT_MASKWRITE(0XF8000170, 0x03F03F30U, 0x00100C00U),
	EMIT_MASKWRITE(0XF8000180, 0x03F03F30U, 0x00100C00U),
	EMIT_MASKWRITE(0XF8000190, 0x03F03F30U, 0x00100600U),
	EMIT_MASKWRITE(0XF80001A0, 0x03F03F30U, 0x00101800U),
	EMIT_MASKWRITE(0XF80001C4, 0x00000001U, 0x00000001U),
	EMIT_MASKWRITE(0XF800012C, 0x01FFCCCDU, 0x01FC4C4DU),
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	EMIT_EXIT(),
};

static unsigned long ps7_ddr_init_data_3_0[] = {
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000080U),
	EMIT_MASKWRITE(0XF8006004, 0x0007FFFFU, 0x00001081U),
	EMIT_MASKWRITE(0XF8006008, 0x03FFFFFFU, 0x03C0780FU),
	EMIT_MASKWRITE(0XF800600C, 0x03FFFFFFU, 0x02001001U),
	EMIT_MASKWRITE(0XF8006010, 0x03FFFFFFU, 0x00014001U),
	EMIT_MASKWRITE(0XF8006014, 0x001FFFFFU, 0x0004281AU),
	EMIT_MASKWRITE(0XF8006018, 0xF7FFFFFFU, 0x44E458D2U),
	EMIT_MASKWRITE(0XF800601C, 0xFFFFFFFFU, 0x720238E5U),
	EMIT_MASKWRITE(0XF8006020, 0x7FDFFFFCU, 0x270872D0U),
	EMIT_MASKWRITE(0XF8006024, 0x0FFFFFC3U, 0x00000000U),
	EMIT_MASKWRITE(0XF8006028, 0x00003FFFU, 0x00002007U),
	EMIT_MASKWRITE(0XF800602C, 0xFFFFFFFFU, 0x00000008U),
	EMIT_MASKWRITE(0XF8006030, 0xFFFFFFFFU, 0x00040930U),
	EMIT_MASKWRITE(0XF8006034, 0x13FF3FFFU, 0x000116D4U),
	EMIT_MASKWRITE(0XF8006038, 0x00000003U, 0x00000000U),
	EMIT_MASKWRITE(0XF800603C, 0x000FFFFFU, 0x00000777U),
	EMIT_MASKWRITE(0XF8006040, 0xFFFFFFFFU, 0xFFF00000U),
	EMIT_MASKWRITE(0XF8006044, 0x0FFFFFFFU, 0x0F666666U),
	EMIT_MASKWRITE(0XF8006048, 0x0003F03FU, 0x0003C008U),
	EMIT_MASKWRITE(0XF8006050, 0xFF0F8FFFU, 0x77010800U),
	EMIT_MASKWRITE(0XF8006058, 0x00010000U, 0x00000000U),
	EMIT_MASKWRITE(0XF800605C, 0x0000FFFFU, 0x00005003U),
	EMIT_MASKWRITE(0XF8006060, 0x000017FFU, 0x0000003EU),
	EMIT_MASKWRITE(0XF8006064, 0x00021FE0U, 0x00020000U),
	EMIT_MASKWRITE(0XF8006068, 0x03FFFFFFU, 0x00284141U),
	EMIT_MASKWRITE(0XF800606C, 0x0000FFFFU, 0x00001610U),
	EMIT_MASKWRITE(0XF8006078, 0x03FFFFFFU, 0x00466111U),
	EMIT_MASKWRITE(0XF800607C, 0x000FFFFFU, 0x00032222U),
	EMIT_MASKWRITE(0XF80060A4, 0xFFFFFFFFU, 0x10200802U),
	EMIT_MASKWRITE(0XF80060A8, 0x0FFFFFFFU, 0x0690CB73U),
	EMIT_MASKWRITE(0XF80060AC, 0x000001FFU, 0x000001FEU),
	EMIT_MASKWRITE(0XF80060B0, 0x1FFFFFFFU, 0x1CFFFFFFU),
	EMIT_MASKWRITE(0XF80060B4, 0x00000200U, 0x00000200U),
	EMIT_MASKWRITE(0XF80060B8, 0x01FFFFFFU, 0x00200066U),
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000003U),
	EMIT_MASKWRITE(0XF80060C4, 0x00000003U, 0x00000000U),
	EMIT_MASKWRITE(0XF80060C8, 0x000000FFU, 0x00000000U),
	EMIT_MASKWRITE(0XF80060DC, 0x00000001U, 0x00000000U),
	EMIT_MASKWRITE(0XF80060F0, 0x0000FFFFU, 0x00000000U),
	EMIT_MASKWRITE(0XF80060F4, 0x0000000FU, 0x00000008U),
	EMIT_MASKWRITE(0XF8006114, 0x000000FFU, 0x00000000U),
	EMIT_MASKWRITE(0XF8006118, 0x7FFFFFCFU, 0x40000001U),
	EMIT_MASKWRITE(0XF800611C, 0x7FFFFFCFU, 0x40000001U),
	EMIT_MASKWRITE(0XF8006120, 0x7FFFFFCFU, 0x40000001U),
	EMIT_MASKWRITE(0XF8006124, 0x7FFFFFCFU, 0x40000001U),
	EMIT_MASKWRITE(0XF800612C, 0x000FFFFFU, 0x00025010U),
	EMIT_MASKWRITE(0XF8006130, 0x000FFFFFU, 0x00026400U),
	EMIT_MASKWRITE(0XF8006134, 0x000FFFFFU, 0x00029418U),
	EMIT_MASKWRITE(0XF8006138, 0x000FFFFFU, 0x00027820U),
	EMIT_MASKWRITE(0XF8006140, 0x000FFFFFU, 0x00000035U),
	EMIT_MASKWRITE(0XF8006144, 0x000FFFFFU, 0x00000035U),
	EMIT_MASKWRITE(0XF8006148, 0x000FFFFFU, 0x00000035U),
	EMIT_MASKWRITE(0XF800614C, 0x000FFFFFU, 0x00000035U),
	EMIT_MASKWRITE(0XF8006154, 0x000FFFFFU, 0x00000090U),
	EMIT_MASKWRITE(0XF8006158, 0x000FFFFFU, 0x00000080U),
	EMIT_MASKWRITE(0XF800615C, 0x000FFFFFU, 0x00000098U),
	EMIT_MASKWRITE(0XF8006160, 0x000FFFFFU, 0x000000A0U),
	EMIT_MASKWRITE(0XF8006168, 0x001FFFFFU, 0x000000E9U),
	EMIT_MASKWRITE(0XF800616C, 0x001FFFFFU, 0x000000EEU),
	EMIT_MASKWRITE(0XF8006170, 0x001FFFFFU, 0x000000FAU),
	EMIT_MASKWRITE(0XF8006174, 0x001FFFFFU, 0x000000F3U),
	EMIT_MASKWRITE(0XF800617C, 0x000FFFFFU, 0x000000D0U),
	EMIT_MASKWRITE(0XF8006180, 0x000FFFFFU, 0x000000C0U),
	EMIT_MASKWRITE(0XF8006184, 0x000FFFFFU, 0x000000D8U),
	EMIT_MASKWRITE(0XF8006188, 0x000FFFFFU, 0x000000E0U),
	EMIT_MASKWRITE(0XF8006190, 0x6FFFFEFEU, 0x00040080U),
	EMIT_MASKWRITE(0XF8006194, 0x000FFFFFU, 0x0001FC82U),
	EMIT_MASKWRITE(0XF8006204, 0xFFFFFFFFU, 0x00000000U),
	EMIT_MASKWRITE(0XF8006208, 0x000703FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF800620C, 0x000703FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF8006210, 0x000703FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF8006214, 0x000703FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF8006218, 0x000F03FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF800621C, 0x000F03FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF8006220, 0x000F03FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF8006224, 0x000F03FFU, 0x000003FFU),
	EMIT_MASKWRITE(0XF80062A8, 0x00000FF5U, 0x00000000U),
	EMIT_MASKWRITE(0XF80062AC, 0xFFFFFFFFU, 0x00000000U),
	EMIT_MASKWRITE(0XF80062B0, 0x003FFFFFU, 0x00005125U),
	EMIT_MASKWRITE(0XF80062B4, 0x0003FFFFU, 0x000012A8U),
	EMIT_MASKPOLL(0XF8000B74, 0x00002000U),
	EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU, 0x00000081U),
	EMIT_MASKPOLL(0XF8006054, 0x00000007U),
	EMIT_EXIT(),
};

static unsigned long ps7_mio_init_data_3_0[] = {
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	EMIT_MASKWRITE(0XF8000B40, 0x00000FFFU, 0x00000600U),
	EMIT_MASKWRITE(0XF8000B44, 0x00000FFFU, 0x00000600U),
	EMIT_MASKWRITE(0XF8000B48, 0x00000FFFU, 0x00000672U),
	EMIT_MASKWRITE(0XF8000B4C, 0x00000FFFU, 0x00000672U),
	EMIT_MASKWRITE(0XF8000B50, 0x00000FFFU, 0x00000674U),
	EMIT_MASKWRITE(0XF8000B54, 0x00000FFFU, 0x00000674U),
	EMIT_MASKWRITE(0XF8000B58, 0x00000FFFU, 0x00000600U),
	EMIT_MASKWRITE(0XF8000B5C, 0xFFFFFFFFU, 0x0018C61CU),
	EMIT_MASKWRITE(0XF8000B60, 0xFFFFFFFFU, 0x00F9861CU),
	EMIT_MASKWRITE(0XF8000B64, 0xFFFFFFFFU, 0x00F9861CU),
	EMIT_MASKWRITE(0XF8000B68, 0xFFFFFFFFU, 0x00F9861CU),
	EMIT_MASKWRITE(0XF8000B6C, 0x00007FFFU, 0x00000E60U),
	EMIT_MASKWRITE(0XF8000B70, 0x00000001U, 0x00000001U),
	EMIT_MASKWRITE(0XF8000B70, 0x00000021U, 0x00000020U),
	EMIT_MASKWRITE(0XF8000B70, 0x07FEFFFFU, 0x00000823U),
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	EMIT_EXIT(),
};

static unsigned long ps7_peripherals_init_data_3_0[] = {
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	EMIT_MASKWRITE(0XF8000B48, 0x00000180U, 0x00000180U),
	EMIT_MASKWRITE(0XF8000B4C, 0x00000180U, 0x00000180U),
	EMIT_MASKWRITE(0XF8000B50, 0x00000180U, 0x00000180U),
	EMIT_MASKWRITE(0XF8000B54, 0x00000180U, 0x00000180U),
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	EMIT_MASKWRITE(0XE0001034, 0x000000FFU, 0x00000006U),
	EMIT_MASKWRITE(0XE0001018, 0x0000FFFFU, 0x0000007CU),
	EMIT_MASKWRITE(0XE0001000, 0x000001FFU, 0x00000017U),
	EMIT_MASKWRITE(0XE0001004, 0x000003FFU, 0x00000020U),
	EMIT_MASKWRITE(0XE0000034, 0x000000FFU, 0x00000006U),
	EMIT_MASKWRITE(0XE0000018, 0x0000FFFFU, 0x0000007CU),
	EMIT_MASKWRITE(0XE0000000, 0x000001FFU, 0x00000017U),
	EMIT_MASKWRITE(0XE0000004, 0x000003FFU, 0x00000020U),
	EMIT_MASKWRITE(0XE000D000, 0x000800FFU, 0x000800C1U),
	EMIT_MASKWRITE(0XF8007000, 0x20000000U, 0x00000000U),
	EMIT_MASKDELAY(0XF8F00200, 1),
	EMIT_MASKWRITE(0XE000A244, 0x003FFFFFU, 0x00004000U),
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	EMIT_MASKWRITE(0XE000A248, 0x003FFFFFU, 0x00004000U),
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF0000U),
	EMIT_MASKDELAY(0XF8F00200, 1),
	EMIT_MASKWRITE(0XE000A008, 0xFFFFFFFFU, 0xBFFF4000U),
	EMIT_MASKDELAY(0XF8F00200, 1),
	EMIT_MASKDELAY(0XF8F00200, 1),
	EMIT_EXIT(),
};

static unsigned long ps7_post_config_3_0[] = {
	EMIT_MASKWRITE(0XF8000008, 0x0000FFFFU, 0x0000DF0DU),
	EMIT_MASKWRITE(0XF8000900, 0x0000000FU, 0x0000000FU),
	EMIT_MASKWRITE(0XF8000240, 0xFFFFFFFFU, 0x00000000U),
	EMIT_MASKWRITE(0XF8000004, 0x0000FFFFU, 0x0000767BU),
	EMIT_EXIT(),
};

int ps7_init(void)
{
	int ret;

	ret = ps7_config(ps7_mio_init_data_3_0);
	if (ret != PS7_INIT_SUCCESS)
		return ret;
	ret = ps7_config(ps7_pll_init_data_3_0);
	if (ret != PS7_INIT_SUCCESS)
		return ret;
	ret = ps7_config(ps7_clock_init_data_3_0);
	if (ret != PS7_INIT_SUCCESS)
		return ret;
	ret = ps7_config(ps7_ddr_init_data_3_0);
	if (ret != PS7_INIT_SUCCESS)
		return ret;
	ret = ps7_config(ps7_peripherals_init_data_3_0);
	if (ret != PS7_INIT_SUCCESS)
		return ret;

	return PS7_INIT_SUCCESS;
}

int ps7_post_config(void)
{
	return ps7_config(ps7_post_config_3_0);
}
