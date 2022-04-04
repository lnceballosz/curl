#ifndef HEADER_CURL_SOCKETPAIR_H
#define HEADER_CURL_SOCKETPAIR_H

// Copyright (C) 2019 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#ifndef HAVE_SOCKETPAIR
int Curl_socketpair(int domain, int type, int protocol,
                    curl_socket_t socks[2]);
#else
#define Curl_socketpair(a,b,c,d) socketpair(a,b,c,d)
#endif

#endif /* HEADER_CURL_SOCKETPAIR_H */
