/* c/zx-data.h - WARNING: This header was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006,2010 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_data_h
#define _c_zx_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-a-data.h"
#include "c/zx-ac-data.h"
#include "c/zx-as-data.h"
#include "c/zx-b-data.h"
#include "c/zx-b12-data.h"
#include "c/zx-cb-data.h"
#include "c/zx-cdm-data.h"
#include "c/zx-dap-data.h"
#include "c/zx-demomed-data.h"
#include "c/zx-di-data.h"
#include "c/zx-di12-data.h"
#include "c/zx-dp-data.h"
#include "c/zx-ds-data.h"
#include "c/zx-dst-data.h"
#include "c/zx-e-data.h"
#include "c/zx-ecp-data.h"
#include "c/zx-exca-data.h"
#include "c/zx-ff12-data.h"
#include "c/zx-gl-data.h"
#include "c/zx-hrxml-data.h"
#include "c/zx-idhrxml-data.h"
#include "c/zx-idp-data.h"
#include "c/zx-idpdisc-data.h"
#include "c/zx-im-data.h"
#include "c/zx-is-data.h"
#include "c/zx-is12-data.h"
#include "c/zx-lu-data.h"
#include "c/zx-m20-data.h"
#include "c/zx-md-data.h"
#include "c/zx-mm7-data.h"
#include "c/zx-paos-data.h"
#include "c/zx-pmm-data.h"
#include "c/zx-prov-data.h"
#include "c/zx-ps-data.h"
#include "c/zx-sa-data.h"
#include "c/zx-sa11-data.h"
#include "c/zx-sbf-data.h"
#include "c/zx-sec-data.h"
#include "c/zx-sec12-data.h"
#include "c/zx-shibmd-data.h"
#include "c/zx-shps-data.h"
#include "c/zx-sp-data.h"
#include "c/zx-sp11-data.h"
#include "c/zx-subs-data.h"
#include "c/zx-tas3-data.h"
#include "c/zx-tas3sol-data.h"
#include "c/zx-wsc-data.h"
#include "c/zx-wsp-data.h"
#include "c/zx-wsse-data.h"
#include "c/zx-wst-data.h"
#include "c/zx-wsu-data.h"
#include "c/zx-xa-data.h"
#include "c/zx-xac-data.h"
#include "c/zx-xasa-data.h"
#include "c/zx-xasacd1-data.h"
#include "c/zx-xasp-data.h"
#include "c/zx-xaspcd1-data.h"
#include "c/zx-xenc-data.h"
#include "c/zx-xml-data.h"
#include "c/zx-xs-data.h"
#include "c/zx-xsi-data.h"


#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

struct zx_ns_s* zx_url2ns(const char* str, unsigned int len);

#define zx_N_ATTR 337
extern struct zx_at_tok zx_at_tab[zx__ATTR_MAX]; /* gperf generated, see zx-attrs.c */
struct zx_at_tok* zx_attr2tok(const char* s, unsigned int len);

#define zx_N_ELEM 1338
#define zx_N_EL_DESC (1149 + 499)
extern struct zx_el_tok zx_el_tab[zx__ELEM_MAX]; /* gperf generated, see zx-elems.c */
struct zx_el_tok* zx_elem2tok(const char* s, unsigned int len);

/* -------------------------- root -------------------------- */
/* refby( ) */
#ifndef zx_root_EXT
#define zx_root_EXT
#endif
struct zx_root_s {
  ZX_ELEM_EXT
  zx_root_EXT
  struct zx_sa_Assertion_s* Assertion;	/* {0,-1} root */
  struct zx_sa_EncryptedAssertion_s* EncryptedAssertion;	/* {0,-1} root */
  struct zx_sa_NameID_s* NameID;	/* {0,-1} root */
  struct zx_sa_EncryptedID_s* EncryptedID;	/* {0,-1} root */
  struct zx_elem_s* NewID;	/* {0,-1} xs:string */
  struct zx_sp_AuthnRequest_s* AuthnRequest;	/* {0,-1} root */
  struct zx_sp_Response_s* Response;	/* {0,-1} root */
  struct zx_sp_LogoutRequest_s* LogoutRequest;	/* {0,-1} root */
  struct zx_sp_LogoutResponse_s* LogoutResponse;	/* {0,-1} root */
  struct zx_sp_ManageNameIDRequest_s* ManageNameIDRequest;	/* {0,-1} root */
  struct zx_sp_ManageNameIDResponse_s* ManageNameIDResponse;	/* {0,-1} root */
  struct zx_e_Envelope_s* Envelope;	/* {0,-1} root */
  struct zx_e_Header_s* Header;	/* {0,-1} root */
  struct zx_e_Body_s* Body;	/* {0,-1} root */
  struct zx_md_EntityDescriptor_s* EntityDescriptor;	/* {0,-1} root */
  struct zx_md_EntitiesDescriptor_s* EntitiesDescriptor;	/* {0,-1} root */
  struct zx_xasp_XACMLAuthzDecisionQuery_s* XACMLAuthzDecisionQuery;	/* {0,-1} root */
  struct zx_xasp_XACMLPolicyQuery_s* XACMLPolicyQuery;	/* {0,-1} root */
  struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* xaspcd1_XACMLAuthzDecisionQuery;	/* {0,-1} root */
  struct zx_xaspcd1_XACMLPolicyQuery_s* xaspcd1_XACMLPolicyQuery;	/* {0,-1} root */
  struct zx_a_EndpointReference_s* EndpointReference;	/* {0,-1} root */
  struct zx_sec_Token_s* Token;	/* {0,-1} root */
  struct zx_hrxml_Candidate_s* Candidate;	/* {0,-1} root */
  struct zx_sa11_Assertion_s* sa11_Assertion;	/* {0,-1} root */
  struct zx_sp11_Request_s* Request;	/* {0,-1} root */
  struct zx_sp11_Response_s* sp11_Response;	/* {0,-1} root */
  struct zx_ff12_Assertion_s* ff12_Assertion;	/* {0,-1} root */
  struct zx_ff12_AuthnRequest_s* ff12_AuthnRequest;	/* {0,-1} root */
  struct zx_ff12_AuthnResponse_s* AuthnResponse;	/* {0,-1} root */
  struct zx_ff12_AuthnRequestEnvelope_s* AuthnRequestEnvelope;	/* {0,-1} root */
  struct zx_ff12_AuthnResponseEnvelope_s* AuthnResponseEnvelope;	/* {0,-1} root */
  struct zx_ff12_RegisterNameIdentifierRequest_s* RegisterNameIdentifierRequest;	/* {0,-1} root */
  struct zx_ff12_RegisterNameIdentifierResponse_s* RegisterNameIdentifierResponse;	/* {0,-1} root */
  struct zx_ff12_FederationTerminationNotification_s* FederationTerminationNotification;	/* {0,-1} root */
  struct zx_ff12_LogoutRequest_s* ff12_LogoutRequest;	/* {0,-1} root */
  struct zx_ff12_LogoutResponse_s* ff12_LogoutResponse;	/* {0,-1} root */
  struct zx_ff12_NameIdentifierMappingRequest_s* NameIdentifierMappingRequest;	/* {0,-1} root */
  struct zx_ff12_NameIdentifierMappingResponse_s* NameIdentifierMappingResponse;	/* {0,-1} root */
  struct zx_m20_EntityDescriptor_s* m20_EntityDescriptor;	/* {0,-1} root */
  struct zx_m20_EntitiesDescriptor_s* m20_EntitiesDescriptor;	/* {0,-1}  */
};

