#pragma once
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
namespace sf
{
	class Window;
}

namespace Display
{
	static int WIDTH = 1280;
	static int HEIGHT = 720;

	void Initialize();
	void Close();
	void CheckForEvent();

	void Clear();
	void Update();

	bool WindowIsOpen();

	const sf::Window& GetWindow();


}
#endif // DISPLAY_H_INCLUDED