#ifndef __ISS_H
#define __ISS_H

#include "swantypes.h"

STRUCT_DECLARE(ISS)

#include "gfl/core/gfl_heap.h"
#include "system/game_data.h"
#include "field/iss_city.sys.h"
#include "field/iss_3ds_sys.h"
#include "field/iss_dungeon_sys.h"
#include "field/iss_road_sys.h"
#include "field/iss_switch_sys.h"
#include "field/iss_zone_sys.h"

struct ISS
{
    HeapID m_HeapID;
    u16 _padHeapID;
    GameData* m_GameData;
    u32 NowBoundBGM;
    u32 FrameCounter;
    ISSCitySys* m_CitySys;
    ISSRoadSystem* m_RoadSys;
    ISSDungeonSys* m_DungeonSys;
    ISSZoneSys* m_ZoneSys;
    ISSSwitchSys* m_SwitchSys;
    ISS3DSoundSys* m_3DSoundSys;
};

#endif //__ISS_H
// Tchaikovsky code generator
