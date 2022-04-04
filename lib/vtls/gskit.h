#ifndef HEADER_CURL_GSKIT_H
#define HEADER_CURL_GSKIT_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

/*
 * This header should only be needed to get included by vtls.c and gskit.c
 */

#include "urldata.h"

#ifdef USE_GSKIT

extern const struct Curl_ssl Curl_ssl_gskit;

#endif /* USE_GSKIT */

#endif /* HEADER_CURL_GSKIT_H */
