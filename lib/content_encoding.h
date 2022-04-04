#ifndef HEADER_CURL_CONTENT_ENCODING_H
#define HEADER_CURL_CONTENT_ENCODING_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

struct contenc_writer {
  const struct content_encoding *handler;  /* Encoding handler. */
  struct contenc_writer *downstream;  /* Downstream writer. */
  void *params;  /* Encoding-specific storage (variable length). */
};

/* Content encoding writer. */
struct content_encoding {
  const char *name;        /* Encoding name. */
  const char *alias;       /* Encoding name alias. */
  CURLcode (*init_writer)(struct Curl_easy *data,
                          struct contenc_writer *writer);
  CURLcode (*unencode_write)(struct Curl_easy *data,
                             struct contenc_writer *writer,
                             const char *buf, size_t nbytes);
  void (*close_writer)(struct Curl_easy *data,
                       struct contenc_writer *writer);
  size_t paramsize;
};


CURLcode Curl_build_unencoding_stack(struct Curl_easy *data,
                                     const char *enclist, int maybechunked);
CURLcode Curl_unencode_write(struct Curl_easy *data,
                             struct contenc_writer *writer,
                             const char *buf, size_t nbytes);
void Curl_unencode_cleanup(struct Curl_easy *data);
char *Curl_all_content_encodings(void);

#endif /* HEADER_CURL_CONTENT_ENCODING_H */
