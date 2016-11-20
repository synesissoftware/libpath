/* /////////////////////////////////////////////////////////////////////////
 * File:        libpath/equate/types/enumerations/EquateOption.h
 *
 * Purpose:     Equate options defined for libpath library.
 *
 * Created:     9th November 2012
 * Updated:     20th November 2016
 *
 * Home:        http://synesis.com.au/software/
 *
 * Copyright (c) 2012-2016, Matthew Wilson and Synesis Software
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



#if defined(LIBPATH_DEFINING_STRING_VARIABLES)
                                                                            /* String form likely used in diagnostics, so use enumerator name (contraction) */
# define LIBPATH_DEFINE_EquateOption_(en, value, shimString, helpString)    INIT_ERR_STR_DECL(libpath_EquateOption_##en, #shimString);
# undef LIBPATH_DEFINING_STRING_VARIABLES
#elif defined(LIBPATH_DEFINING_STRING_ARRAY)
# define LIBPATH_DEFINE_EquateOption_(en, value, shimString, helpString)    INIT_ERR_STR_ENTRY(libpath_EquateOption_##en),
# undef LIBPATH_DEFINING_STRING_ARRAY
#else
# define LIBPATH_DEFINE_EquateOption_(en, value, shimString, helpString)    libpath_EquateOption_##en value /*!< helpString */,
#endif

//LIBPATH_DEFINE_EquateOption_(AssumeDirectory, = 0x0001, AssumeDirectory, causes the full path to be assumed to be a directory as if it had a trailing slash)

#undef LIBPATH_DEFINE_EquateOption_
