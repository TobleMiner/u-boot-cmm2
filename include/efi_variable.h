/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2020, Heinrich Schuchardt <xypron.glpk@gmx.de>
 */

#ifndef _EFI_VARIABLE_H
#define _EFI_VARIABLE_H

#include <linux/bitops.h>

#define EFI_VARIABLE_READ_ONLY BIT(31)

/**
 * efi_get_variable() - retrieve value of a UEFI variable
 *
 * @variable_name:	name of the variable
 * @vendor:		vendor GUID
 * @attributes:		attributes of the variable
 * @data_size:		size of the buffer to which the variable value is copied
 * @data:		buffer to which the variable value is copied
 * @timep:		authentication time (seconds since start of epoch)
 * Return:		status code
 */
efi_status_t efi_get_variable_int(u16 *variable_name, const efi_guid_t *vendor,
				  u32 *attributes, efi_uintn_t *data_size,
				  void *data, u64 *timep);

/**
 * efi_set_variable() - set value of a UEFI variable
 *
 * @variable_name:	name of the variable
 * @vendor:		vendor GUID
 * @attributes:		attributes of the variable
 * @data_size:		size of the buffer with the variable value
 * @data:		buffer with the variable value
 * @ro_check:		check the read only read only bit in attributes
 * Return:		status code
 */
efi_status_t efi_set_variable_int(u16 *variable_name, const efi_guid_t *vendor,
				  u32 attributes, efi_uintn_t data_size,
				  const void *data, bool ro_check);

/**
 * efi_get_next_variable_name_int() - enumerate the current variable names
 *
 * @variable_name_size:	size of variable_name buffer in byte
 * @variable_name:	name of uefi variable's name in u16
 * @vendor:		vendor's guid
 *
 * See the Unified Extensible Firmware Interface (UEFI) specification for
 * details.
 *
 * Return: status code
 */
efi_status_t efi_get_next_variable_name_int(efi_uintn_t *variable_name_size,
					    u16 *variable_name,
					    efi_guid_t *vendor);

/**
 * efi_query_variable_info_int() - get information about EFI variables
 *
 * This function implements the QueryVariableInfo() runtime service.
 *
 * See the Unified Extensible Firmware Interface (UEFI) specification for
 * details.
 *
 * @attributes:				bitmask to select variables to be
 *					queried
 * @maximum_variable_storage_size:	maximum size of storage area for the
 *					selected variable types
 * @remaining_variable_storage_size:	remaining size of storage are for the
 *					selected variable types
 * @maximum_variable_size:		maximum size of a variable of the
 *					selected type
 * Returns:				status code
 */
efi_status_t efi_query_variable_info_int(u32 attributes,
					 u64 *maximum_variable_storage_size,
					 u64 *remaining_variable_storage_size,
					 u64 *maximum_variable_size);

#define EFI_VAR_FILE_NAME "ubootefi.var"

#define EFI_VAR_BUF_SIZE 0x4000

#define EFI_VAR_FILE_MAGIC 0x0161566966456255 /* UbEfiVa, version 1 */

/**
 * struct efi_var_entry - UEFI variable file entry
 *
 * @length:	length of enty, multiple of 8
 * @attr:	variable attributes
 * @time:	authentication time (seconds since start of epoch)
 * @guid:	vendor GUID
 * @name:	UTF16 variable name
 */
struct efi_var_entry {
	u32 length;
	u32 attr;
	u64 time;
	efi_guid_t guid;
	u16 name[];
};

/**
 * struct efi_var_file - file for storing UEFI variables
 *
 * @reserved:	unused, may be overwritten by memory probing
 * @magic:	identifies file format
 * @length:	length including header
 * @crc32:	CRC32 without header
 * @var:	variables
 */
struct efi_var_file {
	u64 reserved;
	u64 magic;
	u32 length;
	u32 crc32;
	struct efi_var_entry var[];
};

/**
 * efi_var_to_file() - save non-volatile variables as file
 *
 * File ubootefi.var is created on the EFI system partion.
 *
 * Return:	status code
 */
efi_status_t efi_var_to_file(void);

/**
 * efi_var_from_file() - read variables from file
 *
 * File ubootefi.var is read from the EFI system partitions and the variables
 * stored in the file are created.
 *
 * In case the file does not exist yet or a variable cannot be set EFI_SUCCESS
 * is returned.
 *
 * Return:	status code
 */
efi_status_t efi_var_from_file(void);

#endif
