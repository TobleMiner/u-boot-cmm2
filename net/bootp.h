/*
 *	Copied from LiMon - BOOTP.
 *
 *	Copyright 1994, 1995, 2000 Neil Russell.
 *	(See License)
 *	Copyright 2000 Paolo Scaffardi
 */

#ifndef __BOOTP_H__
#define __BOOTP_H__

#ifndef __NET_H__
#include <net.h>
#endif /* __NET_H__ */

/**********************************************************************/

/*
 *	BOOTP header.
 */
#if defined(CONFIG_CMD_DHCP)
/* Minimum DHCP Options size per RFC2131 - results in 576 byte pkt */
#define OPT_FIELD_SIZE 312
#if defined(CONFIG_BOOTP_VENDOREX)
extern u8 *dhcp_vendorex_prep(u8 *e); /*rtn new e after add own opts. */
extern u8 *dhcp_vendorex_proc(u8 *e); /*rtn next e if mine,else NULL  */
#endif
#else
#define OPT_FIELD_SIZE 64
#endif

struct bootp_hdr {
	uchar		bp_op;		/* Operation			*/
# define OP_BOOTREQUEST	1
# define OP_BOOTREPLY	2
	uchar		bp_htype;	/* Hardware type		*/
# define HWT_ETHER	1
	uchar		bp_hlen;	/* Hardware address length	*/
# define HWL_ETHER	6
	uchar		bp_hops;	/* Hop count (gateway thing)	*/
	ulong		bp_id;		/* Transaction ID		*/
	ushort		bp_secs;	/* Seconds since boot		*/
	ushort		bp_spare1;	/* Alignment			*/
	struct in_addr	bp_ciaddr;	/* Client IP address		*/
	struct in_addr	bp_yiaddr;	/* Your (client) IP address	*/
	struct in_addr	bp_siaddr;	/* Server IP address		*/
	struct in_addr	bp_giaddr;	/* Gateway IP address		*/
	uchar		bp_chaddr[16];	/* Client hardware address	*/
	char		bp_sname[64];	/* Server host name		*/
	char		bp_file[128];	/* Boot file name		*/
	char		bp_vend[OPT_FIELD_SIZE]; /* Vendor information	*/
};

#define BOOTP_HDR_SIZE	sizeof(struct bootp_hdr)

/**********************************************************************/
/*
 *	Global functions and variables.
 */

/* bootp.c */
extern ulong	bootp_id;		/* ID of cur BOOTP request	*/
extern int	bootp_try;


/* Send a BOOTP request */
void bootp_reset(void);
void bootp_request(void);

/****************** DHCP Support *********************/
void dhcp_request(void);

/* DHCP States */
typedef enum { INIT,
	       INIT_REBOOT,
	       REBOOTING,
	       SELECTING,
	       REQUESTING,
	       REBINDING,
	       BOUND,
	       RENEWING } dhcp_state_t;

#define DHCP_DISCOVER 1
#define DHCP_OFFER    2
#define DHCP_REQUEST  3
#define DHCP_DECLINE  4
#define DHCP_ACK      5
#define DHCP_NAK      6
#define DHCP_RELEASE  7

/**********************************************************************/

#endif /* __BOOTP_H__ */
