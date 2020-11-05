/*
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */
#include "system.h"
#include "soc/port.h"
#include "utils/system.h"
#include "utils/net.h"

#ifdef CFG_SWITCH_LOOPDETECT_INCLUDED

/* #define SP_LOOP_DETECT_DEBUG */
/* Interval in us for timer callback routines. */
#define LOOP_DETECT_INTERVAL     (1000000UL)   /* 1 second in us. */

/* Interval in system tick to check if loop is removed. */
#define LOOP_REMOVED_INTERVAL    (2000UL)     /* 2 seconds in ms. */

#define DISCOVERY_PKTBUF_LEN      (68)

/* Discoery packet format. */
typedef struct discovery_packet_s {
    uint32 DA_upper;
    uint16 DA_lower;
    uint16 SA_upper;
    uint32 SA_lower;
    uint16 ether_type;
    uint16 pading;
    uint32 module_id_0;
    uint32 module_id_1;
    uint32 module_id_2;
} discovery_packet_t;

static uint8 *packet_buffer = NULL;

static uint8 discovery_indicator;
static soc_tx_packet_t *spkt;
static uint32 loop_timer[BCM5354X_PORT_MAX+1];
static uint32 loop_counter[BCM5354X_PORT_MAX+1][3];
static BOOL loop_status[BCM5354X_PORT_MAX+1];
static uint8 loopdetect_status = FALSE;
static uint8 loopdetect_phy_led1_mode = 0x3;
static uint8 loopdetect_phy_led2_mode = 0xA;
static uint16 loopdetect_phy_led_select = 0x180;
extern uint32 _getticks(void);

/*
 *  Function : bcm533xx_loopdetect_task
 *
 *  Purpose :
 *      Check per-port discovery packet counter.
 */

/* Access to shadowed registers at offset 0x1c */
#define REG_1C_SEL(_s)                  ((_s) << 10)
#define REG_1C_WR(_s,_v)                (REG_1C_SEL(_s) | (_v) | 0x8000)

/* Access expansion registers at offset 0x15 */
#define MII_EXP_MAP_REG(_r)             ((_r) | 0x0f00)
#define MII_EXP_UNMAP                   (0)

/*
 * Non-standard MII Registers
 */
#define MII_ECR_REG             0x10 /* MII Extended Control Register */
#define MII_EXP_REG             0x15 /* MII Expansion registers */
#define MII_EXP_SEL             0x17 /* MII Expansion register select */
#define MII_TEST1_REG           0x1e /* MII Test Register 1 */
#define RDB_LED_MATRIX          0x1f /* LED matrix mode */

