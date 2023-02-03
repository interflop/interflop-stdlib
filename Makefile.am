ACLOCAL_AMFLAGS= -I m4
SUBDIRS=rng prng fma hashmap iostream
lib_LTLIBRARIES = libinterflop_stdlib.la
libdir=$(interflop_libdir)

if ENABLE_LTO
LTO_FLAGS = -flto
else
LTO_FLAGS =
endif

if ENABLE_WARNINGS
WARNING_FLAGS = -Wall -Wextra -Wno-varargs
else
WARNING_FLAGS = 
endif

libinterflop_stdlib_la_SOURCES = \
	interflop_stdlib.h \
	interflop_stdlib.c

libinterflop_stdlib_la_CFLAGS = \
	$(LTO_FLAGS) -O3 \
	-fno-stack-protector \
	$(WARNING_FLAGS)
libinterflop_stdlib_la_LDFLAGS = \
	$(LTO_FLAGS) -O3

headersdir=$(interflop_includedir)/interflop
headers_HEADERS=interflop.h interflop_stdlib.h
nobase_headers_HEADERS= \
	iostream/logger.h \
	rng/vfc_rng.h \
	rng/xoroshiro128.h \
	prng/vr_rand.h \
	prng/tinymt64.h \
	prng/xoshiro.hxx \
	fma/interflop_fma.h \
	common/float_const.h \
	common/float_struct.h \
	common/float_utils.h \
	common/generic_builtin.h \
	common/quadmath-imp.h \
	common/options.h \
	hashmap/vfc_hashmap.h

m4dir = $(interflop_datarootdir)
m4_DATA = \
	m4/ax_interflop_stdlib.m4 \
	m4/ax_warnings.m4 \
	m4/ax_lto.m4 \
	m4/ax_intrinsic_fma.m4 \
	m4/ax_interflop_rng.m4

interflop_configdir = $(interflop_bindir)
interflop_config_SCRIPTS = interflop-config-${PACKAGE_VERSION}

interflop-config-${PACKAGE_VERSION}: interflop-config.in
	./automake-expand --config-log config.log --input interflop-config.in --output interflop-config-${PACKAGE_VERSION} && \
	chmod +x interflop-config-${PACKAGE_VERSION}

install-exec-hook: interflop-config-${PACKAGE_VERSION}
	$(MKDIR_P) $(bindir) && \
	ln -sf $(interflop_bindir)/interflop-config-${PACKAGE_VERSION} $(bindir)/interflop-config-${PACKAGE_VERSION} && \
	ln -sf $(interflop_bindir)/interflop-config-${PACKAGE_VERSION} $(bindir)/interflop-config

install-data-hook:
	$(MKDIR_P) $(includedir) && \
	ln -sTf $(interflop_includedir)/interflop $(includedir)/interflop && \
	ln -sTf $(interflop_datarootdir) $(datarootdir)/interflop