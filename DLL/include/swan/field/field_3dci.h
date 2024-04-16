#ifndef __FIELD_3DCI_H
#define __FIELD_3DCI_H

#include "swantypes.h"

STRUCT_DECLARE(Fld3DCi)
STRUCT_DECLARE(Fld3DCiFadeState)
STRUCT_DECLARE(Fld3DCiG2DMaterial)

#include "gfl/g3d/gfl_g3d_camera.h"
#include "gfl/g3d/gfl_g3d_scenemgr.h"
#include "gfl/core/gfl_heap.h"
#include "gfl/g3d/gfl_transform.h"
#include "system/game_event.h"
#include "gfl/g2d/gfl_fade.h"
#include "ns/g2d/res/G2DResData.h"
#include "ns/g2d/res/ResCharacter.h"
#include "ns/g2d/res/ResPalette.h"
#include "nds/gx.h"
#include "gfl/core/gfl_tcb.h"
#include "field/event/event_field_effect.h"
#include "math/fixed.h"
#include "gfl/g2d/gfl_bitmap.h"

struct Fld3DCi
{
    void* m_ParticleSystem;
    G3DCamera* m_CameraPersp;
    G3DCamera* m_CameraOrtho;
    G3DCameraProjectionMode CameraType;
    HeapID m_HeapID;
    u16 _padHeapID;
    G3DManager* m_G3DScene;
    u32 SceneNodeIdx;
    SRTMatrix Transform;
    u32 field_58;
    u16 ParticleAnimStartFrame;
    u16 ParticleAnim2StartFrame;
    u16 Actor1AnmStartFrame;
    u16 Actor2AnmStartFrame;
    u16 IsParticleReqEnd;
    u16 FldEffID;
    G2DScreenBGBit BackupScreenDisp;
    u8 BackupBGPriorities[4];
    b32 IsScreenCaptureDone;
    b32 IsParticleBegun;
    b32 field_78;
    b32 Actor1HasAnim;
    b32 Actor2HasAnim;
    NNSG2DResCharHeader* G2DCharHeader;
    NNSG2DResPaletteHeader* G2DPaletteHeader;
    GFLBitmap* G2DBitmap;
    NNSG2DResData* G2DNCGR;
    NNSG2DResData* G2DNCLR;
    EventFieldEffectSub SubData;
    int field_B8[24];
    Fld3DCiG2DMaterial* G2DMaterials;
    u8 G2DMaterialDatID;
    u8 G2DMaterialCount;
    u8 MaterialIndex;
    u8 _padMaterialIndex;
    b32 PtclIsFinished;
    b32 Actor1IsFinished;
    b32 Actor2IsFinished;
    void* SubEventCallback;
    b32 (*UpdateCallback)(GameEvent*, Fld3DCi*);
    u32 UpdateCallbackState;
    u16 FrameCounter;
    u16 NextSoundKeyFrameIdx;
    u16 NextFadeKeyFrameIdx;
    u16 _padNextFadeKeyFrameIdx;
    b32 LCDConfigTCBResult;
    Fld3DCiFadeState* m_FadeState;
};

struct Fld3DCiFadeState
{
    FadeMode Mode;
    fx32 Value;
    s32 TargetValue;
    u32 MaxFrame;
    u32 NowFrame;
    s32 IncPerFrame;
    TCB* m_TCB;
};

struct Fld3DCiG2DMaterial
{
    char TextureName[20];
    char PaletteName[20];
    u8 G3DSceneRscIdx;
    u8 CharDatID;
    u8 PltDatID;
    u8 PltInOffset;
    u8 TileWidth;
    u8 TileHeight;
    u8 SrcTileWidth;
    u8 SrcTileOffsX;
};

#endif //__FIELD_3DCI_H
// Tchaikovsky code generator
