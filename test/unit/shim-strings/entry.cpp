/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/shim-strings/entry.cpp
 *
 * Purpose: Unit-tests the libpath string shims.
 *
 * Created: 11th February 2024
 * Updated: 14th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <libpath/common/types.h>

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
#include <stlsoft/conversion/sas_to_string.hpp>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_rc_known_values(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.shim-strings", verbosity))
    {
        XTESTS_RUN_CASE(test_rc_known_values);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_rc_known_values()
{
    TEST_MS_EQ("operation is not supported", stlsoft::sas_to_string(LIBPATH_RC_OF(UnsupportedOperation)));

    TEST_MS_EQ("unexpected condition", stlsoft::sas_to_string(LIBPATH_RC_OF(UnexpectedCondition)));

    TEST_MS_EQ("out of memory", stlsoft::sas_to_string(LIBPATH_RC_OF(OutOfMemory)));

    TEST_MS_EQ("no path specified", stlsoft::sas_to_string(LIBPATH_RC_OF(NoPathSpecified)));

    TEST_MS_EQ("bad path character", stlsoft::sas_to_string(LIBPATH_RC_OF(BadPathCharacter)));

    TEST_MS_EQ("option not supported", stlsoft::sas_to_string(LIBPATH_RC_OF(OptionNotSupported)));

    TEST_MS_EQ("invalid root", stlsoft::sas_to_string(LIBPATH_RC_OF(InvalidRoot)));

    TEST_MS_EQ("a reserved parameter that is reserved for future use must have the value 0 or NULL", stlsoft::sas_to_string(LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero)));

    TEST_MS_EQ("first/only path parameter is invalid", stlsoft::sas_to_string(LIBPATH_RC_OF(FirstPathInvalid)));

    TEST_MS_EQ("second path parameter is invalid", stlsoft::sas_to_string(LIBPATH_RC_OF(SecondPathInvalid)));

    TEST_MS_EQ("working directory path parameter is invalid", stlsoft::sas_to_string(LIBPATH_RC_OF(WorkingDirectoryPathInvalid)));

    TEST_MS_EQ("operation completed successfully", stlsoft::sas_to_string(LIBPATH_RC_OF(Success)));
}


/* ///////////////////////////// end of file //////////////////////////// */

