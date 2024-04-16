#ifndef __ISS_SWITCH_SYS_H
#define __ISS_SWITCH_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(ISSSwitchMuteStateChangeRequest)
STRUCT_DECLARE(ISSSwitchMasterVolumeChangeRequest)
STRUCT_DECLARE(ISSSwitchSys)
STRUCT_DECLARE(ISSSwitchSet)
STRUCT_DECLARE(ISSSwitch)

ENUM_DECLARE(ISSSwitchSetVolumeFadeState)
ENUM_DECLARE(ISSSwitchState)

enum ISSSwitchSetVolumeFadeState
#ifdef __cplusplus
: u32
#endif
{
    ISS_SWITCH_SET_VOLUME_KEEP = 0x0,
    ISS_SWITCH_SET_VOLUME_LOWER = 0x1,
    ISS_SWITCH_SET_VOLUME_RAISE = 0x2,
};

enum ISSSwitchState
#ifdef __cplusplus
: u32
#endif
{
    ISS_SWITCH_ON = 0x0,
    ISS_SWITCH_MUTED = 0x1,
    ISS_SWITCH_FADE_IN = 0x2,
    ISS_SWITCH_FADE_OUT = 0x3,
};

struct ISSSwitchMuteStateChangeRequest
{
    b32 Enabled;
    b32 IsUnmute;
    u32 BGMId;
    u32 SwitchIndex;
};

struct ISSSwitchMasterVolumeChangeRequest
{
    b32 Enabled;
    u32 BGMId;
    u32 TargetVolume;
    u16 Interval;
    u16 _padInterval;
};

struct ISSSwitchSys
{
    b32 IsEnabled;
    u8 SetCount;
    u8 _padSetCount1;
    u16 _padSetCount2;
    ISSSwitchSet** SwitchSets;
    ISSSwitchSet* NowSwitchSet;
    ISSSwitchMuteStateChangeRequest m_SwitchMuteStateChangeRequests[4];
    ISSSwitchMasterVolumeChangeRequest m_VolumeChangeReq;
};

struct ISSSwitchSet
{
    ISSSwitchSetVolumeFadeState FadeStatus;
    u32 BGMId;
    u16 ZoneIDs[9];
    u8 ZoneIDCount;
    u8 _padZoneIDCount;
    ISSSwitch* Switches[9];
    u32 MasterVolume;
    s32 FadeVolumeAddend;
    u32 BaseVolume;
    u16 NowFrame;
    u16 EndFrame;
};

struct ISSSwitch
{
    ISSSwitchState State;
    u16 NowFrame;
    u16 EndFrame;
    u16 TrackMask;
    u16 _padTrackMask;
};

#endif //__ISS_SWITCH_SYS_H
// Tchaikovsky code generator
