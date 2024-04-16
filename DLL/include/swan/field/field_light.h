#ifndef __FIELD_LIGHT_H
#define __FIELD_LIGHT_H

#include "swantypes.h"

STRUCT_DECLARE(LightColorInterpState)
STRUCT_DECLARE(LightVectorInterpState)
STRUCT_DECLARE(FieldLightInfo)
STRUCT_DECLARE(FieldLightInterpolator)
STRUCT_DECLARE(FieldLightData)
STRUCT_DECLARE(FieldLightFlashInfo)
STRUCT_DECLARE(FieldLightSystem)

SWAN_CPPTYPE(field::g3d, LightColorInterpState)
SWAN_CPPTYPE(field::g3d, LightVectorInterpState)
SWAN_CPPTYPE_EX(field::g3d, LightConfig, FieldLightInfo)
SWAN_CPPTYPE_EX(field::g3d, LightInterpolator, FieldLightInterpolator)
SWAN_CPPTYPE_EX(field::g3d, LightData, FieldLightData)
SWAN_CPPTYPE_EX(field::g3d, LightFlashInfo, FieldLightFlashInfo)
SWAN_CPPTYPE_EX(field::g3d, LightSystem, FieldLightSystem)

#include "nds/gx.h"
#include "math/fixed.h"
#include "math/vector.h"
#include "gfl/g3d/gfl_g3d_light.h"
#include "field/field_fog.h"

struct LightColorInterpState
{
    GXColor Red1;
    s16 RedDiff;
    GXColor Green1;
    s16 GreenDiff;
    GXColor Blue1;
    s16 BlueDiff;
};

struct LightVectorInterpState
{
    VecFx32 SrcDir;
    VecFx32 Axis;
    fxangle AngleAtoB;
    s16 _padAngleAtoB;
};

struct FieldLightInfo
{
    u16 DayPart;
    s16 MinutesOffs;
    u8 LightIsEnabled[4];
    GXColor LightColors[4];
    VecFx16 LightPositions[4];
    GXColor GXDiffuse;
    GXColor GXAmbient;
    GXColor GXSpecular;
    GXColor GXEmission;
    GXColor GXFogColor;
    GXColor ClearColor;
};

struct FieldLightInterpolator
{
    u16 DayPart;
    u16 MinutesOffs;
    u8 IsLightsEnabled[4];
    LightColorInterpState LightColorStates[4];
    LightVectorInterpState LightVectorStates[4];
    LightColorInterpState DiffuseState;
    LightColorInterpState AmbientState;
    LightColorInterpState SpecularState;
    LightColorInterpState EmissionState;
    LightColorInterpState FogColorState;
    LightColorInterpState ClearColorState;
    u16 TransitionFrame;
    u16 TransitionFrameCount;
};

struct FieldLightData
{
    FieldLightInfo Entries[16];
};

struct FieldLightFlashInfo
{
    u16 State;
    u16 IntervalIn;
    u16 IntervalOut;
    GXColor FlashColor;
};

struct FieldLightSystem
{
    u16 ReqFlash;
    u16 Season;
    G3DLight* m_G3DLight;
    FieldFog* m_Fog;
    u32 LightsCount;
    FieldLightData LightData;
    u32 CurrentLightIndex;
    u16 CurrentLightFileNo;
    FieldLightInfo CurrentLightInfo;
    s16 IsEnabled;
    int LightsNeedsUpdate;
    FieldLightInterpolator LightInterpolator;
    FieldLightFlashInfo m_FlashInfo;
    int SecondsOfDay;
};

#endif //__FIELD_LIGHT_H
// Tchaikovsky code generator
