#ifndef __GFL_BITMAP_H
#define __GFL_BITMAP_H

#include "swantypes.h"

STRUCT_DECLARE(GFLBitmap)

ENUM_DECLARE(GFLBitmapType)

enum GFLBitmapType
#ifdef __cplusplus
: u32
#endif
{
    GFL_BMP_DYNAMIC = 0x0,
    GFL_BMP_STATIC_RAM = 0x1,
    GFL_BMP_STATIC_VRAM = 0x2,
};

SWAN_CPPTYPE_EX(gfl::g2d, Bitmap, GFLBitmap)

#include "ns/g2d/res/ResCharacter.h"
#include "gfl/core/gfl_heap.h"

C_DECL_BEGIN

extern GFLBitmap*  GFL_BitmapCreate(u32 tileWidth, u32 tileHeight, u32 bytesPerTile, HeapID heapId);
extern GFLBitmap*  GFL_BitmapWrap(void* pixelData, u16 tileWidth, u16 tileHeight, u32 bytesPerTile, HeapID heapId);
extern GFLBitmap*  GFL_BitmapWrapVRAM(void* pixelData, u16 tileWidth, u16 tileHeight, u32 bytesPerTile, HeapID heapId);
extern void        GFL_BitmapFree(GFLBitmap* bmp);
extern u8*         GFL_BitmapGetPixelData(GFLBitmap* bmp);
extern u32         GFL_BitmapGetWidth(GFLBitmap* bmp);
extern u32         GFL_BitmapGetHeight(GFLBitmap* bmp);
extern u32         GFL_BitmapCalcPixelDataSize(GFLBitmap* bmp);
extern void        GFL_BitmapCopy(GFLBitmap* src, GFLBitmap* dst);
extern u8          GFL_BitmapGetBytesPerTile(GFLBitmap* bmp);
extern void        GFL_BitmapCopyArea(GFLBitmap* src, GFLBitmap* dst, u16 startInX, u16 startInY, s32 startOutX, s32 startOutY, u32 copyWidth, u32 copyHeight, u16 transparentIndex);
extern void        GFL_BitmapCopyAreaRebased(GFLBitmap* src, GFLBitmap* dst, s32 startInX, s32 startInY, s32 startOutX, s32 startOutY, u32 copyWidth, u32 copyHeight, u16 transparentIndex, u8 base);
extern void        GFL_BitmapFillArea(GFLBitmap* bmp, u16 startX, u16 startY, u16 fillWidth, u16 fillHeight, u8 fillIndex);
extern void        GFL_BitmapFill(GFLBitmap* bitmap, u8 fillIndex);
extern GFLBitmap*  GFL_BitmapMakeLinear(GFLBitmap* bmp, b32 keepAsNew, HeapID heapId);
extern void        GFL_BitmapConvFromCHAR(GFLBitmap* bmp, NNSG2DResCharHeader* ncgr, HeapID heapId);

C_DECL_END

struct GFLBitmap
{
    u8* PixelData;
    u16 PixelWidth;
    u16 PixelHeight;
    u16 BytesPerTile;
    u16 Type;
  
    #ifdef __cplusplus
  
    INLINE static gfl::g2d::Bitmap* Create(u32 tileWidth, u32 tileHeight, u32 bytesPerTile, HeapID heapId) {
        return GFL_BitmapCreate(tileWidth, tileHeight, bytesPerTile, heapId);
    }

    INLINE static gfl::g2d::Bitmap* Wrap(void* pixelData, u16 tileWidth, u16 tileHeight, u32 bytesPerTile, HeapID heapId) {
        return GFL_BitmapWrap(pixelData, tileWidth, tileHeight, bytesPerTile, heapId);
    }

    INLINE static gfl::g2d::Bitmap* WrapVRAM(void* pixelData, u16 tileWidth, u16 tileHeight, u32 bytesPerTile, HeapID heapId) {
        return GFL_BitmapWrapVRAM(pixelData, tileWidth, tileHeight, bytesPerTile, heapId);
    }

    INLINE void Free() {
        GFL_BitmapFree(this);
    }

    INLINE u32 GetWidth() {
        return GFL_BitmapGetWidth(this);
    }

    INLINE u32 GetHeight() {
        return GFL_BitmapGetHeight(this);
    }

    INLINE u8* GetPixelData() {
        return GFL_BitmapGetPixelData(this);
    }

    INLINE u8 GetBytesPerTile() {
        return GFL_BitmapGetBytesPerTile(this);
    }

    INLINE void Copy(gfl::g2d::Bitmap* dst) {
        GFL_BitmapCopy(this, dst);
    }

    INLINE void CopyArea(gfl::g2d::Bitmap* dst, u16 startInX, u16 startInY, s32 startOutX, s32 startOutY, u32 copyWidth, u32 copyHeight, u16 transparentIndex) {
        GFL_BitmapCopyArea(this, dst, startInX, startInY, startOutX, startOutY, copyWidth, copyHeight, transparentIndex);
    }

    INLINE void CopyAreaRebased(gfl::g2d::Bitmap* dst, s32 startInX, s32 startInY, s32 startOutX, s32 startOutY, u32 copyWidth, u32 copyHeight, u16 transparentIndex, u8 base) {
        GFL_BitmapCopyAreaRebased(this, dst, startInX, startInY, startOutX, startOutY, copyWidth, copyHeight, transparentIndex, base);
    }

    INLINE void Fill(u8 fillIndex) {
        GFL_BitmapFill(this, fillIndex);
    }

    INLINE void FillArea(u16 startX, u16 startY, u16 fillWidth, u16 fillHeight, u8 fillIndex) {
        GFL_BitmapFillArea(this, startX, startY, fillWidth, fillHeight, fillIndex);
    }

    INLINE gfl::g2d::Bitmap* MakeLinear(b32 keepAsNew, HeapID heapId) {
        return GFL_BitmapMakeLinear(this, keepAsNew, heapId);
    }

    INLINE u32 CalcPixelDataSize() {
        return GFL_BitmapCalcPixelDataSize(this);
    }

    INLINE void ConvFromCHAR(ns::g2d::res::CharHeader* ncgr, HeapID heapId) {
        GFL_BitmapConvFromCHAR(this, ncgr, heapId);
    }

    #endif
};

#endif //__GFL_BITMAP_H
// Tchaikovsky code generator
