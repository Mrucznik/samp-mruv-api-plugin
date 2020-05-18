cmake_minimum_required(VERSION 3.0)

project(mruvapi)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")

if(UNIX)
	set(CMAKE_CXX_FLAGS "-m32 -std=c++11")
	set(CMAKE_C_FLAGS "-m32")
	set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)
endif()

if(WIN32 AND MVC)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/test/plugins")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/test/plugins")
endif()

add_definitions(-DOPENSSL_NO_ASM) # must have for compilation with -m32 flag
# gRPC
include(FetchContent)
FetchContent_Declare(
		gRPC
		GIT_REPOSITORY https://github.com/grpc/grpc
		GIT_TAG        v1.28.0
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

# removes the sprintf warnings from plugin-natives
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/test/plugins)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/lib/samp-log-core")
find_package(log-core ${LOG-CORE_VERSION} REQUIRED CONFIG)

add_subdirectory(lib/fmt)
mark_as_advanced(FMT_TEST FMT_INSTALL FMT_PEDANTIC FMT_DOC FMT_USE_CPP11 FMT_WERROR)

find_package(Boost 1.62 QUIET)
if(NOT Boost_FOUND)
	set(BOOST_ROOT "${BOOST_ROOT}" CACHE PATH "Set the Boost root folder.")
	mark_as_advanced(CLEAR BOOST_ROOT)
	message(FATAL_ERROR "Could NOT find Boost; specify additional paths.")
endif()
mark_as_advanced(BOOST_ROOT Boost_DIR)

add_subdirectory(src)
