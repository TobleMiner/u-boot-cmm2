/*
 * (C) Copyright 2003-2004
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * (C) Copyright 2004
 * Mark Jonas, Freescale Semiconductor, mark.jonas@motorola.com.
 *
 * (C) Copyright 2004
 * Martin Krause, TQ-Systems GmbH, martin.krause@tqs.de
 *
 * See file CREDITS for list of people who contributed to this
 * project.
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
 */

#include <common.h>
#include <mpc5xxx.h>
#include <pci.h>

#if defined(CONFIG_MPC5200_DDR)
#include "mt46v16m16-75.h"
#else
#include "mt48lc16m16a2-75.h"
#endif

#ifndef CFG_RAMBOOT
static void sdram_start (int hi_addr)
{
	long hi_addr_bit = hi_addr ? 0x01000000 : 0;

	/* unlock mode register */
	*(vu_long *)MPC5XXX_SDRAM_CTRL = SDRAM_CONTROL | 0x80000000 |
		hi_addr_bit;
	__asm__ volatile ("sync");

	/* precharge all banks */
	*(vu_long *)MPC5XXX_SDRAM_CTRL = SDRAM_CONTROL | 0x80000002 |
		hi_addr_bit;
	__asm__ volatile ("sync");

#if SDRAM_DDR
	/* set mode register: extended mode */
	*(vu_long *)MPC5XXX_SDRAM_MODE = SDRAM_EMODE;
	__asm__ volatile ("sync");

	/* set mode register: reset DLL */
	*(vu_long *)MPC5XXX_SDRAM_MODE = SDRAM_MODE | 0x04000000;
	__asm__ volatile ("sync");
#endif

	/* precharge all banks */
	*(vu_long *)MPC5XXX_SDRAM_CTRL = SDRAM_CONTROL | 0x80000002 |
		hi_addr_bit;
	__asm__ volatile ("sync");

	/* auto refresh */
	*(vu_long *)MPC5XXX_SDRAM_CTRL = SDRAM_CONTROL | 0x80000004 |
		hi_addr_bit;
	__asm__ volatile ("sync");

	/* set mode register */
	*(vu_long *)MPC5XXX_SDRAM_MODE = SDRAM_MODE;
	__asm__ volatile ("sync");

	/* normal operation */
	*(vu_long *)MPC5XXX_SDRAM_CTRL = SDRAM_CONTROL | hi_addr_bit;
	__asm__ volatile ("sync");
}
#endif

/*
 * ATTENTION: Although partially referenced initdram does NOT make real use
 *            use of CFG_SDRAM_BASE. The code does not work if CFG_SDRAM_BASE
 *            is something else than 0x00000000.
 */

#if defined(CONFIG_MPC5200)
long int initdram (int board_type)
{
	ulong dramsize = 0;
	ulong dramsize2 = 0;
#ifndef CFG_RAMBOOT
	ulong test1, test2;

	/* setup SDRAM chip selects */
	*(vu_long *)MPC5XXX_SDRAM_CS0CFG = 0x0000001c; /* 512MB at 0x0 */
	*(vu_long *)MPC5XXX_SDRAM_CS1CFG = 0x40000000; /* disabled */
	__asm__ volatile ("sync");

	/* setup config registers */
	*(vu_long *)MPC5XXX_SDRAM_CONFIG1 = SDRAM_CONFIG1;
	*(vu_long *)MPC5XXX_SDRAM_CONFIG2 = SDRAM_CONFIG2;
	__asm__ volatile ("sync");

#if SDRAM_DDR
	/* set tap delay */
	*(vu_long *)MPC5XXX_CDM_PORCFG = SDRAM_TAPDELAY;
	__asm__ volatile ("sync");
#endif

	/* find RAM size using SDRAM CS0 only */
	sdram_start(0);
	test1 = get_ram_size((ulong *)CFG_SDRAM_BASE, 0x20000000);
	sdram_start(1);
	test2 = get_ram_size((ulong *)CFG_SDRAM_BASE, 0x20000000);
	if (test1 > test2) {
		sdram_start(0);
		dramsize = test1;
	} else {
		dramsize = test2;
	}

	/* memory smaller than 1MB is impossible */
	if (dramsize < (1 << 20)) {
		dramsize = 0;
	}

	/* set SDRAM CS0 size according to the amount of RAM found */
	if (dramsize > 0) {
		*(vu_long *)MPC5XXX_SDRAM_CS0CFG = 0x13 +
			__builtin_ffs(dramsize >> 20) - 1;
	} else {
		*(vu_long *)MPC5XXX_SDRAM_CS0CFG = 0; /* disabled */
	}

	/* let SDRAM CS1 start right after CS0 */
	*(vu_long *)MPC5XXX_SDRAM_CS1CFG = dramsize + 0x0000001c; /* 512MB */

	/* find RAM size using SDRAM CS1 only */
	sdram_start(0);
	test1 = get_ram_size((ulong *)(CFG_SDRAM_BASE + dramsize), 0x20000000);
	sdram_start(1);
	test2 = get_ram_size((ulong *)(CFG_SDRAM_BASE + dramsize), 0x20000000);
	if (test1 > test2) {
		sdram_start(0);
		dramsize2 = test1;
	} else {
		dramsize2 = test2;
	}

	/* memory smaller than 1MB is impossible */
	if (dramsize2 < (1 << 20)) {
		dramsize2 = 0;
	}

	/* set SDRAM CS1 size according to the amount of RAM found */
	if (dramsize2 > 0) {
		*(vu_long *)MPC5XXX_SDRAM_CS1CFG = dramsize
			| (0x13 + __builtin_ffs(dramsize2 >> 20) - 1);
	} else {
		*(vu_long *)MPC5XXX_SDRAM_CS1CFG = dramsize; /* disabled */
	}

#else /* CFG_RAMBOOT */

	/* retrieve size of memory connected to SDRAM CS0 */
	dramsize = *(vu_long *)MPC5XXX_SDRAM_CS0CFG & 0xFF;
	if (dramsize >= 0x13) {
		dramsize = (1 << (dramsize - 0x13)) << 20;
	} else {
		dramsize = 0;
	}

	/* retrieve size of memory connected to SDRAM CS1 */
	dramsize2 = *(vu_long *)MPC5XXX_SDRAM_CS1CFG & 0xFF;
	if (dramsize2 >= 0x13) {
		dramsize2 = (1 << (dramsize2 - 0x13)) << 20;
	} else {
		dramsize2 = 0;
	}

#endif /* CFG_RAMBOOT */

/*	return dramsize + dramsize2; */
	return dramsize;
}

