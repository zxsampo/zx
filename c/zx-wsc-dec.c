/* c/zx-wsc-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** dec-templ.c  -  XML decoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: dec-templ.c,v 1.30 2008-10-04 23:42:14 sampo Exp $
 **
 ** 28.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 12.8.2006, added special scanning of xmlns to avoid backtracking elem recognition --Sampo
 ** 23.9.2006, added collection of WO information --Sampo
 ** 21.6.2007, improved handling of undeclared namespace prefixes --Sampo
 ** 27.10.2010, CSE refactoring, re-engineered namespace handling --Sampo
 ** 21.11.2010, re-engineered to extract most code to zx_DEC_elem, leaving just switches --Sampo
 **
 ** N.B: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-wsc-data.h"
#define TPF zx_
#include "zx_ext_pt.h"



int zx_DEC_ATTR_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_Algorithm_ATTR:  x->Algorithm = x->gg.attr; return 1;
    case zx_Id_ATTR|zx_wsu_NS:  x->Id = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_wsse_SecurityTokenReference_ELEM:
    if (!x->SecurityTokenReference)
      x->SecurityTokenReference = (struct zx_wsse_SecurityTokenReference_s*)el;
    return 1;
  case zx_wsc_Properties_ELEM:
    if (!x->Properties)
      x->Properties = (struct zx_wsc_Properties_s*)el;
    return 1;
  case zx_wsc_Generation_ELEM:
    if (!x->Generation)
      x->Generation = el;
    return 1;
  case zx_wsc_Offset_ELEM:
    if (!x->Offset)
      x->Offset = el;
    return 1;
  case zx_wsc_Length_ELEM:
    if (!x->Length)
      x->Length = el;
    return 1;
  case zx_wsc_Label_ELEM:
    if (!x->Label)
      x->Label = el;
    return 1;
  case zx_wsc_Nonce_ELEM:
    if (!x->Nonce)
      x->Nonce = el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_Id_ATTR|zx_wsu_NS:  x->Id = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}


/* EOF -- c/zx-wsc-dec.c */