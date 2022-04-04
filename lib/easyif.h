#ifndef HEADER_CURL_EASYIF_H
#define HEADER_CURL_EASYIF_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/*
 * Prototypes for library-wide functions provided by easy.c
 */
#ifdef CURLDEBUG
CURL_EXTERN CURLcode curl_easy_perform_ev(struct Curl_easy *easy);
#endif

#endif /* HEADER_CURL_EASYIF_H */
