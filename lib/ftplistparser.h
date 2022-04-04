#ifndef HEADER_CURL_FTPLISTPARSER_H
#define HEADER_CURL_FTPLISTPARSER_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifndef CURL_DISABLE_FTP

/* WRITEFUNCTION callback for parsing LIST responses */
size_t Curl_ftp_parselist(char *buffer, size_t size, size_t nmemb,
                          void *connptr);

struct ftp_parselist_data; /* defined inside ftplibparser.c */

CURLcode Curl_ftp_parselist_geterror(struct ftp_parselist_data *pl_data);

struct ftp_parselist_data *Curl_ftp_parselist_data_alloc(void);

void Curl_ftp_parselist_data_free(struct ftp_parselist_data **pl_data);

#endif /* CURL_DISABLE_FTP */
#endif /* HEADER_CURL_FTPLISTPARSER_H */
