#include "Main.h"

i32 deltaColor = 0;
i32 startX = 100, startY = 100, endX = 200, endY = 200;
f32 step = 0.2f;

void Setup(CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime) {
	;
}

void Update(CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime) {

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

	fb.Print("KeyboardStatus: {");
	for (i32 i = 0; i < 128; i++) {
		if (kb.IsKeyPressed(i)) {
			fb.Print(i);
			fb.Print(", ");
		}
	}
	fb.Print("}");

	deltaColor += 1;
}
