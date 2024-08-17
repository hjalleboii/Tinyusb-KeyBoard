cmake_minimum_required(VERSION 3.28.3)


include_directories(incude/)
aux_source_directory(layouts LAYOUTS_SRC)
set(TINYUSB_KEYBOARD_SRC 
${LAYOUTS_SRC}
KeyBoard.c
)
