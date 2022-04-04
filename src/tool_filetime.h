#ifndef HEADER_CURL_TOOL_FILETIME_H
#define HEADER_CURL_TOOL_FILETIME_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

struct GlobalConfig;

curl_off_t getfiletime(const char *filename, struct GlobalConfig *global);

#if defined(HAVE_UTIME) || defined(HAVE_UTIMES) ||      \
  (defined(WIN32) && (SIZEOF_CURL_OFF_T >= 8))
void setfiletime(curl_off_t filetime, const char *filename,
                 struct GlobalConfig *global);
#else
#define setfiletime(a,b,c) Curl_nop_stmt
#endif /* defined(HAVE_UTIME) || defined(HAVE_UTIMES) ||        \
          (defined(WIN32) && (SIZEOF_CURL_OFF_T >= 8)) */

#endif /* HEADER_CURL_TOOL_FILETIME_H */
