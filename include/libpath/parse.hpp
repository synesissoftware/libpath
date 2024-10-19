/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/parse.hpp
 *
 * Purpose: C++ include for libpath Parsing API.
 *
 * Created: 29th March 2013
 * Updated: 11th August 2024
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



#ifndef SYNSOFT_LIBPATH_INCL_libpath_HPP_parse
#define SYNSOFT_LIBPATH_INCL_libpath_HPP_parse


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/parse.h>
#include <libpath/common/types.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace parsing {


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef libpath_PathDescriptor_t                            PathDescriptor_t;


class dp_slices
{
public: // Member types
    typedef StringSlice_t                                   string_slice_type;
    typedef string_slice_type*                              pointer;
    typedef string_slice_type const*                        const_pointer;
    typedef string_slice_type&                              reference;
    typedef string_slice_type const&                        const_reference;
    typedef pointer                                         iterator;
    typedef const_pointer                                   const_iterator;
    typedef libpath_size_t                                  size_type;

public: // Construction
    dp_slices();

public: // Operations
    void            resize(size_type newSize);

public: // Iteration
    const_iterator  begin() const;
    const_iterator  end() const;

public: // Accessors
    const_reference operator [](size_type index) const;

private:

private:
    StringSlice_t   m_slices[10];
};


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

inline
LIBPATH_RC
parse_path_from_string_slice(
    StringSlice_t const*    path
,   sint32_t                flags
,   PathDescriptor_t*       result
,   libpath_size_t          numDirectoryPartSlices
,   StringSlice_t           directoryPartSlices[]
)
{
    return libpath_Parse_ParsePathFromStringSlice(path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

inline
LIBPATH_RC
parse_path_from_string_slice(
    StringSlice_t const&    path
,   sint32_t                flags
,   PathDescriptor_t*       result
,   libpath_size_t          numDirectoryPartSlices
,   StringSlice_t           directoryPartSlices[]
)
{
    return libpath_Parse_ParsePathFromStringSlice(&path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template <
    libpath_size_t  V_dimension
>
inline
LIBPATH_RC
parse_path_from_string_slice(
    StringSlice_t const*    path
,   sint32_t                flags
,   PathDescriptor_t*       result
,   StringSlice_t           (&directoryPartSlices)[V_dimension]
)
{
    return libpath_Parse_ParsePathFromStringSlice(path, flags, result, V_dimension, &directoryPartSlices[0]);
}

template <
    libpath_size_t  V_dimension
>
inline
LIBPATH_RC
parse_path_from_string_slice(
    StringSlice_t const&    path
,   sint32_t                flags
,   PathDescriptor_t*       result
,   StringSlice_t           (&directoryPartSlices)[V_dimension]
)
{
    return libpath_Parse_ParsePathFromStringSlice(&path, flags, result, V_dimension, &directoryPartSlices[0]);
}
#endif /* C++11 or later */

inline
LIBPATH_RC
parse_path_from_string_ptr_and_len(
    libpath_char_t const*   path
,   libpath_size_t          pathLen
,   sint32_t                flags
,   PathDescriptor_t*       result
,   libpath_size_t          numDirectoryPartSlices
,   StringSlice_t           directoryPartSlices[]
)
{
    return libpath_Parse_ParsePathFromStringPtrAndLen(path, pathLen, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

inline
LIBPATH_RC
parse_path_from_cstyle_string(
    libpath_char_t const*   path
,   sint32_t                flags
,   PathDescriptor_t*       result
,   libpath_size_t          numDirectoryPartSlices
,   StringSlice_t           directoryPartSlices[]
)
{
    return libpath_Parse_ParsePathFromCStyleString(path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

#ifdef LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template <
    libpath_size_t  V_dimension
>
inline
LIBPATH_RC
parse_path_from_cstyle_string(
    libpath_char_t const*   path
,   sint32_t                flags
,   PathDescriptor_t*       result
,   StringSlice_t           (&directoryPartSlices)[V_dimension]
)
{
    return libpath_Parse_ParsePathFromCStyleString(path, flags, result, V_dimension, &directoryPartSlices[0]);
}
#endif /* C++11 or later */



inline
bool
is_absolute(
    PathDescriptor_t const& result
)
{
    return 0 != libpath_ParseResult_IsPathAbsolute(result);
}

inline
bool
is_rooted(
    PathDescriptor_t const& result
)
{
    return 0 != libpath_ParseResult_IsPathRooted(result);
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace parsing */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_HPP_parse */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

