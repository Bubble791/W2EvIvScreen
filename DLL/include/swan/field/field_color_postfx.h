#ifndef __FIELD_COLOR_POSTFX_H
#define __FIELD_COLOR_POSTFX_H

#include "swantypes.h"

STRUCT_DECLARE(FieldColorPostFX)

ENUM_DECLARE(FieldColorPostFXMode)

enum FieldColorPostFXMode
#ifdef __cplusplus
: u32
#endif
{
    FIELD_POSTFX_MODE_LUT = 0x0,
    FIELD_POSTFX_MODE_VINTAGE = 0x1,
};
SWAN_CPPTYPE_EX(field::g3d, ColorPostFXMode, FieldColorPostFXMode)

SWAN_CPPTYPE_EX(field::g3d, ColorPostFX, FieldColorPostFX)

struct FieldColorPostFX
{
    u8* LuminanceTable;
    FieldColorPostFXMode Mode;
};

#endif //__FIELD_COLOR_POSTFX_H
// Tchaikovsky code generator
