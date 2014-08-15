#===============================================================================
# Project    : nFlux
# File       : docs/CMakeLists.txt
# Description: CMake file for building documentation using Doxygen
#===============================================================================
# Add Doxygen target
find_package(Doxygen)
if (DOXYGEN_FOUND)
	# Set Doxygen output to the docs dir in the build directory
	set(DOCS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
	
	# Generate Doxyfile from Doxyfile.in, plugging in CMake variables
	configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
		${CMAKE_BINARY_DIR}/Doxyfile @ONLY
	)
	
	# Add the docs target
	add_custom_target(docs
		${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src
		COMMENT "Generating API documentation with Doxygen" VERBATIM
	)
endif (DOXYGEN_FOUND)