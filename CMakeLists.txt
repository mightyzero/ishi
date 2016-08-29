#==============================================================================#
# Minh Pham - Copyright 2014 - All rights reserved.
#
# Project: ishi
# Dependencies:
# - GLEW               | required by project
# - TGA library        | required by project
# - Doxygen executable | optional by project
# - OpenGL library     | required by SFML, GLEW
# - GLU library        | required by GLEW
#==============================================================================#
cmake_minimum_required(VERSION 2.8.12)

# Do not interpret strings as variables and dereference them
cmake_policy(SET CMP0054 NEW)

#-----------------#
# Project Details #
#-----------------#
project(ishi)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

#-------------------------#
# Configure Build Options #
#-------------------------#
# Build to Debug target by default
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

# Set build outputs for the generic no-config case (e.g. with mingw)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set build outputs for multi-config builds (e.g. msvc)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
	string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# Set compilation flags
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  set(DEBUG_FLAGS -g -O0 -std=c++11 -Wall -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wextra)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
  set(DEBUG_FLAGS -Zi -Od -W4 -WX)
endif()

#------------------------------------------------------------------------------#
# Configure Code Coverage Options                                              #
#------------------------------------------------------------------------------#
set(DO_COVERAGE true)

if (DO_COVERAGE)
	message(STATUS "Code coverage is enabled - adding flags")

	set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
endif (DO_COVERAGE)

#---------------#
# Build Project #
#---------------#
set(INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

set(MAIN ishi)

include_directories(${INC_DIR})

# Project source files are all cpp files under SRC_DIR.
# Note: CMake needs to be re-run when a new source file is added.
file(GLOB_RECURSE SOURCE "${SRC_DIR}/*.cpp" "${INC_DIR}/*.h")

add_library(${MAIN} ${SOURCE})

target_compile_options(${MAIN} PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_FLAGS}>")

#-------------#
# Build Tests #
#-------------#
set(EXT_PROJECTS_DIR "ext")
set(TEST_SRC_DIR ${PROJECT_SOURCE_DIR}/test)

set(TEST_MAIN ishi_test)

# Includes Catch in the project
add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${INC_DIR} ${CATCH_INCLUDE_DIR})

# Test source files are all cpp files under SRC_DIR.
# Note: CMake needs to be re-run when a new test source file is added.
file(GLOB_RECURSE TEST_SOURCE "${TEST_SRC_DIR}/*.cpp")

add_executable(${TEST_MAIN} ${SOURCE} ${TEST_SOURCE})

target_compile_options(${TEST_MAIN} PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_FLAGS}>")

enable_testing(true)  # Enables unit-testing.
add_test(unittest ${TEST_MAIN})

#------------------------#
# Generate Documentation #
#------------------------#
find_package(Doxygen)
if (DOXYGEN_FOUND)
	# Set Doxygen output to the docs dir in the build directory
	set(DOCS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)

	# Generate Doxyfile from Doxyfile.in, plugging in CMake variables
	configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
		${CMAKE_BINARY_DIR}/Doxyfile @ONLY)

	# Add the make docs target
	add_custom_target(docs
		${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src
		COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif (DOXYGEN_FOUND)
