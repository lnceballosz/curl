#ifndef HEADER_CURL_VERSION_WIN32_H
#define HEADER_CURL_VERSION_WIN32_H

// Copyright (C) 2016 - 2021, Steve Holme, <steve_holme@hotmail.com>.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(WIN32)

/* Version condition */
typedef enum {
  VERSION_LESS_THAN,
  VERSION_LESS_THAN_EQUAL,
  VERSION_EQUAL,
  VERSION_GREATER_THAN_EQUAL,
  VERSION_GREATER_THAN
} VersionCondition;

/* Platform identifier */
typedef enum {
  PLATFORM_DONT_CARE,
  PLATFORM_WINDOWS,
  PLATFORM_WINNT
} PlatformIdentifier;

/* This is used to verify if we are running on a specific windows version */
bool curlx_verify_windows_version(const unsigned int majorVersion,
                                  const unsigned int minorVersion,
                                  const unsigned int buildVersion,
                                  const PlatformIdentifier platform,
                                  const VersionCondition condition);

#endif /* WIN32 */

#endif /* HEADER_CURL_VERSION_WIN32_H */
