--- source/savepng.c.orig
+++ source/savepng.c
@@ -203,7 +203,7 @@
 	goto Error;
 
     /* Set error handling. */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* If we get here, we had a problem reading the file. */
 	goto Error;
     }
