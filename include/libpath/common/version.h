/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath/common/version.h
 *
 * Purpose: Portability discrimination for libpath library.
 *
 * Created: 9th November 2012
 * Updated: 27th July 2024
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


#ifndef SYNSOFT_LIBPATH_INCL_libpath_common_H_version
#define SYNSOFT_LIBPATH_INCL_libpath_common_H_version


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/** @def LIBPATH_MAJOR
 * The major version number of libpath
 *
 * A change to the major version component implies that a dramatic change
 * has occurred in the library, such that considerable changes to source
 * dependent on previous version(s) will need to be effected.
 */

/** @def LIBPATH_MINOR
 * The minor version number of libpath
 *
 * A change to the minor version component implies that a significant
 * addition has been added to the library, such that recompilation will be
 * necessitated, and code changes might be desired (to take advantage of the
 * new functionality).
 */

/** @def LIBPATH_VER_PATCH
 * The patch version number of libpath
 *
 * A change to the patch version component implies that a defect has been
 * fixed. Dependent code should be recompiled in order to pick up the
 * changes.
 */

/** @def LIBPATH_VER_ALPHABETA
 * The alpha-beta number of libpath
 *
 * This number indicates the alpha/beta/release-candidate nature of the
 * released version of the library.
 */

/** @def LIBPATH
 * The current composite version number of libpath
 *
 * In addition to the individual version symbols - LIBPATH_MAJOR,
 * LIBPATH_MINOR and LIBPATH_PATCH - a composite symbol
 * LIBPATH is defined, where:
 *  - bits 24-31: the major version
 *  - bits 16-23: the minor version
 *  - bits 8-15: the patch version
 *  - bits 0-7: the alpha-beta number; if not alpha/beta, it is 0xFF
 */

#define LIBPATH_VER_MAJOR               0
#define LIBPATH_VER_MINOR               2
#define LIBPATH_VER_PATCH               0
#define LIBPATH_VER_ALPHABETA           02

#define LIBPATH_VER \
    (0\
        |   (   LIBPATH_VER_MAJOR       << 24   ) \
        |   (   LIBPATH_VER_MINOR       << 16   ) \
        |   (   LIBPATH_VER_PATCH       <<  8   ) \
        |   (   LIBPATH_VER_ALPHABETA   <<  0   ) \
    )

#define LIBPATH_VER_REVISION            LIBPATH_VER_PATCH


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !SYNSOFT_LIBPATH_INCL_libpath_common_H_version */

#ifdef LIBPATH_CF_pragma_once_SUPPORTED
# pragma once
#endif

/* ///////////////////////////// end of file //////////////////////////// */

