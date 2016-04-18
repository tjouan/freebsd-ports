--- src/Mod/Draft/DraftSnap.py.orig	2016-04-24 15:00:32 UTC
+++ src/Mod/Draft/DraftSnap.py
@@ -826,6 +826,7 @@ class Snapper:
 
     def setCursor(self,mode=None):
         "setCursor(self,mode=None): sets or resets the cursor to the given mode or resets"
+        return
         if self.selectMode:
             mw = FreeCADGui.getMainWindow()
             for w in mw.findChild(QtGui.QMdiArea).findChildren(QtGui.QWidget):
