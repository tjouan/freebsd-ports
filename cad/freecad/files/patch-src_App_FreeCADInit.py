--- src/App/FreeCADInit.py.orig	2016-04-24 14:01:28 UTC
+++ src/App/FreeCADInit.py
@@ -41,12 +41,11 @@ def InitApplications():
 		FreeCAD.Console.PrintError("\n\nSeems the python standard libs are not installed, bailing out!\n\n")
 		raise
 	# Checking on FreeCAD module path ++++++++++++++++++++++++++++++++++++++++++
-	ModDir = FreeCAD.getHomePath()+'Mod'
-	ModDir = os.path.realpath(ModDir)
+	#ModDir = '/usr/local/share/FreeCAD/Mod'
+	ModDir = '/usr/local/Mod'
 	BinDir = FreeCAD.getHomePath()+'bin'
 	BinDir = os.path.realpath(BinDir)
-	LibDir = FreeCAD.getHomePath()+'lib'
-	LibDir = os.path.realpath(LibDir)
+	LibDir = '/usr/local/lib/freecad'
 	Lib64Dir = FreeCAD.getHomePath()+'lib64'
 	Lib64Dir = os.path.realpath(Lib64Dir)
 	AddPath = FreeCAD.ConfigGet("AdditionalModulePaths").split(";")
