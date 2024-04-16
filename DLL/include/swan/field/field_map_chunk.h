#ifndef __FIELD_MAP_CHUNK_H
#define __FIELD_MAP_CHUNK_H

#include "swantypes.h"

STRUCT_DECLARE(FieldChunkVTable)
STRUCT_DECLARE(FieldChunkLoader)
STRUCT_DECLARE(FieldChunkContext)
STRUCT_DECLARE(FieldChunk)

#include "gfl/core/gfl_heap.h"
#include "field/field_static_prop.h"
#include "field/field_terrain_animator.h"
#include "gfl/g3d/gfl_g3d_system.h"
#include "ns/g3d/Model.h"
#include "gfl/fs/gfl_container.h"
#include "math/vector.h"
#include "field/field_rail_tile.h"

struct FieldChunkVTable
{
    u32 Magic;
    void (*LoaderUpdateFunc)(FieldChunk* chunk, FieldChunkContext* context);
    void (*GetTerrainFunc)(MapTerrainSamplerOutput*, GFContainer*, VecFx32*, fx32, fx32);
    void (*GetTerrainBaseLayerFunc)(MapTerrainSamplerOutput*, GFContainer*, VecFx32*, fx32, fx32);
};

struct FieldChunkLoader
{
    u16 State;
    u16 _padState;
    u32 NowLoadedDataLength;
    u32 BufferLoadedDataLength;
    u32 TotalRawDataLength;
    b32 field_10;
    b32 field_14;
    b32 field_18;
    b32 field_1C;
    b32 IsTerrainLoadDone;
};

struct FieldChunkContext
{
    FieldTerrainSRTAnimatorChunkState* m_SRTAnimatorState;
    FieldPropSystem* m_PropSystem;
    void* WFBC;
    void* ResortMap;
    u32 ChunkIdx;
    HeapID m_HeapID;
    u16 _padHeapID;
};

struct FieldChunk
{
    u16 Active;
    u16 DisableStreamer;
    VecFx32 ChunkWorldPos;
    ArcTool* MapChunkArc;
    u32 ReqLoadDatID;
    u32 VTableIndex;
    u32 ChunkBufferSize;
    u32 TextureVRAMSize;
    u32 ChunkStreamerBufSize;
    FieldChunkVTable* ChunkVTableSet;
    NNSG3DModel* m_NNSModelPtr;
    NNSG3DModel m_NNSModel;
    G3DResource* ModelRsc;
    G3DResource* TexRsc1;
    u32 TextureVRAM;
    u32 PaletteVRAM;
    G3DResource* MapTextures;
    FieldPropResBank* PropResBank;
    FieldPropInstance* PropInstances;
    FieldPropInstance* PropInstances2;
    u16 PropCapacity1;
    u16 PropCapacity2;
    u32 field_A8;
    u32 field_AC;
    FieldChunkLoader Loader;
    GFContainer* ChunkContainer;
    FieldChunkContext* Context;
};

#endif //__FIELD_MAP_CHUNK_H
// Tchaikovsky code generator
