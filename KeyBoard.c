#include "KeyBoard.h"
#include "stdio.h"

static struct repeating_timer KeyBoard_tud_task_timer;

static bool Capslock = false;

const static uint8_t scancode_to_hid_key_minor[128] = {0, 41, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 45, 46, 42, 43, 20, 26, 8, 21, 23, 28, 24, 12, 18, 19, 47, 48, 40, 224, 4, 22, 7, 9, 10, 11, 13, 14, 15, 51, 52, 53, 225, 50, 29, 27, 6, 25, 5, 17, 16, 54, 55, 56, 229, 85, 226, 44, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 72, 71, 95, 96, 97, 86, 92, 93, 94, 87, 89, 90, 91, 98, 99, 0, 0, 100, 68, 69, 103, 0, 0, 140, 0, 0, 0, 0, 0, 0, 0, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 0, 136, 145, 144, 135, 0, 0, 148, 147, 146, 138, 0, 139, 0, 137, 133, 0};
const static uint8_t scancode_to_hid_key_major[128] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 0, 70, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 83, 0, 74, 82, 75, 0, 80, 0, 79, 0, 77, 81, 78, 73, 76, 0, 0, 0, 0, 0, 0, 0, 227, 231, 101, 233, 234, 0, 0, 0, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static unsigned short (*keyboard_layout_key_to_scancode_function)(unsigned int) = NULL;
static struct scancode_modbits (*keyboard_layout_char_to_scancode_modbits_function)(unsigned short) = NULL;




size_t KeyBoard_compile_string_to_key_data_single_key(const char *str, size_t len, key_data_single_key_t *outbuffer, size_t outbuffer_size)
{
  const char *end = str + len;
  const char *cur = str;

  key_data_single_key_t *out = outbuffer;
  key_data_single_key_t *bufferend = outbuffer + outbuffer_size;

  while (cur < end && out < bufferend)
  {
    if (*cur < 128)
    {
      *out = KeyBoard_char_to_key_data_single_key(cur, 1);
      ++cur;
      if (!(out->key == 0))
      {
        ++out;
      }
    }
    else if (cur + 1 < end)
    {

      *out = KeyBoard_char_to_key_data_single_key(cur, 2);
      cur += 2;
      if (!(out->key == 0))
      {
        ++out;
      }
    }
  }
  return out - outbuffer;
}

size_t KeyBoard_compile_string_to_key_data(const char *str, size_t len, key_data_t *outbuffer, size_t outbuffer_size)
{
  const char *end = str + len;
  const char *cur = str;

  key_data_t *out = outbuffer;
  key_data_t *bufferend = outbuffer + outbuffer_size;
  size_t offset_to_key_code = 0;

  while (cur < end && out < bufferend)
  {
    key_data_single_key_t cbuf;
    
    if (*cur < 128)
    {
      cbuf = KeyBoard_char_to_key_data_single_key(cur, 1);
      ++cur;
    }
    else if (cur + 1 < end)
    {

      cbuf = KeyBoard_char_to_key_data_single_key(cur, 2);
      cur += 2;
    }
    else
    {
      continue;
    }

    if(offset_to_key_code == 0){
      memset(out,0,sizeof(key_data_t));
    }else{

      bool addnew = offset_to_key_code >= 6;
      for(size_t i = 0; i < offset_to_key_code && !addnew; i++){
        if(out->keycodes[i]==cbuf.key){
          addnew = true;
        }
      }
      if(out->modifiers != cbuf.mod){
        addnew = true;
      }

      
      if(addnew){
        out++;
        memset(out,0,sizeof(key_data_t));
        offset_to_key_code = 0;
      }

    }
    out->modifiers=cbuf.mod;
    out->keycodes[offset_to_key_code]=cbuf.key;
    offset_to_key_code ++;



  //  out->keycodes[0]=cbuf.key;
  //  out->modifiers = cbuf.mod;
  //  out++;

  }
  return out - outbuffer +1;
}

