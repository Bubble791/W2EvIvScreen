#ifndef __EVENT_FIELD_EFFECT_H
#define __EVENT_FIELD_EFFECT_H

#include "swantypes.h"

STRUCT_DECLARE(EventFieldEffectSubNormal)
STRUCT_DECLARE(EventFieldEffectSubPokeSprite)
STRUCT_DECLARE(EventFieldEffectSubCutin)
UNION_DECLARE(EventFieldEffectSub)

ENUM_DECLARE(FieldClashEffectCutInType)

enum FieldClashEffectCutInType
#ifdef __cplusplus
: u32
#endif
{
    FIELD_CLASH_CUTIN_NONE = 0x0,
    FIELD_CLASH_CUTIN_FACE = 0x1,
    FIELD_CLASH_CUTIN_FIGURE = 0x2,
};

#include "nds/gx.h"

struct EventFieldEffectSubNormal
{
    u32 ActorIDToHide;
};

struct EventFieldEffectSubPokeSprite
{
    u32 Species;
    u32 Forme;
    u32 Sex;
    b32 IsShiny;
    b32 IsEgg;
    b32 HasInitialDelay;
    u16 InitialDelayCountdown;
    u16 PlaybackCountdown;
    u32 VoiceHandle;
};

struct EventFieldEffectSubCutin
{
    u32 OpponentNameMsgID;
    GXColor NameTexPltColor1;
    GXColor NameTexPltColor2;
    u8 PlayerDisplayType;
    u8 _padding1;
    u16 _padding2;
};

union EventFieldEffectSub
{
    EventFieldEffectSubNormal Normal;
    EventFieldEffectSubCutin Cutin;
    EventFieldEffectSubPokeSprite PokeSprite;
};

#endif //__EVENT_FIELD_EFFECT_H
// Tchaikovsky code generator
