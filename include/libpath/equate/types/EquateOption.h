

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define LIBPATH_EQUATEOPTION(eo)     libpath_EquateOption_##eo

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
typedef libpath_EquateOption_t          EquateOption_t;
#else /* ? __cplusplus */
typedef enum libpath_EquateOption_t     libpath_EquateOption_t;
#endif /* __cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */
