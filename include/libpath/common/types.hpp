/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/common/types.hpp
 *
 * Purpose:     Main include for common types defined for libpath library.
 *
 * Created:     29th March 2013
 * Updated:     20th November 2016
 *
 * Home:        http://synesis.com.au/software/
 *
 * Copyright (c) 2013-2016, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_HPP_types
#define SYNSOFT_LIBPATH_INCL_libpath_common_HPP_types

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/common/types.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace libpath {

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef libpath_sint32_t                                    sint32_t;
typedef libpath_StringSlice_t                               StringSlice_t;

struct return_0_on_invalid_path_policy
{
    enum {  return_0        =   true  };
    enum {  return_minus1   =   false };
    enum {  throw_exception =   false };
    enum {  invoke_abend    =   false };
};

struct return_minus1_on_invalid_path_policy
{
    enum {  return_0        =   false };
    enum {  return_minus1   =   true  };
    enum {  throw_exception =   false };
    enum {  invoke_abend    =   false };
};

struct throw_on_invalid_path_policy
{
    enum {  return_0        =   false };
    enum {  return_minus1   =   false };
    enum {  throw_exception =   true  };
    enum {  invoke_abend    =   false };

    /**
     *
     * \exception libpath::exceptions::invalid_path
     * \exception std::bad_alloc
     */
    static
    void
    respond(
        LIBPATH_RC                    rc
    ,   libpath_StringSlice_t const*  path
    );
};

struct abort_on_invalid_path_policy
{
    enum {  return_0        =   false };
    enum {  return_minus1   =   false };
    enum {  throw_exception =   false };
    enum {  invoke_abend    =   true  };

#ifdef _MSC_VER
    __declspec(noreturn)
#endif /* compiler */
    static
    void
    respond(
        LIBPATH_RC                    rc
    ,   libpath_StringSlice_t const*  path
    );
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace libpath */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_HPP_types */

/* ///////////////////////////// end of file //////////////////////////// */
