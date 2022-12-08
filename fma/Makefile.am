lib_LTLIBRARIES = libinterflop_fma.la

libinterflop_fma_la_CFLAGS = -Og -fno-stack-protector -I$(top_srcdir)/..
if WALL_CFLAGS
libinterflop_fma_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_fma_la_SOURCES = \
    fmaqApproc.h \
    fmaqApprox.c 
library_includedir = $(includedir)/
