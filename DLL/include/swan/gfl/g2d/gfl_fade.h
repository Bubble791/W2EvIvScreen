#ifndef __GFL_FADE_H
#define __GFL_FADE_H

#include "swantypes.h"

STRUCT_DECLARE(FadeManager)

ENUM_DECLARE(FadeMode)

enum FadeMode
#ifdef __cplusplus
: u32
#endif
{
    FADE_ENGINE_A_BLACK = 0x1,
    FADE_ENGINE_B_BLACK = 0x2,
    FADE_ENGINE_A_WHITE = 0x4,
    FADE_ENGINE_B_WHITE = 0x8,
};

SWAN_CPPTYPE_EX(gfl::g2d, Fade, FadeManager)

C_DECL_BEGIN

extern void    GFL_FadeCreate(HeapID heapId);
extern void    GFL_FadeUpdate();
extern u32     GFL_FadeGetUpdateFreq();
extern void    GFL_FadeSetUpdateFreq(u32 framesPerUpdate);
extern void    GFL_FadeSetUpdateFreqOne();
extern void    GFL_FadeSet(FadeMode mode, s32 brightnessStart, s32 brightnessEnd, s32 slowness);
extern b32     GFL_FadeIsRunning();
extern void    GFL_FadeFlush();

C_DECL_END

struct FadeManager
{
    FadeMode Mode;
    s32 BrightnessStart;
    s32 NowBrightness;
    s32 BrightnessEnd;
    u32 WaitFramesRemaining;
    u32 WaitFramesCount;
    s32 BrightnessAddPerUpdate;
    u32 UpdateFreq;
  
    #ifdef __cplusplus
  
    INLINE static void Create(HeapID heapId) {
        GFL_FadeCreate(heapId);
    }

    INLINE static void Update() {
        GFL_FadeUpdate();
    }

    INLINE static void Set(FadeMode mode, s32 brightnessStart, s32 brightnessEnd, s32 slowness) {
        GFL_FadeSet(mode, brightnessStart, brightnessEnd, slowness);
    }

    INLINE static b32 IsRunning() {
        return GFL_FadeIsRunning();
    }

    INLINE static void Flush() {
        GFL_FadeFlush();
    }

    INLINE static u32 GetUpdateFreq() {
        return GFL_FadeGetUpdateFreq();
    }

    INLINE static void SetUpdateFreq(u32 framesPerUpdate) {
        GFL_FadeSetUpdateFreq(framesPerUpdate);
    }

    INLINE static void SetUpdateFreqOne() {
        GFL_FadeSetUpdateFreqOne();
    }

    #endif
};

#endif //__GFL_FADE_H
// Tchaikovsky code generator
