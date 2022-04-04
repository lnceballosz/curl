// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#define ENABLE_CURLX_PRINTF
/* use our own printf() functions */
#include "curlx.h"

#include "tool_cfgable.h"
#include "tool_cb_rea.h"
#include "tool_operate.h"

#include "memdebug.h" /* keep this as LAST include */

/*
** callback for CURLOPT_READFUNCTION
*/

size_t tool_read_cb(char *buffer, size_t sz, size_t nmemb, void *userdata)
{
  ssize_t rc;
  struct InStruct *in = userdata;

  rc = read(in->fd, buffer, sz*nmemb);
  if(rc < 0) {
    if(errno == EAGAIN) {
      errno = 0;
      in->config->readbusy = TRUE;
      return CURL_READFUNC_PAUSE;
    }
    /* since size_t is unsigned we can't return negative values fine */
    rc = 0;
  }
  in->config->readbusy = FALSE;
  return (size_t)rc;
}

/*
** callback for CURLOPT_XFERINFOFUNCTION used to unpause busy reads
*/

int tool_readbusy_cb(void *clientp,
                     curl_off_t dltotal, curl_off_t dlnow,
                     curl_off_t ultotal, curl_off_t ulnow)
{
  struct per_transfer *per = clientp;
  struct OperationConfig *config = per->config;

  (void)dltotal;  /* unused */
  (void)dlnow;  /* unused */
  (void)ultotal;  /* unused */
  (void)ulnow;  /* unused */

  if(config->readbusy) {
    config->readbusy = FALSE;
    curl_easy_pause(per->curl, CURLPAUSE_CONT);
  }

  return per->noprogress? 0 : CURL_PROGRESSFUNC_CONTINUE;
}
