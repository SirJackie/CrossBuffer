#include "MouseSupport.h"

CS_Mouse::CS_Mouse(){
    x = 0;
    y = 0;
    screenWidth = 0;
    screenHeight = 0;

    lBtnState = csFalse;
    mBtnState = csFalse;
    rBtnState = csFalse;
    infinityMode = csFalse;
}

CS_Mouse::CS_Mouse(i32 screenWidth_, i32 screenHeight_){
    x = 0;
    y = 0;
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;

    lBtnState = csFalse;
    mBtnState = csFalse;
    rBtnState = csFalse;
    infinityMode = csFalse;
}

string CS_Mouse::GetStrStatus(){
    stringstream ss;
    
    ss << "MouseX: ";
    ss << x;
    ss << "; MouseY: ";
    ss << y;

    ss << "; ScreenWidth: ";
    ss << screenWidth;
    ss << "; ScreenHeight: ";
    ss << screenHeight;
    

    ss << "; LBtnState: ";
    if (lBtnState == csTrue) {
        ss << "True";
    }
    else {
        ss << "False";
    }


    ss << "; MBtnState: ";
    if (mBtnState == csTrue) {
        ss << "True";
    }
    else {
        ss << "False";
    }


    ss << "; RBtnState: ";
    if (rBtnState == csTrue) {
        ss << "True";
    }
    else {
        ss << "False";
    }
    

    return ss.str();
}

void CS_Mouse::OpenInfinityMode(){
    infinityMode = csTrue;
}

void CS_Mouse::CloseInfinityMode(){
    infinityMode = csFalse;
}
