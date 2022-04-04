// Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#include "tool_setup.h"

#if defined(NETWARE)

#ifdef NETWARE
#  ifdef __NOVELL_LIBC__
#    include <screen.h>
#  else
#    include <nwconio.h>
#  endif
#endif

#include "tool_panykey.h"

#include "memdebug.h" /* keep this as LAST include */

void tool_pressanykey(void)
{
#if defined(NETWARE)
  pressanykey();
#endif
}

#endif /* NETWARE */
