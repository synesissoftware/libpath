

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define LIBPATH_COMPAREOPTION(co)                           libpath_CompareOption_##co


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** This enumeration defines flags that may be used, in combination,
 * as flags that moderate the behaviour of
 * libpath_Compare_ComparePathsAsStringSlices(),
 * libpath_Compare_ComparePathsAsStringPtrsAndLens(), and
 * libpath_Compare_ComparePathsAsCStyleStrings():
 */
enum libpath_CompareOption_t
{
#include <libpath/compare/types/enumerations/CompareOption.h>
#ifndef LIBPATH_DOCUMENTATION_SKIP_SECTION
    libpath_CompareOption_MaxValue
#endif /* !LIBPATH_DOCUMENTATION_SKIP_SECTION */
};
#ifdef __cplusplus
#else /* ? __cplusplus */
typedef enum libpath_CompareOption_t                        libpath_CompareOption_t;
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef __cplusplus

namespace LIBPATH_NS_OUTER_NAMESPACE_NAME {
namespace parsing {

typedef libpath_CompareOption_t                             CompareOption_t;

} /* namespace parsing */
} /* namespace LIBPATH_NS_OUTER_NAMESPACE_NAME */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

