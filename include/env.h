/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Common environment functions
 *
 * (C) Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 */

#ifndef __ENV_H
#define __ENV_H

#include <stdbool.h>
#include <linux/types.h>

/**
 * env_get_id() - Gets a sequence number for the environment
 *
 * This value increments every time the environment changes, so can be used an
 * an indication of this
 *
 * @return environment ID
 */
int env_get_id(void);

/**
 * env_init() - Set up the pre-relocation environment
 *
 * This locates the environment or uses the default if nothing is available.
 * This must be called before env_get() will work.
 *
 * @return 0 if OK, -ENODEV if no environment drivers are enabled
 */
int env_init(void);

/**
 * env_relocate() - Set up the post-relocation environment
 *
 * This loads the environment into RAM so that it can be modified. This is
 * called after relocation, before the environment is used
 */
void env_relocate(void);

/**
 * env_match() - Match a name / name=value pair
 *
 * This is used prior to relocation for finding envrionment variables
 *
 * @name: A simple 'name', or a 'name=value' pair.
 * @index: The environment index for a 'name2=value2' pair.
 * @return index for the value if the names match, else -1.
 */
int env_match(unsigned char *name, int index);

/**
 * env_get_f() - Look up the value of an environment variable (early)
 *
 * This function is called from env_get() if the environment has not been
 * loaded yet (GD_FLG_ENV_READY flag is 0). Some environment locations will
 * support reading the value (slowly) and some will not.
 *
 * @varname:	Variable to look up
 * @return value of variable, or NULL if not found
 */
int env_get_f(const char *name, char *buf, unsigned int len);

/**
 * env_set_ulong() - set an environment variable to an integer
 *
 * @varname: Variable to adjust
 * @value: Value to set for the variable (will be converted to a string)
 * @return 0 if OK, 1 on error
 */
int env_set_ulong(const char *varname, ulong value);

/**
 * env_set_hex() - set an environment variable to a hex value
 *
 * @varname: Variable to adjust
 * @value: Value to set for the variable (will be converted to a hex string)
 * @return 0 if OK, 1 on error
 */
int env_set_hex(const char *varname, ulong value);

/**
 * env_set_addr - Set an environment variable to an address in hex
 *
 * @varname:	Environment variable to set
 * @addr:	Value to set it to
 * @return 0 if ok, 1 on error
 */
static inline int env_set_addr(const char *varname, const void *addr)
{
	return env_set_hex(varname, (ulong)addr);
}

/**
 * env_complete() - return an auto-complete for environment variables
 *
 * @var: partial name to auto-complete
 * @maxv: Maximum number of matches to return
 * @cmdv: Returns a list of possible matches
 * @maxsz: Size of buffer to use for matches
 * @buf: Buffer to use for matches
 * @dollar_comp: non-zero to wrap each match in ${...}
 * @return number of matches found (in @cmdv)
 */
int env_complete(char *var, int maxv, char *cmdv[], int maxsz, char *buf,
		 bool dollar_comp);

#endif
