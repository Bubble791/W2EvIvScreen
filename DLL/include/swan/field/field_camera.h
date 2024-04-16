#ifndef __FIELD_CAMERA_H
#define __FIELD_CAMERA_H

#include "swantypes.h"

STRUCT_DECLARE(FieldEvCameraAnimationCoords)
STRUCT_DECLARE(FieldEvCameraAnimationFlags)
STRUCT_DECLARE(FieldEvCameraAnimationState)
STRUCT_DECLARE(FieldEvCameraAnimationSetup)
STRUCT_DECLARE(FieldEvCameraAnimation)
STRUCT_DECLARE(FieldEvCameraAnimationHandler)
STRUCT_DECLARE(CameraDelayManager)
STRUCT_DECLARE(FieldCamera)

ENUM_DECLARE(FieldCameraTransformType)

typedef void (*FieldCameraAnimatorFunc)(FieldCamera* fldCam);

enum FieldCameraTransformType
#ifdef __cplusplus
: u32
#endif
{
    FLDCAM_TARGET_REL = 0x0,
    FLDCAM_CAMERA_REL = 0x1,
    FLDCAM_FULL_ABS = 0x2,
};

#include "field/field_camera_boundary.h"
#include "math/vector.h"
#include "math/fixed.h"
#include "field/field_camera.h"
#include "gfl/fs/gfl_archive.h"
#include "gfl/g3d/gfl_g3d_camera.h"
#include "math/angle.h"

struct FieldEvCameraAnimationCoords
{
    VecFx32 CameraPos;
    VecFx32 TargetPos;
    VecFx32 ExtraTranslation;
    fxangle Pitch;
    fxangle Yaw;
    fx32 Distance;
    fxangle FOV;
    u16 _padFOV;
};

struct FieldEvCameraAnimationFlags
{
    b32 AnimateExtraTranslation;
    b32 AnimatePitch;
    b32 AnimateYaw;
    b32 AnimateTargetDistance;
    b32 AnimateFOV;
    b32 AnimateTargetPos;
};

struct FieldEvCameraAnimationState
{
    u16 FrameCount;
    u16 NowFrame;
    b32 IsEvCameraUsed;
    b32 IsRunning;
    FieldEvCameraAnimationFlags Flags;
};

struct FieldEvCameraAnimationSetup
{
    FieldEvCameraAnimationCoords TargetCoords;
    FieldEvCameraAnimationFlags Flags;
};

struct FieldEvCameraAnimation
{
    FieldEvCameraAnimationCoords TargetCoords;
    FieldEvCameraAnimationState State;
};

struct FieldEvCameraAnimationHandler
{
    u32 BackupTransformFuncIdx;
    FieldEvCameraAnimationCoords BackupCoords;
    FieldEvCameraAnimationCoords InitCoords;
    FieldEvCameraAnimation Animation;
};

struct CameraDelayManager
{
    u32 DelayMax;
    u32 ReadIdx;
    u32 WriteIdx;
    u32 ReadWriteDelay;
    b32 DelayReadIsReady;
    b32 NoDelayX;
    b32 NoDelayY;
    b32 NoDelayZ;
    VecFx32* TargetVectors;
    VecFx32* CamPosVectors;
    b32 IsRunningDelay;
    b32 WriteDisabled;
};

struct FieldCamera
{
    HeapID m_HeapID;
    u16 _PaddingHeapID;
    ArcTool* DefaultCamArc;
    ArcTool* CameraBoundaryArc;
    G3DCamera* m_G3DCamera;
    u32 DefaultCameraIdx;
    FieldCameraTransformType TransformType;
    VecFx32* PlayerBaseTranslation;
    VecFx32* BaseTranslation;
    VecFx32* AbsCamPosPtr;
    VecFx32 FixedCameraTranslation;
    VecFx32 CamPosOffset;
    VecFx32 CalcEyePos;
    VecFx32 FixedTargetTranslation;
    VecFx32 CalcTargetPos;
    VecFx32 TargetPosOffset;
    VecFx32 TargetPosBase;
    fxangle Pitch;
    fxangle Yaw;
    s32 TZDist;
    fxangle FOV;
    u16 AngleTgtEye;
    u16 field_84;
    u16 field_86;
    CameraBoundary CameraBoundaryBuffer[4];
    u8 CameraBoundaryCount;
    u8 UseCameraBoundaries;
    u16 CamBoundIdx;
    CameraDelayManager* CamDelayManager;
    FieldEvCameraAnimationHandler Animator;
    u32 field_1A8;
    FieldCameraAnimatorFunc AnimatorFunction;
};

#endif //__FIELD_CAMERA_H
// Tchaikovsky code generator
