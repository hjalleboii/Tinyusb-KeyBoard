#ifndef SV_SE
#define SV_SE

#include "layout_utils.h"
unsigned short SV_SE_layout_key_to_scancode(unsigned int key);
struct scancode_modbits SV_SE_char_to_scancode_modbits(unsigned short c);
#endif
