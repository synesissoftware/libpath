/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/common/types.h
 *
 * Purpose:     Main include for common types defined for libpath library.
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_types
#define SYNSOFT_LIBPATH_INCL_libpath_common_H_types

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <libpath/common/internal/defs.h>
#include <libpath/common/basic_types.h>
#include <libpath/common/macros.h>
#include <libpath/common/namespace.h>
#include <libpath/common/portability/operating_system.h>
#include <libpath/common/types/fundamental.h>
#include <libpath/common/types/slices.h>
#include <libpath/common/result_codes/result_codes.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def LIBPATH_API
 *
 * An object-like macro that equates
 * to <code>LIBPATH_CALL(LIBPATH_RC)</code>
 *
 * \see LIBPATH_CALL()
 * \see LIBPATH_RC
 */
#define LIBPATH_API                                         LIBPATH_CALL(LIBPATH_RC)

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef __cplusplus

# include <libpath/common/shims/access/string/StringSlice.hpp>
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_types */

/* ///////////////////////////// end of file //////////////////////////// */
