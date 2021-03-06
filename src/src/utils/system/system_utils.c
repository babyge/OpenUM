/*
 * $Id: system_utils.c,v 1.2 Broadcom SDK $
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include "system.h"
#if CFG_UIP_STACK_ENABLED
#include "uip.h"
#include "appl/dhcpc.h"
#endif
#include "utils/system.h"

#ifdef CFG_NVRAM_CONFIG_INCLUDED
#include "utils/nvram.h"
#endif /* CFG_NVRAM_CONFIG_INCLUDED */
#ifdef CFG_FACTORY_CONFIG_INCLUDED
#include "utils/factory.h"
#endif /* CFG_FACTORY_CONFIG_INCLUDED */

#if CFG_UIP_STACK_ENABLED
#ifdef CFG_ZEROCONF_MDNS_INCLUDED
#include "appl/mdns.h"
#endif /* CFG_ZEROCONF_MDNS_INCLUDED */
#endif /* CFG_UIP_STACK_ENABLED */

/*
 * System mac
 */
static uint8 system_mac[6] = DEFAULT_MAC_ADDR;

/*
 * System name/description
 */
static char system_name[MAX_SYSTEM_NAME_LEN + 1] = DEFAULT_SYSTEM_NAME;

#ifdef CFG_PRODUCT_REGISTRATION_INCLUDED
/*
 * Product registration status
 */
static uint8 product_reg_status = DEFAULT_REGISTRATION_STATUS;

/*
 * Product serial number
 */
static uint32   product_serial_num_magic;
static char product_serial_num[MAX_SERIAL_NUM_LEN + 1] = DEFAULT_SERIAL_NUMBER;
#endif /* CFG_PRODUCT_REGISTRATION_INCLUDED */

static int hexdigit_to_decimal(int digit);

static int
hexdigit_to_decimal(int digit)
{
    if (digit >= '0' && digit <= '9') return (digit - '0'     );
    if (digit >= 'a' && digit <= 'f') return (digit - 'a' + 10);
    if (digit >= 'A' && digit <= 'F') return (digit - 'A' + 10);
    return 0;
}

sys_error_t
parse_mac_address(const char *str, uint8 *macaddr)
{
    const char *s;
    int i;
    char gap_ch;

    if (str == NULL || str[0] == 0 || macaddr == NULL) {
        return SYS_ERR_PARAMETER;
    }
    if (sal_strchr(str, '-')) {
        gap_ch = '-';
    } else if (sal_strchr(str, ':')) {
        gap_ch = ':';
    } else {
        return SYS_ERR_PARAMETER;
    }

    s = str;
    for (i = 0; i < 6; i++) {
        if (!isxdigit((unsigned)*s)) {  /* bad character */
            return SYS_ERR_PARAMETER;
        }
        macaddr[i] = hexdigit_to_decimal((unsigned)*(s++));
        if (isxdigit((unsigned)*s)) {
            macaddr[i] *= 16;
            macaddr[i] += hexdigit_to_decimal((unsigned)*(s++));
        }
        if ((i < 5) && (*(s++) != gap_ch)) {  /* bad character */
            return SYS_ERR_PARAMETER;
        }
    }
    if (*s) {
        return SYS_ERR_PARAMETER;
    }

    return SYS_OK;
}

#ifdef CFG_PRODUCT_REGISTRATION_INCLUDED
sys_error_t
set_registration_status(uint8 status)
{
    if (status > REGISTRATION_STATUS_REGISTERED) {
        return SYS_ERR_PARAMETER;
    }

    product_reg_status = status;
    return SYS_OK;
}

sys_error_t
get_registration_status(uint8 *status)
{
    if (status == NULL) {
        return SYS_ERR_PARAMETER;
    }

    *status = product_reg_status;
    return SYS_OK;
}

