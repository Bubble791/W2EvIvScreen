#ifndef __FIELD_G3DOBJ_H
#define __FIELD_G3DOBJ_H

#include "swantypes.h"

STRUCT_DECLARE(FieldG3DObjSystem)
STRUCT_DECLARE(FieldG3DObj)
STRUCT_DECLARE(FieldG3DObjResGroup)
STRUCT_DECLARE(FieldG3DObjResRequest)

SWAN_CPPTYPE_EX(field::g3d, ObjManager, FieldG3DObjSystem)
SWAN_CPPTYPE_EX(field::g3d, Obj, FieldG3DObj)
SWAN_CPPTYPE_EX(field::g3d, ObjResGroup, FieldG3DObjResGroup)
SWAN_CPPTYPE_EX(field::g3d, ObjResRequest, FieldG3DObjResRequest)

#include "gfl/g3d/gfl_g3d_system.h"
#include "gfl/core/gfl_heap.h"
#include "gfl/g3d/gfl_transform.h"
#include "gfl/fs/gfl_archive.h"
#include "field/field_color_postfx.h"

C_DECL_BEGIN

extern FieldG3DObjSystem*  FieldG3DObjSystem_Create(HeapID heapId, u32 resLimit, u32 objLimit);
extern void                FieldG3DObjSystem_Free(FieldG3DObjSystem* objSys);
extern void                FieldG3DObjSystem_SetupResources(FieldG3DObjSystem* sys);
extern void                FieldG3DObjSystem_Draw(FieldG3DObjSystem* sys);
extern u16                 FieldG3DObjSystem_AddResGroup(FieldG3DObjSystem* sys, FieldG3DObjResRequest* req, b32 preloadTextures);
extern void                FieldG3DObjSystem_FreeResGroup(FieldG3DObjSystem* g3dObjSys, u16 resGroupIdx);
extern u16                 FieldG3DObjSystem_AddObj(FieldG3DObjSystem* sys, u32 resGroupIdx, u16 modelIdxInRes, VecFx32* pos);
extern void                FieldG3DObjSystem_FreeObj(FieldG3DObjSystem* g3dObjSys, u16 objIdx);
extern void                FieldG3DObjSystem_DrawObj(FieldG3DObjSystem* g3dObjSys, u16 objIdx);
extern SRTMatrix*          FieldG3DObjSystem_GetObjTransform(FieldG3DObjSystem* g3dObjSys, u16 objIdx);
extern void                FieldG3DObjSystem_SetObjPosition(FieldG3DObjSystem* g3dObjSys, u16 objIdx, VecFx32* position);
extern b32                 FieldG3DObjSystem_StepObjAnm(FieldG3DObjSystem* g3dObjSys, u16 objIdx, fx16 addend);
extern int                 FieldG3DObjSystem_StepObjAnmLoop(FieldG3DObjSystem* g3dObjSys, u16 objIdx, fx16 addend);
extern fx32                FieldG3DObjSystem_GetAnmFrame(FieldG3DObjSystem* g3dObjSys, u16 objIdx, u8 anmIdx);
extern void                FieldG3DObjSystem_SetAnmFrame(FieldG3DObjSystem* g3dObjSys, u16 objIdx, u8 anmIdx, fx32 frame);
extern void                FieldG3DObj_Free(FieldG3DObj* obj, FieldG3DObjResGroup* resGroup);
extern void                FieldG3DObj_Setup(FieldG3DObj* obj, FieldG3DObjResGroup* resGroup, u16 resGroupId, u16 modelIdxInRes, HeapID heapId, VecFx32* position, b32 identityRS);
extern void                FieldG3DObjResRequest_Clear(FieldG3DObjResRequest* req);
extern void                FieldG3DObjResRequest_SetModel(FieldG3DObjResRequest* req, ArcTool* arc, u16 datId);
extern void                FieldG3DObjResRequest_SetAnmArc(FieldG3DObjResRequest* req, ArcTool* arc);
extern void                FieldG3DObjResRequest_AddAnm(FieldG3DObjResRequest* req, u16 datId);
extern void                FieldG3DObjResGroup_Free(FieldG3DObjResGroup* resGroup);
extern void                FieldG3DObjResGroup_SetupTextures(FieldG3DObjResGroup* resGroup);

