# Copyright (C) 1998 - 2022, Daniel Stenberg, <daniel@haxx.se>, et al.
# SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
#
# SPDX-License-Identifier: curl

AUTOMAKE_OPTIONS = foreign nostdinc

EXTRA_DIST = README.md Makefile.example Makefile.inc Makefile.m32 \
  makefile.dj $(COMPLICATED_EXAMPLES) .checksrc

# Specify our include paths here, and do it relative to $(top_srcdir) and
# $(top_builddir), to ensure that these paths which belong to the library
# being currently built and tested are searched before the library which
# might possibly already be installed in the system.
#
# $(top_srcdir)/include is for libcurl's external include files

AM_CPPFLAGS = -I$(top_srcdir)/include

LIBDIR = $(top_builddir)/lib

# Avoid libcurl obsolete stuff
AM_CPPFLAGS += -DCURL_NO_OLDIES

if USE_CPPFLAG_CURL_STATICLIB
AM_CPPFLAGS += -DCURL_STATICLIB
endif

# Prevent LIBS from being used for all link targets
LIBS = $(BLANK_AT_MAKETIME)

# Dependencies
if USE_EXPLICIT_LIB_DEPS
LDADD = $(LIBDIR)/libcurl.la @LIBCURL_LIBS@
else
LDADD = $(LIBDIR)/libcurl.la
endif

# This might hold -Werror
CFLAGS += @CURL_CFLAG_EXTRAS@

# Makefile.inc provides the check_PROGRAMS and COMPLICATED_EXAMPLES defines
include Makefile.inc

all: $(check_PROGRAMS)

CHECKSRC = $(CS_$(V))
CS_0 = @echo "  RUN     " $@;
CS_1 =
CS_ = $(CS_0)

checksrc:
	$(CHECKSRC)(@PERL@ $(top_srcdir)/scripts/checksrc.pl -D$(srcdir) $(srcdir)/*.c)
