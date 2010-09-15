/* zxidpool.c  -  Attribute handling
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidpool.c,v 1.7 2009-11-24 23:53:40 sampo Exp $
 *
 * 4.9.2009, forked from zxidsimp.c --Sampo
 * 1.2.2010, added ses_to methods --Sampo
 * 21.5.2010, added local attribute authority and local EPRs feature --Sampo
 */

#include "platform.h"

#include <memory.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zx-sa-data.h"

/*(i) Convert attributes from (session) pool to LDIF entry, applying OUTMAP.
 * This is used by zxid_simple() SSO successful code to generate return
 * value, but can also be used later to regenerate the LDIF
 * given the pool. See zxid_ses_to_pool() for how to create the pool.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by: */
static struct zx_str* zxid_pool_to_ldif(zxid_conf* cf, struct zxid_attr* pool)
{
  char* p;
  char* name;
  char* idpnid = 0;
  char* affid = 0;
  int len = 0, name_len;
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  struct zx_str* ss;
  
  /* Length computation pass */

  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL) {
	D("attribute(%s) filtered out by del rule in OUTMAP", at->name);
	continue;
      }
      at->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, STRNULLCHK(at->val)));
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
	name_len = strlen(map->dst);
      } else {
	name_len = strlen(at->name);
      }
      len += name_len + sizeof(": \n")-1 + at->map_val->len;
      DD("len1=%d", len);

      for (av = at->nv; av; av = av->n) {
	av->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, STRNULLCHK(av->val)));
	len += name_len + sizeof(": \n")-1 + av->map_val->len;
	DD("len2=%d", len);
      }
    } else {
      name_len = strlen(at->name);
      len += name_len + sizeof(": \n")-1 + (at->val?strlen(at->val):0);
      DD("len3=%d name_len=%d name(%s)", len, name_len, at->name);
      for (av = at->nv; av; av = av->n) {
	len += name_len + sizeof(": \n")-1 + (av->val?strlen(av->val):0);
	DD("len4=%d", len);
      }
    }

    if (!strcmp(at->name, "idpnid")) idpnid = at->val;
    else if (!strcmp(at->name, "affid")) affid = at->val;
  }
  len += sizeof("dn: idpnid=,affid=\n")-1 + (idpnid?strlen(idpnid):0) + (affid?strlen(affid):0);
  DD("lenFin=%d", p-ss->s);
  
  /* Attribute rendering pass */

  ss = zx_new_len_str(cf->ctx, len);
  p = ss->s;

  memcpy(p, "dn: idpnid=", sizeof("dn: idpnid=")-1);
  p += sizeof("dn: idpnid=")-1;
  if (idpnid) {
    strcpy(p, idpnid);
    p += strlen(idpnid);
  }
  memcpy(p, ",affid=", sizeof(",affid=")-1);
  p += sizeof(",affid=")-1;
  if (affid) {
    strcpy(p, affid);
    p += strlen(affid);
  }
  *p++ = '\n';

  DD("len 0=%d", p-ss->s);

  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL)
	continue;
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
	name = map->dst;
      } else {
	name = at->name;
      }
      
      name_len = strlen(name);
      strcpy(p, name);
      p += name_len;
      *p++ = ':';
      *p++ = ' ';
      memcpy(p, at->map_val->s, at->map_val->len);
      p += at->map_val->len;
      *p++ = '\n';

      DD("len 1=%d", p-ss->s);
      
      for (av = at->nv; av; av = av->n) {
	strcpy(p, name);
	p += name_len;
	*p++ = ':';
	*p++ = ' ';
	memcpy(p, av->map_val->s, av->map_val->len);
	p += av->map_val->len;
	*p++ = '\n';

	DD("len 2=%d", p-ss->s);
      }


    } else {
      name_len = strlen(at->name);
      strcpy(p, at->name);
      p += name_len;
      *p++ = ':';
      *p++ = ' ';
      if (at->val) {
	strcpy(p, at->val);
	p += strlen(at->val);
      }
      *p++ = '\n';

      DD("len 3=%d name_len=%d name(%s)", p-ss->s, name_len, at->name);
      
      for (av = at->nv; av; av = av->n) {
	strcpy(p, at->name);
	p += name_len;
	*p++ = ':';
	*p++ = ' ';
	if (at->val) {
	  strcpy(p, av->val);
	  p += strlen(av->val);
	}
	*p++ = '\n';

	D("len 4=%d", p-ss->s);
      }

    }
  }
  DD("len Fin=%d", p-ss->s);

  ASSERTOP(p, ==, ss->s+len);
  return ss;
}

