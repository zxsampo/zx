/* c/zx-as-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
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
#include "c/zx-as-data.h"
#define TPF zx_
#include "zx_ext_pt.h"



int zx_DEC_ATTR_as_Extensions(struct zx_ctx* c, struct zx_as_Extensions_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_as_Extensions(struct zx_ctx* c, struct zx_as_Extensions_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_as_Parameter(struct zx_ctx* c, struct zx_as_Parameter_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_name_ATTR:  x->name = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_as_Parameter(struct zx_ctx* c, struct zx_as_Parameter_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_as_PasswordTransforms(struct zx_ctx* c, struct zx_as_PasswordTransforms_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_as_PasswordTransforms(struct zx_ctx* c, struct zx_as_PasswordTransforms_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_as_Transform_ELEM:
    if (!x->Transform)
      x->Transform = (struct zx_as_Transform_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_as_SASLRequest(struct zx_ctx* c, struct zx_as_SASLRequest_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_advisoryAuthnID_ATTR:  x->advisoryAuthnID = x->gg.attr; return 1;
    case zx_authzID_ATTR:  x->authzID = x->gg.attr; return 1;
    case zx_mechanism_ATTR:  x->mechanism = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_as_SASLRequest(struct zx_ctx* c, struct zx_as_SASLRequest_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_as_Data_ELEM:
    if (!x->Data)
      x->Data = el;
    return 1;
  case zx_sp_RequestedAuthnContext_ELEM:
    if (!x->RequestedAuthnContext)
      x->RequestedAuthnContext = (struct zx_sp_RequestedAuthnContext_s*)el;
    return 1;
  case zx_as_Extensions_ELEM:
    if (!x->Extensions)
      x->Extensions = (struct zx_as_Extensions_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_as_SASLResponse(struct zx_ctx* c, struct zx_as_SASLResponse_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_serverMechanism_ATTR:  x->serverMechanism = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_as_SASLResponse(struct zx_ctx* c, struct zx_as_SASLResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Status_ELEM:
    if (!x->Status)
      x->Status = (struct zx_lu_Status_s*)el;
    return 1;
  case zx_as_PasswordTransforms_ELEM:
    if (!x->PasswordTransforms)
      x->PasswordTransforms = (struct zx_as_PasswordTransforms_s*)el;
    return 1;
  case zx_as_Data_ELEM:
    if (!x->Data)
      x->Data = el;
    return 1;
  case zx_a_EndpointReference_ELEM:
    if (!x->EndpointReference)
      x->EndpointReference = (struct zx_a_EndpointReference_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_as_Transform(struct zx_ctx* c, struct zx_as_Transform_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_name_ATTR:  x->name = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_as_Transform(struct zx_ctx* c, struct zx_as_Transform_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_as_Parameter_ELEM:
    if (!x->Parameter)
      x->Parameter = (struct zx_as_Parameter_s*)el;
    return 1;

  default: return 0;
  }
}


/* EOF -- c/zx-as-dec.c */
