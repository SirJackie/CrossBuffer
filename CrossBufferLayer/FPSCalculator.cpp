#include "FPSCalculator.h"

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

void FPSCalculator::ShowOnScreen(FrameBuffer& fb) {
	//string str;
	//str += "FPS: ";
	////str += FPS;
	//str += "; Width: ";
	//str += fb.Width;
	//str += "; Height: ";
	//str += fb.Height;
	//str += "; Pitch: ";
	//str += fb.Pitch;
	//str += "; pBits: ";
	//str += (int)fb.pBits;
	//str += "\n";

	//fb.Draw(str.c_str());
}
