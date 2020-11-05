/*
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 *
 * XGS internal PHY read function with AER support.
 *
 * This function accepts a 32-bit PHY register address and will
 * properly configure clause 45 DEVAD and XAUI lane access.
 * Please see phymod_reg.h for additional information.
 */

#include <phy/phy_tsc_iblk.h>

#include <phymod/acc/phymod_tsc_iblk.h>

int
phymod_tsc_iblk_write(const phymod_access_t *pa, uint32_t addr, uint32_t data)
{
    int ioerr;
    phy_ctrl_t *pc;
    uint32_t lane, lane_map;
    uint32_t rdata, wr_mask;

    wr_mask = (data >> 16);
    if (wr_mask) {
        /* Support write mask */
        phymod_tsc_iblk_read(pa, addr, &rdata);
        data = (rdata & ~wr_mask) | (data & wr_mask);
        data &= 0xffff;
    }

    pc = (phy_ctrl_t *)(pa->user_acc);

    lane_map = PHYMOD_ACC_LANE_MASK(pa);
    if (lane_map) {
        if (lane_map == 0x3) {
            PHY_CTRL_LANE(pc) = PHY_TSC_IBLK_MCAST01;
        } else if (lane_map == 0xc) {
            PHY_CTRL_LANE(pc) = PHY_TSC_IBLK_MCAST23;
        } else if (lane_map == 0xf) {
            PHY_CTRL_LANE(pc) = PHY_TSC_IBLK_BCAST;
        } else if (lane_map & 0xffff) {
            lane = -1;
            while (lane_map) {
                lane++;
                lane_map >>= 1;
            }
            PHY_CTRL_LANE(pc) = lane;
        }
    }

    PHY_CTRL_LANE(pc) |= PHY_LANE_VALID;

    ioerr = phy_tsc_iblk_mdio_write(pc, addr, data);
    
    /* Clear LANE to zero */
    PHY_CTRL_LANE(pc) = 0;
    
    return ioerr;
}