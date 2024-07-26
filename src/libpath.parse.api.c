/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath.parse.api.c
 *
 * Purpose: Main implementation file for libpath Parsing API.
 *
 * Created: 9th November 2012
 * Updated: 27th July 2024
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



/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/parse/api.h>
#include <libpath/util/api.h>

#include "libpath.parse.internal.h"

#include "libpath.quality.contract.h"

#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef __cplusplus

static
LIBPATH_RC
libpath_Parse_ParsePathFromCStyleString_UNCHECKED_(
    libpath_char_t const*       path
,   libpath_sint32_t            flags
,   libpath_PathDescriptor_t*   result
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices
);

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringPtrAndLen_UNCHECKED_(
    libpath_char_t const*       path
,   libpath_size_t              pathLen
,   libpath_sint32_t            flags
,   libpath_PathDescriptor_t*   result
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices
);

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringSlice_impl_1_(
    libpath_StringSlice_t const*    path
,   libpath_sint32_t                flags
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices
,   libpath_PathDescriptor_t*       result
);

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringSlice_impl_2_(
    libpath_StringSlice_t const*    path
,   libpath_char_t const* const     begin
,   libpath_char_t const* const     end
,   libpath_sint32_t                flags
,   libpath_char_t const*           lastSlash
,   libpath_char_t const*           lastPeriod
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices
,   libpath_PathDescriptor_t*       result
);

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringSlice_impl_3_(
    libpath_StringSlice_t const*    path
,   libpath_char_t const* const     begin
,   libpath_char_t const* const     end
,   libpath_sint32_t                flags
,   libpath_char_t const*           startOfEntry
,   libpath_char_t const*           endOfEntryStem
,   libpath_char_t const*           startOfEntryExtension
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices
,   libpath_PathDescriptor_t*       result
);
#endif /* !__cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

LIBPATH_API
libpath_Parse_ParsePathFromStringSlice(
    libpath_StringSlice_t const*    path
,   libpath_sint32_t                flags
,   libpath_PathDescriptor_t*       result                  /* = NULL */
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices     /* = NULL */
)
{
    libpath_ParseResult_t stub;

    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != path, "path may not be NULL");
    LIBPATH_MESSAGE_ASSERT(0 == numDirectoryPartSlices || LIBPATH_LF_nullptr != directoryPartSlices, "invalid directory part slice parameters");

    if (LIBPATH_LF_nullptr == result)
    {
        result = &stub;
    }
    memset(result, 0, sizeof(*result));

    if (0 != numDirectoryPartSlices)
    {
        memset(directoryPartSlices, 0, sizeof(directoryPartSlices[0]) * numDirectoryPartSlices);
    }

    result->input = *path;

    if (0 == path->len)
    {
        return libpath_ResultCode_NoPathSpecified;
    }
