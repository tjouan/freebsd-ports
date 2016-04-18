--- src/Base/TimeInfo.cpp.orig	2016-04-07 01:39:34 UTC
+++ src/Base/TimeInfo.cpp
@@ -60,7 +60,14 @@ void TimeInfo::setCurrent(void)
 #if defined (_MSC_VER)
     _ftime( &timebuffer );
 #elif defined(__GNUC__)
-    ftime( &timebuffer );
+    struct timezone tz;
+    struct timeval t;
+    if (gettimeofday(&t, &tz) < 0)
+      ;
+    timebuffer.millitm = t.tv_usec / 1000;
+    timebuffer.time = t.tv_sec;
+    timebuffer.timezone = tz.tz_minuteswest;
+    timebuffer.dstflag = tz.tz_dsttime;
 #endif
 }
 
