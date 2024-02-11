

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define LIBPATH_PARSEOPTION(po)                             libpath_ParseOption_##po


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** This enumeration defines flags that may be used, in combination,
 * as flags that moderate the behaviour of
 * libpath_Parse_ParsePathFromStringSlice(),
 * libpath_Parse_ParsePathFromCStyleString(), and
 * libpath_Parse_ParsePathFromStringPtrAndLen():
 */
enum libpath_ParseOption_t
{
#include <libpath/parse/types/enumerations/ParseOption.h>
#ifndef LIBPATH_DOCUMENTATION_SKIP_SECTION
    libpath_ParseOption_MaxValue
#endif /* !LIBPATH_DOCUMENTATION_SKIP_SECTION */
};
#ifdef __cplusplus
#else /* ? __cplusplus */
typedef enum libpath_ParseOption_t                          libpath_ParseOption_t;
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef __cplusplus

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace parsing {

typedef libpath_ParseOption_t                               ParseOption_t;

} /* namespace parsing */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

