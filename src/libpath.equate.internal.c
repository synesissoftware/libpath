
/*
 *
 * Updated: 13th February 2013
 */

#include "libpath.equate.internal.h"

#include <libpath/util/api.h>
#include "libpath.parse.internal.h"
#include "libpath.quality.contract.h"

#include <ctype.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Internal functions
 */

libpath_truthy_t
libpath_Internal_part_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
)
{
    if(lhs->len != rhs->len)
    {
        return LIBPATH_V_FALSEY;
    }

#ifdef LIBPATH_OS_IS_WINDOWS
    if(0 != _strnicmp(lhs->ptr, rhs->ptr, lhs->len))
#else
    if(0 != strncmp(lhs->ptr, rhs->ptr, lhs->len))
#endif
    {
        return LIBPATH_V_FALSEY;
    }

    return LIBPATH_V_TRUEY;
}

#ifdef LIBPATH_OS_IS_WINDOWS
libpath_truthy_t
libpath_Internal_volumes_definitely_different(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
)
{
    LIBPATH_ASSERT(2 == lhs->len || 3 == lhs->len);
    LIBPATH_ASSERT(2 == rhs->len || 3 == rhs->len);
    LIBPATH_ASSERT(':' == lhs->ptr[1]);
    LIBPATH_ASSERT(':' == rhs->ptr[1]);

    return toupper(lhs->ptr[0]) != toupper(rhs->ptr[0]);
}
#endif

libpath_truthy_t
libpath_Internal_roots_definitely_different(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
)
{
    if( 3 == lhs->len &&
        3 == rhs->len)
    {
#ifdef LIBPATH_OS_IS_WINDOWS
        return toupper(lhs->ptr[0]) != toupper(rhs->ptr[0]);
#else
        return lhs->ptr[0] != rhs->ptr[0];
#endif
    }

    if( (   lhs->len > 3 ||
            rhs->len > 3) &&
        lhs->len != rhs->len)
    {
        return LIBPATH_V_TRUEY;
    }

    return LIBPATH_V_FALSEY;
}

libpath_truthy_t
libpath_Internal_roots_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
)
{
    LIBPATH_ASSERT(lhs->len == rhs->len);

    { size_t i; for(i = 0; i != lhs->len; ++i)
    {
        libpath_char_t const    lch =   lhs->ptr[i];
        libpath_char_t const    rch =   rhs->ptr[i];

#ifdef LIBPATH_OS_IS_WINDOWS
        if(toupper(lch) != toupper(rch))
#else
        if(lch != rch)
#endif
        {
            if( !libpath_Internal_character_is_pnsep(lch) ||
                !libpath_Internal_character_is_pnsep(rch))
            {
                return LIBPATH_V_FALSEY;
            }
        }
    }}

    return LIBPATH_V_TRUEY;
}

size_t
libpath_Internal_count_dots(
    libpath_StringSlice_t const* part
)
{
    if(0 == part->len)
    {
        return 0;
    }

    if('.' == part->ptr[0])
    {
        if(1 == part->len)
        {
            return 1;
        }

        if( 2 == part->len &&
            libpath_Internal_character_is_pnsep(part->ptr[1]))
        {
            return 1;
        }

        if('.' == part->ptr[1])
        {
            if(2 == part->len)
            {
                return 2;
            }

            if( 3 == part->len ||
                libpath_Internal_character_is_pnsep(part->ptr[2]))
            {
                return 2;
            }
        }
    }

    return 0;
}

size_t
libpath_Internal_canonicalise_parts(
    size_t                  cdirparts
,   libpath_StringSlice_t*  dirparts
)
{
    libpath_StringSlice_t* const        begin   =   dirparts;
    libpath_StringSlice_t const * const end     =   dirparts + cdirparts;

    libpath_StringSlice_t*              dest    =   begin;
    libpath_StringSlice_t const*        src     =   begin;

    size_t                              nonDots =   0;

    for(; src != end; ++src)
    {
        size_t const numDots = libpath_Internal_count_dots(src);

        switch(numDots)
        {
            case    1:
                // We simply remove this part, by not incrementing
                // the dest
                continue;
            case    2:
                // We decrement the dest if we have any non-dots
                // directories in hand
                if(0 != nonDots)
                {
                    --dest;
                    --nonDots;
                    continue;
            default:
                    ++nonDots;
                }
                if(dest != src)
                {
                    *dest = *src;
                }
                ++dest;
                break;
        }
    }

    return dest - dirparts;
}

