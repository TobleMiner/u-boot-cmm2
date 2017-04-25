/*
 *  Copyright (C) 2013-2017 Altera Corporation <www.altera.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _CLOCK_MANAGER_H_
#define _CLOCK_MANAGER_H_

#ifndef __ASSEMBLER__
void cm_wait_for_lock(u32 mask);
int cm_wait_for_fsm(void);
void cm_print_clock_quick_summary(void);
#endif

#if defined(CONFIG_TARGET_SOCFPGA_GEN5)
#include <asm/arch/clock_manager_gen5.h>
#endif
#endif /* _CLOCK_MANAGER_H_ */
