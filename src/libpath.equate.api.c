/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath.equate.api.c
 *
 * Purpose: Main implementation file for libpath Equating API.
 *
 * Created: 9th November 2012
 * Updated: 19th October 2024
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

#include <libpath/equate/api.h>
#include <libpath/parse/api.h>
#include <libpath/util/api.h>

#include "libpath.equate.internal.h"

#include "libpath.quality.contract.h"

#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef __cplusplus

static
LIBPATH_RC
libpath_Internal_PathEquals_impl_2_(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   libpath_StringSlice_t const*    cwd
,   libpath_sint32_t                flags
,   libpath_StringSlice_t*        (*dpallocs)[3]
,   libpath_PathDescriptor_t*       lresult
,   libpath_PathDescriptor_t*       rresult
,   libpath_truthy_t*               result
);

static
LIBPATH_RC
libpath_Equate_EquatePathsAsStringPtrsAndLens_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_size_t                              lhsLen
,   libpath_char_t const*                       rhs
,   libpath_size_t                              rhsLen
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt /* = NULL */
,   void*                                       reserved
,   libpath_truthy_t*                           result
);

static
LIBPATH_RC
libpath_Equate_EquatePathsAsCStyleStrings_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_char_t const*                       rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt /* = NULL */
,   void*                                       reserved
,   libpath_truthy_t*                           result
);
#endif /* !__cplusplus */

static
LIBPATH_RC
libpath_Internal_PathEquals_impl_(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   libpath_StringSlice_t const*    cwd
,   void*                           mem
,   libpath_StringSlice_t*        (*dpallocs)[3]
,   libpath_truthy_t*               result
);

/**
 *
 * @note An invalid path will never be compared as equivalent: if
 *   either or both paths are invalid, the result will be false, even
 *   in the case where both parameters refer to the empty string
 *
 */
LIBPATH_RC
libpath_Internal_PathEquals_(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   libpath_StringSlice_t const*    cwd
,   void*                           mem
,   libpath_truthy_t*               result
)
{
    libpath_StringSlice_t*  dpAllocs[3] =   { LIBPATH_LF_nullptr, LIBPATH_LF_nullptr, LIBPATH_LF_nullptr };
    libpath_truthy_t const  r           =   libpath_Internal_PathEquals_impl_(lhs, rhs, cwd, mem, &dpAllocs, result);

    libpath_Util_FreeSliceArray(dpAllocs[0]);
    libpath_Util_FreeSliceArray(dpAllocs[1]);
    libpath_Util_FreeSliceArray(dpAllocs[2]);

    return r;
}

static
LIBPATH_RC
libpath_Internal_PathEquals_impl_(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   libpath_StringSlice_t const*    cwd
,   void*                           mem
,   libpath_StringSlice_t*        (*dpallocs)[3]
,   libpath_truthy_t*               result
)
{
    // The design of libpath_Internal_PathEquals_() is based on the following
    // observations/design parameters:
    //
    // 1. We do not care about ordering, so where it is faster to establish
    //    difference without definitively establishing ordering it is
    //    safe and reasonable to do so. For example, we do not need to
    //    determine whether a pair of directories will, post-
    //    canonicalisation and/or post-"absoluting", be equal if we already
    //    know that the entry or (for Windows) root is different;
    // 2. For simplicity and straightforwardness of implementation (as well
    //    as, assumedly, overall performance) we do not attempt to do any
    //    "pre-comparison", i.e. before parsing the path;
    // 3. We prefer to carry out O(1) comparison operations before other
    //    more-complex operations;
    // 4. Apropos the previous point, we avoid any potential memory
    //    allocation until all other possible avenues of unequivocal
    //    difference have been exhausted.
    //
    // Consider the following scenarios:
    //
    // A. "abc" vs "abcd"
    //
    //     i. parse both
    //    ii. compare the entry parts -> different, complete
    //
    // B. "/abc" vs "\\abc"
    //
    //     i. parse both
    //    ii. compare the enry parts -> same, continue
    //   iii. compare the roots -> same, continue
    //    iv. compare the directories -> same (empty), complete

    int const           flags   =   0;

    libpath_PathDescriptor_t  lresult;
    libpath_PathDescriptor_t  rresult;

    LIBPATH_ASSERT(LIBPATH_LF_nullptr != lhs);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != rhs);

    LIBPATH_SUPPRESS_UNUSED(mem);

    if (libpath_ResultCode_Success != libpath_Parse_ParsePathFromStringSlice(lhs, flags, &lresult, 0, LIBPATH_LF_nullptr) ||
        libpath_ResultCode_Success != libpath_Parse_ParsePathFromStringSlice(rhs, flags, &rresult, 0, LIBPATH_LF_nullptr))
    {
        *result = LIBPATH_V_FALSEY;

        return LIBPATH_RC_OF(Success);
    }
    else
    {
        // Algorithm:
        //
        // 1. If entries are different, then paths are different -> return false
        // 2. If roots (or volumeParts) are different, then paths are different -> return false
        // 3. If same "level" of root, then compare directories, or
        // 4. If different "level" of root and no cwd, then paths are different -> return false
        // 5. If different "level" of root and cwd, then get cwd and three-way compare of directories

        // entry first
        if (!libpath_Internal_directory_part_equal(&lresult.entryPart, &rresult.entryPart))
        {
            *result = LIBPATH_V_FALSEY;

            return LIBPATH_RC_OF(Success);
        }
        else
        {
            if (0 == lresult.locationPart.len &&
                0 == rresult.locationPart.len)
            {
                *result = LIBPATH_V_TRUEY;

                return LIBPATH_RC_OF(Success);
            }
        }

        return libpath_Internal_PathEquals_impl_2_(
                    lhs
                ,   rhs
                ,   cwd
                ,   flags
                ,   dpallocs
                ,   &lresult
                ,   &rresult
                ,   result
                );
    }
}