/*() Convert attributes from (session) pool to JSON, applying OUTMAP.
 * *** Need to check escaping JSON values, e.g. " or \n */

/* Called by:  zxid_ses_to_json */
static struct zx_str* zxid_pool_to_json(zxid_conf* cf, struct zxid_attr* pool)
{
  char* p;
  char* name;
  int len = sizeof("{")-1, name_len;
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  struct zx_str* ss;
  
  /* Length computation pass */

  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL) {
	D("attribute(%s) filtered out by del rule in OUTMAP", at->name);
	continue;
      }
      at->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, STRNULLCHK(at->val)));
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
	name_len = strlen(map->dst);
      } else {
	name_len = strlen(at->name);
      }

      if (at->nv) {  /* Multivalue requires array */
	len += name_len + sizeof("\"\":[\"\"],")-1 + at->map_val->len;
	for (av = at->nv; av; av = av->n) {
	  av->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, STRNULLCHK(av->val)));
	  len += name_len + sizeof(",\"\"")-1 + av->map_val->len;
	}
      } else {
	len += name_len + sizeof("\"\":\"\",")-1 + at->map_val->len;
      }
    } else {
      name_len = strlen(at->name);
      if (at->nv) {  /* Multivalue requires array */
	len += name_len + sizeof("\"\":[\"\"],")-1 + (at->val?strlen(at->val):0);
	for (av = at->nv; av; av = av->n)
	  len += name_len + sizeof(",\"\"")-1 + (av->val?strlen(av->val):0);
      } else {
	len += name_len + sizeof("\"\":\"\",")-1 + (at->val?strlen(at->val):0);
      }
    }
  }
  
  /* Attribute rendering pass */

  ss = zx_new_len_str(cf->ctx, len);
  p = ss->s;
  *p++ = '{';

  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL)
	continue;
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
	name = map->dst;
      } else {
	name = at->name;
      }

      *p++ = '"';
      strcpy(p, name);
      p += strlen(name);
      *p++ = '"';
      *p++ = ':';
      if (at->nv) {
	*p++ = '[';
	*p++ = '"';
	memcpy(p, at->map_val->s, at->map_val->len);
	p += at->map_val->len;
	*p++ = '"';
	for (av = at->nv; av; av = av->n) {
	  *p++ = ',';
	  *p++ = '"';
	  memcpy(p, av->map_val->s, av->map_val->len);
	  p += av->map_val->len;
	  *p++ = '"';
	}
	*p++ = ']';
      } else {
	*p++ = '"';
	memcpy(p, at->map_val->s, at->map_val->len);
	p += at->map_val->len;
	*p++ = '"';
      }

    } else {
      *p++ = '"';
      strcpy(p, at->name);
      p += strlen(at->name);
      *p++ = '"';
      *p++ = ':';
      if (at->nv) {
	*p++ = '[';
	*p++ = '"';
	if (at->val) {
	  strcpy(p, at->val);
	  p += strlen(at->val);
	}
	*p++ = '"';
	for (av = at->nv; av; av = av->n) {
	  *p++ = ',';
	  *p++ = '"';
	  if (at->val) {
	    strcpy(p, av->val);
	    p += strlen(av->val);
	  }
	  *p++ = '"';
	}
	*p++ = ']';
      } else {
	*p++ = '"';
	if (at->val) {
	  strcpy(p, at->val);
	  p += strlen(at->val);
	}
	*p++ = '"';
      }
    }
    *p++ = ',';
  }
  *p = '}';   /* Overwrites last comma */
  ASSERTOP(p, ==, ss->s+len);
  return ss;
}

