ifndef NAND_SPL
ifeq ($(CONFIG_NAND), y)
TEXT_BASE = $(CONFIG_RAMBOOT_TEXT_BASE)
endif
endif

ifndef TEXT_BASE
TEXT_BASE = 0xFE000000
endif
