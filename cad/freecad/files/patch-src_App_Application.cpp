--- src/App/Application.cpp.orig	2016-04-24 09:20:18 UTC
+++ src/App/Application.cpp
@@ -2069,17 +2069,7 @@ std::string Application::FindHomePath(co
             absPath = path;
     }
     else {
-        // Find the path of the executable. Theoretically, there could  occur a
-        // race condition when using readlink, but we only use  this method to
-        // get the absolute path of the executable to compute the actual home
-        // path. In the worst case we simply get q wrong path and FreeCAD is not
-        // able to load its modules.
-        char resolved[PATH_MAX];
-        int nchars = readlink("/proc/self/exe", resolved, PATH_MAX);
-        if (nchars < 0 || nchars >= PATH_MAX)
-            throw Base::Exception("Cannot determine the absolute path of the executable");
-        resolved[nchars] = '\0'; // enfore null termination
-        absPath = resolved;
+        absPath = "/usr/local/bin/FreeCAD";
     }
 
     // should be an absolute path now