/*() Convert attributes from (session) pool to query string, applying OUTMAP.
 * *** Need to check multivalue handling. Now all values are simply blurted
 *     out as separate name=value pairs.
 * *** Need to figure out how to distinguish query string return from
 *     other returns, like redirect. Perhaps arrange dn field always first? */

/* Called by:  zxid_ses_to_qs */
static struct zx_str* zxid_pool_to_qs(zxid_conf* cf, struct zxid_attr* pool)
{
  char* p;
  char* name;
  int len = sizeof("dn=QS1&")-1, name_len;
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  struct zx_str* ss;
  
  /* Length computation pass */

  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL) {
	D("attribute(%s) filtered out by del rule in OUTMAP", at->name);
	continue;
      }
      at->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, STRNULLCHK(at->val)));
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
	name_len = strlen(map->dst);
      } else {
	name_len = strlen(at->name);
      }
      len += name_len + sizeof("=&")-1 + zx_url_encode_len(at->map_val->len,at->map_val->s)-1;
      for (av = at->nv; av; av = av->n) {
	av->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, STRNULLCHK(av->val)));
	len += name_len + sizeof("=&")-1 + zx_url_encode_len(av->map_val->len,av->map_val->s)-1;
      }
      D("len=%d name_len=%d %s", len, name_len, at->name);
    } else {
      name_len = strlen(at->name);
      len += name_len + sizeof("=&")-1 + (at->val?zx_url_encode_len(strlen(at->val),at->val)-1:0);
      D("len=%d name_len=%d %s (nomap) url_enc_len=%d", len, name_len, at->name, (at->val?zx_url_encode_len(strlen(at->val),at->val)-1:0));
      for (av = at->nv; av; av = av->n)
	len += name_len + sizeof("=&")-1 + (av->val?zx_url_encode_len(strlen(av->val),av->val)-1:0);
    }
  }
  
  /* Attribute rendering pass */

  DD("HERE %d", 0);

  ss = zx_new_len_str(cf->ctx, len);
  p = ss->s;
  memcpy(p, "dn=QS1&", sizeof("dn=QS1&")-1);
  p += sizeof("dn=QS1&")-1;
  
  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL)
	continue;
      if (map->dst && map->src && map->src[0] != '*') {
	name = map->dst;
      } else {
	name = at->name;
      }
      
      name_len = strlen(name);
      strcpy(p, name);
      p += name_len;
      *p++ = '=';
      p = zx_url_encode_raw(at->map_val->len, at->map_val->s, p);
      *p++ = '&';
      
      for (av = at->nv; av; av = av->n) {
	strcpy(p, name);
	p += name_len;
	*p++ = '=';
	p = zx_url_encode_raw(av->map_val->len, av->map_val->s, p);
	*p++ = '&';
      }
    } else {
      name_len = strlen(at->name);
      strcpy(p, at->name);
      p += name_len;
      *p++ = '=';
      if (at->val)
	p = zx_url_encode_raw(strlen(at->val), at->val, p);
      *p++ = '&';
      
      for (av = at->nv; av; av = av->n) {
	strcpy(p, at->name);
	p += name_len;
	*p++ = '=';
	if (at->val)
	  p = zx_url_encode_raw(strlen(av->val), av->val, p);
	*p++ = '&';
      }
    }
  }
  D("p=%p == %p ss=%p len=%d", p, ss->s+len, ss->s, len);
  D("p(%.*s)", len, ss->s);
  ASSERTOP(p, ==, ss->s+len);
  *p = 0;  /* Zap last & */
  return ss;
}

/*() Convert attributes from session to LDIF, applying OUTMAP. */

