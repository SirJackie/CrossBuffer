#include "KeyboardSupport.h"

CS_Keyboard::CS_Keyboard()
{
    for (i32 i = 0; i < 256; i++) {
        keyBuffer[i] = csFalse;
    }
}

csbool CS_Keyboard::IsKeyPressed(i8 key)
{
    return keyBuffer[key];
}

void CS_Keyboard::SimuLayerSetKeyIsPressed(i8 key)
{
    keyBuffer[key] = csTrue;
}

void CS_Keyboard::SimuLayerSetKeyIsReleased(i8 key)
{
    keyBuffer[key] = csFalse;
}

void CS_Keyboard::SimuLayerSetKeyState(i8 key, csbool state)
{
    keyBuffer[key] = state;
}

string CS_Keyboard::GetStrStatus(){
    string str = "{";
    
    if(keyBuffer[CSK_Esc] == csTrue) str += "CSK_Esc, ";
    if(keyBuffer[CSK_F1] == csTrue) str += "CSK_F1, ";
    if(keyBuffer[CSK_F2] == csTrue) str += "CSK_F2, ";
    if(keyBuffer[CSK_F3] == csTrue) str += "CSK_F3, ";
    if(keyBuffer[CSK_F4] == csTrue) str += "CSK_F4, ";
    if(keyBuffer[CSK_F5] == csTrue) str += "CSK_F5, ";
    if(keyBuffer[CSK_F6] == csTrue) str += "CSK_F6, ";
    if(keyBuffer[CSK_F7] == csTrue) str += "CSK_F7, ";
    if(keyBuffer[CSK_F8] == csTrue) str += "CSK_F8, ";
    if(keyBuffer[CSK_F9] == csTrue) str += "CSK_F9, ";
    if(keyBuffer[CSK_F10] == csTrue) str += "CSK_F10, ";
    if(keyBuffer[CSK_F11] == csTrue) str += "CSK_F11, ";
    if(keyBuffer[CSK_F12] == csTrue) str += "CSK_F12, ";

    if(keyBuffer[CSK_BackQuote] == csTrue) str += "CSK_BackQuote, ";
    if(keyBuffer[CSK_Num1] == csTrue) str += "CSK_Num1, ";
    if(keyBuffer[CSK_Num2] == csTrue) str += "CSK_Num2, ";
    if(keyBuffer[CSK_Num3] == csTrue) str += "CSK_Num3, ";
    if(keyBuffer[CSK_Num4] == csTrue) str += "CSK_Num4, ";
    if(keyBuffer[CSK_Num5] == csTrue) str += "CSK_Num5, ";
    if(keyBuffer[CSK_Num6] == csTrue) str += "CSK_Num6, ";
    if(keyBuffer[CSK_Num7] == csTrue) str += "CSK_Num7, ";
    if(keyBuffer[CSK_Num8] == csTrue) str += "CSK_Num8, ";
    if(keyBuffer[CSK_Num9] == csTrue) str += "CSK_Num9, ";
    if(keyBuffer[CSK_Num0] == csTrue) str += "CSK_Num0, ";
    if(keyBuffer[CSK_Minus] == csTrue) str += "CSK_Minus, ";
    if(keyBuffer[CSK_Plus] == csTrue) str += "CSK_Plus, ";
    if(keyBuffer[CSK_Backspace] == csTrue) str += "CSK_Backspace, ";

    if(keyBuffer[CSK_Tab] == csTrue) str += "CSK_Tab, ";
    if(keyBuffer[CSK_Q] == csTrue) str += "CSK_Q, ";
    if(keyBuffer[CSK_W] == csTrue) str += "CSK_W, ";
    if(keyBuffer[CSK_E] == csTrue) str += "CSK_E, ";
    if(keyBuffer[CSK_R] == csTrue) str += "CSK_R, ";
    if(keyBuffer[CSK_T] == csTrue) str += "CSK_T, ";
    if(keyBuffer[CSK_Y] == csTrue) str += "CSK_Y, ";
    if(keyBuffer[CSK_U] == csTrue) str += "CSK_U, ";
    if(keyBuffer[CSK_I] == csTrue) str += "CSK_I, ";
    if(keyBuffer[CSK_O] == csTrue) str += "CSK_O, ";
    if(keyBuffer[CSK_P] == csTrue) str += "CSK_P, ";
    if(keyBuffer[CSK_LeftSquareBracket] == csTrue) str += "CSK_LeftSquareBracket, ";
    if(keyBuffer[CSK_RightSquareBracket] == csTrue) str += "CSK_RightSquareBracket, ";
    if(keyBuffer[CSK_BackSlash] == csTrue) str += "CSK_BackSlash, ";

    if(keyBuffer[CSK_CapsLock] == csTrue) str += "CSK_CapsLock, ";
    if(keyBuffer[CSK_A] == csTrue) str += "CSK_A, ";
    if(keyBuffer[CSK_S] == csTrue) str += "CSK_S, ";
    if(keyBuffer[CSK_D] == csTrue) str += "CSK_D, ";
    if(keyBuffer[CSK_F] == csTrue) str += "CSK_F, ";
    if(keyBuffer[CSK_G] == csTrue) str += "CSK_G, ";
    if(keyBuffer[CSK_H] == csTrue) str += "CSK_H, ";
    if(keyBuffer[CSK_J] == csTrue) str += "CSK_J, ";
    if(keyBuffer[CSK_K] == csTrue) str += "CSK_K, ";
    if(keyBuffer[CSK_L] == csTrue) str += "CSK_L, ";
    if(keyBuffer[CSK_Semicolon] == csTrue) str += "CSK_Semicolon, ";
    if(keyBuffer[CSK_Quote] == csTrue) str += "CSK_Quote, ";
    if(keyBuffer[CSK_Enter] == csTrue) str += "CSK_Enter, ";

    if(keyBuffer[CSK_Shift] == csTrue) str += "CSK_Shift, ";
    if(keyBuffer[CSK_Z] == csTrue) str += "CSK_Z, ";
    if(keyBuffer[CSK_X] == csTrue) str += "CSK_X, ";
    if(keyBuffer[CSK_C] == csTrue) str += "CSK_C, ";
    if(keyBuffer[CSK_V] == csTrue) str += "CSK_V, ";
    if(keyBuffer[CSK_B] == csTrue) str += "CSK_B, ";
    if(keyBuffer[CSK_N] == csTrue) str += "CSK_N, ";
    if(keyBuffer[CSK_M] == csTrue) str += "CSK_M, ";
    if(keyBuffer[CSK_Comma] == csTrue) str += "CSK_Comma, ";
    if(keyBuffer[CSK_FullStop] == csTrue) str += "CSK_FullStop, ";
    if(keyBuffer[CSK_Slash] == csTrue) str += "CSK_Slash, ";
    if(keyBuffer[CSK_RightShift] == csTrue) str += "CSK_RightShift, ";

    if(keyBuffer[CSK_Ctrl] == csTrue) str += "CSK_Ctrl, ";
    if(keyBuffer[CSK_Win] == csTrue) str += "CSK_Win, ";
    if(keyBuffer[CSK_Alt] == csTrue) str += "CSK_Alt, ";
    if(keyBuffer[CSK_Space] == csTrue) str += "CSK_Space, ";
    if(keyBuffer[CSK_RightAlt] == csTrue) str += "CSK_RightAlt, ";
    if(keyBuffer[CSK_RightCtrl] == csTrue) str += "CSK_RightCtrl, ";

    if(keyBuffer[CSK_Up] == csTrue) str += "CSK_Up, ";
    if(keyBuffer[CSK_Down] == csTrue) str += "CSK_Down, ";
    if(keyBuffer[CSK_Left] == csTrue) str += "CSK_Left, ";
    if(keyBuffer[CSK_Right] == csTrue) str += "CSK_Right, ";

    if(keyBuffer[CSK_Insert] == csTrue) str += "CSK_Insert, ";
    if(keyBuffer[CSK_Delete] == csTrue) str += "CSK_Delete, ";
    if(keyBuffer[CSK_Home] == csTrue) str += "CSK_Home, ";
    if(keyBuffer[CSK_End] == csTrue) str += "CSK_End, ";
    if(keyBuffer[CSK_PageUp] == csTrue) str += "CSK_PageUp, ";
    if(keyBuffer[CSK_PageDown] == csTrue) str += "CSK_PageDown, ";

    if(keyBuffer[CSK_PrintScreen] == csTrue) str += "CSK_PrintScreen, ";
    if(keyBuffer[CSK_ScrollLock] == csTrue) str += "CSK_ScrollLock, ";
    if(keyBuffer[CSK_PauseAndBreak] == csTrue) str += "CSK_PauseAndBreak, ";

    if(keyBuffer[CSK_Keypad0] == csTrue) str += "CSK_Keypad0, ";
    if(keyBuffer[CSK_Keypad1] == csTrue) str += "CSK_Keypad1, ";
    if(keyBuffer[CSK_Keypad2] == csTrue) str += "CSK_Keypad2, ";
    if(keyBuffer[CSK_Keypad3] == csTrue) str += "CSK_Keypad3, ";
    if(keyBuffer[CSK_Keypad4] == csTrue) str += "CSK_Keypad4, ";
    if(keyBuffer[CSK_Keypad5] == csTrue) str += "CSK_Keypad5, ";
    if(keyBuffer[CSK_Keypad6] == csTrue) str += "CSK_Keypad6, ";
    if(keyBuffer[CSK_Keypad7] == csTrue) str += "CSK_Keypad7, ";
    if(keyBuffer[CSK_Keypad8] == csTrue) str += "CSK_Keypad8, ";
    if(keyBuffer[CSK_Keypad9] == csTrue) str += "CSK_Keypad9, ";
    if(keyBuffer[CSK_KeypadDot] == csTrue) str += "CSK_KeypadDot, ";
    if(keyBuffer[CSK_KeypadNumLock] == csTrue) str += "CSK_KeypadNumLock, ";
    if(keyBuffer[CSK_KeypadEnter] == csTrue) str += "CSK_KeypadEnter, ";
    if(keyBuffer[CSK_KeypadAdd] == csTrue) str += "CSK_KeypadAdd, ";
    if(keyBuffer[CSK_KeypadMinus] == csTrue) str += "CSK_KeypadMinus, ";
    if(keyBuffer[CSK_KeypadMultiply] == csTrue) str += "CSK_KeypadMultiply, ";
    if(keyBuffer[CSK_MultiplyDevide] == csTrue) str += "CSK_MultiplyDevide, ";

    str += "}";
    return str;
}
