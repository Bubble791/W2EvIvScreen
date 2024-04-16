#ifndef __FIELD_DISP_CONTROL_H
#define __FIELD_DISP_CONTROL_H

#include "swantypes.h"

STRUCT_DECLARE(FieldDispControlParamSetAlpha)
STRUCT_DECLARE(FieldDispControlParamSetBrightness)
STRUCT_DECLARE(FieldDispControlParamSetAll)
STRUCT_DECLARE(FieldDispControlParamAdjustAlpha)
STRUCT_DECLARE(FieldDispControlParamAdjustBrightness)
UNION_DECLARE(FieldDispControlParam)
STRUCT_DECLARE(FieldDispControl)

ENUM_DECLARE(FieldDispControlScreen)

enum FieldDispControlScreen
#ifdef __cplusplus
: u32
#endif
{
    FLD_DISPCTL_SCREEN_LOWER = 0x0,
    FLD_DISPCTL_SCREEN_UPPER = 0x1,
};

#include "nds/gx.h"

struct FieldDispControlParamSetAlpha
{
    G2DTargetPixel TargetPx1;
    G2DTargetPixel TargetPx2;
    s32 EvA;
    s32 EvB;
};

struct FieldDispControlParamSetBrightness
{
    G2DTargetPixel TargetPx;
    s32 EvY;
};

struct FieldDispControlParamSetAll
{
    G2DTargetPixel TargetPx1;
    G2DTargetPixel TargetPx2;
    s32 EvA;
    s32 EvB;
    s32 EvY;
};

struct FieldDispControlParamAdjustAlpha
{
    s32 EvA;
    s32 EvB;
};

struct FieldDispControlParamAdjustBrightness
{
    s32 EvY;
};

union FieldDispControlParam
{
    FieldDispControlParamSetAlpha SetAlpha;
    FieldDispControlParamSetBrightness SetBrightness;
    FieldDispControlParamSetAll SetAll;
    FieldDispControlParamAdjustAlpha AdjustAlpha;
    FieldDispControlParamAdjustBrightness AdjustBrightness;
};

struct FieldDispControl
{
    u16 TopScreenFunc;
    u16 BottomScreenFunc;
    FieldDispControlParam TopScreenParam;
    FieldDispControlParam BottomScreenParam;
    u8 BGsEnabled[8];
    u8 ReqSetMasterBrightA;
    u8 ReqSetMasterBrightB;
    u8 MasterBrightA;
    u8 MasterBrightB;
};

#endif //__FIELD_DISP_CONTROL_H
// Tchaikovsky code generator
