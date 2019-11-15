// SPDX-License-Identifier: GPL-2.0
/*
 * (C) Copyright 2018 Rockchip Electronics Co., Ltd.
 */

#include <common.h>
#include <debug_uart.h>
#include <ram.h>
#include <asm/io.h>
#include <asm/arch-rockchip/sdram.h>
#include <asm/arch-rockchip/sdram_common.h>

/* n: Unit bytes */
void sdram_copy_to_reg(u32 *dest, const u32 *src, u32 n)
{
	int i;

	for (i = 0; i < n / sizeof(u32); i++) {
		writel(*src, dest);
		src++;
		dest++;
	}
}

void sdram_org_config(struct sdram_cap_info *cap_info,
		      struct sdram_base_params *base,
		      u32 *p_os_reg2, u32 *p_os_reg3, u32 channel)
{
	*p_os_reg2 |= SYS_REG_ENC_DDRTYPE(base->dramtype);
	*p_os_reg2 |= SYS_REG_ENC_NUM_CH(base->num_channels);

	*p_os_reg2 |= SYS_REG_ENC_ROW_3_4(cap_info->row_3_4, channel);
	*p_os_reg2 |= SYS_REG_ENC_CHINFO(channel);
	*p_os_reg2 |= SYS_REG_ENC_RANK(cap_info->rank, channel);
	*p_os_reg2 |= SYS_REG_ENC_COL(cap_info->col, channel);
	*p_os_reg2 |= SYS_REG_ENC_BK(cap_info->bk, channel);
	*p_os_reg2 |= SYS_REG_ENC_BW(cap_info->bw, channel);
	*p_os_reg2 |= SYS_REG_ENC_DBW(cap_info->dbw, channel);

	SYS_REG_ENC_CS0_ROW(cap_info->cs0_row, *p_os_reg2, *p_os_reg3, channel);
	if (cap_info->cs1_row)
		SYS_REG_ENC_CS1_ROW(cap_info->cs1_row, *p_os_reg2,
				    *p_os_reg3, channel);
	*p_os_reg3 |= SYS_REG_ENC_CS1_COL(cap_info->col, channel);
	*p_os_reg3 |= SYS_REG_ENC_VERSION(DDR_SYS_REG_VERSION);
}

int sdram_detect_bw(struct sdram_cap_info *cap_info)
{
	return 0;
}

int sdram_detect_cs(struct sdram_cap_info *cap_info)
{
	return 0;
}

int sdram_detect_col(struct sdram_cap_info *cap_info,
		     u32 coltmp)
{
	void __iomem *test_addr;
	u32 col;
	u32 bw = cap_info->bw;

	for (col = coltmp; col >= 9; col -= 1) {
		writel(0, CONFIG_SYS_SDRAM_BASE);
		test_addr = (void __iomem *)(CONFIG_SYS_SDRAM_BASE +
				(1ul << (col + bw - 1ul)));
		writel(PATTERN, test_addr);
		if ((readl(test_addr) == PATTERN) &&
		    (readl(CONFIG_SYS_SDRAM_BASE) == 0))
			break;
	}
	if (col == 8) {
		printascii("col error\n");
		return -1;
	}

	cap_info->col = col;

	return 0;
}

int sdram_detect_bank(struct sdram_cap_info *cap_info,
		      u32 coltmp, u32 bktmp)
{
	void __iomem *test_addr;
	u32 bk;
	u32 bw = cap_info->bw;

	test_addr = (void __iomem *)(CONFIG_SYS_SDRAM_BASE +
			(1ul << (coltmp + bktmp + bw - 1ul)));
	writel(0, CONFIG_SYS_SDRAM_BASE);
	writel(PATTERN, test_addr);
	if ((readl(test_addr) == PATTERN) &&
	    (readl(CONFIG_SYS_SDRAM_BASE) == 0))
		bk = 3;
	else
		bk = 2;

	cap_info->bk = bk;

	return 0;
}

/* detect bg for ddr4 */
int sdram_detect_bg(struct sdram_cap_info *cap_info,
		    u32 coltmp)
{
	void __iomem *test_addr;
	u32 dbw;
	u32 bw = cap_info->bw;

	test_addr = (void __iomem *)(CONFIG_SYS_SDRAM_BASE +
			(1ul << (coltmp + bw + 1ul)));
	writel(0, CONFIG_SYS_SDRAM_BASE);
	writel(PATTERN, test_addr);
	if ((readl(test_addr) == PATTERN) &&
	    (readl(CONFIG_SYS_SDRAM_BASE) == 0))
		dbw = 0;
	else
		dbw = 1;

	cap_info->dbw = dbw;

	return 0;
}

