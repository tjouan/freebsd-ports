--- src/Main/MainGui.cpp.orig	2016-04-07 01:39:34 UTC
+++ src/Main/MainGui.cpp
@@ -21,13 +21,15 @@
  *                                                                         *
  *   Juergen Riegel 2002                                                   *
  ***************************************************************************/
+#include "Python.h"
+
 #include <FCConfig.h>
 
 #ifdef _PreComp_
 #   undef _PreComp_
 #endif
 
-#ifdef FC_OS_LINUX
+#if defined(FC_OS_LINUX) || defined(FC_OS_BSD)
 #   include <unistd.h>
 #endif
 
