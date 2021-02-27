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
	if (CurY + TEXT_HEIGHT > Height) {
		return;
	}

	if (CurX + TEXT_WIDTH > Width) {
		return;
	}

	for (; *stringPointer != 0x00; stringPointer++) {

		// Before Drawing
		if (*stringPointer == '\n') {
			CurY += TEXT_HEIGHT;
			CurX = InitCurX;
			continue;
		}

		// Drawing
		this->DrawChar(CurX, CurY, color, *stringPointer);  // Draw White Cover
		CurX += TEXT_WIDTH;

		// After
		if (CurX + TEXT_WIDTH >= this->Width) {
			CurY += TEXT_HEIGHT;
			CurX = InitCurX;
		}
		if (CurY >= this->Height) {
			return;
		}

	}
	return;
}

void FrameBuffer::Draw(const char* stringPointer) {

	Color White = CreateColor(255, 255, 255);
	Color Black = CreateColor(0, 0, 0);

	// Save Origin CurX and CurY
	int originCurX = CurX;
	int originCurY = CurY;

	// Draw Black Shadow
	CurX += 1;
	CurY += 1;
	this->DrawString(Black, stringPointer);

	// Draw White Cover
	CurX = originCurX;
	CurY = originCurY;
	this->DrawString(White, stringPointer);
}

FrameBuffer::FrameBuffer() {
	Width  = 0;
	Height = 0;

	Pitch  = 0;
	pBits  = nullptr;

	externalBits = false;

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH ) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT) ? INIT_CUR_Y : 0;
}

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
	for (int y = 0; y < Height - 1; y++) {
		for (int x = 0; x < Width - 1; x++) {
			SetPixel((*this), x, y, CreateColor(0, 0, 0));
		}
	}

	externalBits = false;

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH ) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT) ? INIT_CUR_Y : 0;
}

FrameBuffer::~FrameBuffer() {
	if (externalBits == true)  {
		//system("mshta javascript:alert('externalBits==true.');window.close();");
		return;
	}
	// (externalBits == false) {
		delete[] pBits;
		//system("mshta javascript:alert('externalBits==false.');window.close();");
	// }
}

void FrameBuffer::Draw(const FrameBuffer& fb, int x, int y) {

	if (x + fb.Width > this->Width) {
		system("mshta javascript:alert('notok.');window.close();");
		return;
	}

	if (y + fb.Height > this->Height) {
		system("mshta javascript:alert('notok.');window.close();");
		return;
	}

	system("mshta javascript:alert('ok.');window.close();");
}
