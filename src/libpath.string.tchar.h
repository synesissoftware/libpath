/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath.string.tchar.h
 *
 * Purpose: Internal include file specifying character
 *          encoding-dependent mappings to standard c-style string
 *          functions.
 *
 * Created: 9th November 2012
 * Updated: 10th February 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2012-2019, Matthew Wilson and Synesis Software
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
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * includes
 */


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef LIBPATH_USE_WIDESTRINGS

# include <wchar.h>

# define  libpath_Internal_standard_string_strlen           wcslen
#else /* ? LIBPATH_USE_WIDESTRINGS */

# ifdef LIBPATH_CXX_VER_2011_plus
#  include <cstring>
# else
#  include <string.h>
# endif

# define libpath_Internal_standard_string_strlen            strlen
#endif /* LIBPATH_USE_WIDESTRINGS */


/* ////////////////////////////////////////////////////////////////////// */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

