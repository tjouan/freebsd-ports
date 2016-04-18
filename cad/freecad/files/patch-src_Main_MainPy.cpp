--- src/Main/MainPy.cpp.orig	2016-04-07 01:39:34 UTC
+++ src/Main/MainPy.cpp
@@ -27,7 +27,7 @@
 # undef _PreComp_
 #endif
 
-#ifdef FC_OS_LINUX
+#if defined(FC_OS_LINUX) || defined(FC_OS_BSD)
 #	include <unistd.h>
 #endif
 
@@ -71,7 +71,7 @@ BOOL APIENTRY DllMain(HANDLE hModule, DW
 
     return true;
 }
-#elif defined(FC_OS_LINUX)
+#elif defined(FC_OS_LINUX) || defined(FC_OS_BSD)
 # ifndef GNU_SOURCE
 #   define GNU_SOURCE
 # endif
@@ -111,7 +111,7 @@ extern "C"
         argv[0] = (char*)malloc(MAX_PATH);
         strncpy(argv[0],szFileName,MAX_PATH);
         argv[0][MAX_PATH-1] = '\0'; // ensure null termination
-#elif defined(FC_OS_LINUX)
+#elif defined(FC_OS_LINUX) || defined(FC_OS_BSD)
         putenv("LANG=C");
         putenv("LC_ALL=C");
         // get whole path of the library
