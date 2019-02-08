// SPDX-License-Identifier: (GPL-2.0+ or MIT)
/*
 * (C) Copyright (C) 2019 Jerome Brunet <jbrunet@baylibre.com>
 *
 * Based on code from Linux kernel:
 * Copyright (c) 2018 Amlogic, Inc. All rights reserved.
 * Author: Xingyu Chen <xingyu.chen@amlogic.com>
 * Author: Yixun Lan <yixun.lan@amlogic.com>
 */

#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <dt-bindings/gpio/meson-g12a-gpio.h>

#include "pinctrl-meson-axg.h"

#define EE_OFF	15

/* emmc */
static const unsigned int emmc_nand_d0_pins[]		= { PIN(BOOT_0, EE_OFF) };
static const unsigned int emmc_nand_d1_pins[]		= { PIN(BOOT_1, EE_OFF) };
static const unsigned int emmc_nand_d2_pins[]		= { PIN(BOOT_2, EE_OFF) };
static const unsigned int emmc_nand_d3_pins[]		= { PIN(BOOT_3, EE_OFF) };
static const unsigned int emmc_nand_d4_pins[]		= { PIN(BOOT_4, EE_OFF) };
static const unsigned int emmc_nand_d5_pins[]		= { PIN(BOOT_5, EE_OFF) };
static const unsigned int emmc_nand_d6_pins[]		= { PIN(BOOT_6, EE_OFF) };
static const unsigned int emmc_nand_d7_pins[]		= { PIN(BOOT_7, EE_OFF) };
static const unsigned int emmc_clk_pins[]		= { PIN(BOOT_8, EE_OFF) };
static const unsigned int emmc_cmd_pins[]		= { PIN(BOOT_10, EE_OFF) };
static const unsigned int emmc_nand_ds_pins[]		= { PIN(BOOT_13, EE_OFF) };

/* nand */
static const unsigned int nand_wen_clk_pins[]		= { PIN(BOOT_8, EE_OFF) };
static const unsigned int nand_ale_pins[]		= { PIN(BOOT_9, EE_OFF) };
static const unsigned int nand_cle_pins[]		= { PIN(BOOT_10, EE_OFF) };
static const unsigned int nand_ce0_pins[]		= { PIN(BOOT_11, EE_OFF) };
static const unsigned int nand_ren_wr_pins[]		= { PIN(BOOT_12, EE_OFF) };
static const unsigned int nand_rb0_pins[]		= { PIN(BOOT_14, EE_OFF) };
static const unsigned int nand_ce1_pins[]		= { PIN(BOOT_15, EE_OFF) };

/* nor */
static const unsigned int nor_hold_pins[]		= { PIN(BOOT_3, EE_OFF) };
static const unsigned int nor_d_pins[]			= { PIN(BOOT_4, EE_OFF) };
static const unsigned int nor_q_pins[]			= { PIN(BOOT_5, EE_OFF) };
static const unsigned int nor_c_pins[]			= { PIN(BOOT_6, EE_OFF) };
static const unsigned int nor_wp_pins[]			= { PIN(BOOT_7, EE_OFF) };
static const unsigned int nor_cs_pins[]			= { PIN(BOOT_14, EE_OFF) };

/* sdio */
static const unsigned int sdio_d0_pins[]		= { PIN(GPIOX_0, EE_OFF) };
static const unsigned int sdio_d1_pins[]		= { PIN(GPIOX_1, EE_OFF) };
static const unsigned int sdio_d2_pins[]		= { PIN(GPIOX_2, EE_OFF) };
static const unsigned int sdio_d3_pins[]		= { PIN(GPIOX_3, EE_OFF) };
static const unsigned int sdio_clk_pins[]		= { PIN(GPIOX_4, EE_OFF) };
static const unsigned int sdio_cmd_pins[]		= { PIN(GPIOX_5, EE_OFF) };

/* sdcard */
static const unsigned int sdcard_d0_c_pins[]		= { PIN(GPIOC_0, EE_OFF) };
static const unsigned int sdcard_d1_c_pins[]		= { PIN(GPIOC_1, EE_OFF) };
static const unsigned int sdcard_d2_c_pins[]		= { PIN(GPIOC_2, EE_OFF) };
static const unsigned int sdcard_d3_c_pins[]		= { PIN(GPIOC_3, EE_OFF) };
static const unsigned int sdcard_clk_c_pins[]		= { PIN(GPIOC_4, EE_OFF) };
static const unsigned int sdcard_cmd_c_pins[]		= { PIN(GPIOC_5, EE_OFF) };

static const unsigned int sdcard_d0_z_pins[]		= { PIN(GPIOZ_2, EE_OFF) };
static const unsigned int sdcard_d1_z_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int sdcard_d2_z_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int sdcard_d3_z_pins[]		= { PIN(GPIOZ_5, EE_OFF) };
static const unsigned int sdcard_clk_z_pins[]		= { PIN(GPIOZ_6, EE_OFF) };
static const unsigned int sdcard_cmd_z_pins[]		= { PIN(GPIOZ_7, EE_OFF) };

/* spi0 */
static const unsigned int spi0_mosi_c_pins[]		= { PIN(GPIOC_0, EE_OFF) };
static const unsigned int spi0_miso_c_pins[]		= { PIN(GPIOC_1, EE_OFF) };
static const unsigned int spi0_ss0_c_pins[]		= { PIN(GPIOC_2, EE_OFF) };
static const unsigned int spi0_clk_c_pins[]		= { PIN(GPIOC_3, EE_OFF) };

static const unsigned int spi0_mosi_x_pins[]		= { PIN(GPIOX_8, EE_OFF) };
static const unsigned int spi0_miso_x_pins[]		= { PIN(GPIOX_9, EE_OFF) };
static const unsigned int spi0_ss0_x_pins[]		= { PIN(GPIOX_10, EE_OFF) };
static const unsigned int spi0_clk_x_pins[]		= { PIN(GPIOX_11, EE_OFF) };

/* spi1 */
static const unsigned int spi1_mosi_pins[]		= { PIN(GPIOH_4, EE_OFF) };
static const unsigned int spi1_miso_pins[]		= { PIN(GPIOH_5, EE_OFF) };
static const unsigned int spi1_ss0_pins[]		= { PIN(GPIOH_6, EE_OFF) };
static const unsigned int spi1_clk_pins[]		= { PIN(GPIOH_7, EE_OFF) };

/* i2c0 */
static const unsigned int i2c0_sda_c_pins[]		= { PIN(GPIOC_5, EE_OFF) };
static const unsigned int i2c0_sck_c_pins[]		= { PIN(GPIOC_6, EE_OFF) };
static const unsigned int i2c0_sda_z0_pins[]		= { PIN(GPIOZ_0, EE_OFF) };
static const unsigned int i2c0_sck_z1_pins[]		= { PIN(GPIOZ_1, EE_OFF) };
static const unsigned int i2c0_sda_z7_pins[]		= { PIN(GPIOZ_7, EE_OFF) };
static const unsigned int i2c0_sck_z8_pins[]		= { PIN(GPIOZ_8, EE_OFF) };

/* i2c1 */
static const unsigned int i2c1_sda_x_pins[]		= { PIN(GPIOX_10, EE_OFF) };
static const unsigned int i2c1_sck_x_pins[]		= { PIN(GPIOX_11, EE_OFF) };
static const unsigned int i2c1_sda_h2_pins[]		= { PIN(GPIOH_2, EE_OFF) };
static const unsigned int i2c1_sck_h3_pins[]		= { PIN(GPIOH_3, EE_OFF) };
static const unsigned int i2c1_sda_h6_pins[]		= { PIN(GPIOH_6, EE_OFF) };
static const unsigned int i2c1_sck_h7_pins[]		= { PIN(GPIOH_7, EE_OFF) };

/* i2c2 */
static const unsigned int i2c2_sda_x_pins[]		= { PIN(GPIOX_17, EE_OFF) };
static const unsigned int i2c2_sck_x_pins[]		= { PIN(GPIOX_18, EE_OFF) };
static const unsigned int i2c2_sda_z_pins[]		= { PIN(GPIOZ_14, EE_OFF) };
static const unsigned int i2c2_sck_z_pins[]		= { PIN(GPIOZ_15, EE_OFF) };

/* i2c3 */
static const unsigned int i2c3_sda_h_pins[]		= { PIN(GPIOH_0, EE_OFF) };
static const unsigned int i2c3_sck_h_pins[]		= { PIN(GPIOH_1, EE_OFF) };
static const unsigned int i2c3_sda_a_pins[]		= { PIN(GPIOA_14, EE_OFF) };
static const unsigned int i2c3_sck_a_pins[]		= { PIN(GPIOA_15, EE_OFF) };

/* uart_a */
static const unsigned int uart_a_tx_pins[]		= { PIN(GPIOX_12, EE_OFF) };
static const unsigned int uart_a_rx_pins[]		= { PIN(GPIOX_13, EE_OFF) };
static const unsigned int uart_a_cts_pins[]		= { PIN(GPIOX_14, EE_OFF) };
static const unsigned int uart_a_rts_pins[]		= { PIN(GPIOX_15, EE_OFF) };

/* uart_b */
static const unsigned int uart_b_tx_pins[]		= { PIN(GPIOX_6, EE_OFF) };
static const unsigned int uart_b_rx_pins[]		= { PIN(GPIOX_7, EE_OFF) };

