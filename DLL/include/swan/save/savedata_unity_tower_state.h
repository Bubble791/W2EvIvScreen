#ifndef __SAVEDATA_UNITY_TOWER_STATE_H
#define __SAVEDATA_UNITY_TOWER_STATE_H

#include "swantypes.h"

STRUCT_DECLARE(UnityTowerState)

struct UnityTowerState
{
    u8 FloorCountry;
    u8 GuestCount;
    u8 FloorNumber;
    u8 field_3[5];
    u8 VisitorIndices[5];
    u8 field_D;
    u16 field_E;
};

#endif //__SAVEDATA_UNITY_TOWER_STATE_H
// Tchaikovsky code generator
