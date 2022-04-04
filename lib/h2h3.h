#ifndef HEADER_CURL_H2H3_H
#define HEADER_CURL_H2H3_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#define H2H3_PSEUDO_METHOD ":method"
#define H2H3_PSEUDO_SCHEME ":scheme"
#define H2H3_PSEUDO_AUTHORITY ":authority"
#define H2H3_PSEUDO_PATH ":path"
#define H2H3_PSEUDO_STATUS ":status"

struct h2h3pseudo {
  const char *name;
  size_t namelen;
  const char *value;
  size_t valuelen;
};

struct h2h3req {
  size_t entries;
  struct h2h3pseudo header[1]; /* the array is allocated to contain entries */
};

/*
 * Curl_pseudo_headers() creates the array with pseudo headers to be
 * used in a HTTP/2 or HTTP/3 request. Returns an allocated struct.
 * Free it with Curl_pseudo_free().
 */
CURLcode Curl_pseudo_headers(struct Curl_easy *data,
                             const char *request,
                             const size_t len,
                             struct h2h3req **hp);

/*
 * Curl_pseudo_free() frees a h2h3req struct.
 */
void Curl_pseudo_free(struct h2h3req *hp);

#endif /* HEADER_CURL_H2H3_H */
