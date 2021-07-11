#include "FileSupport.h"

CS_File::CS_File(){
    file     = csNullPtr;
    fileHead = csNullPtr;
    fileEnd  = csNullPtr;
    fileMode = csReadBinary;
    length   = 0;
}

CS_File::CS_File(string fileName_, csFileMode fileMode_, CS_FrameBuffer& fb){
    fileMode = fileMode_;
    file = fopen(fileName_.c_str(), fileMode == csReadBinary ? "rb" : "wb");
    ptrfb = &fb;

    ptrfb->PrintLn((i64) file);

    if(file != csNullPtr){
        // Get the Length of the File
        fseek(file, 0, SEEK_END);
        length = GetPositionNow() + 1;
        fseek(file, 0, SEEK_SET);
    }
    else{
        fileHead = csNullPtr;
        fileEnd  = csNullPtr;
        fileMode = csReadBinary;
        length   = 0;
    }
}

void CS_File::Read(ui8* buffer, i32 length){
    if(fileMode == csReadBinary && file != csNullPtr){
        fread(buffer, sizeof(ui8), length, file);
    }
}

void CS_File::Write(ui8* buffer, i32 length){
    if(fileMode == csWriteBinary && file != csNullPtr){
        fwrite(buffer, sizeof(ui8), length, file);
    }
}

i32 CS_File::GetPositionNow(){
    return ftell(file);
}

void CS_File::GoToHead(){
    file = fileHead;
}

void CS_File::GoToEnd(){
    file = fileEnd;
}

void CS_File::Close(){
    if(file != csNullPtr){
        fclose(file);
        file = csNullPtr;
    }
}

CS_File::~CS_File(){
    Close();
}
