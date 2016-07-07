/*
 * (C) Copyright 2016
 * Vikas Manocha, <vikas.manocha@st.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/rcc.h>
#include <asm/arch/stm32.h>
#include <asm/arch/stm32_periph.h>

#define RCC_CR_HSION		(1 << 0)
#define RCC_CR_HSEON		(1 << 16)
#define RCC_CR_HSERDY		(1 << 17)
#define RCC_CR_HSEBYP		(1 << 18)
#define RCC_CR_CSSON		(1 << 19)
#define RCC_CR_PLLON		(1 << 24)
#define RCC_CR_PLLRDY		(1 << 25)

#define RCC_PLLCFGR_PLLM_MASK	0x3F
#define RCC_PLLCFGR_PLLN_MASK	0x7FC0
#define RCC_PLLCFGR_PLLP_MASK	0x30000
#define RCC_PLLCFGR_PLLQ_MASK	0xF000000
#define RCC_PLLCFGR_PLLSRC	(1 << 22)
#define RCC_PLLCFGR_PLLM_SHIFT	0
#define RCC_PLLCFGR_PLLN_SHIFT	6
#define RCC_PLLCFGR_PLLP_SHIFT	16
#define RCC_PLLCFGR_PLLQ_SHIFT	24

#define RCC_CFGR_AHB_PSC_MASK	0xF0
#define RCC_CFGR_APB1_PSC_MASK	0x1C00
#define RCC_CFGR_APB2_PSC_MASK	0xE000
#define RCC_CFGR_SW0		(1 << 0)
#define RCC_CFGR_SW1		(1 << 1)
#define RCC_CFGR_SW_MASK	0x3
#define RCC_CFGR_SW_HSI		0
#define RCC_CFGR_SW_HSE		RCC_CFGR_SW0
#define RCC_CFGR_SW_PLL		RCC_CFGR_SW1
#define RCC_CFGR_SWS0		(1 << 2)
#define RCC_CFGR_SWS1		(1 << 3)
#define RCC_CFGR_SWS_MASK	0xC
#define RCC_CFGR_SWS_HSI	0
#define RCC_CFGR_SWS_HSE	RCC_CFGR_SWS0
#define RCC_CFGR_SWS_PLL	RCC_CFGR_SWS1
#define RCC_CFGR_HPRE_SHIFT	4
#define RCC_CFGR_PPRE1_SHIFT	10
#define RCC_CFGR_PPRE2_SHIFT	13

#define RCC_APB1ENR_PWREN	(1 << 28)

/*
 * RCC USART specific definitions
 */
#define RCC_ENR_USART1EN		(1 << 4)
#define RCC_ENR_USART2EN		(1 << 17)
#define RCC_ENR_USART3EN		(1 << 18)
#define RCC_ENR_USART6EN		(1 <<  5)

/*
 * Offsets of some PWR registers
 */
#define PWR_CR1_ODEN		(1 << 16)
#define PWR_CR1_ODSWEN		(1 << 17)
#define PWR_CSR1_ODRDY		(1 << 16)
#define PWR_CSR1_ODSWRDY	(1 << 17)


/*
 * RCC GPIO specific definitions
 */
#define RCC_ENR_GPIO_A_EN	(1 << 0)
#define RCC_ENR_GPIO_B_EN	(1 << 1)
#define RCC_ENR_GPIO_C_EN	(1 << 2)
#define RCC_ENR_GPIO_D_EN	(1 << 3)
#define RCC_ENR_GPIO_E_EN	(1 << 4)
#define RCC_ENR_GPIO_F_EN	(1 << 5)
#define RCC_ENR_GPIO_G_EN	(1 << 6)
#define RCC_ENR_GPIO_H_EN	(1 << 7)
#define RCC_ENR_GPIO_I_EN	(1 << 8)
#define RCC_ENR_GPIO_J_EN	(1 << 9)
#define RCC_ENR_GPIO_K_EN	(1 << 10)

