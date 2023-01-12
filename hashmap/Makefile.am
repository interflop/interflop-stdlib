lib_LTLIBRARIES = libinterflop_hashmap.la

if LTO_CFLAGS
libinterflop_hashmap_la_CFLAGS = -flto -O3 -fno-stack-protector -I$(top_srcdir)/..
libinterflop_hashmap_la_LDFLAGS = -flto -O3
else
libinterflop_hashmap_la_CFLAGS = -O3 -fno-stack-protector -I$(top_srcdir)/..
endif
if WALL_CFLAGS
libinterflop_hashmap_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_hashmap_la_SOURCES = \
    vfc_hashmap.h \
    vfc_hashmap.c 
libinterflop_hashmap_la_includedir = $(includedir)/
