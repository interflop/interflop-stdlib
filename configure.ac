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

# --enable-wall
AC_ARG_ENABLE(wall, AS_HELP_STRING([--enable-wall],[Enable -Wall compilation flag]), [WALL_CFLAGS="yes"])
AM_CONDITIONAL([WALL_CFLAGS], [test "x$WALL_CFLAGS" = "xyes"])
if test "x$WALL_CFLAGS" = "xyes"; then
   AC_DEFINE([WALL_CFLAGS], [],  ["Enable -Wall compilation flag"])
   AC_MSG_NOTICE([-Wall is set])
fi

# --enable-lto
AC_ARG_ENABLE(lto, AS_HELP_STRING([--enable-lto],[Enable Link Time Optimizer]), [LTO_CFLAGS="yes"])
AM_CONDITIONAL([LTO_CFLAGS], [test "x$LTO_CFLAGS" = "xyes"])
if test "x$LTO_CFLAGS" = "xyes"; then
   AC_DEFINE([LTO_CFLAGS], [],  ["Enable Link Time Optimizer"])
   AC_MSG_NOTICE([Link Time Optimizer is set])
fi

# --enable-intrinsic-fma
# Taken from configure.ac Verrou
AC_CACHE_CHECK([intrinsic fma], interflop_cv_intrinsic_fma,
  [AC_ARG_ENABLE(intrinsic-fma,
    AS_HELP_STRING([--enable-intrinsic-fma],[enables interflop-stdlib to use intrinsic fma]),
    [interflop_cv_intrinsic_fma=$enableval],
    [interflop_cv_intrinsic_fma=yes])])

if test "$interflop_cv_intrinsic_fma" != no; then
  # Check for fmaintrin.h
  AC_LANG_PUSH(C++)
  CXXFLAGS="$safe_CXXFLAGS -mfma"
  AC_MSG_CHECKING([for fmaintrin.h ])
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
      #include <immintrin.h>
      #include <stdlib.h>
]], [[
       double a,b,c,d;
      __m128d ai,bi,ci,di;
      ai = _mm_load_sd(&a);
      bi = _mm_load_sd(&b);
      ci = _mm_load_sd(&c);
      di = _mm_fmadd_sd(ai,bi,ci);
      d  = _mm_cvtsd_f64(di);
      return EXIT_SUCCESS;
    ]])],
    [
      AC_MSG_RESULT([yes])
      interflop_cv_intrinsic_fma=yes
    ],[
      AC_MSG_RESULT([no])
      AC_MSG_NOTICE([--enable-intrinsic-fma=no was given. Use soft-fma])
      interflop_cv_intrinsic_fma=no
  ])
  AC_LANG_POP(C++)
else
   AC_MSG_NOTICE([--enable-intrinsic-fma=no was given. Use soft-fma])
   interflop_cv_intrinsic_fma=no
fi

AM_CONDITIONAL([HAVE_FMA_INTRINSIC], [test "x$interflop_cv_intrinsic_fma" == "xyes"],[])
AC_SUBST(interflop_cv_intrinsic_fma)

AC_CONFIG_FILES([
 Makefile
 rng/Makefile
 prng/Makefile
 fma/Makefile
 hashmap/Makefile
 iostream/Makefile
])
AC_OUTPUT