/* uart_c */
static const unsigned int uart_c_rts_pins[]		= { PIN(GPIOH_4, EE_OFF) };
static const unsigned int uart_c_cts_pins[]		= { PIN(GPIOH_5, EE_OFF) };
static const unsigned int uart_c_rx_pins[]		= { PIN(GPIOH_6, EE_OFF) };
static const unsigned int uart_c_tx_pins[]		= { PIN(GPIOH_7, EE_OFF) };

/* uart_ao_a_c */
static const unsigned int uart_ao_a_rx_c_pins[]		= { PIN(GPIOC_2, EE_OFF) };
static const unsigned int uart_ao_a_tx_c_pins[]		= { PIN(GPIOC_3, EE_OFF) };

/* iso7816 */
static const unsigned int iso7816_clk_c_pins[]		= { PIN(GPIOC_5, EE_OFF) };
static const unsigned int iso7816_data_c_pins[]		= { PIN(GPIOC_6, EE_OFF) };
static const unsigned int iso7816_clk_x_pins[]		= { PIN(GPIOX_8, EE_OFF) };
static const unsigned int iso7816_data_x_pins[]		= { PIN(GPIOX_9, EE_OFF) };
static const unsigned int iso7816_clk_h_pins[]		= { PIN(GPIOH_6, EE_OFF) };
static const unsigned int iso7816_data_h_pins[]		= { PIN(GPIOH_7, EE_OFF) };
static const unsigned int iso7816_clk_z_pins[]		= { PIN(GPIOZ_0, EE_OFF) };
static const unsigned int iso7816_data_z_pins[]		= { PIN(GPIOZ_1, EE_OFF) };

/* eth */
static const unsigned int eth_mdio_pins[]		= { PIN(GPIOZ_0, EE_OFF) };
static const unsigned int eth_mdc_pins[]		= { PIN(GPIOZ_1, EE_OFF) };
static const unsigned int eth_rgmii_rx_clk_pins[]	= { PIN(GPIOZ_2, EE_OFF) };
static const unsigned int eth_rx_dv_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int eth_rxd0_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int eth_rxd1_pins[]		= { PIN(GPIOZ_5, EE_OFF) };
static const unsigned int eth_rxd2_rgmii_pins[]		= { PIN(GPIOZ_6, EE_OFF) };
static const unsigned int eth_rxd3_rgmii_pins[]		= { PIN(GPIOZ_7, EE_OFF) };
static const unsigned int eth_rgmii_tx_clk_pins[]	= { PIN(GPIOZ_8, EE_OFF) };
static const unsigned int eth_txen_pins[]		= { PIN(GPIOZ_9, EE_OFF) };
static const unsigned int eth_txd0_pins[]		= { PIN(GPIOZ_10, EE_OFF) };
static const unsigned int eth_txd1_pins[]		= { PIN(GPIOZ_11, EE_OFF) };
static const unsigned int eth_txd2_rgmii_pins[]		= { PIN(GPIOZ_12, EE_OFF) };
static const unsigned int eth_txd3_rgmii_pins[]		= { PIN(GPIOZ_13, EE_OFF) };
static const unsigned int eth_link_led_pins[]		= { PIN(GPIOZ_14, EE_OFF) };
static const unsigned int eth_act_led_pins[]		= { PIN(GPIOZ_15, EE_OFF) };

/* pwm_a */
static const unsigned int pwm_a_pins[]			= { PIN(GPIOX_6, EE_OFF) };

/* pwm_b */
static const unsigned int pwm_b_x7_pins[]		= { PIN(GPIOX_7, EE_OFF) };
static const unsigned int pwm_b_x19_pins[]		= { PIN(GPIOX_19, EE_OFF) };

/* pwm_c */
static const unsigned int pwm_c_c_pins[]		= { PIN(GPIOC_4, EE_OFF) };
static const unsigned int pwm_c_x5_pins[]		= { PIN(GPIOX_5, EE_OFF) };
static const unsigned int pwm_c_x8_pins[]		= { PIN(GPIOX_8, EE_OFF) };

/* pwm_d */
static const unsigned int pwm_d_x3_pins[]		= { PIN(GPIOX_3, EE_OFF) };
static const unsigned int pwm_d_x6_pins[]		= { PIN(GPIOX_6, EE_OFF) };

/* pwm_e */
static const unsigned int pwm_e_pins[]			= { PIN(GPIOX_16, EE_OFF) };

/* pwm_f */
static const unsigned int pwm_f_x_pins[]		= { PIN(GPIOX_7, EE_OFF) };
static const unsigned int pwm_f_h_pins[]		= { PIN(GPIOH_5, EE_OFF) };

/* cec_ao */
static const unsigned int cec_ao_a_h_pins[]		= { PIN(GPIOH_3, EE_OFF) };
static const unsigned int cec_ao_b_h_pins[]		= { PIN(GPIOH_3, EE_OFF) };

/* jtag_b */
static const unsigned int jtag_b_tdo_pins[]		= { PIN(GPIOC_0, EE_OFF) };
static const unsigned int jtag_b_tdi_pins[]		= { PIN(GPIOC_1, EE_OFF) };
static const unsigned int jtag_b_clk_pins[]		= { PIN(GPIOC_4, EE_OFF) };
static const unsigned int jtag_b_tms_pins[]		= { PIN(GPIOC_5, EE_OFF) };

/* bt565_a */
static const unsigned int bt565_a_vs_pins[]		= { PIN(GPIOZ_0, EE_OFF) };
static const unsigned int bt565_a_hs_pins[]		= { PIN(GPIOZ_1, EE_OFF) };
static const unsigned int bt565_a_clk_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int bt565_a_din0_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int bt565_a_din1_pins[]		= { PIN(GPIOZ_5, EE_OFF) };
static const unsigned int bt565_a_din2_pins[]		= { PIN(GPIOZ_6, EE_OFF) };
static const unsigned int bt565_a_din3_pins[]		= { PIN(GPIOZ_7, EE_OFF) };
static const unsigned int bt565_a_din4_pins[]		= { PIN(GPIOZ_8, EE_OFF) };
static const unsigned int bt565_a_din5_pins[]		= { PIN(GPIOZ_9, EE_OFF) };
static const unsigned int bt565_a_din6_pins[]		= { PIN(GPIOZ_10, EE_OFF) };
static const unsigned int bt565_a_din7_pins[]		= { PIN(GPIOZ_11, EE_OFF) };

/* tsin_a */
static const unsigned int tsin_a_valid_pins[]		= { PIN(GPIOX_2, EE_OFF) };
static const unsigned int tsin_a_sop_pins[]		= { PIN(GPIOX_1, EE_OFF) };
static const unsigned int tsin_a_din0_pins[]		= { PIN(GPIOX_0, EE_OFF) };
static const unsigned int tsin_a_clk_pins[]		= { PIN(GPIOX_3, EE_OFF) };

/* tsin_b */
static const unsigned int tsin_b_valid_x_pins[]		= { PIN(GPIOX_9, EE_OFF) };
static const unsigned int tsin_b_sop_x_pins[]		= { PIN(GPIOX_8, EE_OFF) };
static const unsigned int tsin_b_din0_x_pins[]		= { PIN(GPIOX_10, EE_OFF) };
static const unsigned int tsin_b_clk_x_pins[]		= { PIN(GPIOX_11, EE_OFF) };

static const unsigned int tsin_b_valid_z_pins[]		= { PIN(GPIOZ_2, EE_OFF) };
static const unsigned int tsin_b_sop_z_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int tsin_b_din0_z_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int tsin_b_clk_z_pins[]		= { PIN(GPIOZ_5, EE_OFF) };

static const unsigned int tsin_b_fail_pins[]		= { PIN(GPIOZ_6, EE_OFF) };
static const unsigned int tsin_b_din1_pins[]		= { PIN(GPIOZ_7, EE_OFF) };
static const unsigned int tsin_b_din2_pins[]		= { PIN(GPIOZ_8, EE_OFF) };
static const unsigned int tsin_b_din3_pins[]		= { PIN(GPIOZ_9, EE_OFF) };
static const unsigned int tsin_b_din4_pins[]		= { PIN(GPIOZ_10, EE_OFF) };
static const unsigned int tsin_b_din5_pins[]		= { PIN(GPIOZ_11, EE_OFF) };
static const unsigned int tsin_b_din6_pins[]		= { PIN(GPIOZ_12, EE_OFF) };
static const unsigned int tsin_b_din7_pins[]		= { PIN(GPIOZ_13, EE_OFF) };

/* hdmitx */
static const unsigned int hdmitx_sda_pins[]		= { PIN(GPIOH_0, EE_OFF) };
static const unsigned int hdmitx_sck_pins[]		= { PIN(GPIOH_1, EE_OFF) };
static const unsigned int hdmitx_hpd_in_pins[]		= { PIN(GPIOH_2, EE_OFF) };

/* pdm */
static const unsigned int pdm_din0_c_pins[]		= { PIN(GPIOC_0, EE_OFF) };
static const unsigned int pdm_din1_c_pins[]		= { PIN(GPIOC_1, EE_OFF) };
static const unsigned int pdm_din2_c_pins[]		= { PIN(GPIOC_2, EE_OFF) };
static const unsigned int pdm_din3_c_pins[]		= { PIN(GPIOC_3, EE_OFF) };
static const unsigned int pdm_dclk_c_pins[]		= { PIN(GPIOC_4, EE_OFF) };