#define zx_NEW_root(c, father) (struct zx_root_s*)zx_new_elem((c),(father),zx_root_ELEM)
int zx_DEC_ATTR_root(struct zx_ctx* c, struct zx_root_s* x);
int zx_DEC_ELEM_root(struct zx_ctx* c, struct zx_root_s* x);

#ifdef ZX_ENA_AUX
struct zx_root_s* zx_DEEP_CLONE_root(struct zx_ctx* c, struct zx_root_s* x, int dup_strs);
void zx_DUP_STRS_root(struct zx_ctx* c, struct zx_root_s* x);
int zx_WALK_SO_root(struct zx_ctx* c, struct zx_root_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_root(struct zx_ctx* c, struct zx_root_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif

#ifdef ZX_ENA_GETPUT

struct zx_sa_Assertion_s* zx_root_GET_Assertion(struct zx_root_s* x, int n);
struct zx_sa_EncryptedAssertion_s* zx_root_GET_EncryptedAssertion(struct zx_root_s* x, int n);
struct zx_sa_NameID_s* zx_root_GET_NameID(struct zx_root_s* x, int n);
struct zx_sa_EncryptedID_s* zx_root_GET_EncryptedID(struct zx_root_s* x, int n);
struct zx_elem_s* zx_root_GET_NewID(struct zx_root_s* x, int n);
struct zx_sp_AuthnRequest_s* zx_root_GET_AuthnRequest(struct zx_root_s* x, int n);
struct zx_sp_Response_s* zx_root_GET_Response(struct zx_root_s* x, int n);
struct zx_sp_LogoutRequest_s* zx_root_GET_LogoutRequest(struct zx_root_s* x, int n);
struct zx_sp_LogoutResponse_s* zx_root_GET_LogoutResponse(struct zx_root_s* x, int n);
struct zx_sp_ManageNameIDRequest_s* zx_root_GET_ManageNameIDRequest(struct zx_root_s* x, int n);
struct zx_sp_ManageNameIDResponse_s* zx_root_GET_ManageNameIDResponse(struct zx_root_s* x, int n);
struct zx_e_Envelope_s* zx_root_GET_Envelope(struct zx_root_s* x, int n);
struct zx_e_Header_s* zx_root_GET_Header(struct zx_root_s* x, int n);
struct zx_e_Body_s* zx_root_GET_Body(struct zx_root_s* x, int n);
struct zx_md_EntityDescriptor_s* zx_root_GET_EntityDescriptor(struct zx_root_s* x, int n);
struct zx_md_EntitiesDescriptor_s* zx_root_GET_EntitiesDescriptor(struct zx_root_s* x, int n);
struct zx_xasp_XACMLAuthzDecisionQuery_s* zx_root_GET_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n);
struct zx_xasp_XACMLPolicyQuery_s* zx_root_GET_XACMLPolicyQuery(struct zx_root_s* x, int n);
struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* zx_root_GET_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n);
struct zx_xaspcd1_XACMLPolicyQuery_s* zx_root_GET_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x, int n);
struct zx_a_EndpointReference_s* zx_root_GET_EndpointReference(struct zx_root_s* x, int n);
struct zx_sec_Token_s* zx_root_GET_Token(struct zx_root_s* x, int n);
struct zx_hrxml_Candidate_s* zx_root_GET_Candidate(struct zx_root_s* x, int n);
struct zx_sa11_Assertion_s* zx_root_GET_sa11_Assertion(struct zx_root_s* x, int n);
struct zx_sp11_Request_s* zx_root_GET_Request(struct zx_root_s* x, int n);
struct zx_sp11_Response_s* zx_root_GET_sp11_Response(struct zx_root_s* x, int n);
struct zx_ff12_Assertion_s* zx_root_GET_ff12_Assertion(struct zx_root_s* x, int n);
struct zx_ff12_AuthnRequest_s* zx_root_GET_ff12_AuthnRequest(struct zx_root_s* x, int n);
struct zx_ff12_AuthnResponse_s* zx_root_GET_AuthnResponse(struct zx_root_s* x, int n);
struct zx_ff12_AuthnRequestEnvelope_s* zx_root_GET_AuthnRequestEnvelope(struct zx_root_s* x, int n);
struct zx_ff12_AuthnResponseEnvelope_s* zx_root_GET_AuthnResponseEnvelope(struct zx_root_s* x, int n);
struct zx_ff12_RegisterNameIdentifierRequest_s* zx_root_GET_RegisterNameIdentifierRequest(struct zx_root_s* x, int n);
struct zx_ff12_RegisterNameIdentifierResponse_s* zx_root_GET_RegisterNameIdentifierResponse(struct zx_root_s* x, int n);
struct zx_ff12_FederationTerminationNotification_s* zx_root_GET_FederationTerminationNotification(struct zx_root_s* x, int n);
struct zx_ff12_LogoutRequest_s* zx_root_GET_ff12_LogoutRequest(struct zx_root_s* x, int n);
struct zx_ff12_LogoutResponse_s* zx_root_GET_ff12_LogoutResponse(struct zx_root_s* x, int n);
struct zx_ff12_NameIdentifierMappingRequest_s* zx_root_GET_NameIdentifierMappingRequest(struct zx_root_s* x, int n);
struct zx_ff12_NameIdentifierMappingResponse_s* zx_root_GET_NameIdentifierMappingResponse(struct zx_root_s* x, int n);
struct zx_m20_EntityDescriptor_s* zx_root_GET_m20_EntityDescriptor(struct zx_root_s* x, int n);
struct zx_m20_EntitiesDescriptor_s* zx_root_GET_m20_EntitiesDescriptor(struct zx_root_s* x, int n);

