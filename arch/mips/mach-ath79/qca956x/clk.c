// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019 Rosy Song <rosysong@rosinson.com>
 */

#include <common.h>
#include <clock_legacy.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include <mach/ar71xx_regs.h>
#include <mach/ath79.h>
#include <wait_bit.h>

#define PLL_SRIF_DPLL2_KI_LSB 29
#define PLL_SRIF_DPLL2_KI_MASK 0x60000000
#define PLL_SRIF_DPLL2_KI_SET(x) \
	(((x) << PLL_SRIF_DPLL2_KI_LSB) & PLL_SRIF_DPLL2_KI_MASK)
#define PLL_SRIF_DPLL2_KD_LSB 25
#define PLL_SRIF_DPLL2_KD_MASK 0x1e000000
#define PLL_SRIF_DPLL2_KD_SET(x) \
	(((x) << PLL_SRIF_DPLL2_KD_LSB) & PLL_SRIF_DPLL2_KD_MASK)
#define PLL_SRIF_DPLL2_PLL_PWD_LSB 22
#define PLL_SRIF_DPLL2_PLL_PWD_MASK 0x00400000
#define PLL_SRIF_DPLL2_PLL_PWD_SET(x) \
	(((x) << PLL_SRIF_DPLL2_PLL_PWD_LSB) & PLL_SRIF_DPLL2_PLL_PWD_MASK)
#define PLL_SRIF_DPLL2_OUTDIV_LSB 19
#define PLL_SRIF_DPLL2_OUTDIV_MASK 0x00380000
#define PLL_SRIF_DPLL2_OUTDIV_SET(x) \
	(((x) << PLL_SRIF_DPLL2_OUTDIV_LSB) & PLL_SRIF_DPLL2_OUTDIV_MASK)
#define PLL_SRIF_DPLL2_PHASE_SHIFT_LSB 12
#define PLL_SRIF_DPLL2_PHASE_SHIFT_MASK 0x0007f000
#define PLL_SRIF_DPLL2_PHASE_SHIFT_SET(x) \
	(((x) << PLL_SRIF_DPLL2_PHASE_SHIFT_LSB) & PLL_SRIF_DPLL2_PHASE_SHIFT_MASK)
#define CPU_PLL_CONFIG_PLLPWD_LSB 30
#define CPU_PLL_CONFIG_PLLPWD_MASK 0x40000000
#define CPU_PLL_CONFIG_PLLPWD_SET(x) \
	(((x) << CPU_PLL_CONFIG_PLLPWD_LSB) & CPU_PLL_CONFIG_PLLPWD_MASK)
#define CPU_PLL_CONFIG_OUTDIV_LSB 19
#define CPU_PLL_CONFIG_OUTDIV_MASK 0x00380000
#define CPU_PLL_CONFIG_OUTDIV_SET(x) \
	(((x) << CPU_PLL_CONFIG_OUTDIV_LSB) & CPU_PLL_CONFIG_OUTDIV_MASK)
#define CPU_PLL_CONFIG_RANGE_LSB 17
#define CPU_PLL_CONFIG_RANGE_MASK 0x00060000
#define CPU_PLL_CONFIG_RANGE_SET(x) \
	(((x) << CPU_PLL_CONFIG_RANGE_LSB) & CPU_PLL_CONFIG_RANGE_MASK)
#define CPU_PLL_CONFIG_REFDIV_LSB 12
#define CPU_PLL_CONFIG_REFDIV_MASK 0x0001f000
#define CPU_PLL_CONFIG_REFDIV_SET(x) \
	(((x) << CPU_PLL_CONFIG_REFDIV_LSB) & CPU_PLL_CONFIG_REFDIV_MASK)
#define CPU_PLL_CONFIG1_NINT_LSB 18
#define CPU_PLL_CONFIG1_NINT_MASK 0x07fc0000
#define CPU_PLL_CONFIG1_NINT_SET(x) \
	(((x) << CPU_PLL_CONFIG1_NINT_LSB) & CPU_PLL_CONFIG1_NINT_MASK)
#define CPU_PLL_DITHER1_DITHER_EN_LSB 31
#define CPU_PLL_DITHER1_DITHER_EN_MASK 0x80000000
#define CPU_PLL_DITHER1_DITHER_EN_SET(x) \
	(((x) << CPU_PLL_DITHER1_DITHER_EN_LSB) & CPU_PLL_DITHER1_DITHER_EN_MASK)
