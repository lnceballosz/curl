#ifndef HEADER_CURL_PATH_H
#define HEADER_CURL_PATH_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#include <curl/curl.h>
#include "urldata.h"

#ifdef WIN32
#  undef  PATH_MAX
#  define PATH_MAX MAX_PATH
#  ifndef R_OK
#    define R_OK 4
#  endif
#endif

#ifndef PATH_MAX
#define PATH_MAX 1024 /* just an extra precaution since there are systems that
                         have their definition hidden well */
#endif

CURLcode Curl_getworkingpath(struct Curl_easy *data,
                             char *homedir,
                             char **path);

CURLcode Curl_get_pathname(const char **cpp, char **path, char *homedir);
#endif /* HEADER_CURL_PATH_H */
