#ifndef GERMAN
#define GERMAN

#include "layout_utils.h"
unsigned short GERMAN_layout_key_to_scancode(unsigned int key);
struct scancode_modbits GERMAN_char_to_scancode_modbits(unsigned short c);
#endif
