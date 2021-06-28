#ifndef __CSBF_HardwareSimuLayer_D3DParts__
#define __CSBF_HardwareSimuLayer_D3DParts__

#include <d3d9.h>


class D3DHelper {
public:
	IDirect3D9* pDirect3D;
	IDirect3DDevice9* pDevice;
	IDirect3DSurface9* pBackBuffer;
	D3DLOCKED_RECT rect;
};

void InitializeD3DThings(HWND& hWnd, D3DHelper& d3dHelper);

#endif
