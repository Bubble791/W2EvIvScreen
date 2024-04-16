#ifndef __GFL_BG_SYS_H
#define __GFL_BG_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(BGHandler)
STRUCT_DECLARE(BGSys)
STRUCT_DECLARE(BGSetup)
STRUCT_DECLARE(BGSysLCDConfig)
STRUCT_DECLARE(BGSysVRAMConfig)

ENUM_DECLARE(BGResolution)
ENUM_DECLARE(BGOperationMode)
ENUM_DECLARE(BGMoveType)
ENUM_DECLARE(BGTransformCommand)

enum BGResolution
#ifdef __cplusplus
: u32
#endif
{
    BGRES_128x128 = 0x0,
    BGRES_256x256 = 0x1,
    BGRES_256x512 = 0x2,
    BGRES_512x256 = 0x3,
    BGRES_512x512 = 0x4,
    BGRES_1024x1024 = 0x5,
};

enum BGOperationMode
#ifdef __cplusplus
: u32
#endif
{
    BGMODE_TEXT = 0x0,
    BGMODE_AFFINE = 0x1,
    BGMODE_EXTENDED = 0x2,
};

enum BGMoveType
#ifdef __cplusplus
: u32
#endif
{
    BG_MOVE_SET_X = 0x0,
    BG_MOVE_RIGHT = 0x1,
    BG_MOVE_LEFT = 0x2,
    BG_MOVE_SET_Y = 0x3,
    BG_MOVE_DOWN = 0x4,
    BG_MOVE_UP = 0x5,
};

enum BGTransformCommand
#ifdef __cplusplus
: u32
#endif
{
    BG_ROTATE_SET = 0x0,
    BG_ROTATE_RIGHT = 0x1,
    BG_ROTATE_LEFT = 0x2,
    BG_SCALE_SET_X = 0x3,
    BG_SCALE_UP_X = 0x4,
    BG_SCALE_DOWN_X = 0x5,
    BG_SCALE_SET_Y = 0x6,
    BG_SCALE_UP_Y = 0x7,
    BG_SCALE_DOWN_Y = 0x8,
    BG_ORIGIN_SET_X = 0x9,
    BG_ORIGIN_INC_X = 0xA,
    BG_ORIGIN_DEC_X = 0xB,
    BG_ORIGIN_SET_Y = 0xC,
    BG_ORIGIN_INC_Y = 0xD,
    BG_ORIGIN_DEC_Y = 0xE,
};

#include "gfl/core/gfl_heap.h"
#include "gfl/core/gfl_areaman.h"
#include "math/fixed.h"
#include "math/angle.h"
#include "nds/gx.h"

C_DECL_BEGIN

