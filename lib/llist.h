#ifndef HEADER_CURL_LLIST_H
#define HEADER_CURL_LLIST_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#include <stddef.h>

typedef void (*Curl_llist_dtor)(void *, void *);

struct Curl_llist_element {
  void *ptr;
  struct Curl_llist_element *prev;
  struct Curl_llist_element *next;
};

struct Curl_llist {
  struct Curl_llist_element *head;
  struct Curl_llist_element *tail;
  Curl_llist_dtor dtor;
  size_t size;
};

void Curl_llist_init(struct Curl_llist *, Curl_llist_dtor);
void Curl_llist_insert_next(struct Curl_llist *, struct Curl_llist_element *,
                            const void *, struct Curl_llist_element *node);
void Curl_llist_remove(struct Curl_llist *, struct Curl_llist_element *,
                       void *);
size_t Curl_llist_count(struct Curl_llist *);
void Curl_llist_destroy(struct Curl_llist *, void *);
#endif /* HEADER_CURL_LLIST_H */
