--- radio/src/targets/simu/simpgmspace.cpp.orig	2016-03-26 17:07:42 UTC
+++ radio/src/targets/simu/simpgmspace.cpp
@@ -760,7 +760,7 @@ char *findTrueFileName(const char *path)
       for (;;) {
         struct simu::dirent * res = simu::readdir(dir);
         if (res == 0) break;
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
         if ((res->d_type == DT_REG) || (res->d_type == DT_LNK)) {
 #else
         if ((res->d_type == simu::DT_REG) || (res->d_type == simu::DT_LNK)) {
@@ -911,7 +911,7 @@ FRESULT f_readdir (DIR * rep, FILINFO * 
   simu::dirent * ent = simu::readdir((simu::DIR *)rep->fs);
   if (!ent) return FR_NO_FILE;
 
-#if defined(WIN32) || !defined(__GNUC__) || defined(__APPLE__)
+#if defined(WIN32) || !defined(__GNUC__) || defined(__APPLE__) || defined(__FreeBSD__)
   fil->fattrib = (ent->d_type == DT_DIR ? AM_DIR : 0);
 #else
   if (ent->d_type == simu::DT_UNKNOWN) {
