#ifndef __CSBF_BasicDataTypeDeclarations__
#define __CSBF_BasicDataTypeDeclarations__

#include <cstring>

/*
** Define Cross Platform Types
*/

typedef    unsigned int      ui32;    // Should be 32-bit 4-byte sign-less
typedef    signed   int      i32;     // Should be 32-bit 4-byte sign-ful

typedef    unsigned short    ui16;    // Should be 16-bit 2-byte sign-less
typedef    signed   short    i16;     // Should be 16-bit 2-byte sign-ful

typedef    unsigned char     ui8;     // Should be 16-bit 2-byte sign-less
typedef    signed   char     i8;      // Should be 16-bit 2-byte sign-ful

typedef    double            f64;     // Should be 64-bit 8-byte float
typedef    float             f32;     // Should be 32-bit 4-byte float

typedef    char              csbool;  // Boolean value, no matter what
#define    csTrue            1
#define    csFalse           0

#define    csNull            NULL
#define    csNullPtr         nullptr

/*
** Define Mathematics Functions
*/

i32 CS_iclamp(i32 min, i32 x, i32 max);
f32 CS_fclamp(f32 min, f32 x, f32 max);

using std::memset;
void CS_Memset(void* ptr, i8 fillingContent, i32 length);


/*
** Systematic Keyboard Index Declaration
*/

