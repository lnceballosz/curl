// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* <DESC>
 * Set working URL with CURLU *.
 * </DESC>
 */
#include <stdio.h>
#include <curl/curl.h>

#if !CURL_AT_LEAST_VERSION(7, 80, 0)
#error "this example requires curl 7.80.0 or later"
#endif

int main(void)
{
  CURL *curl;
  CURLcode res;

  CURLU *urlp;
  CURLUcode uc;

  /* get a curl handle */
  curl = curl_easy_init();

  /* init Curl URL */
  urlp = curl_url();
  uc = curl_url_set(urlp, CURLUPART_URL,
                    "http://example.com/path/index.html", 0);

  if(uc) {
    fprintf(stderr, "curl_url_set() failed: %s", curl_url_strerror(uc));
    goto cleanup;
  }

  if(curl) {
    /* set urlp to use as working URL */
    curl_easy_setopt(curl, CURLOPT_CURLU, urlp);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    goto cleanup;
  }

  cleanup:
  curl_url_cleanup(urlp);
  curl_easy_cleanup(curl);
  return 0;
}
