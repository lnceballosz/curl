// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_strdup.h"

#ifndef HAVE_STRDUP
char *strdup(const char *str)
{
  size_t len;
  char *newstr;

  if(!str)
    return (char *)NULL;

  len = strlen(str) + 1;

  newstr = malloc(len);
  if(!newstr)
    return (char *)NULL;

  memcpy(newstr, str, len);
  return newstr;
}
#endif
