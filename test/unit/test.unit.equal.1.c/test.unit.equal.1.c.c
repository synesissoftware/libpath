/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.equal.1.c.c
 *
 * Purpose: Implementation file for the test.unit.equal.1.c project.
 *
 * Created: 28th March 2013
 * Updated: 4th May 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/equate.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <assert.h>
#include <stdbool.h>
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

static void test_1_20(void);

static void test_1_30(void);
static void test_1_31(void);
static void test_1_32(void);
static void test_1_33(void);

static void test_1_40(void);
static void test_1_41(void);
static void test_1_42(void);
static void test_1_43(void);
static void test_1_44(void);
static void test_1_45(void);

static void test_1_50(void);


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.equal.1.c", verbosity))
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

        XTESTS_RUN_CASE(test_1_20);

        XTESTS_RUN_CASE(test_1_30);
        XTESTS_RUN_CASE(test_1_31);
        XTESTS_RUN_CASE(test_1_32);
        XTESTS_RUN_CASE(test_1_33);

        XTESTS_RUN_CASE(test_1_40);
        XTESTS_RUN_CASE(test_1_41);
        XTESTS_RUN_CASE(test_1_42);
        XTESTS_RUN_CASE(test_1_43);
        XTESTS_RUN_CASE(test_1_44);
        XTESTS_RUN_CASE(test_1_45);

        XTESTS_RUN_CASE(test_1_50);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static
bool
path_equals(
    char const* lhs
,   char const* rhs
,   char const* cwd /* = LIBPATH_LF_nullptr */
,   char const* mem /* = LIBPATH_LF_nullptr */
)
{
    libpath_sint32_t                    flags   =   0;
    libpath_WorkingDirectoryContext_t   ctxt;
    int                                 result;
    LIBPATH_RC                          rc;

    ctxt.mechanism          =   libpath_WorkingDirectoryContextMechanism_CStyleString;
    ctxt.details.cwd_css    =   cwd;

    rc = libpath_Equate_EquatePathsAsCStyleStrings(
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

    return (LIBPATH_RC_OF(Success) == rc) && (0 != result);
}


static void test_1_0(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("", "", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_1(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("", "a", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("a", "", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_2(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("file", "file", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("fil1", "fil2", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_3(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("file.ext", "file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("file.ex1", "file.ex2", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_4(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\file.ext", "dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_5(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1\\file.ext", "dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1\\file.ext", "dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_6(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/dir2/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/dir3/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/./file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "./dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/././././././././././././././././././././././././././././././././././././././././././././././file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1/dir2/../dir3/../dir4/../dir5/../dir6/../dir7/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1/dir2/dir3/dir4/dir5/dir6/dir7/../../../../../../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("../dir1/dir2/../file.ext", "../dir1/dir2/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_7(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/dir2/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/dir3/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/./file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "./dir9/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/././././././././././././././././././././././././././././././././././././././././././././././file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir9/dir2/../dir3/../dir4/../dir5/../dir6/../dir7/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir9/dir2/dir3/dir4/dir5/dir6/dir7/../../../../../../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("../dir1/dir2/../file.ext", "../dir9/dir2/../file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_8(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/../../file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "../dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}

static void test_1_9(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "D:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "C:\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_10(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server1\\share1\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server1\\share1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server1\\share2\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server2\\share1\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server10\\share10\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_11(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1/dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1\\dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1/dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1\\dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1/dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1\\dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1/dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1\\dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_20(void)
{
    // Trailing slashes

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def", "abc.def", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def/", "abc.def", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def", "abc.def/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def\\", "abc.def", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def", "abc.def\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def/", "abc.def/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def\\", "abc.def/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def/", "abc.def\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def\\", "abc.def\\", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif

}

static void test_1_30(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", "/dir1/dir2", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", "/dir1/dir8", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", "/dir1/dir2/dir3/..", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", "dir4/.././file.ext", "/./dir1/dir2/dir3/dir4//..", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/../file.ext", ".././file.ext", "/dir1/dir2/dir3/dir4", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", ".././file.ext", "/dir1/dir2/dir3/dir4", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/../file.ext", ".././../file.ext", "/dir1/dir2/dir3/dir4", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/dir4/dir5/file.ext", "file.ext", "/dir1/dir2/dir3/dir4/dir5", LIBPATH_LF_nullptr));
}

static void test_1_31(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/", "dir3", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/", "dir3", "/dir1/dir2", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/", "dir3/", "/dir1/dir2", LIBPATH_LF_nullptr));
}

static void test_1_32(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_33(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "dir1/file.ext", "/", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "C:\\dir1\\file.ext", "C:/", LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\dir1/file.ext", "C:\\dir1\\file.ext", "C:", LIBPATH_LF_nullptr));
#endif
}

static void test_1_40(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\dir1\\file.ext", "\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\dir1\\file.ext", "/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_41(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "C:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "c:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:\\dir1\\file.ext", "C:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:\\dir1\\file.ext", "c:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "C:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "c:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:/dir1/file.ext", "C:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:/dir1/file.ext", "c:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "D:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "D:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:/dir1/file.ext", "D:\\dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:/dir1/file.ext", "D:/dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1\\file.ext", "C:dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1\\file.ext", "C:dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1/file.ext", "C:dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1/file.ext", "C:dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1\\file.ext", "D:dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1\\file.ext", "D:dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1/file.ext", "D:dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1/file.ext", "D:dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
#endif
}

static void test_1_42(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/file.ext", "dir1/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "dir1/file.ext", "/", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "c:dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "c:dir1\\file.ext", "/", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "d:dir1\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "d:dir1\\file.ext", "/", LIBPATH_LF_nullptr));
#endif
}

static void test_1_43(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/file.ext", "dir2/file.ext", "/dir1", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir2\\file.ext", "/dir1", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir2\\file.ext", "\\dir1\\", LIBPATH_LF_nullptr));
#endif
}

static void test_1_44(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/file.ext", "dir1/dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/file.ext", "dir2/file.ext", "/dir1/dir2/dir3/./../..", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir2\\file.ext", "/dir1/dir2/dir3/./../..", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir1\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir2\\file.ext", "\\dir1\\dir2\\dir3\\.\\..\\..", LIBPATH_LF_nullptr));
#endif
}

static void test_1_45(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/file.ext", "dir1/dir2/dir3/./../../dir2/file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/file.ext", "./../../dir2/file.ext", "/dir1/dir2/dir3/", LIBPATH_LF_nullptr));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir1\\dir2\\dir3\\.\\..\\..\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\dir2\\file.ext", "c:.\\..\\..\\dir2\\file.ext", "/dir1/dir2/dir3", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir1\\dir2\\dir3\\.\\..\\..\\dir2\\file.ext", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:.\\..\\..\\dir2\\file.ext", "\\dir1\\dir2\\dir3", LIBPATH_LF_nullptr));
#endif
}

static void test_1_50(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/", "/dir1/dir2/dir3/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/", "/dir1/dir2/dir3", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3", "/dir1/dir2/dir3/", LIBPATH_LF_nullptr, LIBPATH_LF_nullptr));
}


/* ///////////////////////////// end of file //////////////////////////// */

