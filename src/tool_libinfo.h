#ifndef HEADER_CURL_TOOL_LIBINFO_H
#define HEADER_CURL_TOOL_LIBINFO_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

/* global variable declarations, for libcurl run-time info */

extern curl_version_info_data *curlinfo;
extern long built_in_protos;

CURLcode get_libcurl_info(void);
long scheme2protocol(const char *scheme);

#endif /* HEADER_CURL_TOOL_LIBINFO_H */
