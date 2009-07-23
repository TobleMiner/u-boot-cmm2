/*
 * SMSC LAN9[12]1[567] Network driver
 *
 * (c) 2007 Pengutronix, Sascha Hauer <s.hauer@pengutronix.de>
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
#include <command.h>
#include <malloc.h>
#include <net.h>
#include <miiphy.h>

#include "smc911x.h"

u32 pkt_data_pull(struct eth_device *dev, u32 addr) \
	__attribute__ ((weak, alias ("smc911x_reg_read")));
void pkt_data_push(struct eth_device *dev, u32 addr, u32 val) \
	__attribute__ ((weak, alias ("smc911x_reg_write")));

#define mdelay(n)       udelay((n)*1000)

static void smx911x_handle_mac_address(struct eth_device *dev)
{
	unsigned long addrh, addrl;
	uchar *m = dev->enetaddr;

	addrl = m[0] | (m[1] << 8) | (m[2] << 16) | (m[3] << 24);
	addrh = m[4] | (m[5] << 8);
	smc911x_set_mac_csr(dev, ADDRL, addrl);
	smc911x_set_mac_csr(dev, ADDRH, addrh);

	printf(DRIVERNAME ": MAC %pM\n", m);
}

static int smc911x_miiphy_read(struct eth_device *dev,
				u8 phy, u8 reg, u16 *val)
{
	while (smc911x_get_mac_csr(dev, MII_ACC) & MII_ACC_MII_BUSY)
		;

	smc911x_set_mac_csr(dev, MII_ACC, phy << 11 | reg << 6 |
				MII_ACC_MII_BUSY);

	while (smc911x_get_mac_csr(dev, MII_ACC) & MII_ACC_MII_BUSY)
		;

	*val = smc911x_get_mac_csr(dev, MII_DATA);

	return 0;
}

static int smc911x_miiphy_write(struct eth_device *dev,
				u8 phy, u8 reg, u16  val)
{
	while (smc911x_get_mac_csr(dev, MII_ACC) & MII_ACC_MII_BUSY)
		;

	smc911x_set_mac_csr(dev, MII_DATA, val);
	smc911x_set_mac_csr(dev, MII_ACC,
		phy << 11 | reg << 6 | MII_ACC_MII_BUSY | MII_ACC_MII_WRITE);

	while (smc911x_get_mac_csr(dev, MII_ACC) & MII_ACC_MII_BUSY)
		;
	return 0;
}

static int smc911x_phy_reset(struct eth_device *dev)
{
	u32 reg;

	reg = smc911x_reg_read(dev, PMT_CTRL);
	reg &= ~0xfffff030;
	reg |= PMT_CTRL_PHY_RST;
	smc911x_reg_write(dev, PMT_CTRL, reg);

	mdelay(100);

	return 0;
}

static void smc911x_phy_configure(struct eth_device *dev)
{
	int timeout;
	u16 status;

	smc911x_phy_reset(dev);

	smc911x_miiphy_write(dev, 1, PHY_BMCR, PHY_BMCR_RESET);
	mdelay(1);
	smc911x_miiphy_write(dev, 1, PHY_ANAR, 0x01e1);
	smc911x_miiphy_write(dev, 1, PHY_BMCR, PHY_BMCR_AUTON |
				PHY_BMCR_RST_NEG);

	timeout = 5000;
	do {
		mdelay(1);
		if ((timeout--) == 0)
			goto err_out;

		if (smc911x_miiphy_read(dev, 1, PHY_BMSR, &status) != 0)
			goto err_out;
	} while (!(status & PHY_BMSR_LS));

	printf(DRIVERNAME ": phy initialized\n");

	return;

err_out:
	printf(DRIVERNAME ": autonegotiation timed out\n");
}

static void smc911x_enable(struct eth_device *dev)
{
	/* Enable TX */
	smc911x_reg_write(dev, HW_CFG, 8 << 16 | HW_CFG_SF);

	smc911x_reg_write(dev, GPT_CFG, GPT_CFG_TIMER_EN | 10000);

	smc911x_reg_write(dev, TX_CFG, TX_CFG_TX_ON);

	/* no padding to start of packets */
	smc911x_reg_write(dev, RX_CFG, 0);

	smc911x_set_mac_csr(dev, MAC_CR, MAC_CR_TXEN | MAC_CR_RXEN |
				MAC_CR_HBDIS);

}

