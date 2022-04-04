#ifndef HEADER_CURL_TOOL_SETUP_H
#define HEADER_CURL_TOOL_SETUP_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#define CURL_NO_OLDIES

/*
 * curl_setup.h may define preprocessor macros such as _FILE_OFFSET_BITS and
 * _LARGE_FILES in order to support files larger than 2 GB. On platforms
 * where this happens it is mandatory that these macros are defined before
 * any system header file is included, otherwise file handling function
 * prototypes will be misdeclared and curl tool may not build properly;
 * therefore we must include curl_setup.h before curl.h when building curl.
 */

#include "curl_setup.h" /* from the lib directory */

/*
 * curl tool certainly uses libcurl's external interface.
 */

#include <curl/curl.h> /* external interface */

/*
 * Platform specific stuff.
 */

#if defined(macintosh) && defined(__MRC__)
#  define main(x,y) curl_main(x,y)
#endif

#ifndef OS
#  define OS "unknown"
#endif

#ifndef UNPRINTABLE_CHAR
   /* define what to use for unprintable characters */
#  define UNPRINTABLE_CHAR '.'
#endif

#ifndef HAVE_STRDUP
#  include "tool_strdup.h"
#endif

#endif /* HEADER_CURL_TOOL_SETUP_H */
