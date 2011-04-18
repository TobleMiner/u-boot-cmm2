/*
 * Copyright 2011 Freescale Semiconductor, Inc.
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
 *
 */

#ifndef _ASM_MPC85xx_CONFIG_H_
#define _ASM_MPC85xx_CONFIG_H_

/* SoC specific defines for Freescale MPC85xx (PQ3) and QorIQ processors */

/* Number of TLB CAM entries we have on FSL Book-E chips */
#if defined(CONFIG_E500MC)
#define CONFIG_SYS_NUM_TLBCAMS		64
#elif defined(CONFIG_E500)
#define CONFIG_SYS_NUM_TLBCAMS		16
#endif

#if defined(CONFIG_MPC8536)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_SYS_FSL_SEC_COMPAT	2

#elif defined(CONFIG_MPC8540)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		8

#elif defined(CONFIG_MPC8541)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		8
#define CONFIG_SYS_FSL_SEC_COMPAT	2

#elif defined(CONFIG_MPC8544)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		10
#define CONFIG_SYS_FSL_SEC_COMPAT	2

#elif defined(CONFIG_MPC8548)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		10
#define CONFIG_SYS_FSL_SEC_COMPAT	2

#elif defined(CONFIG_MPC8555)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		8
#define CONFIG_SYS_FSL_SEC_COMPAT	2

#elif defined(CONFIG_MPC8560)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		8

#elif defined(CONFIG_MPC8568)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		10
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define QE_MURAM_SIZE			0x10000UL
#define MAX_QE_RISC			2
#define QE_NUM_OF_SNUM			28

#elif defined(CONFIG_MPC8569)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		10
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define QE_MURAM_SIZE			0x20000UL
#define MAX_QE_RISC			4
#define QE_NUM_OF_SNUM			46

#elif defined(CONFIG_MPC8572)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_DDR_115
#define CONFIG_SYS_FSL_ERRATUM_DDR111_DDR134

#elif defined(CONFIG_P1010)
#define CONFIG_MAX_CPUS			1
#define CONFIG_FSL_SDHC_V2_3
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_FSL_SATA_V2
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_CCSRBAR_DEFAULT	0xff700000

/* P1011 is single core version of P1020 */
#elif defined(CONFIG_P1011)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

/* P1012 is single core version of P1021 */
#elif defined(CONFIG_P1012)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define QE_MURAM_SIZE			0x6000UL
#define MAX_QE_RISC			1
#define QE_NUM_OF_SNUM			28

/* P1013 is single core version of P1022 */
#elif defined(CONFIG_P1013)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_FSL_SATA_ERRATUM_A001

#elif defined(CONFIG_P1014)
#define CONFIG_MAX_CPUS			1
#define CONFIG_FSL_SDHC_V2_3
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_FSL_SATA_V2
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_CCSRBAR_DEFAULT	0xff700000

/* P1015 is single core version of P1024 */
#elif defined(CONFIG_P1015)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

/* P1016 is single core version of P1025 */
#elif defined(CONFIG_P1016)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define QE_MURAM_SIZE			0x6000UL
#define MAX_QE_RISC			1
#define QE_NUM_OF_SNUM			28

/* P1017 is single core version of P1023 */
#elif defined(CONFIG_P1017)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		1
#define CONFIG_SYS_NUM_FM1_DTSEC	2
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_QMAN_NUM_PORTALS	3
#define CONFIG_SYS_BMAN_NUM_PORTALS	3
#define CONFIG_SYS_FM_MURAM_SIZE	0x10000

#elif defined(CONFIG_P1020)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

#elif defined(CONFIG_P1021)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define QE_MURAM_SIZE			0x6000UL
#define MAX_QE_RISC			1
#define QE_NUM_OF_SNUM			28

#elif defined(CONFIG_P1022)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_FSL_SATA_ERRATUM_A001

#elif defined(CONFIG_P1023)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		1
#define CONFIG_SYS_NUM_FM1_DTSEC	2
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_QMAN_NUM_PORTALS	3
#define CONFIG_SYS_BMAN_NUM_PORTALS	3
#define CONFIG_SYS_FM_MURAM_SIZE	0x10000

/* P1024 is lower end variant of P1020 */
#elif defined(CONFIG_P1024)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

/* P1025 is lower end variant of P1021 */
#elif defined(CONFIG_P1025)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_TSECV2
#define CONFIG_FSL_PCIE_DISABLE_ASPM
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define QE_MURAM_SIZE			0x6000UL
#define MAX_QE_RISC			1
#define QE_NUM_OF_SNUM			28

/* P2010 is single core version of P2020 */
#elif defined(CONFIG_P2010)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_SYS_FSL_ERRATUM_ESDHC_A001

