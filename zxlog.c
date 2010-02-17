/* zxlog.c  -  Liberty oriented logging facility with log signing and encryption
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxlog.c,v 1.32 2009-11-24 23:53:40 sampo Exp $
 *
 * 18.11.2006, created --Sampo
 * 10.10.2007, added ipport --Sampo
 * 7.10.2008,  added inline documentation --Sampo
 * 29.8.2009,  added hmac chaining field --Sampo
 *
 * See also: Logging chapter in README.zxid
 */

#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef USE_OPENSSL
#include <openssl/x509.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#endif

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"

#define ZXID_LOG_DIR "log/"
#define ZXLOG_TIME_FMT "%04d%02d%02d-%02d%02d%02d.%03ld"
#define ZXLOG_TIME_ARG(t,usec) t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, \
                               t.tm_hour, t.tm_min, t.tm_sec, usec/1000

/*() Allocate memory for logging purpose.
 * Generally memory allocation goes via zx_alloc() family of functions. However
 * dues to special requirements of cryptographically implemeted logging,
 * we maintain this special allocation function  (which backends to zx_alloc()).
 *
 * This function is considered internal. Do not use unless you know what you are doing. */

/* Called by:  zxlog_write_line x3 */
static char* zxlog_alloc_zbuf(struct zxid_conf* cf, int *zlen, char* zbuf, int len, char* sig, int nonce)
{
  char* p;
  p = ZX_ALLOC(cf->ctx, nonce + 2 + len + *zlen);
  if (nonce)
    zx_rand(p, nonce);
  p[nonce] = (len >> 8) & 0xff;
  p[nonce+1] = len & 0xff;
  if (len) {
    memcpy(p+nonce+2, sig, len);
    ZX_FREE(cf->ctx, sig);
  }
  memcpy(p+nonce+2+len, zbuf, *zlen);
  ZX_FREE(cf->ctx, zbuf);
  *zlen += nonce + 2 + len;
  return p;
}

/*() Write a line to a log, taking care of all formalities of locking and
* observing all special options for signing and encryption of the logs.
* Not usually called directly (but you can if you want to), this is the
* work horse behind zxlog().
*
* cf::  ZXID configuration object, used for memory allocation.
* c_path:: Path to the log file, as C string
* encflags:: Encryption flags. See LOG_ERR or LOG_ACT configuration options in zxidconf.h
* n:: length of log data
* logbuf:: The data that should be logged
*/

