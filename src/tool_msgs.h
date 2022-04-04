#ifndef HEADER_CURL_TOOL_MSGS_H
#define HEADER_CURL_TOOL_MSGS_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

void warnf(struct GlobalConfig *config, const char *fmt, ...);
void notef(struct GlobalConfig *config, const char *fmt, ...);
void helpf(FILE *errors, const char *fmt, ...);
void errorf(struct GlobalConfig *config, const char *fmt, ...);

#endif /* HEADER_CURL_TOOL_MSGS_H */
