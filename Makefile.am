SUBDIRS=rng prng
lib_LTLIBRARIES = libinterflop_stdlib.la
libinterflop_stdlib_la_CFLAGS = -fPIC -static -nostdlib -fno-stack-protector
if WALL_CFLAGS
libinterflop_stdlib_la_CFLAGS += -fPIC -static   -fno-stack-protector
endif
libinterflop_stdlib_la_SOURCES = \
    interflop_stdlib.h \
    interflop_stdlib.c

include_HEADERS=interflop_stdlib.h