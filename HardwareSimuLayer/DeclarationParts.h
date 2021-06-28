#ifndef __CSBF_HardwareSimuLayer_DeclarationParts__
#define __CSBF_HardwareSimuLayer_DeclarationParts__

#include "../CrossBufferLayer/BasicDataTypeDeclarations.h"

class Window {
public:
	int screenWidth;
	int screenHeight;
	int unit;
	int windowWidth;
	int windowHeight;
	int leftMargin;
	int topMargin;

	Window();
	Window(i32 ScreenWidth_, i32 ScreenHeight_);
};


#endif
