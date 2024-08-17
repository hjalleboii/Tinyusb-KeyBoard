#ifndef GREEK
#define GREEK

#include "layout_utils.h"
unsigned short GREEK_layout_key_to_scancode(unsigned int key);
struct scancode_modbits GREEK_char_to_scancode_modbits(unsigned short c);
#endif