sys_error_t
get_serial_num(uint8 *valid, char *serial_num)
{
    if (serial_num == NULL) {
        return SYS_ERR_PARAMETER;
    }

    if (product_serial_num_magic == FACTORY_SERIAL_NUMBER_MAGIC) {
        *valid = TRUE;
        sal_memcpy(serial_num, product_serial_num, MAX_SERIAL_NUM_LEN);
    } else {
        *valid = FALSE;
    }

    return SYS_OK;
}

sys_error_t
set_serial_num(uint8 valid, const char *serial_num)
{
    factory_config_t cfg;

    if (serial_num == NULL) {
        return SYS_ERR_PARAMETER;
    }

    if (factory_config_get(&cfg) != SYS_OK) {
#if CFG_CONSOLE_ENABLED
        sal_printf("factory_config_get failed in board_serial_num_set()");
#endif /* CFG_CONSOLE_ENABLED */
        return SYS_ERR;
    }

    if (valid == TRUE) {
        cfg.serial_num_magic = FACTORY_SERIAL_NUMBER_MAGIC;
        sal_memcpy(cfg.serial_num, serial_num, MAX_SERIAL_NUM_LEN);
        product_serial_num_magic = FACTORY_SERIAL_NUMBER_MAGIC;
        sal_memcpy(product_serial_num, serial_num, MAX_SERIAL_NUM_LEN);
    } else {
        product_serial_num_magic = 0;
        cfg.serial_num_magic = 0; /* Indicate an invalid serial number */
    }

    if (factory_config_set(&cfg) != SYS_OK) {
#if CFG_CONSOLE_ENABLED
        sal_printf("factory_config_set failed in board_serial_num_set()");
#endif /* CFG_CONSOLE_ENABLED */
        return SYS_ERR;
    }

    return SYS_OK;
}
#endif /* CFG_PRODUCT_REGISTRATION_INCLUDED */

sys_error_t
set_system_name(const char *name)
{
    if (name == NULL) {
        return SYS_ERR_PARAMETER;
    }

    if (sal_strlen(name) > MAX_SYSTEM_NAME_LEN) {
        return SYS_ERR_PARAMETER;
    }

    sal_strcpy(system_name, name);
#ifdef CFG_ZEROCONF_MDNS_INCLUDED
    mdns_host_domain_name_set();
#endif /* CFG_ZEROCONF_MDNS_INCLUDED */

    return SYS_OK;
}

sys_error_t
get_system_name(char *buf, uint8 len)
{
    if (buf == NULL || len == 0) {
        return SYS_ERR_PARAMETER;
    }

    if (sal_strlen(system_name) >= len) {
        return SYS_ERR_PARAMETER;
    }

    sal_strcpy(buf, system_name);

    return SYS_OK;
}

sys_error_t
get_system_mac(uint8 *mac_buf)
{
    if (mac_buf == NULL) {
        return SYS_ERR_PARAMETER;
    }
    sal_memcpy(mac_buf, system_mac, 6);
    return SYS_OK;
}

void
system_utils_init()
{
#ifdef CFG_FACTORY_CONFIG_INCLUDED
    factory_config_t cfg;
    if (factory_config_get(&cfg) == SYS_OK) {
        sal_memcpy(system_mac, cfg.mac, 6);
#ifdef CFG_PRODUCT_REGISTRATION_INCLUDED
        product_serial_num_magic = cfg.serial_num_magic;
        sal_memcpy(product_serial_num, cfg.serial_num, MAX_SERIAL_NUM_LEN);
#endif /* CFG_PRODUCT_REGISTRATION_INCLUDED */
    }
#else /* !CFG_FACTORY_CONFIG_INCLUDED */
#ifdef CFG_NVRAM_SUPPORT_INCLUDED
    const char *str_ptr;
    uint8 mac_addr[6];

    str_ptr = nvram_get("macaddr");
    if (str_ptr &&
        parse_mac_address(str_ptr, (uint8 *)&mac_addr) == SYS_OK) {
        sal_memcpy(system_mac, mac_addr, 6);
    }
#endif /* CFG_NVRAM_SUPPORT_INCLUDED */
#endif /* CFG_FACTORY_CONFIG_INCLUDED */
}

