#ifndef HEADER_CURL_SLIST_H
#define HEADER_CURL_SLIST_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/*
 * Curl_slist_duplicate() duplicates a linked list. It always returns the
 * address of the first record of the cloned list or NULL in case of an
 * error (or if the input list was NULL).
 */
struct curl_slist *Curl_slist_duplicate(struct curl_slist *inlist);

/*
 * Curl_slist_append_nodup() takes ownership of the given string and appends
 * it to the list.
 */
struct curl_slist *Curl_slist_append_nodup(struct curl_slist *list,
                                           char *data);

#endif /* HEADER_CURL_SLIST_H */
