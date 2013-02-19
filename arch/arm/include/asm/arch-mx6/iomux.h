/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef __ASM_ARCH_IOMUX_H__
#define __ASM_ARCH_IOMUX_H__

#define MX6_IOMUXC_GPR4		0x020e0010
#define MX6_IOMUXC_GPR6		0x020e0018
#define MX6_IOMUXC_GPR7		0x020e001c

/*
 * IOMUXC_GPR13 bit fields
 */
#define IOMUXC_GPR13_SDMA_STOP_REQ	(1<<30)
#define IOMUXC_GPR13_CAN2_STOP_REQ	(1<<29)
#define IOMUXC_GPR13_CAN1_STOP_REQ	(1<<28)
#define IOMUXC_GPR13_ENET_STOP_REQ	(1<<27)
#define IOMUXC_GPR13_SATA_PHY_8_MASK	(7<<24)
#define IOMUXC_GPR13_SATA_PHY_7_MASK	(0x1f<<19)
#define IOMUXC_GPR13_SATA_PHY_6_SHIFT	16
#define IOMUXC_GPR13_SATA_PHY_6_MASK	(7<<IOMUXC_GPR13_SATA_PHY_6_SHIFT)
#define IOMUXC_GPR13_SATA_SPEED_MASK	(1<<15)
#define IOMUXC_GPR13_SATA_PHY_5_MASK	(1<<14)
#define IOMUXC_GPR13_SATA_PHY_4_MASK	(7<<11)
#define IOMUXC_GPR13_SATA_PHY_3_MASK	(0x1f<<7)
#define IOMUXC_GPR13_SATA_PHY_2_MASK	(0x1f<<2)
#define IOMUXC_GPR13_SATA_PHY_1_MASK	(3<<0)

#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_0P5DB	(0<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_1P0DB	(1<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_1P5DB	(2<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_2P0DB	(3<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_2P5DB	(4<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_3P0DB	(5<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_3P5DB	(6<<24)
#define IOMUXC_GPR13_SATA_PHY_8_RXEQ_4P0DB	(7<<24)

#define IOMUXC_GPR13_SATA_PHY_7_SATA1I	(0x10<<19)
#define IOMUXC_GPR13_SATA_PHY_7_SATA1M	(0x10<<19)
#define IOMUXC_GPR13_SATA_PHY_7_SATA1X	(0x1A<<19)
#define IOMUXC_GPR13_SATA_PHY_7_SATA2I	(0x12<<19)
#define IOMUXC_GPR13_SATA_PHY_7_SATA2M	(0x12<<19)
#define IOMUXC_GPR13_SATA_PHY_7_SATA2X	(0x1A<<19)

#define IOMUXC_GPR13_SATA_SPEED_1P5G	(0<<15)
#define IOMUXC_GPR13_SATA_SPEED_3G	(1<<15)

#define IOMUXC_GPR13_SATA_SATA_PHY_5_SS_DISABLED	(0<<14)
#define IOMUXC_GPR13_SATA_SATA_PHY_5_SS_ENABLED		(1<<14)

#define IOMUXC_GPR13_SATA_SATA_PHY_4_ATTEN_16_16	(0<<11)
#define IOMUXC_GPR13_SATA_SATA_PHY_4_ATTEN_14_16	(1<<11)
#define IOMUXC_GPR13_SATA_SATA_PHY_4_ATTEN_12_16	(2<<11)
#define IOMUXC_GPR13_SATA_SATA_PHY_4_ATTEN_10_16	(3<<11)
#define IOMUXC_GPR13_SATA_SATA_PHY_4_ATTEN_9_16		(4<<11)
#define IOMUXC_GPR13_SATA_SATA_PHY_4_ATTEN_8_16		(5<<11)

#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_0P00_DB	(0<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_0P37_DB	(1<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_0P74_DB	(2<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_1P11_DB	(3<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_1P48_DB	(4<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_1P85_DB	(5<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_2P22_DB	(6<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_2P59_DB	(7<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_2P96_DB	(8<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_3P33_DB	(9<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_3P70_DB	(0xA<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_4P07_DB	(0xB<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_4P44_DB	(0xC<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_4P81_DB	(0xD<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_5P28_DB	(0xE<<7)
#define IOMUXC_GPR13_SATA_PHY_3_TXBOOST_5P75_DB	(0xF<<7)

#define IOMUXC_GPR13_SATA_PHY_2_TX_0P937V	(0<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_0P947V	(1<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_0P957V	(2<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_0P966V	(3<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_0P976V	(4<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_0P986V	(5<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_0P996V	(6<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P005V	(7<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P015V	(8<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P025V	(9<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P035V	(0xA<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P045V	(0xB<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P054V	(0xC<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P064V	(0xD<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P074V	(0xE<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P084V	(0xF<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P094V	(0x10<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P104V	(0x11<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P113V	(0x12<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P123V	(0x13<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P133V	(0x14<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P143V	(0x15<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P152V	(0x16<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P162V	(0x17<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P172V	(0x18<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P182V	(0x19<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P191V	(0x1A<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P201V	(0x1B<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P211V	(0x1C<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P221V	(0x1D<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P230V	(0x1E<<2)
#define IOMUXC_GPR13_SATA_PHY_2_TX_1P240V	(0x1F<<2)

#define IOMUXC_GPR13_SATA_PHY_1_FAST	0
#define IOMUXC_GPR13_SATA_PHY_1_MEDIUM	1
#define IOMUXC_GPR13_SATA_PHY_1_SLOW	2

#define IOMUXC_GPR13_SATA_MASK (IOMUXC_GPR13_SATA_PHY_8_MASK \
				|IOMUXC_GPR13_SATA_PHY_7_MASK \
				|IOMUXC_GPR13_SATA_PHY_6_MASK \
				|IOMUXC_GPR13_SATA_SPEED_MASK \
				|IOMUXC_GPR13_SATA_PHY_5_MASK \
				|IOMUXC_GPR13_SATA_PHY_4_MASK \
				|IOMUXC_GPR13_SATA_PHY_3_MASK \
				|IOMUXC_GPR13_SATA_PHY_2_MASK \
				|IOMUXC_GPR13_SATA_PHY_1_MASK)
#endif	/* __ASM_ARCH_IOMUX_H__ */
