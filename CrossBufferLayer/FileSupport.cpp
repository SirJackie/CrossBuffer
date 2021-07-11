#include "FileSupport.h"

CS_File::CS_File(){
    file     = csNullPtr;
    fileHead = csNullPtr;
    fileEnd  = csNullPtr;
    fileMode = csReadBinary;
    length   = 0;
}

CS_File::CS_File(string fileName_, csFileMode fileMode_){
    fileMode = fileMode_;
    file = fopen(fileName_.c_str(), fileMode == csReadBinary ? "rb" : "wb");

    if(file != csNullPtr){
        // Get the Length of the File
        fileHead = file;
        fseek(file, 0, SEEK_END);
        fileEnd = file;
        length = GetPositionNow() + 1;
        file = fileHead;
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
