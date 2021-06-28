#ifndef __CSBF_HardwareSimuLayer_Win32Parts__
#define __CSBF_HardwareSimuLayer_Win32Parts__

#include <Windows.h>
#include "Resource.h"
#include "../CrossBufferLayer/BasicDataTypeDeclarations.h"
#include "DeclarationParts.h"


typedef LRESULT(*MsgProcType) (HWND, UINT, WPARAM, LPARAM);

void GetScreenResolution(i32& resultWidth, i32& resultHeight);

WNDCLASSEX GetRegistedWindowClass
	       (const wchar_t* WindowClassName, WNDPROC& MsgProc, HINSTANCE& hInstance);

void CreateWindowRectUsingWindow(Window& win, const wchar_t* WindowClassName, const wchar_t* WindowTitle, WNDCLASSEX& wc, RECT& resultRect, HWND& resultHwnd);

#endif
