/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath.equate.api.cpp
 *
 * Purpose: Main implementation file for libpath Comparing API.
 *
 * Created: 9th November 2012
 * Updated: 24th July 2024
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

#include <libpath/compare/api.h>
#include <libpath/parse/api.h>
#include <libpath/util/api.h>

#include "libpath.compare.internal.h"
#include "libpath.equate.internal.h"
#include "libpath.parse.internal.h"
#include "libpath.quality.contract.h"

#include <ctype.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define LIBPATH_RLEVEL_RELATIVE                             (0x0000)
#define LIBPATH_RLEVEL_ROOT_SLASH                           (0x0001)
#ifdef LIBPATH_OS_IS_WINDOWS
# define LIBPATH_RLEVEL_VOLUME_LETTER                       (0x0002)
# define LIBPATH_RLEVEL_UNC_ROOT                            (0x0004)
#endif /* LIBPATH_OS_IS_WINDOWS */
#define LIBPATH_RLEVEL_ABSOLUTE                             (0x0010)

#define LIBPATH_OLD_RELATIVITY_MASK_                        (LIBPATH_RLEVEL_RELATIVE | LIBPATH_RLEVEL_ROOT_SLASH | LIBPATH_RLEVEL_ABSOLUTE)
#define OLD_REL(x)                                          ((x) & LIBPATH_OLD_RELATIVITY_MASK_)

#define LIBPATH_COMBINE_RLEVELS_(rl1, rl2)                  ((((rl1) & 0xffff & LIBPATH_OLD_RELATIVITY_MASK_) << 16) | (((rl2) & 0xffff & LIBPATH_OLD_RELATIVITY_MASK_) << 0))

#define LIBPATH_IS_RELATIVE_(rl)                            (0                            == (LIBPATH_OLD_RELATIVITY_MASK_ & (rl)))
#define LIBPATH_IS_ROOTED_(rl)                              (LIBPATH_RLEVEL_ROOT_SLASH    == (LIBPATH_RLEVEL_ROOT_SLASH    & (rl)))
#ifdef LIBPATH_OS_IS_WINDOWS
# define LIBPATH_HAS_VOLUME_(rl)                            (LIBPATH_RLEVEL_VOLUME_LETTER == (LIBPATH_RLEVEL_VOLUME_LETTER & (rl)))
# define LIBPATH_IS_UNC_(rl)                                (LIBPATH_RLEVEL_UNC_ROOT      == (LIBPATH_RLEVEL_UNC_ROOT      & (rl)))
#endif /* LIBPATH_OS_IS_WINDOWS */
#define LIBPATH_IS_ABSOLUTE_(rl)                            (LIBPATH_RLEVEL_ABSOLUTE      == (LIBPATH_RLEVEL_ABSOLUTE      & (rl)))


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef enum libpath_relativity_level_t_
{
    relative    =   LIBPATH_RLEVEL_RELATIVE,
    rooted      =   LIBPATH_RLEVEL_ROOT_SLASH,
#ifdef LIBPATH_OS_IS_WINDOWS
    volume      =   LIBPATH_RLEVEL_VOLUME_LETTER,
    unc         =   LIBPATH_RLEVEL_UNC_ROOT,
#endif
    absolute    =   LIBPATH_RLEVEL_ABSOLUTE,

} libpath_relativity_level_t_;


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef __cplusplus

static
LIBPATH_RC
libpath_Compare_ComparePathsAsStringSlices_UNCHECKED_(
    libpath_StringSlice_t const*                lhs
,   libpath_StringSlice_t const*                rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   libpath_truthy_t*                           result
);

static
LIBPATH_RC
libpath_Compare_ComparePathsAsStringPtrsAndLens_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_size_t                              lhsLen
,   libpath_char_t const*                       rhs
,   libpath_size_t                              rhsLen
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   libpath_truthy_t*                           result
);

static
LIBPATH_RC
libpath_Compare_ComparePathsAsCStyleStrings_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_char_t const*                       rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   libpath_truthy_t*                           result
);
#endif /* !__cplusplus */


