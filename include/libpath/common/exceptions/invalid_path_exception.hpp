/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/exceptions/invalid_path_exception.hpp
 *
 * Purpose: Definition of libpath::exceptions::invalid_path_exception.
 *
 * Created: 5th April 2013
 * Updated: 4th May 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2013-2019, Matthew Wilson and Synesis Software
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_exceptions_HPP_invalid_path_exception
#define SYNSOFT_LIBPATH_INCL_libpath_common_exceptions_HPP_invalid_path_exception


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/common/internal.h>

#include <libpath/common/exceptions/libpath_exception.hpp>

#include <string>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace exceptions {


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

class invalid_path_exception
    : public libpath_exception
{
public: // Member types
    /// The parent class type
    typedef libpath_exception                               parent_class_type;
    /// The type of this class
    typedef invalid_path_exception                          class_type;
    /// The string type
    typedef std::string                                     string_type;

public: // Construction
    /// Constructs an instance of this type.
    invalid_path_exception(
        LIBPATH_RC                      rc
    ,   libpath_StringSlice_t const*    path
    )
        : parent_class_type("invalid path")
        , rc(rc)
        , path(LIBPATH_LF_nullptr == path ? "" : path->ptr, LIBPATH_LF_nullptr == path ? 0u : path->len)
    {}
    ~invalid_path_exception() LIBPATH_LF_noexcept
    {}
private:
    class_type& operator =(class_type const&);

public: // Fields
    LIBPATH_RC const    rc;
    string_type const   path;
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace exceptions */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_exceptions_HPP_invalid_path_exception */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

