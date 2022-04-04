#ifndef HEADER_CURL_SPLAY_H
#define HEADER_CURL_SPLAY_H

// Copyright (C) 1997 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#include "timeval.h"

struct Curl_tree {
  struct Curl_tree *smaller; /* smaller node */
  struct Curl_tree *larger;  /* larger node */
  struct Curl_tree *samen;   /* points to the next node with identical key */
  struct Curl_tree *samep;   /* points to the prev node with identical key */
  struct curltime key;        /* this node's "sort" key */
  void *payload;             /* data the splay code doesn't care about */
};

struct Curl_tree *Curl_splay(struct curltime i,
                             struct Curl_tree *t);

struct Curl_tree *Curl_splayinsert(struct curltime key,
                                   struct Curl_tree *t,
                                   struct Curl_tree *newnode);

struct Curl_tree *Curl_splaygetbest(struct curltime key,
                                    struct Curl_tree *t,
                                    struct Curl_tree **removed);

int Curl_splayremove(struct Curl_tree *t,
                     struct Curl_tree *removenode,
                     struct Curl_tree **newroot);

#define Curl_splaycomparekeys(i,j) ( ((i.tv_sec)  < (j.tv_sec)) ? -1 : \
                                   ( ((i.tv_sec)  > (j.tv_sec)) ?  1 : \
                                   ( ((i.tv_usec) < (j.tv_usec)) ? -1 : \
                                   ( ((i.tv_usec) > (j.tv_usec)) ?  1 : 0))))

#endif /* HEADER_CURL_SPLAY_H */
