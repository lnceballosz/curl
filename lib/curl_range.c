// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#include <curl/curl.h>
#include "curl_range.h"
#include "sendf.h"
#include "strtoofft.h"

/* Only include this function if one or more of FTP, FILE are enabled. */
#if !defined(CURL_DISABLE_FTP) || !defined(CURL_DISABLE_FILE)

 /*
  Check if this is a range download, and if so, set the internal variables
  properly.
 */
CURLcode Curl_range(struct Curl_easy *data)
{
  curl_off_t from, to;
  char *ptr;
  char *ptr2;

  if(data->state.use_range && data->state.range) {
    CURLofft from_t;
    CURLofft to_t;
    from_t = curlx_strtoofft(data->state.range, &ptr, 0, &from);
    if(from_t == CURL_OFFT_FLOW)
      return CURLE_RANGE_ERROR;
    while(*ptr && (ISSPACE(*ptr) || (*ptr == '-')))
      ptr++;
    to_t = curlx_strtoofft(ptr, &ptr2, 0, &to);
    if(to_t == CURL_OFFT_FLOW)
      return CURLE_RANGE_ERROR;
    if((to_t == CURL_OFFT_INVAL) && !from_t) {
      /* X - */
      data->state.resume_from = from;
      DEBUGF(infof(data, "RANGE %" CURL_FORMAT_CURL_OFF_T " to end of file",
                   from));
    }
    else if((from_t == CURL_OFFT_INVAL) && !to_t) {
      /* -Y */
      data->req.maxdownload = to;
      data->state.resume_from = -to;
      DEBUGF(infof(data, "RANGE the last %" CURL_FORMAT_CURL_OFF_T " bytes",
                   to));
    }
    else {
      /* X-Y */
      curl_off_t totalsize;

      /* Ensure the range is sensible - to should follow from. */
      if(from > to)
        return CURLE_RANGE_ERROR;

      totalsize = to - from;
      if(totalsize == CURL_OFF_T_MAX)
        return CURLE_RANGE_ERROR;

      data->req.maxdownload = totalsize + 1; /* include last byte */
      data->state.resume_from = from;
      DEBUGF(infof(data, "RANGE from %" CURL_FORMAT_CURL_OFF_T
                   " getting %" CURL_FORMAT_CURL_OFF_T " bytes",
                   from, data->req.maxdownload));
    }
    DEBUGF(infof(data, "range-download from %" CURL_FORMAT_CURL_OFF_T
                 " to %" CURL_FORMAT_CURL_OFF_T ", totally %"
                 CURL_FORMAT_CURL_OFF_T " bytes",
                 from, to, data->req.maxdownload));
  }
  else
    data->req.maxdownload = -1;
  return CURLE_OK;
}

#endif
