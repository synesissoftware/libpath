
#include <libpath/parse.hpp>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static
int
on_invalid_arguments(
    FILE*       stm
,   char const* message
,   char const* program_name
);

static
int
parse_and_display_results(
    FILE*       stm_out
,   FILE*       stm_cr
,   char const* path
,   char const* program_name
);

static
int
show_usage(
    FILE*       stm
,   char const* program_name
);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    char const* const program_name = argv[0];

    switch (argc)
    {
    case 1:
    case 0:

        return on_invalid_arguments(stderr, "path not specified", program_name);
    case 2:
        if (0 == ::strcmp("--help", argv[1]))
        {
            return show_usage(stdout, program_name);
        }
        else
        {
            char const* const path_to_parse = argv[1];

            return parse_and_display_results(stdout, stderr, path_to_parse, program_name);
        }
    default:

        return on_invalid_arguments(stderr, "too many arguments", program_name);
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementations
 */

static
int
on_invalid_arguments(
    FILE*       stm
,   char const* message
,   char const* program_name
)
{
  fprintf(
    stm
  , "%s: %s: use --help for usage\n"
  , program_name
  , message
  );

  return EXIT_FAILURE;
}

static
int
parse_and_display_results(
    FILE*       stm_out
,   FILE*       stm_cr
,   char const* path
,   char const* program_name
)
{
    using libpath::StringSlice_t;
    using namespace libpath::parsing;
    // using libpath::parsing::ParseResult_t;

    assert(NULL != stm_out);
    assert(NULL != stm_cr);
    assert(NULL != path);

    static char const   blanks[] = "                                                                                                                                                                                                                                                                                            ";

    int const           flags   =   0
                                ;
    ParseResult_t       result;
    StringSlice_t       directoryPartSlices[20]; // WARNING: magic number!
    libpath_size_t      numDirectoryPartSlices = sizeof(directoryPartSlices) / sizeof(0[directoryPartSlices]);
    LIBPATH_RC const    rc      =   parse_path_from_cstyle_string(
                                        path
                                    ,   flags
                                    ,   &result
                                    ,   numDirectoryPartSlices
                                    ,   &directoryPartSlices[0]
                                    );
    int                 dp_width;

    if (LIBPATH_RC_SUCCESS(rc))
    {
        fprintf(
            stm_out
        ,   "results of parsing '%s':\n"
            "\tinput:                \t%.*s'%.*s'\n"
            "\tpath:                 \t%.*s'%.*s'\n"
            "\tlocationPart:         \t%.*s'%.*s'\n"
#ifdef LIBPATH_OS_IS_WINDOWS
            "\tvolumePart:           \t%.*s'%.*s'\n"
#endif /* LIBPATH_OS_IS_WINDOWS */
            "\trootPart:             \t%.*s'%.*s'\n"
            "\tdirectoryPart:        \t%.*s'%.*s'\n"
            "\tentryPart:            \t%.*s'%.*s'\n"
            "\tentryStemPart:        \t%.*s'%.*s'\n"
            "\tentryExtensionPart:   \t%.*s'%.*s'\n"
            "\tnumDotsDirectoryParts:\t%lu:\n"
            "\tnumDirectoryParts:    \t%lu:\n"
        ,   path
        ,   0, "", int(result.input.len), result.input.ptr
        ,   0, "", int(result.path.len), result.path.ptr
        ,   0, "", int(result.locationPart.len), result.locationPart.ptr
#ifdef LIBPATH_OS_IS_WINDOWS
        ,   0, "", int(result.volumePart.len), result.volumePart.ptr
#endif /* LIBPATH_OS_IS_WINDOWS */
        ,   0, "", int(result.rootPart.len), result.rootPart.ptr
        ,   int(result.rootPart.len), blanks, int(result.directoryPart.len), result.directoryPart.ptr
        ,   int(result.rootPart.len + result.directoryPart.len), blanks, int(result.entryPart.len), result.entryPart.ptr
        ,   int(result.rootPart.len + result.directoryPart.len), blanks, int(result.entryStemPart.len), result.entryStemPart.ptr
        ,   int(result.rootPart.len + result.directoryPart.len + result.entryStemPart.len), blanks, int(result.entryExtensionPart.len), result.entryExtensionPart.ptr
        ,   result.numDotsDirectoryParts
        ,   result.numDirectoryParts
        );
        fprintf(
            stm_out
        ,   "\tdirectoryParts:\n"
        );
        dp_width = int(result.rootPart.len);
        for (size_t i = 0; i != result.numDirectoryParts; ++i)
        {
            StringSlice_t const& directoryPart = directoryPartSlices[i];

            fprintf(
                stm_out
            ,   "\t                      \t%.*s'%.*s'\n"
            ,   dp_width, blanks
            ,   int(directoryPart.len), directoryPart.ptr
            );

            dp_width += int(directoryPart.len);
        }

        return EXIT_SUCCESS;
    }
    else
    {
        fprintf(
            stm_cr
        ,   "%s: failed to parse '%s', at offset %lu: %.*s\n"
        ,   program_name
        ,   path
        ,   result.firstBadCharOffset
        ,   int(libpath_rc_getStringLen(rc)), libpath_rc_getStringPtr(rc)
        );

        return EXIT_FAILURE;
    }
}

static
int
show_usage(
    FILE*       stm
,   char const* program_name
)
{
  fprintf(
    stm
  , "USAGE: %s <path>\n"
  , program_name
  );

  return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