#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
libpath_size_t
libpath_Internal_canonicalise_parts(
    libpath_size_t          cdirparts
,   libpath_StringSlice_t*  dirparts
);

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
static
int
libpath_Internal_compare_directory_part(
    libpath_StringSlice_t const*    dirpart1
,   libpath_StringSlice_t const*    dirpart2
,   int                             flags
)
{
    libpath_StringSlice_t const* const  lhs =   dirpart1;
    libpath_StringSlice_t const* const  rhs =   dirpart2;

    int             r       =   0;
    libpath_size_t  lhsLen  =   lhs->len;
    libpath_size_t  rhsLen  =   rhs->len;
    libpath_size_t  i;

    LIBPATH_SUPPRESS_UNUSED(flags);

    if (0 != lhsLen &&
        libpath_Internal_character_is_pathname_separator(lhs->ptr[lhsLen - 1]))
    {
        --lhsLen;
    }
    if (0 != rhsLen &&
        libpath_Internal_character_is_pathname_separator(rhs->ptr[rhsLen - 1]))
    {
        --rhsLen;
    }

    for (i = 0; 0 == r && i != lhsLen && i != rhsLen; ++i)
    {
#ifdef LIBPATH_OS_IS_WINDOWS
        char const  cl  =   (char)toupper(lhs->ptr[i]);
        char const  cr  =   (char)toupper(rhs->ptr[i]);
#else
        char const  cl  =   lhs->ptr[i];
        char const  cr  =   rhs->ptr[i];
#endif
        int const   cd  =   (int)(unsigned char)cl - (int)(unsigned char)cr;    /* C99: 7.21.4(1) */

        if (0 != cd)
        {
            if (!libpath_Internal_character_is_pathname_separator(cl) ||
                !libpath_Internal_character_is_pathname_separator(cr))
            {
                return cd;
            }
        }
    }

    LIBPATH_ASSERT((lhsLen == i) || (rhsLen == i));

    if (lhsLen != i)
    {
        return +1;
    }
    if (rhsLen != i)
    {
        return -1;
    }

    return 0;
}

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
static
int
libpath_Internal_compare_directory_parts(
    libpath_size_t                  ndirparts1
,   libpath_StringSlice_t const*    dirparts1
,   libpath_size_t                  ndirparts2
,   libpath_StringSlice_t const*    dirparts2
,   int                             flags
)
{
    int             r   =   0;
    libpath_size_t  i;

    for (i = 0; 0 == r && ndirparts1 != i && ndirparts2 != i; ++i)
    {
        r = libpath_Internal_compare_directory_part(&dirparts1[i], &dirparts2[i], flags);
    }

    if (0 == r)
    {
        if (ndirparts2 != i)
        {
            LIBPATH_ASSERT(ndirparts1 == i);

            r = -1;
        }
        else
        if (ndirparts1 != i)
        {
            LIBPATH_ASSERT(ndirparts2 == i);

            r = +1;
        }
    }

    return r;
}

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
static
int
libpath_Internal_compare_directory_parts_with_wd(
    libpath_size_t                  ndirparts_abs
,   libpath_StringSlice_t const*    dirparts_abs
,   libpath_size_t                  ndirparts_rel
,   libpath_StringSlice_t const*    dirparts_rel
,   libpath_size_t                  ndirparts_cwd
,   libpath_StringSlice_t const*    dirparts_cwd
,   int                             flags
)
{
    int             r   =   0;
    libpath_size_t  i;
    libpath_size_t  j;

    for (i = 0; ndirparts_abs != i && ndirparts_cwd != i; ++i)
    {
        r = libpath_Internal_compare_directory_part(&dirparts_abs[i], &dirparts_cwd[i], flags);

        if (0 != r)
        {
            return r;
        }
    }

    LIBPATH_ASSERT(0 == r);

    /* At this point, one of 3 things is true:
     *
     * 1. abs and cwd parts all exhausted
     * 2. abs parts exhausted; cwd parts remain
     * 3. cwd parts exhausted; abs parts remain
     *
     * Actions are:
     *
     * 1. return (rel parts remain) ? -1 : 0
     * 2. return -1
     * 3. continue
     */

    LIBPATH_ASSERT((ndirparts_abs == i) || (ndirparts_cwd == i));

    if (ndirparts_abs == i)
    {
        if (ndirparts_cwd == i)
        {
            /* 1. */

            return (0 != ndirparts_rel) ? -1 : 0;
        }
        else
        {
            /* 2. */

            return -1;
        }
    }

    /* 3. */

    for (j = 0; ndirparts_abs != i && ndirparts_rel != j; ++i, ++j)
    {
        r = libpath_Internal_compare_directory_part(&dirparts_abs[i], &dirparts_rel[j], flags);

        if (0 != r)
        {
            return r;
        }
    }

    LIBPATH_ASSERT(0 == r);

    /* At this point, one of three things is true:
     *
     * 1. abs and rel parts all exhausted
     * 2. abs parts exhausted; rel parts remain
     * 3. rel parts exhausted; abs parts remain
     *
     * Actions are:
     *
     * 1. return 0
     * 2. return -1
     * 3. return +1
     */

    LIBPATH_ASSERT((ndirparts_abs == i) || (ndirparts_rel == j));

    if (ndirparts_rel != j)
    {
        /* 2. */

        return -1;
    }
    else
    {
        LIBPATH_ASSERT(ndirparts_rel == j);

        if (ndirparts_abs != i)
        {
            /* 3. */

            return +1;
        }
        else
        {
            /* 1. */

            return 0;
        }
    }
}

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
static
void
canonicalise_between_relative_and_cwd(
    libpath_size_t*                     nrdirparts
,   libpath_StringSlice_t*              rdirparts
,   libpath_size_t*                     ncdirparts
,   libpath_StringSlice_t const*        cdirparts
)
{
    for (; 0 != *nrdirparts && 0 != *ncdirparts; )
    {
        libpath_StringSlice_t const*    rel_first_part  =   &rdirparts[0];
        libpath_StringSlice_t const*    cwd_last_part   =   &cdirparts[*ncdirparts - 1];

        if (2 == libpath_Internal_count_dots(rel_first_part) &&
            0 == libpath_Internal_count_dots(cwd_last_part))
        {
            // need to move down the relative parts
            memmove(&rdirparts[0], &rdirparts[1], --*nrdirparts * sizeof(libpath_StringSlice_t));

            --*ncdirparts;
        }
        else
        {
            break;
        }
    }
}

