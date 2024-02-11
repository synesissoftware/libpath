
add_executable(test.scratch.compare.models
    test.scratch.compare.models.cpp
)

target_link_libraries(test.scratch.compare.models
    libpath
)

# target_link_libraries(test.scratch.compare.models
#     xTests::xTests.core
# )

target_compile_options(test.scratch.compare.models PRIVATE
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

