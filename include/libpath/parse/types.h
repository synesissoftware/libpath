/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/parse/types.h
 *
 * Purpose: libpath Parsing API types.
 *
 * Created: 9th November 2012
 * Updated: 15th March 2025
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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
struct libpath_PathDescriptor_t
{
#if 0
    LIBPATH_RCX                     rcx;
#else
    libpath_uintptr_t               reserved0;
#endif /* 0 */
    /** @brief The input string, unchanged. */
    libpath_StringSlice_t           input;
    /** @brief The full path. */
    libpath_StringSlice_t           fullPath;
    /** @brief The location part of the path. */
    libpath_StringSlice_t           locationPart;
    /** @brief The root part of the path. */
    libpath_StringSlice_t           rootPart;
    /** @brief The directory part of the path. */
    libpath_StringSlice_t           directoryPart;
    /** @brief The number of directory parts. */
    libpath_size_t                  numDirectoryParts;
    /** @brief The number of directory parts that are dots (i.e. `"."` or `".."`). */
    libpath_size_t                  numDotsDirectoryParts;
    /** @brief The entry name part of the path.
     *
     * @note This corresponds to the concept of "base-name", with the caveat
     *  that it will never be obtained non-empty from an input path that
     *  bears a trailing path-name separator.
     */
    libpath_StringSlice_t           entryNamePart;
    /** @brief The entry stem part of the path. */
    libpath_StringSlice_t           entryStemPart;
    /** @brief The entry extension part of the path. */
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
};

#ifndef __cplusplus
typedef struct libpath_PathDescriptor_t                     libpath_PathDescriptor_t;
#endif /* __cplusplus */
typedef struct libpath_PathDescriptor_t                     libpath_ParseResult_t;


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_parse_H_types */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

