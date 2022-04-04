#ifndef HEADER_CURL_TOOL_WRITEOUT_H
#define HEADER_CURL_TOOL_WRITEOUT_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"
#include "tool_operate.h"

typedef enum {
  VAR_NONE,       /* must be the first */
  VAR_APPCONNECT_TIME,
  VAR_CONNECT_TIME,
  VAR_CONTENT_TYPE,
  VAR_EFFECTIVE_FILENAME,
  VAR_EFFECTIVE_METHOD,
  VAR_EFFECTIVE_URL,
  VAR_ERRORMSG,
  VAR_EXITCODE,
  VAR_FTP_ENTRY_PATH,
  VAR_HEADER_JSON,
  VAR_HEADER_SIZE,
  VAR_HTTP_CODE,
  VAR_HTTP_CODE_PROXY,
  VAR_HTTP_VERSION,
  VAR_INPUT_URL,
  VAR_JSON,
  VAR_LOCAL_IP,
  VAR_LOCAL_PORT,
  VAR_NAMELOOKUP_TIME,
  VAR_NUM_CONNECTS,
  VAR_NUM_HEADERS,
  VAR_ONERROR,
  VAR_PRETRANSFER_TIME,
  VAR_PRIMARY_IP,
  VAR_PRIMARY_PORT,
  VAR_PROXY_SSL_VERIFY_RESULT,
  VAR_REDIRECT_COUNT,
  VAR_REDIRECT_TIME,
  VAR_REDIRECT_URL,
  VAR_REFERER,
  VAR_REQUEST_SIZE,
  VAR_SCHEME,
  VAR_SIZE_DOWNLOAD,
  VAR_SIZE_UPLOAD,
  VAR_SPEED_DOWNLOAD,
  VAR_SPEED_UPLOAD,
  VAR_SSL_VERIFY_RESULT,
  VAR_STARTTRANSFER_TIME,
  VAR_STDERR,
  VAR_STDOUT,
  VAR_TOTAL_TIME,
  VAR_URLNUM,
  VAR_NUM_OF_VARS /* must be the last */
} writeoutid;

struct writeoutvar {
  const char *name;
  writeoutid id;
  CURLINFO ci;
  int (*writefunc)(FILE *stream, const struct writeoutvar *wovar,
                   struct per_transfer *per, CURLcode per_result,
                   bool use_json);
};

void ourWriteOut(const char *writeinfo, struct per_transfer *per,
                 CURLcode per_result);

#endif /* HEADER_CURL_TOOL_WRITEOUT_H */
