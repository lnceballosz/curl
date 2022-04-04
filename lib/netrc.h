#ifndef HEADER_CURL_NETRC_H
#define HEADER_CURL_NETRC_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"
#ifndef CURL_DISABLE_NETRC

/* returns -1 on failure, 0 if the host is found, 1 is the host isn't found */
int Curl_parsenetrc(const char *host,
                    char **loginp,
                    char **passwordp,
                    bool *login_changed,
                    bool *password_changed,
                    char *filename);
  /* Assume: (*passwordp)[0]=0, host[0] != 0.
   * If (*loginp)[0] = 0, search for login and password within a machine
   * section in the netrc.
   * If (*loginp)[0] != 0, search for password within machine and login.
   */
#else
/* disabled */
#define Curl_parsenetrc(a,b,c,d,e,f) 1
#endif

#endif /* HEADER_CURL_NETRC_H */
