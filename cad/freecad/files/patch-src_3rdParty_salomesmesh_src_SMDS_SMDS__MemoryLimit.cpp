--- src/3rdParty/salomesmesh/src/SMDS/SMDS_MemoryLimit.cpp.orig	2016-04-07 01:39:34 UTC
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_MemoryLimit.cpp
@@ -27,51 +27,11 @@
 // This is not done inside a function of SALOME because allocated memory is not returned
 // to the system. (PAL16631)
 //
-#ifndef WIN32
-#if !(defined(__MACH__) && defined(__APPLE__))
-#include <sys/sysinfo.h>
-#endif
-#endif
-
 #ifdef _DEBUG_
 #include <iostream>
 #endif
 
 int main (int argc, char ** argv)
 {
-#if (defined(__MACH__) && defined(__APPLE__))
-	//do nothing
-#else
-  // To better understand what is going on here, consult bug [SALOME platform 0019911]
-#ifndef WIN32
-  struct sysinfo si;
-  int err = sysinfo( &si );
-  if ( err )
-    return -1;
-  unsigned long freeRamKb = ( si.freeram  * si.mem_unit ) / 1024;
-
-  // totat RAM size in Gb, float is in order not to have 1 instead of 1.9
-  float totalramGb = float( si.totalram * si.mem_unit ) / 1024 / 1024 / 1024;
-
-  // nb Kbites to allocate at one step. Small nb leads to hung up
-  const int stepKb = int( 5 * totalramGb );
-
-  unsigned long nbSteps = freeRamKb / stepKb * 2;
-  try {
-    while ( nbSteps-- ) {
-      new char[stepKb*1024];
-      err = sysinfo( &si );
-      if ( !err )
-        freeRamKb = ( si.freeram  * si.mem_unit ) / 1024;
-    }
-  } catch (...) {}
-
-// #ifdef _DEBUG_
-//   std::cout << freeRamKb / 1024 << std::endl;
-// #endif
-  return freeRamKb / 1024;
-#endif
-#endif
-
   return -1;
 }
