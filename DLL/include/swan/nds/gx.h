#ifndef __GX_H
#define __GX_H

#include "swantypes.h"
#include "swan_cpp_enum_ops.h"

STRUCT_DECLARE(G2DBGTransformRegs)
STRUCT_DECLARE(G2DBlendRegs)
UNION_DECLARE(BGCntBit12)
STRUCT_DECLARE(BGCntReg)
STRUCT_DECLARE(LCDIO)
STRUCT_DECLARE(StdPalette)
STRUCT_DECLARE(DispCntReg)
STRUCT_DECLARE(PowCntReg)

ENUM_DECLARE(GXLightID)
ENUM_DECLARE(GEPixelFormat)
ENUM_DECLARE(VRAMBankMask)
ENUM_DECLARE(VRAMBank)
ENUM_DECLARE(GfxUploadTarget)
ENUM_DECLARE(G2DTargetPixel)
ENUM_DECLARE(G2DScreenBGBit)
ENUM_DECLARE(G2DDisplayMode)
ENUM_DECLARE(G2DBGMode)
ENUM_DECLARE(G2DBG)
ENUM_DECLARE(G2DBGScreenSize)
ENUM_DECLARE(G2DDisplayLayout)
ENUM_DECLARE(G2DEngine)
ENUM_DECLARE(G2DColorPaletteMode)

typedef u16 GXColor;

enum GXLightID
#ifdef __cplusplus
: u32
#endif
{
    GX_LIGHTID_0 = 0x0,
    GX_LIGHTID_1 = 0x1,
    GX_LIGHTID_2 = 0x2,
    GX_LIGHTID_3 = 0x3,
};
SWAN_CPPTYPE_EX(nn::gx, LightID, GXLightID)

enum GEPixelFormat
#ifdef __cplusplus
: u32
#endif
{
    GE_PIXFMT_NULL = 0x0,
    GE_PIXFMT_A3I5 = 0x1,
    GE_PIXFMT_IDX2 = 0x2,
    GE_PIXFMT_IDX4 = 0x3,
    GE_PIXFMT_IDX8 = 0x4,
    GE_PIXFMT_IDXCMPR = 0x5,
    GE_PIXFMT_A5I3 = 0x6,
    GE_PIXFMT_RGB5A1 = 0x7,
};

enum VRAMBankMask
#ifdef __cplusplus
: u32
#endif
{
    VRAM_MASK_NONE = 0x0,
    VRAM_MASK_A = 0x1,
    VRAM_MASK_B = 0x2,
    VRAM_MASK_C = 0x4,
    VRAM_MASK_D = 0x8,
    VRAM_MASK_E = 0x10,
    VRAM_MASK_F = 0x20,
    VRAM_MASK_G = 0x40,
    VRAM_MASK_H = 0x80,
    VRAM_MASK_I = 0x100,
};
DEFINE_ENUM_FLAG_OPERATORS(VRAMBankMask)

enum VRAMBank
#ifdef __cplusplus
: u32
#endif
{
    VRAM_BANK_A = 0x0,
    VRAM_BANK_B = 0x1,
    VRAM_BANK_C = 0x2,
    VRAM_BANK_D = 0x3,
    VRAM_BANK_E = 0x4,
    VRAM_BANK_F = 0x5,
    VRAM_BANK_G = 0x6,
    VRAM_BANK_H = 0x7,
    VRAM_BANK_I = 0x8,
};

