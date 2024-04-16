#ifndef __GFL_SYSTEMFONT_H
#define __GFL_SYSTEMFONT_H

#include "swantypes.h"

STRUCT_DECLARE(SystemFontData)
STRUCT_DECLARE(SystemFont)

SWAN_CPPTYPE(gfl::str, SystemFont)

#include "gfl/str/gfl_textprint.h"

C_DECL_BEGIN

extern void    GFL_SystemFontInit(const char* path);
extern void    GFL_SystemFontGetGlyph(u32 glyphIndex, TextPrint* textPrint);
extern u32     GFL_SystemFontUnpackBits(u8 data);
extern u8      GFL_SystemFontGetHeight();
extern u32     GFL_SystemFontGetTabSize();
extern void    GFL_SystemFontSetColorIndices(u32 primaryIndex, u32 secondaryIndex);

C_DECL_END

struct SystemFontData
{
    u32 GlyphsOffset;
    u32 GlyphWidthsOffset;
    u32 GlyphCount;
    u8 CellWidth;
    u8 CellHeight;
    u8 LetterSpacing;
    u8 LineSpacing;
};

struct SystemFont
{
    SystemFontData* FontData;
    u32 PrimaryColorIndexMask;
    u32 SecondaryColorIndexMask;
    b32 IsUsingEmbeddedFont;
  
    #ifdef __cplusplus
  
    INLINE static void Init(const char* path) {
        GFL_SystemFontInit(path);
    }

    INLINE static void GetGlyph(u32 glyphIndex, gfl::str::TextPrint* textPrint) {
        GFL_SystemFontGetGlyph(glyphIndex, textPrint);
    }

    INLINE static u32 UnpackBits(u8 data) {
        return GFL_SystemFontUnpackBits(data);
    }

    INLINE static u8 GetHeight() {
        return GFL_SystemFontGetHeight();
    }

    INLINE static u32 GetTabSize() {
        return GFL_SystemFontGetTabSize();
    }

    INLINE static void SetColorIndices(u32 primaryIndex, u32 secondaryIndex) {
        GFL_SystemFontSetColorIndices(primaryIndex, secondaryIndex);
    }

    #endif
};

extern SystemFont* g_SystemFont;

#endif //__GFL_SYSTEMFONT_H
// Tchaikovsky code generator
