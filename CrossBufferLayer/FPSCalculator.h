#ifndef __CSBF_FPSCalculator__
#define __CSBF_FPSCalculator__

#include "BasicDataTypeDeclarations.h"

/*
** FPS Calculating
*/

class FPSCalculator {
private:
	f32 FPS;
	i32 DeltaTimeCount;
	i32 FrameCount;
public:
	FPSCalculator();
	void Count(i32 deltaTime);
};

#endif
