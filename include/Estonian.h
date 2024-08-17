#ifndef ESTONIAN
#define ESTONIAN

#include "layout_utils.h"
unsigned short ESTONIAN_layout_key_to_scancode(unsigned int key);
struct scancode_modbits ESTONIAN_char_to_scancode_modbits(unsigned short c);
#endif
