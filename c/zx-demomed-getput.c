/* c/zx-demomed-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** getput-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: getput-templ.c,v 1.8 2009-08-30 15:09:26 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** Edit with care! xsd2sg.pl applies various substitutions to this file.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-demomed-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_DeleteObjectRequest_NUM_ObjectID) */

int zx_demomed_DeleteObjectRequest_NUM_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_DeleteObjectRequest_GET_ObjectID) */

struct zx_elem_s* zx_demomed_DeleteObjectRequest_GET_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_DeleteObjectRequest_POP_ObjectID) */

struct zx_elem_s* zx_demomed_DeleteObjectRequest_POP_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ObjectID;
  if (y)
    x->ObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_DeleteObjectRequest_PUSH_ObjectID) */

void zx_demomed_DeleteObjectRequest_PUSH_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ObjectID->g;
  x->ObjectID = z;
}

/* FUNC(zx_demomed_DeleteObjectRequest_REV_ObjectID) */

void zx_demomed_DeleteObjectRequest_REV_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ObjectID;
  if (!y) return;
  x->ObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ObjectID->g;
    x->ObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_DeleteObjectRequest_PUT_ObjectID) */

void zx_demomed_DeleteObjectRequest_PUT_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_DeleteObjectRequest_ADD_ObjectID) */

void zx_demomed_DeleteObjectRequest_ADD_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ObjectID->g;
    x->ObjectID = z;
    return;
  case -1:
    y = x->ObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_DeleteObjectRequest_DEL_ObjectID) */

void zx_demomed_DeleteObjectRequest_DEL_ObjectID(struct zx_demomed_DeleteObjectRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectID = (struct zx_elem_s*)x->ObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_DeleteObjectResponse_NUM_Status) */

int zx_demomed_DeleteObjectResponse_NUM_Status(struct zx_demomed_DeleteObjectResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_DeleteObjectResponse_GET_Status) */

struct zx_lu_Status_s* zx_demomed_DeleteObjectResponse_GET_Status(struct zx_demomed_DeleteObjectResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_DeleteObjectResponse_POP_Status) */

struct zx_lu_Status_s* zx_demomed_DeleteObjectResponse_POP_Status(struct zx_demomed_DeleteObjectResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_DeleteObjectResponse_PUSH_Status) */

void zx_demomed_DeleteObjectResponse_PUSH_Status(struct zx_demomed_DeleteObjectResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_demomed_DeleteObjectResponse_REV_Status) */

void zx_demomed_DeleteObjectResponse_REV_Status(struct zx_demomed_DeleteObjectResponse_s* x)
{
  struct zx_lu_Status_s* nxt;
  struct zx_lu_Status_s* y;
  if (!x) return;
  y = x->Status;
  if (!y) return;
  x->Status = 0;
  while (y) {
    nxt = (struct zx_lu_Status_s*)y->gg.g.n;
    y->gg.g.n = &x->Status->gg.g;
    x->Status = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_DeleteObjectResponse_PUT_Status) */

void zx_demomed_DeleteObjectResponse_PUT_Status(struct zx_demomed_DeleteObjectResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  y = x->Status;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Status = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_DeleteObjectResponse_ADD_Status) */

void zx_demomed_DeleteObjectResponse_ADD_Status(struct zx_demomed_DeleteObjectResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Status->gg.g;
    x->Status = z;
    return;
  case -1:
    y = x->Status;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_DeleteObjectResponse_DEL_Status) */

void zx_demomed_DeleteObjectResponse_DEL_Status(struct zx_demomed_DeleteObjectResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Status = (struct zx_lu_Status_s*)x->Status->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Status_s*)x->Status;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_DeleteObjectResponse_NUM_Count) */

int zx_demomed_DeleteObjectResponse_NUM_Count(struct zx_demomed_DeleteObjectResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Count; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_DeleteObjectResponse_GET_Count) */

struct zx_elem_s* zx_demomed_DeleteObjectResponse_GET_Count(struct zx_demomed_DeleteObjectResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Count; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_DeleteObjectResponse_POP_Count) */

struct zx_elem_s* zx_demomed_DeleteObjectResponse_POP_Count(struct zx_demomed_DeleteObjectResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Count;
  if (y)
    x->Count = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_DeleteObjectResponse_PUSH_Count) */

void zx_demomed_DeleteObjectResponse_PUSH_Count(struct zx_demomed_DeleteObjectResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Count->g;
  x->Count = z;
}

/* FUNC(zx_demomed_DeleteObjectResponse_REV_Count) */

void zx_demomed_DeleteObjectResponse_REV_Count(struct zx_demomed_DeleteObjectResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Count;
  if (!y) return;
  x->Count = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Count->g;
    x->Count = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_DeleteObjectResponse_PUT_Count) */

void zx_demomed_DeleteObjectResponse_PUT_Count(struct zx_demomed_DeleteObjectResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Count;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Count = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_DeleteObjectResponse_ADD_Count) */

void zx_demomed_DeleteObjectResponse_ADD_Count(struct zx_demomed_DeleteObjectResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Count->g;
    x->Count = z;
    return;
  case -1:
    y = x->Count;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Count; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_DeleteObjectResponse_DEL_Count) */

void zx_demomed_DeleteObjectResponse_DEL_Count(struct zx_demomed_DeleteObjectResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Count = (struct zx_elem_s*)x->Count->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Count;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Count; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_GetObjectListRequest_NUM_ObjectSearchParm) */

int zx_demomed_GetObjectListRequest_NUM_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x)
{
  struct zx_demomed_ObjectSearchParm_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectSearchParm; y; ++n, y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_GetObjectListRequest_GET_ObjectSearchParm) */

