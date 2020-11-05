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
    0x6c, 0x2f, 0x2f, 0x45, 0x4e, 0x22, 0x3e, 0x0d,      /* l//EN">. */
    0x0a, 0x3c, 0x48, 0x54, 0x4d, 0x4c, 0x3e, 0x3c,      /* .<HTML>< */
    0x48, 0x45, 0x41, 0x44, 0x3e, 0x0d, 0x0a, 0x3c,      /* HEAD>..< */
    0x54, 0x49, 0x54, 0x4c, 0x45, 0x3e, 0x53, 0x65,      /* TITLE>Se */
    0x74, 0x20, 0x52, 0x61, 0x74, 0x65, 0x20, 0x3c,      /* t Rate < */
    0x2f, 0x54, 0x49, 0x54, 0x4c, 0x45, 0x3e, 0x0d,      /* /TITLE>. */
    0x0a, 0x3c, 0x4d, 0x45, 0x54, 0x41, 0x20, 0x68,      /* .<META h */
    0x74, 0x74, 0x70, 0x2d, 0x65, 0x71, 0x75, 0x69,      /* ttp-equi */
    0x76, 0x3d, 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e,      /* v=Conten */
    0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x20, 0x63,      /* t-Type c */
    0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x3d, 0x22,      /* ontent=" */
    0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d,      /* text/htm */
    0x6c, 0x3b, 0x20, 0x63, 0x68, 0x61, 0x72, 0x73,      /* l; chars */
    0x65, 0x74, 0x3d, 0x55, 0x54, 0x46, 0x2d, 0x38,      /* et=UTF-8 */
    0x22, 0x3e, 0x0d, 0x0a, 0x3c, 0x4c, 0x49, 0x4e,      /* ">..<LIN */
    0x4b, 0x20, 0x68, 0x72, 0x65, 0x66, 0x3d, 0x22,      /* K href=" */
    0x66, 0x6f, 0x72, 0x6d, 0x2e, 0x63, 0x73, 0x73,      /* form.css */
    0x22, 0x20, 0x72, 0x65, 0x6c, 0x3d, 0x73, 0x74,      /* " rel=st */
    0x79, 0x6c, 0x65, 0x73, 0x68, 0x65, 0x65, 0x74,      /* ylesheet */
    0x3e, 0x0d, 0x0a, 0x3c, 0x53, 0x43, 0x52, 0x49,      /* >..<SCRI */
    0x50, 0x54, 0x20, 0x6c, 0x61, 0x6e, 0x67, 0x75,      /* PT langu */
    0x61, 0x67, 0x65, 0x3d, 0x4a, 0x61, 0x76, 0x61,      /* age=Java */
    0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x20, 0x74,      /* Script t */
    0x79, 0x70, 0x65, 0x3d, 0x22, 0x74, 0x65, 0x78,      /* ype="tex */
    0x74, 0x2f, 0x6a, 0x61, 0x76, 0x61, 0x73, 0x63,      /* t/javasc */
    0x72, 0x69, 0x70, 0x74, 0x22, 0x3e, 0x0d, 0x0a,      /* ript">.. */
    0x66, 0x75, 0x6e, 0x63, 0x74, 0x69, 0x6f, 0x6e,      /* function */
    0x20, 0x73, 0x65, 0x74, 0x72, 0x61, 0x74, 0x65,      /*  setrate */
    0x5f, 0x68, 0x65, 0x6c, 0x70, 0x28, 0x29, 0x0d,      /* _help(). */
    0x0a, 0x7b, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x77,      /* .{..   w */
    0x69, 0x6e, 0x64, 0x6f, 0x77, 0x2e, 0x6f, 0x70,      /* indow.op */
    0x65, 0x6e, 0x28, 0x27, 0x72, 0x61, 0x74, 0x65,      /* en('rate */
    0x68, 0x65, 0x6c, 0x70, 0x32, 0x2e, 0x68, 0x74,      /* help2.ht */
    0x6d, 0x27, 0x2c, 0x27, 0x4d, 0x79, 0x57, 0x69,      /* m','MyWi */
    0x6e, 0x64, 0x6f, 0x77, 0x73, 0x27, 0x2c, 0x27,      /* ndows',' */
    0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x3d, 0x79,      /* status=y */
    0x65, 0x73, 0x2c, 0x6c, 0x65, 0x66, 0x74, 0x3d,      /* es,left= */
    0x35, 0x30, 0x2c, 0x74, 0x6f, 0x70, 0x3d, 0x35,      /* 50,top=5 */
    0x30, 0x2c, 0x73, 0x63, 0x72, 0x6f, 0x6c, 0x6c,      /* 0,scroll */
    0x62, 0x61, 0x72, 0x73, 0x3d, 0x79, 0x65, 0x73,      /* bars=yes */
    0x2c, 0x72, 0x65, 0x73, 0x69, 0x7a, 0x61, 0x62,      /* ,resizab */
    0x6c, 0x65, 0x3d, 0x79, 0x65, 0x73, 0x2c, 0x77,      /* le=yes,w */
    0x69, 0x64, 0x74, 0x68, 0x3d, 0x36, 0x30, 0x30,      /* idth=600 */
    0x2c, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x3d,      /* ,height= */
    0x34, 0x30, 0x30, 0x27, 0x29, 0x3b, 0x0d, 0x0a,      /* 400');.. */
    0x7d, 0x0d, 0x0a, 0x0d, 0x0a, 0x66, 0x75, 0x6e,      /* }....fun */
    0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x69, 0x6e,      /* ction in */
    0x69, 0x74, 0x5f, 0x72, 0x61, 0x74, 0x65, 0x28,      /* it_rate( */
    0x29, 0x0d, 0x0a, 0x7b, 0x0d, 0x0a, 0x09, 0x72,      /* )..{...r */
    0x61, 0x74, 0x65, 0x5f, 0x63, 0x61, 0x70, 0x73,      /* ate_caps */
    0x20, 0x3d, 0x20, 0x6e, 0x65, 0x77, 0x20, 0x41,      /*  = new A */
    0x72, 0x72, 0x61, 0x79, 0x28,                        /* rray(    */
};

