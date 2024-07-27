
# include_directories(${CMAKE_SOURCE_DIR}/include)

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

	add_compile_options("/Zc:__cplusplus")

	# add_definitions(-D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
endif()


file(GLOB CORE_SRCS
	*.c
	*.cpp
)

add_library(core
	${CORE_SRCS}
)

# specify the primary public headers for the library, which controls whether
# they'll be installed
#
# NOTE: it is not yet known (to me, at least) how to include additional
# header files from sub-directories, so this is done below in an additional
# `install()` step
set(CORE_PUBLIC_HEADERS
	"${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h"
)

set_target_properties(core PROPERTIES
	OUTPUT_NAME "libpath.core"
	# PUBLIC_HEADER "${CORE_PUBLIC_HEADERS}"
)

target_include_directories(core PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_compile_options(core PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
		-Wno-unused-but-set-parameter
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ##########################################################
# install

install(TARGETS core
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	# PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME_LOWER}
)

# install the include/libpath/*/ subdirectories here, as do not (yet) know how to do so via PUBLIC_HEADER property
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/
	DESTINATION include/${PROJECT_NAME_LOWER}
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #

