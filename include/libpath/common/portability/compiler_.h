/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/portability/compiler_.h
 *
 * Purpose: Compiler discrimination for libpath library.
 *
 * Created: 7th February 2024
 * Updated: 11th February 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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
 * - LIBPATH_CF_pragma_once_SUPPORTED - defined if translator supports the
 *   `#pragma once` preprocessor directive;
 */

/** @def LIBPATH_CF_pragma_once_SUPPORTED
 *
 * Defined if the compiler supports `#pragma once` preprocessor directive
 */

#if 0
#elif defined(__BORLANDC__)

# if (__BORLANDC__ & 0xfff0) >= 0x0580
#  define LIBPATH_CF_pragma_once_SUPPORTED
# endif
#elif defined(__COMO__)

# define LIBPATH_CF_pragma_once_SUPPORTED
#elif defined(__DMC__)

# define LIBPATH_CF_pragma_once_SUPPORTED
#elif defined(__INTEL_COMPILER)

# if __INTEL_COMPILER >= 700

#  define LIBPATH_CF_pragma_once_SUPPORTED
# endif /* compiler */
#elif defined(__MWERKS__)

# define LIBPATH_CF_pragma_once_SUPPORTED
#elif defined(__SUNPRO_C) || \
      defined(__SUNPRO_CC)

#elif defined(__VECTORC)

#elif defined(__WATCOMC__)

# if __WATCOMC__ >= 1200

#  define LIBPATH_CF_pragma_once_SUPPORTED
# endif
#elif defined(__GNUC__)

# if __GNUC__ > 3 || \
     (   __GNUC__ == 3 && \
         __GNUC_MINOR__ >= 4)

#  define LIBPATH_CF_pragma_once_SUPPORTED
# endif
#elif defined(__clang__)

# define LIBPATH_CF_pragma_once_SUPPORTED
#elif defined(_MSC_VER)

# if _MSC_VER >= 900

#  define LIBPATH_CF_pragma_once_SUPPORTED
# endif /* compiler */
#endif


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

