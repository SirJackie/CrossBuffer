#ifndef __CSBF_HardwareSimuLayer_DeclarationParts__
#define __CSBF_HardwareSimuLayer_DeclarationParts__

#include "../CrossBufferLayer/BasicDataTypeDeclarations.h"

class Window {
public:
	int ScreenWidth;
	int ScreenHeight;
	int Unit;
	int WindowWidth;
	int WindowHeight;
	int LeftMargin;
	int TopMargin;

	Window();
	Window(i32 ScreenWidth_, i32 ScreenHeight_);
};


#endif