struct zx_demomed_ObjectSearchParm_s* zx_demomed_GetObjectListRequest_GET_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x, int n)
{
  struct zx_demomed_ObjectSearchParm_s* y;
  if (!x) return 0;
  for (y = x->ObjectSearchParm; n>=0 && y; --n, y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_GetObjectListRequest_POP_ObjectSearchParm) */

struct zx_demomed_ObjectSearchParm_s* zx_demomed_GetObjectListRequest_POP_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x)
{
  struct zx_demomed_ObjectSearchParm_s* y;
  if (!x) return 0;
  y = x->ObjectSearchParm;
  if (y)
    x->ObjectSearchParm = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_GetObjectListRequest_PUSH_ObjectSearchParm) */

void zx_demomed_GetObjectListRequest_PUSH_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x, struct zx_demomed_ObjectSearchParm_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ObjectSearchParm->gg.g;
  x->ObjectSearchParm = z;
}

/* FUNC(zx_demomed_GetObjectListRequest_REV_ObjectSearchParm) */

void zx_demomed_GetObjectListRequest_REV_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x)
{
  struct zx_demomed_ObjectSearchParm_s* nxt;
  struct zx_demomed_ObjectSearchParm_s* y;
  if (!x) return;
  y = x->ObjectSearchParm;
  if (!y) return;
  x->ObjectSearchParm = 0;
  while (y) {
    nxt = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n;
    y->gg.g.n = &x->ObjectSearchParm->gg.g;
    x->ObjectSearchParm = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_GetObjectListRequest_PUT_ObjectSearchParm) */

void zx_demomed_GetObjectListRequest_PUT_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x, int n, struct zx_demomed_ObjectSearchParm_s* z)
{
  struct zx_demomed_ObjectSearchParm_s* y;
  if (!x || !z) return;
  y = x->ObjectSearchParm;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ObjectSearchParm = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_GetObjectListRequest_ADD_ObjectSearchParm) */

void zx_demomed_GetObjectListRequest_ADD_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x, int n, struct zx_demomed_ObjectSearchParm_s* z)
{
  struct zx_demomed_ObjectSearchParm_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ObjectSearchParm->gg.g;
    x->ObjectSearchParm = z;
    return;
  case -1:
    y = x->ObjectSearchParm;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectSearchParm; n > 1 && y; --n, y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_GetObjectListRequest_DEL_ObjectSearchParm) */

void zx_demomed_GetObjectListRequest_DEL_ObjectSearchParm(struct zx_demomed_GetObjectListRequest_s* x, int n)
{
  struct zx_demomed_ObjectSearchParm_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectSearchParm = (struct zx_demomed_ObjectSearchParm_s*)x->ObjectSearchParm->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_ObjectSearchParm_s*)x->ObjectSearchParm;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectSearchParm; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectSearchParm_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_GetObjectListResponse_NUM_Status) */

int zx_demomed_GetObjectListResponse_NUM_Status(struct zx_demomed_GetObjectListResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_GetObjectListResponse_GET_Status) */

struct zx_lu_Status_s* zx_demomed_GetObjectListResponse_GET_Status(struct zx_demomed_GetObjectListResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_GetObjectListResponse_POP_Status) */

struct zx_lu_Status_s* zx_demomed_GetObjectListResponse_POP_Status(struct zx_demomed_GetObjectListResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_GetObjectListResponse_PUSH_Status) */

void zx_demomed_GetObjectListResponse_PUSH_Status(struct zx_demomed_GetObjectListResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_demomed_GetObjectListResponse_REV_Status) */

void zx_demomed_GetObjectListResponse_REV_Status(struct zx_demomed_GetObjectListResponse_s* x)
{
  struct zx_lu_Status_s* nxt;
  struct zx_lu_Status_s* y;
  if (!x) return;
  y = x->Status;
  if (!y) return;
  x->Status = 0;
  while (y) {
    nxt = (struct zx_lu_Status_s*)y->gg.g.n;
    y->gg.g.n = &x->Status->gg.g;
    x->Status = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_GetObjectListResponse_PUT_Status) */

void zx_demomed_GetObjectListResponse_PUT_Status(struct zx_demomed_GetObjectListResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  y = x->Status;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Status = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_GetObjectListResponse_ADD_Status) */

void zx_demomed_GetObjectListResponse_ADD_Status(struct zx_demomed_GetObjectListResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Status->gg.g;
    x->Status = z;
    return;
  case -1:
    y = x->Status;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_GetObjectListResponse_DEL_Status) */

void zx_demomed_GetObjectListResponse_DEL_Status(struct zx_demomed_GetObjectListResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Status = (struct zx_lu_Status_s*)x->Status->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Status_s*)x->Status;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_GetObjectListResponse_NUM_ObjectInfo) */

int zx_demomed_GetObjectListResponse_NUM_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x)
{
  struct zx_demomed_ObjectInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectInfo; y; ++n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_GetObjectListResponse_GET_ObjectInfo) */

struct zx_demomed_ObjectInfo_s* zx_demomed_GetObjectListResponse_GET_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x, int n)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return 0;
  for (y = x->ObjectInfo; n>=0 && y; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_GetObjectListResponse_POP_ObjectInfo) */

struct zx_demomed_ObjectInfo_s* zx_demomed_GetObjectListResponse_POP_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return 0;
  y = x->ObjectInfo;
  if (y)
    x->ObjectInfo = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_GetObjectListResponse_PUSH_ObjectInfo) */

void zx_demomed_GetObjectListResponse_PUSH_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x, struct zx_demomed_ObjectInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ObjectInfo->gg.g;
  x->ObjectInfo = z;
}

