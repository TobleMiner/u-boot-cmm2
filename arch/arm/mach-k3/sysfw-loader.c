// SPDX-License-Identifier: GPL-2.0+
/*
 * K3: System Firmware Loader
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *	Andreas Dannenberg <dannenberg@ti.com>
 */

#include <common.h>
#include <spl.h>
#include <malloc.h>
#include <remoteproc.h>
#include <asm/cache.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include <g_dnl.h>
#include <usb.h>
#include <dfu.h>
#include <dm/uclass-internal.h>
#include <spi_flash.h>

#include <asm/arch/sys_proto.h>
#include "common.h"

DECLARE_GLOBAL_DATA_PTR;

/* Name of the FIT image nodes for SYSFW and its config data */
#define SYSFW_FIRMWARE			"sysfw.bin"
#define SYSFW_CFG_BOARD			"board-cfg.bin"
#define SYSFW_CFG_PM			"pm-cfg.bin"
#define SYSFW_CFG_RM			"rm-cfg.bin"
#define SYSFW_CFG_SEC			"sec-cfg.bin"

static bool sysfw_loaded;
static void *sysfw_load_address;

/*
 * Populate SPL hook to override the default load address used by the SPL
 * loader function with a custom address for SYSFW loading.
 */
struct image_header *spl_get_load_buffer(ssize_t offset, size_t size)
{
	if (sysfw_loaded)
		return (struct image_header *)(CONFIG_SYS_TEXT_BASE + offset);
	else if (sysfw_load_address)
		return sysfw_load_address;
	else
		panic("SYSFW load address not defined!");
}

/*
 * Populate SPL hook to skip the default SPL loader FIT post-processing steps
 * during SYSFW loading and return to the calling function so we can perform
 * our own custom processing.
 */
bool spl_load_simple_fit_skip_processing(void)
{
	return !sysfw_loaded;
}

static int fit_get_data_by_name(const void *fit, int images, const char *name,
				const void **addr, size_t *size)
{
	int node_offset;

	node_offset = fdt_subnode_offset(fit, images, name);
	if (node_offset < 0)
		return -ENOENT;

	return fit_image_get_data(fit, node_offset, addr, size);
}

static void k3_sysfw_load_using_fit(void *fit)
{
	int images;
	const void *sysfw_addr;
	size_t sysfw_size;
	int ret;

	/* Find the node holding the images information */
	images = fdt_path_offset(fit, FIT_IMAGES_PATH);
	if (images < 0)
		panic("Cannot find /images node (%d)\n", images);

	/* Extract System Firmware (SYSFW) image from FIT */
	ret = fit_get_data_by_name(fit, images, SYSFW_FIRMWARE,
				   &sysfw_addr, &sysfw_size);
	if (ret < 0)
		panic("Error accessing %s node in FIT (%d)\n", SYSFW_FIRMWARE,
		      ret);

	/*
	 * Start up system controller firmware
	 *
	 * It is assumed that remoteproc device 0 is the corresponding
	 * system-controller that runs SYSFW. Make sure DT reflects the same.
	 */
	ret = rproc_dev_init(0);
	if (ret)
		panic("rproc failed to be initialized (%d)\n", ret);

	ret = rproc_load(0, (ulong)sysfw_addr, (ulong)sysfw_size);
	if (ret)
		panic("Firmware failed to start on rproc (%d)\n", ret);

	ret = rproc_start(0);
	if (ret)
		panic("Firmware init failed on rproc (%d)\n", ret);
}

static void k3_sysfw_configure_using_fit(void *fit,
					 struct ti_sci_handle *ti_sci)
{
	struct ti_sci_board_ops *board_ops = &ti_sci->ops.board_ops;
	int images;
	const void *cfg_fragment_addr;
	size_t cfg_fragment_size;
	int ret;

	/* Find the node holding the images information */
	images = fdt_path_offset(fit, FIT_IMAGES_PATH);
	if (images < 0)
		panic("Cannot find /images node (%d)\n", images);