enum GfxUploadTarget
#ifdef __cplusplus
: u32
#endif
{
    GFX_UPLOAD_TEXTURE = 0x0,
    GFX_UPLOAD_PALETTE = 0x1,
    GFX_UPLOAD_REAR_PLANE_BITMAP_A = 0x2,
    GFX_UPLOAD_REAR_PLANE_BITMAP_B = 0x3,
    GFX_UPLOAD_BG_CHAR_0A = 0x4,
    GFX_UPLOAD_BG_CHAR_1A = 0x5,
    GFX_UPLOAD_BG_CHAR_2A = 0x6,
    GFX_UPLOAD_BG_CHAR_3A = 0x7,
    GFX_UPLOAD_BG_SCREEN_0A = 0x8,
    GFX_UPLOAD_BG_SCREEN_1A = 0x9,
    GFX_UPLOAD_BG_SCREEN_2A = 0xA,
    GFX_UPLOAD_BG_SCREEN_3A = 0xB,
    GFX_UPLOAD_BG_SCREEN_2A_EXT = 0xC,
    GFX_UPLOAD_BG_SCREEN_3A_EXT = 0xD,
    GFX_UPLOAD_STD_PLT_OBJ_A = 0xE,
    GFX_UPLOAD_STD_PLT_BG_A = 0xF,
    GFX_UPLOAD_EXT_PLT_OBJ_A = 0x10,
    GFX_UPLOAD_EXT_PLT_BG_A = 0x11,
    GFX_UPLOAD_OAM_A = 0x12,
    GFX_UPLOAD_OBJ_CHAR_A = 0x13,
    GFX_UPLOAD_BG_CHAR_0B = 0x14,
    GFX_UPLOAD_BG_CHAR_1B = 0x15,
    GFX_UPLOAD_BG_CHAR_2B = 0x16,
    GFX_UPLOAD_BG_CHAR_3B = 0x17,
    GFX_UPLOAD_BG_SCREEN_0B = 0x18,
    GFX_UPLOAD_BG_SCREEN_1B = 0x19,
    GFX_UPLOAD_BG_SCREEN_2B = 0x1A,
    GFX_UPLOAD_BG_SCREEN_3B = 0x1B,
    GFX_UPLOAD_BG_SCREEN_2B_EXT = 0x1C,
    GFX_UPLOAD_BG_SCREEN_3B_EXT = 0x1D,
    GFX_UPLOAD_STD_PLT_OBJ_B = 0x1E,
    GFX_UPLOAD_STD_PLT_BG_B = 0x1F,
    GFX_UPLOAD_EXT_PLT_OBJ_B = 0x20,
    GFX_UPLOAD_EXT_PLT_BG_B = 0x21,
    GFX_UPLOAD_OAM_B = 0x22,
    GFX_UPLOAD_OBJ_CHAR_B = 0x23,
};

enum G2DTargetPixel
#ifdef __cplusplus
: u32
#endif
{
    G2D_TARGETPX_NONE = 0x0,
    G2D_TARGETPX_BG0 = 0x1,
    G2D_TARGETPX_BG1 = 0x2,
    G2D_TARGETPX_BG2 = 0x4,
    G2D_TARGETPX_BG3 = 0x8,
    G2D_TARGETPX_OBJ = 0x10,
    G2D_TARGETPIXEL_BD = 0x20,
    G2D_TARGETPIXEL_ALL = 0x3F,
};

enum G2DScreenBGBit
#ifdef __cplusplus
: u32
#endif
{
    G2D_SCREENBG_NONE = 0x0,
    G2D_SCREENBG_0 = 0x1,
    G2D_SCREENBG_1 = 0x2,
    G2D_SCREENBG_2 = 0x4,
    G2D_SCREENBG_3 = 0x8,
    G2D_SCREENBG_OBJ = 0x10,
};
DEFINE_ENUM_FLAG_OPERATORS(G2DScreenBGBit)

enum G2DDisplayMode
#ifdef __cplusplus
: u32
#endif
{
    G2D_DISPMODE_OFF = 0x0,
    G2D_DISPMODE_GRAPHICS = 0x1,
    G2D_DISPMODE_VRAM = 0x2,
    G2D_DISPMODE_RAM_DMA = 0x3,
};

enum G2DBGMode
#ifdef __cplusplus
: u32
#endif
{
    G2D_BGMODE_HTTT = 0x0,
    G2D_BGMODE_HTTA = 0x1,
    G2D_BGMODE_HTAA = 0x2,
    G2D_BGMODE_HTTE = 0x3,
    G2D_BGMODE_HTAE = 0x4,
    G2D_BGMODE_HTEE = 0x5,
    G2D_BGMODE_3_L_ = 0x6,
};

