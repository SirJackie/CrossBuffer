#include "DeclarationParts.h"

Window::Window()
{
	screenWidth  = 0;
	screenHeight = 0;
	unit         = 0;
	windowHeight = 0;
	windowWidth  = 0;
	leftMargin   = 0;
	topMargin    = 0;
}

Window::Window(i32 ScreenWidth_, i32 ScreenHeight_)
{
	screenWidth = ScreenWidth_;
	screenHeight = ScreenHeight_;
	unit = screenHeight / 30;
	windowHeight = 26 * unit;
	windowWidth = windowHeight / 9 * 16;
	leftMargin = (screenWidth - windowWidth) / 2;
	topMargin = (screenHeight - windowHeight) / 2;
}
