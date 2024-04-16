#ifndef __RESMODEL_H
#define __RESMODEL_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG3DResMdlInfo)
STRUCT_DECLARE(NNSG3DResMdl)
STRUCT_DECLARE(NNSG3DResMdlBlock)
STRUCT_DECLARE(NNSG3DResMaterial)

SWAN_CPPTYPE_EX(ns::g3d::res, ModelInfo, NNSG3DResMdlInfo)
SWAN_CPPTYPE_EX(ns::g3d::res, Model, NNSG3DResMdl)
SWAN_CPPTYPE_EX(ns::g3d::res, ModelBlock, NNSG3DResMdlBlock)
SWAN_CPPTYPE_EX(ns::g3d::res, Material, NNSG3DResMaterial)

#include "ns/g3d/res/PATRICIATree.h"
#include "ns/cmn/res/ResBase.h"
#include "ns/g3d/res/G3DResData.h"

struct NNSG3DResMdlInfo
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 JointCount;
    u8 MaterialCount;
    u8 MeshCount;
    u8 MtxStackTop;
    u8 field_7;
    fx32 GlobalScale;
    fx32 GlobalScaleInv;
    u16 VertexCount;
    u16 FaceCount;
    u16 TriCount;
    u16 QuadCount;
    VecFx16 BBoxMin;
    VecFx16 BBoxDim;
    fx32 BBoxScale;
    fx32 BBoxScaleInv;
};

struct NNSG3DResMdl
{
    u32 Size;
    u32 RenderCmdOffset;
    u32 MaterialsOffset;
    u32 MeshesOffset;
    u32 IBPMatrixOffset;
    NNSG3DResMdlInfo Info;
    NNSPatriciaTree JointTree;
};

struct NNSG3DResMdlBlock
{
    NNSCmnResBlockHeader BlockHeader;
    NNSPatriciaTree ModelTree;
};

struct NNSG3DResMaterial
{
    u16 field_0;
    u16 Size;
    u32 DifAmb;
    u32 SpeEmi;
    u32 PolyAttr;
    u32 PolyAttrMask;
    u32 TexImageParam;
    u32 TexImageParamMask;
    u16 PaletteBase;
    u16 Flags;
    u16 TexWidth;
    u16 TexHeight;
    fx32 field_24;
    fx32 field_28;
    u8 Transform[];
};

#endif //__RESMODEL_H
// Tchaikovsky code generator
