/*
 * $Id: config_loader.h,v 1.3 Broadcom SDK $
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_
#define __BOOTLOADER__
/* Chip type */
#define CFG_XGS_CHIP                        (1)
/* #define CFG_ROBO_CHIP                       (!CFG_XGS_CHIP) */

#define CONFIG_EMULATION                    (0)

/* Enable UART1 output */
#define CFG_USE_UART1                       (1)

/* Enable console output */
#define CFG_CONSOLE_ENABLED                 (1)

/* Enable debug output */
#define CFG_DEBUGGING_ENABLED               (0)

/* Enable assertion */
#define CFG_ASSERTION_ENABLED               (0)

/* Enhanced power saving */
#define CFG_ENHANCED_POWER_SAVING           (0)

/* Enable packet RX/TX support */
#define CFG_RXTX_SUPPORT_ENABLED            (0)

/* Enable SAL LIB_support */
#define CFG_SAL_LIB_SUPPORT_ENABLED         (1)

/* CLI support */
#define CFG_CLI_ENABLED                     (1 && CFG_CONSOLE_ENABLED)

/* CLI prompt */
#define CFG_CLI_PROMPT                      "CMD> "

/* CLI system commands support */
#define CFG_CLI_SYSTEM_CMD_ENABLED          (1)

/* CLI switch commands support */
#define CFG_CLI_SWITCH_CMD_ENABLED          (1)

/* CLI power commands support */
#define CFG_CLI_POWER_CMD_ENABLED           (0)

/* CLI RX commands support */
#define CFG_CLI_RX_CMD_ENABLED              (0)

/* CLI TX commands support */
#define CFG_CLI_TX_CMD_ENABLED              (0)

/* CLI RX monitor */
#define CFG_CLI_RX_MON_PRIORITY             (1)

/* uIP main control RX priority */
#define CFG_UIP_RX_PRIORITY                 (10)

/* CLI TX packet configurations */
#define CFG_CLI_TX_MAX_PKTCFGS              (8)

/* UART baudrate */
#define CFG_UART_BAUDRATE                (115200) 

/* PCIe serdes powerdown */
#define CFG_PCIE_SERDES_POWERDOWN_ENABLED   (1)

/* Max background tasks */
#define CFG_MAX_BACKGROUND_TASKS            (8)

/* Enable timer callback mechanism */
#define CFG_TIMER_CALLBACK_SUPPORT          (1)

/* Max registered timer (callback) */
#define CFG_MAX_REGISTERED_TIMERS           (16)

/* Enable linkchange callback mechanism */
#define CFG_LINKCHANGE_CALLBACK_SUPPORT     (1)

/* Max registered link change callback */
#define CFG_MAX_REGISTERED_LINKCHANGE       (16)

/* Interval for checking link change (in us) */
#define CFG_LINKCHANGE_CHECK_INTERVAL       (600000UL)

/* Max registered RX callback functions */
#define CFG_MAX_REGISTERED_RX_CBKS          (16)

/* Whether RX uses interrupt for receiving notification */
#define CFG_RX_USE_INTERRUPT                (0)

/* Packet length (excluding CRC) */
#define MIN_PACKET_LENGTH                   (60)
#define MAX_PACKET_LENGTH                   (1514)

/* FP */
#define ENTRIES_PER_SLICE                   (128)

/* Critical region protection with antoher processor*/
#define CFG_SOC_SEMAPHORE_INCLUDED

/* chip type */
#define CFG_SWITCH_XGS_NEW_SBUS_FORMAT_INCLUDED

/* Stoarge related */
#define CFG_FLASH_SUPPORT_ENABLED           (1)
#define CFG_CLI_FLASH_CMD_ENABLED           (1)

/* A factory data management engine*/
#define CFG_FACTORY_CONFIG_INCLUDED

/* A binary storage management engine, named serializer */
#define CFG_PERSISTENCE_SUPPORT_ENABLED     (0)

#define CFG_AGE_ENABLED                     (1)

/* IP above layer related  setting*/
#define CFG_UIP_STACK_ENABLED               (0 && CFG_RXTX_SUPPORT_ENABLED)
#define MAX_IP_TOTAL_LENGTH                 (1500)
#define CFG_UIP_IPV6_ENABLED                (1 && CFG_UIP_STACK_ENABLED)
#define CFG_NET_LINKCHANGE_NOTIFY_INCLUDED
#define CFG_NET_MAX_LINKCHANGE_HANDLER      (8)

/* HTTP server */
#define CFG_HTTPD_ENABLED                   (0)

/* Zero Configuration Networking */
/* Auto config of IPv4 Link-Local Addresses */
/* #define CFG_ZEROCONF_AUTOIP_INCLUDED */

/* Multicast DNS and DNS-SD (Bonjour) */
/* #define CFG_ZEROCONF_MDNS_INCLUDED */

#ifdef CFG_ZEROCONF_MDNS_INCLUDED
/* End with dot symbol */
#define CFG_MDNS_DEFAULT_HTTP_INSTANCE "UM-BCM95357x."
/* TXT record information */
#define CFG_MDNS_MODEL_NAME "BCM95357xR"
#define CFG_MDNS_MODEL_DESC "BCM95357x Reference Board"
#endif /* CFG_ZEROCONF_MDNS_INCLUDED */

/* Port Control Manager support */
#define CFG_PCM_SUPPORT_INCLUDED


/*
  *  CFG_NVRAM_SUPPORT_INCLUDED
  *      undefined : exclude the NVRAM defined advance command line engine
  *      defined: include the NVRAM storage
  */

