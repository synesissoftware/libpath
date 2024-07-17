/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.parse.1.cpp
 *
 * Purpose: Implementation file for the test.unit.parse.1 project.
 *
 * Created: 9th November 2012
 * Updated: 4th May 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/parse.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#if _XTESTS_VER < 0x00150000
# error This code requires xTests 0.21.0, or later
#endif

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);

    static void test_1_6(void);
    static void test_1_7(void);
    static void test_1_8(void);

    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_12(void);

    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);

    static void test_1_30(void);
    static void test_1_31(void);
    static void test_1_32(void);
    static void test_1_33(void);
    static void test_1_34(void);
    static void test_1_35(void);
    static void test_1_36(void);
    static void test_1_37(void);

    static void test_1_40(void);
    static void test_1_41(void);
    static void test_1_42(void);
    static void test_1_43(void);
    static void test_1_44(void);

    static void test_1_50(void);
    static void test_1_51(void);
    static void test_1_52(void);
    static void test_1_53(void);
    static void test_1_54(void);

    static void test_1_60(void);
    static void test_1_61(void);

    static void test_1_70(void);
    static void test_1_71(void);
    static void test_1_72(void);
    static void test_1_73(void);

    static void test_1_80(void);
    static void test_1_81(void);
    static void test_1_82(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.parse.1", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);

        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);

        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);

        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);

        XTESTS_RUN_CASE(test_1_30);
        XTESTS_RUN_CASE(test_1_31);
        XTESTS_RUN_CASE(test_1_32);
        XTESTS_RUN_CASE(test_1_33);
        XTESTS_RUN_CASE(test_1_34);
        XTESTS_RUN_CASE(test_1_35);
        XTESTS_RUN_CASE(test_1_36);
        XTESTS_RUN_CASE(test_1_37);

        XTESTS_RUN_CASE(test_1_40);
        XTESTS_RUN_CASE(test_1_41);
        XTESTS_RUN_CASE(test_1_42);
        XTESTS_RUN_CASE(test_1_43);
        XTESTS_RUN_CASE(test_1_44);

        XTESTS_RUN_CASE(test_1_50);
        XTESTS_RUN_CASE(test_1_51);
        XTESTS_RUN_CASE(test_1_52);
        XTESTS_RUN_CASE(test_1_53);
        XTESTS_RUN_CASE(test_1_54);

        XTESTS_RUN_CASE(test_1_60);
        XTESTS_RUN_CASE(test_1_61);

        XTESTS_RUN_CASE(test_1_70);
        XTESTS_RUN_CASE(test_1_71);
        XTESTS_RUN_CASE(test_1_72);
        XTESTS_RUN_CASE(test_1_73);

        XTESTS_RUN_CASE(test_1_80);
        XTESTS_RUN_CASE(test_1_81);
        XTESTS_RUN_CASE(test_1_82);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

 using ::libpath::StringSlice_t;

 using ::libpath::parsing::ParseResult_t;

 using ::libpath::parsing::parse_path_from_cstyle_string;
 using ::libpath::parsing::parse_path_from_string_ptr_and_len;

 using ::libpath::parsing::is_absolute;
 using ::libpath::parsing::is_rooted;


#ifdef __cplusplus

    const libpath_size_t    NUM_DP_ELEMENTS =   10;
#else /* ? __cplusplus */

# define                    NUM_DP_ELEMENTS    (10)
#endif /* __cplusplus */


static void test_1_0(void)
{
    char const input[] = "";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[1];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_NoPathSpecified, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_NoPathSpecified, rc);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
    XTESTS_TEST_INTEGER_EQUAL(0u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);
}

