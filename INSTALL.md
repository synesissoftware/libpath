# libpath - Installation and Use <!-- omit in toc -->

**libpath** is a classic-form C/C++ library, insofar as it has
implementation files in its **src** directory and header files in its
**include/libpath** directory. Thus, once "installed", one must simply
include **libpath/libpath.h** or **libpath/libpath.hpp** (or one of the utility headers), and compile-in
or link-in the implementation. There are several ways to do this:


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)




## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **libpath**, from
   https://github.com/synesissoftware/libpath/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/libpath/
   ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script, as
   in:

   ```bash
   $ cd ~/open-source/libpath
   $ ./prepare_cmake.sh -v
   ```

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 2 then you do
   not need this step.)

4. As a check, execute the built test program files via the
   **build_run_all_unit_tests.sh** script, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

5. Install the library on the host, via `cmake`, as in:


   ```bash
   $ sudo cmake --install ./_build --config Release
   ```

7. Then to use the library, it is a simple matter as follows:

   1. Assuming a simple program that will verify the installation:

      ```C
      // parse_path.c
      #include <libpath/libpath.h>
      #include <stdio.h>
      #include <stdlib.h>

      int main(int argc, char* argv[])
      {
        char const* const         program_name = argv[0];
        char const* const         path = (argc > 1) ? argv[1] : program_name;
        libpath_PathDescriptor_t  result;
        LIBPATH_RC const          rc  = libpath_Parse_ParsePathFromCStyleString(
                                          path
                                        , 0
                                        , &result
                                        , 0
                                        , NULL
                                        );

        if (LIBPATH_RC_SUCCESS(rc))
        {
          fprintf(
              stdout
          ,   "results of parsing '%s':\n"
              "\tinput:                \t'%.*s'\n"
              "\tpath:                 \t'%.*s'\n"
              "\tlocationPart:         \t'%.*s'\n"
      #ifdef LIBPATH_OS_IS_WINDOWS
              "\tvolumePart:           \t'%.*s'\n"
      #endif /* LIBPATH_OS_IS_WINDOWS */
              "\trootPart:             \t'%.*s'\n"
              "\tdirectoryPart:        \t'%.*s'\n"
              "\tentryPart:            \t'%.*s'\n"
              "\tentryStemPart:        \t'%.*s'\n"
              "\tentryExtensionPart:   \t'%.*s'\n"
              "\tnumDotsDirectoryParts:\t%lu:\n"
              "\tnumDirectoryParts:    \t%lu:\n"
          ,   path
          ,   (int)(result.input.len), result.input.ptr
          ,   (int)(result.path.len), result.path.ptr
          ,   (int)(result.locationPart.len), result.locationPart.ptr
      #ifdef LIBPATH_OS_IS_WINDOWS
          ,   (int)(result.volumePart.len), result.volumePart.ptr
      #endif /* LIBPATH_OS_IS_WINDOWS */
          ,   (int)(result.rootPart.len), result.rootPart.ptr
          ,   (int)(result.directoryPart.len), result.directoryPart.ptr
          ,   (int)(result.entryPart.len), result.entryPart.ptr
          ,   (int)(result.entryStemPart.len), result.entryStemPart.ptr
          ,   (int)(result.entryExtensionPart.len), result.entryExtensionPart.ptr
          ,   result.numDotsDirectoryParts
          ,   result.numDirectoryParts
          );

          return EXIT_SUCCESS;
        }
        else
        {
          fprintf(
              stdout
          ,   "%s: failed to parse '%s', at offset %lu: %.*s\n"
          ,   program_name
          ,   path
          ,   result.firstBadCharOffset
          ,   (int)libpath_rc_getStringLen(rc), libpath_rc_getStringPtr(rc)
          );

          return EXIT_FAILURE;
        }
      }
      ```

   2. Compile your project against **libpath**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit include directory for **libpath**:

      ```bash
      $ cc -c parse_path.c
      ```

   3. Link your project against **libpath**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit library directory for **libpath**:

      ```bash
      $ cc parse_path.o -o parse_path -llibpath.core
      ```

   4. Test your project:

      Then you can run, as in:

      ```bash
      $ ./parse_path
      results of parsing './parse_path':
        input:                	'./parse_path'
        path:                 	'./parse_path'
        locationPart:         	'./'
        rootPart:             	''
        directoryPart:        	'./'
        entryPart:            	'parse_path'
        entryStemPart:        	'parse_path'
        entryExtensionPart:   	''
        numDotsDirectoryParts:	1:
        numDirectoryParts:    	1:
      ```

      or as in:

      ```bash
      $ ./parse_path ../../../libpath/install/example/parse_path.o
      results of parsing '../../../libpath/install/example/parse_path.o':
        input:                	'../../../libpath/install/example/parse_path.o'
        path:                 	'../../../libpath/install/example/parse_path.o'
        locationPart:         	'../../../libpath/install/example/'
        rootPart:             	''
        directoryPart:        	'../../../libpath/install/example/'
        entryPart:            	'parse_path.o'
        entryStemPart:        	'parse_path'
        entryExtensionPart:   	'.o'
        numDotsDirectoryParts:	3:
        numDirectoryParts:    	6:
      ```


<!-- ########################### end of file ########################### -->

