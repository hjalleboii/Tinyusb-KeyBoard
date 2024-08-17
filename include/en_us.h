#ifndef EN_US
#define EN_US

#include "layout_utils.h"
unsigned short EN_US_layout_key_to_scancode(unsigned int key);
struct scancode_modbits EN_US_char_to_scancode_modbits(unsigned short c);
#endif
