/*
 * (C) Copyright 2003
 * Kyle Harris, Nexus Technologies, Inc. kharris@nexus-tech.net
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

#include <config.h>
#include <common.h>
#include <mmc.h>
#include <asm/errno.h>
#include <asm/arch/hardware.h>

#ifdef CONFIG_MMC

extern int
fat_register_read(int(*block_read)(int device, ulong blknr, ulong blkcnt, uchar *buffer));

/* 
 * FIXME needs to read cid and csd info to determine block size
 * and other parameters
 */
static uchar mmc_buf[MMC_BLOCK_SIZE];
static mmc_csd_t mmc_csd;
static int mmc_ready = 0;


static uchar * 
/****************************************************/
mmc_cmd(ushort cmd, ushort argh, ushort argl, ushort cmdat)
/****************************************************/
{
	static uchar resp[20];
	ulong status;
	int words, i;

	debug("mmc_cmd %x %x %x %x\n", cmd, argh, argl, cmdat);
	MMC_STRPCL = MMC_STRPCL_STOP_CLK;
	MMC_I_MASK = ~MMC_I_MASK_CLK_IS_OFF;
	while (!(MMC_I_REG & MMC_I_REG_CLK_IS_OFF));
	MMC_CMD    = cmd; 
	MMC_ARGH   = argh;
	MMC_ARGL   = argl;
	MMC_CMDAT  = cmdat;
	MMC_I_MASK = ~MMC_I_MASK_END_CMD_RES;
	MMC_STRPCL = MMC_STRPCL_START_CLK;
	while (!(MMC_I_REG & MMC_I_REG_END_CMD_RES));

	status = MMC_STAT;
	debug("MMC status %x\n", status);
	if (status & MMC_STAT_TIME_OUT_RESPONSE)
	{
		return 0;
	}

	switch (cmdat & 0x3)
	{
		case MMC_CMDAT_R1:
		case MMC_CMDAT_R3:
			words = 3; 
			break;

		case MMC_CMDAT_R2:
			words = 8; 
			break;

		default:
			return 0;
	}
	for (i = words-1; i >= 0; i--)
	{
		ulong res_fifo = MMC_RES;
		int offset = i << 1;

		resp[offset] = ((uchar *)&res_fifo)[0];
		resp[offset+1] = ((uchar *)&res_fifo)[1];
	}
#ifdef MMC_DEBUG
	for (i=0; i<words*2; i += 2)
	{
		printf("MMC resp[%d] = %02x\n", i, resp[i]);
		printf("MMC resp[%d] = %02x\n", i+1, resp[i+1]);
	}
#endif
	return resp;
}

int
/****************************************************/
mmc_block_read(uchar *dst, ulong src, ulong len)
/****************************************************/
{
	uchar *resp;
	ushort argh, argl;
	ulong status;

	if (len == 0)
	{
		return 0;
	}

	debug("mmc_block_rd dst %lx src %lx len %d\n", (ulong)dst, src, len);

	argh = len >> 16;
	argl = len & 0xffff;

	/* set block len */
	resp = mmc_cmd(MMC_CMD_SET_BLOCKLEN, argh, argl, MMC_CMDAT_R1);

	/* send read command */
	argh = src >> 16;
	argl = src & 0xffff;
	MMC_STRPCL = MMC_STRPCL_STOP_CLK;
	MMC_RDTO = 0xffff;
	MMC_NOB = 1;
	MMC_BLKLEN = len;
	resp = mmc_cmd(MMC_CMD_READ_BLOCK, argh, argl, 
			MMC_CMDAT_R1|MMC_CMDAT_READ|MMC_CMDAT_BLOCK|MMC_CMDAT_DATA_EN);

	
	MMC_I_MASK = ~MMC_I_MASK_RXFIFO_RD_REQ;
	while (len)
	{
		if (MMC_I_REG & MMC_I_REG_RXFIFO_RD_REQ)
		{
			*dst++ = MMC_RXFIFO;
			len--;
		}
		status = MMC_STAT;
		if (status & MMC_STAT_ERRORS)
		{
			printf("MMC_STAT error %lx\n", status);
			return -1;
		}
	}
	MMC_I_MASK = ~MMC_I_MASK_DATA_TRAN_DONE;
	while (!(MMC_I_REG & MMC_I_REG_DATA_TRAN_DONE));
	status = MMC_STAT;
	if (status & MMC_STAT_ERRORS)
	{
		printf("MMC_STAT error %lx\n", status);
		return -1;
	}
	return 0;
}

