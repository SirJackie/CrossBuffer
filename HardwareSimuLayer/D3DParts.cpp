#include "D3DParts.h"

void InitializeD3DThings(HWND& hWnd, D3DHelper& d3dHelper)
{
	
}

D3DHelper::D3DHelper()
{
	pDirect3D   = csNullPtr;
	pDevice     = csNullPtr;
	pBackBuffer = csNullPtr;
	rect = {0, nullptr};
}

D3DHelper::D3DHelper(HWND& hWnd)
{
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

	pDevice = pDevice;
	pBackBuffer = csNullPtr;
	rect = { 0, nullptr };
}

void D3DHelper::LockBuffer()
{
	pDevice->Clear(
		0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0
	);
	pBackBuffer = NULL;
	pDevice->GetBackBuffer(
		0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer
	);
	pBackBuffer->LockRect(&rect, NULL, NULL);
}

void D3DHelper::UnlockBuffer()
{
	pBackBuffer->UnlockRect();
	pBackBuffer->Release();
	pDevice->Present(NULL, NULL, NULL, NULL);
}

void D3DHelper::PaintFrameBufferHere(const FrameBuffer& fb)
{
	i32* pBitsNow = (i32*)(rect.pBits);
	i32  bufferPitch = (rect.Pitch) >> 2;
	i8*  pRed = fb.redBuffer;
	i8*  pGreen = fb.greenBuffer;
	i8*  pBlue = fb.blueBuffer;

	for (i32 y = 0; y < fb.height; y++) {
		for (i32 x = 0; x < fb.width; x++) {
			*pBitsNow =
				(i32)
				(
					(0xff << 24) |
					(((*pRed) & 0xff) << 16) |
					(((*pGreen) & 0xff) << 8) |
					((*pBlue) & 0xff)
					);
			pRed++;
			pGreen++;
			pBlue++;
			pBitsNow++;
		}
		pBitsNow += bufferPitch - fb.width;
	}
}