/* Called by:  test_mode x12 */
void zxlog_write_line(struct zxid_conf* cf, char* c_path, int encflags, int n, const char* logbuf)
{
  RSA* log_sign_pkey;
  struct rsa_st* rsa_pkey;
  struct aes_key_st aes_key;
  int len = 0, blen, zlen, um;
  char sigletter = 'P';
  char encletter = 'P';
  char* p;
  char* sig = 0;
  char* zbuf;
  char* b64;
  char sigbuf[28+4];   /* Space for "SP " and sha1 */
  char keybuf[16];
  char ivec[16];
  if (n == -2)
    n = strlen(logbuf);
  if (encflags & 0x70) {          /* Encrypt check */
    zbuf = zx_zlib_raw_deflate(cf->ctx, n-1, logbuf, &zlen);
    switch (encflags & 0x06) {     /* Sign check */
    case 0x02:      /* Sx plain sha1 */
      sigletter = 'S';
      sig = ZX_ALLOC(cf->ctx, 20);
      SHA1(zbuf, zlen, sig);
      len = 20;
      break;
    case 0x04:      /* Rx RSA-SHA1 signature */
      sigletter = 'R';
      LOCK(cf->mx, "logsign wrln");      
      if (!(log_sign_pkey = cf->log_sign_pkey))
	log_sign_pkey = cf->log_sign_pkey = zxid_read_private_key(cf, "logsign-nopw-cert.pem");
      UNLOCK(cf->mx, "logsign wrln");      
      if (!log_sign_pkey)
	break;
      len = zxsig_data_rsa_sha1(cf->ctx, zlen, zbuf, &sig, log_sign_pkey, "enc log line");
      break;
    case 0x06:      /* Dx DSA-SHA1 signature */
      ERR("DSA-SHA1 sig not implemented in encrypted mode. Use RSA-SHA1 or none. %x", encflags);
      break;
    case 0: break;  /* Px no signing */
    }
    
    switch (encflags & 0x70) {
    case 0x10:  /* xZ RFC1951 zip + safe base64 */
      encletter = 'Z';
      zbuf = zxlog_alloc_zbuf(cf, &zlen, zbuf, len, sig, 0);
      break;
    case 0x20:  /* xA RSA-AES */
      encletter = 'A';
      zbuf = zxlog_alloc_zbuf(cf, &zlen, zbuf, len, sig, 16);
      zx_rand(keybuf, 16);
      AES_set_encrypt_key(keybuf, 128, &aes_key);
      memcpy(ivec, zbuf, sizeof(ivec));
      AES_cbc_encrypt(zbuf+16, zbuf+16, zlen-16, &aes_key, ivec, 1);

      LOCK(cf->mx, "logenc wrln");
      if (!cf->log_enc_cert)
	cf->log_enc_cert = zxid_read_cert(cf, "logenc-nopw-cert.pem");
      rsa_pkey = zx_get_rsa_pub_from_cert(cf->log_enc_cert, "log_enc_cert");
      UNLOCK(cf->mx, "logenc wrln");
      if (!rsa_pkey)
	break;
      
      len = RSA_size(rsa_pkey);
      sig = ZX_ALLOC(cf->ctx, len);
      if (RSA_public_encrypt(16, keybuf, sig, rsa_pkey, RSA_PKCS1_OAEP_PADDING) < 0) {
	ERR("RSA enc fail %x", encflags);
	zx_report_openssl_error("zxlog rsa enc");
	return;
      }
      p = ZX_ALLOC(cf->ctx, 2 + len + zlen);
      p[0] = (len >> 8) & 0xff;
      p[1] = len & 0xff;
      memcpy(p+2, sig, len);
      memcpy(p+2+len, zbuf, zlen);
      ZX_FREE(cf->ctx, sig);
      ZX_FREE(cf->ctx, zbuf);
      zbuf = p;
      zlen += 2 + len;
      break;
    case 0x30:  /* xT RSA-3DES */
      encletter = 'T';
      ERR("Enc not implemented %x", encflags);
      break;
    case 0x40:  /* xB AES */
      encletter = 'B';
      zbuf = zxlog_alloc_zbuf(cf, &zlen, zbuf, len, sig, 16);
      if (!cf->log_symkey[0]) {
	char buf[1024];
	int gotall = read_all(sizeof(buf), buf, "symkey",
			      "%s" ZXID_PEM_DIR "logenc.key", cf->path);
	if (!gotall && cf->auto_cert) {
	  INFO("AUTO_CERT: generating symmetric encryption key for logging in %s" ZXID_PEM_DIR "logenc.key", cf->path);
	  gotall = 128 >> 3;
	  zx_rand(buf, gotall);
	  um = umask(0077);  /* Key material should be readable only by owner */
	  write_all_path_fmt("auto_cert", sizeof(buf), buf,
			     "%s" ZXID_PEM_DIR "logenc.key", cf->path, 0, "%.*s",
			     gotall, buf);
	  umask(um);
	}
	SHA1(buf, gotall, cf->log_symkey);
      }
      AES_set_encrypt_key(cf->log_symkey, 128, &aes_key);
      memcpy(ivec, zbuf, sizeof(ivec));
      AES_cbc_encrypt(zbuf+16, zbuf+16, zlen-16, &aes_key, ivec, 1);
      break;
    case 0x50:  /* xU 3DES */
      encletter = 'U';
      ERR("Enc not implemented %x", encflags);
      break;
    default:
      ERR("Enc not implemented %x", encflags);
      break;
    }

    blen = SIMPLE_BASE64_LEN(zlen) + 3 + 1;
    b64 = ZX_ALLOC(cf->ctx, blen);
    b64[0] = sigletter;
    b64[1] = encletter;
    b64[2] = ' ';
    p = base64_fancy_raw(zbuf, zlen, b64+3, safe_basis_64, 1<<31, 0, 0, '.');
    blen = p-b64 + 1;
    *p = '\n';
    write2_or_append_lock_c_path(c_path, 0, 0, blen, b64, "zxlog enc", SEEK_END, O_APPEND);
    return;
  }

  switch (encflags & 0x06) {
  case 0x02:   /* SP plain sha1 */
    strcpy(sigbuf, "SP ");
    sha1_safe_base64(sigbuf+3, n-1, logbuf);
    sigbuf[3+27] = ' ';
    len = 3+27+1;
    p = sigbuf;
    break;
  case 0x04:   /* RP RSA-SHA1 signature */
    LOCK(cf->mx, "logsign wrln");      
    if (!(log_sign_pkey = cf->log_sign_pkey))
      log_sign_pkey = cf->log_sign_pkey = zxid_read_private_key(cf, "logsign-nopw-cert.pem");
    UNLOCK(cf->mx, "logsign wrln");
    if (!log_sign_pkey)
      break;
    zlen = zxsig_data_rsa_sha1(cf->ctx, n-1, logbuf, &zbuf, log_sign_pkey, "log line");
    len = SIMPLE_BASE64_LEN(zlen) + 4;
    sig = ZX_ALLOC(cf->ctx, len);
    strcpy(sig, "RP ");
    p = base64_fancy_raw(zbuf, zlen, sig+3, safe_basis_64, 1<<31, 0, 0, '.');
    len = p-sig + 1;
    *p = ' ';
    p = sig;
    break;
  case 0x06:   /* DP DSA-SHA1 signature */
    ERR("DSA-SHA1 signature not implemented %x", encflags);
    break;
  case 0:      /* Plain logging, no signing, no encryption. */
    len = 5;
    p = "PP - ";
    break;
  }
  write2_or_append_lock_c_path(c_path, len, p, n, logbuf, "zxlog sig", SEEK_END, O_APPEND);
  if (sig)
    ZX_FREE(cf->ctx, sig);
}

