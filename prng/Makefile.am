lib_LTLIBRARIES = libinterflop_prng.la
 
if LTO_CFLAGS
libinterflop_prng_la_CFLAGS = -flto -O3 -fno-stack-protector
libinterflop_prng_la_CPPFLAGS = -flto -O3 -fno-stack-protector
libinterflop_prng_la_LDFLAGS = -flto -O3
else
libinterflop_prng_la_CFLAGS = -O3 -fno-stack-protector
libinterflop_prng_la_CPPFLAGS = -O3 -fno-stack-protector
endif
if WALL_CFLAGS
libinterflop_prng_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_prng_la_SOURCES = \
    xoshiro.cxx \
    tinymt64.c 
