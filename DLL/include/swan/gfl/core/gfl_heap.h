#ifndef __GFL_HEAP_H
#define __GFL_HEAP_H

#include "swantypes.h"

#include <string.h>

#define GFL_HEAP__FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define GFL_NEW(heapId, type) (type*) GFL_HeapAllocate((heapId), sizeof(type), 0, GFL_HEAP__FILENAME__, __LINE__)
#define GFL_NEW_ARRAY(heapId, type, count) (type*) GFL_HeapAllocate((heapId), sizeof(type) * (count), 0, GFL_HEAP__FILENAME__, __LINE__)

#define GFL_MALLOC(heapId, size) GFL_HeapAllocate((heapId), (size), 0, GFL_HEAP__FILENAME__, __LINE__)
#define GFL_CALLOC(heapId, size) GFL_HeapAllocate((heapId), (size), 1, GFL_HEAP__FILENAME__, __LINE__)
#define GFL_FREE(ptr) GFL_HeapFree((ptr))

STRUCT_DECLARE(HeapSetup)
STRUCT_DECLARE(HeapDebugInfo)
STRUCT_DECLARE(HeapHandle)
STRUCT_DECLARE(HeapBlockHandle)
STRUCT_DECLARE(GFLHeapManager)

ENUM_DECLARE(AllocatorState)

typedef u16 HeapID;

enum AllocatorState
#ifdef __cplusplus
: u32
#endif
{
    HEAP_OK = 0x0,
    HEAP_ID_OUT_OF_RANGE = 0x1,
    HEAP_MISSING_HANDLE = 0x2,
    HEAP_ALLOC_FAIL = 0x3,
    HEAP_LIMIT_REACHED = 0x4,
    HEAP_INIT_FAIL = 0x5,
};

C_DECL_BEGIN

extern b32                         GFL_HeapMgrInit(HeapSetup* mainHeapInfo, u16 mainHeapCount, u16 subHeapCount, u32 alignment);
extern void*                       GFL_HeapGetRawPtr(HeapID heapId);
extern u16                         GFL_HeapGetAllocationCount(HeapID heapId);
extern void                        GFL_HeapCreateRoot(void* memAddress, u32 size, HeapID heapId);
extern void                        GFL_HeapCreateChild(HeapID parentHeapId, HeapID heapId, u32 size);
extern b32                         GFL_HeapAddRoot(void* startAddress, u32 size, int heapId);
extern b32                         GFL_HeapAddChild(HeapID mainHeapID, HeapID subHeapID, u32 size);
extern void                        GFL_HeapDelete(HeapID heapId);
extern u32                         GFL_HeapGetSize(HeapID heapId);
extern u16                         GFL_HeapGetAllocationCount(HeapID heapId);
extern u32                         GFL_HeapGetFreeSize(HeapID heapId);
extern u32                         GFL_HeapGetHighestAllocatableSize(HeapID heapId);
extern b32                         GFL_HeapDeleteCore(HeapID heapId);
extern u16                         GFL_HeapGetAllocationCountCore(HeapID heapId);
extern u32                         GFL_HeapGetFreeSizeCore(HeapID heapId);
extern void*                       GFL_HeapAllocate(HeapID heapId, u32 size, b32 calloc, const char* sourceFile, u16 lineNo);
extern void                        GFL_HeapFree(void* heap);
extern void                        GFL_HeapResize(void* block, u32 newSize);
extern void*                       GFL_HeapAllocateCore(HeapID heapId, u32 size);
extern b32                         GFL_HeapFreeCore(void* heap);
extern b32                         GFL_HeapResizeCore(void* block, u32 newSize);
extern HeapID                      GFL_HeapGetBlockHeapID(void* block);
extern void                        GFL_HeapSetBlockDebugInfo(void* block, const char* __file__, u16 __line__);
extern HeapDebugInfo*              GFL_HeapGetBlockDebugInfoPtr(void* block);
extern b32                         GFL_HeapStatusCheck(HeapID heapId);
extern b32                         GFL_HeapStatusValidate(HeapID heapId);
extern AllocatorState              GFL_HeapGetLastResult();
extern void                        GFL_HeapHandleAllocResult(AllocatorState state);
extern void                        GFL_HeapDebugTraceAlloc(HeapID heapId, void* block, u32 blockLength);
extern void                        GFL_HeapDebugTraceFree(void* block);
extern void                        GFL_HeapDebugNotifyTrackedAlloc(void* block);
extern void                        GFL_HeapDebugNotifyTrackedFree(void* block);
extern void                        GFL_HeapDeleteCleanCheck(HeapID heapId);
extern void                        GFL_HeapDumpAllocFailure(HeapID heapId, u32 blockLength);
extern void                        GFL_HeapDumpOnFailure(HeapID heapId);
extern b32                         GFL_HeapDebugCopyFileName(char* dest, char* src);
SWAN_CPPONLY(INLINE void*          operator new(size_t size, HeapID heapId) { return GFL_MALLOC(heapId, size); });
SWAN_CPPONLY(INLINE void*          operator new[](size_t size, HeapID heapId) { return GFL_MALLOC(heapId, size); });

C_DECL_END

struct HeapSetup
{
    int Size;
    int field_4;
};

struct HeapDebugInfo
{
    char FileName[18];
    u16 LineNo;
};

struct HeapHandle
{
    void* HeapBase;
    void* ParentHeapBase;
    void* StartAddress;
    u16 AllocationBlockCount;
    char IsMainHeap;
    char field_F;
};

struct HeapBlockHandle
{
    u16 HeapID;
    u16 Magic;
    HeapDebugInfo DebugInfo;
    int field_18;
};

struct GFLHeapManager
{
    HeapHandle* HeapHandles;
    u8* HeapHandleIndices;
    u16 SubHeapCount;
    u16 MainHeapCount;
    u16 MaxConcurrentSubHandles;
    u16 ResultCode;
};

extern GFLHeapManager* g_HeapMgr;

#endif //__GFL_HEAP_H
// Tchaikovsky code generator
