#ifndef DUTCH
#define DUTCH

#include "layout_utils.h"
unsigned short DUTCH_layout_key_to_scancode(unsigned int key);
struct scancode_modbits DUTCH_char_to_scancode_modbits(unsigned short c);
#endif
