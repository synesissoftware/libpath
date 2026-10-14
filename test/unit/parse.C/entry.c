/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/parse.C/entry.c
 *
 * Purpose: Unit-tests the libpath C parse API.
 *
 * Created: 9th November 2012
 * Updated: 14th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/parse.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>
#if _XTESTS_VER < 0x00150000
# error This code requires xTests 0.21.0, or later
#endif

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdint.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_empty(void);
static void test_1_dot(void);
static void test_2_dots(void);
static void test_3_dots(void);
static void test_4_dots(void);
static void test_5_dots(void);
static void test_rooted_1_dot(void);
static void test_rooted_2_dots(void);
static void test_rooted_3_dots(void);
static void test_rooted_4_dots(void);

static void test_filename_with_trailing_dot(void);
static void test_filename_with_trailing_dots(void);
static void test_stem_only(void);
static void test_filename(void);
static void test_extension_only(void);

static void test_rooted_1_stem(void);
static void test_rooted_1_dir_1_stem(void);
static void test_rooted_1_dir_trailing_slash(void);
static void test_rooted_2_dirs_trailing_slash(void);
static void test_rooted_6_dirs_trailing_slash(void);
static void test_rooted_6_dirs_and_filename(void);
static void test_rooted_6_dirs_and_stem(void);
static void test_slash_only(void);
static void test_filename_multiple_dots(void);

static void test_Windows_backslash_only(void);
static void test_Windows_backslash_rooted_1_stem(void);
static void test_Windows_volume_and_backslash_root(void);
static void test_Windows_volume_and_backslash_rooted_1_stem(void);
static void test_Windows_volume_and_backslash_rooted_6_dirs_and_filename(void);
static void test_Windows_volume_and_slash_root(void);
static void test_Windows_slash_rooted_1_stem(void);
static void test_Windows_volume_and_slash_rooted_6_dirs_and_filename(void);

static void test_Windows_UNC_share(void);
static void test_Windows_UNC_share_and_entry(void);
static void test_Windows_UNC_share_and_6_dirs_and_filename(void);
static void test_Windows_UNC_share_and_6_dirs_and_filename_altslashes(void);
static void test_Windows_UNC_share_and_6_dirs_and_filename_altslashes_2(void);

static void test_Windows_driveletterrelative_and_stem(void);
static void test_Windows_driveletterrelative_and_6_dirs_and_filename(void);
static void test_Windows_driveletterrelative_and_6_dirs_and_filename_altslashes(void);
static void test_Windows_driveletterrelative_and_6_dirs_and_dotsdir_altslashes(void);
static void test_rooted_1_dir_1_stem_extraslashes(void);

static void test_bad_characters(void);
static void test_Windows_bad_characters(void);

static void test_1_component_with_libpath_ParseOption_AssumeDirectory(void);
static void test_2_components_with_libpath_ParseOption_AssumeDirectory(void);
static void test_2_components_with_last_2dotsdir_with_libpath_ParseOption_AssumeDirectory(void);
static void test_2_components_with_last_1dotsdir_with_libpath_ParseOption_AssumeDirectory(void);

