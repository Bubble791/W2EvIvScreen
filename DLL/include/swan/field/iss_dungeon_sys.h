#ifndef __ISS_DUNGEON_SYS_H
#define __ISS_DUNGEON_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(ISSDungeonSys)
STRUCT_DECLARE(ISSDungeonList)
STRUCT_DECLARE(ISSDungeonConfig)

#include "system/game_data.h"
#include "field/field_player.h"
#include "gfl/core/gfl_heap.h"

struct ISSDungeonSys
{
    HeapID m_HeapID;
    u16 _padHeapID;
    PlayerState* m_PlayerState;
    GameData* m_GameData;
    int IsEnabled;
    u16 NowZoneID;
    u16 ReqZoneID;
    ISSDungeonList* m_Dungeons;
    ISSDungeonConfig* NowDungeon;
    u16 field_1C;
    u16 field_1E;
    u16 field_20[4];
    u16 field_28[4];
    u16 field_30[4];
};

struct ISSDungeonList
{
    u8 Count;
    u8 _padCount1;
    u16 _padCount2;
    ISSDungeonConfig* Entries;
};

struct ISSDungeonConfig
{
    u16 ZoneID;
    u16 field_2;
    s16 SeasonalPitch[4];
    u16 SeasonalBitMask[4];
    u32 field_14;
    u32 field_18;
};

#endif //__ISS_DUNGEON_SYS_H
// Tchaikovsky code generator