static RES_CONST_DECL unsigned char CODE _text0001[] = {
    0x29, 0x3b, 0x0d, 0x0a, 0x09, 0x72, 0x61, 0x74,      /* );...rat */
    0x65, 0x5f, 0x76, 0x61, 0x6c, 0x73, 0x20, 0x3d,      /* e_vals = */
    0x20, 0x6e, 0x65, 0x77, 0x20, 0x41, 0x72, 0x72,      /*  new Arr */
    0x61, 0x79, 0x28,                                    /* ay(      */
};

static RES_CONST_DECL unsigned char CODE _text0002[] = {
    0x29, 0x3b, 0x0d, 0x0a, 0x09, 0x72, 0x61, 0x74,      /* );...rat */
    0x65, 0x5f, 0x69, 0x6e, 0x67, 0x72, 0x65, 0x73,      /* e_ingres */
    0x73, 0x20, 0x3d, 0x20,                              /* s =      */
};

static RES_CONST_DECL unsigned char CODE _text0003[] = {
    0x3b, 0x0d, 0x0a, 0x09, 0x72, 0x61, 0x74, 0x65,      /* ;...rate */
    0x5f, 0x65, 0x67, 0x72, 0x65, 0x73, 0x73, 0x20,      /* _egress  */
    0x3d, 0x20,                                          /* =        */
};