libpath_truthy_t
libpath_Internal_directory_whole_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
)
{
    size_t  lhsLen  =   lhs->len;
    size_t  rhsLen  =   rhs->len;

    if( 0 != lhsLen &&
        libpath_Internal_character_is_pnsep(lhs->ptr[lhsLen - 1]))
    {
        --lhsLen;
    }
    if( 0 != rhsLen &&
        libpath_Internal_character_is_pnsep(rhs->ptr[rhsLen - 1]))
    {
        --rhsLen;
    }

    if(lhsLen != rhsLen)
    {
        return LIBPATH_V_FALSEY;
    }

    { size_t i; for(i = 0; i != lhsLen; ++i)
    {
        char const  cl  =   lhs->ptr[i];
        char const  cr  =   rhs->ptr[i];

#ifdef LIBPATH_OS_IS_WINDOWS
        if(toupper(cl) != toupper(cr))
#else
        if(cl != cr)
#endif
        {
            if( !libpath_Internal_character_is_pnsep(cl) ||
                !libpath_Internal_character_is_pnsep(cr))
            {
                return LIBPATH_V_FALSEY;
            }
        }
    }}

    return LIBPATH_V_TRUEY;
}

libpath_truthy_t
libpath_Internal_directory_whole_equal_3(
    libpath_StringSlice_t const*    abs
,   libpath_StringSlice_t const*    rel
,   libpath_StringSlice_t const*    cwd
)
{
    // slight complication here, since trailing pnseps may
    // not be present on cwd, so determine "cwd gap" as
    // the potential absence of trailing sep

    size_t cwd_gap = 0;

    if(0 != cwd->len)
    {
        if(!libpath_Internal_character_is_pnsep(cwd->ptr[cwd->len - 1]))
        {
            ++cwd_gap;
        }
    }

    if(abs->len < cwd->len + cwd_gap + rel->len)
    {
        return LIBPATH_V_FALSEY;
    }

    if(0 != cwd->len)
    {
        libpath_StringSlice_t const abs_cwd = libpath_Util_SliceFromStringPtrAndLen(abs->ptr, cwd->len);

        if(!libpath_Internal_directory_whole_equal(&abs_cwd, cwd))
        {
            return LIBPATH_V_FALSEY;
        }
    }

    if(0 != rel->len)
    {
        libpath_StringSlice_t const abs_rel = libpath_Util_SliceFromStringPtrAndLen(abs->ptr + cwd->len + cwd_gap, rel->len);

        if(!libpath_Internal_directory_whole_equal(&abs_rel, rel))
        {
            return LIBPATH_V_FALSEY;
        }
    }

    return LIBPATH_V_TRUEY;
}

libpath_truthy_t
libpath_Internal_directory_part_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
)
{
    size_t  lhsLen  =   lhs->len;
    size_t  rhsLen  =   rhs->len;

    if( 0 != lhsLen &&
        libpath_Internal_character_is_pnsep(lhs->ptr[lhsLen - 1]))
    {
        --lhsLen;
    }
    if( 0 != rhsLen &&
        libpath_Internal_character_is_pnsep(rhs->ptr[rhsLen - 1]))
    {
        --rhsLen;
    }

    if(lhsLen != rhsLen)
    {
        return LIBPATH_V_FALSEY;
    }

    { size_t i; for(i = 0; i != lhsLen; ++i)
    {
        char const  cl  =   lhs->ptr[i];
        char const  cr  =   rhs->ptr[i];

#ifdef LIBPATH_OS_IS_WINDOWS
        if(toupper(cl) != toupper(cr))
#else
        if(cl != cr)
#endif
        {
            return LIBPATH_V_FALSEY;
        }
    }}

    return LIBPATH_V_TRUEY;
}

libpath_truthy_t
libpath_Internal_directory_parts_equal(
    size_t                  cldirparts
,   libpath_StringSlice_t*  ldirparts
,   size_t                  crdirparts
,   libpath_StringSlice_t*  rdirparts
)
{
    if(cldirparts != crdirparts)
    {
        return LIBPATH_V_FALSEY;
    }

    { size_t i; for(i = 0; i != cldirparts; ++i)
    {
        if(!libpath_Internal_directory_part_equal(&ldirparts[i], &rdirparts[i]))
        {
            return LIBPATH_V_FALSEY;
        }
    }}

    return LIBPATH_V_TRUEY;
}

int
libpath_Internal_get_root_level(
    libpath_ParseResult_t const* r
)
{
#ifndef LIBPATH_OS_IS_WINDOWS
    LIBPATH_ASSERT(r->rootPart.len < 2);
#endif

    switch(r->rootPart.len)
    {
        case    0:
#ifdef LIBPATH_OS_IS_WINDOWS
            return (int)r->volumePart.len;
#else
            return 0;
#endif
        case    1:
            return 1;
        case    3:
            return 3;
        default:
            return 4;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
