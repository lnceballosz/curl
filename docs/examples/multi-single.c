// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* <DESC>
 * using the multi interface to do a single download
 * </DESC>
 */

#include <stdio.h>
#include <string.h>

/* somewhat unix-specific */
#include <sys/time.h>
#include <unistd.h>

/* curl stuff */
#include <curl/curl.h>

/*
 * Simply download a HTTP file.
 */
int main(void)
{
  CURL *http_handle;
  CURLM *multi_handle;
  int still_running = 1; /* keep number of running handles */

  curl_global_init(CURL_GLOBAL_DEFAULT);

  http_handle = curl_easy_init();

  /* set the options (I left out a few, you will get the point anyway) */
  curl_easy_setopt(http_handle, CURLOPT_URL, "https://www.example.com/");

  /* init a multi stack */
  multi_handle = curl_multi_init();

  /* add the individual transfers */
  curl_multi_add_handle(multi_handle, http_handle);

  do {
    CURLMcode mc = curl_multi_perform(multi_handle, &still_running);

    if(!mc)
      /* wait for activity, timeout or "nothing" */
      mc = curl_multi_poll(multi_handle, NULL, 0, 1000, NULL);

    if(mc) {
      fprintf(stderr, "curl_multi_poll() failed, code %d.\n", (int)mc);
      break;
    }

  } while(still_running);

  curl_multi_remove_handle(multi_handle, http_handle);

  curl_easy_cleanup(http_handle);

  curl_multi_cleanup(multi_handle);

  curl_global_cleanup();

  return 0;
}
