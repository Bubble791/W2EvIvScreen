#ifndef __FIELD_MAP_TERRAIN_H
#define __FIELD_MAP_TERRAIN_H

#include "swantypes.h"

STRUCT_DECLARE(TileType)
STRUCT_DECLARE(MapTerrainBuf)
STRUCT_DECLARE(MapTerrainSamplerOutput)

struct TileType
{
    u16 Class;
    u16 Flags;
};

struct MapTerrainBuf
{
    s16 SlopeX;
    s16 HeightDiv;
    s16 SlopeZ;
    u16 _padSlopeZ;
    TileType m_TileType;
    fx32 HeightY;
};

struct MapTerrainSamplerOutput
{
    MapTerrainBuf TerrainBuffers[16];
    u32 LayerCount;
};

#endif //__FIELD_MAP_TERRAIN_H
// Tchaikovsky code generator
