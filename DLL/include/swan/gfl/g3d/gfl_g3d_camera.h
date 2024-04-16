#ifndef __GFL_G3D_CAMERA_H
#define __GFL_G3D_CAMERA_H

#include "swantypes.h"

STRUCT_DECLARE(G3DCameraProjection)
STRUCT_DECLARE(G3DCamera)

ENUM_DECLARE(G3DCameraProjectionMode)

enum G3DCameraProjectionMode
#ifdef __cplusplus
: u32
#endif
{
    G3DCAM_PROJECTION_PERSPECTIVE = 0x0,
    G3DCAM_PROJECTION_FRUSTUM = 0x1,
    G3DCAM_PROJECTION_ORTHO = 0x2,
};
SWAN_CPPTYPE_EX(gfl::g3d, ProjectionMode, G3DCameraProjectionMode)

SWAN_CPPTYPE_EX(gfl::g3d, Projection, G3DCameraProjection)
SWAN_CPPTYPE_EX(gfl::g3d, Camera, G3DCamera)
namespace gfl::g3d { struct CameraOrtho; }
namespace gfl::g3d { struct CameraPerspective; }

#include "math/fixed.h"
#include "math/vector.h"
#include "math/lookat.h"
#include "gfl/core/gfl_heap.h"

C_DECL_BEGIN

extern G3DCamera*              GFL_G3DCameraCreate(G3DCameraProjectionMode proj, fx32 param1, fx32 param2, fx32 param3, fx32 param4, fx32 near, fx32 far, fx32 ndcRangeOverride, VecFx32* position, VecFx32* upVector, VecFx32* target, HeapID heapId);
extern void                    GFL_G3DCameraFree(G3DCamera* cam);
extern void                    GFL_G3DCameraFlush(G3DCamera* cam);
extern void                    GFL_G3DCameraGetLookatPos(G3DCamera* cam, VecFx32* dest);
extern void                    GFL_G3DCameraSetLookatPos(G3DCamera* cam, VecFx32* vec);
extern void                    GFL_G3DCameraGetLookatUpVector(G3DCamera* cam, VecFx32* dest);
extern void                    GFL_G3DCameraSetLookatUpVector(G3DCamera* cam, VecFx32* upVector);
extern void                    GFL_G3DCameraGetLookatTarget(G3DCamera* cam, VecFx32* dest);
extern void                    GFL_G3DCameraSetLookatTarget(G3DCamera* cam, VecFx32* target);
extern G3DCameraProjectionMode GFL_G3DCameraGetProjectionType(G3DCamera* cam);
extern void                    GFL_G3DCameraGetProjectionZNear(G3DCamera* cam, fx32* dest);
extern void                    GFL_G3DCameraSetProjectionZNear(G3DCamera* cam, fx32* pZNear);
extern void                    GFL_G3DCameraSetProjectionZFar(G3DCamera* cam, fx32* pZFar);
extern void                    GFL_G3DCameraPerspectiveSetFOVSin(G3DCamera* cam, fx32 fovSin);
extern void                    GFL_G3DCameraPerspectiveGetFOVCos(G3DCamera* cam, fx32* dest);
extern void                    GFL_G3DCameraPerspectiveSetFOVCos(G3DCamera* cam, fx32 fovCos);
extern void                    GFL_G3DCameraOrthoGetTop(G3DCamera* cam, fx32* pTop);
extern void                    GFL_G3DCameraOrthoSetTop(G3DCamera* cam, fx32 top);
extern void                    GFL_G3DCameraOrthoGetBottom(G3DCamera* cam, fx32* pBottom);
extern void                    GFL_G3DCameraOrthoSetBottom(G3DCamera* cam, fx32 bottom);

C_DECL_END

struct G3DCameraProjection
{
    G3DCameraProjectionMode Type;
    fx32 Param1;
    fx32 Param2;
    fx32 Param3;
    fx32 Param4;
    fx32 ZNear;
    fx32 ZFar;
    fx32 NDCRangeOverride;
};

struct G3DCamera
{
    G3DCameraProjection Projection;
    FxLookAt LookAt;
  
    #ifdef __cplusplus
  
    INLINE static gfl::g3d::Camera* Create(gfl::g3d::ProjectionMode proj, fx32 param1, fx32 param2, fx32 param3, fx32 param4, fx32 near, fx32 far, fx32 ndcRangeOverride, math::Vec3* position, math::Vec3* upVector, math::Vec3* target, HeapID heapId) {
        return GFL_G3DCameraCreate(proj, param1, param2, param3, param4, near, far, ndcRangeOverride, position, upVector, target, heapId);
    }

    INLINE void Free() {
        GFL_G3DCameraFree(this);
    }

    INLINE void Flush() {
        GFL_G3DCameraFlush(this);
    }

    INLINE void GetEye(math::Vec3* dest) {
        GFL_G3DCameraGetLookatPos(this, dest);
    }

    INLINE void SetEye(math::Vec3* vec) {
        GFL_G3DCameraSetLookatPos(this, vec);
    }

    INLINE void GetUpVector(math::Vec3* dest) {
        GFL_G3DCameraGetLookatUpVector(this, dest);
    }

    INLINE void SetUpVector(math::Vec3* upVector) {
        GFL_G3DCameraSetLookatUpVector(this, upVector);
    }

    INLINE void GetTarget(math::Vec3* dest) {
        GFL_G3DCameraGetLookatTarget(this, dest);
    }

    INLINE void SetTarget(math::Vec3* target) {
        GFL_G3DCameraSetLookatTarget(this, target);
    }

    INLINE gfl::g3d::ProjectionMode GetProjectionType() {
        return GFL_G3DCameraGetProjectionType(this);
    }

    INLINE void GetZNear(fx32* dest) {
        GFL_G3DCameraGetProjectionZNear(this, dest);
    }

    INLINE void SetZNear(fx32* pZNear) {
        GFL_G3DCameraSetProjectionZNear(this, pZNear);
    }

    #endif
};

#ifdef __cplusplus
struct gfl::g3d::CameraOrtho : public gfl::g3d::Camera {
    INLINE void GetTop(fx32* pTop) {
        GFL_G3DCameraOrthoGetTop(this, pTop);
    }

    INLINE void SetTop(fx32 top) {
        GFL_G3DCameraOrthoSetTop(this, top);
    }

    INLINE void GetBottom(fx32* pBottom) {
        GFL_G3DCameraOrthoGetBottom(this, pBottom);
    }

    INLINE void SetBottom(fx32 bottom) {
        GFL_G3DCameraOrthoSetBottom(this, bottom);
    }

};
#endif //__cplusplus

#ifdef __cplusplus
struct gfl::g3d::CameraPerspective : public gfl::g3d::Camera {
    INLINE void GetFOVCos(fx32* dest) {
        GFL_G3DCameraPerspectiveGetFOVCos(this, dest);
    }

    INLINE void SetFOVCos(fx32 fovCos) {
        GFL_G3DCameraPerspectiveSetFOVCos(this, fovCos);
    }

    INLINE void SetFOVSin(fx32 fovSin) {
        GFL_G3DCameraPerspectiveSetFOVSin(this, fovSin);
    }

};
#endif //__cplusplus

#endif //__GFL_G3D_CAMERA_H
// Tchaikovsky code generator
