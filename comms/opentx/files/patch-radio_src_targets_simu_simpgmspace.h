--- radio/src/targets/simu/simpgmspace.h.orig	2016-03-26 16:35:11 UTC
+++ radio/src/targets/simu/simpgmspace.h
@@ -37,6 +37,11 @@
 #ifndef simpgmspace_h
 #define simpgmspace_h
 
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/time.h>
+#include <semaphore.h>
+
 extern int g_snapshot_idx;
 
 #ifndef __GNUC__
