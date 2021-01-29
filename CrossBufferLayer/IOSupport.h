#include "FrameBufferSupport.h"
#include "FontSupport.h"


void DrawChar(FrameBuffer fb, int x, int y, int color, char ch)
{
	int* bitmapPointer;
	for (int deltaY = 0; deltaY < 16; deltaY++) {
		bitmapPointer = (int*)(Font + ((int)ch * 16 * 8) + (8 * deltaY));
		if (bitmapPointer[0] == 255) { SetPixel(fb, (x + 0), (y + deltaY), color); }
		if (bitmapPointer[1] == 255) { SetPixel(fb, (x + 1), (y + deltaY), color); }
		if (bitmapPointer[2] == 255) { SetPixel(fb, (x + 2), (y + deltaY), color); }
		if (bitmapPointer[3] == 255) { SetPixel(fb, (x + 3), (y + deltaY), color); }
		if (bitmapPointer[4] == 255) { SetPixel(fb, (x + 4), (y + deltaY), color); }
		if (bitmapPointer[5] == 255) { SetPixel(fb, (x + 5), (y + deltaY), color); }
		if (bitmapPointer[6] == 255) { SetPixel(fb, (x + 6), (y + deltaY), color); }
		if (bitmapPointer[7] == 255) { SetPixel(fb, (x + 7), (y + deltaY), color); }
	}
}


void DrawString(FrameBuffer fb, int x, int y, int color, const char* stringPointer)
{
	int originX = x;
	for (; *stringPointer != 0x00; stringPointer++) {
		if (*stringPointer == '\n') {
			y += 16;
			x = originX;
			continue;
		}
		DrawChar(fb, x, y, color, *stringPointer);  // Draw This Char
		x += 8;

		if (x >= fb.Width) {
			y += 16;
			x = originX;
		}
		if (y >= fb.Height) {
			return;
		}
		
	}
	return;
}


void DrawShadowString(FrameBuffer fb, int x, int y, const char* stringPointer) {
	DrawString(fb, x,     y,     CreateColor(0,   0,   0  , 255), stringPointer);
	DrawString(fb, x + 1, y + 1, CreateColor(255, 255, 255, 255), stringPointer);
}
