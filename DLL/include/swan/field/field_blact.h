#ifndef __FIELD_BLACT_H
#define __FIELD_BLACT_H

#include "swantypes.h"

STRUCT_DECLARE(FldBlActObjMatCacheEntry)
STRUCT_DECLARE(FldBlActObjMatCache)
STRUCT_DECLARE(FieldBlAct)
STRUCT_DECLARE(FldBlActLoader)
STRUCT_DECLARE(FldBlActActorLoadReq)
STRUCT_DECLARE(FldBlActMatLoadReq)
STRUCT_DECLARE(FldBlActMatLoadResult)
STRUCT_DECLARE(FldBlActLiveActor)

typedef void (*FldBlActLoadCallback)(u16 blActIndex, void* data);

#include "field/field_mmodel.h"
#include "gfl/g3d/gfl_blact.h"
#include "math/vector.h"
#include "gfl/g3d/gfl_g3d_system.h"

struct FldBlActObjMatCacheEntry
{
    u16 ObjCode;
    u16 MatIdx;
    u16 Flags;
    u16 _Padding;
};

struct FldBlActObjMatCache
{
    u32 EntryCount;
    FldBlActObjMatCacheEntry* Entries;
};

struct FieldBlAct
{
    u8 field_0;
    u8 field_1;
    u16 MaxSpriteCount;
    BlActSystem* m_BlActSys;
    int field_8;
    int field_C;
    FieldActorSystem* m_ActSys;
    FldBlActObjMatCache m_ObjMatCache;
    FldBlActLoader* m_Loader;
    FldBlActLiveActor* AsyncDeleteActors;
};

struct FldBlActLoader
{
    b32 IsMatLoadingEnabled;
    u16 SpriteLimit;
    u16 ConcurrentAsyncLoadCount;
    u16 FieldActorLimit;
    u16 _padFieldActorLimit;
    FldBlActMatLoadReq* MatLoadRequests;
    FldBlActMatLoadResult* MatLoadResults;
    FldBlActActorLoadReq* ActorSetupRequests;
};

struct FldBlActActorLoadReq
{
    u16* ResultBlActIdxPtr;
    FieldActor* Actor;
    u16 ActorUID;
    u8 BillboardSize;
    u8 SpriteAtlasSize;
    u8 SpriteControllerType;
    u8 InitDone;
    u16 _padInitDone;
    G3DResource* Resource;
    FldBlActLoadCallback LoadCallback;
    void* LoadCallbackData;
    VecFx32 Pos;
};

struct FldBlActMatLoadReq
{
    u16 ActorUID;
    u16 ResID;
    u8 BillboardSize;
    u8 SpriteAtlasSize;
    u16 _padSpriteAtlasSize;
    u32 Flags;
};

struct FldBlActMatLoadResult
{
    u8 ReadingDone;
    u8 _padReadingDone1;
    u16 _padReadingDone2;
    u32 Flags;
    u16 ActorUID;
    u8 BillboardSize;
    u8 SpriteAtlasSize;
    u32 field_C;
    G3DResource* Resource;
};

struct FldBlActLiveActor
{
    FieldActor* m_FieldActor;
    u16 BlActIdx;
    u16 BaseObjCode;
    u16 ObjCode;
    u16 _padObjCode;
};

#endif //__FIELD_BLACT_H
// Tchaikovsky code generator
