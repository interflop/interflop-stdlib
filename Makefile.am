SUBDIRS=rng prng fma hashmap iostream
lib_LTLIBRARIES = libinterflop_stdlib.la
libdir=$(interflop_libdir)

if LTO_CFLAGS
libinterflop_stdlib_la_CFLAGS = -flto -O3 -fno-stack-protector
libinterflop_stdlib_la_LDFLAGS = -flto -O3
else
libinterflop_stdlib_la_CFLAGS = -O3 -fno-stack-protector
endif
if WALL_CFLAGS
libinterflop_stdlib_la_CFLAGS += -Wall -Wextra -g
endif
libinterflop_stdlib_la_SOURCES = \
	interflop_stdlib.h \
	interflop_stdlib.c

headersdir=$(interflop_includedir)/interflop
headers_HEADERS=interflop.h interflop_stdlib.h
nobase_headers_HEADERS= \
	iostream/logger.h \
	rng/vfc_rng.h \
	rng/xoroshiro128.h \
	prng/vr_rand.h \
	fma/interflop_fma.h \
	common/float_const.h \
	common/float_struct.h \
	common/float_utils.h \
	common/generic_builtin.h \
	common/quadmath-imp.h \
	common/options.h \
	hashmap/vfc_hashmap.h
dist_pkgdata_DATA = ax_interflop_stdlib.m4

interflop_configdir = $(interflop_bindir)
interflop_config_SCRIPTS = interflop-config-${PACKAGE_VERSION}

interflop-config: interflop-config.in
	./automake-expand --config-log config.log --input interflop-config.in --output interflop-config-${PACKAGE_VERSION} && \
	chmod +x interflop-config-${PACKAGE_VERSION}

install-exec-hook: interflop-config
	$(MKDIR_P) $(bindir) && \
	ln -sf $(interflop_bindir)/interflop-config-${PACKAGE_VERSION} $(bindir)/interflop-config-${PACKAGE_VERSION} && \
	ln -sf $(interflop_bindir)/interflop-config-${PACKAGE_VERSION} $(bindir)/interflop-config

install-data-hook:
	$(MKDIR_P) $(includedir) && \
	ln -sTf $(interflop_includedir)/interflop $(includedir)/interflop
