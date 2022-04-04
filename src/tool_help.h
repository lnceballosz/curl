#ifndef HEADER_CURL_TOOL_HELP_H
#define HEADER_CURL_TOOL_HELP_H

// Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

void tool_help(char *category);
void tool_list_engines(void);
void tool_version_info(void);

typedef unsigned int curlhelp_t;

struct helptxt {
  const char *opt;
  const char *desc;
  curlhelp_t categories;
};

/*
 * The bitmask output is generated with the following command
 ------------------------------------------------------------
  cd $srcroot/docs/cmdline-opts
  ./gen.pl listcats *.d
 */

#define CURLHELP_HIDDEN 1u << 0u
#define CURLHELP_AUTH 1u << 1u
#define CURLHELP_CONNECTION 1u << 2u
#define CURLHELP_CURL 1u << 3u
#define CURLHELP_DNS 1u << 4u
#define CURLHELP_FILE 1u << 5u
#define CURLHELP_FTP 1u << 6u
#define CURLHELP_HTTP 1u << 7u
#define CURLHELP_IMAP 1u << 8u
#define CURLHELP_IMPORTANT 1u << 9u
#define CURLHELP_MISC 1u << 10u
#define CURLHELP_OUTPUT 1u << 11u
#define CURLHELP_POP3 1u << 12u
#define CURLHELP_POST 1u << 13u
#define CURLHELP_PROXY 1u << 14u
#define CURLHELP_SCP 1u << 15u
#define CURLHELP_SFTP 1u << 16u
#define CURLHELP_SMTP 1u << 17u
#define CURLHELP_SSH 1u << 18u
#define CURLHELP_TELNET 1u << 19u
#define CURLHELP_TFTP 1u << 20u
#define CURLHELP_TLS 1u << 21u
#define CURLHELP_UPLOAD 1u << 22u
#define CURLHELP_VERBOSE 1u << 23u

extern const struct helptxt helptext[];

#endif /* HEADER_CURL_TOOL_HELP_H */
