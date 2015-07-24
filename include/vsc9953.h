/*
 *  vsc9953.h
 *
 *  Driver for the Vitesse VSC9953 L2 Switch
 *
 *  This software may be used and distributed according to the
 *  terms of the GNU Public License, Version 2, incorporated
 *  herein by reference.
 *
 * Copyright 2013  Freescale Semiconductor, Inc.
 *
 */

#ifndef _VSC9953_H_
#define _VSC9953_H_

#include <config.h>
#include <miiphy.h>
#include <asm/types.h>

#define VSC9953_OFFSET			(CONFIG_SYS_CCSRBAR_DEFAULT + 0x800000)

#define VSC9953_SYS_OFFSET		0x010000
#define VSC9953_REW_OFFSET		0x030000
#define VSC9953_DEV_GMII_OFFSET		0x100000
#define VSC9953_QSYS_OFFSET		0x200000
#define VSC9953_ANA_OFFSET		0x280000
#define VSC9953_DEVCPU_GCB		0x070000
#define VSC9953_ES0			0x040000
#define VSC9953_IS1			0x050000
#define VSC9953_IS2			0x060000

#define T1040_SWITCH_GMII_DEV_OFFSET	0x010000
#define VSC9953_PHY_REGS_OFFST		0x0000AC

/* Macros for vsc9953_chip_regs.soft_rst register */
#define VSC9953_SOFT_SWC_RST_ENA	0x00000001

/* Macros for vsc9953_sys_sys.reset_cfg register */
#define VSC9953_CORE_ENABLE		0x80
#define VSC9953_MEM_ENABLE		0x40
#define VSC9953_MEM_INIT		0x20

/* Macros for vsc9953_dev_gmii_mac_cfg_status.mac_ena_cfg register */
#define VSC9953_MAC_ENA_CFG		0x00000011

/* Macros for vsc9953_dev_gmii_mac_cfg_status.mac_mode_cfg register */
#define VSC9953_MAC_MODE_CFG		0x00000011

/* Macros for vsc9953_dev_gmii_mac_cfg_status.mac_ifg_cfg register */
#define VSC9953_MAC_IFG_CFG		0x00000515

/* Macros for vsc9953_dev_gmii_mac_cfg_status.mac_hdx_cfg register */
#define VSC9953_MAC_HDX_CFG		0x00001043

/* Macros for vsc9953_dev_gmii_mac_cfg_status.mac_maxlen_cfg register */
#define VSC9953_MAC_MAX_LEN		0x000005ee

/* Macros for vsc9953_dev_gmii_port_mode.clock_cfg register */
#define VSC9953_CLOCK_CFG		0x00000001
#define VSC9953_CLOCK_CFG_1000M		0x00000001

/* Macros for vsc9953_sys_sys.front_port_mode register */
#define VSC9953_FRONT_PORT_MODE	0x00000000

/* Macros for vsc9953_ana_pfc.pfc_cfg register */
#define VSC9953_PFC_FC			0x00000001
#define VSC9953_PFC_FC_QSGMII		0x00000000

/* Macros for vsc9953_sys_pause_cfg.mac_fc_cfg register */
#define VSC9953_MAC_FC_CFG		0x04700000
#define VSC9953_MAC_FC_CFG_QSGMII	0x00700000

/* Macros for vsc9953_sys_pause_cfg.pause_cfg register */
#define VSC9953_PAUSE_CFG		0x001ffffe

/* Macros for vsc9953_sys_pause_cfgtot_tail_drop_lvl register */
#define VSC9953_TOT_TAIL_DROP_LVL	0x000003ff

/* Macros for vsc9953_vcap_core_cfg.vcap_mv_cfg register */
#define VSC9953_VCAP_MV_CFG		0x0000ffff
#define VSC9953_VCAP_UPDATE_CTRL	0x01000004

/* Macros for vsc9953_ana_port.vlan_cfg register */
#define VSC9953_VLAN_CFG_AWARE_ENA	0x00100000
#define VSC9953_VLAN_CFG_POP_CNT_MASK	0x000c0000
#define VSC9953_VLAN_CFG_VID_MASK	0x00000fff

/* Macros for vsc9953_rew_port.port_vlan_cfg register */
#define VSC9953_PORT_VLAN_CFG_VID_MASK	0x00000fff