/* Called by: */
struct zx_str* zxid_ses_to_ldif(zxid_conf* cf, zxid_ses* ses) {
  return zxid_pool_to_ldif(cf, ses?ses->at:0);
}

/*() Convert attributes from session to JSON, applying OUTMAP. */

/* Called by:  zxid_simple_ab_pep */
struct zx_str* zxid_ses_to_json(zxid_conf* cf, zxid_ses* ses) {
  return zxid_pool_to_json(cf, ses?ses->at:0);
}

/*() Convert attributes from session to query string, applying OUTMAP. */

/* Called by:  zxid_simple_ab_pep */
struct zx_str* zxid_ses_to_qs(zxid_conf* cf, zxid_ses* ses) {
  return zxid_pool_to_qs(cf, ses?ses->at:0);
}

/*() Add values, applying NEED, WANT, and INMAP */

/* Called by:  zxid_add_a7n_at_to_pool x2 */
static int zxid_add_at_values(zxid_conf* cf, zxid_ses* ses, struct zx_sa_Attribute_s* at, char* name, struct zx_str* issuer)
{
  struct zx_str* ss;
  struct zxid_map* map;
  struct zx_sa_AttributeValue_s* av;
  
  /* Attribute must be needed or wanted */

  if (!zxid_is_needed(cf->need, name) && !zxid_is_needed(cf->want, name)) {
    D("attribute(%s) neither needed nor wanted", name);
    return 0;
  }
  
  map = zxid_find_map(cf->inmap, name);
  if (map && map->rule == ZXID_MAP_RULE_DEL) {
    D("attribute(%s) filtered out by del rule in INMAP", name);
    return 0;
  }
  
  if (map && map->dst && map->src && map->src[0] != '*') {
    ses->at = zxid_new_at(cf, ses->at, strlen(map->dst), map->dst, 0, 0, "mapped");
  } else {
    ses->at = zxid_new_at(cf, ses->at, strlen(name), name, 0, 0, "as is");
  }
  ses->at->orig = at;
  ses->at->issuer = issuer;
  
  for (av = at->AttributeValue; av; av = (struct zx_sa_AttributeValue_s*)ZX_NEXT(av)) {
    D("Adding value: %p", av->gg.content);
    if (av->EndpointReference || av->ResourceOffering)
      continue;  /* Skip bootstraps. They are handled elsewhere, see zxid_snarf_eprs_from_ses(). */
    if (av->gg.content) {
      ss = zxid_map_val(cf, map, av->gg.content);
      if (ses->at->val) {
	D("map val(%.*s)", ss->len, ss->s);
	ses->at->nv = zxid_new_at(cf, ses->at->nv, 0, 0, ss->len, ss->s, "multival");
      } else {
	D("copy val(%.*s)", ss->len, ss->s);
	COPYVAL(ses->at->val, ss->s, ss->s+ss->len);
      }
    }
  }
  // *** check that value is not null, add empty string
  return 1;
}

/*() Add Attribute Statements of an Assertion to pool, applying NEED, WANT, and INMAP */

/* Called by:  zxid_ses_to_pool */
static void zxid_add_a7n_at_to_pool(zxid_conf* cf, zxid_ses* ses, zxid_a7n* a7n)
{
  struct zx_sa_Attribute_s* at;
  struct zx_sa_AttributeStatement_s* as;
  if (!a7n)
    return;
  
  for (as = a7n->AttributeStatement; as; as = (struct zx_sa_AttributeStatement_s*)ZX_NEXT(as)) {
    for (at = as->Attribute; at; at = (struct zx_sa_Attribute_s*)ZX_NEXT(at)) {      
      if (at->Name)
	zxid_add_at_values(cf, ses, at, zx_str_to_c(cf->ctx, at->Name), a7n->Issuer ? a7n->Issuer->gg.content : 0);
      if (at->FriendlyName)
	zxid_add_at_values(cf, ses, at, zx_str_to_c(cf->ctx, at->FriendlyName), a7n->Issuer ? a7n->Issuer->gg.content : 0);
    }
  }
}

