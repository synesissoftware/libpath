
/*
 *
 * Updated: 20th July 2024
 */

#include "libpath.parse.internal.h"

#include <libpath/util/api.h>

#include "libpath.quality.contract.h"

#include <ctype.h>


/* /////////////////////////////////////////////////////////////////////////
 * internal functions
 */

libpath_truthy_t
libpath_Internal_path_character_is_bad(
    libpath_char_t                  ch
,   libpath_StringSlice_t const*    path
,   libpath_size_t                  offset
,   int                             flags
)
{
    LIBPATH_SUPPRESS_UNUSED(flags);

#ifndef LIBPATH_OS_IS_WINDOWS
    ((void)&path);
    ((void)&offset);
#endif

    switch (ch)
    {
#ifdef LIBPATH_OS_IS_WINDOWS
    case    ':':

        if (1u == offset &&
            isalpha(path->ptr[0]))
        {
            return LIBPATH_V_FALSEY;
        }
        else
        {
            return LIBPATH_V_TRUEY;
        }
#endif

    case    '|':
    case    '<':
    case    '>':
    case    '?':
    case    '*':
#ifdef LIBPATH_OS_IS_WINDOWS
    case    ';':
#endif
#ifdef LIBPATH_OS_IS_UNIX
    case    ':':
#endif

        return LIBPATH_V_TRUEY;
    default:

        return LIBPATH_V_FALSEY;
    }
}

libpath_size_t
libpath_Internal_count_trailing_dots_directory(
    libpath_StringSlice_t const* path
)
{
    if (0 == path->len)
    {
        return 0;
    }
    else
    {
        if ('.' != path->ptr[path->len - 1])
        {
            return 0;
        }
        else
        {
            if (1 == path->len ||
                libpath_Internal_character_is_pathname_separator(path->ptr[path->len - 2]))
            {
                return 1;
            }
            else
            {
                if ('.' != path->ptr[path->len - 2])
                {
                    return 0;
                }
                else
                {
                    if (2 == path->len ||
                        libpath_Internal_character_is_pathname_separator(path->ptr[path->len - 3]))
                    {
                        return 2;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
}

libpath_truthy_t
libpath_Internal_character_is_pathname_separator(
    libpath_char_t ch
)
{
    switch (ch)
    {
    case    '/':
#ifdef LIBPATH_OS_IS_WINDOWS
    case    '\\':
#endif /* LIBPATH_OS_IS_WINDOWS */

        return LIBPATH_V_TRUEY;
    default:

        return LIBPATH_V_FALSEY;
    }
}


//
//
// @retval LIBPATH_V_TRUEY the path is absolute
// @retval LIBPATH_V_FALSEY the path is not absolute
//
// @note On Windows, it is possible to have a path containing a volume
//   that is not absolute, e.g. 'C:abc', in which case the rootLen will
//   be determined as 2 even though the return value will be LIBPATH_V_FALSEY
libpath_truthy_t
libpath_Internal_path_is_absolute(
    libpath_StringSlice_t const*    path
,   libpath_size_t*                 rootLen
,   libpath_truthy_t*               invalidRoot
)
{
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != path);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != rootLen);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != invalidRoot);
    LIBPATH_ASSERT(0 == path->len || LIBPATH_LF_nullptr != path->ptr);

    if (LIBPATH_LF_nullptr != rootLen)
    {
        *rootLen = 0;
    }

    *invalidRoot = LIBPATH_V_FALSEY;

    if (0 == path->len)
    {
        return LIBPATH_V_FALSEY;
    }

#ifdef LIBPATH_OS_IS_WINDOWS
    // Windows options are:
    //
    // 1. First three characters are a volume and root-directory,
    //    e.g. "H:\file.ext";
    // 2. The path begins with a UNC share specification, e.g.
    //    "\\host\share\file.ext"; for simplicity (and performance)
    ///   we recognise only the first two;
    // 3. first character is a backslash, e.g. "\file.ext";
    // 4. first character is a slash, e.g. "/file.ext";
    // 5. first character is an alphanumeric, e.g. "file.ext";
    // 6. path begins with an invalid character, e.g. "|file.ext";
    // 7. string is empty; or
    // 8. <any-other-case>.
    //
    // The first four give true; the latter four give false.
    //
    // In addition, it is possible for a path to have a volume and yet
    // still be relative, e.g. "H:file.ext"

    switch (path->ptr[0])
    {
    case    '\0':
        // #7

        return LIBPATH_V_FALSEY;
    case    '/':
        // #4

        if (LIBPATH_LF_nullptr != rootLen)
        {
            *rootLen = 1;
        }

        return LIBPATH_V_TRUEY;
    case    '\\':
        // #2 or #3

        if (path->len > 1 &&
            '\\' == path->ptr[1])
        {
            // #2

            if (LIBPATH_LF_nullptr != rootLen)
            {
                libpath_StringSlice_t const root = libpath_Internal_find_UNC_root_slice(path);

                if (LIBPATH_LF_nullptr != rootLen)
                {
                    *rootLen = root.len;
                }

                if (0 == root.len)
                {
                    *invalidRoot = LIBPATH_V_TRUEY;

                    return LIBPATH_V_FALSEY;
                }
            }

            return LIBPATH_V_TRUEY;
        }
        else
        {
            // #3

            if (LIBPATH_LF_nullptr != rootLen)
            {
                *rootLen = 1;
            }

            return LIBPATH_V_TRUEY;
        }

        // fall-through
    case    '?':
    case    '*':
    case    '|':
    case    '<':
    case    '>':
        // #6

        return LIBPATH_V_FALSEY;
    default:
        // #1 / #5

        if (isalpha(path->ptr[0]))
        {
            if (path->len > 1 &&
                ':' == path->ptr[1])
            {
                if (path->len > 2 &&
                    libpath_Internal_character_is_pathname_separator(path->ptr[2]))
                {
                    // #1

                    if (LIBPATH_LF_nullptr != rootLen)
                    {
                        *rootLen = 3;
                    }

                    return LIBPATH_V_TRUEY;
                }
                else
                {
                    if (LIBPATH_LF_nullptr != rootLen)
                    {
                        *rootLen = 2;
                    }
                }
            }

            // #5
            return LIBPATH_V_FALSEY;
        }
        else
        {
            // #8
            return LIBPATH_V_FALSEY;
        }
    }
#else

    // Unix options are:
    //
    // 1. first character is a slash

    if ('/' == path->ptr[0])
    {
        if (LIBPATH_LF_nullptr != rootLen)
        {
            *rootLen = 1;
        }

        return LIBPATH_V_TRUEY;
    }

    return LIBPATH_V_FALSEY;
#endif
}

libpath_truthy_t
libpath_Internal_find_next_directory_part(
    libpath_size_t*                 i
,   libpath_StringSlice_t const*    directoryPart
,   int                             flags
,   libpath_StringSlice_t*          part
,   libpath_truthy_t*               isDots
)
{
    libpath_size_t numConsecutiveDots = 0;

    LIBPATH_ASSERT(LIBPATH_LF_nullptr != directoryPart);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != part);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != isDots);
    LIBPATH_ASSERT(*i <= directoryPart->len + 1);

    part->ptr = directoryPart->ptr + *i;

    *isDots = LIBPATH_V_FALSEY;

    for (; *i < directoryPart->len; ++*i)
    {
        if (libpath_Internal_character_is_pathname_separator(directoryPart->ptr[*i]) &&
            (   (*i + 1) == directoryPart->len ||
                !libpath_Internal_character_is_pathname_separator(directoryPart->ptr[*i + 1])))
        {
            part->len = (directoryPart->ptr + ++*i) - part->ptr;

            if (0 != numConsecutiveDots)
            {
                *isDots = LIBPATH_V_TRUEY;
            }

            return LIBPATH_V_TRUEY;
        }
        else
        if ('.' == directoryPart->ptr[*i])
        {
            ++numConsecutiveDots;
        }
        else
        {
            numConsecutiveDots = 0;
        }
    }

    switch (numConsecutiveDots)
    {
    case    1:
    case    2:

        part->len = numConsecutiveDots;
        *isDots = LIBPATH_V_TRUEY;
        ++*i;

        return LIBPATH_V_TRUEY;
    default:

        break;
    }

    // Handling 'assume directory'
    if (directoryPart->len == *i &&
        !libpath_Internal_character_is_pathname_separator(directoryPart->ptr[*i - 1]) &&
        libpath_ParseOption_AssumeDirectory == (libpath_ParseOption_AssumeDirectory & flags))
    {
        part->len = (directoryPart->ptr + (*i)++) - part->ptr;

        return LIBPATH_V_TRUEY;
    }

    part->len = 0;

    return LIBPATH_V_FALSEY;
}

