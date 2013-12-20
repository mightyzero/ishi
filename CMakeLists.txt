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
# Save important directories                                                   #
#------------------------------------------------------------------------------#
set(INC_ROOT ${PROJECT_SOURCE_DIR}/src)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src)
set(LIB_ROOT ${PROJECT_SOURCE_DIR}/lib)
set(TEST_ROOT ${PROJECT_SOURCE_DIR}/test)

#------------------------------------------------------------------------------#
# List header file directories                                                 #
#------------------------------------------------------------------------------#
set(INCLUDE_DIRS
	${SRC_ROOT}
	${LIB_ROOT}/SFML/include
	${LIB_ROOT}/blitz
)

#------------------------------------------------------------------------------#
# List subdirectories                                                          #
#------------------------------------------------------------------------------#
# set(BUILD_SHARED_LIBS False)
add_subdirectory(${LIB_ROOT}/SFML)
add_subdirectory(${LIB_ROOT}/GLEW)
add_subdirectory(${LIB_ROOT}/blitz)
add_subdirectory(${SRC_ROOT})
add_subdirectory(${TEST_ROOT})
add_subdirectory(${PROJECT_SOURCE_DIR}/docs)