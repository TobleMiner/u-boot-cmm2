#
# (C) Copyright 2000-2013
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:	GPL-2.0+
#
#########################################################################

ifeq ($(CURDIR),$(SRCTREE))
dir :=
else
dir := $(subst $(SRCTREE)/,,$(CURDIR))
endif

ifneq ($(OBJTREE),$(SRCTREE))
# Create object files for SPL in a separate directory
ifeq ($(CONFIG_SPL_BUILD),y)
ifeq ($(CONFIG_TPL_BUILD),y)
obj := $(if $(dir),$(TPLTREE)/$(dir)/,$(TPLTREE)/)
else
obj := $(if $(dir),$(SPLTREE)/$(dir)/,$(SPLTREE)/)
endif
else
obj := $(if $(dir),$(OBJTREE)/$(dir)/,$(OBJTREE)/)
endif
src := $(if $(dir),$(SRCTREE)/$(dir)/,$(SRCTREE)/)

$(shell mkdir -p $(obj))
else
# Create object files for SPL in a separate directory
ifeq ($(CONFIG_SPL_BUILD),y)
ifeq ($(CONFIG_TPL_BUILD),y)
obj := $(if $(dir),$(TPLTREE)/$(dir)/,$(TPLTREE)/)
else
obj := $(if $(dir),$(SPLTREE)/$(dir)/,$(SPLTREE)/)

endif
$(shell mkdir -p $(obj))
else
obj :=
endif
src :=
endif

# clean the slate ...
PLATFORM_RELFLAGS =
PLATFORM_CPPFLAGS =
PLATFORM_LDFLAGS =

#########################################################################
#
# Option checker, gcc version (courtesy linux kernel) to ensure
# only supported compiler options are used
#
CC_OPTIONS_CACHE_FILE := $(OBJTREE)/include/generated/cc_options.mk
CC_TEST_OFILE := $(OBJTREE)/include/generated/cc_test_file.o

-include $(CC_OPTIONS_CACHE_FILE)

cc-option-sys = $(shell mkdir -p $(dir $(CC_TEST_OFILE)); \
		if $(CC) $(CFLAGS) $(1) -S -xc /dev/null -o $(CC_TEST_OFILE) \
		> /dev/null 2>&1; then \
		echo 'CC_OPTIONS += $(strip $1)' >> $(CC_OPTIONS_CACHE_FILE); \
		echo "$(1)"; fi)

ifeq ($(CONFIG_CC_OPT_CACHE_DISABLE),y)
cc-option = $(strip $(if $(call cc-option-sys,$1),$1,$2))
else
cc-option = $(strip $(if $(findstring $1,$(CC_OPTIONS)),$1,\
		$(if $(call cc-option-sys,$1),$1,$2)))
endif

# cc-version
# Usage gcc-ver := $(call cc-version)
cc-version = $(shell $(CONFIG_SHELL) $(SRCTREE)/scripts/gcc-version.sh $(CC))
binutils-version = $(shell $(CONFIG_SHELL) $(SRCTREE)/scripts/binutils-version.sh $(AS))
dtc-version = $(shell $(CONFIG_SHELL) $(SRCTREE)/scripts/dtc-version.sh $(DTC))

#########################################################################

# Load generated board configuration
ifeq ($(CONFIG_TPL_BUILD),y)
# Include TPL autoconf
sinclude $(OBJTREE)/include/tpl-autoconf.mk
else
ifeq ($(CONFIG_SPL_BUILD),y)
# Include SPL autoconf
sinclude $(OBJTREE)/include/spl-autoconf.mk
else
# Include normal autoconf
sinclude $(OBJTREE)/include/autoconf.mk
endif
endif
sinclude $(OBJTREE)/include/config.mk

# Some architecture config.mk files need to know what CPUDIR is set to,
# so calculate CPUDIR before including ARCH/SOC/CPU config.mk files.
# Check if arch/$ARCH/cpu/$CPU exists, otherwise assume arch/$ARCH/cpu contains
# CPU-specific code.
CPUDIR=arch/$(ARCH)/cpu/$(CPU)
ifneq ($(SRCTREE)/$(CPUDIR),$(wildcard $(SRCTREE)/$(CPUDIR)))
CPUDIR=arch/$(ARCH)/cpu
endif

sinclude $(TOPDIR)/arch/$(ARCH)/config.mk	# include architecture dependend rules
sinclude $(TOPDIR)/$(CPUDIR)/config.mk		# include  CPU	specific rules

ifdef	SOC
sinclude $(TOPDIR)/$(CPUDIR)/$(SOC)/config.mk	# include  SoC	specific rules
endif
ifdef	VENDOR
BOARDDIR = $(VENDOR)/$(BOARD)
else
BOARDDIR = $(BOARD)
endif
ifdef	BOARD
sinclude $(TOPDIR)/board/$(BOARDDIR)/config.mk	# include board specific rules
endif

#########################################################################

# We don't actually use $(ARFLAGS) anywhere anymore, so catch people
# who are porting old code to latest mainline but not updating $(AR).
ARFLAGS = $(error update your Makefile to use cmd_link_o_target and not AR)
RELFLAGS= $(PLATFORM_RELFLAGS)
DBGFLAGS= -g # -DDEBUG
OPTFLAGS= -Os #-fomit-frame-pointer

