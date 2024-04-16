#ifndef __G3DRESDATA_H
#define __G3DRESDATA_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG3DResData)

SWAN_CPPTYPE_EX(ns::g3d::res, Data, NNSG3DResData)

#include "ns/g3d/res/ResTexture.h"
#include "ns/cmn/res/ResBase.h"

C_DECL_BEGIN

extern NNSG3DResTex*   NNS_G3DResGetTexBlock(NNSG3DResData* res);

C_DECL_END

struct NNSG3DResData
{
    NNSCmnResHeader Header;
    u32 BlockOffsets[];
  
    #ifdef __cplusplus
  
    INLINE ns::g3d::res::TexData* GetTexBlock() {
        return NNS_G3DResGetTexBlock(this);
    }

    #endif
};

#endif //__G3DRESDATA_H
// Tchaikovsky code generator