/* FUNC(zx_demomed_GetObjectListResponse_REV_ObjectInfo) */

void zx_demomed_GetObjectListResponse_REV_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x)
{
  struct zx_demomed_ObjectInfo_s* nxt;
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return;
  y = x->ObjectInfo;
  if (!y) return;
  x->ObjectInfo = 0;
  while (y) {
    nxt = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n;
    y->gg.g.n = &x->ObjectInfo->gg.g;
    x->ObjectInfo = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_GetObjectListResponse_PUT_ObjectInfo) */

void zx_demomed_GetObjectListResponse_PUT_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x, int n, struct zx_demomed_ObjectInfo_s* z)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x || !z) return;
  y = x->ObjectInfo;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ObjectInfo = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_GetObjectListResponse_ADD_ObjectInfo) */

void zx_demomed_GetObjectListResponse_ADD_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x, int n, struct zx_demomed_ObjectInfo_s* z)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ObjectInfo->gg.g;
    x->ObjectInfo = z;
    return;
  case -1:
    y = x->ObjectInfo;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectInfo; n > 1 && y; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_GetObjectListResponse_DEL_ObjectInfo) */

void zx_demomed_GetObjectListResponse_DEL_ObjectInfo(struct zx_demomed_GetObjectListResponse_s* x, int n)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectInfo = (struct zx_demomed_ObjectInfo_s*)x->ObjectInfo->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_ObjectInfo_s*)x->ObjectInfo;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectInfo; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_GetObjectRequest_NUM_ObjectID) */

int zx_demomed_GetObjectRequest_NUM_ObjectID(struct zx_demomed_GetObjectRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_GetObjectRequest_GET_ObjectID) */

struct zx_elem_s* zx_demomed_GetObjectRequest_GET_ObjectID(struct zx_demomed_GetObjectRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_GetObjectRequest_POP_ObjectID) */

struct zx_elem_s* zx_demomed_GetObjectRequest_POP_ObjectID(struct zx_demomed_GetObjectRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ObjectID;
  if (y)
    x->ObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_GetObjectRequest_PUSH_ObjectID) */

void zx_demomed_GetObjectRequest_PUSH_ObjectID(struct zx_demomed_GetObjectRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ObjectID->g;
  x->ObjectID = z;
}

/* FUNC(zx_demomed_GetObjectRequest_REV_ObjectID) */

void zx_demomed_GetObjectRequest_REV_ObjectID(struct zx_demomed_GetObjectRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ObjectID;
  if (!y) return;
  x->ObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ObjectID->g;
    x->ObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_GetObjectRequest_PUT_ObjectID) */

void zx_demomed_GetObjectRequest_PUT_ObjectID(struct zx_demomed_GetObjectRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_GetObjectRequest_ADD_ObjectID) */

void zx_demomed_GetObjectRequest_ADD_ObjectID(struct zx_demomed_GetObjectRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ObjectID->g;
    x->ObjectID = z;
    return;
  case -1:
    y = x->ObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_GetObjectRequest_DEL_ObjectID) */

void zx_demomed_GetObjectRequest_DEL_ObjectID(struct zx_demomed_GetObjectRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectID = (struct zx_elem_s*)x->ObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_GetObjectResponse_NUM_Status) */

int zx_demomed_GetObjectResponse_NUM_Status(struct zx_demomed_GetObjectResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_GetObjectResponse_GET_Status) */

struct zx_lu_Status_s* zx_demomed_GetObjectResponse_GET_Status(struct zx_demomed_GetObjectResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_GetObjectResponse_POP_Status) */

struct zx_lu_Status_s* zx_demomed_GetObjectResponse_POP_Status(struct zx_demomed_GetObjectResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_GetObjectResponse_PUSH_Status) */

void zx_demomed_GetObjectResponse_PUSH_Status(struct zx_demomed_GetObjectResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_demomed_GetObjectResponse_REV_Status) */

void zx_demomed_GetObjectResponse_REV_Status(struct zx_demomed_GetObjectResponse_s* x)
{
  struct zx_lu_Status_s* nxt;
  struct zx_lu_Status_s* y;
  if (!x) return;
  y = x->Status;
  if (!y) return;
  x->Status = 0;
  while (y) {
    nxt = (struct zx_lu_Status_s*)y->gg.g.n;
    y->gg.g.n = &x->Status->gg.g;
    x->Status = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_GetObjectResponse_PUT_Status) */

void zx_demomed_GetObjectResponse_PUT_Status(struct zx_demomed_GetObjectResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  y = x->Status;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Status = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_GetObjectResponse_ADD_Status) */

void zx_demomed_GetObjectResponse_ADD_Status(struct zx_demomed_GetObjectResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Status->gg.g;
    x->Status = z;
    return;
  case -1:
    y = x->Status;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_GetObjectResponse_DEL_Status) */

void zx_demomed_GetObjectResponse_DEL_Status(struct zx_demomed_GetObjectResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Status = (struct zx_lu_Status_s*)x->Status->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Status_s*)x->Status;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_GetObjectResponse_NUM_ObjectData) */

int zx_demomed_GetObjectResponse_NUM_ObjectData(struct zx_demomed_GetObjectResponse_s* x)
{
  struct zx_demomed_ObjectData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectData; y; ++n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_GetObjectResponse_GET_ObjectData) */

struct zx_demomed_ObjectData_s* zx_demomed_GetObjectResponse_GET_ObjectData(struct zx_demomed_GetObjectResponse_s* x, int n)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x) return 0;
  for (y = x->ObjectData; n>=0 && y; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_GetObjectResponse_POP_ObjectData) */

