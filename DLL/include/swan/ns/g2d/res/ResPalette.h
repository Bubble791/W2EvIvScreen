#ifndef __RESPALETTE_H
#define __RESPALETTE_H

#include "swantypes.h"

STRUCT_DECLARE(NNSG2DResPaletteHeader)
STRUCT_DECLARE(NNSG2DResPaletteBlock)

SWAN_CPPTYPE_EX(ns::g2d::res, PaletteHeader, NNSG2DResPaletteHeader)
SWAN_CPPTYPE_EX(ns::g2d::res, PaletteBlock, NNSG2DResPaletteBlock)

#include "ns/cmn/res/ResBase.h"

struct NNSG2DResPaletteHeader
{
    u32 ColorDepth;
    u32 BaseDataOffs;
    u32 RawDataSize;
    char* RawDataOffset;
    char RawData[];
};

struct NNSG2DResPaletteBlock
{
    NNSCmnResBlockHeader BlockHeader;
    NNSG2DResPaletteHeader PLTTHeader;
};

#endif //__RESPALETTE_H
// Tchaikovsky code generator
