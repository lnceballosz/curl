#ifndef HEADER_CURL_SETOPT_H
#define HEADER_CURL_SETOPT_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

CURLcode Curl_setstropt(char **charp, const char *s);
CURLcode Curl_setblobopt(struct curl_blob **blobp,
                         const struct curl_blob *blob);
CURLcode Curl_vsetopt(struct Curl_easy *data, CURLoption option, va_list arg);

#endif /* HEADER_CURL_SETOPT_H */
