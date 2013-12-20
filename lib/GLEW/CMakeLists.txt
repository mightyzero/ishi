cmake_minimum_required(VERSION 2.8)

# Set project name
project(GLEW)

# Migrate config/version: Set up version number
set(GLEW_VERSION_MAJOR 1)
set(GLEW_VERSION_MINOR 9)
set(GLEW_VERSION_PATCH 0)

set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

#---------------------------------------------------------------------------#
# List header file directories                                              #
#---------------------------------------------------------------------------#
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# find external libraries
find_package(OpenGL REQUIRED)

# add include paths of external libraries
include_directories(${OPENGL_INCLUDE_DIR})

#---------------------------------------------------------------------------#
# List source files                                                         #
#---------------------------------------------------------------------------#
set(GLEW_SRC
	${INCROOT}/GL/glew.h
	${INCROOT}/GL/wglew.h
	${INCROOT}/GL/glxew.h
	${SRCROOT}/glew.c
)

set(GLEWINFO_SRC
	${INCROOT}/GL/glew.h
	${INCROOT}/GL/wglew.h
	${INCROOT}/GL/glxew.h
	${SRCROOT}/glewinfo.c
)

set(VISUALINFO_SRC
	${INCROOT}/GL/glew.h
	${INCROOT}/GL/wglew.h
	${INCROOT}/GL/glxew.h
	${SRCROOT}/visualinfo.c
)

#---------------------------------------------------------------------------#
# List build targets                                                        #
#---------------------------------------------------------------------------#
add_library(glew ${GLEW_SRC})
add_executable(glewinfo ${GLEWINFO_SRC})
add_executable(visualinfo ${VISUALINFO_SRC})

#---------------------------------------------------------------------------#
# Link with libraries                                                       #
#---------------------------------------------------------------------------#
target_link_libraries(glew X11)
target_link_libraries(glew ${OPENGL_gl_LIBRARY})
target_link_libraries(visualinfo ${OPENGL_glu_LIBRARY})

target_link_libraries(glewinfo glew)
target_link_libraries(visualinfo glew)
