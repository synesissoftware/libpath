#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=$Dir/_build


CMakeExamplesDisabled=0
CMakeTestingDisabled=0
CMakeVerboseMakefile=0
Configuration=Release
RunMake=0
CMakeSimulateWindowsOnUnix=0
STLSoftDirGiven=


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -v|--cmake-verbose-makefile)

      CMakeVerboseMakefile=1
      ;;
    -d|--debug-configuration)

      Configuration=Debug
      ;;
    -E|--disable-examples)

      CMakeExamplesDisabled=1
      ;;
    -T|--disable-testing)

      CMakeTestingDisabled=1
      ;;
    -m|--run-make)

      RunMake=1
      ;;
    --simulate-windows-on-unix)

      CMakeSimulateWindowsOnUnix=1
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
        use Debug configuration (by setting CMAKE_BUILD_TYPE=Debug). Default
        is to use Release

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

echo "Executing CMake"

if [ $CMakeExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi

if [ $CMakeTestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi

if [ $CMakeVerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi

if [ $CMakeSimulateWindowsOnUnix -eq 0 ]; then CMakeSimulateWindowsOnUnixFlag="OFF" ; else CMakeSimulateWindowsOnUnixFlag="ON" ; fi

if [ -z $STLSoftDirGiven ]; then CMakeSTLSoftVariable="" ; else CMakeSTLSoftVariable="-DSTLSOFT=$STLSoftDirGiven/" ; fi

cmake \
  $CMakeSTLSoftVariable \
  -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
  -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
  -DCMAKE_BUILD_TYPE=$Configuration \
  -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
  -DLIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX:BOOL=$CMakeSimulateWindowsOnUnixFlag \
  .. || (cd ->/dev/null ; exit 1)

status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing make"

  make
  status=$?
fi

cd ->/dev/null

if [ $CMakeVerboseMakefile -ne 0 ]; then

  echo -e "contents of $CMakeDir:"
  ls -al $CMakeDir
fi

exit $status


# ############################## end of file ############################# #