/*(i) Log to activity and/or error log depending on ~res~ and configuration settings.
 * This is the main audit logging function you should call. Please see <<link:../../html/zxid-log.html: zxid-log.pd>>
 * for detailed description of the log format and features. See <<link:../../html/zxid-conf.html: zxid-conf.pd>> for
 * configuration options governing the logging. (*** check the links)
 *
 * Proper audit trail is essential for any high value transactions based on SSO. Also
 * some SAML protocol Processing Rules, such as duplicate detection, depend on the
 * logging.
 *
 * cf     (1)::  ZXID configuration object, used for configuration options and memory allocation
 * ourts  (2)::  Timestamp as observed by localhost. Typically the wall clock
 *     time. See gettimeofday(3)
 * srcts  (3)::  Timestamp claimed by the message to which the log entry pertains
 * ipport (4)::  IP address and port number from which the message appears to have originated
 * entid  (5)::  Entity ID to which the message pertains, usually the issuer. Null ok.
 * msgid  (6)::  Message ID, can be used for correlation to establish audit trail continuity
 *     from request to response. Null ok.
 * a7nid  (7)::  Assertion ID, if message contained assertion (outermost and first
 *     assertion if there are multiple relevant assertions). Null ok.
 * nid    (8)::  Name ID pertaining to the message
 * sigval (9)::  Signature validation letters
 * res   (10)::  Result letters
 * op    (11)::  Operation code for the message
 * arg   (12)::  Operation specific argument
 * fmt, ...  ::  Free format message conveying additional information
 * return:: 0 on success, nonzero on failure (often ignored as zxlog() is very
 *     robust and rarely fails - and when it does situation is so hopeless that
 *     you would not be able to report its failure anyway)
 */