struct zx_demomed_ObjectData_s* zx_demomed_GetObjectResponse_POP_ObjectData(struct zx_demomed_GetObjectResponse_s* x)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x) return 0;
  y = x->ObjectData;
  if (y)
    x->ObjectData = (struct zx_demomed_ObjectData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_GetObjectResponse_PUSH_ObjectData) */

void zx_demomed_GetObjectResponse_PUSH_ObjectData(struct zx_demomed_GetObjectResponse_s* x, struct zx_demomed_ObjectData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ObjectData->gg.g;
  x->ObjectData = z;
}

/* FUNC(zx_demomed_GetObjectResponse_REV_ObjectData) */

void zx_demomed_GetObjectResponse_REV_ObjectData(struct zx_demomed_GetObjectResponse_s* x)
{
  struct zx_demomed_ObjectData_s* nxt;
  struct zx_demomed_ObjectData_s* y;
  if (!x) return;
  y = x->ObjectData;
  if (!y) return;
  x->ObjectData = 0;
  while (y) {
    nxt = (struct zx_demomed_ObjectData_s*)y->gg.g.n;
    y->gg.g.n = &x->ObjectData->gg.g;
    x->ObjectData = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_GetObjectResponse_PUT_ObjectData) */

void zx_demomed_GetObjectResponse_PUT_ObjectData(struct zx_demomed_GetObjectResponse_s* x, int n, struct zx_demomed_ObjectData_s* z)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x || !z) return;
  y = x->ObjectData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ObjectData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_GetObjectResponse_ADD_ObjectData) */

void zx_demomed_GetObjectResponse_ADD_ObjectData(struct zx_demomed_GetObjectResponse_s* x, int n, struct zx_demomed_ObjectData_s* z)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ObjectData->gg.g;
    x->ObjectData = z;
    return;
  case -1:
    y = x->ObjectData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectData; n > 1 && y; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_GetObjectResponse_DEL_ObjectData) */

void zx_demomed_GetObjectResponse_DEL_ObjectData(struct zx_demomed_GetObjectResponse_s* x, int n)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectData = (struct zx_demomed_ObjectData_s*)x->ObjectData->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_ObjectData_s*)x->ObjectData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectData; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_Object_NUM_ObjectInfo) */

int zx_demomed_Object_NUM_ObjectInfo(struct zx_demomed_Object_s* x)
{
  struct zx_demomed_ObjectInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectInfo; y; ++n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_Object_GET_ObjectInfo) */

struct zx_demomed_ObjectInfo_s* zx_demomed_Object_GET_ObjectInfo(struct zx_demomed_Object_s* x, int n)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return 0;
  for (y = x->ObjectInfo; n>=0 && y; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_Object_POP_ObjectInfo) */

struct zx_demomed_ObjectInfo_s* zx_demomed_Object_POP_ObjectInfo(struct zx_demomed_Object_s* x)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return 0;
  y = x->ObjectInfo;
  if (y)
    x->ObjectInfo = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_Object_PUSH_ObjectInfo) */

void zx_demomed_Object_PUSH_ObjectInfo(struct zx_demomed_Object_s* x, struct zx_demomed_ObjectInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ObjectInfo->gg.g;
  x->ObjectInfo = z;
}

/* FUNC(zx_demomed_Object_REV_ObjectInfo) */

void zx_demomed_Object_REV_ObjectInfo(struct zx_demomed_Object_s* x)
{
  struct zx_demomed_ObjectInfo_s* nxt;
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return;
  y = x->ObjectInfo;
  if (!y) return;
  x->ObjectInfo = 0;
  while (y) {
    nxt = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n;
    y->gg.g.n = &x->ObjectInfo->gg.g;
    x->ObjectInfo = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_Object_PUT_ObjectInfo) */

void zx_demomed_Object_PUT_ObjectInfo(struct zx_demomed_Object_s* x, int n, struct zx_demomed_ObjectInfo_s* z)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x || !z) return;
  y = x->ObjectInfo;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ObjectInfo = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_Object_ADD_ObjectInfo) */

void zx_demomed_Object_ADD_ObjectInfo(struct zx_demomed_Object_s* x, int n, struct zx_demomed_ObjectInfo_s* z)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ObjectInfo->gg.g;
    x->ObjectInfo = z;
    return;
  case -1:
    y = x->ObjectInfo;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectInfo; n > 1 && y; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_Object_DEL_ObjectInfo) */

void zx_demomed_Object_DEL_ObjectInfo(struct zx_demomed_Object_s* x, int n)
{
  struct zx_demomed_ObjectInfo_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectInfo = (struct zx_demomed_ObjectInfo_s*)x->ObjectInfo->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_ObjectInfo_s*)x->ObjectInfo;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectInfo; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_Object_NUM_ObjectData) */

int zx_demomed_Object_NUM_ObjectData(struct zx_demomed_Object_s* x)
{
  struct zx_demomed_ObjectData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectData; y; ++n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_Object_GET_ObjectData) */

struct zx_demomed_ObjectData_s* zx_demomed_Object_GET_ObjectData(struct zx_demomed_Object_s* x, int n)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x) return 0;
  for (y = x->ObjectData; n>=0 && y; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_Object_POP_ObjectData) */

struct zx_demomed_ObjectData_s* zx_demomed_Object_POP_ObjectData(struct zx_demomed_Object_s* x)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x) return 0;
  y = x->ObjectData;
  if (y)
    x->ObjectData = (struct zx_demomed_ObjectData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_Object_PUSH_ObjectData) */

void zx_demomed_Object_PUSH_ObjectData(struct zx_demomed_Object_s* x, struct zx_demomed_ObjectData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ObjectData->gg.g;
  x->ObjectData = z;
}