static const unsigned int pdm_din0_x_pins[]		= { PIN(GPIOX_0, EE_OFF) };
static const unsigned int pdm_din1_x_pins[]		= { PIN(GPIOX_1, EE_OFF) };
static const unsigned int pdm_din2_x_pins[]		= { PIN(GPIOX_2, EE_OFF) };
static const unsigned int pdm_din3_x_pins[]		= { PIN(GPIOX_3, EE_OFF) };
static const unsigned int pdm_dclk_x_pins[]		= { PIN(GPIOX_4, EE_OFF) };

static const unsigned int pdm_din0_z_pins[]		= { PIN(GPIOZ_2, EE_OFF) };
static const unsigned int pdm_din1_z_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int pdm_din2_z_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int pdm_din3_z_pins[]		= { PIN(GPIOZ_5, EE_OFF) };
static const unsigned int pdm_dclk_z_pins[]		= { PIN(GPIOZ_6, EE_OFF) };

static const unsigned int pdm_din0_a_pins[]		= { PIN(GPIOA_8, EE_OFF) };
static const unsigned int pdm_din1_a_pins[]		= { PIN(GPIOA_9, EE_OFF) };
static const unsigned int pdm_din2_a_pins[]		= { PIN(GPIOA_6, EE_OFF) };
static const unsigned int pdm_din3_a_pins[]		= { PIN(GPIOA_5, EE_OFF) };
static const unsigned int pdm_dclk_a_pins[]		= { PIN(GPIOA_7, EE_OFF) };

/* spdif_in */
static const unsigned int spdif_in_h_pins[]		= { PIN(GPIOH_5, EE_OFF) };
static const unsigned int spdif_in_a10_pins[]		= { PIN(GPIOA_10, EE_OFF) };
static const unsigned int spdif_in_a12_pins[]		= { PIN(GPIOA_12, EE_OFF) };

/* spdif_out */
static const unsigned int spdif_out_h_pins[]		= { PIN(GPIOH_4, EE_OFF) };
static const unsigned int spdif_out_a11_pins[]		= { PIN(GPIOA_11, EE_OFF) };
static const unsigned int spdif_out_a13_pins[]		= { PIN(GPIOA_13, EE_OFF) };

/* mclk0 */
static const unsigned int mclk0_a_pins[]		= { PIN(GPIOA_0, EE_OFF) };

/* mclk1 */
static const unsigned int mclk1_x_pins[]		= { PIN(GPIOX_5, EE_OFF) };
static const unsigned int mclk1_z_pins[]		= { PIN(GPIOZ_8, EE_OFF) };
static const unsigned int mclk1_a_pins[]		= { PIN(GPIOA_11, EE_OFF) };

/* tdm */
static const unsigned int tdm_a_slv_sclk_pins[]		= { PIN(GPIOX_11, EE_OFF) };
static const unsigned int tdm_a_slv_fs_pins[]		= { PIN(GPIOX_10, EE_OFF) };
static const unsigned int tdm_a_sclk_pins[]		= { PIN(GPIOX_11, EE_OFF) };
static const unsigned int tdm_a_fs_pins[]		= { PIN(GPIOX_10, EE_OFF) };
static const unsigned int tdm_a_din0_pins[]		= { PIN(GPIOX_9, EE_OFF) };
static const unsigned int tdm_a_din1_pins[]		= { PIN(GPIOX_8, EE_OFF) };
static const unsigned int tdm_a_dout0_pins[]		= { PIN(GPIOX_9, EE_OFF) };
static const unsigned int tdm_a_dout1_pins[]		= { PIN(GPIOX_8, EE_OFF) };

static const unsigned int tdm_b_slv_sclk_pins[]		= { PIN(GPIOA_1, EE_OFF) };
static const unsigned int tdm_b_slv_fs_pins[]		= { PIN(GPIOA_2, EE_OFF) };
static const unsigned int tdm_b_sclk_pins[]		= { PIN(GPIOA_1, EE_OFF) };
static const unsigned int tdm_b_fs_pins[]		= { PIN(GPIOA_2, EE_OFF) };
static const unsigned int tdm_b_din0_pins[]		= { PIN(GPIOA_3, EE_OFF) };
static const unsigned int tdm_b_din1_pins[]		= { PIN(GPIOA_4, EE_OFF) };
static const unsigned int tdm_b_din2_pins[]		= { PIN(GPIOA_5, EE_OFF) };
static const unsigned int tdm_b_din3_a_pins[]		= { PIN(GPIOA_6, EE_OFF) };
static const unsigned int tdm_b_din3_h_pins[]		= { PIN(GPIOH_5, EE_OFF) };
static const unsigned int tdm_b_dout0_pins[]		= { PIN(GPIOA_3, EE_OFF) };
static const unsigned int tdm_b_dout1_pins[]		= { PIN(GPIOA_4, EE_OFF) };
static const unsigned int tdm_b_dout2_pins[]		= { PIN(GPIOA_5, EE_OFF) };
static const unsigned int tdm_b_dout3_a_pins[]		= { PIN(GPIOA_6, EE_OFF) };
static const unsigned int tdm_b_dout3_h_pins[]		= { PIN(GPIOH_5, EE_OFF) };

static const unsigned int tdm_c_slv_sclk_a_pins[]	= { PIN(GPIOA_12, EE_OFF) };
static const unsigned int tdm_c_slv_fs_a_pins[]		= { PIN(GPIOA_13, EE_OFF) };
static const unsigned int tdm_c_slv_sclk_z_pins[]	= { PIN(GPIOZ_7, EE_OFF) };
static const unsigned int tdm_c_slv_fs_z_pins[]		= { PIN(GPIOZ_6, EE_OFF) };
static const unsigned int tdm_c_sclk_a_pins[]		= { PIN(GPIOA_12, EE_OFF) };
static const unsigned int tdm_c_fs_a_pins[]		= { PIN(GPIOA_13, EE_OFF) };
static const unsigned int tdm_c_sclk_z_pins[]		= { PIN(GPIOZ_7, EE_OFF) };
static const unsigned int tdm_c_fs_z_pins[]		= { PIN(GPIOZ_6, EE_OFF) };
static const unsigned int tdm_c_din0_a_pins[]		= { PIN(GPIOA_10, EE_OFF) };
static const unsigned int tdm_c_din1_a_pins[]		= { PIN(GPIOA_9, EE_OFF) };
static const unsigned int tdm_c_din2_a_pins[]		= { PIN(GPIOA_8, EE_OFF) };
static const unsigned int tdm_c_din3_a_pins[]		= { PIN(GPIOA_7, EE_OFF) };
static const unsigned int tdm_c_din0_z_pins[]		= { PIN(GPIOZ_2, EE_OFF) };
static const unsigned int tdm_c_din1_z_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int tdm_c_din2_z_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int tdm_c_din3_z_pins[]		= { PIN(GPIOZ_5, EE_OFF) };
static const unsigned int tdm_c_dout0_a_pins[]		= { PIN(GPIOA_10, EE_OFF) };
static const unsigned int tdm_c_dout1_a_pins[]		= { PIN(GPIOA_9, EE_OFF) };
static const unsigned int tdm_c_dout2_a_pins[]		= { PIN(GPIOA_8, EE_OFF) };
static const unsigned int tdm_c_dout3_a_pins[]		= { PIN(GPIOA_7, EE_OFF) };
static const unsigned int tdm_c_dout0_z_pins[]		= { PIN(GPIOZ_2, EE_OFF) };
static const unsigned int tdm_c_dout1_z_pins[]		= { PIN(GPIOZ_3, EE_OFF) };
static const unsigned int tdm_c_dout2_z_pins[]		= { PIN(GPIOZ_4, EE_OFF) };
static const unsigned int tdm_c_dout3_z_pins[]		= { PIN(GPIOZ_5, EE_OFF) };

