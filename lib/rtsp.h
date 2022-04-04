#ifndef HEADER_CURL_RTSP_H
#define HEADER_CURL_RTSP_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifdef USE_HYPER
#define CURL_DISABLE_RTSP 1
#endif

#ifndef CURL_DISABLE_RTSP

extern const struct Curl_handler Curl_handler_rtsp;

CURLcode Curl_rtsp_parseheader(struct Curl_easy *data, char *header);

#else
/* disabled */
#define Curl_rtsp_parseheader(x,y) CURLE_NOT_BUILT_IN

#endif /* CURL_DISABLE_RTSP */

/*
 * RTSP Connection data
 *
 * Currently, only used for tracking incomplete RTP data reads
 */
struct rtsp_conn {
  char *rtp_buf;
  ssize_t rtp_bufsize;
  int rtp_channel;
};

/****************************************************************************
 * RTSP unique setup
 ***************************************************************************/
struct RTSP {
  /*
   * http_wrapper MUST be the first element of this structure for the wrap
   * logic to work. In this way, we get a cheap polymorphism because
   * &(data->state.proto.rtsp) == &(data->state.proto.http) per the C spec
   *
   * HTTP functions can safely treat this as an HTTP struct, but RTSP aware
   * functions can also index into the later elements.
   */
  struct HTTP http_wrapper; /*wrap HTTP to do the heavy lifting */

  long CSeq_sent; /* CSeq of this request */
  long CSeq_recv; /* CSeq received */
};


#endif /* HEADER_CURL_RTSP_H */
