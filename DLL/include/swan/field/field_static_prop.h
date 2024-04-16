#ifndef __FIELD_STATIC_PROP_H
#define __FIELD_STATIC_PROP_H

#include "swantypes.h"

STRUCT_DECLARE(FieldPropRTCState)
STRUCT_DECLARE(FieldPropResBank)
STRUCT_DECLARE(FieldPropResInstanceHandle)
STRUCT_DECLARE(FieldChunkPropHolder)
STRUCT_DECLARE(FieldPropSystem)
STRUCT_DECLARE(FieldPropResBundle)
STRUCT_DECLARE(FieldPropResAnmHeader)
STRUCT_DECLARE(FieldPropResInfo)
STRUCT_DECLARE(FieldPropResource)
STRUCT_DECLARE(FieldPropResInstance)
STRUCT_DECLARE(FieldPropHandle)
STRUCT_DECLARE(FieldPropPosition)
STRUCT_DECLARE(FieldPropInstance)

ENUM_DECLARE(FieldPropAnmStatus)

enum FieldPropAnmStatus
#ifdef __cplusplus
: u32
#endif
{
    FIELD_PROP_ANMSTATUS_NONE = 0x0,
    FIELD_PROP_ANMSTATUS_PLAY_LOOP = 0x1,
    FIELD_PROP_ANMSTATUS_PAUSED = 0x2,
    FIELD_PROP_ANMSTATUS_PLAY = 0x3,
    FIELD_PROP_ANMSTATUS_PLAY_INV = 0x4,
};

#include "field/field_map_chunk.h"
#include "gfl/g3d/gfl_g3d_system.h"
#include "gfl/g3d/gfl_transform.h"
#include "field/field_g3d_mapper.h"
#include "gfl/core/gfl_heap.h"

struct FieldPropRTCState
{
    u32 NowDayPart;
    u32 PreviousDayPart;
    b32 HasDayPartChanged;
    u8 ReqPlayAnimeID;
    u8 Season;
    u16 _padding;
};

struct FieldPropResBank
{
    FieldPropResInstanceHandle* m_ResInstanceHandles;
    u32 Count;
};

struct FieldPropResInstanceHandle
{
    G3DActor* m_G3DActor;
    int field_4;
};

struct FieldChunkPropHolder
{
    FieldChunk* m_Chunk;
    u32 LastResIndex;
    u16 InstanceIndex;
    u16 IsVisible;
    FieldPropInstance* m_PropInstance;
};

struct FieldPropSystem
{
    HeapID m_HeapID;
    u16 _padHeapID;
    FieldG3DMapper* m_G3DMapper;
    FieldPropRTCState m_RTCState;
    FieldPropResBundle* ResBundle;
    u8 ResIDToBundleIndexLUT[512];
    u32 ResBundleEntryCount;
    FieldPropResBank m_ResBank;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    u32 ResourceCount;
    FieldPropResource* Resources;
    G3DResource* TextureNSBTX;
    u32 ResInstanceCount;
    FieldPropResInstance* m_ResInstances;
    FieldPropHandle* PropHandles[7];
    FieldChunkPropHolder m_ChunkPropHolders[288];
};

struct FieldPropResBundle
{
    u16 Signature;
    u16 FileCount;
    u32 Offsets[];
};

struct FieldPropResAnmHeader
{
    u16 AnmCntType;
    u8 OneAnmSetSize;
    u8 ItemCount;
    u32 AnimeOffsets[4];
};

struct FieldPropResInfo
{
    u16 UID;
    u16 Type;
    u16 DoorUID;
    s16 DoorX;
    s16 DoorY;
    s16 DoorZ;
    u16 Unk1;
    u16 Unk2;
    FieldPropResAnmHeader AnimeHeader;
};

struct FieldPropResource
{
    FieldPropResInfo* m_Info;
    G3DResource* ModelData;
    G3DResource* AnimeData[4];
};

struct FieldPropResInstance
{
    G3DActor* m_G3DActor;
    FieldPropResource* m_PropResource;
    FieldPropAnmStatus AnimationStatuses[4];
};

struct FieldPropHandle
{
    FieldPropSystem* m_PropSystem;
    u32 CurrentAnmIdx;
    FieldChunkPropHolder* m_ChunkPropHolder;
    FieldPropResInstance m_ResInstance;
    SRTMatrix ModelMatrix;
};

struct FieldPropPosition
{
    VecFx32 Position;
    u16 RotationY;
    u16 _padding;
};

struct FieldPropInstance
{
    u32 ResIndex;
    FieldPropPosition Pos;
};

#endif //__FIELD_STATIC_PROP_H
// Tchaikovsky code generator
