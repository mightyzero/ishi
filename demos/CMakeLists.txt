#===============================================================================
# Project    : nFlux
# File       : demos/CMakeLists.txt
# Description: CMake file for building mini-applications for demonstrations
#===============================================================================
include_directories(${INCLUDE_DIRS})

add_executable(FileDemo
	${INC_ROOT}/utilities/File.h
	${TEST_ROOT}/FileDemo.cpp
)

# Configure the SFML library
# Build static library (shared libraries can cause problems with symlinks)
target_link_libraries(FileDemo sfml-window)