int
/****************************************************/
mmc_block_write(ulong dst, uchar *src, int len)
/****************************************************/
{
	uchar *resp;
	ushort argh, argl;
	ulong status;

	if (len == 0)
	{
		return 0;
	}

	debug("mmc_block_wr dst %lx src %lx len %d\n", dst, (ulong)src, len);

	argh = len >> 16;
	argl = len & 0xffff;

	/* set block len */
	resp = mmc_cmd(MMC_CMD_SET_BLOCKLEN, argh, argl, MMC_CMDAT_R1);

	/* send write command */
	argh = dst >> 16;
	argl = dst & 0xffff;
	MMC_STRPCL = MMC_STRPCL_STOP_CLK;
	MMC_NOB = 1;
	MMC_BLKLEN = len;
	resp = mmc_cmd(MMC_CMD_WRITE_BLOCK, argh, argl, 
			MMC_CMDAT_R1|MMC_CMDAT_WRITE|MMC_CMDAT_BLOCK|MMC_CMDAT_DATA_EN);
	
	MMC_I_MASK = ~MMC_I_MASK_TXFIFO_WR_REQ;
	while (len)
	{
		if (MMC_I_REG & MMC_I_REG_TXFIFO_WR_REQ)
		{
			int i, bytes = min(32,len);

			for (i=0; i<bytes; i++)
			{
				MMC_TXFIFO = *src++;
			}
			if (bytes < 32)
			{
				MMC_PRTBUF = MMC_PRTBUF_BUF_PART_FULL;
			}
			len -= bytes;
		}
		status = MMC_STAT;
		if (status & MMC_STAT_ERRORS)
		{
			printf("MMC_STAT error %lx\n", status);
			return -1;
		}
	}
	MMC_I_MASK = ~MMC_I_MASK_DATA_TRAN_DONE;
	while (!(MMC_I_REG & MMC_I_REG_DATA_TRAN_DONE));
	MMC_I_MASK = ~MMC_I_MASK_PRG_DONE;
	while (!(MMC_I_REG & MMC_I_REG_PRG_DONE));
	status = MMC_STAT;
	if (status & MMC_STAT_ERRORS)
	{
		printf("MMC_STAT error %lx\n", status);
		return -1;
	}
	return 0;
}


