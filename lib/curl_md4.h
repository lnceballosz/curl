#ifndef HEADER_CURL_MD4_H
#define HEADER_CURL_MD4_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if !defined(CURL_DISABLE_CRYPTO_AUTH)

#define MD4_DIGEST_LENGTH 16

void Curl_md4it(unsigned char *output, const unsigned char *input,
                const size_t len);

#endif /* !defined(CURL_DISABLE_CRYPTO_AUTH) */

#endif /* HEADER_CURL_MD4_H */
