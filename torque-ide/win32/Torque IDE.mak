# Microsoft Developer Studio Generated NMAKE File, Based on Torque IDE.dsp
!IF "$(CFG)" == ""
CFG=Torque IDE - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Torque IDE - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Torque IDE - Win32 Release" && "$(CFG)" != "Torque IDE - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Torque IDE.mak" CFG="Torque IDE - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Torque IDE - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Torque IDE - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Torque IDE - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Torque IDE.exe"


CLEAN :
	-@erase "$(INTDIR)\torque ide.res"
	-@erase "$(INTDIR)\torqueideapp.obj"
	-@erase "$(INTDIR)\torqueideframe.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Torque IDE.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "C:\programming\wxwindows\include" /I "C:\programming\wxwindows\contrib\include" /I "C:\programming\wxwindows\lib\msw" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "__WINDOWS__" /D "__WXMSW__" /D "__WIN95__" /D "__WIN32__" /D WINVER=0x0400 /D "STRICT" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\torque ide.res" /i "C:\programming\wxwindows\include" /i "C:\programming\wxwindows\contrib\include" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Torque IDE.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib winmm.lib wxmsw25_adv.lib wxmsw25_stc.lib wxpng.lib wxzlib.lib wxjpeg.lib wxtiff.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Torque IDE.pdb" /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libci.lib" /nodefaultlib:"msvcrtd.lib" /out:"$(OUTDIR)\Torque IDE.exe" /libpath:"C:\programming\wxwindows\lib\vc_lib" /libpath:"C:\programming\wxwindows\contrib\lib" 
LINK32_OBJS= \
	"$(INTDIR)\torqueideapp.obj" \
	"$(INTDIR)\torqueideframe.obj" \
	"$(INTDIR)\torque ide.res"

"$(OUTDIR)\Torque IDE.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Torque IDE - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Torque IDE.exe" "$(OUTDIR)\Torque IDE.bsc"


CLEAN :
	-@erase "$(INTDIR)\torque ide.res"
	-@erase "$(INTDIR)\torqueideapp.obj"
	-@erase "$(INTDIR)\torqueideapp.sbr"
	-@erase "$(INTDIR)\torqueideframe.obj"
	-@erase "$(INTDIR)\torqueideframe.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Torque IDE.bsc"
	-@erase "$(OUTDIR)\Torque IDE.exe"
	-@erase "$(OUTDIR)\Torque IDE.ilk"
	-@erase "$(OUTDIR)\Torque IDE.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "C:\programming\wxwindows\include" /I "C:\programming\wxwindows\contrib\include" /I "C:\programming\wxwindows\lib\mswd" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "__WINDOWS__" /D "__WXMSW__" /D "__WXDEBUG__" /D WXDEBUG=1 /D "__WIN95__" /D "__WIN32__" /D WINVER=0x0400 /D "STRICT" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\torque ide.res" /i "C:\programming\wxwindows\include" /i "C:\programming\wxwindows\contrib\include" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Torque IDE.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\torqueideapp.sbr" \
	"$(INTDIR)\torqueideframe.sbr"

"$(OUTDIR)\Torque IDE.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib winmm.lib wxmswd.lib pngd.lib zlibd.lib jpegd.lib tiffd.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Torque IDE.pdb" /debug /machine:I386 /nodefaultlib:"libcd.lib" /nodefaultlib:"libcid.lib" /nodefaultlib:"msvcrt.lib" /out:"$(OUTDIR)\Torque IDE.exe" /pdbtype:sept /libpath:"C:\programming\wxwindows\lib" /libpath:"C:\programming\wxwindows\contrib\lib" 
LINK32_OBJS= \
	"$(INTDIR)\torqueideapp.obj" \
	"$(INTDIR)\torqueideframe.obj" \
	"$(INTDIR)\torque ide.res"

"$(OUTDIR)\Torque IDE.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Torque IDE.dep")
!INCLUDE "Torque IDE.dep"
!ELSE 
!MESSAGE Warning: cannot find "Torque IDE.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Torque IDE - Win32 Release" || "$(CFG)" == "Torque IDE - Win32 Debug"
SOURCE=".\torque ide.rc"

"$(INTDIR)\torque ide.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\torqueideapp.cpp

!IF  "$(CFG)" == "Torque IDE - Win32 Release"


"$(INTDIR)\torqueideapp.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Torque IDE - Win32 Debug"


"$(INTDIR)\torqueideapp.obj"	"$(INTDIR)\torqueideapp.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\torqueideframe.cpp

!IF  "$(CFG)" == "Torque IDE - Win32 Release"


"$(INTDIR)\torqueideframe.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Torque IDE - Win32 Debug"


"$(INTDIR)\torqueideframe.obj"	"$(INTDIR)\torqueideframe.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

