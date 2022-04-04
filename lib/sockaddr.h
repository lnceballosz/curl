#ifndef HEADER_CURL_SOCKADDR_H
#define HEADER_CURL_SOCKADDR_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

struct Curl_sockaddr_storage {
  union {
    struct sockaddr sa;
    struct sockaddr_in sa_in;
#ifdef ENABLE_IPV6
    struct sockaddr_in6 sa_in6;
#endif
#ifdef HAVE_STRUCT_SOCKADDR_STORAGE
    struct sockaddr_storage sa_stor;
#else
    char cbuf[256];   /* this should be big enough to fit a lot */
#endif
  } buffer;
};

#endif /* HEADER_CURL_SOCKADDR_H */
