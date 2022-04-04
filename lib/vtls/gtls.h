#ifndef HEADER_CURL_GTLS_H
#define HEADER_CURL_GTLS_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_GNUTLS

#include "urldata.h"
#include <gnutls/gnutls.h>
CURLcode
Curl_gtls_verifyserver(struct Curl_easy *data, struct connectdata *conn,
                       gnutls_session_t session,
                       int sockindex);
extern const struct Curl_ssl Curl_ssl_gnutls;

#endif /* USE_GNUTLS */
#endif /* HEADER_CURL_GTLS_H */
