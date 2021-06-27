#include "FrameBuffer.h"
#include <vector>
using std::vector;


void FrameBuffer::AllocateBuffer(i32 width, i32 height)
{
    redBuffer   = new i8[width * height];
    greenBuffer = new i8[width * height];
    blueBuffer  = new i8[width * height];
}

void FrameBuffer::DisAllocateBuffer()
{
    delete[] redBuffer;
    delete[] greenBuffer;
    delete[] blueBuffer;
}

void FrameBuffer::ClearSelfBuffer()
{
    for (i32 y = 0; y < height; y++) {
        for (i32 x = 0; x < width; x++) {
            redBuffer[y * width + x] = 0;
            greenBuffer[y * width + x] = 0;
            blueBuffer[y * width + x] = 0;
        }
    }
}

void FrameBuffer::CopySameSizeBuffer(const FrameBuffer& from, FrameBuffer& to)
{
    for (i32 y = 0; y < height; y++) {
        for (i32 x = 0; x < width; x++) {
            to.redBuffer[y * width + x] = from.redBuffer[y * width + x];
            to.greenBuffer[y * width + x] = from.greenBuffer[y * width + x];
            to.blueBuffer[y * width + x] = from.blueBuffer[y * width + x];
        }
    }
}

FrameBuffer::FrameBuffer()
{
    curX = initCurX = INIT_CUR_X;
    curY = initCurY = INIT_CUR_Y;

    width = height = 1;

    AllocateBuffer(1, 1);
    ClearSelfBuffer();
}

FrameBuffer::FrameBuffer(i32 Width_, i32 Height_)
{
    curX = initCurX = INIT_CUR_X;
    curY = initCurY = INIT_CUR_Y;

    width  = Width_;
    height = Height_;

    AllocateBuffer(width, height);
    ClearSelfBuffer();
}

FrameBuffer::FrameBuffer(const FrameBuffer& fb)
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

FrameBuffer& FrameBuffer::operator=(const FrameBuffer& fb)
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

FrameBuffer::~FrameBuffer()
{
    DisAllocateBuffer();
}
