#ifndef HEADER_CURL_HTTP_NTLM_H
#define HEADER_CURL_HTTP_NTLM_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if !defined(CURL_DISABLE_HTTP) && defined(USE_NTLM)

/* this is for ntlm header input */
CURLcode Curl_input_ntlm(struct Curl_easy *data, bool proxy,
                         const char *header);

/* this is for creating ntlm header output */
CURLcode Curl_output_ntlm(struct Curl_easy *data, bool proxy);

void Curl_http_auth_cleanup_ntlm(struct connectdata *conn);

#else /* !CURL_DISABLE_HTTP && USE_NTLM */
#define Curl_http_auth_cleanup_ntlm(x)
#endif

#endif /* HEADER_CURL_HTTP_NTLM_H */
