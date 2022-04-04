#ifndef HEADER_CURL_ENDIAN_H
#define HEADER_CURL_ENDIAN_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/* Converts a 16-bit integer from little endian */
unsigned short Curl_read16_le(const unsigned char *buf);

/* Converts a 32-bit integer from little endian */
unsigned int Curl_read32_le(const unsigned char *buf);

/* Converts a 16-bit integer from big endian */
unsigned short Curl_read16_be(const unsigned char *buf);

#if (SIZEOF_CURL_OFF_T > 4)
/* Converts a 64-bit integer to little endian */
#if defined(HAVE_LONGLONG)
void Curl_write64_le(const long long value, unsigned char *buffer);
#else
void Curl_write64_le(const __int64 value, unsigned char *buffer);
#endif
#endif

#endif /* HEADER_CURL_ENDIAN_H */
