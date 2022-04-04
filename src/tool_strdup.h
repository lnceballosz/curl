#ifndef HEADER_TOOL_STRDUP_H
#define HEADER_TOOL_STRDUP_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#ifndef HAVE_STRDUP
extern char *strdup(const char *str);
#endif

#endif /* HEADER_TOOL_STRDUP_H */
