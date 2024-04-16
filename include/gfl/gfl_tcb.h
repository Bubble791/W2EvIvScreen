#ifndef __GFL_TCB_H
#define __GFL_TCB_H

STRUCT_DECLARE(TCB)
typedef void (*VBlankCallback)(void*);

struct TCB
{
    void* Manager;
    TCB* PrevTCB;
    TCB* NextTCB;
    u32 Priority;
    void* Data;
    void* CallbackFunc;
    u32 WaitPriorityResync;
};

typedef void (*TCBFunc)(TCB* tcb, void* data);

void LONG_CALL GFL_HBlankTCBUpdate(void);
TCB* LONG_CALL GFL_HBlankTCBAdd(TCBFunc callback, void* data, u32 priority);
void LONG_CALL GFL_VBlankExecCallback(void);
int LONG_CALL GFL_VBlankSetCallback(VBlankCallback callback, void* data);
void LONG_CALL GFL_VBlankResetCallback(void);
u32 LONG_CALL GFL_VBlankUpdate(void);
TCB* LONG_CALL GFL_VBlankTCBAdd(TCBFunc callback, void* data, u32 priority);
void* LONG_CALL GFL_VBlankGetTCBMgr(void);
int LONG_CALL GFL_TCBRemove(TCB* tcb);

#endif