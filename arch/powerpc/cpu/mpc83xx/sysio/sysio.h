#ifdef CONFIG_ARCH_MPC8308

#ifndef CONFIG_SYS_SICRL
#define CONFIG_SYS_SICRL (\
	CONFIG_SICRL_SPI |\
	CONFIG_SICRL_UART |\
	CONFIG_SICRL_IRQ |\
	CONFIG_SICRL_I2C2 |\
	CONFIG_SICRL_ETSEC1_A \
)
#endif

#ifndef CONFIG_SYS_SICRH
#define CONFIG_SYS_SICRH (\
	CONFIG_SICRH_ESDHC_A |\
	CONFIG_SICRH_ESDHC_B |\
	CONFIG_SICRH_ESDHC_C |\
	CONFIG_SICRH_GPIO_A |\
	CONFIG_SICRH_GPIO_B |\
	CONFIG_SICRH_IEEE1588_A |\
	CONFIG_SICRH_USB |\
	CONFIG_SICRH_GTM |\
	CONFIG_SICRH_IEEE1588_B |\
	CONFIG_SICRH_ETSEC2 |\
	CONFIG_SICRH_GPIOSEL |\
	CONFIG_SICRH_TMROBI |\
	CONFIG_SICRH_TMSOBI1 |\
	CONFIG_SICRH_TMSOBI2 \
)
#endif

#endif
