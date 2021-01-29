#include "./CrossBufferLayer/CrossBuffer.h"



/*
** Setup Callback Function
*/

void Setup(FrameBuffer fb, int width, int height, int deltaTime) {
	/* Fill Red On The Screen */
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			SetPixel(fb, x, y, CreateColor(255, 0, 0));
		}
	}
}



/*
** Update Callback Function
*/

void Update(FrameBuffer fb, int width, int height, int deltaTime) {
	/* Fill Yellow On The Screen */
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			SetPixel(fb, x, y, CreateColor(255, 255, 0));
		}
	}
}
