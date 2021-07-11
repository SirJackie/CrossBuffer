#include "Main.h"

i32 deltaColor = 0;
i32 startX = 300, startY = 200, endX = 400, endY = 300;
i32 step;
CS_FPSCalculator fpsCalculator;
CS_File file;

void Setup (CS_FrameBuffer& fb, CS_Keyboard& kb, CS_Mouse& mouse, i32 deltaTime) {
	file.Open(CS_Path().join("..").join("Resources").join("Test.txt"), csReadBinary);
	file.Read();
	file.Close();

	file.Open(CS_Path().join("..").join("Resources").join("Test.txt"), csWriteBinary);
	file.ResizeAndClearBuffer(13);
	strcpy((i8*)file.buffer, "Hello World!");
	file.Write();
	file.Close();

	file.Open(CS_Path().join("..").join("Resources").join("Test.txt"), csReadBinary);
	file.Read();
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

	fb.PrintLn("Path Joining Test: (Path Spliter will be changed in defferent OS)");
	extern string CS_OperatingSystem;
	fb.Print("Operating System: ");
	fb.PrintLn(CS_OperatingSystem);
	fb.Print("Path: ");
	fb.PrintLn((string)CS_Path().join("abc").join("def").join("ghi.jpg"));
	fb.PrintLn("");

	fb.PrintLn("File Reading and Writing Test: ");
	fb.PrintLn((i8*)file.buffer);
	fb.PrintLn(file.fileLength);

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
