#ifndef __CSBF_BasicDataTypeDeclarations__
#define __CSBF_BasicDataTypeDeclarations__

#include <cstring>

/*
** Define Cross Platform Types
*/

typedef    unsigned int      ui32;    // Should be 32-bit 4-byte sign-less
typedef    signed   int      si32;    // Should be 32-bit 4-byte sign-ful
typedef    int                i32;    // Should be 32-bit 4-byte auto

typedef    unsigned short    ui16;    // Should be 16-bit 2-byte sign-less
typedef    signed   short    si16;    // Should be 16-bit 2-byte sign-ful
typedef    short              i16;    // Should be 16-bit 2-byte auto

typedef    unsigned char     ui8;     // Should be 16-bit 2-byte sign-less
typedef    signed   char     si8;     // Should be 16-bit 2-byte sign-ful
typedef    char               i8;     // Should be 16-bit 2-byte auto

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

#define    KEY_LBUTTON                1    // ������������̨��ʹ�ã�
#define    KEY_RBUTTON                2    // ����Ҽ�������̨��ʹ�ã�
#define    KEY_CANCEL                 3    // �����жϼ�������Ctrl+PauseBreak������̨��ʹ�ã�
#define    KEY_MBUTTON                4    // ����м�������̨��ʹ�ã�
#define    KEY_XBUTTON1               5    // ���X1���������ĸ�������ʵ���������������̨��ʹ�ã�
#define    KEY_XBUTTON2               6    // ���X2���������ĸ�������ʵ���������������̨��ʹ�ã�
#define    KEY_BACK                   8    // �˸��������Backspace
#define    KEY_TAB                    9    // �Ʊ���������Tab
#define    KEY_CLEAR                 12    // Clear����NumLock�ر�ʱ�����ּ���5
#define    KEY_RETURN                13    // �س���������Enter
#define    KEY_SHIFT                 16    // �ϵ���������Shift
#define    KEY_CONTROL               17    // ���Ƽ�������Ctrl
#define    KEY_MENU                  18    // ������������Alt
#define    KEY_PAUSE                 19    // �ж���ͣ��������PauseBreak
#define    KEY_CAPITAL               20    // ��Сд������������CapsLock
#define    KEY_KANA                  21    // ���뷨�༭����InputMethodEditor���IME������ģʽ
#define    KEY_HANGEUL               21    // ���뷨�༭������ģʽ���������ˣ�Ϊ�˼�����
#define    KEY_HANGUL                21    // ���뷨�༭������ģʽ���������ˣ�Ϊ�˼�����
#define    KEY_JUNJA                 23    // ���뷨�༭��junjaģʽ
#define    KEY_FINAL                 24    // ���뷨�༭��finalģʽ
#define    KEY_HANJA                 25    // ���뷨�༭������ģʽ
#define    KEY_KANJI                 25    // ���뷨�༭������ģʽ
#define    KEY_ESCAPE                27    // �˳���������Esc
#define    KEY_CONVERT               28    // IMEconvert
#define    KEY_NONCONVERT            29    // IMEnonconvert
#define    KEY_ACCEPT                30    // IMEaccept
#define    KEY_MODECHANGE            31    // IMEmodechangerequest
#define    KEY_SPACE                 32    // �ո��������SpaceBar
#define    KEY_PRIOR                 33    // ���Ϸ�ҳ��������PageUp
#define    KEY_NEXT                  34    // ���·�ҳ��������PageDown
#define    KEY_END                   35    // ��β��������End
#define    KEY_HOME                  36    // ��ʼ��������Home
#define    KEY_LEFT                  37    // ����������ǡ�
#define    KEY_UP                    38    // �Ϸ���������ǡ�
#define    KEY_RIGHT                 39    // �ҷ���������ǡ�
#define    KEY_DOWN                  40    // �·���������ǡ�
#define    KEY_SELECT                41    // Select��
#define    KEY_PRINT                 42    // Print��
#define    KEY_EXE                   43    // Excute��
#define    KEY_SNAPSHOT              44    // ��Ļ��ӡ��������PrintScreen
#define    KEY_INSERT                45    // �����������Insert
#define    KEY_DELETE                46    // ɾ����������Delete
#define    KEY_HELP                  47    // Help��
#define    KEY_LWIN                  91    // ��windows�ձ��������һ��������״���Ǹ���
#define    KEY_RWIN                  92    // ��windows�ձ��������һ��������״���Ǹ���
#define    KEY_APPS                  93    // Ӧ�ó���������ǰ�һ�µ����Ҽ��˵����Ǹ���
#define    KEY_SLEEP                 95    // ˯�߼�������Sleep
#define    KEY_NUMPAD0               96    // ���ּ���0��
#define    KEY_NUMPAD1               97    // ���ּ���1��
#define    KEY_NUMPAD2               98    // ���ּ���2��
#define    KEY_NUMPAD3               99    // ���ּ���3��
#define    KEY_NUMPAD4              100    // ���ּ���4��
#define    KEY_NUMPAD5              101    // ���ּ���5��
#define    KEY_NUMPAD6              102    // ���ּ���6��
#define    KEY_NUMPAD7              103    // ���ּ���7��
#define    KEY_NUMPAD8              104    // ���ּ���8��
#define    KEY_NUMPAD9              105    // ���ּ���9��
#define    KEY_MULTIPLY             106    // �˷������������ּ���*��
#define    KEY_ADD                  107    // �ӷ������������ּ���+��
#define    KEY_SEPARATOR            108    // Separator��
#define    KEY_SUBTRACT             109    // ���������������ּ���-��
#define    KEY_DECIMAL              110    // С��������������ּ���.��
#define    KEY_DIVIDE               111    // ���������������ּ���/��
#define    KEY_F1                   112    // ����1��������F1
#define    KEY_F2                   113    // ����2��������F2
#define    KEY_F3                   114    // ����3��������F3
#define    KEY_F4                   115    // ����4��������F4
#define    KEY_F5                   116    // ����5��������F5
#define    KEY_F6                   117    // ����6��������F6
#define    KEY_F7                   118    // ����7��������F7
#define    KEY_F8                   119    // ����8��������F8
#define    KEY_F9                   120    // ����9��������F9
#define    KEY_F10                  121    // ����10��������F10
#define    KEY_F11                  122    // ����11��������F11
#define    KEY_F12                  123    // ����12��������F12
#define    KEY_F13                  124    // ����13��������F13
#define    KEY_F14                  125    // ����14��������F14
#define    KEY_F15                  126    // ����15��������F15
#define    KEY_F16                  127    // ����16��������F16
#define    KEY_F17                  128    // ����17��������F17
#define    KEY_F18                  129    // ����18��������F18
#define    KEY_F19                  130    // ����19��������F19
#define    KEY_F20                  131    // ����20��������F20
#define    KEY_F21                  132    // ����21��������F21
#define    KEY_F22                  133    // ����22��������F22
#define    KEY_F23                  134    // ����23��������F23
#define    KEY_F24                  135    // ����24��������F24
#define    KEY_NUMLOCK              144    // ���ּ���������������NumLock
#define    KEY_SCROLL               145    // ����������������ScrollLock
#define    KEY_OEM_NEC_EQUAL        146    // NECPC-9800���̶�������ּ���=��
#define    KEY_OEM_FJ_JISHO         146    // Fujitsu/OASYS���̶����'Dictionary'��
#define    KEY_OEM_FJ_MASSHOU       147    // Fujitsu/OASYS���̶����'Unregisterword'��
#define    KEY_OEM_FJ_TOUROKU       148    // Fujitsu/OASYS���̶����'Registerword'��
#define    KEY_OEM_FJ_LOYA          149    // Fujitsu/OASYS���̶����'LeftOYAYUBI'��
#define    KEY_OEM_FJ_ROYA          150    // Fujitsu/OASYS���̶����'RightOYAYUBI'��
#define    KEY_LSHIFT               160    // ���ϵ���������Shift������ֻ̨ʹ��KEY_SHIFT������̨��ʹ�ã�
#define    KEY_RSHIFT               161    // ���ϵ���������Shift������ֻ̨ʹ��KEY_SHIFT������̨��ʹ�ã�
#define    KEY_LCONTROL             162    // ����Ƽ�������Ctrl������ֻ̨����KEY_CONTROL������̨��ʹ�ã�
#define    KEY_RCONTROL             163    // �ҿ��Ƽ�������Ctrl������ֻ̨����KEY_CONTROL������̨��ʹ�ã�
#define    KEY_LMENU                164    // �󻻵���������Alt������ֻ̨����KEY_MENU������̨��ʹ�ã�
#define    KEY_RMENU                165    // �һ�����������Alt������ֻ̨����KEY_MENU������̨��ʹ�ã�
#define    KEY_BROWSER_BACK         166    // ��������˼�
#define    KEY_BROWSER_FORWARD      167    // �����ǰ����
#define    KEY_BROWSER_REFRESH      168    // �����ˢ�¼�
#define    KEY_BROWSER_STOP         169    // �����ֹͣ��
#define    KEY_BROWSER_SEARCH       170    // ��������Ҽ�
#define    KEY_BROWSER_FAVORITES    171    // ������ղؼм�
#define    KEY_BROWSER_HOME         172    // �������ҳ��
#define    KEY_VOLUME_MUTE          173    // ����������
#define    KEY_VOLUME_DOWN          174    // �������ͼ�
#define    KEY_VOLUME_UP            175    // �������߼�
#define    KEY_MEDIA_NEXT_TRACK     176    // ý����һ��Ŀ��
#define    KEY_MEDIA_PREV_TRACK     177    // ý����һ��Ŀ��
#define    KEY_MEDIA_STOP           178    // ý��ֹͣ��
#define    KEY_MEDIA_PLAY_PAUSE     179    // ý�岥��/��ͣ��
#define    KEY_LAUNCH_MAIL          180    // �����ʼ���
#define    KEY_LAUNCH_MEDIA_SELECT  181    // ����ý��ѡ���
#define    KEY_LAUNCH_APP1          182    // ����Ӧ�ó���1��
#define    KEY_LAUNCH_APP2          183    // ����Ӧ�ó���2��
#define    KEY_OEM_1                186    // ����';:'��
#define    KEY_OEM_PLUS             187    // ����'=+'��
#define    KEY_OEM_COMMA            188    // ����',<'��
#define    KEY_OEM_MINUS            189    // ����'-_'��
#define    KEY_OEM_PERIOD           190    // ����'.>'��
#define    KEY_OEM_2                191    // ����'/?'��
#define    KEY_OEM_3                192    // ����'`~'��
#define    KEY_OEM_4                219    // ����'[{'��
#define    KEY_OEM_5                220    // ����'|'��
#define    KEY_OEM_6                221    // ����']}'��
#define    KEY_OEM_7                222    // ����''"'��
#define    KEY_OEM_8                223    // ���������ַ�����ͬ�ļ��̲�һ��һ��
#define    KEY_OEM_AX               225    // �ձ�AX���̵�'AX'��
#define    KEY_OEM_102              226    // RT102-key���̵�"<>"��"|"��
#define    KEY_ICO_HELP             227    // ����ͼ���
#define    KEY_ICO_00               228    // 00ͼ���
#define    KEY_PROCESSKEY           229    // IMEPROCESS��
#define    KEY_ICO_CLEAR            230    // Clearͼ���
#define    KEY_PACKET               231    // ��̫�����ʲô��˼
#define    KEY_OEM_RESET            233    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_JUMP             234    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_PA1              235    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_PA2              236    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_PA3              237    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_WSCTRL           238    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_CUSEL            239    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_ATTN             240    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_FINISH           241    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_COPY             242    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_AUTO             243    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_ENLW             244    // ŵ���ǡ�������ʹ�õ�
#define    KEY_OEM_BACKTAB          245    // ŵ���ǡ�������ʹ�õ�
#define    KEY_ATTN                 246    // Attn��
#define    KEY_CRSEL                247    // CrSel��
#define    KEY_EXSEL                248    // ExSel��
#define    KEY_EREOF                249    // EraseEOF��
#define    KEY_PLAY                 250    // Play��
#define    KEY_ZOOM                 251    // Zoom��
#define    KEY_NONAME               252    // δ��
#define    KEY_PA1                  253    // PA1��
#define    KEY_OEM_CLEAR            254    // Clear��

#endif