#ifdef LIBPATH_OS_IS_WINDOWS
libpath_StringSlice_t
libpath_Internal_find_UNC_root_slice(
    libpath_StringSlice_t const*    path
)
{
    enum
    {
        slash2,
        host,
        hostSlash,
        share,
        invalid
    };

    libpath_size_t i = 0;

    int state = slash2;

    LIBPATH_ASSERT(path->len > 1);
    LIBPATH_ASSERT(LIBPATH_LF_nullptr != path->ptr);
    LIBPATH_ASSERT('\\' == path->ptr[0]);
    LIBPATH_ASSERT('\\' == path->ptr[1]);

    i += 2;

    for (; i != path->len; ++i)
    {
        if (invalid == state)
        {
            continue;
        }

        switch (path->ptr[i])
        {
        case    '/':

            if (state == share)
            {
        case    '\\':

                switch (state)
                {
                case    slash2:     state = invalid;    break;
                case    host:       state = hostSlash;  break;
                case    hostSlash:  state = invalid;    break;
                case    share:      return libpath_Util_SliceFromStringPtrAndLen(path->ptr, ++i);
                default:

                    LIBPATH_ASSERT(!"unexpected");
                case    invalid:    state = invalid;    break;
                }
            break;
            }
            else // '/' fall through
        default:

            switch (state)
            {
            case    slash2:     state = host;       break;
            case    host:                           break;
            case    hostSlash:  state = share;      break;
            case    share:                          break;
            default:

                LIBPATH_ASSERT(!"unexpected");
            case    invalid:    state = invalid;    break;
            }
            break;
        }

    }

    return libpath_Util_SliceFromStringPtrAndLen(path->ptr, 0);
}
#endif


/* ///////////////////////////// end of file //////////////////////////// */

