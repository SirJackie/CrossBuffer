#include "Win32Parts.h"

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

void CreateWindowRectUsingWindow(WindowsHelper& win, const wchar_t* WindowClassName, const wchar_t* WindowTitle, WNDCLASSEX& wc, RECT& resultRect, HWND& resultHwnd)
{
	RECT wr;
	wr.left = win.leftMargin;
	wr.right = win.windowWidth + wr.left;
	wr.top = win.topMargin;
	wr.bottom = win.windowHeight + wr.top;
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
	HWND hWnd = CreateWindowW(
		WindowClassName, WindowTitle,
		WS_OVERLAPPEDWINDOW,
		wr.left, wr.top, wr.right - wr.left, wr.bottom - wr.top,
		NULL, NULL, wc.hInstance, NULL
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	resultHwnd = hWnd;
	resultRect = wr;
}

void WindowsHelper::GetScreenResolution(i32& resultWidth, i32& resultHeight)
{
	// Get Screen HDC
	HDC hdcScreen;
	hdcScreen = CreateDC(L"DISPLAY", NULL, NULL, NULL);
	// Get X and Y
	resultWidth = GetDeviceCaps(hdcScreen, HORZRES);
	resultHeight = GetDeviceCaps(hdcScreen, VERTRES);
	// Release HDC
	if (csNull != hdcScreen) {
		DeleteDC(hdcScreen);
	}
}

WindowsHelper::WindowsHelper()
{
	GetScreenResolution(screenWidth, screenHeight);
	unit = screenHeight / 30;

	windowHeight = 26 * unit;
	windowWidth = CS_iclamp(0, windowHeight / 9 * 16, screenWidth - 10);

	leftMargin = (screenWidth - windowWidth) / 2;
	topMargin = (screenHeight - windowHeight) / 2;
}
