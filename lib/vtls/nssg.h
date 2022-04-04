#ifndef HEADER_CURL_NSSG_H
#define HEADER_CURL_NSSG_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_NSS
/*
 * This header should only be needed to get included by vtls.c and nss.c
 */

#include "urldata.h"

/* initialize NSS library if not already */
CURLcode Curl_nss_force_init(struct Curl_easy *data);

extern const struct Curl_ssl Curl_ssl_nss;

#endif /* USE_NSS */
#endif /* HEADER_CURL_NSSG_H */
