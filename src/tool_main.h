#ifndef HEADER_CURL_TOOL_MAIN_H
#define HEADER_CURL_TOOL_MAIN_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#define DEFAULT_MAXREDIRS  50L

#define RETRY_SLEEP_DEFAULT 1000L   /* ms */
#define RETRY_SLEEP_MAX     600000L /* ms == 10 minutes */

#define MAX_PARALLEL 300 /* conservative */
#define PARALLEL_DEFAULT 50

#ifndef STDIN_FILENO
#  define STDIN_FILENO  fileno(stdin)
#endif

#ifndef STDOUT_FILENO
#  define STDOUT_FILENO  fileno(stdout)
#endif

#ifndef STDERR_FILENO
#  define STDERR_FILENO  fileno(stderr)
#endif

#endif /* HEADER_CURL_TOOL_MAIN_H */
