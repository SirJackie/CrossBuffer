#include "DeclarationParts.h"

Window::Window()
{
}

Window::Window(i32 ScreenWidth_, i32 ScreenHeight_)
{
	Window& win = *this;
	win.ScreenWidth = ScreenWidth_;
	win.ScreenHeight = ScreenHeight_;
	win.Unit = win.ScreenHeight / 30;
	win.WindowHeight = 26 * win.Unit;
	win.WindowWidth = win.WindowHeight / 9 * 16;
	win.LeftMargin = (win.ScreenWidth - win.WindowWidth) / 2;
	win.TopMargin = (win.ScreenHeight - win.WindowHeight) / 2;
}