enum G2DBG
#ifdef __cplusplus
: u32
#endif
{
    G2D_BG0A = 0x0,
    G2D_BG1A = 0x1,
    G2D_BG2A = 0x2,
    G2D_BG3A = 0x3,
    G2D_BG0B = 0x4,
    G2D_BG1B = 0x5,
    G2D_BG2B = 0x6,
    G2D_BG3B = 0x7,
};

enum G2DBGScreenSize
#ifdef __cplusplus
: u32
#endif
{
    BGSIZE_T256x256_R128x128 = 0x0,
    BGSIZE_T512x256_R256x256 = 0x1,
    BGSIZE_T256x512_R512x512 = 0x2,
    BGSIZE_T512x512_R1024x1024 = 0x3,
};

enum G2DDisplayLayout
#ifdef __cplusplus
: u32
#endif
{
    G2D_DISPLAYOUT_A_DOWN_B_UP = 0x0,
    G2D_DISPLAYOUT_A_UP_B_DOWN = 0x1,
};

enum G2DEngine
#ifdef __cplusplus
: u32
#endif
{
    G2D_ENGINE_A = 0x0,
    G2D_ENGINE_B = 0x1,
};

enum G2DColorPaletteMode
#ifdef __cplusplus
: u32
#endif
{
    G2D_COL16_PAL16 = 0x0,
    G2D_COL256_PAL1 = 0x1,
};

SWAN_CPPTYPE_EX(nn::gx, Color, GXColor)

#include "math/matrix.h"
#include "math/vector.h"
#include "math/fixed.h"

C_DECL_BEGIN

