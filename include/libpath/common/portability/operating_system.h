/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/common/portability/operating_system.h
 *
 * Purpose:     Operating-system discrimination for libpath library.
 *
 * Created:     2nd February 2013
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_types
# error SYNSOFT_LIBPATH_INCL_libpath_common_H_types not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_types */

/* /////////////////////////////////////////////////////////////////////////
 * feature discrimination
 */

#ifdef LIBPATH_OS_IS_WINDOWS
# undef LIBPATH_OS_IS_WINDOWS
#endif /* LIBPATH_OS_IS_WINDOWS */
#ifdef LIBPATH_OS_IS_UNIX
# undef LIBPATH_OS_IS_UNIX
#endif /* LIBPATH_OS_IS_UNIX */

/* detect UNIX first */
#if 0 || \
    defined(UNIX) || \
    defined(unix) || \
    defined(unix__) || \
    defined(__unix) || \
    defined(__unix__) || \
    0
# define LIBPATH_OS_IS_UNIX
#endif

/* if UNIX not found, then detect Windows */
#ifndef LIBPATH_OS_IS_UNIX
# if defined(LIBPATH_REQUIRE_WINxx_FOR_WINxx)
#  if defined(WIN32) || \
      defined(WIN64)
#   define LIBPATH_OS_IS_WINDOWS
#  endif /* WIN32 || WIN64 */
# elif !defined(LIBPATH_SUPPRESS_WINDOWS)
#  if defined(_WIN32)
#   define LIBPATH_OS_IS_WINDOWS
#  endif /* _WIN32 */
# endif
#endif /* !LIBPATH_OS_IS_UNIX */

/* ///////////////////////////// end of file //////////////////////////// */