extern void                GFL_BGSysCreate(HeapID heapId);
extern void                GFL_BGSysFree();
extern u32                 GFL_BGSysAllocChar(G2DBG bg, size_t size, b32 tail);
extern b32                 GFL_BGSysAllocCharAt(G2DBG bg, u32 offset, size_t size);
extern void                GFL_BGSysFreeCharMemory(G2DBG bg, u32 offset, size_t size);
extern void                GFL_BGSysSetLCDConfig(const BGSysLCDConfig* cfg);
extern void                GFL_BGSysSetLCDConfigForEngine(const BGSysLCDConfig* config, G2DEngine engine);
extern u32                 GFL_BGSysCreateBG(G2DBG bg, BGSetup* setup, BGOperationMode mode);
extern void                GFL_BGSysReleaseBG(G2DBG bg);
extern void                GFL_BGSysSet3DBGPriority(u16 priority);
extern void                GFL_BGSysSetBGPriority(G2DBG bg, u16 priority);
extern void                GFL_BGSysSetBGEnabled(G2DBG bg, b32 enable);
extern void                GFL_BGSysMoveBG(G2DBG bg, BGMoveType type, u32 value);
extern int                 GFL_BGSysGetBGOffsetX(G2DBG bg);
extern u32                 GFL_BGSysGetBGOffsetY(G2DBG bg);
extern void                GFL_BGSysSetBGTransformEx(G2DBG bg, BGMoveType type, u32 value, Mat2* matrix, int originX, int originY);
extern void                GFL_BGSysSetBGTransform(G2DBG bg, Mat2* matrix, int originX, int originY);
extern void                GFL_BGSysTransferUncomp(void* src, void* dest, u32 size);
extern void                GFL_BGSysLoadScr(G2DBG bg);
extern void                GFL_BGSysLoadScrCore(G2DBG bg, void* src, size_t size, u32 offset);
extern void                GFL_BGSysBufferScrDefault(G2DBG bg, void* data, size_t size);
extern void                GFL_BGSysBufferScr(G2DBG bg, void* data, size_t size, u32 destOffset);
extern void                GFL_BGSysLoadChar(G2DBG bg, void* data, size_t size, u32 offset);
extern u32                 GFL_BGSysLoadCharDynamic(G2DBG bg, void* data, size_t size);
extern void                GFL_BGSysClearCharCore(G2DBG bg, size_t size, u32 offset, HeapID heapId);
extern void                GFL_BGSysFillChar(G2DBG bg, u32 fillIndex, u32 tileCount, u32 offset);
extern void                GFL_BGSysFreeFilledChar(G2DBG bg, u32 sizeTiles, u32 offset);
extern void                GFL_BGSysUploadStdPalette(G2DBG bg, void* palette, size_t paletteSize, u32 destOffset);
extern void                GFL_BGSysResetStdPalette(G2DBG bg);
extern u32                 GFL_BGSysConvCoordsToTileIndex(u32 x, u32 y, BGResolution res);
extern u32                 GFL_BGSysConvCoordsToTileIndexEx(u32 x, u32 y, u32 width, u32 height);
extern void                GFL_BGSysLoadScrAreaAll(G2DBG bg, u16* src, u8 dstX, u8 dstY, u8 width, u8 height);
extern void                GFL_BGSysLoadScrArea(G2DBG bg, u8 dstX, u8 dstY, u8 width, u8 height, u16* src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight);
extern void                GFL_BGSysLoadScrAreaLarge(G2DBG bg, u8 dstX, u8 dstY, u8 width, u8 height, u16* src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight);
extern void                GFL_BGSysFillScrArea(G2DBG bg, u16 tile, u32 startX, u32 startY, u8 width, u8 height, u8 palette);
extern void                GFL_BGSysSetScrPaletteNo(G2DBG bg, u32 startX, u32 startY, u32 width, u32 height, u8 paletteNumber);
extern void                GFL_BGSysClearBG(G2DBG bg);
extern void                GFL_BGSysClearChar(G2DBG bg);
extern void                GFL_BGSysClearScr(G2DBG bg);
extern void                GFL_BGSysFillScr(G2DBG bg, u16 map);
extern void                GFL_BGSysFillScrAsync(G2DBG bg, u16 map);
extern void*               GFL_BGSysGetBGCharAddress(G2DBG bg);
extern void*               GFL_BGSysIsScrHeapExists(G2DBG bg);
extern u32                 GFL_BGSysGetBGOffsetX2(G2DBG bg);
extern u32                 GFL_BGSysGetBGOffsetY2(G2DBG bg);
extern BGOperationMode     GFL_BGSysGetBGMode(G2DBG bg);
extern G2DColorPaletteMode GFL_BGSysGetBGColorPaletteMode(G2DBG bg);
extern u32                 GFL_BGSysGetBGBytesPerTile(G2DBG bg);
extern u32                 GFL_BGSysGetBGPriority(G2DBG bg);
extern void                GFL_BGSysUpdate();
extern void                GFL_BGSysLoadQueuedScreens();
extern void                GFL_BGSysQueueScrLoad(G2DBG bg);
extern void                GFL_BGSysFlushTransform();
extern void                GFL_BGSysMoveBGReq(G2DBG bg, BGMoveType type, u32 value);
extern void                GFL_BGSysRotateBGReq(G2DBG bgIndex, BGTransformCommand type, s16 value);
extern void                GFL_BGSysScaleBGReq(G2DBG bg, BGTransformCommand type, s32 value);
extern void                GFL_BGSysAdjustBGOriginReq(G2DBG bg, BGTransformCommand type, s32 value);
extern G2DBGScreenSize     GFL_BGSysCalcScreenSizeMode(BGResolution res, BGOperationMode mode);
extern void                GFL_BGSysGetTileDimensions(BGResolution res, u8* pTileWidth, u8* pTileHeight);
extern void                GFL_BGSysAdjustBGMoveCoord(BGHandler* bg, BGMoveType type, u32 value);
extern void                GFL_BGSysSetBGTransformIdentity(G2DBG bg);
extern void                GFL_BGSysUploadScr(G2DBG bg, void* data, u32 offset, size_t size);
extern void                GFL_BGSysLoadCharCore(G2DBG bg, void* data, size_t size, u32 offset);
extern void                GFL_BGSysUploadChar(G2DBG bg, void* data, u32 offset, size_t size);
extern u32                 GFL_BGSysAllocScreen(G2DBG bg, u32 offset, size_t size);
extern void                GFL_BGSysFreeScreenMemory(G2DBG bg, u32 offset, size_t size);
extern BGHandler*          GFL_BGSysAdjustBGRotateCoord(BGHandler* bg, BGTransformCommand type, s16 value);
extern void                GFL_BGSysAdjustBGScaleCoord(BGHandler* bg, BGTransformCommand type, s32 value);
extern void                GFL_BGSysAdjustBGOriginCoord(BGHandler* bg, BGTransformCommand type, s32 value);
extern void                GFL_BGSysInitVRAM(VRAMBankMask banks);
extern void                GFL_BGSysSetVRAMBanks(const BGSysVRAMConfig* banks);
extern void                GFL_BGSysDisableOBJA();
extern void                GFL_BGSysDisableBGsA();
extern void                GFL_BGSysDisableAllA();
extern void                GFL_BGSysSetBGEnabledA(G2DScreenBGBit mask, b32 enable);
extern void                GFL_BGSysSetEnabledBGsA(G2DScreenBGBit display);
extern void                GFL_BGSysDisableBGsB();
extern void                GFL_BGSysDisableOBJB();
extern void                GFL_BGSysDisableAllB();
extern void                GFL_BGSysSetBGEnabledB(G2DScreenBGBit display, bool enable);
extern void                GFL_BGSysSetEnabledBGsB(G2DScreenBGBit display);
extern void                GFL_BGSysEnableEngines();
extern void                GFL_BGSysSetDisplayLayout(G2DDisplayLayout layout);
extern G2DScreenBGBit      GFL_BGSysGetEnabledBGsA();
extern G2DScreenBGBit      GFL_BGSysGetEnabledBGsB();