#define CPU_PLL_DITHER1_UPDATE_COUNT_LSB 24
#define CPU_PLL_DITHER1_UPDATE_COUNT_MASK 0x3f000000
#define CPU_PLL_DITHER1_UPDATE_COUNT_SET(x) \
	(((x) << CPU_PLL_DITHER1_UPDATE_COUNT_LSB) & CPU_PLL_DITHER1_UPDATE_COUNT_MASK)
#define CPU_PLL_DITHER1_NFRAC_STEP_LSB 18
#define CPU_PLL_DITHER1_NFRAC_STEP_MASK 0x00fc0000
#define CPU_PLL_DITHER1_NFRAC_STEP_SET(x) \
	(((x) << CPU_PLL_DITHER1_NFRAC_STEP_LSB) & CPU_PLL_DITHER1_NFRAC_STEP_MASK)
#define CPU_PLL_DITHER1_NFRAC_MIN_LSB 0
#define CPU_PLL_DITHER1_NFRAC_MIN_MASK 0x0003ffff
#define CPU_PLL_DITHER1_NFRAC_MIN_SET(x) \
	(((x) << CPU_PLL_DITHER1_NFRAC_MIN_LSB) & CPU_PLL_DITHER1_NFRAC_MIN_MASK)
#define CPU_PLL_DITHER2_NFRAC_MAX_LSB 0
#define CPU_PLL_DITHER2_NFRAC_MAX_MASK 0x0003ffff
#define CPU_PLL_DITHER2_NFRAC_MAX_SET(x) \
	(((x) << CPU_PLL_DITHER2_NFRAC_MAX_LSB) & CPU_PLL_DITHER2_NFRAC_MAX_MASK)
#define DDR_PLL_CONFIG_PLLPWD_LSB 30
#define DDR_PLL_CONFIG_PLLPWD_MASK 0x40000000
#define DDR_PLL_CONFIG_PLLPWD_SET(x) \
	(((x) << DDR_PLL_CONFIG_PLLPWD_LSB) & DDR_PLL_CONFIG_PLLPWD_MASK)
#define DDR_PLL_CONFIG_OUTDIV_LSB 23
#define DDR_PLL_CONFIG_OUTDIV_MASK 0x03800000
#define DDR_PLL_CONFIG_OUTDIV_SET(x) \
	(((x) << DDR_PLL_CONFIG_OUTDIV_LSB) & DDR_PLL_CONFIG_OUTDIV_MASK)
#define DDR_PLL_CONFIG_RANGE_LSB 21
#define DDR_PLL_CONFIG_RANGE_MASK 0x00600000
#define DDR_PLL_CONFIG_RANGE_SET(x) \
	(((x) << DDR_PLL_CONFIG_RANGE_LSB) & DDR_PLL_CONFIG_RANGE_MASK)
#define DDR_PLL_CONFIG_REFDIV_LSB 16
#define DDR_PLL_CONFIG_REFDIV_MASK 0x001f0000
#define DDR_PLL_CONFIG_REFDIV_SET(x) \
	(((x) << DDR_PLL_CONFIG_REFDIV_LSB) & DDR_PLL_CONFIG_REFDIV_MASK)
#define DDR_PLL_CONFIG1_NINT_LSB 18
#define DDR_PLL_CONFIG1_NINT_MASK 0x07fc0000
#define DDR_PLL_CONFIG1_NINT_SET(x) \
	(((x) << DDR_PLL_CONFIG1_NINT_LSB) & DDR_PLL_CONFIG1_NINT_MASK)
#define DDR_PLL_DITHER1_DITHER_EN_LSB 31
#define DDR_PLL_DITHER1_DITHER_EN_MASK 0x80000000
#define DDR_PLL_DITHER1_DITHER_EN_SET(x) \
	(((x) << DDR_PLL_DITHER1_DITHER_EN_LSB) & DDR_PLL_DITHER1_DITHER_EN_MASK)
#define DDR_PLL_DITHER1_UPDATE_COUNT_LSB 27
#define DDR_PLL_DITHER1_UPDATE_COUNT_MASK 0x78000000
#define DDR_PLL_DITHER1_UPDATE_COUNT_SET(x) \
	(((x) << DDR_PLL_DITHER1_UPDATE_COUNT_LSB) & DDR_PLL_DITHER1_UPDATE_COUNT_MASK)
#define DDR_PLL_DITHER1_NFRAC_STEP_LSB 20
#define DDR_PLL_DITHER1_NFRAC_STEP_MASK 0x07f00000
#define DDR_PLL_DITHER1_NFRAC_STEP_SET(x) \
	(((x) << DDR_PLL_DITHER1_NFRAC_STEP_LSB) & DDR_PLL_DITHER1_NFRAC_STEP_MASK)
