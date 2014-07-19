#------------------------------------------------------------------------------#
# Set up project details                                                       #
#------------------------------------------------------------------------------#
project(libtga)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

#------------------------------------------------------------------------------#
# List subdirectories                                                          #
#------------------------------------------------------------------------------#
add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(doc)
