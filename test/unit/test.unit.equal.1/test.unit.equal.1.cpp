/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.equal.1.cpp
 *
 * Purpose: Implementation file for the test.unit.equal.1 project.
 *
 * Created: 9th November 2012
 * Updated: 4th May 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/equate.h>

#include <libpath/common/types.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
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
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);
    static void test_1_30(void);
    static void test_1_31(void);
    static void test_1_32(void);
    static void test_1_33(void);
    static void test_1_34(void);
    static void test_1_35(void);
    static void test_1_36(void);
    static void test_1_37(void);
    static void test_1_38(void);
    static void test_1_39(void);
    static void test_1_40(void);
    static void test_1_41(void);
    static void test_1_42(void);
    static void test_1_43(void);
    static void test_1_44(void);
    static void test_1_45(void);
    static void test_1_46(void);
    static void test_1_47(void);
    static void test_1_48(void);
    static void test_1_49(void);
    static void test_1_50(void);
    static void test_1_51(void);
    static void test_1_52(void);
    static void test_1_53(void);
    static void test_1_54(void);
    static void test_1_55(void);
    static void test_1_56(void);
    static void test_1_57(void);
    static void test_1_58(void);
    static void test_1_59(void);
    static void test_1_60(void);
    static void test_1_61(void);
    static void test_1_62(void);
    static void test_1_63(void);
    static void test_1_64(void);
    static void test_1_65(void);
    static void test_1_66(void);
    static void test_1_67(void);
    static void test_1_68(void);
    static void test_1_69(void);
    static void test_1_70(void);
    static void test_1_71(void);
    static void test_1_72(void);
    static void test_1_73(void);
    static void test_1_74(void);
    static void test_1_75(void);
    static void test_1_76(void);
    static void test_1_77(void);
    static void test_1_78(void);
    static void test_1_79(void);
    static void test_1_80(void);
    static void test_1_81(void);
    static void test_1_82(void);
    static void test_1_83(void);
    static void test_1_84(void);
    static void test_1_85(void);
    static void test_1_86(void);
    static void test_1_87(void);
    static void test_1_88(void);
    static void test_1_89(void);
    static void test_1_90(void);
    static void test_1_91(void);
    static void test_1_92(void);
    static void test_1_93(void);
    static void test_1_94(void);
    static void test_1_95(void);
    static void test_1_96(void);
    static void test_1_97(void);
    static void test_1_98(void);
    static void test_1_99(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.equal.1", verbosity))
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
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_1_30);
        XTESTS_RUN_CASE(test_1_31);
        XTESTS_RUN_CASE(test_1_32);
        XTESTS_RUN_CASE(test_1_33);
        XTESTS_RUN_CASE(test_1_34);
        XTESTS_RUN_CASE(test_1_35);
        XTESTS_RUN_CASE(test_1_36);
        XTESTS_RUN_CASE(test_1_37);
        XTESTS_RUN_CASE(test_1_38);
        XTESTS_RUN_CASE(test_1_39);
        XTESTS_RUN_CASE(test_1_40);
        XTESTS_RUN_CASE(test_1_41);
        XTESTS_RUN_CASE(test_1_42);
        XTESTS_RUN_CASE(test_1_43);
        XTESTS_RUN_CASE(test_1_44);
        XTESTS_RUN_CASE(test_1_45);
        XTESTS_RUN_CASE(test_1_46);
        XTESTS_RUN_CASE(test_1_47);
        XTESTS_RUN_CASE(test_1_48);
        XTESTS_RUN_CASE(test_1_49);
        XTESTS_RUN_CASE(test_1_50);
        XTESTS_RUN_CASE(test_1_51);
        XTESTS_RUN_CASE(test_1_52);
        XTESTS_RUN_CASE(test_1_53);
        XTESTS_RUN_CASE(test_1_54);
        XTESTS_RUN_CASE(test_1_55);
        XTESTS_RUN_CASE(test_1_56);
        XTESTS_RUN_CASE(test_1_57);
        XTESTS_RUN_CASE(test_1_58);
        XTESTS_RUN_CASE(test_1_59);
        XTESTS_RUN_CASE(test_1_60);
        XTESTS_RUN_CASE(test_1_61);
        XTESTS_RUN_CASE(test_1_62);
        XTESTS_RUN_CASE(test_1_63);
        XTESTS_RUN_CASE(test_1_64);
        XTESTS_RUN_CASE(test_1_65);
        XTESTS_RUN_CASE(test_1_66);
        XTESTS_RUN_CASE(test_1_67);
        XTESTS_RUN_CASE(test_1_68);
        XTESTS_RUN_CASE(test_1_69);
        XTESTS_RUN_CASE(test_1_70);
        XTESTS_RUN_CASE(test_1_71);
        XTESTS_RUN_CASE(test_1_72);
        XTESTS_RUN_CASE(test_1_73);
        XTESTS_RUN_CASE(test_1_74);
        XTESTS_RUN_CASE(test_1_75);
        XTESTS_RUN_CASE(test_1_76);
        XTESTS_RUN_CASE(test_1_77);
        XTESTS_RUN_CASE(test_1_78);
        XTESTS_RUN_CASE(test_1_79);
        XTESTS_RUN_CASE(test_1_80);
        XTESTS_RUN_CASE(test_1_81);
        XTESTS_RUN_CASE(test_1_82);
        XTESTS_RUN_CASE(test_1_83);
        XTESTS_RUN_CASE(test_1_84);
        XTESTS_RUN_CASE(test_1_85);
        XTESTS_RUN_CASE(test_1_86);
        XTESTS_RUN_CASE(test_1_87);
        XTESTS_RUN_CASE(test_1_88);
        XTESTS_RUN_CASE(test_1_89);
        XTESTS_RUN_CASE(test_1_90);
        XTESTS_RUN_CASE(test_1_91);
        XTESTS_RUN_CASE(test_1_92);
        XTESTS_RUN_CASE(test_1_93);
        XTESTS_RUN_CASE(test_1_94);
        XTESTS_RUN_CASE(test_1_95);
        XTESTS_RUN_CASE(test_1_96);
        XTESTS_RUN_CASE(test_1_97);
        XTESTS_RUN_CASE(test_1_98);
        XTESTS_RUN_CASE(test_1_99);

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

    inline
    bool
    path_equals(
        char const*   lhs
    ,   char const*   rhs
    ,   char const*   cwd   = LIBPATH_LF_nullptr
    ,   char const* /*mem*/ = LIBPATH_LF_nullptr
    )
    {
        libpath_sint32_t                    flags   =   0;
        libpath_WorkingDirectoryContext_t   ctxt;
        libpath_truthy_t                    result;

        ctxt.mechanism          =   libpath_WorkingDirectoryContextMechanism_CStyleString;
        ctxt.details.cwd_css    =   cwd;

        LIBPATH_RC rc = libpath_Equate_EquatePathsAsCStyleStrings(
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


        return (LIBPATH_RC_OF(Success) == rc) && (result);
    }


static void test_1_0(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("", ""));
}

