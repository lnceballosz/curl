#ifndef HEADER_CURL_FORMDATA_H
#define HEADER_CURL_FORMDATA_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifndef CURL_DISABLE_MIME

/* used by FormAdd for temporary storage */
struct FormInfo {
  char *name;
  size_t namelength;
  char *value;
  curl_off_t contentslength;
  char *contenttype;
  long flags;
  char *buffer;      /* pointer to existing buffer used for file upload */
  size_t bufferlength;
  char *showfilename; /* The file name to show. If not set, the actual
                         file name will be used */
  char *userp;        /* pointer for the read callback */
  struct curl_slist *contentheader;
  struct FormInfo *more;
  bool name_alloc;
  bool value_alloc;
  bool contenttype_alloc;
  bool showfilename_alloc;
};

CURLcode Curl_getformdata(struct Curl_easy *data,
                          curl_mimepart *,
                          struct curl_httppost *post,
                          curl_read_callback fread_func);
#else
/* disabled */
#define Curl_getformdata(a,b,c,d) CURLE_NOT_BUILT_IN
#endif


#endif /* HEADER_CURL_FORMDATA_H */
