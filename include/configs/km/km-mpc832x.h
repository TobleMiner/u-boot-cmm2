/*
 * High Level Configuration Options
 */
#define CONFIG_QE	/* Has QE */
#define CONFIG_KM8321	/* Keymile PBEC8321 board specific */

/*
 * System Clock Setup
 */
#define CONFIG_83XX_CLKIN		66000000
#define CONFIG_SYS_CLK_FREQ		66000000
#define CONFIG_83XX_PCICLK		66000000

/*
 * QE UEC ethernet configuration
 */
#define CONFIG_UEC_ETH1		/* GETH1 */
#define UEC_VERBOSE_DEBUG	1

#define CONFIG_SYS_UEC1_UCC_NUM	3	/* UCC4 */
#define CONFIG_SYS_UEC1_RX_CLK		QE_CLK_NONE /* not used in RMII Mode */
#define CONFIG_SYS_UEC1_TX_CLK		QE_CLK17
#define CONFIG_SYS_UEC1_ETH_TYPE	FAST_ETH
#define CONFIG_SYS_UEC1_PHY_ADDR	0
#define CONFIG_SYS_UEC1_INTERFACE_TYPE	PHY_INTERFACE_MODE_RMII
#define CONFIG_SYS_UEC1_INTERFACE_SPEED	100

/*
 * System IO Config
 */
#define CONFIG_SYS_SICRL	SICRL_IRQ_CKS

#define CONFIG_SYS_DDRCDR (\
	DDRCDR_EN | \
	DDRCDR_PZ_MAXZ | \
	DDRCDR_NZ_MAXZ | \
	DDRCDR_M_ODR)

#define CONFIG_SYS_DDR_CS0_BNDS		0x0000007f
#define CONFIG_SYS_DDR_SDRAM_CFG	(SDRAM_CFG_SDRAM_TYPE_DDR2 | \
					 SDRAM_CFG_32_BE | \
					 SDRAM_CFG_SREN | \
					 SDRAM_CFG_HSE)

#define CONFIG_SYS_DDR_SDRAM_CFG2	0x00401000
#define CONFIG_SYS_DDR_CLK_CNTL		(DDR_SDRAM_CLK_CNTL_CLK_ADJUST_05)
#define CONFIG_SYS_DDR_INTERVAL	((0x064 << SDRAM_INTERVAL_BSTOPRE_SHIFT) | \
				 (0x200 << SDRAM_INTERVAL_REFINT_SHIFT))

#define CONFIG_SYS_DDR_CS0_CONFIG	(CSCONFIG_EN | CSCONFIG_AP | \
					 CSCONFIG_ODT_WR_CFG | \
					 CSCONFIG_ROW_BIT_13 | \
					 CSCONFIG_COL_BIT_10)

#define CONFIG_SYS_DDR_MODE	0x47860242
#define CONFIG_SYS_DDR_MODE2	0x8080c000

#define CONFIG_SYS_DDR_TIMING_0	((2 << TIMING_CFG0_MRS_CYC_SHIFT) | \
				 (8 << TIMING_CFG0_ODT_PD_EXIT_SHIFT) | \
				 (2 << TIMING_CFG0_PRE_PD_EXIT_SHIFT) | \
				 (2 << TIMING_CFG0_ACT_PD_EXIT_SHIFT) | \
				 (0 << TIMING_CFG0_WWT_SHIFT) | \
				 (0 << TIMING_CFG0_RRT_SHIFT) | \
				 (0 << TIMING_CFG0_WRT_SHIFT) | \
				 (0 << TIMING_CFG0_RWT_SHIFT))

#define CONFIG_SYS_DDR_TIMING_1	((TIMING_CFG1_CASLAT_40) | \
				 (2 << TIMING_CFG1_WRTORD_SHIFT) | \
				 (2 << TIMING_CFG1_ACTTOACT_SHIFT) | \
				 (3 << TIMING_CFG1_WRREC_SHIFT) | \
				 (7 << TIMING_CFG1_REFREC_SHIFT) | \
				 (3 << TIMING_CFG1_ACTTORW_SHIFT) | \
				 (7 << TIMING_CFG1_ACTTOPRE_SHIFT) | \
				 (3 << TIMING_CFG1_PRETOACT_SHIFT))

#define CONFIG_SYS_DDR_TIMING_2	((8 << TIMING_CFG2_FOUR_ACT_SHIFT) | \
				 (3 << TIMING_CFG2_CKE_PLS_SHIFT) | \
				 (2 << TIMING_CFG2_WR_DATA_DELAY_SHIFT) | \
				 (2 << TIMING_CFG2_RD_TO_PRE_SHIFT) | \
				 (3 << TIMING_CFG2_WR_LAT_DELAY_SHIFT) | \
				 (0 << TIMING_CFG2_ADD_LAT_SHIFT) | \
				 (5 << TIMING_CFG2_CPO_SHIFT))

#define CONFIG_SYS_DDR_TIMING_3	0x00000000

#define CONFIG_SYS_KMBEC_FPGA_BASE	0xE8000000
#define CONFIG_SYS_KMBEC_FPGA_SIZE	128

/* EEprom support */
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN	1

