#ifndef HEADER_CURL_URLAPI_INT_H
#define HEADER_CURL_URLAPI_INT_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

bool Curl_is_absolute_url(const char *url, char *scheme, size_t buflen);

#ifdef DEBUGBUILD
CURLUcode Curl_parse_port(struct Curl_URL *u, char *hostname, bool);
#endif

#endif /* HEADER_CURL_URLAPI_INT_H */
