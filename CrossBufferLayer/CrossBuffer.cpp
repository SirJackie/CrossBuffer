#include "CrossBuffer.h"
#include <stdlib.h>


FrameBuffer::FrameBuffer() {
	Width  = 1;
	Height = 1;

	Pitch  = Width;
	pBits  = new Color[Pitch * Height];

	externalBits = false;

	// Clear the buffer
	SetPixel((*this), 0, 0, CreateColor(0, 0, 0));

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH ) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT) ? INIT_CUR_Y : 0;
}

FrameBuffer::FrameBuffer(int Width_, int Height_, int Pitch_, Color* pBits_) {
	Width   = Width_  > 1 ? Width_  : 1;
	Height  = Height_ > 1 ? Height_ : 1;

	Pitch   = Pitch_;
	pBits   = pBits_;

	externalBits = true;

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH ) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT) ? INIT_CUR_Y : 0;
}

FrameBuffer::FrameBuffer(int Width_, int Height_) {
	Width   = Width_  > 1 ? Width_  : 1;
	Height  = Height_ > 1 ? Height_ : 1;

	Pitch   = Width;
	pBits   = new Color[Pitch * Height];

	externalBits = false;

	// Clear the buffer
	for (int y = 0; y < Height - 1; y++) {
		for (int x = 0; x < Width - 1; x++) {
			SetPixel((*this), x, y, CreateColor(0, 0, 0));
		}
	}

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH * 10) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT * 5) ? INIT_CUR_Y : 0;
}

FrameBuffer::FrameBuffer(const FrameBuffer& fb) {
	Width   = fb.Width;
	Height  = fb.Height;

	Pitch   = Width;
	pBits   = new Color[Pitch * Height];

	externalBits = false;

	// Clear the buffer
	for (int y = 0; y < Height - 1; y++) {
		for (int x = 0; x < Width - 1; x++) {
			SetPixel(
				(*this),
				x,
				y,
				GetPixel(fb, x, y)
			);
		}
	}

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH * 10) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT * 5) ? INIT_CUR_Y : 0;
}

FrameBuffer& FrameBuffer::operator=(const FrameBuffer& fb) {
	Width   = fb.Width;
	Height  = fb.Height;

	if (externalBits == true) {
		;  // Do Nothing
	}
	else {
		delete[] pBits;  // Release the buffer
	}

	Pitch   = Width;
	pBits   = new Color[Pitch * Height];

	externalBits = false;

	// Clear the buffer
	for (int y = 0; y < Height - 1; y++) {
		for (int x = 0; x < Width - 1; x++) {
			SetPixel(
				(*this),
				x,
				y,
				GetPixel(fb, x, y)
			);
		}
	}

	InitCurX = CurX = INIT_CUR_X < (Width  - TEXT_WIDTH * 10) ? INIT_CUR_X : 0;
	InitCurY = CurY = INIT_CUR_Y < (Height - TEXT_HEIGHT * 5) ? INIT_CUR_Y : 0;

	return (*this);
}

FrameBuffer::~FrameBuffer() {
	if (externalBits == true)  {
		// externalBits == true
		// system("mshta javascript:alert('externalBits==true.');window.close();");
		;  // Do Nothing
	}
	else {
		// externalBits == false
		// system("mshta javascript:alert('externalBits==false.');window.close();");
		delete[] pBits;  // Release the buffer
	}
}

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
			CurX = InitCurX;
			continue;
		}

		// Drawing
		this->DrawChar(CurX, CurY, color, *stringPointer);  // Draw White Cover
		CurX += TEXT_WIDTH;

		// After

		if (CurY + TEXT_HEIGHT > Height) {
			return;
		}

		if (CurX + TEXT_WIDTH > Width) {
			CurY += TEXT_HEIGHT;
			CurX = InitCurX;
		}
	}
	return;
}

void FrameBuffer::Draw(const char* stringPointer) {

	Color White = CreateColor(255, 255, 255);
	Color Black = CreateColor(0, 0, 0);

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
		int CurXMinusOne = CurX - 1;
		int CurYMinusOne = CurY - 1;
		int TmpX = CurXMinusOne > 0 ? CurXMinusOne : 0;
		int TmpY = CurYMinusOne > 0 ? CurYMinusOne : 0;

		this->DrawChar(CurX, CurY, Black, *stringPointer);  // Draw Black Shadow
		this->DrawChar(TmpX, TmpY, White, *stringPointer);  // Draw White Cover

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

void FrameBuffer::Draw(const FrameBuffer& fb, int PositionX, int PositionY) {

	if (PositionX + fb.Width > this->Width) {
		//system("mshta javascript:alert('notok.');window.close();");
		return;
	}

	if (PositionY + fb.Height > this->Height) {
		//system("mshta javascript:alert('notok.');window.close();");
		return;
	}

	//system("mshta javascript:alert('ok.');window.close();");

	for (int y = 0; y < fb.Height; y++) {
		for (int x = 0; x < fb.Width; x++) {
			SetPixel(
				(*this),
				x + PositionX,
				y + PositionY,
				GetPixel(fb, x, y)
			);
			/*int tmpx;
			int tmpy;
			SetPixel((*this), x + PositionX, y + PositionY, CreateColor(255, 255, 255));*/
		}
	}
}