static RES_CONST_DECL unsigned char CODE _text0004[] = {
    0x3b, 0x0d, 0x0a, 0x09, 0x0d, 0x0a, 0x20, 0x20,      /* ;.....   */
    0x20, 0x20, 0x76, 0x61, 0x72, 0x20, 0x74, 0x73,      /*   var ts */
    0x65, 0x6c, 0x65, 0x63, 0x74, 0x73, 0x20, 0x3d,      /* elects = */
    0x20, 0x64, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e,      /*  documen */
    0x74, 0x2e, 0x66, 0x6f, 0x72, 0x6d, 0x73, 0x5b,      /* t.forms[ */
    0x30, 0x5d, 0x2e, 0x67, 0x65, 0x74, 0x45, 0x6c,      /* 0].getEl */
    0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x42, 0x79,      /* ementsBy */
    0x54, 0x61, 0x67, 0x4e, 0x61, 0x6d, 0x65, 0x28,      /* TagName( */
    0x27, 0x53, 0x45, 0x4c, 0x45, 0x43, 0x54, 0x27,      /* 'SELECT' */
    0x29, 0x3b, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* );..     */
    0x69, 0x20, 0x3d, 0x20, 0x30, 0x3b, 0x20, 0x0d,      /* i = 0; . */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6f, 0x72,      /* .    for */
    0x28, 0x3b, 0x3b, 0x29, 0x0d, 0x0a, 0x20, 0x20,      /* (;;)..   */
    0x20, 0x20, 0x7b, 0x0d, 0x0a, 0x20, 0x20, 0x20,      /*   {..    */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20,      /*      if  */
    0x28, 0x69, 0x20, 0x3e, 0x3d, 0x20, 0x74, 0x73,      /* (i >= ts */
    0x65, 0x6c, 0x65, 0x63, 0x74, 0x73, 0x2e, 0x6c,      /* elects.l */
    0x65, 0x6e, 0x67, 0x74, 0x68, 0x29, 0x0d, 0x0a,      /* ength).. */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x62, 0x72, 0x65, 0x61,      /*     brea */
    0x6b, 0x3b, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* k;..     */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* ..       */
    0x20, 0x20, 0x76, 0x61, 0x72, 0x20, 0x74, 0x73,      /*   var ts */
    0x65, 0x6c, 0x65, 0x63, 0x74, 0x20, 0x3d, 0x20,      /* elect =  */
    0x74, 0x73, 0x65, 0x6c, 0x65, 0x63, 0x74, 0x73,      /* tselects */
    0x5b, 0x69, 0x5d, 0x3b, 0x0d, 0x0a, 0x20, 0x20,      /* [i];..   */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66,      /*       if */
    0x20, 0x28, 0x74, 0x73, 0x65, 0x6c, 0x65, 0x63,      /*  (tselec */
    0x74, 0x2e, 0x6e, 0x61, 0x6d, 0x65, 0x20, 0x3d,      /* t.name = */
    0x3d, 0x20, 0x22, 0x69, 0x6e, 0x67, 0x72, 0x65,      /* = "ingre */
    0x73, 0x73, 0x22, 0x20, 0x7c, 0x7c, 0x20, 0x74,      /* ss" || t */
    0x73, 0x65, 0x6c, 0x65, 0x63, 0x74, 0x2e, 0x6e,      /* select.n */
    0x61, 0x6d, 0x65, 0x20, 0x3d, 0x3d, 0x20, 0x22,      /* ame == " */
    0x65, 0x67, 0x72, 0x65, 0x73, 0x73, 0x22, 0x29,      /* egress") */
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* ..       */
    0x20, 0x20, 0x7b, 0x0d, 0x0a, 0x20, 0x20, 0x20,      /*   {..    */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x6a, 0x20, 0x3d, 0x20, 0x30, 0x3b, 0x0d,      /*  j = 0;. */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* .        */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6f, 0x72,      /*      for */
    0x28, 0x3b, 0x3b, 0x29, 0x0d, 0x0a, 0x20, 0x20,      /* (;;)..   */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x7b, 0x0d, 0x0a, 0x20, 0x20, 0x20,      /*   {..    */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20,      /*      if  */
    0x28, 0x6a, 0x20, 0x3e, 0x3d, 0x20, 0x72, 0x61,      /* (j >= ra */
    0x74, 0x65, 0x5f, 0x76, 0x61, 0x6c, 0x73, 0x2e,      /* te_vals. */
    0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x29, 0x0d,      /* length). */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* .        */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x62, 0x72, 0x65,      /*      bre */
    0x61, 0x6b, 0x3b, 0x0d, 0x0a, 0x20, 0x20, 0x20,      /* ak;..    */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,      /*  ..      */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x76, 0x61, 0x72, 0x20, 0x6f,      /*    var o */
    0x70, 0x74, 0x3b, 0x20, 0x20, 0x20, 0x20, 0x20,      /* pt;      */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0d,      /*        . */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* .        */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x69, 0x66, 0x20, 0x28, 0x6e, 0x61, 0x76,      /*  if (nav */
    0x69, 0x67, 0x61, 0x74, 0x6f, 0x72, 0x2e, 0x75,      /* igator.u */
    0x73, 0x65, 0x72, 0x41, 0x67, 0x65, 0x6e, 0x74,      /* serAgent */
    0x2e, 0x74, 0x6f, 0x4c, 0x6f, 0x77, 0x65, 0x72,      /* .toLower */
    0x43, 0x61, 0x73, 0x65, 0x28, 0x29, 0x2e, 0x69,      /* Case().i */
    0x6e, 0x64, 0x65, 0x78, 0x4f, 0x66, 0x28, 0x22,      /* ndexOf(" */
    0x6d, 0x73, 0x69, 0x65, 0x22, 0x29, 0x20, 0x21,      /* msie") ! */
    0x3d, 0x20, 0x2d, 0x31, 0x20, 0x26, 0x26, 0x20,      /* = -1 &&  */
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* ..       */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6e, 0x61,      /*       na */
    0x76, 0x69, 0x67, 0x61, 0x74, 0x6f, 0x72, 0x2e,      /* vigator. */
    0x75, 0x73, 0x65, 0x72, 0x41, 0x67, 0x65, 0x6e,      /* userAgen */
    0x74, 0x2e, 0x74, 0x6f, 0x4c, 0x6f, 0x77, 0x65,      /* t.toLowe */
    0x72, 0x43, 0x61, 0x73, 0x65, 0x28, 0x29, 0x2e,      /* rCase(). */
    0x69, 0x6e, 0x64, 0x65, 0x78, 0x4f, 0x66, 0x28,      /* indexOf( */
    0x22, 0x6f, 0x70, 0x65, 0x72, 0x61, 0x22, 0x29,      /* "opera") */
    0x20, 0x3d, 0x3d, 0x20, 0x2d, 0x31, 0x20, 0x29,      /*  == -1 ) */
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* ..       */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x70,      /*       op */
    0x74, 0x20, 0x3d, 0x20, 0x64, 0x6f, 0x63, 0x75,      /* t = docu */
    0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x63, 0x72, 0x65,      /* ment.cre */
    0x61, 0x74, 0x65, 0x45, 0x6c, 0x65, 0x6d, 0x65,      /* ateEleme */
    0x6e, 0x74, 0x28, 0x22, 0x3c, 0x4f, 0x50, 0x54,      /* nt("<OPT */
    0x49, 0x4f, 0x4e, 0x20, 0x76, 0x61, 0x6c, 0x75,      /* ION valu */
    0x65, 0x3d, 0x22, 0x20, 0x2b, 0x20, 0x72, 0x61,      /* e=" + ra */
    0x74, 0x65, 0x5f, 0x76, 0x61, 0x6c, 0x73, 0x5b,      /* te_vals[ */
    0x6a, 0x5d, 0x20, 0x2b, 0x20, 0x22, 0x3e, 0x22,      /* j] + ">" */
    0x29, 0x3b, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* );..     */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x65, 0x6c, 0x73, 0x65,      /*     else */
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* ..       */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x70,      /*       op */
    0x74, 0x20, 0x3d, 0x20, 0x64, 0x6f, 0x63, 0x75,      /* t = docu */
    0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x63, 0x72, 0x65,      /* ment.cre */
    0x61, 0x74, 0x65, 0x45, 0x6c, 0x65, 0x6d, 0x65,      /* ateEleme */
    0x6e, 0x74, 0x28, 0x22, 0x4f, 0x50, 0x54, 0x49,      /* nt("OPTI */
    0x4f, 0x4e, 0x22, 0x29, 0x3b, 0x0d, 0x0a, 0x20,      /* ON");..  */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6f,      /*        o */
    0x70, 0x74, 0x2e, 0x73, 0x65, 0x74, 0x41, 0x74,      /* pt.setAt */
    0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x28,      /* tribute( */
    0x22, 0x56, 0x41, 0x4c, 0x55, 0x45, 0x22, 0x2c,      /* "VALUE", */
    0x20, 0x72, 0x61, 0x74, 0x65, 0x5f, 0x76, 0x61,      /*  rate_va */
    0x6c, 0x73, 0x5b, 0x6a, 0x5d, 0x29, 0x3b, 0x0d,      /* ls[j]);. */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* .        */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x74, 0x73,      /*  if ((ts */
    0x65, 0x6c, 0x65, 0x63, 0x74, 0x2e, 0x6e, 0x61,      /* elect.na */
    0x6d, 0x65, 0x20, 0x3d, 0x3d, 0x20, 0x22, 0x69,      /* me == "i */
    0x6e, 0x67, 0x72, 0x65, 0x73, 0x73, 0x22, 0x20,      /* ngress"  */
    0x26, 0x26, 0x20, 0x72, 0x61, 0x74, 0x65, 0x5f,      /* && rate_ */
    0x76, 0x61, 0x6c, 0x73, 0x5b, 0x6a, 0x5d, 0x20,      /* vals[j]  */
    0x3d, 0x3d, 0x20, 0x72, 0x61, 0x74, 0x65, 0x5f,      /* == rate_ */
    0x69, 0x6e, 0x67, 0x72, 0x65, 0x73, 0x73, 0x29,      /* ingress) */
    0x20, 0x7c, 0x7c, 0x0d, 0x0a, 0x20, 0x20, 0x20,      /*  ||..    */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x28, 0x74, 0x73, 0x65, 0x6c, 0x65, 0x63,      /*  (tselec */
    0x74, 0x2e, 0x6e, 0x61, 0x6d, 0x65, 0x20, 0x3d,      /* t.name = */
    0x3d, 0x20, 0x22, 0x65, 0x67, 0x72, 0x65, 0x73,      /* = "egres */
    0x73, 0x22, 0x20, 0x26, 0x26, 0x20, 0x72, 0x61,      /* s" && ra */
    0x74, 0x65, 0x5f, 0x76, 0x61, 0x6c, 0x73, 0x5b,      /* te_vals[ */
    0x6a, 0x5d, 0x20, 0x3d, 0x3d, 0x20, 0x72, 0x61,      /* j] == ra */
    0x74, 0x65, 0x5f, 0x65, 0x67, 0x72, 0x65, 0x73,      /* te_egres */
    0x73, 0x29, 0x20, 0x29, 0x0d, 0x0a, 0x20, 0x20,      /* s) )..   */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x6f, 0x70, 0x74, 0x2e, 0x73, 0x65,      /*   opt.se */
    0x6c, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x3d,      /* lected = */
    0x20, 0x74, 0x72, 0x75, 0x65, 0x3b, 0x0d, 0x0a,      /*  true;.. */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x6f, 0x70, 0x74, 0x2e, 0x61, 0x70, 0x70, 0x65,      /* opt.appe */
    0x6e, 0x64, 0x43, 0x68, 0x69, 0x6c, 0x64, 0x28,      /* ndChild( */
    0x64, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x74,      /* document */
    0x2e, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x54,      /* .createT */
    0x65, 0x78, 0x74, 0x4e, 0x6f, 0x64, 0x65, 0x28,      /* extNode( */
    0x72, 0x61, 0x74, 0x65, 0x5f, 0x63, 0x61, 0x70,      /* rate_cap */
    0x73, 0x5b, 0x6a, 0x5d, 0x29, 0x29, 0x3b, 0x0d,      /* s[j]));. */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* .        */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x74, 0x73, 0x65, 0x6c, 0x65, 0x63, 0x74,      /*  tselect */
    0x2e, 0x61, 0x70, 0x70, 0x65, 0x6e, 0x64, 0x43,      /* .appendC */
    0x68, 0x69, 0x6c, 0x64, 0x28, 0x6f, 0x70, 0x74,      /* hild(opt */
    0x29, 0x3b, 0x0d, 0x0a, 0x0d, 0x0a, 0x20, 0x20,      /* );....   */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6a, 0x2b,      /*       j+ */
    0x2b, 0x3b, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* +;..     */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x7d, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,      /* }..      */
    0x20, 0x20, 0x20, 0x7d, 0x0d, 0x0a, 0x20, 0x20,      /*    }..   */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0d, 0x0a,      /*       .. */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /*          */
    0x69, 0x2b, 0x2b, 0x3b, 0x0d, 0x0a, 0x20, 0x20,      /* i++;..   */
    0x20, 0x20, 0x7d, 0x0d, 0x0a, 0x0d, 0x0a, 0x7d,      /*   }....} */
    0x0d, 0x0a, 0x0d, 0x0a, 0x0d, 0x0a, 0x3c, 0x2f,      /* ......</ */
    0x53, 0x43, 0x52, 0x49, 0x50, 0x54, 0x3e, 0x0d,      /* SCRIPT>. */
    0x0a, 0x3c, 0x2f, 0x48, 0x45, 0x41, 0x44, 0x3e,      /* .</HEAD> */
    0x0d, 0x0a, 0x3c, 0x42, 0x4f, 0x44, 0x59, 0x20,      /* ..<BODY  */
    0x6f, 0x6e, 0x6c, 0x6f, 0x61, 0x64, 0x3d, 0x22,      /* onload=" */
    0x69, 0x6e, 0x69, 0x74, 0x5f, 0x72, 0x61, 0x74,      /* init_rat */
    0x65, 0x28, 0x29, 0x22, 0x3e, 0x0d, 0x0a, 0x3c,      /* e()">..< */
    0x54, 0x41, 0x42, 0x4c, 0x45, 0x3e, 0x0d, 0x0a,      /* TABLE>.. */
    0x20, 0x20, 0x3c, 0x54, 0x42, 0x4f, 0x44, 0x59,      /*   <TBODY */
    0x3e, 0x0d, 0x0a, 0x20, 0x20, 0x3c, 0x54, 0x52,      /* >..  <TR */
    0x3e, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c,      /* >..    < */
    0x54, 0x44, 0x20, 0x77, 0x69, 0x64, 0x74, 0x68,      /* TD width */
    0x3d, 0x33, 0x30, 0x30, 0x3e, 0x20, 0x20, 0x0d,      /* =300>  . */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,      /* .        */
    0x20, 0x3c, 0x48, 0x31, 0x3e, 0x52, 0x61, 0x74,      /*  <H1>Rat */
    0x65, 0x20, 0x4c, 0x69, 0x6d, 0x69, 0x74, 0x20,      /* e Limit  */
    0x46, 0x6f, 0x72, 0x20, 0x50, 0x6f, 0x72, 0x74,      /* For Port */
    0x20,                                                /*          */
};

