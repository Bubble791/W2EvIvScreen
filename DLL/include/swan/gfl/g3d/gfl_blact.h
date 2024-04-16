#ifndef __GFL_BLACT_H
#define __GFL_BLACT_H

#include "swantypes.h"

STRUCT_DECLARE(BlActSystem)
STRUCT_DECLARE(BlActTexMatMapEntry)
STRUCT_DECLARE(BlActSceneConfig)
STRUCT_DECLARE(BlActScene)
STRUCT_DECLARE(BlActMaterial)
STRUCT_DECLARE(BlAct)
STRUCT_DECLARE(BlActHandle)

ENUM_DECLARE(BlActOrigin)
ENUM_DECLARE(BlActMaterialFlag)
ENUM_DECLARE(BlActPixelFormat)
ENUM_DECLARE(BlActFaceSize)
ENUM_DECLARE(BlActTexLoadMode)
ENUM_DECLARE(BlActBillboardType)

typedef b32 (*BlActVRAMUploadFunc)(b32, u32, void*, size_t);

enum BlActOrigin
#ifdef __cplusplus
: u32
#endif
{
    BL_ORIGIN_CENTER = 0x0,
    BL_ORIGIN_CX_TOP = 0x1,
    BL_ORIGIN_CX_BOTTOM = 0x2,
    BL_ORIGIN_CY_LEFT = 0x3,
    BL_ORIGIN_CY_RIGHT = 0x4,
    BL_ORIGIN_TOP_LEFT = 0x5,
    BL_ORIGIN_TOP_RIGHT = 0x6,
    BL_ORIGIN_BOTTOM_LEFT = 0x7,
    BL_ORIGIN_BOTTOM_RIGHT = 0x8,
};

enum BlActMaterialFlag
#ifdef __cplusplus
: u32
#endif
{
    BL_MATFLAG_ALPHA_MASK = 0x1F,
    BL_MATFLAG_NODRAW = 0x200,
    BL_MATFLAG_POLYID_MASK = 0x3E0,
    BL_MATFLAG_TEX_RIGHT_TO_LEFT = 0x400,
    BL_MATFLAG_TEX_TOP_TO_BOTTOM = 0x800,
    BL_MATFLAG_LIGHT_MASK = 0xF000,
};

enum BlActPixelFormat
#ifdef __cplusplus
: u32
#endif
{
    BL_PIXFMT_IDX4 = 0x0,
    BL_PIXFMT_IDX8 = 0x1,
    BL_PIXFMT_IDX2 = 0x2,
    BL_PIXFMT_A3I5 = 0x3,
    BL_PIXFMT_A5I3 = 0x4,
    BL_PIXFMT_MAX = 0x5,
};

enum BlActFaceSize
#ifdef __cplusplus
: u32
#endif
{
    BL_FACESIZE_32x32 = 0x0,
    BL_FACESIZE_16x16 = 0x1,
    BL_FACESIZE_64x64 = 0x2,
};

enum BlActTexLoadMode
#ifdef __cplusplus
: u32
#endif
{
    BL_LOAD_DISCARD = 0x0,
    BL_LOAD_TRIM = 0x1,
    BL_LOAD_KEEP = 0x2,
    BL_LOAD_SINGLE_USE = 0xFFFFFFFF,
};

enum BlActBillboardType
#ifdef __cplusplus
: u32
#endif
{
    BL_TYPE_CAM_XYZ = 0x0,
    BL_TYPE_CAM_XZ = 0x1,
    BL_TYPE_CAM_IDENTITY = 0x2,
    BL_TYPE_CAM_XZ_GEOM_XZ = 0x3,
};

#include "nds/gx.h"
#include "math/fixed.h"
#include "math/vector.h"
#include "gfl/core/gfl_heap.h"
#include "gfl/core/gfl_areaman.h"
#include "gfl/g3d/gfl_g3d_system.h"

struct BlActSystem
{
    HeapID m_HeapID;
    u16 _padHeapID;
    BlActScene* Scene;
    BlActVRAMUploadFunc VRAMUploadFunc;
    BlActTexMatMapEntry* TexMatMap;
    u16 MaterialCount;
    u16 _padMaterialCount;
    AreaMan* MaterialAllocMgr;
    BlActHandle* ActorHandles;
    u16 ActorCount;
    u16 _padActorCount;
    AreaMan* ActorAllocMgr;
};

struct BlActTexMatMapEntry
{
    u16 MatIdx;
    u16 _padMatIdx;
    G3DResource* TexResource;
};

struct BlActSceneConfig
{
    u16 MaterialCount;
    u16 ActorCount;
    VecFx32 AllScale;
    GXColor ColDiffuse;
    GXColor ColAmbient;
    GXColor ColSpecular;
    GXColor ColEmissive;
    u8 BasePolygonID;
    u8 Origin;
    u16 _padOrigin;
};

struct BlActScene
{
    HeapID m_HeapID;
    u16 _padHeapID;
    BlActMaterial* Materials;
    BlAct* Actors;
    BlActSceneConfig Config;
    b32 IsViewMtxNoLoad;
    b32 IsCustomNormal;
    VecFx16 CustomNormal;
    s16 TexcoordXOffset;
    s16 TexcoordYOffset;
    u16 _padding;
};

struct BlActMaterial
{
    G3DResource* TexResource;
    u16 TexAtlasDimX;
    u16 TexAtlasDimY;
    u8 TexFaceDimX;
    u8 TexFaceDimY;
    u8 FacesPerRow;
    u8 FacesPerColumn;
    u32 TexAddr;
    u32 PltAddr;
    GEPixelFormat TexFormat;
    u32 TexDimXBits;
    u32 TexDimYBits;
    u32 TexVRAMHandle;
    u32 PltVRAMHandle;
};

struct BlAct
{
    u16 GeomFlags;
    u16 _padGeomFlags;
    VecFx32 Position;
    u16 FaceIdx;
    s16 ScaleX;
    s16 Scale2;
    u16 RotationY;
    u16 MatFlags;
    u16 _padMatFlags;
};

struct BlActHandle
{
    u32 BlActIdx;
    u16 MatEntryIdx;
    u16 field_6;
    u32 field_8;
    u16 field_C;
    u16 field_E;
    u32 field_10;
    u16 field_14;
    u16 field_16;
    u32 field_18;
    u16 field_1C;
    u16 field_1E;
    void* Callback;
    void* CallbackData;
};

#endif //__GFL_BLACT_H
// Tchaikovsky code generator
