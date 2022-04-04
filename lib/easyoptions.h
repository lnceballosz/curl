#ifndef HEADER_CURL_EASYOPTIONS_H
#define HEADER_CURL_EASYOPTIONS_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* should probably go into the public header */

#include <curl/curl.h>

/* generated table with all easy options */
extern struct curl_easyoption Curl_easyopts[];

#ifdef DEBUGBUILD
int Curl_easyopts_check(void);
#endif
#endif
