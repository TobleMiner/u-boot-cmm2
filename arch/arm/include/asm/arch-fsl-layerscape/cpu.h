/*
 * Copyright 2014-2015, Freescale Semiconductor
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _FSL_LAYERSCAPE_CPU_H
#define _FSL_LAYERSCAPE_CPU_H

static struct cpu_type cpu_type_list[] = {
	CPU_TYPE_ENTRY(LS2080A, LS2080A, 8),
	CPU_TYPE_ENTRY(LS2085A, LS2085A, 8),
	CPU_TYPE_ENTRY(LS2045A, LS2045A, 4),
	CPU_TYPE_ENTRY(LS2088A, LS2088A, 8),
	CPU_TYPE_ENTRY(LS2084A, LS2084A, 8),
	CPU_TYPE_ENTRY(LS2048A, LS2048A, 4),
	CPU_TYPE_ENTRY(LS2044A, LS2044A, 4),
	CPU_TYPE_ENTRY(LS1043A, LS1043A, 4),
	CPU_TYPE_ENTRY(LS1023A, LS1023A, 2),
	CPU_TYPE_ENTRY(LS1046A, LS1046A, 4),
	CPU_TYPE_ENTRY(LS1026A, LS1026A, 2),
	CPU_TYPE_ENTRY(LS2040A, LS2040A, 4),
	CPU_TYPE_ENTRY(LS1012A, LS1012A, 1),
};

#ifndef CONFIG_SYS_DCACHE_OFF

#ifdef CONFIG_FSL_LSCH3
#define CONFIG_SYS_FSL_CCSR_BASE	0x00000000
#define CONFIG_SYS_FSL_CCSR_SIZE	0x10000000
#define CONFIG_SYS_FSL_QSPI_BASE1	0x20000000
#define CONFIG_SYS_FSL_QSPI_SIZE1	0x10000000
#define CONFIG_SYS_FSL_IFC_BASE1	0x30000000
#define CONFIG_SYS_FSL_IFC_SIZE1	0x10000000
#define CONFIG_SYS_FSL_IFC_SIZE1_1	0x400000
#define CONFIG_SYS_FSL_DRAM_BASE1	0x80000000
#define CONFIG_SYS_FSL_DRAM_SIZE1	0x80000000
#define CONFIG_SYS_FSL_QSPI_BASE2	0x400000000
#define CONFIG_SYS_FSL_QSPI_SIZE2	0x100000000
#define CONFIG_SYS_FSL_IFC_BASE2	0x500000000
#define CONFIG_SYS_FSL_IFC_SIZE2	0x100000000
#define CONFIG_SYS_FSL_DCSR_BASE	0x700000000
#define CONFIG_SYS_FSL_DCSR_SIZE	0x40000000
#define CONFIG_SYS_FSL_MC_BASE		0x80c000000
#define CONFIG_SYS_FSL_MC_SIZE		0x4000000
#define CONFIG_SYS_FSL_NI_BASE		0x810000000
#define CONFIG_SYS_FSL_NI_SIZE		0x8000000
#define CONFIG_SYS_FSL_QBMAN_BASE	0x818000000
#define CONFIG_SYS_FSL_QBMAN_SIZE	0x8000000
#define CONFIG_SYS_FSL_QBMAN_SIZE_1	0x4000000
#define CONFIG_SYS_PCIE1_PHYS_SIZE	0x200000000
#define CONFIG_SYS_PCIE2_PHYS_SIZE	0x200000000
#define CONFIG_SYS_PCIE3_PHYS_SIZE	0x200000000
#define CONFIG_SYS_PCIE4_PHYS_SIZE	0x200000000
#define CONFIG_SYS_FSL_WRIOP1_BASE	0x4300000000
#define CONFIG_SYS_FSL_WRIOP1_SIZE	0x100000000
#define CONFIG_SYS_FSL_AIOP1_BASE	0x4b00000000
#define CONFIG_SYS_FSL_AIOP1_SIZE	0x100000000
#define CONFIG_SYS_FSL_PEBUF_BASE	0x4c00000000
#define CONFIG_SYS_FSL_PEBUF_SIZE	0x400000000
#define CONFIG_SYS_FSL_DRAM_BASE2	0x8080000000
#define CONFIG_SYS_FSL_DRAM_SIZE2	0x7F80000000
#elif defined(CONFIG_FSL_LSCH2)
#define CONFIG_SYS_FSL_BOOTROM_BASE	0x0
#define CONFIG_SYS_FSL_BOOTROM_SIZE	0x1000000
#define CONFIG_SYS_FSL_CCSR_BASE	0x1000000
#define CONFIG_SYS_FSL_CCSR_SIZE	0xf000000
#define CONFIG_SYS_FSL_DCSR_BASE	0x20000000
#define CONFIG_SYS_FSL_DCSR_SIZE	0x4000000
#define CONFIG_SYS_FSL_QSPI_BASE	0x40000000
#define CONFIG_SYS_FSL_QSPI_SIZE	0x20000000
#define CONFIG_SYS_FSL_IFC_BASE		0x60000000
#define CONFIG_SYS_FSL_IFC_SIZE		0x20000000
#define CONFIG_SYS_FSL_DRAM_BASE1	0x80000000
#define CONFIG_SYS_FSL_DRAM_SIZE1	0x80000000
#define CONFIG_SYS_FSL_QBMAN_BASE	0x500000000
#define CONFIG_SYS_FSL_QBMAN_SIZE	0x10000000
#define CONFIG_SYS_FSL_DRAM_BASE2	0x880000000
#define CONFIG_SYS_FSL_DRAM_SIZE2	0x780000000	/* 30GB */
#define CONFIG_SYS_PCIE1_PHYS_SIZE	0x800000000
#define CONFIG_SYS_PCIE2_PHYS_SIZE	0x800000000
#define CONFIG_SYS_PCIE3_PHYS_SIZE	0x800000000
#define CONFIG_SYS_FSL_DRAM_BASE3	0x8800000000
#define CONFIG_SYS_FSL_DRAM_SIZE3	0x7800000000	/* 480GB */
#endif