static int smc911x_init(struct eth_device *dev, bd_t * bd)
{
	printf(DRIVERNAME ": initializing\n");

	if (smc911x_detect_chip(dev))
		goto err_out;

	smc911x_reset(dev);

	/* Configure the PHY, initialize the link state */
	smc911x_phy_configure(dev);

	smx911x_handle_mac_address(dev);

	/* Turn on Tx + Rx */
	smc911x_enable(dev);

	return 0;

err_out:
	return -1;
}

static int smc911x_send(struct eth_device *dev,
			volatile void *packet, int length)
{
	u32 *data = (u32*)packet;
	u32 tmplen;
	u32 status;

	smc911x_reg_write(dev, TX_DATA_FIFO, TX_CMD_A_INT_FIRST_SEG |
				TX_CMD_A_INT_LAST_SEG | length);
	smc911x_reg_write(dev, TX_DATA_FIFO, length);

	tmplen = (length + 3) / 4;

	while (tmplen--)
		pkt_data_push(dev, TX_DATA_FIFO, *data++);

	/* wait for transmission */
	while (!((smc911x_reg_read(dev, TX_FIFO_INF) &
					TX_FIFO_INF_TSUSED) >> 16));

	/* get status. Ignore 'no carrier' error, it has no meaning for
	 * full duplex operation
	 */
	status = smc911x_reg_read(dev, TX_STATUS_FIFO) &
			(TX_STS_LOC | TX_STS_LATE_COLL | TX_STS_MANY_COLL |
			TX_STS_MANY_DEFER | TX_STS_UNDERRUN);

	if (!status)
		return 0;

	printf(DRIVERNAME ": failed to send packet: %s%s%s%s%s\n",
		status & TX_STS_LOC ? "TX_STS_LOC " : "",
		status & TX_STS_LATE_COLL ? "TX_STS_LATE_COLL " : "",
		status & TX_STS_MANY_COLL ? "TX_STS_MANY_COLL " : "",
		status & TX_STS_MANY_DEFER ? "TX_STS_MANY_DEFER " : "",
		status & TX_STS_UNDERRUN ? "TX_STS_UNDERRUN" : "");

	return -1;
}

static void smc911x_halt(struct eth_device *dev)
{
	smc911x_reset(dev);
}

static int smc911x_rx(struct eth_device *dev)
{
	u32 *data = (u32 *)NetRxPackets[0];
	u32 pktlen, tmplen;
	u32 status;

	if ((smc911x_reg_read(dev, RX_FIFO_INF) & RX_FIFO_INF_RXSUSED) >> 16) {
		status = smc911x_reg_read(dev, RX_STATUS_FIFO);
		pktlen = (status & RX_STS_PKT_LEN) >> 16;

		smc911x_reg_write(dev, RX_CFG, 0);

		tmplen = (pktlen + 2+ 3) / 4;
		while (tmplen--)
			*data++ = pkt_data_pull(dev, RX_DATA_FIFO);

		if (status & RX_STS_ES)
			printf(DRIVERNAME
				": dropped bad packet. Status: 0x%08x\n",
				status);
		else
			NetReceive(NetRxPackets[0], pktlen);
	}

	return 0;
}

int smc911x_initialize(u8 dev_num, int base_addr)
{
	unsigned long addrl, addrh;
	struct eth_device *dev;

	dev = malloc(sizeof(*dev));
	if (!dev) {
		free(dev);
		return 0;
	}
	memset(dev, 0, sizeof(*dev));

	dev->iobase = base_addr;

	addrh = smc911x_get_mac_csr(dev, ADDRH);
	addrl = smc911x_get_mac_csr(dev, ADDRL);
	dev->enetaddr[0] = addrl;
	dev->enetaddr[1] = addrl >>  8;
	dev->enetaddr[2] = addrl >> 16;
	dev->enetaddr[3] = addrl >> 24;
	dev->enetaddr[4] = addrh;
	dev->enetaddr[5] = addrh >> 8;

	dev->init = smc911x_init;
	dev->halt = smc911x_halt;
	dev->send = smc911x_send;
	dev->recv = smc911x_rx;
	sprintf(dev->name, "%s-%hu", DRIVERNAME, dev_num);

	eth_register(dev);
	return 0;
}
