#ifndef __GFL_VRAMMGR_H
#define __GFL_VRAMMGR_H

#include "swantypes.h"

STRUCT_DECLARE(VRAMManager)
STRUCT_DECLARE(VRAMManagerAllocation)

SWAN_CPPTYPE(gfl::core, VRAMManager)
SWAN_CPPTYPE_EX(gfl::core, VRAMAllocation, VRAMManagerAllocation)

#include "gfl/core/gfl_areaman.h"
#include "nds/gx.h"

C_DECL_BEGIN

extern VRAMManager*    GFL_VRAMManagerCreate(HeapID heapId, b32 blockSizeEx, VRAMBankMask banks, u32 offset, u32 mappingDispCntBits);
extern void            GFL_VRAMManagerFree(VRAMManager* vman);
extern u32             GFL_VRAMManagerCalcBankSizeBytes(VRAMBankMask banks);
extern u32             GFL_VRAMManagerGetObjTileMappingBoundary(u32 dispcntBits);
extern void            GFL_VRAMManagerAllocInit(VRAMManagerAllocation* allocation);
extern b32             GFL_VRAMManagerAllocIsInvalid(VRAMManagerAllocation* allocation);
extern b32             GFL_VRAMManagerAlloc(VRAMManager* vman, u32 size, VRAMManagerAllocation* alloc);
extern void            GFL_VRAMManagerDeAlloc(VRAMManager* vman, VRAMManagerAllocation* alloc);
extern void*           GFL_VRAMManagerGetAllocAddress(VRAMManager* vman, VRAMManagerAllocation* allocation);

C_DECL_END

struct VRAMManager
{
    AreaMan* m_AreaMan;
    u16 Boundary;
    u16 RealAddrOffset;
  
    #ifdef __cplusplus
  
    INLINE static gfl::core::VRAMManager* Create(HeapID heapId, b32 blockSizeEx, VRAMBankMask banks, u32 offset, u32 mappingDispCntBits) {
        return GFL_VRAMManagerCreate(heapId, blockSizeEx, banks, offset, mappingDispCntBits);
    }

    INLINE void Free() {
        GFL_VRAMManagerFree(this);
    }

    INLINE b32 Alloc(u32 size, gfl::core::VRAMAllocation* alloc) {
        return GFL_VRAMManagerAlloc(this, size, alloc);
    }

    INLINE void DeAlloc(gfl::core::VRAMAllocation* alloc) {
        GFL_VRAMManagerDeAlloc(this, alloc);
    }

    INLINE void* GetAllocAddress(gfl::core::VRAMAllocation* allocation) {
        return GFL_VRAMManagerGetAllocAddress(this, allocation);
    }

    INLINE static u32 GetObjTileMappingBoundary(u32 dispcntBits) {
        return GFL_VRAMManagerGetObjTileMappingBoundary(dispcntBits);
    }

    INLINE static u32 CalcBankSizeBytes(VRAMBankMask banks) {
        return GFL_VRAMManagerCalcBankSizeBytes(banks);
    }

    #endif
};

struct VRAMManagerAllocation
{
    u32 Addr;
    u32 Size;
  
    #ifdef __cplusplus
  
    INLINE void Init() {
        GFL_VRAMManagerAllocInit(this);
    }

    INLINE b32 IsInvalid() {
        return GFL_VRAMManagerAllocIsInvalid(this);
    }

    #endif
};

#endif //__GFL_VRAMMGR_H
// Tchaikovsky code generator
