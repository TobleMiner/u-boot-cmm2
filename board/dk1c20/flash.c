/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */


#include <common.h>
#include <nios.h>

/*---------------------------------------------------------------------*/
#define BANKSZ	(8 * 1024 * 1024)
#define SECTSZ	(64 * 1024)
#define USERFLASH (2 * 1024 * 1024)	/* bottom 2 MB for user */

flash_info_t flash_info[CFG_MAX_FLASH_BANKS];

#define FLASH_WORD_SIZE unsigned char

/*---------------------------------------------------------------------*/

unsigned long flash_init (void)
{
	int i;
	unsigned long addr;
	flash_info_t *fli = &flash_info[0];

	fli->size = BANKSZ;
	fli->sector_count = CFG_MAX_FLASH_SECT;
	fli->flash_id = FLASH_MAN_AMD;

	addr = CFG_FLASH_BASE;
	for (i = 0; i < fli->sector_count; ++i) {
		fli->start[i] = addr;
		addr += SECTSZ;

		/* Protect all but 2 MByte user area */
		if (addr < (CFG_FLASH_BASE + USERFLASH))
			fli->protect[i] = 0;
		else
			fli->protect[i] = 1;
	}

	return (BANKSZ);
}

/*--------------------------------------------------------------------*/
void flash_print_info (flash_info_t * info)
{
	int i, k;
	unsigned long size;
	int erased;
	volatile unsigned char *flash;

	printf ("  Size: %ld KB in %d Sectors\n",
		info->size >> 10, info->sector_count);
	printf ("  Sector Start Addresses:");
	for (i = 0; i < info->sector_count; ++i) {

		/* Check if whole sector is erased */
		if (i != (info->sector_count - 1))
			size = info->start[i + 1] - info->start[i];
		else
			size = info->start[0] + info->size - info->start[i];
		erased = 1;
		flash = (volatile unsigned char *) info->start[i];
		for (k = 0; k < size; k++) {
			if (*flash++ != 0xff) {
				erased = 0;
				break;
			}
		}

		/* Print the info */
		if ((i % 5) == 0)
			printf ("\n   ");
		printf (" %08lX%s%s", info->start[i], erased ? " E" : "  ",
			info->protect[i] ? "RO " : "   ");
	}
	printf ("\n");
}

/*-------------------------------------------------------------------*/


int flash_erase (flash_info_t * info, int s_first, int s_last)
{
	volatile FLASH_WORD_SIZE *addr = (FLASH_WORD_SIZE *) (info->start[0]);
	volatile FLASH_WORD_SIZE *addr2;
	int prot, sect;
	int any = 0;
	unsigned oldpri;
	ulong start;

	/* Some sanity checking */
	if ((s_first < 0) || (s_first > s_last)) {
		printf ("- no sectors to erase\n");
		return 1;
	}

	prot = 0;
	for (sect = s_first; sect <= s_last; ++sect) {
		if (info->protect[sect]) {
			prot++;
		}
	}
	if (prot) {
		printf ("- Warning: %d protected sectors will not be erased!\n",
			prot);
	} else {
		printf ("\n");
	}

	/* NOTE: disabling interrupts on Nios can be very bad since it
	 * also disables the LO_LIMIT exception. It's better here to
	 * set the interrupt priority to 3 & restore it when we're done.
	 */
	oldpri = ipri (3);

	/* It's ok to erase multiple sectors provided we don't delay more
	 * than 50 usec between cmds ... at which point the erase time-out
	 * occurs. So don't go and put printf() calls in the loop ... it
	 * won't be very helpful ;-)
	 */
	for (sect = s_first; sect <= s_last; sect++) {
		if (info->protect[sect] == 0) {	/* not protected */
			addr2 = (FLASH_WORD_SIZE *) (info->start[sect]);
			*addr = 0xaa;
			*addr = 0x55;
			*addr = 0x80;
			*addr = 0xaa;
			*addr = 0x55;
			*addr2 = 0x30;
			any = 1;
		}
	}

	/* Now just wait for 0xff & provide some user feedback while
	 * we wait.
	 */
	if (any) {
		addr2 = (FLASH_WORD_SIZE *) (info->start[sect]);
		start = get_timer (0);
		while (*addr2 != 0xff) {
			udelay (1000 * 1000);
			putc ('.');
			if (get_timer (start) > CFG_FLASH_ERASE_TOUT) {
				printf ("timeout\n");
				return 1;
			}
		}
		printf ("\n");
	}

	/* Restore interrupt priority */
	ipri (oldpri);

	return 0;
}

/*-----------------------------------------------------------------------
 * Copy memory to flash, returns:
 * 0 - OK
 * 1 - write timeout
 * 2 - Flash not erased
 */

int write_buff (flash_info_t * info, uchar * src, ulong addr, ulong cnt)
{

	vu_char *cmd = (vu_char *) info->start[0];
	vu_char *dst = (vu_char *) addr;
	unsigned char b;
	unsigned oldpri;
	ulong start;

	while (cnt) {
		/* Check for sufficient erase */
		b = *src;
		if ((*dst & b) != b) {
			printf ("%02x : %02x\n", *dst, b);
			return (2);
		}

		/* Disable interrupts other than window underflow
		 * (interrupt priority 2)
		 */
		oldpri = ipri (3);
		*cmd = 0xaa;
		*cmd = 0x55;
		*cmd = 0xa0;
		*dst = b;

		/* Verify write */
		start = get_timer (0);
		while (*dst != b) {
			if (get_timer (start) > CFG_FLASH_WRITE_TOUT) {
				ipri (oldpri);
				return 1;
			}
		}
		dst++;
		src++;
		cnt--;
		ipri (oldpri);
	}

	return (0);
}
