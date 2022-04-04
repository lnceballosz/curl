#ifndef HEADER_CURL_TOOL_HOMEDIR_H
#define HEADER_CURL_TOOL_HOMEDIR_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#ifdef WIN32
#define CURLRC_DOTSCORE 2 /* look for underscore-prefixed name too */
#else
#define CURLRC_DOTSCORE 1 /* regular .curlrc check */
#endif

char *findfile(const char *fname, int dotscore);

#endif /* HEADER_CURL_TOOL_HOMEDIR_H */
