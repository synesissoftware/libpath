/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.compare.1.c.c
 *
 * Purpose:     Implementation file for the test.unit.compare.1.c project.
 *
 * Created:     28th March 2013
 * Updated:     20th November 2016
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2013-2016, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/compare.h>

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

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.compare.1.c", verbosity))
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

    ctxt.mechanism          =   libpath_WorkingDirectoryContextMechanism_CStyleString;
    ctxt.details.cwd_css    =   cwd;

    rc = libpath_Compare_ComparePathsAsCStyleStrings(
        lhs
    ,   rhs
    ,   flags
    ,   &ctxt
    ,   NULL
    ,   &result
    );

    if(LIBPATH_RESULTCODE(Success) != rc)
    {
#ifdef _DEBUG
#else /* ? _DEBUG */
        throw std::runtime_error("oops!");
#endif /* _DEBUG */
    }

    return result;
}


static void test_1_0(void)
{
    // Just entry parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "file.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("fil1.ext", "fil2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("fil2.ext", "fil1.ext", NULL, NULL));


    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("...",  "...", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("...",  "....", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("....", "...", NULL, NULL));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "FILE.EXT", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("fil1.ext", "fil2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("FIL2.EXT", "FIL1.EXT", NULL, NULL));
#endif
}

static void test_1_1(void)
{
    // Just rooted entry parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/file.ext", "/file.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/fil1.ext", "/fil2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/fil2.ext", "/fil1.ext", NULL, NULL));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file.ext",  "/FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\file.ext",  "/FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file.ext", "\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\file.ext", "\\FILE.EXT", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/fil1.ext",  "/FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/FIL2.EXT",  "/fil1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\fil1.ext",  "/FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\FIL2.EXT",  "/fil1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/fil1.ext", "\\FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/FIL2.EXT", "\\fil1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\fil1.ext", "\\FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\FIL2.EXT", "\\fil1.ext", NULL, NULL));
#endif
}

static void test_1_2(void)
{
    // Windows-rooted entry parts

#ifdef LIBPATH_OS_IS_WINDOWS

    // case of entry-part

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file.ext",  "C:/FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\file.ext",  "C:/FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file.ext", "C:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\file.ext", "C:\\FILE.EXT", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/fil1.ext",  "C:/FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/FIL2.EXT",  "C:/fil1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\fil1.ext",  "C:/FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\FIL2.EXT",  "C:/fil1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/fil1.ext", "C:\\FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/FIL2.EXT", "C:\\fil1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\fil1.ext", "C:\\FIL2.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\FIL2.EXT", "C:\\fil1.ext", NULL, NULL));


    // case of volume part

    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("C:\\file.ext", "C:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("C:\\file.ext", "c:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("c:\\file.ext", "C:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,  compare_paths("c:\\file.ext", "c:\\FILE.EXT", NULL, NULL));


    // different volumes

    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("C:\\file.ext", "D:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("C:\\file.ext", "d:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("c:\\file.ext", "D:\\FILE.EXT", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,   compare_paths("c:\\file.ext", "d:\\FILE.EXT", NULL, NULL));

#endif
}

static void test_1_3(void)
{
    // Just directory parts

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/", "dir1/", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/", "dir2/", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/", "dir1/", NULL, NULL));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "DIR1/", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("DIR1/",  "dir1/", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("DIR1/",  "DIR1/", NULL, NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "dir1/", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/",  "dir1\\", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\", "dir1/", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\", "dir1\\", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/",  "DIR2/", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2/",  "dir1/", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/",  "DIR2\\", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2/",  "dir1\\", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\", "DIR2/", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2\\", "dir1/", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\", "DIR2\\", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("DIR2\\", "dir1\\", NULL, NULL));
#endif
}

static void test_1_4(void)
{
    // Just single dots dir - 1-dot

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  ".", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  "./", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./", ".", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./", "./", NULL, NULL));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",   ".", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",   ".\\", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", ".", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./",  ".\\", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", "./", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".\\", ".\\", NULL, NULL));
#endif
}

static void test_1_5(void)
{
    // Just single dots dir - 2-dot

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "..", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "../", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../", "..", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../", "../", NULL, NULL));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",   "..", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",   "..\\", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "..", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("../",  "..\\", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "../", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..\\", "..\\", NULL, NULL));
#endif
}

