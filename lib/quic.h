#ifndef HEADER_CURL_QUIC_H
#define HEADER_CURL_QUIC_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef ENABLE_QUIC
#ifdef USE_NGTCP2
#include "vquic/ngtcp2.h"
#endif
#ifdef USE_QUICHE
#include "vquic/quiche.h"
#endif

#include "urldata.h"

/* functions provided by the specific backends */
CURLcode Curl_quic_connect(struct Curl_easy *data,
                           struct connectdata *conn,
                           curl_socket_t sockfd,
                           int sockindex,
                           const struct sockaddr *addr,
                           socklen_t addrlen);
CURLcode Curl_quic_is_connected(struct Curl_easy *data,
                                struct connectdata *conn,
                                int sockindex,
                                bool *connected);
void Curl_quic_ver(char *p, size_t len);
CURLcode Curl_quic_done_sending(struct Curl_easy *data);
void Curl_quic_done(struct Curl_easy *data, bool premature);
bool Curl_quic_data_pending(const struct Curl_easy *data);
void Curl_quic_disconnect(struct Curl_easy *data,
                          struct connectdata *conn, int tempindex);

#else /* ENABLE_QUIC */
#define Curl_quic_done_sending(x)
#define Curl_quic_done(x,y)
#define Curl_quic_data_pending(x)
#define Curl_quic_disconnect(x,y,z)
#endif /* !ENABLE_QUIC */

#endif /* HEADER_CURL_QUIC_H */
