#ifndef __GFL_G3D_SCENEMGR_H
#define __GFL_G3D_SCENEMGR_H

#include "swantypes.h"

STRUCT_DECLARE(G3DScene)
STRUCT_DECLARE(G3DSceneResource)
STRUCT_DECLARE(G3DSceneActor)
STRUCT_DECLARE(G3DManager)

SWAN_CPPTYPE_EX(gfl::g3d, Scene, G3DScene)
SWAN_CPPTYPE_EX(gfl::g3d, SceneResource, G3DSceneResource)
SWAN_CPPTYPE_EX(gfl::g3d, SceneActor, G3DSceneActor)
SWAN_CPPTYPE_EX(gfl::g3d, SceneManager, G3DManager)

#include "gfl/g3d/gfl_g3d_system.h"

struct G3DScene
{
    u16 FirstResIndex;
    u16 ResCount;
    u16 FirstActorIndex;
    u16 ActorCount;
};

struct G3DSceneResource
{
    G3DResource* Resource;
};

struct G3DSceneActor
{
    G3DActor* Actor;
};

struct G3DManager
{
    G3DSceneResource* Resources;
    u8* IsResAlreadyUsed;
    u16 ResourceLimit;
    u16 _padResourceLimit;
    G3DSceneActor* Actors;
    u8* ActorResShareFlags;
    u16 ActorLimit;
    G3DScene Scenes[64];
    HeapID m_HeapID;
};

#endif //__GFL_G3D_SCENEMGR_H
// Tchaikovsky code generator
