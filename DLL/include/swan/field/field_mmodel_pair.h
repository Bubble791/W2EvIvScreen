#ifndef __FIELD_MMODEL_PAIR_H
#define __FIELD_MMODEL_PAIR_H

#include "swantypes.h"

STRUCT_DECLARE(FieldActorPairState)

SWAN_CPPTYPE_EX(field::mmodel, PairWork, FieldActorPairState)

struct FieldActorPairState
{
    s16 HeapID;
    u8 FollowerID;
    u8 OldActorUID;
    u16 ObjCode;
    u16 SCRID;
    u16 AllyTrainerID;
};

#endif //__FIELD_MMODEL_PAIR_H
// Tchaikovsky code generator
