/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.compare.1.cpp
 *
 * Purpose: Implementation file for the test.unit.compare.1 project.
 *
 * Created: 17th February 2013
 * Updated: 19th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/compare.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <new>
#include <stdexcept>

/* Standard C header files */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_compare_filenames(void);
    static void test_compare_slash_rooted_filenames(void);
    static void test_compare_Windows_drive_rooted_filenames(void);
    static void test_compare_relative_directory(void);
    static void test_compare_dots_directory(void);
    static void test_compare_2dotsdir(void);
    static void test_compare_mixed_dots_directory(void);
    static void test_compare_slash(void);
    static void test_compare_2_dirs_and_filename(void);
    static void test_compare_slash_rooted_filename(void);
    static void test_Windows_mixed_rooted_paths(void);
    static void test_mixed_with_root_pwd(void);
    static void test_noncanonical_paths(void);
    static void test_noncanonical_paths_trailing_dots(void);
    static void test_sliding_rel_and_cwd(void);
    static void test_compare_UNC_rooted_paths(void);
    static void test_Windows_mixed_pwd(void);
    static void test_mixed_comparisons(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.compare.1", verbosity))
    {
        XTESTS_RUN_CASE(test_compare_filenames);
        XTESTS_RUN_CASE(test_compare_slash_rooted_filenames);
        XTESTS_RUN_CASE(test_compare_Windows_drive_rooted_filenames);
        XTESTS_RUN_CASE(test_compare_relative_directory);
        XTESTS_RUN_CASE(test_compare_dots_directory);
        XTESTS_RUN_CASE(test_compare_2dotsdir);
        XTESTS_RUN_CASE(test_compare_mixed_dots_directory);
        XTESTS_RUN_CASE(test_compare_slash);
        XTESTS_RUN_CASE(test_compare_2_dirs_and_filename);
        XTESTS_RUN_CASE(test_compare_slash_rooted_filename);
        XTESTS_RUN_CASE(test_Windows_mixed_rooted_paths);
        XTESTS_RUN_CASE(test_mixed_with_root_pwd);
        XTESTS_RUN_CASE(test_noncanonical_paths);
        XTESTS_RUN_CASE(test_noncanonical_paths_trailing_dots);
        XTESTS_RUN_CASE(test_sliding_rel_and_cwd);
        XTESTS_RUN_CASE(test_compare_UNC_rooted_paths);
        XTESTS_RUN_CASE(test_Windows_mixed_pwd);
        XTESTS_RUN_CASE(test_mixed_comparisons);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
//    using libpath::comparing::compare_paths;

    inline
    int
    compare_paths(
        char const*   lhs
    ,   char const*   rhs
    ,   char const*   cwd   = LIBPATH_LF_nullptr
    ,   char const* /*mem*/ = LIBPATH_LF_nullptr
    )
    {
        libpath_sint32_t                    flags   =   0;
        libpath_WorkingDirectoryContext_t   ctxt;
        int                                 result;

        ctxt.mechanism          =   libpath_WorkingDirectoryContextMechanism_CStyleString;
        ctxt.details.cwd_css    =   cwd;

        LIBPATH_RC rc = libpath_Compare_ComparePathsAsCStyleStrings(
            lhs
        ,   rhs
        ,   flags
        ,   &ctxt
        ,   LIBPATH_LF_nullptr
        ,   &result
        );

        switch (rc)
        {
        case    LIBPATH_RC_OF(FirstPathInvalid):
        case    LIBPATH_RC_OF(SecondPathInvalid):
        case    LIBPATH_RC_OF(WorkingDirectoryPathInvalid):

            break;
        default:

            break;
        }

        if (LIBPATH_RC_FAILURE(rc))
        {
            return INT_MIN;
        }

        return result;
    }



static void test_compare_filenames(void)
{
    // Just entry parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "file.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("fil1.ext", "fil2.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("fil2.ext", "fil1.ext"));


    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("...",  "..."));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("...",  "...."));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("....", "..."));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "FILE.EXT"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("fil1.ext", "fil2.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("FIL2.EXT", "FIL1.EXT"));
#endif
}

static void test_compare_slash_rooted_filenames(void)
{
    // Just rooted entry parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/file.ext", "/file.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/fil1.ext", "/fil2.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/fil2.ext", "/fil1.ext"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file.ext",  "/FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\file.ext",  "/FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file.ext", "\\FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\file.ext", "\\FILE.EXT"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/fil1.ext",  "/FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/FIL2.EXT",  "/fil1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\fil1.ext",  "/FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\FIL2.EXT",  "/fil1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/fil1.ext", "\\FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/FIL2.EXT", "\\fil1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\fil1.ext", "\\FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\FIL2.EXT", "\\fil1.ext"));
#endif
}