int zx_root_NUM_Assertion(struct zx_root_s* x);
int zx_root_NUM_EncryptedAssertion(struct zx_root_s* x);
int zx_root_NUM_NameID(struct zx_root_s* x);
int zx_root_NUM_EncryptedID(struct zx_root_s* x);
int zx_root_NUM_NewID(struct zx_root_s* x);
int zx_root_NUM_AuthnRequest(struct zx_root_s* x);
int zx_root_NUM_Response(struct zx_root_s* x);
int zx_root_NUM_LogoutRequest(struct zx_root_s* x);
int zx_root_NUM_LogoutResponse(struct zx_root_s* x);
int zx_root_NUM_ManageNameIDRequest(struct zx_root_s* x);
int zx_root_NUM_ManageNameIDResponse(struct zx_root_s* x);
int zx_root_NUM_Envelope(struct zx_root_s* x);
int zx_root_NUM_Header(struct zx_root_s* x);
int zx_root_NUM_Body(struct zx_root_s* x);
int zx_root_NUM_EntityDescriptor(struct zx_root_s* x);
int zx_root_NUM_EntitiesDescriptor(struct zx_root_s* x);
int zx_root_NUM_XACMLAuthzDecisionQuery(struct zx_root_s* x);
int zx_root_NUM_XACMLPolicyQuery(struct zx_root_s* x);
int zx_root_NUM_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x);
int zx_root_NUM_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x);
int zx_root_NUM_EndpointReference(struct zx_root_s* x);
int zx_root_NUM_Token(struct zx_root_s* x);
int zx_root_NUM_Candidate(struct zx_root_s* x);
int zx_root_NUM_sa11_Assertion(struct zx_root_s* x);
int zx_root_NUM_Request(struct zx_root_s* x);
int zx_root_NUM_sp11_Response(struct zx_root_s* x);
int zx_root_NUM_ff12_Assertion(struct zx_root_s* x);
int zx_root_NUM_ff12_AuthnRequest(struct zx_root_s* x);
int zx_root_NUM_AuthnResponse(struct zx_root_s* x);
int zx_root_NUM_AuthnRequestEnvelope(struct zx_root_s* x);
int zx_root_NUM_AuthnResponseEnvelope(struct zx_root_s* x);
int zx_root_NUM_RegisterNameIdentifierRequest(struct zx_root_s* x);
int zx_root_NUM_RegisterNameIdentifierResponse(struct zx_root_s* x);
int zx_root_NUM_FederationTerminationNotification(struct zx_root_s* x);
int zx_root_NUM_ff12_LogoutRequest(struct zx_root_s* x);
int zx_root_NUM_ff12_LogoutResponse(struct zx_root_s* x);
int zx_root_NUM_NameIdentifierMappingRequest(struct zx_root_s* x);
int zx_root_NUM_NameIdentifierMappingResponse(struct zx_root_s* x);
int zx_root_NUM_m20_EntityDescriptor(struct zx_root_s* x);
int zx_root_NUM_m20_EntitiesDescriptor(struct zx_root_s* x);

