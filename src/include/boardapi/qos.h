/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef _BOARDAPI_QOS_H_
#define _BOARDAPI_QOS_H_

/*
 * Select QoS types
 */
typedef enum qos_type_s {
    QT_PORT_BASED,
    QT_DOT1P_PRIORITY,
    QT_COUNT
} qos_type_t;

extern sys_error_t board_qos_type_set(qos_type_t type) REENTRANT;
extern sys_error_t board_qos_type_get(qos_type_t *type) REENTRANT;

/*
 * Assign port based priority
 */
extern sys_error_t board_untagged_priority_set(uint16 uport, 
                                               uint8 priority) REENTRANT;
extern sys_error_t board_untagged_priority_get(uint16 uport, 
                                               uint8 *priority) REENTRANT;
                                               
                                           
#endif /* _BOARDAPI_QOS_H_ */