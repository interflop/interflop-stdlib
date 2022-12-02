lib_LTLIBRARIES = libinterflop_prng.la
 
libinterflop_prng_la_CFLAGS = -fPIC -O3 -fno-stack-protector
libinterflop_prng_la_CPPFLAGS = -fPIC -O3 -fno-stack-protector
if WALL_CFLAGS
libinterflop_prng_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_prng_la_SOURCES = \
    xoshiro.cxx \
    tinymt64.c 