struct zx_sa_Assertion_s* zx_root_POP_Assertion(struct zx_root_s* x);
struct zx_sa_EncryptedAssertion_s* zx_root_POP_EncryptedAssertion(struct zx_root_s* x);
struct zx_sa_NameID_s* zx_root_POP_NameID(struct zx_root_s* x);
struct zx_sa_EncryptedID_s* zx_root_POP_EncryptedID(struct zx_root_s* x);
struct zx_elem_s* zx_root_POP_NewID(struct zx_root_s* x);
struct zx_sp_AuthnRequest_s* zx_root_POP_AuthnRequest(struct zx_root_s* x);
struct zx_sp_Response_s* zx_root_POP_Response(struct zx_root_s* x);
struct zx_sp_LogoutRequest_s* zx_root_POP_LogoutRequest(struct zx_root_s* x);
struct zx_sp_LogoutResponse_s* zx_root_POP_LogoutResponse(struct zx_root_s* x);
struct zx_sp_ManageNameIDRequest_s* zx_root_POP_ManageNameIDRequest(struct zx_root_s* x);
struct zx_sp_ManageNameIDResponse_s* zx_root_POP_ManageNameIDResponse(struct zx_root_s* x);
struct zx_e_Envelope_s* zx_root_POP_Envelope(struct zx_root_s* x);
struct zx_e_Header_s* zx_root_POP_Header(struct zx_root_s* x);
struct zx_e_Body_s* zx_root_POP_Body(struct zx_root_s* x);
struct zx_md_EntityDescriptor_s* zx_root_POP_EntityDescriptor(struct zx_root_s* x);
struct zx_md_EntitiesDescriptor_s* zx_root_POP_EntitiesDescriptor(struct zx_root_s* x);
struct zx_xasp_XACMLAuthzDecisionQuery_s* zx_root_POP_XACMLAuthzDecisionQuery(struct zx_root_s* x);
struct zx_xasp_XACMLPolicyQuery_s* zx_root_POP_XACMLPolicyQuery(struct zx_root_s* x);
struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* zx_root_POP_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x);
struct zx_xaspcd1_XACMLPolicyQuery_s* zx_root_POP_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x);
struct zx_a_EndpointReference_s* zx_root_POP_EndpointReference(struct zx_root_s* x);
struct zx_sec_Token_s* zx_root_POP_Token(struct zx_root_s* x);
struct zx_hrxml_Candidate_s* zx_root_POP_Candidate(struct zx_root_s* x);
struct zx_sa11_Assertion_s* zx_root_POP_sa11_Assertion(struct zx_root_s* x);
struct zx_sp11_Request_s* zx_root_POP_Request(struct zx_root_s* x);
struct zx_sp11_Response_s* zx_root_POP_sp11_Response(struct zx_root_s* x);
struct zx_ff12_Assertion_s* zx_root_POP_ff12_Assertion(struct zx_root_s* x);
struct zx_ff12_AuthnRequest_s* zx_root_POP_ff12_AuthnRequest(struct zx_root_s* x);
struct zx_ff12_AuthnResponse_s* zx_root_POP_AuthnResponse(struct zx_root_s* x);
struct zx_ff12_AuthnRequestEnvelope_s* zx_root_POP_AuthnRequestEnvelope(struct zx_root_s* x);
struct zx_ff12_AuthnResponseEnvelope_s* zx_root_POP_AuthnResponseEnvelope(struct zx_root_s* x);
struct zx_ff12_RegisterNameIdentifierRequest_s* zx_root_POP_RegisterNameIdentifierRequest(struct zx_root_s* x);
struct zx_ff12_RegisterNameIdentifierResponse_s* zx_root_POP_RegisterNameIdentifierResponse(struct zx_root_s* x);
struct zx_ff12_FederationTerminationNotification_s* zx_root_POP_FederationTerminationNotification(struct zx_root_s* x);
struct zx_ff12_LogoutRequest_s* zx_root_POP_ff12_LogoutRequest(struct zx_root_s* x);
struct zx_ff12_LogoutResponse_s* zx_root_POP_ff12_LogoutResponse(struct zx_root_s* x);
struct zx_ff12_NameIdentifierMappingRequest_s* zx_root_POP_NameIdentifierMappingRequest(struct zx_root_s* x);
struct zx_ff12_NameIdentifierMappingResponse_s* zx_root_POP_NameIdentifierMappingResponse(struct zx_root_s* x);
struct zx_m20_EntityDescriptor_s* zx_root_POP_m20_EntityDescriptor(struct zx_root_s* x);
struct zx_m20_EntitiesDescriptor_s* zx_root_POP_m20_EntitiesDescriptor(struct zx_root_s* x);