static struct meson_pmx_group meson_g12a_periphs_groups[] = {
	GPIO_GROUP(GPIOZ_0, EE_OFF),
	GPIO_GROUP(GPIOZ_1, EE_OFF),
	GPIO_GROUP(GPIOZ_2, EE_OFF),
	GPIO_GROUP(GPIOZ_3, EE_OFF),
	GPIO_GROUP(GPIOZ_4, EE_OFF),
	GPIO_GROUP(GPIOZ_5, EE_OFF),
	GPIO_GROUP(GPIOZ_6, EE_OFF),
	GPIO_GROUP(GPIOZ_7, EE_OFF),
	GPIO_GROUP(GPIOZ_8, EE_OFF),
	GPIO_GROUP(GPIOZ_9, EE_OFF),
	GPIO_GROUP(GPIOZ_10, EE_OFF),
	GPIO_GROUP(GPIOZ_11, EE_OFF),
	GPIO_GROUP(GPIOZ_12, EE_OFF),
	GPIO_GROUP(GPIOZ_13, EE_OFF),
	GPIO_GROUP(GPIOZ_14, EE_OFF),
	GPIO_GROUP(GPIOZ_15, EE_OFF),
	GPIO_GROUP(GPIOH_0, EE_OFF),
	GPIO_GROUP(GPIOH_1, EE_OFF),
	GPIO_GROUP(GPIOH_2, EE_OFF),
	GPIO_GROUP(GPIOH_3, EE_OFF),
	GPIO_GROUP(GPIOH_4, EE_OFF),
	GPIO_GROUP(GPIOH_5, EE_OFF),
	GPIO_GROUP(GPIOH_6, EE_OFF),
	GPIO_GROUP(GPIOH_7, EE_OFF),
	GPIO_GROUP(GPIOH_8, EE_OFF),
	GPIO_GROUP(BOOT_0, EE_OFF),
	GPIO_GROUP(BOOT_1, EE_OFF),
	GPIO_GROUP(BOOT_2, EE_OFF),
	GPIO_GROUP(BOOT_3, EE_OFF),
	GPIO_GROUP(BOOT_4, EE_OFF),
	GPIO_GROUP(BOOT_5, EE_OFF),
	GPIO_GROUP(BOOT_6, EE_OFF),
	GPIO_GROUP(BOOT_7, EE_OFF),
	GPIO_GROUP(BOOT_8, EE_OFF),
	GPIO_GROUP(BOOT_9, EE_OFF),
	GPIO_GROUP(BOOT_10, EE_OFF),
	GPIO_GROUP(BOOT_11, EE_OFF),
	GPIO_GROUP(BOOT_12, EE_OFF),
	GPIO_GROUP(BOOT_13, EE_OFF),
	GPIO_GROUP(BOOT_14, EE_OFF),
	GPIO_GROUP(BOOT_15, EE_OFF),
	GPIO_GROUP(GPIOC_0, EE_OFF),
	GPIO_GROUP(GPIOC_1, EE_OFF),
	GPIO_GROUP(GPIOC_2, EE_OFF),
	GPIO_GROUP(GPIOC_3, EE_OFF),
	GPIO_GROUP(GPIOC_4, EE_OFF),
	GPIO_GROUP(GPIOC_5, EE_OFF),
	GPIO_GROUP(GPIOC_6, EE_OFF),
	GPIO_GROUP(GPIOC_7, EE_OFF),
	GPIO_GROUP(GPIOA_0, EE_OFF),
	GPIO_GROUP(GPIOA_1, EE_OFF),
	GPIO_GROUP(GPIOA_2, EE_OFF),
	GPIO_GROUP(GPIOA_3, EE_OFF),
	GPIO_GROUP(GPIOA_4, EE_OFF),
	GPIO_GROUP(GPIOA_5, EE_OFF),
	GPIO_GROUP(GPIOA_6, EE_OFF),
	GPIO_GROUP(GPIOA_7, EE_OFF),
	GPIO_GROUP(GPIOA_8, EE_OFF),
	GPIO_GROUP(GPIOA_9, EE_OFF),
	GPIO_GROUP(GPIOA_10, EE_OFF),
	GPIO_GROUP(GPIOA_11, EE_OFF),
	GPIO_GROUP(GPIOA_12, EE_OFF),
	GPIO_GROUP(GPIOA_13, EE_OFF),
	GPIO_GROUP(GPIOA_14, EE_OFF),
	GPIO_GROUP(GPIOA_15, EE_OFF),
	GPIO_GROUP(GPIOX_0, EE_OFF),
	GPIO_GROUP(GPIOX_1, EE_OFF),
	GPIO_GROUP(GPIOX_2, EE_OFF),
	GPIO_GROUP(GPIOX_3, EE_OFF),
	GPIO_GROUP(GPIOX_4, EE_OFF),
	GPIO_GROUP(GPIOX_5, EE_OFF),
	GPIO_GROUP(GPIOX_6, EE_OFF),
	GPIO_GROUP(GPIOX_7, EE_OFF),
	GPIO_GROUP(GPIOX_8, EE_OFF),
	GPIO_GROUP(GPIOX_9, EE_OFF),
	GPIO_GROUP(GPIOX_10, EE_OFF),
	GPIO_GROUP(GPIOX_11, EE_OFF),
	GPIO_GROUP(GPIOX_12, EE_OFF),
	GPIO_GROUP(GPIOX_13, EE_OFF),
	GPIO_GROUP(GPIOX_14, EE_OFF),
	GPIO_GROUP(GPIOX_15, EE_OFF),
	GPIO_GROUP(GPIOX_16, EE_OFF),
	GPIO_GROUP(GPIOX_17, EE_OFF),
	GPIO_GROUP(GPIOX_18, EE_OFF),
	GPIO_GROUP(GPIOX_19, EE_OFF),

	/* bank BOOT */
	GROUP(emmc_nand_d0,		1),
	GROUP(emmc_nand_d1,		1),
	GROUP(emmc_nand_d2,		1),
	GROUP(emmc_nand_d3,		1),
	GROUP(emmc_nand_d4,		1),
	GROUP(emmc_nand_d5,		1),
	GROUP(emmc_nand_d6,		1),
	GROUP(emmc_nand_d7,		1),
	GROUP(emmc_clk,			1),
	GROUP(emmc_cmd,			1),
	GROUP(emmc_nand_ds,		1),
	GROUP(nand_ce0,			2),
	GROUP(nand_ale,			2),
	GROUP(nand_cle,			2),
	GROUP(nand_wen_clk,		2),
	GROUP(nand_ren_wr,		2),
	GROUP(nand_rb0,			2),
	GROUP(nand_ce1,			2),
	GROUP(nor_hold,			3),
	GROUP(nor_d,			3),
	GROUP(nor_q,			3),
	GROUP(nor_c,			3),
	GROUP(nor_wp,			3),
	GROUP(nor_cs,			3),

	/* bank GPIOZ */
	GROUP(sdcard_d0_z,		5),
	GROUP(sdcard_d1_z,		5),
	GROUP(sdcard_d2_z,		5),
	GROUP(sdcard_d3_z,		5),
	GROUP(sdcard_clk_z,		5),
	GROUP(sdcard_cmd_z,		5),
	GROUP(i2c0_sda_z0,		4),
	GROUP(i2c0_sck_z1,		4),
	GROUP(i2c0_sda_z7,		7),
	GROUP(i2c0_sck_z8,		7),
	GROUP(i2c2_sda_z,		3),
	GROUP(i2c2_sck_z,		3),
	GROUP(iso7816_clk_z,		3),
	GROUP(iso7816_data_z,		3),
	GROUP(eth_mdio,			1),
	GROUP(eth_mdc,			1),
	GROUP(eth_rgmii_rx_clk,		1),
	GROUP(eth_rx_dv,		1),
	GROUP(eth_rxd0,			1),
	GROUP(eth_rxd1,			1),
	GROUP(eth_rxd2_rgmii,		1),
	GROUP(eth_rxd3_rgmii,		1),
	GROUP(eth_rgmii_tx_clk,		1),
	GROUP(eth_txen,			1),
	GROUP(eth_txd0,			1),
	GROUP(eth_txd1,			1),
	GROUP(eth_txd2_rgmii,		1),
	GROUP(eth_txd3_rgmii,		1),
	GROUP(eth_link_led,		1),
	GROUP(eth_act_led,		1),
	GROUP(bt565_a_vs,		2),
	GROUP(bt565_a_hs,		2),
	GROUP(bt565_a_clk,		2),
	GROUP(bt565_a_din0,		2),
	GROUP(bt565_a_din1,		2),
	GROUP(bt565_a_din2,		2),
	GROUP(bt565_a_din3,		2),
	GROUP(bt565_a_din4,		2),
	GROUP(bt565_a_din5,		2),
	GROUP(bt565_a_din6,		2),
	GROUP(bt565_a_din7,		2),
	GROUP(tsin_b_valid_z,		3),
	GROUP(tsin_b_sop_z,		3),
	GROUP(tsin_b_din0_z,		3),
	GROUP(tsin_b_clk_z,		3),
	GROUP(tsin_b_fail,		3),
	GROUP(tsin_b_din1,		3),
	GROUP(tsin_b_din2,		3),
	GROUP(tsin_b_din3,		3),
	GROUP(tsin_b_din4,		3),
	GROUP(tsin_b_din5,		3),
	GROUP(tsin_b_din6,		3),
	GROUP(tsin_b_din7,		3),
	GROUP(pdm_din0_z,		7),
	GROUP(pdm_din1_z,		7),
	GROUP(pdm_din2_z,		7),
	GROUP(pdm_din3_z,		7),
	GROUP(pdm_dclk_z,		7),
	GROUP(tdm_c_slv_sclk_z,		6),
	GROUP(tdm_c_slv_fs_z,		6),
	GROUP(tdm_c_din0_z,		6),
	GROUP(tdm_c_din1_z,		6),
	GROUP(tdm_c_din2_z,		6),
	GROUP(tdm_c_din3_z,		6),
	GROUP(tdm_c_sclk_z,		4),
	GROUP(tdm_c_fs_z,		4),
	GROUP(tdm_c_dout0_z,		4),
	GROUP(tdm_c_dout1_z,		4),
	GROUP(tdm_c_dout2_z,		4),
	GROUP(tdm_c_dout3_z,		4),
	GROUP(mclk1_z,			4),

