#ifndef __FIELD_EXP_OBJ_H
#define __FIELD_EXP_OBJ_H

#include "swantypes.h"

STRUCT_DECLARE(FieldExpObjScene)
STRUCT_DECLARE(FieldExpObjActor)
STRUCT_DECLARE(FieldExpObjAnm)
STRUCT_DECLARE(FieldExpObjAnmSet)
STRUCT_DECLARE(FieldExpObj)

#include "gfl/g3d/gfl_g3d_system.h"
#include "gfl/g3d/gfl_g3d_scenemgr.h"
#include "gfl/g3d/gfl_transform.h"
#include "math/fixed.h"

struct FieldExpObjScene
{
    b32 Exists;
    FieldExpObjActor* Actors;
    FieldExpObjAnmSet* AnimSets;
    u16 G3DMgrSceneIdx;
    u16 ActorCount;
};

struct FieldExpObjActor
{
    b32 IsBBoxCullingEnabled;
    b32 Hidden;
    SRTMatrix Transform;
};

struct FieldExpObjAnm
{
    u8 Paused;
    u8 IsLooped;
    u8 IsActive;
    u8 _padIsPlaying;
    fx32 FrameStep;
    b32 IsPlaying;
    G3DAnim* Animation;
};

struct FieldExpObjAnmSet
{
    u32 Count;
    FieldExpObjAnm* Animations;
};

struct FieldExpObj
{
    u32 m_HeapID;
    G3DManager* m_G3DMgr;
    FieldExpObjScene Scenes[4];
};

#endif //__FIELD_EXP_OBJ_H
// Tchaikovsky code generator