/* FUNC(zx_demomed_Object_REV_ObjectData) */

void zx_demomed_Object_REV_ObjectData(struct zx_demomed_Object_s* x)
{
  struct zx_demomed_ObjectData_s* nxt;
  struct zx_demomed_ObjectData_s* y;
  if (!x) return;
  y = x->ObjectData;
  if (!y) return;
  x->ObjectData = 0;
  while (y) {
    nxt = (struct zx_demomed_ObjectData_s*)y->gg.g.n;
    y->gg.g.n = &x->ObjectData->gg.g;
    x->ObjectData = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_Object_PUT_ObjectData) */

void zx_demomed_Object_PUT_ObjectData(struct zx_demomed_Object_s* x, int n, struct zx_demomed_ObjectData_s* z)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x || !z) return;
  y = x->ObjectData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ObjectData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_Object_ADD_ObjectData) */

void zx_demomed_Object_ADD_ObjectData(struct zx_demomed_Object_s* x, int n, struct zx_demomed_ObjectData_s* z)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ObjectData->gg.g;
    x->ObjectData = z;
    return;
  case -1:
    y = x->ObjectData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectData; n > 1 && y; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_Object_DEL_ObjectData) */

void zx_demomed_Object_DEL_ObjectData(struct zx_demomed_Object_s* x, int n)
{
  struct zx_demomed_ObjectData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectData = (struct zx_demomed_ObjectData_s*)x->ObjectData->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_ObjectData_s*)x->ObjectData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectData; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_demomed_Object_GET_reqID) */
struct zx_str* zx_demomed_Object_GET_reqID(struct zx_demomed_Object_s* x) { return x->reqID; }
/* FUNC(zx_demomed_Object_PUT_reqID) */
void zx_demomed_Object_PUT_reqID(struct zx_demomed_Object_s* x, struct zx_str* y) { x->reqID = y; }





/* FUNC(zx_demomed_ObjectData_GET_objectID) */
struct zx_str* zx_demomed_ObjectData_GET_objectID(struct zx_demomed_ObjectData_s* x) { return x->objectID; }
/* FUNC(zx_demomed_ObjectData_PUT_objectID) */
void zx_demomed_ObjectData_PUT_objectID(struct zx_demomed_ObjectData_s* x, struct zx_str* y) { x->objectID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectInfo_NUM_Dir) */

int zx_demomed_ObjectInfo_NUM_Dir(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Dir; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectInfo_GET_Dir) */

struct zx_elem_s* zx_demomed_ObjectInfo_GET_Dir(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Dir; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_POP_Dir) */

struct zx_elem_s* zx_demomed_ObjectInfo_POP_Dir(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Dir;
  if (y)
    x->Dir = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_PUSH_Dir) */

void zx_demomed_ObjectInfo_PUSH_Dir(struct zx_demomed_ObjectInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Dir->g;
  x->Dir = z;
}

/* FUNC(zx_demomed_ObjectInfo_REV_Dir) */

void zx_demomed_ObjectInfo_REV_Dir(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Dir;
  if (!y) return;
  x->Dir = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Dir->g;
    x->Dir = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectInfo_PUT_Dir) */

void zx_demomed_ObjectInfo_PUT_Dir(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Dir;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Dir = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectInfo_ADD_Dir) */

void zx_demomed_ObjectInfo_ADD_Dir(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Dir->g;
    x->Dir = z;
    return;
  case -1:
    y = x->Dir;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Dir; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectInfo_DEL_Dir) */

void zx_demomed_ObjectInfo_DEL_Dir(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Dir = (struct zx_elem_s*)x->Dir->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Dir;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Dir; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectInfo_NUM_Name) */

int zx_demomed_ObjectInfo_NUM_Name(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Name; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectInfo_GET_Name) */

struct zx_elem_s* zx_demomed_ObjectInfo_GET_Name(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Name; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_POP_Name) */

struct zx_elem_s* zx_demomed_ObjectInfo_POP_Name(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Name;
  if (y)
    x->Name = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_PUSH_Name) */

void zx_demomed_ObjectInfo_PUSH_Name(struct zx_demomed_ObjectInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Name->g;
  x->Name = z;
}

/* FUNC(zx_demomed_ObjectInfo_REV_Name) */

void zx_demomed_ObjectInfo_REV_Name(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Name;
  if (!y) return;
  x->Name = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Name->g;
    x->Name = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectInfo_PUT_Name) */

void zx_demomed_ObjectInfo_PUT_Name(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Name;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Name = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectInfo_ADD_Name) */

void zx_demomed_ObjectInfo_ADD_Name(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Name->g;
    x->Name = z;
    return;
  case -1:
    y = x->Name;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Name; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectInfo_DEL_Name) */

void zx_demomed_ObjectInfo_DEL_Name(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Name = (struct zx_elem_s*)x->Name->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Name;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Name; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectInfo_NUM_Type) */

int zx_demomed_ObjectInfo_NUM_Type(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Type; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectInfo_GET_Type) */

struct zx_elem_s* zx_demomed_ObjectInfo_GET_Type(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Type; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_POP_Type) */

struct zx_elem_s* zx_demomed_ObjectInfo_POP_Type(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Type;
  if (y)
    x->Type = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_PUSH_Type) */

void zx_demomed_ObjectInfo_PUSH_Type(struct zx_demomed_ObjectInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Type->g;
  x->Type = z;
}

/* FUNC(zx_demomed_ObjectInfo_REV_Type) */

void zx_demomed_ObjectInfo_REV_Type(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Type;
  if (!y) return;
  x->Type = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Type->g;
    x->Type = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectInfo_PUT_Type) */