#define DDR_PLL_DITHER1_NFRAC_MIN_LSB 0
#define DDR_PLL_DITHER1_NFRAC_MIN_MASK 0x0003ffff
#define DDR_PLL_DITHER1_NFRAC_MIN_SET(x) \
	(((x) << DDR_PLL_DITHER1_NFRAC_MIN_LSB) & DDR_PLL_DITHER1_NFRAC_MIN_MASK)
#define DDR_PLL_DITHER2_NFRAC_MAX_LSB 0
#define DDR_PLL_DITHER2_NFRAC_MAX_MASK 0x0003ffff
#define DDR_PLL_DITHER2_NFRAC_MAX_SET(x) \
	(((x) << DDR_PLL_DITHER2_NFRAC_MAX_LSB) & DDR_PLL_DITHER2_NFRAC_MAX_MASK)
#define CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_LSB 24
#define CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_MASK 0x01000000
#define CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_LSB) & CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_MASK)
#define CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_LSB 21
#define CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_MASK 0x00200000
#define CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_LSB) & CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_MASK)
#define CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_LSB 20
#define CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_MASK 0x00100000
#define CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_LSB) & CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_MASK)
#define CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_LSB 15
#define CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_MASK 0x000f8000
#define CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_LSB) & CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_MASK)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_LSB 10
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_MASK 0x00007c00
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_LSB) & CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_MASK)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_LSB 5
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_MASK 0x000003e0
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_LSB) & CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_MASK)
#define CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_LSB 4
#define CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_MASK 0x00000010
#define CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_LSB) & CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_MASK)
#define CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_LSB 3
#define CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_MASK 0x00000008
#define CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_LSB) & CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_MASK)
#define CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_LSB 2
#define CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_MASK 0x00000004
#define CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(x) \
	(((x) << CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_LSB) & CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_MASK)

#define CPU_PLL_CONFIG1_NINT_VAL CPU_PLL_CONFIG1_NINT_SET(0x1f)
#define CPU_PLL_CONFIG_REF_DIV_VAL CPU_PLL_CONFIG_REFDIV_SET(0x1)
#define CPU_PLL_CONFIG_RANGE_VAL CPU_PLL_CONFIG_RANGE_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1 CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2 CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER1_VAL CPU_PLL_DITHER1_DITHER_EN_SET(0) | \
	CPU_PLL_DITHER1_NFRAC_MIN_SET(0) | \
	CPU_PLL_DITHER1_NFRAC_STEP_SET(0) | \
	CPU_PLL_DITHER1_UPDATE_COUNT_SET(0x0)
#define CPU_PLL_DITHER2_VAL CPU_PLL_DITHER2_NFRAC_MAX_SET(0x0)
#define DDR_PLL_CONFIG1_NINT_VAL DDR_PLL_CONFIG1_NINT_SET(0x1a)
#define DDR_PLL_CONFIG_REF_DIV_VAL DDR_PLL_CONFIG_REFDIV_SET(0x1)
#define DDR_PLL_CONFIG_RANGE_VAL DDR_PLL_CONFIG_RANGE_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1 DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2 DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER1_VAL DDR_PLL_DITHER1_DITHER_EN_SET(0) | \
	DDR_PLL_DITHER1_NFRAC_MIN_SET(0) | \
	DDR_PLL_DITHER1_NFRAC_STEP_SET(0) | \
	DDR_PLL_DITHER1_UPDATE_COUNT_SET(0x0)
#define DDR_PLL_DITHER2_VAL DDR_PLL_DITHER2_NFRAC_MAX_SET(0x0)
#define AHB_CLK_FROM_DDR CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_DDR \
	CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_CPU \
	CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL \
	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(0x2)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV \
	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV \
	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

static inline void set_val(u32 _reg, u32 _mask, u32 _val)
{
	void __iomem *pll_regs = map_physmem(AR71XX_PLL_BASE,
					     AR71XX_PLL_SIZE, MAP_NOCACHE);
	writel((readl(pll_regs + _reg) & (~(_mask))) | _val, pll_regs + _reg);
}

#define cpu_pll_set(_mask, _val)	\
	set_val(QCA956X_PLL_CPU_CONFIG_REG, _mask, _val)

#define ddr_pll_set(_mask, _val)	\
	set_val(QCA956X_PLL_DDR_CONFIG_REG, _mask, _val)

