#ifndef __ISS_CITY_SYS_H
#define __ISS_CITY_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(ISSCitySys)
STRUCT_DECLARE(ISSCityUnit)

ENUM_DECLARE(ISSCitySysState)

enum ISSCitySysState
#ifdef __cplusplus
: u32
#endif
{
    ISS_CITY_SYS_KEEP = 0x0,
    ISS_CITY_SYS_FADEIN = 0x1,
    ISS_CITY_SYS_FADEOUT = 0x2,
};

#include "field/field_player.h"

struct ISSCitySys
{
    PlayerState* m_PlayerState;
    b32 Enabled;
    u32 State;
    u32 EmitterVolume;
    u32 MasterVolume;
    ISSCityUnit** m_Units;
    u8 UnitCount;
    u8 NowUnitIndex;
    u16 _padding;
};

struct ISSCityUnit
{
    u16 ZoneID;
    u16 _padZoneID;
    u32 OriginGX;
    s32 OriginGY;
    u32 OriginGZ;
    u8 VolumeCurve[6];
    u8 CurveKeysX[6];
    u8 CurveKeysY[6];
    u8 CurveKeysZ[6];
};

#endif //__ISS_CITY_SYS_H
// Tchaikovsky code generator
