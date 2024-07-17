
add_executable(test.unit.equal.1
    test.unit.equal.1.cpp
)

target_link_libraries(test.unit.equal.1
    libpath
)

target_link_libraries(test.unit.equal.1
    xTests::core
)

target_compile_options(test.unit.equal.1 PRIVATE
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

