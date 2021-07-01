#include "FrameBuffer.h"
#include "FontSupport.h"
#include <vector>
using std::vector;


void CS_FrameBuffer::AllocateBuffer(i32 width, i32 height)
{
    redBuffer   = new ui8[width * height];
    greenBuffer = new ui8[width * height];
    blueBuffer  = new ui8[width * height];
}

void CS_FrameBuffer::DisAllocateBuffer()
{
    delete[] redBuffer;
    delete[] greenBuffer;
    delete[] blueBuffer;
}

void CS_FrameBuffer::ClearSelfBuffer()
{
    CS_Memset(redBuffer, 0, width * height);
    CS_Memset(greenBuffer, 0, width * height);
    CS_Memset(blueBuffer, 0, width * height);
}

void CS_FrameBuffer::CopySameSizeBuffer(const CS_FrameBuffer& from, CS_FrameBuffer& to)
{
    if(  (from.width * from.height)  <  (to.width * to.height)  ){
        return;  // Too small to copy
    }

    ui8* toRedBuffPtr = to.redBuffer;
    ui8* toGreenBuffPtr = to.greenBuffer;
    ui8* toBlueBuffPtr = to.blueBuffer;

    ui8* fromRedBuffPtr = from.redBuffer;
    ui8* fromGreenBuffPtr = from.greenBuffer;
    ui8* fromBlueBuffPtr = from.blueBuffer;

    for (i32 i = 0; i < width * height; i++) {
        *toRedBuffPtr = *fromRedBuffPtr;
        *toGreenBuffPtr = *fromGreenBuffPtr;
        *toBlueBuffPtr = *fromBlueBuffPtr;

        toRedBuffPtr++;
        toGreenBuffPtr++;
        toBlueBuffPtr++;

        fromRedBuffPtr++;
        fromGreenBuffPtr++;
        fromBlueBuffPtr++;
    }
}

CS_FrameBuffer::CS_FrameBuffer()
{
    curX = initCurX = CS_FONT_INIT_CUR_X;
    curY = initCurY = CS_FONT_INIT_CUR_Y;

    width = height = 1;

    AllocateBuffer(1, 1);
    ClearSelfBuffer();
}

CS_FrameBuffer::CS_FrameBuffer(i32 Width_, i32 Height_)
{
    curX = initCurX = CS_FONT_INIT_CUR_X;
    curY = initCurY = CS_FONT_INIT_CUR_Y;

    width  = Width_;
    height = Height_;

    AllocateBuffer(width, height);
    ClearSelfBuffer();
}

CS_FrameBuffer::CS_FrameBuffer(const CS_FrameBuffer& fb)
{
    width  = fb.width;
    height = fb.height;

    curX = fb.curX;
    curY = fb.curY;
    initCurX = fb.initCurX;
    initCurY = fb.initCurY;

    AllocateBuffer(width, height);
    CopySameSizeBuffer(fb, (*this));
}

CS_FrameBuffer& CS_FrameBuffer::operator=(const CS_FrameBuffer& fb)
{
    DisAllocateBuffer();

    width = fb.width;
    height = fb.height;

    curX = fb.curX;
    curY = fb.curY;
    initCurX = fb.initCurX;
    initCurY = fb.initCurY;

    AllocateBuffer(width, height);
    CopySameSizeBuffer(fb, (*this));

    return (*this);  // Support a = b = c
}

CS_FrameBuffer::~CS_FrameBuffer()
{
    DisAllocateBuffer();
}

void CS_FrameBuffer::DrawChar(const char& ch, i32 xStart, i32 yStart)
{
    ui8* chBmStartPtr = ((ui8*)CS_font + 16 * 8 * ch);
    ui8* redBufStartPtr = redBuffer;
    ui8* grnBufStartPtr = greenBuffer;
    ui8* bluBufStartPtr = blueBuffer;

    i32 xMin = CS_iclamp(0, xStart, width);
    i32 yMin = CS_iclamp(0, yStart, height);
    i32 xMax = CS_iclamp(0, xStart + CS_FONT_WIDTH, width);
    i32 yMax = CS_iclamp(0, yStart + CS_FONT_HEIGHT, height);

    i32 deltaY = yMin-yStart;
    ui8* chBmPtr = chBmStartPtr + deltaY * CS_FONT_WIDTH;
    ui8* redBufPtr = redBufStartPtr + deltaY * width;
    ui8* grnBufPtr = grnBufStartPtr + deltaY * width;
    ui8* bluBufPtr = bluBufStartPtr + deltaY * width;

    for (i32 y = yMin; y < yMax; y++) {
        i32 deltaY = (y - yStart);
        chBmPtr = chBmStartPtr + deltaY * CS_FONT_WIDTH;
        redBufPtr = redBufStartPtr + y * width + xMin;
        grnBufPtr = grnBufStartPtr + y * width + xMin;
        bluBufPtr = bluBufStartPtr + y * width + xMin;

        for (i32 x = xMin; x < xMax; x++) {
            if (*chBmPtr != 0) *redBufPtr = *chBmPtr;
            if (*chBmPtr != 0) *grnBufPtr = *chBmPtr;
            if (*chBmPtr != 0) *bluBufPtr = *chBmPtr;

            chBmPtr++;
            redBufPtr++;
            grnBufPtr++;
            bluBufPtr++;
        }
    }
}

void CS_FrameBuffer::DrawString(const i8* str, const i32 x, const i32 y)
{
    i32 xNow = x, yNow = y;
    i8* charNow = (i8*)str;
    while (*charNow != 0) {
        DrawChar(*charNow, xNow, yNow);
        charNow++;
        if ((xNow + CS_FONT_WIDTH) > width) {
            yNow += CS_FONT_HEIGHT;
            xNow = x;
        }
        else {
            xNow+= CS_FONT_WIDTH;
        }
    }
}
