#ifndef __GFL_G3D_LIGHT_H
#define __GFL_G3D_LIGHT_H

#include "swantypes.h"

STRUCT_DECLARE(Light)
STRUCT_DECLARE(LightSetup)
STRUCT_DECLARE(LightSetupList)
STRUCT_DECLARE(G3DLight)

SWAN_CPPTYPE(gfl::g3d, Light)
SWAN_CPPTYPE(gfl::g3d, LightSetup)
SWAN_CPPTYPE(gfl::g3d, LightSetupList)
SWAN_CPPTYPE_EX(gfl::g3d, LightSet, G3DLight)

#include "nds/gx.h"
#include "math/fixed.h"
#include "gfl/core/gfl_heap.h"

C_DECL_BEGIN

extern G3DLight*   GFL_G3DLightCreate(LightSetupList* setup, s16 heapId);
extern void        GFL_G3DLightFree(G3DLight* lights);
extern void        GFL_G3DLightFlush(G3DLight* lights);
extern void        GFL_G3DLightGetDirVector(G3DLight* lights, u8 lightIndex, VecFx16* dest);
extern void        GFL_G3DLightSetDirVector(G3DLight* lights, u8 lightIndex, VecFx16* dirVector);
extern void        GFL_G3DLightGetColor(G3DLight* lights, u8 lightIndex, GXColor* dest);
extern void        GFL_G3DLightSetColor(G3DLight* lights, u8 lightIndex, GXColor* pColor);

C_DECL_END

struct Light
{
    VecFx16 Direction;
    GXColor Color;
};

struct LightSetup
{
    u8 Index;
    char _padIndex;
    Light m_Light;
};

struct LightSetupList
{
    LightSetup* Lights;
    u8 LightCount;
};

struct G3DLight
{
    Light Lights[4];
  
    #ifdef __cplusplus
  
    INLINE static gfl::g3d::LightSet* Create(gfl::g3d::LightSetupList* setup, s16 heapId) {
        return GFL_G3DLightCreate(setup, heapId);
    }

    INLINE void Free() {
        GFL_G3DLightFree(this);
    }

    INLINE void Flush() {
        GFL_G3DLightFlush(this);
    }

    INLINE void GetDirVector(u8 lightIndex, VecFx16* dest) {
        GFL_G3DLightGetDirVector(this, lightIndex, dest);
    }

    INLINE void SetDirVector(u8 lightIndex, VecFx16* dirVector) {
        GFL_G3DLightSetDirVector(this, lightIndex, dirVector);
    }

    INLINE void GetColor(u8 lightIndex, GXColor* dest) {
        GFL_G3DLightGetColor(this, lightIndex, dest);
    }

    INLINE void SetColor(u8 lightIndex, GXColor* pColor) {
        GFL_G3DLightSetColor(this, lightIndex, pColor);
    }

    #endif
};

#endif //__GFL_G3D_LIGHT_H
// Tchaikovsky code generator
