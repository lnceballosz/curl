#ifndef HEADER_CURL_GETINFO_H
#define HEADER_CURL_GETINFO_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

CURLcode Curl_getinfo(struct Curl_easy *data, CURLINFO info, ...);
CURLcode Curl_initinfo(struct Curl_easy *data);

#endif /* HEADER_CURL_GETINFO_H */
