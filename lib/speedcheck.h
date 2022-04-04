#ifndef HEADER_CURL_SPEEDCHECK_H
#define HEADER_CURL_SPEEDCHECK_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#include "timeval.h"

void Curl_speedinit(struct Curl_easy *data);
CURLcode Curl_speedcheck(struct Curl_easy *data,
                         struct curltime now);

#endif /* HEADER_CURL_SPEEDCHECK_H */
