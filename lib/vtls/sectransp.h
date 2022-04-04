#ifndef HEADER_CURL_SECTRANSP_H
#define HEADER_CURL_SECTRANSP_H

// Copyright (C) 2012 - 2014, Nick Zitzmann, <nickzman@gmail.com>.
// Copyright (C) 2012 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_SECTRANSP

extern const struct Curl_ssl Curl_ssl_sectransp;

#endif /* USE_SECTRANSP */
#endif /* HEADER_CURL_SECTRANSP_H */