static RES_CONST_DECL unsigned char CODE _text0005[] = {
    0x3c, 0x2f, 0x48, 0x31, 0x3e, 0x0d, 0x0a, 0x20,      /* </H1>..  */
    0x20, 0x20, 0x20, 0x3c, 0x54, 0x44, 0x3e, 0x20,      /*    <TD>  */
    0x20, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,      /*  ..      */
    0x20, 0x20, 0x20, 0x3c, 0x69, 0x6e, 0x70, 0x75,      /*    <inpu */
    0x74, 0x20, 0x74, 0x79, 0x70, 0x65, 0x3d, 0x62,      /* t type=b */
    0x75, 0x74, 0x74, 0x6f, 0x6e, 0x20, 0x76, 0x61,      /* utton va */
    0x6c, 0x75, 0x65, 0x3d, 0x48, 0x65, 0x6c, 0x70,      /* lue=Help */
    0x20, 0x6f, 0x6e, 0x63, 0x6c, 0x69, 0x63, 0x6b,      /*  onclick */
    0x3d, 0x22, 0x73, 0x65, 0x74, 0x72, 0x61, 0x74,      /* ="setrat */
    0x65, 0x5f, 0x68, 0x65, 0x6c, 0x70, 0x28, 0x29,      /* e_help() */
    0x22, 0x3e, 0x0d, 0x0a, 0x3c, 0x2f, 0x54, 0x42,      /* ">..</TB */
    0x4f, 0x44, 0x59, 0x3e, 0x3c, 0x2f, 0x54, 0x41,      /* ODY></TA */
    0x42, 0x4c, 0x45, 0x3e, 0x20, 0x20, 0x20, 0x20,      /* BLE>     */
    0x20, 0x20, 0x20, 0x20, 0x0d, 0x0a, 0x3c, 0x46,      /*     ..<F */
    0x4f, 0x52, 0x4d, 0x20, 0x6e, 0x61, 0x6d, 0x65,      /* ORM name */
    0x3d, 0x73, 0x65, 0x74, 0x72, 0x61, 0x74, 0x65,      /* =setrate */
    0x20, 0x61, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3d,      /*  action= */
    0x22, 0x73, 0x65, 0x74, 0x72, 0x61, 0x74, 0x65,      /* "setrate */
    0x2e, 0x63, 0x67, 0x69, 0x22, 0x20, 0x6d, 0x65,      /* .cgi" me */
    0x74, 0x68, 0x6f, 0x64, 0x3d, 0x70, 0x6f, 0x73,      /* thod=pos */
    0x74, 0x3e, 0x0d, 0x0a, 0x3c, 0x49, 0x4e, 0x50,      /* t>..<INP */
    0x55, 0x54, 0x20, 0x74, 0x79, 0x70, 0x65, 0x3d,      /* UT type= */
    0x68, 0x69, 0x64, 0x64, 0x65, 0x6e, 0x20, 0x6e,      /* hidden n */
    0x61, 0x6d, 0x65, 0x3d, 0x70, 0x6f, 0x72, 0x74,      /* ame=port */
    0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x3d,            /*  value=  */
};