#elif defined(CONFIG_MGT5100)

long int initdram (int board_type)
{
	ulong dramsize = 0;
#ifndef CFG_RAMBOOT
	ulong test1, test2;

	/* setup and enable SDRAM chip selects */
	*(vu_long *)MPC5XXX_SDRAM_START = 0x00000000;
	*(vu_long *)MPC5XXX_SDRAM_STOP = 0x0000ffff;/* 2G */
	*(vu_long *)MPC5XXX_ADDECR |= (1 << 22); /* Enable SDRAM */
	__asm__ volatile ("sync");

	/* setup config registers */
	*(vu_long *)MPC5XXX_SDRAM_CONFIG1 = SDRAM_CONFIG1;
	*(vu_long *)MPC5XXX_SDRAM_CONFIG2 = SDRAM_CONFIG2;

	/* address select register */
	*(vu_long *)MPC5XXX_SDRAM_XLBSEL = SDRAM_ADDRSEL;
	__asm__ volatile ("sync");

	/* find RAM size */
	sdram_start(0);
	test1 = get_ram_size((ulong *)CFG_SDRAM_BASE, 0x80000000);
	sdram_start(1);
	test2 = get_ram_size((ulong *)CFG_SDRAM_BASE, 0x80000000);
	if (test1 > test2) {
		sdram_start(0);
		dramsize = test1;
	} else {
		dramsize = test2;
	}

	/* set SDRAM end address according to size */
	*(vu_long *)MPC5XXX_SDRAM_STOP = ((dramsize - 1) >> 15);

#else /* CFG_RAMBOOT */

	/* Retrieve amount of SDRAM available */
	dramsize = ((*(vu_long *)MPC5XXX_SDRAM_STOP + 1) << 15);

#endif /* CFG_RAMBOOT */

	return dramsize;
}

#else
#error Neither CONFIG_MPC5200 or CONFIG_MGT5100 defined
#endif

int checkboard (void)
{
#if defined (CONFIG_TQM5200_AA)
	puts ("Board: TQM5200-AA (TQ-Systems GmbH)\n");
#endif
#if defined (CONFIG_TQM5200_AB)
	puts ("Board: TQM5200-AB (TQ-Systems GmbH)\n");
#endif
#if defined (CONFIG_TQM5200_AC)
	puts ("Board: TQM5200-AC (TQ-Systems GmbH)\n");
#endif
	return 0;
}

void flash_preinit(void)
{
	/*
	 * Now, when we are in RAM, enable flash write
	 * access for detection process.
	 * Note that CS_BOOT cannot be cleared when
	 * executing in flash.
	 */
#if defined(CONFIG_MGT5100)
	*(vu_long *)MPC5XXX_ADDECR &= ~(1 << 25); /* disable CS_BOOT */
	*(vu_long *)MPC5XXX_ADDECR |= (1 << 16); /* enable CS0 */
#endif
	*(vu_long *)MPC5XXX_BOOTCS_CFG &= ~0x1; /* clear RO */
}


