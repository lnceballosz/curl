#ifndef HEADER_CURL_TOOL_CB_DBG_H
#define HEADER_CURL_TOOL_CB_DBG_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

/*
** callback for CURLOPT_DEBUGFUNCTION
*/

int tool_debug_cb(CURL *handle, curl_infotype type,
                  char *data, size_t size,
                  void *userdata);

#endif /* HEADER_CURL_TOOL_CB_DBG_H */