#elif defined(CONFIG_P2020)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_LAWS		12
#define CONFIG_SYS_FSL_SEC_COMPAT	2
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_SYS_FSL_ERRATUM_ESDHC_A001

#elif defined(CONFIG_PPC_P2040)
#define CONFIG_MAX_CPUS			4
#define CONFIG_SYS_FSL_NUM_CC_PLLS	2
#define CONFIG_SYS_FSL_NUM_LAWS		32
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		1
#define CONFIG_SYS_NUM_FM1_DTSEC	5
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_FM_MURAM_SIZE	0x28000
#define CONFIG_SYS_FSL_USB1_PHY_ENABLE
#define CONFIG_SYS_FSL_USB2_PHY_ENABLE
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

#elif defined(CONFIG_PPC_P3041)
#define CONFIG_MAX_CPUS			4
#define CONFIG_SYS_FSL_NUM_CC_PLLS	2
#define CONFIG_SYS_FSL_NUM_LAWS		32
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		1
#define CONFIG_SYS_NUM_FM1_DTSEC	5
#define CONFIG_SYS_NUM_FM1_10GEC	1
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_FM_MURAM_SIZE	0x28000
#define CONFIG_SYS_FSL_USB1_PHY_ENABLE
#define CONFIG_SYS_FSL_USB2_PHY_ENABLE
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

#elif defined(CONFIG_PPC_P4040)
#define CONFIG_MAX_CPUS			4
#define CONFIG_SYS_FSL_NUM_CC_PLLS	4
#define CONFIG_SYS_FSL_NUM_LAWS		32
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_FM_MURAM_SIZE	0x28000

#elif defined(CONFIG_PPC_P4080)
#define CONFIG_MAX_CPUS			8
#define CONFIG_SYS_FSL_NUM_CC_PLLS	4
#define CONFIG_SYS_FSL_NUM_LAWS		32
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		2
#define CONFIG_SYS_NUM_FM1_DTSEC	4
#define CONFIG_SYS_NUM_FM2_DTSEC	4
#define CONFIG_SYS_NUM_FM1_10GEC	1
#define CONFIG_SYS_NUM_FM2_10GEC	1
#define CONFIG_NUM_DDR_CONTROLLERS	2
#define CONFIG_SYS_FM_MURAM_SIZE	0x28000
#define CONFIG_SYS_FSL_ERRATUM_CPC_A002
#define CONFIG_SYS_FSL_ERRATUM_CPC_A003
#define CONFIG_SYS_FSL_ERRATUM_DDR_A003
#define CONFIG_SYS_FSL_ERRATUM_ELBC_A001
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
#define CONFIG_SYS_FSL_ERRATUM_ESDHC135
#define CONFIG_SYS_FSL_ERRATUM_ESDHC136
#define CONFIG_SYS_P4080_ERRATUM_CPU22
#define CONFIG_SYS_P4080_ERRATUM_SERDES8
#define CONFIG_SYS_P4080_ERRATUM_SERDES9
#define CONFIG_SYS_P4080_ERRATUM_SERDES_A001
#define CONFIG_SYS_P4080_ERRATUM_SERDES_A005

/* P5010 is single core version of P5020 */
#elif defined(CONFIG_PPC_P5010)
#define CONFIG_MAX_CPUS			1
#define CONFIG_SYS_FSL_NUM_CC_PLLS	2
#define CONFIG_SYS_FSL_NUM_LAWS		32
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		1
#define CONFIG_SYS_NUM_FM1_DTSEC	5
#define CONFIG_SYS_NUM_FM1_10GEC	1
#define CONFIG_NUM_DDR_CONTROLLERS	1
#define CONFIG_SYS_FM_MURAM_SIZE	0x28000
#define CONFIG_SYS_FSL_USB1_PHY_ENABLE
#define CONFIG_SYS_FSL_USB2_PHY_ENABLE
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

#elif defined(CONFIG_PPC_P5020)
#define CONFIG_MAX_CPUS			2
#define CONFIG_SYS_FSL_NUM_CC_PLLS	2
#define CONFIG_SYS_FSL_NUM_LAWS		32
#define CONFIG_SYS_FSL_SEC_COMPAT	4
#define CONFIG_SYS_NUM_FMAN		1
#define CONFIG_SYS_NUM_FM1_DTSEC	5
#define CONFIG_SYS_NUM_FM1_10GEC	1
#define CONFIG_NUM_DDR_CONTROLLERS	2
#define CONFIG_SYS_FM_MURAM_SIZE	0x28000
#define CONFIG_SYS_FSL_USB1_PHY_ENABLE
#define CONFIG_SYS_FSL_USB2_PHY_ENABLE
#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

#else
#error Processor type not defined for this platform
#endif

#endif /* _ASM_MPC85xx_CONFIG_H_ */
