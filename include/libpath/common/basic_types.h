/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/common/basic_types.h
 *
 * Purpose:     Basic types defined for libpath library.
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_basic_types
#define SYNSOFT_LIBPATH_INCL_libpath_common_H_basic_types

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/common/macros.h>
#include <libpath/common/namespace.h>

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** A type that is used to represent, in a language-independent manner,
 * truthiness
 *
 * To test for truey, rely on the C/C++ compiler's implicit conversions to
 * boolean, such as <code>if(t)</code>; to test for falsey, do the same with
 * the logical NOT operator, such as <code>if(!t)</code>.
 *
 */
typedef int                                                 libpath_truthy_t;

#ifndef LIBPATH_NO_NAMESPACE
namespace libpath {

/** @see libpath_truthy_t
 */
typedef libpath_truthy_t                                    truthy_t;

} /* namespace libpath */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#if !defined(LIBPATH_NO_NAMESPACE) || \
    defined(LIBPATH_DOCUMENTATION_SKIP_SECTION)

# define LIBPATH_V_TRUEY                                    LIBPATH_STATIC_CAST(LIBPATH_NS_QUALIFY(truthy_t), true)
# define LIBPATH_V_FALSEY                                   LIBPATH_STATIC_CAST(LIBPATH_NS_QUALIFY(truthy_t), false)
#else /* ? __cplusplus */

# define LIBPATH_V_TRUEY                                    LIBPATH_STATIC_CAST(libpath_truthy_t, 1)
# define LIBPATH_V_FALSEY                                   LIBPATH_STATIC_CAST(libpath_truthy_t, 0)
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_basic_types */

/* ///////////////////////////// end of file //////////////////////////// */
