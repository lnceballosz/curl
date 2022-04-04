#ifndef HEADER_CURL_POP3_H
#define HEADER_CURL_POP3_H

// Copyright (C) 2009 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "pingpong.h"
#include "curl_sasl.h"

/****************************************************************************
 * POP3 unique setup
 ***************************************************************************/
typedef enum {
  POP3_STOP,         /* do nothing state, stops the state machine */
  POP3_SERVERGREET,  /* waiting for the initial greeting immediately after
                        a connect */
  POP3_CAPA,
  POP3_STARTTLS,
  POP3_UPGRADETLS,   /* asynchronously upgrade the connection to SSL/TLS
                       (multi mode only) */
  POP3_AUTH,
  POP3_APOP,
  POP3_USER,
  POP3_PASS,
  POP3_COMMAND,
  POP3_QUIT,
  POP3_LAST          /* never used */
} pop3state;

/* This POP3 struct is used in the Curl_easy. All POP3 data that is
   connection-oriented must be in pop3_conn to properly deal with the fact that
   perhaps the Curl_easy is changed between the times the connection is
   used. */
struct POP3 {
  curl_pp_transfer transfer;
  char *id;               /* Message ID */
  char *custom;           /* Custom Request */
};

/* pop3_conn is used for struct connection-oriented data in the connectdata
   struct */
struct pop3_conn {
  struct pingpong pp;
  pop3state state;        /* Always use pop3.c:state() to change state! */
  bool ssldone;           /* Is connect() over SSL done? */
  bool tls_supported;     /* StartTLS capability supported by server */
  size_t eob;             /* Number of bytes of the EOB (End Of Body) that
                             have been received so far */
  size_t strip;           /* Number of bytes from the start to ignore as
                             non-body */
  struct SASL sasl;       /* SASL-related storage */
  unsigned int authtypes; /* Accepted authentication types */
  unsigned int preftype;  /* Preferred authentication type */
  char *apoptimestamp;    /* APOP timestamp from the server greeting */
};

extern const struct Curl_handler Curl_handler_pop3;
extern const struct Curl_handler Curl_handler_pop3s;

/* Authentication type flags */
#define POP3_TYPE_CLEARTEXT (1 << 0)
#define POP3_TYPE_APOP      (1 << 1)
#define POP3_TYPE_SASL      (1 << 2)

/* Authentication type values */
#define POP3_TYPE_NONE      0
#define POP3_TYPE_ANY       ~0U

/* This is the 5-bytes End-Of-Body marker for POP3 */
#define POP3_EOB "\x0d\x0a\x2e\x0d\x0a"
#define POP3_EOB_LEN 5

/* This function scans the body after the end-of-body and writes everything
 * until the end is found */
CURLcode Curl_pop3_write(struct Curl_easy *data, char *str, size_t nread);

#endif /* HEADER_CURL_POP3_H */
