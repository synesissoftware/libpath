

#include <libpath/common/types.hpp>

#include <libpath/common/exceptions/invalid_path_exception.hpp>

#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace libpath {

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* static */
void
throw_on_invalid_path_policy::respond(
  LIBPATH_RC                    rc
, libpath_StringSlice_t const*  path
)
{
  throw ::libpath::exceptions::invalid_path_exception(rc, path);
}

/* static */
void
abort_on_invalid_path_policy::respond(
  LIBPATH_RC                    /* rc */
, libpath_StringSlice_t const*  /* path */
)
{
  ::abort();
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace libpath */

/* ///////////////////////////// end of file //////////////////////////// */
