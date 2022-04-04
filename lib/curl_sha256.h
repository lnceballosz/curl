#ifndef HEADER_CURL_SHA256_H
#define HEADER_CURL_SHA256_H

// Copyright (C) 2017, Florin Petriuc, <petriuc.florin@gmail.com>
// Copyright (C) 2018 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifndef CURL_DISABLE_CRYPTO_AUTH
#include "curl_hmac.h"

extern const struct HMAC_params Curl_HMAC_SHA256[1];

#ifdef USE_WOLFSSL
/* SHA256_DIGEST_LENGTH is an enum value in wolfSSL. Need to import it from
 * sha.h*/
#include <wolfssl/options.h>
#include <wolfssl/openssl/sha.h>
#else
#define SHA256_DIGEST_LENGTH 32
#endif

CURLcode Curl_sha256it(unsigned char *outbuffer, const unsigned char *input,
                       const size_t len);

#endif

#endif /* HEADER_CURL_SHA256_H */
