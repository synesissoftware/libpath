/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.version.c
 *
 * Purpose: Unit-test the library version macros.
 *
 * Created: 8th February 2024
 * Updated: 8th February 2024
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
#include <stdlib.h>
#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_version(void);


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.version", verbosity))
    {
        XTESTS_RUN_CASE(test_version);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_version(void)
{
    unsigned const  major   =   (LIBPATH_VER >> 24) & 0xff;
    unsigned const  minor   =   (LIBPATH_VER >> 16) & 0xff;
    unsigned const  patch   =   (LIBPATH_VER >>  8) & 0xff;
    unsigned const  ab      =   (LIBPATH_VER >>  0) & 0xff;

    XTESTS_TEST_INTEGER_EQUAL_EXACT(LIBPATH_VER_MAJOR, major);
    XTESTS_TEST_INTEGER_EQUAL_EXACT(LIBPATH_VER_MINOR, minor);
    XTESTS_TEST_INTEGER_EQUAL_EXACT(LIBPATH_VER_REVISION, patch);
    XTESTS_TEST_INTEGER_EQUAL_EXACT(LIBPATH_VER_ALPHABETA, ab);
}


/* ///////////////////////////// end of file //////////////////////////// */