void zx_root_PUSH_Assertion(struct zx_root_s* x, struct zx_sa_Assertion_s* y);
void zx_root_PUSH_EncryptedAssertion(struct zx_root_s* x, struct zx_sa_EncryptedAssertion_s* y);
void zx_root_PUSH_NameID(struct zx_root_s* x, struct zx_sa_NameID_s* y);
void zx_root_PUSH_EncryptedID(struct zx_root_s* x, struct zx_sa_EncryptedID_s* y);
void zx_root_PUSH_NewID(struct zx_root_s* x, struct zx_elem_s* y);
void zx_root_PUSH_AuthnRequest(struct zx_root_s* x, struct zx_sp_AuthnRequest_s* y);
void zx_root_PUSH_Response(struct zx_root_s* x, struct zx_sp_Response_s* y);
void zx_root_PUSH_LogoutRequest(struct zx_root_s* x, struct zx_sp_LogoutRequest_s* y);
void zx_root_PUSH_LogoutResponse(struct zx_root_s* x, struct zx_sp_LogoutResponse_s* y);
void zx_root_PUSH_ManageNameIDRequest(struct zx_root_s* x, struct zx_sp_ManageNameIDRequest_s* y);
void zx_root_PUSH_ManageNameIDResponse(struct zx_root_s* x, struct zx_sp_ManageNameIDResponse_s* y);
void zx_root_PUSH_Envelope(struct zx_root_s* x, struct zx_e_Envelope_s* y);
void zx_root_PUSH_Header(struct zx_root_s* x, struct zx_e_Header_s* y);
void zx_root_PUSH_Body(struct zx_root_s* x, struct zx_e_Body_s* y);
void zx_root_PUSH_EntityDescriptor(struct zx_root_s* x, struct zx_md_EntityDescriptor_s* y);
void zx_root_PUSH_EntitiesDescriptor(struct zx_root_s* x, struct zx_md_EntitiesDescriptor_s* y);
void zx_root_PUSH_XACMLAuthzDecisionQuery(struct zx_root_s* x, struct zx_xasp_XACMLAuthzDecisionQuery_s* y);
void zx_root_PUSH_XACMLPolicyQuery(struct zx_root_s* x, struct zx_xasp_XACMLPolicyQuery_s* y);
void zx_root_PUSH_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x, struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* y);
void zx_root_PUSH_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x, struct zx_xaspcd1_XACMLPolicyQuery_s* y);
void zx_root_PUSH_EndpointReference(struct zx_root_s* x, struct zx_a_EndpointReference_s* y);
void zx_root_PUSH_Token(struct zx_root_s* x, struct zx_sec_Token_s* y);
void zx_root_PUSH_Candidate(struct zx_root_s* x, struct zx_hrxml_Candidate_s* y);
void zx_root_PUSH_sa11_Assertion(struct zx_root_s* x, struct zx_sa11_Assertion_s* y);
void zx_root_PUSH_Request(struct zx_root_s* x, struct zx_sp11_Request_s* y);
void zx_root_PUSH_sp11_Response(struct zx_root_s* x, struct zx_sp11_Response_s* y);
void zx_root_PUSH_ff12_Assertion(struct zx_root_s* x, struct zx_ff12_Assertion_s* y);
void zx_root_PUSH_ff12_AuthnRequest(struct zx_root_s* x, struct zx_ff12_AuthnRequest_s* y);
void zx_root_PUSH_AuthnResponse(struct zx_root_s* x, struct zx_ff12_AuthnResponse_s* y);
void zx_root_PUSH_AuthnRequestEnvelope(struct zx_root_s* x, struct zx_ff12_AuthnRequestEnvelope_s* y);
void zx_root_PUSH_AuthnResponseEnvelope(struct zx_root_s* x, struct zx_ff12_AuthnResponseEnvelope_s* y);
void zx_root_PUSH_RegisterNameIdentifierRequest(struct zx_root_s* x, struct zx_ff12_RegisterNameIdentifierRequest_s* y);
void zx_root_PUSH_RegisterNameIdentifierResponse(struct zx_root_s* x, struct zx_ff12_RegisterNameIdentifierResponse_s* y);
void zx_root_PUSH_FederationTerminationNotification(struct zx_root_s* x, struct zx_ff12_FederationTerminationNotification_s* y);
void zx_root_PUSH_ff12_LogoutRequest(struct zx_root_s* x, struct zx_ff12_LogoutRequest_s* y);
void zx_root_PUSH_ff12_LogoutResponse(struct zx_root_s* x, struct zx_ff12_LogoutResponse_s* y);
void zx_root_PUSH_NameIdentifierMappingRequest(struct zx_root_s* x, struct zx_ff12_NameIdentifierMappingRequest_s* y);
void zx_root_PUSH_NameIdentifierMappingResponse(struct zx_root_s* x, struct zx_ff12_NameIdentifierMappingResponse_s* y);
void zx_root_PUSH_m20_EntityDescriptor(struct zx_root_s* x, struct zx_m20_EntityDescriptor_s* y);
void zx_root_PUSH_m20_EntitiesDescriptor(struct zx_root_s* x, struct zx_m20_EntitiesDescriptor_s* y);


