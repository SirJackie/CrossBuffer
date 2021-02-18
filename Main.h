#include "./CrossBufferLayer/CrossBuffer.h"


/* Define Window Class Properties */
#define WindowClassName L"CrossBuffer Class"
#define WindowTitle     L"CrossBuffer <Click Mouse Buttons or A and D to swap the color>"

/*
** Setup Callback Function
*/

void Setup(FrameBuffer fb, Keyboard kb, int deltaTime) {
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

void Update(FrameBuffer fb, Keyboard kb, int deltaTime) {
	/* Fill Yellow On The Screen */
	for (int y = 0; y < fb.Height; y++) {
		for (int x = 0; x < fb.Width; x++) {
			SetPixel(fb, x, y, c);
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
	fb.Draw("Hello World!\n");
}
