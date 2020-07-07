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
#include <uuid.h>
#include <acpi/acpigen.h>
#include <acpi/acpi_device.h>
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

void acpigen_emit_ext_op(struct acpi_ctx *ctx, uint op)
{
	acpigen_emit_byte(ctx, EXT_OP_PREFIX);
	acpigen_emit_byte(ctx, op);
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

void acpigen_write_string(struct acpi_ctx *ctx, const char *str)
{
	acpigen_emit_byte(ctx, STRING_PREFIX);
	acpigen_emit_string(ctx, str);
}

/*
 * The naming conventions for ACPI namespace names are a bit tricky as
 * each element has to be 4 chars wide ("All names are a fixed 32 bits.")
 * and "By convention, when an ASL compiler pads a name shorter than 4
 * characters, it is done so with trailing underscores ('_')".
 *
 * Check sections 5.3, 20.2.2 and 20.4 of ACPI spec 6.3 for details.
 */
static void acpigen_emit_simple_namestring(struct acpi_ctx *ctx,
					   const char *name)
{
	const char *ptr;
	int i;

	for (i = 0, ptr = name; i < 4; i++) {
		if (!*ptr || *ptr == '.')
			acpigen_emit_byte(ctx, '_');
		else
			acpigen_emit_byte(ctx, *ptr++);
	}
}

static void acpigen_emit_double_namestring(struct acpi_ctx *ctx,
					   const char *name, int dotpos)
{
	acpigen_emit_byte(ctx, DUAL_NAME_PREFIX);
	acpigen_emit_simple_namestring(ctx, name);
	acpigen_emit_simple_namestring(ctx, &name[dotpos + 1]);
}

static void acpigen_emit_multi_namestring(struct acpi_ctx *ctx,
					  const char *name)
{
	unsigned char *pathlen;
	int count = 0;

	acpigen_emit_byte(ctx, MULTI_NAME_PREFIX);
	pathlen = ctx->current;
	acpigen_emit_byte(ctx, 0);

	while (*name) {
		acpigen_emit_simple_namestring(ctx, name);
		/* find end or next entity */
		while (*name != '.' && *name)
			name++;
		/* forward to next */
		if (*name == '.')
			name++;
		count++;
	}

	*pathlen = count;
}

void acpigen_emit_namestring(struct acpi_ctx *ctx, const char *namepath)
{
	int dotcount;
	int dotpos;
	int i;

	/* We can start with a '\' */
	if (*namepath == '\\') {
		acpigen_emit_byte(ctx, '\\');
		namepath++;
	}

	/* And there can be any number of '^' */
	while (*namepath == '^') {
		acpigen_emit_byte(ctx, '^');
		namepath++;
	}

	for (i = 0, dotcount = 0; namepath[i]; i++) {
		if (namepath[i] == '.') {
			dotcount++;
			dotpos = i;
		}
	}

	/* If we have only \\ or only ^* then we need to add a null name */
	if (!*namepath)
		acpigen_emit_byte(ctx, ZERO_OP);
	else if (dotcount == 0)
		acpigen_emit_simple_namestring(ctx, namepath);
	else if (dotcount == 1)
		acpigen_emit_double_namestring(ctx, namepath, dotpos);
	else
		acpigen_emit_multi_namestring(ctx, namepath);
}

void acpigen_write_name(struct acpi_ctx *ctx, const char *namepath)
{
	acpigen_emit_byte(ctx, NAME_OP);
	acpigen_emit_namestring(ctx, namepath);
}

static void acpigen_write_method_internal(struct acpi_ctx *ctx,
					  const char *name, uint flags)
{
	acpigen_emit_byte(ctx, METHOD_OP);
	acpigen_write_len_f(ctx);
	acpigen_emit_namestring(ctx, name);
	acpigen_emit_byte(ctx, flags);
}

/* Method (name, nargs, NotSerialized) */
void acpigen_write_method(struct acpi_ctx *ctx, const char *name, int nargs)
{
	acpigen_write_method_internal(ctx, name,
				      nargs & ACPI_METHOD_NARGS_MASK);
}

/* Method (name, nargs, Serialized) */
void acpigen_write_method_serialized(struct acpi_ctx *ctx, const char *name,
				     int nargs)
{
	acpigen_write_method_internal(ctx, name,
				      (nargs & ACPI_METHOD_NARGS_MASK) |
				      ACPI_METHOD_SERIALIZED_MASK);
}

void acpigen_write_sta(struct acpi_ctx *ctx, uint status)
{
	/* Method (_STA, 0, NotSerialized) { Return (status) } */
	acpigen_write_method(ctx, "_STA", 0);
	acpigen_emit_byte(ctx, RETURN_OP);
	acpigen_write_byte(ctx, status);
	acpigen_pop_len(ctx);
}

/*
 * ToUUID(uuid)
 *
 * ACPI 6.3 Section 19.6.142 table 19-438 defines a special output order for the
 * bytes that make up a UUID Buffer object:
 *
 * UUID byte order for input to this function:
 *   aabbccdd-eeff-gghh-iijj-kkllmmnnoopp
 *
 * UUID byte order output by this function:
 *   ddccbbaa-ffee-hhgg-iijj-kkllmmnnoopp
 */
int acpigen_write_uuid(struct acpi_ctx *ctx, const char *uuid)
{
	u8 buf[UUID_BIN_LEN];
	int ret;

	/* Parse UUID string into bytes */
	ret = uuid_str_to_bin(uuid, buf, UUID_STR_FORMAT_GUID);
	if (ret)
		return log_msg_ret("bad hex", -EINVAL);

	/* BufferOp */
	acpigen_emit_byte(ctx, BUFFER_OP);
	acpigen_write_len_f(ctx);

	/* Buffer length in bytes */
	acpigen_write_word(ctx, UUID_BIN_LEN);

	/* Output UUID in expected order */
	acpigen_emit_stream(ctx, (char *)buf, UUID_BIN_LEN);

	acpigen_pop_len(ctx);

	return 0;
}

void acpigen_write_power_res(struct acpi_ctx *ctx, const char *name, uint level,
			     uint order, const char *const dev_states[],
			     size_t dev_states_count)
{
	size_t i;

	for (i = 0; i < dev_states_count; i++) {
		acpigen_write_name(ctx, dev_states[i]);
		acpigen_write_package(ctx, 1);
		acpigen_emit_simple_namestring(ctx, name);
		acpigen_pop_len(ctx);		/* Package */
	}

	acpigen_emit_ext_op(ctx, POWER_RES_OP);

	acpigen_write_len_f(ctx);

	acpigen_emit_simple_namestring(ctx, name);
	acpigen_emit_byte(ctx, level);
	acpigen_emit_word(ctx, order);
}

/* Sleep (ms) */
void acpigen_write_sleep(struct acpi_ctx *ctx, u64 sleep_ms)
{
	acpigen_emit_ext_op(ctx, SLEEP_OP);
	acpigen_write_integer(ctx, sleep_ms);
}

void acpigen_write_store(struct acpi_ctx *ctx)
{
	acpigen_emit_byte(ctx, STORE_OP);
}

/* Or (arg1, arg2, res) */
void acpigen_write_or(struct acpi_ctx *ctx, u8 arg1, u8 arg2, u8 res)
{
	acpigen_emit_byte(ctx, OR_OP);
	acpigen_emit_byte(ctx, arg1);
	acpigen_emit_byte(ctx, arg2);
	acpigen_emit_byte(ctx, res);
}

/* And (arg1, arg2, res) */
void acpigen_write_and(struct acpi_ctx *ctx, u8 arg1, u8 arg2, u8 res)
{
	acpigen_emit_byte(ctx, AND_OP);
	acpigen_emit_byte(ctx, arg1);
	acpigen_emit_byte(ctx, arg2);
	acpigen_emit_byte(ctx, res);
}

/* Not (arg, res) */
void acpigen_write_not(struct acpi_ctx *ctx, u8 arg, u8 res)
{
	acpigen_emit_byte(ctx, NOT_OP);
	acpigen_emit_byte(ctx, arg);
	acpigen_emit_byte(ctx, res);
}

/* Store (str, DEBUG) */
void acpigen_write_debug_string(struct acpi_ctx *ctx, const char *str)
{
	acpigen_write_store(ctx);
	acpigen_write_string(ctx, str);
	acpigen_emit_ext_op(ctx, DEBUG_OP);
}

/**
 * acpigen_get_dw0_in_local5() - Generate code to put dw0 cfg0 in local5
 *
 * Store (\_SB.GPC0 (addr), Local5)
 *
 * \_SB.GPC0 is used to read cfg0 value from dw0. It is typically defined in
 * the board's gpiolib.asl
 *
 * The value needs to be stored in a local variable so that it can be used in
 * expressions in the ACPI code.
 *
 * @ctx: ACPI context pointer
 * @dw0_read: Name to use to read dw0, e.g. "\\_SB.GPC0"
 * @addr: GPIO pin configuration register address
 *
 */
static void acpigen_get_dw0_in_local5(struct acpi_ctx *ctx,
				      const char *dw0_read, ulong addr)
{
	acpigen_write_store(ctx);
	acpigen_emit_namestring(ctx, dw0_read);
	acpigen_write_integer(ctx, addr);
	acpigen_emit_byte(ctx, LOCAL5_OP);
}

/**
 * acpigen_set_gpio_val() - Emit code to set value of TX GPIO to on/off
 *
 * @ctx: ACPI context pointer
 * @dw0_read: Method name to use to read dw0, e.g. "\\_SB.GPC0"
 * @dw0_write: Method name to use to read dw0, e.g. "\\_SB.SPC0"
 * @gpio_num: GPIO number to adjust
 * @vaL: true to set on, false to set off
 */
static int acpigen_set_gpio_val(struct acpi_ctx *ctx, u32 tx_state_val,
				const char *dw0_read, const char *dw0_write,
				struct acpi_gpio *gpio, bool val)
{
	acpigen_get_dw0_in_local5(ctx, dw0_read, gpio->pin0_addr);

	/* Store (0x40, Local0) */
	acpigen_write_store(ctx);
	acpigen_write_integer(ctx, tx_state_val);
	acpigen_emit_byte(ctx, LOCAL0_OP);

	if (val) {
		/* Or (Local5, PAD_CFG0_TX_STATE, Local5) */
		acpigen_write_or(ctx, LOCAL5_OP, LOCAL0_OP, LOCAL5_OP);
	} else {
		/* Not (PAD_CFG0_TX_STATE, Local6) */
		acpigen_write_not(ctx, LOCAL0_OP, LOCAL6_OP);

		/* And (Local5, Local6, Local5) */
		acpigen_write_and(ctx, LOCAL5_OP, LOCAL6_OP, LOCAL5_OP);
	}

	/*
	 * \_SB.SPC0 (addr, Local5)
	 * \_SB.SPC0 is used to write cfg0 value in dw0. It is defined in
	 * gpiolib.asl.
	 */
	acpigen_emit_namestring(ctx, dw0_write);
	acpigen_write_integer(ctx, gpio->pin0_addr);
	acpigen_emit_byte(ctx, LOCAL5_OP);

	return 0;
}

int acpigen_set_enable_tx_gpio(struct acpi_ctx *ctx, u32 tx_state_val,
			       const char *dw0_read, const char *dw0_write,
			       struct acpi_gpio *gpio, bool enable)
{
	bool set;
	int ret;

	set = gpio->polarity == ACPI_GPIO_ACTIVE_HIGH ? enable : !enable;
	ret = acpigen_set_gpio_val(ctx, tx_state_val, dw0_read, dw0_write, gpio,
				   set);
	if (ret)
		return log_msg_ret("call", ret);

	return 0;
}
