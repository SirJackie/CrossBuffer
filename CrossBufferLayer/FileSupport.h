#ifndef __CSBF_FileSupport__
#define __CSBF_FileSupport__

#include "BasicDataTypeDeclarations.h"

typedef char csFileMode;
const csFileMode csReadBinary = 0;
const csFileMode csWriteBinary = 1;

class CS_File{
private:
    FILE *file;
    FILE *fileHead;
    FILE *fileEnd;
public:
    csFileMode fileMode;
    i32 length;

    CS_File();
    CS_File(string fileName_, csFileMode fileMode_);

    void Read (ui8* buffer, i32 length);
    void Write(ui8* buffer, i32 length);
    i32  GetPositionNow();
    void GoToHead();
    void GoToEnd();
    void Close();

    ~CS_File();
};

#endif
