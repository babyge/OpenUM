/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef _PKT_H_
#define _PKT_H_

/* RX flags (read by handler) */
#define SYS_RX_FLAG_TIMESTAMP                       (1 << 0)
#define SYS_RX_FLAG_COS                             (1 << 1)
#define SYS_RX_FLAG_TRUNCATED                       (1 << 2)
#define SYS_RX_FLAG_ERROR_CRC                       (1 << 3)
#define SYS_RX_FLAG_ERROR_OTHER                     (1 << 4)

/* TX flags (used by caller) */
#define SYS_TX_FLAG_TIMESTAMP_REQUEST               (1 << 8)
#define SYS_TX_FLAG_USE_UNTAG_PORT_LIST             (1 << 9) 

/* VLAN tagging mode (Used if tx_uplist is empty) */
#define SYS_TX_TAG_MODE_FOLLOW_SWITCH_RULES         (0)
#define SYS_TX_TAG_MODE_UNTAG_ALL                   (1)
#define SYS_TX_TAG_MODE_TAG_ALL                     (2)

typedef struct sys_pkt_s {
    uint8 * pkt_data;
    uint16  pkt_len;
    uint16  buf_len;
    uint16  flags;
    uint16  cos;
            
    uint16  rx_src_uport;
    uint32  rx_timestamp;
            
    uint8   tx_uplist[MAX_UPLIST_WIDTH];    /* Follow switch ARL if empty */
    uint8   tx_untag_uplist[MAX_UPLIST_WIDTH];   /* If USE_UNTAG_PORT_BITMAP set */
    uint8   tx_tag_mode;                    /* Only if tx_uplist is empty */
    void *  cookie;
            
    uint32  reserved1;
    uint32  reserved2;
    uint32  reserved3;
    uint32  reserved4;
            
    uint32  internal0;  /* Used internally in kernel */
    uint32  internal1;  /* Used internally in board */
    
    struct sys_pkt_s *  next;
} sys_pkt_t;

#endif /* _PKT_H_ */