
add_executable(test.scratch.compare.models
	test.scratch.compare.models.cpp
)

target_link_libraries(test.scratch.compare.models
	core
)

target_link_libraries(test.scratch.compare.models
	$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
)

target_compile_options(test.scratch.compare.models PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-c++11-long-long
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