/*() Add simple attribute to pool, applying NEED, WANT, and INMAP */

/* Called by:  zxid_add_ldif_attrs_to_ses, zxid_add_qs_to_ses, zxid_ses_to_pool x23 */
void zxid_add_attr_to_ses(zxid_conf* cf, zxid_ses* ses, char* at_name, struct zx_str* val)
{
  struct zxid_map* map;
  if (!val)
    val = zx_dup_str(cf->ctx, "-");

  if (zxid_is_needed(cf->need, at_name) || zxid_is_needed(cf->want, at_name)) {
    map = zxid_find_map(cf->inmap, at_name);
    if (map && map->rule == ZXID_MAP_RULE_DEL) {
      D("attribute(%s) filtered out by del rule in INMAP", at_name);
    } else {
      if (map && map->dst && map->src && map->src[0] != '*') {
	ses->at = zxid_new_at(cf, ses->at, strlen(map->dst), map->dst, val->len, val->s, "mapd2");
      } else {
	ses->at = zxid_new_at(cf, ses->at, strlen(at_name), at_name, val->len, val->s, "as is2");
      }
    }
  } else {
    D("attribute(%s) neither needed nor wanted", at_name);
  }
}

/*() Parse LDIF format and insert attributes to linked list. Return new head of the list.
 * *** illegal input causes corrupt pointer. For example query string input causes corruption. */

/* Called by:  zxid_ses_to_pool x3 */
static void zxid_add_ldif_attrs_to_ses(zxid_conf* cf, zxid_ses* ses, const char* prefix, char* p, char* lk)
{
  char* name;
  char* val;
  char* nbuf;
  char name_buf[ZXID_MAX_USER];
  int len;
  if (prefix) {
    strncpy(name_buf, prefix, sizeof(name_buf)-1);
    nbuf = name_buf + MIN(strlen(prefix), sizeof(name_buf)-1);
  } else
    nbuf = name_buf;  

  for (; p; ++p) {
    name = p;
    p = strstr(p, ": ");
    if (!p)
      break;
    len = MIN(p-name, sizeof(name_buf)-(nbuf-name_buf)-1);
    memcpy(nbuf, name, len);
    nbuf[len]=0;

    val = p+2;
    p = strchr(val, '\n');  /* *** parsing LDIF is fragile if values are multiline */
    len = p?(p-val):strlen(val);
    D("%s: ATTR(%s)=VAL(%.*s)", lk, name_buf, len, val);
    zxid_add_attr_to_ses(cf, ses, name_buf,  zx_dup_len_str(cf->ctx, len, val));
  }
}

/*() Copy user's local EPRs to his current session.
 * This function implements a feature where user can have at
 * some site some long term EPRs (with long term credential). When SSO
 * is made, these EPRs are copied to user's session's EPR
 * cache and thus made available. The persistent user EPRs could
 * be used to implement stuff like subscriptions.
 *
 * The ".all" user's EPRs provide a mechanism to add to all users of
 * a given SP some EPR. Naturally such EPR can not have per user
 * or short time credential. This can have security implications.
 *
 * cf:: Config object for cf->path, and for memory allocation
 * ses:: Session object. ses->sid is used to determine desitmation directory.
 * path:: Path to the user directory (in /var/zxid/user/<sha1_safe_base64(idpnid)>/)
 */

