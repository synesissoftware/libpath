
include_directories(${CMAKE_SOURCE_DIR}/include)

if(APPLE)

	message("-- -- adding '/usr/local/include' to include-directories for 'projects'")

	include_directories("/usr/local/include")
endif(APPLE)

if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()
endif(WIN32)

if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))

	target_compile_definitions(core
		PRIVATE
			"/Zc:__cplusplus"
	)

	# add_definitions(-D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
endif()


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

