/* c/zx-ecp-aux.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** aux-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: aux-templ.c,v 1.12 2008-10-04 23:42:14 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-ecp-data.h"



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

#define EL_NAME   ecp_RelayState
#define EL_STRUCT zx_ecp_RelayState_s
#define EL_NS     ecp
#define EL_TAG    RelayState

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ecp_RelayState) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ecp_RelayState(struct zx_ctx* c, struct zx_ecp_RelayState_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_ecp_RelayState) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ecp_RelayState_s* zx_DEEP_CLONE_ecp_RelayState(struct zx_ctx* c, struct zx_ecp_RelayState_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_ecp_RelayState_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ecp_RelayState_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_ecp_RelayState) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ecp_RelayState(struct zx_ctx* c, struct zx_ecp_RelayState_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ecp_RelayState) */

int zx_WALK_WO_ecp_RelayState(struct zx_ctx* c, struct zx_ecp_RelayState_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




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

#define EL_NAME   ecp_Request
#define EL_STRUCT zx_ecp_Request_s
#define EL_NS     ecp
#define EL_TAG    Request

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ecp_Request) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ecp_Request(struct zx_ctx* c, struct zx_ecp_Request_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->IsPassive);
  zx_dup_attr(c, x->ProviderName);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  for (se = &x->Issuer->gg;
       se && se->g.tok == zx_sa_Issuer_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa_Issuer(c, (struct zx_sa_Issuer_s*)se);
  for (se = &x->IDPList->gg;
       se && se->g.tok == zx_sp_IDPList_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sp_IDPList(c, (struct zx_sp_IDPList_s*)se);

}

/* FUNC(zx_DEEP_CLONE_ecp_Request) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ecp_Request_s* zx_DEEP_CLONE_ecp_Request(struct zx_ctx* c, struct zx_ecp_Request_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_ecp_Request_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ecp_Request_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->IsPassive = zx_clone_attr(c, x->IsPassive);
  x->ProviderName = zx_clone_attr(c, x->ProviderName);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

  for (enn = 0, e = &x->Issuer->gg;
       e && e->g.tok == zx_sa_Issuer_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa_Issuer(c,(struct zx_sa_Issuer_s*)e,dup_strs);
  	  if (!enn)
  	      x->Issuer = (struct zx_sa_Issuer_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->IDPList->gg;
       e && e->g.tok == zx_sp_IDPList_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sp_IDPList(c,(struct zx_sp_IDPList_s*)e,dup_strs);
  	  if (!enn)
  	      x->IDPList = (struct zx_sp_IDPList_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_ecp_Request) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ecp_Request(struct zx_ctx* c, struct zx_ecp_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->Issuer->gg;
       e && e->g.tok == zx_sa_Issuer_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa_Issuer(c, (struct zx_sa_Issuer_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->IDPList->gg;
       e && e->g.tok == zx_sp_IDPList_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sp_IDPList(c, (struct zx_sp_IDPList_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ecp_Request) */

int zx_WALK_WO_ecp_Request(struct zx_ctx* c, struct zx_ecp_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




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

#define EL_NAME   ecp_Response
#define EL_STRUCT zx_ecp_Response_s
#define EL_NS     ecp
#define EL_TAG    Response

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ecp_Response) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ecp_Response(struct zx_ctx* c, struct zx_ecp_Response_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AssertionConsumerServiceURL);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_ecp_Response) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ecp_Response_s* zx_DEEP_CLONE_ecp_Response(struct zx_ctx* c, struct zx_ecp_Response_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_ecp_Response_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ecp_Response_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AssertionConsumerServiceURL = zx_clone_attr(c, x->AssertionConsumerServiceURL);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_ecp_Response) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ecp_Response(struct zx_ctx* c, struct zx_ecp_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ecp_Response) */

int zx_WALK_WO_ecp_Response(struct zx_ctx* c, struct zx_ecp_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-ecp-aux.c */
