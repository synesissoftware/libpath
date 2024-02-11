/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/portability.h
 *
 * Purpose: Portability discrimination for libpath library.
 *
 * Created: 8th February 2024
 * Updated: 8th February 2024
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_portability
#define SYNSOFT_LIBPATH_INCL_libpath_common_H_portability


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#define SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_portability
#include <libpath/common/portability/compiler_.h>
#include <libpath/common/portability/operating_system_.h>
#include <libpath/common/portability/language_.h>
#undef SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_portability


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** @def LIBPATH_ATTRIBUTE_NO_RETURN
 *
 * Resolves to the appropriate declaration, if any, to mark a function
 * declaration as (the equivalent of) `[[noreturn]]`
 */

#if 0
#elif defined(LIBPATH_CXX_VER_2011_plus)

# define LIBPATH_ATTRIBUTE_NO_RETURN                        [[noreturn]]
#elif 0 || \
      defined(__clang__) || \
      defined(__GNUC__) || \
      0

# define LIBPATH_ATTRIBUTE_NO_RETURN                        __attribute__((__noreturn__))
#elif defined(_MSC_FULL_VER) && \
      _MSC_FULL_VER >= 140050320

# define LIBPATH_ATTRIBUTE_NO_RETURN                        __declspec(noreturn)
#else

# define LIBPATH_ATTRIBUTE_NO_RETURN
#endif


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_portability */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

