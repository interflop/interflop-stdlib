SUBDIRS=rng prng
lib_LTLIBRARIES = libinterflop_stdlib.la
libinterflop_stdlib_la_CFLAGS = -fPIC -fno-stack-protector
if WALL_CFLAGS
libinterflop_stdlib_la_CFLAGS += -Wall -Wextra
endif
libinterflop_stdlib_la_SOURCES = \
    interflop_stdlib.h \
    interflop_stdlib.c

headersdir = $(includedir)/interflop-stdlib
headers_HEADERS=interflop.h interflop_stdlib.h
nobase_headers_HEADERS= \
    iostream/logger.c \
    iostream/logger.h \
    rng/vfc_rng.h \
    prng/vr_rand.h