static
int
libpath_ParseResult_get_relativity_level_(
    libpath_ParseResult_t const* pr
)
{
    int level = LIBPATH_RLEVEL_RELATIVE;

    if (libpath_ParseResult_IsPathRooted(pr))
    {
        level |= LIBPATH_RLEVEL_ROOT_SLASH;
    }
    if (libpath_ParseResult_IsPathAbsolute(pr))
    {
        level |= LIBPATH_RLEVEL_ABSOLUTE;
    }

#ifdef LIBPATH_OS_IS_WINDOWS
    switch (pr->volumePart.len)
    {
    case 2:
    case 3:
        level |= LIBPATH_RLEVEL_VOLUME_LETTER;
        break;

    default:
        break;
    }
    if (pr->rootPart.len >= 5)
    {
        level |= LIBPATH_RLEVEL_UNC_ROOT;
    }
#endif

    return level;
}


#ifdef LIBPATH_OS_IS_WINDOWS
# ifdef __cplusplus
extern "C"
# endif /* __cplusplus */
static
int
compare_volume_letters(
    libpath_StringSlice_t const* lhs
,   libpath_StringSlice_t const* rhs
)
{
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != lhs);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != rhs);

    LIBPATH_ASSERT(0 != lhs->len);
    LIBPATH_ASSERT(0 != rhs->len);

    return (int)(unsigned char)toupper(0[lhs->ptr]) - (int)(unsigned char)toupper(0[rhs->ptr]);    /* C99: 7.21.4(1) */
}
#endif


