#ifndef HEADER_CURL_INET_PTON_H
#define HEADER_CURL_INET_PTON_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

int Curl_inet_pton(int, const char *, void *);

#ifdef HAVE_INET_PTON
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#elif defined(HAVE_WS2TCPIP_H)
/* inet_pton() exists in Vista or later */
#include <ws2tcpip.h>
#endif
#define Curl_inet_pton(x,y,z) inet_pton(x,y,z)
#endif

#endif /* HEADER_CURL_INET_PTON_H */