extern void            gfxInit();
extern b32             gfxUploadAsync(GfxUploadTarget target, u32 dstOffset, void* src, size_t size);
extern void            gfxSetVCountIntrLine(u16 scanline);
extern void            gfxSetHBlankIRQEnabled(b32 enable);
extern void            gfxSetVBlankIRQEnabled(b32 enable);
extern b32             gfxEngineIsEnabledA();
extern void            gfxEngineDisableA();
extern void            gfxEngineEnableA();
extern void            gfxSetEngineModeA(G2DDisplayMode dispMode, G2DBGMode bgMode, b32 bg03D);
extern void            gfxSetBGModeB(G2DBGMode bgMode);
extern void            gfxRegSetMasterBrightness(s16* reg, s16 bright);
extern s32             gfxRegGetMasterBrightness(s16* reg);
extern void            gfxRegSetBGTransform(G2DBGTransformRegs* dest, Mat2* matrix, int originX, int originY, int offsetX, int offsetY);
extern void            gfxRegSetAlphaBlend(G2DBlendRegs* regs, G2DTargetPixel targetPixel1, G2DTargetPixel targetPixel2, int eva, int evb);
extern void            gfxRegSetBrightnessBlend(G2DBlendRegs* regs, G2DTargetPixel targetPixel, s16 evy);
extern void            gfxRegSetBlend(G2DBlendRegs* regs, G2DTargetPixel target1, G2DTargetPixel target2, s16 eva, s16 evb, s16 bldy);
extern void            gfxRegAdjustBrightnessBlend(G2DBlendRegs* regs, s16 bldy);
extern void            gfxPerspective(fx32 fovSin, fx32 fovCos, fx32 aspect, fx32 near, fx32 far, fx32 ndcRange, b32 apply, Mat4* outMatrix);
extern void            gfxOrtho(fx32 top, fx32 bottom, fx32 left, fx32 right, fx32 near, fx32 far, fx32 ndcRange, b32 apply, Mat4* outMatrix);
extern void            gfxLookAt(VecFx32* eye, VecFx32* up, VecFx32* tgt, b32 setToGpu, Mat4x3* dest);
extern void            gfxRotateX(fx32 sin, fx32 cos);
extern void            gfxRotateY(fx32 sin, fx32 cos);
extern void            gfxRotateZ(fx32 sin, fx32 cos);
extern void            gfxLoadMatrix4x4(Mat4* mat);
extern void            gfxLoadMatrix4x3(Mat4x3* mat);
extern void            gfxMultMatrix4x4(Mat4* mat);
extern void            gfxMultMatrix4x3(Mat4x3* mat);
extern void            gfxMultMatrix3x3(Mat3* mat);
extern void            gfxMultTransRot4x3(Mat3* rotation, VecFx32* translation);
extern void            gfxInit3D();
extern void            gfxReset3D();
extern void            gfxResetFIFO();
extern void            gfxResetMatrixStack();
extern void            gfxResetMatrixStackKeepProjection();
extern void            gfxSetFog(u8 enable, u16 alphaMode, u16 depthShift, u16 offset);
extern int             gfxGetClipMatrix(Mat4* dest);
extern int             gfxGetNormalMatrix(Mat3* dest);
extern void*           gfxSetEdgeColorTable(u16* edgeColorTable);
extern void            gfxSetFogTable(u8* fogTable);
extern void            gfxClearColor(GXColor color, u8 alpha, s16 clearDepth, u8 polyId, b32 fog);
extern void            gfxResetLUTs();
extern int             gfxGetWorldMatrixStackLevel(u32* dest);
extern int             gfxGetProjectionMatrixStackLevel(u32* dest);
extern void            gfxSet1DotDepth(fx32 depth);
extern int             gfxGetBoxTestResult(int* dest);
extern void            gfxClearFIFO(volatile int* fifo);
extern void*           gfxGetScreenAddrBG0A();
extern void*           gfxGetScreenAddrBG0B();
extern void*           gfxGetScreenAddrBG1A();
extern void*           gfxGetScreenAddrBG1B();
extern void*           gfxGetScreenAddrBG2A();
extern void*           gfxGetScreenAddrBG2B();
extern void*           gfxGetScreenAddrBG3A();
extern void*           gfxGetScreenAddrBG3B();
extern void*           gfxGetCharAddrBG0A();
extern void*           gfxGetCharAddrBG0B();
extern void*           gfxGetCharAddrBG1A();
extern void*           gfxGetCharAddrBG1B(void);
extern void*           gfxGetCharAddrBG2A();
extern void*           gfxGetCharAddrBG2B(void);
extern void*           gfxGetCharAddrBG3A();
extern void*           gfxGetCharAddrBG3B(void);
extern void            gfxUploadStdPaletteBGA(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadStdPaletteBGB(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadStdPaletteObjA(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadStdPaletteObjB(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadOAMA(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadOAMB(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadObjCharA(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadObjCharB(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen0A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen0B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen1A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen1B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen2A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen2B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen3A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGScreen3B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar0A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar0B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar1A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar1B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar2A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar2B(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar3A(void* src, u32 dstOffset, size_t size);
extern void            gfxUploadBGChar3B(void* src, u32 dstOffset, size_t size);
extern void            gfxBeginBGExtPltAUpload();
extern void            gfxUploadExtPaletteBGA(void* src, u32 dstOffset, size_t size);
extern void            gfxEndBGExtPltAUpload();
extern void            gfxBeginObjExtPltAUpload(void);
extern void            gfxUploadExtPaletteObjA(void* src, u32 dstOffset, size_t size);
extern void            gfxEndObjExtPltAUpload();
extern void            gfxBeginBGExtPltBUpload();
extern void            gfxUploadExtPaletteBGB(void* src, int dstOffset, size_t size);
extern void            gfxEndBGExtPltBUpload();
extern void            gfxBeginObjExtPltBUpload();
extern void            gfxUploadExtPaletteObjB(void* src, u32 dstOffset, size_t size);
extern void            gfxEndObjExtPltBUpload();
extern void            gfxBeginTextureUpload();
extern void            gfxUploadTexture(void* src, u32 dstOffset, size_t size);
extern void            gfxEndTextureUpload();
extern void            gfxBeginPaletteUpload();
extern void            gfxUploadPalette(void* src, int dstOffset, size_t size);
extern void            gfxEndPaletteUpload();
extern void            gfxBeginRearPlaneImageUpload();
extern void            gfxUploadRearPlaneImageB(void* src, size_t size);
extern void            gfxEndRearPlaneImageUpload();
extern void            gfxSetLCDCBanksCore(VRAMBankMask mask);
extern void            gfxSetBGBanksA(VRAMBankMask banks);
extern void            gfxSetObjBanksA(VRAMBankMask banks);
extern void            gfxSetBGExtPltBanksA(VRAMBankMask banks);
extern void            gfxSetObjExtPltBanksA(VRAMBankMask banks);
extern void            gfxSetTextureBanks(VRAMBankMask banks);
extern void            gfxSetPaletteBanks(VRAMBankMask banks);
extern void            gfxSetLCDCBanks(VRAMBankMask mask);
extern void            gfxSetBGBanksB(VRAMBankMask banks);
extern void            gfxSetObjBanksB(VRAMBankMask banks);
extern void            gfxSetBGExtPltBanksB(VRAMBankMask banks);
extern void            gfxSetObjExtPltBanksB(VRAMBankMask banks);
extern VRAMBankMask    gfxAcquireBanksForLCDC(u16* bankQueue);
extern VRAMBankMask    gfxAcquireBGBanksA();
extern VRAMBankMask    gfxAcquireObjBanksA();
extern VRAMBankMask    gfxAcquireBGExtPltBanksA();
extern VRAMBankMask    gfxAcquireObjExtPltBanksA();
extern VRAMBankMask    gfxAcquireTextureBanks();
extern VRAMBankMask    gfxAcquirePaletteBanks();
extern VRAMBankMask    gfxAcquireBGBanksB();
extern VRAMBankMask    gfxAcquireObjBanksB();
extern VRAMBankMask    gfxAcquireBGExtPltBanksB();
extern VRAMBankMask    gfxAcquireObjExtPltBanksB();
extern VRAMBankMask    gfxDisableQueuedBanks(u16* pBankMask);
extern VRAMBankMask    gfxDisableBGBanksA();
extern VRAMBankMask    gfxDisableObjBanksA();
extern VRAMBankMask    gfxDisableBGExtPltBanksA();
extern VRAMBankMask    gfxDisableObjExtPltBanksA();
extern VRAMBankMask    gfxDisableTextureBanks();
extern VRAMBankMask    gfxDisablePaletteBanks();
extern VRAMBankMask    gfxDisableRearPlaneImageBanks();
extern VRAMBankMask    gfxDisableLCDCBanks();
extern VRAMBankMask    gfxDisableBGBanksB();
extern VRAMBankMask    gfxDisableObjBanksB();
extern VRAMBankMask    gfxDisableBGExtPltBanksB();
extern VRAMBankMask    gfxDisableObjExtPltBanksB();
extern VRAMBankMask    gfxGetObjBanksA(void);
extern VRAMBankMask    gfxGetObjExtPltBanksA();
extern VRAMBankMask    gfxGetTextureBanks();
extern VRAMBankMask    gfxGetObjBanksB(void);
extern VRAMBankMask    gfxGetObjExtPltBanksB();
extern void            gfxUploadMatrix4x3(Mat4x3* mat, volatile s32* fifo);
extern void            gfxUploadMatrix4x4(Mat4* mat, volatile int* fifo);
extern void            gfxInitVRAM(void);

C_DECL_END

struct G2DBGTransformRegs
{
    s16 Dx;
    s16 Dmx;
    s16 Dy;
    s16 Dmy;
    s32 X;
    s32 Y;
};

struct G2DBlendRegs
{
    u16 BLDCNT;
    u16 BLDALPHA;
    u16 BLDY;
    u16 UNUSED6;
};

union BGCntBit12 {
u32 ExtPltSlot:1;
u32 DispAreaOverflow:1;
};

struct BGCntReg {
union {
    struct {
    u16 Priority:2;
    u16 CharBase:4;
    u16 Mosaic:1;
    u16 ColorPaletteMode:1;
    u16 ScreenBase:5;
    u16 Bit12:1;
    u16 ScreenSize:2;
    };
    u16 RawBits;
};
};
static_assert(sizeof(BGCntReg) == sizeof(u16));

struct LCDIO
{
    BGCntReg BG0CNT;
    BGCntReg BG1CNT;
    BGCntReg BG2CNT;
    BGCntReg BG3CNT;
    u16 BG0HOFS;
    u16 BG0VOFS;
    u16 BG1HOFS;
    u16 BG1VOFS;
    u16 BG2HOFS;
    u16 BG2VOFS;
    u16 BG3HOFS;
    u16 BG3VOFS;
    G2DBGTransformRegs BG2Transform;
    G2DBGTransformRegs BG3Transform;
    u16 WIN0H;
    u16 WIN1H;
    u16 WIN0V;
    u16 WIN1V;
    u16 WININ;
    u16 WINOUT;
    u32 MOSAIC;
    G2DBlendRegs BLD;
};

struct StdPalette
{
    GXColor Colors[256];
};

struct DispCntReg {
union {
    struct {
    u32 BGMode:3;
    u32 IsBG03D:1;
    u32 TileOBJMapping:1;
    u32 BitmapOBJSize:1;
    u32 BitmapOBJMapping:1;
    u32 ForcedBlank:1;
    u32 DispBGs:5;
    u32 DispWnd0:1;
    u32 DispWnd1:1;
    u32 DispObjWnd:1;
    u32 DisplayMode:2;
    u32 VRAMBlock:2;
    u32 TileOBJBoundary:2;
    u32 BitmapOBJBoundary:1;
    u32 ProcessOBJInHBlank:1;
    u32 CharBase:3;
    u32 ScreenBase:3;
    u32 EnableBGExtPlt;
    u32 EnableOBJExtPlt;
    };
    u32 RawBits;
};
};

struct PowCntReg {
union {
    struct {
    u16 BothLCDs:1;
    u16 Engine2DA:1;
    u16 RenderingEngine:1;
    u16 GeometryEngine:1;
    u16 _NotUsed:5;
    u16 Engine2DB:1;
    u16 _NotUsed2:5;
    u16 DispLayout:1;		
    };
    u16 RawBits;
};
};

extern LCDIO LCDIO_A;

extern LCDIO LCDIO_B;

extern s16 MASTER_BRIGHT_A;

extern s16 MASTER_BRIGHT_B;

extern volatile DispCntReg DISPCNT_A;

extern volatile DispCntReg DISPCNT_B;

extern StdPalette STD_PALETTE_BG_A;

extern StdPalette STD_PALETTE_BG_B;

extern StdPalette STD_PALETTE_OBJ_A;

extern StdPalette STD_PALETTE_OBJ_B;

extern u16 g_GfxVRAMLCDCBanks;

extern u16 g_GfxVRAMBGBanksA;

extern u16 g_GfxVRAMObjBanksA;

extern u16 g_GfxVRAMPlainARM7Banks;

extern u16 g_GfxVRAMTexBanks;

extern u16 g_GfxVRAMPltBanks;

extern u16 g_GfxVRAMRearPlaneImageBanks;

extern u16 g_GfxVRAMBGExtPltBanksA;

extern u16 g_GfxVRAMObjExtPltBanksA;

extern u16 g_GfxVRAMBGBanksB;

extern u16 g_GfxVRAMObjBanksB;

extern u16 g_GfxVRAMBGExtPltBanksB;

extern u16 g_GfxVRAMObjExtPltBanksB;

extern volatile PowCntReg POWCNT1;

#endif //__GX_H
// Tchaikovsky code generator
