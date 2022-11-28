SUBDIRS=rng prng
lib_LTLIBRARIES = libinterflop_stdlib.la
libinterflop_stdlib_la_CFLAGS = -fPIC -fno-stack-protector
if WALL_CFLAGS
libinterflop_stdlib_la_CFLAGS += -Wall -Wextra
endif
libinterflop_stdlib_la_SOURCES = \
    interflop_stdlib.h \
    interflop_stdlib.c

include_HEADERS=interflop.h interflop_stdlib.h