C_DECL_END

struct FieldG3DObjSystem
{
    HeapID m_HeapID;
    u16 _padHeapID;
    u16 ResGroupCount;
    u16 ObjectsCount;
    FieldG3DObjResGroup* ResGroups;
    FieldG3DObj* Objects;
    FieldColorPostFX* m_ColorPostFX;
  
    #ifdef __cplusplus
  
    INLINE static field::g3d::ObjManager*  Create(HeapID heapId, u32 resLimit, u32 objLimit) {
        return FieldG3DObjSystem_Create(heapId, resLimit, objLimit);
    }

    INLINE void Free() {
        FieldG3DObjSystem_Free(this);
    }

    INLINE void SetupResources() {
        FieldG3DObjSystem_SetupResources(this);
    }

    INLINE void Draw() {
        FieldG3DObjSystem_Draw(this);
    }

    INLINE u16 AddResGroup(field::g3d::ObjResRequest* req, b32 preloadTextures) {
        return FieldG3DObjSystem_AddResGroup(this, req, preloadTextures);
    }

    INLINE void FreeResGroup(u16 resGroupIdx) {
        FieldG3DObjSystem_FreeResGroup(this, resGroupIdx);
    }

    INLINE u16 AddObj(u32 resGroupIdx, u16 modelIdxInRes, VecFx32* pos) {
        return FieldG3DObjSystem_AddObj(this, resGroupIdx, modelIdxInRes, pos);
    }

    INLINE void FreeObj(u16 objIdx) {
        FieldG3DObjSystem_FreeObj(this, objIdx);
    }

    INLINE void DrawObj(u16 objIdx) {
        FieldG3DObjSystem_DrawObj(this, objIdx);
    }

    INLINE gfl::g3d::Transform*  GetObjTransform(u16 objIdx) {
        return FieldG3DObjSystem_GetObjTransform(this, objIdx);
    }

    INLINE void SetObjPosition(u16 objIdx, VecFx32* position) {
        FieldG3DObjSystem_SetObjPosition(this, objIdx, position);
    }

    #endif
};

struct FieldG3DObj
{
    u32 Flags;
    u16 ResGroupID;
    u16 ModelIdxInRes;
    SRTMatrix Transform;
    G3DActor* Actor;
    G3DAnim* Animations[8];
  
    #ifdef __cplusplus
  
    INLINE void Free(field::g3d::ObjResGroup* resGroup) {
        FieldG3DObj_Free(this, resGroup);
    }

    INLINE void Setup(field::g3d::ObjResGroup* resGroup, u16 resGroupId, u16 modelIdxInRes, HeapID heapId, VecFx32* position, b32 identityRS) {
        FieldG3DObj_Setup(this, resGroup, resGroupId, modelIdxInRes, heapId, position, identityRS);
    }

    #endif
};

struct FieldG3DObjResGroup
{
    G3DResource* MdlRes;
    G3DResource* TexRes;
    G3DResource* AnmResources[8];
    u8 AnmCount;
    u8 Status;
    u16 field_2A;
  
    #ifdef __cplusplus
  
    INLINE void Free() {
        FieldG3DObjResGroup_Free(this);
    }

    INLINE void SetupTextures() {
        FieldG3DObjResGroup_SetupTextures(this);
    }

    #endif
};

struct FieldG3DObjResRequest
{
    ArcTool* MdlArc;
    ArcTool* TexArc;
    ArcTool* AnmArc;
    u16 MdlDatID;
    u16 TexDatID;
    u16 AnmDatIDs[8];
    u8 AnmCount;
  
    #ifdef __cplusplus
  
    INLINE void Clear() {
        FieldG3DObjResRequest_Clear(this);
    }

    INLINE void SetModel(gfl::fs::Archive* arc, u16 datId) {
        FieldG3DObjResRequest_SetModel(this, arc, datId);
    }

    INLINE void SetAnmArc(gfl::fs::Archive* arc) {
        FieldG3DObjResRequest_SetAnmArc(this, arc);
    }

    INLINE void AddAnm(u16 datId) {
        FieldG3DObjResRequest_AddAnm(this, datId);
    }

    #endif
};

#endif //__FIELD_G3DOBJ_H
// Tchaikovsky code generator
