#ifndef __FIELD_G3D_MAPPER_H
#define __FIELD_G3D_MAPPER_H

#include "swantypes.h"

STRUCT_DECLARE(FieldG3DMapperConfig)
STRUCT_DECLARE(FieldG3DMapper)
STRUCT_DECLARE(FieldChunkLocator)
STRUCT_DECLARE(FieldChunkHandle)

#include "math/vector.h"
#include "field/field_terrain_animator.h"
#include "gfl/g3d/gfl_g3d_system.h"
#include "field/field_static_prop.h"
#include "gfl/core/gfl_heap.h"
#include "math/fixed.h"
#include "field/field_map_chunk.h"

struct FieldG3DMapperConfig
{
    fx32 ChunkSpan;
    u32 field_4;
    u16 ChunkLoadDiameterX;
    u16 ChunkLoadDiameterZ;
    u32 LocatorGenType;
    u32 ChunkArcID;
    s16 MatrixWidth;
    s16 MatrixHeight;
    u32 ChunkIDCount;
    u32* ChunkDatIDs;
    b32 IsSharedTexResource;
    u32 TexturesArcID;
    u32 TexturesID;
    FieldTerrainAnmInfo m_TerrainAnmInfo;
    u32 ChunkBufferSize;
    u32 RenderPhase1MaxChunkCount;
};

struct FieldG3DMapper
{
    HeapID m_HeapID;
    u16 _padHeapID;
    int ChunkSpan;
    int field_8;
    int LocatorGenType;
    int ChunkArcID;
    u16 MatrixWidth;
    u16 MatrixHeight;
    int ChunkIDCount;
    u32* ChunkDatIDs;
    int IsSharedTexResource;
    FieldChunkHandle* ChunkHandles;
    FieldChunkLocator* ChunkLocators;
    u8 ChunkLoadDiameterX;
    u8 ChunkLoadDiameterZ;
    u16 ChunkCapacity;
    int ChunkIDOfPlayer;
    VecFx32 PlayerPos;
    u8 Phase1MaxChunkCount;
    u8 DrawnChunkCount;
    u8 LastDrawnCount;
    u8 NowDrawnCount;
    u8* DrawnChunkIndices;
    int MaxConcurrentDrawChunkByteSize;
    u8 ChunkSizeCapPassingChunkEndIdx;
    u8 NowDrawScanline;
    u16 field_4E;
    int field_50;
    VecFx32 ChunkBasePos;
    G3DResource* MapTextures;
    FieldPropSystem* m_PropSystem;
    FieldTerrainAnimator* m_TerrainAnimator;
    void* WFBC;
    void* ResortMap;
    void* HeightEx;
};

struct FieldChunkLocator
{
    u32 ChunkID;
    VecFx32 Position;
};

struct FieldChunkHandle
{
    FieldChunk* Chunk;
    FieldChunkContext Context;
    FieldChunkLocator Locator;
};

#endif //__FIELD_G3D_MAPPER_H
// Tchaikovsky code generator
