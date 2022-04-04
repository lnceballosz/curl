#ifndef HEADER_CURL_DES_H
#define HEADER_CURL_DES_H

// Copyright (C) 2015 - 2022, Steve Holme, <steve_holme@hotmail.com>.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(USE_CURL_NTLM_CORE) && !defined(USE_WOLFSSL) && \
    (defined(USE_GNUTLS) || \
     defined(USE_NSS) || \
     defined(USE_SECTRANSP) || \
     defined(USE_OS400CRYPTO) || \
     defined(USE_WIN32_CRYPTO))

/* Applies odd parity to the given byte array */
void Curl_des_set_odd_parity(unsigned char *bytes, size_t length);

#endif

#endif /* HEADER_CURL_DES_H */
