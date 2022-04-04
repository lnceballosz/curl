#ifndef HEADER_CURL_KEYLOG_H
#define HEADER_CURL_KEYLOG_H

// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "curl_setup.h"

/*
 * Opens the TLS key log file if requested by the user. The SSLKEYLOGFILE
 * environment variable specifies the output file.
 */
void Curl_tls_keylog_open(void);

/*
 * Closes the TLS key log file if not already.
 */
void Curl_tls_keylog_close(void);

/*
 * Returns true if the user successfully enabled the TLS key log file.
 */
bool Curl_tls_keylog_enabled(void);

/*
 * Appends a key log file entry.
 * Returns true iff the key log file is open and a valid entry was provided.
 */
bool Curl_tls_keylog_write(const char *label,
                           const unsigned char client_random[32],
                           const unsigned char *secret, size_t secretlen);

/*
 * Appends a line to the key log file, ensure it is terminated by a LF.
 * Returns true iff the key log file is open and a valid line was provided.
 */
bool Curl_tls_keylog_write_line(const char *line);

#endif /* HEADER_CURL_KEYLOG_H */