	/* bank GPIOX */
	GROUP(sdio_d0,			1),
	GROUP(sdio_d1,			1),
	GROUP(sdio_d2,			1),
	GROUP(sdio_d3,			1),
	GROUP(sdio_clk,			1),
	GROUP(sdio_cmd,			1),
	GROUP(spi0_mosi_x,		4),
	GROUP(spi0_miso_x,		4),
	GROUP(spi0_ss0_x,		4),
	GROUP(spi0_clk_x,		4),
	GROUP(i2c1_sda_x,		5),
	GROUP(i2c1_sck_x,		5),
	GROUP(i2c2_sda_x,		1),
	GROUP(i2c2_sck_x,		1),
	GROUP(uart_a_tx,		1),
	GROUP(uart_a_rx,		1),
	GROUP(uart_a_cts,		1),
	GROUP(uart_a_rts,		1),
	GROUP(uart_b_tx,		2),
	GROUP(uart_b_rx,		2),
	GROUP(iso7816_clk_x,		6),
	GROUP(iso7816_data_x,		6),
	GROUP(pwm_a,			1),
	GROUP(pwm_b_x7,			4),
	GROUP(pwm_b_x19,		1),
	GROUP(pwm_c_x5,			4),
	GROUP(pwm_c_x8,			5),
	GROUP(pwm_d_x3,			4),
	GROUP(pwm_d_x6,			4),
	GROUP(pwm_e,			1),
	GROUP(pwm_f_x,			1),
	GROUP(tsin_a_valid,		3),
	GROUP(tsin_a_sop,		3),
	GROUP(tsin_a_din0,		3),
	GROUP(tsin_a_clk,		3),
	GROUP(tsin_b_valid_x,		3),
	GROUP(tsin_b_sop_x,		3),
	GROUP(tsin_b_din0_x,		3),
	GROUP(tsin_b_clk_x,		3),
	GROUP(pdm_din0_x,		2),
	GROUP(pdm_din1_x,		2),
	GROUP(pdm_din2_x,		2),
	GROUP(pdm_din3_x,		2),
	GROUP(pdm_dclk_x,		2),
	GROUP(tdm_a_slv_sclk,		2),
	GROUP(tdm_a_slv_fs,		2),
	GROUP(tdm_a_din0,		2),
	GROUP(tdm_a_din1,		2),
	GROUP(tdm_a_sclk,		1),
	GROUP(tdm_a_fs,			1),
	GROUP(tdm_a_dout0,		1),
	GROUP(tdm_a_dout1,		1),
	GROUP(mclk1_x,			2),

	/* bank GPIOC */
	GROUP(sdcard_d0_c,		1),
	GROUP(sdcard_d1_c,		1),
	GROUP(sdcard_d2_c,		1),
	GROUP(sdcard_d3_c,		1),
	GROUP(sdcard_clk_c,		1),
	GROUP(sdcard_cmd_c,		1),
	GROUP(spi0_mosi_c,		5),
	GROUP(spi0_miso_c,		5),
	GROUP(spi0_ss0_c,		5),
	GROUP(spi0_clk_c,		5),
	GROUP(i2c0_sda_c,		3),
	GROUP(i2c0_sck_c,		3),
	GROUP(uart_ao_a_rx_c,		2),
	GROUP(uart_ao_a_tx_c,		2),
	GROUP(iso7816_clk_c,		5),
	GROUP(iso7816_data_c,		5),
	GROUP(pwm_c_c,			5),
	GROUP(jtag_b_tdo,		2),
	GROUP(jtag_b_tdi,		2),
	GROUP(jtag_b_clk,		2),
	GROUP(jtag_b_tms,		2),
	GROUP(pdm_din0_c,		4),
	GROUP(pdm_din1_c,		4),
	GROUP(pdm_din2_c,		4),
	GROUP(pdm_din3_c,		4),
	GROUP(pdm_dclk_c,		4),

	/* bank GPIOH */
	GROUP(spi1_mosi,		3),
	GROUP(spi1_miso,		3),
	GROUP(spi1_ss0,			3),
	GROUP(spi1_clk,			3),
	GROUP(i2c1_sda_h2,		2),
	GROUP(i2c1_sck_h3,		2),
	GROUP(i2c1_sda_h6,		4),
	GROUP(i2c1_sck_h7,		4),
	GROUP(i2c3_sda_h,		2),
	GROUP(i2c3_sck_h,		2),
	GROUP(uart_c_tx,		2),
	GROUP(uart_c_rx,		2),
	GROUP(uart_c_cts,		2),
	GROUP(uart_c_rts,		2),
	GROUP(iso7816_clk_h,		1),
	GROUP(iso7816_data_h,		1),
	GROUP(pwm_f_h,			4),
	GROUP(cec_ao_a_h,		4),
	GROUP(cec_ao_b_h,		5),
	GROUP(hdmitx_sda,		1),
	GROUP(hdmitx_sck,		1),
	GROUP(hdmitx_hpd_in,		1),
	GROUP(spdif_out_h,		1),
	GROUP(spdif_in_h,		1),
	GROUP(tdm_b_din3_h,		6),
	GROUP(tdm_b_dout3_h,		5),

	/* bank GPIOA */
	GROUP(i2c3_sda_a,		2),
	GROUP(i2c3_sck_a,		2),
	GROUP(pdm_din0_a,		1),
	GROUP(pdm_din1_a,		1),
	GROUP(pdm_din2_a,		1),
	GROUP(pdm_din3_a,		1),
	GROUP(pdm_dclk_a,		1),
	GROUP(spdif_in_a10,		1),
	GROUP(spdif_in_a12,		1),
	GROUP(spdif_out_a11,		1),
	GROUP(spdif_out_a13,		1),
	GROUP(tdm_b_slv_sclk,		2),
	GROUP(tdm_b_slv_fs,		2),
	GROUP(tdm_b_din0,		2),
	GROUP(tdm_b_din1,		2),
	GROUP(tdm_b_din2,		2),
	GROUP(tdm_b_din3_a,		2),
	GROUP(tdm_b_sclk,		1),
	GROUP(tdm_b_fs,			1),
	GROUP(tdm_b_dout0,		1),
	GROUP(tdm_b_dout1,		1),
	GROUP(tdm_b_dout2,		3),
	GROUP(tdm_b_dout3_a,		3),
	GROUP(tdm_c_slv_sclk_a,		3),
	GROUP(tdm_c_slv_fs_a,		3),
	GROUP(tdm_c_din0_a,		3),
	GROUP(tdm_c_din1_a,		3),
	GROUP(tdm_c_din2_a,		3),
	GROUP(tdm_c_din3_a,		3),
	GROUP(tdm_c_sclk_a,		2),
	GROUP(tdm_c_fs_a,		2),
	GROUP(tdm_c_dout0_a,		2),
	GROUP(tdm_c_dout1_a,		2),
	GROUP(tdm_c_dout2_a,		2),
	GROUP(tdm_c_dout3_a,		2),
	GROUP(mclk0_a,			1),
	GROUP(mclk1_a,			2),
};

/* uart_ao_a */
static const unsigned int uart_ao_a_tx_pins[]		= { GPIOAO_0 };
static const unsigned int uart_ao_a_rx_pins[]		= { GPIOAO_1 };
static const unsigned int uart_ao_a_cts_pins[]		= { GPIOE_0 };
static const unsigned int uart_ao_a_rts_pins[]		= { GPIOE_1 };

/* uart_ao_b */
static const unsigned int uart_ao_b_tx_2_pins[]		= { GPIOAO_2 };
static const unsigned int uart_ao_b_rx_3_pins[]		= { GPIOAO_3 };
static const unsigned int uart_ao_b_tx_8_pins[]		= { GPIOAO_8 };
static const unsigned int uart_ao_b_rx_9_pins[]		= { GPIOAO_9 };
static const unsigned int uart_ao_b_cts_pins[]		= { GPIOE_0 };
static const unsigned int uart_ao_b_rts_pins[]		= { GPIOE_1 };

/* i2c_ao */
static const unsigned int i2c_ao_sck_pins[]		= { GPIOAO_2 };
static const unsigned int i2c_ao_sda_pins[]		= { GPIOAO_3 };

static const unsigned int i2c_ao_sck_e_pins[]		= { GPIOE_0 };
static const unsigned int i2c_ao_sda_e_pins[]		= { GPIOE_1 };

/* i2c_ao_slave */
static const unsigned int i2c_ao_slave_sck_pins[]	= { GPIOAO_2 };
static const unsigned int i2c_ao_slave_sda_pins[]	= { GPIOAO_3 };

/* ir_in */
static const unsigned int remote_ao_input_pins[]	= { GPIOAO_5 };

/* ir_out */
static const unsigned int remote_ao_out_pins[]		= { GPIOAO_4 };

/* pwm_ao_a */
static const unsigned int pwm_ao_a_pins[]		= { GPIOAO_11 };
static const unsigned int pwm_ao_a_hiz_pins[]		= { GPIOAO_11 };

/* pwm_ao_b */
static const unsigned int pwm_ao_b_pins[]		= { GPIOE_0 };

/* pwm_ao_c */
static const unsigned int pwm_ao_c_4_pins[]		= { GPIOAO_4 };
static const unsigned int pwm_ao_c_hiz_pins[]		= { GPIOAO_4 };
static const unsigned int pwm_ao_c_6_pins[]		= { GPIOAO_6 };

/* pwm_ao_d */
static const unsigned int pwm_ao_d_5_pins[]		= { GPIOAO_5 };
static const unsigned int pwm_ao_d_10_pins[]		= { GPIOAO_10 };
static const unsigned int pwm_ao_d_e_pins[]		= { GPIOE_1 };

