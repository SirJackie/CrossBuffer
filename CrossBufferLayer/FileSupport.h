#ifndef __CSBF_FileSupport__
#define __CSBF_FileSupport__

#include "BasicDataTypeDeclarations.h"
#include "FrameBuffer.h"

typedef char csFileMode;
const csFileMode csReadBinary = 0;
const csFileMode csWriteBinary = 1;

class CS_File{
public:
    FILE *file;
    FILE *fileHead;
    FILE *fileEnd;

    CS_FrameBuffer* ptrfb;

    csFileMode fileMode;
    i32 length;

    CS_File();
    CS_File(string fileName_, csFileMode fileMode_, CS_FrameBuffer& fb);

    void Read (ui8* buffer, i32 length);
    void Write(ui8* buffer, i32 length);
    i32  GetPositionNow();
    void GoToHead();
    void GoToEnd();
    void Close();

    ~CS_File();
};

#endif
