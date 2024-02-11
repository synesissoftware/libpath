/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/types/fundamental_.h
 *
 * Purpose: Fundamental types.
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
 * NOTES:
 *
 * For the moment, we assume stdint.h. That's ok, because *my* installations
 * of VC6-9 have one present (because I wrote one and placed it in the VC6-9
 * INCLUDE paths); other users of VC6-9 (if there are any left) will be out
 * of luck, but may utilise the same trick.
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifdef LIBPATH_CXX_VER_2011_plus
# include <cstddef>
# include <cstdint>
#else
# include <stddef.h>
# include <stdint.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * feature discrimination
 */

/** @def LIBPATH_USE_WIDE_STRINGS
 *
 * @brief The character type used by the library
 *
 * @note If compiling for Windows (LIBPATH_OS_IS_WINDOWS is defined) _and_
 *  the preprocessor symbol @c _UNICODE is defined _and_ the preprocessor
 *  symbol @c LIBPATH_NO_USE_WIDE_STRINGS is _not_ defined, then
 *  libpath_char_t is defined to be @c wchar_t; in all circumstances
 *  otherwise, libpath_char_t is defined to be @c char.
 */

/** @def LIBPATH_NO_USE_WIDE_STRINGS
 *
 * @brief Suppresses any possible definition of LIBPATH_USE_WIDE_STRINGS
 */

#ifndef LIBPATH_USE_WIDE_STRINGS
# if 0
# elif defined(LIBPATH_OS_IS_WINDOWS) && \
       defined(_UNICODE)
#  define LIBPATH_USE_WIDE_STRINGS
# endif /* _WIN32 && UNICODE && _UNICODE */
#endif /* !LIBPATH_USE_WIDE_STRINGS */

#ifdef LIBPATH_NO_USE_WIDE_STRINGS
# ifdef LIBPATH_USE_WIDE_STRINGS
#  undef LIBPATH_USE_WIDE_STRINGS
# endif /* LIBPATH_USE_WIDE_STRINGS */
#endif /* LIBPATH_NO_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */


#if 0
#elif defined(LIBPATH_USE_WIDE_STRINGS)
# ifdef LIBPATH_CXX_VER_2011_plus
#  include <cwchar>
# else
#  include <wchar.h>    /* for wchar_t (if not built-in) */
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

#if 0
#elif defined(LIBPATH_USE_WIDE_STRINGS)

# ifdef LIBPATH_CXX_VER_2011_plus

typedef wchar_t                                             libpath_char_t;
# else

typedef wchar_t                                             libpath_char_t;
# endif
#else

typedef char                                                libpath_char_t;
#endif

#ifdef LIBPATH_CXX_VER_2011_plus

typedef std::size_t                                         libpath_size_t;

typedef std::int32_t                                        libpath_sint32_t;

typedef std::uint32_t                                       libpath_uint32_t;

typedef std::uintptr_t                                      libpath_uintptr_t;
#else

typedef size_t                                              libpath_size_t;

typedef int32_t                                             libpath_sint32_t;

typedef uint32_t                                            libpath_uint32_t;

typedef uintptr_t                                           libpath_uintptr_t;
#endif


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