static void test_1_1(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("", "a"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("a", ""));
}

static void test_1_2(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("file", "file"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("fil1", "fil2"));
}

static void test_1_3(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("file.ext", "file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("file.ex1", "file.ex2"));
}

static void test_1_4(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1/file.ext"));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\file.ext", "dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\file.ext", "dir1/file.ext"));
#endif
}

static void test_1_5(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir2/file.ext"));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1\\file.ext", "dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1\\file.ext", "dir2/file.ext"));
#endif
}

static void test_1_6(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/dir2/../file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/dir3/../file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/./file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "./dir1/file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/../file.ext", "dir1/././././././././././././././././././././././././././././././././././././././././././././././file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1/dir2/../dir3/../dir4/../dir5/../dir6/../dir7/../file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "dir1/dir2/dir3/dir4/dir5/dir6/dir7/../../../../../../file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("../dir1/dir2/../file.ext", "../dir1/dir2/../file.ext"));
}

static void test_1_7(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/dir2/../file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/dir3/../file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/./file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "./dir9/file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/dir2/../file.ext", "dir9/././././././././././././././././././././././././././././././././././././././././././././././file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir9/dir2/../dir3/../dir4/../dir5/../dir6/../dir7/../file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "dir9/dir2/dir3/dir4/dir5/dir6/dir7/../../../../../../file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("../dir1/dir2/../file.ext", "../dir9/dir2/../file.ext"));
}

