#ifndef __GFL_G3D_TPANM_H
#define __GFL_G3D_TPANM_H

#include "swantypes.h"

STRUCT_DECLARE(GFBTPController)
STRUCT_DECLARE(GFBTPValue)

struct GFBTPController
{
    u16* KeyFrames;
    u8* TextureIndices;
    u8* PaletteIndices;
    u8* Targets;
    u32 KeyFrameCount;
    u32 TargetCount;
    u32 FrameCount;
};

struct GFBTPValue
{
    u8 TextureIndex;
    u8 PaletteIndex;
};

#endif //__GFL_G3D_TPANM_H
// Tchaikovsky code generator
