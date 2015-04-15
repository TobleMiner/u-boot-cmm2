/*
 * Copyright (C) 2015, Bin Meng <bmeng.cn@gmail.com>
 *
 * Intel Platform Controller Hub EG20T (codename Topcliff) GMAC Driver
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <pci.h>
#include <malloc.h>
#include <miiphy.h>
#include "pch_gbe.h"

#if !defined(CONFIG_PHYLIB)
# error "PCH Gigabit Ethernet driver requires PHYLIB - missing CONFIG_PHYLIB"
#endif

static struct pci_device_id supported[] = {
	{ PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_TCF_GBE },
	{ }
};

static void pch_gbe_mac_read(struct pch_gbe_regs *mac_regs, u8 *addr)
{
	u32 macid_hi, macid_lo;

	macid_hi = readl(&mac_regs->mac_adr[0].high);
	macid_lo = readl(&mac_regs->mac_adr[0].low) & 0xffff;
	debug("pch_gbe: macid_hi %#x macid_lo %#x\n", macid_hi, macid_lo);

	addr[0] = (u8)(macid_hi & 0xff);
	addr[1] = (u8)((macid_hi >> 8) & 0xff);
	addr[2] = (u8)((macid_hi >> 16) & 0xff);
	addr[3] = (u8)((macid_hi >> 24) & 0xff);
	addr[4] = (u8)(macid_lo & 0xff);
	addr[5] = (u8)((macid_lo >> 8) & 0xff);
}

static int pch_gbe_mac_write(struct pch_gbe_regs *mac_regs, u8 *addr)
{
	u32 macid_hi, macid_lo;
	ulong start;

	macid_hi = addr[0] + (addr[1] << 8) + (addr[2] << 16) + (addr[3] << 24);
	macid_lo = addr[4] + (addr[5] << 8);

	writel(macid_hi, &mac_regs->mac_adr[0].high);
	writel(macid_lo, &mac_regs->mac_adr[0].low);
	writel(0xfffe, &mac_regs->addr_mask);

	start = get_timer(0);
	while (get_timer(start) < PCH_GBE_TIMEOUT) {
		if (!(readl(&mac_regs->addr_mask) & PCH_GBE_BUSY))
			return 0;

		udelay(10);
	}

	return -ETIME;
}

static int pch_gbe_reset(struct eth_device *dev)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct pch_gbe_regs *mac_regs = priv->mac_regs;
	ulong start;

	priv->rx_idx = 0;
	priv->tx_idx = 0;

	writel(PCH_GBE_ALL_RST, &mac_regs->reset);

	/*
	 * Configure the MAC to RGMII mode after reset
	 *
	 * For some unknown reason, we must do the configuration here right
	 * after resetting the whole MAC, otherwise the reset bit in the RESET
	 * register will never be cleared by the hardware. And there is another
	 * way of having the same magic, that is to configure the MODE register
	 * to have the MAC work in MII/GMII mode, which is how current Linux
	 * pch_gbe driver does. Since anyway we need program the MAC to RGMII
	 * mode in the driver, we just do it here.
	 *
	 * Note: this behavior is not documented in the hardware manual.
	 */
	writel(PCH_GBE_RGMII_MODE_RGMII | PCH_GBE_CHIP_TYPE_INTERNAL,
	       &mac_regs->rgmii_ctrl);

	start = get_timer(0);
	while (get_timer(start) < PCH_GBE_TIMEOUT) {
		if (!(readl(&mac_regs->reset) & PCH_GBE_ALL_RST)) {
			/*
			 * Soft reset clears hardware MAC address registers,
			 * so we have to reload MAC address here in order to
			 * make linux pch_gbe driver happy.
			 */
			return pch_gbe_mac_write(mac_regs, dev->enetaddr);
		}

		udelay(10);
	}

	debug("pch_gbe: reset timeout\n");
	return -ETIME;
}