void zx_demomed_ObjectInfo_PUT_Type(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Type;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Type = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectInfo_ADD_Type) */

void zx_demomed_ObjectInfo_ADD_Type(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Type->g;
    x->Type = z;
    return;
  case -1:
    y = x->Type;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Type; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectInfo_DEL_Type) */

void zx_demomed_ObjectInfo_DEL_Type(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Type = (struct zx_elem_s*)x->Type->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Type;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Type; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectInfo_NUM_Created) */

int zx_demomed_ObjectInfo_NUM_Created(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Created; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectInfo_GET_Created) */

struct zx_elem_s* zx_demomed_ObjectInfo_GET_Created(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Created; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_POP_Created) */

struct zx_elem_s* zx_demomed_ObjectInfo_POP_Created(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Created;
  if (y)
    x->Created = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_PUSH_Created) */

void zx_demomed_ObjectInfo_PUSH_Created(struct zx_demomed_ObjectInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Created->g;
  x->Created = z;
}

/* FUNC(zx_demomed_ObjectInfo_REV_Created) */

void zx_demomed_ObjectInfo_REV_Created(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Created;
  if (!y) return;
  x->Created = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Created->g;
    x->Created = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectInfo_PUT_Created) */

void zx_demomed_ObjectInfo_PUT_Created(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Created;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Created = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectInfo_ADD_Created) */

void zx_demomed_ObjectInfo_ADD_Created(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Created->g;
    x->Created = z;
    return;
  case -1:
    y = x->Created;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Created; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectInfo_DEL_Created) */

void zx_demomed_ObjectInfo_DEL_Created(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Created = (struct zx_elem_s*)x->Created->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Created;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Created; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectInfo_NUM_Comment) */

int zx_demomed_ObjectInfo_NUM_Comment(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Comment; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectInfo_GET_Comment) */

struct zx_elem_s* zx_demomed_ObjectInfo_GET_Comment(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Comment; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_POP_Comment) */

struct zx_elem_s* zx_demomed_ObjectInfo_POP_Comment(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Comment;
  if (y)
    x->Comment = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectInfo_PUSH_Comment) */

void zx_demomed_ObjectInfo_PUSH_Comment(struct zx_demomed_ObjectInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Comment->g;
  x->Comment = z;
}

/* FUNC(zx_demomed_ObjectInfo_REV_Comment) */

void zx_demomed_ObjectInfo_REV_Comment(struct zx_demomed_ObjectInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Comment;
  if (!y) return;
  x->Comment = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Comment->g;
    x->Comment = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectInfo_PUT_Comment) */

void zx_demomed_ObjectInfo_PUT_Comment(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Comment;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Comment = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectInfo_ADD_Comment) */

void zx_demomed_ObjectInfo_ADD_Comment(struct zx_demomed_ObjectInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Comment->g;
    x->Comment = z;
    return;
  case -1:
    y = x->Comment;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Comment; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectInfo_DEL_Comment) */

void zx_demomed_ObjectInfo_DEL_Comment(struct zx_demomed_ObjectInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Comment = (struct zx_elem_s*)x->Comment->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Comment;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Comment; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_demomed_ObjectInfo_GET_objectID) */
struct zx_str* zx_demomed_ObjectInfo_GET_objectID(struct zx_demomed_ObjectInfo_s* x) { return x->objectID; }
/* FUNC(zx_demomed_ObjectInfo_PUT_objectID) */
void zx_demomed_ObjectInfo_PUT_objectID(struct zx_demomed_ObjectInfo_s* x, struct zx_str* y) { x->objectID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectSearchParm_NUM_Dir) */

int zx_demomed_ObjectSearchParm_NUM_Dir(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Dir; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectSearchParm_GET_Dir) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_GET_Dir(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Dir; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_POP_Dir) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_POP_Dir(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Dir;
  if (y)
    x->Dir = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_PUSH_Dir) */

void zx_demomed_ObjectSearchParm_PUSH_Dir(struct zx_demomed_ObjectSearchParm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Dir->g;
  x->Dir = z;
}

/* FUNC(zx_demomed_ObjectSearchParm_REV_Dir) */

void zx_demomed_ObjectSearchParm_REV_Dir(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Dir;
  if (!y) return;
  x->Dir = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Dir->g;
    x->Dir = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_PUT_Dir) */

void zx_demomed_ObjectSearchParm_PUT_Dir(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Dir;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Dir = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_ADD_Dir) */

void zx_demomed_ObjectSearchParm_ADD_Dir(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Dir->g;
    x->Dir = z;
    return;
  case -1:
    y = x->Dir;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Dir; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectSearchParm_DEL_Dir) */

void zx_demomed_ObjectSearchParm_DEL_Dir(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Dir = (struct zx_elem_s*)x->Dir->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Dir;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Dir; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectSearchParm_NUM_Name) */

int zx_demomed_ObjectSearchParm_NUM_Name(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Name; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectSearchParm_GET_Name) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_GET_Name(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Name; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_POP_Name) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_POP_Name(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Name;
  if (y)
    x->Name = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_PUSH_Name) */

void zx_demomed_ObjectSearchParm_PUSH_Name(struct zx_demomed_ObjectSearchParm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Name->g;
  x->Name = z;
}

/* FUNC(zx_demomed_ObjectSearchParm_REV_Name) */

void zx_demomed_ObjectSearchParm_REV_Name(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Name;
  if (!y) return;
  x->Name = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Name->g;
    x->Name = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_PUT_Name) */

void zx_demomed_ObjectSearchParm_PUT_Name(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Name;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Name = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_ADD_Name) */

void zx_demomed_ObjectSearchParm_ADD_Name(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Name->g;
    x->Name = z;
    return;
  case -1:
    y = x->Name;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Name; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectSearchParm_DEL_Name) */

