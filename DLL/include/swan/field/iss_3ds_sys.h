#ifndef __ISS_3DS_SYS_H
#define __ISS_3DS_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(ISS3DSoundUnit)
STRUCT_DECLARE(ISS3DSoundSys)
STRUCT_DECLARE(ISS3DSoundConfig)

#include "gfl/core/gfl_heap.h"
#include "math/vector.h"
#include "math/fixed.h"

struct ISS3DSoundUnit
{
    b32 Enabled;
    VecFx32 Location;
    fx32 Radius;
    u32 BaseVolume;
    u16 TrackBitMask;
    u16 _padTrackBitMask;
};

struct ISS3DSoundSys
{
    HeapID m_HeapID;
    u16 _padHeapID;
    b32 IsEnabled;
    u8 TargetMasterVolume;
    u8 MasterVolume;
    u8 MasterVolumeChangeSpeed;
    u8 _padMasterVolume;
    VecFx32 ListenerPos;
    VecFx32 ListenerLookPos;
    ISS3DSoundUnit Units[16];
    u32 UnitVolumes[16];
    u32 UnitPans[16];
    ISS3DSoundConfig* Configs;
    u8 ConfigCount;
    u8 NowConfig;
    u16 field_26A;
    u32 field_26C;
};

struct ISS3DSoundConfig
{
    u32 BGMId;
    u16 EnabledUnitsMask;
    u16 _padding;
};

#endif //__ISS_3DS_SYS_H
// Tchaikovsky code generator
