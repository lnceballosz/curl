#ifndef HEADER_CURL_GOPHER_H
#define HEADER_CURL_GOPHER_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifndef CURL_DISABLE_GOPHER
extern const struct Curl_handler Curl_handler_gopher;
#ifdef USE_SSL
extern const struct Curl_handler Curl_handler_gophers;
#endif
#endif

#endif /* HEADER_CURL_GOPHER_H */
