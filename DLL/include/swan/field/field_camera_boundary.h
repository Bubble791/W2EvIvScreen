#ifndef __FIELD_CAMERA_BOUNDARY_H
#define __FIELD_CAMERA_BOUNDARY_H

#include "swantypes.h"

STRUCT_DECLARE(CameraBoundaryCoordsRect)
STRUCT_DECLARE(CameraBoundaryCoordsCircle)
STRUCT_DECLARE(CameraBoundary)

#include "math/fixed.h"

struct CameraBoundaryCoordsRect
{
    s32 West;
    s32 East;
    s32 North;
    s32 South;
};

struct CameraBoundaryCoordsCircle
{
    fx32 X;
    fx32 Z;
    fx32 DistMax;
    u16 AngleMin;
    u16 AngleMax;
};

struct CameraBoundary
{
    u32 Func;
    b32 IsCamPosNotTgt;
    union
    {
        CameraBoundaryCoordsRect Rect;
        CameraBoundaryCoordsCircle Circle;
    };
};

#endif //__FIELD_CAMERA_BOUNDARY_H
// Tchaikovsky code generator
