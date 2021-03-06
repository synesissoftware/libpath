/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/common/namespace.h
 *
 * Purpose:     Conditional discrimination and declaration for namespace for
 *              libpath library.
 *
 * Created:     20th November 2016
 * Updated:     20th November 2016
 *
 * Home:        http://synesis.com.au/software/
 *
 * Copyright (c) 2016, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_namespace
#define SYNSOFT_LIBPATH_INCL_libpath_common_H_namespace

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////////////////////////////////////////
 * feature discrimination
 */

#ifndef LIBPATH_NO_NAMESPACE
# ifndef __cplusplus
#  define LIBPATH_NO_NAMESPACE
# endif
#endif

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifndef LIBPATH_NO_NAMESPACE

# define LIBPATH_NS_QUALIFY(t)              ::libpath::t
#else
# define LIBPATH_NS_QUALIFY(t)              t
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef LIBPATH_NO_NAMESPACE
namespace libpath {

} /* namespace libpath */
#endif

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_namespace */

/* ///////////////////////////// end of file //////////////////////////// */
