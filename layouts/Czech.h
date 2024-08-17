#ifndef CZECH
#define CZECH

#include "layout_utils.h"
unsigned short CZECH_layout_key_to_scancode(unsigned int key);
struct scancode_modbits CZECH_char_to_scancode_modbits(unsigned short c);
#endif
