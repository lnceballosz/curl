// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#ifndef CURL_DISABLE_LIBCURL_OPTION

#include "slist_wc.h"

/* The last #include files should be: */
#include "memdebug.h"

/*
 * slist_wc_append() appends a string to the linked list. This function can be
 * used as an initialization function as well as an append function.
 */
struct slist_wc *slist_wc_append(struct slist_wc *list,
                                 const char *data)
{
  struct curl_slist *new_item = curl_slist_append(NULL, data);

  if(!new_item)
    return NULL;

  if(!list) {
    list = malloc(sizeof(struct slist_wc));

    if(!list) {
      curl_slist_free_all(new_item);
      return NULL;
    }

    list->first = new_item;
    list->last = new_item;
    return list;
  }

  list->last->next = new_item;
  list->last = list->last->next;
  return list;
}

/* be nice and clean up resources */
void slist_wc_free_all(struct slist_wc *list)
{
  if(!list)
    return;

  curl_slist_free_all(list->first);
  free(list);
}

#endif /* CURL_DISABLE_LIBCURL_OPTION */
