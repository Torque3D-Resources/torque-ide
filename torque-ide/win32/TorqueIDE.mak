# Microsoft Developer Studio Generated NMAKE File, Based on TorqueIDE.dsp
!IF "$(CFG)" == ""
CFG=TorqueIDE - Win32 Release
!MESSAGE No configuration specified. Defaulting to TorqueIDE - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "TorqueIDE - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TorqueIDE.mak" CFG="TorqueIDE - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TorqueIDE - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\TorqueIDE.exe"


CLEAN :
	-@erase "$(INTDIR)\TorqueIDE.res"
	-@erase "$(INTDIR)\torqueideabout.obj"
	-@erase "$(INTDIR)\torqueideapp.obj"
	-@erase "$(INTDIR)\torqueideframe.obj"
	-@erase "$(INTDIR)\torqueideprefs.obj"
	-@erase "$(INTDIR)\torqueidestc.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\TorqueIDE.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W4 /O2 /I "$(WXWIN)/include" /I "$(WXWIN)/contrib/include" /I "$(WXWIN)/lib/vc_lib/msw" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /D "_MT" /D wxUSE_GUI=1 /Fp"$(INTDIR)\TorqueIDE.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TorqueIDE.res" /i "$(WXWIN)/include" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TorqueIDE.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib $(WXWIN)/lib/vc_lib/wxbase25.lib $(WXWIN)/lib/vc_lib/wxmsw25_core.lib $(WXWIN)/lib/vc_lib/wxmsw25_stc.lib $(WXWIN)/lib/vc_lib/wxzlib.lib $(WXWIN)/lib/vc_lib/wxregex.lib $(WXWIN)/lib/vc_lib/wxpng.lib $(WXWIN)/lib/vc_lib/wxjpeg.lib $(WXWIN)/lib/vc_lib/wxtiff.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\TorqueIDE.pdb" /machine:I386 /out:"$(OUTDIR)\TorqueIDE.exe" 
LINK32_OBJS= \
	"$(INTDIR)\torqueideabout.obj" \
	"$(INTDIR)\torqueideapp.obj" \
	"$(INTDIR)\torqueideframe.obj" \
	"$(INTDIR)\torqueideprefs.obj" \
	"$(INTDIR)\torqueidestc.obj" \
	"$(INTDIR)\TorqueIDE.res"

"$(OUTDIR)\TorqueIDE.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("TorqueIDE.dep")
!INCLUDE "TorqueIDE.dep"
!ELSE 
!MESSAGE Warning: cannot find "TorqueIDE.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TorqueIDE - Win32 Release"
SOURCE=..\src\TorqueIDE.rc

"$(INTDIR)\TorqueIDE.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\TorqueIDE.res" /i "$(WXWIN)/include" /i "\torque-ide\src" /d "NDEBUG" $(SOURCE)


SOURCE=..\src\torqueideabout.cpp

"$(INTDIR)\torqueideabout.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\torqueideapp.cpp

"$(INTDIR)\torqueideapp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\torqueideframe.cpp

"$(INTDIR)\torqueideframe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\torqueideprefs.cpp

"$(INTDIR)\torqueideprefs.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\src\torqueidestc.cpp

"$(INTDIR)\torqueidestc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