C_DECL_END

struct BGHandler
{
    void* ScreenData;
    u32 ScreenDataSize;
    u32 ScreenOffset;
    u32 OffsetX;
    u32 OffsetY;
    u8 BGMode;
    u8 Resolution;
    u8 ColorPaletteMode;
    u8 BytesPerTile;
    fxangle Rotation;
    u16 _padRotation;
    fx32 ScaleX;
    fx32 ScaleY;
    u32 OriginX;
    u32 OriginY;
};

struct BGSys
{
    HeapID m_HeapID;
    u16 _padHeapID;
    u16 TransformDirtyFlags;
    u16 ReqLoadScreens;
    BGHandler BGs[8];
    AreaMan* EngineAArea;
    AreaMan* EngineBArea;
    u32 CharBases[8];
    u32 ScreenBases[8];
    u32 CharSizes[8];
  
    #ifdef __cplusplus
  
    INLINE static void Create(HeapID heapId) {
        GFL_BGSysCreate(heapId);
    }

    INLINE static void Free() {
        GFL_BGSysFree();
    }

    INLINE static u32 AllocChar(G2DBG bg, size_t size, b32 tail) {
        return GFL_BGSysAllocChar(bg, size, tail);
    }

    INLINE static b32 AllocCharAt(G2DBG bg, u32 offset, size_t size) {
        return GFL_BGSysAllocCharAt(bg, offset, size);
    }

    INLINE static void FreeCharMemory(G2DBG bg, u32 offset, size_t size) {
        GFL_BGSysFreeCharMemory(bg, offset, size);
    }

    INLINE static u32 CreateBG(G2DBG bg, BGSetup* setup, BGOperationMode mode) {
        return GFL_BGSysCreateBG(bg, setup, mode);
    }

    INLINE static void ReleaseBG(G2DBG bg) {
        GFL_BGSysReleaseBG(bg);
    }

    INLINE static void MoveBG(G2DBG bg, BGMoveType type, u32 value) {
        GFL_BGSysMoveBG(bg, type, value);
    }

    INLINE static int GetBGOffsetX(G2DBG bg) {
        return GFL_BGSysGetBGOffsetX(bg);
    }

    INLINE static u32 GetBGOffsetY(G2DBG bg) {
        return GFL_BGSysGetBGOffsetY(bg);
    }

