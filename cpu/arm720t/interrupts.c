/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
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
#include <clps7111.h>

#include <asm/proc-armv/ptrace.h>
#ifdef CONFIG_NETARM
#include <asm/arch/netarm_registers.h>
#endif

extern void reset_cpu(ulong addr);

#ifndef CONFIG_NETARM
/* we always count down the max. */
#define TIMER_LOAD_VAL 0xffff
/* macro to read the 16 bit timer */
#define READ_TIMER (IO_TC1D & 0xffff)
#else
#define IRQEN	(*(volatile unsigned int *)(NETARM_GEN_MODULE_BASE + NETARM_GEN_INTR_ENABLE))
#define TM2CTRL	(*(volatile unsigned int *)(NETARM_GEN_MODULE_BASE + NETARM_GEN_TIMER2_CONTROL))
#define TM2STAT	(*(volatile unsigned int *)(NETARM_GEN_MODULE_BASE + NETARM_GEN_TIMER2_STATUS))
#define TIMER_LOAD_VAL NETARM_GEN_TSTAT_CTC_MASK
#define READ_TIMER (TM2STAT & NETARM_GEN_TSTAT_CTC_MASK)
#endif

#ifdef CONFIG_USE_IRQ
/* enable IRQ/FIQ interrupts */
void enable_interrupts (void)
{
	unsigned long temp;
	__asm__ __volatile__("mrs %0, cpsr\n"
			     "bic %0, %0, #0x80\n"
			     "msr cpsr_c, %0"
			     : "=r" (temp)
			     :
			     : "memory");
}


/*
 * disable IRQ/FIQ interrupts
 * returns true if interrupts had been enabled before we disabled them
 */
int disable_interrupts (void)
{
	unsigned long old,temp;
	__asm__ __volatile__("mrs %0, cpsr\n"
			     "orr %1, %0, #0x80\n"
			     "msr cpsr_c, %1"
			     : "=r" (old), "=r" (temp)
			     :
			     : "memory");
	return (old & 0x80) == 0;
}
#else
void enable_interrupts (void)
{
	return;
}
int disable_interrupts (void)
{
	return 0;
}
#endif


void bad_mode (void)
{
	panic ("Resetting CPU ...\n");
	reset_cpu (0);
}

void show_regs (struct pt_regs *regs)
{
	unsigned long flags;
	const char *processor_modes[] =
		{ "USER_26", "FIQ_26", "IRQ_26", "SVC_26", "UK4_26", "UK5_26",
"UK6_26", "UK7_26",
		"UK8_26", "UK9_26", "UK10_26", "UK11_26", "UK12_26", "UK13_26",
				"UK14_26", "UK15_26",
		"USER_32", "FIQ_32", "IRQ_32", "SVC_32", "UK4_32", "UK5_32",
				"UK6_32", "ABT_32",
		"UK8_32", "UK9_32", "UK10_32", "UND_32", "UK12_32", "UK13_32",
				"UK14_32", "SYS_32"
	};

	flags = condition_codes (regs);

	printf ("pc : [<%08lx>]    lr : [<%08lx>]\n"
			"sp : %08lx  ip : %08lx  fp : %08lx\n",
			instruction_pointer (regs),
			regs->ARM_lr, regs->ARM_sp, regs->ARM_ip, regs->ARM_fp);
	printf ("r10: %08lx  r9 : %08lx  r8 : %08lx\n",
			regs->ARM_r10, regs->ARM_r9, regs->ARM_r8);
	printf ("r7 : %08lx  r6 : %08lx  r5 : %08lx  r4 : %08lx\n",
			regs->ARM_r7, regs->ARM_r6, regs->ARM_r5, regs->ARM_r4);
	printf ("r3 : %08lx  r2 : %08lx  r1 : %08lx  r0 : %08lx\n",
			regs->ARM_r3, regs->ARM_r2, regs->ARM_r1, regs->ARM_r0);
	printf ("Flags: %c%c%c%c",
			flags & CC_N_BIT ? 'N' : 'n',
			flags & CC_Z_BIT ? 'Z' : 'z',
			flags & CC_C_BIT ? 'C' : 'c', flags & CC_V_BIT ? 'V' : 'v');
	printf ("  IRQs %s  FIQs %s  Mode %s%s\n",
			interrupts_enabled (regs) ? "on" : "off",
			fast_interrupts_enabled (regs) ? "on" : "off",
			processor_modes[processor_mode (regs)],
			thumb_mode (regs) ? " (T)" : "");
}

