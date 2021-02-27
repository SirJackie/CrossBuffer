#include "./CrossBufferLayer/CrossBuffer.h"


/* Define Window Class Properties */
#define WindowClassName L"CrossBuffer Class"
#define WindowTitle     L"CrossBuffer <Click Mouse Buttons or A and D to swap the color>"

/*
** Setup Callback Function
*/

void Setup(FrameBuffer &fb, Keyboard kb, int deltaTime) {
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

void Update(FrameBuffer &fb, Keyboard kb, int deltaTime) {

	FrameBuffer fb2(1024, 500);

	/* Fill Color On The Screen */
	for (int y = 0; y < fb2.Height; y++) {
		for (int x = 0; x < fb2.Width; x++) {
			SetPixel(fb2, x, y, CreateColor(x, y, 128));
		}
	}

	if (kb[KEY_MOUSE_LBTN] || kb['A']) {
		SetColorR(c, (Color)(  (int)GetColorR(c) + 1  ));
		SetColorG(c, (Color)(  (int)GetColorG(c) + 1  ));
		SetColorB(c, (Color)(  (int)GetColorB(c) + 1  ));
	}

	if (kb[KEY_MOUSE_RBTN] || kb['D']) {
		SetColorR(c, (Color)(  (int)GetColorR(c) - 1)  );
		SetColorG(c, (Color)(  (int)GetColorG(c) - 1)  );
		SetColorB(c, (Color)(  (int)GetColorB(c) - 1)  );
	}

	//CalcFPS(fb, deltaTime);
	fb2.Draw("Hello World!\n");
	//fb2.Draw("I can d");
	//fb2.Draw("raw WHATEVER I");
	//fb2.Draw(" want!\n");
	//fb2.Draw("Third Line!\n");
	fb.Draw(fb2, 0, 0);  // ok
}