/* Called by:  zxid_an_page_cf, zxid_anoint_sso_a7n, zxid_anoint_sso_resp, zxid_chk_sig, zxid_decode_redir_or_post x2, zxid_fed_mgmt_cf, zxid_get_ent_by_sha1_name, zxid_get_ent_ss, zxid_get_meta x2, zxid_idp_dispatch, zxid_idp_select_zxstr_cf_cgi, zxid_idp_soap_dispatch x2, zxid_idp_soap_parse, zxid_parse_conf_raw, zxid_parse_meta, zxid_saml_ok x2, zxid_simple_render_ses, zxid_simple_ses_active_cf, zxid_sp_anon_finalize, zxid_sp_deref_art x5, zxid_sp_dig_sso_a7n x2, zxid_sp_dispatch, zxid_sp_meta, zxid_sp_mni_redir, zxid_sp_mni_soap, zxid_sp_slo_redir, zxid_sp_slo_soap, zxid_sp_soap_dispatch x2, zxid_sp_soap_parse, zxid_sp_sso_finalize x2, zxid_start_sso_url x3 */
int zxlog(struct zxid_conf* cf,   /* 1 */
	  struct timeval* ourts,  /* 2 null allowed, will use current time */
	  struct timeval* srcts,  /* 3 null allowed, will use start of unix epoch + 501 usec */
	  const char* ipport,     /* 4 null allowed, -:- or cf->ipport if not given */
	  struct zx_str* entid,   /* 5 null allowed, - if not given */
	  struct zx_str* msgid,   /* 6 null allowed, - if not given */
	  struct zx_str* a7nid,   /* 7 null allowed, - if not given */
	  struct zx_str* nid,     /* 8 null allowed, - if not given */
	  const char* sigval,     /* 9 null allowed, - if not given */
	  const char* res,        /* 10 */
	  const char* op,         /* 11 */
	  const char* arg,        /* 12 null allowed, - if not given */
	  const char* fmt, ...)   /* 13 null allowed as format, ends the line w/o further ado */
{
  int n;
  char* p;
  char sha1_name[28];
  char logbuf[1024];
  char c_path[ZXID_MAX_BUF];
  struct tm ot;
  struct tm st;
  struct timeval ourtsdefault;
  struct timeval srctsdefault;
  va_list ap;
  
  /* Avoid computation if logging is hopeless. */
  
  if (!((cf->log_err_in_act || res[0] == 'K') && cf->log_act)
      && !(cf->log_err && res[0] != 'K')) {
    return 0;
  }
  
  /* Prepare values */

  if (!ourts) {
    ourts = &ourtsdefault;
    GETTIMEOFDAY(ourts, 0);
  }
  if (!srcts) {
    srcts = &srctsdefault;
    srctsdefault.tv_sec = 0;
    srctsdefault.tv_usec = 501000;
  }
  GMTIME_R(ourts->tv_sec, ot);
  GMTIME_R(srcts->tv_sec, st);
  
  if (entid && entid->len && entid->s) {
    sha1_safe_base64(sha1_name, entid->len, entid->s);
    sha1_name[27] = 0;
  } else {
    sha1_name[0] = '-';
    sha1_name[1] = 0;
  }
  
  if (!ipport) {
    ipport = cf->ipport;
    if (!ipport)
      ipport = "-:-";
  }
  
  /* Format */
  
  n = snprintf(logbuf, sizeof(logbuf)-3, ZXLOG_TIME_FMT " " ZXLOG_TIME_FMT
	       " %s %s"  /* ipport  sha1_name-of-ent */
	       " %.*s"
	       " %.*s"
	       " %.*s"
	       " %s %s %s %s %s ",
	       ZXLOG_TIME_ARG(ot, ourts->tv_usec), ZXLOG_TIME_ARG(st, srcts->tv_usec),
	       ipport, sha1_name,
	       msgid?msgid->len:1, msgid?msgid->s:"-",
	       a7nid?a7nid->len:1, a7nid?a7nid->s:"-",
	       nid?nid->len:1,     nid?nid->s:"-",
	       zx_instance, STRNULLCHKD(sigval), res, op, arg?arg:"-");
  if (n <= 0 || n >= sizeof(logbuf)-3) {
    if (n < 0) {
      perror("snprintf");
      D("Broken snprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", n);
    }
    D("Log buffer too short: %d chars needed", n);
    if (n <= 0)
      n = 0;
    else
      n = sizeof(logbuf)-3;
  } else { /* Space left: try printing the format string as well! */
    p = logbuf+n;
    if (fmt && fmt[0]) {
      va_start(ap, fmt);
      n = vsnprintf(p, sizeof(logbuf)-n-2, fmt?fmt:"-", ap);
      if (n <= 0 || n >= sizeof(logbuf)-(p-logbuf)-2) {
	if (n < 0) {
	  perror("vsnprintf");
	  D("Broken vsnprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", n);
	}
	D("Log buffer truncated during format print: %d chars needed", n);
	if (n <= 0)
	  n = p-logbuf;
	else
	  n = sizeof(logbuf)-(p-logbuf)-2;
      } else
	n += p-logbuf;
      va_end(ap);
    } else {
      logbuf[n++] = '-';
    }
  }
  logbuf[n++] = '\n';
  logbuf[n] = 0;
  /*logbuf[sizeof(logbuf)-1] = 0;*/
  
  /* Output stage */
  
  D("LOG(%.*s)", n-1, logbuf);
  if ((cf->log_err_in_act || res[0] == 'K') && cf->log_act) {
    name_from_path(c_path, sizeof(c_path), "%s" ZXID_LOG_DIR "act", cf->path);
    zxlog_write_line(cf, c_path, cf->log_act, n, logbuf);
  }
  if (cf->log_err && (cf->log_act_in_err || res[0] != 'K')) {  /* If enabled, everything goes to err */
    name_from_path(c_path, sizeof(c_path), "%s" ZXID_LOG_DIR "err", cf->path);
    zxlog_write_line(cf, c_path, cf->log_err, n, logbuf);
  }
  return 0;
}

