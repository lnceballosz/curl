#ifndef HEADER_CURL_TOOL_CB_WRT_H
#define HEADER_CURL_TOOL_CB_WRT_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

/*
** callback for CURLOPT_WRITEFUNCTION
*/

size_t tool_write_cb(char *buffer, size_t sz, size_t nmemb, void *userdata);

/* create a local file for writing, return TRUE on success */
bool tool_create_output_file(struct OutStruct *outs,
                             struct OperationConfig *config);

#endif /* HEADER_CURL_TOOL_CB_WRT_H */