#ifndef __cplusplus

    return libpath_Parse_ParsePathFromStringSlice_impl_1_(
                path
            ,   flags
            ,   numDirectoryPartSlices
            ,   directoryPartSlices
            ,   result
            );
}

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringSlice_impl_1_(
    libpath_StringSlice_t const*    path
,   libpath_sint32_t                flags
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices
,   libpath_PathDescriptor_t*       result
)
{
#endif /* !__cplusplus */
    /*
     * Now we do some actual parsing.
     *
     * For further functionality we find the following:
     *
     * - first slash
     * - last slash
     * - last period
    */

    libpath_char_t const*       lastSlash       =   LIBPATH_LF_nullptr;
#ifdef LIBPATH_OS_IS_WINDOWS
    libpath_char_t const*       lastBackSlash   =   LIBPATH_LF_nullptr;
#endif
    libpath_char_t const*       lastPeriod      =   LIBPATH_LF_nullptr;

    libpath_char_t const* const begin           =   path->ptr;
    libpath_char_t const* const end             =   path->ptr + path->len;

    LIBPATH_ASSERT(begin != end);

    { libpath_char_t const* s; for (s = begin; s != end; ++s)
    {
        switch (*s)
        {
        case    '/':

            lastSlash = s;
            break;
#ifdef LIBPATH_OS_IS_WINDOWS
        case    '\\':

            lastBackSlash = s;
            break;
#endif
        case    '.':

            {
                lastPeriod = s;
            }
            break;
        default:

            if (libpath_Internal_path_character_is_bad(*s, path, LIBPATH_STATIC_CAST(libpath_size_t, s - begin), flags))
            {
                result->firstBadCharOffset = LIBPATH_STATIC_CAST(libpath_size_t, s - begin);

                return LIBPATH_RC_OF(BadPathCharacter);
            }
            break;
        }
    }}

#ifdef LIBPATH_OS_IS_WINDOWS
    if (LIBPATH_LF_nullptr == lastSlash)
    {
        lastSlash = lastBackSlash;
    }
    else
    if (lastSlash < lastBackSlash)
    {
        lastSlash = lastBackSlash;
    }
#endif
#ifndef __cplusplus

    return libpath_Parse_ParsePathFromStringSlice_impl_2_(
                path
            ,   begin
            ,   end
            ,   flags
            ,   lastSlash
            ,   lastPeriod
            ,   numDirectoryPartSlices
            ,   directoryPartSlices
            ,   result
            );
}

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringSlice_impl_2_(
    libpath_StringSlice_t const*    path
,   libpath_char_t const* const     begin
,   libpath_char_t const* const     end
,   libpath_sint32_t                flags
,   libpath_char_t const*           lastSlash
,   libpath_char_t const*           lastPeriod
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices
,   libpath_PathDescriptor_t*       result
)
{
#endif /* !__cplusplus */
    libpath_char_t const*       startOfEntry;
    libpath_char_t const*       endOfEntryStem;
    libpath_char_t const*       startOfEntryExtension;


    // TODO: discriminate the actual flags
    if (libpath_ParseOption_AssumeDirectory == (libpath_ParseOption_AssumeDirectory & flags) &&
        !libpath_Internal_character_is_pathname_separator(end[-1]))
    {
        startOfEntry = end;
    }
    else
    if (LIBPATH_LF_nullptr == lastSlash)
    {
        startOfEntry = begin;
    }
    else
    {
        startOfEntry = lastSlash + 1;
    }

    if ('.' == end[-1])
    {
        endOfEntryStem = end;
        startOfEntryExtension = end;
    }
    else
    if (lastPeriod < startOfEntry)
    {
        endOfEntryStem = end;
        startOfEntryExtension = end;
    }
    else
    {
        endOfEntryStem = lastPeriod;
        startOfEntryExtension = lastPeriod;
    }
#ifndef __cplusplus

    return libpath_Parse_ParsePathFromStringSlice_impl_3_(
                path
            ,   begin
            ,   end
            ,   flags
            ,   startOfEntry
            ,   endOfEntryStem
            ,   startOfEntryExtension
            ,   numDirectoryPartSlices
            ,   directoryPartSlices
            ,   result
            );
}

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringSlice_impl_3_(
    libpath_StringSlice_t const*    path
,   libpath_char_t const* const     begin
,   libpath_char_t const* const     end
,   libpath_sint32_t                flags
,   libpath_char_t const*           startOfEntry
,   libpath_char_t const*           endOfEntryStem
,   libpath_char_t const*           startOfEntryExtension
,   libpath_size_t                  numDirectoryPartSlices
,   libpath_StringSlice_t*          directoryPartSlices
,   libpath_PathDescriptor_t*       result
)
{
#endif /* !__cplusplus */

    libpath_char_t const*   startOfDirectory;
    libpath_size_t          rootLen;
    libpath_truthy_t        pathIsAbsolute;
    libpath_truthy_t        invalidRoot;

    if (!libpath_Internal_path_is_absolute(path, &rootLen, &invalidRoot))
    {
        if (invalidRoot)
        {
            return LIBPATH_RC_OF(InvalidRoot);
        }

#ifdef LIBPATH_OS_IS_WINDOWS
        if (begin == startOfEntry &&
            2 == rootLen)
        {
            startOfEntry += 2;
        }
#endif
        pathIsAbsolute = LIBPATH_V_FALSEY;
    }
    else
    {
        pathIsAbsolute = LIBPATH_V_TRUEY;
    }

    startOfDirectory = begin + rootLen;


    // Now sort:
    //
    // 1. path
    // 2. location
    // 3. root
    // 4. directory
    // 4.1 directory parts
    // 5. entry

    // 1. path

    result->path = result->input;

    // 2. location

    result->locationPart.ptr = begin;
    result->locationPart.len = startOfEntry - begin;

    // 3. root

    result->rootPart.ptr = begin;
    if (pathIsAbsolute)
    {
        result->rootPart.len = startOfDirectory - begin;
    }
    else
    {
        result->rootPart.len = 0;
    }

#ifdef LIBPATH_OS_IS_WINDOWS
    if (rootLen > 1)
    {
        result->volumePart.ptr = begin;
        result->volumePart.len = startOfDirectory - begin;
    }
#endif

    // 4. directory

    result->directoryPart.ptr = startOfDirectory;
    result->directoryPart.len = startOfEntry - startOfDirectory;

    // 4.1 directory parts

    if (0 != result->directoryPart.len)
    {
        libpath_size_t          pre =   0;
        libpath_size_t          i   =   0;
        libpath_truthy_t        isDots;
        libpath_StringSlice_t   part;

        while (libpath_Internal_find_next_directory_part(&i, &result->directoryPart, flags, &part, &isDots))
        {
            if (result->numDirectoryParts < numDirectoryPartSlices)
            {
                directoryPartSlices[result->numDirectoryParts] = part;
            }

            ++result->numDirectoryParts;

            if (isDots)
            {
                ++result->numDotsDirectoryParts;
            }

            pre = i;
        }

        ((void)&pre);
    }

    // 5. entry

    result->entryPart.ptr = startOfEntry;
    result->entryPart.len = end - startOfEntry;

    result->entryStemPart.ptr = result->entryPart.ptr;
    result->entryStemPart.len = endOfEntryStem - result->entryPart.ptr;

    result->entryExtensionPart.ptr = startOfEntryExtension;
    result->entryExtensionPart.len = end - startOfEntryExtension;

    return libpath_ResultCode_Success;
}

