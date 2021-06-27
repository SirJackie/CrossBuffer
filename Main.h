#include "./CrossBufferLayer/CrossBuffer.h"
#include <vector>
#include <sstream>
using std::vector;
using std::stringstream;


/* Define Window Class Properties */
#define WindowClassName    L"CrossBuffer Class"
#define WindowTitle        L"CrossBuffer <Press WASD and IJKL to move the position>"
#define BitmapRootAddress  "..\\"


int StartX = 8;
int StartY = 30;
int EndX;
int EndY;
FrameBuffer bitmapFb;

/*
** Setup Callback Function
*/

void Setup(FrameBuffer &fb, Keyboard kb, int deltaTime, vector<FrameBuffer*>& fbLoadingQueue) {
	//EndX = fb.Width - 200;
	//EndY = fb.Height - 200;

	///* Fill Red On The Screen */
	//for (int y = 0; y < fb.Height; y++) {
	//	for (int x = 0; x < fb.Width; x++) {
	//		SetPixel(fb, x, y, CreateColor(255, 0, 0));
	//	}
	//}

	//bitmapFb.LoadBMP("TestingBitmap.bmp", fbLoadingQueue);
}


/*
** Update Callback Function
*/

//Color c = CreateColor(0, 144, 255);

FPSCalculator fps;

void Update(FrameBuffer &fb, Keyboard kb, int deltaTime, vector<FrameBuffer*>& fbLoadingQueue) {

	//if (kb.IsKeyPressed('A')) {
	//	StartX -= 3;
	//}
	//if (kb.IsKeyPressed('D')) {
	//	StartX += 3;
	//}
	//if (kb.IsKeyPressed('W')) {
	//	StartY -= 3;
	//}
	//if (kb.IsKeyPressed('S')) {
	//	StartY += 3;
	//}

	//if (kb.IsKeyPressed('J')) {
	//	EndX -= 3;
	//}
	//if (kb.IsKeyPressed('L')) {
	//	EndX += 3;
	//}
	//if (kb.IsKeyPressed('I')) {
	//	EndY -= 3;
	//}
	//if (kb.IsKeyPressed('K')) {
	//	EndY += 3;
	//}

	//FrameBuffer fb2(EndX - StartX, EndY - StartY);

	///* Fill Color On The Screen */
	//for (int y = 0; y < fb2.Height; y++) {
	//	for (int x = 0; x < fb2.Width; x++) {
	//		SetPixel(fb2, x, y, CreateColor(x/6, y/6, 128));
	//	}
	//}

	//fb2.Draw("Hello World!\n");
	//fb2.Draw("I can d");
	//fb2.Draw("raw WHATEVER I");
	//fb2.Draw(" want!\n");
	//fb2.Draw("Third Line!");

	////fb2.DrawString(CreateColor(255, 255, 255), "Hello World!\n");
	////fb2.DrawString(CreateColor(255, 255, 255), "I can d");
	////fb2.DrawString(CreateColor(255, 255, 255), "raw WHATEVER I");
	////fb2.DrawString(CreateColor(255, 255, 255), " want!\n");
	////fb2.DrawString(CreateColor(255, 255, 255), "Third Line!\n");

	//fb2.Draw(bitmapFb);
	//fb2.Draw("Still Third Line!");

	//fb.DrawBuffer(fb2, StartX, StartY);  // ok
	//fps.Count(deltaTime);
	////fps.ShowOnScreen(fb);

	////fbList.push_back(&fb2);
	//stringstream ss;
	//ss << fbLoadingQueue.size();
	//fb.Draw(ss.str().c_str());
}
