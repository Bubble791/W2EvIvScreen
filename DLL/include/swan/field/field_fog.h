#ifndef __FIELD_FOG_H
#define __FIELD_FOG_H

#include "swantypes.h"

STRUCT_DECLARE(FieldFogAnimation)
STRUCT_DECLARE(FieldFog)
STRUCT_DECLARE(FieldFogCtrl)

#include "nds/gx.h"
#include "gfl/fs/gfl_archive.h"

struct FieldFogAnimation
{
    u16 NowFrame;
    u16 EndFrame;
    s32 FogOffsetStart;
    s32 FogOffsetAddend;
    s32 FogDepthShiftStart;
    s32 FogDepthShiftAddend;
};

struct FieldFog
{
    u8 FogIsEnabled;
    u8 FogAlphaMode;
    u8 FogDepthShift;
    u8 FogAlpha;
    u32 FogOffset;
    GXColor FogColor;
    u16 _padFogColor;
    u8 FogTable[32];
    FieldFogAnimation Animation;
    b32 IsDirty;
};

struct FieldFogCtrl
{
    u8 NeedsReloadData;
    u8 ReloadInterval;
    u16 CurrentFog;
    void* FogArcData;
    u32 StaticLightIndex;
    ArcTool* FogArcHandle;
};

#endif //__FIELD_FOG_H
// Tchaikovsky code generator