LIBPATH_API
libpath_Parse_ParsePathFromStringPtrAndLen(
    libpath_char_t const*       path
,   libpath_size_t              pathLen
,   libpath_sint32_t            flags
,   libpath_PathDescriptor_t*   result /* = NULL */
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices /* = NULL */
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != path || 0 == pathLen, "path parameter may not be NULL if pathLen is not 0");
    LIBPATH_MESSAGE_ASSERT(0 == numDirectoryPartSlices || LIBPATH_LF_nullptr != directoryPartSlices, "invalid directory part slice parameters");
#ifndef __cplusplus

    return libpath_Parse_ParsePathFromStringPtrAndLen_UNCHECKED_(path, pathLen, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

static
LIBPATH_RC
libpath_Parse_ParsePathFromStringPtrAndLen_UNCHECKED_(
    libpath_char_t const*       path
,   libpath_size_t              pathLen
,   libpath_sint32_t            flags
,   libpath_PathDescriptor_t*   result
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices
)
{
    libpath_StringSlice_t const path_sl = libpath_Util_SliceFromStringPtrAndLen(path, pathLen);
#endif /* !__cplusplus */

    return libpath_Parse_ParsePathFromStringSlice(&path_sl, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

LIBPATH_API
libpath_Parse_ParsePathFromCStyleString(
    libpath_char_t const*       path
,   libpath_sint32_t            flags
,   libpath_PathDescriptor_t*   result /* = NULL */
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices /* = NULL */
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != path, "path parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(0 == numDirectoryPartSlices || LIBPATH_LF_nullptr != directoryPartSlices, "invalid directory part slice parameters");
#ifndef __cplusplus

    return libpath_Parse_ParsePathFromCStyleString_UNCHECKED_(path, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

static
LIBPATH_RC
libpath_Parse_ParsePathFromCStyleString_UNCHECKED_(
    libpath_char_t const*       path
,   libpath_sint32_t            flags
,   libpath_PathDescriptor_t*   result
,   libpath_size_t              numDirectoryPartSlices
,   libpath_StringSlice_t*      directoryPartSlices
)
{
#endif /* !__cplusplus */

    libpath_StringSlice_t const path_sl = libpath_Util_SliceFromCStyleString(path);

    return libpath_Parse_ParsePathFromStringSlice(&path_sl, flags, result, numDirectoryPartSlices, directoryPartSlices);
}

LIBPATH_CALL(int)
libpath_ParseResult_IsPathAbsolute(
    libpath_ParseResult_t const*    result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

#ifdef LIBPATH_OS_IS_WINDOWS

    return result->rootPart.len > 1;
#else

    return 0 != result->rootPart.len;
#endif
}

LIBPATH_CALL(int)
libpath_ParseResult_IsPathRooted(
    libpath_ParseResult_t const*    result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    return 0 != result->rootPart.len;
}


/* ///////////////////////////// end of file //////////////////////////// */