    INLINE static void SetBGTransform(G2DBG bg, Mat2* matrix, int originX, int originY) {
        GFL_BGSysSetBGTransform(bg, matrix, originX, originY);
    }

    INLINE static void SetBGTransformEx(G2DBG bg, BGMoveType type, u32 value, Mat2* matrix, int originX, int originY) {
        GFL_BGSysSetBGTransformEx(bg, type, value, matrix, originX, originY);
    }

    INLINE static void TransferUncomp(void* src, void* dest, u32 size) {
        GFL_BGSysTransferUncomp(src, dest, size);
    }

    INLINE static void LoadScr(G2DBG bg) {
        GFL_BGSysLoadScr(bg);
    }

    INLINE static void LoadScrCore(G2DBG bg, void* src, size_t size, u32 offset) {
        GFL_BGSysLoadScrCore(bg, src, size, offset);
    }

    INLINE static void BufferScrDefault(G2DBG bg, void* data, size_t size) {
        GFL_BGSysBufferScrDefault(bg, data, size);
    }

    INLINE static void BufferScr(G2DBG bg, void* data, size_t size, u32 destOffset) {
        GFL_BGSysBufferScr(bg, data, size, destOffset);
    }

    INLINE static void LoadChar(G2DBG bg, void* data, size_t size, u32 offset) {
        GFL_BGSysLoadChar(bg, data, size, offset);
    }

    INLINE static u32 LoadCharDynamic(G2DBG bg, void* data, size_t size) {
        return GFL_BGSysLoadCharDynamic(bg, data, size);
    }

    INLINE static void ClearCharCore(G2DBG bg, size_t size, u32 offset, HeapID heapId) {
        GFL_BGSysClearCharCore(bg, size, offset, heapId);
    }

    INLINE static void FillChar(G2DBG bg, u32 fillIndex, u32 tileCount, u32 offset) {
        GFL_BGSysFillChar(bg, fillIndex, tileCount, offset);
    }

    INLINE static void FreeFilledChar(G2DBG bg, u32 sizeTiles, u32 offset) {
        GFL_BGSysFreeFilledChar(bg, sizeTiles, offset);
    }

    INLINE static u32 ConvCoordsToTileIndex(u32 x, u32 y, BGResolution res) {
        return GFL_BGSysConvCoordsToTileIndex(x, y, res);
    }

    INLINE static u32 ConvCoordsToTileIndexEx(u32 x, u32 y, u32 width, u32 height) {
        return GFL_BGSysConvCoordsToTileIndexEx(x, y, width, height);
    }

    INLINE static void LoadScrAreaAll(G2DBG bg, u16* src, u8 dstX, u8 dstY, u8 width, u8 height) {
        GFL_BGSysLoadScrAreaAll(bg, src, dstX, dstY, width, height);
    }

    INLINE static void LoadScrArea(G2DBG bg, u8 dstX, u8 dstY, u8 width, u8 height, u16* src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight) {
        GFL_BGSysLoadScrArea(bg, dstX, dstY, width, height, src, srcX, srcY, srcWidth, srcHeight);
    }

    INLINE static void LoadScrAreaLarge(G2DBG bg, u8 dstX, u8 dstY, u8 width, u8 height, u16* src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight) {
        GFL_BGSysLoadScrAreaLarge(bg, dstX, dstY, width, height, src, srcX, srcY, srcWidth, srcHeight);
    }

    INLINE static void FillScrArea(G2DBG bg, u16 tile, u32 startX, u32 startY, u8 width, u8 height, u8 palette) {
        GFL_BGSysFillScrArea(bg, tile, startX, startY, width, height, palette);
    }

    INLINE static void SetScrPaletteNo(G2DBG bg, u32 startX, u32 startY, u32 width, u32 height, u8 paletteNumber) {
        GFL_BGSysSetScrPaletteNo(bg, startX, startY, width, height, paletteNumber);
    }

    INLINE static void ClearBG(G2DBG bg) {
        GFL_BGSysClearBG(bg);
    }

    INLINE static void ClearChar(G2DBG bg) {
        GFL_BGSysClearChar(bg);
    }

    INLINE static void ClearScr(G2DBG bg) {
        GFL_BGSysClearScr(bg);
    }

    INLINE static void FillScr(G2DBG bg, u16 map) {
        GFL_BGSysFillScr(bg, map);
    }

