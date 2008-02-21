/* DO NOT EDIT THIS FILE
 * Automatically generated by generate-cdef-headers.xsl
 * DO NOT EDIT THIS FILE
 */

#ifndef __BFIN_CDEF_ADSP_BF537_proc__
#define __BFIN_CDEF_ADSP_BF537_proc__

#include "../mach-common/ADSP-EDN-core_cdef.h"

#include "ADSP-EDN-BF534-extended_cdef.h"

#define pEMAC_OPMODE                   ((uint32_t volatile *)EMAC_OPMODE) /* Operating Mode Register */
#define bfin_read_EMAC_OPMODE()        bfin_read32(EMAC_OPMODE)
#define bfin_write_EMAC_OPMODE(val)    bfin_write32(EMAC_OPMODE, val)
#define pEMAC_ADDRLO                   ((uint32_t volatile *)EMAC_ADDRLO) /* Address Low (32 LSBs) Register */
#define bfin_read_EMAC_ADDRLO()        bfin_read32(EMAC_ADDRLO)
#define bfin_write_EMAC_ADDRLO(val)    bfin_write32(EMAC_ADDRLO, val)
#define pEMAC_ADDRHI                   ((uint32_t volatile *)EMAC_ADDRHI) /* Address High (16 MSBs) Register */
#define bfin_read_EMAC_ADDRHI()        bfin_read32(EMAC_ADDRHI)
#define bfin_write_EMAC_ADDRHI(val)    bfin_write32(EMAC_ADDRHI, val)
#define pEMAC_HASHLO                   ((uint32_t volatile *)EMAC_HASHLO) /* Multicast Hash Table Low (Bins 31-0) Register */
#define bfin_read_EMAC_HASHLO()        bfin_read32(EMAC_HASHLO)
#define bfin_write_EMAC_HASHLO(val)    bfin_write32(EMAC_HASHLO, val)
#define pEMAC_HASHHI                   ((uint32_t volatile *)EMAC_HASHHI) /* Multicast Hash Table High (Bins 63-32) Register */
#define bfin_read_EMAC_HASHHI()        bfin_read32(EMAC_HASHHI)
#define bfin_write_EMAC_HASHHI(val)    bfin_write32(EMAC_HASHHI, val)
#define pEMAC_STAADD                   ((uint32_t volatile *)EMAC_STAADD) /* Station Management Address Register */
#define bfin_read_EMAC_STAADD()        bfin_read32(EMAC_STAADD)
#define bfin_write_EMAC_STAADD(val)    bfin_write32(EMAC_STAADD, val)
#define pEMAC_STADAT                   ((uint32_t volatile *)EMAC_STADAT) /* Station Management Data Register */
#define bfin_read_EMAC_STADAT()        bfin_read32(EMAC_STADAT)
#define bfin_write_EMAC_STADAT(val)    bfin_write32(EMAC_STADAT, val)
#define pEMAC_FLC                      ((uint32_t volatile *)EMAC_FLC) /* Flow Control Register */
#define bfin_read_EMAC_FLC()           bfin_read32(EMAC_FLC)
#define bfin_write_EMAC_FLC(val)       bfin_write32(EMAC_FLC, val)
#define pEMAC_VLAN1                    ((uint32_t volatile *)EMAC_VLAN1) /* VLAN1 Tag Register */
#define bfin_read_EMAC_VLAN1()         bfin_read32(EMAC_VLAN1)
#define bfin_write_EMAC_VLAN1(val)     bfin_write32(EMAC_VLAN1, val)
#define pEMAC_VLAN2                    ((uint32_t volatile *)EMAC_VLAN2) /* VLAN2 Tag Register */
#define bfin_read_EMAC_VLAN2()         bfin_read32(EMAC_VLAN2)
#define bfin_write_EMAC_VLAN2(val)     bfin_write32(EMAC_VLAN2, val)
#define pEMAC_WKUP_CTL                 ((uint32_t volatile *)EMAC_WKUP_CTL) /* Wake-Up Control/Status Register */
#define bfin_read_EMAC_WKUP_CTL()      bfin_read32(EMAC_WKUP_CTL)
#define bfin_write_EMAC_WKUP_CTL(val)  bfin_write32(EMAC_WKUP_CTL, val)
#define pEMAC_WKUP_FFMSK0              ((uint32_t volatile *)EMAC_WKUP_FFMSK0) /* Wake-Up Frame Filter 0 Byte Mask Register */
#define bfin_read_EMAC_WKUP_FFMSK0()   bfin_read32(EMAC_WKUP_FFMSK0)
#define bfin_write_EMAC_WKUP_FFMSK0(val) bfin_write32(EMAC_WKUP_FFMSK0, val)
#define pEMAC_WKUP_FFMSK1              ((uint32_t volatile *)EMAC_WKUP_FFMSK1) /* Wake-Up Frame Filter 1 Byte Mask Register */
#define bfin_read_EMAC_WKUP_FFMSK1()   bfin_read32(EMAC_WKUP_FFMSK1)
#define bfin_write_EMAC_WKUP_FFMSK1(val) bfin_write32(EMAC_WKUP_FFMSK1, val)
#define pEMAC_WKUP_FFMSK2              ((uint32_t volatile *)EMAC_WKUP_FFMSK2) /* Wake-Up Frame Filter 2 Byte Mask Register */
#define bfin_read_EMAC_WKUP_FFMSK2()   bfin_read32(EMAC_WKUP_FFMSK2)
#define bfin_write_EMAC_WKUP_FFMSK2(val) bfin_write32(EMAC_WKUP_FFMSK2, val)
#define pEMAC_WKUP_FFMSK3              ((uint32_t volatile *)EMAC_WKUP_FFMSK3) /* Wake-Up Frame Filter 3 Byte Mask Register */
#define bfin_read_EMAC_WKUP_FFMSK3()   bfin_read32(EMAC_WKUP_FFMSK3)
#define bfin_write_EMAC_WKUP_FFMSK3(val) bfin_write32(EMAC_WKUP_FFMSK3, val)
#define pEMAC_WKUP_FFCMD               ((uint32_t volatile *)EMAC_WKUP_FFCMD) /* Wake-Up Frame Filter Commands Register */
#define bfin_read_EMAC_WKUP_FFCMD()    bfin_read32(EMAC_WKUP_FFCMD)
#define bfin_write_EMAC_WKUP_FFCMD(val) bfin_write32(EMAC_WKUP_FFCMD, val)
#define pEMAC_WKUP_FFOFF               ((uint32_t volatile *)EMAC_WKUP_FFOFF) /* Wake-Up Frame Filter Offsets Register */
#define bfin_read_EMAC_WKUP_FFOFF()    bfin_read32(EMAC_WKUP_FFOFF)
#define bfin_write_EMAC_WKUP_FFOFF(val) bfin_write32(EMAC_WKUP_FFOFF, val)
#define pEMAC_WKUP_FFCRC0              ((uint32_t volatile *)EMAC_WKUP_FFCRC0) /* Wake-Up Frame Filter 0,1 CRC-16 Register */
#define bfin_read_EMAC_WKUP_FFCRC0()   bfin_read32(EMAC_WKUP_FFCRC0)
#define bfin_write_EMAC_WKUP_FFCRC0(val) bfin_write32(EMAC_WKUP_FFCRC0, val)
#define pEMAC_WKUP_FFCRC1              ((uint32_t volatile *)EMAC_WKUP_FFCRC1) /* Wake-Up Frame Filter 2,3 CRC-16 Register */
#define bfin_read_EMAC_WKUP_FFCRC1()   bfin_read32(EMAC_WKUP_FFCRC1)
#define bfin_write_EMAC_WKUP_FFCRC1(val) bfin_write32(EMAC_WKUP_FFCRC1, val)
#define pEMAC_SYSCTL                   ((uint32_t volatile *)EMAC_SYSCTL) /* EMAC System Control Register */
#define bfin_read_EMAC_SYSCTL()        bfin_read32(EMAC_SYSCTL)
#define bfin_write_EMAC_SYSCTL(val)    bfin_write32(EMAC_SYSCTL, val)
#define pEMAC_SYSTAT                   ((uint32_t volatile *)EMAC_SYSTAT) /* EMAC System Status Register */
#define bfin_read_EMAC_SYSTAT()        bfin_read32(EMAC_SYSTAT)
#define bfin_write_EMAC_SYSTAT(val)    bfin_write32(EMAC_SYSTAT, val)
#define pEMAC_RX_STAT                  ((uint32_t volatile *)EMAC_RX_STAT) /* RX Current Frame Status Register */
#define bfin_read_EMAC_RX_STAT()       bfin_read32(EMAC_RX_STAT)
#define bfin_write_EMAC_RX_STAT(val)   bfin_write32(EMAC_RX_STAT, val)
#define pEMAC_RX_STKY                  ((uint32_t volatile *)EMAC_RX_STKY) /* RX Sticky Frame Status Register */
#define bfin_read_EMAC_RX_STKY()       bfin_read32(EMAC_RX_STKY)
#define bfin_write_EMAC_RX_STKY(val)   bfin_write32(EMAC_RX_STKY, val)
#define pEMAC_RX_IRQE                  ((uint32_t volatile *)EMAC_RX_IRQE) /* RX Frame Status Interrupt Enables Register */
#define bfin_read_EMAC_RX_IRQE()       bfin_read32(EMAC_RX_IRQE)
#define bfin_write_EMAC_RX_IRQE(val)   bfin_write32(EMAC_RX_IRQE, val)
#define pEMAC_TX_STAT                  ((uint32_t volatile *)EMAC_TX_STAT) /* TX Current Frame Status Register */
#define bfin_read_EMAC_TX_STAT()       bfin_read32(EMAC_TX_STAT)
#define bfin_write_EMAC_TX_STAT(val)   bfin_write32(EMAC_TX_STAT, val)
#define pEMAC_TX_STKY                  ((uint32_t volatile *)EMAC_TX_STKY) /* TX Sticky Frame Status Register */
#define bfin_read_EMAC_TX_STKY()       bfin_read32(EMAC_TX_STKY)
#define bfin_write_EMAC_TX_STKY(val)   bfin_write32(EMAC_TX_STKY, val)
#define pEMAC_TX_IRQE                  ((uint32_t volatile *)EMAC_TX_IRQE) /* TX Frame Status Interrupt Enables Register */
#define bfin_read_EMAC_TX_IRQE()       bfin_read32(EMAC_TX_IRQE)
#define bfin_write_EMAC_TX_IRQE(val)   bfin_write32(EMAC_TX_IRQE, val)
#define pEMAC_MMC_CTL                  ((uint32_t volatile *)EMAC_MMC_CTL) /* MMC Counter Control Register */
#define bfin_read_EMAC_MMC_CTL()       bfin_read32(EMAC_MMC_CTL)
#define bfin_write_EMAC_MMC_CTL(val)   bfin_write32(EMAC_MMC_CTL, val)
#define pEMAC_MMC_RIRQS                ((uint32_t volatile *)EMAC_MMC_RIRQS) /* MMC RX Interrupt Status Register */
#define bfin_read_EMAC_MMC_RIRQS()     bfin_read32(EMAC_MMC_RIRQS)
#define bfin_write_EMAC_MMC_RIRQS(val) bfin_write32(EMAC_MMC_RIRQS, val)
#define pEMAC_MMC_RIRQE                ((uint32_t volatile *)EMAC_MMC_RIRQE) /* MMC RX Interrupt Enables Register */
#define bfin_read_EMAC_MMC_RIRQE()     bfin_read32(EMAC_MMC_RIRQE)
#define bfin_write_EMAC_MMC_RIRQE(val) bfin_write32(EMAC_MMC_RIRQE, val)
#define pEMAC_MMC_TIRQS                ((uint32_t volatile *)EMAC_MMC_TIRQS) /* MMC TX Interrupt Status Register */
#define bfin_read_EMAC_MMC_TIRQS()     bfin_read32(EMAC_MMC_TIRQS)
#define bfin_write_EMAC_MMC_TIRQS(val) bfin_write32(EMAC_MMC_TIRQS, val)
#define pEMAC_MMC_TIRQE                ((uint32_t volatile *)EMAC_MMC_TIRQE) /* MMC TX Interrupt Enables Register */
#define bfin_read_EMAC_MMC_TIRQE()     bfin_read32(EMAC_MMC_TIRQE)
#define bfin_write_EMAC_MMC_TIRQE(val) bfin_write32(EMAC_MMC_TIRQE, val)
#define pEMAC_RXC_OK                   ((uint32_t volatile *)EMAC_RXC_OK) /* RX Frame Successful Count */
#define bfin_read_EMAC_RXC_OK()        bfin_read32(EMAC_RXC_OK)
#define bfin_write_EMAC_RXC_OK(val)    bfin_write32(EMAC_RXC_OK, val)
#define pEMAC_RXC_FCS                  ((uint32_t volatile *)EMAC_RXC_FCS) /* RX Frame FCS Failure Count */
#define bfin_read_EMAC_RXC_FCS()       bfin_read32(EMAC_RXC_FCS)
#define bfin_write_EMAC_RXC_FCS(val)   bfin_write32(EMAC_RXC_FCS, val)
#define pEMAC_RXC_ALIGN                ((uint32_t volatile *)EMAC_RXC_ALIGN) /* RX Alignment Error Count */
#define bfin_read_EMAC_RXC_ALIGN()     bfin_read32(EMAC_RXC_ALIGN)
#define bfin_write_EMAC_RXC_ALIGN(val) bfin_write32(EMAC_RXC_ALIGN, val)
#define pEMAC_RXC_OCTET                ((uint32_t volatile *)EMAC_RXC_OCTET) /* RX Octets Successfully Received Count */
#define bfin_read_EMAC_RXC_OCTET()     bfin_read32(EMAC_RXC_OCTET)
#define bfin_write_EMAC_RXC_OCTET(val) bfin_write32(EMAC_RXC_OCTET, val)
#define pEMAC_RXC_DMAOVF               ((uint32_t volatile *)EMAC_RXC_DMAOVF) /* Internal MAC Sublayer Error RX Frame Count */
#define bfin_read_EMAC_RXC_DMAOVF()    bfin_read32(EMAC_RXC_DMAOVF)
#define bfin_write_EMAC_RXC_DMAOVF(val) bfin_write32(EMAC_RXC_DMAOVF, val)
#define pEMAC_RXC_UNICST               ((uint32_t volatile *)EMAC_RXC_UNICST) /* Unicast RX Frame Count */
#define bfin_read_EMAC_RXC_UNICST()    bfin_read32(EMAC_RXC_UNICST)
#define bfin_write_EMAC_RXC_UNICST(val) bfin_write32(EMAC_RXC_UNICST, val)
#define pEMAC_RXC_MULTI                ((uint32_t volatile *)EMAC_RXC_MULTI) /* Multicast RX Frame Count */
#define bfin_read_EMAC_RXC_MULTI()     bfin_read32(EMAC_RXC_MULTI)
#define bfin_write_EMAC_RXC_MULTI(val) bfin_write32(EMAC_RXC_MULTI, val)
#define pEMAC_RXC_BROAD                ((uint32_t volatile *)EMAC_RXC_BROAD) /* Broadcast RX Frame Count */
#define bfin_read_EMAC_RXC_BROAD()     bfin_read32(EMAC_RXC_BROAD)
#define bfin_write_EMAC_RXC_BROAD(val) bfin_write32(EMAC_RXC_BROAD, val)
#define pEMAC_RXC_LNERRI               ((uint32_t volatile *)EMAC_RXC_LNERRI) /* RX Frame In Range Error Count */
#define bfin_read_EMAC_RXC_LNERRI()    bfin_read32(EMAC_RXC_LNERRI)
#define bfin_write_EMAC_RXC_LNERRI(val) bfin_write32(EMAC_RXC_LNERRI, val)
#define pEMAC_RXC_LNERRO               ((uint32_t volatile *)EMAC_RXC_LNERRO) /* RX Frame Out Of Range Error Count */
#define bfin_read_EMAC_RXC_LNERRO()    bfin_read32(EMAC_RXC_LNERRO)
#define bfin_write_EMAC_RXC_LNERRO(val) bfin_write32(EMAC_RXC_LNERRO, val)
#define pEMAC_RXC_LONG                 ((uint32_t volatile *)EMAC_RXC_LONG) /* RX Frame Too Long Count */
#define bfin_read_EMAC_RXC_LONG()      bfin_read32(EMAC_RXC_LONG)
#define bfin_write_EMAC_RXC_LONG(val)  bfin_write32(EMAC_RXC_LONG, val)
#define pEMAC_RXC_MACCTL               ((uint32_t volatile *)EMAC_RXC_MACCTL) /* MAC Control RX Frame Count */
#define bfin_read_EMAC_RXC_MACCTL()    bfin_read32(EMAC_RXC_MACCTL)
#define bfin_write_EMAC_RXC_MACCTL(val) bfin_write32(EMAC_RXC_MACCTL, val)
#define pEMAC_RXC_OPCODE               ((uint32_t volatile *)EMAC_RXC_OPCODE) /* Unsupported Op-Code RX Frame Count */
#define bfin_read_EMAC_RXC_OPCODE()    bfin_read32(EMAC_RXC_OPCODE)
#define bfin_write_EMAC_RXC_OPCODE(val) bfin_write32(EMAC_RXC_OPCODE, val)
#define pEMAC_RXC_PAUSE                ((uint32_t volatile *)EMAC_RXC_PAUSE) /* MAC Control Pause RX Frame Count */
#define bfin_read_EMAC_RXC_PAUSE()     bfin_read32(EMAC_RXC_PAUSE)
#define bfin_write_EMAC_RXC_PAUSE(val) bfin_write32(EMAC_RXC_PAUSE, val)
#define pEMAC_RXC_ALLFRM               ((uint32_t volatile *)EMAC_RXC_ALLFRM) /* Overall RX Frame Count */
#define bfin_read_EMAC_RXC_ALLFRM()    bfin_read32(EMAC_RXC_ALLFRM)
#define bfin_write_EMAC_RXC_ALLFRM(val) bfin_write32(EMAC_RXC_ALLFRM, val)
#define pEMAC_RXC_ALLOCT               ((uint32_t volatile *)EMAC_RXC_ALLOCT) /* Overall RX Octet Count */
#define bfin_read_EMAC_RXC_ALLOCT()    bfin_read32(EMAC_RXC_ALLOCT)
#define bfin_write_EMAC_RXC_ALLOCT(val) bfin_write32(EMAC_RXC_ALLOCT, val)
#define pEMAC_RXC_TYPED                ((uint32_t volatile *)EMAC_RXC_TYPED) /* Type/Length Consistent RX Frame Count  */
#define bfin_read_EMAC_RXC_TYPED()     bfin_read32(EMAC_RXC_TYPED)
#define bfin_write_EMAC_RXC_TYPED(val) bfin_write32(EMAC_RXC_TYPED, val)
#define pEMAC_RXC_SHORT                ((uint32_t volatile *)EMAC_RXC_SHORT) /* RX Frame Fragment Count - Byte Count x < 64 */
#define bfin_read_EMAC_RXC_SHORT()     bfin_read32(EMAC_RXC_SHORT)
#define bfin_write_EMAC_RXC_SHORT(val) bfin_write32(EMAC_RXC_SHORT, val)
#define pEMAC_RXC_EQ64                 ((uint32_t volatile *)EMAC_RXC_EQ64) /* Good RX Frame Count - Byte Count x = 64 */
#define bfin_read_EMAC_RXC_EQ64()      bfin_read32(EMAC_RXC_EQ64)
#define bfin_write_EMAC_RXC_EQ64(val)  bfin_write32(EMAC_RXC_EQ64, val)
#define pEMAC_RXC_LT128                ((uint32_t volatile *)EMAC_RXC_LT128) /* Good RX Frame Count - Byte Count  64 <= x < 128 */
#define bfin_read_EMAC_RXC_LT128()     bfin_read32(EMAC_RXC_LT128)
#define bfin_write_EMAC_RXC_LT128(val) bfin_write32(EMAC_RXC_LT128, val)
#define pEMAC_RXC_LT256                ((uint32_t volatile *)EMAC_RXC_LT256) /* Good RX Frame Count - Byte Count 128 <= x < 256 */
#define bfin_read_EMAC_RXC_LT256()     bfin_read32(EMAC_RXC_LT256)
#define bfin_write_EMAC_RXC_LT256(val) bfin_write32(EMAC_RXC_LT256, val)
#define pEMAC_RXC_LT512                ((uint32_t volatile *)EMAC_RXC_LT512) /* Good RX Frame Count - Byte Count 256 <= x < 512 */
#define bfin_read_EMAC_RXC_LT512()     bfin_read32(EMAC_RXC_LT512)
#define bfin_write_EMAC_RXC_LT512(val) bfin_write32(EMAC_RXC_LT512, val)
#define pEMAC_RXC_LT1024               ((uint32_t volatile *)EMAC_RXC_LT1024) /* Good RX Frame Count - Byte Count 512 <= x < 1024 */
#define bfin_read_EMAC_RXC_LT1024()    bfin_read32(EMAC_RXC_LT1024)
#define bfin_write_EMAC_RXC_LT1024(val) bfin_write32(EMAC_RXC_LT1024, val)
#define pEMAC_RXC_GE1024               ((uint32_t volatile *)EMAC_RXC_GE1024) /* Good RX Frame Count - Byte Count x >= 1024 */
#define bfin_read_EMAC_RXC_GE1024()    bfin_read32(EMAC_RXC_GE1024)
#define bfin_write_EMAC_RXC_GE1024(val) bfin_write32(EMAC_RXC_GE1024, val)
#define pEMAC_TXC_OK                   ((uint32_t volatile *)EMAC_TXC_OK) /* TX Frame Successful Count */
#define bfin_read_EMAC_TXC_OK()        bfin_read32(EMAC_TXC_OK)
#define bfin_write_EMAC_TXC_OK(val)    bfin_write32(EMAC_TXC_OK, val)
#define pEMAC_TXC_1COL                 ((uint32_t volatile *)EMAC_TXC_1COL) /* TX Frames Successful After Single Collision Count */
#define bfin_read_EMAC_TXC_1COL()      bfin_read32(EMAC_TXC_1COL)
#define bfin_write_EMAC_TXC_1COL(val)  bfin_write32(EMAC_TXC_1COL, val)
#define pEMAC_TXC_GT1COL               ((uint32_t volatile *)EMAC_TXC_GT1COL) /* TX Frames Successful After Multiple Collisions Count */
#define bfin_read_EMAC_TXC_GT1COL()    bfin_read32(EMAC_TXC_GT1COL)
#define bfin_write_EMAC_TXC_GT1COL(val) bfin_write32(EMAC_TXC_GT1COL, val)
#define pEMAC_TXC_OCTET                ((uint32_t volatile *)EMAC_TXC_OCTET) /* TX Octets Successfully Received Count */
#define bfin_read_EMAC_TXC_OCTET()     bfin_read32(EMAC_TXC_OCTET)
#define bfin_write_EMAC_TXC_OCTET(val) bfin_write32(EMAC_TXC_OCTET, val)
#define pEMAC_TXC_DEFER                ((uint32_t volatile *)EMAC_TXC_DEFER) /* TX Frame Delayed Due To Busy Count */
#define bfin_read_EMAC_TXC_DEFER()     bfin_read32(EMAC_TXC_DEFER)
#define bfin_write_EMAC_TXC_DEFER(val) bfin_write32(EMAC_TXC_DEFER, val)
#define pEMAC_TXC_LATECL               ((uint32_t volatile *)EMAC_TXC_LATECL) /* Late TX Collisions Count */
#define bfin_read_EMAC_TXC_LATECL()    bfin_read32(EMAC_TXC_LATECL)
#define bfin_write_EMAC_TXC_LATECL(val) bfin_write32(EMAC_TXC_LATECL, val)
#define pEMAC_TXC_XS_COL               ((uint32_t volatile *)EMAC_TXC_XS_COL) /* TX Frame Failed Due To Excessive Collisions Count */
#define bfin_read_EMAC_TXC_XS_COL()    bfin_read32(EMAC_TXC_XS_COL)
#define bfin_write_EMAC_TXC_XS_COL(val) bfin_write32(EMAC_TXC_XS_COL, val)
#define pEMAC_TXC_DMAUND               ((uint32_t volatile *)EMAC_TXC_DMAUND) /* Internal MAC Sublayer Error TX Frame Count */
#define bfin_read_EMAC_TXC_DMAUND()    bfin_read32(EMAC_TXC_DMAUND)
#define bfin_write_EMAC_TXC_DMAUND(val) bfin_write32(EMAC_TXC_DMAUND, val)
#define pEMAC_TXC_CRSERR               ((uint32_t volatile *)EMAC_TXC_CRSERR) /* Carrier Sense Deasserted During TX Frame Count */
#define bfin_read_EMAC_TXC_CRSERR()    bfin_read32(EMAC_TXC_CRSERR)
#define bfin_write_EMAC_TXC_CRSERR(val) bfin_write32(EMAC_TXC_CRSERR, val)
#define pEMAC_TXC_UNICST               ((uint32_t volatile *)EMAC_TXC_UNICST) /* Unicast TX Frame Count */
#define bfin_read_EMAC_TXC_UNICST()    bfin_read32(EMAC_TXC_UNICST)
#define bfin_write_EMAC_TXC_UNICST(val) bfin_write32(EMAC_TXC_UNICST, val)
#define pEMAC_TXC_MULTI                ((uint32_t volatile *)EMAC_TXC_MULTI) /* Multicast TX Frame Count */
#define bfin_read_EMAC_TXC_MULTI()     bfin_read32(EMAC_TXC_MULTI)
#define bfin_write_EMAC_TXC_MULTI(val) bfin_write32(EMAC_TXC_MULTI, val)
#define pEMAC_TXC_BROAD                ((uint32_t volatile *)EMAC_TXC_BROAD) /* Broadcast TX Frame Count */
#define bfin_read_EMAC_TXC_BROAD()     bfin_read32(EMAC_TXC_BROAD)
#define bfin_write_EMAC_TXC_BROAD(val) bfin_write32(EMAC_TXC_BROAD, val)
#define pEMAC_TXC_XS_DFR               ((uint32_t volatile *)EMAC_TXC_XS_DFR) /* TX Frames With Excessive Deferral Count */
#define bfin_read_EMAC_TXC_XS_DFR()    bfin_read32(EMAC_TXC_XS_DFR)
#define bfin_write_EMAC_TXC_XS_DFR(val) bfin_write32(EMAC_TXC_XS_DFR, val)
#define pEMAC_TXC_MACCTL               ((uint32_t volatile *)EMAC_TXC_MACCTL) /* MAC Control TX Frame Count */
#define bfin_read_EMAC_TXC_MACCTL()    bfin_read32(EMAC_TXC_MACCTL)
#define bfin_write_EMAC_TXC_MACCTL(val) bfin_write32(EMAC_TXC_MACCTL, val)
#define pEMAC_TXC_ALLFRM               ((uint32_t volatile *)EMAC_TXC_ALLFRM) /* Overall TX Frame Count */
#define bfin_read_EMAC_TXC_ALLFRM()    bfin_read32(EMAC_TXC_ALLFRM)
#define bfin_write_EMAC_TXC_ALLFRM(val) bfin_write32(EMAC_TXC_ALLFRM, val)
#define pEMAC_TXC_ALLOCT               ((uint32_t volatile *)EMAC_TXC_ALLOCT) /* Overall TX Octet Count */
#define bfin_read_EMAC_TXC_ALLOCT()    bfin_read32(EMAC_TXC_ALLOCT)
#define bfin_write_EMAC_TXC_ALLOCT(val) bfin_write32(EMAC_TXC_ALLOCT, val)
#define pEMAC_TXC_EQ64                 ((uint32_t volatile *)EMAC_TXC_EQ64) /* Good TX Frame Count - Byte Count x = 64 */
#define bfin_read_EMAC_TXC_EQ64()      bfin_read32(EMAC_TXC_EQ64)
#define bfin_write_EMAC_TXC_EQ64(val)  bfin_write32(EMAC_TXC_EQ64, val)
#define pEMAC_TXC_LT128                ((uint32_t volatile *)EMAC_TXC_LT128) /* Good TX Frame Count - Byte Count  64 <= x < 128 */
#define bfin_read_EMAC_TXC_LT128()     bfin_read32(EMAC_TXC_LT128)
#define bfin_write_EMAC_TXC_LT128(val) bfin_write32(EMAC_TXC_LT128, val)
#define pEMAC_TXC_LT256                ((uint32_t volatile *)EMAC_TXC_LT256) /* Good TX Frame Count - Byte Count 128 <= x < 256 */
#define bfin_read_EMAC_TXC_LT256()     bfin_read32(EMAC_TXC_LT256)
#define bfin_write_EMAC_TXC_LT256(val) bfin_write32(EMAC_TXC_LT256, val)
#define pEMAC_TXC_LT512                ((uint32_t volatile *)EMAC_TXC_LT512) /* Good TX Frame Count - Byte Count 256 <= x < 512 */
#define bfin_read_EMAC_TXC_LT512()     bfin_read32(EMAC_TXC_LT512)
#define bfin_write_EMAC_TXC_LT512(val) bfin_write32(EMAC_TXC_LT512, val)
#define pEMAC_TXC_LT1024               ((uint32_t volatile *)EMAC_TXC_LT1024) /* Good TX Frame Count - Byte Count 512 <= x < 1024 */
#define bfin_read_EMAC_TXC_LT1024()    bfin_read32(EMAC_TXC_LT1024)
#define bfin_write_EMAC_TXC_LT1024(val) bfin_write32(EMAC_TXC_LT1024, val)
#define pEMAC_TXC_GE1024               ((uint32_t volatile *)EMAC_TXC_GE1024) /* Good TX Frame Count - Byte Count x >= 1024 */
#define bfin_read_EMAC_TXC_GE1024()    bfin_read32(EMAC_TXC_GE1024)
#define bfin_write_EMAC_TXC_GE1024(val) bfin_write32(EMAC_TXC_GE1024, val)
#define pEMAC_TXC_ABORT                ((uint32_t volatile *)EMAC_TXC_ABORT) /* Total TX Frames Aborted Count */
#define bfin_read_EMAC_TXC_ABORT()     bfin_read32(EMAC_TXC_ABORT)
#define bfin_write_EMAC_TXC_ABORT(val) bfin_write32(EMAC_TXC_ABORT, val)

#endif /* __BFIN_CDEF_ADSP_BF537_proc__ */
