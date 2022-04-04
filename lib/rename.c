// Copyright (C) 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "rename.h"

#include "curl_setup.h"

#if (!defined(CURL_DISABLE_HTTP) || !defined(CURL_DISABLE_COOKIES)) || \
  !defined(CURL_DISABLE_ALTSVC)

#include "curl_multibyte.h"
#include "timeval.h"

/* The last 3 #include files should be in this order */
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"

/* return 0 on success, 1 on error */
int Curl_rename(const char *oldpath, const char *newpath)
{
#ifdef WIN32
  /* rename() on Windows doesn't overwrite, so we can't use it here.
     MoveFileEx() will overwrite and is usually atomic, however it fails
     when there are open handles to the file. */
  const int max_wait_ms = 1000;
  struct curltime start = Curl_now();
  TCHAR *tchar_oldpath = curlx_convert_UTF8_to_tchar((char *)oldpath);
  TCHAR *tchar_newpath = curlx_convert_UTF8_to_tchar((char *)newpath);
  for(;;) {
    timediff_t diff;
    if(MoveFileEx(tchar_oldpath, tchar_newpath, MOVEFILE_REPLACE_EXISTING)) {
      curlx_unicodefree(tchar_oldpath);
      curlx_unicodefree(tchar_newpath);
      break;
    }
    diff = Curl_timediff(Curl_now(), start);
    if(diff < 0 || diff > max_wait_ms) {
      curlx_unicodefree(tchar_oldpath);
      curlx_unicodefree(tchar_newpath);
      return 1;
    }
    Sleep(1);
  }
#else
  if(rename(oldpath, newpath))
    return 1;
#endif
  return 0;
}

#endif
