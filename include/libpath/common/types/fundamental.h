/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/types/fundamental.h
 *
 * Purpose: Definition of fundamental types for libpath library.
 *
 * Created: 9th November 2012
 * Updated: 8th February 2024
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_types
# error SYNSOFT_LIBPATH_INCL_libpath_common_H_types not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_types */


/* /////////////////////////////////////////////////////////////////////////
 * NOTES:
 *
 * For the moment, we assume stdint.h. That's ok, because *my* installations
 * of VC6-9 have one present (because I wrote one and placed it in the VC6-9
 * INCLUDE paths); other users of VC6-9 (if there are any left) will be out
 * of luck, but may utilise the same trick.
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifdef LIBPATH_CXX_VER_2011_plus
# include <cstdint>
#else
# include <stdint.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef char                                                libpath_char_t;

#ifdef LIBPATH_CXX_VER_2011_plus

typedef std::int32_t                                        libpath_sint32_t;

typedef std::uint32_t                                       libpath_uint32_t;
#else

typedef int32_t                                             libpath_sint32_t;

typedef uint32_t                                            libpath_uint32_t;
#endif


/* ///////////////////////////// end of file //////////////////////////// */

