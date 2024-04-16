#ifndef __FIELD_POSITION_H
#define __FIELD_POSITION_H

#include "swantypes.h"

UNION_DECLARE(FieldPosition)
STRUCT_DECLARE(GPosXYZ)

#include "math/vector.h"
#include "field/field_rail_system.h"

union FieldPosition
{
    VecFx32 Vector;
    RailPosition Rail;
};

struct GPosXYZ
{
    u16 X;
    s16 Y;
    u16 Z;
};

#endif //__FIELD_POSITION_H
// Tchaikovsky code generator
