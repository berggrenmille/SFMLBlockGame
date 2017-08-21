#include "Display.h"
int main()
{
	// create the window
	Display::Initialize();
	while (Display::WindowIsOpen())
	{
		Display::CheckForEvent();
	}
	return 0;
}