#ifdef	CONFIG_PCI
static struct pci_controller hose;

extern void pci_mpc5xxx_init(struct pci_controller *);

void pci_init_board(void)
{
	pci_mpc5xxx_init(&hose);
}
#endif

#if defined (CFG_CMD_IDE) && defined (CONFIG_IDE_RESET)

#if defined (CONFIG_MINIFAP)
#define SM501_POWER_MODE0_GATE		0x00000040UL
#define SM501_POWER_MODE1_GATE		0x00000048UL
#define POWER_MODE_GATE_GPIO_PWM_I2C	0x00000040UL
#define SM501_GPIO_DATA_DIR_HIGH	0x0001000CUL
#define SM501_GPIO_DATA_HIGH		0x00010004UL
#define SM501_GPIO_51			0x00080000UL
#else
#define GPIO_PSC1_4	0x01000000UL
#endif

void init_ide_reset (void)
{
	debug ("init_ide_reset\n");

#if defined (CONFIG_MINIFAP)
	/* Configure GPIO_51 of the SM501 grafic controller as ATA reset */

	/* enable GPIO control (in both power modes) */
	*(vu_long *) (SM501_MMIO_BASE+SM501_POWER_MODE0_GATE) |=
		POWER_MODE_GATE_GPIO_PWM_I2C;
	*(vu_long *) (SM501_MMIO_BASE+SM501_POWER_MODE1_GATE) |=
		POWER_MODE_GATE_GPIO_PWM_I2C;
	/* configure GPIO51 as output */
	*(vu_long *) (SM501_MMIO_BASE+SM501_GPIO_DATA_DIR_HIGH) |=
		SM501_GPIO_51;
#else
	/* Configure PSC1_4 as GPIO output for ATA reset */
	*(vu_long *) MPC5XXX_WU_GPIO_ENABLE |= GPIO_PSC1_4;
	*(vu_long *) MPC5XXX_WU_GPIO_DIR    |= GPIO_PSC1_4;
#endif
}

void ide_set_reset (int idereset)
{
	debug ("ide_reset(%d)\n", idereset);

#if defined (CONFIG_MINIFAP)
	if (idereset) {
		*(vu_long *) (SM501_MMIO_BASE+SM501_GPIO_DATA_HIGH) &=
			~SM501_GPIO_51;
	} else {
		*(vu_long *) (SM501_MMIO_BASE+SM501_GPIO_DATA_HIGH) |=
			SM501_GPIO_51;
	}
#else
	if (idereset) {
		*(vu_long *) MPC5XXX_WU_GPIO_DATA &= ~GPIO_PSC1_4;
	} else {
		*(vu_long *) MPC5XXX_WU_GPIO_DATA |=  GPIO_PSC1_4;
	}
#endif
}
#endif /* defined (CFG_CMD_IDE) && defined (CONFIG_IDE_RESET) */

#ifdef CONFIG_POST
/*
 * Reads GPIO pin PSC6_3. A keypress is reported, if PSC6_3 is low. If PSC6_3
 * is left open, no keypress is detected.
 */
int post_hotkeys_pressed(void)
{
	struct mpc5xxx_gpio *gpio;

	gpio = (struct mpc5xxx_gpio*) MPC5XXX_GPIO;

	/*
	 * Configure PSC6_1 and PSC6_3 as GPIO. PSC6 then couldn't be used in
	 * CODEC or UART mode. Consumer IrDA should still be possible.
         */
	gpio->port_config &= ~(0x07000000);
	gpio->port_config |=   0x03000000;

	/* Enable GPIO for GPIO_IRDA_1 (IR_USB_CLK pin) = PSC6_3 */
	gpio->simple_gpioe |= 0x20000000;

	/* Configure GPIO_IRDA_1 as input */
	gpio->simple_ddr &= ~(0x20000000);

	return ((gpio->simple_ival & 0x20000000) ? 0 : 1);
}
#endif

#if defined(CONFIG_POST) || defined(CONFIG_LOGBUFFER)

void post_word_store (ulong a)
{
	volatile ulong *save_addr =
		(volatile ulong *)(MPC5XXX_SRAM + MPC5XXX_SRAM_POST_SIZE);

	*save_addr = a;
}

ulong post_word_load (void)
{
	volatile ulong *save_addr =
		(volatile ulong *)(MPC5XXX_SRAM + MPC5XXX_SRAM_POST_SIZE);

	return *save_addr;
}

#endif	/* CONFIG_POST || CONFIG_LOGBUFFER*/
