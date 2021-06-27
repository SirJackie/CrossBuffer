#ifndef __CSBF_FPSCalculator__
#define __CSBF_FPSCalculator__

/*
** FPS Calculating
*/

class FPSCalculator {
private:
	float FPS;
	int   DeltaTimeCount;
	int   FrameCount;
public:
	FPSCalculator();
	void Count(int deltaTime);
};

#endif
