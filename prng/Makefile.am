noinst_LTLIBRARIES = libinterflop_prng.la
 
libinterflop_prng_la_CFLAGS = -fPIC -static -O3
if WALL_CFLAGS
libinterflop_prng_la_CFLAGS += -Wall -Wextra
endif
libinterflop_prng_la_SOURCES = \
    xoshiro.cxx \
    xoshiro.hxx \
    tinymt64.c \
    tinymt64.h
