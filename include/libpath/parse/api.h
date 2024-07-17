/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/parse/api.h
 *
 * Purpose: libpath Parsing API.
 *
 * Created: 9th November 2012
 * Updated: 4th May 2024
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_parse_H_api
#define SYNSOFT_LIBPATH_INCL_libpath_parse_H_api


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <libpath/parse/types.h>
#include <libpath/common/macros.h>
#include <libpath/common/version.h>


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Parses a path
 *
 * @param path The path to parse. May not be NULL.
 * @param flags Flags that moderate the parsing
 * @param result Structure to receive the detailed results. May be NULL.
 * @param numDirectoryPartSlices Number of slices in the array pointed to
 *   by the directoryPartSlices parameter. May be less than the total
 *   number of slices detected by the function, in which case only the
 *   number requested will be copied into the array. May be 0, in which
 *   case the directoryPartSlices is ignored
 * @param directoryPartSlices Pointer to an array of slices that will be
 *   set to contain the path's directory parts. At most
 *   numDirectoryPartSlices will be written, even if that is less than
 *   the number available. May only be NULL if numDirectoryPartSlices is
 *   0
 *
 * @return A value of the libpath_rc_t (aka LIBPATH_RC) enumeration
 *   indicating the results of the parsing
 * @retval libpath_ResultCode_Success the path has been parsed correctly
 *   and recognised as valid
 * @retval libpath_ResultCode_BadPathCharacter the @c path parameter
 *   specifies a string containing an invalid path character (such as
 *   '|', '<', '>', '?', '*'). If @c result is specified,
 *   the @c firstBadCharOffset will specify the offset of the (bad)
 *   character that terminated parsing; in all other cases its value is
 *   unspecified (and callers should not rely on any value at all).
 *
 * @note If this function has previously succeeded for a given path, it
 *   is guaranteed to succeed on a subsequent attempt. This allows for a
 *   caller to parse the path passing few (or no) directory part slices
 *   and then, once succeeded, call again passing sufficient directory
 *   part slices. (In practise, it may be more efficient to try with a
 *   commonly sufficient number of slices (probably on the stack), and
 *   only go to the (slight) expense of an allocation and second call
 *   when necessary.)
 * @note Regardless of whether the function succeeds or fails, if a
 *   @c result parameter is passed, its @c input slice member will be set
 *   to reflect the characteristics of the input.
 *
 *
 * @pre NULL != path
 * @pre 0 == numDirectoryPartSlices || NULL != directoryPartSlices
 */
LIBPATH_API
libpath_Parse_ParsePathFromStringSlice(
    libpath_StringSlice_t const*    path
,   libpath_sint32_t                flags
,   libpath_ParseResult_t*          result /* = NULL */
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices /* = NULL */
);

LIBPATH_API
libpath_Parse_ParsePathFromStringPtrAndLen(
    libpath_char_t const*       path
,   libpath_size_t              pathLen
,   libpath_sint32_t            flags
,   libpath_ParseResult_t*      result /* = NULL */
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices /* = NULL */
);

LIBPATH_API
libpath_Parse_ParsePathFromCStyleString(
    libpath_char_t const*       path
,   libpath_sint32_t            flags
,   libpath_ParseResult_t*      result /* = NULL */
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices /* = NULL */
);


/** Indicates whether a parsed-path's result indicates that the path was
 * absolute
 *
 * @param result Pointer to an instance of libpath_ParseResult_t previously
 *   filled out by a successful call to libpath_ParsePath() (or equiv.).
 *
 * @retval !0 The parsed path is absolute
 * @retval 0 The parsed path is not absolute
 *
 * @note On Unix a positive result indicates that the parsed path begins
 *   with a slash ('/'); on Windows it indicates that the parsed path
 *   begins with a volume+root specification (e.g. 'C:\' or 'C:/') or a
 *   UNC path specification (e.g. '\\server\share\ or '\\server\share/');
 *   a path beginning with a slash (i.e. '/') or a backslash (i.e. '\') is
 *   not considered absolute on Windows (though it is not relative either!)
 *
 * @pre NULL != result
 */
LIBPATH_CALL(int)
libpath_ParseResult_IsPathAbsolute(
    libpath_ParseResult_t const*    result
);

#ifdef __cplusplus
extern "C++"
inline
int
libpath_ParseResult_IsPathAbsolute(
    libpath_ParseResult_t const&    result
)
{
    return libpath_ParseResult_IsPathAbsolute(&result);
}
#endif /* __cplusplus */

/** Indicates whether a parsed-path's result indicates that the path was
 * rooted
 *
 * @retval !0 The parsed path is rooted
 * @retval 0 The parsed path is not rooted
 *
 * @note On Unix a positive result indicates that the parsed path begins
 *   with a slash ('/') (and this function is identical in function to
 *   libpath_ParseResult_IsPathAbsolute()); on Windows it indicates that
 *   the parsed path begins with a volume+root
 *   specification (e.g. 'C:\' or 'C:/') or a UNC path
 *   specification (e.g. '\\server\share\ or '\\server\share/') or a
 *   slash (i.e. '/') or a backslash (i.e. '\')
 *
 * @pre NULL != result
 */
LIBPATH_CALL(int)
libpath_ParseResult_IsPathRooted(
    libpath_ParseResult_t const*    result
);

#ifdef __cplusplus
extern "C++"
inline
int
libpath_ParseResult_IsPathRooted(
    libpath_ParseResult_t const&    result
)
{
    return libpath_ParseResult_IsPathRooted(&result);
}
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef __cplusplus

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace parsing {

} /* namespace parsing */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef __cplusplus

#if 0
# include <libpath/internal/shims/access/string/ParseOption.hpp>
# include <libpath/internal/shims/access/string/ResultCode.hpp>
#endif /* 0 */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_parse_H_api */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

