#ifndef HEADER_CURL_FILE_H
#define HEADER_CURL_FILE_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/****************************************************************************
 * FILE unique setup
 ***************************************************************************/
struct FILEPROTO {
  char *path; /* the path we operate on */
  char *freepath; /* pointer to the allocated block we must free, this might
                     differ from the 'path' pointer */
  int fd;     /* open file descriptor to read from! */
};

#ifndef CURL_DISABLE_FILE
extern const struct Curl_handler Curl_handler_file;
#endif

#endif /* HEADER_CURL_FILE_H */
