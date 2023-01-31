AC_INIT([interflop-stdlib],[0.0.1],[interflop.project@gmail.com])
AM_SILENT_RULES([yes])
AC_CONFIG_AUX_DIR(autoconf)
AM_INIT_AUTOMAKE([subdir-objects -Wall -Werror foreign])
AC_CONFIG_MACRO_DIRS([m4])
AC_PROG_CC
AC_PROG_CXX
AM_PROG_AR
AC_CONFIG_HEADERS([config.h])
LT_INIT
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_SUBST(INTERFLOP_DIRNAME, interflop-${PACKAGE_VERSION})

if test "x$prefix" != "xNONE"; then
  AC_SUBST(interflop_prefix, ${prefix}/lib/${INTERFLOP_DIRNAME})
else
  AC_SUBST(interflop_prefix, ${ac_default_prefix}/lib/${INTERFLOP_DIRNAME})
fi

AC_SUBST(interflop_includedir, $interflop_prefix/include)
AC_SUBST(interflop_bindir, $interflop_prefix/bin)
AC_SUBST(interflop_libdir, $interflop_prefix/lib)
AC_SUBST(interflop_datarootdir, $interflop_prefix/share)

AX_WARNINGS()
AX_LTO()
AX_INTRINSIC_FMA()

AC_CONFIG_FILES([
 Makefile
 rng/Makefile
 prng/Makefile
 fma/Makefile
 hashmap/Makefile
 iostream/Makefile
])
AC_OUTPUT