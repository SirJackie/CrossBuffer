#ifndef __CSBF_HardwareSimuLayer_DeclarationParts__
#define __CSBF_HardwareSimuLayer_DeclarationParts__

#include "../CrossBufferLayer/BasicDataTypeDeclarations.h"


class Window {
public:
	i32 screenWidth;
	i32 screenHeight;
	i32 unit;
	i32 windowWidth;
	i32 windowHeight;
	i32 leftMargin;
	i32 topMargin;

	Window();
	Window(i32 ScreenWidth_, i32 ScreenHeight_);
};

#endif