static void test_1_6(void)
{
    // mixed dots entities

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths(".",  ".", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("..",  "..", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("...",  "...", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths(".",  "..", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("..",  "...", NULL, NULL)); // '...' is a file; '..' is a directory

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("...",  "....", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("....",  ".....", NULL, NULL));
}

static void test_1_7(void)
{
    // root directory

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/", "/", NULL, NULL));

#ifdef LIBPATH_OS_IS_UNIX
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/",  "\\", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\", "/", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\", "\\", NULL, NULL));
#endif
}

static void test_1_8(void)
{
    // more complex relative paths

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir3/file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/dir3/file.ext", "dir1/dir2/file.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "dir1/dir21/file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/dir21/file.ext", "dir1/dir2/file.ext", NULL, NULL));
}

static void test_1_9(void)
{
    // absolute vs relative - no cwd

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "/file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/file.ext", "file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file.ext", "/dir1/file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file.ext", "dir1/file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext", NULL, NULL));

#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "C:\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext", NULL, NULL));
#endif
}

static void test_1_10(void)
{
    // absolute vs rooted - no cwd

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\file.ext", "C:\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file.ext", "C:\\dir1\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "\\dir1\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "\\dir1\\dir2\\file.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\abcdefghijklmnopqrstuvwxyz.ext", "X:\\", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "\\abcdefghijklmnopqrstuvwxyz.ext", NULL, NULL));
#endif
}

static void test_1_11(void)
{
    // absolute vs relative - cwd

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "/dir1/dir2/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/dir1/dir2/file1.ext",  "file2.ext", "/dir1/dir2/", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "dir2/file1.ext", "/dir1/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/dir1/dir2/file1.ext",  "dir2/file2.ext", "/dir1/", NULL));

#ifdef _DEBUG
#else /* ? _DEBUG */
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/dir1/dir2/file1.ext",  "file1.ext", "//dir1//dir2/", NULL));
#endif /* _DEBUG */

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/", NULL));



    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "/", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file.ext", "/file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/file.ext", "file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file.ext", "/dir1/file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/file.ext", "dir1/file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file.ext", "/dir1/dir2/file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/dir2/file.ext", "dir1/dir2/file.ext", "/", NULL));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "/", "/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/", "abcdefghijklmnopqrstuvwxyz.ext", "/", NULL));

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "/file1.ext",  "file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "/file2.ext",  "file1.ext", "C:\\", NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file1.ext", "C:\\dir1\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file1.ext",  "file2.ext", "C:\\dir1\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "/file2.ext",  "file1.ext", "C:\\dir1\\", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths( "C:/file1.ext",  "file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths( "C:/file1.ext",  "file2.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "C:/file2.ext",  "file1.ext", "C:\\", NULL));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file1.ext",  "file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file1.ext",  "file2.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths( "D:/file2.ext",  "file1.ext", "C:\\", NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file.ext", "C:\\file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\file.ext", "file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file.ext", "C:\\dir1\\file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\file.ext", "dir1\\file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\dir2\\file.ext", "C:\\dir1\\dir2\\file.ext", "/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:\\dir1\\dir2\\file.ext", "dir1\\dir2\\file.ext", "/", NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("abcdefghijklmnopqrstuvwxyz.ext", "X:\\", "/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("X:\\", "abcdefghijklmnopqrstuvwxyz.ext", "/", NULL));
#endif
}

static void test_1_12(void)
{
    // paths that need canonicalising

    // file1.ext <=> file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file1.ext", "file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("file1.ext", "dir1/../file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/../file1.ext", "file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./file1.ext", "dir1/dir2/../../file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/../../file1.ext", "./file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file1.ext", NULL, NULL));

    // dir1/file1.ext <=> dir1/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/./file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/./file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "./dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./dir1/file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "dir1/dir2/../file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/../file1.ext", "dir1/file1.ext", NULL, NULL));

    // dir1/dir2/file1.ext <=> dir1/dir2/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file1.ext", NULL, NULL));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file1.ext
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file1.ext", NULL, NULL));


    // file1.ext <=> file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "dir1/../file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/../file1.ext", "file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./file1.ext", "dir1/dir2/../../file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/../../file1.ext", "./file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./file1.ext", "dir1/../dir2/../dir3/../file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/../dir2/../dir3/../file1.ext", "./file2.ext", NULL, NULL));

    // dir1/file1.ext <=> dir1/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/./file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/./file1.ext", "dir1/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "./dir1/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./dir1/file1.ext", "dir1/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/././././././././././././././././././././././././././././././././file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/././././././././././././././././././././././././././././././././file1.ext", "dir1/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir1/dir2/../file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/../file1.ext", "dir1/file2.ext", NULL, NULL));

    // dir1/dir2/file1.ext <=> dir1/dir2/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/./dir2/./file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/./dir2/./file1.ext", "dir1/dir2/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/file1.ext", "dir1/dir2/dir3/../file2.ext", NULL, NULL));

    // d1/d2/d3/d4/d5/file1.ext <=> d1/d2/d3/d4/d5/file2.ext
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "./d1/./d2/./d3/./d4/./d5/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("./d1/./d2/./d3/./d4/./d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/file1.ext", "d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("d1/d2/d3/d4/d5/d6/d7/d8/d9/../../../../file1.ext", "d1/d2/d3/d4/d5/file2.ext", NULL, NULL));


}