    INLINE static void FillScrAsync(G2DBG bg, u16 map) {
        GFL_BGSysFillScrAsync(bg, map);
    }

    INLINE static void* IsScrHeapExists(G2DBG bg) {
        return GFL_BGSysIsScrHeapExists(bg);
    }

    INLINE static BGOperationMode GetBGMode(G2DBG bg) {
        return GFL_BGSysGetBGMode(bg);
    }

    INLINE static G2DColorPaletteMode GetBGColorPaletteMode(G2DBG bg) {
        return GFL_BGSysGetBGColorPaletteMode(bg);
    }

    INLINE static u32 GetBGBytesPerTile(G2DBG bg) {
        return GFL_BGSysGetBGBytesPerTile(bg);
    }

    INLINE static u32 GetBGPriority(G2DBG bg) {
        return GFL_BGSysGetBGPriority(bg);
    }

    INLINE static void Update() {
        GFL_BGSysUpdate();
    }

    INLINE static void LoadQueuedScreens() {
        GFL_BGSysLoadQueuedScreens();
    }

    INLINE static void QueueScrLoad(G2DBG bg) {
        GFL_BGSysQueueScrLoad(bg);
    }

    INLINE static void FlushTransform() {
        GFL_BGSysFlushTransform();
    }

    INLINE static void MoveBGReq(G2DBG bg, BGMoveType type, u32 value) {
        GFL_BGSysMoveBGReq(bg, type, value);
    }

    INLINE static void RotateBGReq(G2DBG bgIndex, BGTransformCommand type, s16 value) {
        GFL_BGSysRotateBGReq(bgIndex, type, value);
    }

    INLINE static void ScaleBGReq(G2DBG bg, BGTransformCommand type, s32 value) {
        GFL_BGSysScaleBGReq(bg, type, value);
    }

    INLINE static void AdjustBGOriginReq(G2DBG bg, BGTransformCommand type, s32 value) {
        GFL_BGSysAdjustBGOriginReq(bg, type, value);
    }

    INLINE static G2DBGScreenSize CalcScreenSizeMode(BGResolution res, BGOperationMode mode) {
        return GFL_BGSysCalcScreenSizeMode(res, mode);
    }

    INLINE static void GetTileDimensions(BGResolution res, u8* pTileWidth, u8* pTileHeight) {
        GFL_BGSysGetTileDimensions(res, pTileWidth, pTileHeight);
    }

    INLINE static void AdjustBGMoveCoord(BGHandler* bg, BGMoveType type, u32 value) {
        GFL_BGSysAdjustBGMoveCoord(bg, type, value);
    }

    INLINE static void SetBGTransformIdentity(G2DBG bg) {
        GFL_BGSysSetBGTransformIdentity(bg);
    }

    INLINE static void UploadScr(G2DBG bg, void* data, u32 offset, size_t size) {
        GFL_BGSysUploadScr(bg, data, offset, size);
    }

    INLINE static void LoadCharCore(G2DBG bg, void* data, size_t size, u32 offset) {
        GFL_BGSysLoadCharCore(bg, data, size, offset);
    }

    INLINE static void UploadChar(G2DBG bg, void* data, u32 offset, size_t size) {
        GFL_BGSysUploadChar(bg, data, offset, size);
    }

    INLINE static u32 AllocScreen(G2DBG bg, u32 offset, size_t size) {
        return GFL_BGSysAllocScreen(bg, offset, size);
    }

    INLINE static void FreeScreenMemory(G2DBG bg, u32 offset, size_t size) {
        GFL_BGSysFreeScreenMemory(bg, offset, size);
    }

    INLINE static BGHandler* AdjustBGRotateCoord(BGHandler* bg, BGTransformCommand type, s16 value) {
        return GFL_BGSysAdjustBGRotateCoord(bg, type, value);
    }

    INLINE static void AdjustBGScaleCoord(BGHandler* bg, BGTransformCommand type, s32 value) {
        GFL_BGSysAdjustBGScaleCoord(bg, type, value);
    }

    INLINE static void AdjustBGOriginCoord(BGHandler* bg, BGTransformCommand type, s32 value) {
        GFL_BGSysAdjustBGOriginCoord(bg, type, value);
    }

    #endif
};