STATICFN void
bcm5354x_loopdetect_task(void *param)
{
    uint8 i, link;
    uint32 counter_idx;
    uint32 val;

	FP_POLICY_TABLEm_t fp_policy_table;
    FP_COUNTER_TABLEm_t fp_counter_table;

    if (FALSE == loopdetect_status) {
        return;
    }

    discovery_indicator++;

    if (discovery_indicator & 0x1) {
        /* Send discovery packet every 2 seconds */
        bcm5354x_tx(0, spkt);
    } else {
        /* Check discovery FP counter for each port */
        for (i = BCM5354X_LPORT_MIN; i <= BCM5354X_LPORT_MAX ; i++) {
            bcm5354x_link_status(0, i, &link);

            READ_FP_POLICY_TABLEm(0,LOOP_COUNT_IDX - BCM5354X_LPORT_MIN + (i), fp_policy_table);                          

            counter_idx = FP_POLICY_TABLEm_COUNTER_INDEXf_GET(fp_policy_table);

            if (link) {
                /* link up */
                if (FP_POLICY_TABLEm_COUNTER_MODEf_GET(fp_policy_table) == 1) {
                    READ_FP_COUNTER_TABLEm(0, (LOOP_COUNT_IDX  + (2 * counter_idx)), fp_counter_table);
                } else {
                    READ_FP_COUNTER_TABLEm(0, (LOOP_COUNT_IDX  + (2 * counter_idx) + 1), fp_counter_table);
                }

                /* Compared counter[0] is enough for packet/byte */
                if (FP_COUNTER_TABLEm_PACKET_COUNTERf_GET(fp_counter_table) != loop_counter[i][0]) {
                    
                    if (!loop_status[i]) {
                        loop_status[i] = TRUE;
#if 0
                        /* Set bicolor selector 0 and 1 as Blink LED (0xA) */
                        phy_reg_write(i, MII_EXP_SEL, 0xF04);
                        phy_reg_write(i, MII_EXP_REG, 0x1AA | (1 << 10));
                        phy_reg_write(i, MII_EXP_SEL, 0x0);

                        /* set 1 sec blink rate */
                        phy_reg_write(i, MII_EXP_SEL, 0xF06);
                        phy_reg_write(i, MII_EXP_REG, 0x1| (1 << 5));
                        phy_reg_write(i, MII_EXP_SEL, 0x0);

                        /* Set LED Modes and Control, LED1 = LED2 = bicolor */
                        phy_reg_write(i, 0x1C, REG_1C_WR(0x0d, (0xA & 0xf) |
                                     ((0xA & 0xf) << 4)));
#endif
                        /* Update LED status */
                        val = READCSR(LED_PORT_STATUS_OFFSET(SOC_PORT_L2P_MAPPING(i)));
                        val |= 0x02;
                        WRITECSR(LED_PORT_STATUS_OFFSET(SOC_PORT_L2P_MAPPING(i)), val);
                        sal_printf("Loop found on port %d\n", i);
                    }
                    loop_counter[i][0] = FP_COUNTER_TABLEm_PACKET_COUNTERf_GET(fp_counter_table);
                    loop_timer[i] = sal_get_ticks();
                } else {
                    /*
                     * Assume loop has been removed if counter does not increment
                     * after LOOP_REMOVED_INTERVAL.
                     */
                    if (loop_status[i] &&
                        SAL_TIME_EXPIRED(loop_timer[i], LOOP_REMOVED_INTERVAL)) {
                        loop_status[i] = FALSE;
#if 0
                        /* Set bicolor selector 1 as Link LED (default) */
                        phy_reg_write(i, 0x17, 0xF04);
                        phy_reg_write(i, 0x15, loopdetect_phy_led_select);
                        phy_reg_write(i, 0x17, 0x0);
                        /* Set LED Modes and Control, LED2 = bicolor & LED1 = ACT (default) */
                        val = 0xB400 | 
                              (loopdetect_phy_led1_mode & 0xf) |
                              ((loopdetect_phy_led2_mode & 0xf) << 4) ;
                        phy_reg_write(i, 0x1C, val);
#endif
                        val = READCSR(LED_PORT_STATUS_OFFSET(SOC_PORT_L2P_MAPPING(i)));
                        val &= 0xFD;
                        WRITECSR(LED_PORT_STATUS_OFFSET(SOC_PORT_L2P_MAPPING(i)), val);
                        sal_printf("Loop removed on port %d\n", i);
                    }
                } /* counter changed */
            } else {
                /* link down */
                if (loop_status[i] == TRUE) {
                    /* Clear loop status when link up -> down */
                    loop_status[i] = FALSE;
					

#if 0
                    /* Set bicolor selector 1 as Link LED (default) */
                    phy_reg_write(i, 0x17, 0xF04);
                    phy_reg_write(i, 0x15, loopdetect_phy_led_select);
                    phy_reg_write(i, 0x17, 0x0);
                    /* Set LED Modes and Control, LED2 = bicolor & LED1 = ACT (default) */
                    val = 0xB400 | 
                          (loopdetect_phy_led1_mode & 0xf) |
                          ((loopdetect_phy_led2_mode & 0xf) << 4) ;
                    phy_reg_write(i, 0x1C, val);
#endif
                    val = READCSR(LED_PORT_STATUS_OFFSET(SOC_PORT_L2P_MAPPING(i)));
                    val &= 0xFD;
                    WRITECSR(LED_PORT_STATUS_OFFSET(SOC_PORT_L2P_MAPPING(i)), val);                    
                    sal_printf("Loop removed on port %d\n", i);
                }
            }
        } /* for each port */
    }
}

STATICFN void
loopdetect_cbk(struct soc_tx_packet_s *pkt)
{

}