static RES_CONST_DECL unsigned char CODE _text0006[] = {
    0x3e, 0x0d, 0x0a, 0x3c, 0x54, 0x41, 0x42, 0x4c,      /* >..<TABL */
    0x45, 0x3e, 0x0d, 0x0a, 0x20, 0x20, 0x3c, 0x54,      /* E>..  <T */
    0x42, 0x4f, 0x44, 0x59, 0x3e, 0x0d, 0x0a, 0x20,      /* BODY>..  */
    0x20, 0x3c, 0x54, 0x52, 0x3e, 0x0d, 0x0a, 0x20,      /*  <TR>..  */
    0x20, 0x20, 0x20, 0x3c, 0x54, 0x44, 0x20, 0x77,      /*    <TD w */
    0x69, 0x64, 0x74, 0x68, 0x3d, 0x38, 0x30, 0x3e,      /* idth=80> */
    0x3c, 0x42, 0x3e, 0x49, 0x6e, 0x67, 0x72, 0x65,      /* <B>Ingre */
    0x73, 0x73, 0x20, 0x52, 0x61, 0x74, 0x65, 0x20,      /* ss Rate  */
    0x3c, 0x2f, 0x42, 0x3e, 0x0d, 0x0a, 0x09, 0x3c,      /* </B>...< */
    0x54, 0x44, 0x20, 0x77, 0x69, 0x64, 0x74, 0x68,      /* TD width */
    0x3d, 0x31, 0x35, 0x30, 0x3e, 0x3c, 0x53, 0x45,      /* =150><SE */
    0x4c, 0x45, 0x43, 0x54, 0x20, 0x6e, 0x61, 0x6d,      /* LECT nam */
    0x65, 0x3d, 0x69, 0x6e, 0x67, 0x72, 0x65, 0x73,      /* e=ingres */
    0x73, 0x3e, 0x20, 0x0d, 0x0a, 0x20, 0x20, 0x20,      /* s> ..    */
    0x20, 0x20, 0x20, 0x20, 0x3c, 0x4f, 0x50, 0x54,      /*     <OPT */
    0x49, 0x4f, 0x4e, 0x3e, 0x0d, 0x0a, 0x20, 0x20,      /* ION>..   */
    0x20, 0x20, 0x09, 0x3c, 0x2f, 0x53, 0x45, 0x4c,      /*   .</SEL */
    0x45, 0x43, 0x54, 0x3e, 0x0d, 0x0a, 0x20, 0x20,      /* ECT>..   */
};