void zx_root_PUT_Assertion(struct zx_root_s* x, int n, struct zx_sa_Assertion_s* y);
void zx_root_PUT_EncryptedAssertion(struct zx_root_s* x, int n, struct zx_sa_EncryptedAssertion_s* y);
void zx_root_PUT_NameID(struct zx_root_s* x, int n, struct zx_sa_NameID_s* y);
void zx_root_PUT_EncryptedID(struct zx_root_s* x, int n, struct zx_sa_EncryptedID_s* y);
void zx_root_PUT_NewID(struct zx_root_s* x, int n, struct zx_elem_s* y);
void zx_root_PUT_AuthnRequest(struct zx_root_s* x, int n, struct zx_sp_AuthnRequest_s* y);
void zx_root_PUT_Response(struct zx_root_s* x, int n, struct zx_sp_Response_s* y);
void zx_root_PUT_LogoutRequest(struct zx_root_s* x, int n, struct zx_sp_LogoutRequest_s* y);
void zx_root_PUT_LogoutResponse(struct zx_root_s* x, int n, struct zx_sp_LogoutResponse_s* y);
void zx_root_PUT_ManageNameIDRequest(struct zx_root_s* x, int n, struct zx_sp_ManageNameIDRequest_s* y);
void zx_root_PUT_ManageNameIDResponse(struct zx_root_s* x, int n, struct zx_sp_ManageNameIDResponse_s* y);
void zx_root_PUT_Envelope(struct zx_root_s* x, int n, struct zx_e_Envelope_s* y);
void zx_root_PUT_Header(struct zx_root_s* x, int n, struct zx_e_Header_s* y);
void zx_root_PUT_Body(struct zx_root_s* x, int n, struct zx_e_Body_s* y);
void zx_root_PUT_EntityDescriptor(struct zx_root_s* x, int n, struct zx_md_EntityDescriptor_s* y);
void zx_root_PUT_EntitiesDescriptor(struct zx_root_s* x, int n, struct zx_md_EntitiesDescriptor_s* y);
void zx_root_PUT_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n, struct zx_xasp_XACMLAuthzDecisionQuery_s* y);
void zx_root_PUT_XACMLPolicyQuery(struct zx_root_s* x, int n, struct zx_xasp_XACMLPolicyQuery_s* y);
void zx_root_PUT_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n, struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* y);
void zx_root_PUT_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x, int n, struct zx_xaspcd1_XACMLPolicyQuery_s* y);
void zx_root_PUT_EndpointReference(struct zx_root_s* x, int n, struct zx_a_EndpointReference_s* y);
void zx_root_PUT_Token(struct zx_root_s* x, int n, struct zx_sec_Token_s* y);
void zx_root_PUT_Candidate(struct zx_root_s* x, int n, struct zx_hrxml_Candidate_s* y);
void zx_root_PUT_sa11_Assertion(struct zx_root_s* x, int n, struct zx_sa11_Assertion_s* y);
void zx_root_PUT_Request(struct zx_root_s* x, int n, struct zx_sp11_Request_s* y);
void zx_root_PUT_sp11_Response(struct zx_root_s* x, int n, struct zx_sp11_Response_s* y);
void zx_root_PUT_ff12_Assertion(struct zx_root_s* x, int n, struct zx_ff12_Assertion_s* y);
void zx_root_PUT_ff12_AuthnRequest(struct zx_root_s* x, int n, struct zx_ff12_AuthnRequest_s* y);
void zx_root_PUT_AuthnResponse(struct zx_root_s* x, int n, struct zx_ff12_AuthnResponse_s* y);
void zx_root_PUT_AuthnRequestEnvelope(struct zx_root_s* x, int n, struct zx_ff12_AuthnRequestEnvelope_s* y);
void zx_root_PUT_AuthnResponseEnvelope(struct zx_root_s* x, int n, struct zx_ff12_AuthnResponseEnvelope_s* y);
void zx_root_PUT_RegisterNameIdentifierRequest(struct zx_root_s* x, int n, struct zx_ff12_RegisterNameIdentifierRequest_s* y);
void zx_root_PUT_RegisterNameIdentifierResponse(struct zx_root_s* x, int n, struct zx_ff12_RegisterNameIdentifierResponse_s* y);
void zx_root_PUT_FederationTerminationNotification(struct zx_root_s* x, int n, struct zx_ff12_FederationTerminationNotification_s* y);
void zx_root_PUT_ff12_LogoutRequest(struct zx_root_s* x, int n, struct zx_ff12_LogoutRequest_s* y);
void zx_root_PUT_ff12_LogoutResponse(struct zx_root_s* x, int n, struct zx_ff12_LogoutResponse_s* y);
void zx_root_PUT_NameIdentifierMappingRequest(struct zx_root_s* x, int n, struct zx_ff12_NameIdentifierMappingRequest_s* y);
void zx_root_PUT_NameIdentifierMappingResponse(struct zx_root_s* x, int n, struct zx_ff12_NameIdentifierMappingResponse_s* y);
void zx_root_PUT_m20_EntityDescriptor(struct zx_root_s* x, int n, struct zx_m20_EntityDescriptor_s* y);
void zx_root_PUT_m20_EntitiesDescriptor(struct zx_root_s* x, int n, struct zx_m20_EntitiesDescriptor_s* y);

