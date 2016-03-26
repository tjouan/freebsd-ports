--- companion/src/mountlist.cpp.orig	2016-03-26 14:54:42 UTC
+++ companion/src/mountlist.cpp
@@ -455,7 +455,7 @@ read_file_system_list (bool need_fs_type
         me = (mount_entry *) malloc (sizeof *me);
         me->me_devname = strdup (fsp->f_mntfromname);
         me->me_mountdir = strdup (fsp->f_mntonname);
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
         me->me_type = fsp->f_fstypename;
 #else
         me->me_type = fsp->fs_typename;