static void pch_gbe_rx_descs_init(struct eth_device *dev)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct pch_gbe_regs *mac_regs = priv->mac_regs;
	struct pch_gbe_rx_desc *rx_desc = &priv->rx_desc[0];
	int i;

	memset(rx_desc, 0, sizeof(struct pch_gbe_rx_desc) * PCH_GBE_DESC_NUM);
	for (i = 0; i < PCH_GBE_DESC_NUM; i++)
		rx_desc->buffer_addr = pci_phys_to_mem(priv->bdf,
			(u32)(priv->rx_buff[i]));

	writel(pci_phys_to_mem(priv->bdf, (u32)rx_desc),
	       &mac_regs->rx_dsc_base);
	writel(sizeof(struct pch_gbe_rx_desc) * (PCH_GBE_DESC_NUM - 1),
	       &mac_regs->rx_dsc_size);

	writel(pci_phys_to_mem(priv->bdf, (u32)(rx_desc + 1)),
	       &mac_regs->rx_dsc_sw_p);
}

static void pch_gbe_tx_descs_init(struct eth_device *dev)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct pch_gbe_regs *mac_regs = priv->mac_regs;
	struct pch_gbe_tx_desc *tx_desc = &priv->tx_desc[0];

	memset(tx_desc, 0, sizeof(struct pch_gbe_tx_desc) * PCH_GBE_DESC_NUM);

	writel(pci_phys_to_mem(priv->bdf, (u32)tx_desc),
	       &mac_regs->tx_dsc_base);
	writel(sizeof(struct pch_gbe_tx_desc) * (PCH_GBE_DESC_NUM - 1),
	       &mac_regs->tx_dsc_size);
	writel(pci_phys_to_mem(priv->bdf, (u32)(tx_desc + 1)),
	       &mac_regs->tx_dsc_sw_p);
}

static void pch_gbe_adjust_link(struct pch_gbe_regs *mac_regs,
				struct phy_device *phydev)
{
	if (!phydev->link) {
		printf("%s: No link.\n", phydev->dev->name);
		return;
	}

	clrbits_le32(&mac_regs->rgmii_ctrl,
		     PCH_GBE_RGMII_RATE_2_5M | PCH_GBE_CRS_SEL);
	clrbits_le32(&mac_regs->mode,
		     PCH_GBE_MODE_GMII_ETHER | PCH_GBE_MODE_FULL_DUPLEX);

	switch (phydev->speed) {
	case 1000:
		setbits_le32(&mac_regs->rgmii_ctrl, PCH_GBE_RGMII_RATE_125M);
		setbits_le32(&mac_regs->mode, PCH_GBE_MODE_GMII_ETHER);
		break;
	case 100:
		setbits_le32(&mac_regs->rgmii_ctrl, PCH_GBE_RGMII_RATE_25M);
		setbits_le32(&mac_regs->mode, PCH_GBE_MODE_MII_ETHER);
		break;
	case 10:
		setbits_le32(&mac_regs->rgmii_ctrl, PCH_GBE_RGMII_RATE_2_5M);
		setbits_le32(&mac_regs->mode, PCH_GBE_MODE_MII_ETHER);
		break;
	}

	if (phydev->duplex) {
		setbits_le32(&mac_regs->rgmii_ctrl, PCH_GBE_CRS_SEL);
		setbits_le32(&mac_regs->mode, PCH_GBE_MODE_FULL_DUPLEX);
	}

	printf("Speed: %d, %s duplex\n", phydev->speed,
	       (phydev->duplex) ? "full" : "half");

	return;
}

static int pch_gbe_init(struct eth_device *dev, bd_t *bis)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct pch_gbe_regs *mac_regs = priv->mac_regs;

	if (pch_gbe_reset(dev))
		return -1;

	pch_gbe_rx_descs_init(dev);
	pch_gbe_tx_descs_init(dev);

	/* Enable frame bursting */
	writel(PCH_GBE_MODE_FR_BST, &mac_regs->mode);
	/* Disable TCP/IP accelerator */
	writel(PCH_GBE_RX_TCPIPACC_OFF, &mac_regs->tcpip_acc);
	/* Disable RX flow control */
	writel(0, &mac_regs->rx_fctrl);
	/* Configure RX/TX mode */
	writel(PCH_GBE_RH_ALM_EMP_16 | PCH_GBE_RH_ALM_FULL_16 |
	       PCH_GBE_RH_RD_TRG_32, &mac_regs->rx_mode);
	writel(PCH_GBE_TM_TH_TX_STRT_32 | PCH_GBE_TM_TH_ALM_EMP_16 |
	       PCH_GBE_TM_TH_ALM_FULL_32 | PCH_GBE_TM_ST_AND_FD |
	       PCH_GBE_TM_SHORT_PKT, &mac_regs->tx_mode);

	/* Start up the PHY */
	if (phy_startup(priv->phydev)) {
		printf("Could not initialize PHY %s\n",
		       priv->phydev->dev->name);
		return -1;
	}

	pch_gbe_adjust_link(mac_regs, priv->phydev);

	if (!priv->phydev->link)
		return -1;

	/* Enable TX & RX */
	writel(PCH_GBE_RX_DMA_EN | PCH_GBE_TX_DMA_EN, &mac_regs->dma_ctrl);
	writel(PCH_GBE_MRE_MAC_RX_EN, &mac_regs->mac_rx_en);

	return 0;
}

