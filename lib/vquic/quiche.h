#ifndef HEADER_CURL_VQUIC_QUICHE_H
#define HEADER_CURL_VQUIC_QUICHE_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_QUICHE

#include <quiche.h>
#include <openssl/ssl.h>

struct quic_handshake {
  char *buf;       /* pointer to the buffer */
  size_t alloclen; /* size of allocation */
  size_t len;      /* size of content in buffer */
  size_t nread;    /* how many bytes have been read */
};

struct quicsocket {
  quiche_config *cfg;
  quiche_conn *conn;
  quiche_h3_conn *h3c;
  quiche_h3_config *h3config;
  uint8_t scid[QUICHE_MAX_CONN_ID_LEN];
  curl_socket_t sockfd;
  uint32_t version;
  SSL_CTX *sslctx;
  SSL *ssl;
  bool h3_recving; /* TRUE when in h3-body-reading state */
};

#endif

#endif /* HEADER_CURL_VQUIC_QUICHE_H */
