/* /////////////////////////////////////////////////////////////////////////
* File:        libpath/common/result_codes.h
*
* Purpose:     Definition of result code types.
*
* Created:     13th February 2013
* Updated:     20th November 2016
*
* Home:        http://synesis.com.au/software/
*
* Copyright (c) 2013, Matthew Wilson and Synesis Software
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
 * macros
 */

/** \def LIBPATH_RESULTCODE(detail)
 *
 * Generates the full name of a libpath ResultCode
 *
 * \param detail The detail part of the result code
 *
 * \see libpath_rc_t
 */
#define LIBPATH_RESULTCODE(detail)  libpath_ResultCode_##detail

/** \def LIBPATH_SUCCESS(rc)
 *
 * Evaluates to truey if \c rc represents a success code
 *
 * \param rc The return code to evaluated
 */
#define LIBPATH_SUCCESS(rc)         (LIBPATH_RESULTCODE(Success) == (rc))

/** \def LIBPATH_FAILURE(rc)
 *
 * Evaluates to falsey if \c rc represents a failure code
 *
 * \param rc The return code to evaluated
 */
#define LIBPATH_FAILURE(rc)         (LIBPATH_RESULTCODE(Success) != (rc))

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
typedef enum libpath_rc_t           LIBPATH_RC;

/** Extended result code enumeration
 */
enum libpath_rcx_t
{
#include <libpath/common/result_codes/enumerations/rcx.h>
#ifndef LIBPATH_DOCUMENTATION_SKIP_SECTION
    libpath_ResultCodeX_MaxValue
#endif /* !LIBPATH_DOCUMENTATION_SKIP_SECTION */
};
typedef enum libpath_rcx_t          LIBPATH_RCX;

/* ///////////////////////////// end of file //////////////////////////// */
