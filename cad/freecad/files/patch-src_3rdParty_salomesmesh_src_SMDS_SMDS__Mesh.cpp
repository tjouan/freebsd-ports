--- src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp.orig	2016-04-07 01:39:34 UTC
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp
@@ -42,12 +42,6 @@
 #include <iterator>
 using namespace std;
 
-#ifndef WIN32
-#if !(defined(__MACH__) && defined(__APPLE__))
-#include <sys/sysinfo.h>
-#endif
-#endif
-
 // number of added entitis to check memory after
 #define CHECKMEMORY_INTERVAL 1000
 
@@ -61,49 +55,7 @@ using namespace std;
 
 int SMDS_Mesh::CheckMemory(const bool doNotRaise) throw (std::bad_alloc)
 {
-#if (defined(__MACH__) && defined(__APPLE__))
 	return 1000;
-#else	
-#ifndef WIN32
-  struct sysinfo si;
-  int err = sysinfo( &si );
-  if ( err )
-    return -1;
-
-  static int limit = -1;
-  if ( limit < 0 ) {
-    int status = system("SMDS_MemoryLimit"); // it returns lower limit of free RAM
-    if (status >= 0 ) {
-      limit = WEXITSTATUS(status);
-    }
-    if ( limit < 20 )
-      limit = 20;
-    else
-      limit = int( limit * 1.5 );
-#ifdef _DEBUG_
-    MESSAGE ( "SMDS_Mesh::CheckMemory() memory limit = " << limit << " MB" );
-#endif
-  }
-
-  const unsigned long Mbyte = 1024 * 1024;
-  // compute separately to avoid overflow
-  int freeMb =
-    ( si.freeram  * si.mem_unit ) / Mbyte +
-    ( si.freeswap * si.mem_unit ) / Mbyte;
-
-  if ( freeMb > limit )
-    return freeMb - limit;
-
-  if ( doNotRaise )
-    return 0;
-#ifdef _DEBUG_
-  MESSAGE ("SMDS_Mesh::CheckMemory() throws as free memory too low: " << freeMb <<" MB" );
-#endif
-  throw std::bad_alloc();
-#else
-  return -1;
-#endif
-#endif
 }
 
 ///////////////////////////////////////////////////////////////////////////////
