#
# Linux-Kernel is expected to be at 1000'8000,
# entry 1000'8000 (mem base + reserved)
#
# We load ourself to internal RAM at 2001'2000
# Check map file when changing CONFIG_SYS_TEXT_BASE.
# Everything has fit into 192kB internal SRAM!
#

# XXX CONFIG_SYS_TEXT_BASE = 0x20012000
CONFIG_SYS_TEXT_BASE = 0x13FC0000
