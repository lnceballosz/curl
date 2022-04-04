#ifndef HEADER_CURL_MEMRCHR_H
#define HEADER_CURL_MEMRCHR_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef HAVE_MEMRCHR

#ifdef HAVE_STRING_H
#  include <string.h>
#endif
#ifdef HAVE_STRINGS_H
#  include <strings.h>
#endif

#else /* HAVE_MEMRCHR */

void *Curl_memrchr(const void *s, int c, size_t n);

#define memrchr(x,y,z) Curl_memrchr((x),(y),(z))

#endif /* HAVE_MEMRCHR */

#endif /* HEADER_CURL_MEMRCHR_H */