void zx_root_ADD_Assertion(struct zx_root_s* x, int n, struct zx_sa_Assertion_s* z);
void zx_root_ADD_EncryptedAssertion(struct zx_root_s* x, int n, struct zx_sa_EncryptedAssertion_s* z);
void zx_root_ADD_NameID(struct zx_root_s* x, int n, struct zx_sa_NameID_s* z);
void zx_root_ADD_EncryptedID(struct zx_root_s* x, int n, struct zx_sa_EncryptedID_s* z);
void zx_root_ADD_NewID(struct zx_root_s* x, int n, struct zx_elem_s* z);
void zx_root_ADD_AuthnRequest(struct zx_root_s* x, int n, struct zx_sp_AuthnRequest_s* z);
void zx_root_ADD_Response(struct zx_root_s* x, int n, struct zx_sp_Response_s* z);
void zx_root_ADD_LogoutRequest(struct zx_root_s* x, int n, struct zx_sp_LogoutRequest_s* z);
void zx_root_ADD_LogoutResponse(struct zx_root_s* x, int n, struct zx_sp_LogoutResponse_s* z);
void zx_root_ADD_ManageNameIDRequest(struct zx_root_s* x, int n, struct zx_sp_ManageNameIDRequest_s* z);
void zx_root_ADD_ManageNameIDResponse(struct zx_root_s* x, int n, struct zx_sp_ManageNameIDResponse_s* z);
void zx_root_ADD_Envelope(struct zx_root_s* x, int n, struct zx_e_Envelope_s* z);
void zx_root_ADD_Header(struct zx_root_s* x, int n, struct zx_e_Header_s* z);
void zx_root_ADD_Body(struct zx_root_s* x, int n, struct zx_e_Body_s* z);
void zx_root_ADD_EntityDescriptor(struct zx_root_s* x, int n, struct zx_md_EntityDescriptor_s* z);
void zx_root_ADD_EntitiesDescriptor(struct zx_root_s* x, int n, struct zx_md_EntitiesDescriptor_s* z);
void zx_root_ADD_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n, struct zx_xasp_XACMLAuthzDecisionQuery_s* z);
void zx_root_ADD_XACMLPolicyQuery(struct zx_root_s* x, int n, struct zx_xasp_XACMLPolicyQuery_s* z);
void zx_root_ADD_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n, struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* z);
void zx_root_ADD_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x, int n, struct zx_xaspcd1_XACMLPolicyQuery_s* z);
void zx_root_ADD_EndpointReference(struct zx_root_s* x, int n, struct zx_a_EndpointReference_s* z);
void zx_root_ADD_Token(struct zx_root_s* x, int n, struct zx_sec_Token_s* z);
void zx_root_ADD_Candidate(struct zx_root_s* x, int n, struct zx_hrxml_Candidate_s* z);
void zx_root_ADD_sa11_Assertion(struct zx_root_s* x, int n, struct zx_sa11_Assertion_s* z);
void zx_root_ADD_Request(struct zx_root_s* x, int n, struct zx_sp11_Request_s* z);
void zx_root_ADD_sp11_Response(struct zx_root_s* x, int n, struct zx_sp11_Response_s* z);
void zx_root_ADD_ff12_Assertion(struct zx_root_s* x, int n, struct zx_ff12_Assertion_s* z);
void zx_root_ADD_ff12_AuthnRequest(struct zx_root_s* x, int n, struct zx_ff12_AuthnRequest_s* z);
void zx_root_ADD_AuthnResponse(struct zx_root_s* x, int n, struct zx_ff12_AuthnResponse_s* z);
void zx_root_ADD_AuthnRequestEnvelope(struct zx_root_s* x, int n, struct zx_ff12_AuthnRequestEnvelope_s* z);
void zx_root_ADD_AuthnResponseEnvelope(struct zx_root_s* x, int n, struct zx_ff12_AuthnResponseEnvelope_s* z);
void zx_root_ADD_RegisterNameIdentifierRequest(struct zx_root_s* x, int n, struct zx_ff12_RegisterNameIdentifierRequest_s* z);
void zx_root_ADD_RegisterNameIdentifierResponse(struct zx_root_s* x, int n, struct zx_ff12_RegisterNameIdentifierResponse_s* z);
void zx_root_ADD_FederationTerminationNotification(struct zx_root_s* x, int n, struct zx_ff12_FederationTerminationNotification_s* z);
void zx_root_ADD_ff12_LogoutRequest(struct zx_root_s* x, int n, struct zx_ff12_LogoutRequest_s* z);
void zx_root_ADD_ff12_LogoutResponse(struct zx_root_s* x, int n, struct zx_ff12_LogoutResponse_s* z);
void zx_root_ADD_NameIdentifierMappingRequest(struct zx_root_s* x, int n, struct zx_ff12_NameIdentifierMappingRequest_s* z);
void zx_root_ADD_NameIdentifierMappingResponse(struct zx_root_s* x, int n, struct zx_ff12_NameIdentifierMappingResponse_s* z);
void zx_root_ADD_m20_EntityDescriptor(struct zx_root_s* x, int n, struct zx_m20_EntityDescriptor_s* z);
void zx_root_ADD_m20_EntitiesDescriptor(struct zx_root_s* x, int n, struct zx_m20_EntitiesDescriptor_s* z);

void zx_root_DEL_Assertion(struct zx_root_s* x, int n);
void zx_root_DEL_EncryptedAssertion(struct zx_root_s* x, int n);
void zx_root_DEL_NameID(struct zx_root_s* x, int n);
void zx_root_DEL_EncryptedID(struct zx_root_s* x, int n);
void zx_root_DEL_NewID(struct zx_root_s* x,int n);
void zx_root_DEL_AuthnRequest(struct zx_root_s* x, int n);
void zx_root_DEL_Response(struct zx_root_s* x, int n);
void zx_root_DEL_LogoutRequest(struct zx_root_s* x, int n);
void zx_root_DEL_LogoutResponse(struct zx_root_s* x, int n);
void zx_root_DEL_ManageNameIDRequest(struct zx_root_s* x, int n);
void zx_root_DEL_ManageNameIDResponse(struct zx_root_s* x, int n);
void zx_root_DEL_Envelope(struct zx_root_s* x, int n);
void zx_root_DEL_Header(struct zx_root_s* x, int n);
void zx_root_DEL_Body(struct zx_root_s* x, int n);
void zx_root_DEL_EntityDescriptor(struct zx_root_s* x, int n);
void zx_root_DEL_EntitiesDescriptor(struct zx_root_s* x, int n);
void zx_root_DEL_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n);
void zx_root_DEL_XACMLPolicyQuery(struct zx_root_s* x, int n);
void zx_root_DEL_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x, int n);
void zx_root_DEL_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x, int n);
void zx_root_DEL_EndpointReference(struct zx_root_s* x, int n);
void zx_root_DEL_Token(struct zx_root_s* x, int n);
void zx_root_DEL_Candidate(struct zx_root_s* x, int n);
void zx_root_DEL_sa11_Assertion(struct zx_root_s* x, int n);
void zx_root_DEL_Request(struct zx_root_s* x, int n);
void zx_root_DEL_sp11_Response(struct zx_root_s* x, int n);
void zx_root_DEL_ff12_Assertion(struct zx_root_s* x, int n);
void zx_root_DEL_ff12_AuthnRequest(struct zx_root_s* x, int n);
void zx_root_DEL_AuthnResponse(struct zx_root_s* x, int n);
void zx_root_DEL_AuthnRequestEnvelope(struct zx_root_s* x, int n);
void zx_root_DEL_AuthnResponseEnvelope(struct zx_root_s* x, int n);
void zx_root_DEL_RegisterNameIdentifierRequest(struct zx_root_s* x, int n);
void zx_root_DEL_RegisterNameIdentifierResponse(struct zx_root_s* x, int n);
void zx_root_DEL_FederationTerminationNotification(struct zx_root_s* x, int n);
void zx_root_DEL_ff12_LogoutRequest(struct zx_root_s* x, int n);
void zx_root_DEL_ff12_LogoutResponse(struct zx_root_s* x, int n);
void zx_root_DEL_NameIdentifierMappingRequest(struct zx_root_s* x, int n);
void zx_root_DEL_NameIdentifierMappingResponse(struct zx_root_s* x, int n);
void zx_root_DEL_m20_EntityDescriptor(struct zx_root_s* x, int n);
void zx_root_DEL_m20_EntitiesDescriptor(struct zx_root_s* x, int n);

