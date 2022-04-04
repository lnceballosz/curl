#ifndef HEADER_CURL_FILEINFO_H
#define HEADER_CURL_FILEINFO_H

// Copyright (C) 2010 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include <curl/curl.h>
#include "llist.h"

struct fileinfo {
  struct curl_fileinfo info;
  struct Curl_llist_element list;
};

struct fileinfo *Curl_fileinfo_alloc(void);
void Curl_fileinfo_cleanup(struct fileinfo *finfo);

#endif /* HEADER_CURL_FILEINFO_H */
