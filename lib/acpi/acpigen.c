// SPDX-License-Identifier: GPL-2.0
/*
 * Generation of ACPI (Advanced Configuration and Power Interface) tables
 *
 * Copyright 2019 Google LLC
 * Mostly taken from coreboot
 */

#define LOG_CATEGORY LOGC_ACPI

#include <common.h>
#include <dm.h>
#include <log.h>
#include <acpi/acpigen.h>
#include <dm/acpi.h>

u8 *acpigen_get_current(struct acpi_ctx *ctx)
{
	return ctx->current;
}

void acpigen_emit_byte(struct acpi_ctx *ctx, uint data)
{
	*(u8 *)ctx->current++ = data;
}

void acpigen_emit_word(struct acpi_ctx *ctx, uint data)
{
	acpigen_emit_byte(ctx, data & 0xff);
	acpigen_emit_byte(ctx, (data >> 8) & 0xff);
}

void acpigen_emit_dword(struct acpi_ctx *ctx, uint data)
{
	/* Output the value in little-endian format */
	acpigen_emit_byte(ctx, data & 0xff);
	acpigen_emit_byte(ctx, (data >> 8) & 0xff);
	acpigen_emit_byte(ctx, (data >> 16) & 0xff);
	acpigen_emit_byte(ctx, (data >> 24) & 0xff);
}

/*
 * Maximum length for an ACPI object generated by this code,
 *
 * If you need to change this, change acpigen_write_len_f(ctx) and
 * acpigen_pop_len(ctx)
 */
#define ACPIGEN_MAXLEN 0xfffff

void acpigen_write_len_f(struct acpi_ctx *ctx)
{
	assert(ctx->ltop < (ACPIGEN_LENSTACK_SIZE - 1));
	ctx->len_stack[ctx->ltop++] = ctx->current;
	acpigen_emit_byte(ctx, 0);
	acpigen_emit_byte(ctx, 0);
	acpigen_emit_byte(ctx, 0);
}

void acpigen_pop_len(struct acpi_ctx *ctx)
{
	int len;
	char *p;

	assert(ctx->ltop > 0);
	p = ctx->len_stack[--ctx->ltop];
	len = ctx->current - (void *)p;
	assert(len <= ACPIGEN_MAXLEN);
	/* generate store length for 0xfffff max */
	p[0] = ACPI_PKG_LEN_3_BYTES | (len & 0xf);
	p[1] = len >> 4 & 0xff;
	p[2] = len >> 12 & 0xff;
}

char *acpigen_write_package(struct acpi_ctx *ctx, int nr_el)
{
	char *p;

	acpigen_emit_byte(ctx, PACKAGE_OP);
	acpigen_write_len_f(ctx);
	p = ctx->current;
	acpigen_emit_byte(ctx, nr_el);

	return p;
}

void acpigen_write_byte(struct acpi_ctx *ctx, unsigned int data)
{
	acpigen_emit_byte(ctx, BYTE_PREFIX);
	acpigen_emit_byte(ctx, data & 0xff);
}

void acpigen_write_word(struct acpi_ctx *ctx, unsigned int data)
{
	acpigen_emit_byte(ctx, WORD_PREFIX);
	acpigen_emit_word(ctx, data);
}

void acpigen_write_dword(struct acpi_ctx *ctx, unsigned int data)
{
	acpigen_emit_byte(ctx, DWORD_PREFIX);
	acpigen_emit_dword(ctx, data);
}

void acpigen_write_qword(struct acpi_ctx *ctx, u64 data)
{
	acpigen_emit_byte(ctx, QWORD_PREFIX);
	acpigen_emit_dword(ctx, data & 0xffffffff);
	acpigen_emit_dword(ctx, (data >> 32) & 0xffffffff);
}

void acpigen_write_zero(struct acpi_ctx *ctx)
{
	acpigen_emit_byte(ctx, ZERO_OP);
}

void acpigen_write_one(struct acpi_ctx *ctx)
{
	acpigen_emit_byte(ctx, ONE_OP);
}

void acpigen_write_integer(struct acpi_ctx *ctx, u64 data)
{
	if (data == 0)
		acpigen_write_zero(ctx);
	else if (data == 1)
		acpigen_write_one(ctx);
	else if (data <= 0xff)
		acpigen_write_byte(ctx, (unsigned char)data);
	else if (data <= 0xffff)
		acpigen_write_word(ctx, (unsigned int)data);
	else if (data <= 0xffffffff)
		acpigen_write_dword(ctx, (unsigned int)data);
	else
		acpigen_write_qword(ctx, data);
}

void acpigen_emit_stream(struct acpi_ctx *ctx, const char *data, int size)
{
	int i;

	for (i = 0; i < size; i++)
		acpigen_emit_byte(ctx, data[i]);
}

void acpigen_emit_string(struct acpi_ctx *ctx, const char *str)
{
	acpigen_emit_stream(ctx, str, str ? strlen(str) : 0);
	acpigen_emit_byte(ctx, '\0');
}
