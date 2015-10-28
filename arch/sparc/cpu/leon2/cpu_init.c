/* Initializes CPU and basic hardware such as memory
 * controllers, IRQ controller and system timer 0.
 *
 * (C) Copyright 2007, 2015
 * Daniel Hellstrom, Cobham Gaisler, daniel@gaisler.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/asi.h>
#include <asm/leon.h>
#include <asm/io.h>

#include <config.h>

#define TIMER_BASE_CLK 1000000
#define US_PER_TICK (1000000 / CONFIG_SYS_HZ)

DECLARE_GLOBAL_DATA_PTR;

/*
 * Breath some life into the CPU...
 *
 * Set up the memory map,
 * initialize a bunch of registers.
 *
 * Run from FLASH/PROM:
 *  - until memory controller is set up, only registers available
 *  - no global variables available for writing
 *  - constants available
 */

void cpu_init_f(void)
{
	LEON2_regs *leon2 = (LEON2_regs *) LEON2_PREGS;

	/* initialize the IRQMP */
	leon2->Interrupt_Force = 0;
	leon2->Interrupt_Pending = 0;
	leon2->Interrupt_Clear = 0xfffe;	/* clear all old pending interrupts */
	leon2->Interrupt_Mask = 0xfffe0000;	/* mask all IRQs */

	/* cache */

	/* I/O port setup */
#ifdef LEON2_IO_PORT_DIR
	leon2->PIO_Direction = LEON2_IO_PORT_DIR;
#endif
#ifdef LEON2_IO_PORT_DATA
	leon2->PIO_Data = LEON2_IO_PORT_DATA;
#endif
#ifdef LEON2_IO_PORT_INT
	leon2->PIO_Interrupt = LEON2_IO_PORT_INT;
#else
	leon2->PIO_Interrupt = 0;
#endif

	/* disable timers */
	leon2->Timer_Control_1 = leon2->Timer_Control_2 = 0;
}

int arch_cpu_init(void)
{
	gd->cpu_clk = CONFIG_SYS_CLK_FREQ;
	gd->bus_clk = CONFIG_SYS_CLK_FREQ;
	gd->ram_size = CONFIG_SYS_SDRAM_SIZE;

	return 0;
}

/*
 * initialize higher level parts of CPU
 */
int cpu_init_r(void)
{
	return 0;
}

/* Uses Timer 0 to get accurate
 * pauses. Max 2 raised to 32 ticks
 *
 */
void cpu_wait_ticks(unsigned long ticks)
{
	unsigned long start = get_timer(0);
	while (get_timer(start) < ticks) ;
}

/* initiate and setup timer0 interrupt to configured HZ. Base clock is 1MHz.
 * Return irq number for timer int or a negative number for
 * dealing with self
 */
int timer_interrupt_init_cpu(void)
{
	LEON2_regs *leon2 = (LEON2_regs *) LEON2_PREGS;

	/* SYS_HZ ticks per second */
	leon2->Timer_Counter_1 = 0;
	leon2->Timer_Reload_1 = (TIMER_BASE_CLK / CONFIG_SYS_HZ) - 1;
	leon2->Timer_Control_1 =
	    (LEON2_TIMER_CTRL_EN | LEON2_TIMER_CTRL_RS | LEON2_TIMER_CTRL_LD);

	return LEON2_TIMER1_IRQNO;
}

/*
 * This function is intended for SHORT delays only.
 */
unsigned long cpu_usec2ticks(unsigned long usec)
{
	if (usec < US_PER_TICK)
		return 1;
	return usec / US_PER_TICK;
}

unsigned long cpu_ticks2usec(unsigned long ticks)
{
	return ticks * US_PER_TICK;
}

int timer_init(void)
{
	LEON2_regs *leon2 = (LEON2_regs *)LEON2_PREGS;

	/* initialize prescaler common to all timers to 1MHz */
	leon2->Scaler_Counter = leon2->Scaler_Reload =
		(((CONFIG_SYS_CLK_FREQ / 1000) + 500) / 1000) - 1;

	/* SYS_HZ ticks per second */
	leon2->Timer_Counter_1 = 0;
	leon2->Timer_Reload_1 = (CONFIG_SYS_TIMER_RATE / CONFIG_SYS_HZ) - 1;
	leon2->Timer_Control_1 = LEON2_TIMER_CTRL_EN | LEON2_TIMER_CTRL_RS |
		LEON2_TIMER_CTRL_LD;

	CONFIG_SYS_TIMER_COUNTER = (void *)&leon2->Timer_Counter_1;
	return 0;
}
