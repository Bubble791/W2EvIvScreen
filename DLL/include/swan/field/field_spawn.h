#ifndef __FIELD_SPAWN_H
#define __FIELD_SPAWN_H

#include "swantypes.h"

STRUCT_DECLARE(ZoneSpawnInfo)

#include "field/field_position.h"

struct ZoneSpawnInfo
{
    u32 ChangeType;
    u16 ZoneID;
    u16 WarpID;
    u16 WarpDir;
    u16 PosWeightBits;
    b32 IsRail;
    FieldPosition Pos;
};

#endif //__FIELD_SPAWN_H
// Tchaikovsky code generator
