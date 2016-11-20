/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/parse/types.h
 *
 * Purpose:     Main include for libpath library's Parsing API's types.
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_parse_H_types
#define SYNSOFT_LIBPATH_INCL_libpath_parse_H_types

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/common/types.h>

#include <libpath/parse/types/ParseOption.h>

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** parse-result information
 *
 */
struct libpath_ParseResult_t
{
#if 0
    LIBPATH_RCX                     rcx;
#else
    int                             reserved0;
#endif /* 0 */
    libpath_StringSlice_t           input;
    libpath_StringSlice_t           path;
    libpath_StringSlice_t           locationPart;
    libpath_StringSlice_t           rootPart;
    libpath_StringSlice_t           directoryPart;
    size_t                          numDirectoryParts;
    size_t                          numDotsDirectoryParts;
    libpath_StringSlice_t           entryPart;
    libpath_StringSlice_t           entryBaseNamePart;
    libpath_StringSlice_t           entryExtensionPart;

    /*
     *
     * locationPart = [rootPart + directoryPart]
     *
     * numDirectoryParts does not include the root (if present)
     *
     * rootPart will only be filled out if a complete root is
     * establised; c/w volumePart
     *
     * numDotsDirectoryParts is the number of dots directory parts, such
     * as ".", "..", "./", ".\\" (Windows-only), "../", and
     * "..\\" (Windows-only). It does not take into account whether those
     * dots parts may be canonicalisable (i.e. leading double-dots parts
     * are included in the total).
     */

#ifdef LIBPATH_OS_IS_WINDOWS
    libpath_StringSlice_t           volumePart;
#endif /* LIBPATH_OS_IS_WINDOWS */

    size_t                          firstBadCharOffset;
};

#ifndef __cplusplus
typedef struct libpath_ParseResult_t    libpath_ParseResult_t;
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_parse_H_types */

/* ///////////////////////////// end of file //////////////////////////// */
