#ifndef HEADER_CURL_KRB5_H
#define HEADER_CURL_KRB5_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

struct Curl_sec_client_mech {
  const char *name;
  size_t size;
  int (*init)(void *);
  int (*auth)(void *, struct Curl_easy *data, struct connectdata *);
  void (*end)(void *);
  int (*check_prot)(void *, int);
  int (*encode)(void *, const void *, int, int, void **);
  int (*decode)(void *, void *, int, int, struct connectdata *);
};

#define AUTH_OK         0
#define AUTH_CONTINUE   1
#define AUTH_ERROR      2

#ifdef HAVE_GSSAPI
int Curl_sec_read_msg(struct Curl_easy *data, struct connectdata *conn, char *,
                      enum protection_level);
void Curl_sec_end(struct connectdata *);
CURLcode Curl_sec_login(struct Curl_easy *, struct connectdata *);
int Curl_sec_request_prot(struct connectdata *conn, const char *level);
#else
#define Curl_sec_end(x)
#endif

#endif /* HEADER_CURL_KRB5_H */
