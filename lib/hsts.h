#ifndef HEADER_CURL_HSTS_H
#define HEADER_CURL_HSTS_H

// Copyright (C) 2020 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_HSTS)
#include <curl/curl.h>
#include "llist.h"

#ifdef DEBUGBUILD
extern time_t deltatime;
#endif

struct stsentry {
  struct Curl_llist_element node;
  const char *host;
  bool includeSubDomains;
  curl_off_t expires; /* the timestamp of this entry's expiry */
};

/* The HSTS cache. Needs to be able to tailmatch host names. */
struct hsts {
  struct Curl_llist list;
  char *filename;
  unsigned int flags;
};

struct hsts *Curl_hsts_init(void);
void Curl_hsts_cleanup(struct hsts **hp);
CURLcode Curl_hsts_parse(struct hsts *h, const char *hostname,
                         const char *sts);
struct stsentry *Curl_hsts(struct hsts *h, const char *hostname,
                           bool subdomain);
CURLcode Curl_hsts_save(struct Curl_easy *data, struct hsts *h,
                        const char *file);
CURLcode Curl_hsts_loadfile(struct Curl_easy *data,
                            struct hsts *h, const char *file);
CURLcode Curl_hsts_loadcb(struct Curl_easy *data,
                          struct hsts *h);
#else
#define Curl_hsts_cleanup(x)
#define Curl_hsts_loadcb(x,y) CURLE_OK
#define Curl_hsts_save(x,y,z)
#endif /* CURL_DISABLE_HTTP || CURL_DISABLE_HSTS */
#endif /* HEADER_CURL_HSTS_H */
