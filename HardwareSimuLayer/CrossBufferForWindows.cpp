// Include Hardware Simulation Parts
#include "Win32Parts.h"
#include "D3DParts.h"
#include "DeclarationParts.h"

// Include Standard Libraries
#include <time.h>

// Include the CrossBufferLayer
#include "../Main.h"
#include "../CrossBufferLayer/CrossBuffer.h"



/*
** Define Global Variables
*/

D3DHelper d3dHelper;
BOOL FirstTimeRunning = TRUE;
clock_t lastTime = clock();
clock_t thisTime = clock();
Window win;
Keyboard kb;

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

/*
** Main Function
*/

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	// Get Present Time
	thisTime = clock();
	lastTime = thisTime;

	// Calculate Window Size
	i32 screenWidth, screenHeight;
	GetScreenResolution(screenWidth, screenHeight);
	win = Window(screenWidth, screenHeight);

	// Regist Window Class
	WNDPROC wpMsgProc = MsgProc;
	WNDCLASSEX wc = GetRegistedWindowClass(WindowClassName, wpMsgProc, hInstance);

	// Create Window
	RECT wr;
	HWND hWnd;
	CreateWindowRectUsingWindow(win, WindowClassName, WindowTitle, wc, wr, hWnd);

	InitializeD3DThings(hWnd, d3dHelper);

	// Process Messages From Windows
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		// If there is a Message
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		/* Else, Process the Game Loop */
		else
		{
			/*
			** Main Loop
			*/
			
			// Get Present Time
			thisTime = clock();

			// Clear & Get Back Buffer
			d3dHelper.pDevice->Clear(
				0, NULL, D3DCLEAR_TARGET,
				D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0
			);
			d3dHelper.pBackBuffer = NULL;
			d3dHelper.pDevice->GetBackBuffer(
				0, 0, D3DBACKBUFFER_TYPE_MONO, &(d3dHelper.pBackBuffer)
			);
			d3dHelper.pBackBuffer->LockRect(&(d3dHelper.rect), NULL, NULL);

			// Init FrameBuffer Object
			//FrameBuffer fb(win.Width, win.Height, (rect.Pitch) >> 2, (Color*)rect.pBits);
			FrameBuffer fb(win.windowWidth, win.windowHeight);

			// If it is the First Time Running
			if (FirstTimeRunning) {
				Setup(fb, kb, 0);                      /* Call the Setup() in Main.h */
				FirstTimeRunning = FALSE;
			}

			// If it is not the First Time Running
			else {
				Update(fb, kb, thisTime - lastTime);   /* Call the Update() in Main.h */
			}

			i32* pBits = (i32*)d3dHelper.rect.pBits;
			i32  bufferPitch = (d3dHelper.rect.Pitch)>>2;
			i8* pRed = fb.redBuffer;
			i8* pGreen = fb.greenBuffer;
			i8* pBlue = fb.blueBuffer;

			for (i32 y = 0; y < fb.height; y++) {
				for (i32 x = 0; x < fb.width; x++) {
					pBits[y * bufferPitch + x] = 
					(i32)
					(
						(     0xff                << 24) |
						(  (  (*pRed  ) & 0xff  ) << 16) |
						(  (  (*pGreen) & 0xff  ) <<  8) |
						(     (*pBlue) & 0xff          )
					);
					pRed++;
					pGreen++;
					pBlue++;
				}
			}

			

			// Release Back Buffer and Swap it to Front
			d3dHelper.pBackBuffer->UnlockRect();
			d3dHelper.pBackBuffer->Release();
			d3dHelper.pDevice->Present(NULL, NULL, NULL, NULL);

			// Calculate the Delta Time
			// lastTime in next frame = thisTime in this frame
			lastTime = thisTime;
		}
	}


	/*
	** After the Main Loop
	*/

	// Release All the Variables
	UnregisterClass(WindowClassName, wc.hInstance);
	if (d3dHelper.pDevice)
	{
		d3dHelper.pDevice->Release();
		d3dHelper.pDevice = NULL;
	}
	if (d3dHelper.pDirect3D)
	{
		d3dHelper.pDirect3D->Release();
		d3dHelper.pDirect3D = NULL;
	}
	return 0;
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
		kb.HardwareSimuSetKeyIsPressed(wParam);
		if (wParam == KEY_ESCAPE) {
			PostQuitMessage(0);
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_KEYUP:
		kb.HardwareSimuSetKeyIsReleased(wParam);
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_LBUTTONDOWN:
		kb.HardwareSimuSetKeyIsPressed(KEY_MOUSE_LBTN);
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_LBUTTONUP:
		kb.HardwareSimuSetKeyIsReleased(KEY_MOUSE_LBTN);
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_RBUTTONDOWN:
		kb.HardwareSimuSetKeyIsPressed(KEY_MOUSE_RBTN);
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_RBUTTONUP:
		kb.HardwareSimuSetKeyIsReleased(KEY_MOUSE_RBTN);
		return DefWindowProc(hWnd, msg, wParam, lParam);

	case WM_MOUSEMOVE:
		/* Get Mouse Position */
		LOWORD(lParam);  // MouseX
		HIWORD(lParam);  // MouseY
		return DefWindowProc(hWnd, msg, wParam, lParam);

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}
