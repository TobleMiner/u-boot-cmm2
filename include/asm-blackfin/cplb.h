/************************************************************************
 *
 * cplb.h
 *
 * (c) Copyright 2002-2003 Analog Devices, Inc.  All rights reserved.
 *
 ************************************************************************/

/* Defines necessary for cplb initialisation routines. */
#ifndef _CPLB_H
#define _CPLB_H

#define CONFIG_BLKFIN_WT

#define CPLB_ENABLE_ICACHE_P	0
#define CPLB_ENABLE_DCACHE_P	1
#define CPLB_ENABLE_DCACHE2_P	2
#define CPLB_ENABLE_CPLBS_P	3	/* Deprecated! */
#define CPLB_ENABLE_ICPLBS_P	4
#define CPLB_ENABLE_DCPLBS_P	5

#define CPLB_ENABLE_ICACHE	(1<<CPLB_ENABLE_ICACHE_P)
#define CPLB_ENABLE_DCACHE	(1<<CPLB_ENABLE_DCACHE_P)
#define CPLB_ENABLE_DCACHE2	(1<<CPLB_ENABLE_DCACHE2_P)
#define CPLB_ENABLE_CPLBS	(1<<CPLB_ENABLE_CPLBS_P)
#define CPLB_ENABLE_ICPLBS	(1<<CPLB_ENABLE_ICPLBS_P)
#define CPLB_ENABLE_DCPLBS	(1<<CPLB_ENABLE_DCPLBS_P)
#define CPLB_ENABLE_ANY_CPLBS	CPLB_ENABLE_CPLBS | \
				CPLB_ENABLE_ICPLBS | \
				CPLB_ENABLE_DCPLBS

#define CPLB_RELOADED		0x0000
#define CPLB_NO_UNLOCKED	0x0001
#define CPLB_NO_ADDR_MATCH	0x0002
#define CPLB_PROT_VIOL		0x0003

#define CPLB_DEF_CACHE		CPLB_L1_CHBL | CPLB_WT
#define CPLB_CACHE_ENABLED	CPLB_L1_CHBL | CPLB_DIRTY

#define CPLB_ALL_ACCESS	CPLB_SUPV_WR | CPLB_USER_RD | CPLB_USER_WR

#define CPLB_I_PAGE_MGMT	CPLB_LOCK | CPLB_VALID
#define CPLB_D_PAGE_MGMT	CPLB_LOCK | CPLB_ALL_ACCESS | CPLB_VALID
#define CPLB_DNOCACHE		CPLB_ALL_ACCESS | CPLB_VALID
#define CPLB_DDOCACHE		CPLB_DNOCACHE | CPLB_DEF_CACHE
#define CPLB_INOCACHE   	CPLB_USER_RD | CPLB_VALID
#define CPLB_IDOCACHE   	CPLB_INOCACHE | CPLB_L1_CHBL

/* Data Attibutes*/

#define SDRAM_IGENERIC          (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_USER_RD | CPLB_VALID)
#define SDRAM_IKERNEL           (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_USER_RD | CPLB_VALID | CPLB_LOCK)
#define L1_IMEMORY              (PAGE_SIZE_1MB | CPLB_L1_CHBL | CPLB_USER_RD | CPLB_VALID | CPLB_LOCK)
#define SDRAM_INON_CHBL         (PAGE_SIZE_4MB | CPLB_USER_RD | CPLB_VALID)

/*Use the menuconfig cache policy here - CONFIG_BLKFIN_WT/CONFIG_BLKFIN_WB*/

#define ANOMALY_05000158                0x200

#ifdef CONFIG_BLKFIN_WB		/*Write Back Policy */
#define SDRAM_DGENERIC          (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_DIRTY | CPLB_SUPV_WR | CPLB_USER_WR | CPLB_USER_RD | CPLB_VALID | ANOMALY_05000158)
#define SDRAM_DNON_CHBL         (PAGE_SIZE_4MB | CPLB_DIRTY | CPLB_SUPV_WR | CPLB_USER_RD | CPLB_USER_WR | CPLB_VALID | ANOMALY_05000158)
#define SDRAM_DKERNEL           (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_USER_RD | CPLB_USER_WR | CPLB_DIRTY | CPLB_SUPV_WR | CPLB_VALID | CPLB_LOCK | ANOMALY_05000158)
#define L1_DMEMORY              (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_DIRTY | CPLB_SUPV_WR | CPLB_USER_WR | CPLB_USER_RD | CPLB_VALID | ANOMALY_05000158)
#define SDRAM_EBIU              (PAGE_SIZE_4MB | CPLB_DIRTY | CPLB_USER_RD | CPLB_USER_WR | CPLB_SUPV_WR | CPLB_VALID | ANOMALY_05000158)

#else				/*Write Through */
#define SDRAM_DGENERIC          (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_WT | CPLB_L1_AOW | CPLB_SUPV_WR | CPLB_USER_RD | CPLB_USER_WR | CPLB_VALID | ANOMALY_05000158)
#define SDRAM_DNON_CHBL         (PAGE_SIZE_4MB | CPLB_WT | CPLB_L1_AOW | CPLB_SUPV_WR | CPLB_USER_WR | CPLB_USER_RD | CPLB_VALID | ANOMALY_05000158)
#define SDRAM_DKERNEL           (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_WT | CPLB_L1_AOW | CPLB_USER_RD | CPLB_SUPV_WR | CPLB_USER_WR | CPLB_VALID | CPLB_LOCK | ANOMALY_05000158)
#define L1_DMEMORY              (PAGE_SIZE_4MB | CPLB_L1_CHBL | CPLB_L1_AOW | CPLB_WT | CPLB_SUPV_WR | CPLB_USER_WR | CPLB_VALID | ANOMALY_05000158)
#define SDRAM_EBIU              (PAGE_SIZE_4MB | CPLB_WT | CPLB_L1_AOW | CPLB_USER_RD | CPLB_USER_WR | CPLB_SUPV_WR | CPLB_VALID | ANOMALY_05000158)
#endif

#if defined(CONFIG_BF561)
#define page_descriptor_table_size (CONFIG_MEM_SIZE/4 + 2)	/* SDRAM +L1 + ASYNC_Memory */
#else
#define page_descriptor_table_size (CONFIG_MEM_SIZE/4 + 1 + 3)	/* SDRAM + L1 + ASYNC_Memory */
#endif
#endif				/* _CPLB_H */
