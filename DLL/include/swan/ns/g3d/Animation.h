#ifndef __ANIMATION_H
#define __ANIMATION_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG3DAnimation)

SWAN_CPPTYPE_EX(ns::g3d, Animation, NNSG3DAnimation)

#include "ns/g3d/res/ResAnimation.h"
#include "ns/g3d/res/ResTexture.h"
#include "math/fixed.h"

struct NNSG3DAnimation
{
    fx32 NowFrame;
    fx32 dword4;
    NNSG3DResAnm* ResAnimation;
    void* VTable;
    NNSG3DAnimation* Next;
    NNSG3DResTex* Textures;
    u8 Priority;
    u8 TargetCount;
    u16 TargetInfo[1];
};

#endif //__ANIMATION_H
// Tchaikovsky code generator
