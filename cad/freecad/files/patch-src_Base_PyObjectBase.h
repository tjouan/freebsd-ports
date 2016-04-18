--- src/Base/PyObjectBase.h.orig	2016-04-07 01:39:34 UTC
+++ src/Base/PyObjectBase.h
@@ -36,7 +36,7 @@
 // needed header
 #undef slots
 #include <Python.h>
-#ifdef FC_OS_MACOSX
+#if defined(FC_OS_MACOSX) || defined(FC_OS_BSD)
 #undef toupper
 #undef tolower
 #undef isupper
