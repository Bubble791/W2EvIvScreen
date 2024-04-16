#ifndef __GFL_TEXTPRINT_H
#define __GFL_TEXTPRINT_H

#include "swantypes.h"

#define GFL_TEXTPRINT_ASCII_HI 0x80
#define GFL_TEXTPRINT_ASCII_EXT_LO 0xA0
#define GFL_TEXTPRINT_ASCII_EXT_HI 0xDF
#define GFL_TEXTPRINT_IS_ASCII(character) ((((unsigned char)(character)) <= GFL_TEXTPRINT_ASCII_HI)\
|| (((unsigned char)(character)) >= GFL_TEXTPRINT_ASCII_EXT_LO \
&& ((unsigned char)(character)) <= GFL_TEXTPRINT_ASCII_EXT_HI))

STRUCT_DECLARE(TextPrintState)
STRUCT_DECLARE(TextPrint)

ENUM_DECLARE(TextPrintSpecialChar)

enum TextPrintSpecialChar
#ifdef __cplusplus
: u32
#endif
{
    TEXTPRINT_NULL = 0x0,
    TEXTPRINT_LF = 0x1,
    TEXTPRINT_TAB = 0x2,
    TEXTPRINT_MA = 0x3,
    TEXTPRINT_SPECIAL_CHAR_END = 0x4,
    TEXTPRINT_CR = 0xFFFE,
};
SWAN_CPPTYPE(gfl::str, TextPrintSpecialChar)

SWAN_CPPTYPE(gfl::str, TextPrintState)
SWAN_CPPTYPE(gfl::str, TextPrint)

#include "gfl/g2d/gfl_bitmap.h"

C_DECL_BEGIN

extern void    GFL_TextPrintInit(const char* fontPath);
extern void    GFL_TextPrintDrawIndices(u16* printstr, TextPrintState* state);
extern void    GFL_TextPrintDrawString(const char* string, TextPrintState* state);
extern void    GFL_TextPrintStringToIndices(const char* cstr, u16* printstr, u32 destCapacity);
extern u32     GFL_TextPrintASCIIToIndex(u32 character);
extern int     GFL_TextPrintSJISToIndex(u32 character);

C_DECL_END

struct TextPrintState
{
    GFLBitmap* m_Bitmap;
    u16 OutOffsX;
    u16 OutOffsY;
    u8 LetterSpacing;
    u8 LineSpacing;
    u8 GlyphColorIndex:4;
    u8 BGColorIndex:4;
    u8 _Padding;
};

struct TextPrint
{
    u8 CharBitmapBuffer[32];
    u8 CharWidth;
    u8 _padCharWidth;
    u16 OutOffsX;
    u16 OutOffsY;
  
    #ifdef __cplusplus
  
    INLINE static void Init(const char* fontPath) {
        GFL_TextPrintInit(fontPath);
    }

    INLINE static void StringToIndices(const char* cstr, u16* printstr, u32 destCapacity) {
        GFL_TextPrintStringToIndices(cstr, printstr, destCapacity);
    }

    INLINE static u32 ASCIIToIndex(u32 character) {
        return GFL_TextPrintASCIIToIndex(character);
    }

    INLINE static int SJISToIndex(u32 character) {
        return GFL_TextPrintSJISToIndex(character);
    }

    INLINE static void DrawIndices(u16* printstr, gfl::str::TextPrintState* state) {
        GFL_TextPrintDrawIndices(printstr, state);
    }

    INLINE static void DrawString(const char* string, gfl::str::TextPrintState* state) {
        GFL_TextPrintDrawString(string, state);
    }

    #endif
};

extern TextPrintState g_DebugPrintState;

extern TextPrint* g_TextPrint;

#endif //__GFL_TEXTPRINT_H
// Tchaikovsky code generator
