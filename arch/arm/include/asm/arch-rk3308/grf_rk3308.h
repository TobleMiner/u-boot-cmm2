/* SPDX-License-Identifier: GPL-2.0+ */
/*
 *Copyright 2019 Rockchip Electronics Co., Ltd.
 */
#ifndef _ASM_ARCH_GRF_rk3308_H
#define _ASM_ARCH_GRF_rk3308_H

struct rk3308_grf {
	unsigned int gpio0a_iomux;
	unsigned int reserved0;
	unsigned int gpio0b_iomux;
	unsigned int reserved1;
	unsigned int gpio0c_iomux;
	unsigned int reserved2[3];
	unsigned int gpio1a_iomux;
	unsigned int reserved3;
	unsigned int gpio1bl_iomux;
	unsigned int gpio1bh_iomux;
	unsigned int gpio1cl_iomux;
	unsigned int gpio1ch_iomux;
	unsigned int gpio1d_iomux;
	unsigned int reserved4;
	unsigned int gpio2a_iomux;
	unsigned int reserved5;
	unsigned int gpio2b_iomux;
	unsigned int reserved6;
	unsigned int gpio2c_iomux;
	unsigned int reserved7[3];
	unsigned int gpio3a_iomux;
	unsigned int reserved8;
	unsigned int gpio3b_iomux;
	unsigned int reserved9[5];
	unsigned int gpio4a_iomux;
	unsigned int reserved33;
	unsigned int gpio4b_iomux;
	unsigned int reserved10;
	unsigned int gpio4c_iomux;
	unsigned int reserved11;
	unsigned int gpio4d_iomux;
	unsigned int reserved34;
	unsigned int gpio0a_p;
	unsigned int gpio0b_p;
	unsigned int gpio0c_p;
	unsigned int reserved12;
	unsigned int gpio1a_p;
	unsigned int gpio1b_p;
	unsigned int gpio1c_p;
	unsigned int gpio1d_p;
	unsigned int gpio2a_p;
	unsigned int gpio2b_p;
	unsigned int gpio2c_p;
	unsigned int reserved13;
	unsigned int gpio3a_p;
	unsigned int gpio3b_p;
	unsigned int reserved14[2];
	unsigned int gpio4a_p;
	unsigned int gpio4b_p;
	unsigned int gpio4c_p;
	unsigned int gpio4d_p;
	unsigned int reserved15[(0x100 - 0xec) / 4 - 1];
	unsigned int gpio0a_e;
	unsigned int gpio0b_e;
	unsigned int gpio0c_e;
	unsigned int reserved16;
	unsigned int gpio1a_e;
	unsigned int gpio1b_e;
	unsigned int gpio1c_e;
	unsigned int gpio1d_e;
	unsigned int gpio2a_e;
	unsigned int gpio2b_e;
	unsigned int gpio2c_e;
	unsigned int reserved17;
	unsigned int gpio3a_e;
	unsigned int gpio3b_e;
	unsigned int reserved18[2];
	unsigned int gpio4a_e;
	unsigned int gpio4b_e;
	unsigned int gpio4c_e;
	unsigned int gpio4d_e;
	unsigned int gpio0a_sr;
	unsigned int gpio0b_sr;
	unsigned int gpio0c_sr;
	unsigned int reserved19;
	unsigned int gpio1a_sr;
	unsigned int gpio1b_sr;
	unsigned int gpio1c_sr;
	unsigned int gpio1d_sr;
	unsigned int gpio2a_sr;
	unsigned int gpio2b_sr;
	unsigned int gpio2c_sr;
	unsigned int reserved20;
	unsigned int gpio3a_sr;
	unsigned int gpio3b_sr;
	unsigned int reserved21[2];
	unsigned int gpio4a_sr;
	unsigned int gpio4b_sr;
	unsigned int gpio4c_sr;
	unsigned int gpio4d_sr;
	unsigned int gpio0a_smt;
	unsigned int gpio0b_smt;
	unsigned int gpio0c_smt;
	unsigned int reserved22;
	unsigned int gpio1a_smt;
	unsigned int gpio1b_smt;
	unsigned int gpio1c_smt;
	unsigned int gpio1d_smt;
	unsigned int gpio2a_smt;
	unsigned int gpio2b_smt;
	unsigned int gpio2c_smt;
	unsigned int reserved23;
	unsigned int gpio3a_smt;
	unsigned int gpio3b_smt;
	unsigned int reserved35[2];
	unsigned int gpio4a_smt;
	unsigned int gpio4b_smt;
	unsigned int gpio4c_smt;
	unsigned int gpio4d_smt;
	unsigned int reserved24[(0x300 - 0x1EC) / 4 - 1];
	unsigned int soc_con0;
	unsigned int soc_con1;
	unsigned int soc_con2;
	unsigned int soc_con3;
	unsigned int soc_con4;
	unsigned int soc_con5;
	unsigned int soc_con6;
	unsigned int soc_con7;
	unsigned int soc_con8;
	unsigned int soc_con9;
	unsigned int soc_con10;
	unsigned int reserved25[(0x380 - 0x328) / 4 - 1];
	unsigned int soc_status0;
	unsigned int reserved26[(0x400 - 0x380) / 4 - 1];
	unsigned int cpu_con0;
	unsigned int cpu_con1;
	unsigned int cpu_con2;
	unsigned int reserved27[(0x420 - 0x408) / 4 - 1];
	unsigned int cpu_status0;
	unsigned int cpu_status1;
	unsigned int reserved28[(0x440 - 0x424) / 4 - 1];
	unsigned int pvtm_con0;
	unsigned int pvtm_con1;
	unsigned int pvtm_status0;
	unsigned int pvtm_status1;
	unsigned int reserved29[(0x460 - 0x44C) / 4 - 1];
	unsigned int tsadc_tbl;
	unsigned int tsadc_tbh;
	unsigned int reserved30[(0x480 - 0x464) / 4 - 1];
	unsigned int host0_con0;
	unsigned int host0_con1;
	unsigned int otg_con0;
	unsigned int host0_status0;
	unsigned int reserved31[(0x4a0 - 0x48C) / 4 - 1];
	unsigned int mac_con0;
	unsigned int upctrl_con0;
	unsigned int upctrl_status0;
	unsigned int reserved32[(0x500 - 0x4A8) / 4 - 1];
	unsigned int os_reg0;
	unsigned int os_reg1;
	unsigned int os_reg2;
	unsigned int os_reg3;
	unsigned int os_reg4;
	unsigned int os_reg5;
	unsigned int os_reg6;
	unsigned int os_reg7;
	unsigned int os_reg8;
	unsigned int os_reg9;
	unsigned int os_reg10;
	unsigned int os_reg11;
	unsigned int reserved38[(0x600 - 0x52c) / 4 - 1];
	unsigned int soc_con12;
	unsigned int reserved39;
	unsigned int soc_con13;
	unsigned int soc_con14;
	unsigned int soc_con15;
	unsigned int reserved40[(0x800 - 0x610) / 4 - 1];
	unsigned int chip_id;
};
check_member(rk3308_grf, gpio0a_p, 0xa0);

struct rk3308_sgrf {
	unsigned int soc_con0;
	unsigned int soc_con1;
	unsigned int con_tzma_r0size;
	unsigned int con_secure0;
	unsigned int reserved0;
	unsigned int clk_timer_en;
	unsigned int clkgat_con;
	unsigned int fastboot_addr;
	unsigned int fastboot_en;
	unsigned int reserved1[(0x30 - 0x24) / 4];
	unsigned int srst_con;
};
check_member(rk3308_sgrf, fastboot_en, 0x20);

#endif