	/* Extract board configuration from FIT */
	ret = fit_get_data_by_name(fit, images, SYSFW_CFG_BOARD,
				   &cfg_fragment_addr, &cfg_fragment_size);
	if (ret < 0)
		panic("Error accessing %s node in FIT (%d)\n", SYSFW_CFG_BOARD,
		      ret);

	/* Apply board configuration to SYSFW */
	ret = board_ops->board_config(ti_sci,
				      (u64)(u32)cfg_fragment_addr,
				      (u32)cfg_fragment_size);
	if (ret)
		panic("Failed to set board configuration (%d)\n", ret);

	/* Extract power/clock (PM) specific configuration from FIT */
	ret = fit_get_data_by_name(fit, images, SYSFW_CFG_PM,
				   &cfg_fragment_addr, &cfg_fragment_size);
	if (ret < 0)
		panic("Error accessing %s node in FIT (%d)\n", SYSFW_CFG_PM,
		      ret);

	/* Apply power/clock (PM) specific configuration to SYSFW */
	ret = board_ops->board_config_pm(ti_sci,
					 (u64)(u32)cfg_fragment_addr,
					 (u32)cfg_fragment_size);
	if (ret)
		panic("Failed to set board PM configuration (%d)\n", ret);

	/* Extract resource management (RM) specific configuration from FIT */
	ret = fit_get_data_by_name(fit, images, SYSFW_CFG_RM,
				   &cfg_fragment_addr, &cfg_fragment_size);
	if (ret < 0)
		panic("Error accessing %s node in FIT (%d)\n", SYSFW_CFG_RM,
		      ret);

	/* Apply resource management (RM) configuration to SYSFW */
	ret = board_ops->board_config_rm(ti_sci,
					 (u64)(u32)cfg_fragment_addr,
					 (u32)cfg_fragment_size);
	if (ret)
		panic("Failed to set board RM configuration (%d)\n", ret);

	/* Extract security specific configuration from FIT */
	ret = fit_get_data_by_name(fit, images, SYSFW_CFG_SEC,
				   &cfg_fragment_addr, &cfg_fragment_size);
	if (ret < 0)
		panic("Error accessing %s node in FIT (%d)\n", SYSFW_CFG_SEC,
		      ret);

	/* Apply security configuration to SYSFW */
	ret = board_ops->board_config_security(ti_sci,
					       (u64)(u32)cfg_fragment_addr,
					       (u32)cfg_fragment_size);
	if (ret)
		panic("Failed to set board security configuration (%d)\n",
		      ret);
}

#if CONFIG_IS_ENABLED(DFU)
static int k3_sysfw_dfu_download(void *addr)
{
	char dfu_str[50];
	int ret;

	sprintf(dfu_str, "sysfw.itb ram 0x%p 0x%x", addr,
		CONFIG_K3_SYSFW_IMAGE_SIZE_MAX);
	ret = dfu_config_entities(dfu_str, "ram", "0");
	if (ret) {
		dfu_free_entities();
		goto exit;
	}

	run_usb_dnl_gadget(0, "usb_dnl_dfu");
exit:
	dfu_free_entities();
	return ret;
}
#endif

#if CONFIG_IS_ENABLED(SPI_LOAD)
static void *k3_sysfw_get_spi_addr(void)
{
	struct udevice *dev;
	fdt_addr_t addr;
	int ret;

	ret = uclass_find_device_by_seq(UCLASS_SPI, CONFIG_SF_DEFAULT_BUS,
					true, &dev);
	if (ret)
		return NULL;

	addr = dev_read_addr_index(dev, 1);
	if (addr == FDT_ADDR_T_NONE)
		return NULL;

	return (void *)(addr + CONFIG_K3_SYSFW_IMAGE_SPI_OFFS);
}
#endif

