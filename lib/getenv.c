// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#include <curl/curl.h>
#include "curl_memory.h"

#include "memdebug.h"

static char *GetEnv(const char *variable)
{
#if defined(_WIN32_WCE) || defined(CURL_WINDOWS_APP)
  (void)variable;
  return NULL;
#elif defined(WIN32)
  /* This uses Windows API instead of C runtime getenv() to get the environment
     variable since some changes aren't always visible to the latter. #4774 */
  char *buf = NULL;
  char *tmp;
  DWORD bufsize;
  DWORD rc = 1;
  const DWORD max = 32768; /* max env var size from MSCRT source */

  for(;;) {
    tmp = realloc(buf, rc);
    if(!tmp) {
      free(buf);
      return NULL;
    }

    buf = tmp;
    bufsize = rc;

    /* It's possible for rc to be 0 if the variable was found but empty.
       Since getenv doesn't make that distinction we ignore it as well. */
    rc = GetEnvironmentVariableA(variable, buf, bufsize);
    if(!rc || rc == bufsize || rc > max) {
      free(buf);
      return NULL;
    }

    /* if rc < bufsize then rc is bytes written not including null */
    if(rc < bufsize)
      return buf;

    /* else rc is bytes needed, try again */
  }
#else
  char *env = getenv(variable);
  return (env && env[0])?strdup(env):NULL;
#endif
}

char *curl_getenv(const char *v)
{
  return GetEnv(v);
}
