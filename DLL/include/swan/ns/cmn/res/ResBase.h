#ifndef __RESBASE_H
#define __RESBASE_H

#include "swantypes.h"

STRUCT_DECLARE(NNSCmnResHeader)
STRUCT_DECLARE(NNSCmnResBlockHeader)

SWAN_CPPTYPE_EX(ns::cmn::res, Header, NNSCmnResHeader)
SWAN_CPPTYPE_EX(ns::cmn::res, BlockHeader, NNSCmnResBlockHeader)

struct NNSCmnResHeader
{
    s32 Magic;
    s16 BOM;
    u16 Version;
    u32 FileSize;
    u16 HeaderSize;
    u16 BlockCount;
};

struct NNSCmnResBlockHeader
{
    u32 Magic;
    u32 BlockSize;
};

#endif //__RESBASE_H
// Tchaikovsky code generator
