#ifndef __GFL_TCB_H
#define __GFL_TCB_H

#include "swantypes.h"

STRUCT_DECLARE(TCB)
STRUCT_DECLARE(TCBManager)

typedef void (*TCBFunc)(TCB* tcb, void* data);

SWAN_CPPTYPE(gfl::core, TCB)
SWAN_CPPTYPE(gfl::core, TCBManager)

C_DECL_BEGIN

extern u32         GFL_TCBMgrCalcAllocSize(u32 tcbLimit);
extern TCBManager* GFL_TCBMgrCreate(u32 taskCount, void* alloc);
extern void        GFL_TCBMgrSetup(TCBManager* mgr);
extern void        GFL_TCBMgrUpdate(TCBManager* mgr);
extern TCB*        GFL_TCBMgrAddTask(TCBManager* mgr, TCBFunc callbackFunc, void* data, u32 priority);
extern TCB*        GFL_TCBMgrAddTaskCore(TCBManager* mgr, TCBFunc callbackFunc, void* data, u32 priority);
extern b32         GFL_TCBRemove(TCB* tcb);
extern void*       GFL_TCBGetData(TCB* tcb);
extern void        GFL_TCBSetCallbackFunc(TCB* tcb, TCBFunc func);

C_DECL_END

struct TCB
{
    TCBManager* Manager;
    TCB* PrevTCB;
    TCB* NextTCB;
    u32 Priority;
    void* Data;
    TCBFunc CallbackFunc;
    b32 WaitPriorityResync;
  
    #ifdef __cplusplus
  
    INLINE b32 Remove() {
        return GFL_TCBRemove(this);
    }

    INLINE void* GetData() {
        return GFL_TCBGetData(this);
    }

    INLINE void SetCallbackFunc(TCBFunc func) {
        GFL_TCBSetCallbackFunc(this, func);
    }

    #endif
};

struct TCBManager
{
    u32 MaxTCBCount;
    u32 NowTCBCount;
    TCB TCBTail;
    TCB** TCBPtrs;
    TCB* TCBs;
    b32 IsAddingTCB;
    TCB* NowExecTCB;
    TCB* NextExecTCB;
  
    #ifdef __cplusplus
  
    INLINE static u32 CalcAllocSize(u32 tcbLimit) {
        return GFL_TCBMgrCalcAllocSize(tcbLimit);
    }

    INLINE static gfl::core::TCBManager* Create(u32 taskCount, void* alloc) {
        return GFL_TCBMgrCreate(taskCount, alloc);
    }

    INLINE void Setup() {
        GFL_TCBMgrSetup(this);
    }

    INLINE void Update() {
        GFL_TCBMgrUpdate(this);
    }

    INLINE gfl::core::TCB* AddTask(TCBFunc callbackFunc, void* data, u32 priority) {
        return GFL_TCBMgrAddTask(this, callbackFunc, data, priority);
    }

    #endif
};

#endif //__GFL_TCB_H
// Tchaikovsky code generator
