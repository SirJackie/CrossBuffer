#include "./CrossBufferLayer/CrossBuffer.h"


/* Define Window Class Properties */
#define WindowClassName L"CrossBuffer Class"
#define WindowTitle     L"CrossBuffer <Press WASD and IJKL to move the position>"


int StartX = 10;
int StartY = 10;
//int EndX   = 15;
//int EndY   = 218;
int EndX;
int EndY;


/*
** Setup Callback Function
*/

void Setup(FrameBuffer &fb, Keyboard kb, int deltaTime) {
	EndX = fb.Width - 200;
	EndY = fb.Height - 200;

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

FPSCalculator fps;

void Update(FrameBuffer &fb, Keyboard kb, int deltaTime) {

	if (kb['A']) {
		StartX -= 3;
	}
	if (kb['D']) {
		StartX += 3;
	}
	if (kb['W']) {
		StartY -= 3;
	}
	if (kb['S']) {
		StartY += 3;
	}

	if (kb['J']) {
		EndX -= 3;
	}
	if (kb['L']) {
		EndX += 3;
	}
	if (kb['I']) {
		EndY -= 3;
	}
	if (kb['K']) {
		EndY += 3;
	}

	FrameBuffer fb2(EndX - StartX, EndY - StartY);

	/* Fill Color On The Screen */
	for (int y = 0; y < fb2.Height; y++) {
		for (int x = 0; x < fb2.Width; x++) {
			SetPixel(fb2, x, y, CreateColor(x/6, y/6, 128));
		}
	}

	//CalcFPS(fb, deltaTime);
	fb2.Draw("Hello World!\n");
	fb2.Draw("I can d");
	fb2.Draw("raw WHATEVER I");
	fb2.Draw(" want!\n");
	fb2.Draw("Third Line!\n");

	//fb2.DrawString(CreateColor(255, 255, 255), "Hello World!\n");
	//fb2.DrawString(CreateColor(255, 255, 255), "I can d");
	//fb2.DrawString(CreateColor(255, 255, 255), "raw WHATEVER I");
	//fb2.DrawString(CreateColor(255, 255, 255), " want!\n");
	//fb2.DrawString(CreateColor(255, 255, 255), "Third Line!\n");

	fps.Count(deltaTime);
	fps.ShowOnScreen(fb);
	fb.Draw(fb2, StartX, StartY);  // ok
}