/* jtag_a */
static const unsigned int jtag_a_tdi_pins[]		= { GPIOAO_8 };
static const unsigned int jtag_a_tdo_pins[]		= { GPIOAO_9 };
static const unsigned int jtag_a_clk_pins[]		= { GPIOAO_6 };
static const unsigned int jtag_a_tms_pins[]		= { GPIOAO_7 };

/* cec_ao */
static const unsigned int cec_ao_a_pins[]		= { GPIOAO_10 };
static const unsigned int cec_ao_b_pins[]		= { GPIOAO_10 };

/* tsin_ao_a */
static const unsigned int tsin_ao_asop_pins[]		= { GPIOAO_6 };
static const unsigned int tsin_ao_adin0_pins[]		= { GPIOAO_7 };
static const unsigned int tsin_ao_aclk_pins[]		= { GPIOAO_8 };
static const unsigned int tsin_ao_a_valid_pins[]	= { GPIOAO_9 };

/* spdif_ao_out */
static const unsigned int spdif_ao_out_pins[]		= { GPIOAO_10 };

/* tdm_ao_b */
static const unsigned int tdm_ao_b_slv_fs_pins[]	= { GPIOAO_7 };
static const unsigned int tdm_ao_b_slv_sclk_pins[]	= { GPIOAO_8 };
static const unsigned int tdm_ao_b_fs_pins[]		= { GPIOAO_7 };
static const unsigned int tdm_ao_b_sclk_pins[]		= { GPIOAO_8 };
static const unsigned int tdm_ao_b_din0_pins[]		= { GPIOAO_4 };
static const unsigned int tdm_ao_b_din1_pins[]		= { GPIOAO_10 };
static const unsigned int tdm_ao_b_din2_pins[]		= { GPIOAO_6 };
static const unsigned int tdm_ao_b_dout0_pins[]		= { GPIOAO_4 };
static const unsigned int tdm_ao_b_dout1_pins[]		= { GPIOAO_10 };
static const unsigned int tdm_ao_b_dout2_pins[]		= { GPIOAO_6 };

/* mclk0_ao */
static const unsigned int mclk0_ao_pins[]		= { GPIOAO_9 };

static struct meson_pmx_group meson_g12a_aobus_groups[] = {
	GPIO_GROUP(GPIOAO_0, 0),
	GPIO_GROUP(GPIOAO_1, 0),
	GPIO_GROUP(GPIOAO_2, 0),
	GPIO_GROUP(GPIOAO_3, 0),
	GPIO_GROUP(GPIOAO_4, 0),
	GPIO_GROUP(GPIOAO_5, 0),
	GPIO_GROUP(GPIOAO_6, 0),
	GPIO_GROUP(GPIOAO_7, 0),
	GPIO_GROUP(GPIOAO_8, 0),
	GPIO_GROUP(GPIOAO_9, 0),
	GPIO_GROUP(GPIOAO_10, 0),
	GPIO_GROUP(GPIOAO_11, 0),
	GPIO_GROUP(GPIOE_0, 0),
	GPIO_GROUP(GPIOE_1, 0),
	GPIO_GROUP(GPIOE_2, 0),

	/* bank AO */
	GROUP(uart_ao_a_tx,		1),
	GROUP(uart_ao_a_rx,		1),
	GROUP(uart_ao_a_cts,		1),
	GROUP(uart_ao_a_rts,		1),
	GROUP(uart_ao_b_tx_2,		2),
	GROUP(uart_ao_b_rx_3,		2),
	GROUP(uart_ao_b_tx_8,		3),
	GROUP(uart_ao_b_rx_9,		3),
	GROUP(uart_ao_b_cts,		2),
	GROUP(uart_ao_b_rts,		2),
	GROUP(i2c_ao_sck,		1),
	GROUP(i2c_ao_sda,		1),
	GROUP(i2c_ao_sck_e,		4),
	GROUP(i2c_ao_sda_e,		4),
	GROUP(i2c_ao_slave_sck,		3),
	GROUP(i2c_ao_slave_sda,		3),
	GROUP(remote_ao_input,		1),
	GROUP(remote_ao_out,		1),
	GROUP(pwm_ao_a,			3),
	GROUP(pwm_ao_a_hiz,		2),
	GROUP(pwm_ao_b,			3),
	GROUP(pwm_ao_c_4,		3),
	GROUP(pwm_ao_c_hiz,		4),
	GROUP(pwm_ao_c_6,		3),
	GROUP(pwm_ao_d_5,		3),
	GROUP(pwm_ao_d_10,		3),
	GROUP(pwm_ao_d_e,		3),
	GROUP(jtag_a_tdi,		1),
	GROUP(jtag_a_tdo,		1),
	GROUP(jtag_a_clk,		1),
	GROUP(jtag_a_tms,		1),
	GROUP(cec_ao_a,			1),
	GROUP(cec_ao_b,			2),
	GROUP(tsin_ao_asop,		4),
	GROUP(tsin_ao_adin0,		4),
	GROUP(tsin_ao_aclk,		4),
	GROUP(tsin_ao_a_valid,		4),
	GROUP(spdif_ao_out,		4),
	GROUP(tdm_ao_b_dout0,		5),
	GROUP(tdm_ao_b_dout1,		5),
	GROUP(tdm_ao_b_dout2,		5),
	GROUP(tdm_ao_b_fs,		5),
	GROUP(tdm_ao_b_sclk,		5),
	GROUP(tdm_ao_b_din0,		6),
	GROUP(tdm_ao_b_din1,		6),
	GROUP(tdm_ao_b_din2,		6),
	GROUP(tdm_ao_b_slv_fs,		6),
	GROUP(tdm_ao_b_slv_sclk,	6),
	GROUP(mclk0_ao,			5),
};

static const char * const gpio_periphs_groups[] = {
	"GPIOZ_0", "GPIOZ_1", "GPIOZ_2", "GPIOZ_3", "GPIOZ_4",
	"GPIOZ_5", "GPIOZ_6", "GPIOZ_7", "GPIOZ_8", "GPIOZ_9",
	"GPIOZ_10", "GPIOZ_11", "GPIOZ_12", "GPIOZ_13", "GPIOZ_14",
	"GPIOZ_15",

	"GPIOH_0", "GPIOH_1", "GPIOH_2", "GPIOH_3", "GPIOH_4",
	"GPIOH_5", "GPIOH_6", "GPIOH_7", "GPIOH_8",

	"BOOT_0", "BOOT_1", "BOOT_2", "BOOT_3", "BOOT_4",
	"BOOT_5", "BOOT_6", "BOOT_7", "BOOT_8", "BOOT_9",
	"BOOT_10", "BOOT_11", "BOOT_12", "BOOT_13", "BOOT_14",
	"BOOT_15",

	"GPIOC_0", "GPIOC_1", "GPIOC_2", "GPIOC_3", "GPIOC_4",
	"GPIOC_5", "GPIOC_6", "GPIOC_7",

	"GPIOA_0", "GPIOA_1", "GPIOA_2", "GPIOA_3", "GPIOA_4",
	"GPIOA_5", "GPIOA_6", "GPIOA_7", "GPIOA_8", "GPIOA_9",
	"GPIOA_10", "GPIOA_11", "GPIOA_12", "GPIOA_13", "GPIOA_14",
	"GPIOA_15",

	"GPIOX_0", "GPIOX_1", "GPIOX_2", "GPIOX_3", "GPIOX_4",
	"GPIOX_5", "GPIOX_6", "GPIOX_7", "GPIOX_8", "GPIOX_9",
	"GPIOX_10", "GPIOX_11", "GPIOX_12", "GPIOX_13", "GPIOX_14",
	"GPIOX_15", "GPIOX_16", "GPIOX_17", "GPIOX_18", "GPIOX_19",
};

static const char * const emmc_groups[] = {
	"emmc_nand_d0", "emmc_nand_d1", "emmc_nand_d2",
	"emmc_nand_d3", "emmc_nand_d4", "emmc_nand_d5",
	"emmc_nand_d6", "emmc_nand_d7",
	"emmc_clk", "emmc_cmd", "emmc_nand_ds",
};

static const char * const nand_groups[] = {
	"emmc_nand_d0", "emmc_nand_d1", "emmc_nand_d2",
	"emmc_nand_d3", "emmc_nand_d4", "emmc_nand_d5",
	"emmc_nand_d6", "emmc_nand_d7",
	"nand_ce0", "nand_ale", "nand_cle",
	"nand_wen_clk", "nand_ren_wr", "nand_rb0",
	"emmc_nand_ds", "nand_ce1",
};

static const char * const nor_groups[] = {
	"nor_d", "nor_q", "nor_c", "nor_cs",
	"nor_hold", "nor_wp",
};

static const char * const sdio_groups[] = {
	"sdio_d0", "sdio_d1", "sdio_d2", "sdio_d3",
	"sdio_cmd", "sdio_clk", "sdio_dummy",
};

static const char * const sdcard_groups[] = {
	"sdcard_d0_c", "sdcard_d1_c", "sdcard_d2_c", "sdcard_d3_c",
	"sdcard_clk_c", "sdcard_cmd_c",
	"sdcard_d0_z", "sdcard_d1_z", "sdcard_d2_z", "sdcard_d3_z",
	"sdcard_clk_z", "sdcard_cmd_z",
};

