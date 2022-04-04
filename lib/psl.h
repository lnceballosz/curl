#ifndef HEADER_PSL_H
#define HEADER_PSL_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifdef USE_LIBPSL
#include <libpsl.h>

#define PSL_TTL (72 * 3600)     /* PSL time to live before a refresh. */

struct PslCache {
  const psl_ctx_t *psl; /* The PSL. */
  time_t expires; /* Time this PSL life expires. */
  bool dynamic; /* PSL should be released when no longer needed. */
};

const psl_ctx_t *Curl_psl_use(struct Curl_easy *easy);
void Curl_psl_release(struct Curl_easy *easy);
void Curl_psl_destroy(struct PslCache *pslcache);

#else

#define Curl_psl_use(easy) NULL
#define Curl_psl_release(easy)
#define Curl_psl_destroy(pslcache)

#endif /* USE_LIBPSL */
#endif /* HEADER_PSL_H */
