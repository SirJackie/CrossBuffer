#ifndef __CSBF_HardwareSimuLayer_D3DParts__
#define __CSBF_HardwareSimuLayer_D3DParts__

#include <d3d9.h>
#include "../CrossBufferLayer/FrameBuffer.h"


class D3DHelper {
public:
	IDirect3D9* pDirect3D;
	IDirect3DDevice9* pDevice;
	IDirect3DSurface9* pBackBuffer;
	D3DLOCKED_RECT rect;

	D3DHelper();
	D3DHelper(HWND& hWnd);
	void LockBuffer();
	void UnlockBuffer();
	void PaintFrameBufferHere(const FrameBuffer& fb);
};

#endif
