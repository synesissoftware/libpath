/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/compare.hpp
 *
 * Purpose: C++ include for libpath Comparing API.
 *
 * Created: 9th November 2012
 * Updated: 11th February 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2012-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SYNSOFT_LIBPATH_INCL_libpath_HPP_compare
#define SYNSOFT_LIBPATH_INCL_libpath_HPP_compare


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/compare.h>
#include <libpath/common/types.hpp>

#ifdef LIBPATH_CXX_VER_2011_plus
# include <cstdlib>
# include <cstring>
#else
# include <stdlib.h>
# include <string.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * preprocessor feature control
 */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace comparing {


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

namespace ximpl_compare {

// The following are borrowed (by kind permission of me) from STLSoft:
//
// - `no_type`
// - `yes_type`
// - `value_to_yesno_type`

struct no_type
{
    char ar[1];
};

struct yes_type
{
    char ar[32];
};

template <int B>
struct value_to_yesno_type
{
    enum { value = 1 };

    typedef yes_type                                        type;
};
template <>
struct value_to_yesno_type<0>
{
    enum { value = 0 };

    typedef no_type                                         type;
};




template <typename P>
int
handle_compare_result_(
    LIBPATH_RC   /* rc     */
,   char const*  /* lhs    */
,   char const*  /* rhs    */
,   char const*  /* cwd    */
,   int          /* result */
,   yes_type
,   ...
)
{
    return 0;
}

template <typename P>
int
handle_compare_result_(
    LIBPATH_RC   /* rc     */
,   char const*  /* lhs    */
,   char const*  /* rhs    */
,   char const*  /* cwd    */
,   int          /* result */
,   no_type
,   yes_type
,   ...
)
{
    return -1;
}

template <typename P>
int
handle_compare_result_(
    LIBPATH_RC      rc
,   char const*     lhs
,   char const*     rhs
,   char const*     cwd
,   int          /* result */
,   no_type
,   no_type
,   yes_type
,   ...
)
{
    char const* p = NULL;

    switch (rc)
    {
    case  libpath_ResultCode_FirstPathInvalid:            p = lhs; break;
    case  libpath_ResultCode_SecondPathInvalid:           p = rhs; break;
    case  libpath_ResultCode_WorkingDirectoryPathInvalid: p = cwd; break;

    default:
        break;
    }

    if (NULL != p)
    {
        libpath_StringSlice_t path = {
#ifdef LIBPATH_CXX_VER_2011_plus
            std::strlen(p)
#else
            ::strlen(p)
#endif
            ,   p
        };

        P::respond(rc, &path);
    }
    else
    {
        P::respond(rc, NULL);
    }

    return 0;
}

template <typename P>
int
handle_compare_result_(
    LIBPATH_RC   /* rc     */
,   char const*  /* lhs    */
,   char const*  /* rhs    */
,   char const*  /* cwd    */
,   int          /* result */
,   no_type
,   no_type
,   no_type
,   yes_type
)
{
#ifdef LIBPATH_CXX_VER_2011_plus
    std::abort();
#else
    ::abort();
#endif

    return 0;
}

template <typename P>
int
handle_compare_result_(
    LIBPATH_RC      rc
,   char const*     lhs
,   char const*     rhs
,   char const*     cwd
,   int             result
)
{
    typedef typename value_to_yesno_type<P::return_0>::type         return_0_type;
    typedef typename value_to_yesno_type<P::return_minus1>::type    return_minus1_type;
    typedef typename value_to_yesno_type<P::throw_exception>::type  throw_exception_type;
    typedef typename value_to_yesno_type<P::invoke_abend>::type     invoke_abend_type;

    return handle_compare_result_<P>(
            rc
        ,   lhs
        ,   rhs
        ,   cwd
        ,   result
        ,   return_0_type()
        ,   return_minus1_type()
        ,   throw_exception_type()
        ,   invoke_abend_type()
        );
}

template <typename P>
int
compare_paths_and_(
    char const*     lhs
,   char const*     rhs
,   char const*     cwd = NULL
,   char const*  /* mem */ = NULL
)
{
    libpath_sint32_t                    flags   =   0;
    libpath_WorkingDirectoryContext_t   ctxt;
    int                                 result;

    ctxt.mechanism          =   libpath_WorkingDirectoryContextMechanism_CStyleString;
    ctxt.details.cwd_css    =   cwd;

    LIBPATH_RC const rc = libpath_Compare_ComparePathsAsCStyleStrings(
            lhs
        ,   rhs
        ,   flags
        ,   &ctxt
        ,   NULL
        ,   &result
        );

    if (LIBPATH_RC_OF(Success) != rc)
    {
        return handle_compare_result_<P>(rc, lhs, rhs, cwd, result);
    }

    return result;
}

} /* namespace ximpl_compare */




template <typename P>
int
compare_paths_and_(
    char const*     lhs
,   char const*     rhs
,   char const*     cwd = NULL
,   char const*     mem = NULL
)
{
    return ximpl_compare::compare_paths_and_<P>(lhs, rhs, cwd, mem);
}


int
compare_paths(
    char const*     lhs
,   char const*     rhs
,   char const*     cwd = NULL
,   char const*     mem = NULL
);


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace comparing */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_HPP_compare */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