void zx_root_REV_Assertion(struct zx_root_s* x);
void zx_root_REV_EncryptedAssertion(struct zx_root_s* x);
void zx_root_REV_NameID(struct zx_root_s* x);
void zx_root_REV_EncryptedID(struct zx_root_s* x);
void zx_root_REV_NewID(struct zx_root_s* x);
void zx_root_REV_AuthnRequest(struct zx_root_s* x);
void zx_root_REV_Response(struct zx_root_s* x);
void zx_root_REV_LogoutRequest(struct zx_root_s* x);
void zx_root_REV_LogoutResponse(struct zx_root_s* x);
void zx_root_REV_ManageNameIDRequest(struct zx_root_s* x);
void zx_root_REV_ManageNameIDResponse(struct zx_root_s* x);
void zx_root_REV_Envelope(struct zx_root_s* x);
void zx_root_REV_Header(struct zx_root_s* x);
void zx_root_REV_Body(struct zx_root_s* x);
void zx_root_REV_EntityDescriptor(struct zx_root_s* x);
void zx_root_REV_EntitiesDescriptor(struct zx_root_s* x);
void zx_root_REV_XACMLAuthzDecisionQuery(struct zx_root_s* x);
void zx_root_REV_XACMLPolicyQuery(struct zx_root_s* x);
void zx_root_REV_xaspcd1_XACMLAuthzDecisionQuery(struct zx_root_s* x);
void zx_root_REV_xaspcd1_XACMLPolicyQuery(struct zx_root_s* x);
void zx_root_REV_EndpointReference(struct zx_root_s* x);
void zx_root_REV_Token(struct zx_root_s* x);
void zx_root_REV_Candidate(struct zx_root_s* x);
void zx_root_REV_sa11_Assertion(struct zx_root_s* x);
void zx_root_REV_Request(struct zx_root_s* x);
void zx_root_REV_sp11_Response(struct zx_root_s* x);
void zx_root_REV_ff12_Assertion(struct zx_root_s* x);
void zx_root_REV_ff12_AuthnRequest(struct zx_root_s* x);
void zx_root_REV_AuthnResponse(struct zx_root_s* x);
void zx_root_REV_AuthnRequestEnvelope(struct zx_root_s* x);
void zx_root_REV_AuthnResponseEnvelope(struct zx_root_s* x);
void zx_root_REV_RegisterNameIdentifierRequest(struct zx_root_s* x);
void zx_root_REV_RegisterNameIdentifierResponse(struct zx_root_s* x);
void zx_root_REV_FederationTerminationNotification(struct zx_root_s* x);
void zx_root_REV_ff12_LogoutRequest(struct zx_root_s* x);
void zx_root_REV_ff12_LogoutResponse(struct zx_root_s* x);
void zx_root_REV_NameIdentifierMappingRequest(struct zx_root_s* x);
void zx_root_REV_NameIdentifierMappingResponse(struct zx_root_s* x);
void zx_root_REV_m20_EntityDescriptor(struct zx_root_s* x);
void zx_root_REV_m20_EntitiesDescriptor(struct zx_root_s* x);

#endif
int zx_LEN_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, int simplelen, struct zx_ns_s* ns);
char* zx_ENC_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, char* p, char* simpletag, int simplelen, struct zx_ns_s* ns);
struct zx_str* zx_EASY_ENC_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, char* simpletag, int simplelen, struct zx_ns_s* ns);
int zx_DEC_ATTR_simple_elem(struct zx_ctx* c, struct zx_elem_s* el);
int zx_DEC_ELEM_simple_elem(struct zx_ctx* c, struct zx_elem_s* el);
int zx_DEC_ATTR_wrong_elem(struct zx_ctx* c, struct zx_elem_s* el);
int zx_DEC_ELEM_wrong_elem(struct zx_ctx* c, struct zx_elem_s* el);
void zx_DUP_STRS_simple_elem(struct zx_ctx* c, struct zx_elem_s* x);
struct zx_elem_s* zx_DEEP_CLONE_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, int dup_strs);
int zx_WALK_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_str* node, void* ctx));
int zx_WALK_WO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_str* node, void* ctx));

#endif
