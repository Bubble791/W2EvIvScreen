#ifndef __MODEL_H
#define __MODEL_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG3DModel)
STRUCT_DECLARE(NNSG3DMaterial)

SWAN_CPPTYPE_EX(ns::g3d, Model, NNSG3DModel)
SWAN_CPPTYPE_EX(ns::g3d, Material, NNSG3DMaterial)

#include "ns/g3d/res/ResModel.h"
#include "ns/g3d/Animation.h"

struct NNSG3DModel
{
    u32 Flags;
    NNSG3DResMdl* ResModel;
    NNSG3DAnimation* MatAnmList;
    void* GetMatAnmValueFunc;
    NNSG3DAnimation* SklAnmList;
    void* GetSklAnmValueFunc;
    NNSG3DAnimation* VisAnmList;
    void* GetVisAnmValueFunc;
    void* UserCallbackFunc;
    u8 UserCallbackTriggerID;
    u8 UserCallbackState;
    u8 field_26;
    u8 field_27;
    void* RenderStartCallback;
    u32 field_2C;
    u8* OverrideRenderCommandPtr;
    void* JointStates;
    NNSG3DMaterial* MaterialStates;
    u32 MatAnmTargetBits[2];
    u32 SklAnmTargetBits[2];
    u32 VisAnmTargetBits[2];
};

struct NNSG3DMaterial
{
    u32 Flags;
    u32 DifAmb;
    u32 SpeEmi;
    u32 PolyAttr;
    u32 TexImageParam;
    u32 PaletteBase;
    fx32 ScaleU;
    fx32 ScaleV;
    fx16 RotSin;
    fx16 RotCos;
    fx32 TransU;
    fx32 TransV;
    u16 TexWidth;
    u16 TexHeight;
    u32 dword30;
    u32 dword34;
};

#endif //__MODEL_H
// Tchaikovsky code generator
