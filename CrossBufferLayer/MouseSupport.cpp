#include "MouseSupport.h"

string CS_Mouse::GetStrStatus(){
    newSS.clear();
    newSS.str("");
    
    newSS << "MouseX: ";
    newSS << x;
    newSS << "; MouseY: ";
    newSS << y;
    newSS << "; LBtnState: ";
    newSS << lBtnState;
    newSS << "; MBtnState: ";
    newSS << mBtnState;
    newSS << "; RBtnState: ";
    newSS << rBtnState;
    
    return newSS.str();
}
