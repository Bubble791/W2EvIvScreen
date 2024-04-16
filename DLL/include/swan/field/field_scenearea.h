#ifndef __FIELD_SCENEAREA_H
#define __FIELD_SCENEAREA_H

#include "swantypes.h"

STRUCT_DECLARE(CameraAreaRect)
STRUCT_DECLARE(CameraAreaCircle)
STRUCT_DECLARE(CameraArea)
STRUCT_DECLARE(FieldDynCameraFunctions)
STRUCT_DECLARE(FieldSceneArea)

typedef b32 (*CameraAreaCollCheck)(FieldSceneArea*, CameraArea*, VecFx32*);
typedef void (*CameraAreaCalcFunc)(FieldSceneArea*, CameraArea*, VecFx32*);

#include "field/field_camera.h"
#include "field/fieldmap.h"
#include "math/vector.h"
#include "math/fixed.h"

struct CameraAreaRect
{
    u16 GridX;
    u16 GridZ;
    u16 GridW;
    u16 Unk1;
    u16 GridH;
    u16 Unk2;
    u16 Pitch1;
    u16 Yaw1;
    fx32 TZ1;
    u16 Pitch2;
    u16 Yaw2;
    fx32 TZ2;
    int ForbidDelayManager;
    VecFx32 TargetOffset1;
    VecFx32 TargetOffset2;
    fxangle FOV1;
    fxangle FOV2;
};

struct CameraAreaCircle
{
    u32 AngleStart;
    u32 AngleEnd;
    fx32 RadiusStart;
    fx32 RadiusEnd;
    fx32 X;
    fx32 Y;
    fx32 Z;
    s32 Pitch;
    int TZDist;
    VecFx32 CamTgt;
    VecFx32 CamPos;
};

struct CameraArea
{
    union
    {
        CameraAreaRect Rect;
        CameraAreaCircle Circle;
    };
    int Unk4;
    u16 CollCheckFunc;
    u16 StayFunc;
    u16 EnterFunc;
    u16 ExitFunc;
};

struct FieldDynCameraFunctions
{
    CameraAreaCollCheck* CollCheckFuncs;
    CameraAreaCalcFunc* CalcFuncs;
    u16 CollCheckFuncCount;
    u16 CalcFuncCount;
};

struct FieldSceneArea
{
    FieldCamera* m_FieldCamera;
    Field* m_Field;
    CameraArea* m_CameraData;
    FieldDynCameraFunctions* CameraFunctions;
    int CameraCount;
    int LastCamIdx;
    int IsCameraAreaEnable;
    int CurrentCamDataFlags;
};

#endif //__FIELD_SCENEAREA_H
// Tchaikovsky code generator
