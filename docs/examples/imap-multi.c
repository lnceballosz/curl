// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* <DESC>
 * IMAP example using the multi interface
 * </DESC>
 */

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

/* This is a simple example showing how to fetch mail using libcurl's IMAP
 * capabilities. It builds on the imap-fetch.c example to demonstrate how to
 * use libcurl's multi interface.
 */

int main(void)
{
  CURL *curl;
  CURLM *mcurl;
  int still_running = 1;

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if(!curl)
    return 1;

  mcurl = curl_multi_init();
  if(!mcurl)
    return 2;

  /* Set username and password */
  curl_easy_setopt(curl, CURLOPT_USERNAME, "user");
  curl_easy_setopt(curl, CURLOPT_PASSWORD, "secret");

  /* This will fetch message 1 from the user's inbox */
  curl_easy_setopt(curl, CURLOPT_URL, "imap://imap.example.com/INBOX/;UID=1");

  /* Tell the multi stack about our easy handle */
  curl_multi_add_handle(mcurl, curl);

  do {
    CURLMcode mc = curl_multi_perform(mcurl, &still_running);

    if(still_running)
      /* wait for activity, timeout or "nothing" */
      mc = curl_multi_poll(mcurl, NULL, 0, 1000, NULL);

    if(mc)
      break;
  } while(still_running);

  /* Always cleanup */
  curl_multi_remove_handle(mcurl, curl);
  curl_multi_cleanup(mcurl);
  curl_easy_cleanup(curl);
  curl_global_cleanup();

  return 0;
}
