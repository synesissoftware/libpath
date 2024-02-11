/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/shims/access/string/StringSlice.hpp
 *
 * Purpose: Definition of String Access Shims for libpath StringSlice.
 *
 * Created: 13th February 2013
 * Updated: 11th February 2024
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_shims_access_string_HPP_StringSlice
#define SYNSOFT_LIBPATH_INCL_libpath_shims_access_string_HPP_StringSlice


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/common/portability.h>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft {
#endif /* !STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

inline
libpath_char_t const*
#if 0
#elif defined(LIBPATH_USE_WIDE_STRINGS)
c_str_data_w(
    LIBPATH_NS_QUALIFY(StringSlice_t) const& slice
)
#else
c_str_data_a(
    LIBPATH_NS_QUALIFY(StringSlice_t) const& slice
)
#endif
{
    return slice.ptr;
}


inline
libpath_size_t
#if 0
#elif defined(LIBPATH_USE_WIDE_STRINGS)
c_str_len_w(
    LIBPATH_NS_QUALIFY(StringSlice_t) const& slice
)
#else
c_str_len_a(
    LIBPATH_NS_QUALIFY(StringSlice_t) const& slice
)
#endif
{
    return slice.len;
}

inline
libpath_char_t const*
c_str_data(
    LIBPATH_NS_QUALIFY(StringSlice_t) const& slice
)
{
    return slice.ptr;
}

inline
libpath_size_t
c_str_len(
    LIBPATH_NS_QUALIFY(StringSlice_t) const& slice
)
{
    return slice.len;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* !STLSOFT_NO_NAMESPACE */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_shims_access_string_HPP_StringSlice */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

