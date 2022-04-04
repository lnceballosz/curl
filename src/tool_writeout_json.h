#ifndef HEADER_CURL_TOOL_WRITEOUT_JSON_H
#define HEADER_CURL_TOOL_WRITEOUT_JSON_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"
#include "tool_writeout.h"

void ourWriteOutJSON(FILE *stream, const struct writeoutvar mappings[],
                     struct per_transfer *per, CURLcode per_result);
void headerJSON(FILE *stream, struct per_transfer *per);
void jsonWriteString(FILE *stream, const char *in, bool lowercase);

#endif /* HEADER_CURL_TOOL_WRITEOUT_H */
