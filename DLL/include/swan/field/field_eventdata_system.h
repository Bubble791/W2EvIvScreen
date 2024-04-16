#ifndef __FIELD_EVENTDATA_SYSTEM_H
#define __FIELD_EVENTDATA_SYSTEM_H

#include "swantypes.h"

STRUCT_DECLARE(EventDataSystem)

SWAN_CPPTYPE_EX(field, EntityDataSystem, EventDataSystem)

#include "gfl/fs/gfl_archive.h"
#include "field/field_encount_data.h"
#include "field/field_eventdata.h"

struct EventDataSystem
{
    u32 field_0;
    ArcTool* EntityNARC;
    ArcTool* EncdataNARC;
    ArcTool* ScriptFileNARC;
    u16 ZoneID;
    u16 nFurniture;
    u16 nActors;
    u16 nWarps;
    u16 nTriggers;
    ZoneFurniture* pFurniture;
    ZoneNPC* pActors;
    ZoneWarp* pWarps;
    ZoneTrigger* pTriggers;
    u16 nFurniture2;
    u16 nActors2;
    u16 nWarps2;
    u16 nTriggers2;
    b32 IsEncountDataLoaded;
    EncData EncountData;
    u8* pInitScr;
    ZoneEntities Entities;
};

#endif //__FIELD_EVENTDATA_SYSTEM_H
// Tchaikovsky code generator