void zx_demomed_ObjectSearchParm_DEL_Name(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Name = (struct zx_elem_s*)x->Name->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Name;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Name; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectSearchParm_NUM_Type) */

int zx_demomed_ObjectSearchParm_NUM_Type(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Type; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectSearchParm_GET_Type) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_GET_Type(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Type; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_POP_Type) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_POP_Type(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Type;
  if (y)
    x->Type = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_PUSH_Type) */

void zx_demomed_ObjectSearchParm_PUSH_Type(struct zx_demomed_ObjectSearchParm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Type->g;
  x->Type = z;
}

/* FUNC(zx_demomed_ObjectSearchParm_REV_Type) */

void zx_demomed_ObjectSearchParm_REV_Type(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Type;
  if (!y) return;
  x->Type = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Type->g;
    x->Type = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_PUT_Type) */

void zx_demomed_ObjectSearchParm_PUT_Type(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Type;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Type = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_ADD_Type) */

void zx_demomed_ObjectSearchParm_ADD_Type(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Type->g;
    x->Type = z;
    return;
  case -1:
    y = x->Type;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Type; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectSearchParm_DEL_Type) */

void zx_demomed_ObjectSearchParm_DEL_Type(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Type = (struct zx_elem_s*)x->Type->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Type;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Type; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_ObjectSearchParm_NUM_objectID) */

int zx_demomed_ObjectSearchParm_NUM_objectID(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->objectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_demomed_ObjectSearchParm_GET_objectID) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_GET_objectID(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->objectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_POP_objectID) */

struct zx_elem_s* zx_demomed_ObjectSearchParm_POP_objectID(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->objectID;
  if (y)
    x->objectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_demomed_ObjectSearchParm_PUSH_objectID) */

void zx_demomed_ObjectSearchParm_PUSH_objectID(struct zx_demomed_ObjectSearchParm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->objectID->g;
  x->objectID = z;
}

/* FUNC(zx_demomed_ObjectSearchParm_REV_objectID) */

void zx_demomed_ObjectSearchParm_REV_objectID(struct zx_demomed_ObjectSearchParm_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->objectID;
  if (!y) return;
  x->objectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->objectID->g;
    x->objectID = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_PUT_objectID) */

void zx_demomed_ObjectSearchParm_PUT_objectID(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->objectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->objectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_demomed_ObjectSearchParm_ADD_objectID) */

void zx_demomed_ObjectSearchParm_ADD_objectID(struct zx_demomed_ObjectSearchParm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->objectID->g;
    x->objectID = z;
    return;
  case -1:
    y = x->objectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->objectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_demomed_ObjectSearchParm_DEL_objectID) */

void zx_demomed_ObjectSearchParm_DEL_objectID(struct zx_demomed_ObjectSearchParm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->objectID = (struct zx_elem_s*)x->objectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->objectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->objectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif






/* FUNC(zx_demomed_ObjectStoreInfo_GET_objectID) */
struct zx_str* zx_demomed_ObjectStoreInfo_GET_objectID(struct zx_demomed_ObjectStoreInfo_s* x) { return x->objectID; }
/* FUNC(zx_demomed_ObjectStoreInfo_PUT_objectID) */
void zx_demomed_ObjectStoreInfo_PUT_objectID(struct zx_demomed_ObjectStoreInfo_s* x, struct zx_str* y) { x->objectID = y; }
/* FUNC(zx_demomed_ObjectStoreInfo_GET_storeRef) */
struct zx_str* zx_demomed_ObjectStoreInfo_GET_storeRef(struct zx_demomed_ObjectStoreInfo_s* x) { return x->storeRef; }
/* FUNC(zx_demomed_ObjectStoreInfo_PUT_storeRef) */
void zx_demomed_ObjectStoreInfo_PUT_storeRef(struct zx_demomed_ObjectStoreInfo_s* x, struct zx_str* y) { x->storeRef = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_StoreObjectRequest_NUM_Object) */

int zx_demomed_StoreObjectRequest_NUM_Object(struct zx_demomed_StoreObjectRequest_s* x)
{
  struct zx_demomed_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_StoreObjectRequest_GET_Object) */

struct zx_demomed_Object_s* zx_demomed_StoreObjectRequest_GET_Object(struct zx_demomed_StoreObjectRequest_s* x, int n)
{
  struct zx_demomed_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_StoreObjectRequest_POP_Object) */

struct zx_demomed_Object_s* zx_demomed_StoreObjectRequest_POP_Object(struct zx_demomed_StoreObjectRequest_s* x)
{
  struct zx_demomed_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_demomed_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_StoreObjectRequest_PUSH_Object) */

void zx_demomed_StoreObjectRequest_PUSH_Object(struct zx_demomed_StoreObjectRequest_s* x, struct zx_demomed_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_demomed_StoreObjectRequest_REV_Object) */

void zx_demomed_StoreObjectRequest_REV_Object(struct zx_demomed_StoreObjectRequest_s* x)
{
  struct zx_demomed_Object_s* nxt;
  struct zx_demomed_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_demomed_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_StoreObjectRequest_PUT_Object) */

void zx_demomed_StoreObjectRequest_PUT_Object(struct zx_demomed_StoreObjectRequest_s* x, int n, struct zx_demomed_Object_s* z)
{
  struct zx_demomed_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_StoreObjectRequest_ADD_Object) */

void zx_demomed_StoreObjectRequest_ADD_Object(struct zx_demomed_StoreObjectRequest_s* x, int n, struct zx_demomed_Object_s* z)
{
  struct zx_demomed_Object_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Object->gg.g;
    x->Object = z;
    return;
  case -1:
    y = x->Object;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_StoreObjectRequest_DEL_Object) */

void zx_demomed_StoreObjectRequest_DEL_Object(struct zx_demomed_StoreObjectRequest_s* x, int n)
{
  struct zx_demomed_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_demomed_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_StoreObjectResponse_NUM_Status) */

int zx_demomed_StoreObjectResponse_NUM_Status(struct zx_demomed_StoreObjectResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_StoreObjectResponse_GET_Status) */

struct zx_lu_Status_s* zx_demomed_StoreObjectResponse_GET_Status(struct zx_demomed_StoreObjectResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_StoreObjectResponse_POP_Status) */

struct zx_lu_Status_s* zx_demomed_StoreObjectResponse_POP_Status(struct zx_demomed_StoreObjectResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_StoreObjectResponse_PUSH_Status) */

void zx_demomed_StoreObjectResponse_PUSH_Status(struct zx_demomed_StoreObjectResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_demomed_StoreObjectResponse_REV_Status) */

void zx_demomed_StoreObjectResponse_REV_Status(struct zx_demomed_StoreObjectResponse_s* x)
{
  struct zx_lu_Status_s* nxt;
  struct zx_lu_Status_s* y;
  if (!x) return;
  y = x->Status;
  if (!y) return;
  x->Status = 0;
  while (y) {
    nxt = (struct zx_lu_Status_s*)y->gg.g.n;
    y->gg.g.n = &x->Status->gg.g;
    x->Status = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_StoreObjectResponse_PUT_Status) */

void zx_demomed_StoreObjectResponse_PUT_Status(struct zx_demomed_StoreObjectResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  y = x->Status;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Status = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_StoreObjectResponse_ADD_Status) */

void zx_demomed_StoreObjectResponse_ADD_Status(struct zx_demomed_StoreObjectResponse_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Status->gg.g;
    x->Status = z;
    return;
  case -1:
    y = x->Status;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_StoreObjectResponse_DEL_Status) */

void zx_demomed_StoreObjectResponse_DEL_Status(struct zx_demomed_StoreObjectResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Status = (struct zx_lu_Status_s*)x->Status->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Status_s*)x->Status;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_demomed_StoreObjectResponse_NUM_ObjectStoreInfo) */

int zx_demomed_StoreObjectResponse_NUM_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x)
{
  struct zx_demomed_ObjectStoreInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectStoreInfo; y; ++n, y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_demomed_StoreObjectResponse_GET_ObjectStoreInfo) */