static void test_1_8(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/../../file.ext", "dir1/file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "../dir1/file.ext"));
}

static void test_1_9(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "D:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "C:\\dir2\\file.ext"));
#endif
}

static void test_1_10(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server1\\share1\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server1\\share1\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server1\\share2\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server2\\share1\\dir1\\file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("\\\\server1\\share1\\dir1\\file.ext", "\\\\server10\\share10\\dir1\\file.ext"));
#endif
}

static void test_1_11(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1/dir2/file.ext"));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1/dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1/dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1\\dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1/dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1/dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1\\dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1\\dir2/file.ext", "dir1\\dir2\\file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1/dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1/dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1\\dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2\\file.ext", "dir1\\dir2\\file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1/dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1/dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1\\dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/dir2/file.ext", "dir1\\dir2\\file.ext"));
#endif
}

static void test_1_12(void)
{
}

static void test_1_13(void)
{
}

static void test_1_14(void)
{
}

static void test_1_15(void)
{
}

static void test_1_16(void)
{
}

static void test_1_17(void)
{
}

static void test_1_18(void)
{
}

static void test_1_19(void)
{
}

static void test_1_20(void)
{
    // Trailing slashes

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def", "abc.def"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def/", "abc.def"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def", "abc.def/"));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def\\", "abc.def"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("abc.def", "abc.def\\"));
#endif
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def/", "abc.def/"));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def\\", "abc.def/"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def/", "abc.def\\"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("abc.def\\", "abc.def\\"));
#endif

}

static void test_1_21(void)
{
}

static void test_1_22(void)
{
}

static void test_1_23(void)
{
}

static void test_1_24(void)
{
}

static void test_1_25(void)
{
}

static void test_1_26(void)
{
}

static void test_1_27(void)
{
}

static void test_1_28(void)
{
}

static void test_1_29(void)
{
}

static void test_1_30(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", "/dir1/dir2"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", "/dir1/dir8"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", "dir3/file.ext", "/dir1/dir2/dir3/.."));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", "dir4/.././file.ext", "/./dir1/dir2/dir3/dir4//.."));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/../file.ext", ".././file.ext", "/dir1/dir2/dir3/dir4"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/file.ext", ".././file.ext", "/dir1/dir2/dir3/dir4"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/../file.ext", ".././../file.ext", "/dir1/dir2/dir3/dir4"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/dir4/dir5/file.ext", "file.ext", "/dir1/dir2/dir3/dir4/dir5"));
}

static void test_1_31(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/", "dir3", LIBPATH_LF_nullptr));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/", "dir3", "/dir1/dir2"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/", "dir3/", "/dir1/dir2"));
}

static void test_1_32(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/file.ext", "dir1/file.ext"));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("dir1/file.ext", "C:\\dir1\\file.ext"));
#endif
}

static void test_1_33(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "dir1/file.ext", "/"));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("dir1/file.ext", "C:\\dir1\\file.ext", "C:/"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\dir1/file.ext", "C:\\dir1\\file.ext", "C:"));
#endif
}

static void test_1_34(void)
{
}

static void test_1_35(void)
{
}

static void test_1_36(void)
{
}

static void test_1_37(void)
{
}

static void test_1_38(void)
{
}

static void test_1_39(void)
{
}

static void test_1_40(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "/dir1/file.ext"));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\dir1\\file.ext", "\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("\\dir1\\file.ext", "/dir1/file.ext"));
#endif
}

static void test_1_41(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:/dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "C:/dir1/file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "c:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:\\dir1\\file.ext", "C:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:\\dir1\\file.ext", "c:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "C:/dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:/dir1/file.ext", "c:/dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:/dir1/file.ext", "C:/dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("c:/dir1/file.ext", "c:/dir1/file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "D:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "D:/dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:/dir1/file.ext", "D:\\dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:/dir1/file.ext", "D:/dir1/file.ext"));

    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1\\file.ext", "C:dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1\\file.ext", "C:dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1/file.ext", "C:dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:dir1/file.ext", "C:dir1/file.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1\\file.ext", "D:dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1\\file.ext", "D:dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1/file.ext", "D:dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:dir1/file.ext", "D:dir1/file.ext"));
#endif
}

