
/*
 * Created:
 * Updated: 11th February 2024
 */

#include <libpath/parse/types.h>


/* /////////////////////////////////////////////////////////////////////////
 * internal API functions
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/*
 *
 * @retval LIBPATH_V_TRUEY the value held by @c ch is that of a
 *   valid path-name-separator on the executing platform
 * @retval LIBPATH_V_FALSEY the value held by @c ch is not that of a
 *   valid path-name-separator on the executing platform
 */
libpath_truthy_t
libpath_Internal_character_is_pathname_separator(
    libpath_char_t                  ch
);

libpath_truthy_t
libpath_Internal_path_character_is_bad(
    libpath_char_t                  ch
,   libpath_StringSlice_t const*    path
,   libpath_size_t                  offset
,   int                             flags
);

/* Evaluates whether the path ends with a dots directory, i.e. one of the
 * following sequences (where <pes> means possibly-empty-string and <nes>
 * means non-empty-string that does not end in '.' or a recognised slash):
 *
 * path                 |      result
 * ----                 |      ------
 * ""                   |          0
 * "."                  |          1
 * ".."                 |          2
 * "..."                |          0
 * "...."               |          0
 * "<pes>/."            |          1
 * "<pes>/.."           |          2
 * "<pes>/..."          |          0
 * "<pes>/...."         |          0
 * "<pes>\."            |          1    (Windows-only)
 * "<pes>\.."           |          2    (Windows-only)
 * "<pes>\..."          |          0    (Windows-only)
 * "<pes>\...."         |          0    (Windows-only)
 * "<nes>."             |          0
 * "<nes>.."            |          0
 * "<nes>..."           |          0
 */
libpath_size_t
libpath_Internal_count_trailing_dots_directory(
    libpath_StringSlice_t const*    path
);

/*
 *
 * @param invalidRoot Pointer to a variable that receives an indication as
 *   to whether the root is invalid
 *
 * @retval LIBPATH_V_TRUEY the path is absolute, and *rootLen is the
 *   length of the root part of the path
 * @retval LIBPATH_V_FALSEY the path is not absolute
 *
 * @note On Unix, the root is always the 1-character string "/"; on Windows
 *   the root may or may not be absolute, depending on whether a volume or
 *   UNC share precedes the root character (which may be either "\" or "/")
 *
 * @note On Windows, it is possible to have a path containing a volume
 *   that is not absolute, e.g. 'C:abc', in which case the rootLen will
 *   be determined as 2 even though the return value will be false
 */
libpath_truthy_t
libpath_Internal_path_is_absolute(
    libpath_StringSlice_t const*    path
,   libpath_size_t*                 rootLen
,   libpath_truthy_t*               invalidRoot
);

libpath_truthy_t
libpath_Internal_find_next_directory_part(
    libpath_size_t*                 i
,   libpath_StringSlice_t const*    directoryPart
,   int                             flags
,   libpath_StringSlice_t*          part
,   libpath_truthy_t*               isDots
);

#ifdef LIBPATH_OS_IS_WINDOWS
/*
 *
 * @retval empty-slice A full UNC root was not present at the start of the
 *   given @c path
 * @retval non-empty-slice A full UNC root was present at the start of the
 *   given @c path, and the slice designates the UNC root part of the path
 */
libpath_StringSlice_t
libpath_Internal_find_UNC_root_slice(
    libpath_StringSlice_t const*    path
);
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

