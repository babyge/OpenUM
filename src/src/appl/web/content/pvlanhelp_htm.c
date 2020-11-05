/*
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

/***** GENERATED FILE; DO NOT EDIT. *****/

#include "appl/ssp.h"

static RES_CONST_DECL unsigned char CODE _text0000[] = {
    0x3c, 0x21, 0x44, 0x4f, 0x43, 0x54, 0x59, 0x50,      /* <!DOCTYP */
    0x45, 0x20, 0x48, 0x54, 0x4d, 0x4c, 0x20, 0x50,      /* E HTML P */
    0x55, 0x42, 0x4c, 0x49, 0x43, 0x20, 0x22, 0x2d,      /* UBLIC "- */
    0x2f, 0x2f, 0x57, 0x33, 0x43, 0x2f, 0x2f, 0x44,      /* //W3C//D */
    0x54, 0x44, 0x20, 0x48, 0x54, 0x4d, 0x4c, 0x20,      /* TD HTML  */
    0x34, 0x2e, 0x30, 0x31, 0x20, 0x54, 0x72, 0x61,      /* 4.01 Tra */
    0x6e, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61,      /* nsitiona */
    0x6c, 0x2f, 0x2f, 0x45, 0x4e, 0x22, 0x3e, 0x0a,      /* l//EN">. */
    0x3c, 0x48, 0x54, 0x4d, 0x4c, 0x3e, 0x3c, 0x48,      /* <HTML><H */
    0x45, 0x41, 0x44, 0x3e, 0x3c, 0x54, 0x49, 0x54,      /* EAD><TIT */
    0x4c, 0x45, 0x3e, 0x50, 0x4f, 0x52, 0x54, 0x20,      /* LE>PORT  */
    0x42, 0x41, 0x53, 0x45, 0x20, 0x56, 0x4c, 0x41,      /* BASE VLA */
    0x4e, 0x20, 0x48, 0x45, 0x4c, 0x50, 0x3c, 0x2f,      /* N HELP</ */
    0x54, 0x49, 0x54, 0x4c, 0x45, 0x3e, 0x0a, 0x3c,      /* TITLE>.< */
    0x4d, 0x45, 0x54, 0x41, 0x20, 0x68, 0x74, 0x74,      /* META htt */
    0x70, 0x2d, 0x65, 0x71, 0x75, 0x69, 0x76, 0x3d,      /* p-equiv= */
    0x22, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74,      /* "Content */
    0x2d, 0x54, 0x79, 0x70, 0x65, 0x22, 0x20, 0x63,      /* -Type" c */
    0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x3d, 0x22,      /* ontent=" */
    0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d,      /* text/htm */
    0x6c, 0x3b, 0x20, 0x63, 0x68, 0x61, 0x72, 0x73,      /* l; chars */
    0x65, 0x74, 0x3d, 0x55, 0x54, 0x46, 0x2d, 0x38,      /* et=UTF-8 */
    0x22, 0x3e, 0x20, 0x0a, 0x3c, 0x4c, 0x49, 0x4e,      /* "> .<LIN */
    0x4b, 0x20, 0x68, 0x72, 0x65, 0x66, 0x3d, 0x22,      /* K href=" */
    0x66, 0x6f, 0x72, 0x6d, 0x2e, 0x63, 0x73, 0x73,      /* form.css */
    0x22, 0x20, 0x72, 0x65, 0x6c, 0x3d, 0x73, 0x74,      /* " rel=st */
    0x79, 0x6c, 0x65, 0x73, 0x68, 0x65, 0x65, 0x74,      /* ylesheet */
    0x20, 0x74, 0x79, 0x70, 0x65, 0x3d, 0x22, 0x74,      /*  type="t */
    0x65, 0x78, 0x74, 0x2f, 0x63, 0x73, 0x73, 0x22,      /* ext/css" */
    0x3e, 0x0a, 0x0a, 0x3c, 0x2f, 0x48, 0x45, 0x41,      /* >..</HEA */
    0x44, 0x3e, 0x0a, 0x3c, 0x42, 0x4f, 0x44, 0x59,      /* D>.<BODY */
    0x3e, 0x0a, 0x0a, 0x3c, 0x66, 0x6f, 0x6e, 0x74,      /* >..<font */
    0x20, 0x73, 0x69, 0x7a, 0x65, 0x3d, 0x34, 0x3e,      /*  size=4> */
    0x3c, 0x42, 0x3e, 0x47, 0x65, 0x74, 0x74, 0x69,      /* <B>Getti */
    0x6e, 0x67, 0x20, 0x73, 0x74, 0x61, 0x72, 0x74,      /* ng start */
    0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20,      /* ed with  */
    0x50, 0x6f, 0x72, 0x74, 0x2d, 0x42, 0x61, 0x73,      /* Port-Bas */
    0x65, 0x64, 0x20, 0x50, 0x72, 0x69, 0x76, 0x61,      /* ed Priva */
    0x74, 0x65, 0x20, 0x56, 0x4c, 0x41, 0x4e, 0x3c,      /* te VLAN< */
    0x2f, 0x42, 0x3e, 0x3c, 0x2f, 0x66, 0x6f, 0x6e,      /* /B></fon */
    0x74, 0x3e, 0x0a, 0x3c, 0x42, 0x52, 0x3e, 0x3c,      /* t>.<BR>< */
    0x42, 0x52, 0x3e, 0x0a, 0x0a, 0x3c, 0x42, 0x3e,      /* BR>..<B> */
    0x41, 0x64, 0x64, 0x20, 0x56, 0x4c, 0x41, 0x4e,      /* Add VLAN */
    0x3c, 0x2f, 0x42, 0x3e, 0x20, 0x41, 0x64, 0x64,      /* </B> Add */
    0x20, 0x61, 0x20, 0x6e, 0x65, 0x77, 0x20, 0x65,      /*  a new e */
    0x6e, 0x74, 0x72, 0x79, 0x20, 0x6f, 0x66, 0x20,      /* ntry of  */
    0x70, 0x6f, 0x72, 0x74, 0x20, 0x62, 0x61, 0x73,      /* port bas */
    0x65, 0x64, 0x20, 0x56, 0x4c, 0x41, 0x4e, 0x20,      /* ed VLAN  */
    0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x68, 0x65,      /* with the */
    0x20, 0x64, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70,      /*  descrip */
    0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6e, 0x61, 0x6d,      /* tion nam */
    0x65, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x70, 0x6f,      /* e and po */
    0x72, 0x74, 0x20, 0x6d, 0x65, 0x6d, 0x62, 0x65,      /* rt membe */
    0x72, 0x73, 0x68, 0x69, 0x70, 0x2e, 0x3c, 0x42,      /* rship.<B */
    0x52, 0x3e, 0x3c, 0x42, 0x52, 0x3e, 0x0a, 0x3c,      /* R><BR>.< */
    0x42, 0x52, 0x3e, 0x0a, 0x0a, 0x3c, 0x42, 0x3e,      /* BR>..<B> */
    0x49, 0x44, 0x3c, 0x2f, 0x42, 0x3e, 0x20, 0x69,      /* ID</B> i */
    0x6e, 0x64, 0x69, 0x63, 0x61, 0x74, 0x65, 0x73,      /* ndicates */
    0x20, 0x74, 0x68, 0x65, 0x20, 0x70, 0x6f, 0x72,      /*  the por */
    0x74, 0x20, 0x62, 0x61, 0x73, 0x65, 0x64, 0x20,      /* t based  */
    0x70, 0x72, 0x69, 0x76, 0x61, 0x74, 0x65, 0x20,      /* private  */
    0x56, 0x4c, 0x41, 0x4e, 0x20, 0x49, 0x44, 0x20,      /* VLAN ID  */
    0x74, 0x6f, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72,      /* to contr */
    0x6f, 0x6c, 0x2e, 0x0a, 0x3c, 0x42, 0x52, 0x3e,      /* ol..<BR> */
    0x3c, 0x42, 0x52, 0x3e, 0x0a, 0x3c, 0x42, 0x3e,      /* <BR>.<B> */
    0x4d, 0x65, 0x6d, 0x62, 0x65, 0x72, 0x3c, 0x2f,      /* Member</ */
    0x42, 0x3e, 0x20, 0x69, 0x6e, 0x64, 0x69, 0x63,      /* B> indic */
    0x61, 0x74, 0x65, 0x73, 0x20, 0x74, 0x68, 0x65,      /* ates the */
    0x20, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x20,      /*  number  */
    0x6f, 0x66, 0x20, 0x6d, 0x65, 0x6d, 0x62, 0x65,      /* of membe */
    0x72, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x73, 0x20,      /* r ports  */
    0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x70,      /* of the p */
    0x72, 0x69, 0x76, 0x61, 0x74, 0x65, 0x20, 0x56,      /* rivate V */
    0x4c, 0x41, 0x4e, 0x2e, 0x0a, 0x3c, 0x42, 0x52,      /* LAN..<BR */
    0x3e, 0x3c, 0x42, 0x52, 0x3e, 0x0a, 0x3c, 0x42,      /* ><BR>.<B */
    0x3e, 0x44, 0x65, 0x6c, 0x65, 0x74, 0x65, 0x3c,      /* >Delete< */
    0x2f, 0x42, 0x3e, 0x20, 0x72, 0x65, 0x6d, 0x6f,      /* /B> remo */
    0x76, 0x65, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20,      /* ves the  */
    0x73, 0x70, 0x65, 0x63, 0x69, 0x66, 0x69, 0x65,      /* specifie */
    0x64, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x20, 0x62,      /* d port b */
    0x61, 0x73, 0x65, 0x64, 0x20, 0x70, 0x72, 0x69,      /* ased pri */
    0x76, 0x61, 0x74, 0x65, 0x20, 0x56, 0x4c, 0x41,      /* vate VLA */
    0x4e, 0x2e, 0x0a, 0x0a, 0x3c, 0x2f, 0x42, 0x4f,      /* N...</BO */
    0x44, 0x59, 0x3e, 0x3c, 0x2f, 0x48, 0x54, 0x4d,      /* DY></HTM */
    0x4c, 0x3e, 0x0a, 0x0a,                              /* L>..     */
};


RES_CONST_DECL SSP_DATA_ENTRY CODE sspfile_pvlanhelp_htm[] = {
    { 0x80, 0, 676, 0, 0, _text0000 },
};