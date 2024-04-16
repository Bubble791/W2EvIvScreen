#ifndef __SND_H
#define __SND_H

#include "swantypes.h"

STRUCT_DECLARE(SoundChannel)

ENUM_DECLARE(SoundEncoding)

enum SoundEncoding
#ifdef __cplusplus
: u32
#endif
{
    SNDENC_PCM8 = 0x0,
    SNDENC_PCM16 = 0x1,
    SNDENC_ADPCM = 0x2,
};

C_DECL_BEGIN

extern SoundChannel*   sndLockChannel(u32 channelNo);
extern void            sndReleaseChannel(SoundChannel* channel);
extern b32             sndPlaySamples(SoundChannel* channel, SoundEncoding codec, void* sampleData, b32 looping, s32 loopStart, s32 sampleCount, s32 sampleRate, u32 volume, s32 speed, u32 pan);
extern void            sndStopChannel(SoundChannel* channel);
extern void            sndSetChannelVolume(SoundChannel* chan, u8 volume);
extern void            sndSetChannelSpeed(SoundChannel* chan, s32 speed);
extern b32             sndIsChannelPlaying(SoundChannel* channel);

C_DECL_END

struct SoundChannel
{
    u32 ChannelNo;
    s32 SampleRate;
    b32 IsPlaying;
    u32 field_C;
    u32 PacketIndex;
};

#endif //__SND_H
// Tchaikovsky code generator