struct zx_demomed_ObjectStoreInfo_s* zx_demomed_StoreObjectResponse_GET_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x, int n)
{
  struct zx_demomed_ObjectStoreInfo_s* y;
  if (!x) return 0;
  for (y = x->ObjectStoreInfo; n>=0 && y; --n, y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_demomed_StoreObjectResponse_POP_ObjectStoreInfo) */

struct zx_demomed_ObjectStoreInfo_s* zx_demomed_StoreObjectResponse_POP_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x)
{
  struct zx_demomed_ObjectStoreInfo_s* y;
  if (!x) return 0;
  y = x->ObjectStoreInfo;
  if (y)
    x->ObjectStoreInfo = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_demomed_StoreObjectResponse_PUSH_ObjectStoreInfo) */

void zx_demomed_StoreObjectResponse_PUSH_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x, struct zx_demomed_ObjectStoreInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ObjectStoreInfo->gg.g;
  x->ObjectStoreInfo = z;
}

/* FUNC(zx_demomed_StoreObjectResponse_REV_ObjectStoreInfo) */

void zx_demomed_StoreObjectResponse_REV_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x)
{
  struct zx_demomed_ObjectStoreInfo_s* nxt;
  struct zx_demomed_ObjectStoreInfo_s* y;
  if (!x) return;
  y = x->ObjectStoreInfo;
  if (!y) return;
  x->ObjectStoreInfo = 0;
  while (y) {
    nxt = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n;
    y->gg.g.n = &x->ObjectStoreInfo->gg.g;
    x->ObjectStoreInfo = y;
    y = nxt;
  }
}

/* FUNC(zx_demomed_StoreObjectResponse_PUT_ObjectStoreInfo) */

void zx_demomed_StoreObjectResponse_PUT_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x, int n, struct zx_demomed_ObjectStoreInfo_s* z)
{
  struct zx_demomed_ObjectStoreInfo_s* y;
  if (!x || !z) return;
  y = x->ObjectStoreInfo;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ObjectStoreInfo = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_demomed_StoreObjectResponse_ADD_ObjectStoreInfo) */

void zx_demomed_StoreObjectResponse_ADD_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x, int n, struct zx_demomed_ObjectStoreInfo_s* z)
{
  struct zx_demomed_ObjectStoreInfo_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ObjectStoreInfo->gg.g;
    x->ObjectStoreInfo = z;
    return;
  case -1:
    y = x->ObjectStoreInfo;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectStoreInfo; n > 1 && y; --n, y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_demomed_StoreObjectResponse_DEL_ObjectStoreInfo) */

void zx_demomed_StoreObjectResponse_DEL_ObjectStoreInfo(struct zx_demomed_StoreObjectResponse_s* x, int n)
{
  struct zx_demomed_ObjectStoreInfo_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectStoreInfo = (struct zx_demomed_ObjectStoreInfo_s*)x->ObjectStoreInfo->gg.g.n;
    return;
  case -1:
    y = (struct zx_demomed_ObjectStoreInfo_s*)x->ObjectStoreInfo;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ObjectStoreInfo; n > 1 && y->gg.g.n; --n, y = (struct zx_demomed_ObjectStoreInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* EOF -- c/zx-demomed-getput.c */