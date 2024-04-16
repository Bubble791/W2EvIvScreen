#ifndef __GFL_ARCHIVE_H
#define __GFL_ARCHIVE_H

#include "swantypes.h"

STRUCT_DECLARE(ArcTool)

SWAN_CPPTYPE_EX(gfl::fs, Archive, ArcTool)
namespace gfl::fs { struct ArcSystem; }

#include "nds/fs.h"
#include "gfl/core/gfl_heap.h"

C_DECL_BEGIN

extern void        GFL_ArcSysInit(const char** pathList, int arcCount);
extern const char* GFL_ArcSysGetResourcePath(int arcId);
extern void        GFL_ArcSysLoadFile(ArcTool* arctool, int arcId);
extern void        GFL_ArcSysCreateRawHandle(ArcTool* arc, int arcId);
extern ArcTool*    GFL_ArcSysCreateFileHandle(int arcId, HeapID heapId);
extern ArcTool*    GFL_ArcSysCreateMemoryHandle(u32 offset, u32 size, HeapID heapId);
extern u16         GFL_ArcSysGetDataMax(int arcId);
extern u32         GFL_ArcSysGetDataLength(int arcId, u16 datId);
extern void*       GFL_ArcSysReadRawResource(int arcId, HeapID heapId, int seekOffset, int readLength);
extern void*       GFL_ArcSysReadHeapNew(int arcId, u16 datId, HeapID heapId);
extern void*       GFL_ArcSysReadHeapNewDirect(const char* path, u16 datId, HeapID heapId);
extern void*       GFL_ArcSysReadHeapNewRange(int arcId, u16 datId, HeapID heapId, int offset, int length);
extern void*       GFL_ArcSysReadHeapNewLZ(int arcId, u16 datId, b32 compressed, HeapID heapId);
extern void*       GFL_ArcSysReadHeapNewLZGetLen(int arcId, u16 datId, b32 compressed, HeapID heapId, u32* fileLength);
extern void*       GFL_ArcSysReadHeapNewImpl(int arcId, u16 datId, HeapID heapId, int offset, int length);
extern void        GFL_ArcSysRead(void* dest, int arcId, u16 datId);
extern void        GFL_ArcSysReadRange(void* dest, int arcId, u16 datId, int offset, int length);
extern void        GFL_ArcSysReadImpl(void* dest, int arcId, u16 datId, int offset, int length);
extern void        GFL_ArcToolInit(ArcTool* arc);
extern b32         GFL_ArcToolSeek(ArcTool* arc, u32 offset);
extern u32         GFL_ArcToolReadRaw(ArcTool* arc, s32 length, void* dest);
extern u16         GFL_ArcToolGetDataMax(ArcTool* arc);
extern u32         GFL_ArcToolGetDataLength(ArcTool* arcId, u16 datId);
extern b32         GFL_ArcToolReadRange(ArcTool* arc, u16 datId, u32 offset, u32 length, void* dest);
extern void        GFL_ArcToolRead(ArcTool* arc, u16 datId, void* dest);
extern void*       GFL_ArcToolReadHeapNew(ArcTool* arc, u16 datId, HeapID heapId);
extern void*       GFL_ArcToolReadHeapNewLZ(ArcTool* arc, u16 datId, b32 compressed, HeapID heapId);
extern void*       GFL_ArcToolReadHeapNewLZGetLen(ArcTool* arc, u16 datId, b32 compressed, HeapID heapId, u32* fileLength);
extern void        GFL_ArcToolFree(ArcTool* arc);

C_DECL_END

struct ArcTool
{
    FSFile File;
    u32 FIMGOffset;
    u16 NARCHeaderSize;
    u16 NARCFileCount;
  
    #ifdef __cplusplus
  
    INLINE static gfl::fs::Archive* Open(int arcId, HeapID heapId) {
        return GFL_ArcSysCreateFileHandle(arcId, heapId);
    }

    INLINE static gfl::fs::Archive* OpenExt(u32 offset, u32 size, HeapID heapId) {
        return GFL_ArcSysCreateMemoryHandle(offset, size, heapId);
    }

