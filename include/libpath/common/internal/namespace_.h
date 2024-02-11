/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/internal/namespace_.h
 *
 * Purpose: Conditional discrimination and declaration for namespace for
 *          libpath library.
 *
 * Created: 20th November 2016
 * Updated: 11th February 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2016-2019, Matthew Wilson and Synesis Software
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


#ifndef SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_internal
# error SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_internal not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_internal */


/* /////////////////////////////////////////////////////////////////////////
 * feature discrimination
 */

#ifndef LIBPATH_NO_NAMESPACE
# ifndef __cplusplus
#  define LIBPATH_NO_NAMESPACE
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** @def LIBPATH_NS_OUTER_NAMESPACE_NAME
 *
 * @brief Specifies, if defined, the libpath library outer namespace; if
 *   not specified then defaults to `libpath`
 */

#ifndef LIBPATH_NS_OUTER_NAMESPACE_NAME
# define LIBPATH_NS_OUTER_NAMESPACE_NAME                    libpath
#endif


/** @def LIBPATH_NS_QUALIFY(name)
 *
 * @brief Qualifies @c name with `::libpath::`
 */

#ifndef LIBPATH_NO_NAMESPACE

# define LIBPATH_NS_QUALIFY(t)                              ::LIBPATH_NS_OUTER_NAMESPACE_NAME::t
#else

# define LIBPATH_NS_QUALIFY(t)                              t
#endif


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef LIBPATH_NO_NAMESPACE
namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {

} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */
#endif


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

