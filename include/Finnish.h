#ifndef FINNISH
#define FINNISH

#include "layout_utils.h"
unsigned short FINNISH_layout_key_to_scancode(unsigned int key);
struct scancode_modbits FINNISH_char_to_scancode_modbits(unsigned short c);
#endif
