/* c/zx-idhrxml-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
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
#include "c/zx-idhrxml-data.h"
#define TPF zx_
#include "zx_ext_pt.h"



int zx_DEC_ATTR_idhrxml_Create(struct zx_ctx* c, struct zx_idhrxml_Create_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Create(struct zx_ctx* c, struct zx_idhrxml_Create_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_Subscription_ELEM:
    if (!x->Subscription)
      x->Subscription = (struct zx_idhrxml_Subscription_s*)el;
    return 1;
  case zx_idhrxml_CreateItem_ELEM:
    if (!x->CreateItem)
      x->CreateItem = (struct zx_idhrxml_CreateItem_s*)el;
    return 1;
  case zx_idhrxml_ResultQuery_ELEM:
    if (!x->ResultQuery)
      x->ResultQuery = (struct zx_idhrxml_ResultQuery_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_CreateItem(struct zx_ctx* c, struct zx_idhrxml_CreateItem_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_id_ATTR:  x->id = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;
    case zx_objectType_ATTR|zx_dst_NS:  x->objectType = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_CreateItem(struct zx_ctx* c, struct zx_idhrxml_CreateItem_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_idhrxml_NewData_ELEM:
    if (!x->NewData)
      x->NewData = (struct zx_idhrxml_NewData_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_CreateResponse(struct zx_ctx* c, struct zx_idhrxml_CreateResponse_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_timeStamp_ATTR:  x->timeStamp = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_CreateResponse(struct zx_ctx* c, struct zx_idhrxml_CreateResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Status_ELEM:
    if (!x->Status)
      x->Status = (struct zx_lu_Status_s*)el;
    return 1;
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_ItemData_ELEM:
    if (!x->ItemData)
      x->ItemData = (struct zx_idhrxml_ItemData_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Data(struct zx_ctx* c, struct zx_idhrxml_Data_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_nextOffset_ATTR:  x->nextOffset = x->gg.attr; return 1;
    case zx_notSorted_ATTR:  x->notSorted = x->gg.attr; return 1;
    case zx_remaining_ATTR:  x->remaining = x->gg.attr; return 1;
    case zx_setID_ATTR:  x->setID = x->gg.attr; return 1;
    case zx_changeFormat_ATTR|zx_dst_NS:  x->changeFormat = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Data(struct zx_ctx* c, struct zx_idhrxml_Data_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_hrxml_Candidate_ELEM:
    if (!x->Candidate)
      x->Candidate = (struct zx_hrxml_Candidate_s*)el;
    return 1;
  case zx_idhrxml_Subscription_ELEM:
    if (!x->Subscription)
      x->Subscription = (struct zx_idhrxml_Subscription_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Delete(struct zx_ctx* c, struct zx_idhrxml_Delete_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Delete(struct zx_ctx* c, struct zx_idhrxml_Delete_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_DeleteItem_ELEM:
    if (!x->DeleteItem)
      x->DeleteItem = (struct zx_idhrxml_DeleteItem_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_DeleteItem(struct zx_ctx* c, struct zx_idhrxml_DeleteItem_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_id_ATTR:  x->id = x->gg.attr; return 1;
    case zx_notChangedSince_ATTR:  x->notChangedSince = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;
    case zx_objectType_ATTR|zx_dst_NS:  x->objectType = x->gg.attr; return 1;
    case zx_predefined_ATTR|zx_dst_NS:  x->predefined = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_DeleteItem(struct zx_ctx* c, struct zx_idhrxml_DeleteItem_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_idhrxml_Select_ELEM:
    if (!x->Select)
      x->Select = el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_DeleteResponse(struct zx_ctx* c, struct zx_idhrxml_DeleteResponse_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_itemIDRef_ATTR:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_DeleteResponse(struct zx_ctx* c, struct zx_idhrxml_DeleteResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Status_ELEM:
    if (!x->Status)
      x->Status = (struct zx_lu_Status_s*)el;
    return 1;
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_ItemData(struct zx_ctx* c, struct zx_idhrxml_ItemData_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_notSorted_ATTR:  x->notSorted = x->gg.attr; return 1;
    case zx_changeFormat_ATTR|zx_dst_NS:  x->changeFormat = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_ItemData(struct zx_ctx* c, struct zx_idhrxml_ItemData_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_hrxml_Candidate_ELEM:
    if (!x->Candidate)
      x->Candidate = (struct zx_hrxml_Candidate_s*)el;
    return 1;
  case zx_idhrxml_Subscription_ELEM:
    if (!x->Subscription)
      x->Subscription = (struct zx_idhrxml_Subscription_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Modify(struct zx_ctx* c, struct zx_idhrxml_Modify_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Modify(struct zx_ctx* c, struct zx_idhrxml_Modify_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_Subscription_ELEM:
    if (!x->Subscription)
      x->Subscription = (struct zx_idhrxml_Subscription_s*)el;
    return 1;
  case zx_idhrxml_ModifyItem_ELEM:
    if (!x->ModifyItem)
      x->ModifyItem = (struct zx_idhrxml_ModifyItem_s*)el;
    return 1;
  case zx_idhrxml_ResultQuery_ELEM:
    if (!x->ResultQuery)
      x->ResultQuery = (struct zx_idhrxml_ResultQuery_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_ModifyItem(struct zx_ctx* c, struct zx_idhrxml_ModifyItem_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_id_ATTR:  x->id = x->gg.attr; return 1;
    case zx_notChangedSince_ATTR:  x->notChangedSince = x->gg.attr; return 1;
    case zx_overrideAllowed_ATTR:  x->overrideAllowed = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;
    case zx_objectType_ATTR|zx_dst_NS:  x->objectType = x->gg.attr; return 1;
    case zx_predefined_ATTR|zx_dst_NS:  x->predefined = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_ModifyItem(struct zx_ctx* c, struct zx_idhrxml_ModifyItem_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_idhrxml_Select_ELEM:
    if (!x->Select)
      x->Select = el;
    return 1;
  case zx_idhrxml_NewData_ELEM:
    if (!x->NewData)
      x->NewData = (struct zx_idhrxml_NewData_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_ModifyResponse(struct zx_ctx* c, struct zx_idhrxml_ModifyResponse_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_timeStamp_ATTR:  x->timeStamp = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_ModifyResponse(struct zx_ctx* c, struct zx_idhrxml_ModifyResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Status_ELEM:
    if (!x->Status)
      x->Status = (struct zx_lu_Status_s*)el;
    return 1;
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_ItemData_ELEM:
    if (!x->ItemData)
      x->ItemData = (struct zx_idhrxml_ItemData_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_NewData(struct zx_ctx* c, struct zx_idhrxml_NewData_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_NewData(struct zx_ctx* c, struct zx_idhrxml_NewData_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_hrxml_Candidate_ELEM:
    if (!x->Candidate)
      x->Candidate = (struct zx_hrxml_Candidate_s*)el;
    return 1;
  case zx_idhrxml_Subscription_ELEM:
    if (!x->Subscription)
      x->Subscription = (struct zx_idhrxml_Subscription_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Notification(struct zx_ctx* c, struct zx_idhrxml_Notification_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_endReason_ATTR:  x->endReason = x->gg.attr; return 1;
    case zx_expires_ATTR:  x->expires = x->gg.attr; return 1;
    case zx_id_ATTR:  x->id = x->gg.attr; return 1;
    case zx_subscriptionID_ATTR:  x->subscriptionID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Notification(struct zx_ctx* c, struct zx_idhrxml_Notification_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_TestResult_ELEM:
    if (!x->TestResult)
      x->TestResult = (struct zx_lu_TestResult_s*)el;
    return 1;
  case zx_idhrxml_ItemData_ELEM:
    if (!x->ItemData)
      x->ItemData = (struct zx_idhrxml_ItemData_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Notify(struct zx_ctx* c, struct zx_idhrxml_Notify_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_timeStamp_ATTR:  x->timeStamp = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Notify(struct zx_ctx* c, struct zx_idhrxml_Notify_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_Notification_ELEM:
    if (!x->Notification)
      x->Notification = (struct zx_idhrxml_Notification_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_NotifyResponse(struct zx_ctx* c, struct zx_idhrxml_NotifyResponse_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_itemIDRef_ATTR:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_NotifyResponse(struct zx_ctx* c, struct zx_idhrxml_NotifyResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Status_ELEM:
    if (!x->Status)
      x->Status = (struct zx_lu_Status_s*)el;
    return 1;
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Query(struct zx_ctx* c, struct zx_idhrxml_Query_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Query(struct zx_ctx* c, struct zx_idhrxml_Query_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_TestItem_ELEM:
    if (!x->TestItem)
      x->TestItem = (struct zx_idhrxml_TestItem_s*)el;
    return 1;
  case zx_idhrxml_QueryItem_ELEM:
    if (!x->QueryItem)
      x->QueryItem = (struct zx_idhrxml_QueryItem_s*)el;
    return 1;
  case zx_idhrxml_Subscription_ELEM:
    if (!x->Subscription)
      x->Subscription = (struct zx_idhrxml_Subscription_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_QueryItem(struct zx_ctx* c, struct zx_idhrxml_QueryItem_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_changedSince_ATTR:  x->changedSince = x->gg.attr; return 1;
    case zx_contingency_ATTR:  x->contingency = x->gg.attr; return 1;
    case zx_count_ATTR:  x->count = x->gg.attr; return 1;
    case zx_includeCommonAttributes_ATTR:  x->includeCommonAttributes = x->gg.attr; return 1;
    case zx_offset_ATTR:  x->offset = x->gg.attr; return 1;
    case zx_setID_ATTR:  x->setID = x->gg.attr; return 1;
    case zx_setReq_ATTR:  x->setReq = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;
    case zx_objectType_ATTR|zx_dst_NS:  x->objectType = x->gg.attr; return 1;
    case zx_predefined_ATTR|zx_dst_NS:  x->predefined = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_QueryItem(struct zx_ctx* c, struct zx_idhrxml_QueryItem_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_dst_ChangeFormat_ELEM:
    if (!x->ChangeFormat)
      x->ChangeFormat = el;
    return 1;
  case zx_idhrxml_Select_ELEM:
    if (!x->Select)
      x->Select = el;
    return 1;
  case zx_idhrxml_Sort_ELEM:
    if (!x->Sort)
      x->Sort = el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_QueryResponse(struct zx_ctx* c, struct zx_idhrxml_QueryResponse_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_timeStamp_ATTR:  x->timeStamp = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_QueryResponse(struct zx_ctx* c, struct zx_idhrxml_QueryResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_lu_Status_ELEM:
    if (!x->Status)
      x->Status = (struct zx_lu_Status_s*)el;
    return 1;
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_dst_TestResult_ELEM:
    if (!x->TestResult)
      x->TestResult = (struct zx_dst_TestResult_s*)el;
    return 1;
  case zx_idhrxml_Data_ELEM:
    if (!x->Data)
      x->Data = (struct zx_idhrxml_Data_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_ResultQuery(struct zx_ctx* c, struct zx_idhrxml_ResultQuery_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_changedSince_ATTR:  x->changedSince = x->gg.attr; return 1;
    case zx_contingency_ATTR:  x->contingency = x->gg.attr; return 1;
    case zx_includeCommonAttributes_ATTR:  x->includeCommonAttributes = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;
    case zx_itemIDRef_ATTR|zx_dst_NS:  x->itemIDRef = x->gg.attr; return 1;
    case zx_objectType_ATTR|zx_dst_NS:  x->objectType = x->gg.attr; return 1;
    case zx_predefined_ATTR|zx_dst_NS:  x->predefined = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_ResultQuery(struct zx_ctx* c, struct zx_idhrxml_ResultQuery_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_dst_ChangeFormat_ELEM:
    if (!x->ChangeFormat)
      x->ChangeFormat = el;
    return 1;
  case zx_idhrxml_Select_ELEM:
    if (!x->Select)
      x->Select = el;
    return 1;
  case zx_idhrxml_Sort_ELEM:
    if (!x->Sort)
      x->Sort = el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_Subscription(struct zx_ctx* c, struct zx_idhrxml_Subscription_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_adminNotifyToRef_ATTR:  x->adminNotifyToRef = x->gg.attr; return 1;
    case zx_expires_ATTR:  x->expires = x->gg.attr; return 1;
    case zx_id_ATTR:  x->id = x->gg.attr; return 1;
    case zx_includeData_ATTR:  x->includeData = x->gg.attr; return 1;
    case zx_notifyToRef_ATTR:  x->notifyToRef = x->gg.attr; return 1;
    case zx_starts_ATTR:  x->starts = x->gg.attr; return 1;
    case zx_subscriptionID_ATTR:  x->subscriptionID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_Subscription(struct zx_ctx* c, struct zx_idhrxml_Subscription_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_subs_RefItem_ELEM:
    if (!x->RefItem)
      x->RefItem = (struct zx_subs_RefItem_s*)el;
    return 1;
  case zx_lu_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_lu_Extension_s*)el;
    return 1;
  case zx_idhrxml_ResultQuery_ELEM:
    if (!x->ResultQuery)
      x->ResultQuery = (struct zx_idhrxml_ResultQuery_s*)el;
    return 1;
  case zx_idhrxml_Aggregation_ELEM:
    if (!x->Aggregation)
      x->Aggregation = el;
    return 1;
  case zx_idhrxml_Trigger_ELEM:
    if (!x->Trigger)
      x->Trigger = el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_idhrxml_TestItem(struct zx_ctx* c, struct zx_idhrxml_TestItem_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_id_ATTR:  x->id = x->gg.attr; return 1;
    case zx_itemID_ATTR|zx_dst_NS:  x->itemID = x->gg.attr; return 1;
    case zx_objectType_ATTR|zx_dst_NS:  x->objectType = x->gg.attr; return 1;
    case zx_predefined_ATTR|zx_dst_NS:  x->predefined = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_idhrxml_TestItem(struct zx_ctx* c, struct zx_idhrxml_TestItem_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_idhrxml_TestOp_ELEM:
    if (!x->TestOp)
      x->TestOp = el;
    return 1;

  default: return 0;
  }
}


/* EOF -- c/zx-idhrxml-dec.c */