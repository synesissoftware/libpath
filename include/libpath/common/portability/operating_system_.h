/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/portability/operating_system_.h
 *
 * Purpose: Operating-system discrimination for libpath library.
 *
 * Created: 2nd February 2013
 * Updated: 27th July 2024
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
 * - LIBPATH_OS_IS_UNIX - if defined, then compiling for Unix;
 * - LIBPATH_OS_IS_WINDOWS - if defined, then compiling for Windows;
 *
 * User-defined features:
 * - LIBPATH_OS_REQUIRE_WINxx_FOR__WINxx - if compiling under Windows,
 *   require that the symbols WIN32 or WIN64 are present, and do not rely
 *   upon the symbols _WIN32 or _WIN64;
 * - LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX - causes Windows functionality to
 *   be simulated on Unix;
 * - LIBPATH_OS_SIMULATE_UNIX_ON_WINDOWS - causes Unix functionality to be
 *   simulated on Windows;
 */

#ifdef LIBPATH_OS_IS_UNIX
# undef LIBPATH_OS_IS_UNIX
#endif /* LIBPATH_OS_IS_UNIX */
#ifdef LIBPATH_OS_IS_WINDOWS
# undef LIBPATH_OS_IS_WINDOWS
#endif /* LIBPATH_OS_IS_WINDOWS */

/* detect Unix first */
#if 0 || \
    defined(UNIX) || \
    defined(__MACH__) || \
    defined(__unix) || \
    defined(__unix__) || \
    defined(unix) || \
    defined(unix__) || \
    0

# define LIBPATH_OS_IS_UNIX
#endif

/* if Unix not found, then detect Windows */
#ifndef LIBPATH_OS_IS_UNIX

# if 0
# elif defined(LIBPATH_OS_REQUIRE_WINxx_FOR__WINxx)

#  if defined(WIN32) || \
      defined(WIN64)

#   define LIBPATH_OS_IS_WINDOWS
#  endif /* WIN32 || WIN64 */
# elif !defined(LIBPATH_SUPPRESS_WINDOWS)

#  if defined(_WIN32) || \
      defined(_WIN64)

#   define LIBPATH_OS_IS_WINDOWS
#  endif /* _WIN32 || _WIN64 */
# endif
#endif /* !LIBPATH_OS_IS_UNIX */

#if 0
#elif defined(LIBPATH_OS_IS_UNIX)
#elif defined(LIBPATH_OS_IS_WINDOWS)
#else

# error Neither Unix nor Windows defined
#endif

#if 0
#elif defined(LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX) && defined(LIBPATH_OS_SIMULATE_UNIX_ON_WINDOWS)

# error can define at most one of LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX and LIBPATH_OS_SIMULATE_UNIX_ON_WINDOWS
#elif defined(LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX) && !defined(LIBPATH_OS_IS_UNIX)

# error cannot define LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX unless on Unix
#elif defined(LIBPATH_OS_SIMULATE_UNIX_ON_WINDOWS) && !defined(LIBPATH_OS_IS_WINDOWS)

# error cannot define LIBPATH_OS_SIMULATE_UNIX_ON_WINDOWS unless on Windows
#endif

#ifdef LIBPATH_OS_SIMULATE_UNIX_ON_WINDOWS

# define LIBPATH_OS_IS_UNIX
# undef LIBPATH_OS_IS_WINDOWS
#endif

#ifdef LIBPATH_OS_SIMULATE_WINDOWS_ON_UNIX

# define LIBPATH_OS_IS_WINDOWS
# undef LIBPATH_OS_IS_UNIX
#endif


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

