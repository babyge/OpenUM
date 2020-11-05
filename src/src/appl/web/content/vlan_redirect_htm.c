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
    0x34, 0x2e, 0x30, 0x20, 0x54, 0x72, 0x61, 0x6e,      /* 4.0 Tran */
    0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c,      /* sitional */
    0x2f, 0x2f, 0x45, 0x4e, 0x22, 0x3e, 0x0a, 0x3c,      /* //EN">.< */
    0x48, 0x54, 0x4d, 0x4c, 0x3e, 0x3c, 0x48, 0x45,      /* HTML><HE */
    0x41, 0x44, 0x3e, 0x0a, 0x3c, 0x54, 0x49, 0x54,      /* AD>.<TIT */
    0x4c, 0x45, 0x3e, 0x56, 0x4c, 0x41, 0x4e, 0x20,      /* LE>VLAN  */
    0x52, 0x65, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74,      /* Redirect */
    0x3c, 0x2f, 0x54, 0x49, 0x54, 0x4c, 0x45, 0x3e,      /* </TITLE> */
    0x0a, 0x3c, 0x4d, 0x45, 0x54, 0x41, 0x20, 0x68,      /* .<META h */
    0x74, 0x74, 0x70, 0x2d, 0x65, 0x71, 0x75, 0x69,      /* ttp-equi */
    0x76, 0x3d, 0x22, 0x43, 0x6f, 0x6e, 0x74, 0x65,      /* v="Conte */
    0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x22,      /* nt-Type" */
    0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74,      /*  content */
    0x3d, 0x22, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x68,      /* ="text/h */
    0x74, 0x6d, 0x6c, 0x3b, 0x20, 0x63, 0x68, 0x61,      /* tml; cha */
    0x72, 0x73, 0x65, 0x74, 0x3d, 0x55, 0x54, 0x46,      /* rset=UTF */
    0x2d, 0x38, 0x22, 0x3e, 0x20, 0x0a, 0x3c, 0x6c,      /* -8"> .<l */
    0x69, 0x6e, 0x6b, 0x20, 0x68, 0x72, 0x65, 0x66,      /* ink href */
    0x3d, 0x22, 0x66, 0x6f, 0x72, 0x6d, 0x2e, 0x63,      /* ="form.c */
    0x73, 0x73, 0x22, 0x20, 0x72, 0x65, 0x6c, 0x3d,      /* ss" rel= */
    0x22, 0x73, 0x74, 0x79, 0x6c, 0x65, 0x73, 0x68,      /* "stylesh */
    0x65, 0x65, 0x74, 0x22, 0x20, 0x74, 0x79, 0x70,      /* eet" typ */
    0x65, 0x3d, 0x22, 0x74, 0x65, 0x78, 0x74, 0x2f,      /* e="text/ */
    0x63, 0x73, 0x73, 0x22, 0x3e, 0x0a, 0x3c, 0x53,      /* css">.<S */
    0x43, 0x52, 0x49, 0x50, 0x54, 0x20, 0x6c, 0x61,      /* CRIPT la */
    0x6e, 0x67, 0x75, 0x61, 0x67, 0x65, 0x3d, 0x4a,      /* nguage=J */
    0x61, 0x76, 0x61, 0x53, 0x63, 0x72, 0x69, 0x70,      /* avaScrip */
    0x74, 0x20, 0x74, 0x79, 0x70, 0x65, 0x3d, 0x22,      /* t type=" */
    0x74, 0x65, 0x78, 0x74, 0x2f, 0x6a, 0x61, 0x76,      /* text/jav */
    0x61, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x22,      /* ascript" */
    0x3e, 0x0a, 0x0a, 0x66, 0x75, 0x6e, 0x63, 0x74,      /* >..funct */
    0x69, 0x6f, 0x6e, 0x20, 0x6f, 0x6e, 0x5f, 0x6c,      /* ion on_l */
    0x6f, 0x61, 0x64, 0x28, 0x29, 0x0a, 0x7b, 0x0a,      /* oad().{. */
    0x20, 0x76, 0x61, 0x72, 0x20, 0x76, 0x6c, 0x61,      /*  var vla */
    0x6e, 0x5f, 0x74, 0x79, 0x70, 0x65, 0x20, 0x3d,      /* n_type = */
    0x20, 0x22,                                          /*  "       */
};

