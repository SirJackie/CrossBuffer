#ifndef __CSBF_HardwareSimuLayer_Win32Parts__
#define __CSBF_HardwareSimuLayer_Win32Parts__

#include <Windows.h>
#include "Resource.h"
#include "../CrossBufferLayer/BasicDataTypeDeclarations.h"


typedef LRESULT(*MsgProcType) (HWND, UINT, WPARAM, LPARAM);

class WindowsHelper {
public:
	i32 screenWidth;
	i32 screenHeight;
	i32 unit;
	i32 windowWidth;
	i32 windowHeight;
	i32 leftMargin;
	i32 topMargin;

	WNDCLASSEX wc;

	void GetScreenResolution(i32& resultWidth, i32& resultHeight);

	WindowsHelper();
	void regist
	(
		WNDPROC MsgProc, const wchar_t* WindowClassName,
		HINSTANCE& hInstance
	);
};


void CreateWindowRectUsingWindow(WindowsHelper& win, const wchar_t* WindowClassName, const wchar_t* WindowTitle, WNDCLASSEX& wc, RECT& resultRect, HWND& resultHwnd);

#endif
