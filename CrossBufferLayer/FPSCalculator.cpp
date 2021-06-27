#include "FPSCalculator.h"
#include <sstream>
using std::stringstream;

FPSCalculator::FPSCalculator() {
	FPS             = 0.0f;
	DeltaTimeCount  = 0;
	FrameCount      = 0;
}

void FPSCalculator::Count(int deltaTime) {
	/* Calculate FPS */
	DeltaTimeCount += deltaTime;
	FrameCount += 1;

	if (DeltaTimeCount > 1000) {
		FPS = (float)FrameCount / ((float)DeltaTimeCount / 1000);
		DeltaTimeCount -= 1000;
		FrameCount = 0;
	}
}