struct pll_psc {
	u8	pll_m;
	u16	pll_n;
	u8	pll_p;
	u8	pll_q;
	u8	ahb_psc;
	u8	apb1_psc;
	u8	apb2_psc;
};

#define AHB_PSC_1		0
#define AHB_PSC_2		0x8
#define AHB_PSC_4		0x9
#define AHB_PSC_8		0xA
#define AHB_PSC_16		0xB
#define AHB_PSC_64		0xC
#define AHB_PSC_128		0xD
#define AHB_PSC_256		0xE
#define AHB_PSC_512		0xF

#define APB_PSC_1		0
#define APB_PSC_2		0x4
#define APB_PSC_4		0x5
#define APB_PSC_8		0x6
#define APB_PSC_16		0x7

#if !defined(CONFIG_STM32_HSE_HZ)
#error "CONFIG_STM32_HSE_HZ not defined!"
#else
#if (CONFIG_STM32_HSE_HZ == 25000000)
#if (CONFIG_SYS_CLK_FREQ == 200000000)
/* 200 MHz */
struct pll_psc sys_pll_psc = {
	.pll_m = 25,
	.pll_n = 400,
	.pll_p = 2,
	.pll_q = 8,
	.ahb_psc = AHB_PSC_1,
	.apb1_psc = APB_PSC_4,
	.apb2_psc = APB_PSC_2
};
#endif
#else
#error "No PLL/Prescaler configuration for given CONFIG_STM32_HSE_HZ exists"
#endif
#endif

