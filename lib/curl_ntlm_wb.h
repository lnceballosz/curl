#ifndef HEADER_CURL_NTLM_WB_H
#define HEADER_CURL_NTLM_WB_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if !defined(CURL_DISABLE_HTTP) && defined(USE_NTLM) && \
    defined(NTLM_WB_ENABLED)

/* this is for ntlm header input */
CURLcode Curl_input_ntlm_wb(struct Curl_easy *data,
                            struct connectdata *conn, bool proxy,
                            const char *header);

/* this is for creating ntlm header output */
CURLcode Curl_output_ntlm_wb(struct Curl_easy *data, struct connectdata *conn,
                             bool proxy);

void Curl_http_auth_cleanup_ntlm_wb(struct connectdata *conn);

#endif /* !CURL_DISABLE_HTTP && USE_NTLM && NTLM_WB_ENABLED */

#endif /* HEADER_CURL_NTLM_WB_H */