STATICFN void
_bcm5354x_loop_detect_fp_init(void)
{
#ifdef CFG_SWITCH_LAG_INCLUDED
    pbmp_t lag_pbmp[BOARD_MAX_NUM_OF_LAG];
    int lagid, lag_lport;
#endif /* CFG_SWITCH_LAG_INCLUDED */
    uint8 port_based_vlan = FALSE;

    int lport;
    discovery_packet_t *pd;
    pbmp_t all_mask, lpbmp;

    uint32 temp_val, temp[4];


	EGR_MASKm_t egr_mask;
    IFP_REDIRECTION_PROFILEm_t ifp_redirection_profile;
	FP_PORT_FIELD_SELm_t fp_port_field_sel;
#ifdef CFG_SWITCH_LAG_INCLUDED
    VLAN_CTRLr_t vlan_ctrl;
    TRUNK_BITMAPm_t trunk_bitmap;
#endif
    FP_TCAMm_t fp_tcam;
	FP_GLOBAL_MASK_TCAMm_t fp_global_mask_tcam;
    FP_POLICY_TABLEm_t fp_policy_table;
    FP_UDF_OFFSETm_t fp_udf_offset;
    GLP_t glp;

    uint32 udf_mask[4] = {0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000FFFF};

    pd = (discovery_packet_t *) packet_buffer;

    temp[0]  = (hton32(pd->module_id_2) << 16);
    temp[1]  = (hton32(pd->module_id_1) << 16) | (hton32(pd->module_id_2) >> 16);
    temp[2]  = (hton32(pd->module_id_0) << 16) | (hton32(pd->module_id_1) >> 16);
    temp[3]  = (hton32(pd->module_id_0) >> 16);

        
    for (lport = 0; lport <= BCM5354X_LPORT_MAX; lport++) {

        READ_FP_PORT_FIELD_SELm(0, lport, fp_port_field_sel);
        /* Slice 3, F1/F2/F3 */
        FP_PORT_FIELD_SELm_SLICE3_F1f_SET(fp_port_field_sel, 0x4);
        FP_PORT_FIELD_SELm_SLICE3_F2f_SET(fp_port_field_sel, 0x8);
        FP_PORT_FIELD_SELm_SLICE3_F3f_SET(fp_port_field_sel, 0xb);      
        WRITE_FP_PORT_FIELD_SELm(0, lport, fp_port_field_sel);          
    }

#ifdef CFG_SWITCH_LAG_INCLUDED
    /* The USE_LEARN_VID and LEARN_VID will be set to '1' in VLAN_CTRL
     * for port based vlan */
    READ_VLAN_CTRLr(0, vlan_ctrl);
    if (VLAN_CTRLr_USE_LEARN_VIDf_GET(vlan_ctrl) == 1 &&
        VLAN_CTRLr_LEARN_VIDf_GET(vlan_ctrl) == 1)
    {
        port_based_vlan = TRUE;
    }

    for (lagid = 0; lagid < BOARD_MAX_NUM_OF_LAG; lagid++) {
        READ_TRUNK_BITMAPm(0, lagid, trunk_bitmap);
        PBMP_CLEAR(lag_pbmp[lagid]);
        PBMP_WORD_SET(lag_pbmp[lagid], 0, TRUNK_BITMAPm_TRUNK_BITMAPf_GET(trunk_bitmap));
    }
#endif /* CFG_SWITCH_LAG_INCLUDED */


    for (lport = BCM5354X_LPORT_MIN; lport <= BCM5354X_LPORT_MAX; lport++) {
        /* Update port id. */
        GLP_CLR(glp);
        GLP_PORTf_SET(glp, lport);


#ifdef CFG_SWITCH_LAG_INCLUDED
        /*  Revise the source tgid qualify if the port is trunk port */
        for (lagid = 0; lagid < BOARD_MAX_NUM_OF_LAG; lagid++) {
            if (PBMP_MEMBER(lag_pbmp[lagid], lport)) {
				GLP_CLR(glp);
				GLP_Tf_SET(glp, 1);
				GLP_TGIDf_SET(glp, lagid);
            }
        }
#endif /* CFG_SWITCH_LAG_INCLUDED */


	   FP_TCAMm_CLR(fp_tcam);	  
	   FP_TCAMm_F1_4_ETHERTYPEf_SET(fp_tcam, 0x8874);
	   FP_TCAMm_F1_4_ETHERTYPE_MASKf_SET(fp_tcam, 0xFFFFFFFF);
	   FP_TCAMm_F2_8_UDF1f_SET(fp_tcam, temp);
	   FP_TCAMm_F2_8_UDF1_MASKf_SET(fp_tcam, udf_mask);
	   FP_TCAMm_F3_11_SGLPf_SET(fp_tcam, GLP_GET(glp));
	   FP_TCAMm_F3_11_SGLP_MASKf_SET(fp_tcam, 0xFFFFFFFF);
	   FP_TCAMm_VALIDf_SET(fp_tcam, 3);
	
       PBMP_CLEAR(lpbmp);
       PBMP_PORT_ADD(lpbmp, lport);
       FP_GLOBAL_MASK_TCAMm_CLR(fp_global_mask_tcam);
	   FP_GLOBAL_MASK_TCAMm_IPBMf_SET(fp_global_mask_tcam, SOC_PBMP(lpbmp));
	   FP_GLOBAL_MASK_TCAMm_IPBM_MASKf_SET(fp_global_mask_tcam, SOC_PBMP(BCM5354X_ALL_PORTS_MASK));
	   FP_GLOBAL_MASK_TCAMm_VALIDf_SET(fp_global_mask_tcam, 1);

       WRITE_FP_TCAMm(0, LOOP_COUNT_IDX + (lport-BCM5354X_LPORT_MIN), fp_tcam);
       WRITE_FP_GLOBAL_MASK_TCAMm(0, LOOP_COUNT_IDX + (lport-BCM5354X_LPORT_MIN) , fp_global_mask_tcam);
	}

    /* Offset for ETHER II packets (N0 Tags/One Tag) */
    FP_UDF_OFFSETm_CLR(fp_udf_offset);
    FP_UDF_OFFSETm_UDF1_OFFSET3f_SET(fp_udf_offset, 7);
    FP_UDF_OFFSETm_UDF1_OFFSET2f_SET(fp_udf_offset, 6);
    FP_UDF_OFFSETm_UDF1_OFFSET1f_SET(fp_udf_offset, 5);
    FP_UDF_OFFSETm_UDF1_OFFSET0f_SET(fp_udf_offset, 4);
	/* No Tag*/
    WRITE_FP_UDF_OFFSETm(0, 12, fp_udf_offset);
    /* One Tag */
    WRITE_FP_UDF_OFFSETm(0, 140, fp_udf_offset);



	FP_POLICY_TABLEm_CLR(fp_policy_table);		  
	FP_POLICY_TABLEm_Y_DROPf_SET(fp_policy_table, 1);
    FP_POLICY_TABLEm_R_DROPf_SET(fp_policy_table, 1);
	FP_POLICY_TABLEm_G_DROPf_SET(fp_policy_table, 1);
	FP_POLICY_TABLEm_METER_PAIR_MODE_MODIFIERf_SET(fp_policy_table, 1);
	FP_POLICY_TABLEm_METER_SHARING_MODE_MODIFIERf_SET(fp_policy_table, 1);
	FP_POLICY_TABLEm_G_CHANGE_COS_OR_INT_PRIf_SET(fp_policy_table, 2);
	FP_POLICY_TABLEm_G_CHANGE_DSCP_TOSf_SET(fp_policy_table, 4);
	FP_POLICY_TABLEm_G_CHANGE_COS_OR_INT_PRIf_SET(fp_policy_table, 2);

    temp_val = 0;
    for (lport = BCM5354X_LPORT_MIN; lport <= BCM5354X_LPORT_MAX; lport++) {
        if (!(lport % 2)) {
            FP_POLICY_TABLEm_COUNTER_MODEf_SET(fp_policy_table, 1);
			FP_POLICY_TABLEm_COUNTER_INDEXf_SET(fp_policy_table, temp_val);

        } else {
            FP_POLICY_TABLEm_COUNTER_MODEf_SET(fp_policy_table, 2);
			FP_POLICY_TABLEm_COUNTER_INDEXf_SET(fp_policy_table, temp_val);
            temp_val++;
        }
        /* fp action is Drop, no need to assign redirection entry  */
		WRITE_FP_POLICY_TABLEm(0, LOOP_COUNT_IDX + (lport-BCM5354X_LPORT_MIN), fp_policy_table);
    }

	 /* starting from CPU port */
	 for (lport = 0; lport <= BCM5354X_LPORT_MAX; lport++) {

		 if ((lport > 0) && (lport < BCM5354X_LPORT_MIN)) {
			 continue;
		 }

        /* Update port id. */
        GLP_CLR(glp);
  	    GLP_PORTf_SET(glp, lport);

#ifdef CFG_SWITCH_LAG_INCLUDED
        /*  Revise the source tgid qualify if the port is trunk port */
        for (lagid = 0; lagid < BOARD_MAX_NUM_OF_LAG; lagid++) {
            if (PBMP_IS_NULL(lag_pbmp[lagid])) {
                continue;
            }
            if (PBMP_MEMBER(lag_pbmp[lagid], lport)) {
				GLP_CLR(glp);
				GLP_Tf_SET(glp, 1);
				GLP_TGIDf_SET(glp, lagid);
            }
        }
#endif /* CFG_SWITCH_LAG_INCLUDED */


        FP_TCAMm_CLR(fp_tcam);
        FP_TCAMm_F1_4_ETHERTYPEf_SET(fp_tcam, 0x8874);
        FP_TCAMm_F1_4_ETHERTYPE_MASKf_SET(fp_tcam, 0xFFFFFFFF);  
		FP_TCAMm_F3_11_SGLPf_SET(fp_tcam, GLP_GET(glp));
        FP_TCAMm_F3_11_SGLP_MASKf_SET(fp_tcam, 0xFFFFFFFF);
        FP_TCAMm_VALIDf_SET(fp_tcam, 3);
        WRITE_FP_TCAMm(0,LOOP_REDIRECT_IDX + lport,fp_tcam);

        PBMP_CLEAR(lpbmp);
        PBMP_PORT_ADD(lpbmp, lport);
        FP_GLOBAL_MASK_TCAMm_CLR(fp_global_mask_tcam);
        FP_GLOBAL_MASK_TCAMm_IPBMf_SET(fp_global_mask_tcam, SOC_PBMP(lpbmp));
        FP_GLOBAL_MASK_TCAMm_IPBM_MASKf_SET(fp_global_mask_tcam, SOC_PBMP(BCM5354X_ALL_PORTS_MASK));
        FP_GLOBAL_MASK_TCAMm_VALIDf_SET(fp_global_mask_tcam, 1);
        WRITE_FP_GLOBAL_MASK_TCAMm(0,LOOP_REDIRECT_IDX + lport,fp_global_mask_tcam);

        PBMP_ASSIGN(all_mask, BCM5354X_ALL_PORTS_MASK);
        /* Remove ports for PVLAN setting */
        if (port_based_vlan == TRUE) {
            READ_EGR_MASKm(0, lport, egr_mask);
            PBMP_CLEAR(lpbmp);
            PBMP_WORD_SET(lpbmp, 0, EGR_MASKm_EGRESS_MASKf_GET(egr_mask));
            PBMP_REMOVE(all_mask, lpbmp);
        }
#ifdef CFG_SWITCH_LAG_INCLUDED
		/*	Revise the all_mask based on trunk port bitmap */
        for (lagid = 0; lagid < BOARD_MAX_NUM_OF_LAG; lagid++) {
		     if (PBMP_NOT_NULL(lag_pbmp[lagid]) && PBMP_MEMBER(lag_pbmp[lagid], lport)) {
			     PBMP_REMOVE(all_mask, lag_pbmp[lagid]);
                 PBMP_ITER(lag_pbmp[lagid], lag_lport) {
                     PBMP_PORT_ADD(all_mask, lag_lport);
                     break;
                 }
			}
        }
#endif /* CFG_SWITCH_LAG_INCLUDED */
        
        /* Update redirect pbmp to exclude src port. */        
        PBMP_PORT_REMOVE(all_mask, lport);
        /* Update redirect pbmp to exclude src port(cpu entry). */
        IFP_REDIRECTION_PROFILEm_CLR(ifp_redirection_profile);
        IFP_REDIRECTION_PROFILEm_BITMAPf_SET(ifp_redirection_profile, SOC_PBMP(all_mask));
        WRITE_IFP_REDIRECTION_PROFILEm(0, lport, ifp_redirection_profile);
        
        /* starting from index 0 */
        FP_POLICY_TABLEm_CLR(fp_policy_table);        
        FP_POLICY_TABLEm_REDIRECTION_PROFILE_INDEXf_SET(fp_policy_table, lport);
		FP_POLICY_TABLEm_G_PACKET_REDIRECTIONf_SET(fp_policy_table, 3);
        FP_POLICY_TABLEm_G_CHANGE_COS_OR_INT_PRIf_SET(fp_policy_table, 5);
		FP_POLICY_TABLEm_R_CHANGE_COS_OR_INT_PRIf_SET(fp_policy_table, 5);
        FP_POLICY_TABLEm_METER_SHARING_MODE_MODIFIERf_SET(fp_policy_table, 1);
        FP_POLICY_TABLEm_METER_PAIR_MODE_MODIFIERf_SET(fp_policy_table, 1);
        FP_POLICY_TABLEm_Y_CHANGE_COS_OR_INT_PRIf_SET(fp_policy_table, 5);
	    WRITE_FP_POLICY_TABLEm(0, LOOP_REDIRECT_IDX + lport, fp_policy_table);
    }
    discovery_indicator = 0;



}

