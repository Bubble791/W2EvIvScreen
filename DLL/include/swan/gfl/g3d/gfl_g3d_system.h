#ifndef __GFL_G3D_SYSTEM_H
#define __GFL_G3D_SYSTEM_H

#include "swantypes.h"

STRUCT_DECLARE(G3DResource)
STRUCT_DECLARE(G3DSystem)
STRUCT_DECLARE(G3DModel)
STRUCT_DECLARE(G3DAnim)
STRUCT_DECLARE(G3DActor)

ENUM_DECLARE(G3DResourceType)

typedef void (*G3DSystemInitCallback)();
typedef void (*G3DModelDrawCallback)();

enum G3DResourceType
#ifdef __cplusplus
: u32
#endif
{
    G3D_RESTYPE_INVALID = 0x0,
    G3D_RESTYPE_MDL_TEX = 0x1,
    G3D_RESTYPE_MDL = 0x2,
    G3D_RESTYPE_TEX = 0x3,
    G3D_RESTYPE_ANM = 0x4
};
SWAN_CPPTYPE_EX(gfl::g3d, ResourceType, G3DResourceType)

SWAN_CPPTYPE_EX(gfl::g3d, Resource, G3DResource)
SWAN_CPPTYPE_EX(gfl::g3d, System, G3DSystem)
namespace gfl::g3d { struct Texture; }
SWAN_CPPTYPE_EX(gfl::g3d, Model, G3DModel)
SWAN_CPPTYPE_EX(gfl::g3d, Animation, G3DAnim)
SWAN_CPPTYPE_EX(gfl::g3d, Actor, G3DActor)

#include "gfl/g3d/gfl_g3d_camera.h"
#include "gfl/g3d/gfl_g3d_light.h"
#include "gfl/g3d/gfl_transform.h"
#include "ns/g3d/res/G3DResData.h"
#include "ns/g3d/res/ResTexture.h"

C_DECL_BEGIN

