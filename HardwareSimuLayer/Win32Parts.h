#ifndef __CSBF_HardwareSimuLayer_Win32Parts__
#define __CSBF_HardwareSimuLayer_Win32Parts__

#include <Windows.h>
#include "Resource.h"


void GetScreenResolution(int* resultX, int* resultY);
WNDCLASSEX GetRegistedWindowClass
(
	const wchar_t* WindowClassName, WNDPROC& MsgProc, HINSTANCE& hInstance
);

#endif
