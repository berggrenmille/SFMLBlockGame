#include "Headers/Display.h"
int main()
{
	// create the window
	Display::Initialize();
	while (Display::WindowIsOpen())
	{
		Display::CheckForEvent();
		Display::Update();
	}
	return 0;
}