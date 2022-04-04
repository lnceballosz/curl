#ifndef HEADER_CURL_HTTP_NEGOTIATE_H
#define HEADER_CURL_HTTP_NEGOTIATE_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#if !defined(CURL_DISABLE_HTTP) && defined(USE_SPNEGO)

/* this is for Negotiate header input */
CURLcode Curl_input_negotiate(struct Curl_easy *data, struct connectdata *conn,
                              bool proxy, const char *header);

/* this is for creating Negotiate header output */
CURLcode Curl_output_negotiate(struct Curl_easy *data,
                               struct connectdata *conn, bool proxy);

void Curl_http_auth_cleanup_negotiate(struct connectdata *conn);

#else /* !CURL_DISABLE_HTTP && USE_SPNEGO */
#define Curl_http_auth_cleanup_negotiate(x)
#endif

#endif /* HEADER_CURL_HTTP_NEGOTIATE_H */
