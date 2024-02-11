

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define LIBPATH_EQUATEOPTION(eo)                            libpath_EquateOption_##eo


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** This enumeration defines flags that may be used, in combination,
 * as flags that moderate the behaviour of
 * libpath_Equate_EquatePathsAsStringSlices(),
 * libpath_Equate_EquatePathsAsCStyleStrings(), and
 * libpath_Equate_EquatePathsAsStringPtrsAndLens():
 */
enum libpath_EquateOption_t
{
#include <libpath/equate/types/enumerations/EquateOption.h>
#ifndef LIBPATH_DOCUMENTATION_SKIP_SECTION
    libpath_EquateOption_MaxValue
#endif /* !LIBPATH_DOCUMENTATION_SKIP_SECTION */
};
#ifdef __cplusplus
#else /* ? __cplusplus */
typedef enum libpath_EquateOption_t                         libpath_EquateOption_t;
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef __cplusplus

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace parsing {

typedef libpath_EquateOption_t                              EquateOption_t;

} /* namespace parsing */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