static RES_CONST_DECL unsigned char CODE _text0007[] = {
    0x0d, 0x0a, 0x20, 0x20, 0x3c, 0x54, 0x52, 0x3e,      /* ..  <TR> */
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x54,      /* ..    <T */
    0x44, 0x20, 0x77, 0x69, 0x64, 0x74, 0x68, 0x3d,      /* D width= */
    0x38, 0x30, 0x3e, 0x3c, 0x42, 0x3e, 0x45, 0x67,      /* 80><B>Eg */
    0x72, 0x65, 0x73, 0x73, 0x20, 0x52, 0x61, 0x74,      /* ress Rat */
    0x65, 0x20, 0x3c, 0x2f, 0x42, 0x3e, 0x0d, 0x0a,      /* e </B>.. */
    0x09, 0x3c, 0x54, 0x44, 0x20, 0x77, 0x69, 0x64,      /* .<TD wid */
    0x74, 0x68, 0x3d, 0x31, 0x35, 0x30, 0x3e, 0x3c,      /* th=150>< */
    0x53, 0x45, 0x4c, 0x45, 0x43, 0x54, 0x20, 0x6e,      /* SELECT n */
    0x61, 0x6d, 0x65, 0x3d, 0x65, 0x67, 0x72, 0x65,      /* ame=egre */
    0x73, 0x73, 0x3e, 0x20, 0x0d, 0x0a, 0x20, 0x20,      /* ss> ..   */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x4f, 0x50,      /*      <OP */
    0x54, 0x49, 0x4f, 0x4e, 0x3e, 0x0d, 0x0a, 0x20,      /* TION>..  */
    0x20, 0x20, 0x20, 0x09, 0x3c, 0x2f, 0x53, 0x45,      /*    .</SE */
    0x4c, 0x45, 0x43, 0x54, 0x3e, 0x0d, 0x0a, 0x20,      /* LECT>..  */
    0x20, 0x20, 0x20,                                    /*          */
};

