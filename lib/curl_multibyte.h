#ifndef HEADER_CURL_MULTIBYTE_H
#define HEADER_CURL_MULTIBYTE_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(WIN32)

 /*
  * MultiByte conversions using Windows kernel32 library.
  */

wchar_t *curlx_convert_UTF8_to_wchar(const char *str_utf8);
char *curlx_convert_wchar_to_UTF8(const wchar_t *str_w);
#endif /* WIN32 */

/*
 * Macros curlx_convert_UTF8_to_tchar(), curlx_convert_tchar_to_UTF8()
 * and curlx_unicodefree() main purpose is to minimize the number of
 * preprocessor conditional directives needed by code using these
 * to differentiate UNICODE from non-UNICODE builds.
 *
 * In the case of a non-UNICODE build the tchar strings are char strings that
 * are duplicated via strdup and remain in whatever the passed in encoding is,
 * which is assumed to be UTF-8 but may be other encoding. Therefore the
 * significance of the conversion functions is primarily for UNICODE builds.
 *
 * Allocated memory should be free'd with curlx_unicodefree().
 *
 * Note: Because these are curlx functions their memory usage is not tracked
 * by the curl memory tracker memdebug. You'll notice that curlx function-like
 * macros call free and strdup in parentheses, eg (strdup)(ptr), and that's to
 * ensure that the curl memdebug override macros do not replace them.
 */

#if defined(UNICODE) && defined(WIN32)

#define curlx_convert_UTF8_to_tchar(ptr) curlx_convert_UTF8_to_wchar((ptr))
#define curlx_convert_tchar_to_UTF8(ptr) curlx_convert_wchar_to_UTF8((ptr))

typedef union {
  unsigned short       *tchar_ptr;
  const unsigned short *const_tchar_ptr;
  unsigned short       *tbyte_ptr;
  const unsigned short *const_tbyte_ptr;
} xcharp_u;

#else

#define curlx_convert_UTF8_to_tchar(ptr) (strdup)(ptr)
#define curlx_convert_tchar_to_UTF8(ptr) (strdup)(ptr)

typedef union {
  char                *tchar_ptr;
  const char          *const_tchar_ptr;
  unsigned char       *tbyte_ptr;
  const unsigned char *const_tbyte_ptr;
} xcharp_u;

#endif /* UNICODE && WIN32 */

#define curlx_unicodefree(ptr)                          \
  do {                                                  \
    if(ptr) {                                           \
      (free)(ptr);                                      \
      (ptr) = NULL;                                     \
    }                                                   \
  } while(0)

#endif /* HEADER_CURL_MULTIBYTE_H */
