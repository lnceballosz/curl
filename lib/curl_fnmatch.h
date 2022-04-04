#ifndef HEADER_CURL_FNMATCH_H
#define HEADER_CURL_FNMATCH_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#define CURL_FNMATCH_MATCH    0
#define CURL_FNMATCH_NOMATCH  1
#define CURL_FNMATCH_FAIL     2

/* default pattern matching function
 * =================================
 * Implemented with recursive backtracking, if you want to use Curl_fnmatch,
 * please note that there is not implemented UTF/UNICODE support.
 *
 * Implemented features:
 * '?' notation, does not match UTF characters
 * '*' can also work with UTF string
 * [a-zA-Z0-9] enumeration support
 *
 * keywords: alnum, digit, xdigit, alpha, print, blank, lower, graph, space
 *           and upper (use as "[[:alnum:]]")
 */
int Curl_fnmatch(void *ptr, const char *pattern, const char *string);

#endif /* HEADER_CURL_FNMATCH_H */
