
/*
 * Created: 
 * Updated: 20th November 2016
 */

#include <libpath/equate/types.h>
#include <libpath/parse/types.h>

/* /////////////////////////////////////////////////////////////////////////
 * internal API functions
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


libpath_truthy_t
libpath_Internal_part_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
);

#ifdef LIBPATH_OS_IS_WINDOWS
libpath_truthy_t
libpath_Internal_volumes_definitely_different(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
);
#endif

libpath_truthy_t
libpath_Internal_roots_definitely_different(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
);

libpath_truthy_t
libpath_Internal_roots_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
);

size_t
libpath_Internal_count_dots(
    libpath_StringSlice_t const* part
);

size_t
libpath_Internal_canonicalise_parts(
    size_t                  cdirparts
,   libpath_StringSlice_t*  dirparts
);

libpath_truthy_t
libpath_Internal_directory_whole_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
);

libpath_truthy_t
libpath_Internal_directory_whole_equal_3(
    libpath_StringSlice_t const*    abs
,   libpath_StringSlice_t const*    rel
,   libpath_StringSlice_t const*    cwd
);

libpath_truthy_t
libpath_Internal_directory_part_equal(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
);

libpath_truthy_t
libpath_Internal_directory_parts_equal(
    size_t                  cldirparts
,   libpath_StringSlice_t*  ldirparts
,   size_t                  crdirparts
,   libpath_StringSlice_t*  rdirparts
);

int
libpath_Internal_get_root_level(
    libpath_ParseResult_t const* r
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */
