#ifndef __FIELDMAP_H
#define __FIELDMAP_H

#include "swantypes.h"

STRUCT_DECLARE(Field)
STRUCT_DECLARE(FieldMapConfig)
STRUCT_DECLARE(FieldmapCtrlVTable)

ENUM_DECLARE(FieldRenderMode)
ENUM_DECLARE(FieldmapStatus)

enum FieldRenderMode
#ifdef __cplusplus
: u32
#endif
{
    FLD_RENDERMODE_FIELDMAP = 0x0,
    FLD_RENDERMODE_FIELD_EFFECT = 0x1,
    FLD_RENDERMODE_ENCOUNT_EFFECT = 0x2,
};
SWAN_CPPTYPE_EX(field, RenderMode, FieldRenderMode)

enum FieldmapStatus
#ifdef __cplusplus
: u32
#endif
{
    FIELDMAP_STATUS_OPEN = 0x0,
    FIELDMAP_STATUS_LOAD = 0x1,
    FIELDMAP_STATUS_SPAWN = 0x2,
    FIELDMAP_STATUS_RUN = 0x3,
    FIELDMAP_STATUS_UNLOAD = 0x4,
    FIELDMAP_STATUS_CLOSE = 0x5,
};

SWAN_CPPTYPE(field, Field)

#include "math/fixed.h"
#include "math/vector.h"
#include "gfl/core/gfl_heap.h"
#include "gfl/g3d/gfl_g3d_camera.h"
#include "gfl/g3d/gfl_g3d_light.h"
#include "gfl/core/gfl_tcb.h"
#include "system/gamesystem.h"
#include "field/field_areadata.h"
#include "field/field_camera.h"
#include "field/field_light.h"
#include "field/field_fog.h"
#include "field/field_scenearea.h"
#include "field/field_scenearea_loader.h"
#include "field/field_task.h"
#include "field/field_gimmick.h"
#include "field/field_g3dobj.h"
#include "field/field_terrain_animator.h"
#include "field/field_g3d_mapper.h"
#include "field/field_encount.h"
#include "field/field_skill_map_eff.h"
#include "field/field_async_proc.h"
#include "field/field_spawn.h"
#include "field/field_subscreen.h"
#include "field/field_exp_obj.h"
#include "field/field_nogrid_mapper.h"
#include "field/field_effect.h"
#include "field/field_palace_sys.h"
#include "field/field_color_postfx.h"
#include "gfl/g3d/gfl_blact.h"
#include "field/field_3dci.h"
#include "field/field_daycare.h"
#include "field/field_encount_effect.h"
#include "field/field_disp_control.h"
#include "field/field_lens_flare.h"

struct Field
{
    HeapID m_HeapID;
    u16 _padHeapID;
    GameSystem* m_GameSystem;
    GameData* m_GameData;
    AreaData* m_AreaData;
    FieldCamera* m_FieldCamera;
    FieldLightSystem* m_LightSystem;
    FieldFog* m_Fog;
    FieldFogCtrl* m_FogCtrl;
    void* m_WeatherSystem;
    FieldSubscreen* m_Subscreen;
    void* m_MsgBGSys;
    int dword2C;
    void* m_PlaceName;
    int dword34;
    void* m_FesGimmick;
    FieldExpObj* m_FieldExpObj;
    FieldActorSystem* m_ActorSystem;
    FieldNoGridMapper* m_NoGridMapper;
    FieldSceneArea* m_SceneArea;
    FieldSceneAreaLoader* m_SceneAreaLoader;
    FieldG3DMapper* m_G3DMapper;
    int gap54;
    FieldG3DMapperConfig m_G3DMapperConfig;
    FieldPlayer* m_Player;
    EncountSystem* m_EncountSys;
    FieldEffects* m_FieldEffects;
    void* gapA0;
    FieldPalaceSys* m_PalaceSys;
    FieldColorPostFX m_ColorPostFX;
    FieldSkillMapEff* m_SkillMapEff;
    G3DCamera* m_G3DCamera;
    G3DLight* m_Lights;
    TCB* AsyncActorMatLoadTCB;
    BlActSystem* m_ActorBlAct;
    BlActSystem* EffectBlact;
    BlActSystem* WildEffBlAct;
    FieldAsyncProcManager* m_AsyncProcMgr;
    b32 IsMapLoadFinished;
    FieldmapStatus m_Status;
    u8 SubroutinePhase;
    u8 SubRoutineChoiceAlternator;
    u16 _padSubroutine;
    u32 FramesSinceStart;
    u16 ZoneID;
    u16 _padZoneID;
    ZoneSpawnInfo PlayerZoneState;
    VecFx32* PlayerPositionPtr;
    VecFx32 PlayerPosition;
    fx32 gap110;
    u32 ZoneEnvHighResult;
    FieldmapCtrlVTable* ControllerVTable;
    void* m_Controller;
    TCBManager* m_TCBMgr;
    void* TCBMgrHeap;
    FieldGimmickWorkBlock GimmickWork;
    void* m_ParticleSystem;
    Fld3DCi* m_Fld3DCi;
    DayCare* m_DayCare;
    FieldRenderMode RenderMode;
    FieldG3DObjSystem* m_G3DObjSys;
    FieldTaskManager* m_TaskMgr;
    b32 FadeFlag;
    EncEff* m_EncEff;
    b32 IsEffectRunning;
    b32 IsSeasonBannerOverdraw;
    void* NDemoData;
    FieldDispControl* m_FieldDispControl;
    void* m_CasteliaRush;
    FieldLensFlare* m_LensFlare;
};

struct FieldMapConfig
{
    FieldG3DMapperConfig m_G3DMapperConfig;
    FieldmapCtrlVTable* FieldmapCtrlVtable;
    b32 UseMapMatrix;
    u32 HeapSize;
};

struct FieldmapCtrlVTable
{
    u32 TypeID;
    void (*CreateFunc)(Field* field, VecFx32* pos, Direction dir);
    void (*UpdateFunc)(Field* field, VecFx32* outPos);
    void (*FreeFunc)(Field* field);
    void (*GetPosFunc)(Field* field);
};

#endif //__FIELDMAP_H
// Tchaikovsky code generator
