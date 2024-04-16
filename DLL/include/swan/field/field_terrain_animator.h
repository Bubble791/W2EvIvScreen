#ifndef __FIELD_TERRAIN_ANIMATOR_H
#define __FIELD_TERRAIN_ANIMATOR_H

#include "swantypes.h"

STRUCT_DECLARE(FieldTerrainAnmInfo)
STRUCT_DECLARE(FieldTerrainAnimatorSetup)
STRUCT_DECLARE(FieldTerrainSRTAnimatorChunkState)
STRUCT_DECLARE(FieldTerrainSRTAnimator)
STRUCT_DECLARE(FieldTerrainTexPatAnimation)
STRUCT_DECLARE(FieldTerrainTexPatAnimationEntry)
STRUCT_DECLARE(FieldTerrainTexPatAnimationPack)
STRUCT_DECLARE(FieldTerrainTexPatAnimator)
STRUCT_DECLARE(FieldTerrainAnimator)

#include "ns/g3d/res/G3DResData.h"
#include "ns/g3d/res/ResAnimation.h"
#include "gfl/g3d/gfl_g3d_tpanm.h"
#include "gfl/g3d/gfl_g3d_system.h"
#include "math/fixed.h"
#include "ns/g3d/Animation.h"

struct FieldTerrainAnmInfo
{
    u32 SRTAnimeID;
    u32 PatAnimeID;
};

struct FieldTerrainAnimatorSetup
{
    u16 Flags;
    u16 ChunkCapacity;
    u16 ARCIDSRT;
    u16 IdSRT;
    u16 ARCIDPat;
    u16 IdPat;
};

struct FieldTerrainSRTAnimatorChunkState
{
    u32 Flags;
    NNSG3DAnimation* m_NNSAnimation;
    NNSG3DResAnm* m_ResAnm;
};

struct FieldTerrainSRTAnimator
{
    FieldTerrainSRTAnimatorChunkState* ChunkStates;
    u32 ChunkStateCount;
    NNSG3DResData* NSBTAData;
    fx32 NowFrame;
};

struct FieldTerrainTexPatAnimation
{
    b32 IsLoaded;
    GFBTPValue* CurrentValues;
    int* TextureDestVRAMAddresses;
    int* TextureSizes;
    u32* FrameCounters;
    u32 TargetCount;
    G3DResource* WorldTextures;
    void* GFBTPData;
    GFBTPController m_GFBTPController;
    G3DResource* PrivateTextures;
};

struct FieldTerrainTexPatAnimationEntry
{
    u32 GFBTPOffset;
    u32 NSBTXOffset;
};

struct FieldTerrainTexPatAnimationPack
{
    u32 DataCount;
    FieldTerrainTexPatAnimationEntry Offsets[2];
};

struct FieldTerrainTexPatAnimator
{
    FieldTerrainTexPatAnimation Animations[16];
    FieldTerrainTexPatAnimationPack* m_AnimationPack;
};

struct FieldTerrainAnimator
{
    b32 IsPlaying;
    fx32 FrameStep;
    FieldTerrainSRTAnimator m_SRTAnimator;
    FieldTerrainTexPatAnimator m_TexPatAnimator;
};

#endif //__FIELD_TERRAIN_ANIMATOR_H
// Tchaikovsky code generator
