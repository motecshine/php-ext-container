dnl $Id$
dnl config.m4 for extension container

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(container, for container support,
dnl Make sure that the comment is aligned:
dnl [  --with-container             Include container support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(container, whether to enable container support,
dnl Make sure that the comment is aligned:
[  --enable-container           Enable container support])

if test "$PHP_CONTAINER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-container -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/container.h"  # you most likely want to change this
  dnl if test -r $PHP_CONTAINER/$SEARCH_FOR; then # path given as parameter
  dnl   CONTAINER_DIR=$PHP_CONTAINER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for container files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CONTAINER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CONTAINER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the container distribution])
  dnl fi

  dnl # --with-container -> add include path
  dnl PHP_ADD_INCLUDE($CONTAINER_DIR/include)

  dnl # --with-container -> check for lib and symbol presence
  dnl LIBNAME=container # you may want to change this
  dnl LIBSYMBOL=container # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CONTAINER_DIR/$PHP_LIBDIR, CONTAINER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_CONTAINERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong container lib version or lib not found])
  dnl ],[
  dnl   -L$CONTAINER_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(CONTAINER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(
    container, 
    container.c    \
    src/PSRInterface/PSRContainerInterface.c \
    , 
    $ext_shared,, 
    -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
