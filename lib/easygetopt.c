// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#include "strcase.h"
#include "easyoptions.h"

#ifndef CURL_DISABLE_GETOPTIONS

/* Lookups easy options at runtime */
static struct curl_easyoption *lookup(const char *name, CURLoption id)
{
  DEBUGASSERT(name || id);
  DEBUGASSERT(!Curl_easyopts_check());
  if(name || id) {
    struct curl_easyoption *o = &Curl_easyopts[0];
    do {
      if(name) {
        if(strcasecompare(o->name, name))
          return o;
      }
      else {
        if((o->id == id) && !(o->flags & CURLOT_FLAG_ALIAS))
          /* don't match alias options */
          return o;
      }
      o++;
    } while(o->name);
  }
  return NULL;
}

const struct curl_easyoption *curl_easy_option_by_name(const char *name)
{
  /* when name is used, the id argument is ignored */
  return lookup(name, CURLOPT_LASTENTRY);
}

const struct curl_easyoption *curl_easy_option_by_id(CURLoption id)
{
  return lookup(NULL, id);
}

/* Iterates over available options */
const struct curl_easyoption *
curl_easy_option_next(const struct curl_easyoption *prev)
{
  if(prev && prev->name) {
    prev++;
    if(prev->name)
      return prev;
  }
  else if(!prev)
    return &Curl_easyopts[0];
  return NULL;
}

#else
const struct curl_easyoption *curl_easy_option_by_name(const char *name)
{
  (void)name;
  return NULL;
}

const struct curl_easyoption *curl_easy_option_by_id (CURLoption id)
{
  (void)id;
  return NULL;
}

const struct curl_easyoption *
curl_easy_option_next(const struct curl_easyoption *prev)
{
  (void)prev;
  return NULL;
}
#endif
