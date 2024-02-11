# Microsoft Developer Studio Project File - Name="libpath" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libpath - Win32 Debug pseudoUnix
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libpath.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libpath.mak" CFG="libpath - Win32 Debug pseudoUnix"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libpath - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Release Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Debug Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Release Multithreaded Dll" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Debug Multithreaded Dll" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Release pseudoUnix" (based on "Win32 (x86) Static Library")
!MESSAGE "libpath - Win32 Debug pseudoUnix" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libpath - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.debug.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMt"
# PROP BASE Intermediate_Dir "ReleaseMt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMt"
# PROP Intermediate_Dir "ReleaseMt"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.mt.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.mt.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMt"
# PROP BASE Intermediate_Dir "DebugMt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMt"
# PROP Intermediate_Dir "DebugMt"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.mt.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.mt.debug.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Release Multithreaded Dll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDll"
# PROP BASE Intermediate_Dir "ReleaseDll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDll"
# PROP Intermediate_Dir "ReleaseDll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.dll.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.dll.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug Multithreaded Dll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDll"
# PROP BASE Intermediate_Dir "DebugDll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDll"
# PROP Intermediate_Dir "DebugDll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.dll.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.dll.debug.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Release pseudoUnix"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUnix"
# PROP BASE Intermediate_Dir "ReleaseUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUnix"
# PROP Intermediate_Dir "ReleaseUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.unix.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.unix.lib"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug pseudoUnix"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUnix"
# PROP BASE Intermediate_Dir "DebugUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUnix"
# PROP Intermediate_Dir "DebugUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "LIBPATH_SUPPRESS_WINDOWS" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libpath.0.vc6.unix.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/libpath.0.vc6.unix.debug.lib"

!ENDIF 

# Begin Target

# Name "libpath - Win32 Release"
# Name "libpath - Win32 Debug"
# Name "libpath - Win32 Release Multithreaded"
# Name "libpath - Win32 Debug Multithreaded"
# Name "libpath - Win32 Release Multithreaded Dll"
# Name "libpath - Win32 Debug Multithreaded Dll"
# Name "libpath - Win32 Release pseudoUnix"
# Name "libpath - Win32 Debug pseudoUnix"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="..\..\..\src\libpath.c++.api.cpp"
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.compare.api.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.compare.internal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.equate.api.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.equate.internal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.parse.api.c

!IF  "$(CFG)" == "libpath - Win32 Release"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug"

# ADD CPP /Zi

!ELSEIF  "$(CFG)" == "libpath - Win32 Release Multithreaded"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug Multithreaded"

!ELSEIF  "$(CFG)" == "libpath - Win32 Release Multithreaded Dll"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug Multithreaded Dll"

!ELSEIF  "$(CFG)" == "libpath - Win32 Release pseudoUnix"

!ELSEIF  "$(CFG)" == "libpath - Win32 Debug pseudoUnix"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.parse.internal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.util.api.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\include\libpath\compare\api.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\equate\api.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\parse\api.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\util\api.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\internal\nothing_.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\equate\types\enumerations\EquateOption.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\equate\types\EquateOption.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\types\fundamental_.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\exceptions\invalid_path_exception.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.compare.internal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.equate.internal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.internal.types.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.parse.internal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.quality.contract.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libpath.string.tchar.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\exceptions\libpath_exception.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\macros.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\portability\operating_system.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\parse\types\enumerations\ParseOption.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\parse\types\ParseOption.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\result_codes\enumerations\rc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\result_codes\enumerations\rcx.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\result_codes\result_codes_.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\types\slices_.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\shims\access\string\StringSlice.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\types.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\compare\types.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\equate\types.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\parse\types.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\util\types.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\types.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\common\version.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\libpath\shared\types\WorkingDirectoryContext.h
# End Source File
# End Group
# End Target
# End Project
