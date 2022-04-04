#ifndef HEADER_CURL_SOCKS_H
#define HEADER_CURL_SOCKS_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef CURL_DISABLE_PROXY
#define Curl_SOCKS4(a,b,c,d,e) CURLE_NOT_BUILT_IN
#define Curl_SOCKS5(a,b,c,d,e,f) CURLE_NOT_BUILT_IN
#define Curl_SOCKS_getsock(x,y,z) 0
#else
/*
 * Helper read-from-socket functions. Does the same as Curl_read() but it
 * blocks until all bytes amount of buffersize will be read. No more, no less.
 *
 * This is STUPID BLOCKING behavior
 */
int Curl_blockread_all(struct Curl_easy *data,
                       curl_socket_t sockfd,
                       char *buf,
                       ssize_t buffersize,
                       ssize_t *n);

int Curl_SOCKS_getsock(struct connectdata *conn,
                       curl_socket_t *sock,
                       int sockindex);
/*
 * This function logs in to a SOCKS4(a) proxy and sends the specifics to the
 * final destination server.
 */
CURLproxycode Curl_SOCKS4(const char *proxy_name,
                          const char *hostname,
                          int remote_port,
                          int sockindex,
                          struct Curl_easy *data,
                          bool *done);

/*
 * This function logs in to a SOCKS5 proxy and sends the specifics to the
 * final destination server.
 */
CURLproxycode Curl_SOCKS5(const char *proxy_name,
                          const char *proxy_password,
                          const char *hostname,
                          int remote_port,
                          int sockindex,
                          struct Curl_easy *data,
                          bool *done);

#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
/*
 * This function handles the SOCKS5 GSS-API negotiation and initialisation
 */
CURLcode Curl_SOCKS5_gssapi_negotiate(int sockindex,
                                      struct Curl_easy *data);
#endif

#endif /* CURL_DISABLE_PROXY */

#endif  /* HEADER_CURL_SOCKS_H */