void k3_sysfw_loader(void (*config_pm_pre_callback) (void),
		     void (*config_pm_done_callback)(void))
{
	struct spl_image_info spl_image = { 0 };
	struct spl_boot_device bootdev = { 0 };
	struct ti_sci_handle *ti_sci;
	int ret = 0;

	/* Reserve a block of aligned memory for loading the SYSFW image */
	sysfw_load_address = memalign(ARCH_DMA_MINALIGN,
				      CONFIG_K3_SYSFW_IMAGE_SIZE_MAX);
	if (!sysfw_load_address)
		panic("Error allocating %u bytes of memory for SYSFW image\n",
		      CONFIG_K3_SYSFW_IMAGE_SIZE_MAX);

	debug("%s: allocated %u bytes at 0x%p\n", __func__,
	      CONFIG_K3_SYSFW_IMAGE_SIZE_MAX, sysfw_load_address);

	/* Set load address for legacy modes that bypass spl_get_load_buffer */
	spl_image.load_addr = (uintptr_t)sysfw_load_address;

	bootdev.boot_device = spl_boot_device();

	/* Load combined System Controller firmware and config data image */
	switch (bootdev.boot_device) {
#if CONFIG_IS_ENABLED(MMC_SUPPORT)
	case BOOT_DEVICE_MMC1:
	case BOOT_DEVICE_MMC2:
	case BOOT_DEVICE_MMC2_2:
		ret = spl_mmc_load(&spl_image, &bootdev,
#ifdef CONFIG_K3_SYSFW_IMAGE_NAME
				   CONFIG_K3_SYSFW_IMAGE_NAME,
#else
				   NULL,
#endif
#ifdef CONFIG_K3_SYSFW_IMAGE_MMCSD_RAW_MODE_PART
				   CONFIG_K3_SYSFW_IMAGE_MMCSD_RAW_MODE_PART,
#else
				   0,
#endif
#ifdef CONFIG_K3_SYSFW_IMAGE_MMCSD_RAW_MODE_SECT
				   CONFIG_K3_SYSFW_IMAGE_MMCSD_RAW_MODE_SECT);
#else
				   0);
#endif
		break;
#endif
#if CONFIG_IS_ENABLED(SPI_LOAD)
	case BOOT_DEVICE_SPI:
		sysfw_load_address = k3_sysfw_get_spi_addr();
		if (!sysfw_load_address)
			ret = -ENODEV;
		break;
#endif
#if CONFIG_IS_ENABLED(YMODEM_SUPPORT)
	case BOOT_DEVICE_UART:
#ifdef CONFIG_K3_EARLY_CONS
		/*
		 * Establish a serial console if not yet available as required
		 * for UART-based boot. For this use the early console feature
		 * that allows setting up a UART for use before SYSFW has been
		 * brought up. Note that the associated UART module's clocks
		 * must have gotten enabled by the ROM bootcode which will be
		 * the case when continuing to boot serially from the same
		 * UART that the ROM loaded the initial bootloader from.
		 */
		if (!gd->have_console)
			early_console_init();
#endif
		ret = spl_ymodem_load_image(&spl_image, &bootdev);
		break;
#endif
#if CONFIG_IS_ENABLED(DFU)
	case BOOT_DEVICE_DFU:
		ret = k3_sysfw_dfu_download(sysfw_load_address);
		break;
#endif
	default:
		panic("Loading SYSFW image from device %u not supported!\n",
		      bootdev.boot_device);
	}

	if (ret)
		panic("Error %d occurred during loading SYSFW image!\n", ret);

	/*
	 * Now that SYSFW got loaded set helper flag to restore regular SPL
	 * loader behavior so we can later boot into the next stage as expected.
	 */
	sysfw_loaded = true;

	/* Ensure the SYSFW image is in FIT format */
	if (image_get_magic((const image_header_t *)sysfw_load_address) !=
	    FDT_MAGIC)
		panic("SYSFW image not in FIT format!\n");

	/* Extract and start SYSFW */
	k3_sysfw_load_using_fit(sysfw_load_address);

	/* Get handle for accessing SYSFW services */
	ti_sci = get_ti_sci_handle();

	if (config_pm_pre_callback)
		config_pm_pre_callback();

	/* Parse and apply the different SYSFW configuration fragments */
	k3_sysfw_configure_using_fit(sysfw_load_address, ti_sci);

	/*
	 * Now that all clocks and PM aspects are setup, invoke a user-
	 * provided callback function. Usually this callback would be used
	 * to setup or re-configure the U-Boot console UART.
	 */
	if (config_pm_done_callback)
		config_pm_done_callback();
}
