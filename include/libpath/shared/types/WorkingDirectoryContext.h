/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/shared/types/WorkingDirectoryContext.h
 *
 * Purpose:     Definition of shared types for libpath library.
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
# error SYNSOFT_LIBPATH_INCL_libpath_common_H_types not defined. This file cannot be included directly
#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_types */

#ifndef SYNSOFT_LIBPATH_INCL_libpath_shared_types_H_WorkingDirectoryContext
#define SYNSOFT_LIBPATH_INCL_libpath_shared_types_H_WorkingDirectoryContext

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <stddef.h>

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

enum libpath_WorkingDirectoryContextMechanism_t
{
        libpath_WorkingDirectoryContextMechanism_NoneSpecified          =   0
    ,   libpath_WorkingDirectoryContextMechanism_CStyleString           =   1
#ifdef LIBPATH_OS_IS_WINDOWS
    ,   libpath_WorkingDirectoryContextMechanism_GetCurrentDirectory    =   2
#endif
    ,   libpath_WorkingDirectoryContextMechanism_getcwd                 =   3
    ,   libpath_WorkingDirectoryContextMechanism_StringSlice            =   4
};
#ifndef __cplusplus
typedef enum libpath_WorkingDirectoryContextMechanism_t     libpath_WorkingDirectoryContextMechanism_t;
#endif /* __cplusplus */

struct libpath_WorkingDirectoryContext_t
{
    libpath_WorkingDirectoryContextMechanism_t    mechanism;
    union
    {
        libpath_char_t const*           cwd_css;
        libpath_char_t*               (*getcwd)(libpath_char_t*, size_t);
#ifdef LIBPATH_OS_IS_WINDOWS
        unsigned long       (__stdcall *GetCurrentDirectory)(unsigned long, libpath_char_t*);
#endif
        libpath_StringSlice_t           cwd_slice;

    }                                   details;
};
#ifndef __cplusplus
typedef struct libpath_WorkingDirectoryContext_t            libpath_WorkingDirectoryContext_t;
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_LIBPATH_INCL_libpath_shared_types_H_WorkingDirectoryContext */

/* ///////////////////////////// end of file //////////////////////////// */
