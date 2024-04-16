#ifndef __RESCHARACTER_H
#define __RESCHARACTER_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG2DResCharHeader)
STRUCT_DECLARE(NNSG2DResCharBlock)

SWAN_CPPTYPE_EX(ns::g2d::res, CharHeader, NNSG2DResCharHeader)
SWAN_CPPTYPE_EX(ns::g2d::res, CharBlock, NNSG2DResCharBlock)

#include "ns/cmn/res/ResBase.h"

struct NNSG2DResCharHeader
{
    u16 TileHeight;
    u16 TileWidth;
    u32 PixelFormat;
    u16 field_8;
    u16 field_A;
    u32 field_C;
    u32 TileDataSize;
    char* TileDataOffs;
};

struct NNSG2DResCharBlock
{
    NNSCmnResBlockHeader BlockHeader;
    NNSG2DResCharHeader Header;
};

#endif //__RESCHARACTER_H
// Tchaikovsky code generator
