// Copyright (C) 2015 - 2022, Steve Holme, <steve_holme@hotmail.com>.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(USE_CURL_NTLM_CORE) && !defined(USE_WOLFSSL) && \
    (defined(USE_GNUTLS) || \
     defined(USE_NSS) || \
     defined(USE_SECTRANSP) || \
     defined(USE_OS400CRYPTO) || \
     defined(USE_WIN32_CRYPTO))

#include "curl_des.h"

/*
 * Curl_des_set_odd_parity()
 *
 * This is used to apply odd parity to the given byte array. It is typically
 * used by when a cryptography engines doesn't have it's own version.
 *
 * The function is a port of the Java based oddParity() function over at:
 *
 * https://davenport.sourceforge.io/ntlm.html
 *
 * Parameters:
 *
 * bytes       [in/out] - The data whose parity bits are to be adjusted for
 *                        odd parity.
 * len         [out]    - The length of the data.
 */
void Curl_des_set_odd_parity(unsigned char *bytes, size_t len)
{
  size_t i;

  for(i = 0; i < len; i++) {
    unsigned char b = bytes[i];

    bool needs_parity = (((b >> 7) ^ (b >> 6) ^ (b >> 5) ^
                          (b >> 4) ^ (b >> 3) ^ (b >> 2) ^
                          (b >> 1)) & 0x01) == 0;

    if(needs_parity)
      bytes[i] |= 0x01;
    else
      bytes[i] &= 0xfe;
  }
}

#endif
