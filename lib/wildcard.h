#ifndef HEADER_CURL_WILDCARD_H
#define HEADER_CURL_WILDCARD_H

// Copyright (C) 2010 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifndef CURL_DISABLE_FTP
#include "llist.h"

/* list of wildcard process states */
typedef enum {
  CURLWC_CLEAR = 0,
  CURLWC_INIT = 1,
  CURLWC_MATCHING, /* library is trying to get list of addresses for
                      downloading */
  CURLWC_DOWNLOADING,
  CURLWC_CLEAN, /* deallocate resources and reset settings */
  CURLWC_SKIP,  /* skip over concrete file */
  CURLWC_ERROR, /* error cases */
  CURLWC_DONE   /* if is wildcard->state == CURLWC_DONE wildcard loop
                   will end */
} wildcard_states;

typedef void (*wildcard_dtor)(void *ptr);

/* struct keeping information about wildcard download process */
struct WildcardData {
  wildcard_states state;
  char *path; /* path to the directory, where we trying wildcard-match */
  char *pattern; /* wildcard pattern */
  struct Curl_llist filelist; /* llist with struct Curl_fileinfo */
  void *protdata; /* pointer to protocol specific temporary data */
  wildcard_dtor dtor;
  void *customptr;  /* for CURLOPT_CHUNK_DATA pointer */
};

CURLcode Curl_wildcard_init(struct WildcardData *wc);
void Curl_wildcard_dtor(struct WildcardData *wc);

struct Curl_easy;

#else
/* FTP is disabled */
#define Curl_wildcard_dtor(x)
#endif

#endif /* HEADER_CURL_WILDCARD_H */
