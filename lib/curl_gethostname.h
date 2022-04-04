#ifndef HEADER_CURL_GETHOSTNAME_H
#define HEADER_CURL_GETHOSTNAME_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* Hostname buffer size */
#define HOSTNAME_MAX 1024

/* This returns the local machine's un-qualified hostname */
int Curl_gethostname(char * const name, GETHOSTNAME_TYPE_ARG2 namelen);

#endif /* HEADER_CURL_GETHOSTNAME_H */
