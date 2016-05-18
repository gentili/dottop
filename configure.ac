#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(dottop, 1.0.0, gentili@mcpnet.ca)
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
                 Makefile
                 display/Makefile
                 procevents/Makefile
                 dtop/Makefile
                 ])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_11

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lncurses':
#AC_CHECK_LIB([ncurses], [main], [], AC_MSG_ERROR([Missing required library]))
# FIXME: Replace `main' with a function in `-lprocps':
#AC_CHECK_LIB([procps], [main], [], AC_MSG_ERROR([Missing required library]))
AC_CHECK_LIB([pthread], [pthread_create], [], AC_MSG_ERROR([Missing required library]))
AC_CHECK_LIB([SDL2_ttf], [TTF_Init], [], AC_MSG_ERROR([Missing required library]))

# SDL2 specific setup
dnl Check for SDL2
SDL_VERSION=2
AM_PATH_SDL2($SDL_VERSION,
            :,
            AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
)
#CFLAGS="$CFLAGS $SDL_CFLAGS"
#LIBS="$LIBS $SDL_LIBS"

# Checks for header files.
AC_CHECK_HEADERS([string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
#AC_CHECK_FUNCS([floor gettimeofday memset])

AC_OUTPUT
