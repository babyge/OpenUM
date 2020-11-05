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
    0x4c, 0x45, 0x3e, 0x4c, 0x6f, 0x6f, 0x70, 0x20,      /* LE>Loop  */
    0x44, 0x65, 0x74, 0x65, 0x63, 0x74, 0x69, 0x6f,      /* Detectio */
    0x6e, 0x3c, 0x2f, 0x54, 0x49, 0x54, 0x4c, 0x45,      /* n</TITLE */
    0x3e, 0x0a, 0x3c, 0x4d, 0x45, 0x54, 0x41, 0x20,      /* >.<META  */
    0x68, 0x74, 0x74, 0x70, 0x2d, 0x65, 0x71, 0x75,      /* http-equ */
    0x69, 0x76, 0x3d, 0x22, 0x43, 0x6f, 0x6e, 0x74,      /* iv="Cont */
    0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65,      /* ent-Type */
    0x22, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e,      /* " conten */
    0x74, 0x3d, 0x22, 0x74, 0x65, 0x78, 0x74, 0x2f,      /* t="text/ */
    0x68, 0x74, 0x6d, 0x6c, 0x3b, 0x20, 0x63, 0x68,      /* html; ch */
    0x61, 0x72, 0x73, 0x65, 0x74, 0x3d, 0x55, 0x54,      /* arset=UT */
    0x46, 0x2d, 0x38, 0x22, 0x3e, 0x20, 0x0a, 0x3c,      /* F-8"> .< */
    0x4c, 0x49, 0x4e, 0x4b, 0x20, 0x68, 0x72, 0x65,      /* LINK hre */
    0x66, 0x3d, 0x22, 0x66, 0x6f, 0x72, 0x6d, 0x2e,      /* f="form. */
    0x63, 0x73, 0x73, 0x22, 0x20, 0x72, 0x65, 0x6c,      /* css" rel */
    0x3d, 0x73, 0x74, 0x79, 0x6c, 0x65, 0x73, 0x68,      /* =stylesh */
    0x65, 0x65, 0x74, 0x3e, 0x0a, 0x0a, 0x3c, 0x53,      /* eet>..<S */
    0x43, 0x52, 0x49, 0x50, 0x54, 0x20, 0x20, 0x6c,      /* CRIPT  l */
    0x61, 0x6e, 0x67, 0x75, 0x61, 0x67, 0x65, 0x3d,      /* anguage= */
    0x22, 0x4a, 0x61, 0x76, 0x61, 0x53, 0x63, 0x72,      /* "JavaScr */
    0x69, 0x70, 0x74, 0x22, 0x20, 0x74, 0x79, 0x70,      /* ipt" typ */
    0x65, 0x3d, 0x22, 0x74, 0x65, 0x78, 0x74, 0x2f,      /* e="text/ */
    0x6a, 0x61, 0x76, 0x61, 0x73, 0x63, 0x72, 0x69,      /* javascri */
    0x70, 0x74, 0x22, 0x3e, 0x0a, 0x66, 0x75, 0x6e,      /* pt">.fun */
    0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x64, 0x69,      /* ction di */
    0x73, 0x70, 0x6c, 0x61, 0x79, 0x5f, 0x68, 0x65,      /* splay_he */
    0x6c, 0x70, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20,      /* lp().{.  */
    0x20, 0x77, 0x69, 0x6e, 0x64, 0x6f, 0x77, 0x2e,      /*  window. */
    0x6f, 0x70, 0x65, 0x6e, 0x28, 0x27, 0x6c, 0x6f,      /* open('lo */
    0x6f, 0x70, 0x64, 0x65, 0x74, 0x5f, 0x68, 0x65,      /* opdet_he */
    0x6c, 0x70, 0x2e, 0x68, 0x74, 0x6d, 0x27, 0x2c,      /* lp.htm', */
    0x27, 0x4d, 0x79, 0x57, 0x69, 0x6e, 0x64, 0x6f,      /* 'MyWindo */
    0x77, 0x73, 0x27, 0x2c, 0x27, 0x73, 0x74, 0x61,      /* ws','sta */
    0x74, 0x75, 0x73, 0x3d, 0x79, 0x65, 0x73, 0x2c,      /* tus=yes, */
    0x6c, 0x65, 0x66, 0x74, 0x3d, 0x35, 0x30, 0x2c,      /* left=50, */
    0x74, 0x6f, 0x70, 0x3d, 0x35, 0x30, 0x2c, 0x73,      /* top=50,s */
    0x63, 0x72, 0x6f, 0x6c, 0x6c, 0x62, 0x61, 0x72,      /* crollbar */
    0x73, 0x3d, 0x79, 0x65, 0x73, 0x2c, 0x72, 0x65,      /* s=yes,re */
    0x73, 0x69, 0x7a, 0x61, 0x62, 0x6c, 0x65, 0x3d,      /* sizable= */
    0x79, 0x65, 0x73, 0x2c, 0x77, 0x69, 0x64, 0x74,      /* yes,widt */
    0x68, 0x3d, 0x36, 0x30, 0x30, 0x2c, 0x68, 0x65,      /* h=600,he */
    0x69, 0x67, 0x68, 0x74, 0x3d, 0x34, 0x30, 0x30,      /* ight=400 */
    0x27, 0x29, 0x3b, 0x0a, 0x7d, 0x0a, 0x3c, 0x2f,      /* ');.}.</ */
    0x53, 0x43, 0x52, 0x49, 0x50, 0x54, 0x3e, 0x0a,      /* SCRIPT>. */
    0x0a, 0x3c, 0x2f, 0x48, 0x45, 0x41, 0x44, 0x3e,      /* .</HEAD> */
    0x0a, 0x3c, 0x42, 0x4f, 0x44, 0x59, 0x3e, 0x0a,      /* .<BODY>. */
    0x3c, 0x54, 0x41, 0x42, 0x4c, 0x45, 0x20, 0x63,      /* <TABLE c */
    0x65, 0x6c, 0x6c, 0x53, 0x70, 0x61, 0x63, 0x69,      /* ellSpaci */
    0x6e, 0x67, 0x3d, 0x22, 0x30, 0x22, 0x20, 0x62,      /* ng="0" b */
    0x6f, 0x72, 0x64, 0x65, 0x72, 0x3d, 0x22, 0x30,      /* order="0 */
    0x22, 0x3e, 0x0a, 0x3c, 0x54, 0x52, 0x20, 0x76,      /* ">.<TR v */
    0x41, 0x6c, 0x69, 0x67, 0x6e, 0x3d, 0x22, 0x74,      /* Align="t */
    0x6f, 0x70, 0x22, 0x3e, 0x0a, 0x3c, 0x54, 0x44,      /* op">.<TD */
    0x20, 0x77, 0x69, 0x64, 0x74, 0x68, 0x3d, 0x22,      /*  width=" */
    0x39, 0x30, 0x25, 0x22, 0x3e, 0x3c, 0x48, 0x31,      /* 90%"><H1 */
    0x3e, 0x4c, 0x6f, 0x6f, 0x70, 0x20, 0x44, 0x65,      /* >Loop De */
    0x74, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3c,      /* tection< */
    0x2f, 0x48, 0x31, 0x3e, 0x3c, 0x2f, 0x54, 0x44,      /* /H1></TD */
    0x3e, 0x0a, 0x3c, 0x54, 0x44, 0x20, 0x61, 0x6c,      /* >.<TD al */
    0x69, 0x67, 0x6e, 0x3d, 0x22, 0x72, 0x69, 0x67,      /* ign="rig */
    0x68, 0x74, 0x22, 0x3e, 0x3c, 0x49, 0x4e, 0x50,      /* ht"><INP */
    0x55, 0x54, 0x20, 0x74, 0x79, 0x70, 0x65, 0x3d,      /* UT type= */
    0x22, 0x62, 0x75, 0x74, 0x74, 0x6f, 0x6e, 0x22,      /* "button" */
    0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x3d, 0x22,      /*  value=" */
    0x48, 0x65, 0x6c, 0x70, 0x22, 0x20, 0x6f, 0x6e,      /* Help" on */
    0x63, 0x6c, 0x69, 0x63, 0x6b, 0x3d, 0x22, 0x6a,      /* click="j */
    0x61, 0x76, 0x61, 0x73, 0x63, 0x72, 0x69, 0x70,      /* avascrip */
    0x74, 0x3a, 0x64, 0x69, 0x73, 0x70, 0x6c, 0x61,      /* t:displa */
    0x79, 0x5f, 0x68, 0x65, 0x6c, 0x70, 0x28, 0x29,      /* y_help() */
    0x3b, 0x22, 0x3e, 0x3c, 0x2f, 0x54, 0x44, 0x3e,      /* ;"></TD> */
    0x0a, 0x3c, 0x2f, 0x54, 0x52, 0x3e, 0x0a, 0x3c,      /* .</TR>.< */
    0x2f, 0x54, 0x41, 0x42, 0x4c, 0x45, 0x3e, 0x0a,      /* /TABLE>. */
    0x0a, 0x3c, 0x46, 0x4f, 0x52, 0x4d, 0x20, 0x6e,      /* .<FORM n */
    0x61, 0x6d, 0x65, 0x3d, 0x6c, 0x6f, 0x6f, 0x70,      /* ame=loop */
    0x20, 0x6d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x3d,      /*  method= */
    0x70, 0x6f, 0x73, 0x74, 0x20, 0x61, 0x63, 0x74,      /* post act */
    0x69, 0x6f, 0x6e, 0x3d, 0x22, 0x6c, 0x6f, 0x6f,      /* ion="loo */
    0x70, 0x64, 0x65, 0x74, 0x2e, 0x63, 0x67, 0x69,      /* pdet.cgi */
    0x22, 0x3e, 0x0a, 0x3c, 0x54, 0x41, 0x42, 0x4c,      /* ">.<TABL */
    0x45, 0x3e, 0x0a, 0x20, 0x20, 0x3c, 0x54, 0x42,      /* E>.  <TB */
    0x4f, 0x44, 0x59, 0x3e, 0x0a, 0x20, 0x20, 0x3c,      /* ODY>.  < */
    0x54, 0x52, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* TR>.     */
    0x3c, 0x54, 0x44, 0x3e, 0x3c, 0x49, 0x4e, 0x50,      /* <TD><INP */
    0x55, 0x54, 0x20, 0x74, 0x79, 0x70, 0x65, 0x3d,      /* UT type= */
    0x63, 0x68, 0x65, 0x63, 0x6b, 0x62, 0x6f, 0x78,      /* checkbox */
    0x20, 0x6e, 0x61, 0x6d, 0x65, 0x3d, 0x6c, 0x6f,      /*  name=lo */
    0x6f, 0x70, 0x5f, 0x65, 0x6e, 0x20,                  /* op_en    */
};

