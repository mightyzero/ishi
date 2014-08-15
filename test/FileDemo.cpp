/*******************************************************************************
* Project    : nFlux
*
* File       : FileDemo.cpp
* 
* Description: Demonstrate the file utility class. Given an image file path,
*              parse an image file and display it using OpenGL.
* 
* Input      : Image file path
* 
* Output     : The image
*******************************************************************************/
#include <iostream>

#include <SFML/Window.hpp>   // SFML Window module to open display window
#include <SFML/OpenGL.hpp>   // SFML Cross-platform OpenGL header

#include <utilities/File.h>  // File utility class for demo

int main(int argc, char** argv)
{
	// Create a dislay window
	sf::Window window(sf::VideoMode(800, 600), "File Demo");
	while (window.isOpen())
	{
		sf::Event event;

		// Check all window's event triggered since last iteration
		while (window.pollEvent(event))
		{
			// If close window (X) is hit: close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw image

		// End current frame (Swap front and back buffers)
		window.display();
	}

	return 0;
}