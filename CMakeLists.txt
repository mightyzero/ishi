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

#-----------------#
# Project Details #
#-----------------#
project(ishi)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

#-----------------------------#
# Compiler and Linker Options #
#-----------------------------#
# Set compiler flags
if (${MSVC})
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "/Wall")
else()
	add_compile_options(-g -O0 -std=c++11
		-Wall -W -Wunused-variable -Wunused-parameter
	 	-Wunused-function -Wunused -Wno-system-headers -Wno-deprecated
	 	-Woverloaded-virtual -Wwrite-strings -Wextra)
endif()

#---------------#
# Build Outputs #
#---------------#
# First for the generic no-config case (e.g. with mingw)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Second, for multi-config builds (e.g. msvc)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
	string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

#------------------------------------------------------------------------------#
# Configure Code Coverage Options                                              #
#------------------------------------------------------------------------------#
set(DO_COVERAGE true)

if (DO_COVERAGE)
	message(STATUS "Code coverage is enabled - adding flags")

	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS
	    "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
endif (DO_COVERAGE)

#--------------------------------#
# Paths to Important Directories #
#--------------------------------#
set(INC_DIR  ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR  ${PROJECT_SOURCE_DIR}/src)
set(LIB_DIR  ${PROJECT_SOURCE_DIR}/lib)

set(TEST_DIR     ${PROJECT_SOURCE_DIR}/test)
set(TEST_LIB_DIR ${TEST_DIR}/lib)
set(TEST_SRC_DIR ${TEST_DIR}/src)

#--------------------#
# Build Dependencies #
#--------------------#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# set(BUILD_SHARED_LIBS False)

add_subdirectory(${LIB_DIR}/GLEW)      # Build GLEW
add_subdirectory(${LIB_DIR}/libtga)    # Build libTGA

#---------------------------#
# List Project Source Files #
#---------------------------#
set(SOURCES
	${SRC_DIR}/main.cpp)

#---------------#
# Build Project #
#---------------#
set(EXEC ishi)

include_directories(
	${INC_DIR}
	${LIB_DIR}/eigen
)
add_executable(${EXEC} ${SOURCES})
target_link_libraries(${EXEC} tga)

#------------------------#
# List Test Source Files #
#------------------------#
set(TEST_SOURCE
	${TEST_SRC_DIR}/main.cpp)

#-------------#
# Build Tests #
#-------------#
set(TEST_EXEC ishi_test)

include_directories(
	${INC_DIR}
	${TEST_DIR}/include
	${TEST_LIB_DIR}/gtest/include)
add_subdirectory(${TEST_LIB_DIR}/gtest)
add_executable(${TEST_EXEC} ${SOURCE} ${TEST_SOURCE})
target_link_libraries(${TEST_EXEC} gtest)

enable_testing()
add_test(unittest ${TEST_EXEC})

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
