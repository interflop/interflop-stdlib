

# SYNOPSIS
#
#   AX_INTERFLOP_STDLIB()
#
# DESCRIPTION
#
#   Create --with-interflop-stdlib option to link a backend with 
#   the interflop-stdlib library
#

AC_DEFUN([AX_INTERFLOP_STDLIB], 
[
AC_ARG_WITH([interflop-stdlib],
  AS_HELP_STRING([--with-interflop-stdlib@<:@=DIR@:>@],
    [use interflop-stdlib located in DIR]),
  [with_interflop_stdlib="$withval"],
  [with_interflop_stdlib=yes])

if test "x$with_interflop_stdlib" = "xno"; then
   AC_MSG_ERROR([Could not find interflop-stdlib library])
elif test "x$with_interflop_stdlib" = "xyes"; then
   with_interflop_stdlib_path=$ac_default_prefix
else
   with_interflop_stdlib_path="$with_interflop_stdlib"
fi

AC_DEFINE_UNQUOTED(INTERFLOP_STDLIB_PATH, ["$with_interflop_stdlib_path"], [interflop-stdlib install path])
AC_SUBST(INTERFLOP_STDLIB_PATH, [$with_interflop_stdlib_path])
])

