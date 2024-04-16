#ifndef __GFL_PROCSYS_H
#define __GFL_PROCSYS_H

#include "swantypes.h"

STRUCT_DECLARE(GameProcFunctions)
STRUCT_DECLARE(GameProcRequest)
STRUCT_DECLARE(GameProc)
STRUCT_DECLARE(GameProcManager)

ENUM_DECLARE(GameProcStatus)
ENUM_DECLARE(GameProcManagerStatus)

typedef b32 (*GameProcFunc)(GameProc*, u32*, void*, void*);

enum GameProcStatus
#ifdef __cplusplus
: u32
#endif
{
    LOAD = 0x0,
    INIT = 0x1,
    RUN = 0x2,
    END = 0x3,
};
SWAN_CPPTYPE_EX(gfl::core, ProcStatus, GameProcStatus)

enum GameProcManagerStatus
#ifdef __cplusplus
: u32
#endif
{
    GAMEPROC_MGR_IDLE = 0x0,
    GAMEPROC_MGR_RUNNING = 0x1,
    GAMEPROC_MGR_SWITCHING = 0x2,
};
SWAN_CPPTYPE_EX(gfl::core, ProcManagerStatus, GameProcManagerStatus)

SWAN_CPPTYPE_EX(gfl::core, ProcVTable, GameProcFunctions)
SWAN_CPPTYPE_EX(gfl::core, ProcRequest, GameProcRequest)
SWAN_CPPTYPE_EX(gfl::core, Proc, GameProc)
SWAN_CPPTYPE_EX(gfl::core, ProcManager, GameProcManager)
SWAN_CPPTYPE_EX(gfl::core, ProcFunc, GameProcFunc)

#include "gfl/core/gfl_heap.h"

C_DECL_BEGIN

extern GameProcManager*        GFL_ProcMgrCreate(HeapID heapId);
extern void                    GFL_ProcMgrFree(GameProcManager* mgr);
extern GameProcManagerStatus   GFL_ProcMgrUpdate(GameProcManager* mgr);
extern void                    GFL_ProcMgrSwitchQueued(GameProcManager* mgr);
extern void                    GFL_ProcMgrReplaceProc(GameProcManager* mgr, int ovlId, const GameProcFunctions* vtbl, void* procData);
extern void                    GFL_ProcMgrQueueProc(GameProcManager* mgr, int ovlId, const GameProcFunctions* vtbl, void* procData);
extern GameProc*               GFL_ProcCreate(int ovlId, const GameProcFunctions* vtbl, void* processData, HeapID heapId);
extern void                    GFL_ProcFree(void* heap);
extern b32                     GFL_ProcUpdate(GameProc* proc);
extern void*                   GFL_ProcInitSubsystem(GameProc* proc, u32 size, HeapID heapId);
extern void                    GFL_ProcReleaseSubsystem(GameProc* proc);

C_DECL_END

struct GameProcFunctions
{
    GameProcFunc Init;
    GameProcFunc MainLoop;
    GameProcFunc End;
};

struct GameProcRequest
{
    int OvlID;
    const GameProcFunctions* Functions;
    void* ProcessData;
};

struct GameProc
{
    const GameProcFunctions* Functions;
    int OverlayID;
    GameProcStatus ProcessStatus;
    int EventState;
    void* ProcessData;
    void* ProcessSubsystem;
    GameProc* ReturnProcess;
    GameProc* NextProcess;
  
    #ifdef __cplusplus
  
    INLINE static gfl::core::Proc* Create(int ovlId, const gfl::core::ProcVTable* vtbl, void* processData, HeapID heapId) {
        return GFL_ProcCreate(ovlId, vtbl, processData, heapId);
    }

    INLINE void Free() {
        GFL_ProcFree(this);
    }

    INLINE b32 Update() {
        return GFL_ProcUpdate(this);
    }

    INLINE void* InitSubsystem(u32 size, HeapID heapId) {
        return GFL_ProcInitSubsystem(this, size, heapId);
    }

    INLINE void ReleaseSubsystem() {
        GFL_ProcReleaseSubsystem(this);
    }

    #endif
};

struct GameProcManager
{
    HeapID m_HeapID;
    s16 _padHeapID;
    int field_4;
    GameProc* CurrentProc;
    b32 IsReqQueueProc;
    b32 IsReqReplaceProc;
    GameProcRequest ProcRequest;
  
    #ifdef __cplusplus
  
    INLINE static gfl::core::ProcManager* Create(HeapID heapId) {
        return GFL_ProcMgrCreate(heapId);
    }

    INLINE void Free() {
        GFL_ProcMgrFree(this);
    }

    INLINE gfl::core::ProcManagerStatus Update() {
        return GFL_ProcMgrUpdate(this);
    }

    INLINE void ReplaceProc(int ovlId, const gfl::core::ProcVTable* vtbl, void* procData) {
        GFL_ProcMgrReplaceProc(this, ovlId, vtbl, procData);
    }

    INLINE void QueueProc(int ovlId, const gfl::core::ProcVTable* vtbl, void* procData) {
        GFL_ProcMgrQueueProc(this, ovlId, vtbl, procData);
    }

    #endif
};

#endif //__GFL_PROCSYS_H
// Tchaikovsky code generator
