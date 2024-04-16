#ifndef __FIELD_ENCOUNT_DATA_H
#define __FIELD_ENCOUNT_DATA_H

#include "swantypes.h"

STRUCT_DECLARE(WildEncSlot)
STRUCT_DECLARE(EncData)

ENUM_DECLARE(EncountType)

enum EncountType 
#ifdef __cplusplus
: u32
#endif
{
    ENCTYPE_GRASS,
    ENCTYPE_GRASS_RARE,
    ENCTYPE_GRASS_SHAKING,
    ENCTYPE_SURF,
    ENCTYPE_SURF_RARE,
    ENCTYPE_FISHING,
    ENCTYPE_FISHING_RARE,
    ENCTYPE_MAX
};
SWAN_CPPTYPE(field, EncountType)

SWAN_CPPTYPE(field, WildEncSlot)
SWAN_CPPTYPE_EX(field, EncountData, EncData)

struct WildEncSlot
{
    u16 species:11;
    u8 forme:5;
    char LvMin;
    char LvMax;
};

struct EncData
{
    u8 UserData[ENCTYPE_MAX];
    u8 Flags:7;
    b32 FishingEnable:1;
    WildEncSlot Slots[56];
};

#endif //__FIELD_ENCOUNT_DATA_H
// Tchaikovsky code generator
