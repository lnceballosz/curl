#ifndef HEADER_CURL_STRCASE_H
#define HEADER_CURL_STRCASE_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include <curl/curl.h>

/*
 * Only "raw" case insensitive strings. This is meant to be locale independent
 * and only compare strings we know are safe for this.
 *
 * The function is capable of comparing a-z case insensitively.
 *
 * Result is 1 if text matches and 0 if not.
 */

#define strcasecompare(a,b) Curl_strcasecompare(a,b)
#define strncasecompare(a,b,c) Curl_strncasecompare(a,b,c)

int Curl_strcasecompare(const char *first, const char *second);
int Curl_safe_strcasecompare(const char *first, const char *second);
int Curl_strncasecompare(const char *first, const char *second, size_t max);

char Curl_raw_toupper(char in);

/* checkprefix() is a shorter version of the above, used when the first
   argument is the string literal */
#define checkprefix(a,b)    curl_strnequal(b, STRCONST(a))

void Curl_strntoupper(char *dest, const char *src, size_t n);
void Curl_strntolower(char *dest, const char *src, size_t n);

#endif /* HEADER_CURL_STRCASE_H */