STATICFN void
_bcm5354x_loop_detect_init(uint16 port)
{
    uint8 sa[6] = { 0x01, 0x80, 0xC2, 0x0, 0x0, 0x1 };
    uint8 mac_addr[6];
    discovery_packet_t *pd;
    uint8 *p;
    int i;
    uint32 counter_idx;
    uint32 (*funcptr)(void) = (uint32 (*)(void))_getticks;

    FP_POLICY_TABLEm_t fp_policy_table;
    FP_COUNTER_TABLEm_t fp_counter_table;

    packet_buffer = sal_dma_malloc(DISCOVERY_PKTBUF_LEN);

    sal_memset(packet_buffer, 0x0, DISCOVERY_PKTBUF_LEN);

    p = packet_buffer;
    /* Broadcast DA */
    for (i = 0; i < 6; i++) {
        *p++ = 0xFF;
    }
    for (i = 0; i < 6; i++) {
        *p++ = sa[i];
    }
    /* Ether type = 0x8874 */
    *(uint16 *)p = HTON16(0x8874);

    pd = (discovery_packet_t *)packet_buffer;
    get_system_mac(mac_addr);
    sal_memcpy(&pd->module_id_0, mac_addr, 6);
    sal_memcpy(&packet_buffer[22], &port, 2);

    pd->module_id_2 = (*funcptr)();
#ifdef SP_LOOP_DETECT_DEBUG
    sal_printf("module id 0 = 0x%08X\n", pd->module_id_0);
    sal_printf("module id 1 = 0x%08X\n", pd->module_id_1);
    sal_printf("module id 2 = 0x%08X\n", pd->module_id_2);
#endif

    spkt = (soc_tx_packet_t *)sal_malloc(sizeof(soc_tx_packet_t));
    if (spkt == NULL) {
        sal_printf("_bcm5354x_loop_detect_init: malloc failed!\n");
        return;
    }

    sal_memset(spkt, 0, sizeof(soc_tx_packet_t));
    spkt->buffer = packet_buffer;
    spkt->pktlen = DISCOVERY_PKTBUF_LEN;
    spkt->callback = loopdetect_cbk;
    _bcm5354x_loop_detect_fp_init();

    for (i = BCM5354X_LPORT_MIN; i <= BCM5354X_LPORT_MAX; i++) {
        loop_counter[i][0] = 0;
        loop_counter[i][1] = 0;
        loop_counter[i][2] = 0;
        loop_status[i] = FALSE;

        READ_FP_POLICY_TABLEm(0,LOOP_COUNT_IDX + (i - BCM5354X_LPORT_MIN), fp_policy_table);
        counter_idx = FP_POLICY_TABLEm_COUNTER_INDEXf_GET(fp_policy_table);
        FP_COUNTER_TABLEm_CLR(fp_counter_table);
        if (FP_POLICY_TABLEm_COUNTER_MODEf_GET(fp_policy_table) == 1) {            
            WRITE_FP_COUNTER_TABLEm(0, (LOOP_COUNT_IDX + (2 * counter_idx)), fp_counter_table);
        } else {
            WRITE_FP_COUNTER_TABLEm(0, (LOOP_COUNT_IDX + (2 * counter_idx) + 1), fp_counter_table);
        }
    }

    /* Register background process to detect loop */
    timer_add(bcm5354x_loopdetect_task, NULL, LOOP_DETECT_INTERVAL);
}

void
bcm5354x_loop_detect_init(void)
{
#ifdef CFG_VENDOR_CONFIG_SUPPORT_INCLUDED
    sal_config_uint8_get(SAL_CONFIG_PHY_LED1_MODE, &loopdetect_phy_led1_mode);
    sal_config_uint8_get(SAL_CONFIG_PHY_LED2_MODE, &loopdetect_phy_led2_mode);
    sal_config_uint16_get(SAL_CONFIG_PHY_LED_SELECT, &loopdetect_phy_led_select);
#endif 
    _bcm5354x_loop_detect_init(0xA);
}

void
bcm5354x_loop_detect_enable(BOOL enable)
{
    if (loopdetect_status == enable) {
        return;
    }

	if (!enable) {
        timer_remove(bcm5354x_loopdetect_task);
        if (spkt) {
            sal_free(spkt);
            spkt = (soc_tx_packet_t *)NULL;
        }
    } else {
        bcm5354x_loop_detect_init();
    }
    loopdetect_status = enable;
}

uint8
bcm5354x_loop_detect_status_get(void)
{
    return loopdetect_status;
}

#endif /* CFG_SWITCH_LOOPDETECT_INCLUDED */
