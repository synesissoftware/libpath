#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
MakeCmd=${SIS_CMAKE_COMMAND:-make}

Configuration=Release
ExamplesDisabled=0
MinGW=0
RunMake=0
STLSoftDirGiven=
SimulateWindowsOnUnix=0
TestingDisabled=0
VerboseMakefile=0


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -v|--cmake-verbose-makefile)

      VerboseMakefile=1
      ;;
    -d|--debug-configuration)

      Configuration=Debug
      ;;
    -E|--disable-examples)

      ExamplesDisabled=1
      ;;
    -T|--disable-testing)

      TestingDisabled=1
      ;;
    --mingw)

      MinGW=1
      ;;
    -m|--run-make)

      RunMake=1
      ;;
    --simulate-windows-on-unix)

      SimulateWindowsOnUnix=1
      ;;
    -s|--stlsoft-root-dir)

      shift
      STLSoftDirGiven=$1
      ;;
    --help)

      cat << EOF
libpath is a path parsing library (for C and C++)
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2012-2019, Matthew Wilson and Synesis Software
Creates/reinitialises the CMake build script(s)

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (by setting CMAKE_VERBOSE_MAKEFILE
        to be ON)

    -d
    --debug-configuration
        use Debug configuration (by setting CMAKE_BUILD_TYPE=Debug). Default
        is to use Release

    -E
    --disable-examples
        disables building of examples (by setting BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (by setting BUILD_TESTING=OFF). This is
        necessary, for example, when installing on a system that does not
        (yet) have xTests - which itself depends on STLSOFT - installed

    --mingw
        uses explicitly the "MinGW Makefiles" generator

    -m
    --run-make
        executes make after a successful running of CMake

    --simulate-windows-on-unix
        defines the LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX object-like
        preprocessor macro

    -s <dir>
    --stlsoft-root-dir <dir>
        specifies the STLSoft root-directory, which will be passed to CMake
        as the variable STLSOFT, and which will override the environment
        variable STLSOFT (if present)


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

mkdir -p $CMakeDir || exit 1

cd $CMakeDir

echo "Executing CMake (in ${CMakeDir})"

if [ $ExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi
if [ -z $STLSoftDirGiven ]; then CMakeSTLSoftVariable="" ; else CMakeSTLSoftVariable="-DSTLSOFT=$STLSoftDirGiven/" ; fi
if [ $SimulateWindowsOnUnix -eq 0 ]; then CMakeSimulateWindowsOnUnixFlag="OFF" ; else CMakeSimulateWindowsOnUnixFlag="ON" ; fi
if [ $TestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi
if [ $VerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi

if [ $MinGW -ne 0 ]; then

  cmake \
    $CMakeSTLSoftVariable \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DLIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX:BOOL=$CMakeSimulateWindowsOnUnixFlag \
    -G "MinGW Makefiles" \
    -S $Dir \
    -B $CMakeDir \
    || (cd ->/dev/null ; exit 1)
else

  cmake \
    $CMakeSTLSoftVariable \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
    -DLIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX:BOOL=$CMakeSimulateWindowsOnUnixFlag \
    -S $Dir \
    -B $CMakeDir \
    || (cd ->/dev/null ; exit 1)
fi

status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing build (via command \`$MakeCmd\`)"

  $MakeCmd
  status=$?
fi

cd ->/dev/null

if [ $VerboseMakefile -ne 0 ]; then

  echo -e "contents of $CMakeDir:"
  ls -al $CMakeDir
fi

exit $status


# ############################## end of file ############################# #