static RES_CONST_DECL unsigned char CODE _text0001[] = {
    0x22, 0x3b, 0x0a, 0x20, 0x69, 0x66, 0x20, 0x28,      /* ";. if ( */
    0x76, 0x6c, 0x61, 0x6e, 0x5f, 0x74, 0x79, 0x70,      /* vlan_typ */
    0x65, 0x20, 0x3d, 0x3d, 0x20, 0x22, 0x38, 0x30,      /* e == "80 */
    0x32, 0x31, 0x71, 0x22, 0x29, 0x20, 0x7b, 0x0a,      /* 21q") {. */
    0x20, 0x20, 0x20, 0x20, 0x6c, 0x6f, 0x63, 0x61,      /*     loca */
    0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x68, 0x72, 0x65,      /* tion.hre */
    0x66, 0x20, 0x3d, 0x20, 0x22, 0x76, 0x6c, 0x61,      /* f = "vla */
    0x6e, 0x6c, 0x69, 0x73, 0x74, 0x2e, 0x68, 0x74,      /* nlist.ht */
    0x6d, 0x22, 0x3b, 0x0a, 0x20, 0x7d, 0x20, 0x65,      /* m";. } e */
    0x6c, 0x73, 0x65, 0x20, 0x7b, 0x0a, 0x20, 0x20,      /* lse {.   */
    0x20, 0x20, 0x6c, 0x6f, 0x63, 0x61, 0x74, 0x69,      /*   locati */
    0x6f, 0x6e, 0x2e, 0x68, 0x72, 0x65, 0x66, 0x20,      /* on.href  */
    0x3d, 0x20, 0x22, 0x70, 0x76, 0x6c, 0x61, 0x6e,      /* = "pvlan */
    0x76, 0x69, 0x65, 0x77, 0x2e, 0x68, 0x74, 0x6d,      /* view.htm */
    0x22, 0x3b, 0x0a, 0x20, 0x7d, 0x0a, 0x20, 0x72,      /* ";. }. r */
    0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x66, 0x61,      /* eturn fa */
    0x6c, 0x73, 0x65, 0x3b, 0x0a, 0x7d, 0x0a, 0x3c,      /* lse;.}.< */
    0x2f, 0x53, 0x43, 0x52, 0x49, 0x50, 0x54, 0x3e,      /* /SCRIPT> */
    0x0a, 0x3c, 0x2f, 0x48, 0x45, 0x41, 0x44, 0x3e,      /* .</HEAD> */
    0x0a, 0x3c, 0x42, 0x4f, 0x44, 0x59, 0x20, 0x6f,      /* .<BODY o */
    0x6e, 0x4c, 0x6f, 0x61, 0x64, 0x3d, 0x22, 0x6f,      /* nLoad="o */
    0x6e, 0x5f, 0x6c, 0x6f, 0x61, 0x64, 0x28, 0x29,      /* n_load() */
    0x22, 0x3e, 0x0a, 0x3c, 0x2f, 0x42, 0x4f, 0x44,      /* ">.</BOD */
    0x59, 0x3e, 0x3c, 0x2f, 0x48, 0x54, 0x4d, 0x4c,      /* Y></HTML */
    0x3e, 0x0a,                                          /* >.       */
};

#include "sspmacro_vlan.h"
void sspvar_vlan_tag_ssi(SSPTAG_PARAM *params, SSPVAR_RET *ret, SSP_PSMH psmem) REENTRANT;

RES_CONST_DECL SSP_DATA_ENTRY CODE sspfile_vlan_redirect_htm[] = {
    { 0x00, 0, 322, 0, 0, _text0000 },
    { 0x02, 0, SSPMACRO_VLAN_TYPE, 0, 0, sspvar_vlan_tag_ssi },
    { 0x80, 0, 194, 0, 0, _text0001 },
};