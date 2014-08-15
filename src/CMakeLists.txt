#===============================================================================
# Project    : nFlux
# File       : src/CMakeLists.txt
# Description: CMake file for building project libraries and executables
#===============================================================================
#---------------------------------------------------------------------------#
# List include directories                                                  #
#---------------------------------------------------------------------------#
set(INCLUDE_DIRS
	${INCLUDE_DIRS}
	${SRC_ROOT}/core
)
include_directories(${INCLUDE_DIRS})

#---------------------------------------------------------------------------#
# List source files                                                         #
#---------------------------------------------------------------------------#
set(SRC_CORE
	${SRC_ROOT}/core/Point.h
	${SRC_ROOT}/core/Matrix.h
	${SRC_ROOT}/core/Vector.h
)

set(SRC_UTILITIES
	${SRC_ROOT}/utilities/File.h
)

set(SRC_MAIN
	${SRC_CORE}
	${SRC_UTILITIES}
	${SRC_ROOT}/main.cpp
)

#---------------------------------------------------------------------------#
# List build targets                                                        #
#---------------------------------------------------------------------------#
add_executable(nFlux ${SRC_MAIN})

#---------------------------------------------------------------------------#
# Link with libraries                                                       #
#---------------------------------------------------------------------------#
target_link_libraries(nFlux
	sfml-window
	tga
)
