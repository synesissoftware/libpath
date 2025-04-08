/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.parse.1.cpp
 *
 * Purpose: Implementation file for the test.unit.parse.1 project.
 *
 * Created: 9th November 2012
 * Updated: 8th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/parse.hpp>

/* /////////////////////////////////////
 * general includes
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

static void TEST_EMPTY_STRING(void);
static void TEST_SINGLE_DOT(void);
static void TEST_DOUBLE_DOTS(void);
static void TEST_SLASH_DOT(void);
static void TEST_SLASH_DOUBLE_DOTS(void);

static void TEST_TRIPLE_DOTS(void);
static void TEST_5_DOTS(void);
static void TEST_ENTRYNAME_TRAILING_DOTS(void);

static void TEST_STEM_ONLY(void);
static void TEST_STEM_AND_EXT(void);
static void TEST_EXT_ONLY(void);

static void TEST_SLASH_STEM(void);
static void TEST_SLASH_ROOTED_DIR_AND_STEM(void);
static void TEST_SLASH_ROOTED_1_LEVEL_DIR(void);
static void TEST_SLASH_ROOTED_2_LEVEL_DIR(void);
static void TEST_SLASH_ROOTED_N_LEVEL_DIR(void);
static void TEST_SLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void);
static void TEST_SLASH_ROOTED_N_LEVEL_DIR_2(void);
static void TEST_SLASH(void);
static void TEST_COMPLEX_ENTRY_NAME(void);

static void TEST_BACKSLASH(void);
static void TEST_BACKSLASH_STEM(void);
static void TEST_DRIVE_ROOTED_BACKSLASH(void);
static void TEST_DRIVE_ROOTED_BACKSLASH_STEM(void);
static void TEST_BACKSLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void);
static void TEST_DRIVE_ROOTED_SLASH(void);
static void TEST_DRIVE_ROOTED_SLASH_STEM(void);
static void TEST_MIXED_SLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void);

static void TEST_UNC_SERVER_SHARE(void);
static void TEST_MIXED_SLASH_UNC_SERVER_SHARE(void);
static void TEST_UNC_SERVER_SHARE_AND_STEM(void);
static void TEST_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void);
static void TEST_MIXED_SLASH_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void);
static void TEST_MIXED_SLASH_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT_2(void);

static void TEST_DRIVE_RELATIVE_STEM(void);
static void TEST_DRIVE_RELATIVE_N_LEVEL_DIR_AND_STEM_AND_EXT(void);
static void TEST_MIXED_SLASH_DRIVE_RELATIVE_N_LEVEL_DIR_AND_STEM_AND_EXT(void);
static void TEST_MIXED_SLASH_DRIVE_RELATIVE_N_LEVEL_DIR_AND_DOT(void);
static void TEST_SLASH_ROOTED_DIR_AND_STEM_WITH_SLASHRUNS(void);
static void TEST_DIR_AND_STEM(void);

static void TEST_INVALID_CHARS(void);
static void TEST_Windows_INVALID_CHARS(void);

static void TEST_directoryParts(void);
static void TEST_directoryParts_2(void);
static void TEST_directoryParts_3(void);
static void TEST_directoryParts_4(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.parse.1", verbosity))
    {
        XTESTS_RUN_CASE(TEST_EMPTY_STRING);
        XTESTS_RUN_CASE(TEST_SINGLE_DOT);
        XTESTS_RUN_CASE(TEST_DOUBLE_DOTS);
        XTESTS_RUN_CASE(TEST_SLASH_DOT);
        XTESTS_RUN_CASE(TEST_SLASH_DOUBLE_DOTS);

        XTESTS_RUN_CASE(TEST_TRIPLE_DOTS);
        XTESTS_RUN_CASE(TEST_5_DOTS);
        XTESTS_RUN_CASE(TEST_ENTRYNAME_TRAILING_DOTS);

        XTESTS_RUN_CASE(TEST_STEM_ONLY);
        XTESTS_RUN_CASE(TEST_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_EXT_ONLY);

        XTESTS_RUN_CASE(TEST_SLASH_STEM);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_DIR_AND_STEM);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_1_LEVEL_DIR);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_2_LEVEL_DIR);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_N_LEVEL_DIR);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_N_LEVEL_DIR_2);
        XTESTS_RUN_CASE(TEST_SLASH);
        XTESTS_RUN_CASE(TEST_COMPLEX_ENTRY_NAME);

        XTESTS_RUN_CASE(TEST_BACKSLASH);
        XTESTS_RUN_CASE(TEST_BACKSLASH_STEM);
        XTESTS_RUN_CASE(TEST_DRIVE_ROOTED_BACKSLASH);
        XTESTS_RUN_CASE(TEST_DRIVE_ROOTED_BACKSLASH_STEM);
        XTESTS_RUN_CASE(TEST_BACKSLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_DRIVE_ROOTED_SLASH);
        XTESTS_RUN_CASE(TEST_DRIVE_ROOTED_SLASH_STEM);
        XTESTS_RUN_CASE(TEST_MIXED_SLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT);

        XTESTS_RUN_CASE(TEST_UNC_SERVER_SHARE);
        XTESTS_RUN_CASE(TEST_MIXED_SLASH_UNC_SERVER_SHARE);
        XTESTS_RUN_CASE(TEST_UNC_SERVER_SHARE_AND_STEM);
        XTESTS_RUN_CASE(TEST_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_MIXED_SLASH_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_MIXED_SLASH_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT_2);

        XTESTS_RUN_CASE(TEST_DRIVE_RELATIVE_STEM);
        XTESTS_RUN_CASE(TEST_DRIVE_RELATIVE_N_LEVEL_DIR_AND_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_MIXED_SLASH_DRIVE_RELATIVE_N_LEVEL_DIR_AND_STEM_AND_EXT);
        XTESTS_RUN_CASE(TEST_MIXED_SLASH_DRIVE_RELATIVE_N_LEVEL_DIR_AND_DOT);
        XTESTS_RUN_CASE(TEST_SLASH_ROOTED_DIR_AND_STEM_WITH_SLASHRUNS);
        XTESTS_RUN_CASE(TEST_DIR_AND_STEM);

        XTESTS_RUN_CASE(TEST_INVALID_CHARS);
        XTESTS_RUN_CASE(TEST_Windows_INVALID_CHARS);

        XTESTS_RUN_CASE(TEST_directoryParts);
        XTESTS_RUN_CASE(TEST_directoryParts_2);
        XTESTS_RUN_CASE(TEST_directoryParts_3);
        XTESTS_RUN_CASE(TEST_directoryParts_4);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

using ::libpath::StringSlice_t;

typedef ::libpath::parsing::PathDescriptor_t                ParseResult_t;

using ::libpath::parsing::parse_path_from_cstyle_string;
using ::libpath::parsing::parse_path_from_string_ptr_and_len;

using ::libpath::parsing::is_absolute;
using ::libpath::parsing::is_rooted;


#ifdef __cplusplus

    const libpath_size_t    NUM_DP_ELEMENTS =   10;
#else /* ? __cplusplus */

