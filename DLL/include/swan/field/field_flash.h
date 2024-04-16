#ifndef __FIELD_FLASH_H
#define __FIELD_FLASH_H

#include "swantypes.h"

STRUCT_DECLARE(FieldFlashAnimation)
STRUCT_DECLARE(FieldFlash)
STRUCT_DECLARE(FieldFlashG3D)

#include "gfl/g3d/gfl_g3d_system.h"

struct FieldFlashAnimation
{
    fx32 Scale;
    u8 Alpha;
    u16 NowFrame;
    u16 EndFrame;
    u16 _padEndFrame;
    fx32 ScaleSrc;
    fx32 ScaleAddend;
    u16 AlphaSrc;
    s16 AlphaAddend;
};

struct FieldFlash
{
    FieldFlashG3D* m_G3D;
    FieldFlashAnimation m_Animation;
    u16 AnimationState;
    u16 State;
};

struct FieldFlashG3D
{
    G3DResource* ModelResource;
    G3DActor* Actor;
};

#endif //__FIELD_FLASH_H
// Tchaikovsky code generator
