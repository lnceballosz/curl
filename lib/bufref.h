#ifndef HEADER_CURL_BUFREF_H
#define HEADER_CURL_BUFREF_H

// Copyright (C) 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

/*
 * Generic buffer reference.
 */
struct bufref {
  void (*dtor)(void *);         /* Associated destructor. */
  const unsigned char *ptr;     /* Referenced data buffer. */
  size_t len;                   /* The data size in bytes. */
#ifdef DEBUGBUILD
  int signature;                /* Detect API use mistakes. */
#endif
};


void Curl_bufref_init(struct bufref *br);
void Curl_bufref_set(struct bufref *br, const void *ptr, size_t len,
                     void (*dtor)(void *));
const unsigned char *Curl_bufref_ptr(const struct bufref *br);
size_t Curl_bufref_len(const struct bufref *br);
CURLcode Curl_bufref_memdup(struct bufref *br, const void *ptr, size_t len);
void Curl_bufref_free(struct bufref *br);

#endif
