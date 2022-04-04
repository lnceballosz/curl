#ifndef HEADER_CURL_BASE64_H
#define HEADER_CURL_BASE64_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

CURLcode Curl_base64_encode(const char *inputbuff, size_t insize,
                            char **outptr, size_t *outlen);
CURLcode Curl_base64url_encode(const char *inputbuff, size_t insize,
                               char **outptr, size_t *outlen);
CURLcode Curl_base64_decode(const char *src,
                            unsigned char **outptr, size_t *outlen);

#endif /* HEADER_CURL_BASE64_H */
