/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.compare.1.c.c
 *
 * Purpose: Implementation file for the test.unit.compare.1.c project.
 *
 * Created: 28th March 2013
 * Updated: 15th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/compare.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_0(void);
static void test_1_1(void);
static void test_1_2(void);
static void test_1_3(void);
static void test_1_4(void);
static void test_1_5(void);
static void test_1_6(void);
static void test_1_7(void);
static void test_1_8(void);
static void test_1_9(void);
static void test_1_10(void);
static void test_1_11(void);
static void test_1_12(void);
static void test_1_13(void);
static void test_1_14(void);
static void test_1_15(void);
static void test_1_16(void);
static void test_1_17(void);


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.compare.1.c", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

int
compare_paths(
    char const* lhs
,   char const* rhs
,   char const* cwd
,   char const* mem
)
{
    libpath_sint32_t                    flags   =   0;
    libpath_WorkingDirectoryContext_t   ctxt;
    int                                 result;
    LIBPATH_RC                          rc;

    STLSOFT_SUPPRESS_UNUSED(mem);

    ctxt.mechanism          =   libpath_WorkingDirectoryContextMechanism_CStyleString;
    ctxt.details.cwd_css    =   cwd;

    rc = libpath_Compare_ComparePathsAsCStyleStrings(
        lhs
    ,   rhs
    ,   flags
    ,   &ctxt
    ,   LIBPATH_LF_nullptr
    ,   &result
    );

    if (LIBPATH_RC_OF(Success) != rc)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("call to `libpath_Compare_ComparePathsAsCStyleStrings()` failed", "");
    }

    return result;
}


