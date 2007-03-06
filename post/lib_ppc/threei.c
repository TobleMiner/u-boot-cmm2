/*
 * (C) Copyright 2002
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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

/*
 * CPU test
 * Ternary instructions		instr rA,rS,UIMM
 *
 * Logic instructions:		ori, oris, xori, xoris
 *
 * The test contains a pre-built table of instructions, operands and
 * expected results. For each table entry, the test will cyclically use
 * different sets of operand registers and result registers.
 */

#ifdef CONFIG_POST

#include <post.h>
#include "cpu_asm.h"

#if CONFIG_POST & CFG_POST_CPU

extern void cpu_post_exec_21 (ulong *code, ulong *cr, ulong *res, ulong op);
extern ulong cpu_post_makecr (long v);

static struct cpu_post_threei_s
{
    ulong cmd;
    ulong op1;
    ushort op2;
    ulong res;
} cpu_post_threei_table[] =
{
    {
    	OP_ORI,
	0x80000000,
	0xffff,
	0x8000ffff
    },
    {
    	OP_ORIS,
	0x00008000,
	0xffff,
	0xffff8000
    },
    {
    	OP_XORI,
	0x8000ffff,
	0xffff,
	0x80000000
    },
    {
    	OP_XORIS,
	0x00008000,
	0xffff,
	0xffff8000
    },
};
static unsigned int cpu_post_threei_size =
    sizeof (cpu_post_threei_table) / sizeof (struct cpu_post_threei_s);

int cpu_post_test_threei (void)
{
    int ret = 0;
    unsigned int i, reg;
    int flag = disable_interrupts();

    for (i = 0; i < cpu_post_threei_size && ret == 0; i++)
    {
	struct cpu_post_threei_s *test = cpu_post_threei_table + i;

	for (reg = 0; reg < 32 && ret == 0; reg++)
	{
	    unsigned int reg0 = (reg + 0) % 32;
	    unsigned int reg1 = (reg + 1) % 32;
	    unsigned int stk = reg < 16 ? 31 : 15;
    	    unsigned long code[] =
	    {
		ASM_STW(stk, 1, -4),
		ASM_ADDI(stk, 1, -16),
		ASM_STW(3, stk, 8),
		ASM_STW(reg0, stk, 4),
		ASM_STW(reg1, stk, 0),
		ASM_LWZ(reg0, stk, 8),
		ASM_11IX(test->cmd, reg1, reg0, test->op2),
		ASM_STW(reg1, stk, 8),
		ASM_LWZ(reg1, stk, 0),
		ASM_LWZ(reg0, stk, 4),
		ASM_LWZ(3, stk, 8),
		ASM_ADDI(1, stk, 16),
		ASM_LWZ(stk, 1, -4),
		ASM_BLR,
	    };
	    ulong res;
	    ulong cr;

 	    cr = 0;
	    cpu_post_exec_21 (code, & cr, & res, test->op1);

	    ret = res == test->res && cr == 0 ? 0 : -1;

	    if (ret != 0)
	    {
	        post_log ("Error at threei test %d !\n", i);
	    }
	}
    }

    if (flag)
    	enable_interrupts();

    return ret;
}

#endif
#endif
