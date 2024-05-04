/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath.util.api.c
 *
 * Purpose: Main implementation file for libpath Utility API.
 *
 * Created: 9th November 2012
 * Updated: 4th May 2024
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

#include <libpath/util/api.h>
#include <libpath/parse/api.h>

#include "libpath.quality.contract.h"
#include "libpath.string.tchar.h"

#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

LIBPATH_API
libpath_Util_AllocateSliceArray(
    libpath_size_t          numSlices
,   libpath_StringSlice_t** slices
)
{
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != slices);

    *slices = (libpath_StringSlice_t*)malloc(numSlices * sizeof(libpath_StringSlice_t));

    if (LIBPATH_LF_nullptr == *slices)
    {
        return LIBPATH_RC_OF(OutOfMemory);
    }
    else
    {
        return LIBPATH_RC_OF(Success);
    }
}

LIBPATH_CALL(void)
libpath_Util_FreeSliceArray(
    libpath_StringSlice_t*  slices
)
{
    free(slices);
}



libpath_StringSlice_t
libpath_Util_SliceFromCStyleString(
    libpath_char_t const* s
)
{
    libpath_StringSlice_t slice;

    LIBPATH_ASSERT(LIBPATH_LF_nullptr != s);

    slice.len   =   libpath_Internal_standard_string_strlen(s);
    slice.ptr   =   s;

    return slice;
}

libpath_StringSlice_t
libpath_Util_SliceFromStringPtrAndLen(
    libpath_char_t const*   ptr
,   libpath_size_t          len
)
{
    libpath_StringSlice_t slice;

    slice.len   =   len;
    slice.ptr   =   ptr;

    return slice;
}


/* ///////////////////////////// end of file //////////////////////////// */