static void pch_gbe_halt(struct eth_device *dev)
{
	struct pch_gbe_priv *priv = dev->priv;

	pch_gbe_reset(dev);

	phy_shutdown(priv->phydev);
}

static int pch_gbe_send(struct eth_device *dev, void *packet, int length)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct pch_gbe_regs *mac_regs = priv->mac_regs;
	struct pch_gbe_tx_desc *tx_head, *tx_desc;
	u16 frame_ctrl = 0;
	u32 int_st;
	ulong start;

	tx_head = &priv->tx_desc[0];
	tx_desc = &priv->tx_desc[priv->tx_idx];

	if (length < 64)
		frame_ctrl |= PCH_GBE_TXD_CTRL_APAD;

	tx_desc->buffer_addr = pci_phys_to_mem(priv->bdf, (u32)packet);
	tx_desc->length = length;
	tx_desc->tx_words_eob = length + 3;
	tx_desc->tx_frame_ctrl = frame_ctrl;
	tx_desc->dma_status = 0;
	tx_desc->gbec_status = 0;

	/* Test the wrap-around condition */
	if (++priv->tx_idx >= PCH_GBE_DESC_NUM)
		priv->tx_idx = 0;

	writel(pci_phys_to_mem(priv->bdf, (u32)(tx_head + priv->tx_idx)),
	       &mac_regs->tx_dsc_sw_p);

	start = get_timer(0);
	while (get_timer(start) < PCH_GBE_TIMEOUT) {
		int_st = readl(&mac_regs->int_st);
		if (int_st & PCH_GBE_INT_TX_CMPLT)
			return 0;

		udelay(10);
	}

	debug("pch_gbe: sent failed\n");
	return -ETIME;
}

static int pch_gbe_recv(struct eth_device *dev)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct pch_gbe_regs *mac_regs = priv->mac_regs;
	struct pch_gbe_rx_desc *rx_head, *rx_desc;
	u32 hw_desc, buffer_addr, length;
	int rx_swp;

	rx_head = &priv->rx_desc[0];
	rx_desc = &priv->rx_desc[priv->rx_idx];

	readl(&mac_regs->int_st);
	hw_desc = readl(&mac_regs->rx_dsc_hw_p_hld);

	/* Just return if not receiving any packet */
	if ((u32)rx_desc == hw_desc)
		return 0;

	buffer_addr = pci_mem_to_phys(priv->bdf, rx_desc->buffer_addr);
	length = rx_desc->rx_words_eob - 3 - ETH_FCS_LEN;
	net_process_received_packet((uchar *)buffer_addr, length);

	/* Test the wrap-around condition */
	if (++priv->rx_idx >= PCH_GBE_DESC_NUM)
		priv->rx_idx = 0;
	rx_swp = priv->rx_idx;
	if (++rx_swp >= PCH_GBE_DESC_NUM)
		rx_swp = 0;

	writel(pci_phys_to_mem(priv->bdf, (u32)(rx_head + rx_swp)),
	       &mac_regs->rx_dsc_sw_p);

	return length;
}

static int pch_gbe_mdio_ready(struct pch_gbe_regs *mac_regs)
{
	ulong start = get_timer(0);

	while (get_timer(start) < PCH_GBE_TIMEOUT) {
		if (readl(&mac_regs->miim) & PCH_GBE_MIIM_OPER_READY)
			return 0;

		udelay(10);
	}

	return -ETIME;
}

