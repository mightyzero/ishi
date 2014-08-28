set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS "-lgcov")

#------------------------------------------------------------------------------#
# List subdirectories with dependencies                                        #
#------------------------------------------------------------------------------#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest)

#------------------------------------------------------------------------------#
# Include header file directories                                              # 
#------------------------------------------------------------------------------#
include_directories(
	${INC_ROOT}
	${TEST_ROOT}
	${TEST_ROOT}/lib/gtest/include
)

#------------------------------------------------------------------------------#
# List executables                                                             #
#------------------------------------------------------------------------------#
add_executable(TestAll
	${INC_ROOT}/core/Matrix.h
	${INC_ROOT}/core/Point.h
	${TEST_ROOT}/TestPoint.h
	${TEST_ROOT}/TestAll.cpp
)

#------------------------------------------------------------------------------#
# Link executables with libraries                                              #
#------------------------------------------------------------------------------#
target_link_libraries(TestAll gtest)
if (DO_COVERAGE)
	message(STATUS "Code coverage is enabled - linking to coverage library")
	target_link_libraries(TestAll gcov)
endif (DO_COVERAGE)
