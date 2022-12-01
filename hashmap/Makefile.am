lib_LTLIBRARIES = libinterflop_hashmap.la

libinterflop_hashmap_la_CFLAGS = -fPIC -fno-stack-protector -I$(top_srcdir)/..
if WALL_CFLAGS
libinterflop_hashmap_la_CFLAGS += -Wall -Wextra 
endif
libinterflop_hashmap_la_SOURCES = \
    vfc_hashmap.h \
    vfc_hashmap.c 
libinterflop_hashmap_la_includedir = $(includedir)/
