/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/common/macros.h
 *
 * Purpose:     Macros defined for libpath library.
 *
 * Created:     9th November 2012
 * Updated:     20th November 2016
 *
 * Home:        http://synesis.com.au/software/
 *
 * Copyright (c) 2012-2016, Matthew Wilson and Synesis Software
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_macros
#define SYNSOFT_LIBPATH_INCL_libpath_common_H_macros

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */


/** \def LIBPATH_CALL(r)
 *
 * Defines a standard function call return type (\c r)
 *
 * \param r The return type of the function
 */
#ifndef LIBPATH_CALL

# ifdef __cplusplus

#  define LIBPATH_CALL(r)                                   extern "C" r
# else /* ? __cplusplus */

#  define LIBPATH_CALL(r)                                   r
# endif /* __cplusplus */
#endif


/** \def LIBPATH_STATIC_CAST(type, expr)
 *
 * A static type cast
 *
 * \param type The type to which \c expr will be cast
 * \param expr The expression to be cast
 */
#ifdef __cplusplus

# define    LIBPATH_STATIC_CAST(type, expr)                 static_cast<(type), (expr)>
#else /* ? __cplusplus */

# define    LIBPATH_STATIC_CAST(type, expr)                 ((type)(expr))
#endif /* __cplusplus */


/** \def LIBPATH_SUPPRESS_UNUSED(v)
 *
 * Suppresses a warning about non-use of variable/parameter
 * by <em>using</em> the value \c v
 *
 * \param v The value - parameter / variable to use <em>used</em>
 */
#ifndef LIBPATH_SUPPRESS_UNUSED

# ifdef STLSOFT_SUPPRESS_UNUSED

#  define LIBPATH_SUPPRESS_UNUSED(v)                        STLSOFT_SUPPRESS_UNUSED(v)
# else /* ? __cplusplus */

#  define LIBPATH_SUPPRESS_UNUSED(v)                        LIBPATH_STATIC_CAST(void, v)
# endif /* __cplusplus */
#endif


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_macros */

/* ///////////////////////////// end of file //////////////////////////// */