static void test_compare_Windows_drive_rooted_filenames(void)
{
    // Windows-rooted entry parts

#ifdef LIBPATH_OS_IS_WINDOWS

    // case of entry-part

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file.ext",  "C:/FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\file.ext",  "C:/FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file.ext", "C:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\file.ext", "C:\\FILE.EXT"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/fil1.ext",  "C:/FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/FIL2.EXT",  "C:/fil1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\fil1.ext",  "C:/FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\FIL2.EXT",  "C:/fil1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/fil1.ext", "C:\\FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/FIL2.EXT", "C:\\fil1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\fil1.ext", "C:\\FIL2.EXT"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\FIL2.EXT", "C:\\fil1.ext"));


    // case of volume part

    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("C:\\file.ext", "C:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("C:\\file.ext", "c:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("c:\\file.ext", "C:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("c:\\file.ext", "c:\\FILE.EXT"));


    // different volumes

    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("C:\\file.ext", "D:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("C:\\file.ext", "d:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("c:\\file.ext", "D:\\FILE.EXT"));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("c:\\file.ext", "d:\\FILE.EXT"));

#endif
}

static void test_compare_relative_directory(void)
{
    // Just directory parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/", "dir1/"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/", "dir2/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/", "dir1/"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "DIR1/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("DIR1/",  "dir1/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("DIR1/",  "DIR1/"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "dir1/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "dir1\\"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\", "dir1/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\", "dir1\\"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/",  "DIR2/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2/",  "dir1/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/",  "DIR2\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2/",  "dir1\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\", "DIR2/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2\\", "dir1/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\", "DIR2\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2\\", "dir1\\"));
#endif
}

static void test_compare_dots_directory(void)
{
    // Just single dots dir - 1-dot

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  "."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  "./"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./", "."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./", "./"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",   "."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",   ".\\"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", "."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./",  ".\\"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", "./"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", ".\\"));
#endif
}

static void test_compare_2dotsdir(void)
{
    // Just single dots dir - 2-dot

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  ".."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "../"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../", ".."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../", "../"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",   ".."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",   "..\\"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", ".."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../",  "..\\"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "../"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "..\\"));
#endif
}

static void test_compare_mixed_dots_directory(void)
{
    // mixed dots entities

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  "."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  ".."));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("...",  "..."));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths(".",  ".."));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("..",  "...")); // '...' is a file; '..' is a directory

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("...",  "...."));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("....",  "....."));
}

static void test_compare_slash(void)
{
    // root directory

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/", "/"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/",  "\\"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\", "\\"));
#endif
}

static void test_compare_2_dirs_and_filename(void)
{
    // more complex relative paths

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir3/file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/dir3/file.ext", "dir1/dir2/file.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir21/file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/dir21/file.ext", "dir1/dir2/file.ext"));
}

static void test_compare_slash_rooted_filename(void)
{
    // absolute vs relative - no cwd

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "/file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/file.ext", "file.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file.ext", "/dir1/file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file.ext", "dir1/file.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext"));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "C:\\file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "file.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext"));
#endif
}

static void test_Windows_mixed_rooted_paths(void)
{
    // absolute vs rooted - no cwd

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\file.ext", "C:\\file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "\\file.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "\\dir1\\file.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "\\dir1\\dir2\\file.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\abcdefghijklmnopqrstuvwxyz.ext", "X:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "\\abcdefghijklmnopqrstuvwxyz.ext"));
#endif
}

static void test_mixed_with_root_pwd(void)
{
    // absolute vs relative - cwd

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "/dir1/dir2/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/dir1/dir2/file1.ext",  "file2.ext", "/dir1/dir2/"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "dir2/file1.ext", "/dir1/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/dir1/dir2/file1.ext",  "dir2/file2.ext", "/dir1/"));

#if LIBPATH_VER >= 0x00030000
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "//dir1//dir2/"));
#endif

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "/"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "/file.ext", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/file.ext", "file.ext", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file.ext", "/dir1/file.ext", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/file.ext", "dir1/file.ext", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext", "/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext", "/"));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/", "/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext", "/"));

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/file2.ext",  "file1.ext", "C:\\"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file1.ext", "C:\\dir1\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\dir1\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file2.ext",  "file1.ext", "C:\\dir1\\"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file1.ext",  "file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/file1.ext",  "file2.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/file2.ext",  "file1.ext", "C:\\"));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file1.ext",  "file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file1.ext",  "file2.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file2.ext",  "file1.ext", "C:\\"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "C:\\file.ext", "/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "file.ext", "/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext", "/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext", "/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", "/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", "/"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\", "/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext", "/"));
#endif
}

