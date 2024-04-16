#ifndef __FIELD_SOUND_SYSTEM_H
#define __FIELD_SOUND_SYSTEM_H

#include "swantypes.h"

STRUCT_DECLARE(FieldSoundSystemRequest)
STRUCT_DECLARE(FieldSoundSystem)

ENUM_DECLARE(FieldSoundSystemState)
ENUM_DECLARE(FieldSoundCommand)

enum FieldSoundSystemState
#ifdef __cplusplus
: u32
#endif
{
    FIELD_SND_STATE_INIT = 0x0,
    FIELD_SND_STATE_PLAYING = 0x1,
    FIELD_SND_STATE_IDLE = 0x2,
    FIELD_SND_STATE_FADING_OUT = 0x3,
    FIELD_SND_STATE_FADING_IN = 0x4,
    FIELD_SND_STATE_PUSHING = 0x5,
    FIELD_SND_STATE_POPPING = 0x6,
    FIELD_SND_STATE_POPPED = 0x7,
    FIELD_SND_STATE_CHANGING_OUT = 0x8,
    FIELD_SND_STATE_CHANGING_IN = 0x9,
    FIELD_SND_STATE_CHANGED = 0xA,
    FIELD_SND_STATE_PUSHING_POSTPONED = 0xB,
    FIELD_SND_STATE_PUSHED_POSTPONED = 0xC,
    FIELD_SND_STATE_PREPARING = 0xD,
    FIELD_SND_STATE_PREPARED = 0xE,
};

enum FieldSoundCommand
#ifdef __cplusplus
: u32
#endif
{
    FIELD_SND_CMD_NULL = 0x0,
    FIELD_SND_FADE_IN = 0x1,
    FIELD_SND_FADE_OUT = 0x2,
    FIELD_SND_BGM_PUSH = 0x3,
    FIELD_SND_BGM_POP = 0x4,
    FIELD_SND_BGM_CHANGE = 0x5,
    FIELD_SND_BGM_PREPARE = 0x6,
    FIELD_SND_BGM_PLAY = 0x7,
};

#include "system/game_data.h"
#include "gfl/snd/gfl_player_volume_fader.h"

struct FieldSoundSystemRequest
{
    FieldSoundCommand Command;
    u32 SoundID;
    u16 FadeOutTime;
    u16 FadeInTime;
};

struct FieldSoundSystem
{
    GameData* m_GameData;
    FieldSoundSystemState State;
    u32 NowBGM;
    u32 CommandBGMID;
    u32 ChangeTargetBGM;
    u32 field_14;
    u16 CommandFadeInTime;
    u16 CommandFadeOutTime;
    FieldSoundCommand NowCommandID;
    u32 BGMStackIndex;
    u32 LastBGMStack[1];
    FieldSoundSystemRequest CommandBuffer[10];
    u8 CommandReadIndex;
    u8 CommandWriteIndex;
    u16 _padCommandWriteIndex;
    PlayerVolumeFader* m_PlayerVolumeFader;
    void* m_RingtoneSys;
    u16 AmbienceIDs[2];
    u16 AmbienceVolumes[2];
    u32 AvailableBGMSlotBits;
};

#endif //__FIELD_SOUND_SYSTEM_H
// Tchaikovsky code generator
