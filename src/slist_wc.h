#ifndef HEADER_CURL_SLIST_WC_H
#define HEADER_CURL_SLIST_WC_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"
#ifndef CURL_DISABLE_LIBCURL_OPTION

/* linked-list structure with last node cache for easysrc */
struct slist_wc {
  struct curl_slist *first;
  struct curl_slist *last;
};

/*
 * NAME curl_slist_wc_append()
 *
 * DESCRIPTION
 *
 * Appends a string to a linked list. If no list exists, it will be created
 * first. Returns the new list, after appending.
 */
struct slist_wc *slist_wc_append(struct slist_wc *, const char *);

/*
 * NAME curl_slist_free_all()
 *
 * DESCRIPTION
 *
 * free a previously built curl_slist_wc.
 */
void slist_wc_free_all(struct slist_wc *);

#endif /* CURL_DISABLE_LIBCURL_OPTION */

#endif /* HEADER_CURL_SLIST_WC_H */
