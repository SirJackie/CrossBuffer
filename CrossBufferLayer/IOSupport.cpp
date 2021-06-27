#include "IOSupport.h"

Keyboard::Keyboard()
{
    for (i32 i = 0; i < 256; i++) {
        keyBuffer[i] = csFalse;
    }
}

csbool Keyboard::IsKeyPressed(i8 key)
{
    return keyBuffer[key];
}

void Keyboard::HardwareSimuSetKeyIsPressed(i8 key)
{
    keyBuffer[key] = csTrue;
}

void Keyboard::HardwareSimuSetKeyIsReleased(i8 key)
{
    keyBuffer[key] = csFalse;
}
