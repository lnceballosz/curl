#ifndef HEADER_CURL_TOOL_CB_REA_H
#define HEADER_CURL_TOOL_CB_REA_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

/*
** callback for CURLOPT_READFUNCTION
*/

size_t tool_read_cb(char *buffer, size_t sz, size_t nmemb, void *userdata);

/*
** callback for CURLOPT_XFERINFOFUNCTION used to unpause busy reads
*/

int tool_readbusy_cb(void *clientp,
                     curl_off_t dltotal, curl_off_t dlnow,
                     curl_off_t ultotal, curl_off_t ulnow);

#endif /* HEADER_CURL_TOOL_CB_REA_H */
