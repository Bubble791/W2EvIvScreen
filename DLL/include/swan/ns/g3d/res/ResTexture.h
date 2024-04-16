#ifndef __RESTEXTURE_H
#define __RESTEXTURE_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG3DResTexHeader)
STRUCT_DECLARE(NNSG3DResTexCmprHeader)
STRUCT_DECLARE(NNSG3DResPaletteHeader)
STRUCT_DECLARE(NNSG3DResTex)

SWAN_CPPTYPE_EX(ns::g3d::res, TexHeader, NNSG3DResTexHeader)
SWAN_CPPTYPE_EX(ns::g3d::res, TexCmprHeader, NNSG3DResTexCmprHeader)
SWAN_CPPTYPE_EX(ns::g3d::res, PaletteHeader, NNSG3DResPaletteHeader)
SWAN_CPPTYPE_EX(ns::g3d::res, TexData, NNSG3DResTex)

#include "ns/g3d/res/PATRICIATree.h"
#include "ns/g3d/res/G3DResData.h"
#include "ns/cmn/res/ResBase.h"

C_DECL_BEGIN

extern void    NNS_G3DResTexUploadTex(NNSG3DResTex* tex, int a2);

C_DECL_END

struct NNSG3DResTexHeader
{
    u32 RTVRAMAddr;
    u16 ImageSize;
    u16 NameTreeOffs;
    u16 Flags;
    u16 _padFlags;
    u32 ImageOffset;
};

struct NNSG3DResTexCmprHeader
{
    u32 RTVRAMAddr;
    u16 ImageSize;
    u16 NameTreeOffs;
    u16 Flags;
    u16 _padFlags;
    u32 ImageOffset;
    u32 IndexDataOffset;
};

struct NNSG3DResPaletteHeader
{
    u32 RTVRAMAddr;
    u16 ImageSize;
    u16 Flags;
    u16 NameTreeOffs;
    u16 _padNameTreeOffs;
    u32 ImageOffset;
};

struct NNSG3DResTex
{
    NNSCmnResBlockHeader BlockHeader;
    NNSG3DResTexHeader TexHeader;
    NNSG3DResTexCmprHeader CompressedTexHeader;
    NNSG3DResPaletteHeader PaletteHeader;
    NNSPatriciaTree TextureTree;
  
    #ifdef __cplusplus
  
    INLINE void Upload(int a2) {
        NNS_G3DResTexUploadTex(this, a2);
    }

    #endif
};

#endif //__RESTEXTURE_H
// Tchaikovsky code generator