#define EARLY_PGTABLE_SIZE 0x5000
static struct mm_region early_map[] = {
#ifdef CONFIG_FSL_LSCH3
	{ CONFIG_SYS_FSL_CCSR_BASE, CONFIG_SYS_FSL_CCSR_BASE,
	  CONFIG_SYS_FSL_CCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_OCRAM_BASE, CONFIG_SYS_FSL_OCRAM_BASE,
	  CONFIG_SYS_FSL_OCRAM_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_QSPI_BASE1, CONFIG_SYS_FSL_QSPI_BASE1,
	  CONFIG_SYS_FSL_QSPI_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE},
	/* For IFC Region #1, only the first 4MB is cache-enabled */
	{ CONFIG_SYS_FSL_IFC_BASE1, CONFIG_SYS_FSL_IFC_BASE1,
	  CONFIG_SYS_FSL_IFC_SIZE1_1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_IFC_BASE1 + CONFIG_SYS_FSL_IFC_SIZE1_1,
	  CONFIG_SYS_FSL_IFC_BASE1 + CONFIG_SYS_FSL_IFC_SIZE1_1,
	  CONFIG_SYS_FSL_IFC_SIZE1 - CONFIG_SYS_FSL_IFC_SIZE1_1,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FLASH_BASE, CONFIG_SYS_FSL_IFC_BASE1,
	  CONFIG_SYS_FSL_IFC_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DRAM_BASE1, CONFIG_SYS_FSL_DRAM_BASE1,
	  CONFIG_SYS_FSL_DRAM_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
	/* Map IFC region #2 up to CONFIG_SYS_FLASH_BASE for NAND boot */
	{ CONFIG_SYS_FSL_IFC_BASE2, CONFIG_SYS_FSL_IFC_BASE2,
	  CONFIG_SYS_FLASH_BASE - CONFIG_SYS_FSL_IFC_BASE2,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DCSR_BASE, CONFIG_SYS_FSL_DCSR_BASE,
	  CONFIG_SYS_FSL_DCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_DRAM_BASE2, CONFIG_SYS_FSL_DRAM_BASE2,
	  CONFIG_SYS_FSL_DRAM_SIZE2,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
#elif defined(CONFIG_FSL_LSCH2)
	{ CONFIG_SYS_FSL_CCSR_BASE, CONFIG_SYS_FSL_CCSR_BASE,
	  CONFIG_SYS_FSL_CCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_OCRAM_BASE, CONFIG_SYS_FSL_OCRAM_BASE,
	  CONFIG_SYS_FSL_OCRAM_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DCSR_BASE, CONFIG_SYS_FSL_DCSR_BASE,
	  CONFIG_SYS_FSL_DCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_QSPI_BASE, CONFIG_SYS_FSL_QSPI_BASE,
	  CONFIG_SYS_FSL_QSPI_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_IFC_BASE, CONFIG_SYS_FSL_IFC_BASE,
	  CONFIG_SYS_FSL_IFC_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DRAM_BASE1, CONFIG_SYS_FSL_DRAM_BASE1,
	  CONFIG_SYS_FSL_DRAM_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
	{ CONFIG_SYS_FSL_DRAM_BASE2, CONFIG_SYS_FSL_DRAM_BASE2,
	  CONFIG_SYS_FSL_DRAM_SIZE2,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
#endif
	{},	/* list terminator */
};

static struct mm_region final_map[] = {
#ifdef CONFIG_FSL_LSCH3
	{ CONFIG_SYS_FSL_CCSR_BASE, CONFIG_SYS_FSL_CCSR_BASE,
	  CONFIG_SYS_FSL_CCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_OCRAM_BASE, CONFIG_SYS_FSL_OCRAM_BASE,
	  CONFIG_SYS_FSL_OCRAM_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DRAM_BASE1, CONFIG_SYS_FSL_DRAM_BASE1,
	  CONFIG_SYS_FSL_DRAM_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
	{ CONFIG_SYS_FSL_QSPI_BASE1, CONFIG_SYS_FSL_QSPI_BASE1,
	  CONFIG_SYS_FSL_QSPI_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_QSPI_BASE2, CONFIG_SYS_FSL_QSPI_BASE2,
	  CONFIG_SYS_FSL_QSPI_SIZE2,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_IFC_BASE2, CONFIG_SYS_FSL_IFC_BASE2,
	  CONFIG_SYS_FSL_IFC_SIZE2,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DCSR_BASE, CONFIG_SYS_FSL_DCSR_BASE,
	  CONFIG_SYS_FSL_DCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_MC_BASE, CONFIG_SYS_FSL_MC_BASE,
	  CONFIG_SYS_FSL_MC_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_NI_BASE, CONFIG_SYS_FSL_NI_BASE,
	  CONFIG_SYS_FSL_NI_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	/* For QBMAN portal, only the first 64MB is cache-enabled */
	{ CONFIG_SYS_FSL_QBMAN_BASE, CONFIG_SYS_FSL_QBMAN_BASE,
	  CONFIG_SYS_FSL_QBMAN_SIZE_1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN | PTE_BLOCK_NS
	},
	{ CONFIG_SYS_FSL_QBMAN_BASE + CONFIG_SYS_FSL_QBMAN_SIZE_1,
	  CONFIG_SYS_FSL_QBMAN_BASE + CONFIG_SYS_FSL_QBMAN_SIZE_1,
	  CONFIG_SYS_FSL_QBMAN_SIZE - CONFIG_SYS_FSL_QBMAN_SIZE_1,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_PCIE1_PHYS_ADDR, CONFIG_SYS_PCIE1_PHYS_ADDR,
	  CONFIG_SYS_PCIE1_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_PCIE2_PHYS_ADDR, CONFIG_SYS_PCIE2_PHYS_ADDR,
	  CONFIG_SYS_PCIE2_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_PCIE3_PHYS_ADDR, CONFIG_SYS_PCIE3_PHYS_ADDR,
	  CONFIG_SYS_PCIE3_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
#ifdef CONFIG_LS2080A
	{ CONFIG_SYS_PCIE4_PHYS_ADDR, CONFIG_SYS_PCIE4_PHYS_ADDR,
	  CONFIG_SYS_PCIE4_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
#endif
	{ CONFIG_SYS_FSL_WRIOP1_BASE, CONFIG_SYS_FSL_WRIOP1_BASE,
	  CONFIG_SYS_FSL_WRIOP1_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_AIOP1_BASE, CONFIG_SYS_FSL_AIOP1_BASE,
	  CONFIG_SYS_FSL_AIOP1_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_PEBUF_BASE, CONFIG_SYS_FSL_PEBUF_BASE,
	  CONFIG_SYS_FSL_PEBUF_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_DRAM_BASE2, CONFIG_SYS_FSL_DRAM_BASE2,
	  CONFIG_SYS_FSL_DRAM_SIZE2,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
#elif defined(CONFIG_FSL_LSCH2)
	{ CONFIG_SYS_FSL_BOOTROM_BASE, CONFIG_SYS_FSL_BOOTROM_BASE,
	  CONFIG_SYS_FSL_BOOTROM_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_CCSR_BASE, CONFIG_SYS_FSL_CCSR_BASE,
	  CONFIG_SYS_FSL_CCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_OCRAM_BASE, CONFIG_SYS_FSL_OCRAM_BASE,
	  CONFIG_SYS_FSL_OCRAM_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DCSR_BASE, CONFIG_SYS_FSL_DCSR_BASE,
	  CONFIG_SYS_FSL_DCSR_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_QSPI_BASE, CONFIG_SYS_FSL_QSPI_BASE,
	  CONFIG_SYS_FSL_QSPI_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_IFC_BASE, CONFIG_SYS_FSL_IFC_BASE,
	  CONFIG_SYS_FSL_IFC_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE
	},
	{ CONFIG_SYS_FSL_DRAM_BASE1, CONFIG_SYS_FSL_DRAM_BASE1,
	  CONFIG_SYS_FSL_DRAM_SIZE1,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
	{ CONFIG_SYS_FSL_QBMAN_BASE, CONFIG_SYS_FSL_QBMAN_BASE,
	  CONFIG_SYS_FSL_QBMAN_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_DRAM_BASE2, CONFIG_SYS_FSL_DRAM_BASE2,
	  CONFIG_SYS_FSL_DRAM_SIZE2,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
	{ CONFIG_SYS_PCIE1_PHYS_ADDR, CONFIG_SYS_PCIE1_PHYS_ADDR,
	  CONFIG_SYS_PCIE1_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_PCIE2_PHYS_ADDR, CONFIG_SYS_PCIE2_PHYS_ADDR,
	  CONFIG_SYS_PCIE2_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_PCIE3_PHYS_ADDR, CONFIG_SYS_PCIE3_PHYS_ADDR,
	  CONFIG_SYS_PCIE3_PHYS_SIZE,
	  PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
	  PTE_BLOCK_NON_SHARE | PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},
	{ CONFIG_SYS_FSL_DRAM_BASE3, CONFIG_SYS_FSL_DRAM_BASE3,
	  CONFIG_SYS_FSL_DRAM_SIZE3,
	  PTE_BLOCK_MEMTYPE(MT_NORMAL) |
	  PTE_BLOCK_OUTER_SHARE | PTE_BLOCK_NS
	},
#endif
#ifdef CONFIG_SYS_MEM_RESERVE_SECURE
	{},	/* space holder for secure mem */
#endif
	{},
};
#endif	/* !CONFIG_SYS_DCACHE_OFF */

int fsl_qoriq_core_to_cluster(unsigned int core);
u32 cpu_mask(void);
#endif /* _FSL_LAYERSCAPE_CPU_H */
