#ifndef HEADER_CURL_TOOL_CB_PRG_H
#define HEADER_CURL_TOOL_CB_PRG_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#define CURL_PROGRESS_STATS 0 /* default progress display */
#define CURL_PROGRESS_BAR   1

struct ProgressData {
  int         calls;
  curl_off_t  prev;
  struct timeval prevtime;
  int         width;
  FILE       *out;  /* where to write everything to */
  curl_off_t  initial_size;
  unsigned int tick;
  int bar;
  int barmove;
};

void progressbarinit(struct ProgressData *bar,
                     struct OperationConfig *config);

/*
** callback for CURLOPT_PROGRESSFUNCTION
*/

int tool_progress_cb(void *clientp,
                     curl_off_t dltotal, curl_off_t dlnow,
                     curl_off_t ultotal, curl_off_t ulnow);

#endif /* HEADER_CURL_TOOL_CB_PRG_H */
