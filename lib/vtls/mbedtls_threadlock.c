// Copyright (C) 2010, 2011, Hoi-Ho Chan, <hoiho.chan@gmail.com>
// Copyright (C) 2013 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

#if defined(USE_MBEDTLS) &&                                     \
  ((defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)) ||   \
   (defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)))

#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
#  include <pthread.h>
#  define MBEDTLS_MUTEX_T pthread_mutex_t
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
#  include <process.h>
#  define MBEDTLS_MUTEX_T HANDLE
#endif

#include "mbedtls_threadlock.h"
#include "curl_printf.h"
#include "curl_memory.h"
/* The last #include file should be: */
#include "memdebug.h"

/* number of thread locks */
#define NUMT                    2

/* This array will store all of the mutexes available to Mbedtls. */
static MBEDTLS_MUTEX_T *mutex_buf = NULL;

int Curl_mbedtlsthreadlock_thread_setup(void)
{
  int i;

  mutex_buf = calloc(NUMT * sizeof(MBEDTLS_MUTEX_T), 1);
  if(!mutex_buf)
    return 0;     /* error, no number of threads defined */

  for(i = 0;  i < NUMT;  i++) {
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
    if(pthread_mutex_init(&mutex_buf[i], NULL))
      return 0; /* pthread_mutex_init failed */
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
    mutex_buf[i] = CreateMutex(0, FALSE, 0);
    if(mutex_buf[i] == 0)
      return 0;  /* CreateMutex failed */
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
  }

  return 1; /* OK */
}

int Curl_mbedtlsthreadlock_thread_cleanup(void)
{
  int i;

  if(!mutex_buf)
    return 0; /* error, no threads locks defined */

  for(i = 0; i < NUMT; i++) {
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
    if(pthread_mutex_destroy(&mutex_buf[i]))
      return 0; /* pthread_mutex_destroy failed */
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
    if(!CloseHandle(mutex_buf[i]))
      return 0; /* CloseHandle failed */
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
  }
  free(mutex_buf);
  mutex_buf = NULL;

  return 1; /* OK */
}

int Curl_mbedtlsthreadlock_lock_function(int n)
{
  if(n < NUMT) {
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
    if(pthread_mutex_lock(&mutex_buf[n])) {
      DEBUGF(fprintf(stderr,
                     "Error: mbedtlsthreadlock_lock_function failed\n"));
      return 0; /* pthread_mutex_lock failed */
    }
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
    if(WaitForSingleObject(mutex_buf[n], INFINITE) == WAIT_FAILED) {
      DEBUGF(fprintf(stderr,
                     "Error: mbedtlsthreadlock_lock_function failed\n"));
      return 0; /* pthread_mutex_lock failed */
    }
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
  }
  return 1; /* OK */
}

int Curl_mbedtlsthreadlock_unlock_function(int n)
{
  if(n < NUMT) {
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
    if(pthread_mutex_unlock(&mutex_buf[n])) {
      DEBUGF(fprintf(stderr,
                     "Error: mbedtlsthreadlock_unlock_function failed\n"));
      return 0; /* pthread_mutex_unlock failed */
    }
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
    if(!ReleaseMutex(mutex_buf[n])) {
      DEBUGF(fprintf(stderr,
                     "Error: mbedtlsthreadlock_unlock_function failed\n"));
      return 0; /* pthread_mutex_lock failed */
    }
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
  }
  return 1; /* OK */
}

#endif /* USE_MBEDTLS */
