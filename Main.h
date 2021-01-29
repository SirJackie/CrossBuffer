#include "./CrossBufferLayer/CrossBuffer.h"




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
	Color c = CreateColor(255, 0, 0);;

	/* Fill Yellow On The Screen */
	for (int y = 0; y < fb.Height; y++) {
		for (int x = 0; x < fb.Width; x++) {
			SetPixel(fb, x, y, c);
		}
	}
}
