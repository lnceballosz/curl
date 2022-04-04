#ifndef HEADER_CURL_GET_LINE_H
#define HEADER_CURL_GET_LINE_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* get_line() makes sure to only return complete whole lines that fit in 'len'
 * bytes and end with a newline. */
char *Curl_get_line(char *buf, int len, FILE *input);

#endif /* HEADER_CURL_GET_LINE_H */
