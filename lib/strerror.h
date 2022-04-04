#ifndef HEADER_CURL_STRERROR_H
#define HEADER_CURL_STRERROR_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "urldata.h"

#define STRERROR_LEN 256 /* a suitable length */

const char *Curl_strerror(int err, char *buf, size_t buflen);
#if defined(WIN32) || defined(_WIN32_WCE)
const char *Curl_winapi_strerror(DWORD err, char *buf, size_t buflen);
#endif
#ifdef USE_WINDOWS_SSPI
const char *Curl_sspi_strerror(int err, char *buf, size_t buflen);
#endif

#endif /* HEADER_CURL_STRERROR_H */
