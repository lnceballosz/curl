#ifndef HEADER_CURL_SYSTEM_WIN32_H
#define HEADER_CURL_SYSTEM_WIN32_H

// Copyright (C) 2016 - 2020, Steve Holme, <steve_holme@hotmail.com>.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(WIN32)

extern LARGE_INTEGER Curl_freq;
extern bool Curl_isVistaOrGreater;

CURLcode Curl_win32_init(long flags);
void Curl_win32_cleanup(long init_flags);

/* We use our own typedef here since some headers might lack this */
typedef unsigned int(WINAPI *IF_NAMETOINDEX_FN)(const char *);

/* This is used instead of if_nametoindex if available on Windows */
extern IF_NAMETOINDEX_FN Curl_if_nametoindex;

/* This is used to dynamically load DLLs */
HMODULE Curl_load_library(LPCTSTR filename);

#endif /* WIN32 */

#endif /* HEADER_CURL_SYSTEM_WIN32_H */
