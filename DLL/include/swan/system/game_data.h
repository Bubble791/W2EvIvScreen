#ifndef __GAME_DATA_H
#define __GAME_DATA_H

#include "swantypes.h"

STRUCT_DECLARE(GameData)

SWAN_CPPTYPE(gsys, GameData)

#include "pml/poke_party.h"
#include "field/field_player.h"
#include "field/field_eventdata_system.h"
#include "field/field_spawn.h"
#include "save/savedata_bag.h"
#include "field/field_status.h"
#include "battle/btl_result.h"
#include "field/field_mmodel_pair.h"
#include "field/field_mmodel.h"
#include "field/field_map_matrix.h"
#include "field/field_encount.h"
#include "field/field_bgm_info.h"
#include "save/savedata_eventwork.h"
#include "field/field_gimmick.h"
#include "save/savedata_unity_tower_state.h"
#include "save/savedata_box_accessor.h"
#include "field/field_sound_system.h"
#include "save/save_control.h"
#include "save/savedata_player.h"

struct GameData
{
    SaveControl* m_SaveControl;
    u8 field_4[272];
    PlayerState m_PlayerState;
    EventDataSystem* m_EventData;
    PlayerSaveData* m_PlayerSaveData;
    ZoneSpawnInfo* NowZoneSpawnInfo;
    ZoneSpawnInfo* WarpRememberZoneInfo;
    ZoneSpawnInfo* NextSpawnZone;
    ZoneSpawnInfo* EscapeRopeZone;
    ZoneSpawnInfo EntralinkParentSpawnInfo;
    void* m_MyItemSave;
    BagSaveData* m_Bag;
    PokeParty* m_Party;
    void* dword198;
    BoxSaveAccessor* m_BoxSaveAccessor;
    void* dword1A0;
    BGMInfo* m_BGMInfo;
    FieldActorSystem* m_ActorSystem;
    EventWorkSave* m_EventWork;
    MapMtxSys* m_MapMatrix;
    FieldSoundSystem* m_FieldSoundSystem;
    FieldStatus* m_FieldStatus;
    BattleResult LastBattleResult;
    u8 PauseEvents;
    char field_1C1;
    u8 field_1C2;
    char field_1C3;
    u32 TotalStepsTaken;
    u8 NaturalSeason;
    u8 NowWeather;
    u8 LastFieldSubscreen;
    u8 byte1CB;
    u8 byte1CC;
    char byte1CD;
    u8 SkipFrameCounter;
    u8 Is30FPSMode;
    u16 field_1D0;
    u8 ForceSeasonSync;
    char field_1D3;
    char field_1D4[76];
    EncountState* m_EncountState;
    char char224;
    char gap225[3];
    GimmickState m_GimmickState;
    void* dword2BC;
    void* dword2C0;
    void* dword2C4;
    void* dword2C8;
    void* Calendar;
    UnityTowerState m_UnityTowerState;
    void* dword2E0;
    void* dword2E4;
    void* dword2E8;
    void* dword2EC;
    void* dword2F0;
    FieldActorPairState* m_FieldFollow;
    int ScriptPluginNo;
    char gap2FC[12];
    int LensFlareEntryIdx;
    u8 LensFlareRequested;
    char byte30D;
    char gap30E[6];
    void* dword314;
};

#endif //__GAME_DATA_H
// Tchaikovsky code generator
