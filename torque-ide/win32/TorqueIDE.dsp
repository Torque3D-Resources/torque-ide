# Microsoft Developer Studio Project File - Name="TorqueIDE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TorqueIDE - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TorqueIDE.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TorqueIDE.mak" CFG="TorqueIDE - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TorqueIDE - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /YX /FD /c
# ADD CPP /nologo /MD /W4 /O2 /I "$(WXWIN)/include" /I "$(WXWIN)/contrib/include" /I "$(WXWIN)/lib/vc_lib/msw" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /D "_MT" /D wxUSE_GUI=1 /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "$(WXWIN)/include" /d "NDEBUG"
# ADD RSC /l 0x409 /i "$(WXWIN)/include" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib $(WXWIN)/lib/vc_lib/wxbase25.lib $(WXWIN)/lib/vc_lib/wxmsw25_core.lib $(WXWIN)/lib/vc_lib/wxmsw25_stc.lib $(WXWIN)/lib/vc_lib/wxzlib.lib $(WXWIN)/lib/vc_lib/wxregex.lib $(WXWIN)/lib/vc_lib/wxpng.lib $(WXWIN)/lib/vc_lib/wxjpeg.lib $(WXWIN)/lib/vc_lib/wxtiff.lib /nologo /subsystem:windows /machine:I386
# Begin Target

# Name "TorqueIDE - Win32 Release"
# Begin Source File

SOURCE=..\src\torque.ico
# End Source File
# Begin Source File

SOURCE=..\src\TorqueIDE.rc
# End Source File
# Begin Source File

SOURCE=..\src\torqueideabout.cpp
# End Source File
# Begin Source File

SOURCE=..\src\torqueideabout.h
# End Source File
# Begin Source File

SOURCE=..\src\torqueideapp.cpp
# End Source File
# Begin Source File

SOURCE=..\src\torqueideapp.h
# End Source File
# Begin Source File

SOURCE=..\src\torqueideframe.cpp
# End Source File
# Begin Source File

SOURCE=..\src\torqueideframe.h
# End Source File
# Begin Source File

SOURCE=..\src\torqueideprefs.cpp
# End Source File
# Begin Source File

SOURCE=..\src\torqueideprefs.h
# End Source File
# Begin Source File

SOURCE=..\src\torqueidestc.cpp
# End Source File
# Begin Source File

SOURCE=..\src\torqueidestc.h
# End Source File
# End Target
# End Project