#define    KEY_LBUTTON                1    // 鼠标左键（控制台不使用）
#define    KEY_RBUTTON                2    // 鼠标右键（控制台不使用）
#define    KEY_CANCEL                 3    // 控制中断键，就是Ctrl+PauseBreak（控制台不使用）
#define    KEY_MBUTTON                4    // 鼠标中键（控制台不使用）
#define    KEY_XBUTTON1               5    // 鼠标X1键，具体哪个键根据实际情况而定（控制台不使用）
#define    KEY_XBUTTON2               6    // 鼠标X2键，具体哪个键根据实际情况而定（控制台不使用）
#define    KEY_BACK                   8    // 退格键，就是Backspace
#define    KEY_TAB                    9    // 制表键，就是Tab
#define    KEY_CLEAR                 12    // Clear键，NumLock关闭时的数字键盘5
#define    KEY_RETURN                13    // 回车键，就是Enter
#define    KEY_SHIFT                 16    // 上档键，就是Shift
#define    KEY_CONTROL               17    // 控制键，就是Ctrl
#define    KEY_MENU                  18    // 换挡键，就是Alt
#define    KEY_PAUSE                 19    // 中断暂停键，就是PauseBreak
#define    KEY_CAPITAL               20    // 大小写锁定键，就是CapsLock
#define    KEY_KANA                  21    // 输入法编辑器（InputMethodEditor简称IME）假名模式
#define    KEY_HANGEUL               21    // 输入法编辑器假名模式，老名字了，为了兼容性
#define    KEY_HANGUL                21    // 输入法编辑器假名模式，老名字了，为了兼容性
#define    KEY_JUNJA                 23    // 输入法编辑器junja模式
#define    KEY_FINAL                 24    // 输入法编辑器final模式
#define    KEY_HANJA                 25    // 输入法编辑器汉字模式
#define    KEY_KANJI                 25    // 输入法编辑器汉字模式
#define    KEY_ESCAPE                27    // 退出键，就是Esc
#define    KEY_CONVERT               28    // IMEconvert
#define    KEY_NONCONVERT            29    // IMEnonconvert
#define    KEY_ACCEPT                30    // IMEaccept
#define    KEY_MODECHANGE            31    // IMEmodechangerequest
#define    KEY_SPACE                 32    // 空格键，就是SpaceBar
#define    KEY_PRIOR                 33    // 向上翻页键，就是PageUp
#define    KEY_NEXT                  34    // 向下翻页键，就是PageDown
#define    KEY_END                   35    // 结尾键，就是End
#define    KEY_HOME                  36    // 起始键，就是Home
#define    KEY_LEFT                  37    // 左方向键，就是←
#define    KEY_UP                    38    // 上方向键，就是↑
#define    KEY_RIGHT                 39    // 右方向键，就是→
#define    KEY_DOWN                  40    // 下方向键，就是↓
#define    KEY_SELECT                41    // Select键
#define    KEY_PRINT                 42    // Print键
#define    KEY_EXE                   43    // Excute键
#define    KEY_SNAPSHOT              44    // 屏幕打印键，就是PrintScreen
#define    KEY_INSERT                45    // 插入键，就是Insert
#define    KEY_DELETE                46    // 删除键，就是Delete
#define    KEY_HELP                  47    // Help键
#define    KEY_LWIN                  91    // 左windows徽标键，就是一个窗口形状的那个键
#define    KEY_RWIN                  92    // 右windows徽标键，就是一个窗口形状的那个键
#define    KEY_APPS                  93    // 应用程序键，就是按一下弹出右键菜单的那个键
#define    KEY_SLEEP                 95    // 睡眠键，就是Sleep
#define    KEY_NUMPAD0               96    // 数字键盘0键
#define    KEY_NUMPAD1               97    // 数字键盘1键
#define    KEY_NUMPAD2               98    // 数字键盘2键
#define    KEY_NUMPAD3               99    // 数字键盘3键
#define    KEY_NUMPAD4              100    // 数字键盘4键
#define    KEY_NUMPAD5              101    // 数字键盘5键
#define    KEY_NUMPAD6              102    // 数字键盘6键
#define    KEY_NUMPAD7              103    // 数字键盘7键
#define    KEY_NUMPAD8              104    // 数字键盘8键
#define    KEY_NUMPAD9              105    // 数字键盘9键
#define    KEY_MULTIPLY             106    // 乘法键，就是数字键盘*键
#define    KEY_ADD                  107    // 加法键，就是数字键盘+键
#define    KEY_SEPARATOR            108    // Separator键
#define    KEY_SUBTRACT             109    // 减法键，就是数字键盘-键
#define    KEY_DECIMAL              110    // 小数点键，就是数字键盘.键
#define    KEY_DIVIDE               111    // 除法键，就是数字键盘/键
#define    KEY_F1                   112    // 功能1键，就是F1
#define    KEY_F2                   113    // 功能2键，就是F2
#define    KEY_F3                   114    // 功能3键，就是F3
#define    KEY_F4                   115    // 功能4键，就是F4
#define    KEY_F5                   116    // 功能5键，就是F5
#define    KEY_F6                   117    // 功能6键，就是F6
#define    KEY_F7                   118    // 功能7键，就是F7
#define    KEY_F8                   119    // 功能8键，就是F8
#define    KEY_F9                   120    // 功能9键，就是F9
#define    KEY_F10                  121    // 功能10键，就是F10
#define    KEY_F11                  122    // 功能11键，就是F11
#define    KEY_F12                  123    // 功能12键，就是F12
#define    KEY_F13                  124    // 功能13键，就是F13
#define    KEY_F14                  125    // 功能14键，就是F14
#define    KEY_F15                  126    // 功能15键，就是F15
#define    KEY_F16                  127    // 功能16键，就是F16
#define    KEY_F17                  128    // 功能17键，就是F17
#define    KEY_F18                  129    // 功能18键，就是F18
#define    KEY_F19                  130    // 功能19键，就是F19
#define    KEY_F20                  131    // 功能20键，就是F20
#define    KEY_F21                  132    // 功能21键，就是F21
#define    KEY_F22                  133    // 功能22键，就是F22
#define    KEY_F23                  134    // 功能23键，就是F23
#define    KEY_F24                  135    // 功能24键，就是F24
#define    KEY_NUMLOCK              144    // 数字键盘锁定键，就是NumLock
#define    KEY_SCROLL               145    // 滚动锁定键，就是ScrollLock
#define    KEY_OEM_NEC_EQUAL        146    // NECPC-9800键盘定义的数字键盘=键
#define    KEY_OEM_FJ_JISHO         146    // Fujitsu/OASYS键盘定义的'Dictionary'键
#define    KEY_OEM_FJ_MASSHOU       147    // Fujitsu/OASYS键盘定义的'Unregisterword'键
#define    KEY_OEM_FJ_TOUROKU       148    // Fujitsu/OASYS键盘定义的'Registerword'键
#define    KEY_OEM_FJ_LOYA          149    // Fujitsu/OASYS键盘定义的'LeftOYAYUBI'键
#define    KEY_OEM_FJ_ROYA          150    // Fujitsu/OASYS键盘定义的'RightOYAYUBI'键
#define    KEY_LSHIFT               160    // 左上档键，就是Shift，控制台只使用KEY_SHIFT（控制台不使用）
#define    KEY_RSHIFT               161    // 右上档键，就是Shift，控制台只使用KEY_SHIFT（控制台不使用）
#define    KEY_LCONTROL             162    // 左控制键，就是Ctrl，控制台只是用KEY_CONTROL（控制台不使用）
#define    KEY_RCONTROL             163    // 右控制键，就是Ctrl，控制台只是用KEY_CONTROL（控制台不使用）
#define    KEY_LMENU                164    // 左换挡键，就是Alt，控制台只是用KEY_MENU（控制台不使用）
#define    KEY_RMENU                165    // 右换挡键，就是Alt，控制台只是用KEY_MENU（控制台不使用）
#define    KEY_BROWSER_BACK         166    // 浏览器后退键
#define    KEY_BROWSER_FORWARD      167    // 浏览器前进键
#define    KEY_BROWSER_REFRESH      168    // 浏览器刷新键
#define    KEY_BROWSER_STOP         169    // 浏览器停止键
#define    KEY_BROWSER_SEARCH       170    // 浏览器查找键
#define    KEY_BROWSER_FAVORITES    171    // 浏览器收藏夹键
#define    KEY_BROWSER_HOME         172    // 浏览器主页键
#define    KEY_VOLUME_MUTE          173    // 音量静音键
#define    KEY_VOLUME_DOWN          174    // 音量调低键
#define    KEY_VOLUME_UP            175    // 音量调高键
#define    KEY_MEDIA_NEXT_TRACK     176    // 媒体下一曲目键
#define    KEY_MEDIA_PREV_TRACK     177    // 媒体上一曲目键
#define    KEY_MEDIA_STOP           178    // 媒体停止键
#define    KEY_MEDIA_PLAY_PAUSE     179    // 媒体播放/暂停键
#define    KEY_LAUNCH_MAIL          180    // 启动邮件键
#define    KEY_LAUNCH_MEDIA_SELECT  181    // 启动媒体选择键
#define    KEY_LAUNCH_APP1          182    // 启动应用程序1键
#define    KEY_LAUNCH_APP2          183    // 启动应用程序2键
#define    KEY_OEM_1                186    // 符号';:'键
#define    KEY_OEM_PLUS             187    // 符号'=+'键
#define    KEY_OEM_COMMA            188    // 符号',<'键
#define    KEY_OEM_MINUS            189    // 符号'-_'键
#define    KEY_OEM_PERIOD           190    // 符号'.>'键
#define    KEY_OEM_2                191    // 符号'/?'键
#define    KEY_OEM_3                192    // 符号'`~'键
#define    KEY_OEM_4                219    // 符号'[{'键
#define    KEY_OEM_5                220    // 符号'|'键
#define    KEY_OEM_6                221    // 符号']}'键
#define    KEY_OEM_7                222    // 符号''"'键
#define    KEY_OEM_8                223    // 用于其他字符，不同的键盘不一定一样
#define    KEY_OEM_AX               225    // 日本AX键盘的'AX'键
#define    KEY_OEM_102              226    // RT102-key键盘的"<>"或"|"键
#define    KEY_ICO_HELP             227    // 帮助图标键
#define    KEY_ICO_00               228    // 00图标键
#define    KEY_PROCESSKEY           229    // IMEPROCESS键
#define    KEY_ICO_CLEAR            230    // Clear图标键
#define    KEY_PACKET               231    // 不太清楚是什么意思
#define    KEY_OEM_RESET            233    // 诺基亚、爱立信使用的
#define    KEY_OEM_JUMP             234    // 诺基亚、爱立信使用的
#define    KEY_OEM_PA1              235    // 诺基亚、爱立信使用的
#define    KEY_OEM_PA2              236    // 诺基亚、爱立信使用的
#define    KEY_OEM_PA3              237    // 诺基亚、爱立信使用的
#define    KEY_OEM_WSCTRL           238    // 诺基亚、爱立信使用的
#define    KEY_OEM_CUSEL            239    // 诺基亚、爱立信使用的
#define    KEY_OEM_ATTN             240    // 诺基亚、爱立信使用的
#define    KEY_OEM_FINISH           241    // 诺基亚、爱立信使用的
#define    KEY_OEM_COPY             242    // 诺基亚、爱立信使用的
#define    KEY_OEM_AUTO             243    // 诺基亚、爱立信使用的
#define    KEY_OEM_ENLW             244    // 诺基亚、爱立信使用的
#define    KEY_OEM_BACKTAB          245    // 诺基亚、爱立信使用的
#define    KEY_ATTN                 246    // Attn键
#define    KEY_CRSEL                247    // CrSel键
#define    KEY_EXSEL                248    // ExSel键
#define    KEY_EREOF                249    // EraseEOF键
#define    KEY_PLAY                 250    // Play键
#define    KEY_ZOOM                 251    // Zoom键
#define    KEY_NONAME               252    // 未用
#define    KEY_PA1                  253    // PA1键
#define    KEY_OEM_CLEAR            254    // Clear键

#endif
