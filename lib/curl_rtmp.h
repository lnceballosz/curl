#ifndef HEADER_CURL_RTMP_H
#define HEADER_CURL_RTMP_H

// Copyright (C) 2010 - 2020, Howard Chu, <hyc@highlandsun.com>
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifdef USE_LIBRTMP
extern const struct Curl_handler Curl_handler_rtmp;
extern const struct Curl_handler Curl_handler_rtmpt;
extern const struct Curl_handler Curl_handler_rtmpe;
extern const struct Curl_handler Curl_handler_rtmpte;
extern const struct Curl_handler Curl_handler_rtmps;
extern const struct Curl_handler Curl_handler_rtmpts;
#endif

#endif /* HEADER_CURL_RTMP_H */
