#include "../Headers/Display.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
	std::unique_ptr<sf::RenderWindow> window; //pointer to main window
	sf::ContextSettings windowSettings;

	void Initialize() //init the render window
	{
		windowSettings.depthBits = 24;
		windowSettings.majorVersion = 4;
		windowSettings.minorVersion = 5; //OpenGl v4.5
		windowSettings.antialiasingLevel = 8;
		
	
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT)
													, "Meinkraft"
													, sf::Style::Close | sf::Style::Resize
													, windowSettings);
		glewInit();
		glViewport(0, 0, WIDTH, HEIGHT);
		glEnable(GL_DEPTH_TEST);

		//Set Window parameters (Limit framerate, fullscreen, etc)
		window->setFramerateLimit(400);
		window->setMouseCursorVisible(false);
	}

	void Close() //closes the window
	{
		window->close(); 
	}

	void CheckForEvent() //Check for window events
	{
		sf::Event e;
		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Close();
			}
			
			if(e.type == sf::Event::Resized)
			{
				printf("New window width: %i\nNew window heigth: %i\n", e.size.width, e.size.height);
			}
		}
	}

	void Clear() //clears the renderbuffer
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void Update()
	{
		window->display();
	}

	bool WindowIsOpen()
	{
		return window->isOpen();
	}

	const sf::Window& GetWindow() //returns an unchangeable window
	{
		return *window;
	}
}
