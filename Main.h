#include "CrossBufferLayer/CrossBuffer.h"


/*
** Setup Callback Function
*/

void Setup(FrameBuffer fb, Keyboard kb, int deltaTime) {
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

Color c = CreateColor(0, 144, 255);

void Update(FrameBuffer fb, Keyboard kb, int deltaTime) {
	/* Fill Yellow On The Screen */
	for (int y = 0; y < fb.Height; y++) {
		for (int x = 0; x < fb.Width; x++) {
			SetPixel(fb, x, y, c);
		}
	}

	if (kb[KEY_MOUSE_LBTN] || kb['A']) {
		SetColorR(c, GetColorR(c) + 1);
		SetColorG(c, GetColorG(c) + 1);
		SetColorB(c, GetColorB(c) + 1);
	}

	if (kb[KEY_MOUSE_RBTN] || kb['D']) {
		SetColorR(c, GetColorR(c) - 1);
		SetColorG(c, GetColorG(c) - 1);
		SetColorB(c, GetColorB(c) - 1);
	}

	CalcFPS(fb, deltaTime);
	DrawShadowString(fb, 10, 26, "Hello World!");
}
