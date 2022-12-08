SUBDIRS=rng prng fma hashmap
lib_LTLIBRARIES = libinterflop_stdlib.la
libinterflop_stdlib_la_CFLAGS = -O3 -fno-stack-protector
if WALL_CFLAGS
libinterflop_stdlib_la_CFLAGS += -Wall -Wextra -g
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
    prng/vr_rand.h \
    fma/interflop_fma.h \
    common/float_const.h \
    common/float_struct.h \
    common/float_utils.h \
    common/generic_builtin.h \
    common/quadmath-imp.h \
    common/options.c \
    common/options.h \
    hashmap/vfc_hashmap.h \
    hashmap/vfc_hashmap.c