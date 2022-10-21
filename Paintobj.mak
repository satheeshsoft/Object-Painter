# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Paintobj - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Paintobj - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Paintobj - Win32 Debug" && "$(CFG)" !=\
 "Paintobj - Win32 Release" && "$(CFG)" != "Paintobj - Win32 Unicode Debug" &&\
 "$(CFG)" != "Paintobj - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Paintobj.mak" CFG="Paintobj - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Paintobj - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Paintobj - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Paintobj - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "Paintobj - Win32 Unicode Release" (based on\
 "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Paintobj - Win32 Unicode Debug"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Paintobj - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : ".\WinDebug\Paintobj.exe"

CLEAN : 
	-@erase ".\WinDebug\CIRCLE.OBJ"
	-@erase ".\WinDebug\LINE.OBJ"
	-@erase ".\WinDebug\MAINFRM.OBJ"
	-@erase ".\WinDebug\PAINTDOC.OBJ"
	-@erase ".\WinDebug\PAINTED.OBJ"
	-@erase ".\WinDebug\Paintobj.exe"
	-@erase ".\WinDebug\Paintobj.ilk"
	-@erase ".\WinDebug\PAINTOBJ.OBJ"
	-@erase ".\WinDebug\Paintobj.pch"
	-@erase ".\WinDebug\Paintobj.pdb"
	-@erase ".\WinDebug\PAINTOBJ.res"
	-@erase ".\WinDebug\paintvw.obj"
	-@erase ".\WinDebug\SQUARE.OBJ"
	-@erase ".\WinDebug\STDAFX.OBJ"
	-@erase ".\WinDebug\vc40.idb"
	-@erase ".\WinDebug\vc40.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paintobj.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/PAINTOBJ.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Paintobj.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Paintobj.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Paintobj.exe" 
LINK32_OBJS= \
	".\WinDebug\CIRCLE.OBJ" \
	".\WinDebug\LINE.OBJ" \
	".\WinDebug\MAINFRM.OBJ" \
	".\WinDebug\PAINTDOC.OBJ" \
	".\WinDebug\PAINTED.OBJ" \
	".\WinDebug\PAINTOBJ.OBJ" \
	".\WinDebug\PAINTOBJ.res" \
	".\WinDebug\paintvw.obj" \
	".\WinDebug\SQUARE.OBJ" \
	".\WinDebug\STDAFX.OBJ"

".\WinDebug\Paintobj.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : ".\WinRel\Paintobj.exe"

CLEAN : 
	-@erase ".\WinRel\CIRCLE.OBJ"
	-@erase ".\WinRel\LINE.OBJ"
	-@erase ".\WinRel\MAINFRM.OBJ"
	-@erase ".\WinRel\PAINTDOC.OBJ"
	-@erase ".\WinRel\PAINTED.OBJ"
	-@erase ".\WinRel\Paintobj.exe"
	-@erase ".\WinRel\PAINTOBJ.OBJ"
	-@erase ".\WinRel\Paintobj.pch"
	-@erase ".\WinRel\PAINTOBJ.res"
	-@erase ".\WinRel\paintvw.obj"
	-@erase ".\WinRel\SQUARE.OBJ"
	-@erase ".\WinRel\STDAFX.OBJ"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paintobj.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/PAINTOBJ.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Paintobj.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Paintobj.pdb" /machine:I386 /out:"$(OUTDIR)/Paintobj.exe" 
LINK32_OBJS= \
	".\WinRel\CIRCLE.OBJ" \
	".\WinRel\LINE.OBJ" \
	".\WinRel\MAINFRM.OBJ" \
	".\WinRel\PAINTDOC.OBJ" \
	".\WinRel\PAINTED.OBJ" \
	".\WinRel\PAINTOBJ.OBJ" \
	".\WinRel\PAINTOBJ.res" \
	".\WinRel\paintvw.obj" \
	".\WinRel\SQUARE.OBJ" \
	".\WinRel\STDAFX.OBJ"

".\WinRel\Paintobj.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Paintobj"
# PROP BASE Intermediate_Dir "Paintobj"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebug"
# PROP Intermediate_Dir "UDebug"
# PROP Target_Dir ""
OUTDIR=.\UDebug
INTDIR=.\UDebug

ALL : ".\UDebug\Paintobj.exe"

