// Copyright (C) 2020 - 2021, Jacob Hoffman-Andrews,
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifndef HEADER_CURL_RUSTLS_H
#define HEADER_CURL_RUSTLS_H

#include "curl_setup.h"

#ifdef USE_RUSTLS

extern const struct Curl_ssl Curl_ssl_rustls;

#endif /* USE_RUSTLS */
#endif /* HEADER_CURL_RUSTLS_H */
