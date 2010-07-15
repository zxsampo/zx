/* c/zx-pmm-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-pmm-data.h"
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

#define EL_NAME   pmm_PMActivate
#define EL_STRUCT zx_pmm_PMActivate_s
#define EL_NS     pmm
#define EL_TAG    PMActivate

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

/* FUNC(zx_LEN_SO_pmm_PMActivate) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMActivate(struct zx_ctx* c, struct zx_pmm_PMActivate_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMActivate")-1 + 1 + sizeof("</pmm:PMActivate>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_pmm_PMActivateItem_s* e;
      for (e = x->PMActivateItem; e; e = (struct zx_pmm_PMActivateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMActivateItem(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMActivate", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMActivate) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMActivate(struct zx_ctx* c, struct zx_pmm_PMActivate_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMActivate")-1 + 1 + 2 + sizeof("PMActivate")-1 + 1;
  
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
      struct zx_pmm_PMActivateItem_s* e;
      for (e = x->PMActivateItem; e; e = (struct zx_pmm_PMActivateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMActivateItem(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NotifyTo")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMActivate", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMActivate) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMActivate(struct zx_ctx* c, struct zx_pmm_PMActivate_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMActivate");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_pmm_PMActivateItem_s* e;
      for (e = x->PMActivateItem; e; e = (struct zx_pmm_PMActivateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMActivateItem(c, e, p);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dp:NotifyTo", sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMActivate>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMActivate", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMActivate) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMActivate(struct zx_ctx* c, struct zx_pmm_PMActivate_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMActivate", sizeof("PMActivate")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMActivate", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMActivate) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMActivate(struct zx_ctx* c, struct zx_pmm_PMActivate_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMActivate(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMActivate(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMActivate) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMActivate(struct zx_ctx* c, struct zx_pmm_PMActivate_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMActivate(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMActivate(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMActivateItem
#define EL_STRUCT zx_pmm_PMActivateItem_s
#define EL_NS     pmm
#define EL_TAG    PMActivateItem

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

/* FUNC(zx_LEN_SO_pmm_PMActivateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMActivateItem(struct zx_ctx* c, struct zx_pmm_PMActivateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMActivateItem")-1 + 1 + sizeof("</pmm:PMActivateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  len += zx_attr_so_len(x->at, sizeof("at")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMID(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMActivateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMActivateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMActivateItem(struct zx_ctx* c, struct zx_pmm_PMActivateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMActivateItem")-1 + 1 + 2 + sizeof("PMActivateItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->at, sizeof("at")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMID(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMActivateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMActivateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMActivateItem(struct zx_ctx* c, struct zx_pmm_PMActivateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMActivateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  p = zx_attr_so_enc(p, x->at, " at=\"", sizeof(" at=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMID(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMActivateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMActivateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMActivateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMActivateItem(struct zx_ctx* c, struct zx_pmm_PMActivateItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMActivateItem", sizeof("PMActivateItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->at, "at=\"", sizeof("at=\"")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMActivateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMActivateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMActivateItem(struct zx_ctx* c, struct zx_pmm_PMActivateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMActivateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMActivateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMActivateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMActivateItem(struct zx_ctx* c, struct zx_pmm_PMActivateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMActivateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMActivateItem(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMActivateResponse
#define EL_STRUCT zx_pmm_PMActivateResponse_s
#define EL_NS     pmm
#define EL_TAG    PMActivateResponse

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

/* FUNC(zx_LEN_SO_pmm_PMActivateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMActivateResponse(struct zx_ctx* c, struct zx_pmm_PMActivateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMActivateResponse")-1 + 1 + sizeof("</pmm:PMActivateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ENC_LEN_DEBUG(x, "pmm:PMActivateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMActivateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMActivateResponse(struct zx_ctx* c, struct zx_pmm_PMActivateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMActivateResponse")-1 + 1 + 2 + sizeof("PMActivateResponse")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "pmm:PMActivateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMActivateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMActivateResponse(struct zx_ctx* c, struct zx_pmm_PMActivateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMActivateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMActivateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMActivateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMActivateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMActivateResponse(struct zx_ctx* c, struct zx_pmm_PMActivateResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMActivateResponse", sizeof("PMActivateResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMActivateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMActivateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMActivateResponse(struct zx_ctx* c, struct zx_pmm_PMActivateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMActivateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMActivateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMActivateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMActivateResponse(struct zx_ctx* c, struct zx_pmm_PMActivateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMActivateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMActivateResponse(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMDeactivate
#define EL_STRUCT zx_pmm_PMDeactivate_s
#define EL_NS     pmm
#define EL_TAG    PMDeactivate

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

/* FUNC(zx_LEN_SO_pmm_PMDeactivate) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMDeactivate(struct zx_ctx* c, struct zx_pmm_PMDeactivate_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMDeactivate")-1 + 1 + sizeof("</pmm:PMDeactivate>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_pmm_PMDeactivateItem_s* e;
      for (e = x->PMDeactivateItem; e; e = (struct zx_pmm_PMDeactivateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMDeactivateItem(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDeactivate", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMDeactivate) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMDeactivate(struct zx_ctx* c, struct zx_pmm_PMDeactivate_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMDeactivate")-1 + 1 + 2 + sizeof("PMDeactivate")-1 + 1;
  
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
      struct zx_pmm_PMDeactivateItem_s* e;
      for (e = x->PMDeactivateItem; e; e = (struct zx_pmm_PMDeactivateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMDeactivateItem(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NotifyTo")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDeactivate", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMDeactivate) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMDeactivate(struct zx_ctx* c, struct zx_pmm_PMDeactivate_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMDeactivate");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_pmm_PMDeactivateItem_s* e;
      for (e = x->PMDeactivateItem; e; e = (struct zx_pmm_PMDeactivateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMDeactivateItem(c, e, p);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dp:NotifyTo", sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMDeactivate>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMDeactivate", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMDeactivate) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMDeactivate(struct zx_ctx* c, struct zx_pmm_PMDeactivate_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMDeactivate", sizeof("PMDeactivate")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMDeactivate", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMDeactivate) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMDeactivate(struct zx_ctx* c, struct zx_pmm_PMDeactivate_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMDeactivate(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMDeactivate(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMDeactivate) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMDeactivate(struct zx_ctx* c, struct zx_pmm_PMDeactivate_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMDeactivate(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMDeactivate(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMDeactivateItem
#define EL_STRUCT zx_pmm_PMDeactivateItem_s
#define EL_NS     pmm
#define EL_TAG    PMDeactivateItem

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

/* FUNC(zx_LEN_SO_pmm_PMDeactivateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMDeactivateItem(struct zx_ctx* c, struct zx_pmm_PMDeactivateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMDeactivateItem")-1 + 1 + sizeof("</pmm:PMDeactivateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  len += zx_attr_so_len(x->at, sizeof("at")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMID(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMDeactivateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMDeactivateItem(struct zx_ctx* c, struct zx_pmm_PMDeactivateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMDeactivateItem")-1 + 1 + 2 + sizeof("PMDeactivateItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->at, sizeof("at")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMID(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMDeactivateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMDeactivateItem(struct zx_ctx* c, struct zx_pmm_PMDeactivateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMDeactivateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  p = zx_attr_so_enc(p, x->at, " at=\"", sizeof(" at=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMID(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMDeactivateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMDeactivateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMDeactivateItem(struct zx_ctx* c, struct zx_pmm_PMDeactivateItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMDeactivateItem", sizeof("PMDeactivateItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->at, "at=\"", sizeof("at=\"")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMDeactivateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMDeactivateItem(struct zx_ctx* c, struct zx_pmm_PMDeactivateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMDeactivateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMDeactivateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMDeactivateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMDeactivateItem(struct zx_ctx* c, struct zx_pmm_PMDeactivateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMDeactivateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMDeactivateItem(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMDeactivateResponse
#define EL_STRUCT zx_pmm_PMDeactivateResponse_s
#define EL_NS     pmm
#define EL_TAG    PMDeactivateResponse

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

/* FUNC(zx_LEN_SO_pmm_PMDeactivateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMDeactivateResponse(struct zx_ctx* c, struct zx_pmm_PMDeactivateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMDeactivateResponse")-1 + 1 + sizeof("</pmm:PMDeactivateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMDeactivateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMDeactivateResponse(struct zx_ctx* c, struct zx_pmm_PMDeactivateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMDeactivateResponse")-1 + 1 + 2 + sizeof("PMDeactivateResponse")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMDeactivateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMDeactivateResponse(struct zx_ctx* c, struct zx_pmm_PMDeactivateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMDeactivateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMDeactivateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMDeactivateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMDeactivateResponse(struct zx_ctx* c, struct zx_pmm_PMDeactivateResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMDeactivateResponse", sizeof("PMDeactivateResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMDeactivateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMDeactivateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMDeactivateResponse(struct zx_ctx* c, struct zx_pmm_PMDeactivateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMDeactivateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMDeactivateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMDeactivateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMDeactivateResponse(struct zx_ctx* c, struct zx_pmm_PMDeactivateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMDeactivateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMDeactivateResponse(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMDelete
#define EL_STRUCT zx_pmm_PMDelete_s
#define EL_NS     pmm
#define EL_TAG    PMDelete

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

/* FUNC(zx_LEN_SO_pmm_PMDelete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMDelete(struct zx_ctx* c, struct zx_pmm_PMDelete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMDelete")-1 + 1 + sizeof("</pmm:PMDelete>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_pmm_PMDeleteItem_s* e;
      for (e = x->PMDeleteItem; e; e = (struct zx_pmm_PMDeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMDeleteItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDelete", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMDelete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMDelete(struct zx_ctx* c, struct zx_pmm_PMDelete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMDelete")-1 + 1 + 2 + sizeof("PMDelete")-1 + 1;
  
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
      struct zx_pmm_PMDeleteItem_s* e;
      for (e = x->PMDeleteItem; e; e = (struct zx_pmm_PMDeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMDeleteItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDelete", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMDelete) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMDelete(struct zx_ctx* c, struct zx_pmm_PMDelete_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMDelete");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_pmm_PMDeleteItem_s* e;
      for (e = x->PMDeleteItem; e; e = (struct zx_pmm_PMDeleteItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMDeleteItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMDelete>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMDelete", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMDelete) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMDelete(struct zx_ctx* c, struct zx_pmm_PMDelete_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMDelete", sizeof("PMDelete")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMDelete", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMDelete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMDelete(struct zx_ctx* c, struct zx_pmm_PMDelete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMDelete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMDelete(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMDelete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMDelete(struct zx_ctx* c, struct zx_pmm_PMDelete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMDelete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMDelete(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMDeleteItem
#define EL_STRUCT zx_pmm_PMDeleteItem_s
#define EL_NS     pmm
#define EL_TAG    PMDeleteItem

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

/* FUNC(zx_LEN_SO_pmm_PMDeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMDeleteItem(struct zx_ctx* c, struct zx_pmm_PMDeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMDeleteItem")-1 + 1 + sizeof("</pmm:PMDeleteItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMID(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDeleteItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMDeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMDeleteItem(struct zx_ctx* c, struct zx_pmm_PMDeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMDeleteItem")-1 + 1 + 2 + sizeof("PMDeleteItem")-1 + 1;
  
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
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMID(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMDeleteItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMDeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMDeleteItem(struct zx_ctx* c, struct zx_pmm_PMDeleteItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMDeleteItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMID(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMDeleteItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMDeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMDeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMDeleteItem(struct zx_ctx* c, struct zx_pmm_PMDeleteItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMDeleteItem", sizeof("PMDeleteItem")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMDeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMDeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMDeleteItem(struct zx_ctx* c, struct zx_pmm_PMDeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMDeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMDeleteItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMDeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMDeleteItem(struct zx_ctx* c, struct zx_pmm_PMDeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMDeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMDeleteItem(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMDeleteResponse
#define EL_STRUCT zx_pmm_PMDeleteResponse_s
#define EL_NS     pmm
#define EL_TAG    PMDeleteResponse

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

/* FUNC(zx_LEN_SO_pmm_PMDeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMDeleteResponse(struct zx_ctx* c, struct zx_pmm_PMDeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMDeleteResponse")-1 + 1 + sizeof("</pmm:PMDeleteResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ENC_LEN_DEBUG(x, "pmm:PMDeleteResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMDeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMDeleteResponse(struct zx_ctx* c, struct zx_pmm_PMDeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMDeleteResponse")-1 + 1 + 2 + sizeof("PMDeleteResponse")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "pmm:PMDeleteResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMDeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMDeleteResponse(struct zx_ctx* c, struct zx_pmm_PMDeleteResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMDeleteResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMDeleteResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMDeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMDeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMDeleteResponse(struct zx_ctx* c, struct zx_pmm_PMDeleteResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMDeleteResponse", sizeof("PMDeleteResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMDeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMDeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMDeleteResponse(struct zx_ctx* c, struct zx_pmm_PMDeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMDeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMDeleteResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMDeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMDeleteResponse(struct zx_ctx* c, struct zx_pmm_PMDeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMDeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMDeleteResponse(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMGetStatus
#define EL_STRUCT zx_pmm_PMGetStatus_s
#define EL_NS     pmm
#define EL_TAG    PMGetStatus

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

/* FUNC(zx_LEN_SO_pmm_PMGetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMGetStatus(struct zx_ctx* c, struct zx_pmm_PMGetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMGetStatus")-1 + 1 + sizeof("</pmm:PMGetStatus>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMID(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMGetStatus", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMGetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMGetStatus(struct zx_ctx* c, struct zx_pmm_PMGetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMGetStatus")-1 + 1 + 2 + sizeof("PMGetStatus")-1 + 1;
  
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
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMID(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMGetStatus", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMGetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMGetStatus(struct zx_ctx* c, struct zx_pmm_PMGetStatus_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMGetStatus");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMID(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMGetStatus>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMGetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMGetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMGetStatus(struct zx_ctx* c, struct zx_pmm_PMGetStatus_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMGetStatus", sizeof("PMGetStatus")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMGetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMGetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMGetStatus(struct zx_ctx* c, struct zx_pmm_PMGetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMGetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMGetStatus(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMGetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMGetStatus(struct zx_ctx* c, struct zx_pmm_PMGetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMGetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMGetStatus(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMGetStatusResponse
#define EL_STRUCT zx_pmm_PMGetStatusResponse_s
#define EL_NS     pmm
#define EL_TAG    PMGetStatusResponse

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

/* FUNC(zx_LEN_SO_pmm_PMGetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMGetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMGetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMGetStatusResponse")-1 + 1 + sizeof("</pmm:PMGetStatusResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMStatus(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMGetStatusResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMGetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMGetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMGetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMGetStatusResponse")-1 + 1 + 2 + sizeof("PMGetStatusResponse")-1 + 1;
  
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
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMStatus(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMGetStatusResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMGetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMGetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMGetStatusResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMGetStatusResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMStatus(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMGetStatusResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMGetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMGetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMGetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMGetStatusResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMGetStatusResponse", sizeof("PMGetStatusResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMGetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMGetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMGetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMGetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMGetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMGetStatusResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMGetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMGetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMGetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMGetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMGetStatusResponse(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMSetStatus
#define EL_STRUCT zx_pmm_PMSetStatus_s
#define EL_NS     pmm
#define EL_TAG    PMSetStatus

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

/* FUNC(zx_LEN_SO_pmm_PMSetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMSetStatus(struct zx_ctx* c, struct zx_pmm_PMSetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMSetStatus")-1 + 1 + sizeof("</pmm:PMSetStatus>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMStatus(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMSetStatus", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMSetStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMSetStatus(struct zx_ctx* c, struct zx_pmm_PMSetStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMSetStatus")-1 + 1 + 2 + sizeof("PMSetStatus")-1 + 1;
  
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
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMStatus(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMSetStatus", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMSetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMSetStatus(struct zx_ctx* c, struct zx_pmm_PMSetStatus_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMSetStatus");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMStatus(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMSetStatus>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMSetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMSetStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMSetStatus(struct zx_ctx* c, struct zx_pmm_PMSetStatus_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMSetStatus", sizeof("PMSetStatus")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMSetStatus", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMSetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMSetStatus(struct zx_ctx* c, struct zx_pmm_PMSetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMSetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMSetStatus(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMSetStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMSetStatus(struct zx_ctx* c, struct zx_pmm_PMSetStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMSetStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMSetStatus(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMSetStatusResponse
#define EL_STRUCT zx_pmm_PMSetStatusResponse_s
#define EL_NS     pmm
#define EL_TAG    PMSetStatusResponse

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

/* FUNC(zx_LEN_SO_pmm_PMSetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMSetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMSetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMSetStatusResponse")-1 + 1 + sizeof("</pmm:PMSetStatusResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ENC_LEN_DEBUG(x, "pmm:PMSetStatusResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMSetStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMSetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMSetStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMSetStatusResponse")-1 + 1 + 2 + sizeof("PMSetStatusResponse")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "pmm:PMSetStatusResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMSetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMSetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMSetStatusResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMSetStatusResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMSetStatusResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMSetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMSetStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMSetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMSetStatusResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMSetStatusResponse", sizeof("PMSetStatusResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMSetStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMSetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMSetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMSetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMSetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMSetStatusResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMSetStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMSetStatusResponse(struct zx_ctx* c, struct zx_pmm_PMSetStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMSetStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMSetStatusResponse(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMUpdate
#define EL_STRUCT zx_pmm_PMUpdate_s
#define EL_NS     pmm
#define EL_TAG    PMUpdate

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

/* FUNC(zx_LEN_SO_pmm_PMUpdate) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMUpdate(struct zx_ctx* c, struct zx_pmm_PMUpdate_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMUpdate")-1 + 1 + sizeof("</pmm:PMUpdate>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_pmm_PMUpdateItem_s* e;
      for (e = x->PMUpdateItem; e; e = (struct zx_pmm_PMUpdateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMUpdateItem(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMUpdate", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMUpdate) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMUpdate(struct zx_ctx* c, struct zx_pmm_PMUpdate_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMUpdate")-1 + 1 + 2 + sizeof("PMUpdate")-1 + 1;
  
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
      struct zx_pmm_PMUpdateItem_s* e;
      for (e = x->PMUpdateItem; e; e = (struct zx_pmm_PMUpdateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMUpdateItem(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NotifyTo")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMUpdate", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMUpdate) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMUpdate(struct zx_ctx* c, struct zx_pmm_PMUpdate_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMUpdate");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_pmm_PMUpdateItem_s* e;
      for (e = x->PMUpdateItem; e; e = (struct zx_pmm_PMUpdateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMUpdateItem(c, e, p);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dp:NotifyTo", sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMUpdate>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMUpdate", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMUpdate) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMUpdate(struct zx_ctx* c, struct zx_pmm_PMUpdate_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMUpdate", sizeof("PMUpdate")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMUpdate", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMUpdate) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMUpdate(struct zx_ctx* c, struct zx_pmm_PMUpdate_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMUpdate(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMUpdate(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMUpdate) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMUpdate(struct zx_ctx* c, struct zx_pmm_PMUpdate_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMUpdate(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMUpdate(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMUpdateItem
#define EL_STRUCT zx_pmm_PMUpdateItem_s
#define EL_NS     pmm
#define EL_TAG    PMUpdateItem

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

/* FUNC(zx_LEN_SO_pmm_PMUpdateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMUpdateItem(struct zx_ctx* c, struct zx_pmm_PMUpdateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMUpdateItem")-1 + 1 + sizeof("</pmm:PMUpdateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  len += zx_attr_so_len(x->at, sizeof("at")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMDescriptor(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMUpdateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMUpdateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMUpdateItem(struct zx_ctx* c, struct zx_pmm_PMUpdateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMUpdateItem")-1 + 1 + 2 + sizeof("PMUpdateItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->at, sizeof("at")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMDescriptor(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:PMUpdateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMUpdateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMUpdateItem(struct zx_ctx* c, struct zx_pmm_PMUpdateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMUpdateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  p = zx_attr_so_enc(p, x->at, " at=\"", sizeof(" at=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMDescriptor(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMUpdateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMUpdateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMUpdateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMUpdateItem(struct zx_ctx* c, struct zx_pmm_PMUpdateItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMUpdateItem", sizeof("PMUpdateItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->at, "at=\"", sizeof("at=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "pmm:PMUpdateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMUpdateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMUpdateItem(struct zx_ctx* c, struct zx_pmm_PMUpdateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMUpdateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMUpdateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMUpdateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMUpdateItem(struct zx_ctx* c, struct zx_pmm_PMUpdateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMUpdateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMUpdateItem(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_PMUpdateResponse
#define EL_STRUCT zx_pmm_PMUpdateResponse_s
#define EL_NS     pmm
#define EL_TAG    PMUpdateResponse

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

/* FUNC(zx_LEN_SO_pmm_PMUpdateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_PMUpdateResponse(struct zx_ctx* c, struct zx_pmm_PMUpdateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:PMUpdateResponse")-1 + 1 + sizeof("</pmm:PMUpdateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ENC_LEN_DEBUG(x, "pmm:PMUpdateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_PMUpdateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_PMUpdateResponse(struct zx_ctx* c, struct zx_pmm_PMUpdateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PMUpdateResponse")-1 + 1 + 2 + sizeof("PMUpdateResponse")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "pmm:PMUpdateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_PMUpdateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_PMUpdateResponse(struct zx_ctx* c, struct zx_pmm_PMUpdateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:PMUpdateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</pmm:PMUpdateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:PMUpdateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_PMUpdateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_PMUpdateResponse(struct zx_ctx* c, struct zx_pmm_PMUpdateResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "PMUpdateResponse", sizeof("PMUpdateResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:PMUpdateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_PMUpdateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_PMUpdateResponse(struct zx_ctx* c, struct zx_pmm_PMUpdateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_PMUpdateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_PMUpdateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_PMUpdateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_PMUpdateResponse(struct zx_ctx* c, struct zx_pmm_PMUpdateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_PMUpdateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_PMUpdateResponse(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_Provision
#define EL_STRUCT zx_pmm_Provision_s
#define EL_NS     pmm
#define EL_TAG    Provision

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

/* FUNC(zx_LEN_SO_pmm_Provision) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_Provision(struct zx_ctx* c, struct zx_pmm_Provision_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:Provision")-1 + 1 + sizeof("</pmm:Provision>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  len += zx_attr_so_len(x->wait, sizeof("wait")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_prov_ProvisioningHandle_s* e;
      for (e = x->ProvisioningHandle; e; e = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_ProvisioningHandle(c, e);
  }
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMDescriptor(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:Provision", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_Provision) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_Provision(struct zx_ctx* c, struct zx_pmm_Provision_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Provision")-1 + 1 + 2 + sizeof("Provision")-1 + 1;
  
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
      struct zx_prov_ProvisioningHandle_s* e;
      for (e = x->ProvisioningHandle; e; e = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_ProvisioningHandle(c, e);
  }
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMDescriptor(c, e);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NotifyTo")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "pmm:Provision", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_Provision) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_Provision(struct zx_ctx* c, struct zx_pmm_Provision_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:Provision");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);

  p = zx_attr_so_enc(p, x->wait, " wait=\"", sizeof(" wait=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_prov_ProvisioningHandle_s* e;
      for (e = x->ProvisioningHandle; e; e = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_ProvisioningHandle(c, e, p);
  }
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMDescriptor(c, e, p);
  }
  for (se = x->NotifyTo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dp:NotifyTo", sizeof("dp:NotifyTo")-1, zx_ns_tab+zx_xmlns_ix_dp);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</pmm:Provision>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:Provision", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_Provision) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_Provision(struct zx_ctx* c, struct zx_pmm_Provision_s* x, char* p )
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
  ZX_OUT_MEM(p, "Provision", sizeof("Provision")-1);
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
  ENC_LEN_DEBUG(x, "pmm:Provision", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_Provision) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_Provision(struct zx_ctx* c, struct zx_pmm_Provision_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_Provision(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_Provision(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_Provision) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_Provision(struct zx_ctx* c, struct zx_pmm_Provision_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_Provision(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_Provision(c, x, buf ), buf, len);
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

#define EL_NAME   pmm_ProvisionResponse
#define EL_STRUCT zx_pmm_ProvisionResponse_s
#define EL_NS     pmm
#define EL_TAG    ProvisionResponse

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

/* FUNC(zx_LEN_SO_pmm_ProvisionResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_pmm_ProvisionResponse(struct zx_ctx* c, struct zx_pmm_ProvisionResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<pmm:ProvisionResponse")-1 + 1 + sizeof("</pmm:ProvisionResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ENC_LEN_DEBUG(x, "pmm:ProvisionResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_pmm_ProvisionResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_pmm_ProvisionResponse(struct zx_ctx* c, struct zx_pmm_ProvisionResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProvisionResponse")-1 + 1 + 2 + sizeof("ProvisionResponse")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "pmm:ProvisionResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_pmm_ProvisionResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_pmm_ProvisionResponse(struct zx_ctx* c, struct zx_pmm_ProvisionResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<pmm:ProvisionResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_pmm, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</pmm:ProvisionResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "pmm:ProvisionResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_pmm_ProvisionResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_pmm_ProvisionResponse(struct zx_ctx* c, struct zx_pmm_ProvisionResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProvisionResponse", sizeof("ProvisionResponse")-1);
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
  ENC_LEN_DEBUG(x, "pmm:ProvisionResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_pmm_ProvisionResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_pmm_ProvisionResponse(struct zx_ctx* c, struct zx_pmm_ProvisionResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_pmm_ProvisionResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_pmm_ProvisionResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_pmm_ProvisionResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_pmm_ProvisionResponse(struct zx_ctx* c, struct zx_pmm_ProvisionResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_pmm_ProvisionResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_pmm_ProvisionResponse(c, x, buf ), buf, len);
}




/* EOF -- c/zx-pmm-enc.c */
