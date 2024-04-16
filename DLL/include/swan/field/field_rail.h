#ifndef __FIELD_RAIL_H
#define __FIELD_RAIL_H

#include "swantypes.h"

STRUCT_DECLARE(RailPoint)
STRUCT_DECLARE(RailLine)
STRUCT_DECLARE(RailCurve)
STRUCT_DECLARE(RailCameraCoordsAbs)
STRUCT_DECLARE(RailCameraCoordsPlayer)
STRUCT_DECLARE(RailCameraCoordsViewpoint)
STRUCT_DECLARE(RailCameraCoordsViewpointLerp)
UNION_DECLARE(RailCameraCoords)
STRUCT_DECLARE(RailCamera)
UNION_DECLARE(RailComponent)

#include "math/vector.h"
#include "math/fixed.h"

struct RailPoint
{
    u32 ConnectedLines[4];
    u32 LineDirections[4];
    u32 LineWidths[4];
    VecFx32 Position;
    u32 Camera;
    char Name[48];
};

struct RailLine
{
    u32 Point1;
    u32 Point2;
    u32 Angle;
    u32 Curve;
    u32 Camera;
    u32 TileLength;
    char Name[48];
};

struct RailCurve
{
    u32 Type;
    VecFx32 Position;
    char Padding[20];
};

struct RailCameraCoordsAbs
{
    VecFx32 Eye;
    VecFx32 Target;
};

struct RailCameraCoordsPlayer
{
    u32 Pitch;
    u32 Yaw;
    fx32 Zoom;
    VecFx32 TargetOffset;
};

struct RailCameraCoordsViewpoint
{
    fx32 Pitch;
    fx32 Distance;
    VecFx32 Target;
};

struct RailCameraCoordsViewpointLerp
{
    u32 Pitch;
    fx32 Distance;
    VecFx32 TargetStart;
    VecFx32 TargetEnd;
};

union RailCameraCoords
{
    RailCameraCoordsAbs Abs;
    RailCameraCoordsPlayer Player;
    RailCameraCoordsViewpoint Viewpoint;
    RailCameraCoordsViewpointLerp ViewpointLerp;
};

struct RailCamera
{
    u32 Type;
    RailCameraCoords Coords;
};

union RailComponent
{
    RailPoint* Point;
    RailLine* Line;
};

#endif //__FIELD_RAIL_H
// Tchaikovsky code generator
