/* /////////////////////////////////////////////////////////////////////////
* File:        libpath/parse.hpp
*
* Purpose:     C++ include for libpath library's Parsing API.
*
* Created:     29th March 2013
* Updated:     20th November 2016
*
* Home:        http://synesis.com.au/software/
*
* Copyright (c) 2013, Matthew Wilson and Synesis Software
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



#include <libpath/parse.h>
#include <libpath/common/types.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace libpath {
namespace parsing {

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef libpath_ParseResult_t                               ParseResult_t;


class dp_slices
{
public: // Member types
    typedef StringSlice_t               string_slice_type;
    typedef string_slice_type*          pointer;
    typedef string_slice_type const*    const_pointer;
    typedef string_slice_type&          reference;
    typedef string_slice_type const&    const_reference;
    typedef pointer                     iterator;
    typedef const_pointer               const_iterator;
    typedef size_t                      size_type;

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
,   ParseResult_t*          result
,   size_t                  numDirectoryPartSlices
,   StringSlice_t*          directoryPartSlices
)
{
    return libpath_Parse_ParsePathFromStringSlice(path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

inline
LIBPATH_RC
parse_path_from_string_slice(
    StringSlice_t const&    path
,   sint32_t                flags
,   ParseResult_t*          result
,   size_t                  numDirectoryPartSlices
,   StringSlice_t*          directoryPartSlices
)
{
    return libpath_Parse_ParsePathFromStringSlice(&path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

inline
LIBPATH_RC
parse_path_from_string_ptr_and_len(
    libpath_char_t const*   path
,   size_t                  pathLen
,   sint32_t                flags
,   ParseResult_t*          result
,   size_t                  numDirectoryPartSlices
,   StringSlice_t*          directoryPartSlices
)
{
    return libpath_Parse_ParsePathFromStringPtrAndLen(path, pathLen, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

inline
LIBPATH_RC
parse_path_from_cstyle_string(
    libpath_char_t const*   path
,   sint32_t                flags
,   ParseResult_t*          result
,   size_t                  numDirectoryPartSlices
,   StringSlice_t*          directoryPartSlices
)
{
    return libpath_Parse_ParsePathFromCStyleString(path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}



inline
bool
is_absolute(
    ParseResult_t const& result
)
{
    return 0 != libpath_ParseResult_IsPathAbsolute(result);
}

inline
bool
is_rooted(
    ParseResult_t const& result
)
{
    return 0 != libpath_ParseResult_IsPathRooted(result);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace parsing */
} /* namespace libpath */

/* ///////////////////////////// end of file //////////////////////////// */
