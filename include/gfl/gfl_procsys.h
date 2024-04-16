#ifndef __GFL_PROCSYS_H
#define __GFL_PROCSYS_H

STRUCT_DECLARE(GameProcFunctions)
STRUCT_DECLARE(GameProc)

struct GameProc
{
    const void* Functions;
    int OverlayID;
    int ProcessStatus;
    int EventState;
    void* ProcessData;
    void* ProcessSubsystem;
    GameProc* ReturnProcess;
    GameProc* NextProcess;
} ;

typedef int (*GameProcFunc)(GameProc*, u32*, void*, void*);

struct GameProcFunctions
{
    GameProcFunc Init;
    GameProcFunc MainLoop;
    GameProcFunc End;
};

void* LONG_CALL GFL_ProcInitSubsystem(GameProc* proc, u32 size, u16 heapId);
void LONG_CALL sys_memset16(u16 value, void* ptr, int size);
void* LONG_CALL sys_memcpy16(const void* src, void* dst, int size);
void LONG_CALL sys_memset32(u32 value, void* ptr, int size);
void* LONG_CALL sys_memcpy32(const void* src, void* dest, int size);
void LONG_CALL sys_memcpy_volatile(const void* src, volatile int* dest, int size);
void LONG_CALL sys_memset32_fast(u32 value, const void* ptr, int size);
void* LONG_CALL sys_memcpy32_fast(const void* src, void* dst, u32 size);
void sys_memset(const void* ptr, u8 value, int size);
void LONG_CALL sys_memset_fast(const void* ptr, u8 value, int size);
const void* LONG_CALL sys_memcpy(const void* src, void* dst, u32 size);
s32 LONG_CALL sys_memcmp(const void* src1, const void* src2, int size);
const void* LONG_CALL sys_memcpy_fast(const void* src, void* dst, int size);
const void* LONG_CALL sys_memcpy_ex(const void* src, void* dst, s32 size);
void LONG_CALL GFL_ProcReleaseSubsystem(GameProc* proc);
int LONG_CALL GCTX_HIDGetPressedKeys(void);

#endif