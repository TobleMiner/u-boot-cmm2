/*
 * Copyright (C) 2017 Google, Inc
 * Written by Simon Glass <sjg@chromium.org>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <environment.h>

DECLARE_GLOBAL_DATA_PTR;

static struct env_driver *_env_driver_lookup(enum env_location loc)
{
	struct env_driver *drv;
	const int n_ents = ll_entry_count(struct env_driver, env_driver);
	struct env_driver *entry;

	drv = ll_entry_start(struct env_driver, env_driver);
	for (entry = drv; entry != drv + n_ents; entry++) {
		if (loc == entry->location)
			return entry;
	}

	/* Not found */
	return NULL;
}

static enum env_location env_locations[] = {
#ifdef CONFIG_ENV_IS_IN_EEPROM
	ENVL_EEPROM,
#endif
#ifdef CONFIG_ENV_IS_IN_EXT4
	ENVL_EXT4,
#endif
#ifdef CONFIG_ENV_IS_IN_FAT
	ENVL_FAT,
#endif
#ifdef CONFIG_ENV_IS_IN_FLASH
	ENVL_FLASH,
#endif
#ifdef CONFIG_ENV_IS_IN_MMC
	ENVL_MMC,
#endif
#ifdef CONFIG_ENV_IS_IN_NAND
	ENVL_NAND,
#endif
#ifdef CONFIG_ENV_IS_IN_NVRAM
	ENVL_NVRAM,
#endif
#ifdef CONFIG_ENV_IS_IN_REMOTE
	ENVL_REMOTE,
#endif
#ifdef CONFIG_ENV_IS_IN_SPI_FLASH
	ENVL_SPI_FLASH,
#endif
#ifdef CONFIG_ENV_IS_IN_UBI
	ENVL_UBI,
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
	ENVL_NOWHERE,
#endif
};

static enum env_location env_load_location = ENVL_UNKNOWN;

static bool env_has_inited(enum env_location location)
{
	return gd->env_has_init & BIT(location);
}

static void env_set_inited(enum env_location location)
{
	/*
	 * We're using a 32-bits bitmask stored in gd (env_has_init)
	 * using the above enum value as the bit index. We need to
	 * make sure that we're not overflowing it.
	 */
	BUILD_BUG_ON(ARRAY_SIZE(env_locations) > BITS_PER_LONG);

	gd->env_has_init |= BIT(location);
}

/**
 * env_get_location() - Returns the best env location for a board
 * @op: operations performed on the environment
 * @prio: priority between the multiple environments, 0 being the
 *        highest priority
 *
 * This will return the preferred environment for the given priority.
 * This is overridable by boards if they need to.
 *
 * All implementations are free to use the operation, the priority and
 * any other data relevant to their choice, but must take into account
 * the fact that the lowest prority (0) is the most important location
 * in the system. The following locations should be returned by order
 * of descending priorities, from the highest to the lowest priority.
 *
 * Returns:
 * an enum env_location value on success, a negative error code otherwise
 */
__weak enum env_location env_get_location(enum env_operation op, int prio)
{
	switch (op) {
	case ENVOP_GET_CHAR:
	case ENVOP_INIT:
	case ENVOP_LOAD:
		if (prio >= ARRAY_SIZE(env_locations))
			return ENVL_UNKNOWN;

		env_load_location = env_locations[prio];
		return env_load_location;

	case ENVOP_SAVE:
		return env_load_location;
	}

	return ENVL_UNKNOWN;
}


/**
 * env_driver_lookup() - Finds the most suited environment location
 * @op: operations performed on the environment
 * @prio: priority between the multiple environments, 0 being the
 *        highest priority
 *
 * This will try to find the available environment with the highest
 * priority in the system.
 *
 * Returns:
 * NULL on error, a pointer to a struct env_driver otherwise
 */
static struct env_driver *env_driver_lookup(enum env_operation op, int prio)
{
	enum env_location loc = env_get_location(op, prio);
	struct env_driver *drv;

	if (loc == ENVL_UNKNOWN)
		return NULL;

	drv = _env_driver_lookup(loc);
	if (!drv) {
		debug("%s: No environment driver for location %d\n", __func__,
		      loc);
		return NULL;
	}

	return drv;
}

int env_get_char(int index)
{
	struct env_driver *drv;
	int prio;

	if (gd->env_valid == ENV_INVALID)
		return default_environment[index];

	for (prio = 0; (drv = env_driver_lookup(ENVOP_GET_CHAR, prio)); prio++) {
		int ret;

		if (!drv->get_char)
			continue;

		if (!env_has_inited(drv->location))
			continue;

		ret = drv->get_char(index);
		if (!ret)
			return 0;

		debug("%s: Environment %s failed to load (err=%d)\n", __func__,
		      drv->name, ret);
	}

	return -ENODEV;
}

int env_load(void)
{
	struct env_driver *drv;
	int prio;

	for (prio = 0; (drv = env_driver_lookup(ENVOP_LOAD, prio)); prio++) {
		int ret;

		if (!drv->load)
			continue;

		if (!env_has_inited(drv->location))
			continue;

		printf("Loading Environment from %s... ", drv->name);
		ret = drv->load();
		if (ret)
			printf("Failed (%d)\n", ret);
		else
			printf("OK\n");

		if (!ret)
			return 0;
	}

	return -ENODEV;
}

int env_save(void)
{
	struct env_driver *drv;
	int prio;

	for (prio = 0; (drv = env_driver_lookup(ENVOP_SAVE, prio)); prio++) {
		int ret;

		if (!drv->save)
			continue;

		if (!env_has_inited(drv->location))
			continue;

		printf("Saving Environment to %s... ", drv->name);
		ret = drv->save();
		if (ret)
			printf("Failed (%d)\n", ret);
		else
			printf("OK\n");

		if (!ret)
			return 0;
	}

	return -ENODEV;
}

int env_init(void)
{
	struct env_driver *drv;
	int ret = -ENOENT;
	int prio;

	for (prio = 0; (drv = env_driver_lookup(ENVOP_INIT, prio)); prio++) {
		if (!drv->init || !(ret = drv->init()))
			env_set_inited(drv->location);

		debug("%s: Environment %s init done (ret=%d)\n", __func__,
		      drv->name, ret);
	}

	if (!prio)
		return -ENODEV;

	if (ret == -ENOENT) {
		gd->env_addr = (ulong)&default_environment[0];
		gd->env_valid = ENV_VALID;

		return 0;
	}

	return ret;
}