static int pch_gbe_mdio_read(struct mii_dev *bus, int addr, int devad, int reg)
{
	struct pch_gbe_regs *mac_regs = bus->priv;
	u32 miim;

	if (pch_gbe_mdio_ready(mac_regs))
		return -ETIME;

	miim = (addr << PCH_GBE_MIIM_PHY_ADDR_SHIFT) |
	       (reg << PCH_GBE_MIIM_REG_ADDR_SHIFT) |
	       PCH_GBE_MIIM_OPER_READ;
	writel(miim, &mac_regs->miim);

	if (pch_gbe_mdio_ready(mac_regs))
		return -ETIME;

	return readl(&mac_regs->miim) & 0xffff;
}

static int pch_gbe_mdio_write(struct mii_dev *bus, int addr, int devad,
			      int reg, u16 val)
{
	struct pch_gbe_regs *mac_regs = bus->priv;
	u32 miim;

	if (pch_gbe_mdio_ready(mac_regs))
		return -ETIME;

	miim = (addr << PCH_GBE_MIIM_PHY_ADDR_SHIFT) |
	       (reg << PCH_GBE_MIIM_REG_ADDR_SHIFT) |
	       PCH_GBE_MIIM_OPER_WRITE | val;
	writel(miim, &mac_regs->miim);

	if (pch_gbe_mdio_ready(mac_regs))
		return -ETIME;
	else
		return 0;
}

static int pch_gbe_mdio_init(char *name, struct pch_gbe_regs *mac_regs)
{
	struct mii_dev *bus;

	bus = mdio_alloc();
	if (!bus) {
		debug("pch_gbe: failed to allocate MDIO bus\n");
		return -ENOMEM;
	}

	bus->read = pch_gbe_mdio_read;
	bus->write = pch_gbe_mdio_write;
	sprintf(bus->name, name);

	bus->priv = (void *)mac_regs;

	return mdio_register(bus);
}

static int pch_gbe_phy_init(struct eth_device *dev)
{
	struct pch_gbe_priv *priv = dev->priv;
	struct phy_device *phydev;
	int mask = 0xffffffff;

	phydev = phy_find_by_mask(priv->bus, mask, priv->interface);
	if (!phydev) {
		printf("pch_gbe: cannot find the phy\n");
		return -1;
	}

	phy_connect_dev(phydev, dev);

	phydev->supported &= PHY_GBIT_FEATURES;
	phydev->advertising = phydev->supported;

	priv->phydev = phydev;
	phy_config(phydev);

	return 1;
}

int pch_gbe_register(bd_t *bis)
{
	struct eth_device *dev;
	struct pch_gbe_priv *priv;
	pci_dev_t devno;
	u32 iobase;

	devno = pci_find_devices(supported, 0);
	if (devno == -1)
		return -ENODEV;

	dev = (struct eth_device *)malloc(sizeof(*dev));
	if (!dev)
		return -ENOMEM;
	memset(dev, 0, sizeof(*dev));

	/*
	 * The priv structure contains the descriptors and frame buffers which
	 * need a strict buswidth alignment (64 bytes)
	 */
	priv = (struct pch_gbe_priv *)memalign(PCH_GBE_ALIGN_SIZE,
					       sizeof(*priv));
	if (!priv) {
		free(dev);
		return -ENOMEM;
	}
	memset(priv, 0, sizeof(*priv));

	dev->priv = priv;
	priv->dev = dev;
	priv->bdf = devno;

	pci_read_config_dword(devno, PCI_BASE_ADDRESS_1, &iobase);
	iobase &= PCI_BASE_ADDRESS_MEM_MASK;
	iobase = pci_mem_to_phys(devno, iobase);

	dev->iobase = iobase;
	priv->mac_regs = (struct pch_gbe_regs *)iobase;

	sprintf(dev->name, "pch_gbe");

	/* Read MAC address from SROM and initialize dev->enetaddr with it */
	pch_gbe_mac_read(priv->mac_regs, dev->enetaddr);

	dev->init = pch_gbe_init;
	dev->halt = pch_gbe_halt;
	dev->send = pch_gbe_send;
	dev->recv = pch_gbe_recv;

	eth_register(dev);

	priv->interface = PHY_INTERFACE_MODE_RGMII;
	pch_gbe_mdio_init(dev->name, priv->mac_regs);
	priv->bus = miiphy_get_dev_by_name(dev->name);

	return pch_gbe_phy_init(dev);
}
