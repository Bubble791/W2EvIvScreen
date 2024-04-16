#ifndef __FIELD_EVENTDATA_H
#define __FIELD_EVENTDATA_H

#include "swantypes.h"

STRUCT_DECLARE(ZoneFurniture)
STRUCT_DECLARE(ZoneNPCPositionGrid)
STRUCT_DECLARE(ZoneNPCPositionRail)
UNION_DECLARE(ZoneNPCPosition)
STRUCT_DECLARE(ZoneNPC)
STRUCT_DECLARE(ZoneWarp)
STRUCT_DECLARE(ZoneTrigger)
STRUCT_DECLARE(ZoneEntities)

SWAN_CPPTYPE_EX(field, EntityObj, ZoneFurniture)
SWAN_CPPTYPE_EX(field, EntityNPCPositionGrid, ZoneNPCPositionGrid)
SWAN_CPPTYPE_EX(field, EntityNPCPositionRail, ZoneNPCPositionRail)
SWAN_CPPTYPE_EX(field, EntityNPCPosition, ZoneNPCPosition)
SWAN_CPPTYPE_EX(field, EntityNPC, ZoneNPC)
SWAN_CPPTYPE_EX(field, EntityWarp, ZoneWarp)
SWAN_CPPTYPE_EX(field, EntityTrigger, ZoneTrigger)
SWAN_CPPTYPE_EX(field, EntityData, ZoneEntities)

struct ZoneFurniture
{
    u16 SCRID;
    u16 Condition;
    u16 Interactibility;
    u16 IsRail;
    int X;
    int Z;
    int Y;
};

struct ZoneNPCPositionGrid
{
    u16 GPosX;
    u16 GPosZ;
    int Y;
};

struct ZoneNPCPositionRail
{
    __int16 LineID;
    __int16 PosFront;
    __int16 PosSide;
    __int16 Padding;
};

union ZoneNPCPosition
{
    ZoneNPCPositionGrid Grid;
    ZoneNPCPositionRail Rail;
};

struct ZoneNPC
{
    u16 UID;
    u16 ModelID;
    u16 MoveCode;
    u16 EvType;
    u16 SpawnFlag;
    u16 SCRID;
    u16 Direction;
    u16 Param0;
    u16 Param1;
    u16 Param2;
    u16 AreaW;
    u16 AreaH;
    b32 IsPositionRail;
    ZoneNPCPosition Pos;
};

struct ZoneWarp
{
    u16 DestZone;
    u16 DestWarp;
    u8 Direction;
    char TransitionType;
    u16 IsRail;
    u16 X;
    s16 Y;
    u16 Z;
    u16 W;
    u16 H;
    u16 field_12;
};

struct ZoneTrigger
{
    u16 SCRID;
    u16 WkRefVal;
    u16 WKID;
    u16 Unk6;
    u16 Unk8;
    u16 X;
    u16 Z;
    u16 W;
    u16 H;
    s16 Y;
    u16 field_14;
};

struct ZoneEntities
{
    int InitScrOffset;
    char nFurniture;
    char nActor;
    char nWarp;
    char nTrigger;
    char Content[2428];
};

#endif //__FIELD_EVENTDATA_H
// Tchaikovsky code generator
