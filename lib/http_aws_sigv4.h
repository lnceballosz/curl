#ifndef HEADER_CURL_HTTP_AWS_SIGV4_H
#define HEADER_CURL_HTTP_AWS_SIGV4_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

/* this is for creating aws_sigv4 header output */
CURLcode Curl_output_aws_sigv4(struct Curl_easy *data, bool proxy);

#endif /* HEADER_CURL_HTTP_AWS_SIGV4_H */
