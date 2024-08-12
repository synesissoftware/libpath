/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/portability/language_.h
 *
 * Purpose: Language discrimination for libpath library.
 *
 * Created: 2nd February 2013
 * Updated: 12th August 2024
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


#ifndef SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_portability
# error SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_portability not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_portability */


/* /////////////////////////////////////////////////////////////////////////
 * compiler discrimination
 *
 * Discriminated features (that cannot be specified):
 * - LIBPATH_CXX_VER - defined, for C++, the language version, as one of
 *   2023, 2020, 2017, 2014, 2011, 1998, or, if the version is not
 *   recognised, 0. Not defined for C language;
 * - LIBPATH_CXX_VER_2023_plus - defined, for C++, if C++23 or later;
 * - LIBPATH_CXX_VER_202101_plus - defined, for C++, if C++2b or later;
 * - LIBPATH_CXX_VER_2020_plus - defined, for C++, if C++20 or later;
 * - LIBPATH_CXX_VER_2017_plus - defined, for C++, if C++17 or later;
 * - LIBPATH_CXX_VER_2014_plus - defined, for C++, if C++14 or later;
 * - LIBPATH_CXX_VER_2011_plus - defined, for C++, if C++1x or later;
 * - LIBPATH_CXX_VER_1998_plus - defined, for C++, if C++98 or later;
 */

/** @def LIBPATH_CXX_VER
 *
 * Year-only value of C++ language version, e.g. 1998, 2003, ... 2023
 *
 * @note Not defined if translation is C
 */

#ifdef LIBPATH_CXX_VER
# undef LIBPATH_CXX_VER
#endif /* !LIBPATH_CXX_VER */
#ifdef LIBPATH_CXX_VER_2023_plus
# undef LIBPATH_CXX_VER_2023_plus
#endif /* !LIBPATH_CXX_VER_2023_plus */
#ifdef LIBPATH_CXX_VER_202101_plus
# undef LIBPATH_CXX_VER_202101_plus
#endif /* !LIBPATH_CXX_VER_202101_plus */
#ifdef LIBPATH_CXX_VER_2020_plus
# undef LIBPATH_CXX_VER_2020_plus
#endif /* !LIBPATH_CXX_VER_2020_plus */
#ifdef LIBPATH_CXX_VER_2017_plus
# undef LIBPATH_CXX_VER_2017_plus
#endif /* !LIBPATH_CXX_VER_2017_plus */
#ifdef LIBPATH_CXX_VER_2014_plus
# undef LIBPATH_CXX_VER_2014_plus
#endif /* !LIBPATH_CXX_VER_2014_plus */
#ifdef LIBPATH_CXX_VER_2011_plus
# undef LIBPATH_CXX_VER_2011_plus
#endif /* !LIBPATH_CXX_VER_2011_plus */
#ifdef LIBPATH_CXX_VER_1998_plus
# undef LIBPATH_CXX_VER_1998_plus
#endif /* !LIBPATH_CXX_VER_1998_plus */


#ifdef __cplusplus

# if 0
# elif __cplusplus == 202302L

#  define LIBPATH_CXX_VER                                   2023
# elif __cplusplus == 202101L

#  define LIBPATH_CXX_VER                                   2021
# elif __cplusplus == 202002L

#  define LIBPATH_CXX_VER                                   2020
# elif __cplusplus == 201703L

#  define LIBPATH_CXX_VER                                   2017
# elif __cplusplus == 201402L

#  define LIBPATH_CXX_VER                                   2014
# elif __cplusplus == 201103L

#  define LIBPATH_CXX_VER                                   2011
# elif __cplusplus == 199711L

#  define LIBPATH_CXX_VER                                   1998
# else

#  define LIBPATH_CXX_VER                                   0
# endif

# if __cplusplus >= 199711L
#  define LIBPATH_CXX_VER_1998_plus
# endif
# if __cplusplus >= 201103L
#  define LIBPATH_CXX_VER_2011_plus
# endif
# if __cplusplus >= 201402L
#  define LIBPATH_CXX_VER_2014_plus
# endif
# if __cplusplus >= 201703L
#  define LIBPATH_CXX_VER_2017_plus
# endif
# if __cplusplus >= 202003L
#  define LIBPATH_CXX_VER_2020_plus
# endif
# if __cplusplus >= 202101L
#  define LIBPATH_CXX_VER_202101_plus
# endif
# if __cplusplus >= 202302L
#  define LIBPATH_CXX_VER_2023_plus
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * feature abstraction
 */

#ifndef LIBPATH_CXX_VER_2011_plus

# include <stddef.h>
#endif



/* LIBPATH_LF_noexcept */

#ifdef __cplusplus

# if 0
# elif LIBPATH_CXX_VER >= 2023

#  define LIBPATH_LF_noexcept                               noexcept(true)
# elif LIBPATH_CXX_VER >= 2011

#  define LIBPATH_LF_noexcept                               noexcept
# elif LIBPATH_CXX_VER >= 1998

#  define LIBPATH_LF_noexcept                               throw()
# endif
#endif



/* LIBPATH_LF_nullptr */

#if 0
#elif defined(LIBPATH_CXX_VER_2011_plus)

# define LIBPATH_LF_nullptr                                 nullptr
#else

# define LIBPATH_LF_nullptr                                 NULL
#endif



/* LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#ifdef __cplusplus

# if 0 ||\
     defined(LIBPATH_CXX_VER_2011_plus) ||\
     defined(STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT) ||\
     0

#  define LIBPATH_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
# endif
#endif


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

