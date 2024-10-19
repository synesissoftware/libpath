/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.compare.models.cpp
 *
 * Purpose: Implementation file for the test.scratch.compare.models project.
 *
 * Created: 29th March 2013
 * Updated: 19th October 2024
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
 * main()
 */

static int main_(int /* argc */, char* /*argv*/[])
{
    int r0 = ::libpath::comparing::compare_paths_and_<libpath::return_0_on_invalid_path_policy>("/abc", "../def/abc");

    STLSOFT_SUPPRESS_UNUSED(r0);

    int r1 = ::libpath::comparing::compare_paths_and_<libpath::return_minus1_on_invalid_path_policy>("/abc", "../def/abc");

    STLSOFT_SUPPRESS_UNUSED(r1);


    try
    {
        int r2 = ::libpath::comparing::compare_paths_and_<libpath::throw_on_invalid_path_policy>("/abc", "../def/abc");

        STLSOFT_SUPPRESS_UNUSED(r2);
    }
    catch (std::bad_alloc&)
    {
        throw;
    }
    catch (std::exception& x)
    {
        fprintf(stdout, "exception (%s): %s\n", typeid(x).name(), x.what());
    }

    try
    {
        int r3 = ::libpath::comparing::compare_paths_and_<libpath::throw_on_invalid_path_policy>("/abc", ".|./def/abc");

        STLSOFT_SUPPRESS_UNUSED(r3);
    }
    catch (std::bad_alloc&)
    {
        throw;
    }
    catch (std::exception& x)
    {
        fprintf(stdout, "exception (%s): %s\n", typeid(x).name(), x.what());
    }


    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
#if 0
    { for (libpath_size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
#endif /* debug */

        return main_(argc, argv);
    }
    catch (std::bad_alloc&)
    {
        fputs("out of memory\n", stderr);
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "exception: %s\n", x.what());
    }
#if 0
    catch (...)
    {
    }
#endif /* 0 */

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