int configure_clocks(void)
{
	/* Reset RCC configuration */
	setbits_le32(&STM32_RCC->cr, RCC_CR_HSION);
	writel(0, &STM32_RCC->cfgr); /* Reset CFGR */
	clrbits_le32(&STM32_RCC->cr, (RCC_CR_HSEON | RCC_CR_CSSON
		| RCC_CR_PLLON));
	writel(0x24003010, &STM32_RCC->pllcfgr); /* Reset value from RM */
	clrbits_le32(&STM32_RCC->cr, RCC_CR_HSEBYP);
	writel(0, &STM32_RCC->cir); /* Disable all interrupts */

	/* Configure for HSE+PLL operation */
	setbits_le32(&STM32_RCC->cr, RCC_CR_HSEON);
	while (!(readl(&STM32_RCC->cr) & RCC_CR_HSERDY))
		;

	setbits_le32(&STM32_RCC->cfgr, ((
		sys_pll_psc.ahb_psc << RCC_CFGR_HPRE_SHIFT)
		| (sys_pll_psc.apb1_psc << RCC_CFGR_PPRE1_SHIFT)
		| (sys_pll_psc.apb2_psc << RCC_CFGR_PPRE2_SHIFT)));

	/* Configure the main PLL */
	uint32_t pllcfgr = 0;
	pllcfgr = RCC_PLLCFGR_PLLSRC; /* pll source HSE */
	pllcfgr |= sys_pll_psc.pll_m << RCC_PLLCFGR_PLLM_SHIFT;
	pllcfgr |= sys_pll_psc.pll_n << RCC_PLLCFGR_PLLN_SHIFT;
	pllcfgr |= ((sys_pll_psc.pll_p >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT;
	pllcfgr |= sys_pll_psc.pll_q << RCC_PLLCFGR_PLLQ_SHIFT;
	writel(pllcfgr, &STM32_RCC->pllcfgr);

	/* Enable the main PLL */
	setbits_le32(&STM32_RCC->cr, RCC_CR_PLLON);
	while (!(readl(&STM32_RCC->cr) & RCC_CR_PLLRDY))
		;

	/* Enable high performance mode, System frequency up to 200 MHz */
	setbits_le32(&STM32_RCC->apb1enr, RCC_APB1ENR_PWREN);
	setbits_le32(&STM32_PWR->cr1, PWR_CR1_ODEN);
	/* Infinite wait! */
	while (!(readl(&STM32_PWR->csr1) & PWR_CSR1_ODRDY))
		;
	/* Enable the Over-drive switch */
	setbits_le32(&STM32_PWR->cr1, PWR_CR1_ODSWEN);
	/* Infinite wait! */
	while (!(readl(&STM32_PWR->csr1) & PWR_CSR1_ODSWRDY))
		;

	stm32_flash_latency_cfg(5);
	clrbits_le32(&STM32_RCC->cfgr, (RCC_CFGR_SW0 | RCC_CFGR_SW1));
	setbits_le32(&STM32_RCC->cfgr, RCC_CFGR_SW_PLL);

	while ((readl(&STM32_RCC->cfgr) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_PLL)
		;

	return 0;
}

unsigned long clock_get(enum clock clck)
{
	u32 sysclk = 0;
	u32 shift = 0;
	/* Prescaler table lookups for clock computation */
	u8 ahb_psc_table[16] = {
		0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9
	};
	u8 apb_psc_table[8] = {
		0, 0, 0, 0, 1, 2, 3, 4
	};

	if ((readl(&STM32_RCC->cfgr) & RCC_CFGR_SWS_MASK) ==
			RCC_CFGR_SWS_PLL) {
		u16 pllm, plln, pllp;
		pllm = (readl(&STM32_RCC->pllcfgr) & RCC_PLLCFGR_PLLM_MASK);
		plln = ((readl(&STM32_RCC->pllcfgr) & RCC_PLLCFGR_PLLN_MASK)
			>> RCC_PLLCFGR_PLLN_SHIFT);
		pllp = ((((readl(&STM32_RCC->pllcfgr) & RCC_PLLCFGR_PLLP_MASK)
			>> RCC_PLLCFGR_PLLP_SHIFT) + 1) << 1);
		sysclk = ((CONFIG_STM32_HSE_HZ / pllm) * plln) / pllp;
	}

	switch (clck) {
	case CLOCK_CORE:
		return sysclk;
		break;
	case CLOCK_AHB:
		shift = ahb_psc_table[(
			(readl(&STM32_RCC->cfgr) & RCC_CFGR_AHB_PSC_MASK)
			>> RCC_CFGR_HPRE_SHIFT)];
		return sysclk >>= shift;
		break;
	case CLOCK_APB1:
		shift = apb_psc_table[(
			(readl(&STM32_RCC->cfgr) & RCC_CFGR_APB1_PSC_MASK)
			>> RCC_CFGR_PPRE1_SHIFT)];
		return sysclk >>= shift;
		break;
	case CLOCK_APB2:
		shift = apb_psc_table[(
			(readl(&STM32_RCC->cfgr) & RCC_CFGR_APB2_PSC_MASK)
			>> RCC_CFGR_PPRE2_SHIFT)];
		return sysclk >>= shift;
		break;
	default:
		return 0;
		break;
	}
}


void clock_setup(int peripheral)
{
	switch (peripheral) {
	case USART1_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_APB2ENR, RCC_ENR_USART1EN);
		break;
	case GPIO_A_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_A_EN);
		break;
	case GPIO_B_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_B_EN);
		break;
	case GPIO_C_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_C_EN);
		break;
	case GPIO_D_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_D_EN);
		break;
	case GPIO_E_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_E_EN);
		break;
	case GPIO_F_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_F_EN);
		break;
	case GPIO_G_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_G_EN);
		break;
	case GPIO_H_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_H_EN);
		break;
	case GPIO_I_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_I_EN);
		break;
	case GPIO_J_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_J_EN);
		break;
	case GPIO_K_CLOCK_CFG:
		setbits_le32(RCC_BASE + RCC_AHB1ENR, RCC_ENR_GPIO_K_EN);
		break;
	default:
		break;
	}
}
