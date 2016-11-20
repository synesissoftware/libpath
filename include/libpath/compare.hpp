
/*
 *
 * Updated: 20th November 2016
 *
 */

#include <libpath/compare.h>
#include <libpath/common/types.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * preprocessor feature control
 */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace libpath {
namespace comparing {

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

namespace ximpl_compare {

// The following are borrowed (by kind permission of me) from STLSoft

struct yes_type
{
  char ar[32];
};
struct no_type
{
  char ar[1];
};

template <int B>
struct value_to_yesno_type
{
    enum { value = 1 };

    typedef yes_type    type;
};
template <>
struct value_to_yesno_type<0>
{
    enum { value = 0 };

    typedef no_type type;
};




template <typename P>
int
handle_compare_result_(
  LIBPATH_RC  rc
, char const* lhs
, char const* rhs
, char const* cwd
, int         result
, yes_type
, ...
)
{
  return 0;
}

template <typename P>
int
handle_compare_result_(
  LIBPATH_RC  rc
, char const* lhs
, char const* rhs
, char const* cwd
, int         result
, no_type
, yes_type
, ...
)
{
  return -1;
}

template <typename P>
int
handle_compare_result_(
  LIBPATH_RC  rc
, char const* lhs
, char const* rhs
, char const* cwd
, int         result
, no_type
, no_type
, yes_type
, ...
)
{
  char const* p = NULL;

  switch(rc)
  {
    case  libpath_ResultCode_FirstPathInvalid:            p = lhs; break;
    case  libpath_ResultCode_SecondPathInvalid:           p = rhs; break;
    case  libpath_ResultCode_WorkingDirectoryPathInvalid: p = cwd; break;
  }

  if(NULL != p)
  {
    libpath_StringSlice_t path = { ::strlen(p), p };

    P::respond(rc, &path);
  }
  else
  {
    P::respond(rc, NULL);
  }

  return 0;
}

template <typename P>
int
handle_compare_result_(
  LIBPATH_RC  rc
, char const* lhs
, char const* rhs
, char const* cwd
, int         result
, no_type
, no_type
, no_type
, yes_type
)
{
  abort();

  return 0;
}

template <typename P>
int
handle_compare_result_(
  LIBPATH_RC  rc
, char const* lhs
, char const* rhs
, char const* cwd
, int         result
)
{
  typedef typename value_to_yesno_type<P::return_0>::type        return_0_type;
  typedef typename value_to_yesno_type<P::return_minus1>::type   return_minus1_type;
  typedef typename value_to_yesno_type<P::throw_exception>::type throw_exception_type;
  typedef typename value_to_yesno_type<P::invoke_abend>::type    invoke_abend_type;

  return handle_compare_result_<P>(rc, lhs, rhs, cwd, result, return_0_type(), return_minus1_type(), throw_exception_type(), invoke_abend_type());
}

template <typename P>
int
compare_paths_and_(
    char const* lhs
,   char const* rhs
,   char const* cwd = NULL
,   char const* /* mem */ = NULL
)
{
  libpath_sint32_t                  flags   =   0;
  libpath_WorkingDirectoryContext_t ctxt;
  int                               result;

  ctxt.mechanism        = libpath_WorkingDirectoryContextMechanism_CStyleString;
  ctxt.details.cwd_css  = cwd;

  LIBPATH_RC rc = libpath_Compare_ComparePathsAsCStyleStrings(
    lhs
  , rhs
  , flags
  , &ctxt
  , NULL
  , &result
  );

  if(LIBPATH_RESULTCODE(Success) != rc)
  {
    return handle_compare_result_<P>(rc, lhs, rhs, cwd, result);
  }

  return result;
}

} /* namespace ximpl_compare */




template <typename P>
int
compare_paths_and_(
    char const* lhs
,   char const* rhs
,   char const* cwd = NULL
,   char const* mem = NULL
)
{
  return ximpl_compare::compare_paths_and_<P>(lhs, rhs, cwd, mem);
}


inline
int
compare_paths(
    char const* lhs
,   char const* rhs
,   char const* cwd = NULL
,   char const* mem = NULL
);

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace comparing */
} /* namespace libpath */

/* ///////////////////////////// end of file //////////////////////////// */