struct BGSetup
{
    u32 PosX;
    u32 PosY;
    u32 ScreenSize;
    u32 ScreenOffset;
    u8 Resolution;
    u8 ColorsPalettes;
    u8 ScreenBaseBlock;
    u8 CharBaseBlock;
    u32 CharBlockSize;
    u8 ExtPaletteSlot;
    u8 Priority;
    u8 DisplayAreaOverflow;
    u8 _padDisplayAreaOverflow;
    u32 Mosaic;
};

struct BGSysLCDConfig
{
    G2DDisplayMode DisplayModeA;
    G2DBGMode BGModeA;
    G2DBGMode BGModeB;
    b32 IsBG03D;
};

struct BGSysVRAMConfig
{
    VRAMBankMask BGBanksA;
    VRAMBankMask BGExtPltBanksA;
    VRAMBankMask BGBanksB;
    VRAMBankMask BGExtPltBanksB;
    VRAMBankMask ObjBanksA;
    VRAMBankMask ObjExtPltBanksA;
    VRAMBankMask ObjBanksB;
    VRAMBankMask ObjExtPltBanksB;
    VRAMBankMask TexBanks;
    VRAMBankMask PltBanks;
    u32 TileOBJDISPCNTA;
    u32 TileOBJDISPCNTB;
};

#ifdef __cplusplus
namespace gfl::g2d {

  INLINE void SetLCDConfig(const BGSysLCDConfig* cfg) {
    GFL_BGSysSetLCDConfig(cfg);
  }

  INLINE void SetLCDConfigForEngine(const BGSysLCDConfig* config, G2DEngine engine) {
    GFL_BGSysSetLCDConfigForEngine(config, engine);
  }

  INLINE void Set3DBGPriority(u16 priority) {
    GFL_BGSysSet3DBGPriority(priority);
  }

  INLINE void SetBGPriority(G2DBG bg, u16 priority) {
    GFL_BGSysSetBGPriority(bg, priority);
  }

  INLINE void SetBGEnabled(G2DBG bg, b32 enable) {
    GFL_BGSysSetBGEnabled(bg, enable);
  }

  INLINE void UploadStdPalette(G2DBG bg, void* palette, size_t paletteSize, u32 destOffset) {
    GFL_BGSysUploadStdPalette(bg, palette, paletteSize, destOffset);
  }

  INLINE void ResetStdPalette(G2DBG bg) {
    GFL_BGSysResetStdPalette(bg);
  }

  INLINE void InitVRAM(VRAMBankMask banks) {
    GFL_BGSysInitVRAM(banks);
  }

  INLINE void SetVRAMBanks(const BGSysVRAMConfig* banks) {
    GFL_BGSysSetVRAMBanks(banks);
  }

  INLINE void DisableBGsA() {
    GFL_BGSysDisableBGsA();
  }

  INLINE void DisableOBJA() {
    GFL_BGSysDisableOBJA();
  }

  INLINE void DisableAllA() {
    GFL_BGSysDisableAllA();
  }

  INLINE void DisableBGsB() {
    GFL_BGSysDisableBGsB();
  }

  INLINE void DisableOBJB() {
    GFL_BGSysDisableOBJB();
  }

  INLINE void DisableAllB() {
    GFL_BGSysDisableAllB();
  }

  INLINE void SetBGEnabledA(G2DScreenBGBit mask, b32 enable) {
    GFL_BGSysSetBGEnabledA(mask, enable);
  }

  INLINE void SetEnabledBGsA(G2DScreenBGBit display) {
    GFL_BGSysSetEnabledBGsA(display);
  }

  INLINE void SetBGEnabledB(G2DScreenBGBit display, bool enable) {
    GFL_BGSysSetBGEnabledB(display, enable);
  }

  INLINE void SetEnabledBGsB(G2DScreenBGBit display) {
    GFL_BGSysSetEnabledBGsB(display);
  }

  INLINE void EnableEngines() {
    GFL_BGSysEnableEngines();
  }

  INLINE void SetDisplayLayout(G2DDisplayLayout layout) {
    GFL_BGSysSetDisplayLayout(layout);
  }

  INLINE G2DScreenBGBit GetEnabledBGsA() {
    return GFL_BGSysGetEnabledBGsA();
  }

  INLINE G2DScreenBGBit GetEnabledBGsB() {
    return GFL_BGSysGetEnabledBGsB();
  }

  INLINE void* GetBGCharAddress(G2DBG bg) {
    return GFL_BGSysGetBGCharAddress(bg);
  }

}
#endif

#endif //__GFL_BG_SYS_H
// Tchaikovsky code generator
