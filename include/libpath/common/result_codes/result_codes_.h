/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/result_codes_.h
 *
 * Purpose: Definition of result code types.
 *
 * Created: 13th February 2013
 * Updated: 11th February 2024
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


#ifndef SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_types
# error SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_types not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_IMPLEMENTING_libpath_common_H_types */


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** @def LIBPATH_RC_OF(detail)
 *
 * Generates the full name of a libpath ResultCode (@c rc)
 *
 * @param detail The detail part of the result code
 *
 * @see libpath_rc_t
 */
#define LIBPATH_RC_OF(detail)                               libpath_ResultCode_##detail

/** @def LIBPATH_RC_SUCCESS(rc)
 *
 * Evaluates to truey if @c rc represents a success code
 *
 * @param rc The return code to evaluated
 */
#define LIBPATH_RC_SUCCESS(rc)                              (LIBPATH_RC_OF(Success) == (rc))

/** @def LIBPATH_RC_FAILURE(rc)
 *
 * Evaluates to falsey if @c rc represents a failure code
 *
 * @param rc The return code to evaluated
 */
#define LIBPATH_RC_FAILURE(rc)                              (LIBPATH_RC_OF(Success) != (rc))


/** @def LIBPATH_RCX_OF(detail)
 *
 * Generates the full name of a libpath ResultCode (@c rc)
 *
 * @param detail The detail part of the result code
 *
 * @see libpath_rc_t
 */
#define LIBPATH_RCX_OF(detail)                              libpath_ResultCodeX_##detail

/** @def LIBPATH_RC_SUCCESS(rc)
 *
 * Evaluates to truey if @c rc represents a success code
 *
 * @param rc The return code to evaluated
 */
#define LIBPATH_RCX_SUCCESS(rc)                             (LIBPATH_RCX_OF(Success) == (rc))

/** @def LIBPATH_RC_FAILURE(rc)
 *
 * Evaluates to falsey if @c rc represents a failure code
 *
 * @param rc The return code to evaluated
 */
#define LIBPATH_RCX_FAILURE(rc)                             (LIBPATH_RCX_OF(Success) != (rc))


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** Result code enumeration
 */
enum libpath_rc_t
{
#include <libpath/common/result_codes/enumerations/rc.h>
#ifndef LIBPATH_DOCUMENTATION_SKIP_SECTION
    libpath_ResultCode_MaxValue
#endif /* !LIBPATH_DOCUMENTATION_SKIP_SECTION */
};
typedef enum libpath_rc_t                                   LIBPATH_RC;

/** Extended result code enumeration
 */
enum libpath_rcx_t
{
#include <libpath/common/result_codes/enumerations/rcx.h>
#ifndef LIBPATH_DOCUMENTATION_SKIP_SECTION
    libpath_ResultCodeX_MaxValue
#endif /* !LIBPATH_DOCUMENTATION_SKIP_SECTION */
};
typedef enum libpath_rcx_t                                  LIBPATH_RCX;


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