#ifndef __cplusplus

static
LIBPATH_RC
libpath_Internal_PathEquals_impl_2_(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   libpath_StringSlice_t const*    cwd
,   libpath_sint32_t                flags
,   libpath_StringSlice_t*        (*dpallocs)[3]
,   libpath_PathDescriptor_t*       lresult
,   libpath_PathDescriptor_t*       rresult
,   libpath_truthy_t*               result
)
{
#endif /* !__cplusplus */

    // get the root levels:
    //
    // 0 == no root
    // 1 == slash-root
    // 2 == Windows volume, no root
    // 3 == Windows volume
    // 4 == Windows UNC

    int const   lhsRootLevel    =   libpath_Internal_get_root_level(lresult);
    int const   rhsRootLevel    =   libpath_Internal_get_root_level(rresult);

#ifdef LIBPATH_OS_IS_WINDOWS
    if (0 != lhsRootLevel &&
        0 != rhsRootLevel)
    {
        // Compare volume parts if level is 2 or 3
        if ((0x00000002 ^ lhsRootLevel) < 2 &&
            (0x00000002 ^ rhsRootLevel) < 2)
        {
            if (libpath_Internal_volumes_definitely_different(&lresult->volumePart, &rresult->volumePart))
            {
                *result = LIBPATH_V_FALSEY;

                return LIBPATH_RC_OF(Success);
            }
        }

        if (libpath_Internal_roots_definitely_different(&lresult->rootPart, &rresult->rootPart))
        {
            *result = LIBPATH_V_FALSEY;

            return LIBPATH_RC_OF(Success);
        }
    }
#endif

    if (lhsRootLevel == rhsRootLevel)
    {
        // either both relative or both absolute, so we just have to compare
        //
        // - roots, if (both) absolute, or
        // - directories (canonicalised, if either contain dots)

#ifdef LIBPATH_OS_IS_WINDOWS
        if (lhsRootLevel > 3 &&
            !libpath_Internal_roots_equal(&lresult->rootPart, &rresult->rootPart))
        {
            *result = LIBPATH_V_FALSEY;

            return LIBPATH_RC_OF(Success);
        }
#endif

        if (0 == lresult->numDotsDirectoryParts &&
            0 == rresult->numDotsDirectoryParts)
        {
            // can just do informed-comparison of directory strings

            *result = libpath_Internal_directory_whole_equal(&lresult->directoryPart, &rresult->directoryPart);

            return LIBPATH_RC_OF(Success);
        }
        else
        {
            libpath_StringSlice_t** const   ldirparts  =   &(*dpallocs)[0];
            libpath_StringSlice_t** const   rdirparts  =   &(*dpallocs)[1];

            LIBPATH_RC rc = LIBPATH_RC_OF(Success);

            if (LIBPATH_RC_SUCCESS(rc))
            {
                rc = libpath_Util_AllocateSliceArray(lresult->numDirectoryParts, ldirparts);
            }

            if (LIBPATH_RC_SUCCESS(rc))
            {
                rc = libpath_Util_AllocateSliceArray(rresult->numDirectoryParts, rdirparts);
            }

            if (LIBPATH_RC_SUCCESS(rc))
            {
                rc = libpath_Parse_ParsePathFromStringSlice(lhs, flags, lresult, lresult->numDirectoryParts, *ldirparts);
            }

            if (LIBPATH_RC_SUCCESS(rc))
            {
                rc = libpath_Parse_ParsePathFromStringSlice(rhs, flags, rresult, rresult->numDirectoryParts, *rdirparts);
            }

            if (LIBPATH_RC_FAILURE(rc))
            {
                return rc;
            }
            else
            {
                libpath_size_t const    nldirparts  =   libpath_Internal_canonicalise_parts(lresult->numDirectoryParts, *ldirparts);
                libpath_size_t const    nrdirparts  =   libpath_Internal_canonicalise_parts(rresult->numDirectoryParts, *rdirparts);

                *result = libpath_Internal_directory_parts_equal(nldirparts, *ldirparts, nrdirparts, *rdirparts);

                return LIBPATH_RC_OF(Success);
            }
        }
    }
    else
    {
        if (LIBPATH_LF_nullptr == cwd ||
            '\0' == cwd->len)
        {
            *result = LIBPATH_V_FALSEY;

            return LIBPATH_RC_OF(Success);
        }
        else
        {
            // Now we need to make the relative path absolute by combining it with the cwd
            libpath_StringSlice_t const* const  abs         =   (0 != lhsRootLevel) ? lhs : rhs;
            libpath_StringSlice_t const* const  rel         =   (0 != lhsRootLevel) ? rhs : lhs;
            int const                           cwd_flags   =   0
                                                            |   libpath_ParseOption_AssumeDirectory
                                                            ;
            libpath_PathDescriptor_t*     abs_result  =   (0 != lhsRootLevel) ? lresult : rresult;
            libpath_PathDescriptor_t*     rel_result  =   (0 != lhsRootLevel) ? rresult : lresult;
            libpath_PathDescriptor_t      cwd_result;

            if (libpath_ResultCode_Success != libpath_Parse_ParsePathFromStringSlice(cwd, cwd_flags, &cwd_result, 0, LIBPATH_LF_nullptr))
            {
#if LIBPATH_VER >= 0x00030000
# error This needs to return a result code that indicates that it is the cwd
# error Also: need to ensure that cwd is absolute
#endif
                *result = LIBPATH_V_FALSEY;

                return LIBPATH_RC_OF(Success);
            }
            else
            {
                if (libpath_Internal_roots_definitely_different(&abs_result->rootPart, &cwd_result.rootPart))
                {
                    *result = LIBPATH_V_FALSEY;

                    return LIBPATH_RC_OF(Success);
                }
                else
                {
                    if (0 == abs_result->numDotsDirectoryParts &&
                        0 == rel_result->numDotsDirectoryParts &&
                        0 == cwd_result.numDotsDirectoryParts)
                    {
                        // can just do informed-comparison of directory strings
                        *result = libpath_Internal_directory_whole_equal_3(&abs_result->directoryPart, &rel_result->directoryPart, &cwd_result.directoryPart);

                        return LIBPATH_RC_OF(Success);
                    }
                    else
                    {
                        libpath_StringSlice_t** const   abs_dirparts  =   &(*dpallocs)[0];
                        libpath_StringSlice_t** const   rel_dirparts  =   &(*dpallocs)[1];
                        libpath_StringSlice_t** const   cwd_dirparts  =   &(*dpallocs)[2];

                        LIBPATH_RC rc = LIBPATH_RC_OF(Success);

                        if (LIBPATH_RC_SUCCESS(rc))
                        {
                            rc = libpath_Util_AllocateSliceArray(abs_result->numDirectoryParts, abs_dirparts);
                        }

                        if (LIBPATH_RC_SUCCESS(rc))
                        {
                            rc = libpath_Util_AllocateSliceArray(rel_result->numDirectoryParts, rel_dirparts);
                        }

                        if (LIBPATH_RC_SUCCESS(rc))
                        {
                            rc = libpath_Util_AllocateSliceArray(cwd_result.numDirectoryParts, cwd_dirparts);
                        }

                        if (LIBPATH_RC_SUCCESS(rc))
                        {
                            rc = libpath_Parse_ParsePathFromStringSlice( abs,     flags, abs_result, abs_result->numDirectoryParts, *abs_dirparts);
                        }

                        if (LIBPATH_RC_SUCCESS(rc))
                        {
                            rc = libpath_Parse_ParsePathFromStringSlice( rel,     flags, rel_result, rel_result->numDirectoryParts, *rel_dirparts);
                        }

                        if (LIBPATH_RC_SUCCESS(rc))
                        {
                            rc = libpath_Parse_ParsePathFromStringSlice( cwd, cwd_flags, &cwd_result, cwd_result.numDirectoryParts, *cwd_dirparts);
                        }

                        if (LIBPATH_RC_FAILURE(rc))
                        {
                            return rc;
                        }
                        else
                        {
                            libpath_size_t const    nabs_dirparts   =   libpath_Internal_canonicalise_parts(abs_result->numDirectoryParts, *abs_dirparts);
                            libpath_size_t const    nrel_dirparts   =   libpath_Internal_canonicalise_parts(rel_result->numDirectoryParts, *rel_dirparts);
                            libpath_size_t const    ncwd_dirparts   =   libpath_Internal_canonicalise_parts(cwd_result.numDirectoryParts, *cwd_dirparts);


                            // Now work backwards comparing abs and rel parts

                            libpath_size_t  nabs    =   nabs_dirparts;
                            libpath_size_t  nrel    =   nrel_dirparts;
                            libpath_size_t  ncwd    =   ncwd_dirparts;

                            // first canonicalise cwd and relative parts
                            //
                            // Algorithm: while the last cwd part is not double-dots
                            // and the first rel part is
                            //
                            for (; 0 != nrel && 0 != ncwd; )
                            {
                                libpath_StringSlice_t const* const  rel_first_part  =   &(*rel_dirparts)[0];
                                libpath_StringSlice_t const* const  cwd_last_part   =   &(*cwd_dirparts)[ncwd - 1];

                                if (2 == libpath_Internal_count_dots(rel_first_part) &&
                                    0 == libpath_Internal_count_dots(cwd_last_part))
                                {
                                    // need to move down the relative parts
                                    memmove(&(*rel_dirparts)[0], &(*rel_dirparts)[1], --nrel * sizeof(libpath_StringSlice_t));

                                    --ncwd;
                                }
                                else
                                {
                                    break;
                                }
                            }

                            // correlate absolute and relative parts

                            for (; 0 != nabs && 0 != nrel; --nabs, --nrel)
                            {
                                libpath_StringSlice_t const*    abs_part    =   &(*abs_dirparts)[nabs - 1];
                                libpath_StringSlice_t const*    rel_part    =   &(*rel_dirparts)[nrel - 1];

                                if (!libpath_Internal_directory_part_equal(abs_part, rel_part))
                                {
                                    *result = LIBPATH_V_FALSEY;

                                    return LIBPATH_RC_OF(Success);
                                }
                            }

                            // correlate absolute and cwd parts

                            for (; 0 != nabs && 0 != ncwd; --nabs, --ncwd)
                            {
                                libpath_StringSlice_t const*    abs_part    =   &(*abs_dirparts)[nabs - 1];
                                libpath_StringSlice_t const*    cwd_part    =   &(*cwd_dirparts)[ncwd - 1];

                                if (!libpath_Internal_directory_part_equal(abs_part, cwd_part))
                                {
                                    *result = LIBPATH_V_FALSEY;

                                    return LIBPATH_RC_OF(Success);
                                }
                            }

                            if (0 == nabs &&
                                0 == nrel &&
                                0 == ncwd)
                            {
                                *result = LIBPATH_V_TRUEY;

                                return LIBPATH_RC_OF(Success);
                            }

                            *result = LIBPATH_V_FALSEY;

                            return LIBPATH_RC_OF(Success);
                        }
                    }
                }
            }
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

LIBPATH_API
libpath_Equate_EquatePathsAsStringSlices(
    libpath_StringSlice_t const*                lhs
,   libpath_StringSlice_t const*                rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   void*                                       reserved
,   libpath_truthy_t*                           result
)
{
    libpath_StringSlice_t           cwd_;
    libpath_StringSlice_t const*    cwd = LIBPATH_LF_nullptr;

    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs, "lhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs, "rhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    LIBPATH_SUPPRESS_UNUSED(flags);

    if (LIBPATH_LF_nullptr != reserved)
    {
        return LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero);
    }

    if (LIBPATH_LF_nullptr != ctxt)
    {
        switch (ctxt->mechanism)
        {
        case    libpath_WorkingDirectoryContextMechanism_NoneSpecified:

            break;
        case    libpath_WorkingDirectoryContextMechanism_CStyleString:

            if (LIBPATH_LF_nullptr != ctxt->details.cwd_css)
            {
                cwd_ = libpath_Util_SliceFromCStyleString(ctxt->details.cwd_css);
                cwd = &cwd_;
            }
            break;
        case    libpath_WorkingDirectoryContextMechanism_StringSlice:

            cwd = &ctxt->details.cwd_slice;
            break;
        default:

            LIBPATH_MESSAGE_ASSERT(0, "invalid WorkingDirectoryContextMechanism");
#if defined(_WIN32) || defined(_WIN64)
        case    libpath_WorkingDirectoryContextMechanism_GetCurrentDirectory:
#endif
        case    libpath_WorkingDirectoryContextMechanism_getcwd:
            return LIBPATH_RC_OF(OptionNotSupported);
        }
    }

    return libpath_Internal_PathEquals_(lhs, rhs, cwd, LIBPATH_LF_nullptr, result);
}

LIBPATH_API
libpath_Equate_EquatePathsAsStringPtrsAndLens(
    libpath_char_t const*                       lhs
,   libpath_size_t                              lhsLen
,   libpath_char_t const*                       rhs
,   libpath_size_t                              rhsLen
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt /* = NULL */
,   void*                                       reserved
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs || 0 == lhsLen, "lhs parameter may not be NULL if lhsLen is not 0");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs || 0 == rhsLen, "rhs parameter may not be NULL if rhsLen is not 0");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");
#ifndef __cplusplus

    return libpath_Equate_EquatePathsAsStringPtrsAndLens_UNCHECKED_(lhs, lhsLen, rhs, rhsLen, flags, ctxt, reserved, result);
}

