// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2019 NXP
 */

#include <common.h>
#include <asm/arch-fsl-layerscape/immap_lsch3.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include <asm/arch-fsl-layerscape/fsl_portals.h>

struct icid_id_table icid_tbl[] = {
	SET_SDHC_ICID(1, FSL_SDMMC_STREAM_ID),
	SET_SDHC_ICID(2, FSL_SDMMC2_STREAM_ID),
	SET_USB_ICID(1, "snps,dwc3", FSL_USB1_STREAM_ID),
	SET_USB_ICID(2, "snps,dwc3", FSL_USB2_STREAM_ID),
	SET_SATA_ICID(1, "fsl,lx2160a-ahci", FSL_SATA1_STREAM_ID),
	SET_SATA_ICID(2, "fsl,lx2160a-ahci", FSL_SATA2_STREAM_ID),
	SET_SATA_ICID(3, "fsl,lx2160a-ahci", FSL_SATA3_STREAM_ID),
	SET_SATA_ICID(4, "fsl,lx2160a-ahci", FSL_SATA4_STREAM_ID),
#ifdef CONFIG_FSL_CAAM
	SET_SEC_JR_ICID_ENTRY(0, FSL_SEC_JR1_STREAM_ID),
	SET_SEC_JR_ICID_ENTRY(1, FSL_SEC_JR2_STREAM_ID),
	SET_SEC_JR_ICID_ENTRY(2, FSL_SEC_JR3_STREAM_ID),
	SET_SEC_JR_ICID_ENTRY(3, FSL_SEC_JR4_STREAM_ID),
	SET_SEC_RTIC_ICID_ENTRY(0, FSL_SEC_STREAM_ID),
	SET_SEC_RTIC_ICID_ENTRY(1, FSL_SEC_STREAM_ID),
	SET_SEC_RTIC_ICID_ENTRY(2, FSL_SEC_STREAM_ID),
	SET_SEC_RTIC_ICID_ENTRY(3, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(0, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(1, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(2, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(3, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(4, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(5, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(6, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(7, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(8, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(9, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(10, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(11, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(12, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(13, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(14, FSL_SEC_STREAM_ID),
	SET_SEC_DECO_ICID_ENTRY(15, FSL_SEC_STREAM_ID),
#endif
};

int icid_tbl_sz = ARRAY_SIZE(icid_tbl);