int
/****************************************************/
mmc_read(ulong src, uchar *dst, int size)
/****************************************************/
{
	ulong end, part_start, part_end, part_len, aligned_start, aligned_end;
	ulong mmc_block_size, mmc_block_address;

	if (size == 0)
	{
		return 0;
	}

	if (!mmc_ready)
	{
		printf("Please initial the MMC first\n");
		return -1;
	}

	mmc_block_size = MMC_BLOCK_SIZE;
	mmc_block_address = ~(mmc_block_size - 1);

	src -= CFG_MMC_BASE;
	end = src + size;
	part_start = ~mmc_block_address & src;
	part_end = ~mmc_block_address & end;
	aligned_start = mmc_block_address & src;
	aligned_end = mmc_block_address & end;

	/* all block aligned accesses */
	debug("src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
	src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
	if (part_start)
	{
		part_len = mmc_block_size - part_start;
		debug("ps src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
		src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
		if ((mmc_block_read(mmc_buf, aligned_start, mmc_block_size)) < 0)
		{
			return -1;
		}
		memcpy(dst, mmc_buf+part_start, part_len);
		dst += part_len;
		src += part_len;
	}
	debug("src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
	src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
	for (; src < aligned_end; src += mmc_block_size, dst += mmc_block_size)
	{
		debug("al src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
		src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
		if ((mmc_block_read((uchar *)(dst), src, mmc_block_size)) < 0)
		{
			return -1;
		}
	}
	debug("src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
	src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
	if (part_end && src < end)
	{
		debug("pe src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
		src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
		if ((mmc_block_read(mmc_buf, aligned_end, mmc_block_size)) < 0)
		{
			return -1;
		}
		memcpy(dst, mmc_buf, part_end);
	}
	return 0;
}

int
/****************************************************/
mmc_write(uchar *src, ulong dst, int size)
/****************************************************/
{
	ulong end, part_start, part_end, part_len, aligned_start, aligned_end;
	ulong mmc_block_size, mmc_block_address;

	if (size == 0)
	{
		return 0;
	}

	if (!mmc_ready)
	{
		printf("Please initial the MMC first\n");
		return -1;
	}

	mmc_block_size = MMC_BLOCK_SIZE;
	mmc_block_address = ~(mmc_block_size - 1);

	dst -= CFG_MMC_BASE;
	end = dst + size;
	part_start = ~mmc_block_address & dst;
	part_end = ~mmc_block_address & end;
	aligned_start = mmc_block_address & dst;
	aligned_end = mmc_block_address & end;

	/* all block aligned accesses */
	debug("src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
	src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
	if (part_start)
	{
		part_len = mmc_block_size - part_start;
		debug("ps src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
		(ulong)src, dst, end, part_start, part_end, aligned_start, aligned_end);
		if ((mmc_block_read(mmc_buf, aligned_start, mmc_block_size)) < 0)
		{
			return -1;
		}
		memcpy(mmc_buf+part_start, src, part_len);
		if ((mmc_block_write(aligned_start, mmc_buf, mmc_block_size)) < 0)
		{
			return -1;
		}
		dst += part_len;
		src += part_len;
	}
	debug("src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
	src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
	for (; dst < aligned_end; src += mmc_block_size, dst += mmc_block_size)
	{
		debug("al src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
		src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
		if ((mmc_block_write(dst, (uchar *)src, mmc_block_size)) < 0)
		{
			return -1;
		}
	}
	debug("src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
	src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
	if (part_end && dst < end)
	{
		debug("pe src %lx dst %lx end %lx pstart %lx pend %lx astart %lx aend %lx\n",
		src, (ulong)dst, end, part_start, part_end, aligned_start, aligned_end);
		if ((mmc_block_read(mmc_buf, aligned_end, mmc_block_size)) < 0)
		{
			return -1;
		}
		memcpy(mmc_buf, src, part_end);
		if ((mmc_block_write(aligned_end, mmc_buf, mmc_block_size)) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int 
/****************************************************/
mmc_bread(int dev_num, ulong blknr, ulong blkcnt, uchar *dst)
/****************************************************/
{
	int mmc_block_size = MMC_BLOCK_SIZE;
	ulong src = blknr * mmc_block_size + CFG_MMC_BASE;

	mmc_read(src, (uchar *)dst, blkcnt*mmc_block_size);
	return blkcnt;
}

int
/****************************************************/
mmc_init(int verbose)
/****************************************************/
{
 	int retries, rc = -ENODEV;
	uchar *resp;

#ifdef CONFIG_LUBBOCK
	set_GPIO_mode( GPIO6_MMCCLK_MD );
	set_GPIO_mode( GPIO8_MMCCS0_MD );
#endif
	CKEN |= CKEN12_MMC; /* enable MMC unit clock */

	mmc_csd.c_size = 0;

	MMC_CLKRT  = MMC_CLKRT_0_3125MHZ;
	MMC_RESTO  = MMC_RES_TO_MAX; 
	MMC_SPI    = MMC_SPI_DISABLE;

	/* reset */
	retries = 10;
	resp = mmc_cmd(0, 0, 0, 0);
	resp = mmc_cmd(1, 0x00ff, 0xc000, MMC_CMDAT_INIT|MMC_CMDAT_BUSY|MMC_CMDAT_R3);
	while (retries-- && resp && !(resp[4] & 0x80))
	{
		debug("resp %x %x\n", resp[0], resp[1]);
		udelay(50);
		resp = mmc_cmd(1, 0x00ff, 0xff00, MMC_CMDAT_BUSY|MMC_CMDAT_R3);
	}

	/* try to get card id */
	resp = mmc_cmd(2, 0, 0, MMC_CMDAT_R2);
	if (resp)
	{
		/* TODO configure mmc driver depending on card attributes */
		mmc_cid_t *cid = (mmc_cid_t *)resp;
		if (verbose)
		{
			printf("MMC found. Card desciption is:\n");
			printf("Manufacturer ID = %02x%02x%02x\n", 
							cid->id[0], cid->id[1], cid->id[2]);
			printf("HW/FW Revision = %x %x\n",cid->hwrev, cid->fwrev);
			cid->hwrev = cid->fwrev = 0;	/* null terminate string */
			printf("Product Name = %s\n",cid->name);
			printf("Serial Number = %02x%02x%02x\n", 
							cid->sn[0], cid->sn[1], cid->sn[2]);
			printf("Month = %d\n",cid->month);
			printf("Year = %d\n",1997 + cid->year);
		}

		/* MMC exists, get CSD too */
		resp = mmc_cmd(MMC_CMD_SET_RCA, MMC_DEFAULT_RCA, 0, MMC_CMDAT_R1);
		resp = mmc_cmd(MMC_CMD_SEND_CSD, MMC_DEFAULT_RCA, 0, MMC_CMDAT_R2);
		if (resp)
		{
			mmc_csd_t *csd = (mmc_csd_t *)resp;
			memcpy(&mmc_csd, csd, sizeof(csd));
			rc = 0;
			mmc_ready = 1;
			/* FIXME add verbose printout for csd */
		}
	}

	MMC_CLKRT = 0;	/* 20 MHz */
	resp = mmc_cmd(7, MMC_DEFAULT_RCA, 0, MMC_CMDAT_R1);

	fat_register_read(mmc_bread);

	return rc;
}

int
mmc_ident(block_dev_desc_t *dev)
{
	return 0;
}

int
mmc2info(ulong addr)
{
	/* FIXME hard codes to 32 MB device */
	if (addr >= CFG_MMC_BASE && addr < CFG_MMC_BASE + 0x02000000)
	{
		return 1;
	}
	return 0;
}

#endif