#define cpu_ddr_control_set(_mask, _val)	\
	set_val(QCA956X_PLL_CLK_CTRL_REG, _mask, _val)

DECLARE_GLOBAL_DATA_PTR;

static u32 qca956x_get_xtal(void)
{
	u32 val;

	val = ath79_get_bootstrap();
	if (val & QCA956X_BOOTSTRAP_REF_CLK_40)
		return 40000000;
	else
		return 25000000;
}

int get_serial_clock(void)
{
	return qca956x_get_xtal();
}

void qca956x_pll_init(void)
{
	void __iomem *srif_regs = map_physmem(QCA956X_SRIF_BASE,
					      QCA956X_SRIF_SIZE, MAP_NOCACHE);
	void __iomem *pll_regs = map_physmem(AR71XX_PLL_BASE,
					     AR71XX_PLL_SIZE, MAP_NOCACHE);

	/* 8.16.2 Baseband DPLL2 */
	writel(PLL_SRIF_DPLL2_KI_SET(2) | PLL_SRIF_DPLL2_KD_SET(0xa) |
		PLL_SRIF_DPLL2_PLL_PWD_SET(1) | PLL_SRIF_DPLL2_OUTDIV_SET(1) |
		PLL_SRIF_DPLL2_PHASE_SHIFT_SET(6), srif_regs + QCA956X_SRIF_BB_DPLL2_REG);

	/* 8.16.2 PCIE DPLL2 */
	writel(PLL_SRIF_DPLL2_KI_SET(2) | PLL_SRIF_DPLL2_KD_SET(0xa) |
		PLL_SRIF_DPLL2_PLL_PWD_SET(1) | PLL_SRIF_DPLL2_OUTDIV_SET(3) |
		PLL_SRIF_DPLL2_PHASE_SHIFT_SET(6), srif_regs + QCA956X_SRIF_PCIE_DPLL2_REG);

	/* 8.16.2 DDR DPLL2 */
	writel(PLL_SRIF_DPLL2_KI_SET(2) | PLL_SRIF_DPLL2_KD_SET(0xa) |
		PLL_SRIF_DPLL2_PLL_PWD_SET(1) | PLL_SRIF_DPLL2_PHASE_SHIFT_SET(6),
		srif_regs + QCA956X_SRIF_DDR_DPLL2_REG);

	/* 8.16.2 CPU DPLL2 */
	writel(PLL_SRIF_DPLL2_KI_SET(1) | PLL_SRIF_DPLL2_KD_SET(7) |
			  PLL_SRIF_DPLL2_PLL_PWD_SET(1) | PLL_SRIF_DPLL2_PHASE_SHIFT_SET(6),
			  srif_regs + QCA956X_SRIF_CPU_DPLL2_REG);

	/* pll_bypass_set */
	cpu_ddr_control_set(CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_MASK,
			    CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(1));
	cpu_ddr_control_set(CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_MASK,
			    CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(1));
	cpu_ddr_control_set(CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_MASK,
			    CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(1));

	/* init_cpu_pll */
	cpu_pll_set(CPU_PLL_CONFIG_PLLPWD_MASK,  CPU_PLL_CONFIG_PLLPWD_SET(1));
	cpu_pll_set(CPU_PLL_CONFIG_REFDIV_MASK, CPU_PLL_CONFIG_REF_DIV_VAL);
	cpu_pll_set(CPU_PLL_CONFIG_RANGE_MASK, CPU_PLL_CONFIG_RANGE_VAL);
	cpu_pll_set(CPU_PLL_CONFIG_OUTDIV_MASK, CPU_PLL_CONFIG_OUT_DIV_VAL1);
	set_val(QCA956X_PLL_CPU_CONFIG1_REG, CPU_PLL_CONFIG1_NINT_MASK, \
		CPU_PLL_CONFIG1_NINT_VAL);

	/* init_ddr_pll */
	ddr_pll_set(DDR_PLL_CONFIG_PLLPWD_MASK,  DDR_PLL_CONFIG_PLLPWD_SET(1));
	ddr_pll_set(DDR_PLL_CONFIG_REFDIV_MASK, DDR_PLL_CONFIG_REF_DIV_VAL);
	ddr_pll_set(DDR_PLL_CONFIG_RANGE_MASK, DDR_PLL_CONFIG_RANGE_VAL);
	ddr_pll_set(DDR_PLL_CONFIG_OUTDIV_MASK, DDR_PLL_CONFIG_OUT_DIV_VAL1);
	set_val(QCA956X_PLL_DDR_CONFIG1_REG, DDR_PLL_CONFIG1_NINT_MASK,
		DDR_PLL_CONFIG1_NINT_VAL);

	/* init_ahb_pll */
	writel(CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL | AHB_CLK_FROM_DDR |
		CPU_AND_DDR_CLK_FROM_DDR | CPU_AND_DDR_CLK_FROM_CPU |
		CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV | CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV |
		CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(1) |
		CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(1) |
		CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(1), pll_regs + QCA956X_PLL_CLK_CTRL_REG);

	/* ddr_pll_dither_unset */
	writel(DDR_PLL_DITHER1_VAL, pll_regs + QCA956X_PLL_DDR_DIT_FRAC_REG);
	writel(DDR_PLL_DITHER2_VAL, pll_regs + QCA956X_PLL_DDR_DIT2_FRAC_REG);

	/* cpu_pll_dither_unset */
	writel(CPU_PLL_DITHER1_VAL, pll_regs + QCA956X_PLL_CPU_DIT_FRAC_REG);
	writel(CPU_PLL_DITHER2_VAL, pll_regs + QCA956X_PLL_CPU_DIT2_FRAC_REG);

	/* pll_pwd_unset */
	cpu_pll_set(CPU_PLL_CONFIG_PLLPWD_MASK, CPU_PLL_CONFIG_PLLPWD_SET(0));
	ddr_pll_set(DDR_PLL_CONFIG_PLLPWD_MASK, DDR_PLL_CONFIG_PLLPWD_SET(0));

	/* outdiv_unset */
	cpu_pll_set(CPU_PLL_CONFIG_OUTDIV_MASK, CPU_PLL_CONFIG_OUT_DIV_VAL2);
	ddr_pll_set(DDR_PLL_CONFIG_OUTDIV_MASK, DDR_PLL_CONFIG_OUT_DIV_VAL2);

	/* pll_bypass_unset */
	cpu_ddr_control_set(CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_MASK,
			    CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(0));
	cpu_ddr_control_set(CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_MASK,
			    CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(0));
	cpu_ddr_control_set(CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_MASK,
			    CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(0));

	while (readl(pll_regs + QCA956X_PLL_CPU_CONFIG_REG) & 0x8000000)
		/* NOP */;

	while (readl(pll_regs + QCA956X_PLL_DDR_CONFIG_REG) & 0x8000000)
		/* NOP */;
}

