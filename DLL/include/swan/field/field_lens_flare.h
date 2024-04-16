#ifndef __FIELD_LENS_FLARE_H
#define __FIELD_LENS_FLARE_H

#include "swantypes.h"

STRUCT_DECLARE(FieldLensFlare)
STRUCT_DECLARE(FieldLensFlareData)
STRUCT_DECLARE(FieldLensFlareDataEntry)

ENUM_DECLARE(FieldLensFlareState)

enum FieldLensFlareState
#ifdef __cplusplus
: u32
#endif
{
    FIELD_LENSFLARE_PREPARE = 0x0,
    FIELD_LENSFLARE_WAIT_START = 0x1,
    FIELD_LENSFLARE_START = 0x2,
    FIELD_LENSFLARE_WAIT_END = 0x3,
    FIELD_LENSFLARE_END = 0x4,
};

#include "field/field_exp_obj.h"
#include "system/gamesystem.h"
#include "system/game_data.h"

struct FieldLensFlare
{
    FieldExpObj* m_ExpObjSys;
    b32 IsEnabled;
    b32 CanStart;
    b32 IsReady;
    FieldLensFlareState State;
    FieldLensFlareData* m_Data;
    GameSystem* m_GameSystem;
    u16 m_LensFlareID;
    u16 _padLensFlareID;
    GameData* m_GameData;
};

struct FieldLensFlareData
{
    u32 RawDataLength;
    FieldLensFlareDataEntry* RawData;
};

struct FieldLensFlareDataEntry
{
    u16 OutZoneID;
    u16 InZoneID;
    u16 EffectSetIDs[4][3];
};

#endif //__FIELD_LENS_FLARE_H
// Tchaikovsky code generator
