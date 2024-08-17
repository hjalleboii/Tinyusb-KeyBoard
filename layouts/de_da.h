#ifndef DE_DA
#define DE_DA

#include "layout_utils.h"
unsigned short DE_DA_layout_key_to_scancode(unsigned int key);
struct scancode_modbits DE_DA_char_to_scancode_modbits(unsigned short c);
#endif
