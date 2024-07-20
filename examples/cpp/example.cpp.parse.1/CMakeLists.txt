
add_executable(example.cpp.parse.1
    example.cpp.parse.1.cpp
)

target_link_libraries(example.cpp.parse.1
    libpath
)

target_compile_options(example.cpp.parse.1 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:

        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:

        /WX /W4
    >
)


# ############################## end of file ############################# #

