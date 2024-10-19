/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.shim_strings.cpp
 *
 * Purpose: Unit-test for shim-strings.
 *
 * Created: 11th February 2024
 * Updated: 19th October 2024
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
#include <xtests/xtests.h>
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

    if (XTESTS_START_RUNNER("test.unit.shim_strings", verbosity))
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
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("operation is not supported", stlsoft::sas_to_string(LIBPATH_RC_OF(UnsupportedOperation)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("unexpected condition", stlsoft::sas_to_string(LIBPATH_RC_OF(UnexpectedCondition)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("out of memory", stlsoft::sas_to_string(LIBPATH_RC_OF(OutOfMemory)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("no path specified", stlsoft::sas_to_string(LIBPATH_RC_OF(NoPathSpecified)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bad path character", stlsoft::sas_to_string(LIBPATH_RC_OF(BadPathCharacter)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("option not supported", stlsoft::sas_to_string(LIBPATH_RC_OF(OptionNotSupported)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("invalid root", stlsoft::sas_to_string(LIBPATH_RC_OF(InvalidRoot)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a reserved parameter that is reserved for future use must have the value 0 or NULL", stlsoft::sas_to_string(LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("first/only path parameter is invalid", stlsoft::sas_to_string(LIBPATH_RC_OF(FirstPathInvalid)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("second path parameter is invalid", stlsoft::sas_to_string(LIBPATH_RC_OF(SecondPathInvalid)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("working directory path parameter is invalid", stlsoft::sas_to_string(LIBPATH_RC_OF(WorkingDirectoryPathInvalid)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("operation completed successfully", stlsoft::sas_to_string(LIBPATH_RC_OF(Success)));
}


/* ///////////////////////////// end of file //////////////////////////// */