static
LIBPATH_RC
libpath_Compare_ComparePathsAsStringSlices_impl2_(
    libpath_ParseResult_t const*                lhs
,   libpath_ParseResult_t const*                rhs
,   libpath_ParseResult_t const*                cwd
,   libpath_sint32_t                            flags
,   libpath_sint32_t                            lParseFlags
,   libpath_sint32_t                            rParseFlags
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs, "lhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs, "rhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    {
    int const   lhsRelativity   =   libpath_ParseResult_get_relativity_level_(lhs);
    int const   rhsRelativity   =   libpath_ParseResult_get_relativity_level_(rhs);

    /* This section is conceptually simple:
     *
     * IF one side is absolute and the other is not,
     * AND there is no cwd,
     * THEN return the relative before the absolute
     *
     * This is as it is on Unix. However, on Windows it is possible to have
     * rooted-but-non-absolute paths. Here is the truth table:
     *
     *      lhs         rhs             action
     *      ---         ---             ------
     *
     *      relative    relative        <ignore here>
     *      rooted      rooted          <ignore here>
     *      absolute    absolute        <ignore here>
     *
     *      rooted      absolute        return -1
     *      relative    rooted          return -1
     *      relative    absolute        return -1
     *
     *      absolute    relative        return +1
     *      absolute    rooted          return +1
     *      rooted      relative        return +1
     */

#ifdef LIBPATH_OS_IS_WINDOWS
    /* On Windows, if both lhs and rhs have a volume part, regardless of
     * whether either is absolute/(partially-)relative, we can compare
     * the volume letters and return an order if they're different
     */
    if (LIBPATH_HAS_VOLUME_(lhsRelativity) &&
        LIBPATH_HAS_VOLUME_(rhsRelativity))
    {
        int const r = compare_volume_letters(&lhs->volumePart, &rhs->volumePart);

        if (0 != r)
        {
            *result = r;

            return LIBPATH_RC_OF(Success);
        }
    }
#endif

    if (LIBPATH_LF_nullptr == cwd)
    {
        switch (LIBPATH_COMBINE_RLEVELS_(lhsRelativity, rhsRelativity))
        {
        default:
            LIBPATH_MESSAGE_ASSERT(0, "unexpected!");
        case LIBPATH_COMBINE_RLEVELS_(relative, relative):
#ifdef LIBPATH_OS_IS_WINDOWS
        case LIBPATH_COMBINE_RLEVELS_(rooted, rooted):
#endif
        case LIBPATH_COMBINE_RLEVELS_((absolute | rooted), (absolute | rooted)):
            // do nothing here
            break;

#ifdef LIBPATH_OS_IS_WINDOWS
        case LIBPATH_COMBINE_RLEVELS_(rooted, (absolute | rooted)):
        case LIBPATH_COMBINE_RLEVELS_(relative, rooted):
#endif
        case LIBPATH_COMBINE_RLEVELS_(relative, (absolute | rooted)):
            // lhs < rhs
            *result = -1;
            return LIBPATH_RC_OF(Success);

        case LIBPATH_COMBINE_RLEVELS_((absolute | rooted), relative):
#ifdef LIBPATH_OS_IS_WINDOWS
        case LIBPATH_COMBINE_RLEVELS_((absolute | rooted), rooted):
        case LIBPATH_COMBINE_RLEVELS_(rooted, relative):
#endif
            // lhs > rhs
            *result = +1;
            return LIBPATH_RC_OF(Success);
        }
    }

    LIBPATH_ASSERT((OLD_REL(lhsRelativity) == OLD_REL(rhsRelativity)) || (LIBPATH_LF_nullptr != cwd));


    /* If both absolute, see if roots are different */

    if (LIBPATH_IS_ABSOLUTE_(lhsRelativity) &&
        LIBPATH_IS_ABSOLUTE_(rhsRelativity))
    {
        int const r = libpath_Internal_compare_roots(&lhs->rootPart, &rhs->rootPart, flags);

        if (0 != r)
        {
            *result = r;

            return LIBPATH_RC_OF(Success);
        }
    }

    /* If relativity is different (and ) */

    if (OLD_REL(lhsRelativity) != OLD_REL(rhsRelativity))
    {
        LIBPATH_ASSERT(LIBPATH_LF_nullptr != cwd);

        {
            int const                       cwdRelativity   =   libpath_ParseResult_get_relativity_level_(cwd);
            int const                       reversed        =   (OLD_REL(lhsRelativity) > OLD_REL(rhsRelativity));
            int const                       absRelativity   =   reversed ? lhsRelativity : rhsRelativity;
#ifdef LIBPATH_OS_IS_WINDOWS
            int const                       relRelativity   =   reversed ? rhsRelativity : lhsRelativity;
#endif
            libpath_ParseResult_t const*    abs             =   reversed ? lhs : rhs;
            libpath_ParseResult_t const*    rel             =   reversed ? rhs : lhs;
            int const                       r_multiplier    =   reversed ? +1 : -1;
            int const                       abs_base_flags  =   reversed ? lParseFlags : rParseFlags;
            int const                       rel_base_flags  =   reversed ? rParseFlags : lParseFlags;

            /* TODO: need to change the way paths are qualified, so as to be a
            * bitmap of fields:
            *
            * - rooted
            * - volume
            * - UNC
            *
            * That way we can test combinations of REL|CWD with ABS for
            * easier comparison, and avoid the following baroque logic
            */

#ifdef LIBPATH_OS_IS_WINDOWS
            /* On Windows, any of the three can have a volume part, regardless
            * of whether that qualifies as a full root.
            *
            * NOTE: absolute may not be absolute here (on Windows), only that
            * it is _more absolute_ than relative
            *
            *      absolute    relative    cwd         action
            *      --------    --------    ---         ------
            * 0.     UNC         UNC         *         CANNOT OCCUR : handled above
            * 5.     UNC         vol         *         return +1
            * 6.     UNC        no-vol       vol       return +1
            * 7.     UNC        no-vol       UNC       do nothing here
            * 8.     UNC        no-vol      no-vol     return +1
            * 1.     vol         vol         *         volumes must be same (!= is handled above); need to check whether cwd gives root
            * 2.     vol        no-vol       vol       compare abs and cwd vols, return if different
            * 3.     vol        no-vol       UNC       return -1
            * 4.     vol        no-vol      no-vol     return +1
            *
            */

            int const cmbRelativity =   relRelativity | cwdRelativity;

            if (LIBPATH_IS_UNC_(absRelativity))
            {
                if (!LIBPATH_IS_UNC_(cmbRelativity))
                {
                    /* 5. */
                    /* 6. */
                    /* 8. */
                    *result = +1 * r_multiplier;

                    return LIBPATH_RC_OF(Success);
                }
                else
                {
                    /* 7. */

                    ; // do nothing here
                }
            }
            else
            if (LIBPATH_HAS_VOLUME_(absRelativity))
            {
                if (LIBPATH_HAS_VOLUME_(relRelativity))
                {
                    /* 1. */

                    LIBPATH_ASSERT(LIBPATH_IS_ABSOLUTE_(absRelativity));

                    /* Special case: at this point, the relative might have a
                    * volume but no root, and the cwd also has no root
                    */

                    if (LIBPATH_IS_RELATIVE_(cwdRelativity) &&
                        LIBPATH_IS_RELATIVE_(relRelativity))
                    {
                        *result = +1 * r_multiplier;

                        return LIBPATH_RC_OF(Success);
                    }
                }
                else
                if (LIBPATH_HAS_VOLUME_(cwdRelativity))
                {
                    /* 2. */
                    int const r = compare_volume_letters(&abs->volumePart, &cwd->volumePart);

                    if (0 != r)
                    {
                        *result = r * r_multiplier;

                        return LIBPATH_RC_OF(Success);
                    }

                    LIBPATH_ASSERT(LIBPATH_IS_ABSOLUTE_(absRelativity));

                    /* Special case: at this point, we look for combination
                    * of relative relative and relative cwd having volume
                    */

                    if (LIBPATH_IS_RELATIVE_(cwdRelativity) &&
                        LIBPATH_IS_RELATIVE_(relRelativity))
                    {
                        *result = +1 * r_multiplier;

                        return LIBPATH_RC_OF(Success);
                    }
                }
                else
                if (LIBPATH_IS_UNC_(cwdRelativity))
                {
                    /* 3. */
                    *result = -1 * r_multiplier;

                    return LIBPATH_RC_OF(Success);
                }
                else
                {
                    /* 4. */
                    *result = +1 * r_multiplier;

                    return LIBPATH_RC_OF(Success);
                }
            }
#else
            if (cwdRelativity < absRelativity)
            {
                *result = +1 * r_multiplier;

                return LIBPATH_RC_OF(Success);
            }
#endif

#ifdef LIBPATH_OS_IS_WINDOWS
            if (LIBPATH_IS_ABSOLUTE_(absRelativity) &&
                LIBPATH_IS_ABSOLUTE_(cwdRelativity))
            {
                int const r = libpath_Internal_compare_roots(&abs->rootPart, &cwd->rootPart, flags);

                if (0 != r)
                {
                    *result = r * r_multiplier;

                    return LIBPATH_RC_OF(Success);
                }
            }
#endif

            {
                libpath_StringSlice_t*  adirparts   =   LIBPATH_LF_nullptr;
                libpath_StringSlice_t*  rdirparts   =   LIBPATH_LF_nullptr;
                libpath_StringSlice_t*  cdirparts   =   LIBPATH_LF_nullptr;

                LIBPATH_RC rc = LIBPATH_RC_OF(Success);

                if (LIBPATH_RC_SUCCESS(rc))
                {
                    rc = libpath_Util_AllocateSliceArray(abs->numDirectoryParts, &adirparts);
                }

                if (LIBPATH_RC_SUCCESS(rc))
                {
                    rc = libpath_Util_AllocateSliceArray(rel->numDirectoryParts, &rdirparts);
                }

                if (LIBPATH_RC_SUCCESS(rc))
                {
                    rc = libpath_Util_AllocateSliceArray(cwd->numDirectoryParts, &cdirparts);
                }

                if (LIBPATH_RC_FAILURE(rc))
                {
                    libpath_Util_FreeSliceArray(adirparts);
                    libpath_Util_FreeSliceArray(rdirparts);
                    libpath_Util_FreeSliceArray(cdirparts);

                    return rc;
                }
                else
                {
                    libpath_ParseResult_t   aresult     =   { 0 };
                    libpath_ParseResult_t   rresult     =   { 0 };
                    libpath_ParseResult_t   cresult     =   { 0 };
                    int const               abs_flags   =   0
                                                        |   abs_base_flags
                                                        ;
                    int const               rel_flags   =   0
                                                        |   rel_base_flags
                                                        ;
                    int const               cwd_flags   =   0
                                                        |   libpath_ParseOption_AssumeDirectory
                                                        ;

                    /* we don't check the return from these, because they can't fail */

                    libpath_Parse_ParsePathFromStringSlice(&abs->input, abs_flags, &aresult, abs->numDirectoryParts, adirparts);
                    libpath_Parse_ParsePathFromStringSlice(&rel->input, rel_flags, &rresult, rel->numDirectoryParts, rdirparts);
                    libpath_Parse_ParsePathFromStringSlice(&cwd->input, cwd_flags, &cresult, cwd->numDirectoryParts, cdirparts);

                    /* canonicalise all individual parts arrays ... */

                    {
                        libpath_size_t const    nadirparts  =   libpath_Internal_canonicalise_parts(abs->numDirectoryParts, adirparts);
                        libpath_size_t          nrdirparts  =   libpath_Internal_canonicalise_parts(rel->numDirectoryParts, rdirparts);
                        libpath_size_t          ncdirparts  =   libpath_Internal_canonicalise_parts(cwd->numDirectoryParts, cdirparts);

                        /* ... and between relative parts and cwd parts arrays (to account for leading double-dots in relative path) */

                        canonicalise_between_relative_and_cwd(&nrdirparts, rdirparts, &ncdirparts, cdirparts);

                        {
                            int const               r           =   libpath_Internal_compare_directory_parts_with_wd(nadirparts, adirparts, nrdirparts, rdirparts, ncdirparts, cdirparts, flags);

                            libpath_Util_FreeSliceArray(adirparts);
                            libpath_Util_FreeSliceArray(rdirparts);
                            libpath_Util_FreeSliceArray(cdirparts);

                            if (0 != r)
                            {
                                *result = r * r_multiplier;

                                return LIBPATH_RC_OF(Success);
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        /* If there are non dots parts, then we can skip the canonicalisation */

        if (0 == lhs->numDotsDirectoryParts &&
            0 == rhs->numDotsDirectoryParts)
        {
            int const r = libpath_Internal_compare_path_fragment(&lhs->directoryPart, &rhs->directoryPart, flags);

            if (0 != r)
            {
                *result = r;

                return LIBPATH_RC_OF(Success);
            }
        }
        else
        {
            /* 1+ dots parts, so must canonicalise (both) */

            if (0 != lhs->numDirectoryParts ||
                0 != rhs->numDirectoryParts)
            {
#ifdef NDEBUG
# error Rename libpath_ParseResult_t to libpath_PathDescriptor_t (or similar)
#else /* ? NDEBUG */
#endif /* NDEBUG */

#ifdef NDEBUG
# error create libpath_Parse_DeriveDirectoryPartsFrom/For/OnPathDescriptor()
#else /* ? NDEBUG */
#endif /* NDEBUG */

                {
                    libpath_StringSlice_t*  ldirparts   =   LIBPATH_LF_nullptr;
                    libpath_StringSlice_t*  rdirparts   =   LIBPATH_LF_nullptr;

                    LIBPATH_RC rc = LIBPATH_RC_OF(Success);

                    if (LIBPATH_RC_SUCCESS(rc))
                    {
                        rc = libpath_Util_AllocateSliceArray(lhs->numDirectoryParts, &ldirparts);
                    }

                    if (LIBPATH_RC_SUCCESS(rc))
                    {
                        rc = libpath_Util_AllocateSliceArray(rhs->numDirectoryParts, &rdirparts);
                    }

                    if (LIBPATH_RC_FAILURE(rc))
                    {
                        libpath_Util_FreeSliceArray(ldirparts);
                        libpath_Util_FreeSliceArray(rdirparts);

                        return rc;
                    }
                    else
                    {
                        libpath_ParseResult_t   lresult     =   { 0 };
                        libpath_ParseResult_t   rresult     =   { 0 };

                        /* we don't check the return from these, because they can't fail */

                        libpath_Parse_ParsePathFromStringSlice(&lhs->input, lParseFlags, &lresult, lhs->numDirectoryParts, ldirparts);
                        libpath_Parse_ParsePathFromStringSlice(&rhs->input, rParseFlags, &rresult, rhs->numDirectoryParts, rdirparts);

                        {
                        libpath_size_t const    nldirparts  =   libpath_Internal_canonicalise_parts(lhs->numDirectoryParts, ldirparts);
                        libpath_size_t const    nrdirparts  =   libpath_Internal_canonicalise_parts(rhs->numDirectoryParts, rdirparts);

                        int const               r           =   libpath_Internal_compare_directory_parts(nldirparts, ldirparts, nrdirparts, rdirparts, flags);

                        libpath_Util_FreeSliceArray(ldirparts);
                        libpath_Util_FreeSliceArray(rdirparts);

                        if (0 != r)
                        {
                            *result = r;

                            return LIBPATH_RC_OF(Success);
                        }
                        }
                    }
                }
            }
        }
    }

    /* If everything else is the same, then see if entries are different */

    {
        int const r = libpath_Internal_compare_path_fragment(&lhs->entryPart, &rhs->entryPart, flags);

        if (0 != r)
        {
            *result = r;

            return LIBPATH_RC_OF(Success);
        }
    }

    *result = 0;

    return LIBPATH_RC_OF(Success);
    }
}

static
LIBPATH_RC
libpath_Compare_ComparePathsAsStringSlices_impl1_(
    libpath_StringSlice_t const*                lhs
,   libpath_StringSlice_t const*                rhs
,   libpath_StringSlice_t const*                cwd
,   libpath_sint32_t                            flags
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs, "lhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs, "rhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    {
    LIBPATH_RC              rc;
    libpath_sint32_t        lParseFlags =   0;
    libpath_sint32_t        rParseFlags =   0;
    libpath_sint32_t        dParseFlags =   0
                                        |   libpath_ParseOption_AssumeDirectory
                                        ;

    libpath_ParseResult_t   lresult;
    libpath_ParseResult_t   rresult;
    libpath_ParseResult_t   dresult;

    libpath_truthy_t        shouldParseCwd = LIBPATH_V_FALSEY;

    libpath_size_t const    lNumTrailingDots = libpath_Internal_count_trailing_dots_directory(lhs);
    libpath_size_t const    rNumTrailingDots = libpath_Internal_count_trailing_dots_directory(rhs);

    if (0 != lNumTrailingDots)
    {
        lParseFlags |= libpath_ParseOption_AssumeDirectory;
    }

    if (0 != rNumTrailingDots)
    {
        rParseFlags |= libpath_ParseOption_AssumeDirectory;
    }

    rc = libpath_Parse_ParsePathFromStringSlice(lhs, lParseFlags, &lresult, 0, LIBPATH_LF_nullptr);

    if (LIBPATH_RC_OF(Success) != rc)
    {
        switch (rc)
        {
        case LIBPATH_RC_OF(NoPathSpecified):
        case LIBPATH_RC_OF(BadPathCharacter):

            rc = LIBPATH_RC_OF(FirstPathInvalid);
            break;
        default:

            break;
        }

        return rc;
    }

    rc = libpath_Parse_ParsePathFromStringSlice(rhs, rParseFlags, &rresult, 0, LIBPATH_LF_nullptr);

    if (LIBPATH_RC_OF(Success) != rc)
    {
        switch (rc)
        {
        case LIBPATH_RC_OF(NoPathSpecified):
        case LIBPATH_RC_OF(BadPathCharacter):

            rc = LIBPATH_RC_OF(SecondPathInvalid);
            break;
        default:

            break;
        }

        return rc;
    }

    if (LIBPATH_LF_nullptr != cwd)
    {
        if (libpath_ParseResult_get_relativity_level_(&lresult) != libpath_ParseResult_get_relativity_level_(&rresult))
        {
            shouldParseCwd = LIBPATH_V_TRUEY;
        }

        if (shouldParseCwd)
        {
            rc = libpath_Parse_ParsePathFromStringSlice(cwd, dParseFlags, &dresult, 0, LIBPATH_LF_nullptr);

            if (LIBPATH_RC_OF(Success) != rc)
            {
                switch (rc)
                {
                case LIBPATH_RC_OF(NoPathSpecified):
                case LIBPATH_RC_OF(BadPathCharacter):

                    rc = LIBPATH_RC_OF(WorkingDirectoryPathInvalid);
                    break;
                default:

                    break;
                }

                return rc;
            }

        }
    }

    return libpath_Compare_ComparePathsAsStringSlices_impl2_(
            &lresult
        ,   &rresult
        ,   shouldParseCwd ? &dresult : LIBPATH_LF_nullptr
        ,   flags
        ,   lParseFlags
        ,   rParseFlags
        ,   result
        );
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

LIBPATH_API
libpath_Compare_ComparePathsAsStringSlices(
    libpath_StringSlice_t const*                lhs
,   libpath_StringSlice_t const*                rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt        /* = NULL */
,   void*                                       reserved    /* = NULL */
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs, "lhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs, "rhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    if (LIBPATH_LF_nullptr != reserved)
    {
        return LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero);
    }
#ifndef __cplusplus

    return libpath_Compare_ComparePathsAsStringSlices_UNCHECKED_(lhs, rhs, flags, ctxt, result);
}

static
LIBPATH_RC
libpath_Compare_ComparePathsAsStringSlices_UNCHECKED_(
    libpath_StringSlice_t const*                lhs
,   libpath_StringSlice_t const*                rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   libpath_truthy_t*                           result
)
{
#endif /* !__cplusplus */

    libpath_StringSlice_t           cwd_;
    libpath_StringSlice_t const*    cwd = LIBPATH_LF_nullptr;

    if (LIBPATH_LF_nullptr != ctxt)
    {
        switch (ctxt->mechanism)
        {
        case libpath_WorkingDirectoryContextMechanism_NoneSpecified:

            break;
        case libpath_WorkingDirectoryContextMechanism_CStyleString:

            if (LIBPATH_LF_nullptr != ctxt->details.cwd_css)
            {
                cwd_ = libpath_Util_SliceFromCStyleString(ctxt->details.cwd_css);
                cwd = &cwd_;
            }
            break;
        case libpath_WorkingDirectoryContextMechanism_StringSlice:

            cwd = &ctxt->details.cwd_slice;
            break;
        default:

            LIBPATH_MESSAGE_ASSERT(0, "invalid WorkingDirectoryContextMechanism");
#if defined(_WIN32) || defined(_WIN64)
        case libpath_WorkingDirectoryContextMechanism_GetCurrentDirectory:
#endif
        case libpath_WorkingDirectoryContextMechanism_getcwd:
            return LIBPATH_RC_OF(OptionNotSupported);
        }
    }

    return libpath_Compare_ComparePathsAsStringSlices_impl1_(lhs, rhs, cwd, flags, result);
}

LIBPATH_API
libpath_Compare_ComparePathsAsStringPtrsAndLens(
    libpath_char_t const*                       lhs
,   libpath_size_t                              lhsLen
,   libpath_char_t const*                       rhs
,   libpath_size_t                              rhsLen
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt        /* = NULL */
,   void*                                       reserved    /* = NULL */
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs || 0 == lhsLen, "lhs parameter may not be NULL if lhsLen is not 0");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs || 0 == rhsLen, "rhs parameter may not be NULL if rhsLen is not 0");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    if (LIBPATH_LF_nullptr != reserved)
    {
        return LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero);
    }
#ifndef __cplusplus

    return libpath_Compare_ComparePathsAsStringPtrsAndLens_UNCHECKED_(lhs, lhsLen, rhs, rhsLen, flags, ctxt, result);
}

static
LIBPATH_RC
libpath_Compare_ComparePathsAsStringPtrsAndLens_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_size_t                              lhsLen
,   libpath_char_t const*                       rhs
,   libpath_size_t                              rhsLen
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   libpath_truthy_t*                           result
)
{
#endif /* !__cplusplus */

    libpath_StringSlice_t const lhs_sl = libpath_Util_SliceFromStringPtrAndLen(lhs, lhsLen);
    libpath_StringSlice_t const rhs_sl = libpath_Util_SliceFromStringPtrAndLen(rhs, rhsLen);

    return libpath_Compare_ComparePathsAsStringSlices(&lhs_sl, &rhs_sl, flags, ctxt, LIBPATH_LF_nullptr, result);
}

LIBPATH_API
libpath_Compare_ComparePathsAsCStyleStrings(
    libpath_char_t const*                       lhs
,   libpath_char_t const*                       rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt        /* = NULL */
,   void*                                       reserved    /* = NULL */
,   libpath_truthy_t*                           result
)
{
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != lhs, "lhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != rhs, "rhs parameter may not be NULL");
    LIBPATH_MESSAGE_ASSERT(LIBPATH_LF_nullptr != result, "result parameter may not be NULL");

    if (LIBPATH_LF_nullptr != reserved)
    {
        return LIBPATH_RC_OF(ParameterIsReservedAndMustBeZero);
    }
#ifndef __cplusplus

    return libpath_Compare_ComparePathsAsCStyleStrings_UNCHECKED_(lhs, rhs, flags, ctxt, result);
}

static
LIBPATH_RC
libpath_Compare_ComparePathsAsCStyleStrings_UNCHECKED_(
    libpath_char_t const*                       lhs
,   libpath_char_t const*                       rhs
,   libpath_sint32_t                            flags
,   libpath_WorkingDirectoryContext_t const*    ctxt
,   libpath_truthy_t*                           result
)
{
#endif /* !__cplusplus */

    libpath_StringSlice_t const lhs_sl = libpath_Util_SliceFromCStyleString(lhs);
    libpath_StringSlice_t const rhs_sl = libpath_Util_SliceFromCStyleString(rhs);

    return libpath_Compare_ComparePathsAsStringSlices(&lhs_sl, &rhs_sl, flags, ctxt, LIBPATH_LF_nullptr, result);
}


/* ///////////////////////////// end of file //////////////////////////// */

