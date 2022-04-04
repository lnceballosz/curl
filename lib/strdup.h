#ifndef HEADER_CURL_STRDUP_H
#define HEADER_CURL_STRDUP_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifndef HAVE_STRDUP
extern char *curlx_strdup(const char *str);
#endif
#ifdef WIN32
wchar_t* Curl_wcsdup(const wchar_t* src);
#endif
void *Curl_memdup(const void *src, size_t buffer_length);
void *Curl_saferealloc(void *ptr, size_t size);

#endif /* HEADER_CURL_STRDUP_H */
