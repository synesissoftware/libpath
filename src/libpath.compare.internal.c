
/*
 *
 * Updated: 11th February 2024
 */

#include "libpath.compare.internal.h"

#include <libpath/util/api.h>
#include "libpath.parse.internal.h"
#include "libpath.quality.contract.h"

#include <ctype.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * internal functions
 */


int
libpath_Internal_compare_roots(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   int                             flags
)
{
    LIBPATH_ASSERT(NULL != lhs);
    LIBPATH_ASSERT(NULL != rhs);
    LIBPATH_ASSERT(0 != lhs->len);
    LIBPATH_ASSERT(0 != rhs->len);

    LIBPATH_SUPPRESS_UNUSED(flags);

#ifdef LIBPATH_OS_IS_WINDOWS
    if (1 == lhs->len &&
        1 == rhs->len)
#endif
    {
        LIBPATH_ASSERT(libpath_Internal_character_is_pathname_separator(0[lhs->ptr]));
        LIBPATH_ASSERT(libpath_Internal_character_is_pathname_separator(0[rhs->ptr]));

        return 0;
    }
#ifdef LIBPATH_OS_IS_WINDOWS
    else
    if (3 == lhs->len &&
        3 == rhs->len)
    {
        char const  cl  =   (char)toupper(lhs->ptr[0]);
        char const  cr  =   (char)toupper(rhs->ptr[0]);

        LIBPATH_ASSERT(isalpha(0[lhs->ptr]));
        LIBPATH_ASSERT(isalpha(0[rhs->ptr]));
        LIBPATH_ASSERT(':' == 1[lhs->ptr]);
        LIBPATH_ASSERT(':' == 1[rhs->ptr]);
        LIBPATH_ASSERT(libpath_Internal_character_is_pathname_separator(2[lhs->ptr]));
        LIBPATH_ASSERT(libpath_Internal_character_is_pathname_separator(2[rhs->ptr]));

        return (int)(unsigned char)cl - (int)(unsigned char)cr;    /* C99: 7.21.4(1) */
    }
    else
    if (3 == lhs->len &&
        3 < rhs->len)
    {
        return -1;
    }
    else
    if (3 < lhs->len &&
        3 == rhs->len)
    {
        return +1;
    }
    else
    {
        libpath_size_t  i;
        int             r = 0;

        LIBPATH_MESSAGE_ASSERT(lhs->len >= 5, "must be UNC server+share");
        LIBPATH_MESSAGE_ASSERT(rhs->len >= 5, "must be UNC server+share");

        for(i = 0; 0 == r && i != lhs->len && i != rhs->len; ++i)
        {
            char const  cl  =   (char)toupper(lhs->ptr[i]);
            char const  cr  =   (char)toupper(rhs->ptr[i]);

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

        LIBPATH_ASSERT((lhs->len == i) || (rhs->len == i));

        if (lhs->len != i)
        {
            return +1;
        }
        if (rhs->len != i)
        {
            return -1;
        }
    }

    return 0;
#endif
}

int
libpath_Internal_compare_path_fragment(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   int                             flags
)
{
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

    for(i = 0; 0 == r && i != lhsLen && i != rhsLen; ++i)
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


/* ///////////////////////////// end of file //////////////////////////// */

