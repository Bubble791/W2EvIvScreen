#ifndef __HID_H
#define __HID_H

#include "swantypes.h"
#include "swan_cpp_enum_ops.h"

ENUM_DECLARE(InputButton)

enum InputButton
#ifdef __cplusplus
: u32
#endif
{
    KEY_A = 0x1,
    KEY_B = 0x2,
    KEY_SELECT = 0x4,
    KEY_START = 0x8,
    KEY_RIGHT = 0x10,
    KEY_LEFT = 0x20,
    KEY_UP = 0x40,
    KEY_DOWN = 0x80,
    KEY_R = 0x100,
    KEY_L = 0x200,
    KEY_X = 0x400,
    KEY_Y = 0x800,
    KEY_TOUCH = 0x1000,
    KEY_LID = 0x2000,
};
DEFINE_ENUM_FLAG_OPERATORS(InputButton)

#endif //__HID_H
// Tchaikovsky code generator
