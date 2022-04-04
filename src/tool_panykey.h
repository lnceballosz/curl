#ifndef HEADER_CURL_TOOL_PANYKEY_H
#define HEADER_CURL_TOOL_PANYKEY_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#if defined(NETWARE)
void tool_pressanykey(void);
#else
#define tool_pressanykey() Curl_nop_stmt
#endif

#endif /* HEADER_CURL_TOOL_PANYKEY_H */
