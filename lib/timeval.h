#ifndef HEADER_CURL_TIMEVAL_H
#define HEADER_CURL_TIMEVAL_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

/* Use a larger type even for 32 bit time_t systems so that we can keep
   microsecond accuracy in it */
typedef curl_off_t timediff_t;
#define CURL_FORMAT_TIMEDIFF_T CURL_FORMAT_CURL_OFF_T

#define TIMEDIFF_T_MAX CURL_OFF_T_MAX
#define TIMEDIFF_T_MIN CURL_OFF_T_MIN

struct curltime {
  time_t tv_sec; /* seconds */
  int tv_usec;   /* microseconds */
};

struct curltime Curl_now(void);

/*
 * Make sure that the first argument (t1) is the more recent time and t2 is
 * the older time, as otherwise you get a weird negative time-diff back...
 *
 * Returns: the time difference in number of milliseconds.
 */
timediff_t Curl_timediff(struct curltime t1, struct curltime t2);

/*
 * Make sure that the first argument (t1) is the more recent time and t2 is
 * the older time, as otherwise you get a weird negative time-diff back...
 *
 * Returns: the time difference in number of microseconds.
 */
timediff_t Curl_timediff_us(struct curltime newer, struct curltime older);

#endif /* HEADER_CURL_TIMEVAL_H */
