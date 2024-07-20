/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/compare/types/enumerations/CompareOption.h
 *
 * Purpose: Compare options defined for libpath library.
 *
 * Created: 10th February 2024
 * Updated: 11th February 2024
 *
 * Home:    https://github.com/synesissoftware/libpath
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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
                                                                            /* String form likely used in diagnostics, so use enumerator name (contraction) */
# define LIBPATH_DEFINE_CompareOption_(en, value, shimString, helpString)   LOOKUP_STR_DECL_(libpath_CompareOption_##en, #shimString);
# undef LIBPATH_DEFINING_STRING_VARIABLES
#elif defined(LIBPATH_DEFINING_STRING_ARRAY)
# define LIBPATH_DEFINE_CompareOption_(en, value, shimString, helpString)   LOOKUP_STR_ARRAY_ENTRY_(libpath_CompareOption_##en),
# undef LIBPATH_DEFINING_STRING_ARRAY
#else
# define LIBPATH_DEFINE_CompareOption_(en, value, shimString, helpString)   libpath_CompareOption_##en value /*!< helpString */,
#endif

//LIBPATH_DEFINE_CompareOption_(AssumeDirectory, = 0x0001, AssumeDirectory, causes the full path to be assumed to be a directory as if it had a trailing slash)

#undef LIBPATH_DEFINE_CompareOption_


/* ///////////////////////////// end of file //////////////////////////// */

