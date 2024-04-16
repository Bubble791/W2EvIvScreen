#ifndef __ISS_ZONE_SYS_H
#define __ISS_ZONE_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(ISSZoneSys)
STRUCT_DECLARE(ISSZoneConfig)

struct ISSZoneSys
{
    b32 IsEnabled;
    u8 ZoneCount;
    u8 _padZoneCount1;
    u16 _padZoneCount2;
    ISSZoneConfig* Zones;
    u8 LastZoneDesc;
    u8 _padLastZoneDesc;
    u16 TrackMaskIn;
    u16 TrackMaskOut;
    u16 FadeTime;
    u16 Counter;
};

struct ISSZoneConfig
{
    u16 ZoneID;
    u16 TrackMaskIn;
    u16 TrackMaskOut;
    u16 FadeTime;
};

#endif //__ISS_ZONE_SYS_H
// Tchaikovsky code generator