static RES_CONST_DECL unsigned char CODE _text0008[] = {
    0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x54,      /* ..    <T */
    0x52, 0x3e, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* R>..     */
    0x20, 0x20, 0x3c, 0x54, 0x44, 0x3e, 0x3c, 0x62,      /*   <TD><b */
    0x72, 0x3e, 0x0d, 0x0a, 0x20, 0x20, 0x20, 0x20,      /* r>..     */
    0x3c, 0x54, 0x52, 0x3e, 0x0d, 0x0a, 0x20, 0x20,      /* <TR>..   */
    0x20, 0x20, 0x20, 0x20, 0x3c, 0x54, 0x44, 0x3e,      /*     <TD> */
    0x3c, 0x49, 0x4e, 0x50, 0x55, 0x54, 0x20, 0x74,      /* <INPUT t */
    0x79, 0x70, 0x65, 0x3d, 0x73, 0x75, 0x62, 0x6d,      /* ype=subm */
    0x69, 0x74, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65,      /* it value */
    0x3d, 0x41, 0x70, 0x70, 0x6c, 0x79, 0x3e, 0x0d,      /* =Apply>. */
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x2f, 0x54,      /* .    </T */
    0x52, 0x3e, 0x3c, 0x2f, 0x54, 0x42, 0x4f, 0x44,      /* R></TBOD */
    0x59, 0x3e, 0x3c, 0x2f, 0x54, 0x41, 0x42, 0x4c,      /* Y></TABL */
    0x45, 0x3e, 0x3c, 0x42, 0x52, 0x3e, 0x0d, 0x0a,      /* E><BR>.. */
    0x3c, 0x2f, 0x46, 0x4f, 0x52, 0x4d, 0x3e, 0x0d,      /* </FORM>. */
    0x0a, 0x3c, 0x2f, 0x42, 0x4f, 0x44, 0x59, 0x3e,      /* .</BODY> */
    0x3c, 0x2f, 0x48, 0x54, 0x4d, 0x4c, 0x3e, 0x0d,      /* </HTML>. */
    0x0a,                                                /* .        */
};