# define                    NUM_DP_ELEMENTS    (10)
#endif /* __cplusplus */


static void TEST_EMPTY_STRING(void)
{
    char const input[] = "";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[1];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_NoPathSpecified, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_NoPathSpecified, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_NoPathSpecified, rc);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
    XTESTS_TEST_INTEGER_EQUAL(0u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);
}

static void TEST_SINGLE_DOT(void)
{
    char const input[] = ".";

    ParseResult_t       r;
    StringSlice_t       directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void TEST_DOUBLE_DOTS(void)
{
    char const input[] = "..";

    ParseResult_t       r;
    StringSlice_t       directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void TEST_SLASH_DOT(void)
{
    char const input[] = "/.";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, directoryPartSlices[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_DOUBLE_DOTS(void)
{
    char const input[] = "/..";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_TRIPLE_DOTS(void)
{
    char const input[] = "...";

    ParseResult_t   r;
    LIBPATH_RC      rc = parse_path_from_cstyle_string(input, 0, &r, 0, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);
}

static void TEST_5_DOTS(void)
{
    char const input[] = ".....";

    ParseResult_t   r;
    LIBPATH_RC      rc = parse_path_from_cstyle_string(input, 0, &r, 0, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);
}

static void TEST_ENTRYNAME_TRAILING_DOTS(void)
{
    char const input[] = "..abc.def..";

    ParseResult_t   r;
    LIBPATH_RC      rc = parse_path_from_cstyle_string(input, 0, &r, 0, LIBPATH_LF_nullptr);

    // TODO: define failure result code
    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(11u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);
}

static void TEST_STEM_ONLY(void)
{
    char const input[] = "abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void TEST_STEM_AND_EXT(void)
{
    char const input[] = "a.c";

    ParseResult_t       r;
    StringSlice_t       directoryPartSlices[NUM_DP_ELEMENTS];
    LIBPATH_RC const    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryExtensionPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".c", r.entryExtensionPart);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void TEST_EXT_ONLY(void)
{
    char const input[] = ".bc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void TEST_SLASH_STEM(void)
{
    char const input[] = "/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/", r.locationPart);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/", r.rootPart);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", r.entryStemPart);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_DIR_AND_STEM(void)
{
    char const input[] = "/dir/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/dir/", r.locationPart);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", r.entryStemPart);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_1_LEVEL_DIR(void)
{
    char const input[] = "/dir/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/dir/", r.locationPart);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_2_LEVEL_DIR(void)
{
    char const input[] = "/dir/dir2/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(10u, r.locationPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/dir/dir2/", r.locationPart);
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
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
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
    XTESTS_TEST_INTEGER_EQUAL(10u, r.fullPath.len);
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

    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_N_LEVEL_DIR(void)
{
    char const input[] = "/directory1/directory2/dir3/dir4/d5/d6/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.locationPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/directory1/directory2/dir3/dir4/d5/d6/", r.locationPart);
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
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
    char const input[] = "/directory1/directory2/dir3/dir4/d5/d6/file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(47u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(47u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(39u, r.locationPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("/directory1/directory2/dir3/dir4/d5/d6/", r.locationPart);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("file", r.entryStemPart);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".ext", r.entryExtensionPart);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_N_LEVEL_DIR_2(void)
{
    char const input[] = "/1/2/3/4/5/6/f";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(14u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(14u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH(void)
{
    char const input[] = "/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_COMPLEX_ENTRY_NAME(void)
{
    char const input[] = "this.is.a.more.complex.file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(31u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(31u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(31u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(27u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
}

static void TEST_BACKSLASH(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_BACKSLASH_STEM(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DRIVE_ROOTED_BACKSLASH(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DRIVE_ROOTED_BACKSLASH_STEM(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_BACKSLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:\\directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DRIVE_ROOTED_SLASH(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DRIVE_ROOTED_SLASH_STEM(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_MIXED_SLASH_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:/directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(49u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_UNC_SERVER_SHARE(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    {
        char const input[] = "\\\\192.168.0.1\\share\\";

        ParseResult_t   r;
        LIBPATH_RC      rc;
        StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

        rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

        XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

# ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

        rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

        XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
# endif

        rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

        XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
        XTESTS_TEST_INTEGER_EQUAL(20u, r.input.len);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
        XTESTS_TEST_INTEGER_EQUAL(20u, r.fullPath.len);
        XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
        XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
        XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
        XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
        XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
        XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
        XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
        XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
        XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

        XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
        XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
    }

    {
        char const              input[] =   "\\\\192.168.0.1\\share\\";
        libpath_size_t const    cch     =   STLSOFT_NUM_ELEMENTS(input) - 1;

        { for (libpath_size_t i = 0; i <= cch; ++i)
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
                XTESTS_TEST_INTEGER_EQUAL(i, r.fullPath.len);
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
                XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
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

                XTESTS_TEST_INTEGER_EQUAL(0u, r.fullPath.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
                XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

                XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
                XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
            }
        }}
    }
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_MIXED_SLASH_UNC_SERVER_SHARE(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share/";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_UNC_SERVER_SHARE_AND_STEM(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(23u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(23u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(20u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_MIXED_SLASH_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share\\directory1/directory2\\dir3/dir4\\d5/d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_MIXED_SLASH_UNC_SERVER_SHARE_ROOTED_N_LEVEL_DIR_AND_STEM_AND_EXT_2(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "\\\\192.168.0.1\\share/directory1\\directory2/dir3\\dir4/d5\\d6/file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(66u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DRIVE_RELATIVE_STEM(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.volumePart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DRIVE_RELATIVE_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1\\directory2\\dir3\\dir4\\d5\\d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_MIXED_SLASH_DRIVE_RELATIVE_N_LEVEL_DIR_AND_STEM_AND_EXT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1/directory2\\dir3/dir4\\d5/d6\\file.ext";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(48u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(8u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_MIXED_SLASH_DRIVE_RELATIVE_N_LEVEL_DIR_AND_DOT(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    char const input[] = "C:directory1/directory2\\dir3/dir4\\d5/d6\\.";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(41u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_SLASH_ROOTED_DIR_AND_STEM_WITH_SLASHRUNS(void)
{
    char const input[] = "/dir//abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(9u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(9u, r.fullPath.len);
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
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_TRUE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_TRUE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_DIR_AND_STEM(void)
{
    char const input[] = "dir/abc";

    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];

    rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
#endif

    rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(input, r.input.ptr, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_INTEGER_EQUAL(0u, r.volumePart.len);
#endif
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("dir/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);

    XTESTS_TEST_BOOLEAN_FALSE(is_rooted(r));
#ifdef LIBPATH_OS_IS_WINDOWS
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#else /* ? LIBPATH_OS_IS_WINDOWS */
    XTESTS_TEST_BOOLEAN_FALSE(is_absolute(r));
#endif /* LIBPATH_OS_IS_WINDOWS */
}

static void TEST_INVALID_CHARS(void)
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

    { for (libpath_size_t i = 0; i != STLSOFT_NUM_ELEMENTS(bad_chars); ++i)
    {
        { for (libpath_size_t j = 0; j != STLSOFT_NUM_ELEMENTS(input_template) - 1; ++j)
        {
            char input[STLSOFT_NUM_ELEMENTS(input_template)];

            STLSOFT_STATIC_ASSERT(sizeof(input) == sizeof(input_template));

            memcpy(input, input_template, sizeof(input));

            input[j] = bad_chars[i];

            ParseResult_t   r;
            LIBPATH_RC      rc;
            StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];
            libpath_size_t  firstBadCharOffset;

            rc = parse_path_from_cstyle_string(input, 0, LIBPATH_LF_nullptr, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

            XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);

            rc = parse_path_from_cstyle_string(input, 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0], &firstBadCharOffset);

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

            XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);

            rc = parse_path_from_cstyle_string(input, 0, &r, directoryPartSlices, &firstBadCharOffset);
#endif

            XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
            XTESTS_TEST_INTEGER_EQUAL(31u, r.input.len);
            XTESTS_TEST_INTEGER_EQUAL(j, firstBadCharOffset);
        }}
    }}
}

static void TEST_Windows_INVALID_CHARS(void)
{
#ifdef LIBPATH_OS_IS_WINDOWS
    ParseResult_t   r;
    LIBPATH_RC      rc;
    libpath_size_t  firstBadCharOffset;


    rc = parse_path_from_cstyle_string(":C\\dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C:\\dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);


    rc = parse_path_from_cstyle_string("C\\:dir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C\\d:ir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C\\di:r\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, firstBadCharOffset);


    rc = parse_path_from_cstyle_string("C\\dir:\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, firstBadCharOffset);


    rc = parse_path_from_cstyle_string("\\:Cdir\\file.ext", 0, &r, 0, LIBPATH_LF_nullptr, &firstBadCharOffset);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_BadPathCharacter, rc);
    XTESTS_TEST_INTEGER_EQUAL(15u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, firstBadCharOffset);


#endif
}

static void TEST_directoryParts(void)
{
    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);
}

static void TEST_directoryParts_2(void)
{
    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc/def", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(3u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/def/", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("def/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/def", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("def", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/def/", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(8u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("def/", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


}

static void TEST_directoryParts_3(void)
{
    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc/..", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);


    rc = parse_path_from_cstyle_string("abc/../", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("../", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/..", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("..", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/../", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(7u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(3u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("../", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


}

static void TEST_directoryParts_4(void)
{
    ParseResult_t   r;
    LIBPATH_RC      rc;
    StringSlice_t   directoryPartSlices[NUM_DP_ELEMENTS];


    rc = parse_path_from_cstyle_string("abc/.", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(4u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryNamePart.len);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.entryStemPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryExtensionPart.len);


    rc = parse_path_from_cstyle_string("abc/./", 0, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("./", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/.", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(5u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(1u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(".", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


    rc = parse_path_from_cstyle_string("abc/./", libpath_ParseOption_AssumeDirectory, &r, STLSOFT_NUM_ELEMENTS(directoryPartSlices), &directoryPartSlices[0]);

    XTESTS_TEST_ENUM_EQUAL(libpath_ResultCode_Success, rc);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.input.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.fullPath.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.locationPart.len);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.rootPart.len);
    XTESTS_TEST_INTEGER_EQUAL(6u, r.directoryPart.len);
    XTESTS_TEST_INTEGER_EQUAL(2u, r.numDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(4u, directoryPartSlices[0].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc/", directoryPartSlices[0]);
    XTESTS_TEST_INTEGER_EQUAL(2u, directoryPartSlices[1].len);
    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("./", directoryPartSlices[1]);
    XTESTS_TEST_INTEGER_EQUAL(1u, r.numDotsDirectoryParts);
    XTESTS_TEST_INTEGER_EQUAL(0u, r.entryNamePart.len);


}


/* ///////////////////////////// end of file //////////////////////////// */

