/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2018 Álvaro Fernández Rojas <noltari@gmail.com>
 */

#ifndef __CONFIG_BMIPS_BCM6362_H
#define __CONFIG_BMIPS_BCM6362_H

#include <linux/sizes.h>

/* CPU */
#define CONFIG_SYS_MIPS_TIMER_FREQ	200000000

/* RAM */
#define CONFIG_SYS_SDRAM_BASE		0x80000000

/* USB */
#define CONFIG_EHCI_DESC_BIG_ENDIAN
#define CONFIG_EHCI_MMIO_BIG_ENDIAN
#define CONFIG_SYS_OHCI_SWAP_REG_ACCESS
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS 2
#define CONFIG_USB_OHCI_NEW

/* U-Boot */
#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE + SZ_1M

#if defined(CONFIG_BMIPS_BOOT_RAM)
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SYS_INIT_SP_OFFSET	SZ_8K
#endif

#endif /* __CONFIG_BMIPS_BCM6362_H */
