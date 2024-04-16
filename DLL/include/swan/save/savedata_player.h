#ifndef __SAVEDATA_PLAYER_H
#define __SAVEDATA_PLAYER_H

#include "swantypes.h"

STRUCT_DECLARE(PlayerSaveData)

#include "field/field_spawn.h"
#include "math/fixed.h"
#include "math/vector.h"

struct PlayerSaveData
{
    ZoneSpawnInfo NowSpawnZone;
    ZoneSpawnInfo WarpRememberZoneInfoUnused;
    ZoneSpawnInfo NextSpawnZone;
    ZoneSpawnInfo EscapeRopeZone;
    u16 ReturnZoneID;
    u8 FlashFlag;
    u8 Season;
    u16 Weather;
    u16 PlaceNameZoneID;
    u32 EggCycleSubstepCounter;
    u16 HappinessStepCounter;
    u16 AbyssalRuinsStepCounter;
    u16 ZoneID;
    u16 _padZoneID;
    VecFx32 Position;
    u16 word90;
    u16 word92;
    u32 dword94;
    fxangle RotationAngle;
    u8 byte9A;
    u8 SpecialState;
    u8 PairID;
    u8 PairActorUIDBackup;
    u16 PairObjCode;
    u16 PairSCRID;
    u16 PairAllyTrID;
    u16 StepCounter;
    u16 _padStepCounter;
};

#endif //__SAVEDATA_PLAYER_H
// Tchaikovsky code generator
