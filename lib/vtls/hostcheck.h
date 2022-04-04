#ifndef HEADER_CURL_HOSTCHECK_H
#define HEADER_CURL_HOSTCHECK_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include <curl/curl.h>

/* returns TRUE if there's a match */
bool Curl_cert_hostcheck(const char *match_pattern, size_t matchlen,
                         const char *hostname, size_t hostlen);

#endif /* HEADER_CURL_HOSTCHECK_H */