static void test_1_1(void)
{
    char const input[] = ".";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(1u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(1u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void test_1_2(void)
{
    char const input[] = "..";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(2u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void test_1_3(void)
{
    char const input[] = "/.";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(1u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(1u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_4(void)
{
    char const input[] = "/..";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(2u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_6(void)
{
    char const input[] = "...";

    ParseResult_t  r;
    LIBPATH_RC        rc = parse_path_from_cstyle_string(input, 0, &r, 0, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryExtensionPart.len);
}

static void test_1_7(void)
{
    char const input[] = ".....";

    ParseResult_t  r;
    LIBPATH_RC        rc = parse_path_from_cstyle_string(input, 0, &r, 0, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);
}

static void test_1_8(void)
{
    char const input[] = "..abc.def..";

    ParseResult_t  r;
    LIBPATH_RC        rc = parse_path_from_cstyle_string(input, 0, &r, 0, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(9u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryExtensionPart.len);
}

static void test_1_10(void)
{
    char const input[] = "abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void test_1_11(void)
{
    char const input[] = "a.c";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void test_1_12(void)
{
    char const input[] = ".bc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void test_1_14(void)
{
    char const input[] = "/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_15(void)
{
    char const input[] = "/dir/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_16(void)
{
    char const input[] = "/dir/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_17(void)
{
    char const input[] = "/dir/dir2/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(9u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir2/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */

    directoryPartSlices[1].len = 1234;
    directoryPartSlices[1].ptr = reinterpret_cast<char*>(1234);

    rc = parse_path_from_cstyle_string(input, 0, &r, 1, &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(9u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);

    XTESTS_TEST_INTEGER_EQUAL(1234u, directoryPartSlices[1].len);
    XTESTS_TEST_POINTER_EQUAL(reinterpret_cast<char*>(1234), directoryPartSlices[1].ptr);

    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_18(void)
{
    char const input[] = "/directory1/directory2/dir3/dir4/d5/d6/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4/", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6/", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_19(void)
{
    char const input[] = "/directory1/directory2/dir3/dir4/d5/d6/file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(47u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(47u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4/", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6/", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_20(void)
{
    char const input[] = "/1/2/3/4/5/6/f";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(14u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(14u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(13u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(12u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("1/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("2/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("3/", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("4/", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("5/", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("6/", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_21(void)
{
    char const input[] = "/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_22(void)
{
    char const input[] = "this.is.a.more.complex.file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(31u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(31u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(31u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(27u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void test_1_30(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_31(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_32(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_33(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_34(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_35(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_36(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_37(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_40(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_41(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(23u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(23u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_42(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(58u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_43(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\directory1/directory2\\dir3/dir4\\d5/d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(58u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_44(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share/directory1\\directory2/dir3\\dir4/d5\\d6/file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(58u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4/", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6/", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_50(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_51(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(40u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_52(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1/directory2\\dir3/dir4\\d5/d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(40u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(38u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_53(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1/directory2\\dir3/dir4\\d5/d6\\.";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(11u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[2].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[3].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[4].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[5].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    XTESTS_TEST_INTEGER_EQUAL(1u, directoryPartSlices[6].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[6]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_54(void)
{
    char const input[] = "/dir//abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(9u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(9u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(5u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(5u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir//", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_60(void)
{
    static char const bad_chars[] =
    {
            '|'
        ,   '<'
        ,   '>'
        ,   '?'
        ,   '*'
#ifdef LIBPATH_OS_IS_WINDOWS
        ,   ';'
#else
        ,   ':'
#endif
    };
    char const input_template[] = "/this/is/going/to/be/a.bad.path";

    { for(libpath_size_t i = 0; i != STLSOFT_NUM_ELEMENTS(bad_chars); ++i)
    {
        { for(libpath_size_t j = 0; j != STLSOFT_NUM_ELEMENTS(input_template) - 1; ++j)
        {
            char input[STLSOFT_NUM_ELEMENTS(input_template)];

            STLSOFT_STATIC_ASSERT(sizeof(input) == sizeof(input_template));

            memcpy(input, input_template, sizeof(input));

            input[j] = bad_chars[i];

            ParseResult_t   r;
            LIBPATH_RC      rc;
            StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

            rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

            XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);

            rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

            XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
            XTESTS_TEST_INTEGER_EQUAL(31u, r.input.len);
            XTESTS_TEST_INTEGER_EQUAL(j, r.firstBadCharOffset);
        }}
    }}
}

static void test_1_61(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    ParseResult_t  r;
    LIBPATH_RC        rc;


    rc = parse_path_from_cstyle_string(":C\\dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C:\\dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);


    rc = parse_path_from_cstyle_string("C\\:dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C\\d:ir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C\\di:r\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C\\dir:\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.firstBadCharOffset);



    rc = parse_path_from_cstyle_string("\\:Cdir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.firstBadCharOffset);


#endif
}

static void test_1_70(void)
{
    ParseResult_t  r;
    LIBPATH_RC        rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


}

static void test_1_71(void)
{
    ParseResult_t  r;
    LIBPATH_RC        rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc/def", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/def/", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("def/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/def", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("def", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/def/", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("def/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


}

static void test_1_72(void)
{
    ParseResult_t  r;
    LIBPATH_RC        rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc/..", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/../", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("../", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/..", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/../", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("../", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


}

static void test_1_73(void)
{
    ParseResult_t  r;
    LIBPATH_RC        rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc/.", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/./", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("./", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/.", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


    rc = parse_path_from_cstyle_string("abc/./", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("./", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);


}

static void test_1_80(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_81(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.path.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_1_82(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const              input[] =   "\\\\192.168.0.1\\share\\";
    libpath_size_t const    cch     =   STLSOFT_NUM_ELEMENTS(input) - 1;

    { for(libpath_size_t i = 0; i <= cch; ++i)
    {
        ParseResult_t   r;
        LIBPATH_RC      rc;

        rc = parse_path_from_string_ptr_and_len(input, i, 0, &r, 0, LIBPATH_LF_nullptr);

        if (1 == i ||
            cch == i)
        {
            XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
            XTESTS_TEST_INTEGER_EQUAL(i, r.input.len);
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
            XTESTS_TEST_INTEGER_EQUAL(i, r.path.len);
            XTESTS_TEST_INTEGER_EQUAL(i, r.locationPart.len);
            XTESTS_TEST_INTEGER_EQUAL(i, r.rootPart.len);
            if (cch == i)
            {
                XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
            }
            else
            {
                XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
            }
            XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

            XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
            if (cch == i)
            {
                XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
            }
            else
            {
                XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
            }
        }
        else
        {
            if (0 == i)
            {
                XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_NoPathSpecified, rc);
                XTESTS_TEST_INTEGER_EQUAL(i, r.input.len);
                XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
            }
            else
            {
                XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_InvalidRoot, rc);
                XTESTS_TEST_INTEGER_EQUAL(i, r.input.len);
                XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
            }

            XTESTS_TEST_INTEGER_EQUAL(0u, r.path.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.entryPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
            XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

            XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
            XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
        }
    }}
#endif /* LIBPATH_OS_IS_WINDOWS */
}


/* ///////////////////////////// end of file //////////////////////////// */

