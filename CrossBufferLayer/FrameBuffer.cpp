#include "FrameBuffer.h"
#include <vector>
using std::vector;


void CS_FrameBuffer::AllocateBuffer(i32 width, i32 height)
{
    redBuffer   = new i8[width * height];
    greenBuffer = new i8[width * height];
    blueBuffer  = new i8[width * height];
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
    for (i32 y = 0; y < height; y++) {
        for (i32 x = 0; x < width; x++) {
            to.redBuffer[y * width + x] = from.redBuffer[y * width + x];
            to.greenBuffer[y * width + x] = from.greenBuffer[y * width + x];
            to.blueBuffer[y * width + x] = from.blueBuffer[y * width + x];
        }
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
