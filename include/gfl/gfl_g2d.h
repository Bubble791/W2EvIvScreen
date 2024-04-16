#ifndef __GFL_G2D_H
#define __GFL_G2D_H

typedef enum
{
    G2D_DISPMODE_OFF = 0x0,
    G2D_DISPMODE_GRAPHICS = 0x1,
    G2D_DISPMODE_VRAM = 0x2,
    G2D_DISPMODE_RAM_DMA = 0x3,
}G2DDisplayMode;

typedef enum
{
    G2D_BGMODE_HTTT = 0x0,
    G2D_BGMODE_HTTA = 0x1,
    G2D_BGMODE_HTAA = 0x2,
    G2D_BGMODE_HTTE = 0x3,
    G2D_BGMODE_HTAE = 0x4,
    G2D_BGMODE_HTEE = 0x5,
    G2D_BGMODE_3_L_ = 0x6,
} G2DBGMode;

typedef enum
{
    G2D_SCREENBG_NONE = 0x0,
    G2D_SCREENBG_0 = 0x1,
    G2D_SCREENBG_1 = 0x2,
    G2D_SCREENBG_2 = 0x4,
    G2D_SCREENBG_3 = 0x8,
    G2D_SCREENBG_OBJ = 0x10,
} G2DScreenBGBit;

typedef enum
{
    G2D_BG0A = 0x0,
    G2D_BG1A = 0x1,
    G2D_BG2A = 0x2,
    G2D_BG3A = 0x3,
    G2D_BG0B = 0x4,
    G2D_BG1B = 0x5,
    G2D_BG2B = 0x6,
    G2D_BG3B = 0x7,
} G2DBG;

typedef struct
{
    u32 BGBanksA;
    u32 BGExtPltBanksA;
    u32 BGBanksB;
    u32 BGExtPltBanksB;
    u32 ObjBanksA;
    u32 ObjExtPltBanksA;
    u32 ObjBanksB;
    u32 ObjExtPltBanksB;
    u32 TexBanks;
    u32 PltBanks;
    u32 TileOBJDISPCNTA;
    u32 TileOBJDISPCNTB;
} BGSysVRAMConfig;

typedef struct
{
    u32 DisplayModeA;
    u32 BGModeA;
    u32 BGModeB;
    u32 IsBG03D;
} BGSysLCDConfig;

typedef struct
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
} BGSetup;

enum
{
    G2D_DISPLAYOUT_A_DOWN_B_UP = 0x0,
    G2D_DISPLAYOUT_A_UP_B_DOWN = 0x1,
};

enum
{
    BGMODE_TEXT = 0x0,
    BGMODE_AFFINE = 0x1,
    BGMODE_EXTENDED = 0x2,
};

void LONG_CALL GFL_BGSysInitVRAM(int banks);
void LONG_CALL GFL_BGSysSetVRAMBanks(const BGSysVRAMConfig* banks);
void LONG_CALL GFL_BGSysCreate(int heapId);
void LONG_CALL GFL_BGSysSetLCDConfig(BGSysLCDConfig* cfg);
u32 LONG_CALL GFL_BGSysCreateBG(G2DBG bg, BGSetup* setup, int mode);
void LONG_CALL GFL_BGSysClearCharCore(G2DBG bg, int size, u32 offset, int heapId);
void LONG_CALL GFL_BGSysFillScr(G2DBG bg, u16 map);
void LONG_CALL GFL_BGSysSetBGEnabled(G2DBG bg, int enable);
void LONG_CALL GFL_G2DIOLoadArcNCLRDefault(ArcTool*, int, int, int, int, int);
void LONG_CALL GFL_BGSysLoadArcNCGRStatic(ArcTool*, int, int, int, int, int, int);
void LONG_CALL loadBGScrToVramByFileNoReserveNegAlign(ArcTool*, int, int, int, int, int, int);
void LONG_CALL GFL_WipeSet(int, int, int, int, int, int, int);
int LONG_CALL GFL_WipeIsFinished(void);
void LONG_CALL sub_204B7F4(void);
void LONG_CALL GFL_BGSysSetEnabledBGsA(int);
void LONG_CALL GFL_BGSysSetEnabledBGsB(int);
void LONG_CALL gfxRegSetMasterBrightness(s16*, int);
void LONG_CALL GFL_BGSysSetDisplayLayout(int);
int LONG_CALL GFL_OvlLoad(u32 ovlId);
void LONG_CALL GFL_HeapCreateChild(u16 parentHeapId, u16 heapId, u32 size);
void LONG_CALL GFL_HeapDelete(u16);
void LONG_CALL GFL_OvlUnload(u32);
/*bg：上下屏*/
void* LONG_CALL ClActSys_CreateObj(void*, void*, int, void*, OAM_TEMPLATE*, int bg, u16);

#endif