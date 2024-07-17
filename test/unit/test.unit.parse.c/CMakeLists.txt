
add_executable(test.unit.parse.c
    test.unit.parse.c.c
)

target_link_libraries(test.unit.parse.c
    libpath
)

target_link_libraries(test.unit.parse.c
    xTests::core
)

target_compile_options(test.unit.parse.c PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-unused-parameter
        -Wno-unused-variable
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

