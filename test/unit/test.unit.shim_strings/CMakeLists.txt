
add_executable(test.unit.shim_strings
    test.unit.shim_strings.cpp
)

target_link_libraries(test.unit.shim_strings
    libpath
)

target_link_libraries(test.unit.shim_strings
    xTests::xTests.core
)

target_compile_options(test.unit.shim_strings PRIVATE
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

