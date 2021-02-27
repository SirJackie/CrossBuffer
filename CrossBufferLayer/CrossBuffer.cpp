#include "CrossBuffer.h"
#include <stdlib.h>

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

void FrameBuffer::DrawString(Color color, const char* stringPointer)
{
	for (; *stringPointer != 0x00; stringPointer++) {

		// Before Drawing
		if (*stringPointer == '\n') {
			CurY += TEXT_HEIGHT;
			CurX =  INIT_CUR_X;
			continue;
		}

		// Drawing
		this->DrawChar(CurX, CurY, color, *stringPointer);  // Draw This Char
		CurX += TEXT_WIDTH;

		// After
		if (CurX >= this->Width) {
			CurY += TEXT_HEIGHT;
			CurX =  INIT_CUR_X;
		}
		if (CurY >= this->Height) {
			return;
		}

	}
	return;
}

void FrameBuffer::Draw(const char* stringPointer) {
	Color White = CreateColor(255, 255, 255);
	Color Black = CreateColor(  0,   0,   0);

	for (; *stringPointer != 0x00; stringPointer++) {

		// Before Drawing
		if (*stringPointer == '\n') {
			CurY += TEXT_HEIGHT;
			CurX = INIT_CUR_X;
			continue;
		}

		// Drawing
		this->DrawChar(CurX + 1, CurY + 1, Black, *stringPointer);  // Draw Black Shadow
		this->DrawChar(CurX,     CurY,     White, *stringPointer);  // Draw White Cover
		CurX += TEXT_WIDTH;

		// After
		if (CurX >= this->Width) {
			CurY += TEXT_HEIGHT;
			CurX = INIT_CUR_X;
		}
		if (CurY >= this->Height) {
			return;
		}

	}
	return;
}

//FrameBuffer::FrameBuffer() {
//	Width = 0;
//	Height = 0;
//	pBits = nullptr;
//	Pitch = 0;
//
//	CurX = INIT_CUR_X;
//	CurY = INIT_CUR_Y;
//}

FrameBuffer::FrameBuffer(int Width_, int Height_, int Pitch_, Color* pBits_) {
	Width = Width_;
	Height = Height_;

	Pitch = Pitch_;
	pBits = pBits_;

	externalBits = true;


	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH ) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT) ? INIT_CUR_Y : 0;
}

FrameBuffer::FrameBuffer(int Width_, int Height_) {
	Width = Width_;
	Height = Height_;

	Pitch = Width_;
	pBits = new Color[Pitch * Height];

	externalBits = false;

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH ) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT) ? INIT_CUR_Y : 0;
}

FrameBuffer::~FrameBuffer() {
	if (externalBits == true) {
		system("mshta javascript:alert('externalBits==true.');window.close();");
		return;
	}
	// (externalBits == false)
		delete[] pBits;
		system("mshta javascript:alert('externalBits==false.');window.close();");
	// .
}
