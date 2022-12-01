lib_LTLIBRARIES = libvprec_tools.la

libvfc_hashmap_la_CFLAGS = -fPIC -fno-stack-protector
if WALL_CFLAGS
libvfc_hashmap_la_CFLAGS += -Wall -Wextra 
endif
libvfc_hashmap_la_SOURCES = \
    vfc_hashmap.h \
    vfc_hashmap.c \
libvfc_hashmap_la_includedir = $(includedir)/