extern void            GFL_G3DSysCreate(b32 useFrmHeapVramMgr, u32 numMgmtBlks, u32 dat3, u32 dat4, u16 dtcmAllocSize, HeapID heapId, G3DSystemInitCallback initCallback);
extern void            GFL_G3DSysFree();
extern void            GFL_G3DSysMtxGetProjection(G3DCameraProjection* dest);
extern void            GFL_G3DSysMtxSetProjection(G3DCameraProjection* projection);
extern void            GFL_G3DSysMtxGetViewLookAt(FxLookAt* dest);
extern void            GFL_G3DSysMtxSetViewLookAt(FxLookAt* lookat);
extern void            GFL_G3DSysMtxViewFlush();
extern void            GFL_G3DSysLightSet(GXLightID lightID, Light* light);
extern G3DResource*    GFL_G3DSysReadArcSysResource(int arcId, u16 datId);
extern G3DResource*    GFL_G3DSysReadArcToolResource(ArcTool* arcTool, u16 datId);
extern G3DResource*    GFL_G3DSysReadFSResource(const char* path, u16 datId);
extern void            GFL_G3DSysDrawObj(G3DActor* obj, SRTMatrix* mdlMtx);
extern void            GFL_G3DSysDrawObjBBoxCull(G3DActor* obj, SRTMatrix* mdlMtx);
extern void            GFL_G3DResFree(G3DResource* res);
extern void            GFL_G3DResSetup(G3DResource* res, NNSG3DResData* resData);
extern NNSG3DResData*  GFL_G3DResGetResData(G3DResource* res);
extern NNSG3DResTex*   GFL_G3DResGetTexData(G3DResource* res);
extern u32             GFL_G3DResGetTexVRAMHandle(G3DResource* res);
extern u32             GFL_G3DResGetPltVRAMHandle(G3DResource* res);
extern void*           GFL_G3DResGetTexImageData(G3DResource* res);
extern void*           GFL_G3DResGetTexPaletteData(G3DResource* res);
extern void            GFL_G3DResTrimTexData(G3DResource* res);
extern b32             GFL_G3DResAllocTexMem(NNSG3DResTex* tex, u32* pTexKey, u32* pTex4x4Key);
extern b32             GFL_G3DResAllocPltMem(NNSG3DResTex* tex, u32* pPltKey);
extern b32             GFL_G3DResIsTexNeedsUpload(G3DResource* res);
extern b32             GFL_G3DResUploadTexDataCore(G3DResource* res);
extern b32             GFL_G3DResUploadTexData(G3DResource* res);
extern b32             GFL_G3DResUploadAndReleaseTexData(G3DResource* res);
extern b32             GFL_G3DResFreeTexData(G3DResource* res);
extern G3DModel*       GFL_G3DMdlCreate(G3DResource* modelResource, u32 modelIdx, G3DResource* texResource);
extern G3DResource*    GFL_G3DMdlGetMdlResource(G3DModel* mdl);
extern G3DResource*    GFL_G3DMdlGetTexResource(G3DModel* mdl);
extern void*           GFL_G3DMdlGetRenderObj(G3DModel* mdl);
extern void            GFL_G3DMdlFree(G3DModel* mdl);
extern G3DAnim*        GFL_G3DAnmCreate(G3DModel* mdl, G3DResource* anmRsc, u8 anmIdx);
extern void*           GFL_G3DAnmGetRenderObj(G3DAnim* anm);
extern void            GFL_G3DAnmFree(G3DAnim* anm);
extern G3DActor*       GFL_G3DActorCreate(G3DModel* model, G3DAnim** animations, int animationsCount);
extern void            GFL_G3DActorFree(G3DActor* actor);
extern G3DModel*       GFL_G3DActorGetMdl(G3DActor* actor);
extern G3DAnim*        GFL_G3DActorGetAnm(G3DActor* actor, u8 anmIdx);
extern u16             GFL_G3DActorGetAnmCount(G3DActor* actor);
extern b32             GFL_G3DActorBindAnm(G3DActor* actor, u8 anmIdx);
extern b32             GFL_G3DActorUnbindAnm(G3DActor* actor, u8 anmIdx);
extern b32             GFL_G3DActorGetAnmFrameCount(G3DActor* actor, u8 anmIdx, fx32* dest);
extern b32             GFL_G3DActorResetAnmFrame(G3DActor* actor, u8 anmIdx);
extern b32             GFL_G3DActorGetAnmFrame(G3DActor* actor, u8 anmIdx, fx32* dest);
extern b32             GFL_G3DActorSetAnmFrame(G3DActor* actor, u8 anmIdx, fx32* frame);
extern b32             GFL_G3DActorStepAnmFrame(G3DActor* actor, u8 anmIdx, fx16 addend);
extern b32             GFL_G3DActorStepAnmFrameLoop(G3DActor* anmMdl, u8 anmIdx, fx16 addend);

C_DECL_END

struct G3DResource
{
    s16 			AllocState;
    s16 			ResourceType;
    NNSG3DResData*	ResourceData;
  
    #ifdef __cplusplus
  
    INLINE static gfl::g3d::Resource* Load(int arcId, u16 datId) {
        return GFL_G3DSysReadArcSysResource(arcId, datId);
    }

    INLINE static gfl::g3d::Resource* Load(ArcTool* arcTool, u16 datId) {
        return GFL_G3DSysReadArcToolResource(arcTool, datId);
    }

    INLINE static gfl::g3d::Resource* Load(const char* path, u16 datId) {
        return GFL_G3DSysReadFSResource(path, datId);
    }

    INLINE void Free() {
        GFL_G3DResFree(this);
    }

    INLINE void Setup(ns::g3d::res::Data* resData) {
        GFL_G3DResSetup(this, resData);
    }

    INLINE ns::g3d::res::Data* GetResData() {
        return GFL_G3DResGetResData(this);
    }

    #endif
};

