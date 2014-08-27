cmake_minimum_required(VERSION 2.8)

set(DO_COVERAGE true)

#------------------------------------------------------------------------------#
# Set up project details                                                       #
#------------------------------------------------------------------------------#
project(nFlux)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

#------------------------------------------------------------------------------#
# Add library finder modules path                                              #
#------------------------------------------------------------------------------#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#------------------------------------------------------------------------------#
# Configure compiler and linker options                                        #
#------------------------------------------------------------------------------#
# Set compiler flags
if (MSVC)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "/Wall")
else (MSVC)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}
		"-g -O0 -w -std=c++11"
# 		"-g -Wall -Wextra -std=c++11"
	)
	set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG}
		"-g -O0 -w -std=c++11"
	# 	"-g -O0 -Wall -W -Wshadow -Wunused-variable -Wunused-parameter"
	# 	"-Wunused-function -Wunused -Wno-system-headers -Wno-deprecated"
	# 	"-Woverloaded-virtual -Wwrite-strings -Wextra -std=c++11"
	)
endif (MSVC)

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

if (DO_COVERAGE)
	message(STATUS "Code coverage is enabled - adding flags")
	
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS
	    "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
endif (DO_COVERAGE)

#------------------------------------------------------------------------------#
# PATHS TO IMPORTANT DIRECTORIES                                               #
#------------------------------------------------------------------------------#
# Paths to project root directories
set(INC_ROOT  ${PROJECT_SOURCE_DIR}/src)
set(SRC_ROOT  ${PROJECT_SOURCE_DIR}/src)
set(LIB_ROOT  ${PROJECT_SOURCE_DIR}/lib)
set(TEST_ROOT ${PROJECT_SOURCE_DIR}/test)

# Paths to project include directories
set(CORE_INCLUDE ${INC_ROOT}/core)

# Paths to external libraries directories
set(LIB_SFML_DIR ${LIB_ROOT}/SFML)
set(LIB_GLEW_DIR ${LIB_ROOT}/GLEW)
set(LIB_LTGA_DIR ${LIB_ROOT}/libtga)

# Paths to external libraries include directories
set(LIB_SFML_INCLUDE   ${LIB_ROOT}/SFML/include)
set(LIB_LTGA_INCLUDE   ${LIB_ROOT}/libtga/src)
set(LIB_GTEST_INCLUDE  ${TEST_ROOT}/lib/gtest/include)

#------------------------------------------------------------------------------#
# List subdirectories                                                          #
#------------------------------------------------------------------------------#
# set(BUILD_SHARED_LIBS False)
# Build external libraries
add_subdirectory(${LIB_SFML_DIR})    # Build SFML
add_subdirectory(${LIB_GLEW_DIR})    # Build GLEW
add_subdirectory(${LIB_LTGA_DIR})    # Build libTGA

# Build project
add_subdirectory(${SRC_ROOT})        # Build project source
add_subdirectory(${TEST_ROOT})       # Build project test

# Add Doxygen target
add_subdirectory(${PROJECT_SOURCE_DIR}/docs)