/*
 * (C) Copyright 2001-2003
 * Stefan Roese, esd gmbh germany, stefan.roese@esd-electronics.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/processor.h>
#include <command.h>
#include <malloc.h>

/* ------------------------------------------------------------------------- */

#if 0
#define FPGA_DEBUG
#endif

/* fpga configuration data - gzip compressed and generated by bin2c */
const unsigned char fpgadata[] =
{
#include "fpgadata.c"
};

/*
 * include common fpga code (for esd boards)
 */
#include "../common/fpga.c"


int board_early_init_f (void)
{
	/*
	 * IRQ 0-15  405GP internally generated; active high; level sensitive
	 * IRQ 16    405GP internally generated; active low; level sensitive
	 * IRQ 17-24 RESERVED
	 * IRQ 25 (EXT IRQ 0) CAN0; active low; level sensitive
	 * IRQ 26 (EXT IRQ 1) SER0 ; active low; level sensitive
	 * IRQ 27 (EXT IRQ 2) SER1; active low; level sensitive
	 * IRQ 28 (EXT IRQ 3) FPGA 0; active low; level sensitive
	 * IRQ 29 (EXT IRQ 4) FPGA 1; active low; level sensitive
	 * IRQ 30 (EXT IRQ 5) PCI INTA; active low; level sensitive
	 * IRQ 31 (EXT IRQ 6) COMPACT FLASH; active high; level sensitive
	 */
	mtdcr(UIC0SR, 0xFFFFFFFF);       /* clear all ints */
	mtdcr(UIC0ER, 0x00000000);       /* disable all ints */
	mtdcr(UIC0CR, 0x00000000);       /* set all to be non-critical*/
	mtdcr(UIC0PR, 0xFFFFFF9F);       /* set int polarities */
	mtdcr(UIC0TR, 0x10000000);       /* set int trigger levels */
	mtdcr(UIC0VCR, 0x00000001);      /* set vect base=0,INT0 highest priority*/
	mtdcr(UIC0SR, 0xFFFFFFFF);       /* clear all ints */

	/*
	 * EBC Configuration Register: set ready timeout to 512 ebc-clks -> ca. 15 us
	 */
	mtebc (EBC0_CFG, 0xa8400000); /* ebc always driven */

	return 0;
}

int misc_init_r (void)
{
	unsigned char *dst;
	ulong len = sizeof(fpgadata);
	int status;
	int index;
	int i;

	dst = malloc(CONFIG_SYS_FPGA_MAX_SIZE);
	if (gunzip (dst, CONFIG_SYS_FPGA_MAX_SIZE, (uchar *)fpgadata, &len) != 0) {
		printf ("GUNZIP ERROR - must RESET board to recover\n");
		do_reset (NULL, 0, 0, NULL);
	}

	status = fpga_boot(dst, len);
	if (status != 0) {
		printf("\nFPGA: Booting failed ");
		switch (status) {
		case ERROR_FPGA_PRG_INIT_LOW:
			printf("(Timeout: INIT not low after asserting PROGRAM*)\n ");
			break;
		case ERROR_FPGA_PRG_INIT_HIGH:
			printf("(Timeout: INIT not high after deasserting PROGRAM*)\n ");
			break;
		case ERROR_FPGA_PRG_DONE:
			printf("(Timeout: DONE not high after programming FPGA)\n ");
			break;
		}

		/* display infos on fpgaimage */
		index = 15;
		for (i=0; i<4; i++) {
			len = dst[index];
			printf("FPGA: %s\n", &(dst[index+1]));
			index += len+3;
		}
		putc ('\n');
		/* delayed reboot */
		for (i=20; i>0; i--) {
			printf("Rebooting in %2d seconds \r",i);
			for (index=0;index<1000;index++)
				udelay(1000);
		}
		putc ('\n');
		do_reset(NULL, 0, 0, NULL);
	}

	puts("FPGA:  ");

	/* display infos on fpgaimage */
	index = 15;
	for (i=0; i<4; i++) {
		len = dst[index];
		printf("%s ", &(dst[index+1]));
		index += len+3;
	}
	putc ('\n');

	free(dst);

	/*
	 * Reset FPGA via FPGA_DATA pin
	 */
	SET_FPGA(FPGA_PRG | FPGA_CLK);
	udelay(1000); /* wait 1ms */
	SET_FPGA(FPGA_PRG | FPGA_CLK | FPGA_DATA);
	udelay(1000); /* wait 1ms */

	/*
	 * Reset external DUARTs
	 */
	out_be32((void *)GPIO0_OR,
		 in_be32((void *)GPIO0_OR) | CONFIG_SYS_DUART_RST);
	udelay(10); /* wait 10us */
	out_be32((void *)GPIO0_OR,
		 in_be32((void *)GPIO0_OR) & ~CONFIG_SYS_DUART_RST);
	udelay(1000); /* wait 1ms */

	/*
	 * Enable interrupts in exar duart mcr[3]
	 */
	out_8((void *)(DUART0_BA + 4), 0x08);
	out_8((void *)(DUART1_BA + 4), 0x08);
	out_8((void *)(DUART2_BA + 4), 0x08);
	out_8((void *)(DUART3_BA + 4), 0x08);

	return (0);
}


/*
 * Check Board Identity:
 */

int checkboard (void)
{
	char str[64];
	int i = getenv_f("serial#", str, sizeof(str));

	puts ("Board: ");

	if (i == -1) {
		puts ("### No HW ID - assuming WUH405");
	} else {
		puts(str);
	}

	putc ('\n');

	return 0;
}
