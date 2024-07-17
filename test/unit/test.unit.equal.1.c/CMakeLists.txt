
add_executable(test.unit.equal.1.c
    test.unit.equal.1.c.c
)

target_link_libraries(test.unit.equal.1.c
    libpath
)

target_link_libraries(test.unit.equal.1.c
    xTests::core
)

target_compile_options(test.unit.equal.1.c PRIVATE
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

