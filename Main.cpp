#include "Main.h"

i32 deltaColor = 0;
i32 startX = 100, startY = 100, endX = 200, endY = 200;
i32 step;
CS_FPSCalculator fpsCalculator;
ui8 buffer[100];

void Setup (CS_FrameBuffer& fb, CS_Keyboard& kb, CS_Mouse& mouse, i32 deltaTime) {
	CS_Memset(buffer, 0, 100);
	// FILE *file = fopen("../Resources/Test.txt", "rb");
	CS_File file("../Resources/Test.txt", csReadBinary, fb);
	fread(buffer, sizeof(ui8), 6, file.file);
}

void Update(CS_FrameBuffer& fb, CS_Keyboard& kb, CS_Mouse& mouse, i32 deltaTime) {
	fpsCalculator.Count(deltaTime);
	step = (i32)(0.2f * deltaTime);

	startX = CS_iclamp(0, startX, fb.width);
	startY = CS_iclamp(0, startY, fb.height);

	endX = CS_iclamp(CS_iclamp(0, startX+100, fb.width),  endX, fb.width);
	endY = CS_iclamp(CS_iclamp(0, startY+100, fb.height), endY, fb.height);

	if (deltaColor == 255) {
		deltaColor = 0;
	}

	for (i32 y = startY; y < endY; y++) {
		for (i32 x = startX; x < endX; x++) {
			fb.redBuffer[y * fb.width + x] = 255 - deltaColor;
			fb.greenBuffer[y * fb.width + x] = deltaColor;
			fb.blueBuffer[y * fb.width + x] = deltaColor;
		}
	}

	fb.DrawString("Alphabet", startX + 11, startY + 11, 0, 0, 0);
	fb.DrawString("Alphabet", startX + 10, startY + 10, 255, 255, 255);

	string ts = "C++ String Test!";
	i32 ti32 = 32;
	i16 ti16 = 16;

	fb.PrintLn(fpsCalculator.ToString());
	fb.PrintLn(mouse.ToString());
	fb.PrintLn(kb.ToString());

	for(i32 i = 0; i < 6; i++){
		fb.PrintLn((i32)buffer[i]);
	}

	deltaColor += 1;

	if (kb.IsKeyPressed('W')) startY -= step;
	if (kb.IsKeyPressed('S')) startY += step;
	if (kb.IsKeyPressed('A')) startX -= step;
	if (kb.IsKeyPressed('D')) startX += step;

	if (kb.IsKeyPressed('I')) endY -= step;
	if (kb.IsKeyPressed('K')) endY += step;
	if (kb.IsKeyPressed('J')) endX -= step;
	if (kb.IsKeyPressed('L')) endX += step;

	if (kb.IsKeyFirstTimePressed('Z')) {
		if (mouse.IsInfinityModeOpened() == csFalse) {
			mouse.OpenInfinityMode();
		}
		else {
			mouse.CloseInfinityMode();
		}
	}
}
