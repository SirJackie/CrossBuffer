#ifndef __CSBF_HardwareSimuLayer_Win32Parts__
#define __CSBF_HardwareSimuLayer_Win32Parts__

#include <Windows.h>


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
void ReadBitmapToFrameBuffer(const char* bmpAddress, FrameBuffer& fb) {
	// Getting File Pointer
	FILE* fp = NULL;
	string str;
	str += BitmapRootAddress;
	str += bmpAddress;
	int ret = fopen_s(&fp, str.c_str(), "rb");
	if (fp == 0)
	{
		return;
	}

	// Read the File
	BITMAPFILEHEADER fileheader = { 0 };
	fread(&fileheader, sizeof(fileheader), 1, fp);
	if (fileheader.bfType != 0x4D42)
	{
		fclose(fp);
		return;
	}

	// Read Bitmap Information Header
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	long bmpWidth = head.biWidth;
	long bmpHeight = head.biHeight;
	WORD biBitCount = head.biBitCount;
	if (biBitCount != 24)
	{
		//::AfxMessageBox(_T("«Î—°‘Ò24ŒªŒªÕº£°"));
		fclose(fp);
		return;
	}

	int totalSize = (bmpWidth * biBitCount / 8 + 3) / 4 * 4 * bmpHeight;
	BYTE* pBmpBuf = new BYTE[totalSize];
	size_t size = 0;
	while (true)
	{
		int iret = fread(&pBmpBuf[size], 1, 1, fp);
		if (iret == 0)
			break;
		size = size + iret;
	}
	fclose(fp);

	int pitch = bmpWidth % 4;

	// Create FrameBuffer
	fb.DisAllocateBuffer();
	fb.AllocateBuffer(bmpWidth, bmpHeight);
	int bmpHeightNegOne = bmpHeight - 1;

	for (int i = 0; i < bmpHeight; i++)
	{
		int realPitch = i * pitch;
		for (int j = 0; j < bmpWidth; j++)
		{
			//SetPixel(
			//	fb, j, i,
			//	CreateColor(
			//		pBmpBuf[((bmpHeightNegOne - i) * bmpWidth + j) * 3 + 2 + realPitch],
			//		pBmpBuf[((bmpHeightNegOne - i) * bmpWidth + j) * 3 + 1 + realPitch],
			//		pBmpBuf[((bmpHeightNegOne - i) * bmpWidth + j) * 3 + realPitch]
			//	)
			//);
		}
	}
	delete[] pBmpBuf;
	pBmpBuf = NULL;
}
*/




#endif
