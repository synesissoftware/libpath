/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/types/slices_.h
 *
 * Purpose: Slice types.
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


#ifndef SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_types
# error SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_types not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_types */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifdef LIBPATH_CXX_VER_2011_plus
# include <cstddef>
#else
# include <stddef.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** String slice type
 */
struct libpath_StringSlice_t
{
    /** @brief Number of characters available at @c ptr */
    libpath_size_t          len;
    /** @brief Pointer to first of @c len character(s) available */
    libpath_char_t const*   ptr;
};
#ifdef __cplusplus
#else /* ? __cplusplus */
typedef struct libpath_StringSlice_t                        libpath_StringSlice_t;
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef __cplusplus

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {


typedef libpath_StringSlice_t                               StringSlice_t;

} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

