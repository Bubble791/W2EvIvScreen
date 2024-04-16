#ifndef __GFL_AREAMAN_H
#define __GFL_AREAMAN_H

#include "swantypes.h"

STRUCT_DECLARE(AreaMan)

SWAN_CPPTYPE(gfl::core, AreaMan)

C_DECL_BEGIN

extern AreaMan*    GFL_AreaManCreate(u32 size, HeapID heapId);
extern void        GFL_AreaManFree(AreaMan* area);
extern u32         GFL_AreaManAllocDefault(AreaMan* area, u32 count);
extern u32         GFL_AreaManAllocHead(AreaMan* area, u32 minAddr, u32 addrRange, u32 count);
extern u32         GFL_AreaManAllocTail(AreaMan* area, u32 maxAddr, u32 addrRange, u32 count);
extern b32         GFL_AreaManSetBits(AreaMan* area, u32 bitAddr, u32 bitCount);
extern void        GFL_AreaManDeAlloc(AreaMan* area, u32 bitAddr, u32 bitCount);

C_DECL_END

struct AreaMan
{
    u16 RawSize;
    u16 BlockSize;
    void* HeapEnd;
    b32 Debug;
    u8 Bytes[];
  
    #ifdef __cplusplus
  
    INLINE static gfl::core::AreaMan* Create(u32 size, HeapID heapId) {
        return GFL_AreaManCreate(size, heapId);
    }

    INLINE void Free() {
        GFL_AreaManFree(this);
    }

    INLINE u32 AllocDefault(u32 count) {
        return GFL_AreaManAllocDefault(this, count);
    }

    INLINE u32 AllocHead(u32 minAddr, u32 addrRange, u32 count) {
        return GFL_AreaManAllocHead(this, minAddr, addrRange, count);
    }

    INLINE u32 AllocTail(u32 maxAddr, u32 addrRange, u32 count) {
        return GFL_AreaManAllocTail(this, maxAddr, addrRange, count);
    }

    INLINE b32 SetBits(u32 bitAddr, u32 bitCount) {
        return GFL_AreaManSetBits(this, bitAddr, bitCount);
    }

    INLINE void DeAlloc(u32 bitAddr, u32 bitCount) {
        GFL_AreaManDeAlloc(this, bitAddr, bitCount);
    }

    #endif
};

#endif //__GFL_AREAMAN_H
// Tchaikovsky code generator
