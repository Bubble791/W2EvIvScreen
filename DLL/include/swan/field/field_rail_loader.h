#ifndef __FIELD_RAIL_LOADER_H
#define __FIELD_RAIL_LOADER_H

#include "swantypes.h"

STRUCT_DECLARE(RailDataHandle)
STRUCT_DECLARE(RailLoader)

#include "gfl/fs/gfl_container.h"
#include "field/field_rail.h"
#include "field/field_rail_system.h"
#include "math/fixed.h"

struct RailDataHandle
{
    u16 PointCount;
    u16 LineCount;
    u16 CameraCount;
    u16 CurveCount;
    u16 FuncSet1Count;
    u16 FuncSet2Count;
    u16 FuncSet3Count;
    u16 _padFuncSet2Count;
    RailPoint* Points;
    RailLine* Lines;
    void* Cameras;
    RailCurve* Curves;
    RailCameraFunc* CameraFuncs;
    RailConvRailToWorldFunc* RailToWorldFuncs;
    RailConvWorldToRailFunc* WorldToRailFuncs;
    fx32 TileWidth;
};

struct RailLoader
{
    GFContainer* m_Container;
    u32 ContainerLength;
    RailDataHandle DataHandle;
};

#endif //__FIELD_RAIL_LOADER_H
// Tchaikovsky code generator
