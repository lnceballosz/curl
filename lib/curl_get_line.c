// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if !defined(CURL_DISABLE_COOKIES) || !defined(CURL_DISABLE_ALTSVC) ||  \
  !defined(CURL_DISABLE_HSTS)

#include "curl_get_line.h"
#include "curl_memory.h"
/* The last #include file should be: */
#include "memdebug.h"

/*
 * get_line() makes sure to only return complete whole lines that fit in 'len'
 * bytes and end with a newline.
 */
char *Curl_get_line(char *buf, int len, FILE *input)
{
  bool partial = FALSE;
  while(1) {
    char *b = fgets(buf, len, input);
    if(b) {
      size_t rlen = strlen(b);
      if(rlen && (b[rlen-1] == '\n')) {
        if(partial) {
          partial = FALSE;
          continue;
        }
        return b;
      }
      /* read a partial, discard the next piece that ends with newline */
      partial = TRUE;
    }
    else
      break;
  }
  return NULL;
}

#endif /* if not disabled */
