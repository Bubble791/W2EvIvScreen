#ifndef __FIELD_RAIL_TILE_H
#define __FIELD_RAIL_TILE_H

#include "swantypes.h"

STRUCT_DECLARE(FieldRailTilemapBlock)
STRUCT_DECLARE(FieldRailTilemap)

#include "field/field_map_terrain.h"

struct FieldRailTilemapBlock
{
    u16 Width;
    u16 Height;
    TileType Tiles[];
};

struct FieldRailTilemap
{
    void* RawData;
    u32 DataLength;
    u32 BlockCount;
    FieldRailTilemapBlock** Blocks;
};

#endif //__FIELD_RAIL_TILE_H
// Tchaikovsky code generator
