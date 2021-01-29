#include <Windows.h>
#include <d3d9.h>
#include <time.h>
#include "resource.h"
#include "../Main.h"
#include "../CrossBufferLayer/CrossBuffer.h"


struct Window {

	int ScreenX;
	int ScreenY;
	int Unit;

	int Width;
	int Height;
	int LeftMargin;
	int TopMargin;
};

/* Window Class Properties */
#define WindowClassName L"CrossBuffer Class"
#define WindowTitle     L"CrossBuffer"

/* DirectX Objects */
IDirect3D9* pDirect3D;
IDirect3DDevice9* pDevice;
IDirect3DSurface9* pBackBuffer;
D3DLOCKED_RECT rect;

/* Window Properties */
Window win;

/* Flags */
BOOL FirstTimeRunning = TRUE;

/* Timer */
clock_t lastTime = clock();
clock_t thisTime = clock();


/*
** Functions
*/

void GetScreenResolution(int* resultX, int* resultY) {
	// Get Screen HDC
	HDC hdcScreen;
	hdcScreen = CreateDC(L"DISPLAY", NULL, NULL, NULL);

	// Get X and Y
	*resultX = GetDeviceCaps(hdcScreen, HORZRES);
	*resultY = GetDeviceCaps(hdcScreen, VERTRES);

	// Release HDC
	if (NULL != hdcScreen) DeleteDC(hdcScreen);
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

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}


/*
** Main Function
*/

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	/*
	** Initialize All The Variables
	*/
	thisTime = clock();
	lastTime = thisTime;


	/*
	** Calculate Window Width And Height
	*/
	GetScreenResolution(&(win.ScreenX), &(win.ScreenY));

	win.Unit = win.ScreenY / 30;

	win.Height     = 26 * win.Unit;
	win.Width      = win.Height / 9 * 16;

	//WindowWidth = 1104;
	//WindowHeight = 624;

	win.LeftMargin = (win.ScreenX - win.Width)  / 2;
	win.TopMargin  = (win.ScreenY - win.Height) / 2;
	

	/*
	** Call the OnCreate() in Main.h
	*/
	OnCreate();


	/*
	** Register Window Class
	*/
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0, 0,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		WindowClassName, NULL
	};

	wc.hIconSm = (HICON)LoadImage(
		hInst, MAKEINTRESOURCE(NULL), IMAGE_ICON, 16, 16, 0
	);

	wc.hIcon   = (HICON)LoadImage(
		hInst, MAKEINTRESOURCE(NULL), IMAGE_ICON, 32, 32, 0
	);

	RegisterClassEx(&wc);


	/*
	** Create Window
	*/
	RECT wr;
	wr.left   = win.LeftMargin;
	wr.right  = win.Width  + wr.left;
	wr.top    = win.TopMargin;
	wr.bottom = win.Height + wr.top;

	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
	HWND hWnd = CreateWindowW(
		WindowClassName, WindowTitle,
		WS_OVERLAPPEDWINDOW,
		wr.left, wr.top, wr.right - wr.left, wr.bottom - wr.top,
		NULL, NULL, wc.hInstance, NULL
	);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);


	/*
	** Direct3D Initialize
	*/
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


	/*
	** Process Messages From Windows
	*/
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		/*
		** Main Loop
		*/

		/* If there is a Message from Windows*/
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* Then Process it */
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		/* Else, Process the Game Loop */
		else
		{

			/*
			** Calculate the Time
			** thisTime = the time from the beginning of the program to the present
			*/
			thisTime = clock();


			/*
			** Clear Back Buffer
			*/
			pDevice->Clear(
				0, NULL, D3DCLEAR_TARGET,
				D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0
			);


			/*
			** Get Back Buffer
			*/
			pBackBuffer = NULL;
			pDevice->GetBackBuffer(
				0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer
			);
			pBackBuffer->LockRect(&rect, NULL, NULL);


			/*
			** Call Main.h
			*/

			/* If it is the First Time Running */
			if (FirstTimeRunning) {
				/* Set The Mouse's Initialize Position */

				FrameBuffer fb;
				fb.pBits = rect.pBits;
				fb.Pitch = rect.Pitch;

				/* Call the Setup() in Main.h */
				Setup(fb, win.Width, win.Height, 0);
				FirstTimeRunning = FALSE;
			}

			/* If it is not the First Time Running */
			else {
				/* Call the Update() in Main.h */
				FrameBuffer fb;
				fb.pBits = rect.pBits;
				fb.Pitch = rect.Pitch;

				Update(fb, win.Width, win.Height, thisTime - lastTime);
			}


			/*
			** Release Back Buffer
			*/
			pBackBuffer->UnlockRect();
			pBackBuffer->Release();


			/*
			** Swap the Front and the Back Buffer
			*/
			pDevice->Present(NULL, NULL, NULL, NULL);


			/*
			** Calculate the Time
			** lastTime in next frame = thisTime in this frame
			*/
			lastTime = thisTime;
		}
	}


	/*
	** After the Main Loop
	*/

	/* Call OnDestroy() in Main.h */
	OnDestroy();

	/* Release All the Variables */
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



