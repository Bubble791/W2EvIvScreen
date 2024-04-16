#ifndef __FIELD_RAIL_SYSTEM_H
#define __FIELD_RAIL_SYSTEM_H

#include "swantypes.h"

STRUCT_DECLARE(RailPosition)
STRUCT_DECLARE(FieldRailSystem)
STRUCT_DECLARE(RailUnit)

typedef void (*RailCameraFunc)(FieldRailSystem*);
typedef void (*RailConvRailToWorldFunc)(RailUnit* unit, VecFx32* dest);
typedef b32 (*RailConvWorldToRailFunc)(u32 lineId, FieldRailSystem* railSystem, VecFx32* worldPos, RailPosition* dest, VecFx32* alignedWorldPos);

#include "field/field_camera.h"
#include "gfl/core/gfl_heap.h"
#include "field/field_rail.h"
#include "field/field_rail_loader.h"

struct RailPosition
{
    u16 ComponentID;
    u8 ComponentIsLine;
    u8 RailDirection;
    s16 PosSide;
    u16 PosFront;
};

struct FieldRailSystem
{
    HeapID m_HeapID;
    u16 IsDataLoaded;
    u16 field_4;
    u16 field_6;
    RailUnit* Units;
    u32 UnitCount;
    FieldCamera* m_FieldCamera;
    RailUnit* CameraParentUnit;
    b32 CameraIsDirty;
    RailUnit* PlayerUnit;
    RailDataHandle RailData;
    u16 field_50[18];
};

struct RailUnit
{
    u16 ComponentIsLine;
    u16 State;
    RailComponent CurrentComponent;
    u16 field_8;
    u16 field_A;
    u32 PosVWS;
    u32 LineLengthWorldSpace;
    s32 PosHWS;
    u32 LerpedLineWidth;
    fx32 TileWidth;
    u32 CurrentLineDirection;
    RailDataHandle* RailData;
    u16* field_28;
    u8 field_2C;
    u8 field_2D;
    u16 field_2E;
    u8 field_30;
    u8 field_31;
    u8 Direction;
    u8 field_33;
    u32 field_34;
    VecFx32 CalcPos;
    VecFx32 field_44;
    VecFx32 field_50;
    RailPosition field_5C;
    RailPosition field_64;
    RailPosition field_6C;
    u32 field_74;
    FieldRailSystem* m_RailSystem;
};

#endif //__FIELD_RAIL_SYSTEM_H
// Tchaikovsky code generator
