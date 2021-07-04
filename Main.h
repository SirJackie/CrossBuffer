#ifndef __CSBF_Main__
#define __CSBF_Main__

#include "./CrossBufferLayer/CrossBuffer.h"


/* Define Window Class Properties */
#define WindowTitle (i32*)L"CrossBuffer <Press WASD and IJKL to move the position>"

void Setup  (CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime);
void Update(CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime, i32 mouseX, i32 mouseY, csbool LBtnState, csbool MBtnState, csbool RBtnState);

#endif
