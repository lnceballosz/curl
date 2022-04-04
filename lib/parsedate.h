#ifndef HEADER_CURL_PARSEDATE_H
#define HEADER_CURL_PARSEDATE_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

extern const char * const Curl_wkday[7];
extern const char * const Curl_month[12];

CURLcode Curl_gmtime(time_t intime, struct tm *store);

/* Curl_getdate_capped() differs from curl_getdate() in that this will return
   TIME_T_MAX in case the parsed time value was too big, instead of an
   error. */

time_t Curl_getdate_capped(const char *p);

#endif /* HEADER_CURL_PARSEDATE_H */