CLEAN : 
	-@erase ".\UDebug\CIRCLE.OBJ"
	-@erase ".\UDebug\LINE.OBJ"
	-@erase ".\UDebug\MAINFRM.OBJ"
	-@erase ".\UDebug\PAINTDOC.OBJ"
	-@erase ".\UDebug\PAINTED.OBJ"
	-@erase ".\UDebug\Paintobj.exe"
	-@erase ".\UDebug\Paintobj.ilk"
	-@erase ".\UDebug\PAINTOBJ.OBJ"
	-@erase ".\UDebug\Paintobj.pch"
	-@erase ".\UDebug\Paintobj.pdb"
	-@erase ".\UDebug\PAINTOBJ.res"
	-@erase ".\UDebug\paintvw.obj"
	-@erase ".\UDebug\SQUARE.OBJ"
	-@erase ".\UDebug\STDAFX.OBJ"
	-@erase ".\UDebug\vc40.idb"
	-@erase ".\UDebug\vc40.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)/Paintobj.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\UDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/PAINTOBJ.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Paintobj.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)/Paintobj.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Paintobj.exe" 
LINK32_OBJS= \
	".\UDebug\CIRCLE.OBJ" \
	".\UDebug\LINE.OBJ" \
	".\UDebug\MAINFRM.OBJ" \
	".\UDebug\PAINTDOC.OBJ" \
	".\UDebug\PAINTED.OBJ" \
	".\UDebug\PAINTOBJ.OBJ" \
	".\UDebug\PAINTOBJ.res" \
	".\UDebug\paintvw.obj" \
	".\UDebug\SQUARE.OBJ" \
	".\UDebug\STDAFX.OBJ"

".\UDebug\Paintobj.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Paintob0"
# PROP BASE Intermediate_Dir "Paintob0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "URelease"
# PROP Intermediate_Dir "URelease"
# PROP Target_Dir ""
OUTDIR=.\URelease
INTDIR=.\URelease

ALL : ".\URelease\Paintobj.exe"

CLEAN : 
	-@erase ".\URelease\CIRCLE.OBJ"
	-@erase ".\URelease\LINE.OBJ"
	-@erase ".\URelease\MAINFRM.OBJ"
	-@erase ".\URelease\PAINTDOC.OBJ"
	-@erase ".\URelease\PAINTED.OBJ"
	-@erase ".\URelease\Paintobj.exe"
	-@erase ".\URelease\PAINTOBJ.OBJ"
	-@erase ".\URelease\Paintobj.pch"
	-@erase ".\URelease\PAINTOBJ.res"
	-@erase ".\URelease\paintvw.obj"
	-@erase ".\URelease\SQUARE.OBJ"
	-@erase ".\URelease\STDAFX.OBJ"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)/Paintobj.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\URelease/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/PAINTOBJ.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Paintobj.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)/Paintobj.pdb" /machine:I386\
 /out:"$(OUTDIR)/Paintobj.exe" 
LINK32_OBJS= \
	".\URelease\CIRCLE.OBJ" \
	".\URelease\LINE.OBJ" \
	".\URelease\MAINFRM.OBJ" \
	".\URelease\PAINTDOC.OBJ" \
	".\URelease\PAINTED.OBJ" \
	".\URelease\PAINTOBJ.OBJ" \
	".\URelease\PAINTOBJ.res" \
	".\URelease\paintvw.obj" \
	".\URelease\SQUARE.OBJ" \
	".\URelease\STDAFX.OBJ"

".\URelease\Paintobj.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

MTL_PROJ=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Paintobj - Win32 Debug"
# Name "Paintobj - Win32 Release"
# Name "Paintobj - Win32 Unicode Debug"
# Name "Paintobj - Win32 Unicode Release"

!IF  "$(CFG)" == "Paintobj - Win32 Debug"

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\STDAFX.CPP
DEP_CPP_STDAF=\
	".\PAINTED.H"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paintobj.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

".\WinDebug\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

".\WinDebug\Paintobj.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Paintobj.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

".\WinRel\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

".\WinRel\Paintobj.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)/Paintobj.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

".\UDebug\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

".\UDebug\Paintobj.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)/Paintobj.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

".\URelease\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

".\URelease\Paintobj.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PAINTOBJ.CPP
DEP_CPP_PAINT=\
	".\Mainfrm.h"\
	".\Paintdoc.h"\
	".\PAINTED.H"\
	".\Paintobj.h"\
	".\Paintvw.h"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\PAINTOBJ.OBJ" : $(SOURCE) $(DEP_CPP_PAINT) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\PAINTOBJ.OBJ" : $(SOURCE) $(DEP_CPP_PAINT) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\PAINTOBJ.OBJ" : $(SOURCE) $(DEP_CPP_PAINT) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\PAINTOBJ.OBJ" : $(SOURCE) $(DEP_CPP_PAINT) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MAINFRM.CPP
