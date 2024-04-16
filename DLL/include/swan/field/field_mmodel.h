#ifndef __FIELD_MMODEL_H
#define __FIELD_MMODEL_H

#include "swantypes.h"

STRUCT_DECLARE(FieldActorResGroup)
STRUCT_DECLARE(FieldActorConfig)
STRUCT_DECLARE(FieldActorConfigTable)
STRUCT_DECLARE(FieldActorConfigCache)
STRUCT_DECLARE(ActorPositionRail)
STRUCT_DECLARE(FieldActorSystem)
STRUCT_DECLARE(FieldActor)
STRUCT_DECLARE(FieldActorVTable)

ENUM_DECLARE(Direction)

enum Direction
#ifdef __cplusplus
: u32
#endif
{
    DIR_UP = 0x0,
    DIR_DOWN = 0x1,
    DIR_LEFT = 0x2,
    DIR_RIGHT = 0x3,
    DIR_ANY = 0x8,
    DIR_NONE = 0x9,
};

SWAN_CPPTYPE_EX(field::mmodel, ResInfo, FieldActorConfig)
SWAN_CPPTYPE_EX(field::mmodel, ResInfoTable, FieldActorConfigTable)
SWAN_CPPTYPE_EX(field::mmodel, ResInfoCache, FieldActorConfigCache)
SWAN_CPPTYPE_EX(field::mmodel, PositionRail, ActorPositionRail)
SWAN_CPPTYPE_EX(field::mmodel, Manager, FieldActorSystem)
SWAN_CPPTYPE_EX(field::mmodel, Actor, FieldActor)

#include "field/field_rail_system.h"
#include "gfl/core/gfl_heap.h"
#include "field/fieldmap.h"
#include "field/field_map_terrain.h"
#include "gfl/core/gfl_tcb.h"
#include "field/field_rail_system.h"
#include "gfl/fs/gfl_archive.h"
#include "system/game_data.h"
#include "field/field_g3d_mapper.h"
#include "field/field_nogrid_mapper.h"
#include "field/field_color_postfx.h"
#include "field/field_position.h"
#include "field/field_blact.h"
#include "field/field_mmodel_g3dobj.h"

struct FieldActorResGroup
{
    u16 Res1;
    u16 Res2;
    u16 Animations[3];
};

struct FieldActorConfig
{
    u16 UID;
    u8 EntityType;
    u8 SceneNodeType;
    u8 EnableShadow;
    u8 FootprintType;
    u8 EnableReflections;
    u8 BillboardSize;
    u8 SpriteAtlasSize;
    u8 SpriteControllerType;
    u8 Gender;
    u8 CollWidth;
    u8 CollHeight;
    s8 WPosOffsetX;
    s8 WPosOffsetY;
    s8 WPosOffsetZ;
    FieldActorResGroup RscIndices;
    u16 Padding;
};

struct FieldActorConfigTable
{
    u32 EntryCount;
    FieldActorConfig Entries;
};

struct FieldActorConfigCache
{
    u16 EntryCount;
    u16 EntryUIDs[26];
    u16 _Padding;
    FieldActorConfig Cache[26];
};

struct ActorPositionRail
{
    RailUnit* m_RailUnit;
    RailPosition m_RailPosition;
    int field_C;
};

struct FieldActorSystem
{
    u32 field_0;
    u16 ActorCapacity;
    u16 ActorCount;
    HeapID m_HeapID;
    HeapID FieldHeapID;
    u16 field_C;
    u16 field_E;
    u32 field_10;
    ArcTool* DataArc;
    ArcTool* ActorConfigArc;
    FieldActor* ActorHeap;
    void* TCBMgrHeap;
    TCBManager* m_TCBMgr;
    FieldBlAct* m_FieldBlAct;
    FieldActorG3DSystem* m_ActorG3DSystem;
    void* m_MModelSave;
    GameData* m_GameData;
    FieldG3DMapper* m_G3DMapper;
    FieldNoGridMapper* m_NoGridMapper;
    Field* m_Field;
    void* field_44;
    FieldColorPostFX* m_ColorPostFX;
    FieldActorConfigCache* m_ActorConfigCache;
};

struct FieldActor
{
    u32 Flags;
    u32 MovementFlags;
    u16 ActorUID;
    u16 ZoneID;
    u16 ModelID;
    u16 MoveCode;
    u16 EvType;
    u16 SpawnFlag;
    u16 SCRID;
    u16 DefaultDir;
    u16 FaceDir;
    u16 MotionDir;
    u16 LastFaceDir;
    u16 LastMotionDir;
    u16 Param0;
    u16 Param1;
    u16 Param2;
    u16 NextAcmd;
    s16 field_28;
    u16 field_2A;
    s16 AreaW;
    s16 AreaH;
    GPosXYZ DefaultGPos;
    GPosXYZ InitGPos;
    GPosXYZ GPos;
    s16 field_42;
    VecFx32 WPos;
    VecFx32 WPosOffset;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    TileType CurrentTileUnder;
    TileType CurrentTileUnderOrigY;
    u8 CollisionWidth;
    u8 CollisionHeight;
    s8 ModelPosOffsetX;
    s8 ModelPosOffsetY;
    s8 ModelPosOffsetZ;
    u8 ShadowGroup;
    u16 _padShadowGroup;
    TCB* m_TCB;
    FieldActorSystem* m_ActorSystem;
    void* MoveCodeVTable;
    FieldActorVTable* SceneNodeVTable;
    ActorPositionRail DefaultRailPos;
    ActorPositionRail RailPos;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    char field_CC[24];
    FieldActorConfig m_Config;
};

struct FieldActorVTable
{
    void (*OnCreateFunc)(FieldActor*);
    void (*OnUpdateFunc)(FieldActor*);
    void (*OnDeleteFunc)(FieldActor*);
    void (*OnSuspendFunc)(FieldActor*);
    void (*OnWakeUpFunc)(FieldActor*);
    u16 (*GetBlActIdxFunc)(FieldActor*);
};

#endif //__FIELD_MMODEL_H
// Tchaikovsky code generator