/* #define CFG_NVRAM_SUPPORT_INCLUDED */





/****************************************************************************
 *
 * Features defined below can be selectively add or removed before building the image
 */

/*
  *  CFG_VENDOR_CONFIG_SUPPORT_INCLUDED
  *      undefined : exclude VENDOR CONFIG related code
  *      defined: will include the NVRAM ,some XCMD utils and VENDOR CONFIG code
  */

#define CFG_VENDOR_CONFIG_SUPPORT_INCLUDED

/*
  *  CFG_ETHERNET_WIRESPEED_INCLUDED
  *      undefined : exclude ethernet wirespeed feature
  *      defined: include ethernet wirespeed feature
  */
/* #define CFG_ETHERNET_WIRESPEED_INCLUDED */

#ifdef CFG_ETHERNET_WIRESPEED_INCLUDED
/*
 * Ethernet@wirespeed retry disable.
 *   defined as 0 1'b1 : downgrade after 1 failed link attemp
 *   defined as 0 1'b0 : use WIRESPEED_RETRY_LIMIT
 */
#define CFG_ETHERNET_WIRESPEED_RETRY_DIS       (0)
/*
 * Ethernet@wirespeed retry limit.
 * It is the number of auto-negotiation attemps to link-up prior to speed downgrade.
 * The ethernet@wirespeed mode must be enabled for retry limit.
 * The retry limit can be chosen from 2-8.
 */
#define CFG_ETHERNET_WIRESPEED_RETRY_LIMIT     (5)
#endif /* CFG_ETHERNET_WIRESPEED_INCLUDED */

/*
  *  CFG_DUAL_IMAGE_INCLUDED
  *      undefined : exclude dual image feature
  *      defined: include dual image feature
  */
#define CFG_DUAL_IMAGE_INCLUDED

/*
  *  CFG_DEBUGGING_INCLUDED
  *      undefined : exclude debugging code
  *      defined: include debugging code
  */
/* #define CFG_DEBUGGING_INCLUDED */

/*
  *  CFG_LED_MICROCODE_INCLUDED
  *      undefined : exclude serial LED feature
  *      defined as 1 : includee serial LED feature and use "direct serial out"
  *      defined as 2 : includee serial LED feature and use "internal serial-to-parallel to chip ballout"
  */
/* #define CFG_LED_MICROCODE_INCLUDED   (2) */

/*
  *  CFG_CONFIG_OPTION :
  * BCM53406: Option 1-4
  *                             1: 12x1G/2.5G/5G/10G + 12x1G/2.5G
  *                             2: 4xXAUI + 8x1G/2.5G/5G/10G
  *                             3: 4xXAUI + 4x1G/2.5G/5G/10G
  *                             4: 15x1G/2.5G/5G/10G + 9x1G
  * BCM53456: Option 1-3
  *                             1: 4xQSGMII + 8x1G/2.5G + 4x1G/2.5G/5G/10G
  *                             2: 4xQSGMII + 8x1G/2.5G + 2x10G + 2x13G
  *                             3: 2xQSGMII + 16x1G/2.5G + 4x1G/2.5G/5G/10G
  * BCM53424: Option 1-3
  *                             1: 4xQSGMII + 8x1G + 4x1G/2.5G/5G/10G
  *                             2: 4xQSGMII + 8x1G + 2x10G + 2x13G
  *                             3: 2xQSGMII + 16x1G + 4x1G/2.5G/5G/10G
  */
#define CFG_CONFIG_OPTION  (1)

/*
  *  CFG_CONFIG_1G_PORT_AN : default AN mode on ports with fiber mode and max speed is 1G
  *      defined as 0 : disable AN
  *      defined as 1 : CL73
  *      defined as 2 : CL37
  */
#define CFG_CONFIG_1G_PORT_AN  (2)

/*
  *  CFG_CONFIG_10G_PORT_AN : default AN mode on ports with fiber mode and max speed is 10G
  *      defined as 0 : disable AN
  *      defined as 1 : CL73
  */
#define CFG_CONFIG_10G_PORT_AN  (0)

/*
  *  CFG_TSCF_INTERFACE : TSCF_INTERFACE_SGMII/TSCF_INTERFACE_XFI/TSCF_INTERFACE_FIBER
  */
#define CFG_TSCF_INTERFACE   (TSCF_INTERFACE_XFI)

/*
  *  CFG_TSCE_INTERFACE : TSCE_INTERFACE_SGMII/TSCE_INTERFACE_XFI/TSCE_INTERFACE_FIBER/TSCE_INTERFACE_XAUI
  */
#define CFG_TSCE_INTERFACE   (TSCE_INTERFACE_XFI)

/*
  *  CFG_QTC_INTERFACE : QTC_INTERFACE_QSGMII/QTC_INTERFACE_SGMII/QTC_INTERFACE_FIBER
  */
#define CFG_QTC_INTERFACE    (QTC_INTERFACE_QSGMII)

/*
  *  CFG_SGMIIPX4_INTERFACE : SGMIIPX4_INTERFACE_SGMII/SGMIIPX4_INTERFACE_FIBER
  */
#define CFG_SGMIIPX4_INTERFACE   (SGMIIPX4_INTERFACE_SGMII)

/*
 *  CFG_INTR_INCLUDED
 *      undefined : exclude interrupt system.
 *      defined: include interrupt system.
 */
#define CFG_INTR_INCLUDED

/*
 *  CFG_POLLED_INTR: Enable polled irq and disable true irq.
 */
#define CFG_POLLED_INTR   (1)

#endif /* _CONFIG_H_ */
