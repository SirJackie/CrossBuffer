#include "CrossBuffer.h"

void FrameBuffer::DrawChar(int x, int y, Color color, char ch)
{
	int* bitmapPointer;
	for (int deltaY = 0; deltaY < 16; deltaY++) {
		bitmapPointer = (int*)(Font + ((int)ch * 16 * 8) + (8 * deltaY));
		if (bitmapPointer[0] == 255) { SetPixel((*this), (x + 0), (y + deltaY), color); }
		if (bitmapPointer[1] == 255) { SetPixel((*this), (x + 1), (y + deltaY), color); }
		if (bitmapPointer[2] == 255) { SetPixel((*this), (x + 2), (y + deltaY), color); }
		if (bitmapPointer[3] == 255) { SetPixel((*this), (x + 3), (y + deltaY), color); }
		if (bitmapPointer[4] == 255) { SetPixel((*this), (x + 4), (y + deltaY), color); }
		if (bitmapPointer[5] == 255) { SetPixel((*this), (x + 5), (y + deltaY), color); }
		if (bitmapPointer[6] == 255) { SetPixel((*this), (x + 6), (y + deltaY), color); }
		if (bitmapPointer[7] == 255) { SetPixel((*this), (x + 7), (y + deltaY), color); }
	}
}

void FrameBuffer::DrawString(int x, int y, Color color, const char* stringPointer)
{
	int originX = x;
	for (; *stringPointer != 0x00; stringPointer++) {
		if (*stringPointer == '\n') {
			y += 16;
			x = originX;
			continue;
		}
		this->DrawChar(x, y, color, *stringPointer);  // Draw This Char
		x += 8;

		if (x >= this->Width) {
			y += 16;
			x = originX;
		}
		if (y >= this->Height) {
			return;
		}

	}
	return;
}


void FrameBuffer::DrawShadowString(int x, int y, const char* stringPointer) {
	this->DrawString(x,     y,     CreateColor(0, 0, 0),       stringPointer);
	this->DrawString(x + 1, y + 1, CreateColor(255, 255, 255), stringPointer);
}