int get_clocks(void)
{
	void __iomem *regs;
	u32 ref_rate, cpu_rate, ddr_rate, ahb_rate;
	u32 out_div, ref_div, postdiv, nint, hfrac, lfrac, clk_ctrl;
	u32 pll, cpu_pll, ddr_pll, misc;

	/*
	 * QCA956x timer init workaround has to be applied right before setting
	 * up the clock. Else, there will be no jiffies
	 */
	regs = map_physmem(AR71XX_RESET_BASE, AR71XX_RESET_SIZE,
			   MAP_NOCACHE);
	misc = readl(regs + AR71XX_RESET_REG_MISC_INT_ENABLE);
	misc |= MISC_INT_MIPS_SI_TIMERINT_MASK;
	writel(misc, regs + AR71XX_RESET_REG_MISC_INT_ENABLE);

	regs = map_physmem(AR71XX_PLL_BASE, AR71XX_PLL_SIZE,
			   MAP_NOCACHE);
	pll = readl(regs + QCA956X_PLL_CPU_CONFIG_REG);
	out_div = (pll >> QCA956X_PLL_CPU_CONFIG_OUTDIV_SHIFT) &
			  QCA956X_PLL_CPU_CONFIG_OUTDIV_MASK;
	ref_div = (pll >> QCA956X_PLL_CPU_CONFIG_REFDIV_SHIFT) &
			  QCA956X_PLL_CPU_CONFIG_REFDIV_MASK;

	pll = readl(regs + QCA956X_PLL_CPU_CONFIG1_REG);
	nint = (pll >> QCA956X_PLL_CPU_CONFIG1_NINT_SHIFT) &
			  QCA956X_PLL_CPU_CONFIG1_NINT_MASK;
	hfrac = (pll >> QCA956X_PLL_CPU_CONFIG1_NFRAC_H_SHIFT) &
			  QCA956X_PLL_CPU_CONFIG1_NFRAC_H_MASK;
	lfrac = (pll >> QCA956X_PLL_CPU_CONFIG1_NFRAC_L_SHIFT) &
			  QCA956X_PLL_CPU_CONFIG1_NFRAC_L_MASK;

	ref_rate = qca956x_get_xtal();

	cpu_pll = nint * ref_rate / ref_div;
	cpu_pll += (lfrac * ref_rate) / ((ref_div * 25) << 13);
	cpu_pll += (hfrac >> 13) * ref_rate / ref_div;
	cpu_pll /= (1 << out_div);

	pll = readl(regs + QCA956X_PLL_DDR_CONFIG_REG);
	out_div = (pll >> QCA956X_PLL_DDR_CONFIG_OUTDIV_SHIFT) &
			  QCA956X_PLL_DDR_CONFIG_OUTDIV_MASK;
	ref_div = (pll >> QCA956X_PLL_DDR_CONFIG_REFDIV_SHIFT) &
			  QCA956X_PLL_DDR_CONFIG_REFDIV_MASK;
	pll = readl(regs + QCA956X_PLL_DDR_CONFIG1_REG);
	nint = (pll >> QCA956X_PLL_DDR_CONFIG1_NINT_SHIFT) &
		QCA956X_PLL_DDR_CONFIG1_NINT_MASK;
	hfrac = (pll >> QCA956X_PLL_DDR_CONFIG1_NFRAC_H_SHIFT) &
		QCA956X_PLL_DDR_CONFIG1_NFRAC_H_MASK;
	lfrac = (pll >> QCA956X_PLL_DDR_CONFIG1_NFRAC_L_SHIFT) &
		QCA956X_PLL_DDR_CONFIG1_NFRAC_L_MASK;

	ddr_pll = nint * ref_rate / ref_div;
	ddr_pll += (lfrac * ref_rate) / ((ref_div * 25) << 13);
	ddr_pll += (hfrac >> 13) * ref_rate / ref_div;
	ddr_pll /= (1 << out_div);

	clk_ctrl = readl(regs + QCA956X_PLL_CLK_CTRL_REG);

	postdiv = (clk_ctrl >> QCA956X_PLL_CLK_CTRL_CPU_POST_DIV_SHIFT) &
		  QCA956X_PLL_CLK_CTRL_CPU_POST_DIV_MASK;

	if (clk_ctrl & QCA956X_PLL_CLK_CTRL_CPU_PLL_BYPASS)
		cpu_rate = ref_rate;
	else if (clk_ctrl & QCA956X_PLL_CLK_CTRL_CPU_DDRCLK_FROM_CPUPLL)
		cpu_rate = ddr_pll / (postdiv + 1);
	else
		cpu_rate = cpu_pll / (postdiv + 1);

	postdiv = (clk_ctrl >> QCA956X_PLL_CLK_CTRL_DDR_POST_DIV_SHIFT) &
		  QCA956X_PLL_CLK_CTRL_DDR_POST_DIV_MASK;

	if (clk_ctrl & QCA956X_PLL_CLK_CTRL_DDR_PLL_BYPASS)
		ddr_rate = ref_rate;
	else if (clk_ctrl & QCA956X_PLL_CLK_CTRL_CPU_DDRCLK_FROM_DDRPLL)
		ddr_rate = cpu_pll / (postdiv + 1);
	else
		ddr_rate = ddr_pll / (postdiv + 1);

	postdiv = (clk_ctrl >> QCA956X_PLL_CLK_CTRL_AHB_POST_DIV_SHIFT) &
		  QCA956X_PLL_CLK_CTRL_AHB_POST_DIV_MASK;

	if (clk_ctrl & QCA956X_PLL_CLK_CTRL_AHB_PLL_BYPASS)
		ahb_rate = ref_rate;
	else if (clk_ctrl & QCA956X_PLL_CLK_CTRL_AHBCLK_FROM_DDRPLL)
		ahb_rate = ddr_pll / (postdiv + 1);
	else
		ahb_rate = cpu_pll / (postdiv + 1);

	gd->cpu_clk = cpu_rate;
	gd->mem_clk = ddr_rate;
	gd->bus_clk = ahb_rate;

	debug("cpu_clk=%u, ddr_clk=%u, bus_clk=%u\n",
	      cpu_rate, ddr_rate, ahb_rate);

	return 0;
}

ulong get_bus_freq(ulong dummy)
{
	if (!gd->bus_clk)
		get_clocks();
	return gd->bus_clk;
}

ulong get_ddr_freq(ulong dummy)
{
	if (!gd->mem_clk)
		get_clocks();
	return gd->mem_clk;
}
