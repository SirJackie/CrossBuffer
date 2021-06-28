#include "Win32Parts.h"

void GetScreenResolution(int* resultX, int* resultY)
{
	// Get Screen HDC
	HDC hdcScreen;
	hdcScreen = CreateDC(L"DISPLAY", NULL, NULL, NULL);
	// Get X and Y
	*resultX = GetDeviceCaps(hdcScreen, HORZRES);
	*resultY = GetDeviceCaps(hdcScreen, VERTRES);
	// Release HDC
	if (NULL != hdcScreen) DeleteDC(hdcScreen);
}

typedef LRESULT (*MsgProcType) (HWND, UINT, WPARAM, LPARAM);

WNDCLASSEX GetRegistedWindowClass
(
	const wchar_t* WindowClassName, WNDPROC& MsgProc, HINSTANCE& hInstance
)
{
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0, 0,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		WindowClassName, NULL
	};
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CROSSBUFFERFORWINDOWS));
	RegisterClassEx(&wc);

	return wc;
}
