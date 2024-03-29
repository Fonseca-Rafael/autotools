#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Jupiter], [1.0], [jupiter-bugs@example.org])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

AC_ARG_ENABLE([async-exec], [AS_HELP_STRING([--disable-async-exec],
              [disable asynchronous execution @<:@default: no@:>])],
              [async_exec=${enableval}],
              [async_exec=yes])

# Checks for programs.
AC_PROG_CC
#_DEBUG_START_
#AC_CHECK_PROG([bash_var], [bash], [yes], [no],,[/usr/sbin/bash])
#_DEBUG_END_
AC_PROG_INSTALL

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for libraries.
if test "x${async_exec}" = xyes; then
    have_pthreads=no
    AC_SEARCH_LIBS([pthread_create], [pthread], [have_pthreads=yes])

    if test "x${have_pthreads}" = xyes; then
        AC_CHECK_HEADERS([pthread.h],[], [have_pthreads=no])
    fi

    if test "x${have_pthreads}" = xno; then
        AC_MSG_WARN([
    ---------------------------------
    Unable to find pthreads on this system.
    Building a single-threaded version.
    ---------------------------------])
        async_exec=no
    fi
fi

if test "x${async_exec}" = xyes; then
    AC_DEFINE([ASYNC_EXEC], 1, [async execution enabled])
fi


# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

echo \
"--------------------------------------------------------------

${PACKAGE_NAME} Version ${PACKAGE_VERSION}

Prefix: '${prefix}'.
Compiler: '${CC} ${CFLAGS} ${CPPFLAGS}'

Package features:
  Async Execution: ${async_exec}

Now type 'make @<:@<target>@:>@'
  where the optional <target> is:
    all                 - build all binaries
    install             - install everything

--------------------------------------------------------------"