static void test_1_13(void)
{
    // trailing dots

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/..", "dir1/dir2/../", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/..", "dir1/dir3/../", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir3/..", "dir1/dir2/../", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/dir2/..", "dir4/dir3/../", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir4/dir3/..", "dir1/dir2/../", NULL, NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/dir2/.", "dir1/dir2/./", NULL, NULL));

}

static void test_1_14(void)
{
    // sliding [rel / cwd]

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d5/file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d4/d6/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d3/d5/d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d2/d4/d4/d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d1/d3/d3/d4/d5/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "/d2/d2/d3/d4/d5/file1.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file2.ext", "/d1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d6/file1.ext", "/d1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d5/d5/file1.ext", "/d1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d4/d4/d5/file1.ext", "/d1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d3/d4/d5/file1.ext", "/d1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d2/d3/d4/d5/file1.ext", "/d2", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d2", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file2.ext", "/d1/d2", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d6/file1.ext", "/d1/d2", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d5/d5/file1.ext", "/d1/d2", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d4/d5/file1.ext", "/d1/d2", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d1/d3", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d3/d4/d5/file1.ext", "/d2/d2", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d3", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file2.ext", "/d1/d2/d3", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d6/file1.ext", "/d1/d2/d3", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/d5/file1.ext", "/d1/d2/d3", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d2/d4", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d1/d3/d3", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d4/d5/file1.ext", "/d2/d2/d3", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d4", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file2.ext", "/d1/d2/d3/d4", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d6/file1.ext", "/d1/d2/d3/d4", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d3/d5", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d2/d4/d4", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d1/d3/d3/d4", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "d5/file1.ext", "/d2/d2/d3/d4", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d5", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file2.ext", "/d1/d2/d3/d4/d5", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d4/d6", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d3/d5/d5", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d2/d4/d4/d5", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d1/d3/d3/d4/d5", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "file1.ext", "/d2/d2/d3/d4/d5", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d6", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file2.ext", "/d1/d2/d3/d4/d5/d6", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d5/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d4/d6/d6", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d3/d5/d5/d6", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d2/d4/d4/d5/d6", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d1/d3/d3/d4/d5/d6", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../file1.ext", "/d2/d2/d3/d4/d5/d6", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file2.ext", "/d1/d2/d3/d4/d5/d6/d7", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d6/d8", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d5/d7/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d4/d6/d6/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d3/d5/d5/d6/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d2/d4/d4/d5/d6/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d1/d3/d3/d4/d5/d6/d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/d1/d2/d3/d4/d5/file1.ext", "../../file1.ext", "/d2/d2/d3/d4/d5/d6/d7", NULL));

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file2.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d6\\d8", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d5\\d7\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d4\\d6\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d3\\d5\\d5\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d2\\d4\\d4\\d5\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d1\\d3\\d3\\d4\\d5\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "C:\\d2\\d2\\d3\\d4\\d5\\d6\\d7", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:\\d1\\d2\\d3\\d4\\d5\\file1.ext", "..\\..\\file1.ext", "D:\\d1\\d2\\d3\\d4\\d5\\d6\\d7", NULL));

