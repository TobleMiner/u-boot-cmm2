/*
 * Copyright 2015 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __FSL_SERDES_H__
#define __FSL_SERDES_H__

#include <config.h>

#ifdef CONFIG_LS2080A
enum srds_prtcl {
	/*
	 * Nobody will check whether the device 'NONE' has been configured,
	 * So use it to indicate if the serdes_prtcl_map has been initialized.
	 */
	NONE = 0,
	PCIE1,
	PCIE2,
	PCIE3,
	PCIE4,
	SATA1,
	SATA2,
	XAUI1,
	XAUI2,
	XFI1,
	XFI2,
	XFI3,
	XFI4,
	XFI5,
	XFI6,
	XFI7,
	XFI8,
	SGMII1,
	SGMII2,
	SGMII3,
	SGMII4,
	SGMII5,
	SGMII6,
	SGMII7,
	SGMII8,
	SGMII9,
	SGMII10,
	SGMII11,
	SGMII12,
	SGMII13,
	SGMII14,
	SGMII15,
	SGMII16,
	QSGMII_A, /* A indicates MACs 1-4 */
	QSGMII_B, /* B indicates MACs 5-8 */
	QSGMII_C, /* C indicates MACs 9-12 */
	QSGMII_D, /* D indicates MACs 12-16 */
	SERDES_PRCTL_COUNT
};

enum srds {
	FSL_SRDS_1  = 0,
	FSL_SRDS_2  = 1,
};
#elif defined(CONFIG_FSL_LSCH2)
enum srds_prtcl {
	/*
	 * Nobody will check whether the device 'NONE' has been configured,
	 * So use it to indicate if the serdes_prtcl_map has been initialized.
	 */
	NONE = 0,
	PCIE1,
	PCIE2,
	PCIE3,
	PCIE4,
	SATA1,
	SATA2,
	SRIO1,
	SRIO2,
	SGMII_FM1_DTSEC1,
	SGMII_FM1_DTSEC2,
	SGMII_FM1_DTSEC3,
	SGMII_FM1_DTSEC4,
	SGMII_FM1_DTSEC5,
	SGMII_FM1_DTSEC6,
	SGMII_FM1_DTSEC9,
	SGMII_FM1_DTSEC10,
	SGMII_FM2_DTSEC1,
	SGMII_FM2_DTSEC2,
	SGMII_FM2_DTSEC3,
	SGMII_FM2_DTSEC4,
	SGMII_FM2_DTSEC5,
	SGMII_FM2_DTSEC6,
	SGMII_FM2_DTSEC9,
	SGMII_FM2_DTSEC10,
	SGMII_TSEC1,
	SGMII_TSEC2,
	SGMII_TSEC3,
	SGMII_TSEC4,
	XAUI_FM1,
	XAUI_FM2,
	AURORA,
	CPRI1,
	CPRI2,
	CPRI3,
	CPRI4,
	CPRI5,
	CPRI6,
	CPRI7,
	CPRI8,
	XAUI_FM1_MAC9,
	XAUI_FM1_MAC10,
	XAUI_FM2_MAC9,
	XAUI_FM2_MAC10,
	HIGIG_FM1_MAC9,
	HIGIG_FM1_MAC10,
	HIGIG_FM2_MAC9,
	HIGIG_FM2_MAC10,
	QSGMII_FM1_A,		/* A indicates MACs 1,2,5,6 */
	QSGMII_FM1_B,		/* B indicates MACs 5,6,9,10 */
	QSGMII_FM2_A,
	QSGMII_FM2_B,
	XFI_FM1_MAC1,
	XFI_FM1_MAC2,
	XFI_FM1_MAC9,
	XFI_FM1_MAC10,
	XFI_FM2_MAC9,
	XFI_FM2_MAC10,
	INTERLAKEN,
	QSGMII_SW1_A,		/* Indicates ports on L2 Switch */
	QSGMII_SW1_B,
	SGMII_2500_FM1_DTSEC1,
	SGMII_2500_FM1_DTSEC2,
	SGMII_2500_FM1_DTSEC3,
	SGMII_2500_FM1_DTSEC4,
	SGMII_2500_FM1_DTSEC5,
	SGMII_2500_FM1_DTSEC6,
	SGMII_2500_FM1_DTSEC9,
	SGMII_2500_FM1_DTSEC10,
	SGMII_2500_FM2_DTSEC1,
	SGMII_2500_FM2_DTSEC2,
	SGMII_2500_FM2_DTSEC3,
	SGMII_2500_FM2_DTSEC4,
	SGMII_2500_FM2_DTSEC5,
	SGMII_2500_FM2_DTSEC6,
	SGMII_2500_FM2_DTSEC9,
	SGMII_2500_FM2_DTSEC10,
	TX_CLK,
	SERDES_PRCTL_COUNT
};

enum srds {
	FSL_SRDS_1  = 0,
	FSL_SRDS_2  = 1,
};

#endif

int is_serdes_configured(enum srds_prtcl device);
void fsl_serdes_init(void);
int serdes_get_first_lane(u32 sd, enum srds_prtcl device);
enum srds_prtcl serdes_get_prtcl(int serdes, int cfg, int lane);
int is_serdes_prtcl_valid(int serdes, u32 prtcl);

#ifdef CONFIG_FSL_LSCH2
const char *serdes_clock_to_string(u32 clock);
int get_serdes_protocol(void);
#ifdef CONFIG_SYS_HAS_SERDES
/* Get the volt of SVDD in unit mV */
int get_serdes_volt(void);
/* Set the volt of SVDD in unit mV */
int set_serdes_volt(int svdd);
/* The target volt of SVDD in unit mV */
int setup_serdes_volt(u32 svdd);
#endif
#endif

#endif /* __FSL_SERDES_H__ */
