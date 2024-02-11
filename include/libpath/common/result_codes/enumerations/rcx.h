/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/result_codes/enumerations/rcx.h
 *
 * Purpose: Extended result codes defined for libpath library.
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


#if 0
#elif defined(LIBPATH_DEFINING_STRING_VARIABLES)
# define LIBPATH_DEFINE_ResultCodeX_(en, value, shimString, helpString)         LOOKUP_STR_DECL_(libpath_ResultCodeX_##en, #helpString);
# undef LIBPATH_DEFINING_STRING_VARIABLES

#elif defined(LIBPATH_DEFINING_STRING_ARRAY)

# define LIBPATH_DEFINE_ResultCodeX_(en, value, shimString, helpString)         LOOKUP_STR_ARRAY_ENTRY_(libpath_ResultCodeX_##en),
# undef LIBPATH_DEFINING_STRING_ARRAY

#else

# define LIBPATH_DEFINE_ResultCodeX_(en, value, shimString, helpString)         libpath_ResultCodeX_##en value /*!< helpString */,

#endif

#if !defined(LIBPATH_DEFINING_STRING_VARIABLES) && !defined(LIBPATH_DEFINING_STRING_ARRAY)
LIBPATH_DEFINE_ResultCodeX_(INVALID, =-1000000, INVALID, INVALID)
#endif

LIBPATH_DEFINE_ResultCodeX_(Success, =0, Success, operation completed successfully)

#undef LIBPATH_DEFINE_ResultCodeX_


/* ///////////////////////////// end of file //////////////////////////// */