/* Called by:  zxid_ses_to_pool x3 */
static void zxid_copy_user_eprs_to_ses(zxid_conf* cf, zxid_ses* ses, struct zx_str* path)
{
  char bs_dir[ZXID_MAX_BUF];
  char ses_path[ZXID_MAX_BUF];
  DIR* dir;
  struct dirent * de;
  if (!ses->sid || !*ses->sid || !path)
    return;  /* No valid session. Nothing to do. */
  
  snprintf(bs_dir, sizeof(bs_dir), "%.*s/.bs", path->len, path->s);
  dir = opendir(bs_dir);
  if (!dir) {
    D("Local bootstrap dir(%s) does not exist", bs_dir);
    return;
  }
  while (de = readdir(dir)) {
    if (ONE_OF_2(de->d_name[0], '.', 0))   /* skip . and .. and .foo */
      continue;
    
    snprintf(bs_dir, sizeof(bs_dir), "%.*s/.bs/%s", path->len, path->s, de->d_name);
    snprintf(ses_path, sizeof(ses_path), "%.*s" ZXID_SES_DIR "%s/%s", path->len, path->s, ses->sid, de->d_name);
    copy_file(bs_dir, ses_path, "EPRS2ses", 1);
  }
  closedir(dir);
}

/*(i) Process attributes from the AttributeStatements of the session
 * SSO Assertion and insert them to the pool. NEED, WANT, and INMAP
 * are applied. The pool is suitable for use by PEP or eventually
 * rendering to LDIF (or JSON). This function also implements
 * local attribute authority. */

