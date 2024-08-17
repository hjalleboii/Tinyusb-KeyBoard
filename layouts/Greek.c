#include "Greek.h"

#ifdef __cplusplus
extern "C"{
#endif

#define GREEK_VK_LAUNCH_MEDIA_SELECT   0xe06d
#define GREEK_VK_LAUNCH_MAIL           0xe06c
#define GREEK_VK_LAUNCH_APP1           0xe06b
#define GREEK_VK_BROWSER_STOP          0xe068
#define GREEK_VK_APPS                  0xe05d
#define GREEK_VK_F20                   0x6b
#define GREEK_VK_BROWSER_REFRESH       0xe067
#define GREEK_VK_MULTIPLY              0x37
#define GREEK_VK_LCONTROL              0x1d
#define GREEK_VK_LMENU                 0x38
#define GREEK_VK_M                     0x32
#define GREEK_VK_END                   0x4f
#define GREEK_VK_N                     0x31
#define GREEK_VK_C                     0x2e
#define GREEK_VK_B                     0x30
#define GREEK_VK_X                     0x2d
#define GREEK_VK_OEM_7                 0x28
#define GREEK_VK_E                     0x12
#define GREEK_VK_MEDIA_NEXT_TRACK      0xe019
#define GREEK_VK_Z                     0x2c
#define GREEK_VK_K                     0x25
#define GREEK_VK_OEM_PLUS              0xd
#define GREEK_VK_OEM_JUMP              0x5c
#define GREEK_VK_G                     0x22
#define GREEK_VK_D                     0x20
#define GREEK_VK_PAUSE                 0xe11d
#define GREEK_VK_S                     0x1f
#define GREEK_VK_OEM_6                 0x1b
#define GREEK_VK_ABNT_C2               0x7e
#define GREEK_VK_BROWSER_BACK          0xe06a
#define GREEK_VK_8                     0x9
#define GREEK_VK_CANCEL                0xe046
#define GREEK_VK_7                     0x8
#define GREEK_VK_6                     0x7
#define GREEK_VK_F23                   0x6e
#define GREEK_VK_T                     0x14
#define GREEK_VK_LSHIFT                0x2a
#define GREEK_VK_A                     0x1e
#define GREEK_VK_OEM_PERIOD            0x34
#define GREEK_VK_F12                   0x58
#define GREEK_VK_BROWSER_FORWARD       0xe069
#define GREEK_VK_U                     0x16
#define GREEK_VK_V                     0x2f
#define GREEK_VK_Y                     0x15
#define GREEK_VK_F19                   0x6a
#define GREEK_VK_OEM_MINUS             0xc
#define GREEK_VK_BACK                  0xe
#define GREEK_VK_4                     0x5
#define GREEK_VK_W                     0x11
#define GREEK_VK_F5                    0x3f
#define GREEK_VK_ADD                   0x4e
#define GREEK_VK_OEM_4                 0x1a
#define GREEK_VK_P                     0x19
#define GREEK_VK_MEDIA_PREV_TRACK      0xe010
#define GREEK_VK_J                     0x24
#define GREEK_VK_OEM_COMMA             0x33
#define GREEK_VK_F1                    0x3b
#define GREEK_VK_Q                     0x10
#define GREEK_VK_R                     0x13
#define GREEK_VK_DBE_FLUSHSTRING       0x5d
#define GREEK_VK_1                     0x2
#define GREEK_VK_RMENU                 0xe038
#define GREEK_VK_OEM_3                 0x29
#define GREEK_VK_OEM_5                 0x2b
#define GREEK_VK_TAB                   0xf
#define GREEK_VK_F4                    0x3e
#define GREEK_VK_F                     0x21
#define GREEK_VK_H                     0x23
#define GREEK_VK_ESCAPE                0x1
#define GREEK_VK_DELETE                0x53
#define GREEK_VK_OEM_PA1               0x7b
#define GREEK_VK_L                     0x26
#define GREEK_VK_HELP                  0x63
#define GREEK_VK_9                     0xa
#define GREEK_VK_I                     0x17
#define GREEK_VK_RIGHT                 0x4d
#define GREEK_VK_RCONTROL              0xe01d
#define GREEK_VK_F2                    0x3c
#define GREEK_VK_F3                    0x3d
#define GREEK_VK_F15                   0x66
#define GREEK_VK_F6                    0x40
#define GREEK_VK_3                     0x4
#define GREEK_VK_F8                    0x42
#define GREEK_VK_F9                    0x43
#define GREEK_VK_OEM_2                 0x35
#define GREEK_VK_F10                   0x44
#define GREEK_VK_5                     0x6
#define GREEK_VK_2                     0x3
#define GREEK_VK_NUMLOCK               0x45
#define GREEK_VK_VOLUME_UP             0xe030
#define GREEK_VK_MEDIA_PLAY_PAUSE      0xe022
#define GREEK_VK_SCROLL                0x46
#define GREEK_VK_BROWSER_FAVORITES     0xe066
#define GREEK_VK_SPACE                 0x39
#define GREEK_VK_O                     0x18
#define GREEK_VK_HOME                  0x47
#define GREEK_VK_UP                    0x48
#define GREEK_VK_PRIOR                 0x49
#define GREEK_VK_F22                   0x6d
#define GREEK_VK_F18                   0x69
#define GREEK_VK_OEM_RESET             0x71
#define GREEK_VK_SUBTRACT              0x4a
#define GREEK_VK_CLEAR                 0x4c
#define GREEK_VK_NEXT                  0x51
#define GREEK_VK_LAUNCH_APP2           0xe021
#define GREEK_VK_INSERT                0x52
#define GREEK_VK_F21                   0x6c
#define GREEK_VK_OEM_1                 0x27
#define GREEK_VK_RETURN                0x1c
#define GREEK_VK_SNAPSHOT              0x54
#define GREEK_VK_LWIN                  0xe05b
#define GREEK_VK_0                     0xb
#define GREEK_VK_OEM_102               0x56
#define GREEK_VK_F11                   0x57
#define GREEK_VK_OEM_WSCTRL            0x5a
#define GREEK_VK_CAPITAL               0x3a
#define GREEK_VK_DBE_KATAKANA          0x5b
#define GREEK_VK_OEM_BACKTAB           0x5e
#define GREEK_VK_OEM_AUTO              0x5f
#define GREEK_VK_DBE_NOCODEINPUT       0x62
#define GREEK_VK_F13                   0x64
#define GREEK_VK_DOWN                  0x50
#define GREEK_VK_VOLUME_DOWN           0xe02e
#define GREEK_VK_F14                   0x65
#define GREEK_VK_F17                   0x68
#define GREEK_VK_OEM_PA3               0x6f
#define GREEK_VK_BROWSER_SEARCH        0xe065
#define GREEK_VK_RSHIFT                0x36
#define GREEK_VK_ABNT_C1               0x73
#define GREEK_VK_LEFT                  0x4b
#define GREEK_VK_F24                   0x76
#define GREEK_VK_VOLUME_MUTE           0xe020
#define GREEK_VK_SLEEP                 0xe05f
#define GREEK_VK_F7                    0x41
#define GREEK_VK_MEDIA_STOP            0xe024
#define GREEK_VK_F16                   0x67
#define GREEK_VK_BROWSER_HOME          0xe032
#define GREEK_VK_DIVIDE                0xe035
#define GREEK_VK_RWIN                  0xe05c
unsigned short GREEK_layout_key_to_scancode(unsigned int key){
    switch(key)
        {
    case KEY_LSHIFT: return GREEK_VK_LSHIFT;
    case KEY_RSHIFT: return GREEK_VK_RSHIFT;
    case KEY_LMENU: return GREEK_VK_LMENU;
    case KEY_RMENU: return GREEK_VK_RMENU;
    case KEY_LCONTROL: return GREEK_VK_LCONTROL;
    case KEY_RCONTROL: return GREEK_VK_RCONTROL;
    case KEY_LWIN: return GREEK_VK_LWIN;
    case KEY_RWIN: return GREEK_VK_RWIN;
    case KEY_UP: return GREEK_VK_UP;
    case KEY_DOWN: return GREEK_VK_DOWN;
    case KEY_LEFT: return GREEK_VK_LEFT;
    case KEY_RIGHT: return GREEK_VK_RIGHT;
    case KEY_RETURN: return GREEK_VK_RETURN;
    case KEY_TAB: return GREEK_VK_TAB;
    case KEY_BACK: return GREEK_VK_BACK;
    case KEY_F1: return GREEK_VK_F1;
    case KEY_F2: return GREEK_VK_F2;
    case KEY_F3: return GREEK_VK_F3;
    case KEY_F4: return GREEK_VK_F4;
    case KEY_F5: return GREEK_VK_F5;
    case KEY_F6: return GREEK_VK_F6;
    case KEY_F7: return GREEK_VK_F7;
    case KEY_F8: return GREEK_VK_F8;
    case KEY_F9: return GREEK_VK_F9;
    case KEY_F10: return GREEK_VK_F10;
    case KEY_F11: return GREEK_VK_F11;
    case KEY_F12: return GREEK_VK_F12;
    case KEY_F13: return GREEK_VK_F13;
    case KEY_F14: return GREEK_VK_F14;
    case KEY_F15: return GREEK_VK_F15;
    case KEY_F16: return GREEK_VK_F16;
    case KEY_F17: return GREEK_VK_F17;
    case KEY_F18: return GREEK_VK_F18;
    case KEY_F19: return GREEK_VK_F19;
    case KEY_F20: return GREEK_VK_F20;
    case KEY_F21: return GREEK_VK_F21;
    case KEY_F22: return GREEK_VK_F22;
    case KEY_F23: return GREEK_VK_F23;
    case KEY_F24: return GREEK_VK_F24;
    case KEY_ESCAPE: return GREEK_VK_ESCAPE;
        }
    return 0;
};
struct scancode_modbits GREEK_char_to_scancode_modbits(unsigned short c){
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
            {0x28, 0x2},
            {0x4, 0x2},
            {0x5, 0x2},
            {0x6, 0x2},
            {0x8, 0x2},
            {0x28, 0x0},
            {0xa, 0x2},
            {0xb, 0x2},
            {0x37, 0x0},
            {0x4e, 0x0},
            {0x33, 0x0},
            {0xc, 0x0},
            {0x34, 0x0},
            {0x35, 0x0},
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
            {0x10, 0x2},
            {0x10, 0x0},
            {0x56, 0x0},
            {0xd, 0x0},
            {0x34, 0x2},
            {0x35, 0x2},
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
            {0x1a, 0x0},
            {0x2b, 0x0},
            {0x1b, 0x0},
            {0x7, 0x2},
            {0xc, 0x2},
            {0x29, 0x0},
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
            {0x1a, 0x2},
            {0x2b, 0x2},
            {0x1b, 0x2},
            {0x29, 0x2},
            {0xe, 0x1},
        };
    return char_lookup[c];
    }
    switch(c)
        {
            case 0x9cce: return (struct scancode_modbits){0x32,0x2};
            case 0xbcce: return (struct scancode_modbits){0x32,0x0};
            case 0xbdce: return (struct scancode_modbits){0x31,0x0};
            case 0x92ce: return (struct scancode_modbits){0x30,0x2};
            case 0x89cf: return (struct scancode_modbits){0x2f,0x0};
            case 0x88cf: return (struct scancode_modbits){0x2e,0x0};
            case 0xa7ce: return (struct scancode_modbits){0x2d,0x2};
            case 0xb6ce: return (struct scancode_modbits){0x2c,0x0};
            case 0x87cf: return (struct scancode_modbits){0x2d,0x0};
            case 0x9bce: return (struct scancode_modbits){0x26,0x2};
            case 0xbbce: return (struct scancode_modbits){0x26,0x0};
            case 0x9ace: return (struct scancode_modbits){0x25,0x2};
            case 0xbace: return (struct scancode_modbits){0x25,0x0};
            case 0xbece: return (struct scancode_modbits){0x24,0x0};
            case 0x93ce: return (struct scancode_modbits){0x22,0x2};
            case 0xacc2: return (struct scancode_modbits){0x2b,0x40};
            case 0xa6ce: return (struct scancode_modbits){0x21,0x2};
            case 0x94ce: return (struct scancode_modbits){0x20,0x2};
            case 0xa9c2: return (struct scancode_modbits){0x2e,0x40};
            case 0xa3ce: return (struct scancode_modbits){0x1f,0x2};
            case 0x83cf: return (struct scancode_modbits){0x1f,0x0};
            case 0x91ce: return (struct scancode_modbits){0x1e,0x2};
            case 0x96ce: return (struct scancode_modbits){0x2c,0x2};
            case 0xb3ce: return (struct scancode_modbits){0x22,0x0};
            case 0xb3c2: return (struct scancode_modbits){0x4,0x40};
            case 0x9ece: return (struct scancode_modbits){0x24,0x2};
            case 0xa4c2: return (struct scancode_modbits){0x9,0x40};
            case 0xb1ce: return (struct scancode_modbits){0x1e,0x0};
            case 0xb0c2: return (struct scancode_modbits){0xb,0x40};
            case 0xb4ce: return (struct scancode_modbits){0x20,0x0};
            case 0xb2ce: return (struct scancode_modbits){0x30,0x0};
            case 0x80cf: return (struct scancode_modbits){0x19,0x0};
            case 0x86cf: return (struct scancode_modbits){0x21,0x0};
            case 0x85cf: return (struct scancode_modbits){0x15,0x0};
            case 0xa9ce: return (struct scancode_modbits){0x2f,0x2};
            case 0x9dce: return (struct scancode_modbits){0x31,0x2};
            case 0xa3c2: return (struct scancode_modbits){0x5,0x40};
            case 0xb6c2: return (struct scancode_modbits){0x7,0x40};
            case 0xbbc2: return (struct scancode_modbits){0x1b,0x40};
            case 0xb5ce: return (struct scancode_modbits){0x12,0x0};
            case 0xb2c2: return (struct scancode_modbits){0x3,0x40};
            case 0xb8ce: return (struct scancode_modbits){0x16,0x0};
            case 0xa4ce: return (struct scancode_modbits){0x14,0x2};
            case 0xb1c2: return (struct scancode_modbits){0xc,0x40};
            case 0xa6c2: return (struct scancode_modbits){0xa,0x40};
            case 0xa0ce: return (struct scancode_modbits){0x19,0x2};
            case 0xb7ce: return (struct scancode_modbits){0x23,0x0};
            case 0xbdc2: return (struct scancode_modbits){0xd,0x40};
            case 0x99ce: return (struct scancode_modbits){0x17,0x2};
            case 0x97ce: return (struct scancode_modbits){0x23,0x2};
            case 0x95ce: return (struct scancode_modbits){0x12,0x2};
            case 0x82cf: return (struct scancode_modbits){0x11,0x0};
            case 0x81cf: return (struct scancode_modbits){0x13,0x0};
            case 0xbfce: return (struct scancode_modbits){0x18,0x0};
            case 0xa7c2: return (struct scancode_modbits){0x6,0x40};
            case 0xa1ce: return (struct scancode_modbits){0x13,0x2};
            case 0xa8ce: return (struct scancode_modbits){0x2e,0x2};
            case 0xaec2: return (struct scancode_modbits){0x13,0x40};
            case 0x84cf: return (struct scancode_modbits){0x14,0x0};
            case 0xabc2: return (struct scancode_modbits){0x1a,0x40};
            case 0xa5ce: return (struct scancode_modbits){0x15,0x2};
            case 0x98ce: return (struct scancode_modbits){0x16,0x2};
            case 0xb9ce: return (struct scancode_modbits){0x17,0x0};
            case 0xa5c2: return (struct scancode_modbits){0x15,0x40};
            case 0x9fce: return (struct scancode_modbits){0x18,0x2};
        }
    return (struct scancode_modbits){0,0};
}
#ifdef __cplusplus
}
#endif
