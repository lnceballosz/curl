#ifndef HEADER_CURL_MBEDTLS_THREADLOCK_H
#define HEADER_CURL_MBEDTLS_THREADLOCK_H

// Copyright (C) 2010, Hoi-Ho Chan, <hoiho.chan@gmail.com>
// Copyright (C) 2013 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#ifdef USE_MBEDTLS

#if (defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)) || \
    (defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H))

int Curl_mbedtlsthreadlock_thread_setup(void);
int Curl_mbedtlsthreadlock_thread_cleanup(void);
int Curl_mbedtlsthreadlock_lock_function(int n);
int Curl_mbedtlsthreadlock_unlock_function(int n);

#else

#define Curl_mbedtlsthreadlock_thread_setup() 1
#define Curl_mbedtlsthreadlock_thread_cleanup() 1
#define Curl_mbedtlsthreadlock_lock_function(x) 1
#define Curl_mbedtlsthreadlock_unlock_function(x) 1

#endif /* USE_THREADS_POSIX || USE_THREADS_WIN32 */

#endif /* USE_MBEDTLS */

#endif /* HEADER_CURL_MBEDTLS_THREADLOCK_H */