void do_undefined_instruction (struct pt_regs *pt_regs)
{
	printf ("undefined instruction\n");
	show_regs (pt_regs);
	bad_mode ();
}

void do_software_interrupt (struct pt_regs *pt_regs)
{
	printf ("software interrupt\n");
	show_regs (pt_regs);
	bad_mode ();
}

void do_prefetch_abort (struct pt_regs *pt_regs)
{
	printf ("prefetch abort\n");
	show_regs (pt_regs);
	bad_mode ();
}

void do_data_abort (struct pt_regs *pt_regs)
{
	printf ("data abort\n");
	show_regs (pt_regs);
	bad_mode ();
}

void do_not_used (struct pt_regs *pt_regs)
{
	printf ("not used\n");
	show_regs (pt_regs);
	bad_mode ();
}

void do_fiq (struct pt_regs *pt_regs)
{
	printf ("fast interrupt request\n");
	show_regs (pt_regs);
	bad_mode ();
}

void do_irq (struct pt_regs *pt_regs)
{
	printf ("interrupt request\n");
	show_regs (pt_regs);
	bad_mode ();
}

static ulong timestamp;
static ulong lastdec;

int interrupt_init (void)
{
#ifdef CONFIG_NETARM
        /* disable all interrupts */
	IRQEN = 0;

	/* operate timer 2 in non-prescale mode */
	TM2CTRL = ( NETARM_GEN_TIMER_SET_HZ(CFG_HZ) |
		    NETARM_GEN_TCTL_ENABLE |
		    NETARM_GEN_TCTL_INIT_COUNT(TIMER_LOAD_VAL));

	/* set timer 2 counter */
	lastdec = TIMER_LOAD_VAL;
#else
	/* disable all interrupts */
	IO_INTMR1 = 0;

	/* operate timer 1 in prescale mode */
	IO_SYSCON1 |= SYSCON1_TC1M;

	/* select 2kHz clock source for timer 1 */
	IO_SYSCON1 &= ~SYSCON1_TC1S;

	/* set timer 1 counter */
	lastdec = IO_TC1D = TIMER_LOAD_VAL;
#endif
	timestamp = 0;

	return (0);
}

/*
 * timer without interrupts
 */

void reset_timer (void)
{
	reset_timer_masked ();
}

ulong get_timer (ulong base)
{
	return get_timer_masked () - base;
}

void set_timer (ulong t)
{
	timestamp = t;
}

void udelay (unsigned long usec)
{
	ulong tmo;

	tmo = usec / 1000;
	tmo *= CFG_HZ;
	tmo /= 1000;

	tmo += get_timer (0);

	while (get_timer_masked () < tmo)
		/*NOP*/;
}

void reset_timer_masked (void)
{
	/* reset time */
	lastdec = READ_TIMER;
	timestamp = 0;
}

ulong get_timer_masked (void)
{
	ulong now = READ_TIMER;

	if (lastdec >= now) {
		/* normal mode */
		timestamp += lastdec - now;
	} else {
		/* we have an overflow ... */
		timestamp += lastdec + TIMER_LOAD_VAL - now;
	}
	lastdec = now;

	return timestamp;
}

void udelay_masked (unsigned long usec)
{
	ulong tmo;

	tmo = usec / 1000;
	tmo *= CFG_HZ;
	tmo /= 1000;

	reset_timer_masked ();

	while (get_timer_masked () < tmo)
		/*NOP*/;
}