    INLINE void OpenRaw(int arcId) {
        GFL_ArcSysCreateRawHandle(this, arcId);
    }

    INLINE b32 Seek(u32 offset) {
        return GFL_ArcToolSeek(this, offset);
    }

    INLINE u32 ReadRaw(s32 length, void* dest) {
        return GFL_ArcToolReadRaw(this, length, dest);
    }

    INLINE u16 GetDataMax() {
        return GFL_ArcToolGetDataMax(this);
    }

    INLINE u32 GetDataLength(u16 datId) {
        return GFL_ArcToolGetDataLength(this, datId);
    }

    INLINE void Read(u16 datId, void* dest) {
        GFL_ArcToolRead(this, datId, dest);
    }

    INLINE b32 ReadRange(u16 datId, u32 offset, u32 length, void* dest) {
        return GFL_ArcToolReadRange(this, datId, offset, length, dest);
    }

    INLINE void* ReadHeapNew(u16 datId, HeapID heapId) {
        return GFL_ArcToolReadHeapNew(this, datId, heapId);
    }

    INLINE void* ReadHeapNewLZ(u16 datId, b32 compressed, HeapID heapId) {
        return GFL_ArcToolReadHeapNewLZ(this, datId, compressed, heapId);
    }

    INLINE void* ReadHeapNewLZ(u16 datId, b32 compressed, HeapID heapId, u32* fileLength) {
        return GFL_ArcToolReadHeapNewLZGetLen(this, datId, compressed, heapId, fileLength);
    }

    INLINE void Free() {
        GFL_ArcToolFree(this);
    }

    #endif
};

#ifdef __cplusplus
struct gfl::fs::ArcSystem {
    INLINE static void Init(const char** pathList, int arcCount) {
        GFL_ArcSysInit(pathList, arcCount);
    }

    INLINE static const char* GetResourcePath(int arcId) {
        return GFL_ArcSysGetResourcePath(arcId);
    }

    INLINE static void LoadFile(gfl::fs::Archive* arctool, int arcId) {
        GFL_ArcSysLoadFile(arctool, arcId);
    }

    INLINE static u16 GetDataMax(int arcId) {
        return GFL_ArcSysGetDataMax(arcId);
    }

    INLINE static u32 GetDataLength(int arcId, u16 datId) {
        return GFL_ArcSysGetDataLength(arcId, datId);
    }

    INLINE static void* ReadRawResource(int arcId, HeapID heapId, int seekOffset, int readLength) {
        return GFL_ArcSysReadRawResource(arcId, heapId, seekOffset, readLength);
    }

    INLINE static void* ReadHeapNew(int arcId, u16 datId, HeapID heapId) {
        return GFL_ArcSysReadHeapNew(arcId, datId, heapId);
    }

    INLINE static void* ReadHeapNewDirect(const char* path, u16 datId, HeapID heapId) {
        return GFL_ArcSysReadHeapNewDirect(path, datId, heapId);
    }

    INLINE static void* ReadHeapNewRange(int arcId, u16 datId, HeapID heapId, int offset, int length) {
        return GFL_ArcSysReadHeapNewRange(arcId, datId, heapId, offset, length);
    }

    INLINE static void* ReadHeapNewLZ(int arcId, u16 datId, b32 compressed, HeapID heapId) {
        return GFL_ArcSysReadHeapNewLZ(arcId, datId, compressed, heapId);
    }

    INLINE static void* ReadHeapNewLZ(int arcId, u16 datId, b32 compressed, HeapID heapId, u32* fileLength) {
        return GFL_ArcSysReadHeapNewLZGetLen(arcId, datId, compressed, heapId, fileLength);
    }

    INLINE static void Read(void* dest, int arcId, u16 datId) {
        GFL_ArcSysRead(dest, arcId, datId);
    }

    INLINE static void ReadRange(void* dest, int arcId, u16 datId, int offset, int length) {
        GFL_ArcSysReadRange(dest, arcId, datId, offset, length);
    }

};
#endif //__cplusplus

#endif //__GFL_ARCHIVE_H
// Tchaikovsky code generator
