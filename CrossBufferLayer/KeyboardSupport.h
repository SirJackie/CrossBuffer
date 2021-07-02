#ifndef __CSBF_KeyboardSupport__
#define __CSBF_KeyboardSupport__

#include "BasicDataTypeDeclarations.h"


class CS_Keyboard {
private:
	csbool keyBuffer[256];
public:
	CS_Keyboard();
	csbool IsKeyPressed(i8 key);
	void   SimuLayerSetKeyIsPressed(i8 key);
	void   SimuLayerSetKeyIsReleased(i8 key);
};


/*
** Unique Cross-platformed Global Keyboard Index Declaration
*/

#define CSK_Esc                     27
#define CSK_F1                      112
#define CSK_F2                      113
#define CSK_F3                      114
#define CSK_F4                      115
#define CSK_F5                      116
#define CSK_F6                      117
#define CSK_F7                      118
#define CSK_F8                      119
#define CSK_F9                      120
#define CSK_F10                     121
#define CSK_F11                     122
#define CSK_F12                     123
#define CSK_BackQuote               58
#define CSK_Num1                    49
#define CSK_Num2                    50
#define CSK_Num3                    51
#define CSK_Num4                    52
#define CSK_Num5                    53
#define CSK_Num6                    54
#define CSK_Num7                    55
#define CSK_Num8                    56
#define CSK_Num9                    57
#define CSK_Num0                    58
#define CSK_Minus                   59
#define CSK_Plus                    60
#define CSK_Backspace               8
#define CSK_Tab                     9
#define CSK_Q                       81
#define CSK_W                       87
#define CSK_E                       69
#define CSK_R                       82
#define CSK_T                       84
#define CSK_Y                       89
#define CSK_U                       85
#define CSK_I                       73
#define CSK_O                       79
#define CSK_P                       80
#define CSK_LeftSquareBracket       92
#define CSK_RightSquareBracket      93
#define CSK_BackSlash               94
#define CSK_CapsLock                20
#define CSK_A                       65
#define CSK_S                       83
#define CSK_D                       68
#define CSK_F                       70
#define CSK_G                       71
#define CSK_H                       72
#define CSK_J                       74
#define CSK_K                       75
#define CSK_L                       76
#define CSK_Semicolon               95
#define CSK_Quote                   96
#define CSK_Enter                   13
#define CSK_Shift                   16
#define CSK_Z                       90
#define CSK_X                       88
#define CSK_C                       67
#define CSK_V                       86
#define CSK_B                       66
#define CSK_N                       78
#define CSK_M                       77
#define CSK_Comma                   97
#define CSK_FullStop                98
#define CSK_Slash                   99
#define CSK_RightShift              103
#define CSK_Ctrl                    100
#define CSK_Win                     91
#define CSK_Alt                     101
#define CSK_Space                   32
#define CSK_RightAlt                102
#define CSK_RightCtrl               104
#define CSK_Up                      38
#define CSK_Down                    40
#define CSK_Left                    37
#define CSK_Right                   39
#define CSK_Insert                  45
#define CSK_Delete                  46


#endif
