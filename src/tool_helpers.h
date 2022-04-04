#ifndef HEADER_CURL_TOOL_HELPERS_H
#define HEADER_CURL_TOOL_HELPERS_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

const char *param2text(int res);

int SetHTTPrequest(struct OperationConfig *config, HttpReq req,
                   HttpReq *store);

void customrequest_helper(struct OperationConfig *config, HttpReq req,
                          char *method);

#endif /* HEADER_CURL_TOOL_HELPERS_H */
