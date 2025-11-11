#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "tusb.h"
#include "bsp/board.h"
#include "pico/stdlib.h"
#include "usb_descriptors.h"

#define BIT(x) 1 << x

#ifdef __cplusplus
extern "C"{
#endif

struct key_data
{
    uint8_t modifiers;
    uint8_t keycodes[6];
};
struct key_data_single_key
{
    uint8_t mod;
    uint8_t key;
};
enum STATUS
{
    NOT_MOUNTED,
    MOUNTED,
    SUSPENDED
};

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

typedef struct key_data_single_key key_data_single_key_t;
typedef struct key_data key_data_t;

static_assert(sizeof(key_data_t) == 7);
static_assert(sizeof(key_data_single_key_t) == 2);
size_t KeyBoard_compile_string_to_key_data_single_key(const char *str, size_t len, key_data_single_key_t *outbuffer, size_t outbuffer_size);
size_t KeyBoard_compile_string_to_key_data(const char *str, size_t len, key_data_t *outbuffer, size_t outbuffer_size);

int KeyBoard_bind_layout_functions(
    unsigned short (*key_to_scancode_function)(unsigned int),
    struct scancode_modbits (*char_to_scancode_modbits_function)(unsigned short));
int KeyBoard_send_key_data(const key_data_t *keys, size_t count);
int KeyBoard_send_key_data_sk(const key_data_single_key_t *keys, size_t count);
key_data_single_key_t KeyBoard_char_to_key_data_single_key(const char *c, uint32_t len);
key_data_single_key_t KeyBoard_noncharkey_to_key_data_single_key(enum KEYBOARD_NONCHAR_KEYS key);
uint8_t KeyBoard_scancode_to_hid_key(uint16_t scancode);



bool KeyBoard_single_key_exists_in_key_data(const key_data_single_key_t *skd, const key_data_t *kd);


void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize);
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen);
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const *report, uint16_t len);

void tud_resume_cb(void);
void tud_suspend_cb(bool remote_wakeup_en);
void tud_umount_cb(void);
void tud_mount_cb(void);

#ifdef __cplusplus
}
#endif
#endif