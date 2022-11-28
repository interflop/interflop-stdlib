lib_LTLIBRARIES = libinterflop_rng.la

libinterflop_rng_la_CFLAGS = -fPIC -static -O3
if WALL_CFLAGS
libinterflop_rng_la_CFLAGS += -Wall -Wextra
endif
libinterflop_rng_la_SOURCES = \
    splitmix64.c \
    xoroshiro128.c \
    vfc_rng.c
