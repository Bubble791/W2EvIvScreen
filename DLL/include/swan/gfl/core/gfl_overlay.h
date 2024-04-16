#ifndef __GFL_OVERLAY_H
#define __GFL_OVERLAY_H

#include "swantypes.h"

STRUCT_DECLARE(OvlListEntry)
STRUCT_DECLARE(OvlManager)

ENUM_DECLARE(OvlRegion)

enum OvlRegion
#ifdef __cplusplus
: u32
#endif
{
    OVLRGN_EWRAM,
    OVLRGN_ITCM,
    OVLRGN_DTCM
};
SWAN_CPPTYPE_EX(gfl::ovl, Region, OvlRegion)

SWAN_CPPTYPE_EX(gfl::ovl, Handle, OvlListEntry)
SWAN_CPPTYPE_EX(gfl::ovl, Manager, OvlManager)

#include "gfl/core/gfl_heap.h"

C_DECL_BEGIN

extern void            GFL_OvlManagerInit(HeapID heapId, u32 wramOvlMax, u32 itcmOvlMax, u32 dtcmOvlMax);
extern b32             GFL_OvlCheckMemoryCollision(u32 ovlId);
extern b32             GFL_OvlLoad(u32 ovlId);
extern void            GFL_OvlUnload(u32 ovlId);
extern void            GFL_OvlEntryUnload(OvlListEntry* ovlEntry);
extern OvlRegion       GFL_OvlGetMemoryRegion(u32 ovlId);
extern b32             GFL_OvlGetMemoryRange(u32 ovlId, u32* overlayAddress, u32* overlayEnd);
extern OvlListEntry*   GFL_OvlGetList(OvlRegion region);
extern u8              GFL_OvlGetListCount(OvlRegion region);

C_DECL_END

struct OvlListEntry
{
    u32 OvlID;
    b32 Exists;
  
    #ifdef __cplusplus
  
    INLINE void Unload() {
        GFL_OvlEntryUnload(this);
    }

    #endif
};

struct OvlManager
{
    u8 OvlMaxWRAM;
    u8 OvlMaxITCM;
    u8 OvlMaxDTCM;
    u8 _padOvlMax;
    OvlListEntry* OverlaysWRAM;
    OvlListEntry* OverlaysITCM;
    OvlListEntry* OverlaysDTCM;
    OvlListEntry OvlList[];
  
    #ifdef __cplusplus
  
    INLINE static void Init(HeapID heapId, u32 wramOvlMax, u32 itcmOvlMax, u32 dtcmOvlMax) {
        GFL_OvlManagerInit(heapId, wramOvlMax, itcmOvlMax, dtcmOvlMax);
    }

    INLINE static gfl::ovl::Region GetMemoryRegion(u32 ovlId) {
        return GFL_OvlGetMemoryRegion(ovlId);
    }

    INLINE static b32 GetMemoryRange(u32 ovlId, u32* overlayAddress, u32* overlayEnd) {
        return GFL_OvlGetMemoryRange(ovlId, overlayAddress, overlayEnd);
    }

    INLINE static u8 GetOvlCount(gfl::ovl::Region region) {
        return GFL_OvlGetListCount(region);
    }

    INLINE static gfl::ovl::Handle* GetOvlList(gfl::ovl::Region region) {
        return GFL_OvlGetList(region);
    }

    INLINE static b32 CheckMemoryCollision(u32 ovlId) {
        return GFL_OvlCheckMemoryCollision(ovlId);
    }

    INLINE static b32 Load(u32 ovlId) {
        return GFL_OvlLoad(ovlId);
    }

    INLINE static void Unload(u32 ovlId) {
        GFL_OvlUnload(ovlId);
    }

    #endif
};

extern OvlManager* g_OvlManager;

#endif //__GFL_OVERLAY_H
// Tchaikovsky code generator