OBJCFLAGS += --gap-fill=0xff

gccincdir := $(shell $(CC) -print-file-name=include)

CPPFLAGS := $(DBGFLAGS) $(OPTFLAGS) $(RELFLAGS)		\
	-D__KERNEL__

# Enable garbage collection of un-used sections for SPL
ifeq ($(CONFIG_SPL_BUILD),y)
CPPFLAGS += -ffunction-sections -fdata-sections
LDFLAGS_FINAL += --gc-sections
endif

ifneq ($(CONFIG_SYS_TEXT_BASE),)
CPPFLAGS += -DCONFIG_SYS_TEXT_BASE=$(CONFIG_SYS_TEXT_BASE)
endif

ifeq ($(CONFIG_SPL_BUILD),y)
CPPFLAGS += -DCONFIG_SPL_BUILD
ifeq ($(CONFIG_TPL_BUILD),y)
CPPFLAGS += -DCONFIG_TPL_BUILD
endif
endif

# Does this architecture support generic board init?
ifeq ($(__HAVE_ARCH_GENERIC_BOARD),)
ifneq ($(CONFIG_SYS_GENERIC_BOARD),)
CHECK_GENERIC_BOARD = $(error Your architecture does not support generic board. \
Please undefined CONFIG_SYS_GENERIC_BOARD in your board config file)
endif
endif

ifneq ($(OBJTREE),$(SRCTREE))
CPPFLAGS += -I$(OBJTREE)/include
endif

CPPFLAGS += -I$(TOPDIR)/include -I$(SRCTREE)/arch/$(ARCH)/include
CPPFLAGS += -fno-builtin -ffreestanding -nostdinc	\
	-isystem $(gccincdir) -pipe $(PLATFORM_CPPFLAGS)

CFLAGS := $(CPPFLAGS) -Wall -Wstrict-prototypes

ifdef BUILD_TAG
CFLAGS += -DBUILD_TAG='"$(BUILD_TAG)"'
endif

CFLAGS_SSP := $(call cc-option,-fno-stack-protector)
CFLAGS += $(CFLAGS_SSP)
# Some toolchains enable security related warning flags by default,
# but they don't make much sense in the u-boot world, so disable them.
CFLAGS_WARN := $(call cc-option,-Wno-format-nonliteral) \
	       $(call cc-option,-Wno-format-security)
CFLAGS += $(CFLAGS_WARN)

# Report stack usage if supported
CFLAGS_STACK := $(call cc-option,-fstack-usage)
CFLAGS += $(CFLAGS_STACK)

BCURDIR = $(subst $(SRCTREE)/,,$(CURDIR:$(obj)%=%))

ifeq ($(findstring examples/,$(BCURDIR)),)
ifeq ($(CONFIG_SPL_BUILD),)
ifdef FTRACE
CFLAGS += -finstrument-functions -DFTRACE
endif
endif
endif

# $(CPPFLAGS) sets -g, which causes gcc to pass a suitable -g<format>
# option to the assembler.
AFLAGS_DEBUG :=

# turn jbsr into jsr for m68k
ifeq ($(ARCH),m68k)
ifeq ($(findstring 3.4,$(shell $(CC) --version)),3.4)
AFLAGS_DEBUG := -Wa,-gstabs,-S
endif
endif

AFLAGS := $(AFLAGS_DEBUG) -D__ASSEMBLY__ $(CPPFLAGS)

LDFLAGS += $(PLATFORM_LDFLAGS)
LDFLAGS_FINAL += -Bstatic

LDFLAGS_u-boot += -T $(obj)u-boot.lds $(LDFLAGS_FINAL)
ifneq ($(CONFIG_SYS_TEXT_BASE),)
LDFLAGS_u-boot += -Ttext $(CONFIG_SYS_TEXT_BASE)
endif

LDFLAGS_$(SPL_BIN) += -T $(obj)u-boot-spl.lds $(LDFLAGS_FINAL)
ifneq ($(CONFIG_SPL_TEXT_BASE),)
LDFLAGS_$(SPL_BIN) += -Ttext $(CONFIG_SPL_TEXT_BASE)
endif

# Location of a usable BFD library, where we define "usable" as
# "built for ${HOST}, supports ${TARGET}".  Sensible values are
# - When cross-compiling: the root of the cross-environment
# - Linux/ppc (native): /usr
# - NetBSD/ppc (native): you lose ... (must extract these from the
#   binutils build directory, plus the native and U-Boot include
#   files don't like each other)
#
# So far, this is used only by tools/gdb/Makefile.

ifeq ($(HOSTOS),darwin)
BFD_ROOT_DIR =		/usr/local/tools
else
ifeq ($(HOSTARCH),$(ARCH))
# native
BFD_ROOT_DIR =		/usr
else
#BFD_ROOT_DIR =		/LinuxPPC/CDK		# Linux/i386
#BFD_ROOT_DIR =		/usr/pkg/cross		# NetBSD/i386
BFD_ROOT_DIR =		/opt/powerpc
endif
endif

#########################################################################

export	CONFIG_SYS_TEXT_BASE PLATFORM_CPPFLAGS PLATFORM_RELFLAGS CPPFLAGS CFLAGS AFLAGS
