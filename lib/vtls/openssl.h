#ifndef HEADER_CURL_SSLUSE_H
#define HEADER_CURL_SSLUSE_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_OPENSSL
/*
 * This header should only be needed to get included by vtls.c, openssl.c
 * and ngtcp2.c
 */

#include "urldata.h"

/*
 * In an effort to avoid using 'X509 *' here, we instead use the struct
 * x509_st version of the type so that we can forward-declare it here without
 * having to include <openssl/x509v3.h>. Including that header causes name
 * conflicts when libcurl is built with both Schannel and OpenSSL support.
 */
struct x509_st;
CURLcode Curl_ossl_verifyhost(struct Curl_easy *data, struct connectdata *conn,
                              struct x509_st *server_cert);
extern const struct Curl_ssl Curl_ssl_openssl;

struct ssl_ctx_st;
CURLcode Curl_ossl_set_client_cert(struct Curl_easy *data,
                                   struct ssl_ctx_st *ctx, char *cert_file,
                                   const struct curl_blob *cert_blob,
                                   const char *cert_type, char *key_file,
                                   const struct curl_blob *key_blob,
                                   const char *key_type, char *key_passwd);

#endif /* USE_OPENSSL */
#endif /* HEADER_CURL_SSLUSE_H */
