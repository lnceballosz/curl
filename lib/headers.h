#ifndef HEADER_CURL_HEADER_H
#define HEADER_CURL_HEADER_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if !defined(CURL_DISABLE_HTTP) && defined(USE_HEADERS_API)

struct Curl_header_store {
  struct Curl_llist_element node;
  char *name; /* points into 'buffer' */
  char *value; /* points into 'buffer */
  int request; /* 0 is the first request, then 1.. 2.. */
  unsigned char type; /* CURLH_* defines */
  char buffer[1]; /* this is the raw header blob */
};

/*
 * Curl_headers_push() gets passed a full header to store.
 */
CURLcode Curl_headers_push(struct Curl_easy *data, const char *header,
                           unsigned char type);

/*
 * Curl_headers_cleanup(). Free all stored headers and associated memory.
 */
CURLcode Curl_headers_cleanup(struct Curl_easy *data);

#else
#define Curl_headers_push(x,y,z) CURLE_OK
#define Curl_headers_cleanup(x) Curl_nop_stmt
#endif

#endif /* HEADER_CURL_HEADER_H */
