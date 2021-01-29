#include "CrossBufferLayer/FrameBufferSupport.h"
#include "CrossBufferLayer/FontSupport.h"
#include "CrossBufferLayer/IOSupport.h"
#include "CrossBufferLayer/FPSCalculator.h"


/*
** Setup Callback Function
*/

void Setup(FrameBuffer fb, int deltaTime) {
	/* Fill Red On The Screen */
	for (int y = 0; y < fb.Height; y++) {
		for (int x = 0; x < fb.Width; x++) {
			SetPixel(fb, x, y, CreateColor(255, 0, 0));
		}
	}
}




/*
** Update Callback Function
*/

void Update(FrameBuffer fb, int deltaTime) {
	Color c = CreateColor(0, 0, 0);
	SetColorR(c, 1);
	SetColorG(c, 144);
	SetColorB(c, 255);

	/* Fill Yellow On The Screen */
	for (int y = 0; y < fb.Height; y++) {
		for (int x = 0; x < fb.Width; x++) {
			SetPixel(fb, x, y, c);
		}
	}

	CalcFPS(fb, deltaTime);
	DrawShadowString(fb, 10, 26, "Hello World!");
}
