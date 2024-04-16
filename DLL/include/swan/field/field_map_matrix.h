#ifndef __FIELD_MAP_MATRIX_H
#define __FIELD_MAP_MATRIX_H

#include "swantypes.h"

STRUCT_DECLARE(MapMtxSys)

SWAN_CPPTYPE_EX(field, MapMatrixSystem, MapMtxSys)

struct MapMtxSys
{
    s16 HeapID;
    u16 ZoneID;
    u32 MatrixID;
    u16 MatrixWidth;
    u16 MatrixHeight;
    u16 HasZones;
    u16 _padHasZones;
    u32 ChunkIDCount;
    u16 ZoneIDs[900];
    u32 ChunkIDs[900];
};

#endif //__FIELD_MAP_MATRIX_H
// Tchaikovsky code generator