struct G3DSystem
{
    void* Allocator;
    void* PaletteVRAMManager;
    void* TexVRAMManager;
    HeapID m_HeapID;
    s16 pad_heapId;
    G3DCameraProjection CameraProjection;
    Light Lights[4];
    FxLookAt CameraLookAt;
    b32 UseManualAlphaSort;
    b32 DepthBufferW;
    void* MtxFlushFunc;
    b32 IsVRAMFrameHeap;
    int dword90;
    b32 ReqSwapBuffers;
    G3DModelDrawCallback m_ModelDrawCallback;
    int dword9C;
  
    #ifdef __cplusplus
  
    INLINE static void Create(b32 useFrmHeapVramMgr, u32 numMgmtBlks, u32 dat3, u32 dat4, u16 dtcmAllocSize, HeapID heapId, G3DSystemInitCallback initCallback) {
        GFL_G3DSysCreate(useFrmHeapVramMgr, numMgmtBlks, dat3, dat4, dtcmAllocSize, heapId, initCallback);
    }

    INLINE static void Free() {
        GFL_G3DSysFree();
    }

    INLINE static void DrawObj(gfl::g3d::Actor* obj, gfl::g3d::Transform* mdlMtx) {
        GFL_G3DSysDrawObj(obj, mdlMtx);
    }

    INLINE static void DrawObjBBoxCull(gfl::g3d::Actor* obj, gfl::g3d::Transform* mdlMtx) {
        GFL_G3DSysDrawObjBBoxCull(obj, mdlMtx);
    }

    INLINE static void GetProjection(gfl::g3d::Projection* dest) {
        GFL_G3DSysMtxGetProjection(dest);
    }

    INLINE static void SetProjection(gfl::g3d::Projection* projection) {
        GFL_G3DSysMtxSetProjection(projection);
    }

    INLINE static void GetViewLookAt(FxLookAt* dest) {
        GFL_G3DSysMtxGetViewLookAt(dest);
    }

    INLINE static void SetViewLookAt(FxLookAt* lookat) {
        GFL_G3DSysMtxSetViewLookAt(lookat);
    }

    INLINE static void SetLight(GXLightID lightID, gfl::g3d::Light* light) {
        GFL_G3DSysLightSet(lightID, light);
    }

    INLINE static void FlushViewMatrix() {
        GFL_G3DSysMtxViewFlush();
    }

    #endif
};

#ifdef __cplusplus
struct gfl::g3d::Texture : public gfl::g3d::Resource {
    INLINE ns::g3d::res::TexData* GetTexData() {
        return GFL_G3DResGetTexData(this);
    }

    INLINE b32 FreeTexData() {
        return GFL_G3DResFreeTexData(this);
    }

    INLINE u32 GetTexVRAMHandle() {
        return GFL_G3DResGetTexVRAMHandle(this);
    }

    INLINE u32 GetPltVRAMHandle() {
        return GFL_G3DResGetPltVRAMHandle(this);
    }

    INLINE void* GetTexImageData() {
        return GFL_G3DResGetTexImageData(this);
    }

    INLINE void* GetPaletteImageData() {
        return GFL_G3DResGetTexPaletteData(this);
    }

    INLINE void TrimData() {
        GFL_G3DResTrimTexData(this);
    }

    INLINE b32 AllocTexMem(u32* pTexKey, u32* pTex4x4Key) {
        return GFL_G3DResAllocTexMem(GetTexData(), pTexKey, pTex4x4Key);
    }

    INLINE b32 AllocPltMem(u32* pPltKey) {
        return GFL_G3DResAllocPltMem(GetTexData(), pPltKey);
    }

    INLINE b32 IsNeedsUpload() {
        return GFL_G3DResIsTexNeedsUpload(this);
    }

    INLINE b32 UploadCore() {
        return GFL_G3DResUploadTexDataCore(this);
    }

    INLINE b32 Upload() {
        return GFL_G3DResUploadTexData(this);
    }

    INLINE b32 UploadAndRelease() {
        return GFL_G3DResUploadAndReleaseTexData(this);
    }

};
#endif //__cplusplus

struct G3DModel
{
    u16 		Magic;
    u16 		_padMagic;
    void*		RenderObj;
    G3DResource*	Model;
    G3DResource*	Textures;
  
