#
# (C) Copyright 2007-2008 Michal Simek
# Michal SIMEK <monstr@monstr.eu>
#
# (C) Copyright 2004 Atmark Techno, Inc.
# Yasushi SHOJI <yashi@atmark-techno.com>
#
# SPDX-License-Identifier:	GPL-2.0+
#

ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE := mb-
endif

CONFIG_STANDALONE_LOAD_ADDR ?= 0x80F00000

PLATFORM_CPPFLAGS += -ffixed-r31 -D__microblaze__
