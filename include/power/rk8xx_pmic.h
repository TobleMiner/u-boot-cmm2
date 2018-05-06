/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2015 Google, Inc
 * Written by Simon Glass <sjg@chromium.org>
 */

#ifndef _PMIC_RK8XX_H_
#define _PMIC_RK8XX_H_

enum {
	REG_SECONDS			= 0x00,
	REG_MINUTES,
	REG_HOURS,
	REG_DAYS,
	REG_MONTHS,
	REG_YEARS,
	REG_WEEKS,
	REG_ALARM_SECONDS,
	REG_ALARM_MINUTES,
	REG_ALARM_HOURS,
	REG_ALARM_DAYS,
	REG_ALARM_MONTHS,
	REG_ALARM_YEARS,

	REG_RTC_CTRL			= 0x10,
	REG_RTC_STATUS,
	REG_RTC_INT,
	REG_RTC_COMP_LSB,
	REG_RTC_COMP_MSB,

	ID_MSB				= 0x17,
	ID_LSB,

	REG_CLK32OUT			= 0x20,
	REG_VB_MON,
	REG_THERMAL,
	REG_DCDC_EN,
	REG_LDO_EN,
	REG_SLEEP_SET_OFF1,
	REG_SLEEP_SET_OFF2,
	REG_DCDC_UV_STS,
	REG_DCDC_UV_ACT,
	REG_LDO_UV_STS,
	REG_LDO_UV_ACT,
	REG_DCDC_PG,
	REG_LDO_PG,
	REG_VOUT_MON_TDB,
	REG_BUCK1_CONFIG,
	REG_BUCK1_ON_VSEL,
	REG_BUCK1_SLP_VSEL,
	REG_BUCK1_DVS_VSEL,
	REG_BUCK2_CONFIG,
	REG_BUCK2_ON_VSEL,
	REG_BUCK2_SLP_VSEL,
	REG_BUCK2_DVS_VSEL,
	REG_BUCK3_CONFIG,
	REG_BUCK4_CONFIG,
	REG_BUCK4_ON_VSEL,
	REG_BUCK4_SLP_VSEL,
	REG_BOOST_CONFIG_REG,
	REG_LDO1_ON_VSEL,
	REG_LDO1_SLP_VSEL,
	REG_LDO2_ON_VSEL,
	REG_LDO2_SLP_VSEL,
	REG_LDO3_ON_VSEL,
	REG_LDO3_SLP_VSEL,
	REG_LDO4_ON_VSEL,
	REG_LDO4_SLP_VSEL,
	REG_LDO5_ON_VSEL,
	REG_LDO5_SLP_VSEL,
	REG_LDO6_ON_VSEL,
	REG_LDO6_SLP_VSEL,
	REG_LDO7_ON_VSEL,
	REG_LDO7_SLP_VSEL,
	REG_LDO8_ON_VSEL,
	REG_LDO8_SLP_VSEL,
	REG_DEVCTRL,
	REG_INT_STS1,
	REG_INT_STS_MSK1,
	REG_INT_STS2,
	REG_INT_STS_MSK2,
	REG_IO_POL,
	REG_OTP_VDD_EN,
	REG_H5V_EN,
	REG_SLEEP_SET_OFF,
	REG_BOOST_LDO9_ON_VSEL,
	REG_BOOST_LDO9_SLP_VSEL,
	REG_BOOST_CTRL,

	/* Not sure what this does */
	REG_DCDC_ILMAX			= 0x90,
	REG_CHRG_COMP			= 0x9a,
	REG_SUP_STS			= 0xa0,
	REG_USB_CTRL,
	REG1_CHRG_CTRL,
	REG2_CHRG_CTRL,
	REG3_CHRG_CTRL,
	REG_BAT_CTRL,
	REG_BAT_HTS_TS1,
	REG_BAT_LTS_TS1,
	REG_BAT_HTS_TS2,
	REG_BAT_LTS_TS2,
	REG_TS_CTRL,
	REG_ADC_CTRL,
	REG_ON_SOURCE,
	REG_OFF_SOURCE,
	REG_GGCON,
	REG_GGSTS,
	REG_FRAME_SMP_INTERV,
	REG_AUTO_SLP_CUR_THR,
	REG3_GASCNT_CAL,
	REG2_GASCNT_CAL,
	REG1_GASCNT_CAL,
	REG0_GASCNT_CAL,
	REG3_GASCNT,
	REG2_GASCNT,
	REG1_GASCNT,
	REG0_GASCNT,
	REGH_BAT_CUR_AVG,
	REGL_BAT_CUR_AVG,
	REGH_TS1_ADC,
	REGL_TS1_ADC,
	REGH_TS2_ADC,
	REGL_TS2_ADC,
	REGH_BAT_OCV,
	REGL_BAT_OCV,
	REGH_BAT_VOL,
	REGL_BAT_VOL,
	REGH_RELAX_ENTRY_THRES,
	REGL_RELAX_ENTRY_THRES,
	REGH_RELAX_EXIT_THRES,
	REGL_RELAX_EXIT_THRES,
	REGH_RELAX_VOL1,
	REGL_RELAX_VOL1,
	REGH_RELAX_VOL2,
	REGL_RELAX_VOL2,
	REGH_BAT_CUR_R_CALC,
	REGL_BAT_CUR_R_CALC,
	REGH_BAT_VOL_R_CALC,
	REGL_BAT_VOL_R_CALC,
	REGH_CAL_OFFSET,
	REGL_CAL_OFFSET,
	REG_NON_ACT_TIMER_CNT,
	REGH_VCALIB0,
	REGL_VCALIB0,
	REGH_VCALIB1,
	REGL_VCALIB1,
	REGH_IOFFSET,
	REGL_IOFFSET,
	REG_SOC,
	REG3_REMAIN_CAP,
	REG2_REMAIN_CAP,
	REG1_REMAIN_CAP,
	REG0_REMAIN_CAP,
	REG_UPDAT_LEVE,
	REG3_NEW_FCC,
	REG2_NEW_FCC,
	REG1_NEW_FCC,
	REG0_NEW_FCC,
	REG_NON_ACT_TIMER_CNT_SAVE,
	REG_OCV_VOL_VALID,
	REG_REBOOT_CNT,
	REG_POFFSET,
	REG_MISC_MARK,
	REG_HALT_CNT,
	REGH_CALC_REST,
	REGL_CALC_REST,
	SAVE_DATA19,
	RK808_NUM_OF_REGS,
};

enum {
	RK805_ID = 0x8050,
	RK808_ID = 0x0000,
	RK818_ID = 0x8180,
};

#define RK8XX_ID_MSK	0xfff0

struct rk8xx_reg_table {
	char *name;
	u8 reg_ctl;
	u8 reg_vol;
};

struct rk8xx_priv {
	int variant;
};

int rk8xx_spl_configure_buck(struct udevice *pmic, int buck, int uvolt);
int rk818_spl_configure_usb_input_current(struct udevice *pmic, int current_ma);
int rk818_spl_configure_usb_chrg_shutdown(struct udevice *pmic, int uvolt);

#endif
