set(libtga_la_SOURCES
	tga.c
	tgaread.c
	tgawrite.c
)

include_directories(.)

add_library(tga ${libtga_la_SOURCES})