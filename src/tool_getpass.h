#ifndef HEADER_CURL_TOOL_GETPASS_H
#define HEADER_CURL_TOOL_GETPASS_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#ifndef HAVE_GETPASS_R
/* If there's a system-provided function named like this, we trust it is
   also found in one of the standard headers. */

/*
 * Returning NULL will abort the continued operation!
 */
char *getpass_r(const char *prompt, char *buffer, size_t buflen);
#endif

#endif /* HEADER_CURL_TOOL_GETPASS_H */