static const char * const spi0_groups[] = {
	"spi0_mosi_c", "spi0_miso_c", "spi0_ss0_c", "spi0_clk_c",
	"spi0_mosi_x", "spi0_miso_x", "spi0_ss0_x", "spi0_clk_x",
};

static const char * const spi1_groups[] = {
	"spi1_mosi", "spi1_miso", "spi1_ss0", "spi1_clk",
};

static const char * const i2c0_groups[] = {
	"i2c0_sda_c", "i2c0_sck_c",
	"i2c0_sda_z0", "i2c0_sck_z1",
	"i2c0_sda_z7", "i2c0_sck_z8",
};

static const char * const i2c1_groups[] = {
	"i2c1_sda_x", "i2c1_sck_x",
	"i2c1_sda_h2", "i2c1_sck_h3",
	"i2c1_sda_h6", "i2c1_sck_h7",
};

static const char * const i2c2_groups[] = {
	"i2c2_sda_x", "i2c2_sck_x",
	"i2c2_sda_z", "i2c2_sck_z",
};

static const char * const i2c3_groups[] = {
	"i2c3_sda_h", "i2c3_sck_h",
	"i2c3_sda_a", "i2c3_sck_a",
};

static const char * const uart_a_groups[] = {
	"uart_a_tx", "uart_a_rx", "uart_a_cts", "uart_a_rts",
};

static const char * const uart_b_groups[] = {
	"uart_b_tx", "uart_b_rx",
};

static const char * const uart_c_groups[] = {
	"uart_c_tx", "uart_c_rx", "uart_c_cts", "uart_c_rts",
};

static const char * const uart_ao_a_c_groups[] = {
	"uart_ao_a_rx_c", "uart_ao_a_tx_c",
};

static const char * const iso7816_groups[] = {
	"iso7816_clk_c", "iso7816_data_c",
	"iso7816_clk_x", "iso7816_data_x",
	"iso7816_clk_h", "iso7816_data_h",
	"iso7816_clk_z", "iso7816_data_z",
};

static const char * const eth_groups[] = {
	"eth_rxd2_rgmii", "eth_rxd3_rgmii", "eth_rgmii_tx_clk",
	"eth_txd2_rgmii", "eth_txd3_rgmii", "eth_rgmii_rx_clk",
	"eth_txd0", "eth_txd1", "eth_txen", "eth_mdc",
	"eth_rxd0", "eth_rxd1", "eth_rx_dv", "eth_mdio",
	"eth_link_led", "eth_act_led",
};

static const char * const pwm_a_groups[] = {
	"pwm_a",
};

static const char * const pwm_b_groups[] = {
	"pwm_b_x7", "pwm_b_x19",
};

static const char * const pwm_c_groups[] = {
	"pwm_c_c", "pwm_c_x5", "pwm_c_x8",
};

static const char * const pwm_d_groups[] = {
	"pwm_d_x3", "pwm_d_x6",
};

static const char * const pwm_e_groups[] = {
	"pwm_e",
};

static const char * const pwm_f_groups[] = {
	"pwm_f_x", "pwm_f_h",
};

static const char * const cec_ao_a_h_groups[] = {
	"cec_ao_a_h",
};

static const char * const cec_ao_b_h_groups[] = {
	"cec_ao_b_h",
};

static const char * const jtag_b_groups[] = {
	"jtag_b_tdi", "jtag_b_tdo", "jtag_b_clk", "jtag_b_tms",
};

static const char * const bt565_a_groups[] = {
	"bt565_a_vs", "bt565_a_hs", "bt565_a_clk",
	"bt565_a_din0", "bt565_a_din1", "bt565_a_din2",
	"bt565_a_din3", "bt565_a_din4", "bt565_a_din5",
	"bt565_a_din6", "bt565_a_din7",
};

static const char * const tsin_a_groups[] = {
	"tsin_a_valid", "tsin_a_sop", "tsin_a_din0",
	"tsin_a_clk",
};

static const char * const tsin_b_groups[] = {
	"tsin_b_valid_x", "tsin_b_sop_x", "tsin_b_din0_x", "tsin_b_clk_x",
	"tsin_b_valid_z", "tsin_b_sop_z", "tsin_b_din0_z", "tsin_b_clk_z",
	"tsin_b_fail", "tsin_b_din1", "tsin_b_din2", "tsin_b_din3",
	"tsin_b_din4", "tsin_b_din5", "tsin_b_din6", "tsin_b_din7",
};

static const char * const hdmitx_groups[] = {
	"hdmitx_sda", "hdmitx_sck", "hdmitx_hpd_in",
};

static const char * const pdm_groups[] = {
	"pdm_din0_c", "pdm_din1_c", "pdm_din2_c", "pdm_din3_c",
	"pdm_dclk_c",
	"pdm_din0_x", "pdm_din1_x", "pdm_din2_x", "pdm_din3_x",
	"pdm_dclk_x",
	"pdm_din0_z", "pdm_din1_z", "pdm_din2_z", "pdm_din3_z",
	"pdm_dclk_z",
	"pdm_din0_a", "pdm_din1_a", "pdm_din2_a", "pdm_din3_a",
	"pdm_dclk_a",
};

static const char * const spdif_in_groups[] = {
	"spdif_in_h", "spdif_in_a10", "spdif_in_a12",
};

static const char * const spdif_out_groups[] = {
	"spdif_out_h", "spdif_out_a11", "spdif_out_a13",
};

static const char * const mclk0_groups[] = {
	"mclk0_a",
};

static const char * const mclk1_groups[] = {
	"mclk1_x", "mclk1_z", "mclk1_a",
};

static const char * const tdm_a_groups[] = {
	"tdm_a_slv_sclk", "tdm_a_slv_fs", "tdm_a_sclk", "tdm_a_fs",
	"tdm_a_din0", "tdm_a_din1", "tdm_a_dout0", "tdm_a_dout1",
};

static const char * const tdm_b_groups[] = {
	"tdm_b_slv_sclk", "tdm_b_slv_fs", "tdm_b_sclk", "tdm_b_fs",
	"tdm_b_din0", "tdm_b_din1", "tdm_b_din2",
	"tdm_b_din3_a", "tdm_b_din3_h",
	"tdm_b_dout0", "tdm_b_dout1", "tdm_b_dout2",
	"tdm_b_dout3_a", "tdm_b_dout3_h",
};

static const char * const tdm_c_groups[] = {
	"tdm_c_slv_sclk_a", "tdm_c_slv_fs_a",
	"tdm_c_slv_sclk_z", "tdm_c_slv_fs_z",
	"tdm_c_sclk_a", "tdm_c_fs_a",
	"tdm_c_sclk_z", "tdm_c_fs_z",
	"tdm_c_din0_a", "tdm_c_din1_a",
	"tdm_c_din2_a", "tdm_c_din3_a",
	"tdm_c_din0_z", "tdm_c_din1_z",
	"tdm_c_din2_z", "tdm_c_din3_z",
	"tdm_c_dout0_a", "tdm_c_dout1_a",
	"tdm_c_dout2_a", "tdm_c_dout3_a",
	"tdm_c_dout0_z", "tdm_c_dout1_z",
	"tdm_c_dout2_z", "tdm_c_dout3_z",
};

static const char * const gpio_aobus_groups[] = {
	"GPIOAO_0", "GPIOAO_1", "GPIOAO_2", "GPIOAO_3", "GPIOAO_4",
	"GPIOAO_5", "GPIOAO_6", "GPIOAO_7", "GPIOAO_8", "GPIOAO_9",
	"GPIOAO_10", "GPIOAO_11", "GPIOE_0", "GPIOE_1", "GPIOE_2",
};

static const char * const uart_ao_a_groups[] = {
	"uart_ao_a_tx", "uart_ao_a_rx",
	"uart_ao_a_cts", "uart_ao_a_rts",
};

static const char * const uart_ao_b_groups[] = {
	"uart_ao_b_tx_2", "uart_ao_b_rx_3",
	"uart_ao_b_tx_8", "uart_ao_b_rx_9",
	"uart_ao_b_cts", "uart_ao_b_rts",
};

static const char * const i2c_ao_groups[] = {
	"i2c_ao_sck", "i2c_ao_sda",
	"i2c_ao_sck_e", "i2c_ao_sda_e",
};

static const char * const i2c_ao_slave_groups[] = {
	"i2c_ao_slave_sck", "i2c_ao_slave_sda",
};

static const char * const remote_ao_input_groups[] = {
	"remote_ao_input",
};

static const char * const remote_ao_out_groups[] = {
	"remote_ao_out",
};

static const char * const pwm_ao_a_groups[] = {
	"pwm_ao_a", "pwm_ao_a_hiz",
};

static const char * const pwm_ao_b_groups[] = {
	"pwm_ao_b",
};

static const char * const pwm_ao_c_groups[] = {
	"pwm_ao_c_4", "pwm_ao_c_hiz",
	"pwm_ao_c_6",
};

static const char * const pwm_ao_d_groups[] = {
	"pwm_ao_d_5", "pwm_ao_d_10", "pwm_ao_d_e",
};

static const char * const jtag_a_groups[] = {
	"jtag_a_tdi", "jtag_a_tdo", "jtag_a_clk", "jtag_a_tms",
};

