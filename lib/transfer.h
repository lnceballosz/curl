#ifndef HEADER_CURL_TRANSFER_H
#define HEADER_CURL_TRANSFER_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#define Curl_headersep(x) ((((x)==':') || ((x)==';')))
char *Curl_checkheaders(const struct Curl_easy *data,
                        const char *thisheader,
                        const size_t thislen);

void Curl_init_CONNECT(struct Curl_easy *data);

CURLcode Curl_pretransfer(struct Curl_easy *data);
CURLcode Curl_posttransfer(struct Curl_easy *data);

typedef enum {
  FOLLOW_NONE,  /* not used within the function, just a placeholder to
                   allow initing to this */
  FOLLOW_FAKE,  /* only records stuff, not actually following */
  FOLLOW_RETRY, /* set if this is a request retry as opposed to a real
                   redirect following */
  FOLLOW_REDIR /* a full true redirect */
} followtype;

CURLcode Curl_follow(struct Curl_easy *data, char *newurl,
                     followtype type);
CURLcode Curl_readwrite(struct connectdata *conn,
                        struct Curl_easy *data, bool *done,
                        bool *comeback);
int Curl_single_getsock(struct Curl_easy *data,
                        struct connectdata *conn, curl_socket_t *socks);
CURLcode Curl_readrewind(struct Curl_easy *data);
CURLcode Curl_fillreadbuffer(struct Curl_easy *data, size_t bytes,
                             size_t *nreadp);
CURLcode Curl_retry_request(struct Curl_easy *data, char **url);
bool Curl_meets_timecondition(struct Curl_easy *data, time_t timeofdoc);
CURLcode Curl_get_upload_buffer(struct Curl_easy *data);

CURLcode Curl_done_sending(struct Curl_easy *data,
                           struct SingleRequest *k);

/* This sets up a forthcoming transfer */
void
Curl_setup_transfer (struct Curl_easy *data,
                     int sockindex,     /* socket index to read from or -1 */
                     curl_off_t size,   /* -1 if unknown at this point */
                     bool getheader,    /* TRUE if header parsing is wanted */
                     int writesockindex /* socket index to write to. May be
                                           the same we read from. -1
                                           disables */
  );

#endif /* HEADER_CURL_TRANSFER_H */
