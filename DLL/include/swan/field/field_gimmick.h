#ifndef __FIELD_GIMMICK_H
#define __FIELD_GIMMICK_H

#include "swantypes.h"

STRUCT_DECLARE(FieldGimmickWorkBlock)
STRUCT_DECLARE(GimmickState)

SWAN_CPPTYPE_EX(field, GimmickWork, FieldGimmickWorkBlock)

struct FieldGimmickWorkBlock
{
    u32 Password;
    void* Data;
};

struct GimmickState
{
    u32 GimmickID;
    u32 UserData[32];
    u8 field_84[5];
    u8 field_89[5];
    u16 field_8E;
    u32 field_90;
};

#endif //__FIELD_GIMMICK_H
// Tchaikovsky code generator