static void test_noncanonical_paths(void)
{
    // paths that need canonicalising

    // file1.ext <=> file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file1.ext", "file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file1.ext", "dir1/../file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/../file1.ext", "file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./file1.ext", "dir1/dir2/../../file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/../../file1.ext", "./file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file1.ext"));

    // dir1/file1.ext <=> dir1/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/./file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/./file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "./dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./dir1/file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/dir2/../file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/../file1.ext", "dir1/file1.ext"));

    // dir1/dir2/file1.ext <=> dir1/dir2/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file1.ext"));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file1.ext"));


    // file1.ext <=> file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "dir1/../file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/../file1.ext", "file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./file1.ext", "dir1/dir2/../../file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/../../file1.ext", "./file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file2.ext"));

    // dir1/file1.ext <=> dir1/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/./file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/./file1.ext", "dir1/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "./dir1/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./dir1/file1.ext", "dir1/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/dir2/../file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/../file1.ext", "dir1/file2.ext"));

    // dir1/dir2/file1.ext <=> dir1/dir2/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file2.ext"));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file2.ext"));


}

static void test_noncanonical_paths_trailing_dots(void)
{
    // trailing dots

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/..", "dir1/dir2/../"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/..", "dir1/dir3/../"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir3/..", "dir1/dir2/../"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/..", "dir4/dir3/../"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir4/dir3/..", "dir1/dir2/../"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/.", "dir1/dir2/./"));
}

static void test_sliding_rel_and_cwd(void)
{
    // sliding [rel / cwd]

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file2.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d6/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d5/d5/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d4/d4/d5/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d3/d3/d4/d5/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d2/d2/d3/d4/d5/file1.ext"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file2.ext", "/d1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d6/file1.ext", "/d1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d5/d5/file1.ext", "/d1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d4/d4/d5/file1.ext", "/d1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d3/d4/d5/file1.ext", "/d1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d2"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d2"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file2.ext", "/d1/d2"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d6/file1.ext", "/d1/d2"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d5/d5/file1.ext", "/d1/d2"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d4/d5/file1.ext", "/d1/d2"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d3"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d2/d2"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d3"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file2.ext", "/d1/d2/d3"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d6/file1.ext", "/d1/d2/d3"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/d5/file1.ext", "/d1/d2/d3"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d4"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d3/d3"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d2/d2/d3"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d4"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file2.ext", "/d1/d2/d3/d4"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d6/file1.ext", "/d1/d2/d3/d4"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d5"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d4/d4"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d3/d3/d4"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d2/d2/d3/d4"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d5"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file2.ext", "/d1/d2/d3/d4/d5"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d6"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d5/d5"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d4/d4/d5"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d3/d3/d4/d5"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d2/d2/d3/d4/d5"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d6"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file2.ext", "/d1/d2/d3/d4/d5/d6"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d6/d6"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d5/d5/d6"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d4/d4/d5/d6"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d3/d3/d4/d5/d6"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d2/d2/d3/d4/d5/d6"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file2.ext", "/d1/d2/d3/d4/d5/d6/d7"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d8"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d7/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d6/d6/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d5/d5/d6/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d4/d4/d5/d6/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d3/d3/d4/d5/d6/d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d2/d2/d3/d4/d5/d6/d7"));

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file2.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d8"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d7\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d6\\d6\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d5\\d5\\d6\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d4\\d4\\d5\\d6\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d3\\d3\\d4\\d5\\d6\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d2\\d2\\d3\\d4\\d5\\d6\\d7"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "D:\\d1\\d2\\d3\\d4\\d5\\d6\\d7"));
#endif
}

static void test_compare_UNC_rooted_paths(void)
{
    // UNC roots

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\\\server1\\share1/dir1\\file1.ext", "\\\\server1\\share1\\dir1/file1.ext"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file2.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1\\dir1\\file2.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir2\\file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1\\dir2\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share2\\dir1\\file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share2\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server2\\share1\\dir1\\file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server2\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));

#endif
}

static void test_Windows_mixed_pwd(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:\\"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:\\"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:"));
#endif
}

static void test_mixed_comparisons(void)
{
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "file2.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("file2.ext", "file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir2/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file1.ext", "dir1/file1.ext"));

#ifdef LIBPATH_OS_IS_WINDOWS

    // absolute, rooted, and relative paths

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:/dir1/file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:/dir1/file1.ext", "/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:/dir1/file1.ext"));


    // relative paths with volumes

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "C:"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "D:"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "C:dir1/file1.ext", "C:"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "C:"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "D:"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:"));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:/"));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext", "/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file2.ext", "/"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir2/file1.ext", "/"));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1/"));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:file1.ext", "C:/dir1/file2.ext", "/dir1"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:file2.ext", "C:/dir1/file1.ext", "/dir1"));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:file1.ext", "C:/dir2/file1.ext", "/dir1"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir2"));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:dir1/file1.ext", "/"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:"));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "file1.ext", "dir1"));
#endif
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

