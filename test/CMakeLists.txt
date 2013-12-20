set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS "-lgcov")

#------------------------------------------------------------------------------#
# List subdirectories with dependencies                                        #
#------------------------------------------------------------------------------#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest)

#------------------------------------------------------------------------------#
# List header file directories                                                 #
#------------------------------------------------------------------------------#
set(INCLUDE_DIRS
	${INCLUDE_DIRS}
	${TEST_ROOT}
	${TEST_ROOT}/lib/gtest/include
	${INC_ROOT}
	${LIB_ROOT}/blitz
)
include_directories(${INCLUDE_DIRS})

#------------------------------------------------------------------------------#
# List executables                                                             #
#------------------------------------------------------------------------------#
add_executable(TestAll
	${TEST_ROOT}/TestAll.cpp
	${INC_ROOT}/core/Matrix.h
	${INC_ROOT}/core/Point.h
)

#------------------------------------------------------------------------------#
# Link executables with libraries                                              #
#------------------------------------------------------------------------------#
target_link_libraries(TestAll gtest)
if (DO_COVERAGE)
	message(STATUS "Code coverage is enabled - linking to coverage library")
	target_link_libraries(TestAll gcov)
endif (DO_COVERAGE)