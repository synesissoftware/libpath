/* /////////////////////////////////////////////////////////////////////////
 * File:    libpath.rc_strings.c
 *
 * Purpose: Strings defined associated with `rc` type.
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



/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <libpath/common/macros.h>
#include <libpath/common/types.h>


        #define LIBPATH_LITERAL_STRING(s)       s


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define LOOKUP_STR_DECL_(rc, desc)                              \
                                                                \
    static const libpath_char_t         s_str##rc[] =   desc;   \
    static const struct LookupString    s_rct##rc = { rc, s_str##rc, LIBPATH_NUM_ELEMENTS(s_str##rc) - 1 }


#define LOOKUP_STR_ARRAY_ENTRY_(rc) \
                                    \
    &s_rct##rc


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct LookupString
{
    int                     code;       /*!< The code. */
    libpath_char_t const*   str;        /*!< The string.        */
    libpath_size_t          len;        /*!< The string length. */
};


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

static
libpath_char_t const*
libpath_lookup_ResultCode_4_(
    int                         code
,   struct LookupString const** mappings
,   size_t                      cMappings
,   size_t*                     len
)
{
    /* Use Null Object (Variable) here for len, so do not need to check
     * elsewhere.
     */
    size_t  len_;

    if (NULL == len)
    {
        len = &len_;
    }

#if 0
    /*
     * TODO: work out whether can do indexed guessing
     */

#endif

    /* Linear search. Should only be needed if order in
     * pantheios_LookupLookupStringA_() messed up.
     */
    { libpath_size_t i; for (i = 0; i < cMappings; ++i)
    {
        if (code == mappings[i]->code)
        {
            return (*len = mappings[i]->len, mappings[i]->str);
        }
    }}

    return (*len = 0, LIBPATH_LITERAL_STRING(""));
}

/* /////////////////////////////////////////////////////////////////////////
 * type-specific helper functions
 */

static libpath_char_t const*
libpath_lookup_rc_2_(
    int             code
,   libpath_size_t* len
)
{
#define LIBPATH_DEFINING_STRING_VARIABLES
#include <libpath/common/result_codes/enumerations/rc.h>

    static struct LookupString const* s_strings[] =
    {
#define LIBPATH_DEFINING_STRING_ARRAY
#include <libpath/common/result_codes/enumerations/rc.h>

    };

    return libpath_lookup_ResultCode_4_(code, s_strings, LIBPATH_NUM_ELEMENTS(s_strings), len);
}

static libpath_char_t const*
libpath_lookup_rcx_2_(
    int             code
,   libpath_size_t* len
)
{
#define LIBPATH_DEFINING_STRING_VARIABLES
#include <libpath/common/result_codes/enumerations/rcx.h>

    static struct LookupString const* s_strings[] =
    {
#define LIBPATH_DEFINING_STRING_ARRAY
#include <libpath/common/result_codes/enumerations/rcx.h>

    };

    return libpath_lookup_ResultCode_4_(code, s_strings, LIBPATH_NUM_ELEMENTS(s_strings), len);
}


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

LIBPATH_CALL(libpath_char_t const*)
libpath_rc_getStringPtr(
    LIBPATH_RC  rc
)
{
    return libpath_lookup_rc_2_((int)rc, NULL);
}

LIBPATH_CALL(libpath_size_t)
libpath_rc_getStringLen(
    LIBPATH_RC  rc
)
{
    libpath_size_t len;

    return (libpath_lookup_rc_2_((int)rc, &len), len);
}

LIBPATH_CALL(libpath_char_t const*)
libpath_rcx_getStringPtr(
    LIBPATH_RCX rcx
)
{
    return libpath_lookup_rcx_2_((int)rcx, NULL);
}

LIBPATH_CALL(libpath_size_t)
libpath_rcx_getStringLen(
    LIBPATH_RCX rcx
)
{
    libpath_size_t len;

    return (libpath_lookup_rcx_2_((int)rcx, &len), len);
}


/* ///////////////////////////// end of file //////////////////////////// */

