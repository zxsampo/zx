/* c/zx-shps-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** enc-templ.c  -  XML encoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: enc-templ.c,v 1.27 2007-10-05 22:24:28 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006,  factored data structure walking to aux-templ.c --Sampo
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 26.8.2006, some CSE --Sampo
 ** 23.9.2006, added WO logic --Sampo
 ** 30.9.2007, improvements to WO encoding --Sampo
 ** 8.2.2010,  better handling of schema order encoding of unknown namespace prefixes --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** N.B2: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-shps-data.h"
#include "c/zx-ns.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_CallbackEPR
#define EL_STRUCT zx_shps_CallbackEPR_s
#define EL_NS     shps
#define EL_TAG    CallbackEPR

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_CallbackEPR) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_CallbackEPR(struct zx_ctx* c, struct zx_shps_CallbackEPR_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:CallbackEPR")-1 + 1 + sizeof("</shps:CallbackEPR>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_Address(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_ReferenceParameters(c, e);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_Metadata(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:CallbackEPR", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_CallbackEPR) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_CallbackEPR(struct zx_ctx* c, struct zx_shps_CallbackEPR_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CallbackEPR")-1 + 1 + 2 + sizeof("CallbackEPR")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_Address(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_ReferenceParameters(c, e);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_Metadata(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:CallbackEPR", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_CallbackEPR) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_CallbackEPR(struct zx_ctx* c, struct zx_shps_CallbackEPR_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:CallbackEPR");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->notOnOrAfter, " notOnOrAfter=\"", sizeof(" notOnOrAfter=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_Address(c, e, p);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_ReferenceParameters(c, e, p);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_Metadata(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:CallbackEPR>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:CallbackEPR", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_CallbackEPR) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_CallbackEPR(struct zx_ctx* c, struct zx_shps_CallbackEPR_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CallbackEPR", sizeof("CallbackEPR")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->notOnOrAfter, "notOnOrAfter=\"", sizeof("notOnOrAfter=\"")-1);
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);
  p = zx_attr_wo_enc(p, x->actor, "actor=\"", sizeof("actor=\"")-1);
  p = zx_attr_wo_enc(p, x->mustUnderstand, "mustUnderstand=\"", sizeof("mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:CallbackEPR", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_CallbackEPR) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_CallbackEPR(struct zx_ctx* c, struct zx_shps_CallbackEPR_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_CallbackEPR(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_CallbackEPR(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_CallbackEPR) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_CallbackEPR(struct zx_ctx* c, struct zx_shps_CallbackEPR_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_CallbackEPR(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_CallbackEPR(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_Delete
#define EL_STRUCT zx_shps_Delete_s
#define EL_NS     shps
#define EL_TAG    Delete

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_Delete(struct zx_ctx* c, struct zx_shps_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:Delete")-1 + 1 + sizeof("</shps:Delete>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Delete", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_Delete(struct zx_ctx* c, struct zx_shps_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Delete")-1 + 1 + 2 + sizeof("Delete")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Delete", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_Delete(struct zx_ctx* c, struct zx_shps_Delete_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:Delete");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:Delete>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_Delete(struct zx_ctx* c, struct zx_shps_Delete_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Delete", sizeof("Delete")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_Delete(struct zx_ctx* c, struct zx_shps_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_Delete(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_Delete(struct zx_ctx* c, struct zx_shps_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_Delete(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_DeleteResponse
#define EL_STRUCT zx_shps_DeleteResponse_s
#define EL_NS     shps
#define EL_TAG    DeleteResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_DeleteResponse(struct zx_ctx* c, struct zx_shps_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:DeleteResponse")-1 + 1 + sizeof("</shps:DeleteResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:DeleteResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_DeleteResponse(struct zx_ctx* c, struct zx_shps_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeleteResponse")-1 + 1 + 2 + sizeof("DeleteResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:DeleteResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_DeleteResponse(struct zx_ctx* c, struct zx_shps_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:DeleteResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:DeleteResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_DeleteResponse(struct zx_ctx* c, struct zx_shps_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "DeleteResponse", sizeof("DeleteResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_DeleteResponse(struct zx_ctx* c, struct zx_shps_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_DeleteResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_DeleteResponse(struct zx_ctx* c, struct zx_shps_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_DeleteResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_GetStatus
#define EL_STRUCT zx_shps_GetStatus_s
#define EL_NS     shps
#define EL_TAG    GetStatus

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_GetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_GetStatus(struct zx_ctx* c, struct zx_shps_GetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:GetStatus")-1 + 1 + sizeof("</shps:GetStatus>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:GetStatus", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_GetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_GetStatus(struct zx_ctx* c, struct zx_shps_GetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetStatus")-1 + 1 + 2 + sizeof("GetStatus")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:GetStatus", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_GetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_GetStatus(struct zx_ctx* c, struct zx_shps_GetStatus_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:GetStatus");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:GetStatus>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:GetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_GetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_GetStatus(struct zx_ctx* c, struct zx_shps_GetStatus_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "GetStatus", sizeof("GetStatus")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:GetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_GetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_GetStatus(struct zx_ctx* c, struct zx_shps_GetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_GetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_GetStatus(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_GetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_GetStatus(struct zx_ctx* c, struct zx_shps_GetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_GetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_GetStatus(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_GetStatusResponse
#define EL_STRUCT zx_shps_GetStatusResponse_s
#define EL_NS     shps
#define EL_TAG    GetStatusResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_GetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_GetStatusResponse(struct zx_ctx* c, struct zx_shps_GetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:GetStatusResponse")-1 + 1 + sizeof("</shps:GetStatusResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_shps_GetStatusResponseItem_s* e;
      for (e = x->GetStatusResponseItem; e; e = (struct zx_shps_GetStatusResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_GetStatusResponseItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:GetStatusResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_GetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_GetStatusResponse(struct zx_ctx* c, struct zx_shps_GetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetStatusResponse")-1 + 1 + 2 + sizeof("GetStatusResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_shps_GetStatusResponseItem_s* e;
      for (e = x->GetStatusResponseItem; e; e = (struct zx_shps_GetStatusResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_GetStatusResponseItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:GetStatusResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_GetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_GetStatusResponse(struct zx_ctx* c, struct zx_shps_GetStatusResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:GetStatusResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_shps_GetStatusResponseItem_s* e;
      for (e = x->GetStatusResponseItem; e; e = (struct zx_shps_GetStatusResponseItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_GetStatusResponseItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:GetStatusResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:GetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_GetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_GetStatusResponse(struct zx_ctx* c, struct zx_shps_GetStatusResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "GetStatusResponse", sizeof("GetStatusResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:GetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_GetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_GetStatusResponse(struct zx_ctx* c, struct zx_shps_GetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_GetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_GetStatusResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_GetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_GetStatusResponse(struct zx_ctx* c, struct zx_shps_GetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_GetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_GetStatusResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_GetStatusResponseItem
#define EL_STRUCT zx_shps_GetStatusResponseItem_s
#define EL_NS     shps
#define EL_TAG    GetStatusResponseItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_GetStatusResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_GetStatusResponseItem(struct zx_ctx* c, struct zx_shps_GetStatusResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:GetStatusResponseItem")-1 + 1 + sizeof("</shps:GetStatusResponseItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->ServiceStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceStatus")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:GetStatusResponseItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_GetStatusResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_GetStatusResponseItem(struct zx_ctx* c, struct zx_shps_GetStatusResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetStatusResponseItem")-1 + 1 + 2 + sizeof("GetStatusResponseItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);
  for (se = x->ServiceStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceStatus")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:GetStatusResponseItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_GetStatusResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_GetStatusResponseItem(struct zx_ctx* c, struct zx_shps_GetStatusResponseItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:GetStatusResponseItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->ServiceStatus; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceStatus", sizeof("shps:ServiceStatus")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:GetStatusResponseItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:GetStatusResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_GetStatusResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_GetStatusResponseItem(struct zx_ctx* c, struct zx_shps_GetStatusResponseItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "GetStatusResponseItem", sizeof("GetStatusResponseItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:GetStatusResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_GetStatusResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_GetStatusResponseItem(struct zx_ctx* c, struct zx_shps_GetStatusResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_GetStatusResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_GetStatusResponseItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_GetStatusResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_GetStatusResponseItem(struct zx_ctx* c, struct zx_shps_GetStatusResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_GetStatusResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_GetStatusResponseItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_InvocationContext
#define EL_STRUCT zx_shps_InvocationContext_s
#define EL_NS     shps
#define EL_TAG    InvocationContext

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_InvocationContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_InvocationContext(struct zx_ctx* c, struct zx_shps_InvocationContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:InvocationContext")-1 + 1 + sizeof("</shps:InvocationContext>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->InvokingProvider; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:InvokingProvider")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->InvokingPrincipal; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:InvokingPrincipal")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("di:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_di);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvocationContext", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_InvocationContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_InvocationContext(struct zx_ctx* c, struct zx_shps_InvocationContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InvocationContext")-1 + 1 + 2 + sizeof("InvocationContext")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->InvokingProvider; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("InvokingProvider")-1);
  for (se = x->InvokingPrincipal; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("InvokingPrincipal")-1);
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SecurityMechID")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvocationContext", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_InvocationContext) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_InvocationContext(struct zx_ctx* c, struct zx_shps_InvocationContext_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:InvocationContext");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->InvokingProvider; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:InvokingProvider", sizeof("shps:InvokingProvider")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->InvokingPrincipal; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:InvokingPrincipal", sizeof("shps:InvokingPrincipal")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "di:SecurityMechID", sizeof("di:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_di);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:InvocationContext>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvocationContext", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_InvocationContext) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_InvocationContext(struct zx_ctx* c, struct zx_shps_InvocationContext_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "InvocationContext", sizeof("InvocationContext")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvocationContext", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_InvocationContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_InvocationContext(struct zx_ctx* c, struct zx_shps_InvocationContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_InvocationContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_InvocationContext(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_InvocationContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_InvocationContext(struct zx_ctx* c, struct zx_shps_InvocationContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_InvocationContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_InvocationContext(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_InvokeItem
#define EL_STRUCT zx_shps_InvokeItem_s
#define EL_NS     shps
#define EL_TAG    InvokeItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_InvokeItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_InvokeItem(struct zx_ctx* c, struct zx_shps_InvokeItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:InvokeItem")-1 + 1 + sizeof("</shps:InvokeItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvokeItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_InvokeItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_InvokeItem(struct zx_ctx* c, struct zx_shps_InvokeItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InvokeItem")-1 + 1 + 2 + sizeof("InvokeItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvokeItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_InvokeItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_InvokeItem(struct zx_ctx* c, struct zx_shps_InvokeItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:InvokeItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:InvokeItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvokeItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_InvokeItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_InvokeItem(struct zx_ctx* c, struct zx_shps_InvokeItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "InvokeItem", sizeof("InvokeItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvokeItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_InvokeItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_InvokeItem(struct zx_ctx* c, struct zx_shps_InvokeItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_InvokeItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_InvokeItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_InvokeItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_InvokeItem(struct zx_ctx* c, struct zx_shps_InvokeItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_InvokeItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_InvokeItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_InvokeResponse
#define EL_STRUCT zx_shps_InvokeResponse_s
#define EL_NS     shps
#define EL_TAG    InvokeResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_InvokeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_InvokeResponse(struct zx_ctx* c, struct zx_shps_InvokeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:InvokeResponse")-1 + 1 + sizeof("</shps:InvokeResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_shps_InvokeResponseItem_s* e;
      for (e = x->InvokeResponseItem; e; e = (struct zx_shps_InvokeResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_InvokeResponseItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvokeResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_InvokeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_InvokeResponse(struct zx_ctx* c, struct zx_shps_InvokeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InvokeResponse")-1 + 1 + 2 + sizeof("InvokeResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_shps_InvokeResponseItem_s* e;
      for (e = x->InvokeResponseItem; e; e = (struct zx_shps_InvokeResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_InvokeResponseItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvokeResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_InvokeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_InvokeResponse(struct zx_ctx* c, struct zx_shps_InvokeResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:InvokeResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_shps_InvokeResponseItem_s* e;
      for (e = x->InvokeResponseItem; e; e = (struct zx_shps_InvokeResponseItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_InvokeResponseItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:InvokeResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvokeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_InvokeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_InvokeResponse(struct zx_ctx* c, struct zx_shps_InvokeResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "InvokeResponse", sizeof("InvokeResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvokeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_InvokeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_InvokeResponse(struct zx_ctx* c, struct zx_shps_InvokeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_InvokeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_InvokeResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_InvokeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_InvokeResponse(struct zx_ctx* c, struct zx_shps_InvokeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_InvokeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_InvokeResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_InvokeResponseItem
#define EL_STRUCT zx_shps_InvokeResponseItem_s
#define EL_NS     shps
#define EL_TAG    InvokeResponseItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_InvokeResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_InvokeResponseItem(struct zx_ctx* c, struct zx_shps_InvokeResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:InvokeResponseItem")-1 + 1 + sizeof("</shps:InvokeResponseItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvokeResponseItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_InvokeResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_InvokeResponseItem(struct zx_ctx* c, struct zx_shps_InvokeResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InvokeResponseItem")-1 + 1 + 2 + sizeof("InvokeResponseItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:InvokeResponseItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_InvokeResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_InvokeResponseItem(struct zx_ctx* c, struct zx_shps_InvokeResponseItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:InvokeResponseItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:InvokeResponseItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvokeResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_InvokeResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_InvokeResponseItem(struct zx_ctx* c, struct zx_shps_InvokeResponseItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "InvokeResponseItem", sizeof("InvokeResponseItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:InvokeResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_InvokeResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_InvokeResponseItem(struct zx_ctx* c, struct zx_shps_InvokeResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_InvokeResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_InvokeResponseItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_InvokeResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_InvokeResponseItem(struct zx_ctx* c, struct zx_shps_InvokeResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_InvokeResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_InvokeResponseItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_Poll
#define EL_STRUCT zx_shps_Poll_s
#define EL_NS     shps
#define EL_TAG    Poll

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_Poll) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_Poll(struct zx_ctx* c, struct zx_shps_Poll_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:Poll")-1 + 1 + sizeof("</shps:Poll>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->wait, sizeof("wait")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_Action(c, e);
  }
  {
      struct zx_dp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_dp_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_dp_Response(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Poll", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_Poll) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_Poll(struct zx_ctx* c, struct zx_shps_Poll_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Poll")-1 + 1 + 2 + sizeof("Poll")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->wait, sizeof("wait")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_Action(c, e);
  }
  {
      struct zx_dp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_dp_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_dp_Response(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Poll", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_Poll) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_Poll(struct zx_ctx* c, struct zx_shps_Poll_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:Poll");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->wait, " wait=\"", sizeof(" wait=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_Action(c, e, p);
  }
  {
      struct zx_dp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_dp_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_dp_Response(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:Poll>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Poll", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_Poll) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_Poll(struct zx_ctx* c, struct zx_shps_Poll_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Poll", sizeof("Poll")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->wait, "wait=\"", sizeof("wait=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Poll", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_Poll) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_Poll(struct zx_ctx* c, struct zx_shps_Poll_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_Poll(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_Poll(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_Poll) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_Poll(struct zx_ctx* c, struct zx_shps_Poll_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_Poll(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_Poll(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_PollResponse
#define EL_STRUCT zx_shps_PollResponse_s
#define EL_NS     shps
#define EL_TAG    PollResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_PollResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_PollResponse(struct zx_ctx* c, struct zx_shps_PollResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:PollResponse")-1 + 1 + sizeof("</shps:PollResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->nextPoll, sizeof("nextPoll")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dp_Request_s* e;
      for (e = x->Request; e; e = (struct zx_dp_Request_s*)e->gg.g.n)
	  len += zx_LEN_SO_dp_Request(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:PollResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_PollResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_PollResponse(struct zx_ctx* c, struct zx_shps_PollResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PollResponse")-1 + 1 + 2 + sizeof("PollResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->nextPoll, sizeof("nextPoll")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dp_Request_s* e;
      for (e = x->Request; e; e = (struct zx_dp_Request_s*)e->gg.g.n)
	  len += zx_LEN_WO_dp_Request(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:PollResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_PollResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_PollResponse(struct zx_ctx* c, struct zx_shps_PollResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:PollResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->nextPoll, " nextPoll=\"", sizeof(" nextPoll=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dp_Request_s* e;
      for (e = x->Request; e; e = (struct zx_dp_Request_s*)e->gg.g.n)
	  p = zx_ENC_SO_dp_Request(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:PollResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:PollResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_PollResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_PollResponse(struct zx_ctx* c, struct zx_shps_PollResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "PollResponse", sizeof("PollResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->nextPoll, "nextPoll=\"", sizeof("nextPoll=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:PollResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_PollResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_PollResponse(struct zx_ctx* c, struct zx_shps_PollResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_PollResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_PollResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_PollResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_PollResponse(struct zx_ctx* c, struct zx_shps_PollResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_PollResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_PollResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_ProxyInvoke
#define EL_STRUCT zx_shps_ProxyInvoke_s
#define EL_NS     shps
#define EL_TAG    ProxyInvoke

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_ProxyInvoke) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_ProxyInvoke(struct zx_ctx* c, struct zx_shps_ProxyInvoke_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:ProxyInvoke")-1 + 1 + sizeof("</shps:ProxyInvoke>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shps_ProxyInvokeItem_s* e;
      for (e = x->ProxyInvokeItem; e; e = (struct zx_shps_ProxyInvokeItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_ProxyInvokeItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvoke", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_ProxyInvoke) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_ProxyInvoke(struct zx_ctx* c, struct zx_shps_ProxyInvoke_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxyInvoke")-1 + 1 + 2 + sizeof("ProxyInvoke")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shps_ProxyInvokeItem_s* e;
      for (e = x->ProxyInvokeItem; e; e = (struct zx_shps_ProxyInvokeItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_ProxyInvokeItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvoke", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_ProxyInvoke) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_ProxyInvoke(struct zx_ctx* c, struct zx_shps_ProxyInvoke_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:ProxyInvoke");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_shps_ProxyInvokeItem_s* e;
      for (e = x->ProxyInvokeItem; e; e = (struct zx_shps_ProxyInvokeItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_ProxyInvokeItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:ProxyInvoke>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvoke", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_ProxyInvoke) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_ProxyInvoke(struct zx_ctx* c, struct zx_shps_ProxyInvoke_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ProxyInvoke", sizeof("ProxyInvoke")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvoke", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_ProxyInvoke) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_ProxyInvoke(struct zx_ctx* c, struct zx_shps_ProxyInvoke_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_ProxyInvoke(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_ProxyInvoke(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_ProxyInvoke) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_ProxyInvoke(struct zx_ctx* c, struct zx_shps_ProxyInvoke_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_ProxyInvoke(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_ProxyInvoke(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_ProxyInvokeItem
#define EL_STRUCT zx_shps_ProxyInvokeItem_s
#define EL_NS     shps
#define EL_TAG    ProxyInvokeItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_ProxyInvokeItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_ProxyInvokeItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:ProxyInvokeItem")-1 + 1 + sizeof("</shps:ProxyInvokeItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  {
      struct zx_shps_InvocationContext_s* e;
      for (e = x->InvocationContext; e; e = (struct zx_shps_InvocationContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_InvocationContext(c, e);
  }
  for (se = x->RequestHeaders; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:RequestHeaders")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_ProxyInvokeItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_ProxyInvokeItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxyInvokeItem")-1 + 1 + 2 + sizeof("ProxyInvokeItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);
  {
      struct zx_shps_InvocationContext_s* e;
      for (e = x->InvocationContext; e; e = (struct zx_shps_InvocationContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_InvocationContext(c, e);
  }
  for (se = x->RequestHeaders; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RequestHeaders")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_ProxyInvokeItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_ProxyInvokeItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:ProxyInvokeItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  {
      struct zx_shps_InvocationContext_s* e;
      for (e = x->InvocationContext; e; e = (struct zx_shps_InvocationContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_InvocationContext(c, e, p);
  }
  for (se = x->RequestHeaders; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:RequestHeaders", sizeof("shps:RequestHeaders")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:ProxyInvokeItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_ProxyInvokeItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_ProxyInvokeItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ProxyInvokeItem", sizeof("ProxyInvokeItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_ProxyInvokeItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_ProxyInvokeItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_ProxyInvokeItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_ProxyInvokeItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_ProxyInvokeItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_ProxyInvokeItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_ProxyInvokeItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_ProxyInvokeItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_ProxyInvokeResponse
#define EL_STRUCT zx_shps_ProxyInvokeResponse_s
#define EL_NS     shps
#define EL_TAG    ProxyInvokeResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_ProxyInvokeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_ProxyInvokeResponse(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:ProxyInvokeResponse")-1 + 1 + sizeof("</shps:ProxyInvokeResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_shps_ProxyInvokeResponseItem_s* e;
      for (e = x->ProxyInvokeResponseItem; e; e = (struct zx_shps_ProxyInvokeResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_ProxyInvokeResponseItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_ProxyInvokeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_ProxyInvokeResponse(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxyInvokeResponse")-1 + 1 + 2 + sizeof("ProxyInvokeResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_shps_ProxyInvokeResponseItem_s* e;
      for (e = x->ProxyInvokeResponseItem; e; e = (struct zx_shps_ProxyInvokeResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_ProxyInvokeResponseItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_ProxyInvokeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_ProxyInvokeResponse(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:ProxyInvokeResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_shps_ProxyInvokeResponseItem_s* e;
      for (e = x->ProxyInvokeResponseItem; e; e = (struct zx_shps_ProxyInvokeResponseItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_ProxyInvokeResponseItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:ProxyInvokeResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_ProxyInvokeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_ProxyInvokeResponse(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ProxyInvokeResponse", sizeof("ProxyInvokeResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_ProxyInvokeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_ProxyInvokeResponse(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_ProxyInvokeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_ProxyInvokeResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_ProxyInvokeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_ProxyInvokeResponse(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_ProxyInvokeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_ProxyInvokeResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_ProxyInvokeResponseItem
#define EL_STRUCT zx_shps_ProxyInvokeResponseItem_s
#define EL_NS     shps
#define EL_TAG    ProxyInvokeResponseItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_ProxyInvokeResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_ProxyInvokeResponseItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:ProxyInvokeResponseItem")-1 + 1 + sizeof("</shps:ProxyInvokeResponseItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->ResponseHeaders; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ResponseHeaders")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponseItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_ProxyInvokeResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_ProxyInvokeResponseItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxyInvokeResponseItem")-1 + 1 + 2 + sizeof("ProxyInvokeResponseItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);
  for (se = x->ResponseHeaders; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ResponseHeaders")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponseItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_ProxyInvokeResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_ProxyInvokeResponseItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponseItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:ProxyInvokeResponseItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->ResponseHeaders; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ResponseHeaders", sizeof("shps:ResponseHeaders")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:ProxyInvokeResponseItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_ProxyInvokeResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_ProxyInvokeResponseItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponseItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ProxyInvokeResponseItem", sizeof("ProxyInvokeResponseItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:ProxyInvokeResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_ProxyInvokeResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_ProxyInvokeResponseItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_ProxyInvokeResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_ProxyInvokeResponseItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_ProxyInvokeResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_ProxyInvokeResponseItem(struct zx_ctx* c, struct zx_shps_ProxyInvokeResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_ProxyInvokeResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_ProxyInvokeResponseItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_Query
#define EL_STRUCT zx_shps_Query_s
#define EL_NS     shps
#define EL_TAG    Query

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_Query(struct zx_ctx* c, struct zx_shps_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:Query")-1 + 1 + sizeof("</shps:Query>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_di_RequestedService_s* e;
      for (e = x->RequestedService; e; e = (struct zx_di_RequestedService_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_RequestedService(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Query", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_Query(struct zx_ctx* c, struct zx_shps_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Query")-1 + 1 + 2 + sizeof("Query")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_di_RequestedService_s* e;
      for (e = x->RequestedService; e; e = (struct zx_di_RequestedService_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_RequestedService(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Query", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_Query(struct zx_ctx* c, struct zx_shps_Query_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:Query");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_di_RequestedService_s* e;
      for (e = x->RequestedService; e; e = (struct zx_di_RequestedService_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_RequestedService(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:Query>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Query", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_Query(struct zx_ctx* c, struct zx_shps_Query_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Query", sizeof("Query")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Query", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_Query(struct zx_ctx* c, struct zx_shps_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_Query(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_Query(struct zx_ctx* c, struct zx_shps_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_Query(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_QueryRegistered
#define EL_STRUCT zx_shps_QueryRegistered_s
#define EL_NS     shps
#define EL_TAG    QueryRegistered

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_QueryRegistered) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_QueryRegistered(struct zx_ctx* c, struct zx_shps_QueryRegistered_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:QueryRegistered")-1 + 1 + sizeof("</shps:QueryRegistered>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:QueryRegistered", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_QueryRegistered) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_QueryRegistered(struct zx_ctx* c, struct zx_shps_QueryRegistered_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryRegistered")-1 + 1 + 2 + sizeof("QueryRegistered")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:QueryRegistered", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_QueryRegistered) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_QueryRegistered(struct zx_ctx* c, struct zx_shps_QueryRegistered_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:QueryRegistered");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:QueryRegistered>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:QueryRegistered", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_QueryRegistered) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_QueryRegistered(struct zx_ctx* c, struct zx_shps_QueryRegistered_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "QueryRegistered", sizeof("QueryRegistered")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:QueryRegistered", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_QueryRegistered) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_QueryRegistered(struct zx_ctx* c, struct zx_shps_QueryRegistered_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_QueryRegistered(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_QueryRegistered(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_QueryRegistered) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_QueryRegistered(struct zx_ctx* c, struct zx_shps_QueryRegistered_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_QueryRegistered(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_QueryRegistered(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_QueryRegisteredResponse
#define EL_STRUCT zx_shps_QueryRegisteredResponse_s
#define EL_NS     shps
#define EL_TAG    QueryRegisteredResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_QueryRegisteredResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_QueryRegisteredResponse(struct zx_ctx* c, struct zx_shps_QueryRegisteredResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:QueryRegisteredResponse")-1 + 1 + sizeof("</shps:QueryRegisteredResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_EndpointReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:QueryRegisteredResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_QueryRegisteredResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_QueryRegisteredResponse(struct zx_ctx* c, struct zx_shps_QueryRegisteredResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryRegisteredResponse")-1 + 1 + 2 + sizeof("QueryRegisteredResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_EndpointReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:QueryRegisteredResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_QueryRegisteredResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_QueryRegisteredResponse(struct zx_ctx* c, struct zx_shps_QueryRegisteredResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:QueryRegisteredResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_EndpointReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:QueryRegisteredResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:QueryRegisteredResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_QueryRegisteredResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_QueryRegisteredResponse(struct zx_ctx* c, struct zx_shps_QueryRegisteredResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "QueryRegisteredResponse", sizeof("QueryRegisteredResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:QueryRegisteredResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_QueryRegisteredResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_QueryRegisteredResponse(struct zx_ctx* c, struct zx_shps_QueryRegisteredResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_QueryRegisteredResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_QueryRegisteredResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_QueryRegisteredResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_QueryRegisteredResponse(struct zx_ctx* c, struct zx_shps_QueryRegisteredResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_QueryRegisteredResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_QueryRegisteredResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_QueryResponse
#define EL_STRUCT zx_shps_QueryResponse_s
#define EL_NS     shps
#define EL_TAG    QueryResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_QueryResponse(struct zx_ctx* c, struct zx_shps_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:QueryResponse")-1 + 1 + sizeof("</shps:QueryResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_EndpointReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:QueryResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_QueryResponse(struct zx_ctx* c, struct zx_shps_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryResponse")-1 + 1 + 2 + sizeof("QueryResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_EndpointReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:QueryResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_QueryResponse(struct zx_ctx* c, struct zx_shps_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:QueryResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_EndpointReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:QueryResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_QueryResponse(struct zx_ctx* c, struct zx_shps_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "QueryResponse", sizeof("QueryResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_QueryResponse(struct zx_ctx* c, struct zx_shps_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_QueryResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_QueryResponse(struct zx_ctx* c, struct zx_shps_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_QueryResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_Register
#define EL_STRUCT zx_shps_Register_s
#define EL_NS     shps
#define EL_TAG    Register

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_Register) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_Register(struct zx_ctx* c, struct zx_shps_Register_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:Register")-1 + 1 + sizeof("</shps:Register>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_EndpointReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Register", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_Register) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_Register(struct zx_ctx* c, struct zx_shps_Register_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Register")-1 + 1 + 2 + sizeof("Register")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_EndpointReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Register", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_Register) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_Register(struct zx_ctx* c, struct zx_shps_Register_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:Register");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_EndpointReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:Register>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Register", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_Register) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_Register(struct zx_ctx* c, struct zx_shps_Register_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Register", sizeof("Register")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Register", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_Register) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_Register(struct zx_ctx* c, struct zx_shps_Register_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_Register(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_Register(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_Register) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_Register(struct zx_ctx* c, struct zx_shps_Register_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_Register(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_Register(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_RegisterResponse
#define EL_STRUCT zx_shps_RegisterResponse_s
#define EL_NS     shps
#define EL_TAG    RegisterResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_RegisterResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_RegisterResponse(struct zx_ctx* c, struct zx_shps_RegisterResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:RegisterResponse")-1 + 1 + sizeof("</shps:RegisterResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_shps_RegisterResponseItem_s* e;
      for (e = x->RegisterResponseItem; e; e = (struct zx_shps_RegisterResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_RegisterResponseItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:RegisterResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_RegisterResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_RegisterResponse(struct zx_ctx* c, struct zx_shps_RegisterResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RegisterResponse")-1 + 1 + 2 + sizeof("RegisterResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_shps_RegisterResponseItem_s* e;
      for (e = x->RegisterResponseItem; e; e = (struct zx_shps_RegisterResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_RegisterResponseItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:RegisterResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_RegisterResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_RegisterResponse(struct zx_ctx* c, struct zx_shps_RegisterResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:RegisterResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_shps_RegisterResponseItem_s* e;
      for (e = x->RegisterResponseItem; e; e = (struct zx_shps_RegisterResponseItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_RegisterResponseItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:RegisterResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:RegisterResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_RegisterResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_RegisterResponse(struct zx_ctx* c, struct zx_shps_RegisterResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "RegisterResponse", sizeof("RegisterResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:RegisterResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_RegisterResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_RegisterResponse(struct zx_ctx* c, struct zx_shps_RegisterResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_RegisterResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_RegisterResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_RegisterResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_RegisterResponse(struct zx_ctx* c, struct zx_shps_RegisterResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_RegisterResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_RegisterResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_RegisterResponseItem
#define EL_STRUCT zx_shps_RegisterResponseItem_s
#define EL_NS     shps
#define EL_TAG    RegisterResponseItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_RegisterResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_RegisterResponseItem(struct zx_ctx* c, struct zx_shps_RegisterResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:RegisterResponseItem")-1 + 1 + sizeof("</shps:RegisterResponseItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:RegisterResponseItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_RegisterResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_RegisterResponseItem(struct zx_ctx* c, struct zx_shps_RegisterResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RegisterResponseItem")-1 + 1 + 2 + sizeof("RegisterResponseItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:RegisterResponseItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_RegisterResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_RegisterResponseItem(struct zx_ctx* c, struct zx_shps_RegisterResponseItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:RegisterResponseItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:RegisterResponseItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:RegisterResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_RegisterResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_RegisterResponseItem(struct zx_ctx* c, struct zx_shps_RegisterResponseItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "RegisterResponseItem", sizeof("RegisterResponseItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:RegisterResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_RegisterResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_RegisterResponseItem(struct zx_ctx* c, struct zx_shps_RegisterResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_RegisterResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_RegisterResponseItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_RegisterResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_RegisterResponseItem(struct zx_ctx* c, struct zx_shps_RegisterResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_RegisterResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_RegisterResponseItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_SetStatus
#define EL_STRUCT zx_shps_SetStatus_s
#define EL_NS     shps
#define EL_TAG    SetStatus

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_SetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_SetStatus(struct zx_ctx* c, struct zx_shps_SetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:SetStatus")-1 + 1 + sizeof("</shps:SetStatus>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shps_SetStatusItem_s* e;
      for (e = x->SetStatusItem; e; e = (struct zx_shps_SetStatusItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_SetStatusItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:SetStatus", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_SetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_SetStatus(struct zx_ctx* c, struct zx_shps_SetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SetStatus")-1 + 1 + 2 + sizeof("SetStatus")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shps_SetStatusItem_s* e;
      for (e = x->SetStatusItem; e; e = (struct zx_shps_SetStatusItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_SetStatusItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:SetStatus", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_SetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_SetStatus(struct zx_ctx* c, struct zx_shps_SetStatus_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:SetStatus");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_shps_SetStatusItem_s* e;
      for (e = x->SetStatusItem; e; e = (struct zx_shps_SetStatusItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_SetStatusItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:SetStatus>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:SetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_SetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_SetStatus(struct zx_ctx* c, struct zx_shps_SetStatus_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "SetStatus", sizeof("SetStatus")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:SetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_SetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_SetStatus(struct zx_ctx* c, struct zx_shps_SetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_SetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_SetStatus(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_SetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_SetStatus(struct zx_ctx* c, struct zx_shps_SetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_SetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_SetStatus(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_SetStatusItem
#define EL_STRUCT zx_shps_SetStatusItem_s
#define EL_NS     shps
#define EL_TAG    SetStatusItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_SetStatusItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_SetStatusItem(struct zx_ctx* c, struct zx_shps_SetStatusItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:SetStatusItem")-1 + 1 + sizeof("</shps:SetStatusItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceStatus")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:SetStatusItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_SetStatusItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_SetStatusItem(struct zx_ctx* c, struct zx_shps_SetStatusItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SetStatusItem")-1 + 1 + 2 + sizeof("SetStatusItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceStatus")-1);
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:SetStatusItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_SetStatusItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_SetStatusItem(struct zx_ctx* c, struct zx_shps_SetStatusItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:SetStatusItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceStatus; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceStatus", sizeof("shps:ServiceStatus")-1, zx_ns_tab+zx_xmlns_ix_shps);
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:SetStatusItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:SetStatusItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_SetStatusItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_SetStatusItem(struct zx_ctx* c, struct zx_shps_SetStatusItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "SetStatusItem", sizeof("SetStatusItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:SetStatusItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_SetStatusItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_SetStatusItem(struct zx_ctx* c, struct zx_shps_SetStatusItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_SetStatusItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_SetStatusItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_SetStatusItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_SetStatusItem(struct zx_ctx* c, struct zx_shps_SetStatusItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_SetStatusItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_SetStatusItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_SetStatusResponse
#define EL_STRUCT zx_shps_SetStatusResponse_s
#define EL_NS     shps
#define EL_TAG    SetStatusResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_SetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_SetStatusResponse(struct zx_ctx* c, struct zx_shps_SetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:SetStatusResponse")-1 + 1 + sizeof("</shps:SetStatusResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:SetStatusResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_SetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_SetStatusResponse(struct zx_ctx* c, struct zx_shps_SetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SetStatusResponse")-1 + 1 + 2 + sizeof("SetStatusResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:SetStatusResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_SetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_SetStatusResponse(struct zx_ctx* c, struct zx_shps_SetStatusResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:SetStatusResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:SetStatusResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:SetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_SetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_SetStatusResponse(struct zx_ctx* c, struct zx_shps_SetStatusResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "SetStatusResponse", sizeof("SetStatusResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:SetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_SetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_SetStatusResponse(struct zx_ctx* c, struct zx_shps_SetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_SetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_SetStatusResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_SetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_SetStatusResponse(struct zx_ctx* c, struct zx_shps_SetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_SetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_SetStatusResponse(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_Update
#define EL_STRUCT zx_shps_Update_s
#define EL_NS     shps
#define EL_TAG    Update

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_Update) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_Update(struct zx_ctx* c, struct zx_shps_Update_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:Update")-1 + 1 + sizeof("</shps:Update>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shps_UpdateItem_s* e;
      for (e = x->UpdateItem; e; e = (struct zx_shps_UpdateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_UpdateItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Update", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_Update) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_Update(struct zx_ctx* c, struct zx_shps_Update_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Update")-1 + 1 + 2 + sizeof("Update")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shps_UpdateItem_s* e;
      for (e = x->UpdateItem; e; e = (struct zx_shps_UpdateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_UpdateItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:Update", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_Update) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_Update(struct zx_ctx* c, struct zx_shps_Update_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:Update");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_shps_UpdateItem_s* e;
      for (e = x->UpdateItem; e; e = (struct zx_shps_UpdateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_UpdateItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:Update>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Update", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_Update) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_Update(struct zx_ctx* c, struct zx_shps_Update_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Update", sizeof("Update")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:Update", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_Update) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_Update(struct zx_ctx* c, struct zx_shps_Update_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_Update(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_Update(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_Update) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_Update(struct zx_ctx* c, struct zx_shps_Update_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_Update(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_Update(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_UpdateItem
#define EL_STRUCT zx_shps_UpdateItem_s
#define EL_NS     shps
#define EL_TAG    UpdateItem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_UpdateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_UpdateItem(struct zx_ctx* c, struct zx_shps_UpdateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:UpdateItem")-1 + 1 + sizeof("</shps:UpdateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_EndpointReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:UpdateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_UpdateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_UpdateItem(struct zx_ctx* c, struct zx_shps_UpdateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UpdateItem")-1 + 1 + 2 + sizeof("UpdateItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ServiceHandle")-1);
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_EndpointReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:UpdateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_UpdateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_UpdateItem(struct zx_ctx* c, struct zx_shps_UpdateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:UpdateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ServiceHandle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:ServiceHandle", sizeof("shps:ServiceHandle")-1, zx_ns_tab+zx_xmlns_ix_shps);
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_EndpointReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:UpdateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:UpdateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_UpdateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_UpdateItem(struct zx_ctx* c, struct zx_shps_UpdateItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "UpdateItem", sizeof("UpdateItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:UpdateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_UpdateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_UpdateItem(struct zx_ctx* c, struct zx_shps_UpdateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_UpdateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_UpdateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_UpdateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_UpdateItem(struct zx_ctx* c, struct zx_shps_UpdateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_UpdateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_UpdateItem(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   shps_UpdateResponse
#define EL_STRUCT zx_shps_UpdateResponse_s
#define EL_NS     shps
#define EL_TAG    UpdateResponse

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_shps_UpdateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_shps_UpdateResponse(struct zx_ctx* c, struct zx_shps_UpdateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<shps:UpdateResponse")-1 + 1 + sizeof("</shps:UpdateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:UpdateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_shps_UpdateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_shps_UpdateResponse(struct zx_ctx* c, struct zx_shps_UpdateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UpdateResponse")-1 + 1 + 2 + sizeof("UpdateResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "shps:UpdateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_shps_UpdateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_shps_UpdateResponse(struct zx_ctx* c, struct zx_shps_UpdateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<shps:UpdateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_shps, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</shps:UpdateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:UpdateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_shps_UpdateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_shps_UpdateResponse(struct zx_ctx* c, struct zx_shps_UpdateResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "UpdateResponse", sizeof("UpdateResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "shps:UpdateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_shps_UpdateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_shps_UpdateResponse(struct zx_ctx* c, struct zx_shps_UpdateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_shps_UpdateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_shps_UpdateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_shps_UpdateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_shps_UpdateResponse(struct zx_ctx* c, struct zx_shps_UpdateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_shps_UpdateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_shps_UpdateResponse(c, x, buf ), buf, len);
}




/* EOF -- c/zx-shps-enc.c */
