#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "tusb.h"
#include "bsp/board.h"
#include "pico/stdlib.h"
#include "usb_descriptors.h"
#include "KeyBoardLayouts.h"
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