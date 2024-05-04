

include_directories(${CMAKE_SOURCE_DIR}/include)

if (APPLE)

	message("-- -- adding '/usr/local/include' to include-directories for 'projects'")

	include_directories("/usr/local/include")
endif()


if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)

	# if (NOT NDEBUG)
endif(UNIX)

if(WIN32)

	message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)



file(GLOB UTIL_SRCS
	*.c
	*.cpp
)

add_library(libpath ${UTIL_SRCS})

target_compile_options(libpath PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
		-Wno-unused-but-set-parameter
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS libpath)


# ############################## end of file ############################# #