#endif
}

static void test_1_15(void)
{
    // UNC roots

#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\\\server1\\share1/dir1\\file1.ext", "\\\\server1\\share1\\dir1/file1.ext", NULL, NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1\\dir1\\file2.ext", "\\\\server1\\share1\\dir1\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir2\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1\\dir2\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server1\\share2\\dir1\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share2\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\\\server1\\share1\\dir1\\file1.ext", "\\\\server2\\share1\\dir1\\file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server2\\share1\\dir1\\file1.ext", "\\\\server1\\share1\\dir1\\file1.ext", NULL, NULL));

#endif
}

static void test_1_16(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:\\", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:\\", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file2.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir1\\file2.ext", "C:\\dir1\\file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "C:\\dir2\\file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir2\\file1.ext", "C:\\dir1\\file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("\\dir1\\file1.ext", "D:\\dir1\\file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\dir1\\file1.ext", "C:\\dir1\\file1.ext", "D:", NULL));
#endif
}

static void test_1_17(void)
{
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("file1.ext", "file2.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("file2.ext", "file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "dir2/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file1.ext", "dir1/file1.ext", NULL, NULL));

#ifdef LIBPATH_OS_IS_WINDOWS

    // absolute, rooted, and relative paths

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:/dir1/file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:/dir1/file1.ext", "/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:/dir1/file1.ext", "\\\\server1\\share1/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:/dir1/file1.ext", NULL, NULL));


    // relative paths with volumes

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:dir1/file1.ext", "D:", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "C:dir1/file1.ext", "C:", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("/dir1/file1.ext", "C:/dir1/file1.ext", "D:", NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:", NULL));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file2.ext", "C:/dir1/file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir2/file1.ext", "C:/dir1/file1.ext", "C:", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "C:/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("dir1/file1.ext", "C:/dir1/file1.ext", "D:/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("dir1/file1.ext", "D:/dir1/file1.ext", "C:/", NULL));

    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext", NULL, NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:dir1/file1.ext", "C:/dir1/file1.ext", "/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir1/file2.ext", "/", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:dir1/file1.ext", "C:/dir2/file1.ext", "/", NULL));

    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1/", NULL));
    XTESTS_TEST_INTEGER_EQUAL(0,   compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:file1.ext", "C:/dir1/file2.ext", "/dir1", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:file2.ext", "C:/dir1/file1.ext", "/dir1", NULL));
    XTESTS_TEST_INTEGER_LESS(0,    compare_paths("C:file1.ext", "C:/dir2/file1.ext", "/dir1", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("C:file1.ext", "C:/dir1/file1.ext", "/dir2", NULL));

    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "C:dir1/file1.ext", "/", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "dir1/file1.ext", "C:", NULL));
    XTESTS_TEST_INTEGER_GREATER(0, compare_paths("\\\\server1\\share1/dir1/file1.ext", "file1.ext", "dir1", NULL));
#endif
}

static void test_1_18(void)
{
}

static void test_1_19(void)
{
}

static void test_1_20(void)
{
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
}

static void test_1_31(void)
{
}

static void test_1_32(void)
{
}

static void test_1_33(void)
{
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
}

static void test_1_41(void)
{
}

static void test_1_42(void)
{
}

static void test_1_43(void)
{
}

static void test_1_44(void)
{
}

static void test_1_45(void)
{
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

/* ///////////////////////////// end of file //////////////////////////// */