static RES_CONST_DECL unsigned char CODE _text0001[] = {
    0x3e, 0x3c, 0x42, 0x3e, 0x26, 0x6e, 0x62, 0x73,      /* ><B>&nbs */
    0x70, 0x3b, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65,      /* p;Enable */
    0x20, 0x4c, 0x6f, 0x6f, 0x70, 0x20, 0x44, 0x65,      /*  Loop De */
    0x74, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20,      /* tection  */
    0x3c, 0x2f, 0x42, 0x3e, 0x26, 0x6e, 0x62, 0x73,      /* </B>&nbs */
    0x70, 0x3b, 0x26, 0x6e, 0x62, 0x73, 0x70, 0x3b,      /* p;&nbsp; */
    0x26, 0x6e, 0x62, 0x73, 0x70, 0x3b, 0x26, 0x6e,      /* &nbsp;&n */
    0x62, 0x73, 0x70, 0x3b, 0x0a, 0x20, 0x20, 0x20,      /* bsp;.    */
    0x20, 0x3c, 0x54, 0x44, 0x3e, 0x26, 0x6e, 0x62,      /*  <TD>&nb */
    0x73, 0x70, 0x3b, 0x0a, 0x20, 0x20, 0x3c, 0x54,      /* sp;.  <T */
    0x52, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c,      /* R>.    < */
    0x54, 0x44, 0x3e, 0x26, 0x6e, 0x62, 0x73, 0x70,      /* TD>&nbsp */
    0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x54,      /* ;.    <T */
    0x44, 0x3e, 0x26, 0x6e, 0x62, 0x73, 0x70, 0x3b,      /* D>&nbsp; */
    0x0a, 0x20, 0x20, 0x3c, 0x54, 0x52, 0x3e, 0x0a,      /* .  <TR>. */
    0x20, 0x20, 0x20, 0x20, 0x3c, 0x54, 0x44, 0x3e,      /*     <TD> */
    0x26, 0x6e, 0x62, 0x73, 0x70, 0x3b, 0x26, 0x6e,      /* &nbsp;&n */
    0x62, 0x73, 0x70, 0x3b, 0x26, 0x6e, 0x62, 0x73,      /* bsp;&nbs */
    0x70, 0x3b, 0x26, 0x6e, 0x62, 0x73, 0x70, 0x3b,      /* p;&nbsp; */
    0x26, 0x6e, 0x62, 0x73, 0x70, 0x3b, 0x26, 0x6e,      /* &nbsp;&n */
    0x62, 0x73, 0x70, 0x3b, 0x26, 0x6e, 0x62, 0x73,      /* bsp;&nbs */
    0x70, 0x3b, 0x3c, 0x49, 0x4e, 0x50, 0x55, 0x54,      /* p;<INPUT */
    0x20, 0x74, 0x79, 0x70, 0x65, 0x3d, 0x73, 0x75,      /*  type=su */
    0x62, 0x6d, 0x69, 0x74, 0x20, 0x76, 0x61, 0x6c,      /* bmit val */
    0x75, 0x65, 0x3d, 0x41, 0x70, 0x70, 0x6c, 0x79,      /* ue=Apply */
    0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x54,      /* >.    <T */
    0x44, 0x3e, 0x0a, 0x20, 0x20, 0x3c, 0x2f, 0x54,      /* D>.  </T */
    0x52, 0x3e, 0x0a, 0x20, 0x20, 0x3c, 0x2f, 0x54,      /* R>.  </T */
    0x42, 0x4f, 0x44, 0x59, 0x3e, 0x0a, 0x3c, 0x2f,      /* BODY>.</ */
    0x54, 0x41, 0x42, 0x4c, 0x45, 0x3e, 0x0a, 0x3c,      /* TABLE>.< */
    0x2f, 0x46, 0x4f, 0x52, 0x4d, 0x3e, 0x0a, 0x3c,      /* /FORM>.< */
    0x2f, 0x42, 0x4f, 0x44, 0x59, 0x3e, 0x3c, 0x2f,      /* /BODY></ */
    0x48, 0x54, 0x4d, 0x4c, 0x3e, 0x0a,                  /* HTML>.   */
};

void sspvar_loopdet_tag_checked(SSPTAG_PARAM *params, SSPVAR_RET *ret, SSP_PSMH psmem) REENTRANT;

RES_CONST_DECL SSP_DATA_ENTRY CODE sspfile_loopdet_htm[] = {
    { 0x00, 0, 774, 0, 0, _text0000 },
    { 0x02, 0, 0, 0, 0, sspvar_loopdet_tag_checked },
    { 0x80, 0, 262, 0, 0, _text0001 },
};