#ifndef __GFL_CONTAINER_H
#define __GFL_CONTAINER_H

#include "swantypes.h"

STRUCT_DECLARE(GFContainer)

SWAN_CPPTYPE_EX(gfl::fs, Container, GFContainer)

struct GFContainer
{
    u16 Signature;
    u16 FileCount;
    u32 FileOffsets[];
};

#endif //__GFL_CONTAINER_H
// Tchaikovsky code generator