/* Macros for vsc9953_ana_ana_tables.vlan_tidx register */
#define VSC9953_ANA_TBL_VID_MASK	0x00000fff

/* Macros for vsc9953_ana_ana_tables.vlan_access register */
#define VSC9953_VLAN_PORT_MASK		0x00001ffc
#define VSC9953_VLAN_CMD_MASK		0x00000003
#define VSC9953_VLAN_CMD_IDLE		0x00000000
#define VSC9953_VLAN_CMD_READ		0x00000001
#define VSC9953_VLAN_CMD_WRITE		0x00000002
#define VSC9953_VLAN_CMD_INIT		0x00000003

/* Macros for vsc9953_qsys_sys.switch_port_mode register */
#define VSC9953_PORT_ENA		0x00002000

/* Macros for vsc9953_ana_ana.adv_learn register */
#define VSC9953_VLAN_CHK		0x00000400

/* Macros for vsc9953_rew_port.port_tag_cfg register */
#define VSC9953_TAG_CFG_MASK		0x00000180
#define VSC9953_TAG_CFG_NONE		0x00000000
#define VSC9953_TAG_CFG_ALL_BUT_PVID_ZERO	0x00000080
#define VSC9953_TAG_CFG_ALL_BUT_ZERO		0x00000100
#define VSC9953_TAG_CFG_ALL		0x00000180

#define VSC9953_MAX_PORTS		10
#define VSC9953_PORT_CHECK(port)	\
	(((port) < 0 || (port) >= VSC9953_MAX_PORTS) ? 0 : 1)
#define VSC9953_INTERNAL_PORT_CHECK(port) ( \
	( \
		(port) < VSC9953_MAX_PORTS - 2 || (port) >= VSC9953_MAX_PORTS \
	) ? 0 : 1 \
)
#define VSC9953_MAX_VLAN		4096
#define VSC9953_VLAN_CHECK(vid)	\
	(((vid) < 0 || (vid) >= VSC9953_MAX_VLAN) ? 0 : 1)

#define DEFAULT_VSC9953_MDIO_NAME	"VSC9953_MDIO0"

#define MIIMIND_OPR_PEND		0x00000004

struct vsc9953_mdio_info {
	struct vsc9953_mii_mng	*regs;
	char	*name;
};

/* VSC9953 ANA structure */

struct vsc9953_ana_port {
	u32	vlan_cfg;
	u32	drop_cfg;
	u32	qos_cfg;
	u32	vcap_cfg;
	u32	vcap_s1_key_cfg[3];
	u32	vcap_s2_cfg;
	u32	qos_pcp_dei_map_cfg[16];
	u32	cpu_fwd_cfg;
	u32	cpu_fwd_bpdu_cfg;
	u32	cpu_fwd_garp_cfg;
	u32	cpu_fwd_ccm_cfg;
	u32	port_cfg;
	u32	pol_cfg;
	u32	reserved[34];
};

struct vsc9953_ana_pol {
	u32	pol_pir_cfg;
	u32	pol_cir_cfg;
	u32	pol_mode_cfg;
	u32	pol_pir_state;
	u32	pol_cir_state;
	u32	reserved1[3];
};

struct vsc9953_ana_ana_tables {
	u32	entry_lim[11];
	u32	an_moved;
	u32	mach_data;
	u32	macl_data;
	u32	mac_access;
	u32	mact_indx;
	u32	vlan_access;
	u32	vlan_tidx;
};

struct vsc9953_ana_ana {
	u32	adv_learn;
	u32	vlan_mask;
	u32	reserved;
	u32	anag_efil;
	u32	an_events;
	u32	storm_limit_burst;
	u32	storm_limit_cfg[4];
	u32	isolated_prts;
	u32	community_ports;
	u32	auto_age;
	u32	mac_options;
	u32	learn_disc;
	u32	agen_ctrl;
	u32	mirror_ports;
	u32	emirror_ports;
	u32	flooding;
	u32	flooding_ipmc;
	u32	sflow_cfg[11];
	u32	port_mode[12];
};

struct vsc9953_ana_pgid {
	u32	port_grp_id[91];
};

struct vsc9953_ana_pfc {
	u32	pfc_cfg;
	u32	reserved1[15];
};