#include "sspmacro_rate.h"
void sspvar_rate_tag_info(SSPTAG_PARAM *params, SSPVAR_RET *ret, SSP_PSMH psmem) REENTRANT;
void sspvar_rate_tag_string(SSPTAG_PARAM *params, SSPVAR_RET *ret, SSP_PSMH psmem) REENTRANT;

RES_CONST_DECL SSP_DATA_ENTRY CODE sspfile_setrate_htm[] = {
    { 0x00, 0, 469, 0, 0, _text0000 },
    { 0x02, 0, SSPMACRO_RATE_CAPS, 0, 0, sspvar_rate_tag_info },
    { 0x00, 0, 27, 0, 0, _text0001 },
    { 0x02, 0, SSPMACRO_RATE_VALS, 0, 0, sspvar_rate_tag_info },
    { 0x00, 0, 20, 0, 0, _text0002 },
    { 0x02, 0, SSPMACRO_RATE_INGRESS, 0, 0, sspvar_rate_tag_string },
    { 0x00, 0, 18, 0, 0, _text0003 },
    { 0x02, 0, SSPMACRO_RATE_EGRESS, 0, 0, sspvar_rate_tag_string },
    { 0x00, 0, 1425, 0, 0, _text0004 },
    { 0x02, 0, SSPMACRO_RATE_PORT, 0, 0, sspvar_rate_tag_string },
    { 0x00, 0, 199, 0, 0, _text0005 },
    { 0x02, 0, SSPMACRO_RATE_PORT1, 0, 0, sspvar_rate_tag_string },
    { 0x00, 0, 144, 0, 0, _text0006 },
    { 0x02, 0, SSPMACRO_RATE_SPS, 0, 0, sspvar_rate_tag_info },
    { 0x00, 0, 123, 0, 0, _text0007 },
    { 0x02, 0, SSPMACRO_RATE_SPE, 0, 0, sspvar_rate_tag_info },
    { 0x80, 0, 137, 0, 0, _text0008 },
};