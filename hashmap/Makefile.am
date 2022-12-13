lib_LTLIBRARIES = libinterflop_hashmap.la

libinterflop_hashmap_la_CFLAGS = -flto -O3 -fno-stack-protector -I$(top_srcdir)/..
libinterflop_hashmap_la_LDFLAGS = -flto -O3
if WALL_CFLAGS
libinterflop_hashmap_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_hashmap_la_SOURCES = \
    vfc_hashmap.h \
    vfc_hashmap.c 
libinterflop_hashmap_la_includedir = $(includedir)/