struct vsc9953_ana_pol_misc {
	u32	pol_flowc[10];
	u32	reserved1[17];
	u32	pol_hyst;
};

struct vsc9953_ana_common {
	u32	aggr_cfg;
	u32	cpuq_cfg;
	u32	cpuq_8021_cfg;
	u32	dscp_cfg;
	u32	dscp_rewr_cfg;
	u32	vcap_rng_type_cfg;
	u32	vcap_rng_val_cfg;
	u32	discard_cfg;
	u32	fid_cfg;
};

struct vsc9953_analyzer {
	struct vsc9953_ana_port	port[11];
	u32	reserved1[9536];
	struct vsc9953_ana_pol	pol[164];
	struct vsc9953_ana_ana_tables	ana_tables;
	u32	reserved2[14];
	struct vsc9953_ana_ana	ana;
	u32	reserved3[22];
	struct vsc9953_ana_pgid	port_id_tbl;
	u32	reserved4[549];
	struct vsc9953_ana_pfc	pfc[10];
	struct vsc9953_ana_pol_misc	pol_misc;
	u32	reserved5[196];
	struct vsc9953_ana_common	common;
};
/* END VSC9953 ANA structure t*/

/* VSC9953 DEV_GMII structure */

struct vsc9953_dev_gmii_port_mode {
	u32	clock_cfg;
	u32	port_misc;
	u32	reserved1;
	u32	eee_cfg;
};

struct vsc9953_dev_gmii_mac_cfg_status {
	u32	mac_ena_cfg;
	u32	mac_mode_cfg;
	u32	mac_maxlen_cfg;
	u32	mac_tags_cfg;
	u32	mac_adv_chk_cfg;
	u32	mac_ifg_cfg;
	u32	mac_hdx_cfg;
	u32	mac_fc_mac_low_cfg;
	u32	mac_fc_mac_high_cfg;
	u32	mac_sticky;
};

struct vsc9953_dev_gmii {
	struct vsc9953_dev_gmii_port_mode	port_mode;
	struct vsc9953_dev_gmii_mac_cfg_status	mac_cfg_status;
};

/* END VSC9953 DEV_GMII structure */

/* VSC9953 QSYS structure */

struct vsc9953_qsys_hsch {
	u32	cir_cfg;
	u32	reserved1;
	u32	se_cfg;
	u32	se_dwrr_cfg[8];
	u32	cir_state;
	u32	reserved2[20];
};

struct vsc9953_qsys_sys {
	u32	port_mode[12];
	u32	switch_port_mode[11];
	u32	stat_cnt_cfg;
	u32	eee_cfg[10];
	u32	eee_thrs;
	u32	igr_no_sharing;
	u32	egr_no_sharing;
	u32	sw_status[11];
	u32	ext_cpu_cfg;
	u32	cpu_group_map;
	u32	reserved1[23];
};

struct vsc9953_qsys_qos_cfg {
	u32	red_profile[16];
	u32	res_qos_mode;
};

struct vsc9953_qsys_drop_cfg {
	u32	egr_drop_mode;
};

struct vsc9953_qsys_mmgt {
	u32	eq_cntrl;
	u32	reserved1;
};

struct vsc9953_qsys_hsch_misc {
	u32	hsch_misc_cfg;
	u32	reserved1[546];
};

struct vsc9953_qsys_res_ctrl {
	u32	res_cfg;
	u32	res_stat;

};

struct vsc9953_qsys_reg {
	struct vsc9953_qsys_hsch	hsch[108];
	struct vsc9953_qsys_sys	sys;
	struct vsc9953_qsys_qos_cfg	qos_cfg;
	struct vsc9953_qsys_drop_cfg	drop_cfg;
	struct vsc9953_qsys_mmgt	mmgt;
	struct vsc9953_qsys_hsch_misc	hsch_misc;
	struct vsc9953_qsys_res_ctrl	res_ctrl[1024];
};

/* END VSC9953 QSYS structure */

/* VSC9953 SYS structure */

struct vsc9953_sys_stat {
	u32	rx_cntrs[64];
	u32	tx_cntrs[64];
	u32	drop_cntrs[64];
	u32	reserved1[6];
};

