#ifndef __CSBF_FrameBuffer__
#define __CSBF_FrameBuffer__

#include "BasicDataTypeDeclarations.h"
#include "FontSupport.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

#define INIT_CUR_X   10
#define INIT_CUR_Y   10
#define TEXT_WIDTH   8
#define TEXT_HEIGHT  16

class FrameBuffer
{
public:

    // Properties
    i32 width;
    i32 height;

    i8* redBuffer;
    i8* greenBuffer;
    i8* blueBuffer;

    i32 curX;
    i32 curY;
    i32 initCurX;
    i32 initCurY;


    // Methods
    void AllocateBuffer
         (i32 width, i32 height);
    void DisAllocateBuffer
         ();
    void ClearSelfBuffer
         ();
    void CopySameSizeBuffer
         (const FrameBuffer& from, FrameBuffer& to);

    FrameBuffer();
    FrameBuffer(i32 Width_, i32 Height_);
    FrameBuffer(const FrameBuffer& fb);
    FrameBuffer& operator=(const FrameBuffer& fb);
    ~FrameBuffer();

   /*
	void DrawChar
         (i32 x, i32 y, i8 r, i8 g, i8 b, char ch);
    void DrawString
         (i8 r, i8 g, i8 b, const i8* stringPointer);
    void DrawBuffer
         (const FrameBuffer& fb, i32 PositionX, i32 PositionY);
    void Draw
         (const char* stringPointer);
    void Draw
         (const FrameBuffer& fb);
    void InitCursor
         ();
   */
};

#endif
