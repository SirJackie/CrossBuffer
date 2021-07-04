// Include Hardware Simulation Parts
#include "WindowsHelper.h"
#include "D3DHelper.h"
#include "KeyboardHelper.h"

// Include Standard Libraries
#include <time.h>

// Include the CrossBufferLayer
#include "../Main.h"
#include "../CrossBufferLayer/CrossBuffer.h"

// WindowsSimuLayer Variables
WSL_WindowsHelper   windowsHelper;
WSL_D3DHelper       d3dHelper;
WSL_KeyboardHelper  keyboardHelper;

// CrossBufferLayer Variables
CS_FrameBuffer fb;
CS_Mouse       mouse;

// Time Counting Variables
csbool FirstTimeRunning;
clock_t lastTime;
clock_t thisTime;

// Windows.h Loop Message Variable
MSG msg;

// Message Processing Function Declaration
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);




/*
** Main Function
*/

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	// Initialize CrossBufferLayer and WIndowsSimuLayer Objects
	windowsHelper   = WSL_WindowsHelper(MsgProc, hInstance, (wchar_t*)WindowTitle, (wchar_t*)WindowTitle);
	d3dHelper       = WSL_D3DHelper(windowsHelper.hWnd);
	keyboardHelper  = WSL_KeyboardHelper();
	fb              = CS_FrameBuffer(windowsHelper.windowWidth, windowsHelper.windowHeight);

	// Initialize Time Counting Variables
	FirstTimeRunning = csTrue;

	// Initialize Windows.h Loop Message Variable
	ZeroMemory(&msg, sizeof(msg));


	/* Main Loop */
	while (msg.message != WM_QUIT)
	{
		// If there is a Message
		if (PeekMessage(&msg, csNull, 0, 0, PM_REMOVE))
		{
			/* Process it */

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		// Else
		else
		{
			/* Process our Game Loop */
			
			// Update Time Counting Variables
			thisTime = clock();

			// Lock System BackBuffer and Clear the FrameBuffer
			d3dHelper.LockBuffer();  
			fb = CS_FrameBuffer
			(
				windowsHelper.windowWidth, windowsHelper.windowHeight
			);

			// If it is the First Time Running
			if (FirstTimeRunning) {
				Setup(fb, keyboardHelper.kb, mouse, 0);                     // Call the Setup()  in Main.h
				FirstTimeRunning = csFalse;
			}

			// If it is not the First Time Running
			else {
				Update(fb, keyboardHelper.kb, mouse, thisTime - lastTime);  // Call the Update() in Main.h
			}

			// Paint Our FrameBuffer to System BackBuffer
			d3dHelper.PaintFrameBufferHere(fb);

			// Release Back Buffer and Swap it as the FrontBuffer
			d3dHelper.UnlockBuffer();

			// Update Time Counting Variables
			// lastTime in next frame = thisTime in this frame
			lastTime = thisTime;
		}
	}

	/* After the Main Loop */
	{
		// Release All the Variables
		windowsHelper.Unregister((wchar_t*)WindowTitle);
		d3dHelper.Release();
		return 0;
	}

}



/*
** Message Loop
*/

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_KEYDOWN:
		keyboardHelper.windowsKeyBuffer[wParam] = 1;
		keyboardHelper.MoveWinBufIntoKeyBuf();
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_KEYUP:
		keyboardHelper.windowsKeyBuffer[wParam] = 0;
		keyboardHelper.MoveWinBufIntoKeyBuf();
		return DefWindowProc(hWnd, msg, wParam, lParam);

	//case WM_LBUTTONDOWN:
	//	//kb.SimuLayerSetKeyIsPressed((i8)KEY_MOUSE_LBTN);
	//	return DefWindowProc(hWnd, msg, wParam, lParam);

	//case WM_LBUTTONUP:
	//	//kb.SimuLayerSetKeyIsReleased((i8)KEY_MOUSE_LBTN);
	//	return DefWindowProc(hWnd, msg, wParam, lParam);

	//case WM_RBUTTONDOWN:
	//	//kb.SimuLayerSetKeyIsPressed((i8)KEY_MOUSE_RBTN);
	//	return DefWindowProc(hWnd, msg, wParam, lParam);

	//case WM_RBUTTONUP:
	//	//kb.SimuLayerSetKeyIsReleased((i8)KEY_MOUSE_RBTN);
	//	return DefWindowProc(hWnd, msg, wParam, lParam);

	//case WM_MOUSEMOVE:
	//	/* Get Mouse Position */
	//	LOWORD(lParam);  // MouseX
	//	HIWORD(lParam);  // MouseY
	//	return DefWindowProc(hWnd, msg, wParam, lParam);

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}
