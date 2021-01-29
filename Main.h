#include "./CrossBufferLayer/CrossBuffer.h"


/* Background color Transform Variables */
int color = 0;
float DeltaColor = 0.1f;

/* FPS Counting Variables */
float FPS = 0;
int   deltaTimeCount;
int   frameCount;

/* Temp Variables */
int RedCubeX = 100;
int RedCubeY = 100;

int GreenCubeX;
int GreenCubeY;

/* Mouse Sensitivity */
float MouseSensitivity;


/*
** On Create Callback Function
*/
void OnCreate() {
	;
}


/*
** Setup Callback Function
*/
void Setup(FrameBuffer fb, int width, int height, int deltaTime) {

	/* Fill Yellow On The Screen */
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			SetPixel(fb, x, y, CreateColor(255, 255, 0));
		}
	}
}


/*
** Update Callback Function
*/
void Update(FrameBuffer fb, int width, int height, int deltaTime) {
	/*
	** Process Background
	*/

	/* Draw Background */
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			SetPixel(fb, x, y, CreateColor(color, color, color));
		}
	}

	/* Calculate The color Of The Background In The Next Frame*/
	color += (int)(color * (float)deltaTime);

	if (color >= 250) {
		DeltaColor = -0.1f;
	}

	else if (color <= 5) {
		DeltaColor = 0.1f;
	}


	

	/* Boundary Treatment For Red Cube */
	if (RedCubeX < 0) {
		RedCubeX = 0;
	}
	else if (RedCubeX > width - 100) {
		RedCubeX = width - 100;
	}

	if (RedCubeY < 0) {
		RedCubeY = 0;
	}
	else if (RedCubeY > height - 100) {
		RedCubeY = height - 100;
	}

	/* Draw Red Cube */
	for (int y = RedCubeY; y < RedCubeY + 100; y++) {
		for (int x = RedCubeX; x < RedCubeX + 100; x++) {
			SetPixel(fb, x, y, CreateColor(255, 0, 0));
		}
	}


	/*
	** Process Green Cube That Controlled By Mouse
	*/

	/* Boundary Treatment For Green Cube */
	if (GreenCubeX < 0) {
		GreenCubeX = 0;
	}
	else if (GreenCubeX > width - 100) {
		GreenCubeX = width - 100;
	}

	if (GreenCubeY < 0) {
		GreenCubeY = 0;
	}
	else if (GreenCubeY > height - 100) {
		GreenCubeY = height - 100;
	}

	/* Draw Green Cube */
	for (int y = GreenCubeY; y < GreenCubeY + 100; y++) {
		for (int x = GreenCubeX; x < GreenCubeX + 100; x++) {
			SetPixel(fb, x, y, 0);
		}
	}


	/*
	** FPS Processing
	*/

	/* Calculate FPS */
	deltaTimeCount += deltaTime;
	frameCount += 1;

	if (deltaTimeCount > 1000) {
		FPS = (float)frameCount / ((float)deltaTimeCount / 1000);
		deltaTimeCount -= 1000;
		frameCount = 0;
	}
}

void OnDestroy() {
	;
}
