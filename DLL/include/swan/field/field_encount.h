#ifndef __FIELD_ENCOUNT_H
#define __FIELD_ENCOUNT_H

#include "swantypes.h"

STRUCT_DECLARE(EncountState)
STRUCT_DECLARE(EncountSystem)

#include "field/field_mmodel.h"
#include "field/field_map_terrain.h"
#include "system/gamesystem.h"
#include "field/fieldmap.h"
#include "system/game_data.h"
#include "field/field_encount_data.h"
#include "field/field_position.h"

struct EncountState
{
    GPosXYZ GPos;
    u8 EncountRateBlockCounter;
    u8 EncountRateStepIncrement;
    u32 EncountRateStepCounter;
    TileType TileTypeUnder;
    u16 EncountRate;
    u16 field_12;
    u32 field_14;
    u16 field_18;
    GPosXYZ RareEncountPos;
    u32 field_20;
    u32 field_24;
};

struct EncountSystem
{
    Field* m_Field;
    GameSystem* m_GameSystem;
    GameData* m_GameData;
    EncData* m_EncData;
    void* m_EffectEncountState;
};

#endif //__FIELD_ENCOUNT_H
// Tchaikovsky code generator