static const char * const cec_ao_a_groups[] = {
	"cec_ao_a",
};

static const char * const cec_ao_b_groups[] = {
	"cec_ao_b",
};

static const char * const tsin_ao_a_groups[] = {
	"tsin_ao_asop", "tsin_ao_adin0", "tsin_ao_aclk", "tsin_ao_a_valid",
};

static const char * const spdif_ao_out_groups[] = {
	"spdif_ao_out",
};

static const char * const tdm_ao_b_groups[] = {
	"tdm_ao_b_dout0", "tdm_ao_b_dout1", "tdm_ao_b_dout2",
	"tdm_ao_b_fs", "tdm_ao_b_sclk",
	"tdm_ao_b_din0", "tdm_ao_b_din1", "tdm_ao_b_din2",
	"tdm_ao_b_slv_fs", "tdm_ao_b_slv_sclk",
};

static const char * const mclk0_ao_groups[] = {
	"mclk0_ao",
};

static struct meson_pmx_func meson_g12a_periphs_functions[] = {
	FUNCTION(gpio_periphs),
	FUNCTION(emmc),
	FUNCTION(nor),
	FUNCTION(spi0),
	FUNCTION(spi1),
	FUNCTION(sdio),
	FUNCTION(nand),
	FUNCTION(sdcard),
	FUNCTION(i2c0),
	FUNCTION(i2c1),
	FUNCTION(i2c2),
	FUNCTION(i2c3),
	FUNCTION(uart_a),
	FUNCTION(uart_b),
	FUNCTION(uart_c),
	FUNCTION(uart_ao_a_c),
	FUNCTION(iso7816),
	FUNCTION(eth),
	FUNCTION(pwm_a),
	FUNCTION(pwm_b),
	FUNCTION(pwm_c),
	FUNCTION(pwm_d),
	FUNCTION(pwm_e),
	FUNCTION(pwm_f),
	FUNCTION(cec_ao_a_h),
	FUNCTION(cec_ao_b_h),
	FUNCTION(jtag_b),
	FUNCTION(bt565_a),
	FUNCTION(tsin_a),
	FUNCTION(tsin_b),
	FUNCTION(hdmitx),
	FUNCTION(pdm),
	FUNCTION(spdif_out),
	FUNCTION(spdif_in),
	FUNCTION(mclk0),
	FUNCTION(mclk1),
	FUNCTION(tdm_a),
	FUNCTION(tdm_b),
	FUNCTION(tdm_c),
};

static struct meson_pmx_func meson_g12a_aobus_functions[] = {
	FUNCTION(gpio_aobus),
	FUNCTION(uart_ao_a),
	FUNCTION(uart_ao_b),
	FUNCTION(i2c_ao),
	FUNCTION(i2c_ao_slave),
	FUNCTION(remote_ao_input),
	FUNCTION(remote_ao_out),
	FUNCTION(pwm_ao_a),
	FUNCTION(pwm_ao_b),
	FUNCTION(pwm_ao_c),
	FUNCTION(pwm_ao_d),
	FUNCTION(jtag_a),
	FUNCTION(cec_ao_a),
	FUNCTION(cec_ao_b),
	FUNCTION(tsin_ao_a),
	FUNCTION(spdif_ao_out),
	FUNCTION(tdm_ao_b),
	FUNCTION(mclk0_ao),
};

static struct meson_bank meson_g12a_periphs_banks[] = {
	/*    name   first                   last                   pullen  pull   dir     out     in   */
	BANK("Z",    PIN(GPIOZ_0, EE_OFF),   PIN(GPIOZ_15, EE_OFF), 4,  0,  4,  0, 12,  0, 13,  0, 14,  0),
	BANK("H",    PIN(GPIOH_0, EE_OFF),   PIN(GPIOH_8,  EE_OFF), 3,  0,  3,  0,  9,  0, 10,  0, 11,  0),
	BANK("BOOT", PIN(BOOT_0,  EE_OFF),   PIN(BOOT_15,  EE_OFF), 0,  0,  0,  0,  0,  0,  1,  0,  2,  0),
	BANK("C",    PIN(GPIOC_0, EE_OFF),   PIN(GPIOC_7,  EE_OFF), 1,  0,  1,  0,  3,  0,  4,  0,  5,  0),
	BANK("A",    PIN(GPIOA_0, EE_OFF),   PIN(GPIOA_15, EE_OFF), 5,  0,  5,  0, 16,  0, 17,  0, 18,  0),
	BANK("X",    PIN(GPIOX_0, EE_OFF),   PIN(GPIOX_19, EE_OFF), 2,  0,  2,  0,  6,  0,  7,  0,  8,  0),
};

static struct meson_bank meson_g12a_aobus_banks[] = {
	/*   name    first                   last                   pullen  pull   dir     out     in  */
	BANK("AO",   PIN(GPIOAO_0, 0),       PIN(GPIOAO_11, 0),     3,  0,  2,  0,  0,  0,  4,  0,  1,  0),
	BANK("E",    PIN(GPIOE_0, 0),        PIN(GPIOE_2, 0),       3, 16,  2, 16,  0, 16,  4, 16,  1,  16),
};

static struct meson_pmx_bank meson_g12a_periphs_pmx_banks[] = {
	/*	 name	 first			last	   	       reg   offset  */
	BANK_PMX("Z",    PIN(GPIOZ_0, EE_OFF),   PIN(GPIOZ_15, EE_OFF), 0x6, 0),
	BANK_PMX("H",    PIN(GPIOH_0, EE_OFF),   PIN(GPIOH_8,  EE_OFF),  0xb, 0),
	BANK_PMX("BOOT", PIN(BOOT_0,  EE_OFF),   PIN(BOOT_15,  EE_OFF),  0x0, 0),
	BANK_PMX("C",    PIN(GPIOC_0, EE_OFF),   PIN(GPIOC_7,  EE_OFF),  0x9, 0),
	BANK_PMX("A",    PIN(GPIOA_0, EE_OFF),   PIN(GPIOA_15, EE_OFF), 0xd, 0),
	BANK_PMX("X",    PIN(GPIOX_0, EE_OFF),   PIN(GPIOX_19, EE_OFF), 0x3, 0),
};

static struct meson_axg_pmx_data meson_g12a_periphs_pmx_banks_data = {
	.pmx_banks	= meson_g12a_periphs_pmx_banks,
	.num_pmx_banks	= ARRAY_SIZE(meson_g12a_periphs_pmx_banks),
};

static struct meson_pmx_bank meson_g12a_aobus_pmx_banks[] = {
	BANK_PMX("AO",  GPIOAO_0, GPIOAO_11, 0x0, 0),
	BANK_PMX("E",   GPIOE_0,  GPIOE_2,   0x1, 16),
};

static struct meson_axg_pmx_data meson_g12a_aobus_pmx_banks_data = {
	.pmx_banks	= meson_g12a_aobus_pmx_banks,
	.num_pmx_banks	= ARRAY_SIZE(meson_g12a_aobus_pmx_banks),
};

static struct meson_pinctrl_data meson_g12a_periphs_pinctrl_data = {
	.name		= "periphs-banks",
	.pin_base	= EE_OFF,
	.groups		= meson_g12a_periphs_groups,
	.funcs		= meson_g12a_periphs_functions,
	.banks		= meson_g12a_periphs_banks,
	.num_pins	= 85,
	.num_groups	= ARRAY_SIZE(meson_g12a_periphs_groups),
	.num_funcs	= ARRAY_SIZE(meson_g12a_periphs_functions),
	.num_banks	= ARRAY_SIZE(meson_g12a_periphs_banks),
	.gpio_driver	= &meson_axg_gpio_driver,
	.pmx_data	= &meson_g12a_periphs_pmx_banks_data,
};

static struct meson_pinctrl_data meson_g12a_aobus_pinctrl_data = {
	.name		= "aobus-banks",
	.pin_base	= 0,
	.groups		= meson_g12a_aobus_groups,
	.funcs		= meson_g12a_aobus_functions,
	.banks		= meson_g12a_aobus_banks,
	.num_pins	= 15,
	.num_groups	= ARRAY_SIZE(meson_g12a_aobus_groups),
	.num_funcs	= ARRAY_SIZE(meson_g12a_aobus_functions),
	.num_banks	= ARRAY_SIZE(meson_g12a_aobus_banks),
	.gpio_driver	= &meson_axg_gpio_driver,
	.pmx_data	= &meson_g12a_aobus_pmx_banks_data,
};

static const struct udevice_id meson_g12a_pinctrl_match[] = {
	{
		.compatible = "amlogic,meson-g12a-periphs-pinctrl",
		.data = (ulong)&meson_g12a_periphs_pinctrl_data,
	},
	{
		.compatible = "amlogic,meson-g12a-aobus-pinctrl",
		.data = (ulong)&meson_g12a_aobus_pinctrl_data,
	},
	{ },
};

U_BOOT_DRIVER(meson_axg_pinctrl) = {
	.name = "meson-g12a-pinctrl",
	.id = UCLASS_PINCTRL,
	.of_match = of_match_ptr(meson_g12a_pinctrl_match),
	.probe = meson_pinctrl_probe,
	.priv_auto_alloc_size = sizeof(struct meson_pinctrl),
	.ops = &meson_axg_pinctrl_ops,
};
