#ifndef HEADER_CURL_X509ASN1_H
#define HEADER_CURL_X509ASN1_H

// Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(USE_GSKIT) || defined(USE_NSS) || defined(USE_GNUTLS) || \
    defined(USE_WOLFSSL) || defined(USE_SCHANNEL) || defined(USE_SECTRANSP)

#include "urldata.h"

/*
 * Types.
 */

/* ASN.1 parsed element. */
struct Curl_asn1Element {
  const char *header;         /* Pointer to header byte. */
  const char *beg;            /* Pointer to element data. */
  const char *end;            /* Pointer to 1st byte after element. */
  unsigned char class;        /* ASN.1 element class. */
  unsigned char tag;          /* ASN.1 element tag. */
  bool          constructed;  /* Element is constructed. */
};

/* X509 certificate: RFC 5280. */
struct Curl_X509certificate {
  struct Curl_asn1Element certificate;
  struct Curl_asn1Element version;
  struct Curl_asn1Element serialNumber;
  struct Curl_asn1Element signatureAlgorithm;
  struct Curl_asn1Element signature;
  struct Curl_asn1Element issuer;
  struct Curl_asn1Element notBefore;
  struct Curl_asn1Element notAfter;
  struct Curl_asn1Element subject;
  struct Curl_asn1Element subjectPublicKeyInfo;
  struct Curl_asn1Element subjectPublicKeyAlgorithm;
  struct Curl_asn1Element subjectPublicKey;
  struct Curl_asn1Element issuerUniqueID;
  struct Curl_asn1Element subjectUniqueID;
  struct Curl_asn1Element extensions;
};

/*
 * Prototypes.
 */

int Curl_parseX509(struct Curl_X509certificate *cert,
                   const char *beg, const char *end);
CURLcode Curl_extract_certinfo(struct Curl_easy *data, int certnum,
                               const char *beg, const char *end);
CURLcode Curl_verifyhost(struct Curl_easy *data, struct connectdata *conn,
                         const char *beg, const char *end);
#endif /* USE_GSKIT or USE_NSS or USE_GNUTLS or USE_WOLFSSL or USE_SCHANNEL
        * or USE_SECTRANSP */
#endif /* HEADER_CURL_X509ASN1_H */
