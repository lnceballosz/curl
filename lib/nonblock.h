#ifndef HEADER_CURL_NONBLOCK_H
#define HEADER_CURL_NONBLOCK_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include <curl/curl.h> /* for curl_socket_t */

int curlx_nonblock(curl_socket_t sockfd,    /* operate on this */
                   int nonblock   /* TRUE or FALSE */);

#endif /* HEADER_CURL_NONBLOCK_H */
