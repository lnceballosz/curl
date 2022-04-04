#ifndef HEADER_CURL_TOOL_BNAME_H
#define HEADER_CURL_TOOL_BNAME_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#ifndef HAVE_BASENAME

char *tool_basename(char *path);

#define basename(x) tool_basename((x))

#endif /* HAVE_BASENAME */

#endif /* HEADER_CURL_TOOL_BNAME_H */
