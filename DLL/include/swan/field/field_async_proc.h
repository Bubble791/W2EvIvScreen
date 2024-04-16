#ifndef __FIELD_ASYNC_PROC_H
#define __FIELD_ASYNC_PROC_H

#include "swantypes.h"

STRUCT_DECLARE(FieldAsyncProcManager)
STRUCT_DECLARE(FieldAsyncProc)
STRUCT_DECLARE(FieldAsyncProcTemplate)

typedef void (*FieldAsyncProcFunc)(FieldAsyncProc* proc, Field* field, void* data);

#include "gfl/core/gfl_tcb.h"
#include "field/fieldmap.h"

struct FieldAsyncProcManager
{
    Field* m_Field;
    u32 m_HeapID;
    s32 ProcessLimit;
    FieldAsyncProc* Processes;
    TCBManager* UpdateTCBMgr;
    TCBManager* DrawTCBMgr;
};

struct FieldAsyncProc
{
    FieldAsyncProcManager* m_AsyncProcMgr;
    TCB* UpdateTCB;
    TCB* DrawTCB;
    FieldAsyncProcTemplate* Template;
    void* DataHeap;
    u32 OvlID;
};

struct FieldAsyncProcTemplate
{
    u32 TCBPriority;
    u16 DataHeapSize;
    u16 _padDataHeapSize;
    FieldAsyncProcFunc InitFunc;
    void* EndCallback;
    FieldAsyncProcFunc UpdateFunc;
    FieldAsyncProcFunc DrawFunc;
};

#endif //__FIELD_ASYNC_PROC_H
// Tchaikovsky code generator
