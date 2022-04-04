#ifndef HEADER_CURL_TOOL_UTIL_H
#define HEADER_CURL_TOOL_UTIL_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

struct timeval tvnow(void);

/*
 * Make sure that the first argument (t1) is the more recent time and t2 is
 * the older time, as otherwise you get a weird negative time-diff back...
 *
 * Returns: the time difference in number of milliseconds.
 */
long tvdiff(struct timeval t1, struct timeval t2);

#endif /* HEADER_CURL_TOOL_UTIL_H */
