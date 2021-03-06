/* c/zx-ac-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
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
#include "c/zx-ac-data.h"
#define TPF zx_
#include "zx_ext_pt.h"



int zx_DEC_ATTR_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_ActivationLimitDuration_ELEM:
    if (!x->ActivationLimitDuration)
      x->ActivationLimitDuration = (struct zx_ac_ActivationLimitDuration_s*)el;
    return 1;
  case zx_ac_ActivationLimitUsages_ELEM:
    if (!x->ActivationLimitUsages)
      x->ActivationLimitUsages = (struct zx_ac_ActivationLimitUsages_s*)el;
    return 1;
  case zx_ac_ActivationLimitSession_ELEM:
    if (!x->ActivationLimitSession)
      x->ActivationLimitSession = el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_duration_ATTR:  x->duration = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_number_ATTR:  x->number = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Length_ELEM:
    if (!x->Length)
      x->Length = (struct zx_ac_Length_s*)el;
    return 1;
  case zx_ac_Alphabet_ELEM:
    if (!x->Alphabet)
      x->Alphabet = (struct zx_ac_Alphabet_s*)el;
    return 1;
  case zx_ac_Generation_ELEM:
    if (!x->Generation)
      x->Generation = (struct zx_ac_Generation_s*)el;
    return 1;
  case zx_ac_ActivationLimit_ELEM:
    if (!x->ActivationLimit)
      x->ActivationLimit = (struct zx_ac_ActivationLimit_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_case_ATTR:  x->case_is_c_keyword = x->gg.attr; return 1;
    case zx_excludedChars_ATTR:  x->excludedChars = x->gg.attr; return 1;
    case zx_requiredChars_ATTR:  x->requiredChars = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_ID_ATTR:  x->ID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_GoverningAgreements_ELEM:
    if (!x->GoverningAgreements)
      x->GoverningAgreements = (struct zx_ac_GoverningAgreements_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_ID_ATTR:  x->ID = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Identification_ELEM:
    if (!x->Identification)
      x->Identification = (struct zx_ac_Identification_s*)el;
    return 1;
  case zx_ac_TechnicalProtection_ELEM:
    if (!x->TechnicalProtection)
      x->TechnicalProtection = (struct zx_ac_TechnicalProtection_s*)el;
    return 1;
  case zx_ac_OperationalProtection_ELEM:
    if (!x->OperationalProtection)
      x->OperationalProtection = (struct zx_ac_OperationalProtection_s*)el;
    return 1;
  case zx_ac_AuthenticationMethod_ELEM:
    if (!x->AuthenticationMethod)
      x->AuthenticationMethod = (struct zx_ac_AuthenticationMethod_s*)el;
    return 1;
  case zx_ac_GoverningAgreements_ELEM:
    if (!x->GoverningAgreements)
      x->GoverningAgreements = (struct zx_ac_GoverningAgreements_s*)el;
    return 1;
  case zx_ac_AuthenticatingAuthority_ELEM:
    if (!x->AuthenticatingAuthority)
      x->AuthenticatingAuthority = (struct zx_ac_AuthenticatingAuthority_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_PrincipalAuthenticationMechanism_ELEM:
    if (!x->PrincipalAuthenticationMechanism)
      x->PrincipalAuthenticationMechanism = (struct zx_ac_PrincipalAuthenticationMechanism_s*)el;
    return 1;
  case zx_ac_Authenticator_ELEM:
    if (!x->Authenticator)
      x->Authenticator = (struct zx_ac_Authenticator_s*)el;
    return 1;
  case zx_ac_AuthenticatorTransportProtocol_ELEM:
    if (!x->AuthenticatorTransportProtocol)
      x->AuthenticatorTransportProtocol = (struct zx_ac_AuthenticatorTransportProtocol_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_PreviousSession_ELEM:
    if (!x->PreviousSession)
      x->PreviousSession = (struct zx_ac_PreviousSession_s*)el;
    return 1;
  case zx_ac_ResumeSession_ELEM:
    if (!x->ResumeSession)
      x->ResumeSession = (struct zx_ac_ResumeSession_s*)el;
    return 1;
  case zx_ac_DigSig_ELEM:
    if (!x->DigSig)
      x->DigSig = (struct zx_ac_DigSig_s*)el;
    return 1;
  case zx_ac_Password_ELEM:
    if (!x->Password)
      x->Password = (struct zx_ac_Password_s*)el;
    return 1;
  case zx_ac_ZeroKnowledge_ELEM:
    if (!x->ZeroKnowledge)
      x->ZeroKnowledge = (struct zx_ac_ZeroKnowledge_s*)el;
    return 1;
  case zx_ac_SharedSecretChallengeResponse_ELEM:
    if (!x->SharedSecretChallengeResponse)
      x->SharedSecretChallengeResponse = (struct zx_ac_SharedSecretChallengeResponse_s*)el;
    return 1;
  case zx_ac_SharedSecretDynamicPlaintext_ELEM:
    if (!x->SharedSecretDynamicPlaintext)
      x->SharedSecretDynamicPlaintext = (struct zx_ac_SharedSecretDynamicPlaintext_s*)el;
    return 1;
  case zx_ac_IPAddress_ELEM:
    if (!x->IPAddress)
      x->IPAddress = (struct zx_ac_IPAddress_s*)el;
    return 1;
  case zx_ac_AsymmetricDecryption_ELEM:
    if (!x->AsymmetricDecryption)
      x->AsymmetricDecryption = (struct zx_ac_AsymmetricDecryption_s*)el;
    return 1;
  case zx_ac_AsymmetricKeyAgreement_ELEM:
    if (!x->AsymmetricKeyAgreement)
      x->AsymmetricKeyAgreement = (struct zx_ac_AsymmetricKeyAgreement_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_HTTP_ELEM:
    if (!x->HTTP)
      x->HTTP = (struct zx_ac_HTTP_s*)el;
    return 1;
  case zx_ac_SSL_ELEM:
    if (!x->SSL)
      x->SSL = (struct zx_ac_SSL_s*)el;
    return 1;
  case zx_ac_MobileNetworkNoEncryption_ELEM:
    if (!x->MobileNetworkNoEncryption)
      x->MobileNetworkNoEncryption = (struct zx_ac_MobileNetworkNoEncryption_s*)el;
    return 1;
  case zx_ac_MobileNetworkRadioEncryption_ELEM:
    if (!x->MobileNetworkRadioEncryption)
      x->MobileNetworkRadioEncryption = (struct zx_ac_MobileNetworkRadioEncryption_s*)el;
    return 1;
  case zx_ac_MobileNetworkEndToEndEncryption_ELEM:
    if (!x->MobileNetworkEndToEndEncryption)
      x->MobileNetworkEndToEndEncryption = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)el;
    return 1;
  case zx_ac_WTLS_ELEM:
    if (!x->WTLS)
      x->WTLS = (struct zx_ac_WTLS_s*)el;
    return 1;
  case zx_ac_IPSec_ELEM:
    if (!x->IPSec)
      x->IPSec = (struct zx_ac_IPSec_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_mechanism_ATTR:  x->mechanism = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_governingAgreementRef_ATTR:  x->governingAgreementRef = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_GoverningAgreementRef_ELEM:
    if (!x->GoverningAgreementRef)
      x->GoverningAgreementRef = (struct zx_ac_GoverningAgreementRef_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_nym_ATTR:  x->nym = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_PhysicalVerification_ELEM:
    if (!x->PhysicalVerification)
      x->PhysicalVerification = (struct zx_ac_PhysicalVerification_s*)el;
    return 1;
  case zx_ac_WrittenConsent_ELEM:
    if (!x->WrittenConsent)
      x->WrittenConsent = (struct zx_ac_WrittenConsent_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_ActivationPin_ELEM:
    if (!x->ActivationPin)
      x->ActivationPin = (struct zx_ac_ActivationPin_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_sharing_ATTR:  x->sharing = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_medium_ATTR:  x->medium = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_max_ATTR:  x->max = x->gg.attr; return 1;
    case zx_min_ATTR:  x->min = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_SecurityAudit_ELEM:
    if (!x->SecurityAudit)
      x->SecurityAudit = (struct zx_ac_SecurityAudit_s*)el;
    return 1;
  case zx_ac_DeactivationCallCenter_ELEM:
    if (!x->DeactivationCallCenter)
      x->DeactivationCallCenter = (struct zx_ac_DeactivationCallCenter_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Length_ELEM:
    if (!x->Length)
      x->Length = (struct zx_ac_Length_s*)el;
    return 1;
  case zx_ac_Alphabet_ELEM:
    if (!x->Alphabet)
      x->Alphabet = (struct zx_ac_Alphabet_s*)el;
    return 1;
  case zx_ac_Generation_ELEM:
    if (!x->Generation)
      x->Generation = (struct zx_ac_Generation_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_credentialLevel_ATTR:  x->credentialLevel = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Password_ELEM:
    if (!x->Password)
      x->Password = (struct zx_ac_Password_s*)el;
    return 1;
  case zx_ac_Token_ELEM:
    if (!x->Token)
      x->Token = (struct zx_ac_Token_s*)el;
    return 1;
  case zx_ac_Smartcard_ELEM:
    if (!x->Smartcard)
      x->Smartcard = (struct zx_ac_Smartcard_s*)el;
    return 1;
  case zx_ac_ActivationPin_ELEM:
    if (!x->ActivationPin)
      x->ActivationPin = (struct zx_ac_ActivationPin_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_KeyActivation_ELEM:
    if (!x->KeyActivation)
      x->KeyActivation = (struct zx_ac_KeyActivation_s*)el;
    return 1;
  case zx_ac_KeyStorage_ELEM:
    if (!x->KeyStorage)
      x->KeyStorage = (struct zx_ac_KeyStorage_s*)el;
    return 1;
  case zx_ac_KeySharing_ELEM:
    if (!x->KeySharing)
      x->KeySharing = (struct zx_ac_KeySharing_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_KeyActivation_ELEM:
    if (!x->KeyActivation)
      x->KeyActivation = (struct zx_ac_KeyActivation_s*)el;
    return 1;
  case zx_ac_KeyStorage_ELEM:
    if (!x->KeyStorage)
      x->KeyStorage = (struct zx_ac_KeyStorage_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_SwitchAudit_ELEM:
    if (!x->SwitchAudit)
      x->SwitchAudit = (struct zx_ac_SwitchAudit_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_PrivateKeyProtection_ELEM:
    if (!x->PrivateKeyProtection)
      x->PrivateKeyProtection = (struct zx_ac_PrivateKeyProtection_s*)el;
    return 1;
  case zx_ac_SecretKeyProtection_ELEM:
    if (!x->SecretKeyProtection)
      x->SecretKeyProtection = (struct zx_ac_SecretKeyProtection_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x)
{
  switch (x->gg.attr->g.tok) {
    case zx_DeviceInHand_ATTR:  x->DeviceInHand = x->gg.attr; return 1;
    case zx_DeviceType_ATTR:  x->DeviceType = x->gg.attr; return 1;
    case zx_SeedLength_ATTR:  x->SeedLength = x->gg.attr; return 1;

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_TimeSyncToken_ELEM:
    if (!x->TimeSyncToken)
      x->TimeSyncToken = (struct zx_ac_TimeSyncToken_s*)el;
    return 1;
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}




int zx_DEC_ATTR_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x)
{
  switch (x->gg.attr->g.tok) {

  default: return 0;
  }
}

int zx_DEC_ELEM_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x)
{
  struct zx_elem_s* el = x->gg.kids;
  switch (el->g.tok) {
  case zx_ac_Extension_ELEM:
    if (!x->Extension)
      x->Extension = (struct zx_ac_Extension_s*)el;
    return 1;

  default: return 0;
  }
}


/* EOF -- c/zx-ac-dec.c */