/* Called by:  zxid_as_call_ses, zxid_fetch_ses, zxid_simple_ab_pep, zxid_wsf_validate_a7n */
void zxid_ses_to_pool(zxid_conf* cf, zxid_ses* ses)
{
  char* src;
  char* dst;
  char* lim;
  int got;
  struct zx_str* issuer = 0;
  struct zx_str* affid;
  struct zx_str* nid;
  struct zx_str* tgtissuer = 0;
  struct zx_str* tgtaffid;
  struct zx_str* tgtnid;
  struct zx_str* accr;
  struct zx_str* path;
  struct zx_sa_Assertion_s* a7n;
  struct zx_sa_Assertion_s* tgta7n;
  char buf[ZXID_MAX_USER];
  char sha1_name[28];

  D_INDENT("ses_to_pool: ");
  zxid_get_ses_sso_a7n(cf, ses);
  a7n = ses->a7n;
  D("adding a7n %p to pool", a7n);
  zxid_add_a7n_at_to_pool(cf, ses, a7n);
  
  /* Format some pseudo attributes that describe the SSO */

  if (a7n)
    issuer = a7n->Issuer&&a7n->Issuer->gg.content?a7n->Issuer->gg.content:0;
  zxid_add_attr_to_ses(cf, ses, "issuer", issuer);
  zxid_add_attr_to_ses(cf, ses, "ssoa7npath",zx_dup_str(cf->ctx, STRNULLCHK(ses->sso_a7n_path)));
  
  affid = ses->nameid&&ses->nameid->NameQualifier?ses->nameid->NameQualifier:0;
  nid = ses->nameid&&ses->nameid->gg.content?ses->nameid->gg.content:0;
  zxid_add_attr_to_ses(cf, ses, "affid",  affid);
  zxid_add_attr_to_ses(cf, ses, "idpnid", nid);
  zxid_add_attr_to_ses(cf, ses, "nidfmt", zx_dup_str(cf->ctx, ses->nidfmt?"P":"T"));
  if (nid) {  
    zxid_user_sha1_name(cf, affid, nid, sha1_name);
    path = zx_strf(cf->ctx, "%s" ZXID_USER_DIR "%s", cf->path, sha1_name);
    zxid_add_attr_to_ses(cf, ses, "localpath",   path);
    got = read_all(sizeof(buf)-1, buf, "splocal_user_at", "%.*s/.bs/.at", path->len, path->s);
    if (got)
      zxid_add_ldif_attrs_to_ses(cf, ses, "local_", buf, "splocal_user_at");
    zxid_copy_user_eprs_to_ses(cf, ses, path);
  }

  /* Format pseudo attrs that describe the target, defaulting to the SSO identity. */
  
  if (ses->tgta7n)
    tgta7n = ses->tgta7n;
  else
    tgta7n = a7n;
  if (tgta7n)
    tgtissuer = tgta7n->Issuer&&tgta7n->Issuer->gg.content?tgta7n->Issuer->gg.content:0;
  if (tgtissuer)
    zxid_add_attr_to_ses(cf, ses, "tgtissuer", tgtissuer);
  zxid_add_attr_to_ses(cf, ses, "tgta7npath",zx_dup_str(cf->ctx, STRNULLCHK(ses->tgt_a7n_path)));

  tgtaffid = ses->tgtnameid&&ses->tgtnameid->NameQualifier?ses->tgtnameid->NameQualifier:0;
  tgtnid = ses->tgtnameid&&ses->tgtnameid->gg.content?ses->tgtnameid->gg.content:0;
  if (!tgtissuer) tgtissuer = issuer;  /* Default: requestor is the target */
  if (!tgtaffid)  tgtaffid = affid;
  if (!tgtnid)    tgtnid = nid;
  zxid_add_attr_to_ses(cf, ses, "tgtaffid",  tgtaffid);
  zxid_add_attr_to_ses(cf, ses, "tgtnid",    tgtnid);
  zxid_add_attr_to_ses(cf, ses, "tgtfmt",    zx_dup_str(cf->ctx, ses->tgtfmt?"P":"T"));
  if (tgtnid) {
    zxid_user_sha1_name(cf, tgtaffid, tgtnid, sha1_name);
    path = zx_strf(cf->ctx, "%s" ZXID_USER_DIR "%s", cf->path, sha1_name);
    zxid_add_attr_to_ses(cf, ses, "tgtpath",   path);
    got = read_all(sizeof(buf)-1, buf, "sptgt_user_at", "%.*s/.bs/.at", path->len, path->s);
    if (got)
      zxid_add_ldif_attrs_to_ses(cf, ses, "tgt_", buf, "sptgt_user_at");
    zxid_copy_user_eprs_to_ses(cf, ses, path);
  }
  
  accr = a7n&&a7n->AuthnStatement&&a7n->AuthnStatement->AuthnContext&&a7n->AuthnStatement->AuthnContext->AuthnContextClassRef&&a7n->AuthnStatement->AuthnContext->AuthnContextClassRef->content&&a7n->AuthnStatement->AuthnContext->AuthnContextClassRef->content?a7n->AuthnStatement->AuthnContext->AuthnContextClassRef->content:0;
  zxid_add_attr_to_ses(cf, ses, "authnctxlevel", accr);
  
  got = read_all(sizeof(buf)-1, buf, "splocal.all", "%s" ZXID_USER_DIR ".all/.bs/.at" , cf->path);
  if (got)
    zxid_add_ldif_attrs_to_ses(cf, ses, 0, buf, "splocal.all");
  path = zx_strf(cf->ctx, "%s" ZXID_USER_DIR ".all", cf->path);
  zxid_copy_user_eprs_to_ses(cf, ses, path);
  
  zxid_add_attr_to_ses(cf, ses, "eid",        zxid_my_entity_id(cf));
  zxid_add_attr_to_ses(cf, ses, "sigres",     zx_strf(cf->ctx, "%x", ses->sigres));
  zxid_add_attr_to_ses(cf, ses, "ssores",     zx_strf(cf->ctx, "%x", ses->ssores));
  if (ses->sid && *ses->sid) {
    zxid_add_attr_to_ses(cf, ses, "sesid",      zx_dup_str(cf->ctx, STRNULLCHK(ses->sid)));
    zxid_add_attr_to_ses(cf, ses, "sespath",    zx_strf(cf->ctx, "%s" ZXID_SES_DIR "%s", cf->path, STRNULLCHK(ses->sid)));
  }
  zxid_add_attr_to_ses(cf, ses, "sesix",      zx_dup_str(cf->ctx, STRNULLCHK(ses->sesix)));
  zxid_add_attr_to_ses(cf, ses, "setcookie",  zx_dup_str(cf->ctx, STRNULLCHK(ses->setcookie)));
  zxid_add_attr_to_ses(cf, ses, "cookie",     zx_dup_str(cf->ctx, STRNULLCHK(ses->cookie)));
  zxid_add_attr_to_ses(cf, ses, "msgid",      zx_dup_str(cf->ctx, STRNULLCHK(ses->wsp_msgid)));

  zxid_add_attr_to_ses(cf, ses, "rs",         zx_dup_str(cf->ctx, STRNULLCHK(ses->rs)));
  src = dst = ses->at->val;
  lim = ses->at->val + strlen(ses->at->val);
  URL_DECODE(dst, src, lim);
  *dst = 0;
  D("RelayState(%s)", ses->at->val);
  D_DEDENT("ses_to_pool: ");
}

