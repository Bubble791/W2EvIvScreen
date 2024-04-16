#ifndef __GAMESYSTEM_H
#define __GAMESYSTEM_H

#include "swantypes.h"

STRUCT_DECLARE(GameSystemProcData)
STRUCT_DECLARE(GameSystem)

ENUM_DECLARE(GameEntryPoint)

typedef struct GameEvent GameEvent; //forward declared for GameEventProvider
typedef GameEvent* (*GameEventProvider)(GameSystem*, void*);

enum GameEntryPoint
#ifdef __cplusplus
: u32
#endif
{
    GAME_ENTRYPOINT_OPENING = 0x0,
    GAME_ENTRYPOINT_FIELD_CONTINUE = 0x1,
    GAME_ENTRYPOINT_DEBUG = 0x2,
};
SWAN_CPPTYPE(gsys, GameEntryPoint)

SWAN_CPPTYPE_EX(gsys, ProcData, GameSystemProcData)
SWAN_CPPTYPE(gsys, GameSystem)
SWAN_CPPTYPE_EX(gsys, EventProvider, GameEventProvider)

#include "system/game_event.h"
#include "gfl/core/gfl_procsys.h"
#include "math/vector.h"
#include "system/game_data.h"
#include "field/fieldmap.h"
#include "field/iss.h"

C_DECL_BEGIN

extern void                    GSYS_Create(GameSystem* gsys, int heapId, void* gsysProcData);
extern b32                     GSYS_Update(GameSystem* gsys);
extern void                    GSYS_SetEventProvider(GameSystem* result, GameEventProvider provider, void* providerData);
extern b32                     GSYS_FeedEventsFromProvider(GameSystem* gsys, GameEventProvider eventProvider, void* eventProviderData);
extern b32                     GSYS_UpdateEventRunningFlag(GameSystem* gsys);
extern b32                     GSYS_GetEventRunningFlag(GameSystem* gsys);
extern GameProcManagerStatus   GSYS_GetProcMgrState(GameSystem* gsys);
extern void                    GSYS_QueueProc(GameSystem* sysBlk, int ovlId, GameProcFunctions* publics, void* procData);
extern void                    GSYS_QueueProcAsEvent(GameEvent* parentEvent, int ovlId, GameProcFunctions* functions, void* procData);
extern void                    GSYS_StartFieldmapProc(GameSystem* gsys);
extern GameEvent*              GSYS_GetNowEvent(GameSystem* gsys);
extern void                    GSYS_SetNowEvent(GameSystem* gsys, GameEvent* event);
extern b32                     GSYS_CheckNowEvent(GameSystem* gsys);
extern b32                     GSYS_UpdateEvents(GameSystem* gsys);
extern GameData*               GSYS_GetGameData(GameSystem* gsys);
extern Field*                  GSYS_GetField(GameSystem* gsys);
extern void                    GSYS_SetField(GameSystem* gsys, Field* field);
extern b32                     GSYS_CheckField(GameSystem* gsys);
extern void*                   GSYS_GetPlayerInfo(GameSystem* gsys);
extern void*                   GSYS_GetLinkFestival(GameSystem* gsys);
extern void*                   GSYS_GetGameCommSystem(GameSystem* gsys);
extern void                    GSYS_Terminate(GameSystem* gsys);
extern void                    GSYS_Free(GameSystem* gsys);
extern void*                   GameData_GetParty(void* game);
C_DECL_END

struct GameSystemProcData
{
    GameEntryPoint EntryPointType;
    VecFx32 SpawnPlayerPos;
    u16 field_10;
    u16 field_12;
};

struct GameSystem
{
    HeapID m_HeapID;
    s16 _padHeapID;
    GameSystemProcData* ProcData;
    GameProcManager* GameSysProcManager;
    GameProcManagerStatus ProcManagerState;
    void* EventProvider;
    void* EventProviderData;
    GameEvent* CurrentEvent;
    GameData* m_GameData;
    Field* m_Field;
    void* m_GameComm;
    int field_28;
    ISS* m_ISS;
    void* m_LinkFestival;
    char field_34;
    u8 LastUpdateGameEventRunning;
    u8 field_36;
    char field_37;
  
    #ifdef __cplusplus
  
    INLINE b32 Update() {
        return GSYS_Update(this);
    }

    INLINE void SetEventProvider(GameEventProvider provider, void* providerData) {
        GSYS_SetEventProvider(this, provider, providerData);
    }

    INLINE b32 FeedEventsFromProvider(GameEventProvider eventProvider, void* eventProviderData) {
        return GSYS_FeedEventsFromProvider(this, eventProvider, eventProviderData);
    }

    INLINE b32 UpdateEventRunningFlag() {
        return GSYS_UpdateEventRunningFlag(this);
    }

    INLINE b32 GetEventRunningFlag() {
        return GSYS_GetEventRunningFlag(this);
    }

    INLINE gfl::core::ProcManagerStatus GetProcMgrState() {
        return GSYS_GetProcMgrState(this);
    }

    INLINE void QueueProc(int ovlId, gfl::core::ProcVTable* publics, void* procData) {
        GSYS_QueueProc(this, ovlId, publics, procData);
    }

    INLINE static void QueueProcAsEvent(gsys::Event* parentEvent, int ovlId, gfl::core::ProcVTable* functions, void* procData) {
        GSYS_QueueProcAsEvent(parentEvent, ovlId, functions, procData);
    }

    INLINE void StartFieldmapProc() {
        GSYS_StartFieldmapProc(this);
    }

    INLINE gsys::Event* GetNowEvent() {
        return GSYS_GetNowEvent(this);
    }

    INLINE void SetNowEvent(gsys::Event* event) {
        GSYS_SetNowEvent(this, event);
    }

    INLINE b32 CheckNowEvent() {
        return GSYS_CheckNowEvent(this);
    }

    INLINE b32 UpdateEvents() {
        return GSYS_UpdateEvents(this);
    }

    INLINE gsys::GameData* GetGameData() {
        return GSYS_GetGameData(this);
    }

    INLINE field::Field* GetField() {
        return GSYS_GetField(this);
    }

    INLINE void SetField(field::Field* field) {
        GSYS_SetField(this, field);
    }

    INLINE b32 CheckField() {
        return GSYS_CheckField(this);
    }

    INLINE void Terminate() {
        GSYS_Terminate(this);
    }

    INLINE void* GetPlayerInfo() {
        return GSYS_GetPlayerInfo(this);
    }

    INLINE void* GetLinkFestival() {
        return GSYS_GetLinkFestival(this);
    }

    INLINE void* GetGameCommSystem() {
        return GSYS_GetGameCommSystem(this);
    }

    #endif
};

extern GameSystem* g_GameSystem;

#endif //__GAMESYSTEM_H
// Tchaikovsky code generator
