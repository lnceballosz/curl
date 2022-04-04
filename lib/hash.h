#ifndef HEADER_CURL_HASH_H
#define HEADER_CURL_HASH_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#include <stddef.h>

#include "llist.h"

/* Hash function prototype */
typedef size_t (*hash_function) (void *key,
                                 size_t key_length,
                                 size_t slots_num);

/*
   Comparator function prototype. Compares two keys.
*/
typedef size_t (*comp_function) (void *key1,
                                 size_t key1_len,
                                 void *key2,
                                 size_t key2_len);

typedef void (*Curl_hash_dtor)(void *);

struct Curl_hash {
  struct Curl_llist *table;

  /* Hash function to be used for this hash table */
  hash_function hash_func;

  /* Comparator function to compare keys */
  comp_function comp_func;
  Curl_hash_dtor   dtor;
  int slots;
  size_t size;
};

struct Curl_hash_element {
  struct Curl_llist_element list;
  void   *ptr;
  size_t key_len;
  char   key[1]; /* allocated memory following the struct */
};

struct Curl_hash_iterator {
  struct Curl_hash *hash;
  int slot_index;
  struct Curl_llist_element *current_element;
};

void Curl_hash_init(struct Curl_hash *h,
                    int slots,
                    hash_function hfunc,
                    comp_function comparator,
                    Curl_hash_dtor dtor);

void *Curl_hash_add(struct Curl_hash *h, void *key, size_t key_len, void *p);
int Curl_hash_delete(struct Curl_hash *h, void *key, size_t key_len);
void *Curl_hash_pick(struct Curl_hash *, void *key, size_t key_len);
void Curl_hash_apply(struct Curl_hash *h, void *user,
                     void (*cb)(void *user, void *ptr));
#define Curl_hash_count(h) ((h)->size)
void Curl_hash_destroy(struct Curl_hash *h);
void Curl_hash_clean(struct Curl_hash *h);
void Curl_hash_clean_with_criterium(struct Curl_hash *h, void *user,
                                    int (*comp)(void *, void *));
size_t Curl_hash_str(void *key, size_t key_length, size_t slots_num);
size_t Curl_str_key_compare(void *k1, size_t key1_len, void *k2,
                            size_t key2_len);
void Curl_hash_start_iterate(struct Curl_hash *hash,
                             struct Curl_hash_iterator *iter);
struct Curl_hash_element *
Curl_hash_next_element(struct Curl_hash_iterator *iter);

void Curl_hash_print(struct Curl_hash *h,
                     void (*func)(void *));


#endif /* HEADER_CURL_HASH_H */