    #ifdef __cplusplus
  
    INLINE static gfl::g3d::Model* Create(gfl::g3d::Resource* modelResource, u32 modelIdx, gfl::g3d::Resource* texResource) {
        return GFL_G3DMdlCreate(modelResource, modelIdx, texResource);
    }

    INLINE void Free() {
        GFL_G3DMdlFree(this);
    }

    INLINE gfl::g3d::Resource* GetMdlResource() {
        return GFL_G3DMdlGetMdlResource(this);
    }

    INLINE gfl::g3d::Resource* GetTexResource() {
        return GFL_G3DMdlGetTexResource(this);
    }

    INLINE void* GetRenderObj() {
        return GFL_G3DMdlGetRenderObj(this);
    }

    #endif
};

struct G3DAnim
{
    u16             Magic;
    u16             _padMagic;
    void*           AnmObj;
    G3DResource*    AnimRes;
  
    #ifdef __cplusplus
  
    INLINE static gfl::g3d::Animation* Create(gfl::g3d::Model* mdl, gfl::g3d::Resource* anmRsc, u8 anmIdx) {
        return GFL_G3DAnmCreate(mdl, anmRsc, anmIdx);
    }

    INLINE void Free() {
        GFL_G3DAnmFree(this);
    }

    INLINE void* GetRenderObj() {
        return GFL_G3DAnmGetRenderObj(this);
    }

    #endif
};

struct G3DActor
{
    G3DModel*     Model;
    G3DAnim**     Anims;
    u16           AnimCount;
    u16           Magic;
  
    #ifdef __cplusplus
  
    INLINE static gfl::g3d::Actor* Create(gfl::g3d::Model* model, gfl::g3d::Animation** animations, int animationsCount) {
        return GFL_G3DActorCreate(model, animations, animationsCount);
    }

    INLINE void Free() {
        GFL_G3DActorFree(this);
    }

    INLINE void Draw(gfl::g3d::Transform* mdlMtx) {
        GFL_G3DSysDrawObj(this, mdlMtx);
    }

    INLINE void DrawCullCheck(gfl::g3d::Transform* mdlMtx) {
        GFL_G3DSysDrawObjBBoxCull(this, mdlMtx);
    }

    INLINE gfl::g3d::Model* GetModel() {
        return GFL_G3DActorGetMdl(this);
    }

    INLINE u16 GetAnimationCount() {
        return GFL_G3DActorGetAnmCount(this);
    }

    INLINE gfl::g3d::Animation* GetAnimation(u8 anmIdx) {
        return GFL_G3DActorGetAnm(this, anmIdx);
    }

    INLINE b32 BindAnm(u8 anmIdx) {
        return GFL_G3DActorBindAnm(this, anmIdx);
    }

    INLINE b32 UnbindAnm(u8 anmIdx) {
        return GFL_G3DActorUnbindAnm(this, anmIdx);
    }

    INLINE b32 GetAnmFrameCount(u8 anmIdx, fx32* dest) {
        return GFL_G3DActorGetAnmFrameCount(this, anmIdx, dest);
    }

    INLINE b32 ResetAnmFrame(u8 anmIdx) {
        return GFL_G3DActorResetAnmFrame(this, anmIdx);
    }

    INLINE b32 GetAnmFrame(u8 anmIdx, fx32* dest) {
        return GFL_G3DActorGetAnmFrame(this, anmIdx, dest);
    }

    INLINE b32 SetAnmFrame(u8 anmIdx, fx32* frame) {
        return GFL_G3DActorSetAnmFrame(this, anmIdx, frame);
    }

    INLINE b32 StepAnmFrame(u8 anmIdx, fx16 addend) {
        return GFL_G3DActorStepAnmFrame(this, anmIdx, addend);
    }

    INLINE b32 StepAnmFrameLoop(u8 anmIdx, fx16 addend) {
        return GFL_G3DActorStepAnmFrameLoop(this, anmIdx, addend);
    }

    #endif
};

#endif //__GFL_G3D_SYSTEM_H
// Tchaikovsky code generator
