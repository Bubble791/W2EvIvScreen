#ifndef __FIELD_EVENT_H
#define __FIELD_EVENT_H

#include "swan/swantypes.h"

C_DECL_BEGIN

#define ITEMUSE_EVENT_CHECKAGAIN    0
#define ITEMUSE_EVENT_CANCEL        1
#define ITEMUSE_EVENT_HIDEN         2
#define ITEMUSE_EVENT_FIELD         3
#define ITEMUSE_EVENT_NEW_APP       4

#define ITEM_EVENT_TOWN_MAP     7
#define ITEM_EVENT_PAL_PAD      8
#define ITEM_EVENT_BICYCLE_0    10
#define ITEM_EVENT_BICYCLE_1    11
#define ITEM_EVENT_HONEY        15
#define ITEM_EVENT_SUPER_ROD    16
#define ITEM_EVENT_VS_RECORDER  17
#define ITEM_EVEMT_MAIL         18

typedef struct
{
    u32 unknow;
} EventTypes;

typedef struct
{
    /*0x00*/ GameSystem* GameSystem;
    /*0x04*/ Field* Field;
    /*0x08*/ u8 unk8[12];
    /*0x14*/ int SubprocParam;
    /*0x18*/ u8 unk18[0x10];
    /*0x28*/ EventTypes EventType;
} AppCallFramework;

typedef struct
{
    /*0x00*/ u16 m_HeapID;
    /*0x02*/ u16 field_2;
    /*0x04*/ int AppID;
    /*0x08*/ int LastAppID;
    /*0x0C*/ int ChildAppID;
    /*0x10*/ int SubprocResult;
    /*0x14*/ int unk14;
    /*0x18*/ AppCallFramework *m_AppCallFramework;
    /*0x1C*/ void *SubprocData;
    /*0x20*/ int m_Param[5];
} EventFieldAppCall;

typedef void *(*ProcData)(EventFieldAppCall*, int, int, void*);
typedef void (*FreeProc)(void*);
typedef int (*CreatProc)(EventFieldAppCall*, void*);
typedef void (*FieldProc)(EventFieldAppCall*, int);

typedef struct
{
    /*0x00*/ u32 OvlID;
    /*0x04*/ GameProcFunctions *ProcFuncs;
    /*0x08*/ ProcData ProcDataMakeFunc;
    /*0x0C*/ CreatProc CreateResult;
    /*0x10*/ FieldProc field_10;
    /*0x14*/ FreeProc FreeSubprocDataFunc;

} EventFieldAppTable;

typedef struct
{
    GameSystem *unk0;
    u8 unk4[0x28];
    int fieldId;
    int unk30;
}UNKNOW;

typedef struct
{
    u8 unk0[0xC];
    int EventFieldAppId;
    int unk10;
    int unk14;
    UNKNOW *unk18;
    u8 unk1C[0x54];
    int unk70;
}FIELD_PARAM;

typedef struct
{
    u8 unk0[0x38];
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
}BAG_RETURN_PARAM;

typedef struct
{
    /*0x000*/ void *unk0;
    /*0x004*/ void *unk4;
    /*0x008*/ int unk8;
    /*0x00C*/ int unkC;
    /*0x010*/ int unk10;
    /*0x014*/ int unk14;
    /*0x018*/ void* bagSave;
    /*0x01C*/ void* unk1C;
    /*0x020*/ void* unk20;
    /*0x024*/ void *m_itemTable[6]; // 背包内存， 可能是当前道具列表的值？
    /*0x03C*/ u8 unk3C[0x85C];
    /*0x898*/ int unk898;
    /*0x89C*/ int unk89C;
    /*0x8A0*/ int selectItem;
    /*0x8A4*/ int unk8A4;
    /*0x8B0*/ int unk8B0;
    /*0x8B4*/ int unk8B4;
    /*0x8C0*/ int KeyRetypeIntervalRepeated;
    /*0x8C4*/ int KeyRetypeIntervalFirst;
    /*0x8C8*/ int unk8C8;
} BagView;

typedef void (*FieldBagItemUse)(BagView *);
extern void sub_02199900(BagView *a1, FieldBagItemUse a2);
extern void sub_0219f6e4(BagView *a1, int a2);
extern void GFL_MsgDataLoadStrbuf(void *a1, int a2, void *a3);
extern void copyVarForText(void *a1, int a2, int a3);
extern void GFL_WordSetFormatStrbuf(void *a1, void *a2, void *a3);

// actionBlock:检查程序，表格地址在ovy12 0216CE54, 2为无论何时都能触发
extern int sub_0219a354(BagView * m_bagView, int actionBlock, int param_3, int param_4);
extern int PML_ItemIsMail(u16);

C_DECL_END

#endif