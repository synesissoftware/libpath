
add_executable(test.unit.version
    test.unit.version.c
)

target_link_libraries(test.unit.version
    libpath
)

target_link_libraries(test.unit.version
    xTests::xTests.core
)

target_compile_options(test.unit.version PRIVATE
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

