#ifndef __GAME_EVENT_H
#define __GAME_EVENT_H

#include "swantypes.h"

STRUCT_DECLARE(GameEvent)

ENUM_DECLARE(GameEventReturnCode)

typedef GameEventReturnCode (*GameEventCallback)(GameEvent*, u32*, void*);

enum GameEventReturnCode
#ifdef __cplusplus
: u32
#endif
{
    GAMEEVENT_CONTINUE = 0x0,
    GAMEEVENT_DONE = 0x1,
};
SWAN_CPPTYPE_EX(gsys, EventReturnCode, GameEventReturnCode)

SWAN_CPPTYPE_EX(gsys, Event, GameEvent)
SWAN_CPPTYPE_EX(gsys, EventCallback, GameEventCallback)

#include "system/gamesystem.h"

C_DECL_BEGIN

extern GameEvent*          GameEvent_Create(GameSystem* gsys, GameEvent* parentEvent, GameEventCallback callback, u32 evtDataSize);
extern GameEvent*          GameEvent_CreateOverlayDelegate(GameSystem* gsys, int ovlId, GameEventProvider eventConstructor, void* eventData);
extern void*               GameEvent_GetData(GameEvent* event);
extern u32*                GameEvent_GetStatePtr(GameEvent* event);
extern GameEvent*          GameEvent_GetReturnEvent(GameEvent* event);
extern GameSystem*         GameEvent_GetGameSystem(GameEvent* event);
extern GameEventReturnCode GameEvent_RunCallback(GameEvent* event);
extern void                GameEvent_Transplant(GameEvent* event, GameEventCallback callback, u32 size);
extern void                GameEvent_Replace(GameEvent* nowEvent, GameEvent* event);
extern void                GameEvent_ChainNext(GameEvent* currentEvent, GameEvent* event);
extern void                GameEvent_Free(GameEvent* event);

C_DECL_END

struct GameEvent
{
    GameEvent* ReturnEvent;
    GameEventCallback Callback;
    u32 EventState;
    void* EventData;
    GameSystem* m_GameSystem;
  
    #ifdef __cplusplus
  
    INLINE void* GetData() {
        return GameEvent_GetData(this);
    }

    INLINE u32* GetStatePtr() {
        return GameEvent_GetStatePtr(this);
    }

    INLINE gsys::Event* GetReturnEvetn() {
        return GameEvent_GetReturnEvent(this);
    }

    INLINE gsys::GameSystem* GetGameSystem() {
        return GameEvent_GetGameSystem(this);
    }

    INLINE gsys::EventReturnCode RunCallback() {
        return GameEvent_RunCallback(this);
    }

    INLINE void Transplant(GameEventCallback callback, u32 size) {
        GameEvent_Transplant(this, callback, size);
    }

    INLINE void Replace(gsys::Event* event) {
        GameEvent_Replace(this, event);
    }

    INLINE void ChainNext(gsys::Event* event) {
        GameEvent_ChainNext(this, event);
    }

    INLINE static gsys::Event* Create(gsys::GameSystem* gsys, gsys::Event* parentEvent, GameEventCallback callback, u32 evtDataSize) {
        return GameEvent_Create(gsys, parentEvent, callback, evtDataSize);
    }

    INLINE static gsys::Event* CreateOverlayDelegate(gsys::GameSystem* gsys, int ovlId, GameEventProvider eventConstructor, void* eventData) {
        return GameEvent_CreateOverlayDelegate(gsys, ovlId, eventConstructor, eventData);
    }

    #endif
};

#endif //__GAME_EVENT_H
// Tchaikovsky code generator
