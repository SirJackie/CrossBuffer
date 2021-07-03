#include "KeyboardHelper.h"

LSL_KeyboardHelper::LSL_KeyboardHelper()
{
	CS_Memset(linuxKeyBuffer, 0, 256);
}

void LSL_KeyboardHelper::MoveLnxBufIntoKeyBuf()
{
	kb.SimuLayerSetKeyState(CSK_Esc, linuxKeyBuffer[27]);
	kb.SimuLayerSetKeyState(CSK_F1, linuxKeyBuffer[112]);
	kb.SimuLayerSetKeyState(CSK_F2, linuxKeyBuffer[113]);
	kb.SimuLayerSetKeyState(CSK_F3, linuxKeyBuffer[114]);
	kb.SimuLayerSetKeyState(CSK_F4, linuxKeyBuffer[115]);
	kb.SimuLayerSetKeyState(CSK_F5, linuxKeyBuffer[116]);
	kb.SimuLayerSetKeyState(CSK_F6, linuxKeyBuffer[117]);
	kb.SimuLayerSetKeyState(CSK_F7, linuxKeyBuffer[118]);
	kb.SimuLayerSetKeyState(CSK_F8, linuxKeyBuffer[119]);
	kb.SimuLayerSetKeyState(CSK_F9, linuxKeyBuffer[120]);
	// kb.SimuLayerSetKeyState(CSK_F10, linuxKeyBuffer[26]);
	// kb.SimuLayerSetKeyState(CSK_F11, linuxKeyBuffer[28]);
	// kb.SimuLayerSetKeyState(CSK_F12, linuxKeyBuffer[29]);

	// kb.SimuLayerSetKeyState(CSK_BackQuote, linuxKeyBuffer[25]);
	kb.SimuLayerSetKeyState(CSK_Num1, linuxKeyBuffer[49]);
	kb.SimuLayerSetKeyState(CSK_Num2, linuxKeyBuffer[50]);
	kb.SimuLayerSetKeyState(CSK_Num3, linuxKeyBuffer[51]);
	kb.SimuLayerSetKeyState(CSK_Num4, linuxKeyBuffer[52]);
	kb.SimuLayerSetKeyState(CSK_Num5, linuxKeyBuffer[53]);
	kb.SimuLayerSetKeyState(CSK_Num6, linuxKeyBuffer[54]);
	kb.SimuLayerSetKeyState(CSK_Num7, linuxKeyBuffer[55]);
	kb.SimuLayerSetKeyState(CSK_Num8, linuxKeyBuffer[56]);
	kb.SimuLayerSetKeyState(CSK_Num9, linuxKeyBuffer[57]);
	kb.SimuLayerSetKeyState(CSK_Num0, linuxKeyBuffer[48]);
	// kb.SimuLayerSetKeyState(CSK_Minus, linuxKeyBuffer[10]);
	// kb.SimuLayerSetKeyState(CSK_Plus, linuxKeyBuffer[11]);
	kb.SimuLayerSetKeyState(CSK_Backspace, linuxKeyBuffer[8]);

	kb.SimuLayerSetKeyState(CSK_Tab, linuxKeyBuffer[9]);
	kb.SimuLayerSetKeyState(CSK_Q, linuxKeyBuffer[81]);
	kb.SimuLayerSetKeyState(CSK_W, linuxKeyBuffer[87]);
	kb.SimuLayerSetKeyState(CSK_E, linuxKeyBuffer[69]);
	kb.SimuLayerSetKeyState(CSK_R, linuxKeyBuffer[82]);
	kb.SimuLayerSetKeyState(CSK_T, linuxKeyBuffer[84]);
	kb.SimuLayerSetKeyState(CSK_Y, linuxKeyBuffer[89]);
	kb.SimuLayerSetKeyState(CSK_U, linuxKeyBuffer[85]);
	kb.SimuLayerSetKeyState(CSK_I, linuxKeyBuffer[73]);
	kb.SimuLayerSetKeyState(CSK_O, linuxKeyBuffer[79]);
	kb.SimuLayerSetKeyState(CSK_P, linuxKeyBuffer[80]);
	// kb.SimuLayerSetKeyState(CSK_LeftSquareBracket, linuxKeyBuffer[12]);
	// kb.SimuLayerSetKeyState(CSK_RightSquareBracket, linuxKeyBuffer[14]);
	// kb.SimuLayerSetKeyState(CSK_BackSlash, linuxKeyBuffer[15]);

	kb.SimuLayerSetKeyState(CSK_CapsLock, linuxKeyBuffer[20]);
	kb.SimuLayerSetKeyState(CSK_A, linuxKeyBuffer[65]);
	kb.SimuLayerSetKeyState(CSK_S, linuxKeyBuffer[83]);
	kb.SimuLayerSetKeyState(CSK_D, linuxKeyBuffer[68]);
	kb.SimuLayerSetKeyState(CSK_F, linuxKeyBuffer[70]);
	kb.SimuLayerSetKeyState(CSK_G, linuxKeyBuffer[71]);
	kb.SimuLayerSetKeyState(CSK_H, linuxKeyBuffer[72]);
	kb.SimuLayerSetKeyState(CSK_J, linuxKeyBuffer[74]);
	kb.SimuLayerSetKeyState(CSK_K, linuxKeyBuffer[75]);
	kb.SimuLayerSetKeyState(CSK_L, linuxKeyBuffer[76]);
	// kb.SimuLayerSetKeyState(CSK_Semicolon, linuxKeyBuffer[18]);
	// kb.SimuLayerSetKeyState(CSK_Quote, linuxKeyBuffer[21]);
	kb.SimuLayerSetKeyState(CSK_Enter, linuxKeyBuffer[13]);

	kb.SimuLayerSetKeyState(CSK_Shift, linuxKeyBuffer[16]);
	kb.SimuLayerSetKeyState(CSK_Z, linuxKeyBuffer[90]);
	kb.SimuLayerSetKeyState(CSK_X, linuxKeyBuffer[88]);
	kb.SimuLayerSetKeyState(CSK_C, linuxKeyBuffer[67]);
	kb.SimuLayerSetKeyState(CSK_V, linuxKeyBuffer[86]);
	kb.SimuLayerSetKeyState(CSK_B, linuxKeyBuffer[66]);
	kb.SimuLayerSetKeyState(CSK_N, linuxKeyBuffer[78]);
	kb.SimuLayerSetKeyState(CSK_M, linuxKeyBuffer[77]);
	// kb.SimuLayerSetKeyState(CSK_Comma, linuxKeyBuffer[22]);
	// kb.SimuLayerSetKeyState(CSK_FullStop, linuxKeyBuffer[23]);
	// kb.SimuLayerSetKeyState(CSK_Slash, linuxKeyBuffer[24]);
	// kb.SimuLayerSetKeyState(CSK_RightShift, linuxKeyBuffer[123]);

	kb.SimuLayerSetKeyState(CSK_Ctrl, linuxKeyBuffer[17]);
	kb.SimuLayerSetKeyState(CSK_Win, linuxKeyBuffer[91]);
	// kb.SimuLayerSetKeyState(CSK_Alt, linuxKeyBuffer[125]);
	kb.SimuLayerSetKeyState(CSK_Space, linuxKeyBuffer[32]);
	// kb.SimuLayerSetKeyState(CSK_RightAlt, linuxKeyBuffer[126]);
	// kb.SimuLayerSetKeyState(CSK_RightCtrl, linuxKeyBuffer[124]);

	kb.SimuLayerSetKeyState(CSK_Up, linuxKeyBuffer[38]);
	kb.SimuLayerSetKeyState(CSK_Down, linuxKeyBuffer[40]);
	kb.SimuLayerSetKeyState(CSK_Left, linuxKeyBuffer[37]);
	kb.SimuLayerSetKeyState(CSK_Right, linuxKeyBuffer[39]);

	kb.SimuLayerSetKeyState(CSK_Insert, linuxKeyBuffer[45]);
	kb.SimuLayerSetKeyState(CSK_Delete, linuxKeyBuffer[46]);
	kb.SimuLayerSetKeyState(CSK_Home, linuxKeyBuffer[36]);
	kb.SimuLayerSetKeyState(CSK_End, linuxKeyBuffer[35]);
	kb.SimuLayerSetKeyState(CSK_PageUp, linuxKeyBuffer[33]);
	kb.SimuLayerSetKeyState(CSK_PageDown, linuxKeyBuffer[34]);

	// kb.SimuLayerSetKeyState(CSK_PrintScreen, linuxKeyBuffer[30]);
	// kb.SimuLayerSetKeyState(CSK_ScrollLock, linuxKeyBuffer[31]);
	kb.SimuLayerSetKeyState(CSK_PauseAndBreak, linuxKeyBuffer[19]);

	kb.SimuLayerSetKeyState(CSK_Keypad0, linuxKeyBuffer[96]);
	kb.SimuLayerSetKeyState(CSK_Keypad1, linuxKeyBuffer[97]);
	kb.SimuLayerSetKeyState(CSK_Keypad2, linuxKeyBuffer[98]);
	kb.SimuLayerSetKeyState(CSK_Keypad3, linuxKeyBuffer[99]);
	kb.SimuLayerSetKeyState(CSK_Keypad4, linuxKeyBuffer[100]);
	kb.SimuLayerSetKeyState(CSK_Keypad5, linuxKeyBuffer[101]);
	kb.SimuLayerSetKeyState(CSK_Keypad6, linuxKeyBuffer[102]);
	kb.SimuLayerSetKeyState(CSK_Keypad7, linuxKeyBuffer[103]);
	kb.SimuLayerSetKeyState(CSK_Keypad8, linuxKeyBuffer[104]);
	kb.SimuLayerSetKeyState(CSK_Keypad9, linuxKeyBuffer[105]);
	kb.SimuLayerSetKeyState(CSK_KeypadDot, linuxKeyBuffer[110]);
	// kb.SimuLayerSetKeyState(CSK_KeypadNumLock, linuxKeyBuffer[122]);
	// kb.SimuLayerSetKeyState(CSK_KeypadEnter, linuxKeyBuffer[121]);
	kb.SimuLayerSetKeyState(CSK_KeypadAdd, linuxKeyBuffer[107]);
	kb.SimuLayerSetKeyState(CSK_KeypadMinus, linuxKeyBuffer[109]);
	kb.SimuLayerSetKeyState(CSK_KeypadMultiply, linuxKeyBuffer[106]);
	kb.SimuLayerSetKeyState(CSK_MultiplyDevide, linuxKeyBuffer[111]);
}