struct vsc9953_sys_sys {
	u32	reset_cfg;
	u32	reserved1;
	u32	vlan_etype_cfg;
	u32	port_mode[12];
	u32	front_port_mode[10];
	u32	frame_aging;
	u32	stat_cfg;
	u32	reserved2[50];
};

struct vsc9953_sys_pause_cfg {
	u32	pause_cfg[11];
	u32	pause_tot_cfg;
	u32	tail_drop_level[11];
	u32	tot_tail_drop_lvl;
	u32	mac_fc_cfg[10];
};

struct vsc9953_sys_mmgt {
	u16	free_cnt;
};

struct vsc9953_system_reg {
	struct vsc9953_sys_stat	stat;
	struct vsc9953_sys_sys	sys;
	struct vsc9953_sys_pause_cfg	pause_cfg;
	struct vsc9953_sys_mmgt	mmgt;
};

/* END VSC9953 SYS structure */

/* VSC9953 REW structure */

struct	vsc9953_rew_port {
	u32	port_vlan_cfg;
	u32	port_tag_cfg;
	u32	port_port_cfg;
	u32	port_dscp_cfg;
	u32	port_pcp_dei_qos_map_cfg[16];
	u32	reserved[12];
};

struct	vsc9953_rew_common {
	u32	reserve[4];
	u32	dscp_remap_dp1_cfg[64];
	u32	dscp_remap_cfg[64];
};

struct	vsc9953_rew_reg {
	struct vsc9953_rew_port	port[12];
	struct vsc9953_rew_common	common;
};

/* END VSC9953 REW structure */

/* VSC9953 DEVCPU_GCB structure */

struct vsc9953_chip_regs {
	u32	chipd_id;
	u32	gpr;
	u32	soft_rst;
};

struct vsc9953_gpio {
	u32	gpio_out_set[10];
	u32	gpio_out_clr[10];
	u32	gpio_out[10];
	u32	gpio_in[10];
};

struct vsc9953_mii_mng {
	u32	miimstatus;
	u32	reserved1;
	u32	miimcmd;
	u32	miimdata;
	u32	miimcfg;
	u32	miimscan_0;
	u32	miimscan_1;
	u32	miiscan_lst_rslts;
	u32	miiscan_lst_rslts_valid;
};

struct vsc9953_mii_read_scan {
	u32	mii_scan_results_sticky[2];
};

struct vsc9953_devcpu_gcb {
	struct vsc9953_chip_regs	chip_regs;
	struct vsc9953_gpio		gpio;
	struct vsc9953_mii_mng	mii_mng[2];
	struct vsc9953_mii_read_scan	mii_read_scan;
};

/* END VSC9953 DEVCPU_GCB structure */

/* VSC9953 IS* structure */

struct vsc9953_vcap_core_cfg {
	u32	vcap_update_ctrl;
	u32	vcap_mv_cfg;
};

struct vsc9953_vcap {
	struct vsc9953_vcap_core_cfg	vcap_core_cfg;
};

/* END VSC9953 IS* structure */

#define VSC9953_PORT_INFO_INITIALIZER(idx) \
{									\
	.enabled	= 0,						\
	.phyaddr	= 0,						\
	.index		= idx,						\
	.phy_regs	= NULL,						\
	.enet_if	= PHY_INTERFACE_MODE_NONE,			\
	.bus		= NULL,						\
	.phydev		= NULL,						\
}

/* Structure to describe a VSC9953 port */
struct vsc9953_port_info {
	u8	enabled;
	u8	phyaddr;
	int	index;
	void	*phy_regs;
	phy_interface_t	enet_if;
	struct mii_dev	*bus;
	struct phy_device	*phydev;
};

/* Structure to describe a VSC9953 switch */
struct vsc9953_info {
	struct vsc9953_port_info	port[VSC9953_MAX_PORTS];
};

void vsc9953_init(bd_t *bis);

void vsc9953_port_info_set_mdio(int port_no, struct mii_dev *bus);
void vsc9953_port_info_set_phy_address(int port_no, int address);
void vsc9953_port_enable(int port_no);
void vsc9953_port_disable(int port_no);
void vsc9953_port_info_set_phy_int(int port_no, phy_interface_t phy_int);

#endif /* _VSC9953_H_ */
