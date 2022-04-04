// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* <DESC>
 * Shows HTTPS usage with client certs and optional ssl engine use.
 * </DESC>
 */
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

/*
 * An SSL-enabled libcurl is required for this sample to work (at least one
 * SSL backend has to be configured).
 *
 *  **** This example only works with libcurl 7.56.0 and later! ****
*/

int main(int argc, char **argv)
{
  const char *name = argc > 1 ? argv[1] : "openssl";
  CURLsslset result;

  if(!strcmp("list", name)) {
    const curl_ssl_backend **list;
    int i;

    result = curl_global_sslset((curl_sslbackend)-1, NULL, &list);
    assert(result == CURLSSLSET_UNKNOWN_BACKEND);

    for(i = 0; list[i]; i++)
      printf("SSL backend #%d: '%s' (ID: %d)\n",
             i, list[i]->name, list[i]->id);

    return 0;
  }
  else if(isdigit((int)(unsigned char)*name)) {
    int id = atoi(name);

    result = curl_global_sslset((curl_sslbackend)id, NULL, NULL);
  }
  else
    result = curl_global_sslset((curl_sslbackend)-1, name, NULL);

  if(result == CURLSSLSET_UNKNOWN_BACKEND) {
    fprintf(stderr, "Unknown SSL backend id: %s\n", name);
    return 1;
  }

  assert(result == CURLSSLSET_OK);

  printf("Version with SSL backend '%s':\n\n\t%s\n", name, curl_version());

  return 0;
}