static void test_1_0(void)
{
    // Just entry parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("fil1.ext", "fil2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("fil2.ext", "fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));


    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("...",  "...", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("...",  "....", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("....", "...", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("fil1.ext", "fil2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("FIL2.EXT", "FIL1.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_1(void)
{
    // Just rooted entry parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/file.ext", "/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/fil1.ext", "/fil2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/fil2.ext", "/fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file.ext",  "/FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\file.ext",  "/FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file.ext", "\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\file.ext", "\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/fil1.ext",  "/FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/FIL2.EXT",  "/fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\fil1.ext",  "/FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\FIL2.EXT",  "/fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/fil1.ext", "\\FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/FIL2.EXT", "\\fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\fil1.ext", "\\FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\FIL2.EXT", "\\fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_2(void)
{
    // Windows-rooted entry parts

#ifdef LIBPATH_OS_IS_WINDOWS

    // case of entry-part

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file.ext",  "C:/FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\file.ext",  "C:/FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file.ext", "C:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\file.ext", "C:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/fil1.ext",  "C:/FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/FIL2.EXT",  "C:/fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\fil1.ext",  "C:/FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\FIL2.EXT",  "C:/fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/fil1.ext", "C:\\FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/FIL2.EXT", "C:\\fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\fil1.ext", "C:\\FIL2.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\FIL2.EXT", "C:\\fil1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));


    // case of volume part

    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("C:\\file.ext", "C:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("C:\\file.ext", "c:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("c:\\file.ext", "C:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("c:\\file.ext", "c:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));


    // different volumes

    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("C:\\file.ext", "D:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("C:\\file.ext", "d:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("c:\\file.ext", "D:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("c:\\file.ext", "d:\\FILE.EXT", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#endif
}

static void test_1_3(void)
{
    // Just directory parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/", "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/", "dir2/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/", "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "DIR1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("DIR1/",  "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("DIR1/",  "DIR1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "dir1\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\", "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\", "dir1\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/",  "DIR2/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2/",  "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/",  "DIR2\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2/",  "dir1\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\", "DIR2/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2\\", "dir1/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\", "DIR2\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2\\", "dir1\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_4(void)
{
    // Just single dots dir - 1-dot

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  ".", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  "./", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./", ".", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./", "./", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",   ".", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",   ".\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", ".", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./",  ".\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", "./", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", ".\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_5(void)
{
    // Just single dots dir - 2-dot

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "..", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../", "..", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../", "../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",   "..", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",   "..\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "..", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../",  "..\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "..\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_6(void)
{
    // mixed dots entities

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  ".", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "..", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("...",  "...", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths(".",  "..", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("..",  "...", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr)); // '...' is a file; '..' is a directory

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("...",  "....", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("....",  ".....", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_7(void)
{
    // root directory

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/", "/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/",  "\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\", "/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\", "\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_8(void)
{
    // more complex relative paths

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir3/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/dir3/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir21/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/dir21/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_9(void)
{
    // absolute vs relative - no cwd

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/file.ext", "file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file.ext", "/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "C:\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_10(void)
{
    // absolute vs rooted - no cwd

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\file.ext", "C:\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "\\dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\abcdefghijklmnopqrstuvwxyz.ext", "X:\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "\\abcdefghijklmnopqrstuvwxyz.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_11(void)
{
    // absolute vs relative - cwd

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "/dir1/dir2/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/dir1/dir2/file1.ext",  "file2.ext", "/dir1/dir2/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "dir2/file1.ext", "/dir1/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/dir1/dir2/file1.ext",  "dir2/file2.ext", "/dir1/", LIBPATH_LF_nullptr));

#if LIBPATH_VER >= 0x00040000
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "//dir1//dir2/", LIBPATH_LF_nullptr));
#endif

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/", LIBPATH_LF_nullptr));



    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "/file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/file.ext", "file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file.ext", "/dir1/file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/file.ext", "dir1/file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext", "/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext", "/", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/file2.ext",  "file1.ext", "C:\\", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file1.ext", "C:\\dir1\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\dir1\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file2.ext",  "file1.ext", "C:\\dir1\\", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file1.ext",  "file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/file1.ext",  "file2.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/file2.ext",  "file1.ext", "C:\\", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file1.ext",  "file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file1.ext",  "file2.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file2.ext",  "file1.ext", "C:\\", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "C:\\file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", "/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext", "/", LIBPATH_LF_nullptr));
#endif
}

static void test_1_12(void)
{
    // paths that need canonicalising

    // file1.ext <=> file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file1.ext", "file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file1.ext", "dir1/../file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/../file1.ext", "file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./file1.ext", "dir1/dir2/../../file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/../../file1.ext", "./file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    // dir1/file1.ext <=> dir1/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/./file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/./file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "./dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./dir1/file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/dir2/../file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/../file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    // dir1/dir2/file1.ext <=> dir1/dir2/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));


    // file1.ext <=> file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "dir1/../file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/../file1.ext", "file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./file1.ext", "dir1/dir2/../../file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/../../file1.ext", "./file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    // dir1/file1.ext <=> dir1/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/./file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/./file1.ext", "dir1/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "./dir1/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./dir1/file1.ext", "dir1/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/dir2/../file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/../file1.ext", "dir1/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    // dir1/dir2/file1.ext <=> dir1/dir2/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));


}

static void test_1_13(void)
{
    // trailing dots

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/..", "dir1/dir2/../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/..", "dir1/dir3/../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir3/..", "dir1/dir2/../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/..", "dir4/dir3/../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir4/dir3/..", "dir1/dir2/../", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/.", "dir1/dir2/./", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

}

static void test_1_14(void)
{
    // sliding [rel / cwd]

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d6/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d5/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d4/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d3/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d2/d2/d3/d4/d5/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file2.ext", "/d1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d6/file1.ext", "/d1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d5/d5/file1.ext", "/d1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d4/d4/d5/file1.ext", "/d1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d3/d4/d5/file1.ext", "/d1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d2", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d2", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file2.ext", "/d1/d2", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d6/file1.ext", "/d1/d2", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d5/d5/file1.ext", "/d1/d2", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d4/d5/file1.ext", "/d1/d2", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d3", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d2/d2", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d3", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file2.ext", "/d1/d2/d3", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d6/file1.ext", "/d1/d2/d3", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/d5/file1.ext", "/d1/d2/d3", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d4", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d3/d3", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d2/d2/d3", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d4", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file2.ext", "/d1/d2/d3/d4", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d6/file1.ext", "/d1/d2/d3/d4", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d5", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d4/d4", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d3/d3/d4", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d2/d2/d3/d4", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d5", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file2.ext", "/d1/d2/d3/d4/d5", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d5/d5", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d4/d4/d5", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d3/d3/d4/d5", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d2/d2/d3/d4/d5", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file2.ext", "/d1/d2/d3/d4/d5/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d6/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d5/d5/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d4/d4/d5/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d3/d3/d4/d5/d6", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d2/d2/d3/d4/d5/d6", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file2.ext", "/d1/d2/d3/d4/d5/d6/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d8", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d7/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d6/d6/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d5/d5/d6/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d4/d4/d5/d6/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d3/d3/d4/d5/d6/d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d2/d2/d3/d4/d5/d6/d7", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file2.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d8", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d7\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d6\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d5\\d5\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d4\\d4\\d5\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d3\\d3\\d4\\d5\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d2\\d2\\d3\\d4\\d5\\d6\\d7", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "D:\\d1\\d2\\d3\\d4\\d5\\d6\\d7", LIBPATH_LF_nullptr));

#endif
}

static void test_1_15(void)
{
    // UNC roots

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\\\server1\\share1/dir1\\file1.ext", "\\\\server1\\share1\\dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1\\dir1\\file2.ext", "\\\\server1\\share1\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir2\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1\\dir2\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share2\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share2\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server2\\share1\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server2\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#endif
}

static void test_1_16(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:\\", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:\\", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:", LIBPATH_LF_nullptr));
#endif
}

static void test_1_17(void)
{
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "file2.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("file2.ext", "file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir2/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS

    // absolute, rooted, and relative paths

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:/dir1/file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:/dir1/file1.ext", "/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));


    // relative paths with volumes

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "D:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "C:dir1/file1.ext", "C:", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "D:", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file2.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir2/file1.ext", "/", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:file1.ext", "C:/dir1/file2.ext", "/dir1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:file2.ext", "C:/dir1/file1.ext", "/dir1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:file1.ext", "C:/dir2/file1.ext", "/dir1", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir2", LIBPATH_LF_nullptr));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:dir1/file1.ext", "/", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:", LIBPATH_LF_nullptr));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "file1.ext", "dir1", LIBPATH_LF_nullptr));
#endif
}


/* ///////////////////////////// end of file //////////////////////////// */

