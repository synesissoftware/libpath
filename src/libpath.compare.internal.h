
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

int
libpath_Internal_compare_roots(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   int                             flags
);

int
libpath_Internal_compare_path_fragment(
    libpath_StringSlice_t const*    lhs
,   libpath_StringSlice_t const*    rhs
,   int                             flags
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */
