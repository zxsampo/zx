/* c/zx-xasa-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
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
#include "c/zx-xasa-data.h"
#define TPF zx_
#include "zx_ext_pt.h"



int zx_DEC_ATTR_xasa_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasa_XACMLAuthzDecisionStatement_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_xasa_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasa_XACMLAuthzDecisionStatement_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_xac_Response_ELEM:
    if (!x->Response)
      x->Response = (struct zx_xac_Response_s*)el;
    return 1;
  case zx_xac_Request_ELEM:
    if (!x->Request)
      x->Request = (struct zx_xac_Request_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_xasa_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasa_XACMLPolicyStatement_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_xasa_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasa_XACMLPolicyStatement_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_xa_Policy_ELEM:
    if (!x->Policy)
      x->Policy = (struct zx_xa_Policy_s*)el;
    return 1;
  case zx_xa_PolicySet_ELEM:
    if (!x->PolicySet)
      x->PolicySet = (struct zx_xa_PolicySet_s*)el;
    return 1;

  default: return 0;
  }
}


/* EOF -- c/zx-xasa-dec.c */