static
LIBPATH_RC
libpath_Equate_EquatePathsAsStringPtrsAndLens_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_size_t                              lhsLen
,   libpath_char_t const*                       rhs
,   libpath_size_t                              rhsLen
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt /* = NULL */
,   void*                                       reserved
,   libpath_truthy_t*                           result
)
{
#endif /* !__cplusplus */

    libpath_StringSlice_t const lhs_sl = libpath_Util_SliceFromStringPtrAndLen(lhs, lhsLen);
    libpath_StringSlice_t const rhs_sl = libpath_Util_SliceFromStringPtrAndLen(rhs, rhsLen);

    return libpath_Equate_EquatePathsAsStringSlices(&lhs_sl, &rhs_sl, flags, ctxt, reserved, result);
}

LIBPATH_API
libpath_Equate_EquatePathsAsCStyleStrings(
    libpath_char_t const*                       lhs
,   libpath_char_t const*                       rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt /* = NULL */
,   void*                                       reserved
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs, "lhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs, "rhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");
#ifndef __cplusplus

    return libpath_Equate_EquatePathsAsCStyleStrings_UNCHECKED_(lhs, rhs, flags, ctxt, reserved, result);
}

static
LIBPATH_RC
libpath_Equate_EquatePathsAsCStyleStrings_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_char_t const*                       rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   void*                                       reserved
,   libpath_truthy_t*                           result
)
{
#endif /* !__cplusplus */

    libpath_StringSlice_t const lhs_sl = libpath_Util_SliceFromCStyleString(lhs);
    libpath_StringSlice_t const rhs_sl = libpath_Util_SliceFromCStyleString(rhs);

    return libpath_Equate_EquatePathsAsStringSlices(&lhs_sl, &rhs_sl, flags, ctxt, reserved, result);
}


/* ///////////////////////////// end of file //////////////////////////// */

