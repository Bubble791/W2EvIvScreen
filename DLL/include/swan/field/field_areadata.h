#ifndef __FIELD_AREADATA_H
#define __FIELD_AREADATA_H

#include "swantypes.h"

STRUCT_DECLARE(AreaData)

SWAN_CPPTYPE(field, AreaData)

C_DECL_BEGIN

extern AreaData*   AreaData_Create(HeapID heapId, u16 areaId, u16 areaSeasonShift);
extern void        AreaData_Free(AreaData* ad);
extern int         AreaData_GetPropBundleID(AreaData* ad);
extern int         AreaData_GetTexSetID(AreaData* ad);
extern int         AreaData_GetSRTAnmID(AreaData* ad);
extern int         AreaData_GetPatAnmID(AreaData* ad);
extern int         AreaData_IsExterior(AreaData* ad);
extern int         AreaData_GetLightsID(AreaData* ad);
extern u8          AreaData_GetEdgeColorTableID(AreaData* ad);
extern int         AreaData_GetActorMatColorID(AreaData* ad);
extern b32         AreaData_HasSeasons(u16 areaID);

C_DECL_END

struct AreaData
{
    u16 Buildings;
    u16 Textures;
    u8 SrtAnime;
    u8 PatAnime;
    u8 IsExterior;
    u8 Lights;
    u8 EdgeColorTableId;
    u8 BbdMdlColors;
  
    #ifdef __cplusplus
  
    INLINE static field::AreaData* Create(HeapID heapId, u16 areaId, u16 areaSeasonShift) {
        return AreaData_Create(heapId, areaId, areaSeasonShift);
    }

    INLINE void Free() {
        AreaData_Free(this);
    }

    INLINE int GetPropBundleID() {
        return AreaData_GetPropBundleID(this);
    }

    INLINE int GetTexSetID() {
        return AreaData_GetTexSetID(this);
    }

    INLINE int GetSRTAnmID() {
        return AreaData_GetSRTAnmID(this);
    }

    INLINE int GetPatAnmID() {
        return AreaData_GetPatAnmID(this);
    }

    INLINE int GetIsExterior() {
        return AreaData_IsExterior(this);
    }

    INLINE int GetLightsID() {
        return AreaData_GetLightsID(this);
    }

    INLINE u8 GetEdgeColorTableID() {
        return AreaData_GetEdgeColorTableID(this);
    }

    INLINE int GetActorMatColorID() {
        return AreaData_GetActorMatColorID(this);
    }

    INLINE static b32 HasSeasons(u16 areaID) {
        return AreaData_HasSeasons(areaID);
    }

    #endif
};

#endif //__FIELD_AREADATA_H
// Tchaikovsky code generator
