#ifndef LAYOUT_UTILS
#define LAYOUT_UTILS

#define lktsc_f(l) l##_layout_key_to_scancode
#define ctscm_f(l) l##_char_to_scancode_modbits

#ifdef __cplusplus
extern "C"{
#endif
struct scancode_modbits {unsigned short scancode; unsigned char modbits;};

enum KEYBOARD_NONCHAR_KEYS{
    KEY_LSHIFT = 1,
    KEY_RSHIFT = 2,
    KEY_LMENU = 3,
    KEY_RMENU = 4,
    KEY_LCONTROL = 5,
    KEY_RCONTROL = 6,
    KEY_LWIN = 7,
    KEY_RWIN = 8,
    KEY_UP = 9,
    KEY_DOWN = 10,
    KEY_LEFT = 11,
    KEY_RIGHT = 12,
    KEY_RETURN = 13,
    KEY_TAB = 14,
    KEY_BACK = 15,
    KEY_F1 = 16,
    KEY_F2 = 17,
    KEY_F3 = 18,
    KEY_F4 = 19,
    KEY_F5 = 20,
    KEY_F6 = 21,
    KEY_F7 = 22,
    KEY_F8 = 23,
    KEY_F9 = 24,
    KEY_F10 = 25,
    KEY_F11 = 26,
    KEY_F12 = 27,
    KEY_F13 = 28,
    KEY_F14 = 29,
    KEY_F15 = 30,
    KEY_F16 = 31,
    KEY_F17 = 32,
    KEY_F18 = 33,
    KEY_F19 = 34,
    KEY_F20 = 35,
    KEY_F21 = 36,
    KEY_F22 = 37,
    KEY_F23 = 38,
    KEY_F24 = 39,
    KEY_ESCAPE = 40,
};

#ifdef __cplusplus
}
#endif

#endif