int KeyBoard_bind_layout_functions(
    unsigned short (*key_to_scancode_function)(unsigned int),
    struct scancode_modbits (*char_to_scancode_modbits_function)(unsigned short))
{
  keyboard_layout_key_to_scancode_function = key_to_scancode_function;
  keyboard_layout_char_to_scancode_modbits_function = char_to_scancode_modbits_function;
}

int KeyBoard_send_key_data(const key_data_t *keys, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    while (!tud_hid_ready())
    {
      tud_task();
      tight_loop_contents();
    };
    tud_hid_keyboard_report(1, keys[i].modifiers, keys[i].keycodes);
    while (!tud_hid_ready())
    {
      tud_task();
      tight_loop_contents();
    };
    tud_hid_keyboard_report(1, keys[i].modifiers, NULL);
  }

  return 0;
}

int KeyBoard_send_key_data_sk(const key_data_single_key_t *keys, size_t count)
{
  uint8_t buf[6] = {0};
  for (size_t i = 0; i < count; i++)
  {
    buf[0] = keys[i].key;
    
    while (!tud_hid_ready())
    {
      tud_task();
      tight_loop_contents();
    };
    tud_hid_keyboard_report(1, keys[i].mod, buf);
    while (!tud_hid_ready())
    {
      tud_task();
      tight_loop_contents();
    };
    tud_hid_keyboard_report(1, keys[i].mod, NULL);
  }

  return 0;
}

key_data_single_key_t KeyBoard_char_to_key_data_single_key(const char *c, uint32_t len)
{
  // len is normally 1 but sometimes a charachter is represented with more bytes e.g åäö
  uint16_t v = 0;

  if (len > sizeof(v))
    return (key_data_single_key_t){0, 0};
  memcpy(&v, c, len);
  if (!keyboard_layout_char_to_scancode_modbits_function)
  {
    return (key_data_single_key_t){0, 0};
  }
  struct scancode_modbits sc_mb = keyboard_layout_char_to_scancode_modbits_function(v);
  return (key_data_single_key_t){sc_mb.modbits, KeyBoard_scancode_to_hid_key(sc_mb.scancode)};
}

key_data_single_key_t KeyBoard_noncharkey_to_key_data_single_key(enum KEYBOARD_NONCHAR_KEYS key)
{
  if (!keyboard_layout_key_to_scancode_function)
  {
    return (key_data_single_key_t){0, 0};
  }
  uint16_t sc = keyboard_layout_key_to_scancode_function(key);
  return (key_data_single_key_t){0, KeyBoard_scancode_to_hid_key(sc)};
}

uint8_t KeyBoard_scancode_to_hid_key(uint16_t scancode)
{
  if (scancode < 128)
    return scancode_to_hid_key_minor[scancode];
  return scancode_to_hid_key_major[scancode % 128];
}

bool KeyBoard_single_key_exists_in_key_data(const key_data_single_key_t *skd, const key_data_t *kd)
{
  for (size_t i = 0; i < sizeof(kd->keycodes); i++)
  {
    if (skd->key == kd->keycodes[i])
      return true;
  }
  return false;
}



// Invoked when sent REPORT successfully to host
// Application can use this to send the next report
// Note: For composite reports, report[0] is report ID
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const *report, uint16_t len)
{
  (void)instance;
  (void)len;

  uint8_t next_report_id = report[0] + 1;

  if (next_report_id < REPORT_ID_COUNT)
  {
    // send_hid_report(next_report_id, board_button_read());
  }
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen)
{
  // TODO not Implemented
  (void)instance;
  (void)report_id;
  (void)report_type;
  (void)buffer;
  (void)reqlen;

  return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize)
{
  (void)instance;

  if (report_type == HID_REPORT_TYPE_OUTPUT)
  {
    // Set keyboard LED e.g Capslock, Numlock etc...
    if (report_id == REPORT_ID_KEYBOARD)
    {
      // bufsize should be (at least) 1
      if (bufsize < 1)
        return;

      uint8_t const kbd_leds = buffer[0];

      if (kbd_leds & KEYBOARD_LED_CAPSLOCK)
      {
        Capslock = true;
      }
      else
      {
        Capslock = false;
      }
    }
  }
}
