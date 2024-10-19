/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.type_strings.cpp
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

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

    static void test_rc_known_values(void);
    static void test_rcx_known_values(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.type_strings", verbosity))
    {
        XTESTS_RUN_CASE(test_rc_known_values);
        XTESTS_RUN_CASE(test_rcx_known_values);

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
    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(UnsupportedOperation);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("operation is not supported", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(UnexpectedCondition);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("unexpected condition", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(OutOfMemory);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("out of memory", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(NoPathSpecified);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("no path specified", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(BadPathCharacter);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bad path character", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(OptionNotSupported);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("option not supported", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(InvalidRoot);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("invalid root", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a reserved parameter that is reserved for future use must have the value 0 or NULL", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(FirstPathInvalid);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("first/only path parameter is invalid", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(SecondPathInvalid);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("second path parameter is invalid", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(WorkingDirectoryPathInvalid);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("working directory path parameter is invalid", s);
    }

    {
        LIBPATH_RC const    rc  =   LIBPATH_RC_OF(Success);
        std::string const   s   =   std::string(libpath_rc_getStringPtr(rc), libpath_rc_getStringLen(rc));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("operation completed successfully", s);
    }
}

static void test_rcx_known_values()
{
    {
        LIBPATH_RCX const   rcx =   LIBPATH_RCX_OF(Success);
        std::string const   s   =   std::string(libpath_rcx_getStringPtr(rcx), libpath_rcx_getStringLen(rcx));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("operation completed successfully", s);
    }

}


/* ///////////////////////////// end of file //////////////////////////// */