static void test_1_42(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/file.ext", "dir1/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/file.ext", "dir1/file.ext", "/"));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "c:dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\file.ext", "c:dir1\\file.ext", "/"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "d:dir1\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\file.ext", "d:dir1\\file.ext", "/"));
#endif
}

static void test_1_43(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/file.ext", "dir1/dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/file.ext", "dir2/file.ext", "/dir1"));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir1\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir2\\file.ext", "/dir1"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir1\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir2\\file.ext", "\\dir1\\"));
#endif
}

static void test_1_44(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/file.ext", "dir1/dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/file.ext", "dir2/file.ext", "/dir1/dir2/dir3/./../.."));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir1\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir2\\file.ext", "/dir1/dir2/dir3/./../.."));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir1\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir2\\file.ext", "\\dir1\\dir2\\dir3\\.\\..\\.."));
#endif
}

static void test_1_45(void)
{
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/file.ext", "dir1/dir2/dir3/./../../dir2/file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/file.ext", "./../../dir2/file.ext", "/dir1/dir2/dir3/"));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "c:dir1\\dir2\\dir3\\.\\..\\..\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("C:\\dir1\\dir2\\file.ext", "c:.\\..\\..\\dir2\\file.ext", "/dir1/dir2/dir3"));

    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:dir1\\dir2\\dir3\\.\\..\\..\\dir2\\file.ext"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("C:\\dir1\\dir2\\file.ext", "d:.\\..\\..\\dir2\\file.ext", "\\dir1\\dir2\\dir3"));
#endif
}

static void test_1_46(void)
{
}

static void test_1_47(void)
{
}

static void test_1_48(void)
{
}

static void test_1_49(void)
{
}

static void test_1_50(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(path_equals("/dir1/dir2/dir3/", "/dir1/dir2/dir3/"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3/", "/dir1/dir2/dir3"));
    XTESTS_TEST_BOOLEAN_FALSE(path_equals("/dir1/dir2/dir3", "/dir1/dir2/dir3/"));
}

static void test_1_51(void)
{
}

static void test_1_52(void)
{
}

static void test_1_53(void)
{
}

static void test_1_54(void)
{
}

static void test_1_55(void)
{
}

static void test_1_56(void)
{
}

static void test_1_57(void)
{
}

static void test_1_58(void)
{
}

static void test_1_59(void)
{
}

static void test_1_60(void)
{
}

static void test_1_61(void)
{
}

static void test_1_62(void)
{
}

static void test_1_63(void)
{
}

static void test_1_64(void)
{
}

static void test_1_65(void)
{
}

static void test_1_66(void)
{
}

static void test_1_67(void)
{
}

static void test_1_68(void)
{
}

static void test_1_69(void)
{
}

static void test_1_70(void)
{
}

static void test_1_71(void)
{
}

static void test_1_72(void)
{
}

static void test_1_73(void)
{
}

static void test_1_74(void)
{
}

static void test_1_75(void)
{
}

static void test_1_76(void)
{
}

static void test_1_77(void)
{
}

static void test_1_78(void)
{
}

static void test_1_79(void)
{
}

static void test_1_80(void)
{
}

static void test_1_81(void)
{
}

static void test_1_82(void)
{
}

static void test_1_83(void)
{
}

static void test_1_84(void)
{
}

static void test_1_85(void)
{
}

static void test_1_86(void)
{
}

static void test_1_87(void)
{
}

static void test_1_88(void)
{
}

static void test_1_89(void)
{
}

static void test_1_90(void)
{
}

static void test_1_91(void)
{
}

static void test_1_92(void)
{
}

static void test_1_93(void)
{
}

static void test_1_94(void)
{
}

static void test_1_95(void)
{
}

static void test_1_96(void)
{
}

static void test_1_97(void)
{
}

static void test_1_98(void)
{
}

static void test_1_99(void)
{
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

