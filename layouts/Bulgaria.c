#include "Bulgaria.h"

#ifdef __cplusplus
extern "C"{
#endif

#define BULGARIA_VK_LAUNCH_MEDIA_SELECT 0xe06d
#define BULGARIA_VK_LAUNCH_MAIL        0xe06c
#define BULGARIA_VK_LAUNCH_APP1        0xe06b
#define BULGARIA_VK_BROWSER_STOP       0xe068
#define BULGARIA_VK_APPS               0xe05d
#define BULGARIA_VK_F20                0x6b
#define BULGARIA_VK_BROWSER_REFRESH    0xe067
#define BULGARIA_VK_MULTIPLY           0x37
#define BULGARIA_VK_LCONTROL           0x1d
#define BULGARIA_VK_LMENU              0x38
#define BULGARIA_VK_M                  0x32
#define BULGARIA_VK_END                0x4f
#define BULGARIA_VK_N                  0x31
#define BULGARIA_VK_B                  0x30
#define BULGARIA_VK_C                  0x2e
#define BULGARIA_VK_X                  0x2d
#define BULGARIA_VK_OEM_7              0x28
#define BULGARIA_VK_E                  0x12
#define BULGARIA_VK_MEDIA_NEXT_TRACK   0xe019
#define BULGARIA_VK_Z                  0x2c
#define BULGARIA_VK_K                  0x25
#define BULGARIA_VK_OEM_JUMP           0x5c
#define BULGARIA_VK_G                  0x22
#define BULGARIA_VK_J                  0x24
#define BULGARIA_VK_DBE_FLUSHSTRING    0x5d
#define BULGARIA_VK_D                  0x20
#define BULGARIA_VK_PAUSE              0xe11d
#define BULGARIA_VK_S                  0x1f
#define BULGARIA_VK_OEM_6              0x1b
#define BULGARIA_VK_ABNT_C2            0x7e
#define BULGARIA_VK_BROWSER_BACK       0xe06a
#define BULGARIA_VK_8                  0x9
#define BULGARIA_VK_CANCEL             0xe046
#define BULGARIA_VK_7                  0x8
#define BULGARIA_VK_6                  0x7
#define BULGARIA_VK_F23                0x6e
#define BULGARIA_VK_T                  0x14
#define BULGARIA_VK_LSHIFT             0x2a
#define BULGARIA_VK_A                  0x1e
#define BULGARIA_VK_OEM_PERIOD         0xd
#define BULGARIA_VK_F12                0x58
#define BULGARIA_VK_OEM_8              0x33
#define BULGARIA_VK_Q                  0x34
#define BULGARIA_VK_R                  0x13
#define BULGARIA_VK_OEM_COMMA          0x10
#define BULGARIA_VK_F1                 0x3b
#define BULGARIA_VK_BROWSER_FORWARD    0xe069
#define BULGARIA_VK_U                  0x16
#define BULGARIA_VK_V                  0x2f
#define BULGARIA_VK_Y                  0x15
#define BULGARIA_VK_F                  0x21
#define BULGARIA_VK_F4                 0x3e
#define BULGARIA_VK_F19                0x6a
#define BULGARIA_VK_OEM_MINUS          0xc
#define BULGARIA_VK_BACK               0xe
#define BULGARIA_VK_4                  0x5
#define BULGARIA_VK_W                  0x11
#define BULGARIA_VK_F5                 0x3f
#define BULGARIA_VK_ADD                0x4e
#define BULGARIA_VK_OEM_4              0x1a
#define BULGARIA_VK_P                  0x19
#define BULGARIA_VK_MEDIA_PREV_TRACK   0xe010
#define BULGARIA_VK_1                  0x2
#define BULGARIA_VK_RMENU              0xe038
#define BULGARIA_VK_OEM_3              0x29
#define BULGARIA_VK_OEM_5              0x2b
#define BULGARIA_VK_TAB                0xf
#define BULGARIA_VK_H                  0x23
#define BULGARIA_VK_ESCAPE             0x1
#define BULGARIA_VK_DELETE             0x53
#define BULGARIA_VK_OEM_PA1            0x7b
#define BULGARIA_VK_L                  0x26
#define BULGARIA_VK_HELP               0x63
#define BULGARIA_VK_9                  0xa
#define BULGARIA_VK_I                  0x17
#define BULGARIA_VK_RIGHT              0x4d
#define BULGARIA_VK_RCONTROL           0xe01d
#define BULGARIA_VK_F2                 0x3c
#define BULGARIA_VK_F3                 0x3d
#define BULGARIA_VK_F15                0x66
#define BULGARIA_VK_F6                 0x40
#define BULGARIA_VK_3                  0x4
#define BULGARIA_VK_F8                 0x42
#define BULGARIA_VK_F9                 0x43
#define BULGARIA_VK_OEM_2              0x35
#define BULGARIA_VK_F10                0x44
#define BULGARIA_VK_5                  0x6
#define BULGARIA_VK_2                  0x3
#define BULGARIA_VK_NUMLOCK            0x45
#define BULGARIA_VK_VOLUME_UP          0xe030
#define BULGARIA_VK_MEDIA_PLAY_PAUSE   0xe022
#define BULGARIA_VK_SCROLL             0x46
#define BULGARIA_VK_BROWSER_FAVORITES  0xe066
#define BULGARIA_VK_SPACE              0x39
#define BULGARIA_VK_O                  0x18
#define BULGARIA_VK_HOME               0x47
#define BULGARIA_VK_UP                 0x48
#define BULGARIA_VK_PRIOR              0x49
#define BULGARIA_VK_F22                0x6d
#define BULGARIA_VK_F18                0x69
#define BULGARIA_VK_OEM_RESET          0x71
#define BULGARIA_VK_SUBTRACT           0x4a
#define BULGARIA_VK_CLEAR              0x4c
#define BULGARIA_VK_NEXT               0x51
#define BULGARIA_VK_LAUNCH_APP2        0xe021
#define BULGARIA_VK_INSERT             0x52
#define BULGARIA_VK_F21                0x6c
#define BULGARIA_VK_OEM_1              0x27
#define BULGARIA_VK_RETURN             0x1c
#define BULGARIA_VK_SNAPSHOT           0x54
#define BULGARIA_VK_LWIN               0xe05b
#define BULGARIA_VK_0                  0xb
#define BULGARIA_VK_OEM_102            0x56
#define BULGARIA_VK_F11                0x57
#define BULGARIA_VK_OEM_WSCTRL         0x5a
#define BULGARIA_VK_CAPITAL            0x3a
#define BULGARIA_VK_DBE_KATAKANA       0x5b
#define BULGARIA_VK_OEM_BACKTAB        0x5e
#define BULGARIA_VK_OEM_AUTO           0x5f
#define BULGARIA_VK_DBE_NOCODEINPUT    0x62
#define BULGARIA_VK_F13                0x64
#define BULGARIA_VK_DOWN               0x50
#define BULGARIA_VK_VOLUME_DOWN        0xe02e
#define BULGARIA_VK_F14                0x65
#define BULGARIA_VK_F17                0x68
#define BULGARIA_VK_OEM_PA3            0x6f
#define BULGARIA_VK_BROWSER_SEARCH     0xe065
#define BULGARIA_VK_RSHIFT             0x36
#define BULGARIA_VK_ABNT_C1            0x73
#define BULGARIA_VK_LEFT               0x4b
#define BULGARIA_VK_F24                0x76
#define BULGARIA_VK_VOLUME_MUTE        0xe020
#define BULGARIA_VK_SLEEP              0xe05f
#define BULGARIA_VK_F7                 0x41
#define BULGARIA_VK_MEDIA_STOP         0xe024
#define BULGARIA_VK_F16                0x67
#define BULGARIA_VK_BROWSER_HOME       0xe032
#define BULGARIA_VK_DIVIDE             0xe035
#define BULGARIA_VK_RWIN               0xe05c
unsigned short BULGARIA_layout_key_to_scancode(unsigned int key){
    switch(key)
        {
    case KEY_LSHIFT: return BULGARIA_VK_LSHIFT;
    case KEY_RSHIFT: return BULGARIA_VK_RSHIFT;
    case KEY_LMENU: return BULGARIA_VK_LMENU;
    case KEY_RMENU: return BULGARIA_VK_RMENU;
    case KEY_LCONTROL: return BULGARIA_VK_LCONTROL;
    case KEY_RCONTROL: return BULGARIA_VK_RCONTROL;
    case KEY_LWIN: return BULGARIA_VK_LWIN;
    case KEY_RWIN: return BULGARIA_VK_RWIN;
    case KEY_UP: return BULGARIA_VK_UP;
    case KEY_DOWN: return BULGARIA_VK_DOWN;
    case KEY_LEFT: return BULGARIA_VK_LEFT;
    case KEY_RIGHT: return BULGARIA_VK_RIGHT;
    case KEY_RETURN: return BULGARIA_VK_RETURN;
    case KEY_TAB: return BULGARIA_VK_TAB;
    case KEY_BACK: return BULGARIA_VK_BACK;
    case KEY_F1: return BULGARIA_VK_F1;
    case KEY_F2: return BULGARIA_VK_F2;
    case KEY_F3: return BULGARIA_VK_F3;
    case KEY_F4: return BULGARIA_VK_F4;
    case KEY_F5: return BULGARIA_VK_F5;
    case KEY_F6: return BULGARIA_VK_F6;
    case KEY_F7: return BULGARIA_VK_F7;
    case KEY_F8: return BULGARIA_VK_F8;
    case KEY_F9: return BULGARIA_VK_F9;
    case KEY_F10: return BULGARIA_VK_F10;
    case KEY_F11: return BULGARIA_VK_F11;
    case KEY_F12: return BULGARIA_VK_F12;
    case KEY_F13: return BULGARIA_VK_F13;
    case KEY_F14: return BULGARIA_VK_F14;
    case KEY_F15: return BULGARIA_VK_F15;
    case KEY_F16: return BULGARIA_VK_F16;
    case KEY_F17: return BULGARIA_VK_F17;
    case KEY_F18: return BULGARIA_VK_F18;
    case KEY_F19: return BULGARIA_VK_F19;
    case KEY_F20: return BULGARIA_VK_F20;
    case KEY_F21: return BULGARIA_VK_F21;
    case KEY_F22: return BULGARIA_VK_F22;
    case KEY_F23: return BULGARIA_VK_F23;
    case KEY_F24: return BULGARIA_VK_F24;
    case KEY_ESCAPE: return BULGARIA_VK_ESCAPE;
        }
    return 0;
};
struct scancode_modbits BULGARIA_char_to_scancode_modbits(unsigned short c){
    if(c < 128){
        const struct scancode_modbits char_lookup[128]={
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x39, 0x0},
            {0x2, 0x2},
            {0x5, 0x2},
            {0x00, 0x00},
            {0xc, 0x2},
            {0x6, 0x2},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x29, 0x0},
            {0x29, 0x2},
            {0x37, 0x0},
            {0x4e, 0x0},
            {0x10, 0x0},
            {0xc, 0x0},
            {0xd, 0x0},
            {0xe035, 0x0},
            {0xb, 0x0},
            {0x2, 0x0},
            {0x3, 0x0},
            {0x4, 0x0},
            {0x5, 0x0},
            {0x6, 0x0},
            {0x7, 0x0},
            {0x8, 0x0},
            {0x9, 0x0},
            {0xa, 0x0},
            {0x8, 0x2},
            {0x1b, 0x0},
            {0x00, 0x00},
            {0x7, 0x2},
            {0x00, 0x00},
            {0x3, 0x2},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0x00, 0x00},
            {0xe, 0x1},
        };
    return char_lookup[c];
    }
    switch(c)
        {
            case 0x8dd0: return (struct scancode_modbits){0x56,0x2};
            case 0x91d0: return (struct scancode_modbits){0x35,0x2};
            case 0x9bd0: return (struct scancode_modbits){0x34,0x2};
            case 0xbbd0: return (struct scancode_modbits){0x34,0x0};
            case 0x80d1: return (struct scancode_modbits){0x33,0x0};
            case 0x9fd0: return (struct scancode_modbits){0x32,0x2};
            case 0xbfd0: return (struct scancode_modbits){0x32,0x0};
            case 0xa5d0: return (struct scancode_modbits){0x31,0x2};
            case 0x85d1: return (struct scancode_modbits){0x31,0x0};
            case 0xa4d0: return (struct scancode_modbits){0x30,0x2};
            case 0x84d1: return (struct scancode_modbits){0x30,0x0};
            case 0x8dd1: return (struct scancode_modbits){0x2f,0x0};
            case 0x8ad1: return (struct scancode_modbits){0x2e,0x0};
            case 0x99d0: return (struct scancode_modbits){0x2d,0x2};
            case 0xb9d0: return (struct scancode_modbits){0x2d,0x0};
            case 0x8ed1: return (struct scancode_modbits){0x2c,0x0};
            case 0xaad0: return (struct scancode_modbits){0x2e,0x2};
            case 0x87d1: return (struct scancode_modbits){0x28,0x0};
            case 0x9cd0: return (struct scancode_modbits){0x27,0x2};
            case 0xbcd0: return (struct scancode_modbits){0x27,0x0};
            case 0x92d0: return (struct scancode_modbits){0x26,0x2};
            case 0x9dd0: return (struct scancode_modbits){0x25,0x2};
            case 0xbdd0: return (struct scancode_modbits){0x25,0x0};
            case 0xa2d0: return (struct scancode_modbits){0x24,0x2};
            case 0xb8d0: return (struct scancode_modbits){0x13,0x0};
            case 0xa0d0: return (struct scancode_modbits){0x33,0x2};
            case 0xa7c2: return (struct scancode_modbits){0x1b,0x2};
            case 0xa3d0: return (struct scancode_modbits){0x11,0x2};
            case 0xadd0: return (struct scancode_modbits){0x2f,0x2};
            case 0x8bd1: return (struct scancode_modbits){0x10,0x2};
            case 0x82d1: return (struct scancode_modbits){0x24,0x0};
            case 0x9dd1: return (struct scancode_modbits){0x56,0x0};
            case 0xaed0: return (struct scancode_modbits){0x2c,0x2};
            case 0xa9d0: return (struct scancode_modbits){0x15,0x2};
            case 0xb5d0: return (struct scancode_modbits){0x12,0x0};
            case 0x86d1: return (struct scancode_modbits){0x1a,0x0};
            case 0x83d1: return (struct scancode_modbits){0x11,0x0};
            case 0xb2d0: return (struct scancode_modbits){0x26,0x0};
            case 0xa6d0: return (struct scancode_modbits){0x1a,0x2};
            case 0x89d1: return (struct scancode_modbits){0x15,0x0};
            case 0xb7d0: return (struct scancode_modbits){0x19,0x0};
            case 0xafd0: return (struct scancode_modbits){0x1f,0x2};
            case 0x95d0: return (struct scancode_modbits){0x12,0x2};
            case 0x9ad0: return (struct scancode_modbits){0x16,0x2};
            case 0xa7d0: return (struct scancode_modbits){0x28,0x2};
            case 0xbad0: return (struct scancode_modbits){0x16,0x0};
            case 0xb1d0: return (struct scancode_modbits){0x35,0x0};
            case 0xbed0: return (struct scancode_modbits){0x21,0x0};
            case 0x98d0: return (struct scancode_modbits){0x13,0x2};
            case 0x88d1: return (struct scancode_modbits){0x14,0x0};
            case 0xa8d0: return (struct scancode_modbits){0x14,0x2};
            case 0x81d1: return (struct scancode_modbits){0x17,0x0};
            case 0xa1d0: return (struct scancode_modbits){0x17,0x2};
            case 0xb4d0: return (struct scancode_modbits){0x18,0x0};
            case 0x94d0: return (struct scancode_modbits){0x18,0x2};
            case 0x97d0: return (struct scancode_modbits){0x19,0x2};
            case 0x8cd1: return (struct scancode_modbits){0x1e,0x0};
            case 0x8fd1: return (struct scancode_modbits){0x1f,0x0};
            case 0xb0d0: return (struct scancode_modbits){0x20,0x0};
            case 0x90d0: return (struct scancode_modbits){0x20,0x2};
            case 0x9ed0: return (struct scancode_modbits){0x21,0x2};
            case 0xb6d0: return (struct scancode_modbits){0x22,0x0};
            case 0x96d0: return (struct scancode_modbits){0x22,0x2};
            case 0xb3d0: return (struct scancode_modbits){0x23,0x0};
            case 0x93d0: return (struct scancode_modbits){0x23,0x2};
        }
    return (struct scancode_modbits){0,0};
}
#ifdef __cplusplus
}
#endif
