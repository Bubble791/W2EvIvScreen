#ifndef __RESANIMATION_H
#define __RESANIMATION_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG3DResAnm)
STRUCT_DECLARE(NNSG3DResAnmBlock)

SWAN_CPPTYPE_EX(ns::g3d::res, Animation, NNSG3DResAnm)
SWAN_CPPTYPE_EX(ns::g3d::res, AnimationBlock, NNSG3DResAnmBlock)

#include "ns/g3d/res/PATRICIATree.h"
#include "ns/cmn/res/ResBase.h"
#include "ns/g3d/res/G3DResData.h"

struct NNSG3DResAnm
{
    u8 TargetID;
    u8 field_1;
    u16 TypeID;
    u16 FrameCount;
    u16 TargetCount;
};

struct NNSG3DResAnmBlock
{
    NNSCmnResBlockHeader BlockHeader;
    NNSPatriciaTree AnimationTree;
};

#endif //__RESANIMATION_H
// Tchaikovsky code generator
