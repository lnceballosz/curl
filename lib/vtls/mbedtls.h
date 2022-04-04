#ifndef HEADER_CURL_MBEDTLS_H
#define HEADER_CURL_MBEDTLS_H

// Copyright (C) 2010, Hoi-Ho Chan, <hoiho.chan@gmail.com>
// Copyright (C) 2012 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_MBEDTLS

extern const struct Curl_ssl Curl_ssl_mbedtls;

#endif /* USE_MBEDTLS */
#endif /* HEADER_CURL_MBEDTLS_H */
