#ifndef HEADER_CURL_TOOL_BINMODE_H
#define HEADER_CURL_TOOL_BINMODE_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#ifdef HAVE_SETMODE

void set_binmode(FILE *stream);

#else

#define set_binmode(x) Curl_nop_stmt

#endif /* HAVE_SETMODE */

#endif /* HEADER_CURL_TOOL_BINMODE_H */