/*() Compute path for logging. Optionally attempt to create the necessary
 * directories if they are missing (you should do `make dirs' rather than
 * depend on this).
 *
 * cf::     ZXID configuration object uded for deternining root if the logging
 *     hierarchy, see PATH configuration option. Also used for memory allocation.
 * entid::  Issuer or target entity ID. For wire messages the URL.
 * objid::  AssertionID or MessageID. For wire messages the payload.
 * dir::    Directory prefix indicating branch of audit trail ("rely/" or "issue/")
 * kind::   Kind of object, used as path component ("/a7n/" or "/msg/")
 * create_dirs::  Flag: should creating directories be attempted. Usually 1 if intent
 *     is to write a file to the computed path. Usually 0 if the intent is to read.
 * return:: The path, as zx_str or 0 if failure */

/* Called by:  zxid_anoint_a7n, zxid_anoint_sso_resp, zxid_decode_redir_or_post x2, zxid_saml2_post_enc, zxid_saml2_redir_enc, zxid_sp_sso_finalize */
struct zx_str* zxlog_path(struct zxid_conf* cf,
			  struct zx_str* entid,  /* issuer or target entity ID */
			  struct zx_str* objid,  /* AssertionID or MessageID */
			  const char* dir,       /* rely/ or issue/ */
			  const char* kind,      /* /a7n/ or /msg/ */
			  int create_dirs)
{
  struct stat st;
  int dir_len = strlen(dir);
  int kind_len = strlen(kind);
  int len = cf->path_len + sizeof("log/")-1 + dir_len + 27 + kind_len + 27;
  char* s = ZX_ALLOC(cf->ctx, len+1);
  char* p;

  if (!entid) {
    ERR("No EntityID supplied %d", 0);
    ZX_FREE(cf->ctx, s);
    return 0;
  }

  memcpy(s, cf->path, cf->path_len);
  p = s + cf->path_len;
  memcpy(p, "log/", sizeof("log/"));
  p += sizeof("log/")-1;
  if (stat(s, &st)) {
    ERR("zxid log directory missing path(%s): giving up (%d %s)", s, errno, STRERROR(errno));
    ZX_FREE(cf->ctx, s);
    return 0;
  }
  
  memcpy(p, dir, dir_len+1);
  p += dir_len;
  if (stat(s, &st)) {
    if (create_dirs) {
      if (MKDIR(s, 0777)) {
	ERR("mkdir path(%s) failed: %d %s", s, errno, STRERROR(errno));
	ZX_FREE(cf->ctx, s);
	return 0;	
      }
    } else {
      ERR("directory missing path(%s) and no create_dirs (%d %s)", s, errno, STRERROR(errno));
      ZX_FREE(cf->ctx, s);
      return 0;
    }
  }
  
  sha1_safe_base64(p, entid->len, entid->s);
  p[27] = 0;
  p+=27;
  if (stat(s, &st)) {
    if (create_dirs) {
      if (MKDIR(s, 0777)) {
	ERR("mkdir path(%s) failed: %d %s", s, errno, STRERROR(errno));
	ZX_FREE(cf->ctx, s);
	return 0;	
      }
    } else {
      ERR("directory missing path(%s) and no create_dirs (%d %s)", s, errno, STRERROR(errno));
      ZX_FREE(cf->ctx, s);
      return 0;
    }
  }
  
  memcpy(p, kind, kind_len+1);
  p += kind_len;
  if (stat(s, &st)) {
    if (create_dirs) {
      if (MKDIR(s, 0777)) {
	ERR("mkdir path(%s) failed: %d %s", s, errno, STRERROR(errno));
	ZX_FREE(cf->ctx, s);
	return 0;	
      }
    } else {
      ERR("zxid directory missing path(%s) and no create_dirs (%d %s)", s, errno, STRERROR(errno));
      ZX_FREE(cf->ctx, s);
      return 0;
    }
  }
  
  sha1_safe_base64(p, objid->len, objid->s);
  p[27] = 0;
  p+=27;
  return zx_ref_len_str(cf->ctx, len, s);
}

