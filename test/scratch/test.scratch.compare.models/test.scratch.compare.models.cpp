/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.compare.models.cpp
 *
 * Purpose:     Implementation file for the test.scratch.compare.models project.
 *
 * Created:     29th March 2013
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
 * includes
 */

#include <libpath/compare.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <exception>
#include <new>
#include <typeinfo>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_return_0();
static void test_return_minus1();
static void test_throw();
static void test_abend();

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char** /*argv*/)
{
    int r0 = ::libpath::comparing::compare_paths_and_<libpath::return_0_on_invalid_path_policy>("/abc", "../def/abc");

    int r1 = ::libpath::comparing::compare_paths_and_<libpath::return_minus1_on_invalid_path_policy>("/abc", "../def/abc");


    try
    {
        int r2 = ::libpath::comparing::compare_paths_and_<libpath::throw_on_invalid_path_policy>("/abc", "../def/abc");
    }
    catch(std::bad_alloc&)
    {
        throw;
    }
    catch(std::exception& x)
    {
        fprintf(stdout, "exception (%s): %s\n", typeid(x).name(), x.what());
    }

    try
    {
        int r3 = ::libpath::comparing::compare_paths_and_<libpath::throw_on_invalid_path_policy>("/abc", ".|./def/abc");
    }
    catch(std::bad_alloc&)
    {
        throw;
    }
    catch(std::exception& x)
    {
        fprintf(stdout, "exception (%s): %s\n", typeid(x).name(), x.what());
    }


    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
#endif /* debug */

        return main_(argc, argv);
    }
    catch(std::bad_alloc&)
    {
        fputs("out of memory\n", stderr);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "exception: %s\n", x.what());
    }
#if 0
    catch(...)
    {
    }
#endif /* 0 */

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
