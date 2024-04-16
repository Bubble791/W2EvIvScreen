#ifndef __TYPES_H
#define __TYPES_H

#include <stdint.h>

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t    s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef volatile u16 vu16;
typedef vu16 REGType16v;

#define HEAPID_USER 1
#define HEAPID_PALPAD 52

#define REG_BLDCNT_OFFSET   0x050
#define REG_BLDCNT_ADDR     (0x04000000 + REG_BLDCNT_OFFSET)
#define reg_G2_BLDCNT       (*( REGType16v *) REG_BLDCNT_ADDR)

#define REG_DB_BLDCNT_OFFSET        0x1050
#define REG_DB_BLDCNT_ADDR          (0x04000000 + REG_DB_BLDCNT_OFFSET)
#define reg_G2S_DB_BLDCNT           (*( REGType16v *) REG_DB_BLDCNT_ADDR)

#define OS_VRAM_BANK_ID_A 0x0001
#define OS_VRAM_BANK_ID_B 0x0002
#define OS_VRAM_BANK_ID_C 0x0004
#define OS_VRAM_BANK_ID_D 0x0008
#define OS_VRAM_BANK_ID_E 0x0010
#define OS_VRAM_BANK_ID_F 0x0020
#define OS_VRAM_BANK_ID_G 0x0040
#define OS_VRAM_BANK_ID_H 0x0080
#define OS_VRAM_BANK_ID_I 0x0100
#define OS_VRAM_BANK_ID_ALL 0x01ff

typedef enum
{
    GX_VRAM_A = OS_VRAM_BANK_ID_A,     // VRAM-A
    GX_VRAM_B = OS_VRAM_BANK_ID_B,     // VRAM-B
    GX_VRAM_C = OS_VRAM_BANK_ID_C,     // VRAM-C
    GX_VRAM_D = OS_VRAM_BANK_ID_D,     // VRAM-D
    GX_VRAM_E = OS_VRAM_BANK_ID_E,     // VRAM-E
    GX_VRAM_F = OS_VRAM_BANK_ID_F,     // VRAM-F
    GX_VRAM_G = OS_VRAM_BANK_ID_G,     // VRAM-G
    GX_VRAM_H = OS_VRAM_BANK_ID_H,     // VRAM-H
    GX_VRAM_I = OS_VRAM_BANK_ID_I,     // VRAM-I
    GX_VRAM_ALL = OS_VRAM_BANK_ID_ALL
}
GXVRam;

#define REG_GX_DISPCNT_EXOBJ_SHIFT 20
#define REG_GX_DISPCNT_OBJMAP_SHIFT 4

#define G2D_BG0_2D 0
#define GF_BGL_MODE_TEXT	(0)
#define GF_BGL_MODE_AFFINE	(1)
#define GF_BGL_MODE_256X16	(2)

enum
{
    GX_VRAM_BG_128_A = GX_VRAM_A,
    GX_VRAM_BGEXTPLTT_NONE = 0x0000,
    GX_VRAM_BG_NONE = 0x0000,
    GX_VRAM_SUB_BG_128_C = GX_VRAM_C,
    GX_VRAM_SUB_BGEXTPLTT_NONE = 0x0000,
    GX_VRAM_OBJ_128_B = GX_VRAM_B,
    GX_VRAM_OBJEXTPLTT_NONE = 0,
    GX_VRAM_SUB_OBJ_16_I = GX_VRAM_I,
    GX_VRAM_SUB_OBJEXTPLTT_NONE = 0x0000,
    GX_VRAM_TEX_NONE = 0x0000,
    GX_VRAM_TEXPLTT_NONE = 0x0000,
    GX_OBJVRAMMODE_CHAR_1D_128K = (1 << REG_GX_DISPCNT_OBJMAP_SHIFT) | (2 << REG_GX_DISPCNT_EXOBJ_SHIFT),
};

#define NULL                ((void *)0)
#define TRUE 1
#define FALSE 0

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))
#define TEXT_INDICE(back_color, font_color, shadow_color) (back_color | shadow_color << 5 | font_color << 10)

typedef u8  bool8;
typedef int  BOOL;
typedef u16 bool16;
typedef u32 bool32;

#define	ALIGN4 __attribute__((aligned(4)))
#define THUMB_FUNC __attribute__((target("thumb")))
#define LONG_CALL __attribute__((long_call))
#define UNUSED __attribute__((unused))
#define FALLTHROUGH __attribute__ ((fallthrough))
#define PACKED __attribute__((packed))

#define STRUCT_DECLARE(tag) typedef struct tag tag;

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

#define WIPE_FADE_WHITE		(0x7fff)
#define WIPE_FADE_BLACK		(0x0000)
#define WIPE_FADE_OUTCOLOR	(0xffff)

enum
{
    PLTT_LOAD_BG_A,
    PLTT_LOAD_OBJ_A,
    PLTT_LOAD_BG_A_EXT,
    PLTT_LOAD_OBJ_A_EXT,

    PLTT_LOAD_BG_B,
    PLTT_LOAD_OBJ_B,
    PLTT_LOAD_BG_B_EXT,
    PLTT_LOAD_OBJ_B_EXT,
};

#define PLT_ID(id) (id * 32)

typedef struct
{
    u16 x;
    u16 y;
    u16 anim;
    u8 flag;
    u8 priority;
} OAM_TEMPLATE;

typedef struct
{
   u8 up;
   u8 down;
   u8 left;
   u8 right;
} RECT_HIT_TBL;

enum
{
    KEY_A = 0x1,
    KEY_B = 0x2,
    KEY_SELECT = 0x4,
    KEY_START = 0x8,
    KEY_RIGHT = 0x10,
    KEY_LEFT = 0x20,
    KEY_UP = 0x40,
    KEY_DOWN = 0x80,
    KEY_R = 0x100,
    KEY_L = 0x200,
    KEY_X = 0x400,
    KEY_Y = 0x800,
    KEY_TOUCH = 0x1000,
    KEY_LID = 0x2000,
};

typedef struct
{
    u8 unk0[0xC];
    u16 x;
    u16 y;
} ClAct_228;

#endif