#include "./CrossBufferLayer/CrossBuffer.h"
#include <vector>
#include <sstream>
using std::vector;
using std::stringstream;


/* Define Window Class Properties */
#define WindowClassName    L"CrossBuffer Class"
#define WindowTitle        L"CrossBuffer <Press WASD and IJKL to move the position>"
#define BitmapRootAddress  "..\\"


int StartX = 8;
int StartY = 30;
int EndX;
int EndY;
FrameBuffer bitmapFb;


void Setup(FrameBuffer &fb, Keyboard kb, int deltaTime) {
	;
}

int deltaColor = 0;

void Update(FrameBuffer &fb, Keyboard kb, int deltaTime) {

	if (deltaColor == 255) {
		deltaColor = 0;
	}

	for (i32 i = 0; i < fb.width * fb.height; i++) {
		fb.redBuffer[i] = deltaColor;
		fb.greenBuffer[i] = deltaColor;
		fb.blueBuffer[i] = deltaColor;
	}

	deltaColor += 1;
}