DEP_CPP_MAINF=\
	".\Mainfrm.h"\
	".\PAINTED.H"\
	".\Paintobj.h"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\MAINFRM.OBJ" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\MAINFRM.OBJ" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\MAINFRM.OBJ" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\MAINFRM.OBJ" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PAINTDOC.CPP
DEP_CPP_PAINTD=\
	".\Circle.h"\
	".\Line.h"\
	".\Paintdoc.h"\
	".\PAINTED.H"\
	".\Paintobj.h"\
	".\Square.h"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\PAINTDOC.OBJ" : $(SOURCE) $(DEP_CPP_PAINTD) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\PAINTDOC.OBJ" : $(SOURCE) $(DEP_CPP_PAINTD) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\PAINTDOC.OBJ" : $(SOURCE) $(DEP_CPP_PAINTD) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\PAINTDOC.OBJ" : $(SOURCE) $(DEP_CPP_PAINTD) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\paintvw.cpp
DEP_CPP_PAINTV=\
	".\Mainfrm.h"\
	".\Paintdoc.h"\
	".\PAINTED.H"\
	".\Paintobj.h"\
	".\Paintvw.h"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\paintvw.obj" : $(SOURCE) $(DEP_CPP_PAINTV) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\paintvw.obj" : $(SOURCE) $(DEP_CPP_PAINTV) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\paintvw.obj" : $(SOURCE) $(DEP_CPP_PAINTV) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\paintvw.obj" : $(SOURCE) $(DEP_CPP_PAINTV) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PAINTOBJ.RC
DEP_RSC_PAINTO=\
	".\res\bitmap1.bmp"\
	".\RES\DRAWTOOL.BMP"\
	".\RES\PAINTDOC.ICO"\
	".\RES\PAINTOBJ.ICO"\
	".\RES\PAINTOBJ.RC2"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\PAINTOBJ.res" : $(SOURCE) $(DEP_RSC_PAINTO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\PAINTOBJ.res" : $(SOURCE) $(DEP_RSC_PAINTO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\PAINTOBJ.res" : $(SOURCE) $(DEP_RSC_PAINTO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\PAINTOBJ.res" : $(SOURCE) $(DEP_RSC_PAINTO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\LINE.CPP
DEP_CPP_LINE_=\
	".\Line.h"\
	".\PAINTED.H"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\LINE.OBJ" : $(SOURCE) $(DEP_CPP_LINE_) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\LINE.OBJ" : $(SOURCE) $(DEP_CPP_LINE_) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\LINE.OBJ" : $(SOURCE) $(DEP_CPP_LINE_) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\LINE.OBJ" : $(SOURCE) $(DEP_CPP_LINE_) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PAINTED.CPP
DEP_CPP_PAINTE=\
	".\Line.h"\
	".\PAINTED.H"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\PAINTED.OBJ" : $(SOURCE) $(DEP_CPP_PAINTE) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\PAINTED.OBJ" : $(SOURCE) $(DEP_CPP_PAINTE) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\PAINTED.OBJ" : $(SOURCE) $(DEP_CPP_PAINTE) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\PAINTED.OBJ" : $(SOURCE) $(DEP_CPP_PAINTE) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SQUARE.CPP
DEP_CPP_SQUAR=\
	".\PAINTED.H"\
	".\Square.h"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\SQUARE.OBJ" : $(SOURCE) $(DEP_CPP_SQUAR) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\SQUARE.OBJ" : $(SOURCE) $(DEP_CPP_SQUAR) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\SQUARE.OBJ" : $(SOURCE) $(DEP_CPP_SQUAR) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\SQUARE.OBJ" : $(SOURCE) $(DEP_CPP_SQUAR) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CIRCLE.CPP
DEP_CPP_CIRCL=\
	".\Circle.h"\
	".\PAINTED.H"\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "Paintobj - Win32 Debug"


".\WinDebug\CIRCLE.OBJ" : $(SOURCE) $(DEP_CPP_CIRCL) "$(INTDIR)"\
 ".\WinDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Release"


".\WinRel\CIRCLE.OBJ" : $(SOURCE) $(DEP_CPP_CIRCL) "$(INTDIR)"\
 ".\WinRel\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Debug"


".\UDebug\CIRCLE.OBJ" : $(SOURCE) $(DEP_CPP_CIRCL) "$(INTDIR)"\
 ".\UDebug\Paintobj.pch"


!ELSEIF  "$(CFG)" == "Paintobj - Win32 Unicode Release"


".\URelease\CIRCLE.OBJ" : $(SOURCE) $(DEP_CPP_CIRCL) "$(INTDIR)"\
 ".\URelease\Paintobj.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
