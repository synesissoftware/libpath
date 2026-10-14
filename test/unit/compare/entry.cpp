/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/compare/entry.cpp
 *
 * Purpose: Unit-tests the libpath C++ compare API.
 *
 * Created: 17th February 2013
 * Updated: 14th October 2026
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
#include <xtests/terse-api.h>

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

    if (XTESTS_START_RUNNER("test.unit.compare", verbosity))
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

    TEST_INT_EQ(0,   compare_paths("file.ext", "file.ext"));

    TEST_INT_LT(0,    compare_paths("fil1.ext", "fil2.ext"));
    TEST_INT_GT(0, compare_paths("fil2.ext", "fil1.ext"));


    TEST_INT_EQ(0,   compare_paths("...",  "..."));

    TEST_INT_LT(0,    compare_paths("...",  "...."));
    TEST_INT_GT(0, compare_paths("....", "..."));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0,   compare_paths("file.ext", "FILE.EXT"));

    TEST_INT_LT(0,    compare_paths("fil1.ext", "fil2.ext"));
    TEST_INT_GT(0, compare_paths("FIL2.EXT", "FIL1.EXT"));
#endif
}

static void test_compare_slash_rooted_filenames(void)
{
    // Just rooted entry parts

    TEST_INT_EQ(0,   compare_paths("/file.ext", "/file.ext"));

    TEST_INT_LT(0,    compare_paths("/fil1.ext", "/fil2.ext"));
    TEST_INT_GT(0, compare_paths("/fil2.ext", "/fil1.ext"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0,   compare_paths( "/file.ext",  "/FILE.EXT"));
    TEST_INT_EQ(0,   compare_paths("\\file.ext",  "/FILE.EXT"));
    TEST_INT_EQ(0,   compare_paths( "/file.ext", "\\FILE.EXT"));
    TEST_INT_EQ(0,   compare_paths("\\file.ext", "\\FILE.EXT"));

    TEST_INT_LT(0,    compare_paths( "/fil1.ext",  "/FIL2.EXT"));
    TEST_INT_GT(0, compare_paths( "/FIL2.EXT",  "/fil1.ext"));
    TEST_INT_LT(0,    compare_paths("\\fil1.ext",  "/FIL2.EXT"));
    TEST_INT_GT(0, compare_paths("\\FIL2.EXT",  "/fil1.ext"));
    TEST_INT_LT(0,    compare_paths( "/fil1.ext", "\\FIL2.EXT"));
    TEST_INT_GT(0, compare_paths( "/FIL2.EXT", "\\fil1.ext"));
    TEST_INT_LT(0,    compare_paths("\\fil1.ext", "\\FIL2.EXT"));
    TEST_INT_GT(0, compare_paths("\\FIL2.EXT", "\\fil1.ext"));
#endif
}

static void test_compare_Windows_drive_rooted_filenames(void)
{
    // Windows-rooted entry parts

#ifdef LIBPATH_OS_IS_WINDOWS

    // case of entry-part

    TEST_INT_EQ(0,   compare_paths( "C:/file.ext",  "C:/FILE.EXT"));
    TEST_INT_EQ(0,   compare_paths("C:\\file.ext",  "C:/FILE.EXT"));
    TEST_INT_EQ(0,   compare_paths( "C:/file.ext", "C:\\FILE.EXT"));
    TEST_INT_EQ(0,   compare_paths("C:\\file.ext", "C:\\FILE.EXT"));

    TEST_INT_LT(0,    compare_paths( "C:/fil1.ext",  "C:/FIL2.EXT"));
    TEST_INT_GT(0, compare_paths( "C:/FIL2.EXT",  "C:/fil1.ext"));
    TEST_INT_LT(0,    compare_paths("C:\\fil1.ext",  "C:/FIL2.EXT"));
    TEST_INT_GT(0, compare_paths("C:\\FIL2.EXT",  "C:/fil1.ext"));
    TEST_INT_LT(0,    compare_paths( "C:/fil1.ext", "C:\\FIL2.EXT"));
    TEST_INT_GT(0, compare_paths( "C:/FIL2.EXT", "C:\\fil1.ext"));
    TEST_INT_LT(0,    compare_paths("C:\\fil1.ext", "C:\\FIL2.EXT"));
    TEST_INT_GT(0, compare_paths("C:\\FIL2.EXT", "C:\\fil1.ext"));


    // case of volume part

    TEST_INT_EQ(0,  compare_paths("C:\\file.ext", "C:\\FILE.EXT"));
    TEST_INT_EQ(0,  compare_paths("C:\\file.ext", "c:\\FILE.EXT"));
    TEST_INT_EQ(0,  compare_paths("c:\\file.ext", "C:\\FILE.EXT"));
    TEST_INT_EQ(0,  compare_paths("c:\\file.ext", "c:\\FILE.EXT"));


    // different volumes

    TEST_INT_LT(0,   compare_paths("C:\\file.ext", "D:\\FILE.EXT"));
    TEST_INT_LT(0,   compare_paths("C:\\file.ext", "d:\\FILE.EXT"));
    TEST_INT_LT(0,   compare_paths("c:\\file.ext", "D:\\FILE.EXT"));
    TEST_INT_LT(0,   compare_paths("c:\\file.ext", "d:\\FILE.EXT"));

#endif
}

static void test_compare_relative_directory(void)
{
    // Just directory parts

    TEST_INT_EQ(0,   compare_paths("dir1/", "dir1/"));

    TEST_INT_LT(0,    compare_paths("dir1/", "dir2/"));
    TEST_INT_GT(0, compare_paths("dir2/", "dir1/"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0,   compare_paths("dir1/",  "DIR1/"));
    TEST_INT_EQ(0,   compare_paths("DIR1/",  "dir1/"));
    TEST_INT_EQ(0,   compare_paths("DIR1/",  "DIR1/"));

    TEST_INT_EQ(0,   compare_paths("dir1/",  "dir1/"));
    TEST_INT_EQ(0,   compare_paths("dir1/",  "dir1\\"));
    TEST_INT_EQ(0,   compare_paths("dir1\\", "dir1/"));
    TEST_INT_EQ(0,   compare_paths("dir1\\", "dir1\\"));

    TEST_INT_LT(0,    compare_paths("dir1/",  "DIR2/"));
    TEST_INT_GT(0, compare_paths("DIR2/",  "dir1/"));
    TEST_INT_LT(0,    compare_paths("dir1/",  "DIR2\\"));
    TEST_INT_GT(0, compare_paths("DIR2/",  "dir1\\"));
    TEST_INT_LT(0,    compare_paths("dir1\\", "DIR2/"));
    TEST_INT_GT(0, compare_paths("DIR2\\", "dir1/"));
    TEST_INT_LT(0,    compare_paths("dir1\\", "DIR2\\"));
    TEST_INT_GT(0, compare_paths("DIR2\\", "dir1\\"));
#endif
}

static void test_compare_dots_directory(void)
{
    // Just single dots dir - 1-dot

    TEST_INT_EQ(0,   compare_paths(".",  "."));
    TEST_INT_EQ(0,   compare_paths(".",  "./"));
    TEST_INT_EQ(0,   compare_paths("./", "."));
    TEST_INT_EQ(0,   compare_paths("./", "./"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0,   compare_paths(".",   "."));
    TEST_INT_EQ(0,   compare_paths(".",   ".\\"));
    TEST_INT_EQ(0,   compare_paths(".\\", "."));
    TEST_INT_EQ(0,   compare_paths("./",  ".\\"));
    TEST_INT_EQ(0,   compare_paths(".\\", "./"));
    TEST_INT_EQ(0,   compare_paths(".\\", ".\\"));
#endif
}

static void test_compare_2dotsdir(void)
{
    // Just single dots dir - 2-dot

    TEST_INT_EQ(0,   compare_paths("..",  ".."));
    TEST_INT_EQ(0,   compare_paths("..",  "../"));
    TEST_INT_EQ(0,   compare_paths("../", ".."));
    TEST_INT_EQ(0,   compare_paths("../", "../"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0,   compare_paths("..",   ".."));
    TEST_INT_EQ(0,   compare_paths("..",   "..\\"));
    TEST_INT_EQ(0,   compare_paths("..\\", ".."));
    TEST_INT_EQ(0,   compare_paths("../",  "..\\"));
    TEST_INT_EQ(0,   compare_paths("..\\", "../"));
    TEST_INT_EQ(0,   compare_paths("..\\", "..\\"));
#endif
}

static void test_compare_mixed_dots_directory(void)
{
    // mixed dots entities

    TEST_INT_EQ(0,   compare_paths(".",  "."));
    TEST_INT_EQ(0,   compare_paths("..",  ".."));
    TEST_INT_EQ(0,   compare_paths("...",  "..."));

    TEST_INT_LT(0,    compare_paths(".",  ".."));
    TEST_INT_GT(0, compare_paths("..",  "...")); // '...' is a file; '..' is a directory

    TEST_INT_LT(0,    compare_paths("...",  "...."));
    TEST_INT_LT(0,    compare_paths("....",  "....."));
}

static void test_compare_slash(void)
{
    // root directory

    TEST_INT_EQ(0,   compare_paths("/", "/"));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0,   compare_paths("/",  "\\"));
    TEST_INT_EQ(0,   compare_paths("\\", "/"));
    TEST_INT_EQ(0,   compare_paths("\\", "\\"));
#endif
}

static void test_compare_2_dirs_and_filename(void)
{
    // more complex relative paths

    TEST_INT_LT(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir3/file.ext"));
    TEST_INT_GT(0, compare_paths("dir1/dir3/file.ext", "dir1/dir2/file.ext"));

    TEST_INT_LT(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir21/file.ext"));
    TEST_INT_GT(0, compare_paths("dir1/dir21/file.ext", "dir1/dir2/file.ext"));
}

static void test_compare_slash_rooted_filename(void)
{
    // absolute vs relative - no cwd

    TEST_INT_LT(0,    compare_paths("file.ext", "/file.ext"));
    TEST_INT_GT(0, compare_paths("/file.ext", "file.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file.ext", "/dir1/file.ext"));
    TEST_INT_GT(0, compare_paths("/dir1/file.ext", "dir1/file.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext"));
    TEST_INT_GT(0, compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext"));

    TEST_INT_LT(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/"));
    TEST_INT_GT(0, compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext"));

#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_LT(0,    compare_paths("file.ext", "C:\\file.ext"));
    TEST_INT_GT(0, compare_paths("C:\\file.ext", "file.ext"));
    TEST_INT_LT(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext"));
    TEST_INT_GT(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext"));
    TEST_INT_LT(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext"));
    TEST_INT_GT(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext"));

    TEST_INT_LT(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\"));
    TEST_INT_GT(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext"));
#endif
}

static void test_Windows_mixed_rooted_paths(void)
{
    // absolute vs rooted - no cwd

#ifdef LIBPATH_OS_IS_WINDOWS

    TEST_INT_LT(0,    compare_paths("\\file.ext", "C:\\file.ext"));
    TEST_INT_GT(0, compare_paths("C:\\file.ext", "\\file.ext"));
    TEST_INT_LT(0,    compare_paths("\\dir1\\file.ext", "C:\\dir1\\file.ext"));
    TEST_INT_GT(0, compare_paths("C:\\dir1\\file.ext", "\\dir1\\file.ext"));
    TEST_INT_LT(0,    compare_paths("\\dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext"));
    TEST_INT_GT(0, compare_paths("C:\\dir1\\dir2\\file.ext", "\\dir1\\dir2\\file.ext"));

    TEST_INT_LT(0,    compare_paths("\\abcdefghijklmnopqrstuvwxyz.ext", "X:\\"));
    TEST_INT_GT(0, compare_paths("X:\\", "\\abcdefghijklmnopqrstuvwxyz.ext"));
#endif
}

static void test_mixed_with_root_pwd(void)
{
    // absolute vs relative - cwd

    TEST_INT_EQ(0,   compare_paths( "/file1.ext",  "file1.ext", "/"));
    TEST_INT_LT(0,    compare_paths( "/file1.ext",  "file2.ext", "/"));

    TEST_INT_EQ(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "/dir1/dir2/"));
    TEST_INT_LT(0,    compare_paths( "/dir1/dir2/file1.ext",  "file2.ext", "/dir1/dir2/"));

    TEST_INT_EQ(0,   compare_paths( "/dir1/dir2/file1.ext",  "dir2/file1.ext", "/dir1/"));
    TEST_INT_LT(0,    compare_paths( "/dir1/dir2/file1.ext",  "dir2/file2.ext", "/dir1/"));

#if LIBPATH_VER >= 0x00040000
    TEST_INT_EQ(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "//dir1//dir2/"));
#endif

    TEST_INT_LT(0,    compare_paths( "/file1.ext",  "file2.ext", "/"));

    TEST_INT_LT(0,    compare_paths( "/file1.ext",  "file2.ext", "/"));
    TEST_INT_EQ(0,   compare_paths( "/file1.ext",  "file1.ext", "/"));

    TEST_INT_EQ(0,   compare_paths("file.ext", "/file.ext", "/"));
    TEST_INT_EQ(0,   compare_paths("/file.ext", "file.ext", "/"));
    TEST_INT_EQ(0,   compare_paths("dir1/file.ext", "/dir1/file.ext", "/"));
    TEST_INT_EQ(0,   compare_paths("/dir1/file.ext", "dir1/file.ext", "/"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext", "/"));
    TEST_INT_EQ(0,   compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext", "/"));

    TEST_INT_GT(0, compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/", "/"));
    TEST_INT_LT(0,    compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext", "/"));

#ifdef LIBPATH_OS_IS_WINDOWS

    TEST_INT_EQ(0,   compare_paths( "/file1.ext",  "file1.ext", "C:\\"));
    TEST_INT_LT(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths( "/file2.ext",  "file1.ext", "C:\\"));

    TEST_INT_LT(0,    compare_paths( "/file1.ext",  "file1.ext", "C:\\dir1\\"));
    TEST_INT_LT(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\dir1\\"));
    TEST_INT_LT(0,    compare_paths( "/file2.ext",  "file1.ext", "C:\\dir1\\"));

    TEST_INT_EQ(0,   compare_paths( "C:/file1.ext",  "file1.ext", "C:\\"));
    TEST_INT_LT(0,    compare_paths( "C:/file1.ext",  "file2.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths( "C:/file2.ext",  "file1.ext", "C:\\"));

    TEST_INT_GT(0, compare_paths( "D:/file1.ext",  "file1.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths( "D:/file1.ext",  "file2.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths( "D:/file2.ext",  "file1.ext", "C:\\"));

    TEST_INT_LT(0,    compare_paths("file.ext", "C:\\file.ext", "/"));
    TEST_INT_GT(0, compare_paths("C:\\file.ext", "file.ext", "/"));
    TEST_INT_LT(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext", "/"));
    TEST_INT_GT(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext", "/"));
    TEST_INT_LT(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", "/"));
    TEST_INT_GT(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", "/"));

    TEST_INT_LT(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\", "/"));
    TEST_INT_GT(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext", "/"));
#endif
}

static void test_noncanonical_paths(void)
{
    // paths that need canonicalising

    // file1.ext <=> file1.ext
    TEST_INT_EQ(0,   compare_paths("file1.ext", "file1.ext"));
    TEST_INT_EQ(0,   compare_paths("file1.ext", "dir1/../file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/../file1.ext", "file1.ext"));
    TEST_INT_EQ(0,   compare_paths("./file1.ext", "dir1/dir2/../../file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/../../file1.ext", "./file1.ext"));
    TEST_INT_EQ(0,   compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file1.ext"));

    // dir1/file1.ext <=> dir1/file1.ext
    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "dir1/./file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/./file1.ext", "dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "./dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("./dir1/file1.ext", "dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "dir1/dir2/../file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/../file1.ext", "dir1/file1.ext"));

    // dir1/dir2/file1.ext <=> dir1/dir2/file1.ext
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file1.ext"));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file1.ext
    TEST_INT_EQ(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext"));

    TEST_INT_EQ(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext"));
    TEST_INT_EQ(0,   compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file1.ext"));


    // file1.ext <=> file2.ext
    TEST_INT_LT(0,    compare_paths("file1.ext", "file2.ext"));
    TEST_INT_LT(0,    compare_paths("file1.ext", "dir1/../file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/../file1.ext", "file2.ext"));
    TEST_INT_LT(0,    compare_paths("./file1.ext", "dir1/dir2/../../file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/dir2/../../file1.ext", "./file2.ext"));
    TEST_INT_LT(0,    compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file2.ext"));

    // dir1/file1.ext <=> dir1/file2.ext
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "dir1/file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "dir1/./file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/./file1.ext", "dir1/file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "./dir1/file2.ext"));
    TEST_INT_LT(0,    compare_paths("./dir1/file1.ext", "dir1/file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "dir1/dir2/../file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/dir2/../file1.ext", "dir1/file2.ext"));

    // dir1/dir2/file1.ext <=> dir1/dir2/file2.ext
    TEST_INT_LT(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file2.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file2.ext"));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file2.ext
    TEST_INT_LT(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext"));
    TEST_INT_LT(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file2.ext"));
    TEST_INT_LT(0,    compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext"));

    TEST_INT_LT(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext"));
    TEST_INT_LT(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file2.ext"));
    TEST_INT_LT(0,    compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file2.ext"));
}

static void test_noncanonical_paths_trailing_dots(void)
{
    // trailing dots

    TEST_INT_EQ(0,   compare_paths("dir1/dir2/..", "dir1/dir2/../"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir2/..", "dir1/dir3/../"));
    TEST_INT_EQ(0,   compare_paths("dir1/dir3/..", "dir1/dir2/../"));
    TEST_INT_LT(0,    compare_paths("dir1/dir2/..", "dir4/dir3/../"));
    TEST_INT_GT(0, compare_paths("dir4/dir3/..", "dir1/dir2/../"));

    TEST_INT_EQ(0,   compare_paths("dir1/dir2/.", "dir1/dir2/./"));
}

static void test_sliding_rel_and_cwd(void)
{
    // sliding [rel / cwd]

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file2.ext"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d6/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d5/d5/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d4/d4/d5/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d3/d3/d4/d5/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d2/d2/d3/d4/d5/file1.ext"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d1"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file2.ext", "/d1"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d6/file1.ext", "/d1"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d5/d5/file1.ext", "/d1"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d4/d4/d5/file1.ext", "/d1"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d3/d4/d5/file1.ext", "/d1"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d2"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d2"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file2.ext", "/d1/d2"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d6/file1.ext", "/d1/d2"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d5/d5/file1.ext", "/d1/d2"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d4/d5/file1.ext", "/d1/d2"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d3"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d2/d2"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d3"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file2.ext", "/d1/d2/d3"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d6/file1.ext", "/d1/d2/d3"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/d5/file1.ext", "/d1/d2/d3"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d4"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d3/d3"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d2/d2/d3"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d4"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file2.ext", "/d1/d2/d3/d4"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d6/file1.ext", "/d1/d2/d3/d4"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d5"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d4/d4"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d3/d3/d4"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d2/d2/d3/d4"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d5"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file2.ext", "/d1/d2/d3/d4/d5"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d6"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d5/d5"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d4/d4/d5"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d3/d3/d4/d5"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d2/d2/d3/d4/d5"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d6"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file2.ext", "/d1/d2/d3/d4/d5/d6"));
    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d6/d6"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d5/d5/d6"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d4/d4/d5/d6"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d3/d3/d4/d5/d6"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d2/d2/d3/d4/d5/d6"));

    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file2.ext", "/d1/d2/d3/d4/d5/d6/d7"));
    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d8"));
    TEST_INT_EQ(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d7/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d6/d6/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d5/d5/d6/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d4/d4/d5/d6/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d3/d3/d4/d5/d6/d7"));
    TEST_INT_LT(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d2/d2/d3/d4/d5/d6/d7"));

#ifdef LIBPATH_OS_IS_WINDOWS

    TEST_INT_EQ(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file2.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7"));
    TEST_INT_EQ(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d8"));
    TEST_INT_EQ(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d7\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d6\\d6\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d5\\d5\\d6\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d4\\d4\\d5\\d6\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d3\\d3\\d4\\d5\\d6\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d2\\d2\\d3\\d4\\d5\\d6\\d7"));
    TEST_INT_LT(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "D:\\d1\\d2\\d3\\d4\\d5\\d6\\d7"));
#endif
}

static void test_compare_UNC_rooted_paths(void)
{
    // UNC roots

#ifdef LIBPATH_OS_IS_WINDOWS

    TEST_INT_EQ(0,   compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    TEST_INT_EQ(0,   compare_paths("\\\\server1\\share1/dir1\\file1.ext", "\\\\server1\\share1\\dir1/file1.ext"));

    TEST_INT_LT(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file2.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1\\dir1\\file2.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    TEST_INT_LT(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir2\\file1.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1\\dir2\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    TEST_INT_LT(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share2\\dir1\\file1.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share2\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));
    TEST_INT_LT(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server2\\share1\\dir1\\file1.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server2\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext"));

#endif
}

static void test_Windows_mixed_pwd(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS

    TEST_INT_EQ(0,   compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:\\"));
    TEST_INT_LT(0,    compare_paths("dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths("dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:\\"));
    TEST_INT_LT(0,    compare_paths("dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths("dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:\\"));
    TEST_INT_LT(0,    compare_paths("dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:\\"));
    TEST_INT_GT(0, compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:\\"));

    TEST_INT_EQ(0,   compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:"));
    TEST_INT_LT(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:"));
    TEST_INT_GT(0, compare_paths("\\dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:"));
    TEST_INT_LT(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:"));
    TEST_INT_GT(0, compare_paths("\\dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:"));
    TEST_INT_LT(0,    compare_paths("\\dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:"));
    TEST_INT_GT(0, compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:"));
#endif
}

static void test_mixed_comparisons(void)
{
    TEST_INT_LT(0,    compare_paths("file1.ext", "file2.ext"));
    TEST_INT_GT(0, compare_paths("file2.ext", "file1.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "dir2/file1.ext"));
    TEST_INT_GT(0, compare_paths("dir2/file1.ext", "dir1/file1.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "/dir1/file1.ext"));
    TEST_INT_GT(0, compare_paths("/dir1/file1.ext", "dir1/file1.ext"));

#ifdef LIBPATH_OS_IS_WINDOWS

    // absolute, rooted, and relative paths

    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext"));
    TEST_INT_GT(0, compare_paths("C:/dir1/file1.ext", "dir1/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext"));
    TEST_INT_GT(0, compare_paths("C:/dir1/file1.ext", "/dir1/file1.ext"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext"));
    TEST_INT_LT(0,    compare_paths("/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "/dir1/file1.ext"));
    TEST_INT_LT(0,    compare_paths("C:/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:/dir1/file1.ext"));


    // relative paths with volumes

    TEST_INT_EQ(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "C:"));
    TEST_INT_EQ(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "D:"));
    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "C:dir1/file1.ext", "C:"));

    TEST_INT_EQ(0,   compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "C:"));
    TEST_INT_GT(0, compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "D:"));

    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:"));
    TEST_INT_GT(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:"));

    TEST_INT_GT(0, compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:/"));
    TEST_INT_GT(0, compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:/"));
    TEST_INT_LT(0,    compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:"));
    TEST_INT_LT(0,    compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:"));

    TEST_INT_EQ(0,   compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:/"));
    TEST_INT_GT(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:/"));
    TEST_INT_LT(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:/"));

    TEST_INT_LT(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext"));
    TEST_INT_EQ(0,   compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext", "/"));
    TEST_INT_LT(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file2.ext", "/"));
    TEST_INT_LT(0,    compare_paths("C:dir1/file1.ext", "C:/dir2/file1.ext", "/"));

    TEST_INT_EQ(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1/"));
    TEST_INT_EQ(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1"));
    TEST_INT_LT(0,    compare_paths("C:file1.ext", "C:/dir1/file2.ext", "/dir1"));
    TEST_INT_GT(0, compare_paths("C:file2.ext", "C:/dir1/file1.ext", "/dir1"));
    TEST_INT_LT(0,    compare_paths("C:file1.ext", "C:/dir2/file1.ext", "/dir1"));
    TEST_INT_GT(0, compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir2"));

    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:/"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:dir1/file1.ext", "/"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:"));
    TEST_INT_GT(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "file1.ext", "dir1"));
#endif
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

