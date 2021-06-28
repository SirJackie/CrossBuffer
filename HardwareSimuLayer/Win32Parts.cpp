#include "Win32Parts.h"

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

void WindowsHelper::RegisterAndCreateWindow
(
	WNDPROC MsgProc, HINSTANCE& hInstance,
	const wchar_t* WindowClassName, const wchar_t* WindowTitle
)
{
	// Register Window
	wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0, 0,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		WindowClassName, NULL
	};
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CROSSBUFFERFORWINDOWS));
	RegisterClassEx(&wc);

	// Create Window
	wr.left = leftMargin;
	wr.right = windowWidth + wr.left;
	wr.top = topMargin;
	wr.bottom = windowHeight + wr.top;
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowW(
		WindowClassName, WindowTitle,
		WS_OVERLAPPEDWINDOW,
		wr.left, wr.top, wr.right - wr.left, wr.bottom - wr.top,
		NULL, NULL, wc.hInstance, NULL
	);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
}
