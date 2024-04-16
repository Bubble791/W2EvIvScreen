#ifndef __GFL_PLAYER_VOLUME_FADER_H
#define __GFL_PLAYER_VOLUME_FADER_H

#include "swantypes.h"

STRUCT_DECLARE(PlayerVolumeFader)

struct PlayerVolumeFader
{
    u8 PlayerIndex;
    u8 SrcVolume;
    u8 DstVolume;
    u8 _padDstVolume;
    u16 EndFrame;
    u16 NowFrame;
    u8 Mute;
    u8 _padMute;
};

#endif //__GFL_PLAYER_VOLUME_FADER_H
// Tchaikovsky code generator
