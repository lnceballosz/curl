#ifndef HEADER_CURL_AMIGAOS_H
#define HEADER_CURL_AMIGAOS_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(__AMIGA__) && defined(HAVE_BSDSOCKET_H) && !defined(USE_AMISSL)

bool Curl_amiga_init();
void Curl_amiga_cleanup();

#else

#define Curl_amiga_init() 1
#define Curl_amiga_cleanup() Curl_nop_stmt

#endif

#ifdef USE_AMISSL
#include <openssl/x509v3.h>
void Curl_amiga_X509_free(X509 *a);
#endif /* USE_AMISSL */

#endif /* HEADER_CURL_AMIGAOS_H */

