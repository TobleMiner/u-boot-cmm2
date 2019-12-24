// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2018 Linaro Ltd.
 * Sam Protsenko <semen.protsenko@linaro.org>
 */

#include <env.h>
#include <image-android-dt.h>
#include <common.h>

enum cmd_adtimg_info {
	CMD_ADTIMG_START = 0,
	CMD_ADTIMG_SIZE,
};

static int do_adtimg_dump(cmd_tbl_t *cmdtp, int flag, int argc,
			  char * const argv[])
{
	char *endp;
	ulong hdr_addr;

	if (argc != 2)
		return CMD_RET_USAGE;

	hdr_addr = simple_strtoul(argv[1], &endp, 16);
	if (*endp != '\0') {
		printf("Error: Wrong image address\n");
		return CMD_RET_FAILURE;
	}

	if (!android_dt_check_header(hdr_addr)) {
		printf("Error: DT image header is incorrect\n");
		return CMD_RET_FAILURE;
	}

	android_dt_print_contents(hdr_addr);

	return CMD_RET_SUCCESS;
}

static int adtimg_get_fdt(int argc, char * const argv[],
			  enum cmd_adtimg_info cmd)
{
	ulong hdr_addr;
	u32 index;
	char *endp;
	ulong fdt_addr;
	u32 fdt_size;
	char buf[65];

	if (argc != 4)
		return CMD_RET_USAGE;

	hdr_addr = simple_strtoul(argv[1], &endp, 16);
	if (*endp != '\0') {
		printf("Error: Wrong image address\n");
		return CMD_RET_FAILURE;
	}

	if (!android_dt_check_header(hdr_addr)) {
		printf("Error: DT image header is incorrect\n");
		return CMD_RET_FAILURE;
	}

	index = simple_strtoul(argv[2], &endp, 0);
	if (*endp != '\0') {
		printf("Error: Wrong index\n");
		return CMD_RET_FAILURE;
	}

	if (!android_dt_get_fdt_by_index(hdr_addr, index, &fdt_addr, &fdt_size))
		return CMD_RET_FAILURE;

	switch (cmd) {
	case CMD_ADTIMG_START:
		snprintf(buf, sizeof(buf), "%lx", fdt_addr);
		break;
	case CMD_ADTIMG_SIZE:
		snprintf(buf, sizeof(buf), "%x", fdt_size);
		break;
	default:
		printf("Error: Unknown cmd_adtimg_info value: %d\n", cmd);
		return CMD_RET_FAILURE;
	}

	env_set(argv[3], buf);

	return CMD_RET_SUCCESS;
}

static int do_adtimg_start(cmd_tbl_t *cmdtp, int flag, int argc,
			   char * const argv[])
{
	return adtimg_get_fdt(argc, argv, CMD_ADTIMG_START);
}

static int do_adtimg_size(cmd_tbl_t *cmdtp, int flag, int argc,
			  char * const argv[])
{
	return adtimg_get_fdt(argc, argv, CMD_ADTIMG_SIZE);
}

static cmd_tbl_t cmd_adtimg_sub[] = {
	U_BOOT_CMD_MKENT(dump, 2, 0, do_adtimg_dump, "", ""),
	U_BOOT_CMD_MKENT(start, 4, 0, do_adtimg_start, "", ""),
	U_BOOT_CMD_MKENT(size, 4, 0, do_adtimg_size, "", ""),
};

static int do_adtimg(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	cmd_tbl_t *cp;

	cp = find_cmd_tbl(argv[1], cmd_adtimg_sub, ARRAY_SIZE(cmd_adtimg_sub));

	/* Strip off leading 'adtimg' command argument */
	argc--;
	argv++;

	if (!cp || argc > cp->maxargs)
		return CMD_RET_USAGE;
	if (flag == CMD_FLAG_REPEAT && !cmd_is_repeatable(cp))
		return CMD_RET_SUCCESS;

	return cp->cmd(cmdtp, flag, argc, argv);
}

U_BOOT_CMD(
	adtimg, CONFIG_SYS_MAXARGS, 0, do_adtimg,
	"manipulate dtb/dtbo Android image",
	"dump <addr>\n"
	"    - parse specified image and print its structure info\n"
	"      <addr>: image address in RAM, in hex\n"
	"adtimg start <addr> <index> <varname>\n"
	"    - get address (hex) of FDT in the image, by index\n"
	"      <addr>: image address in RAM, in hex\n"
	"      <index>: index of desired FDT in the image\n"
	"      <varname>: name of variable where to store address of FDT\n"
	"adtimg size <addr> <index> <varname>\n"
	"    - get size (hex, bytes) of FDT in the image, by index\n"
	"      <addr>: image address in RAM, in hex\n"
	"      <index>: index of desired FDT in the image\n"
	"      <varname>: name of variable where to store size of FDT"
);
