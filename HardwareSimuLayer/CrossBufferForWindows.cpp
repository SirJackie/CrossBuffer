// Include Hardware Simulation Parts
#include "Win32Parts.h"
#include "D3DParts.h"
#include "DeclarationParts.h"

// Include Standard Libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;

// Include VS Compiling Shit
#include "resource.h"

// Include the CrossBufferLayer
#include "../Main.h"
#include "../CrossBufferLayer/CrossBuffer.h"



/*
** Define Global Variables
*/

IDirect3D9* pDirect3D;
IDirect3DDevice9* pDevice;
IDirect3DSurface9* pBackBuffer;
D3DLOCKED_RECT rect;
BOOL FirstTimeRunning = TRUE;
clock_t lastTime = clock();
clock_t thisTime = clock();
Window win;
Keyboard kb;

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);





FrameBuffer bitmapbuffer;

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
	GetScreenResolution(&(win.ScreenWidth), &(win.ScreenHeight));
	win.Unit    = win.ScreenHeight / 30;
	win.WindowHeight  = 26 * win.Unit;
	win.WindowWidth   = win.WindowHeight / 9 * 16;
	win.LeftMargin = (win.ScreenWidth - win.WindowWidth)  / 2;
	win.TopMargin  = (win.ScreenHeight - win.WindowHeight) / 2;

	// Regist Window Class
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0, 0,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		WindowClassName, NULL
	};
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	wc.hIcon   = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CROSSBUFFERFORWINDOWS));
	RegisterClassEx(&wc);

	// Create Window
	RECT wr;
	wr.left   = win.LeftMargin;
	wr.right  = win.WindowWidth  + wr.left;
	wr.top    = win.TopMargin;
	wr.bottom = win.WindowHeight + wr.top;
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
	HWND hWnd = CreateWindowW(
		WindowClassName, WindowTitle,
		WS_OVERLAPPEDWINDOW,
		wr.left, wr.top, wr.right - wr.left, wr.bottom - wr.top,
		NULL, NULL, wc.hInstance, NULL
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	// Initialize Direct3D Objects
	pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,
		&d3dpp, &pDevice
	);

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
			pDevice->Clear(
				0, NULL, D3DCLEAR_TARGET,
				D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0
			);
			pBackBuffer = NULL;
			pDevice->GetBackBuffer(
				0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer
			);
			pBackBuffer->LockRect(&rect, NULL, NULL);

			// Init FrameBuffer Object
			//FrameBuffer fb(win.Width, win.Height, (rect.Pitch) >> 2, (Color*)rect.pBits);
			FrameBuffer fb;

			// If it is the First Time Running
			if (FirstTimeRunning) {
				Setup(fb, kb, 0);                      /* Call the Setup() in Main.h */
				FirstTimeRunning = FALSE;
			}

			// If it is not the First Time Running
			else {
				Update(fb, kb, thisTime - lastTime);   /* Call the Update() in Main.h */
			}

			//for (unsigned int i = 0; i < fbLoadingQueue.size(); i++) {
			//	FrameBuffer& fb = *(fbLoadingQueue[i]);
			//	/*if (fb.wannaLoadBitmap == true) {
			//		ReadBitmapToFrameBuffer(fb.bitmapAddress.c_str(), fb);
			//		fb.wannaLoadBitmap = false;
			//	}*/
			//}
			//fbLoadingQueue.clear();

			// Release Back Buffer and Swap it to Front
			pBackBuffer->UnlockRect();
			pBackBuffer->Release();
			pDevice->Present(NULL, NULL, NULL, NULL);

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
	if (pDevice)
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if (pDirect3D)
	{
		pDirect3D->Release();
		pDirect3D = NULL;
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
