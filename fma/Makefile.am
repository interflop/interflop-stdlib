lib_LTLIBRARIES = libinterflop_fma.la
libdir=$(interflop_libdir)

if LTO_CFLAGS
libinterflop_fma_la_CXXFLAGS = -flto -O3 -fno-stack-protector -I../$(top_srcdir)
libinterflop_fma_la_CFLAGS = -flto -O3 -fno-stack-protector -I../$(top_srcdir)
libinterflop_fma_la_LDFLAGS = -flto -O3
else
libinterflop_fma_la_CXXFLAGS = -O3 -fno-stack-protector -I../$(top_srcdir)
libinterflop_fma_la_CFLAGS = -O3 -fno-stack-protector -I../$(top_srcdir)
endif
if HAVE_FMA_INTRINSIC
libinterflop_fma_la_CXXFLAGS += -DHAVE_FMA_INTRINSIC
libinterflop_fma_la_CFLAGS += -DHAVE_FMA_INTRINSIC
endif
if WALL_CFLAGS
libinterflop_fma_la_CXXFLAGS += -Wall -Wextra -g
libinterflop_fma_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_fma_la_SOURCES = \
    fmaqApprox.c \
    interflop_fma.cxx
library_includedir = $(includedir)/