/*() Check if file by path already exist.
 * Since each uniquely ID'd object has unique path, mere existence of a file
 * serves as duplicate ID check. This is used to satisfy some SAML processing rule
 * requirements such as duplicate ID check for assertions.
 *
 * cf::      ZXID configuration object, used for memory allocation
 * path::    Path where file is to be written, usually from zxlog_path()
 * logkey::  String that will help to identify reason of failure
 * return::  0 if no duplicate (success), 1 if duplicate (failure)
 */

/* Called by:  zxid_anoint_a7n, zxid_anoint_sso_resp, zxid_decode_redir_or_post x2, zxid_saml2_post_enc, zxid_saml2_redir_enc, zxid_sp_sso_finalize */
int zxlog_dup_check(struct zxid_conf* cf, struct zx_str* path, const char* logkey)
{
  struct stat st;
  /* We need a c path, but get zx_str. However, the zx_str will come from zxlog_path()
   * so we should be having the nul termination as needed. Just checking. */
  ASSERTOP(path->s[path->len], ==, 0);
  if (!stat(path->s, &st)) {
    ERR("Duplicate %s path(%.*s)", logkey, path->len, path->s);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "EDUP", path->s, "%s", logkey);
    return 1;
  }
  return 0;
}

/*() Write a blob of content to log file according to logflag (see zxidconf.h). If
 * the file already exists, i.e. there is a duplicate, the data is simply appended.
 * When logging objects such as assertions, the duplicate check should be done
 * as preprocessing step, see example below.
 *
 * cf::      ZXID configuration object, used for memory allocation
 * logflag:: 0 if logging should not happen, 1 for normal logging, other values reserved
 * path::    Path where file is to be written, usually from zxlog_path()
 * blob::    The data to be logged.
 * lk::      Log key. Indicates which part of the program invoked the logging function.
 * return::  0 if no log written (failure or logflag false), 1 if log written. Often ignored.
 *
 * *Example*
 *
 *   logpath = zxlog_path(cf, issuer, a7n->ID, "rely/", "/a7n/", 1);
 *   if (logpath) {
 *     if (zxlog_dup_check(cf, logpath, "SSO assertion")) {
 *       zxlog_blob(cf, cf->log_rely_a7n, logpath, zx_EASY_ENC_WO_sa_Assertion(cf->ctx, a7n), "E");
 *       goto erro;
 *     }
 *     zxlog_blob(cf, cf->log_rely_a7n, logpath, zx_EASY_ENC_WO_sa_Assertion(cf->ctx, a7n), "OK");
 *   }
 *
 * In the above example we determine the logpath and check for the duplicate and then log even
 * if duplicate. The logic of this is that in case of duplicate, the audit trail
 * captures both the original and the duplicate assertion (the logging is an append),
 * which may have forensic value. */

/* Called by:  zxid_anoint_a7n x2, zxid_anoint_sso_resp x2, zxid_decode_redir_or_post x2, zxid_saml2_post_enc x2, zxid_saml2_redir_enc x2, zxid_sp_sso_finalize x2 */
int zxlog_blob(struct zxid_conf* cf, int logflag, struct zx_str* path, struct zx_str* blob, const char* lk)
{
  if (!logflag || !blob)
    return 0;
  if (logflag != 1) {
    ERR("Unimplemented blob logging format: %x", logflag);
    return 0;
  }
  
  /* We need a c path, but get zx_str. However, the zx_str will come from zxlog_path()
   * so we should be having the nul termination as needed. Just checking. */
  D("lk(%s): LOGBLOB15(%.*s) len=%d path(%.*s)", lk, MIN(blob->len,15), blob->s, blob->len, path->len, path->s);
  DD("lk(%s): LOGBLOB(%.*s)", lk, blob->len, blob->s);
  ASSERTOP(path->s[path->len], ==, 0);
  if (!write2_or_append_lock_c_path(path->s, blob->len, blob->s, 0, 0, "zxlog blob", SEEK_END,O_APPEND)) {
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "S", "EFILE", 0, "Could not write blob. Permissions?");
  }
  return 1;
}

/* EOF  --  zxlog.c */