static void test_Windows_UNC_share_trailing_backslash(void);
static void test_Windows_UNC_share_trailing_slash(void);
static void test_Windows_UNC_share_with_charwise_steps(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.parse.C", verbosity))
    {
        XTESTS_RUN_CASE(test_empty);
        XTESTS_RUN_CASE(test_1_dot);
        XTESTS_RUN_CASE(test_2_dots);
        XTESTS_RUN_CASE(test_3_dots);
        XTESTS_RUN_CASE(test_4_dots);
        XTESTS_RUN_CASE(test_5_dots);

        XTESTS_RUN_CASE(test_rooted_1_dot);
        XTESTS_RUN_CASE(test_rooted_2_dots);
        XTESTS_RUN_CASE(test_rooted_3_dots);
        XTESTS_RUN_CASE(test_rooted_4_dots);

        XTESTS_RUN_CASE(test_filename_with_trailing_dot);
        XTESTS_RUN_CASE(test_filename_with_trailing_dots);
        XTESTS_RUN_CASE(test_stem_only);
        XTESTS_RUN_CASE(test_filename);
        XTESTS_RUN_CASE(test_extension_only);

        XTESTS_RUN_CASE(test_rooted_1_stem);
        XTESTS_RUN_CASE(test_rooted_1_dir_1_stem);
        XTESTS_RUN_CASE(test_rooted_1_dir_trailing_slash);
        XTESTS_RUN_CASE(test_rooted_2_dirs_trailing_slash);
        XTESTS_RUN_CASE(test_rooted_6_dirs_trailing_slash);
        XTESTS_RUN_CASE(test_rooted_6_dirs_and_filename);
        XTESTS_RUN_CASE(test_rooted_6_dirs_and_stem);
        XTESTS_RUN_CASE(test_slash_only);
        XTESTS_RUN_CASE(test_filename_multiple_dots);

        XTESTS_RUN_CASE(test_Windows_backslash_only);
        XTESTS_RUN_CASE(test_Windows_backslash_rooted_1_stem);
        XTESTS_RUN_CASE(test_Windows_volume_and_backslash_root);
        XTESTS_RUN_CASE(test_Windows_volume_and_backslash_rooted_1_stem);
        XTESTS_RUN_CASE(test_Windows_volume_and_backslash_rooted_6_dirs_and_filename);
        XTESTS_RUN_CASE(test_Windows_volume_and_slash_root);
        XTESTS_RUN_CASE(test_Windows_slash_rooted_1_stem);
        XTESTS_RUN_CASE(test_Windows_volume_and_slash_rooted_6_dirs_and_filename);

        XTESTS_RUN_CASE(test_Windows_UNC_share);
        XTESTS_RUN_CASE(test_Windows_UNC_share_and_entry);
        XTESTS_RUN_CASE(test_Windows_UNC_share_and_6_dirs_and_filename);
        XTESTS_RUN_CASE(test_Windows_UNC_share_and_6_dirs_and_filename_altslashes);
        XTESTS_RUN_CASE(test_Windows_UNC_share_and_6_dirs_and_filename_altslashes_2);

        XTESTS_RUN_CASE(test_Windows_driveletterrelative_and_stem);
        XTESTS_RUN_CASE(test_Windows_driveletterrelative_and_6_dirs_and_filename);
        XTESTS_RUN_CASE(test_Windows_driveletterrelative_and_6_dirs_and_filename_altslashes);
        XTESTS_RUN_CASE(test_Windows_driveletterrelative_and_6_dirs_and_dotsdir_altslashes);
        XTESTS_RUN_CASE(test_rooted_1_dir_1_stem_extraslashes);
        XTESTS_RUN_CASE(test_bad_characters);

        XTESTS_RUN_CASE(test_Windows_bad_characters);

        XTESTS_RUN_CASE(test_1_component_with_libpath_ParseOption_AssumeDirectory);
        XTESTS_RUN_CASE(test_2_components_with_libpath_ParseOption_AssumeDirectory);
        XTESTS_RUN_CASE(test_2_components_with_last_2dotsdir_with_libpath_ParseOption_AssumeDirectory);
        XTESTS_RUN_CASE(test_2_components_with_last_1dotsdir_with_libpath_ParseOption_AssumeDirectory);

        XTESTS_RUN_CASE(test_Windows_UNC_share_trailing_backslash);
        XTESTS_RUN_CASE(test_Windows_UNC_share_trailing_slash);
        XTESTS_RUN_CASE(test_Windows_UNC_share_with_charwise_steps);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

#ifdef __cplusplus
    libpath_size_t const    NUM_DP_ELEMENTS =   10;
#else /* ? __cplusplus */
# define                    NUM_DP_ELEMENTS    (10)
#endif /* __cplusplus */

static void test_empty(void)
{
    char const input[] = "";

    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[1];
    libpath_size_t          firstBadCharOffset;

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_NoPathSpecified, rc);
    TEST_INT_EQ(0, firstBadCharOffset);

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_NoPathSpecified, rc);
    TEST_INT_EQ(0, firstBadCharOffset);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
    TEST_INT_EQ(0u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(0u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);
}

static void test_1_dot(void)
{
    char const input[] = ".";

    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    libpath_size_t          firstBadCharOffset;

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(SIZE_MAX, firstBadCharOffset);

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(SIZE_MAX, firstBadCharOffset);

    TEST_INT_EQ(1u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(1u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(1u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", r.entryNamePart);
    TEST_INT_EQ(1u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_2_dots(void)
{
    char const input[] = "..";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(2u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(2u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(2u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", r.entryNamePart);
    TEST_INT_EQ(2u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_3_dots(void)
{
    char const input[] = "...";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("...", r.entryNamePart);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("...", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_4_dots(void)
{
    char const input[] = "....";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(4u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(4u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(4u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("....", r.entryNamePart);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("....", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_5_dots(void)
{
    char const input[] = ".....";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(5u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(5u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(5u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".....", r.entryNamePart);
    TEST_INT_EQ(5u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".....", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_rooted_1_dot(void)
{
    char const input[] = "/.";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(2u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(2u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, directoryPartSlices[0].len);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(1u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", r.entryNamePart);
    TEST_INT_EQ(1u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_2_dots(void)
{
    char const input[] = "/..";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(2u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", r.entryNamePart);
    TEST_INT_EQ(2u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_3_dots(void)
{
    char const input[] = "/...";

    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr, LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(4u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(4u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("...", r.entryNamePart);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("...", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_4_dots(void)
{
    char const input[] = "/....";

    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    libpath_size_t          firstBadCharOffset;

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(SIZE_MAX, firstBadCharOffset);

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(SIZE_MAX, firstBadCharOffset);

    TEST_INT_EQ(5u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(5u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(4u, r.entryNamePart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("....", r.entryNamePart);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("....", r.entryStemPart);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_filename_with_trailing_dot(void)
{
    char const input[] = "..abc.def.";

    libpath_ParseResult_t  r;
    LIBPATH_RC        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, 0, LIBPATH_LF_nullptr, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(10u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(10u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(10u, r.entryNamePart.len);
    TEST_INT_EQ(10u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);
}

static void test_filename_with_trailing_dots(void)
{
    char const input[] = "..abc.def..";

    libpath_ParseResult_t  r;
    LIBPATH_RC        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, 0, LIBPATH_LF_nullptr, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(11u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(11u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(11u, r.entryNamePart.len);
    TEST_INT_EQ(11u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);
}

static void test_stem_only(void)
{
    char const input[] = "abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_filename(void)
{
    char const input[] = "a.c";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(1u, r.entryStemPart.len);
    TEST_INT_EQ(2u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_extension_only(void)
{
    char const input[] = ".bc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(3u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_rooted_1_stem(void)
{
    char const input[] = "/abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(4u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(4u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_1_dir_1_stem(void)
{
    char const input[] = "/dir/abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(8u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(8u, r.fullPath.len);
    TEST_INT_EQ(5u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_1_dir_trailing_slash(void)
{
    char const input[] = "/dir/";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(5u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(5u, r.fullPath.len);
    TEST_INT_EQ(5u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_2_dirs_trailing_slash(void)
{
    char const input[] = "/dir/dir2/";

    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(10u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(10u, r.fullPath.len);
    TEST_INT_EQ(10u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(9u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    TEST_INT_EQ(5u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir2/", directoryPartSlices[1]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */

    directoryPartSlices[1].len = 1234;
    directoryPartSlices[1].ptr = stlsoft_reinterpret_cast(char*, 1234);

    rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, 1, &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(10u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(10u, r.fullPath.len);
    TEST_INT_EQ(10u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(9u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);

    TEST_INT_EQ(1234u, directoryPartSlices[1].len);
    TEST_PTR_EQ(stlsoft_reinterpret_cast(char*, 1234), directoryPartSlices[1].ptr);

    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_6_dirs_trailing_slash(void)
{
    char const input[] = "/directory1/directory2/dir3/dir4/d5/d6/";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(39u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(39u, r.fullPath.len);
    TEST_INT_EQ(39u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2/", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4/", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6/", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_6_dirs_and_filename(void)
{
    char const input[] = "/directory1/directory2/dir3/dir4/d5/d6/file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(47u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(47u, r.fullPath.len);
    TEST_INT_EQ(39u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2/", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4/", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6/", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_6_dirs_and_stem(void)
{
    char const input[] = "/1/2/3/4/5/6/f";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(14u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(14u, r.fullPath.len);
    TEST_INT_EQ(13u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(12u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(2u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("1/", directoryPartSlices[0]);
    TEST_INT_EQ(2u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("2/", directoryPartSlices[1]);
    TEST_INT_EQ(2u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("3/", directoryPartSlices[2]);
    TEST_INT_EQ(2u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("4/", directoryPartSlices[3]);
    TEST_INT_EQ(2u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("5/", directoryPartSlices[4]);
    TEST_INT_EQ(2u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("6/", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(1u, r.entryNamePart.len);
    TEST_INT_EQ(1u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_slash_only(void)
{
    char const input[] = "/";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(1u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(1u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_filename_multiple_dots(void)
{
    char const input[] = "this.is.a.more.complex.file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(31u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(31u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(31u, r.entryNamePart.len);
    TEST_INT_EQ(27u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
}

static void test_Windows_backslash_only(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(1u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(1u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
    TEST_INT_EQ(0u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_backslash_rooted_1_stem(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(4u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(4u, r.fullPath.len);
    TEST_INT_EQ(1u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
    TEST_INT_EQ(0u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_volume_and_backslash_root(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(3u, r.locationPart.len);
    TEST_INT_EQ(3u, r.rootPart.len);
    TEST_INT_EQ(3u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_volume_and_backslash_rooted_1_stem(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(6u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(6u, r.fullPath.len);
    TEST_INT_EQ(3u, r.locationPart.len);
    TEST_INT_EQ(3u, r.rootPart.len);
    TEST_INT_EQ(3u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_volume_and_backslash_rooted_6_dirs_and_filename(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(49u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(49u, r.fullPath.len);
    TEST_INT_EQ(41u, r.locationPart.len);
    TEST_INT_EQ(3u, r.rootPart.len);
    TEST_INT_EQ(3u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_volume_and_slash_root(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(3u, r.locationPart.len);
    TEST_INT_EQ(3u, r.rootPart.len);
    TEST_INT_EQ(3u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_slash_rooted_1_stem(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(6u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(6u, r.fullPath.len);
    TEST_INT_EQ(3u, r.locationPart.len);
    TEST_INT_EQ(3u, r.rootPart.len);
    TEST_INT_EQ(3u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_volume_and_slash_rooted_6_dirs_and_filename(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(49u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(49u, r.fullPath.len);
    TEST_INT_EQ(41u, r.locationPart.len);
    TEST_INT_EQ(3u, r.rootPart.len);
    TEST_INT_EQ(3u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(20u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(20u, r.fullPath.len);
    TEST_INT_EQ(20u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share_and_entry(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(23u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(23u, r.fullPath.len);
    TEST_INT_EQ(20u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share_and_6_dirs_and_filename(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(66u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(66u, r.fullPath.len);
    TEST_INT_EQ(58u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share_and_6_dirs_and_filename_altslashes(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\directory1/directory2\\dir3/dir4\\d5/d6\\file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(66u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(66u, r.fullPath.len);
    TEST_INT_EQ(58u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share_and_6_dirs_and_filename_altslashes_2(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share/directory1\\directory2/dir3\\dir4/d5\\d6/file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(66u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(66u, r.fullPath.len);
    TEST_INT_EQ(58u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2/", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4/", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6/", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_driveletterrelative_and_stem(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(5u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(5u, r.fullPath.len);
    TEST_INT_EQ(2u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(2u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_driveletterrelative_and_6_dirs_and_filename(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(48u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(48u, r.fullPath.len);
    TEST_INT_EQ(40u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(2u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1\\", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3\\", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5\\", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_driveletterrelative_and_6_dirs_and_filename_altslashes(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1/directory2\\dir3/dir4\\d5/d6\\file.ext";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(48u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(48u, r.fullPath.len);
    TEST_INT_EQ(40u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(2u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(8u, r.entryNamePart.len);
    TEST_INT_EQ(4u, r.entryStemPart.len);
    TEST_INT_EQ(4u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_driveletterrelative_and_6_dirs_and_dotsdir_altslashes(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1/directory2\\dir3/dir4\\d5/d6\\.";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(41u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(41u, r.fullPath.len);
    TEST_INT_EQ(40u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(2u, r.volumePart.len);
    TEST_INT_EQ(38u, r.directoryPart.len);
    TEST_INT_EQ(6u, r.numDirectoryParts);
    TEST_INT_EQ(11u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory1/", directoryPartSlices[0]);
    TEST_INT_EQ(11u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("directory2\\", directoryPartSlices[1]);
    TEST_INT_EQ(5u, directoryPartSlices[2].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir3/", directoryPartSlices[2]);
    TEST_INT_EQ(5u, directoryPartSlices[3].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir4\\", directoryPartSlices[3]);
    TEST_INT_EQ(3u, directoryPartSlices[4].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d5/", directoryPartSlices[4]);
    TEST_INT_EQ(3u, directoryPartSlices[5].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("d6\\", directoryPartSlices[5]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(1u, r.entryNamePart.len);
    TEST_INT_EQ(1u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_rooted_1_dir_1_stem_extraslashes(void)
{
    char const input[] = "/dir//abc";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(9u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(9u, r.fullPath.len);
    TEST_INT_EQ(6u, r.locationPart.len);
    TEST_INT_EQ(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_INT_EQ(0u, r.volumePart.len);
#endif
    TEST_INT_EQ(5u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(5u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir//", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);
    TEST_INT_EQ(3u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
#ifdef LIBPATH_OS_IS_WINDOWS
    TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_bad_characters(void)
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

    { libpath_size_t i; for (i = 0; i != STLSOFT_NUM_ELEMENTS(bad_chars); ++i)
    {
        { libpath_size_t j; for (j = 0; j != STLSOFT_NUM_ELEMENTS(input_template) - 1; ++j)
        {
            libpath_ParseResult_t   r;
            LIBPATH_RC              rc;
            libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
            libpath_size_t          firstBadCharOffset;

            char input[STLSOFT_NUM_ELEMENTS(input_template)];

            STLSOFT_STATIC_ASSERT(sizeof(input) == sizeof(input_template));

            memcpy(input, input_template, sizeof(input));

            input[j] = bad_chars[i];

            rc = libpath_Parse_ParsePathFromCStyleString(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

            TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
            TEST_INT_EQ(j, firstBadCharOffset);

            rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], &firstBadCharOffset);

            TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
            TEST_INT_EQ(31u, r.input.len);
            TEST_INT_EQ(j, firstBadCharOffset);
        }}
    }}
}

static void test_Windows_bad_characters(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS

    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_size_t          firstBadCharOffset;


    rc = libpath_Parse_ParsePathFromCStyleString(":C\\dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
    TEST_INT_EQ(15u, r.input.len);
    TEST_INT_EQ(0u, firstBadCharOffset);


    rc = libpath_Parse_ParsePathFromCStyleString("C:\\dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(15u, r.input.len);


    rc = libpath_Parse_ParsePathFromCStyleString("C\\:dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
    TEST_INT_EQ(15u, r.input.len);
    TEST_INT_EQ(2u, firstBadCharOffset);


    rc = libpath_Parse_ParsePathFromCStyleString("C\\d:ir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
    TEST_INT_EQ(15u, r.input.len);
    TEST_INT_EQ(3u, firstBadCharOffset);


    rc = libpath_Parse_ParsePathFromCStyleString("C\\di:r\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
    TEST_INT_EQ(15u, r.input.len);
    TEST_INT_EQ(4u, firstBadCharOffset);


    rc = libpath_Parse_ParsePathFromCStyleString("C\\dir:\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
    TEST_INT_EQ(15u, r.input.len);
    TEST_INT_EQ(5u, firstBadCharOffset);



    rc = libpath_Parse_ParsePathFromCStyleString("\\:Cdir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    TEST_ENUM_EQ(libpath_ResultCode_BadPathCharacter, rc);
    TEST_INT_EQ(15u, r.input.len);
    TEST_INT_EQ(1u, firstBadCharOffset);
#endif
}

static void test_1_component_with_libpath_ParseOption_AssumeDirectory(void)
{
    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = libpath_Parse_ParsePathFromCStyleString("abc", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(0u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(4u, r.input.len);
    TEST_INT_EQ(4u, r.fullPath.len);
    TEST_INT_EQ(4u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(3u, r.input.len);
    TEST_INT_EQ(3u, r.fullPath.len);
    TEST_INT_EQ(3u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(3u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(3u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(4u, r.input.len);
    TEST_INT_EQ(4u, r.fullPath.len);
    TEST_INT_EQ(4u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
}

static void test_2_components_with_libpath_ParseOption_AssumeDirectory(void)
{
    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = libpath_Parse_ParsePathFromCStyleString("abc/def", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(7u, r.input.len);
    TEST_INT_EQ(7u, r.fullPath.len);
    TEST_INT_EQ(4u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(3u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/def/", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(8u, r.input.len);
    TEST_INT_EQ(8u, r.fullPath.len);
    TEST_INT_EQ(8u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(8u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(4u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("def/", directoryPartSlices[1]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/def", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(7u, r.input.len);
    TEST_INT_EQ(7u, r.fullPath.len);
    TEST_INT_EQ(7u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(7u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(3u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("def", directoryPartSlices[1]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/def/", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(8u, r.input.len);
    TEST_INT_EQ(8u, r.fullPath.len);
    TEST_INT_EQ(8u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(8u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(4u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("def/", directoryPartSlices[1]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


}

static void test_2_components_with_last_2dotsdir_with_libpath_ParseOption_AssumeDirectory(void)
{
    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = libpath_Parse_ParsePathFromCStyleString("abc/..", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(6u, r.input.len);
    TEST_INT_EQ(6u, r.fullPath.len);
    TEST_INT_EQ(4u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(2u, r.entryNamePart.len);
    TEST_INT_EQ(2u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/../", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(7u, r.input.len);
    TEST_INT_EQ(7u, r.fullPath.len);
    TEST_INT_EQ(7u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(7u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(3u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("../", directoryPartSlices[1]);
    TEST_INT_EQ(1u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/..", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(6u, r.input.len);
    TEST_INT_EQ(6u, r.fullPath.len);
    TEST_INT_EQ(6u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(6u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(2u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", directoryPartSlices[1]);
    TEST_INT_EQ(1u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/../", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(7u, r.input.len);
    TEST_INT_EQ(7u, r.fullPath.len);
    TEST_INT_EQ(7u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(7u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(3u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("../", directoryPartSlices[1]);
    TEST_INT_EQ(1u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
}

static void test_2_components_with_last_1dotsdir_with_libpath_ParseOption_AssumeDirectory(void)
{
    libpath_ParseResult_t   r;
    LIBPATH_RC              rc;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = libpath_Parse_ParsePathFromCStyleString("abc/.", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(5u, r.input.len);
    TEST_INT_EQ(5u, r.fullPath.len);
    TEST_INT_EQ(4u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(4u, r.directoryPart.len);
    TEST_INT_EQ(1u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(1u, r.entryNamePart.len);
    TEST_INT_EQ(1u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/./", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(6u, r.input.len);
    TEST_INT_EQ(6u, r.fullPath.len);
    TEST_INT_EQ(6u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(6u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(2u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("./", directoryPartSlices[1]);
    TEST_INT_EQ(1u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/.", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(5u, r.input.len);
    TEST_INT_EQ(5u, r.fullPath.len);
    TEST_INT_EQ(5u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(5u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(1u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[1]);
    TEST_INT_EQ(1u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);


    rc = libpath_Parse_ParsePathFromCStyleString("abc/./", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(6u, r.input.len);
    TEST_INT_EQ(6u, r.fullPath.len);
    TEST_INT_EQ(6u, r.locationPart.len);
    TEST_INT_EQ(0u, r.rootPart.len);
    TEST_INT_EQ(6u, r.directoryPart.len);
    TEST_INT_EQ(2u, r.numDirectoryParts);
    TEST_INT_EQ(4u, directoryPartSlices[0].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    TEST_INT_EQ(2u, directoryPartSlices[1].len);
    TEST_MULTIBYTE_STRING_SLICE_EQUAL("./", directoryPartSlices[1]);
    TEST_INT_EQ(1u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
}

static void test_Windows_UNC_share_trailing_backslash(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(20u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(20u, r.fullPath.len);
    TEST_INT_EQ(20u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share_trailing_slash(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share/";

    libpath_ParseResult_t   r;
    libpath_StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const        rc = libpath_Parse_ParsePathFromCStyleString(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], LIBPATH_LF_nullptr);

    TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
    TEST_INT_EQ(20u, r.input.len);
    TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
    TEST_INT_EQ(20u, r.fullPath.len);
    TEST_INT_EQ(20u, r.locationPart.len);
    TEST_INT_EQ(20u, r.rootPart.len);
    TEST_INT_EQ(20u, r.volumePart.len);
    TEST_INT_EQ(0u, r.directoryPart.len);
    TEST_INT_EQ(0u, r.numDirectoryParts);
    TEST_INT_EQ(0u, r.numDotsDirectoryParts);
    TEST_INT_EQ(0u, r.entryNamePart.len);
    TEST_INT_EQ(0u, r.entryStemPart.len);
    TEST_INT_EQ(0u, r.entryExtensionPart.len);

    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
    TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void test_Windows_UNC_share_with_charwise_steps(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const              input[] =   "\\\\192.168.0.1\\share\\";
    libpath_size_t const    cch     =   STLSOFT_NUM_ELEMENTS(input) - 1;

    { libpath_size_t i; for (i = 0; i <= cch; ++i)
    {
        libpath_ParseResult_t   r;
        LIBPATH_RC const        rc = libpath_Parse_ParsePathFromStringPtrAndLen(input, i, 0, &r, 0, LIBPATH_LF_nullptr, LIBPATH_LF_nullptr);

        if (1 == i ||
            cch == i)
        {
            TEST_ENUM_EQ(libpath_ResultCode_Success, rc);
            TEST_INT_EQ(i, r.input.len);
            TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
            TEST_INT_EQ(i, r.fullPath.len);
            TEST_INT_EQ(i, r.locationPart.len);
            TEST_INT_EQ(i, r.rootPart.len);
            if (cch == i)
            {
                TEST_INT_EQ(20u, r.volumePart.len);
            }
            else
            {
                TEST_INT_EQ(0u, r.volumePart.len);
            }
            TEST_INT_EQ(0u, r.directoryPart.len);
            TEST_INT_EQ(0u, r.numDirectoryParts);
            TEST_INT_EQ(0u, r.numDotsDirectoryParts);
            TEST_INT_EQ(0u, r.entryNamePart.len);
            TEST_INT_EQ(0u, r.entryStemPart.len);
            TEST_INT_EQ(0u, r.entryExtensionPart.len);

            TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathRooted(&r));
            if (cch == i)
            {
                TEST_BOOLEAN_TRUE(libpath_ParseResult_IsPathAbsolute(&r));
            }
            else
            {
                TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
            }
        }
        else
        {
            if (0 == i)
            {
                TEST_ENUM_EQ(libpath_ResultCode_NoPathSpecified, rc);
                TEST_INT_EQ(i, r.input.len);
                TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
            }
            else
            {
                TEST_ENUM_EQ(libpath_ResultCode_InvalidRoot, rc);
                TEST_INT_EQ(i, r.input.len);
                TEST_MS_EQ_N(input, r.input.ptr, r.input.len);
            }

            TEST_INT_EQ(0u, r.fullPath.len);
            TEST_INT_EQ(0u, r.locationPart.len);
            TEST_INT_EQ(0u, r.rootPart.len);
            TEST_INT_EQ(0u, r.volumePart.len);
            TEST_INT_EQ(0u, r.directoryPart.len);
            TEST_INT_EQ(0u, r.numDirectoryParts);
            TEST_INT_EQ(0u, r.numDotsDirectoryParts);
            TEST_INT_EQ(0u, r.entryNamePart.len);
            TEST_INT_EQ(0u, r.entryStemPart.len);
            TEST_INT_EQ(0u, r.entryExtensionPart.len);

            TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathRooted(&r));
            TEST_BOOLEAN_FALSE(libpath_ParseResult_IsPathAbsolute(&r));
        }
    }}
#endif /* LIBPATH_OS_IS_WINDOWS */
}


/* ///////////////////////////// end of file //////////////////////////// */

