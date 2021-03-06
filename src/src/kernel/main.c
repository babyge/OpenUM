/*
 * $Id: main.c,v 1.43 Broadcom SDK $
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include "system.h"
#include "appl/cli.h"
#include "appl/persistence.h"
#include "utils/system.h"
#include "utils/net.h"
#include <sal.h>
#ifdef __C51__
#ifdef CODE_USERCLASS
#pragma userclass (code = init)
#endif /* CODE_USERCLASS */
#ifdef XDATA_USERCLASS
#pragma userclass (xdata = init)
#endif /* XDATA_USERCLASS */
#endif /* __C51__ */



/* Initialization routines called by main */
extern void board_early_init(void) REENTRANT;
extern sys_error_t board_init(void) REENTRANT;
extern void board_late_init(void) REENTRANT;
extern void sal_init(void) REENTRANT;
extern void background_init(void) REENTRANT;
extern void sys_timer_init(void) REENTRANT;
extern void sys_linkchange_init(void) REENTRANT;
extern void sys_rx_init(void) REENTRANT;
extern void sys_tx_init(void) REENTRANT;
extern void appl_init(void) REENTRANT;
#ifdef CFG_ENHANCED_POWER_SAVING
extern void power_management_init(void);
#endif /* CFG_ENHANCED_POWER_SAVING */
extern void ui_pcm_init(void);

/* Forwards */
#if defined(__ARM__) || defined(__LINUX__)
int main(void);
#else
void main(void);
#endif

#if (CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__))
/* RX buffers (it's here so we can customize addr/size later in new code) */
#if defined(__MIPS__) && CFG_RAMAPP
STATIC uint8 rx_buffers[DEFAULT_RX_BUFFER_COUNT][DEFAULT_RX_BUFFER_SIZE] __attribute__ ((aligned (16)));
#elif defined(__LINUX__)
uint8* rx_buffers[DEFAULT_RX_BUFFER_COUNT];
#elif defined(__ARM__)
uint8 rx_buffers[DEFAULT_RX_BUFFER_COUNT][DEFAULT_RX_BUFFER_SIZE] __attribute__ ((section(".packet_buf"), aligned (32)));
#else
STATIC uint8 rx_buffers[DEFAULT_RX_BUFFER_COUNT][DEFAULT_RX_BUFFER_SIZE];
#endif
#endif /* CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__) */


/* Function:
 *   main
 * Description:
 *   C startup function.
 * Parameters:
 *   None
 * Returns:
 *   None
 */
#if defined(__ARM__) || defined(__LINUX__)
int
main(void)
#else
void
main(void)
#endif
{
#if (CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__))
    uint8 i;
#endif /* CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__) */

#if defined(__LINUX__)
   if (sal_bde_init()) {
   	   sal_printf("bde module init fail\n");
   }
#endif
    board_early_init();

    sal_init();


    background_init();
#if CFG_TIMER_CALLBACK_SUPPORT
    sys_timer_init();
#endif /* CFG_TIMER_CALLBACK_SUPPORT */


#if CFG_LINKCHANGE_CALLBACK_SUPPORT
    sys_linkchange_init();
#endif /* CFG_LINKCHANGE_CALLBACK_SUPPORT */

    system_utils_init();

#if CFG_UIP_STACK_ENABLED
    net_utils_init();
#endif /* CFG_UIP_STACK_ENABLED */

    if (board_init() == SYS_OK) {
#if (CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__))
#if defined(__LINUX__)
     for (i=0; i<DEFAULT_RX_BUFFER_COUNT; i++) {
	 	rx_buffers[i] = sal_dma_malloc(DEFAULT_RX_BUFFER_SIZE);
     }
#endif
#endif
#if (CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__))
        sys_tx_init();
        sys_rx_init();
        for(i=0; i<DEFAULT_RX_BUFFER_COUNT; i++) {
            sys_rx_add_buffer(rx_buffers[i], DEFAULT_RX_BUFFER_SIZE);
        }
#endif /* CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__) */

        appl_init();

#if CFG_ENHANCED_POWER_SAVING
        power_management_init();
#endif /* CFG_ENHANCED_POWER_SAVING */

#if CFG_PERSISTENCE_SUPPORT_ENABLED

        persistence_init();

        /*
         * Load current settings or factory defaults (if settings are invalid)
         */
        if (persistence_validate_current_settings()) {

            /*
             * If all current settins are valid, just load them.
             */
            persistence_load_all_current_settings();

        } else {

            /*
             * Part or all of data in current settings are not valid:
             * use factory defaults for the invalid items.
             * First we load factory default for all items.
             */
#if CFG_CONSOLE_ENABLED
            sal_printf("Some of current saved settings are invalid. "
                       "Loading factory defaults.....\n");
#endif /* CFG_CONSOLE_ENABLED */
            persistence_restore_factory_defaults();

            /*
             * Then load current settings for valid items.
             */
            persistence_load_all_current_settings();

            /*
             * Loading done; save to flash (current settings)
             */
            persistence_save_all_current_settings();
        }
#endif /* CFG_PERSISTENCE_SUPPORT_ENABLED */

#if defined(__UMDUMB__)
    board_vlan_type_set(VT_PORT_BASED);
    board_qos_type_set(QT_DOT1P_PRIORITY);
#endif

        board_late_init();
    } else {
        /*
         * FIXME:
         *
         * To remove this "else" block when device init is ready.
 */
        appl_init();
        board_late_init();
    }
#ifdef CFG_PCM_SUPPORT_INCLUDED
    ui_pcm_init();
#endif
#if CFG_CLI_ENABLED
    cli();
#else
    for(;;) POLL();
#endif
#ifdef __ARM__
    return 0;
#endif
}

