

#include <libpath/common/types.hpp>

#include <libpath/common/exceptions/invalid_path_exception.hpp>

#ifdef LIBPATH_CXX_VER_2011_plus
# include <cstdlib>
#else
# include <stdlib.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* static */
void
throw_on_invalid_path_policy::respond(
    LIBPATH_RC                      rc
,   libpath_StringSlice_t const*    path
)
{
    throw ::libpath::exceptions::invalid_path_exception(rc, path);
}

/* static */
void
abort_on_invalid_path_policy::respond(
    LIBPATH_RC                   /* rc */
,   libpath_StringSlice_t const* /* path */
)
{
    std::abort();
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */


/* ///////////////////////////// end of file //////////////////////////// */