/* detect dbw for ddr3,lpddr2,lpddr3,lpddr4 */
int sdram_detect_dbw(struct sdram_cap_info *cap_info, u32 dram_type)
{
	u32 row, col, bk, bw, cs_cap, cs;
	u32 die_bw_0 = 0, die_bw_1 = 0;

	if (dram_type == DDR3 || dram_type == LPDDR4) {
		cap_info->dbw = 1;
	} else if (dram_type == LPDDR3 || dram_type == LPDDR2) {
		row = cap_info->cs0_row;
		col = cap_info->col;
		bk = cap_info->bk;
		cs = cap_info->rank;
		bw = cap_info->bw;
		cs_cap = (1 << (row + col + bk + bw - 20));
		if (bw == 2) {
			if (cs_cap <= 0x2000000) /* 256Mb */
				die_bw_0 = (col < 9) ? 2 : 1;
			else if (cs_cap <= 0x10000000) /* 2Gb */
				die_bw_0 = (col < 10) ? 2 : 1;
			else if (cs_cap <= 0x40000000) /* 8Gb */
				die_bw_0 = (col < 11) ? 2 : 1;
			else
				die_bw_0 = (col < 12) ? 2 : 1;
			if (cs > 1) {
				row = cap_info->cs1_row;
				cs_cap = (1 << (row + col + bk + bw - 20));
				if (cs_cap <= 0x2000000) /* 256Mb */
					die_bw_0 = (col < 9) ? 2 : 1;
				else if (cs_cap <= 0x10000000) /* 2Gb */
					die_bw_0 = (col < 10) ? 2 : 1;
				else if (cs_cap <= 0x40000000) /* 8Gb */
					die_bw_0 = (col < 11) ? 2 : 1;
				else
					die_bw_0 = (col < 12) ? 2 : 1;
			}
		} else {
			die_bw_1 = 1;
			die_bw_0 = 1;
		}
		cap_info->dbw = (die_bw_0 > die_bw_1) ? die_bw_0 : die_bw_1;
	}

	return 0;
}

int sdram_detect_row(struct sdram_cap_info *cap_info,
		     u32 coltmp, u32 bktmp, u32 rowtmp)
{
	u32 row;
	u32 bw = cap_info->bw;
	void __iomem *test_addr;

	for (row = rowtmp; row > 12; row--) {
		writel(0, CONFIG_SYS_SDRAM_BASE);
		test_addr = (void __iomem *)(CONFIG_SYS_SDRAM_BASE +
				(1ul << (row + bktmp + coltmp + bw - 1ul)));
		writel(PATTERN, test_addr);
		if ((readl(test_addr) == PATTERN) &&
		    (readl(CONFIG_SYS_SDRAM_BASE) == 0))
			break;
	}
	if (row == 12) {
		printascii("row error");
		return -1;
	}

	cap_info->cs0_row = row;

	return 0;
}

int sdram_detect_row_3_4(struct sdram_cap_info *cap_info,
			 u32 coltmp, u32 bktmp)
{
	u32 row_3_4;
	u32 bw = cap_info->bw;
	u32 row = cap_info->cs0_row;
	void __iomem *test_addr, *test_addr1;

	test_addr = CONFIG_SYS_SDRAM_BASE;
	test_addr1 = (void __iomem *)(CONFIG_SYS_SDRAM_BASE +
			(0x3ul << (row + bktmp + coltmp + bw - 1ul - 1ul)));

	writel(0, test_addr);
	writel(PATTERN, test_addr1);
	if ((readl(test_addr) == 0) && (readl(test_addr1) == PATTERN))
		row_3_4 = 0;
	else
		row_3_4 = 1;

	cap_info->row_3_4 = row_3_4;

	return 0;
}

int sdram_detect_high_row(struct sdram_cap_info *cap_info)
{
	cap_info->cs0_high16bit_row = cap_info->cs0_row;
	cap_info->cs1_high16bit_row = cap_info->cs1_row;

	return 0;
}

int sdram_detect_cs1_row(struct sdram_cap_info *cap_info, u32 dram_type)
{
	void __iomem *test_addr;
	u32 row = 0, bktmp, coltmp, bw;
	ulong cs0_cap;
	u32 byte_mask;

	if (cap_info->rank == 2) {
		cs0_cap = sdram_get_cs_cap(cap_info, 0, dram_type);

		if (dram_type == DDR4) {
			if (cap_info->dbw == 0)
				bktmp = cap_info->bk + 2;
			else
				bktmp = cap_info->bk + 1;
		} else {
			bktmp = cap_info->bk;
		}
		bw = cap_info->bw;
		coltmp = cap_info->col;

		/*
		 * because px30 support axi split,min bandwidth
		 * is 8bit. if cs0 is 32bit, cs1 may 32bit or 16bit
		 * so we check low 16bit data when detect cs1 row.
		 * if cs0 is 16bit/8bit, we check low 8bit data.
		 */
		if (bw == 2)
			byte_mask = 0xFFFF;
		else
			byte_mask = 0xFF;

		/* detect cs1 row */
		for (row = cap_info->cs0_row; row > 12; row--) {
			test_addr = (void __iomem *)(CONFIG_SYS_SDRAM_BASE +
				    cs0_cap +
				    (1ul << (row + bktmp + coltmp + bw - 1ul)));
			writel(0, CONFIG_SYS_SDRAM_BASE + cs0_cap);
			writel(PATTERN, test_addr);

			if (((readl(test_addr) & byte_mask) ==
			     (PATTERN & byte_mask)) &&
			    ((readl(CONFIG_SYS_SDRAM_BASE + cs0_cap) &
			      byte_mask) == 0)) {
				break;
			}
		}
	}

	cap_info->cs1_row = row;

	return 0;
}