/*(i) Add Attributes from Querty String to Session attribute pool
 * The qs argument is parsed according to the CGI Query String rules
 * and the attributes are added to the session. If apply_map is 1, the
 * INMAP configuration is applied. While this may seem a hassle, it
 * allows for specification of the values as safe_base64, etc. If values
 * are to be added verbatim, just specify 0 (all other values reserved).
 * The input argument qs gets modified in-situ due to URL decoding and
 * nul termination. Make sure to duplicate any string constant before calling.
 * Returns 1 on success, 0 on failure (return value often not checked). */

/* Called by:  zxid_az_cf_ses */
int zxid_add_qs_to_ses(zxid_conf* cf, zxid_ses* ses, char* qs, int apply_map)
{
  char *p, *n, *v, *val, *name;
  if (!qs || !ses)
    return 0;

  D("qs(%s) len=%d", qs, strlen(qs));
  while (*qs) {
    for (; *qs == '&'; ++qs) ;                  /* Skip over & or && */
    if (!*qs) break;
    
    for (name = qs; *qs && *qs != '='; ++qs) ;  /* Scan name (until '=') */
    DD("HERE %d", *qs);
    if (!*qs) break;
    if (qs == name) {                           /* Key was an empty string: skip it */
      for (; *qs && *qs != '&'; ++qs) ;         /* Scan value (until '&') *** or '?' */
      continue;
    }
    for (; name < qs && *name <= ' '; ++name) ; /* Skip over initial whitespace before name */
    n = p = name;
    URL_DECODE(p, name, qs);
    *p = 0;                                     /* Nul-term n (name) */
    
    for (val = ++qs; *qs && *qs != '&'; ++qs) ; /* Skip over = and scan value till '&' */
    v = p = val;
    URL_DECODE(p, val, qs);

    if (*qs)
      ++qs;
    *p = 0;                                     /* Nul-term v (value) */

    if (apply_map) {
      D("map %s=%s", n,v);
      zxid_add_attr_to_ses(cf, ses, n, zx_dup_str(cf->ctx, v));  
    } else {
      D("asis %s=%s", n,v);
      ses->at = zxid_new_at(cf, ses->at, v-n-1, n, p-v, v, "as is");
    }
  }
  return 1;
}

/*(i) Given session object (see zxid_simple_cf_ses() or zxid_fetch_ses()),
 * return n'th value (ix=0 is first) of given attribute, if any, from the
 * session common attribute pool. If apply_map is 0, the value is returned
 * as is. If it is 1 then OUTMAP is applied (the
 * attribute name is in the internal namespace). Other apply_map values
 * are reserved. */

/* Called by: */
struct zx_str* zxid_get_at(zxid_conf* cf, zxid_ses* ses, char* atname, int ix, int apply_map)
{
  struct zxid_attr* at;
  struct zxid_attr* av;
  if (!cf || !ses || !atname) {
    ERR("Missing args cf=%p ses=%p atname=%p", cf, ses, atname);
    return 0;
  }
  for (at = ses->at; at; at = at->n) {
    if (!strcmp(at->name, atname)) {
      for (av = at; av && ix; --ix, av = av->nv) ;
      if (av) {
	if (apply_map) {
	  return zx_dup_str(cf->ctx, at->val); /* *** */
	} else
	  return zx_dup_str(cf->ctx, at->val);
      }
    }
  }
  return 0;
}

/* EOF  --  zxidpool.c */
