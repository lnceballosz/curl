#ifndef HEADER_CURL_LDAP_H
#define HEADER_CURL_LDAP_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifndef CURL_DISABLE_LDAP
extern const struct Curl_handler Curl_handler_ldap;

#if !defined(CURL_DISABLE_LDAPS) && \
    ((defined(USE_OPENLDAP) && defined(USE_SSL)) || \
     (!defined(USE_OPENLDAP) && defined(HAVE_LDAP_SSL)))
extern const struct Curl_handler Curl_handler_ldaps;
#endif

#endif
#endif /* HEADER_CURL_LDAP_H */
